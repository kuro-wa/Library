// Minimum-cost flow problem
// for negative edges
template<class Cap, class Cost>
struct mcf_graph {
public:
  mcf_graph(int n=0) : _n(n), g(n), negative(false) {}
  int add_edge(int from, int to, Cap cap, Cost cost){
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    if (cost < 0) negative = true;
    int m = int(pos.size());
    pos.emplace_back(from, int(g[from].size()));
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to) ++to_id;
    g[from].push_back(_edge{to, to_id, cap, cost});
    g[to].push_back(_edge{from, from_id, 0, -cost});
    return m;
  }
  struct edge { int to, rev; Cap cap; Cost cost;};
  pair<Cap, Cost> flow(int s, int t, Cap flow_limit=numeric_limits<Cap>::max) {
    return slope(s, t, flow_limit).back();
  }
  vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit=numeric_limits<Cap>::max) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    vector<Cost> dual(_n), dist(_n);
    vector<int> pv(_n), pe(_n), vis(_n);
    auto bellmanford = [&]() {
      dist[s] = 0;
      Cost infinity = numeric_limits<Cost>::max();
      for (int cnt = 0; cnt < _n-1; ++cnt) {
        bool update = false;
        for (int v = 0; v < _n; ++v) {
          if(dist[v] == infinity) continue;
          for (int i = 0; i < int(g[v].size()); ++i) {
            auto& e=g[v][i];
            if(e.cap > 0 && dist[e.to] > dist[v]+e.cost) {
              dist[e.to] = dist[v]+e.cost;
              pv[e.to] = v;
              pe[e.to] = i;
              update = true;
            }
          }
        }
        if(!update) break;
      }
      for (int v = 0; v < _n; ++v) {
        if (dist[v] != infinity) vis[v] = 1;
      }
    };
    auto dijkstra = [&]() {
      struct Q {
        Cost key; int to;
        bool operator<(Q r) const { return key > r.key;}
      };
      priority_queue<Q> que;
      dist[s] = 0;
      que.push(Q{0, s});
      while(!que.empty()){
        int v = que.top().to; que.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        if (v == t) break;
        for (int i = 0; i < int(g[v].size()); ++i) {
          auto& e = g[v][i];
          if (vis[e.to] || !e.cap) continue;
          Cost cost = e.cost-dual[e.to]+dual[v];
          if(dist[e.to]-dist[v] > cost ) {
            dist[e.to] = dist[v]+cost ; 
            pv[e.to] = v; pe[e.to] = i;
            que.push(Q{dist[e.to],e.to});
          }
        }
      }
    };
    auto dual_ref = [&]() {
      fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
      fill(pv.begin(), pv.end(), -1);
      fill(pe.begin(), pe.end(), -1);
      fill(vis.begin(), vis.end(), 0);
      if (negative) {
        bellmanford();
        negative = false;
      }
      else {
        dijkstra();
      }
      if (!vis[t]) return false;
      for (int v = 0; v < _n; ++v) {
        if (!vis[v]) continue;
        dual[v] -= dist[t]-dist[v];
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost_per_flow = -1;
    vector<pair<Cap, Cost>> result;
    result.emplace_back(flow, cost);
    while(flow < flow_limit){
      if(!dual_ref()) break;
      Cap c = flow_limit-flow;
      for(int v = t; v != s; v = pv[v]){
        c = min(c, g[pv[v]][pe[v]].cap);
      }
      for(int v = t; v != s; v=pv[v]) {
        auto& e = g[pv[v]][pe[v]];
        e.cap -= c;
        g[v][e.rev].cap += c;
      }
      Cost d = -dual[s];
      flow += c;
      cost += c*d;
      if (prev_cost_per_flow == d) {
        result.pop_back();
      }
      result.emplace_back(flow, cost);
      prev_cost_per_flow = d;
    }
    return result;
  }
 private:
  int _n;
  struct _edge { int to, rev; Cap cap; Cost cost;};
  vector<pair<int, int>> pos;
  vector<vector<_edge>> g;
  bool negative;
};
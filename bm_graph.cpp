// bipertite matching
// O(E*sqrt(V)) (E: num of edges, V: num of vertexes)
struct bm_graph {
 public:
  bm_graph(int n, int m)
    : _n(n), _m(m), g(n), d(n+m, -1) {}
  void add_edge(int from, int to) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _m);
    g[from].push_back(_n+to);
  }
  int calc() {
    vector<int> level(_n), used(_n);
    auto bfs = [&]() {
      fill(level.begin(), level.end(), -1);
      queue<int> que;
      for (int i = 0; i < _n; ++i) {
        if (d[i] == -1) {
          level[i] = 0;
          que.push(i);
        }
      }
      while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto& u : g[v]) {
          int w = d[u];
          if (w < 0 || level[w] >= 0) continue;
          level[w] = level[v]+1;
          que.push(w);
        }
      }
    };
    auto dfs = [&](auto self, int v)->bool {
      used[v] = 1;
      for (auto& u : g[v]) {
        int w = d[u];
        if (w < 0 || (!used[w] && level[w] > level[v] && self(self, w))) {
          d[v] = u;
          d[u] = v;
          return true;
        }
      }
      return false;
    };
    int flow = 0;
    for (;;) {
      bfs();
      fill(used.begin(), used.end(), 0);
      int f = 0;
      for (int i = 0; i < _n; ++i) {
        if (d[i] == -1 && dfs(dfs, i)) ++f;
      }
      if (!f) break;
      flow += f;
    }
    return flow;
  }
  int match_left(int i) {
    assert(0 <= i && i < _n);
    return d[i];
  }
  int match_right(int i) {
    assert(0 <= i && i < _m);
    return d[_n+i];
  }
 private:
  int _n, _m;
  vector<vector<int>> g;
  vector<int> d;
};
//
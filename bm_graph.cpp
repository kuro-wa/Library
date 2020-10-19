// bipertite matching
// O(E*sqrt(V)) (E: num of edges, V: num of vertexes)
struct bm_graph {
 public:
  bm_graph(int n, int m)
    : _n(n), _m(m), g(n), match(n+m, -1) {}
  void add_edge(int from, int to) {
    assert(0 <= from && from < _n);
    assert(_n <= to && to < _n+_m);
    g[from].push_back(to);
  }
  int calc() {
    vector<int> level(_n), used(_n);
    auto bfs = [&]() {
      fill(level.begin(), level.end(), -1);
      queue<int> que;
      for (int i = 0; i < _n; ++i) {
        if (match[i] == -1) {
          que.push(i);
          level[i] = 0;
        }
      }
      while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto& u : g[v]) {
          int w = match[u];
          if (w < 0 || level[w] >= 0) continue;
          level[w] = level[v]+1;
          que.push(w);
        }
      }
    };
    function<bool(int)> dfs = [&](int v) {
      used[v] = 1;
      for (auto& u : g[v]) {
        int w = match[u];
        if (w >= 0) {
          if (used[w]) continue;
          if (level[w] != level[v]+1) continue;
          if (!dfs(w)) continue;
        }
        match[v] = u;
        match[u] = v;
        return true;
      }
      return false;
    };
    int flow = 0;
    while (1) {
      bfs();
      fill(used.begin(), used.end(), 0);
      int f = 0;
      for (int i = 0; i < _n; ++i) {
        if (match[i] == -1 && dfs(i)) ++f;
      }
      if (f == 0) return flow;
      flow += f;
    }
  }
  int get_pair(int n) {
    assert(0 <= n && n < _n+_m);
    return match[n];
  }
 private:
  int _n, _m;
  vector<vector<int>> g;
  vector<int> match;
};
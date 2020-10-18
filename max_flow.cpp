// max flow
// antbook p190
const int INF = 1001001001;
struct Edge {
  Edge(int to=0, int cap=0, int rev=0)
    : to(to), cap(cap), rev(rev) {}
  int to, cap, rev; // to, capacity, reverse
};
struct MaxFlow {
  vector<vector<Edge>> G;
  vector<bool> used;
  // n: num of vertexes
  MaxFlow(int n) : G(n), used(n) {}
  // Adds an edge
  void add_edge(int from, int to, int cap) {
    G[from].emplace_back(to, cap, (int)G[to].size());
    G[to].emplace_back(from, 0, (int)G[from].size()-1);
  }
  // Finds an augmenting path by DFS
  int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
      Edge &e = G[v][i];
      if (!used[e.to] && e.cap > 0) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  // Returns max flow of s->t
  int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
      fill(used.begin(), used.end(), false);
      int f = dfs(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
};
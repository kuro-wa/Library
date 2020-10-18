#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

[UnionFind]

// AntBook p101
// Kruskal's algorithm
struct Edge {
  int u, v;
  ll cost;
  Edge(int u=0, int v=0, ll cost=0): 
    u(u), v(v), cost(cost) {}
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
};

int main() {
  int V; // num of vertexes
  int E; // num of edges
  vector<Edge> es(E); 
  // Input edges here

  sort(es.begin(), es.end());
  UnionFind uf(V);
  ll res = 0;
  for (Edge e: es) {
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  cout << res << endl;
  return 0;
}
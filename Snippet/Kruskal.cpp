// Kruskal's algorithm
// AntBook p101
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

struct Edge {
  int u, v;
  long long cost;
  Edge(int u=0, int v=0, long long cost=0) : u(u), v(v), cost(cost) {}
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
};

int main() {
  int n; // num of vertexes
  vector<Edge> es; // edges
  // Input edges here

  sort(es.begin(), es.end());
  dsu d(n);
  long long res = 0; // total cost
  for (Edge e : es) {
    if (!d.same(e.u, e.v)) {
      d.merge(e.u, e.v);
      res += e.cost;
    }
  }
  return 0;
}
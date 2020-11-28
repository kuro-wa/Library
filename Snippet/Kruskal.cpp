// AntBook p101
// Kruskal's algorithm
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

struct E {
  int u, v;
  long long co;
  E(int u=0, int v=0, long long co=0) : u(u), v(v), co(co) {}
  bool operator<(const E& e) const {
    return co < e.co;
  }
};

int main() {
  int n; // num of vertexes
  vector<E> es; // edges
  // Input edges here

  sort(es.begin(), es.end());
  dsu d(n);
  long long res = 0; // total cost
  for (E e: es) {
    if (!d.same(e.u, e.v)) {
      d.merge(e.u, e.v);
      res += e.co;
    }
  }
  return 0;
}
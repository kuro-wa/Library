// Prim's algorithm
// AntBook p100
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, cost;
  Edge(int to=0, int cost=0) : to(to), cost(cost) {}
};
const long long LINF = 1001002003004005006ll;

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<Edge>> g(n);
  // Input edges here

  vector<long long> mincost(n, LINF); // min cost from set X
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  long long res = 0; // total cost
  auto push = [&](int v, long long d) {
    if (mincost[v] != LINF) return;
    mincost[v] = d;
    res += d;
    for (Edge e : g[v]) {
      if (mincost[e.to] != LINF) continue;
      q.emplace(e.cost, e.to);
    }
  };
  push(0, 0);
  while (!q.empty()) {
    auto [d, v] = q.top(); q.pop();
    push(v, d);
  }
  return 0;  
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// AntBook p100
// Prim's algorithm
using LP = pair<ll, int>;

const ll INF = 1e18;

struct Edge {
  int to, co;
  Edge(int to = 0, int co = 0): to(to), co(co) {}
};

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<Edge>> g(n);
  // Input edges here

  vector<ll> mincost(n, INF);
  priority_queue<LP, vector<LP>, greater<LP>> q;
  ll res = 0;
  auto push = [&](int v, ll x) {
    if (mincost[v] != INF) continue;
    mincost[v] = x;
    res += x;
    for (Edge e: g[v]) {
      if (mincost[e.to] != INF) continue;
      q.emplace(e.cost, e.to);
    }
  };
  push(0, 0);
  while (!q.empty()) {
    ll x = q.top().first;
    int v = q.top().second;
    q.pop();
    push(v, x);
  }
  return 0;  
}
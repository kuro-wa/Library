

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ABC175F, AntBook p97
// Dijkstra's algorithm
using LP = pair<ll, int>;

const ll INF = 1e18;

struct Edge {
  int to, co;
  Edge(int to=0, int co=0): to(to), co(co) {}
};

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<Edge>> g(n);
  // Input edges here

  #if 1
  // Regular Dijkstra
  vector<ll> dist(n, INF);
  priority_queue<LP, vector<LP>, greater<LP>> q;
  // A function trying to update dist[v] by x
  auto push = [&](int v, ll x) {
    if (dist[v] <= x) return;
    dist[v] = x;
    q.emplace(x, v);
  };
  int s = 0; // the start
  push(s, 0);
  while (!q.empty()) {
    ll x = q.top().first;
    int v = q.top().second;
    q.pop();
    if (dist[v] != x) continue;
    for (Edge e: g[v]) {
      push(e.to, x+e.co);
    }
  }
  #endif

  #if 1
  // Shortest path reproduction
  vector<ll> dist(n, INF);
  priority_queue<LP, vector<LP>, greater<LP>> q;
  vector<int> pre(n);
  // A function trying to update dist[v] by x
  // Returns whether updated
  auto push = [&](int v, ll x, int p=-1) {
    if (dist[v] <= x) return;
    dist[v] = x;
    q.emplace(x, v);
    pre[v] = p;
  };
  int s = 0; // the start
  push(s, 0);
  while (!q.empty()) {
    ll x = q.top().first;
    int v = q.top().second;
    q.pop();
    if (dist[v] != x) continue;
    for (Edge e: g[v]) {
      push(e.to, x+e.co, v);
    }
  }
  int t = n-1; // the goal
  vector<int> path;
  for (; t!= -1; t = pre[t]) {
    path.push_back(t);
  }
  reverse(path.begin(), path.end());
  #endif
  return 0;  
}
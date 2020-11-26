#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<int>> to(n);
  // Input edges here

  vector<int> dist(n, INF);
  queue<int> q;
  auto push = [&](int v, int d) {
    if (dist[v] != INF) return;
    dist[v] = d;
    q.emplace(v);
  };

  int s = 0; // the start
  push(s, 0);

  while (!q.empty()){
    int v = q.front(); q.pop();
    for (int u: to[v]) {
      push(u, dist[v]+1);
    }
  }
  return 0;
}
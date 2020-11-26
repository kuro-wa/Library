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

  int s = 0; // the start
  dist[s] = 0;
  q.push(s);

  while (!q.empty()){
    int v = q.front(); q.pop();
    for (int u: to[v]) {
      if (dist[u] != INF) continue;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  return 0;
}
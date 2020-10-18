/*input
6 9
3 4
6 1
2 4
5 3
4 6
1 5
6 2
4 5
5 6
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<int>> to(n);
  // Input edges here

  vector<int> dist(n, INF);
  queue<int> q;
  auto push = [&](int v, int x) {
    if (dist[v] != INF) return;
    dist[v] = x;
    q.push(v);
  };
  int s = 0; // the start
  push(s, 0);
  while (!q.empty()){
    int v = q.front(); q.pop();
    for (int u: to[v]) {
      push(u, dist[v]+1);
    }
  }
}
// Dijkstra's algorithm
// ABC175F, AntBook p97
#include <bits/stdc++.h>
using namespace std;

struct E {
  int to, co;
  E(int to=0, int co=0) : to(to), co(co) {}
};
const long long LINF = 1001002003004005006ll;

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<vector<E>> g(n);
  // Input edges here

  // Regular Dijkstra
  {
    vector<long long> dist(n, LINF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    // A function trying to update dist[v] by d
    auto push = [&](int v, long long d) {
      if (dist[v] <= d) return;
      dist[v] = d;
      q.emplace(d, v);
    };
    int s = 0; // the start
    push(s, 0);
    while (!q.empty()) {
      auto [d, v] = q.top(); q.pop();
      if (dist[v] != d) continue;
      for (E e: g[v]) {
        push(e.to, d+e.co);
      }
    }
  }
  
  // Shortest path reproduction
  {
    vector<long long> dist(n, LINF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<int> pre(n);
    // A function trying to update dist[v] by d
    auto push = [&](int v, long long d, int p=-1) {
      if (dist[v] <= d) return;
      dist[v] = d;
      q.emplace(d, v);
      pre[v] = p;
    };
    int s = 0; // the start
    push(s, 0);
    while (!q.empty()) {
      auto [d, v] = q.top(); q.pop();
      if (dist[v] != d) continue;
      for (E e: g[v]) {
        push(e.to, d+e.co, v);
      }
    }
    int t = n-1; // the goal
    vector<int> path;
    for (; t!= -1; t = pre[t]) {
      path.push_back(t);
    }
    reverse(path.begin(), path.end());
  }
  return 0;  
}
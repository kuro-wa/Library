

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// AntBook p 95
// Bellman-Ford algorithm
const ll INF = 1e18;

struct Edge {
  int from, to;
  ll cost;
  Edge(int from=0, int to=0, ll cost=0): 
    from(from), to(to), cost(cost) {}
};

int main() {
  int V; // num of vertexes
  int E; // num of edges
  cin >> V >> E;
  vector<Edge> es; // edges
  // Input edges here

  // A function to execute Bellman-Ford algorithm
  // Returns false if updated V-1 times
  auto bermanford = [&](vector<ll> &d) {
    rep(i, V) {
      for (Edge e: es){
        if (d[e.from] == INF) continue;
        if (d[e.to] <= d[e.from]+e.cost) continue;
        d[e.to] = d[e.from]+e.cost;
        if (i == V-1) return false;
      }
    }
    return true;
  };

  vector<ll> d;

  // Find a negative loop
  d = vector<ll>(V);
  if (!bermanford(d)) {
    cout << "A negative loop exists." << endl;
    return 0;
  }

  // Compute shortest distances
  d = vector<ll>(V, INF); // the shortest distances
  int s = 0; // the start
  d[s] = 0;
  bermanford(d);
  rep(i, V) cout << d[i] << endl;
  return 0;
}
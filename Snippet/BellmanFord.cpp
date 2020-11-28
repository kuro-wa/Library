// Bellman-Ford algorithm
// AntBook p95
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to;
  long long cost;
  Edge(int from=0, int to=0, long long cost=0) : from(from), to(to), cost(cost) {}
};
const long long LINF = 1001002003004005006ll;

int main() {
  int n; // num of vertexes
  cin >> n;
  vector<Edge> es; // edges
  // Input edges here

  // A function to execute Bellman-Ford algorithm
  // Returns false if updated dist.size() times
  auto bermanford = [&](vector<long long> &dist) {
    for (int i = 0; i < (int)dist.size(); ++i) {
      for (Edge e: es){
        if (dist[e.from] == LINF) continue;
        if (dist[e.to] <= dist[e.from]+e.cost) continue;
        dist[e.to] = dist[e.from]+e.cost;
        if (i == (int)dist.size()-1) return false;
      }
    }
    return true;
  };

  vector<long long> dist;

  // Find a negative loop
  dist = vector<long long>(n);
  if (!bermanford(dist)) {
    // A negative loop exists!
    // Do something
  }

  // Find the shortest path
  dist = vector<long long>(n, LINF);
  int s = 0; // the start
  dist[s] = 0;
  bermanford(dist);
  return 0;
}
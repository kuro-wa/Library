

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// antbook p190
const int INF = 1001001001;
struct Edge {int to, cap, rev;}; // to, capacity, reverse
struct MaxFlow {
    vector<vector<Edge>> G;
    vector<bool> used;
    // n: num of vertexes
    MaxFlow(int n): G(n, vector<Edge>()), used(n) {}
    // adds an edge: capacity is cap, from->to
    void add_edge(int from, int to, int cap) {
        G[from].push_back((Edge){to, cap, (int)G[to].size()});
        G[to].push_back((Edge){from, 0, (int)G[from].size()-1});
    }
    // finds an augmenting path by DFS
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    // max flow of s->t
    int max_flow(int s, int t) {
        int flow = 0;
        for(;;) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

int main() {
}
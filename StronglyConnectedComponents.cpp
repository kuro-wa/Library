#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// antbook p286
struct StronglyConnectedComponent {
private:
    int V; // num of vertexes
    vector<vector<int>> G; // adjacency list
    vector<vector<int>> rG; // relverse adjacency list
public:
    vector<int> vs; // numbering
    vector<bool> used; // whether checked or not
    vector<int> cmp; // topological order of the storongly connected component

    // n: num of vertexes
    StronglyConnectedComponent(int n):
      V(n), G(n, vector<int>()), rG(n, vector<int>()),
      vs(n), used(n), cmp(n) {};

    void add_edge(int from, int to) {
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            if (!used[G[v][i]]) dfs(G[v][i]);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (int i = 0; i < rG[v].size(); i++) {
            if (!used[rG[v][i]]) rdfs(rG[v][i], k);
        }
        vs.push_back(v);
    }

    int build() {
        fill(used.begin(), used.end(), false);
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs(v);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for (int i = vs.size()-1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};

int main() {
}
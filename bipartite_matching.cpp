// antbook p197
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

const int MAX_V = 1001001;
const int INF = 1001001001;

int V;
vector<int> G[MAX_V];
int match[MAX_V]; // matching pair
bool used[MAX_V];

// add edge u - v
void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

// find increasing pass by DFS
bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

//max flow s -> t
int bipartite_matching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) res++;
        }
    }
    return res;
}

int main() {
    int E;
    cin >> V >> E;
    rep(i, E) {
        int a, b, t;
        cin >> a >> b >> t;
        add_edge(a, b, t);
    }
    cout << bipartite_matching() << endl;
}
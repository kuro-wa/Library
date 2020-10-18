

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// AtCoder, AntBook p84
// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  // n: num of elements
  UnionFind(int n=0): d(n,-1) {}
  // Returns x's parent
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  // Unites x's groupe and y's group
  // Returns false if already united
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  // Returns whether x and y belong to the same groupe
  bool same(int x, int y) { return find(x) == find(y);}
  // Returns size of x's group
  int size(int x) { return -d[find(x)];}
};

int main() {
  // UnionFind uf(n);
  return 0;
}


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// AntBook p164
// Lazy Segment Tree
template<typename T>
struct LazySegmentTree {
  int n;
  vector<T> d, dl;
  // n_: num of elements
  LazySegmentTree(int n_=0):
    LazySegmentTree(vector<T>(n_, e())) {}
  // v: an initialization vector
  LazySegmentTree(const vector<T>& v) {
    int n_ = v.size();
    n = 1;
    while (n < n_) n *= 2;
    d.resize(2*n-1, e());
    dl.resize(2*n-1, e());
    for (int i = 0; i < n_; ++i) d[i+n-1] = v[i];
    for (int i = n-2; i >= 0; --i) {
      d[i] = d[i*2+1]+d[i*2+2];
    }
  }
  // Adds x to [a, b)
  // Use like add(a, b, x)
  void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    if  (r < 0) r = n;
    // Intersection of [a, b) and [l, r) is empty
    if (r <= a || b <= l) return;
    // [a, b) includes [l, r)
    if (a <= l && r <= b) {
      dl[k] += x;
      return;
    }
    d[k] += x*(min(b, r)-max(a, l));
    add(a, b, x, k*2+1, l, (l+r)/2);
    add(a, b, x, k*2+2, (l+r)/2, r);
    return;
  }
  // Returns sum of [a, b)
  // Use like query(a, b)
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if  (r < 0) r = n;
    // Intersection of [a, b) and [l, r) is empty
    if (r <= a || b <= l) return e();
    // [a, b) includes [l, r)
    if (a <= l && r <= b) return d[k]+dl[k]*(r-l);
    // Return sum of 2 children
    T res = dl[k]*(min(b, r)-max(a, l));
    res += query(a, b, k*2+1, l, (l+r)/2);
    res += query(a, b, k*2+2, (l+r)/2, r);
    return res;
  }

  // the identtity element
  T e() {
    return 0;
  }
};

int main() {
  // LazySegmentTree<int> t(n);
  return 0;
}
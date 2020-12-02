// Fenwick Tree (Binary Indexed Tree)
template<class T>
struct fenwick_tree {
 public:
  fenwick_tree(int n=0) : _n(n), d(n) {}
  void add(int p, T x) {
    assert(0 <= p && p < _n);
    for (++p; p <= _n; p += p&-p) {
      d[p-1] += x;
    }
  }
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r)-sum(l);
  }
 private:
  int _n;
  vector<T> d;
  T sum(int r) {
    T s = 0;
    for (; r; r -= r&-r) {
      s += d[r-1];
    }
    return s;
  }
};
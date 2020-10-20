// 2-dimensional Fenwick Tree (Binary Indexed Tree)
template<class T>
struct fenwick_tree2D {
 public:
  fenwick_tree2D(int n=0, int m=0) 
    : _n(n), _m(m), d(n, vector<T>(m)) {}
  void add(int p, int q, T x) {
    assert(0 <= p && p < _n);
    assert(0 <= q && q < _m);
    for (int i = p+1; i <= _n; i += i&-i) {
      for (int j = q+1; j <= _n; j += j&-j) {
        d[i-1][j-1] += x;
      }
    }
  }
  T sum(int x1, int x2, int y1, int y2) {
    assert(0 <= x1 && x1 < _n);
    assert(x1 <= x2 && x2 <= _n);
    assert(0 <= y1 && y1 < _m);
    assert(y1 <= y2 && y2 <= _m);
    return sum(x2, y2)-sum(x1, y2)-sum(x2, y1)+sum(x1, y1);
  }
 private:
  int _n, _m;
  vector<vector<T>> d;
  T sum(int x, int y) {
    T s = 0;
    for (int i = x; i; i -= i&-i) {
      for (int j = y; j; j -= j&-j) {
        s += d[i-1][j-1];
      }
    }
    return s;
  }
};
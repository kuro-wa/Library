// Segment Tree
template<class S, S (*op)(S, S), S(*e)()>
struct segtree {
 public:
  segtree(int n=0): segtree(vector<S>(n, e())) {}
  segtree(const vector<S>& v) : _n(int(v.size())) {
    size = 1;
    while (size < _n) size <<= 1;
    d = vector<S>(2*size, e());
    for (int i = 0; i < _n; ++i) d[size+i] = v[i];
    for (int i = size-1; i >= 1; --i) {
      update(i);
    }
  }
  void set(int p, S x) {
    p += size;
    d[p] = x;
    while (p) update(p >>= 1);
  }
  S get(int p) {
    assert(0 <= p && p < _n);
    return d[p+size];
  }
  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;
    while (l < r) {
      if (l&1) sml = op(sml, d[l++]);
      if (r&1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  S all_prod() { return d[1];}
 private:  
  int _n, size;
  vector<S> d;
  void update(int k) { d[k] = op(d[2*k], d[2*k+1]);}
};
// Rewrite the following!!
int e() { return -1001001001;}
int op(int a, int b) { return max(a, b);}
//

int main() {
  segtree<int, op, e> t(n);
  return 0;
}
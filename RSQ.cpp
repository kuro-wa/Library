// RAQ (Range Add Query) and RSQ (Range Sum Query)
// by Lazy Segtree
template<typename T>
struct RSQ {
  using F = T;
 public:
  RSQ(int n=0) : RSQ(vector<T>(n, T(0))) {}
  RSQ(const vector<T>& v) {
    int n = int(v.size());
    vector<S> w(n, S());
    for (int i = 0; i < n; ++i) w[i].x = v[i];
    d = lseg(w);
  }
  void set(int p, T x) { d.set(p, S(x, 1));}
  T get(int p) { return d.get(p).x;}
  T prod(int l, int r) { return d.prod(l, r).x;}
  T all_prod() { return d.all_prod().x;}
  void apply(int p, F f) { d.apply(p, f);}
  void apply(int l, int r, F f) { d.apply(l, r, f);}
 private:
  struct S {
    T x; int l;
    S(T x=T(0), int l=1) : x(x), l(l) {}
  };
  static S op(S a, S b) { return S(a.x+b.x, a.l+b.l);}
  static S e() { return S(T(0), 0);}
  static S mapping(F f, S s) { return S(s.x+s.l*f, s.l);}
  static F composition(F f, F g) { return f+g;}
  static F id() { return F(0);}
  using lseg = lazy_segtree<S, op, e, F, mapping, composition, id>;
  lseg d;
};
//
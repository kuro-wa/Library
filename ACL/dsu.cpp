// DSU (Disjoint Det Union, Union-Find)
struct dsu {
 public:
  dsu(int n=0) : _n(n), d(n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-d[x] < -d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return x;
  }
  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  int leader(int a) {
    assert(0 <= a && a < _n);
    if (d[a] < 0) return a;
    return d[a] = leader(d[a]);
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -d[leader(a)];
  }
  vector<vector<int>> groups() {
    vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; ++i) {
      leader_buf[i] = leader(i);
      ++group_size[leader_buf[i]];
    }
    vector<vector<int>> res(_n);
    for (int i = 0; i < _n; ++i) {
      res[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; ++i) {
      res[leader_buf[i]].push_back(i);
    }
    res.erase(
      remove_if(res.begin(), res.end(),
        [&](const vector<int>& v) { return v.empty();}
      ), res.end()
    );
    return res;
  }
 private:
  int _n;
  vector<int> d;
};
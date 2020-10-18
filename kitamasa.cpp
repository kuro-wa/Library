// Kitamasa's algorithm
// Need to define '+' and '*' on T
template<typename T, T (*zero)(), T (*one)()>
struct kitamasa {
 public:
  kitamasa(const vector<T>& v) : cs(v), rs(1), m(v.size()) {
    rs[0] = vector<T>(2*m+1, zero());
    rs[0][1] = one();
  }
  T calc(const vector<T>& a, long long n) {
    assert((int)(a.size()) == m && n >= 0);
    vector<T> res(rs[0]);
    for (int i = 0; n; ++i, n >>= 1) {
      if (i >= (int)(rs.size())) {
        rs.push_back(merge(rs[i-1], rs[i-1]));
      }
      if (n&1) res = merge(res, rs[i]);
    }
    T ans = zero();
    for (int i = 1; i <= m; ++i) ans = ans+(res[i]*a[i-1]);
    return ans;
  }
 private:
  vector<T> cs;
  vector<vector<T>> rs;
  int m;
  vector<T> merge(const vector<T>& xs, const vector<T>& ys) {
    vector<T> zs(2*m+1, zero());
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= m; ++j) {
        zs[i+j] = zs[i+j]+(xs[i]*ys[j]);
      }
    }
    for (int i = 2*m; i > m; zs[i--] = zero()) {
      for (int j = 1; j <= m; ++j) {
        zs[i-j] = zs[i-j]+(cs[m-j]*zs[i]);
      }
    }
    return zs;
  }
};
// Rewrite the following!!
int zero() { return (int)(0);}
int one() { return (int)(1);}
//

int main() {
  kitamasa<int, zero, one> d({1,1});
  return 0;
} 
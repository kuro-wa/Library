// dynamic auto mod int
struct dynamic_modint {
  using mint = dynamic_modint;
 public:
  static int mod() { return (int)(umod());}
  static void set_mod(int m_) {
    assert(m_ >= 1);
    m = m_;
  }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }
  dynamic_modint(long long v=0) {
    long long x = (long long)(v%(long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  unsigned int val() const { return _v;}
  mint& operator++(){ if (++_v == umod()) _v = 0; return *this;}
  mint& operator--(){ if (_v-- == umod()) _v = umod()-1; return *this;}
  mint operator++(int){ mint res = *this; ++*this; return res;}
  mint operator--(int){ mint res = *this; --*this; return res;}
  mint& operator+=(const mint& rhs) {
    if ((_v += rhs._v) >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    if ((_v -= rhs._v) >= umod()) _v += umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    _v = (unsigned int)((unsigned long long)(_v)*rhs._v%umod());
    return *this;
  }
  mint operator+() const { return *this;}
  mint operator-() const { return mint()-*this;}
  mint pow(long long n) const {
    assert(n >= 0);
    mint x = *this, res = 1;
    while (n) {
      if (n&1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs;}
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs;}
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs;}
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v;}
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v;}
  friend istream& operator>>(istream& is, mint& a) { return is >> a._v;}
  friend ostream& operator<<(ostream& os, const mint& a) { return os << a._v;}

  // for prime mod
  mint inv() const { return pow(umod()-2);}
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv();}
  mint operator/(const mint& rhs) const { return mint(*this) /= rhs;}
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs;}
 private:
  unsigned int _v;
  static unsigned int m;
  static unsigned int umod() { return m;}
};
unsigned int dynamic_modint::m = 998244353;
using mint = dynamic_modint;
// Start with "mint::set_mod"!!
//

int main() {
  mint::set_mod(998244353);
  return 0;
}
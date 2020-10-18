#include <bits/stdc++.h>
using namespace std;

// polynomial
template <typename T, int m=3005>
struct polynomial {
  using poly = polynomial;
 public:
  polynomial(T a=0) : polynomial(vector<T>{a}) {}
  polynomial(const vector<T>& v) : d(v) {}
  T coef(int n) {
    assert(n >= 0);
    if (n >= d.size()) return T(0);
    else return d[n];
  }
  vector<T> all_coef() { fix(); return d;}
  int deg() { return fix()-1;}
  T operator()(T x) {
    int sz = d.size();
    T res = 0, val = 1;
    for (int i = 0; i < sz; ++i) {
      res += val*d[i];
      val *= x;
    }
    return res;
  }
  poly& operator+=(const poly& rhs) {
    int sz = rhs.d.size();
    if (d.size() < sz) d.resize(sz);
    for (int i = 0; i < sz; ++i) d[i] += rhs.d[i];
    return *this;
  }
  poly& operator-=(const poly& rhs) {
    int sz = rhs.d.size();
    if (d.size() < sz) d.resize(sz);
    for (int i = 0; i < sz; ++i) d[i] -= rhs.d[i];
    return *this;
  }
  poly& operator*=(const poly& rhs) {
    int sz = rhs.d.size();
    d.resize(min((int)d.size()+sz-1, m));
    for (int i = d.size()-1; i >= 0; --i) {
      if (d[i] == 0) continue;
      for (int j = sz-1; j >= 1; --j) {
        if (i+j >= m) continue;
        d[i+j] += d[i]*rhs.d[j];
      }
      d[i] *= rhs.d[0];
    }
    return *this;
  }
  poly& operator/=(const poly& rhs) {
    int sz = rhs.d.size();
    while (sz && rhs.d[sz-1] == 0) --sz;
    assert(sz);
    vector<T> v(d.size()-sz+1);
    for (int i = d.size()-1; i >= sz-1; --i) {
      v[i-sz+1] = d[i]/rhs.d[sz-1];
      for (int j = sz-2; j >= 0; --j) {
        d[i-sz+1+j] -= v[i-sz+1]*rhs.d[j];
      }
    }
    d = v;
    return *this;
  }
  poly& operator%=(const poly& rhs) {
    int sz = rhs.d.size();
    while (sz && rhs.d[sz-1] == 0) --sz;
    assert(sz);
    for (int i = d.size()-1; i >= sz-1; --i) {
      T x = d[i]/rhs.d[sz-1];
      for (int j = sz-2; j >= 0; --j) {
        d[i-sz+1+j] -= x*rhs.d[j];
      }
    }
    d.resize(sz-1);
    return *this;
  }
  poly operator+() const { return *this;}
  poly operator-() const { return poly()-*this;}
  poly pow(long long n) const {
    assert(n >= 0);
    poly x = *this, res = 1;
    while (n) {
      if (n&1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  poly diff() {
    int sz = d.size();
    if (sz == 1) return poly();
    poly res;
    res.d.resize(sz-1);
    for (int i = 1; i < sz; ++i) {
      res.d[i-1] = d[i]*i;
    }
    return res;
  }
  poly integ() {
    int sz = d.size();
    poly res;
    res.d.resize(sz+1);
    for (int i = 0; i < sz; ++i) {
      res.d[i+1] = d[i]/(i+1);
    }
    return res;
  }
  T d_integ(T l, T r) {
    if (l != 0) return d_integ(0, r)-d_integ(0, l);
    int sz = d.size();
    T res = 0, val = 1;
    for (int i = 0; i < sz; ++i) {
      val *= r;
      res += val*d[i]/(i+1);
    }
    return res;
  }
  friend poly operator+(const poly& lhs, const poly& rhs) { return poly(lhs) += rhs;}
  friend poly operator-(const poly& lhs, const poly& rhs) { return poly(lhs) -= rhs;}
  friend poly operator*(const poly& lhs, const poly& rhs) { return poly(lhs) *= rhs;}
  friend poly operator/(const poly& lhs, const poly& rhs) { return poly(lhs) /= rhs;}
  friend poly operator%(const poly& lhs, const poly& rhs) { return poly(lhs) %= rhs;}
 private:
  vector<T> d;
  int fix() {
    int sz = d.size();
    while (sz && d[sz-1] == 0) --sz;
    d.resize(max(sz, 1));
    return sz;
  }
};
// Choose the type!!
using poly = polynomial<long long>;
//

int main() {
  return 0;
}

// for modint
#if 1
const int MX = 3005;
using poly = polynomial<mint, MX>;
mint invs[MX];
mint operator/(const mint& a, const int b) {
  return a*invs[b];
}

int main() {
  for (int i = 1; i < MX; ++i) invs[i] = mint(i).inv();
  return 0;
}
#endif
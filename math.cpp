// Solves a*x+b*y=gcd(a, b) and returns gcd(a, b)
// AntBook p109
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  x = 1, y = 0;
  T u = 0, v = 1;
  while (b) {
    T t = a/b;
    a -= t*b; swap(a, b);
    x -= t*u; swap(x, u);
    y -= t*v; swap(y, v);
  }
  if (a < 0) x *= -1, y *= -1, a *= -1;
  return a;
}

// Enumerate divisors of x
vector<long long> divisor(long long x) {
  vector<long long> res;
  for (long long i = 1; i*i <= x; ++i) {
    if (x%i == 0) {
      res.emplace_back(i);
      if(i*i != x) res.emplace_back(x/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

// Returns x^n mod(m)
// AntBook p115
long long pow_mod(long long x, long long n, long long m) {
  assert(n >= 0 && m >= 1);
  long long res = 1, y = (x%m+m)%m;
  while (n) {
    if (n&1) res = res*y%m;
    y = y*y%m;
    n >>= 1;
  }
  return res;
}
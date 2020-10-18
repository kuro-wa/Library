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
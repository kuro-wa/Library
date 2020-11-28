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
// AntBook p109
// Solves a*x+b*y=gcd(a, b) and returns gcd(a, b)
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if (b == 0) {
    if (d > 0) x = 1;
    else x = -1, d *= -1;
    y = 0;
  }
  else {
    d = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
  }
  return d;
}
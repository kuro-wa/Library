const double eps = 1e-10;
bool equal(double a, double b) { return abs(a-b) < eps;}

struct V {
  double x, y;
  V(double x=0, double y=0) : x(x), y(y) {}
  V operator+(const V& p) const { return V(x+p.x, y+p.y);}
  V operator-(const V& p) const { return V(x-p.x, y-p.y);}
  V operator*(double a) const { return V(x*a, y*a);}
  double sqnorm() { return x*x+y*y;}
  double norm() { return sqrt(x*x+y*y);}
  V rot90() { return V(-y, x);}
};

struct Circle {
  V o;
  double r;
  Circle(V o=V(), double r=0) : o(o), r(r) {}
  vector<V> intersections(const Circle& c) {
    V v = c.o-o;
    double d = v.norm();
    if (equal(d, 0)) return {};
    if (equal(d+r+c.r, max({d, r, c.r})*2)) {
      if (equal(d+r, c.r)) return {o-v*(r/d)};
      else return {o+v*(r/d)};
    }
    if (d+r+c.r < max({d, r, c.r})*2) return {};
    double x = (d*d+r*r-c.r*c.r)/(2*d);
    double y = sqrt(r*r-x*x);
    V leg = o+v*(x/d);
    v = v.rot90();
    return {leg+v*(y/d), leg-v*(y/d)};
  }
  bool include(const V& p) {
    return (p-o).norm() < r+eps;
  }
};
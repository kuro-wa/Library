// antbook p234
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

double EPS = 1e-10;

// addition considering error
double add(double a, double b) {
    if (abs(a+b) < EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

// 2D vector
struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(P p) {return P(add(x, p.x), add(y, p.y));}
    P operator-(P p) {return P(add(x, -p.x), add(y, -p.y));}
    P operator*(double d) {return P(x*d, y*d);}
    double dot(P p) { // dot-prodauct
        return add(x*p.x, y*p.y);
    }
    double det(P p) { // cross-product
        return add(x*p.y, -y*p.x);
    }
};
// output for debug
ostream& operator<<(ostream& os, const P& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
// compare in lexical order
bool cmp_x(const P& p, const P& q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

// find convex hull
vector<P> convex_hull(vector<P> ps, int n) {
    sort(ps.begin(), ps.end(), cmp_x);
    int k = 0; // num of convex hull vertex
    vector<P> qs(n*2); // under construction

    // draw convex hull on bottom side
    for (int i = 0; i < n; i++) {
        while (k > 1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }

    // draw convex hull on top side
    for (int i = n-2, t = k; i >= 0; i--) {
        while (k > t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

// (distance)^2
double dist(P p, P q) {
    return (p-q).dot(p-q);
}

int main() {
}
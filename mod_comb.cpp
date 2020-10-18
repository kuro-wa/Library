

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// from atcoder live
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 10007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
 
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// antbook p263
// combination mod prime
// use when prime is small
struct mod_comb {
    vector<mint> fact;
    mod_comb() {
        fact.resize(mod);
        fact[0] = 1;
        for (int i = 1; i < mod; ++i) fact[i] = fact[i-1]*i;
    }
    // retutn a mod (mod) of n! = a*mod^e, O(log_mod n)
    mint mod_fact(int n, int &e) {
        e = 0;
        if (n == 0) return 1;
        // compute part of multiple of p
        mint res = mod_fact(n/mod, e);
        e += n/mod;
        // (p-1)! = -1 mod p so (p-1)1^(n/p) is computed by prity of n/p
        if (n/mod%2 != 0) return res*(-fact[n%mod]);
        return res*fact[n%mod];
    }
    // antbook p109
    // find (x, y) satisfying ax+by=gcd(a, b) and return gcd(a, b)
    int extgcd(int a, int b, int &x, int &y) {
        int d = a;
        if (b == 0) {
            x = 1;
            y = 0;
        }
        else {
            d = extgcd(b, a%b, y, x);
            y -= (a/b)*x;
        }
        return d;
    }
    mint mod_inverse(int n) {
        int x, y;
        extgcd(n, mod, x, y);
        return x;
    }
    // returns nCk, O(log_p n)
    mint operator()(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        int e1, e2, e3;
        mint a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n-k, e3);
        if (e1 > e2+e3) return 0;
        return a1*mod_inverse((a2*a3).x);
    }
} c;

int main() {
}
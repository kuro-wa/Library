// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
 public:
  Sieve(int n=1) : n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (long long i = 2; i <= n; ++i) {
      if (f[i]) continue;
      ps.emplace_back(i);
      f[i] = i;
      for (long long j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  vector<int> primes() { return ps;}
  bool is_prime(int x) {
    assert(0 <= x && x <= n);
    return f[x] == x;
  }
  bool is_prime(long long x) {
    assert(0 <= x && x <= (long long)n*n);
    for (int p : ps) {
      if ((long long)p*p > x) break;
      if (x%p == 0) return false;
    }
    return x != 1;
  }
  map<int, int> factor(int x) {
    assert(0 <= x && x <= n);
    vector<int> fl = factor_list(x);
    if (fl.size() == 0) return {};
    map<int, int> res;
    for (int p : fl) ++res[p];
    return res;
  }
  map<long long,int> factor(long long x) {
    assert(0 <= x && x <= (long long)n*n);
    map<long long,int> res;
    for (int p : ps) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res[p] = y;
    }
    if (x != 1) res[x] =1;
    return res;
  }
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
 private:
  int n;
  vector<int> f;
  vector<int> ps;
  vector<int> factor_list(int x) {
    vector<int> res;
    while (x != 1) {
      res.emplace_back(f[x]);
      x /= f[x];
    }
    return res;
  }
} d(1000005);
//
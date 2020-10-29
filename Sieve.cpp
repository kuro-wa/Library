// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n; // the max num
  // f[i]: the min prime factor of i
  // primes[i]: i-th prime num (0-indexed)
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (long long i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (long long j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  // Returns whether x is a prime num
  bool isPrime(int x) { return f[x] == x;}
  // for long long x (<= n*n)
  bool isPrime(long long x) {
    for (int p : primes) {
      if ((long long)p*p > x) break;
      if (x%p == 0) return false;
    }
    return x != 1;
  }
  // Returns prime foctors of x in ascending order
  // ex. 24: {2, 2, 2, 3}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  // Returns prime foctorization of x
  // res[i]: (i-th prime factor, the index)
  vector<pair<int, int>> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  // for long long x (<= n*n)
  vector<pair<long long,int>> factor(long long x) {
    vector<pair<long long,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};
 
int main() {
  Sieve s(1000005);
  return 0;
}
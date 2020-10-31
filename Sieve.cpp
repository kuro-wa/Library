// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
 public:
  // primes[i]: i-th prime num (0-indexed)
  vector<int> primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (long long i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.emplace_back(i);
      f[i] = i;
      for (long long j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  // Returns whether x (<= n) is a prime num
  bool isPrime(int x) { return f[x] == x;}
  // for long long x (<= n*n)
  bool isPrime(long long x) {
    for (int p : primes) {
      if ((long long)p*p > x) break;
      if (x%p == 0) return false;
    }
    return x != 1;
  }
  // Returns prime foctorization of x (<= n)
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
  // Enumerates divisors of n
  vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i*i <= n; ++i) {
      if (n%i == 0) {
        res.emplace_back(i);
        if(i*i != n) res.emplace_back(n/i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
 private:
  int n; // the max num
  // f[i]: the min prime factor of i
  vector<int> f;
  // Returns prime foctors of x (<= n) in ascending order
  // ex. 24: {2, 2, 2, 3}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.emplace_back(f[x]);
      x /= f[x];
    }
    return res;
  }
} s(1000005);
//
// Returns a map of (a divior of n, Moebius function)
// O(sqrt(n))
map<long long, int> moebius(long long n) {
  map<long long, int> res;
  vector<long long> primes;
  // Enumerate prime foctors of n
  for (ll i = 2; i*i <= n; ++i) {
    if (n%i == 0) {
      primes.push_back(i);
      while (n%i == 0) n /= i;
    }
  }
  if (n != 1) primes.push_back(n);
  int sz = primes.size();
  for (int bit = 0; bit < (1<<sz); ++bit) {
    int m = 1, d = 1;
    for (int i = 0; i < sz; ++i) {
      if (bit>>i&1) {
        m *= -1;
        d *= primes[i];
      }
    }
    res[d] = m;
  }
  return res;
}
//
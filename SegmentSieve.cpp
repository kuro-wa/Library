// Segment Sieve of Erastothenes
// AntBook p113
struct SegmentSieve {
 public:
  SegmentSieve(long long a=0, long long b=1) : a(a), b(b), f2(b-a) {
    assert(0 <= a && a < b);
    int n = 1;
    while ((long long)n*n < b) ++n;
    f.resize(n+1);
    f[0] = f[1] = -1;
    for (long long i = 2; i <= n; ++i) {
      if (f[i]) continue;
      f[i] = i;
      for (long long j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
      for (long long j = max(i*i, (a+i-1)/i*i); j < b; j += i) {
        if (!f2[j-a]) f2[j-a] = i;
      }
    }
    for (long long i = a; i < b; ++i) {
      if (i <= 1) f2[i-a] = -1;
      else if (!f2[i-a]) {
        ps.emplace_back(i);
        f2[i-a] = i;
      }
    }
  }
  vector<long long> primes() { return ps;}
  bool is_prime(long long x) {
    assert(a <= x && x < b);
    return f2[x-a] == x;
  }
 private:
  long long a, b;
  vector<int> f;
  vector<long long> f2;
  vector<long long> ps;
};
//
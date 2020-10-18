// Segment Sieve of Erastothenes
// AntBook p113
struct SegmentSieve {
  long long a, b;
  // f[i], f2[i-a]: the min prime factor of i
  // primes[i]: i-th prime num in [a, b) (0-indexed)
  vector<int> f, f2;
  vector<long long> primes;
  SegmentSieve(long long a=0, long long b=1): a(a), b(b), f2(b-a) {
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
        primes.push_back(i);
        f2[i-a] = i;
      }
    }
  }
  // Returns whether x in [a, b) is a prime num
  bool isPrime(long long x) { return f[x-a] == x;}
};
//

int main() {
  SegmentSieve s(0, 1000000);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i = 0; i < (int)v.size(); ++i) {
    res[v[i]] = i;
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<int> as(n), bs(n);
  rep(i, n) cin >> as[i] >> bs[i];
  vector<int> xs, ys;
  xs = compress(as);
  ys = compress(bs);
  auto mpx = dict(xs), mpy = dict(ys);
  return 0;
}

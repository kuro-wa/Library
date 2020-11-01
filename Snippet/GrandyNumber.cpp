#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

const int MAX_WH = 205;
// an array for memo
// Initialize by -1 at first
int mem[MAX_WH+1][MAX_WH+1];

int grundy(int w, int h) {
  if(mem[w][h] != -1) return mem[w][h];
  set<int> s;
  for (int i = 2; w-i >= 2; ++i) s.insert(grundy(i, h)^grundy(w-i, h));
  for (int i = 2; h-i >= 2; ++i) s.insert(grundy(w, i)^grundy(w, h-i));
  int res = 0;
  while (s.count(res)) ++res;
  return mem[w][h] = res;
}

int main() {
  int w, h;
  cin >> w >> h;

  rep(i, w+1) rep(j, h+1) mem[i][j] = -1;
  cout << (grundy(w, h)?"WIN":"LOSE") << endl;
  return 0;
}
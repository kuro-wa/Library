

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// antbook p337
struct SuffixArray {
    string s;
    int n, k;
    vector<int> sa, rank, tmp, lcp;

    struct CompareSA {
        int n, k;
        vector<int> &rank;

        CompareSA(int n, int k, vector<int> &rank)
          : n(n), k(k), rank(rank) {}

        // compare (rank[i], rank[i+k]) and (rank[j], rank[j+k])
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            else {
                int ri = i+k <= n ? rank[i+k] : -1;
                int rj = j+k <= n ? rank[j+k] : -1;
                return ri < rj;
            }
        }
    };

    SuffixArray(string &s)
      : s(s), n(s.size()), sa(n+1), rank(n+1), tmp(n+1), lcp(n) {}

    // construct a suffix array of s
    vector<int> construct_sa() {
        // start by 1 letter, ranks are letter cords
        for (int i = 0; i <= n; i++) {
            sa[i] = i;
            rank[i] = i < n ? s[i] : -1;
        }
        // already k letters are sorted so sort 2k letters
        for (k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank);
            sort(sa.begin(), sa.end(), csa);
            // wright next ranks in tmp then move to rank
            tmp[sa[0]] = 0;
            for (int i = 1; i <= n; i++) {
                tmp[sa[i]] = tmp[sa[i-1]]+(csa(sa[i-1], sa[i]) ? 1 : 0);
            }
            for (int i = 0; i <= n; i++) {
                rank[i] = tmp[i];
            }
        }
        return sa;
    }

    // construct a longest common prefix array of s
    // !!! WARNING !!! use after construct_sa()
    vector<int> construct_lcp() {
        for (int i = 0; i <= n; i++) rank[sa[i]] = i;
        int h = 0;
        lcp[0] = 0;
        for (int i = 0; i < n; i++) {
            // compute suffix of i and LCP of rank just before
            int j = sa[rank[i]-1];
            // decrease h by 1 as front and increase by back match
            if (h > 0) h--;
            for (; j+h < n && i+h < n; h++) {
                if (s[j+h] != s[i+h]) break;
            }
            lcp[rank[i]-1] = h;
        }
        return lcp;
    }
};

int main() {
}
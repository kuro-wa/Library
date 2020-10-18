#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// antbook p257
const double EPS = 1e-8;
using vec = vector<double>;
using mat = vector<vec>;

// solve Ax = b
// A is a square matrix
// return 0 if no solution or not unique
vec gauss_jordan(const mat& A, const vec& b) {
    int n = A.size();
    // (A|b)
    mat B(n, vec(n+1));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) B[i][j] = A[i][j];
    for (int i = 0; i < n; i++) B[i][n] = b[i];

    for (int i = 0; i < n; i++) {
        // bring max-abs-coefficient formula to row i
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        }
        swap(B[i], B[pivot]);

        // no solution or not unique
        if (abs(B[i][i]) < EPS) return vec();

        // set the coefficient 1
        for (int j = i+1; j <= n; j++) B[i][j] /= B[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // erase i-th variable from j-th formula
                for (int k = i+1; k <= n; k++) B[j][k] -= B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    // b is the solution
    for (int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}

int main() {
}
// Gauss-Jordan (AntBook p257)
// Solve Ax = b
// A is a square matrix
// Returns {} if no solution or not unique
vector<double> gauss_jordan(const vector<vector<double>>& A, const vector<double>& b) {
  const double eps = 1e-10;
  int n = A.size();
  // B = (A|b)
  vector<vector<double>> B(n, vector<double>(n+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) B[i][j] = A[i][j];
    B[i][n] = b[i];
  }
  for (int i = 0; i < n; ++i) {
    // Bring max-abs-coefficient formula to row i
    int pivot = i;
    for (int j = i; j < n; ++j) {
      if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
    }
    swap(B[i], B[pivot]);
    // No solution or not unique
    if (abs(B[i][i]) < eps) return {};
    // Set the coefficient 1
    for (int j = i+1; j <= n; ++j) B[i][j] /= B[i][i];
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        // Erase i-th variable using j-th formula
        for (int k = i+1; k <= n; k++) B[j][k] -= B[j][i]*B[i][k];
      }
    }
  }
  vector<double> res(n);
  for (int i = 0; i < n; ++i) res[i] = B[i][n];
  return res;
}
//
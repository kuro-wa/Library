// square matrix
// Need to define '+' and '*' on T
template<typename T, T (*zero)(), T (*one)()>
struct square_matrix {
  using mat = square_matrix;
 public:
  static void set_size(int m_) {
    assert(m_ >= 1);
    m = m_;
  }
  square_matrix(T a=zero()) : d(vector<vector<T>>(m, vector<T>(m, zero()))) {
    for (int i = 0; i < m; ++i) d[i][i] = a;
  }
  square_matrix(const vector<vector<T>>& v) : d(v){}
  int size() { return m;}
  T get(int r, int c) { return d[r][c];}
  void set(int r, int c, T a) { d[r][c] = a;}
  mat& operator+=(const mat& rhs) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i][j] = d[i][j]+rhs.d[i][j];
      }
    }
    return *this;
  }
  mat& operator-=(const mat& rhs) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i][j] = d[i][j]-rhs.d[i][j];
      }
    }
    return *this;
  }
  mat& operator*=(const mat& rhs) {
    vector<vector<T>> res(m, vector<T>(m, zero()));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < m; ++k) {
          res[i][j] = res[i][j]+d[i][k]*rhs.d[k][j];
        }
      }
    }
    d = res;
    return *this;
  }
  vector<T> operator*(const vector<T>& v) const {
    assert((int)(v.size()) == m);
    vector<T> res(m, zero());
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        res[i] = res[i]+d[i][j]*v[j];
      }
    }
    return res;
  }
  mat operator+() const { return *this;}
  mat operator-() const { return mat()-*this;}
  mat pow(long long n) const {
    assert(n >= 0);
    mat x = *this, res = mat(one());
    while (n) {
      if (n&1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  mat transpose() const {
    mat res();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        res.d[i][j] = d[j][i];
      }
    }
    return res;
  }
  friend mat operator+(const mat& lhs, const mat& rhs) { return mat(lhs) += rhs;}
  friend mat operator-(const mat& lhs, const mat& rhs) { return mat(lhs) -= rhs;}
  friend mat operator*(const mat& lhs, const mat& rhs) { return mat(lhs) *= rhs;}
  friend vector<T> operator*(const vector<T>& v, const mat& rhs) { return rhs*v;}
 private:
  vector<vector<T>> d;
  static unsigned int m;
};
// Rewrite the following!!
template<typename T, T (*zero)(), T (*one)()>
unsigned int square_matrix<T, zero, one>::m = 305;
int zero() { return (int)(0);}
int one() { return (int)(1);}
using mat = square_matrix<int, zero, one>;
// Start with "mat::set_size" if you need!!
//

int main() {
  mat::set_size(3);
  return 0;
}
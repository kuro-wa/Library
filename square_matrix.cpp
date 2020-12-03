// Square Matrix
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
  square_matrix(const vector<vector<T>>& v) : d(v) {
    assert((int)v.size() == m && (int)v[0].size() == m);
  }
  int size() { return m;}
  vector<T>& operator[](int r) {
    assert(0 <= r && r < m);
    return d[r];
  }
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
  mat& operator*=(const T& a) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i][j] = d[i][j]*a;
      }
    }
    return *this;
  }
  vector<T> operator*(const vector<T>& v) const {
    assert((int)v.size() == m);
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
  friend mat operator*(const mat& lhs, const T& a) { return mat(lhs) *= a;}
  friend mat operator*(const T& a, const mat& rhs) { return mat(rhs) *= a;}
  friend vector<T> operator*(const vector<T>& v, const mat& rhs) { return mat(rhs).transpose()*v;}
 private:
  vector<vector<T>> d;
  static int m;
};
// Rewrite the following!!
template<typename T, T (*zero)(), T (*one)()>
int square_matrix<T, zero, one>::m = 305;
using T = int;
T zero() { return T(0);}
T one() { return T(1);}
using mat = square_matrix<T, zero, one>;
// Start with "mat::set_size(size);" if you need to!!
//
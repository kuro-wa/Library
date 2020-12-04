// Square Matrix
template<typename T, T (*zero)(), T (*one)()>
struct square_matrix {
  using mat = square_matrix;
 public:
  static void set_size(int sz) {
    assert(sz >= 1);
    _size = sz;
  }
  static int size() { return _size;}
  square_matrix(T a=zero()) : d(vector<vector<T>>(_size, vector<T>(_size, zero()))) {
    for (int i = 0; i < _size; ++i) d[i][i] = a;
  }
  square_matrix(const vector<vector<T>>& v) : d(v) {
    assert((int)v.size() == _size && (int)v[0].size() == _size);
  }
  vector<T>& operator[](int r) {
    assert(0 <= r && r < _size);
    return d[r];
  }
  mat& operator+=(const mat& rhs) {
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
        d[i][j] = d[i][j]+rhs.d[i][j];
      }
    }
    return *this;
  }
  mat& operator-=(const mat& rhs) {
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
        d[i][j] = d[i][j]-rhs.d[i][j];
      }
    }
    return *this;
  }
  mat& operator*=(const mat& rhs) {
    vector<vector<T>> res(_size, vector<T>(_size, zero()));
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
        for (int k = 0; k < _size; ++k) {
          res[i][j] = res[i][j]+d[i][k]*rhs.d[k][j];
        }
      }
    }
    d = res;
    return *this;
  }
  mat& operator*=(const T& a) {
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
        d[i][j] = d[i][j]*a;
      }
    }
    return *this;
  }
  vector<T> operator*(const vector<T>& v) const {
    assert((int)v.size() == _size);
    vector<T> res(_size, zero());
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
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
    for (int i = 0; i < _size; ++i) {
      for (int j = 0; j < _size; ++j) {
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
  static int _size;
  vector<vector<T>> d;
};
// Rewrite the following!!
template<typename T, T (*zero)(), T (*one)()>
int square_matrix<T, zero, one>::_size = 305;
using T = mint;
T zero() { return T(0);}
T one() { return T(1);}
using mat = square_matrix<T, zero, one>;
// Start with "mat::set_size(size);"!!
//
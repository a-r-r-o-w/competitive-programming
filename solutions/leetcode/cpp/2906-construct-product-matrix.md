# [2906] Construct Product Matrix



### Statement

Given a **0-indexed** 2D integer matrix `grid` of size `n * m`, we define a **0-indexed** 2D matrix `p` of size `n * m` as the **product** matrix of `grid` if the following condition is met:

* Each element `p[i][j]` is calculated as the product of all elements in `grid` except for the element `grid[i][j]`. This product is then taken modulo `12345`.



Return *the product matrix of* `grid`.


**Example 1:**

```

**Input:** grid = [[1,2],[3,4]]
**Output:** [[24,12],[8,6]]
**Explanation:** p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
So the answer is [[24,12],[8,6]].
```

**Example 2:**

```

**Input:** grid = [[12345],[2],[1]]
**Output:** [[2],[0],[0]]
**Explanation:** p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0. So p[0][1] = 0.
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0. So p[0][2] = 0.
So the answer is [[2],[0],[0]].
```

**Constraints:**
* `1 <= n == grid.length<= 10^5`
* `1 <= m == grid[i].length<= 10^5`
* `2 <= n * m <= 10^5`
* `1 <= grid[i][j] <= 10^9`


<br />

### Hints

- Try to solve this without using the <code>'/'</code> (division operation).
- Create two 2D arrays for <b>suffix</b> and <b>prefix</b> product, and use them to find the product for each position.

<br />

### Solution

```cpp
template <int64_t Modulo>
class modular {
    static_assert(Modulo > 0, "Modulo must be positive");

  private:
          int64_t integer = int64_t();
    const int64_t modulo  = Modulo;

    void normalize () {
        if (integer >= modulo or -integer <= modulo) integer %= modulo;
        if (integer < 0) integer += modulo;
    }

  public:
    modular (const modular& m) : integer (m()) { }

    modular (int64_t integer = { }) : integer (integer) { normalize(); }

    modular& operator = (const modular& m)
    { integer = m.integer; return *this; }

    int64_t  mod      ()    const { return modulo;  }
    int64_t  val      ()    const { return integer; }
    int64_t  operator () () const { return integer; }
    int64_t& operator () ()       { return integer; }

    template <typename T> explicit operator T() const { return static_cast <T> (integer); }

    modular& operator += (const modular& other)
    { integer += other(); if (integer >= modulo) integer -= modulo; return *this; }

    modular& operator -= (const modular& other)
    { integer -= other(); if (integer < 0) integer += modulo; return *this; }

    modular& operator *= (const modular& other)
    { return integer *= other.integer, normalize(), *this; }

    modular& operator /= (const modular& other)
    { return *this *= other.extended_euclidean_inverse()(), normalize(), *this; }

    modular& operator ++ () { return *this += 1; }
    modular& operator -- () { return *this -= 1; }
    modular  operator ++ (int) { modular result (*this); *this += 1; return result; }
    modular  operator -- (int) { modular result (*this); *this -= 1; return result; }

    modular operator + () const { return *this; }
    modular operator - () const { return modular(-integer); }

    friend modular operator + (modular self, const modular& other) { return self += other; }
    friend modular operator - (modular self, const modular& other) { return self -= other; }
    friend modular operator * (modular self, const modular& other) { return self *= other; }
    friend modular operator / (modular self, const modular& other) { return self /= other; }

    friend bool operator == (const modular& left, const modular& right) { return left() == right(); }
    friend bool operator != (const modular& left, const modular& right) { return left() != right(); }
    friend bool operator <= (const modular& left, const modular& right) { return left() <= right(); }
    friend bool operator >= (const modular& left, const modular& right) { return left() >= right(); }
    friend bool operator <  (const modular& left, const modular& right) { return left() <  right(); }
    friend bool operator >  (const modular& left, const modular& right) { return left() >  right(); }

    // Assumes modulo is prime
    // Fermat's Little Theorem (https://www.wikiwand.com/en/Fermat%27s_little_theorem)
    modular fermat_inverse () const {
        modular inverse = *this;
        inverse.binary_exponentiate(modulo - 2);
#ifdef LOST_IN_SPACE
        if (*this * inverse != 1)
            throw std::runtime_error("integer and modulo are not co-prime");
#endif
        return inverse;
    }

    // Assumes modulo is prime
    // Euler's Totient Theorem (https://www.wikiwand.com/en/Euler%27s_theorem)
    modular euler_inverse () const {
        auto m = modulo;
        long double totient = modulo;

        for (int64_t i = 2; i * i <= m; ++i)
            if (m % i == 0) {
                while (m % i == 0)
                    m /= i;
                totient *= 1.0L - 1.0L / i;
            }
        if (m > 1)
            totient *= 1.0L - 1.0L / m;

        int64_t phi = totient;
        modular inverse = *this;
        inverse.binary_exponentiate(phi - 1);
#ifdef LOST_IN_SPACE
        if (*this * inverse != 1)
            throw std::runtime_error("integer and modulo are not co-prime");
#endif
        return inverse;
    }

    // Assumes modulo is co-prime with integer
    // Extended Euclidean Algorithm (https://www.wikiwand.com/en/Extended_Euclidean_algorithm)
    modular extended_euclidean_inverse () const {
        int64_t u = 0, v = 1;
        int64_t a = integer, b = modulo;
        while (a != 0) {
            int64_t t = b / a;
            b -= t * a;
            u -= t * v;
            std::swap(a, b);
            std::swap(u, v);
        }
#ifdef LOST_IN_SPACE
        if (b != 1)
            throw std::runtime_error("integer and modulo are not co-prime");
#endif
        return {u};
    }

    // Assumes power is non-negative
    modular& binary_exponentiate (int64_t power) {
        auto base = *this;
        *this = 1;
        while (power > 0) {
            if (power & 1)
                *this *= base;
            base *= base;
            power >>= 1;
        }
        return *this;
    }

    modular& binary_exponentiate (const modular& power) {
        return binary_exponentiate(power());
    }

    std::string to_string () const { return std::to_string(integer); }

    friend std::ostream& operator << (std::ostream& stream, const modular& m)
    { return stream << m(); }

    friend std::istream& operator >> (std::istream& stream, modular& m)
    { stream >> m(); m.normalize(); return stream; }
};

namespace std {

    template <int64_t U, typename V>
    inline modular <U> pow (modular <U> m, const V& power)
    { return m.binary_exponentiate(power); }

    template <int64_t U>
    inline std::string to_string (const modular <U>& m)
    { return m.to_string(); }
}

using mod998244353  = modular<998244353>;
using mod1000000007 = modular<1000000007>;
using mod12345 = modular<12345>;

class Solution {
  public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid.front().size();
      mod12345 product = 1;
      std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
      std::vector<mod12345> row_products(n);
      std::vector<mod12345> suffix_rps(n + 1, 1), prefix_rps(n + 1, 1);
      
      for (int i = 0; i < n; ++i) {
        mod12345 x = 1;
        for (int j = 0; j < m; ++j)
          x *= grid[i][j];
        row_products[i] = x;
      }
      for (int i = 1; i <= n; ++i)
        prefix_rps[i] = prefix_rps[i - 1] * row_products[i - 1];
      for (int i = n - 1; i >= 0; --i)
        suffix_rps[i] = suffix_rps[i + 1] * row_products[i];
      
      std::vector<mod12345> right(m + 1);
      for (int i = 0; i < n; ++i) {
        mod12345 left = 1;
        
        right[m] = 1;
        for (int j = m - 1; j >= 0; --j)
          right[j] = right[j + 1] * grid[i][j];
        
        for (int j = 0; j < m; ++j) {
          ans[i][j] = (prefix_rps[i] * suffix_rps[i + 1] * left * right[j + 1]).val();
          left *= grid[i][j];
        }
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 4369
- total submissions: 18447
- acceptance rate: 23.7%
- likes: 61
- dislikes: 7

<br />

### Similar Problems

- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) (Medium)

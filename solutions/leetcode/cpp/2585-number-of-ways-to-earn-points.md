# [2585] Number of Ways to Earn Points



### Statement

There is a test that has `n` types of questions. You are given an integer `target` and a **0-indexed** 2D integer array `types` where `types[i] = [counti, marksi]` indicates that there are `counti` questions of the `i^th` type, and each one of them is worth `marksi` points.




Return *the number of ways you can earn **exactly*** `target` *points in the exam*. Since the answer may be too large, return it **modulo** `10^9 + 7`.

**Note** that questions of the same type are indistinguishable.

* For example, if there are `3` questions of the same type, then solving the `1^st` and `2^nd` questions is the same as solving the `1^st` and `3^rd` questions, or the `2^nd` and `3^rd` questions.


**Example 1:**

```

**Input:** target = 6, types = [[6,1],[3,2],[2,3]]
**Output:** 7
**Explanation:** You can earn 6 points in one of the seven ways:
- Solve 6 questions of the 0^th type: 1 + 1 + 1 + 1 + 1 + 1 = 6
- Solve 4 questions of the 0^th type and 1 question of the 1^st type: 1 + 1 + 1 + 1 + 2 = 6
- Solve 2 questions of the 0^th type and 2 questions of the 1^st type: 1 + 1 + 2 + 2 = 6
- Solve 3 questions of the 0^th type and 1 question of the 2^nd type: 1 + 1 + 1 + 3 = 6
- Solve 1 question of the 0^th type, 1 question of the 1^st type and 1 question of the 2^nd type: 1 + 2 + 3 = 6
- Solve 3 questions of the 1^st type: 2 + 2 + 2 = 6
- Solve 2 questions of the 2^nd type: 3 + 3 = 6

```

**Example 2:**

```

**Input:** target = 5, types = [[50,1],[50,2],[50,5]]
**Output:** 4
**Explanation:** You can earn 5 points in one of the four ways:
- Solve 5 questions of the 0^th type: 1 + 1 + 1 + 1 + 1 = 5
- Solve 3 questions of the 0^th type and 1 question of the 1^st type: 1 + 1 + 1 + 2 = 5
- Solve 1 questions of the 0^th type and 2 questions of the 1^st type: 1 + 2 + 2 = 5
- Solve 1 question of the 2^nd type: 5

```

**Example 3:**

```

**Input:** target = 18, types = [[6,1],[3,2],[2,3]]
**Output:** 1
**Explanation:** You can only earn 18 points by answering all questions.

```

**Constraints:**
* `1 <= target <= 1000`
* `n == types.length`
* `1 <= n <= 50`
* `types[i].length == 2`
* `1 <= counti, marksi <= 50`


<br />

### Hints

- Use Dynamic Programming
- Let ways[i][points] be the number of ways to score a given number of points after solving some questions of the first i types.
- ways[i][points] is equal to the sum of ways[i-1][points - solved * marks[i] over 0 <= solved <= count_i

<br />

### Solution

2D DP

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

using mod998244353  = modular <998244353>;
using mod1000000007 = modular <1000000007>;

class Solution {
  public:
    int waysToReachTarget (int target, vector <vector <int>>& types) {
      int n = types.size();
      std::vector <std::vector <mod1000000007>> dp (n + 1, std::vector <mod1000000007> (target + 1));
      
      dp[0][0] = 1;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
          for (int k = 0; k <= types[i - 1][0] and k * types[i - 1][1] <= j; ++k)
            dp[i][j] += dp[i - 1][j - k * types[i - 1][1]];
        }
      }
      
      return dp[n][target].val();
    }
};
```

2D DP Space Optimization

```cpp
class Solution {
  public:
    int waysToReachTarget (int target, vector <vector <int>>& types) {
      int n = types.size();
      std::vector <std::vector <mod1000000007>> dp (2, std::vector <mod1000000007> (target + 1));
      
      dp[0][0] = 1;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
          dp[i % 2][j] = 0;
          for (int k = 0; k <= types[i - 1][0] and k * types[i - 1][1] <= j; ++k)
            dp[i % 2][j] += dp[(i + 1) % 2][j - k * types[i - 1][1]];
        }
      }
      
      return dp[n % 2][target].val();
    }
};
```

1D DP

```cpp
class Solution {
  public:
    int waysToReachTarget (int target, vector <vector <int>>& types) {
      int n = types.size();
      std::vector <mod1000000007> dp (target + 1);
      
      dp[0] = 1;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = target; j >= 0; --j) {
          for (int k = 1; k <= types[i - 1][0] and k * types[i - 1][1] <= j; ++k)
            dp[j] += dp[j - k * types[i - 1][1]];
        }
      }
      
      return dp[target].val();
    }
};
```

<br />

### Statistics

- total accepted: 4727
- total submissions: 7973
- acceptance rate: 59.3%
- likes: 109
- dislikes: 2

<br />

### Similar Problems

- [Coin Change II](https://leetcode.com/problems/coin-change-ii) (Medium)
- [Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled) (Hard)

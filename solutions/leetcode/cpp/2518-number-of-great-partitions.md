# [2518] Number of Great Partitions



### Statement

You are given an array `nums` consisting of **positive** integers and an integer `k`.

**Partition** the array into two ordered **groups** such that each element is in exactly **one** group. A partition is called great if the **sum** of elements of each group is greater than or equal to `k`.

Return *the number of **distinct** great partitions*. Since the answer may be too large, return it **modulo** `109 + 7`.

Two partitions are considered distinct if some element `nums[i]` is in different groups in the two partitions.


**Example 1:**

```

**Input:** nums = [1,2,3,4], k = 4
**Output:** 6
**Explanation:** The great partitions are: ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], [1,2,3]).

```

**Example 2:**

```

**Input:** nums = [3,3,3], k = 4
**Output:** 0
**Explanation:** There are no great partitions for this array.

```

**Example 3:**

```

**Input:** nums = [6,6], k = 2
**Output:** 2
**Explanation:** We can either put nums[0] in the first partition or in the second partition.
The great partitions will be ([6], [6]) and ([6], [6]).

```

**Constraints:**
* `1 <= nums.length, k <= 1000`
* `1 <= nums[i] <= 109`


<br>

### Hints

- If the sum of the array is smaller than 2*k, then it is impossible to find a great partition.
- Solve the reverse problem, that is, find the number of partitions where the sum of elements of at least one of the two groups is smaller than k.

<br>

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

using mod998244353  = modular <998244353>;
using mod1000000007 = modular <1000000007>;

class Solution {
  public:
    int countPartitions (vector <int>& nums, int k) {
      int n = nums.size();
      std::vector <mod1000000007> dp (k + 1);
      mod1000000007 ans = 1;
      int64_t sum = std::accumulate(nums.begin(), nums.end(), int64_t(0));
      
      if (sum < 2 * k)
        return 0;
      
      dp[0] = 1;
      
      for (int i = 0; i < n; ++i) {
        ans *= 2;
        for (int j = k - 1; j >= nums[i]; --j) {
          dp[j] += dp[j - nums[i]];
        }
      }
      
      ans -= 2 * std::accumulate(dp.begin(), dp.end(), mod1000000007(0));
      return ans.val();
    }
};
```

<br>

### Statistics

- total accepted: 1237
- total submissions: 4387
- acceptance rate: 28.2%
- likes: 61
- dislikes: 2

<br>

### Similar Problems

- [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) (Hard)
- [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum) (Medium)

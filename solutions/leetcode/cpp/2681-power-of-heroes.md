# [2681] Power of Heroes



### Statement

You are given a **0-indexed** integer array `nums` representing the strength of some heroes. The **power** of a group of heroes is defined as follows:

* Let `i0`, `i1`, ... ,`ik` be the indices of the heroes in a group. Then, the power of this group is `max(nums[i0], nums[i1], ... ,nums[ik])^2 * min(nums[i0], nums[i1], ... ,nums[ik])`.



Return *the sum of the **power** of all **non-empty** groups of heroes possible.* Since the sum could be very large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** nums = [2,1,4]
**Output:** 141
**Explanation:** 
1^stgroup: [2] has power = 2^2* 2 = 8.
2^ndgroup: [1] has power = 1^2 * 1 = 1. 
3^rdgroup: [4] has power = 4^2 * 4 = 64. 
4^thgroup: [2,1] has power = 2^2 * 1 = 4. 
5^thgroup: [2,4] has power = 4^2 * 2 = 32. 
6^thgroup: [1,4] has power = 4^2 * 1 = 16. 
​​​​​​​7^thgroup: [2,1,4] has power = 4^2​​​​​​​ * 1 = 16. 
The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.


```

**Example 2:**

```

**Input:** nums = [1,1,1]
**Output:** 7
**Explanation:** A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^9`


<br />

### Hints

- Try something with sorting the array.
- For a pair of array elements nums[i] and nums[j] (i < j), the power would be nums[i]*nums[j]^2 regardless of how many elements in between are included.
- The number of subsets with the above as power will correspond to 2^(j-i-1).
- Try collecting the terms for nums[0], nums[1], …, nums[j-1] when computing the power of heroes ending at index j to get the power in a single pass.

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

using mod998244353  = modular <998244353>;
using mod1000000007 = modular <1000000007>;

class Solution {
  public:
    int sumOfPower (vector <int>& nums) {
      int n = nums.size();
      mod1000000007 ans = 0, sum = 0;
      std::vector <mod1000000007> p2 (n);
      p2[0] = 1;
      
      for (int i = 1; i < n; ++i)
        p2[i] = p2[i - 1] * 2;
      std::sort(nums.begin(), nums.end());
      for (int i = 1; i < n; ++i) {
        int j = n - i - 1;
        sum += mod1000000007(nums[j]) * p2[i - 1];
      }
      for (int i = n - 1; i >= 0; --i) {
        sum += nums[i];
        ans += mod1000000007(nums[i]) * nums[i] * sum;
        sum -= nums[i];
        if (i - 1 >= 0)
          sum -= nums[i - 1];
        sum /= 2;
      }
      
      return ans.val();
    }
};
```

<br />

### Statistics

- total accepted: 3696
- total submissions: 14209
- acceptance rate: 26.0%
- likes: 124
- dislikes: 9

<br />

### Similar Problems

None

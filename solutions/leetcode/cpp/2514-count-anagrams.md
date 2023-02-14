# [2514] Count Anagrams



### Statement

You are given a string `s` containing one or more words. Every consecutive pair of words is separated by a single space `' '`.

A string `t` is an **anagram** of string `s` if the `ith` word of `t` is a **permutation** of the `ith` word of `s`.

* For example, `"acb dfe"` is an anagram of `"abc def"`, but `"def cab"`and `"adc bef"` are not.



Return *the number of **distinct anagrams** of* `s`. Since the answer may be very large, return it **modulo** `109 + 7`.


**Example 1:**

```

**Input:** s = "too hot"
**Output:** 18
**Explanation:** Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".

```

**Example 2:**

```

**Input:** s = "aa"
**Output:** 1
**Explanation:** There is only one anagram possible for the given string.
```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of lowercase English letters and spaces `' '`.
* There is single space between consecutive words.


<br>

### Hints

- For each word, can you count the number of permutations possible if all characters are distinct?
- How to reduce overcounting when letters are repeated?
- The product of the counts of distinct permutations of all words will give the final answer.

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
    int countAnagrams (string s) {
      constexpr int max = 100000 + 1;
      
      std::vector <mod1000000007> factorial (max);
      factorial[0] = 1;
      
      for (int i = 1; i < max; ++i)
        factorial[i] = factorial[i - 1] * i;
      
      std::stringstream stream (s);
      std::string x;
      std::vector <int> freq (26);
      mod1000000007 ans = 1;
      
      while (stream >> x) {
        int n = x.length();
        for (char c: x)
          ++freq[c - 'a'];
        
        auto val = factorial[n];
        
        for (int i: freq)
          val /= factorial[i];
        
        ans *= val;
        freq.assign(26, 0);
      }
      
      return ans.val();
    }
};
```

<br>

### Statistics

- total accepted: 2656
- total submissions: 9138
- acceptance rate: 29.1%
- likes: 69
- dislikes: 7

<br>

### Similar Problems

- [Group Anagrams](https://leetcode.com/problems/group-anagrams) (Medium)
- [Count Ways to Build Rooms in an Ant Colony](https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony) (Hard)

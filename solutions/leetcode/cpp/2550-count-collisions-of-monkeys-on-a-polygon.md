# [2550] Count Collisions of Monkeys on a Polygon



### Statement

There is a regular convex polygon with `n` vertices. The vertices are labeled from `0` to `n - 1` in a clockwise direction, and each vertex has **exactly one monkey**. The following figure shows a convex polygon of `6` vertices.
![](https://assets.leetcode.com/uploads/2023/01/22/hexagon.jpg)
Each monkey moves simultaneously to a neighboring vertex. A neighboring vertex for a vertex `i` can be:

* the vertex `(i + 1) % n` in the clockwise direction, or
* the vertex `(i - 1 + n) % n` in the counter-clockwise direction.



A **collision** happens if at least two monkeys reside on the same vertex after the movement.

Return *the number of ways the monkeys can move so that at least **one collision***  *happens*. Since the answer may be very large, return it modulo `10^9 + 7`.

**Note** that each monkey can only move once.


**Example 1:**

```

**Input:** n = 3
**Output:** 6
**Explanation:** There are 8 total possible movements.
Two ways such that they collide at some point are:
- Monkey 1 moves in a clockwise direction; monkey 2 moves in an anticlockwise direction; monkey 3 moves in a clockwise direction. Monkeys 1 and 2 collide.
- Monkey 1 moves in an anticlockwise direction; monkey 2 moves in an anticlockwise direction; monkey 3 moves in a clockwise direction. Monkeys 1 and 3 collide.
It can be shown 6 total movements result in a collision.

```

**Example 2:**

```

**Input:** n = 4
**Output:** 14
**Explanation:** It can be shown that there are 14 ways for the monkeys to collide.

```

**Constraints:**
* `3 <= n <= 10^9`


<br />

### Hints

- Try counting the number of ways in which the monkeys will not collide.

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
    int monkeyMove (int n) {
      return (mod1000000007(2).binary_exponentiate(n) - 2).val();
    }
};
```

<br />

### Statistics

- total accepted: 10747
- total submissions: 43201
- acceptance rate: 24.9%
- likes: 88
- dislikes: 340

<br />

### Similar Problems

- [Pow(x, n)](https://leetcode.com/problems/powx-n) (Medium)

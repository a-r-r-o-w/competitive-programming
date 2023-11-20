# [172] Factorial Trailing Zeroes

**[math]**

### Statement

Given an integer `n`, return *the number of trailing zeroes in* `n!`.

Note that `n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1`.


**Example 1:**

```

**Input:** n = 3
**Output:** 0
**Explanation:** 3! = 6, no trailing zero.

```

**Example 2:**

```

**Input:** n = 5
**Output:** 1
**Explanation:** 5! = 120, one trailing zero.

```

**Example 3:**

```

**Input:** n = 0
**Output:** 0

```

**Constraints:**
* `0 <= n <= 10^4`


**Follow up:** Could you write a solution that works in logarithmic time complexity?

<br />

### Hints

None

<br />

### Solution

O(n)

```cpp
class Solution {
  public:
    int trailingZeroes (int n) {
      int p2 = 0, p5 = 0;

      for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x % 2 == 0) {
          x /= 2;
          ++p2;
        }
        while (x % 5 == 0) {
          x /= 5;
          ++p5;
        }
      }

      return std::min(p2, p5);
    }
};
```

O(log(n))

```cpp
class Solution {
  public:
    int trailingZeroes (int n) {
      int p2 = 0, p5 = 0;
      int a = 2, b = 5;

      while (a <= n) {
        p2 += n / a;
        a *= 2;
      }
      while (b <= n) {
        p5 += n / b;
        b *= 5;
      }

      return std::min(p2, p5);
    }
};
```

or better

```cpp
class Solution {
  public:
    int trailingZeroes (int n) {
      int p5 = 0, a = 5;

      while (a <= n) {
        p5 += n / a;
        a *= 5;
      }

      return p5;
    }
};
```

<br />

### Statistics

- total accepted: 358056
- total submissions: 850791
- acceptance rate: 42.1%
- likes: 2536
- dislikes: 1805

<br />

### Similar Problems

- [Number of Digit One](https://leetcode.com/problems/number-of-digit-one) (Hard)
- [Preimage Size of Factorial Zeroes Function](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function) (Hard)
- [Abbreviating the Product of a Range](https://leetcode.com/problems/abbreviating-the-product-of-a-range) (Hard)
- [Maximum Trailing Zeros in a Cornered Path](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path) (Medium)

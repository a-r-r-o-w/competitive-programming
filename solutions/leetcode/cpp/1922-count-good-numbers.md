# [1922] Count Good Numbers

**[math, recursion]**

### Statement

A digit string is **good** if the digits **(0-indexed)** at **even** indices are **even** and the digits at **odd** indices are **prime** (`2`, `3`, `5`, or `7`).

* For example, `"2582"` is good because the digits (`2` and `8`) at even positions are even and the digits (`5` and `2`) at odd positions are prime. However, `"3245"` is **not** good because `3` is at an even index but is not even.



Given an integer `n`, return *the **total** number of good digit strings of length* `n`. Since the answer may be large, **return it modulo** `109 + 7`.

A **digit string** is a string consisting of digits `0` through `9` that may contain leading zeros.


**Example 1:**

```

**Input:** n = 1
**Output:** 5
**Explanation:** The good numbers of length 1 are "0", "2", "4", "6", "8".

```

**Example 2:**

```

**Input:** n = 4
**Output:** 400

```

**Example 3:**

```

**Input:** n = 50
**Output:** 564908303

```

**Constraints:**
* `1 <= n <= 1015`


<br>

### Hints

- Is there a formula we can use to find the count of all the good numbers?
- Exponentiation can be done very fast if we looked at the binary bits of n.

<br>

### Solution

```cpp
class Solution {
  public:
    int countGoodNumbers (long long n) {
      constexpr int mod = 1000000007;

      auto pow = [&] (auto self, int64_t a, int64_t b) -> int64_t {
        if (b == 0)
          return 1;
        int64_t r = self(self, a, b / 2);
        r = (r * r) % mod;
        if (b & 1)
          r = (r * a) % mod;
        return r;
      };

      int64_t even = (n + 1) / 2, odd = n / 2;

      return pow(pow, 5, even) * pow(pow, 4, odd) % mod;
    }
};
```

<br>

### Statistics

- total accepted: 21427
- total submissions: 55386
- acceptance rate: 38.7%
- likes: 596
- dislikes: 282

<br>

### Similar Problems

None

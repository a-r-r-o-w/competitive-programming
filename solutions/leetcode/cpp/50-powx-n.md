# [50] Pow(x, n)

**[math, recursion]**

### Statement

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., `xn`).


**Example 1:**

```

**Input:** x = 2.00000, n = 10
**Output:** 1024.00000

```

**Example 2:**

```

**Input:** x = 2.10000, n = 3
**Output:** 9.26100

```

**Example 3:**

```

**Input:** x = 2.00000, n = -2
**Output:** 0.25000
**Explanation:** 2-2 = 1/22 = 1/4 = 0.25

```

**Constraints:**
* `-100.0 < x < 100.0`
* `-2^31 <= n <= 2^31-1`
* `-10^4 <= xn <= 1^04`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    double myPow (double x, int p) {
      int64_t n = p;
      
      if (n == 0)
        return 1.0;
      
      double r;
      
      if (n < 0) {
        r = myPow(x, -n / 2);
        r = 1.0 / (r * r);
      }
      else {
        r = myPow(x, n / 2);
        r = r * r;
      }
      
      if (std::abs(n) & 1) {
        if (n < 0)
          r /= x;
        else
          r *= x;
      }
      
      return r;
    }
};
```

<br>

### Statistics

- total accepted: 1016403
- total submissions: 3111372
- acceptance rate: 32.7%
- likes: 5569
- dislikes: 6194

<br>

### Similar Problems

- [Sqrt(x)](https://leetcode.com/problems/sqrtx) (Easy)
- [Super Pow](https://leetcode.com/problems/super-pow) (Medium)

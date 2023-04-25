# [400] Nth Digit

**[math, binary-search]**

### Statement

Given an integer `n`, return the `n^th` digit of the infinite integer sequence `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]`.


**Example 1:**

```

**Input:** n = 3
**Output:** 3

```

**Example 2:**

```

**Input:** n = 11
**Output:** 0
**Explanation:** The 11^th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

```

**Constraints:**
* `1 <= n <= 2^31 - 1`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int findNthDigit (int n) {
      int64_t range = 9, p10 = 1, digits = 1, m = n;

      while (true) {
        if (digits * range < m) {
          m -= digits * range;
          ++digits;
          p10 *= 10;
        }
        else
          break;
        range *= 10;
      }

      return std::to_string(p10 + (m - 1) / digits)[(m - 1) % digits] - '0';
    }
};
```

<br />

### Statistics

- total accepted: 84749
- total submissions: 248157
- acceptance rate: 34.2%
- likes: 873
- dislikes: 1807

<br />

### Similar Problems

None

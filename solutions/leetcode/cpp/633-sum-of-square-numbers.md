# [633] Sum of Square Numbers

**[math, two-pointers, binary-search]**

### Statement

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.


**Example 1:**

```

**Input:** c = 5
**Output:** true
**Explanation:** 1 * 1 + 2 * 2 = 5

```

**Example 2:**

```

**Input:** c = 3
**Output:** false

```

**Constraints:**
* `0 <= c <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool judgeSquareSum (int c) {
      int64_t x = c;

      for (int64_t a = 0; a * a <= c; ++a) {
        int64_t b_square = x - a * a;
        int64_t b = std::sqrt(b_square);

        if (b * b == b_square)
          return true;
      }

      return false;
    }
};
```

<br>

### Statistics

- total accepted: 161296
- total submissions: 467368
- acceptance rate: 34.5%
- likes: 1935
- dislikes: 506

<br>

### Similar Problems

- [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square) (Easy)

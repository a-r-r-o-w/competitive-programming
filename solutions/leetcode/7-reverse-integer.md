# [7] Reverse Integer

**[math]**

### Statement

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**
**Example 1:**

```

**Input:** x = 123
**Output:** 321

```

**Example 2:**

```

**Input:** x = -123
**Output:** -321

```

**Example 3:**

```

**Input:** x = 120
**Output:** 21

```

**Constraints:**
* `-231 <= x <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
public:
    int reverse (int x) {
      const int max = (1 << 31) - 1;
      int r = 0;
      
      while (x) {
        if (std::abs(r) > max / 10)
          return 0;
        r = r * 10 + x % 10;
        x /= 10;
      }
      
      return r;
    }
};
```

<br>

### Statistics

- total accepted: 2080991
- total submissions: 7773140
- acceptance rate: 26.8%
- likes: 7269
- dislikes: 9827

<br>

### Similar Problems

- [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) (Medium)
- [Reverse Bits](https://leetcode.com/problems/reverse-bits) (Easy)
- [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal) (Easy)

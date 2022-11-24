# [231] Power of Two

**[math, bit-manipulation, recursion]**

### Statement

Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.


**Example 1:**

```

**Input:** n = 1
**Output:** true
**Explanation:** 20 = 1

```

**Example 2:**

```

**Input:** n = 16
**Output:** true
**Explanation:** 24 = 16

```

**Example 3:**

```

**Input:** n = 3
**Output:** false

```

**Constraints:**
* `-231 <= n <= 231 - 1`


**Follow up:** Could you solve it without loops/recursion?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPowerOfTwo (int n) {
      return n > 0 and !(n & (n - 1));
    }
};
```

<br>

### Statistics

- total accepted: 729387
- total submissions: 1601291
- acceptance rate: 45.5%
- likes: 4068
- dislikes: 315

<br>

### Similar Problems

- [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) (Easy)
- [Power of Three](https://leetcode.com/problems/power-of-three) (Easy)
- [Power of Four](https://leetcode.com/problems/power-of-four) (Easy)

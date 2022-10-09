# [342] Power of Four

**[math, bit-manipulation, recursion]**

### Statement

Given an integer `n`, return *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.


**Example 1:**

```
**Input:** n = 16
**Output:** true

```
**Example 2:**

```
**Input:** n = 5
**Output:** false

```
**Example 3:**

```
**Input:** n = 1
**Output:** true

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
    bool isPowerOfFour (int n) {
      if (n <= 0)
        return false;
      return __builtin_ctz(n) % 2 == 0 and (n & (n - 1)) == 0;
    }
};
```

<br>

### Statistics

- total accepted: 352055
- total submissions: 780346
- acceptance rate: 45.1%
- likes: 2090
- dislikes: 301

<br>

### Similar Problems

- [Power of Two](https://leetcode.com/problems/power-of-two) (Easy)
- [Power of Three](https://leetcode.com/problems/power-of-three) (Easy)

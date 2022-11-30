# [279] Perfect Squares

**[math, dynamic-programming, breadth-first-search]**

### Statement

Given an integer `n`, return *the least number of perfect square numbers that sum to* `n`.

A **perfect square** is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.


**Example 1:**

```

**Input:** n = 12
**Output:** 3
**Explanation:** 12 = 4 + 4 + 4.

```

**Example 2:**

```

**Input:** n = 13
**Output:** 2
**Explanation:** 13 = 4 + 9.

```

**Constraints:**
* `1 <= n <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numSquares (int n) {
      const int inf32 = 1 << 30;
      std::vector <int> dp (n + 1, inf32);
      
      dp[0] = 0;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j * j <= i; ++j)
          dp[i] = std::min(dp[i], dp[i - j * j] + 1);
      }
      
      return dp[n];
    }
};
```

<br>

### Statistics

- total accepted: 572673
- total submissions: 1097539
- acceptance rate: 52.2%
- likes: 7593
- dislikes: 322

<br>

### Similar Problems

- [Count Primes](https://leetcode.com/problems/count-primes) (Medium)
- [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) (Medium)

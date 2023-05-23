# [357] Count Numbers with Unique Digits

**[math, dynamic-programming, backtracking]**

### Statement

Given an integer `n`, return the count of all numbers with unique digits, `x`, where `0 <= x < 10^n`.


**Example 1:**

```

**Input:** n = 2
**Output:** 91
**Explanation:** The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

```

**Example 2:**

```

**Input:** n = 0
**Output:** 1

```

**Constraints:**
* `0 <= n <= 8`


<br />

### Hints

- A direct way is to use the backtracking approach.
- Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10<sup>n</sup>.
- This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
- Let f(k) = count of numbers with unique digits with length equals k.
- f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

<br />

### Solution

```cpp
class Solution {
  public:
    int countNumbersWithUniqueDigits (int n) {
      if (n == 0)
        return 1;
      
      int64_t ans = 10;
      
      for (int i = 2; i <= n; ++i) {
        int64_t p = 9, c = 9;
        for (int j = 2; j <= i; ++j) {
          p *= c;
          --c;
        }
        ans += p;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 117380
- total submissions: 226119
- acceptance rate: 51.9%
- likes: 1257
- dislikes: 1388

<br />

### Similar Problems

- [Count Special Integers](https://leetcode.com/problems/count-special-integers) (Hard)

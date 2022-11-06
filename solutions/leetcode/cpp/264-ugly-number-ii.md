# [264] Ugly Number II

**[hash-table, math, dynamic-programming, heap-priority-queue]**

### Statement

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return *the* `nth` ***ugly number***.


**Example 1:**

```

**Input:** n = 10
**Output:** 12
**Explanation:** [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

```

**Example 2:**

```

**Input:** n = 1
**Output:** 1
**Explanation:** 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

```

**Constraints:**
* `1 <= n <= 1690`


<br>

### Hints

- The naive approach is to call <code>isUgly</code> for every number until you reach the n<sup>th</sup> one. Most numbers are <i>not</i> ugly. Try to focus your effort on generating only the ugly ones.
- An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
- The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L<sub>1</sub>, L<sub>2</sub>, and L<sub>3</sub>.
- Assume you have U<sub>k</sub>, the k<sup>th</sup> ugly number. Then U<sub>k+1</sub> must be Min(L<sub>1</sub> * 2, L<sub>2</sub> * 3, L<sub>3</sub> * 5).

<br>

### Solution

```cpp
class Solution {
  public:
    int nthUglyNumber (int n) {
      int k = 3;
      int factors[] = {2, 3, 5};
      int pointers[] = {0, 0, 0};
      std::vector <int> dp (n, std::numeric_limits <int>::max());
      
      dp[0] = 1;
      
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j)
          dp[i] = std::min(dp[i], dp[pointers[j]] * factors[j]);
        
        for (int j = 0; j < k; ++j) {
          if (dp[i] == dp[pointers[j]] * factors[j])
            ++pointers[j];
        }
      }
      
      return dp[n - 1];
    }
};
```

<br>

### Statistics

- total accepted: 280718
- total submissions: 609926
- acceptance rate: 46.0%
- likes: 4642
- dislikes: 234

<br>

### Similar Problems

- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) (Hard)
- [Count Primes](https://leetcode.com/problems/count-primes) (Medium)
- [Ugly Number](https://leetcode.com/problems/ugly-number) (Easy)
- [Perfect Squares](https://leetcode.com/problems/perfect-squares) (Medium)
- [Super Ugly Number](https://leetcode.com/problems/super-ugly-number) (Medium)
- [Ugly Number III](https://leetcode.com/problems/ugly-number-iii) (Medium)

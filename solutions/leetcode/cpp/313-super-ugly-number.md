# [313] Super Ugly Number

**[array, math, dynamic-programming]**

### Statement

A **super ugly number** is a positive integer whose prime factors are in the array `primes`.

Given an integer `n` and an array of integers `primes`, return *the* `n^th` ***super ugly number***.

The `n^th` **super ugly number** is **guaranteed** to fit in a **32-bit** signed integer.


**Example 1:**

```

**Input:** n = 12, primes = [2,7,13,19]
**Output:** 32
**Explanation:** [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].

```

**Example 2:**

```

**Input:** n = 1, primes = [2,3,5]
**Output:** 1
**Explanation:** 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].

```

**Constraints:**
* `1 <= n <= 10^5`
* `1 <= primes.length <= 100`
* `2 <= primes[i] <= 1000`
* `primes[i]` is **guaranteed** to be a prime number.
* All the values of `primes` are **unique** and sorted in **ascending order**.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int nthSuperUglyNumber (int n, vector <int>& primes) {
      int k = primes.size();
      std::vector <int> index (k);
      std::vector <int64_t> dp (n, std::numeric_limits <int64_t>::max());

      dp[0] = 1;

      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j)
          dp[i] = std::min(dp[i], dp[index[j]] * primes[j]);
        
        for (int j = 0; j < k; ++j) {
          if(dp[i] == dp[index[j]] * primes[j])
            ++index[j];
        }
      }

      return dp[n - 1];
    }
};
```

<br />

### Statistics

- total accepted: 114587
- total submissions: 251101
- acceptance rate: 45.6%
- likes: 1834
- dislikes: 334

<br />

### Similar Problems

- [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) (Medium)

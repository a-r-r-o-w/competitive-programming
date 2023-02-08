# [204] Count Primes

**[array, math, enumeration, number-theory]**

### Statement

Given an integer `n`, return *the number of prime numbers that are strictly less than* `n`.


**Example 1:**

```

**Input:** n = 10
**Output:** 4
**Explanation:** There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

```

**Example 2:**

```

**Input:** n = 0
**Output:** 0

```

**Example 3:**

```

**Input:** n = 1
**Output:** 0

```

**Constraints:**
* `0 <= n <= 5 * 106`


<br>

### Hints

- Checking all the integers in the range [1, n - 1] is not efficient. Think about a better approach.
- Since most of the numbers are not primes, we need a fast approach to exclude the non-prime integers.
- Use Sieve of Eratosthenes.

<br>

### Solution

```cpp
class Solution {
  public:
    int countPrimes (int n) {
      std::vector <bool> sieve (n + 10, true);
      int count = 0;

      sieve[0] = false;
      sieve[1] = false;

      for (int64_t i = 2; i < n; ++i) {
        if (!sieve[i])
          continue;
        ++count;
        for (int64_t j = i * i; j < n; j += i)
          sieve[j] = false;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 696518
- total submissions: 2105937
- acceptance rate: 33.1%
- likes: 6279
- dislikes: 1205

<br>

### Similar Problems

- [Ugly Number](https://leetcode.com/problems/ugly-number) (Easy)
- [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) (Medium)
- [Perfect Squares](https://leetcode.com/problems/perfect-squares) (Medium)
- [Number of Common Factors](https://leetcode.com/problems/number-of-common-factors) (Easy)

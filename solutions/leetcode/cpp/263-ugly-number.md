# [263] Ugly Number

**[math]**

### Statement

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` *if* `n` *is an **ugly number***.


**Example 1:**

```

**Input:** n = 6
**Output:** true
**Explanation:** 6 = 2 × 3

```

**Example 2:**

```

**Input:** n = 1
**Output:** true
**Explanation:** 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

```

**Example 3:**

```

**Input:** n = 14
**Output:** false
**Explanation:** 14 is not ugly since it includes the prime factor 7.

```

**Constraints:**
* `-231 <= n <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isUgly (int n) {
      if (n <= 0)
        return false;
      while (n % 2 == 0)
        n /= 2;
      while (n % 3 == 0)
        n /= 3;
      while (n % 5 == 0)
        n /= 5;
      return n == 1;
    }
};
```

<br>

### Statistics

- total accepted: 335031
- total submissions: 805133
- acceptance rate: 41.6%
- likes: 1841
- dislikes: 1167

<br>

### Similar Problems

- [Happy Number](https://leetcode.com/problems/happy-number) (Easy)
- [Count Primes](https://leetcode.com/problems/count-primes) (Medium)
- [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) (Medium)

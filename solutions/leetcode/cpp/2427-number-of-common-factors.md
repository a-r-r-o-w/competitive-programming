# [2427] Number of Common Factors

**[math, enumeration, number-theory]**

### Statement

Given two positive integers `a` and `b`, return *the number of **common** factors of* `a` *and* `b`.

An integer `x` is a **common factor** of `a` and `b` if `x` divides both `a` and `b`.


**Example 1:**

```

**Input:** a = 12, b = 6
**Output:** 4
**Explanation:** The common factors of 12 and 6 are 1, 2, 3, 6.

```

**Example 2:**

```

**Input:** a = 25, b = 30
**Output:** 2
**Explanation:** The common factors of 25 and 30 are 1, 5.

```

**Constraints:**
* `1 <= a, b <= 1000`


<br>

### Hints

- For each integer in range [1,1000], check if it’s divisible by both A and B.

<br>

### Solution

```cpp
class Solution {
  public:
    int commonFactors (int a, int b) {
      int gcd = std::gcd(a, b);
      int count = 0;
      
      for (int i = 1; i * i <= gcd; ++i) {
        if (gcd % i == 0) {
          count += 1;
          
          if (gcd / i != i)
            count += 1;
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 21745
- total submissions: 26988
- acceptance rate: 80.6%
- likes: 117
- dislikes: 0

<br>

### Similar Problems

- [Count Primes](https://leetcode.com/problems/count-primes) (Medium)

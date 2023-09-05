# [1952] Three Divisors

**[math]**

### Statement

Given an integer `n`, return `true` *if* `n` *has **exactly three positive divisors**. Otherwise, return* `false`.

An integer `m` is a **divisor** of `n` if there exists an integer `k` such that `n = k * m`.


**Example 1:**

```

**Input:** n = 2
**Output:** false
**Explantion:** 2 has only two divisors: 1 and 2.

```

**Example 2:**

```

**Input:** n = 4
**Output:** true
**Explantion:** 4 has three divisors: 1, 2, and 4.

```

**Constraints:**
* `1 <= n <= 104`


<br>

### Hints

- You can count the number of divisors and just check that they are 3
- Beware of the case of n equal 1 as some solutions might fail in it

<br>

### Solution

```cpp
class Solution {
  public:
    bool isThree (int n) {
      int count = 0;
      
      for (int i = 1; i * i <= n; ++i)
        if (n % i == 0) {
          ++count;
          if (n != i * i)
            ++count;
        }
      return count == 3;
    }
};
```

<br>

### Statistics

- total accepted: 35515
- total submissions: 62120
- acceptance rate: 57.2%
- likes: 325
- dislikes: 19

<br>

### Similar Problems

- [Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array) (Easy)
- [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple) (Easy)

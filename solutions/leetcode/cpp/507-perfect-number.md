# [507] Perfect Number

**[math]**

### Statement

A [**perfect number**](https://en.wikipedia.org/wiki/Perfect_number) is a **positive integer** that is equal to the sum of its **positive divisors**, excluding the number itself. A **divisor** of an integer `x` is an integer that can divide `x` evenly.

Given an integer `n`, return `true` *if* `n` *is a perfect number, otherwise return* `false`.


**Example 1:**

```

**Input:** num = 28
**Output:** true
**Explanation:** 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

```

**Example 2:**

```

**Input:** num = 7
**Output:** false

```

**Constraints:**
* `1 <= num <= 10^8`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkPerfectNumber (int num) {
      if (num == 1)
        return false;
      
      int sum = 1;
      
      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          sum += i;
          if (num / i != i)
            sum += num / i;
        }
      }
      
      return num == sum;
    }
};
```

<br>

### Statistics

- total accepted: 118410
- total submissions: 313579
- acceptance rate: 37.8%
- likes: 699
- dislikes: 942

<br>

### Similar Problems

- [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers) (Easy)

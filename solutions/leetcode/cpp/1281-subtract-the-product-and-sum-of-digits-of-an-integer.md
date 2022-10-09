# [1281] Subtract the Product and Sum of Digits of an Integer

**[math]**

### Statement

Given an integer number `n`, return the difference between the product of its digits and the sum of its digits.

**Example 1:**

```

**Input:** n = 234
**Output:** 15 
**Explanation:** 
Product of digits = 2 \* 3 \* 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

```

**Example 2:**

```

**Input:** n = 4421
**Output:** 21
**Explanation:**Product of digits = 4 \* 4 \* 2 \* 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

```

**Constraints:**
* `1 <= n <= 10^5`


<br>

### Hints

- How to compute all digits of the number ?
- Use modulus operator (%) to compute the last digit.
- Generalise modulus operator idea to compute all digits.

<br>

### Solution

```cpp
class Solution {
  public:
    int subtractProductAndSum (int n) {
      int sum = 0;
      int prod = 1;
      
      while (n > 0) {
        int d = n % 10;
        sum += d;
        prod *= d;
        n /= 10;
      }
      
      return prod - sum;
    }
};
```

<br>

### Statistics

- total accepted: 265144
- total submissions: 306073
- acceptance rate: 86.6%
- likes: 1392
- dislikes: 192

<br>

### Similar Problems

None

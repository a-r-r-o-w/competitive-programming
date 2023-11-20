# [2048] Next Greater Numerically Balanced Number

**[math, backtracking, enumeration]**

### Statement

An integer `x` is **numerically balanced** if for every digit `d` in the number `x`, there are **exactly** `d` occurrences of that digit in `x`.

Given an integer `n`, return *the **smallest numerically balanced** number **strictly greater** than* `n`*.*
**Example 1:**

```

**Input:** n = 1
**Output:** 22
**Explanation:** 
22 is numerically balanced since:
- The digit 2 occurs 2 times. 
It is also the smallest numerically balanced number strictly greater than 1.

```

**Example 2:**

```

**Input:** n = 1000
**Output:** 1333
**Explanation:** 
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times. 
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.

```

**Example 3:**

```

**Input:** n = 3000
**Output:** 3133
**Explanation:** 
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.

```

**Constraints:**
* `0 <= n <= 106`


<br>

### Hints

- How far away can the next greater numerically balanced number be from n?
- With the given constraints, what is the largest numerically balanced number?

<br>

### Solution

```cpp
class Solution {
  public:
    int nextBeautifulNumber (int n) {
      std::vector <int> freq (10);

      while (true) {
        ++n;
        int x = n;

        while (x) {
          ++freq[x % 10];
          x /= 10;
        }
        
        bool okay = true;
        for (int i = 0; i < 10; ++i) {
          if (freq[i] == 0)
            continue;
          if (freq[i] != i) {
            okay = false;
            break;
          }
        }

        if (okay)
          return n;
        
        for (int i = 0; i < 10; ++i)
          freq[i] = 0;
      }

      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 10427
- total submissions: 22063
- acceptance rate: 47.3%
- likes: 149
- dislikes: 254

<br>

### Similar Problems

None

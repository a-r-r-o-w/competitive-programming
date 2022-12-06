# [1925] Count Square Sum Triples

**[math, enumeration]**

### Statement

A **square triple** `(a,b,c)` is a triple where `a`, `b`, and `c` are **integers** and `a2 + b2 = c2`.

Given an integer `n`, return *the number of **square triples** such that* `1 <= a, b, c <= n`.


**Example 1:**

```

**Input:** n = 5
**Output:** 2
**Explanation**: The square triples are (3,4,5) and (4,3,5).

```

**Example 2:**

```

**Input:** n = 10
**Output:** 4
**Explanation**: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

```

**Constraints:**
* `1 <= n <= 250`


<br>

### Hints

- Iterate over all possible pairs (a,b) and check that the square root of a * a + b * b is an integers less than or equal n
- You can check that the square root of an integer is an integer using binary seach or a builtin function like sqrt

<br>

### Solution

```cpp
class Solution {
  public:
    int countTriples (int n) {
      int k = (n + 1) / 2;
      int count = 0;
      
      for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
          if (a == b)
            continue;
          int cc = a * a + b * b;
          int c = std::sqrt(cc);
          if (c <= n and c * c == cc)
            ++count;
        }
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 28190
- total submissions: 41475
- acceptance rate: 68.0%
- likes: 290
- dislikes: 25

<br>

### Similar Problems

- [Number of Unequal Triplets in Array](https://leetcode.com/problems/number-of-unequal-triplets-in-array) (Easy)

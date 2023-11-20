# [1318] Minimum Flips to Make a OR b Equal to c

**[bit-manipulation]**

### Statement

Given 3 positives numbers `a`, `b` and `c`. Return the minimum flips required in some bits of `a` and `b` to make (`a` OR `b` == `c`). (bitwise OR operation).  

Flip operationconsists of change**any**single bit 1 to 0 or change the bit 0 to 1in their binary representation.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/06/sample_3_1676.png)

```

**Input:** a = 2, b = 6, c = 5
**Output:** 3
**Explanation:** After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
```

**Example 2:**

```

**Input:** a = 4, b = 2, c = 7
**Output:** 1

```

**Example 3:**

```

**Input:** a = 1, b = 2, c = 3
**Output:** 0

```

**Constraints:**
* `1 <= a <= 10^9`
* `1 <= b<= 10^9`
* `1 <= c<= 10^9`


<br />

### Hints

- Check the bits one by one whether they need to be flipped.

<br />

### Solution

```cpp
class Solution {
  public:
    int minFlips (int a, int b, int c) {
      int ans = 0;
      for (int bit = 0; bit < 31; ++bit) {
        if (c & (1 << bit)) {
          if (!((a & (1 << bit)) or (b & (1 << bit))))
            ++ans;
        }
        else {
          if (a & (1 << bit))
            ++ans;
          if (b & (1 << bit))
            ++ans;
        }
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 74706
- total submissions: 105185
- acceptance rate: 71.0%
- likes: 1496
- dislikes: 82

<br />

### Similar Problems

- [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) (Easy)

# [2443] Sum of Number and Its Reverse



### Statement

Given a **non-negative** integer `num`, return `true` *if* `num` *can be expressed as the sum of any **non-negative** integer and its reverse, or* `false` *otherwise.*
**Example 1:**

```

**Input:** num = 443
**Output:** true
**Explanation:** 172 + 271 = 443 so we return true.

```

**Example 2:**

```

**Input:** num = 63
**Output:** false
**Explanation:** 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.

```

**Example 3:**

```

**Input:** num = 181
**Output:** true
**Explanation:** 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.

```

**Constraints:**
* `0 <= num <= 105`


<br>

### Hints

- The constraints are small enough that we can check every number.
- To reverse a number, first convert it to a string. Then, create a new string that is the reverse of the first one. Finally, convert the new string back into a number.

<br>

### Solution

```cpp
class Solution {
  public:
    bool sumOfNumberAndReverse (int num) {
      const int max = 100000 + 1;
      
      auto reverse = [] (int x) {
        int r = 0;
        while (x) {
          r = r * 10 + x % 10;
          x /= 10;
        }
        return r;
      };
      
      for (int i = 0; i < max; ++i) {
        if (i + reverse(i) == num)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 14366
- total submissions: 36436
- acceptance rate: 39.4%
- likes: 70
- dislikes: 120

<br>

### Similar Problems

- [Sum of Numbers With Units Digit K](https://leetcode.com/problems/sum-of-numbers-with-units-digit-k) (Medium)

# [367] Valid Perfect Square

**[math, binary-search]**

### Statement

Given a **positive** integer *num*, write a function which returns True if *num* is a perfect square else False.

**Follow up:** **Do not** use any built-in library function such as `sqrt`.


**Example 1:**

```
**Input:** num = 16
**Output:** true

```
**Example 2:**

```
**Input:** num = 14
**Output:** false

```

**Constraints:**
* `1 <= num <= 2^31 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPerfectSquare (int num) {
      int low = 0, high = 1 << 16;
      
      while (low < high) {
        int mid = (low + high) / 2;
        if (mid <= num / mid)
          low = mid + 1;
        else
          high = mid;
      }
      
      return (low - 1) * (low - 1) == num;
    }
};
```

<br>

### Statistics

- total accepted: 396776
- total submissions: 918656
- acceptance rate: 43.2%
- likes: 2626
- dislikes: 246

<br>

### Similar Problems

- [Sqrt(x)](https://leetcode.com/problems/sqrtx) (Easy)
- [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers) (Medium)

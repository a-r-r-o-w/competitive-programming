# [2485] Find the Pivot Integer

**[math, prefix-sum]**

### Statement

Given a positive integer `n`, find the **pivot integer** `x` such that:

* The sum of all elements between `1` and `x` inclusively equals the sum of all elements between `x` and `n` inclusively.



Return *the pivot integer* `x`. If no such integer exists, return `-1`. It is guaranteed that there will be at most one pivot index for the given input.


**Example 1:**

```

**Input:** n = 8
**Output:** 6
**Explanation:** 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

```

**Example 2:**

```

**Input:** n = 1
**Output:** 1
**Explanation:** 1 is the pivot integer since: 1 = 1.

```

**Example 3:**

```

**Input:** n = 4
**Output:** -1
**Explanation:** It can be proved that no such integer exist.

```

**Constraints:**
* `1 <= n <= 1000`


<br>

### Hints

- Can you use brute force to check every number from 1 to n if any of them is the pivot integer?
- If you know the sum of [1: pivot], how can you efficiently calculate the sum of the other parts?

<br>

### Solution

```cpp
class Solution {
  public:
    int pivotInteger (int n) {
      int t = n * (n + 1) / 2;
      int x = std::sqrt(t);
      return x * x == t ? x : -1;
    }
};
```

<br>

### Statistics

- total accepted: 17430
- total submissions: 21917
- acceptance rate: 79.5%
- likes: 146
- dislikes: 4

<br>

### Similar Problems

- [Bulb Switcher](https://leetcode.com/problems/bulb-switcher) (Medium)

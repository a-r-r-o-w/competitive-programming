# [2849] Determine if a Cell Is Reachable at a Given Time



### Statement

You are given four integers `sx`, `sy`, `fx`, `fy`, and a **non-negative** integer `t`.

In an infinite 2D grid, you start at the cell `(sx, sy)`. Each second, you **must** move to any of its adjacent cells.

Return `true` *if you can reach cell* `(fx, fy)` *after **exactly*** `t` ***seconds***, *or* `false` *otherwise*.

A cell's **adjacent cells** are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.


**Example 1:**
![](https://assets.leetcode.com/uploads/2023/08/05/example2.svg)

```

**Input:** sx = 2, sy = 4, fx = 7, fy = 7, t = 6
**Output:** true
**Explanation:** Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2023/08/05/example1.svg)

```

**Input:** sx = 3, sy = 1, fx = 7, fy = 3, t = 3
**Output:** false
**Explanation:** Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.

```

**Constraints:**
* `1 <= sx, sy, fx, fy <= 10^9`
* `0 <= t <= 10^9`


<br />

### Hints

- Minimum time to reach the cell should be less than or equal to given time.
- The answer is true if <code>t</code> is greater or equal than the Chebyshev distance from <code>(sx, sy)</code> to <code>(fx, fy)</code>. However, there is one more edge case to be considered.
- The answer is false If <code>sx == fx</code> and <code>sy == fy</code>

<br />

### Solution

```cpp
class Solution {
  public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
      int x = std::abs(sx - fx), y = std::abs(sy - fy);
      int m = std::min(x, y);
      if (x == 0 and y == 0 and t == 1)
        return false;
      return std::abs(x - y) + m <= t;
    }
};
```

<br />

### Statistics

- total accepted: 14729
- total submissions: 70917
- acceptance rate: 20.8%
- likes: 71
- dislikes: 113

<br />

### Similar Problems

- [Reaching Points](https://leetcode.com/problems/reaching-points) (Hard)

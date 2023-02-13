# [2543] Check if Point Is Reachable



### Statement

There exists an infinitely large grid. You are currently at point `(1, 1)`, and you need to reach the point `(targetX, targetY)` using a finite number of steps.

In one **step**, you can move from point `(x, y)` to any one of the following points:

* `(x, y - x)`
* `(x - y, y)`
* `(2 * x, y)`
* `(x, 2 * y)`



Given two integers `targetX` and `targetY` representing the X-coordinate and Y-coordinate of your final position, return `true` *if you can reach the point from* `(1, 1)` *using some number of steps, and* `false` *otherwise*.


**Example 1:**

```

**Input:** targetX = 6, targetY = 9
**Output:** false
**Explanation:** It is impossible to reach (6,9) from (1,1) using any sequence of moves, so false is returned.

```

**Example 2:**

```

**Input:** targetX = 4, targetY = 7
**Output:** true
**Explanation:** You can follow the path (1,1) -> (1,2) -> (1,4) -> (1,8) -> (1,7) -> (2,7) -> (4,7).

```

**Constraints:**
* `1 <= targetX, targetY<= 109`


<br>

### Hints

- Let’s go in reverse order, from (targetX, targetY) to (1, 1). So, now we can move from (x, y) to (x+y, y), (x, y+x), (x/2, y) if x is even, and (x, y/2) if y is even.
- When is it optimal to use the third and fourth operations?
- Think how GCD of (x, y) is affected if we apply the first two operations.
- How can we check if we can reach (1, 1) using the GCD value calculate above?

<br>

### Solution

```cpp
class Solution {
  public:
    bool isReachable (int targetX, int targetY) {
      while (targetX % 2 == 0)
        targetX /= 2;
      while (targetY % 2 == 0)
        targetY /= 2;
      
      return std::gcd(targetX, targetY) == 1;
    }
};
```

<br>

### Statistics

- total accepted: 2881
- total submissions: 7821
- acceptance rate: 36.8%
- likes: 100
- dislikes: 28

<br>

### Similar Problems

- [Reaching Points](https://leetcode.com/problems/reaching-points) (Hard)

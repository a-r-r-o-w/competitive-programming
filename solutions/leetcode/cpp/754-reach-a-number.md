# [754] Reach a Number

**[math, binary-search]**

### Statement

You are standing at position `0` on an infinite number line. There is a destination at position `target`.

You can make some number of moves `numMoves` so that:

* On each move, you can either go left or right.
* During the `ith` move (starting from `i == 1` to `i == numMoves`), you take `i` steps in the chosen direction.



Given the integer `target`, return *the **minimum** number of moves required (i.e., the minimum* `numMoves`*) to reach the destination*.


**Example 1:**

```

**Input:** target = 2
**Output:** 3
**Explanation:**
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to -1 (2 steps).
On the 3rd move, we step from -1 to 2 (3 steps).

```

**Example 2:**

```

**Input:** target = 3
**Output:** 2
**Explanation:**
On the 1st move, we step from 0 to 1 (1 step).
On the 2nd move, we step from 1 to 3 (2 steps).

```

**Constraints:**
* `-109 <= target <= 109`
* `target != 0`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int reachNumber (int target) {
      int64_t jump = 0, s = 0;
      
      target = std::abs(target);
      
      while (s < target or ((target - s) & 1)) {
        ++jump;
        s += jump;
      }
      
      return jump;
    }
};
```

<br>

### Statistics

- total accepted: 41732
- total submissions: 98417
- acceptance rate: 42.4%
- likes: 1319
- dislikes: 691

<br>

### Similar Problems

- [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps) (Medium)

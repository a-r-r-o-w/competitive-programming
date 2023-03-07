# [2579] Count Total Number of Colored Cells



### Statement

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer `n`, indicating that you must do the following routine for `n` minutes:

* At the first minute, color **any** arbitrary unit cell blue.
* Every minute thereafter, color blue **every** uncolored cell that touches a blue cell.



Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
![](https://assets.leetcode.com/uploads/2023/01/10/example-copy-2.png)
Return *the number of **colored cells** at the end of* `n` *minutes*.


**Example 1:**

```

**Input:** n = 1
**Output:** 1
**Explanation:** After 1 minute, there is only 1 blue cell, so we return 1.

```

**Example 2:**

```

**Input:** n = 2
**Output:** 5
**Explanation:** After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 

```

**Constraints:**
* `1 <= n <= 10^5`


<br />

### Hints

- Derive a mathematical relation between total number of colored cells and the time elapsed in minutes.

<br />

### Solution

```cpp
class Solution {
  public:
    long long coloredCells (int n) {
      return 1 + int64_t(n) * (n - 1) * 2;
    }
};
```

<br />

### Statistics

- total accepted: 11893
- total submissions: 22076
- acceptance rate: 53.9%
- likes: 63
- dislikes: 0

<br />

### Similar Problems

- [Minimum Cuts to Divide a Circle](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle) (Easy)

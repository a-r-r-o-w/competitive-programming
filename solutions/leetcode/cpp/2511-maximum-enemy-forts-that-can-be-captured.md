# [2511] Maximum Enemy Forts That Can Be Captured



### Statement

You are given a **0-indexed** integer array `forts` of length `n` representing the positions of several forts. `forts[i]` can be `-1`, `0`, or `1` where:

* `-1` represents there is **no fort** at the `ith` position.
* `0` indicates there is an **enemy** fort at the `ith` position.
* `1` indicates the fort at the `ith` the position is under your command.



Now you have decided to move your army from one of your forts at position `i` to an empty position `j` such that:

* `0 <= i, j <= n - 1`
* The army travels over enemy forts **only**. Formally, for all `k` where `min(i,j) < k < max(i,j)`, `forts[k] == 0.`



While moving the army, all the enemy forts that come in the way are **captured**.

Return *the **maximum** number of enemy forts that can be captured*. In case it is **impossible** to move your army, or you do not have any fort under your command, return `0`*.*
**Example 1:**

```

**Input:** forts = [1,0,0,-1,0,0,0,0,1]
**Output:** 4
**Explanation:**
- Moving the army from position 0 to position 3 captures 2 enemy forts, at 1 and 2.
- Moving the army from position 8 to position 3 captures 4 enemy forts.
Since 4 is the maximum number of enemy forts that can be captured, we return 4.

```

**Example 2:**

```

**Input:** forts = [0,0,1,-1]
**Output:** 0
**Explanation:** Since no enemy fort can be captured, 0 is returned.

```

**Constraints:**
* `1 <= forts.length <= 1000`
* `-1 <= forts[i] <= 1`


<br>

### Hints

- For each fort under your command, check if you can move the army from here.
- If yes, find the closest empty positions satisfying all criteria.
- How can two-pointers be used to solve this problem optimally?

<br>

### Solution

```cpp
class Solution {
  public:
    int captureForts (vector <int>& forts) {
      int n = forts.size(), ans = 0, count = 0;
      bool has = false;
      
      for (int i = 0; i < n; ++i) {
        if (forts[i] == 1) {
          has = true;
          count = 0;
        }
        else if (forts[i] == 0) {
          if (has)
            ++count;
        }
        else if (has) {
          ans = std::max(ans, count);
          count = 0;
          has = false;
        }
      }
      
      has = false;
      count = 0;
      
      for (int i = n - 1; i >= 0; --i) {
        if (forts[i] == 1) {
          has = true;
          count = 0;
        }
        else if (forts[i] == 0) {
          if (has)
            ++count;
        }
        else if (has) {
          ans = std::max(ans, count);
          count = 0;
          has = false;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 9286
- total submissions: 27906
- acceptance rate: 33.3%
- likes: 58
- dislikes: 72

<br>

### Similar Problems

- [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) (Easy)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) (Medium)

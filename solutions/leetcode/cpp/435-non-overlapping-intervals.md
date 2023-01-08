# [435] Non-overlapping Intervals

**[array, dynamic-programming, greedy, sorting]**

### Statement

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.


**Example 1:**

```

**Input:** intervals = [[1,2],[2,3],[3,4],[1,3]]
**Output:** 1
**Explanation:** [1,3] can be removed and the rest of the intervals are non-overlapping.

```

**Example 2:**

```

**Input:** intervals = [[1,2],[1,2],[1,2]]
**Output:** 2
**Explanation:** You need to remove two [1,2] to make the rest of the intervals non-overlapping.

```

**Example 3:**

```

**Input:** intervals = [[1,2],[2,3]]
**Output:** 0
**Explanation:** You don't need to remove any of the intervals since they're already non-overlapping.

```

**Constraints:**
* `1 <= intervals.length <= 105`
* `intervals[i].length == 2`
* `-5 * 104 <= starti < endi <= 5 * 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    
    int eraseOverlapIntervals (vector <vector <int>>& intervals) {
      int n = intervals.size(), count = 0, right = -(1 << 30);

      std::sort(intervals.begin(), intervals.end(), [&] (auto &l, auto &r) {
        if (l[1] < r[1])
          return true;
        if (l[1] > r[1])
          return false;
        return l[0] < r[0];
      });

      for (int i = 0; i < n; ++i) {
        if (right <= intervals[i][0])
          right = intervals[i][1];
        else
          ++count;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 331862
- total submissions: 663458
- acceptance rate: 50.0%
- likes: 5336
- dislikes: 150

<br>

### Similar Problems

- [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons) (Medium)
- [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict) (Easy)

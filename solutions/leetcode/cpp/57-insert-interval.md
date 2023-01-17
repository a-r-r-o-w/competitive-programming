# [57] Insert Interval

**[array]**

### Statement

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` *after the insertion*.


**Example 1:**

```

**Input:** intervals = [[1,3],[6,9]], newInterval = [2,5]
**Output:** [[1,5],[6,9]]

```

**Example 2:**

```

**Input:** intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
**Output:** [[1,2],[3,10],[12,16]]
**Explanation:** Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

```

**Constraints:**
* `0 <= intervals.length <= 104`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 105`
* `intervals` is sorted by `starti` in **ascending** order.
* `newInterval.length == 2`
* `0 <= start <= end <= 105`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> insert (vector <vector <int>> &intervals, vector <int> &newInterval) {
      std::vector <std::vector <int>> result;

      intervals.push_back(newInterval);
      std::sort(intervals.begin(), intervals.end());

      int l = -1, r = -1, n = intervals.size();

      for (int i = 0; i < n; ++i) {
        if (intervals[i][0] > r) {
          if (r != -1)
            result.push_back({l, r});
          l = intervals[i][0];
          r = intervals[i][1];
        }
        else
          r = std::max(r, intervals[i][1]);
      }
      result.push_back({l, r});

      return result;
    }
};
```

<br>

### Statistics

- total accepted: 679805
- total submissions: 1769238
- acceptance rate: 38.4%
- likes: 7130
- dislikes: 495

<br>

### Similar Problems

- [Merge Intervals](https://leetcode.com/problems/merge-intervals) (Medium)
- [Range Module](https://leetcode.com/problems/range-module) (Hard)
- [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals) (Hard)

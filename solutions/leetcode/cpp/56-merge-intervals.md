# [56] Merge Intervals

**[array, sorting]**

### Statement

Given an arrayof `intervals`where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.


**Example 1:**

```

**Input:** intervals = [[1,3],[2,6],[8,10],[15,18]]
**Output:** [[1,6],[8,10],[15,18]]
**Explanation:** Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

```

**Example 2:**

```

**Input:** intervals = [[1,4],[4,5]]
**Output:** [[1,5]]
**Explanation:** Intervals [1,4] and [4,5] are considered overlapping.

```

**Constraints:**
* `1 <= intervals.length <= 10^4`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 10^4`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> merge (vector <vector <int>>& intervals) {
      int n = intervals.size();
      std::vector <std::vector <int>> merged;

      std::sort(intervals.begin(), intervals.end());

      int left = -1, right = -1;

      for (int i = 0; i < n; ++i) {
        if (right < intervals[i][0]) {
          if (left != -1)
            merged.push_back({left, right});
          left = intervals[i][0];
          right = intervals[i][1];
        }
        else {
          left = std::min(left, intervals[i][0]);
          right = std::max(right, intervals[i][1]);
        }
      }
      if (left != -1)
        merged.push_back({left, right});

      return merged;
    }
};
```

<br>

### Statistics

- total accepted: 1757702
- total submissions: 3817288
- acceptance rate: 46.0%
- likes: 17507
- dislikes: 609

<br>

### Similar Problems

- [Insert Interval](https://leetcode.com/problems/insert-interval) (Medium)
- [Meeting Rooms](https://leetcode.com/problems/meeting-rooms) (Easy)
- [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii) (Medium)
- [Teemo Attacking](https://leetcode.com/problems/teemo-attacking) (Easy)
- [Add Bold Tag in String](https://leetcode.com/problems/add-bold-tag-in-string) (Medium)
- [Range Module](https://leetcode.com/problems/range-module) (Hard)
- [Employee Free Time](https://leetcode.com/problems/employee-free-time) (Hard)
- [Partition Labels](https://leetcode.com/problems/partition-labels) (Medium)
- [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections) (Medium)
- [Amount of New Area Painted Each Day](https://leetcode.com/problems/amount-of-new-area-painted-each-day) (Hard)
- [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character) (Hard)
- [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals) (Hard)
- [Divide Intervals Into Minimum Number of Groups](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups) (Medium)
- [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict) (Easy)

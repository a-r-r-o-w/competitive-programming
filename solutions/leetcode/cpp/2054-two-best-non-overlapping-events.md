# [2054] Two Best Non-Overlapping Events

**[array, binary-search, dynamic-programming, sorting, heap-priority-queue]**

### Statement

You are given a **0-indexed** 2D integer array of `events` where `events[i] = [startTimei, endTimei, valuei]`. The `i^th` event starts at `startTimei`and ends at `endTimei`, and if you attend this event, you will receive a value of `valuei`. You can choose **at most** **two** **non-overlapping** events to attend such that the sum of their values is **maximized**.

Return *this **maximum** sum.*

Note that the start time and end time is **inclusive**: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time `t`, the next event must start at or after `t + 1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/09/21/picture5.png)

```

**Input:** events = [[1,3,2],[4,5,2],[2,4,3]]
**Output:** 4
**Explanation:** Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

```

**Example 2:**
![Example 1 Diagram](https://assets.leetcode.com/uploads/2021/09/21/picture1.png)

```

**Input:** events = [[1,3,2],[4,5,2],[1,5,5]]
**Output:** 5
**Explanation:** Choose event 2 for a sum of 5.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/09/21/picture3.png)

```

**Input:** events = [[1,5,3],[1,5,1],[6,6,5]]
**Output:** 8
**Explanation:** Choose events 0 and 2 for a sum of 3 + 5 = 8.
```

**Constraints:**
* `2 <= events.length <= 10^5`
* `events[i].length == 3`
* `1 <= startTimei <= endTimei <= 10^9`
* `1 <= valuei <= 10^6`


<br />

### Hints

- How can sorting the events on the basis of their start times help? How about end times?
- How can we quickly get the maximum score of an interval not intersecting with the interval we chose?

<br />

### Solution

```cpp
class Solution {
  public:
    int maxTwoEvents (vector <vector <int>>& events) {
      int n = events.size();
      
      std::sort(events.begin(), events.end());

      int l = 0, r = n - 1;
      std::vector <int> suffix_max (n + 1);
      int ans = 0;

      for (int i = n - 1; i >= 0; --i)
        suffix_max[i] = std::max(suffix_max[i + 1], events[i][2]);
      
      for (int i = 0; i < n; ++i) {
        int low = i + 1, high = n;
        while (low < high) {
          int mid = (low + high) / 2;
          if (events[mid][0] > events[i][1])
            high = mid;
          else
            low = mid + 1;
        }
        ans = std::max(ans, events[i][2] + suffix_max[low]);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 14584
- total submissions: 32014
- acceptance rate: 45.6%
- likes: 698
- dislikes: 15

<br />

### Similar Problems

- [Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling) (Hard)
- [Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii) (Hard)
- [Maximize Win From Two Segments](https://leetcode.com/problems/maximize-win-from-two-segments) (Medium)

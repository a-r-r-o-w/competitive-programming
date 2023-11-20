# [1751] Maximum Number of Events That Can Be Attended II

**[array, binary-search, dynamic-programming, sorting]**

### Statement

You are given an array of `events` where `events[i] = [startDayi, endDayi, valuei]`. The `i^th` event starts at `startDayi`and ends at `endDayi`, and if you attend this event, you will receive a value of `valuei`. You are also given an integer `k` which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the **entire** event. Note that the end day is **inclusive**: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return *the **maximum sum** of values that you can receive by attending events.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60048-pm.png)

```

**Input:** events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
**Output:** 7
**Explanation:** Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60150-pm.png)

```

**Input:** events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
**Output:** 10
**Explanation:** Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do **not** have to attend k events.
```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60703-pm.png)**

```

**Input:** events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
**Output:** 9
**Explanation:** Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
```

**Constraints:**
* `1 <= k <= events.length`
* `1 <= k * events.length <= 10^6`
* `1 <= startDayi <= endDayi <= 10^9`
* `1 <= valuei <= 10^6`


<br />

### Hints

- Sort the events by its startTime.
- For every event, you can either choose it and consider the next event available, or you can ignore it. You can efficiently find the next event that is available using binary search.

<br />

### Solution

Top Down DP

```cpp
class Solution {
  public:
    int maxValue (vector <vector <int>>& events, int k) {
      int n = events.size();
      std::vector dp (n, std::vector(k + 1, -1));

      std::sort(events.begin(), events.end());

      auto dfs = [&] (auto self, int index, int k) -> int {
        if (index >= n or k <= 0)
          return 0;
        if (dp[index][k] != -1)
          return dp[index][k];
        
        int ans = 0;
        int low = index + 1, high = n;

        while (low < high) {
          int mid = (low + high) / 2;
          if (events[mid][0] > events[index][1])
            high = mid;
          else
            low = mid + 1;
        }

        ans = std::max(ans, self(self, low, k - 1) + events[index][2]);
        ans = std::max(ans, self(self, index + 1, k));
        return dp[index][k] = ans;
      };

      return dfs(dfs, 0, k);
    }
};
```

Bottom Up DP

```cpp
class Solution {
  public:
    int maxValue (vector <vector <int>>& events, int k) {
      int n = events.size();
      std::vector dp (k + 1, std::vector(n + 1, 0));

      std::sort(events.begin(), events.end());

      for (int i = n - 1; i >= 0; --i) {
        int low = i + 1, high = n;
        while (low < high) {
          int mid = (low + high) / 2;
          if (events[mid][0] <= events[i][1])
            low = mid + 1;
          else
            high = mid;
        }
        for (int j = 1; j <= k; ++j)
          dp[j][i] = std::max(dp[j][i + 1], events[i][2] + dp[j - 1][low]);
      }

      return dp[k][0];
    }
};
```

<br />

### Statistics

- total accepted: 43265
- total submissions: 71068
- acceptance rate: 60.9%
- likes: 1424
- dislikes: 26

<br />

### Similar Problems

- [Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended) (Medium)
- [Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi) (Medium)
- [Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events) (Medium)
- [Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii) (Hard)

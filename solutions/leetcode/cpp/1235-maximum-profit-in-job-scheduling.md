# [1235] Maximum Profit in Job Scheduling

**[array, binary-search, dynamic-programming, sorting]**

### Statement

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime`, `endTime` and `profit` arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png)**

```

**Input:** startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
**Output:** 120
**Explanation:** The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png)** 

```

**Input:** startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
**Output:** 150
**Explanation:** The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.

```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png)**

```

**Input:** startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
**Output:** 6

```

**Constraints:**
* `1 <= startTime.length == endTime.length == profit.length <= 5 * 104`
* `1 <= startTime[i] < endTime[i] <= 109`
* `1 <= profit[i] <= 104`


<br>

### Hints

- Think on DP.
- Sort the elements by starting time, then define the dp[i] as the maximum profit taking elements from the suffix starting at i.
- Use binarySearch (lower_bound/upper_bound on C++) to get the next index for the DP transition.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int jobScheduling (vector <int>& startTime, vector <int>& endTime, vector <int>& profit) {
      int n = startTime.size();
      std::map <int, int> compress;
      
      for (int i: startTime)
        compress[i];
      for (int i: endTime)
        compress[i];
      
      int index = 0;
      
      for (auto &[x, y]: compress)
        y = index++;
      
      std::vector <int> order (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return startTime[l] < startTime[r];
      });
      
      std::vector <int> dp (index);
      int m = 0, k = 1;
      
      for (int i: order) {
        int s = compress[startTime[i]];
        int e = compress[endTime[i]];
        int p = profit[i];
        
        while (k <= s) {
          dp[k] = std::max(dp[k - 1], dp[k]);
          ++k;
        }
        
        dp[e] = std::max(dp[e], dp[s] + p);
        m = std::max(m, dp[e]);
      }
      
      return m;
    }
};
```

<br>

### Statistics

- total accepted: 146456
- total submissions: 283810
- acceptance rate: 51.6%
- likes: 4075
- dislikes: 43

<br>

### Similar Problems

- [Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi) (Medium)
- [Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events) (Medium)

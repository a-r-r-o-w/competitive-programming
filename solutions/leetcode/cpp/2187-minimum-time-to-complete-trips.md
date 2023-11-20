# [2187] Minimum Time to Complete Trips

**[array, binary-search]**

### Statement

You are given an array `time` where `time[i]` denotes the time taken by the `i^th` bus to complete **one trip**.

Each bus can make multiple trips **successively**; that is, the next trip can start **immediately after** completing the current trip. Also, each bus operates **independently**; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer `totalTrips`, which denotes the number of trips all buses should make **in total**. Return *the **minimum time** required for all buses to complete **at least*** `totalTrips` *trips*.


**Example 1:**

```

**Input:** time = [1,2,3], totalTrips = 5
**Output:** 3
**Explanation:**
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.

```

**Example 2:**

```

**Input:** time = [2], totalTrips = 1
**Output:** 2
**Explanation:**
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.

```

**Constraints:**
* `1 <= time.length <= 10^5`
* `1 <= time[i], totalTrips <= 10^7`


<br />

### Hints

- For a given amount of time, how can we count the total number of trips completed by all buses within that time?
- Consider using binary search.

<br />

### Solution

```cpp
class Solution {
  public:
    long long minimumTime (vector <int>& time, int totalTrips) {
      int64_t low = 0, high = 1e15;
      int n = time.size();

      auto cost = [&] (int64_t x) {
        int64_t trips = totalTrips;
        for (int i = 0; i < n; ++i) {
          trips -= x / time[i];
          if (trips <= 0)
            return true;
        }
        return false;
      };

      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }

      return low;
    }
};
```

<br />

### Statistics

- total accepted: 73773
- total submissions: 194079
- acceptance rate: 38.0%
- likes: 2020
- dislikes: 119

<br />

### Similar Problems

- [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children) (Medium)
- [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time) (Medium)
- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
- [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers) (Hard)
- [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget) (Hard)
- [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array) (Medium)

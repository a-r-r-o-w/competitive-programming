# [1870] Minimum Speed to Arrive on Time

**[array, binary-search]**

### Statement

You are given a floating-point number `hour`, representing the amount of time you have to reach the office. To commute to the office, you must take `n` trains in sequential order. You are also given an integer array `dist` of length `n`, where `dist[i]` describes the distance (in kilometers) of the `i^th` train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

* For example, if the `1^st` train ride takes `1.5` hours, you must wait for an additional `0.5` hours before you can depart on the `2^nd` train ride at the 2 hour mark.



Return *the **minimum positive integer** speed **(in kilometers per hour)** that all the trains must travel at for you to reach the office on time, or* `-1` *if it is impossible to be on time*.

Tests are generated such that the answer will not exceed `10^7` and `hour` will have **at most two digits after the decimal point**.


**Example 1:**

```

**Input:** dist = [1,3,2], hour = 6
**Output:** 1
**Explanation:** At speed 1:
- The first train ride takes 1/1 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 1 hour mark. The second train takes 3/1 = 3 hours.
- Since we are already at an integer hour, we depart immediately at the 4 hour mark. The third train takes 2/1 = 2 hours.
- You will arrive at exactly the 6 hour mark.

```

**Example 2:**

```

**Input:** dist = [1,3,2], hour = 2.7
**Output:** 3
**Explanation:** At speed 3:
- The first train ride takes 1/3 = 0.33333 hours.
- Since we are not at an integer hour, we wait until the 1 hour mark to depart. The second train ride takes 3/3 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
- You will arrive at the 2.66667 hour mark.

```

**Example 3:**

```

**Input:** dist = [1,3,2], hour = 1.9
**Output:** -1
**Explanation:** It is impossible because the earliest the third train can depart is at the 2 hour mark.

```

**Constraints:**
* `n == dist.length`
* `1 <= n <= 10^5`
* `1 <= dist[i] <= 10^5`
* `1 <= hour <= 10^9`
* There will be at most two digits after the decimal point in `hour`.


<br />

### Hints

- Given the speed the trains are traveling at, can you find the total time it takes for you to arrive?
- Is there a cutoff where any speeds larger will always allow you to arrive on time?

<br />

### Solution

```cpp
class Solution {
  public:
    int minSpeedOnTime (vector <int>& dist, double hour) {
      int n = dist.size();

      if (hour <= n - 1)
        return -1;
      
      auto cost = [&] (int x) {
        double time = 0;
        for (int i = 0; i < n - 1; ++i)
          time += (dist[i] + x - 1) / x;
        time += double(dist.back()) / x;
        return time <= hour;
      };
      
      int low = 1, high = 1e8;

      while (low < high) {
        int mid = (low + high) / 2;
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

- total accepted: 87393
- total submissions: 184323
- acceptance rate: 47.4%
- likes: 2109
- dislikes: 243

<br />

### Similar Problems

- [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children) (Medium)
- [Minimum Skips to Arrive at Meeting On Time](https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time) (Hard)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)
- [The Latest Time to Catch a Bus](https://leetcode.com/problems/the-latest-time-to-catch-a-bus) (Medium)
- [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array) (Medium)

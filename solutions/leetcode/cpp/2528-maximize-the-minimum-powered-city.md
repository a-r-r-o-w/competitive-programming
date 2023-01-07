# [2528] Maximize the Minimum Powered City



### Statement

You are given a **0-indexed** integer array `stations` of length `n`, where `stations[i]` represents the number of power stations in the `ith` city.

Each power station can provide power to every city in a fixed **range**. In other words, if the range is denoted by `r`, then a power station at city `i` can provide power to all cities `j` such that `|i - j| <= r` and `0 <= i, j <= n - 1`.

* Note that `|x|` denotes **absolute** value. For example, `|7 - 5| = 2` and `|3 - 10| = 7`.



The **power** of a city is the total number of power stations it is being provided power from.

The government has sanctioned building `k` more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.

Given the two integers `r` and `k`, return *the **maximum possible minimum power** of a city, if the additional power stations are built optimally.*
**Note** that you can build the `k` power stations in multiple cities.


**Example 1:**

```

**Input:** stations = [1,2,4,5,0], r = 1, k = 2
**Output:** 5
**Explanation:** 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.

```

**Example 2:**

```

**Input:** stations = [4,4,4,4], r = 0, k = 3
**Output:** 4
**Explanation:** 
It can be proved that we cannot make the minimum power of a city greater than 4.

```

**Constraints:**
* `n == stations.length`
* `1 <= n <= 10^5`
* `0 <= stations[i] <= 10^5`
* `0 <= r<= n - 1`
* `0 <= k<= 10^9`


<br>

### Hints

- Pre calculate the number of stations on each city using Line Sweep.
- Use binary search to maximize the minimum.

<br>

### Solution

```cpp
class Solution {
  public:
    long long maxPower (vector <int>& stations, int r, int k) {
      int n = stations.size();
      int64_t low = 0, high = 1e15;
      std::vector <int64_t> power (n), surplus (n);
      int64_t sum = 0;
      
      ++r;
      for (int i = 0; i < n; ++i)
        power[i] = stations[i];
      for (int i = 0; i < r; ++i)
        sum += power[i];
      
      power[0] = sum;
      
      for (int i = 1; i < n; ++i) {
        if (i - r >= 0)
          sum -= stations[i - r];
        if (i + r - 1 < n)
            sum += stations[i + r - 1];
        power[i] = sum;
      }
      
      auto cost = [&] (int64_t x) {
        for (int i = 0; i < n; ++i)
          surplus[i] = 0;
        
        int64_t remain = k;
        sum = 0;
        
        for (int i = 0; i < n; ++i) {
          if (i - r >= 0)
            sum -= surplus[i - r];
          
          int64_t have = power[i] + sum;
          int64_t need = x - have;

          if (have >= x)
            continue;
          if (remain - need < 0)
            return false;
          
          remain -= need;
          surplus[std::min(i + r - 1, n - 1)] += need;
          sum += need;
        }
        
        return true;
      };
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

<br>

### Statistics

- total accepted: 868
- total submissions: 4960
- acceptance rate: 17.5%
- likes: 26
- dislikes: 0

<br>

### Similar Problems

- [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign) (Hard)

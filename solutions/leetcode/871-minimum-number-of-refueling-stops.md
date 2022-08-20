# [871] Minimum Number of Refueling Stops

**[array, dynamic-programming, greedy, heap-priority-queue]**

### Statement

A car travels from a starting position to a destination which is `target` miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array `stations` where `stations[i] = [positioni, fueli]` indicates that the `ith` gas station is `positioni` miles east of the starting position and has `fueli` liters of gas.

The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return *the minimum number of refueling stops the car must make in order to reach its destination*. If it cannot reach the destination, return `-1`.

Note that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If the car reaches the destination with `0` fuel left, it is still considered to have arrived.


**Example 1:**

```

**Input:** target = 1, startFuel = 1, stations = []
**Output:** 0
**Explanation:** We can reach the target without refueling.

```

**Example 2:**

```

**Input:** target = 100, startFuel = 1, stations = [[10,100]]
**Output:** -1
**Explanation:** We can not reach the target (or even the first gas station).

```

**Example 3:**

```

**Input:** target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
**Output:** 2
**Explanation:** We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.

```

**Constraints:**
* `1 <= target, startFuel <= 109`
* `0 <= stations.length <= 500`
* `0 <= positioni <= positioni+1 < target`
* `1 <= fueli < 109`


<br>

### Hints

None

<br>

### Solution

DP - O(n^2)

```cpp
class Solution {
  public:
    int minRefuelStops (int target, int startFuel, vector <vector <int>>& stations) {
      int n = stations.size();
      std::vector <int64_t> dp (n + 1);
      
      dp[0] = startFuel;
      
      for (int i = 0; i < n; ++i) {
        for (int t = i; t >= 0; --t) {
          if (dp[t] >= stations[i][0])
            dp[t + 1] = std::max(dp[t + 1], dp[t] + stations[i][1]);
        }
      }
      
      auto pos = std::lower_bound(dp.begin(), dp.end(), target);
      
      if (pos == dp.end())
        return -1;
      
      return pos - dp.begin();
    }
};
```

Priority Queue - O(n.log(n))

```cpp
class Solution {
  public:
    int minRefuelStops (int target, int startFuel, vector <vector <int>>& stations) {
      stations.push_back({target, 0});
      
      int n = stations.size();
      int ans = 0, prev_location = 0;
      std::priority_queue <int> pq;
      
      for (int i = 0; i < n; ++i) {
        startFuel -= stations[i][0] - prev_location;
        
        while (not pq.empty() and startFuel < 0) {
          startFuel += pq.top();
          pq.pop();
          ++ans;
        }
        
        if (startFuel < 0)
          return -1;
        
        pq.push(stations[i][1]);
        prev_location = stations[i][0];
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 106369
- total submissions: 268653
- acceptance rate: 39.6%
- likes: 3766
- dislikes: 72

<br>

### Similar Problems

None

# [2398] Maximum Number of Robots Within Budget



### Statement

You have `n` robots. You are given two **0-indexed** integer arrays, `chargeTimes` and `runningCosts`, both of length `n`. The `ith` robot costs `chargeTimes[i]` units to charge and costs `runningCosts[i]` units to run. You are also given an integer `budget`.

The **total cost** of running `k` chosen robots is equal to `max(chargeTimes) + k * sum(runningCosts)`, where `max(chargeTimes)` is the largest charge cost among the `k` robots and `sum(runningCosts)` is the sum of running costs among the `k` robots.

Return *the **maximum** number of **consecutive** robots you can run such that the total cost **does not** exceed* `budget`.


**Example 1:**

```

**Input:** chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
**Output:** 3
**Explanation:** 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 \* sum(2,1,3) = 6 + 3 \* 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.

```

**Example 2:**

```

**Input:** chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
**Output:** 0
**Explanation:** No robot can be run that does not exceed the budget, so we return 0.

```

**Constraints:**
* `chargeTimes.length == runningCosts.length == n`
* `1 <= n <= 5 * 10^4`
* `1 <= chargeTimes[i], runningCosts[i] <= 10^5`
* `1 <= budget <= 10^15`


<br>

### Hints

- Use binary search to convert the problem into checking if we can find a specific number of consecutive robots within the budget.
- Maintain a sliding window of the consecutive robots being considered.
- Use either a map, deque, or heap to find the maximum charge times in the window efficiently.

<br>

### Solution

**Binary Search**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximumRobots (vector <int>& chargeTimes, vector <int>& runningCosts, long long budget) {
      int n = chargeTimes.size();
      int low = 0, high = n;
      std::deque <int64_t> max;
      
      auto cost = [&] (int64_t x) {
        if (x == 0)
          return true;
        
        int64_t have = 0;
        
        for (int i = 0; i < x; ++i) {
          have += runningCosts[i];
          
          while (!max.empty() and chargeTimes[i] >= chargeTimes[max.back()])
            max.pop_back();
          
          max.push_back(i);
        }
        
        bool okay = x * have + chargeTimes[max.front()] <= budget;
        
        for (int i = x; i < n and not okay; ++i) {
          have -= runningCosts[i - x];
          have += runningCosts[i];
          
          while (!max.empty() and max.front() <= i - x)
            max.pop_front();
          
          while (!max.empty() and chargeTimes[i] >= chargeTimes[max.back()])
            max.pop_back();
          
          max.push_back(i);
          
          okay |= x * have + chargeTimes[max.front()] <= budget;
        }
        
        max.clear();
        
        return okay;
      };
      
      while (low < high) {
        int mid = (low + high) / 2;
        
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }
      
      if (not cost(low))
        --low;
      
      return low;
    }
};
```

**Sliding Window**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximumRobots (vector <int>& chargeTimes, vector <int>& runningCosts, long long budget) {
      int64_t n = chargeTimes.size(), i = 0, j = 0, best = 0, cost = 0;
      std::multiset <int> max;
      max.insert(0);
      
      while (i < n) {
        cost += runningCosts[i];
        max.insert(chargeTimes[i]);
        
        while ((i - j + 1) * cost + *max.rbegin() > budget) {
          cost -= runningCosts[j];
          max.erase(max.find(chargeTimes[j]));
          ++j;
        }
        
        best = std::max(best, i - j + 1);
        ++i;
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 4859
- total submissions: 20046
- acceptance rate: 24.2%
- likes: 179
- dislikes: 2

<br>

### Similar Problems

- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) (Hard)
- [Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays) (Hard)
- [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign) (Hard)
- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)

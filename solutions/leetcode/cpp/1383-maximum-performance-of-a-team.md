# [1383] Maximum Performance of a Team

**[array, greedy, sorting, heap-priority-queue]**

### Statement

You are given two integers `n` and `k` and two integer arrays `speed` and `efficiency` both of length `n`. There are `n` engineers numbered from `1` to `n`. `speed[i]` and `efficiency[i]` represent the speed and efficiency of the `ith` engineer respectively.

Choose **at most** `k` different engineers out of the `n` engineers to form a team with the maximum **performance**.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return *the maximum performance of this team*. Since the answer can be a huge number, return it **modulo** `109 + 7`.


**Example 1:**

```

**Input:** n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
**Output:** 60
**Explanation:** 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.

```

**Example 2:**

```

**Input:** n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
**Output:** 68
**Explanation:**This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

```

**Example 3:**

```

**Input:** n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
**Output:** 72

```

**Constraints:**
* `1 <= k <= n <= 105`
* `speed.length == n`
* `efficiency.length == n`
* `1 <= speed[i] <= 105`
* `1 <= efficiency[i] <= 108`


<br>

### Hints

- Keep track of the engineers by their efficiency in decreasing order.
- Starting from one engineer, to build a team, it suffices to bring K-1 more engineers who have higher efficiencies as well as high speeds.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxPerformance (int n, vector <int>& speed, vector <int>& efficiency, int k) {
      std::vector <int> order (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        if (efficiency[l] < efficiency[r])
          return false;
        if (efficiency[l] > efficiency[r])
          return true;
        return speed[l] > speed[r];
      });
      
      std::priority_queue <int, std::vector <int>, std::greater <int>> pq;
      int64_t speed_sum = 0, best = 0;
      
      for (int i = 0; i < n; ++i) {
        int j = order[i];
        
        pq.push(speed[j]);
        speed_sum += speed[j];
        
        if (pq.size() > k) {
          speed_sum -= pq.top();
          pq.pop();
        }
        
        best = std::max(best, efficiency[j] * speed_sum);
      }
      
      return best % 1000000007;
    }
};
```

<br>

### Statistics

- total accepted: 59892
- total submissions: 130485
- acceptance rate: 45.9%
- likes: 2011
- dislikes: 58

<br>

### Similar Problems

- [Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps) (Hard)

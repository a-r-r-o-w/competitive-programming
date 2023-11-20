# [2141] Maximum Running Time of N Computers

**[array, binary-search, greedy, sorting]**

### Statement

You have `n` computers. You are given the integer `n` and a **0-indexed** integer array `batteries` where the `i^th` battery can **run** a computer for `batteries[i]` minutes. You are interested in running **all** `n` computers **simultaneously** using the given batteries.

Initially, you can insert **at most one battery** into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery **any number of times**. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return *the **maximum** number of minutes you can run all the* `n` *computers simultaneously.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/01/06/example1-fit.png)

```

**Input:** n = 2, batteries = [3,3,3]
**Output:** 4
**Explanation:** 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.


```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/01/06/example2.png)

```

**Input:** n = 2, batteries = [1,1,1,1]
**Output:** 2
**Explanation:** 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.

```

**Constraints:**
* `1 <= n <= batteries.length <= 10^5`
* `1 <= batteries[i] <= 10^9`


<br />

### Hints

- For a given running time, can you determine if it is possible to run all n computers simultaneously?
- Try to use Binary Search to find the maximal running time

<br />

### Solution

```cpp
class Solution {
  public:
    long long maxRunTime (int n, vector <int>& batteries) {
      int m = batteries.size();
      int64_t sum = std::accumulate(batteries.begin(), batteries.end(), int64_t(0));
      int64_t low = 1, high = 1e14 + 42;

      auto cost = [&] (int64_t x) {
        int64_t remain = 0;
        for (int64_t i: batteries)
          remain += std::min(x, i);
        return remain < (int64_t)n * x;
      };

      while (low < high) {
        int64_t mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }

      return low - 1;
    }
};
```

<br />

### Statistics

- total accepted: 44504
- total submissions: 88231
- acceptance rate: 50.4%
- likes: 1662
- dislikes: 43

<br />

### Similar Problems

- [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements) (Medium)
- [Sell Diminishing-Valued Colored Balls](https://leetcode.com/problems/sell-diminishing-valued-colored-balls) (Medium)
- [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign) (Hard)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)
- [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups) (Easy)

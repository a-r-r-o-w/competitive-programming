# [746] Min Cost Climbing Stairs

**[array, dynamic-programming]**

### Statement

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.


**Example 1:**

```

**Input:** cost = [10,15,20]
**Output:** 15
**Explanation:** You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

```

**Example 2:**

```

**Input:** cost = [1,100,1,1,1,100,1,1,100,1]
**Output:** 6
**Explanation:** You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

```

**Constraints:**
* `2 <= cost.length <= 1000`
* `0 <= cost[i] <= 999`


<br>

### Hints

- Say f[i] is the final cost to climb to the top from step i.  Then f[i] = cost[i] + min(f[i+1], f[i+2]).

<br>

### Solution

```cpp
class Solution {
  public:
    int minCostClimbingStairs (vector <int>& cost) {
      int n = cost.size();
      int a = 0;
      int b = 0;
      
      for (int i = 2; i <= n; ++i) {
        int c = std::min(b + cost[i - 1], a + cost[i - 2]);
        a = b;
        b = c;
      }
      
      return b;
    }
};
```

<br>

### Statistics

- total accepted: 507926
- total submissions: 852199
- acceptance rate: 59.6%
- likes: 6262
- dislikes: 1080

<br>

### Similar Problems

- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) (Easy)

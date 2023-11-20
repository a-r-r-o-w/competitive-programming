# [1547] Minimum Cost to Cut a Stick

**[array, dynamic-programming, sorting]**

### Statement

Given a wooden stick of length `n` units. The stick is labelled from `0` to `n`. For example, a stick of length **6** is labelled as follows:
![](https://assets.leetcode.com/uploads/2020/07/21/statement.jpg)
Given an integer array `cuts` where `cuts[i]` denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return *the minimum total cost* of the cuts.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/07/23/e1.jpg)

```

**Input:** n = 7, cuts = [1,3,4,5]
**Output:** 16
**Explanation:** Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
![](https://assets.leetcode.com/uploads/2020/07/21/e11.jpg)
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
```

**Example 2:**

```

**Input:** n = 9, cuts = [5,6,1,4,2]
**Output:** 22
**Explanation:** If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

```

**Constraints:**
* `2 <= n <= 10^6`
* `1 <= cuts.length <= min(n - 1, 100)`
* `1 <= cuts[i] <= n - 1`
* All the integers in `cuts` array are **distinct**.


<br />

### Hints

- Build a dp array where dp[i][j] is the minimum cost to achieve all the cuts between i and j.
- When you try to get the minimum cost between i and j, try all possible cuts k between them, dp[i][j] = min(dp[i][k] + dp[k][j]) + (j - i) for all possible cuts k between them.

<br />

### Solution

```cpp
class Solution {
  public:
    int minCost (int n, vector <int>& cuts) {
      cuts.push_back(0);
      cuts.push_back(n);
      int m = cuts.size();
      std::vector <std::vector <int>> dp (m, std::vector <int> (m));
      
      std::sort(cuts.begin(), cuts.end());

      for (int length = 2; length < m; ++length) {
        for (int left = 0; left + length < m; ++left) {
          int right = left + length, ans = 1 << 30;
          for (int i = left + 1; i <= right - 1; ++i)
            ans = std::min(ans, dp[left][i] + dp[i][right]);
          dp[left][right] = ans + cuts[right] - cuts[left];
        }
      }

      return dp[0][m - 1];
    }
};
```

<br />

### Statistics

- total accepted: 75620
- total submissions: 121272
- acceptance rate: 62.4%
- likes: 3266
- dislikes: 70

<br />

### Similar Problems

- [Number of Ways to Divide a Long Corridor](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor) (Hard)

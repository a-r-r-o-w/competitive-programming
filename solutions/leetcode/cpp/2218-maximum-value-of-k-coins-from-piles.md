# [2218] Maximum Value of K Coins From Piles

**[array, dynamic-programming, prefix-sum]**

### Statement

There are `n` **piles** of coins on a table. Each pile consists of a **positive number** of coins of assorted denominations.

In one move, you can choose any coin on **top** of any pile, remove it, and add it to your wallet.

Given a list `piles`, where `piles[i]` is a list of integers denoting the composition of the `i^th` pile from **top to bottom**, and a positive integer `k`, return *the **maximum total value** of coins you can have in your wallet if you choose **exactly*** `k` *coins optimally*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/11/09/e1.png)

```

**Input:** piles = [[1,100,3],[7,8,9]], k = 2
**Output:** 101
**Explanation:**
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.

```

**Example 2:**

```

**Input:** piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
**Output:** 706
**Explanation:**The maximum total can be obtained if we choose all coins from the last pile.

```

**Constraints:**
* `n == piles.length`
* `1 <= n <= 1000`
* `1 <= piles[i][j] <= 10^5`
* `1 <= k <= sum(piles[i].length) <= 2000`


<br />

### Hints

- For each pile i, what will be the total value of coins we can collect if we choose the first j coins?
- How can we use dynamic programming to combine the results from different piles to find the most optimal answer?

<br />

### Solution

```cpp
class Solution {
  public:
    int maxValueOfCoins (vector <vector <int>>& piles, int k) {
      int n = piles.size();
      std::vector <std::vector <int>> dp (k, std::vector <int> (n, -1));

      auto dfs = [&] (auto self, int count, int index) -> int {
        if (count >= k)
          return 0;
        if (index >= n)
          return -(1 << 30);
        if (dp[count][index] != -1)
          return dp[count][index];
        int pref = 0, remain = k - count, max = 0;
        max = std::max(max, self(self, count, index + 1) + 0);
        for (int i = 0; i < int(piles[index].size()) and remain > 0; ++i, --remain) {
          pref += piles[index][i];
          max = std::max(max, self(self, count + i + 1, index + 1) + pref);
        }
        return dp[count][index] = max;
      };

      return dfs(dfs, 0, 0);
    }
};
```

<br />

### Statistics

- total accepted: 29684
- total submissions: 52337
- acceptance rate: 56.7%
- likes: 1380
- dislikes: 19

<br />

### Similar Problems

- [Coin Change](https://leetcode.com/problems/coin-change) (Medium)
- [Coin Change II](https://leetcode.com/problems/coin-change-ii) (Medium)

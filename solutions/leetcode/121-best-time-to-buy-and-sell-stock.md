# [121] Best Time to Buy and Sell Stock

**[array, dynamic-programming]**

### Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.


**Example 1:**

```

**Input:** prices = [7,1,5,3,6,4]
**Output:** 5
**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

```

**Example 2:**

```

**Input:** prices = [7,6,4,3,1]
**Output:** 0
**Explanation:** In this case, no transactions are done and the max profit = 0.

```

**Constraints:**
* `1 <= prices.length <= 105`
* `0 <= prices[i] <= 104`


<br>

### Hints

None

<br>

### Solution

**Finding the maximum value in suffix and minimum value in prefix**

```cpp
class Solution {
  public:
    int maxProfit (vector <int>& prices) {
      const int inf32 = 1 << 30;
      int n = prices.size();
      std::vector <int> max_suffix (n + 1, -inf32);
      std::vector <int> min_prefix (n + 1, inf32);
      
      for (int i = 0; i < n; ++i) {
        max_suffix[n - i - 1] = std::max(max_suffix[n - i], prices[n - i - 1]);
        min_prefix[i + 1] = std::min(min_prefix[i], prices[i]);
      }
      
      int best = 0;
      for (int i = 0; i < n; ++i)
        best = std::max(best, max_suffix[i] - min_prefix[i + 1]);
      
      return best;
    }
};
```

**Kadane's algorithm on difference array**

```cpp
class Solution {
  public:
    int maxProfit (vector <int>& prices) {
      int n = prices.size();
      int sum = 0;
      int best = 0;
      
      for (int i = 1; i < n; ++i) {
        int x = prices[i] - prices[i - 1];
        sum = std::max(sum + x, x);
        best = std::max(best, sum);
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 2311394
- total submissions: 4259361
- acceptance rate: 54.3%
- likes: 17270
- dislikes: 564

<br>

### Similar Problems

- [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) (Easy)
- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) (Medium)
- [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii) (Hard)
- [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv) (Hard)
- [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown) (Medium)
- [Sum of Beauty in the Array](https://leetcode.com/problems/sum-of-beauty-in-the-array) (Medium)
- [Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements) (Easy)
- [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks) (Medium)

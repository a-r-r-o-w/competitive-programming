# [2110] Number of Smooth Descent Periods of a Stock

**[array, math, dynamic-programming]**

### Statement

You are given an integer array `prices` representing the daily price history of a stock, where `prices[i]` is the stock price on the `i^th` day.

A **smooth descent period** of a stock consists of **one or more contiguous** days such that the price on each day is **lower** than the price on the **preceding day** by **exactly** `1`. The first day of the period is exempted from this rule.

Return *the number of **smooth descent periods***.


**Example 1:**

```

**Input:** prices = [3,2,1,4]
**Output:** 7
**Explanation:** There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.

```

**Example 2:**

```

**Input:** prices = [8,6,7,7]
**Output:** 4
**Explanation:** There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.

```

**Example 3:**

```

**Input:** prices = [1]
**Output:** 1
**Explanation:** There is 1 smooth descent period: [1]

```

**Constraints:**
* `1 <= prices.length <= 10^5`
* `1 <= prices[i] <= 10^5`


<br />

### Hints

- Any array is a series of adjacent longest possible smooth descent periods. For example, [5,3,2,1,7,6] is [5] + [3,2,1] + [7,6].
- Think of a 2-pointer approach to traverse the array and find each longest possible period.
- Suppose you found the longest possible period with a length of k. How many periods are within that period? How can you count them quickly? Think of the formula to calculate the sum of 1, 2, 3, ..., k.

<br />

### Solution

```cpp
class Solution {
  public:
    long long getDescentPeriods (vector <int>& prices) {
      int n = prices.size();
      int64_t ans = 0;

      for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n and prices[j - 1] - prices[j] == 1)
          ++j;
        int64_t k = j - i;
        ans += k * (k + 1) / 2;
        i = j - 1;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 27426
- total submissions: 47585
- acceptance rate: 57.6%
- likes: 518
- dislikes: 21

<br />

### Similar Problems

- [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k) (Medium)
- [Number of Valid Subarrays](https://leetcode.com/problems/number-of-valid-subarrays) (Hard)
- [Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays) (Medium)

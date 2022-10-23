# [2448] Minimum Cost to Make Array Equal



### Statement

You are given two **0-indexed** arrays `nums` and `cost` consisting each of `n` **positive** integers.

You can do the following operation **any** number of times:

* Increase or decrease **any** element of the array `nums` by `1`.



The cost of doing one operation on the `ith` element is `cost[i]`.

Return *the **minimum** total cost such that all the elements of the array* `nums` *become **equal***.


**Example 1:**

```

**Input:** nums = [1,3,5,2], cost = [2,3,1,14]
**Output:** 8
**Explanation:** We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.

```

**Example 2:**

```

**Input:** nums = [2,2,2,2,2], cost = [4,2,8,1,3]
**Output:** 0
**Explanation:** All the elements are already equal, so no operations are needed.

```

**Constraints:**
* `n == nums.length == cost.length`
* `1 <= n <= 105`
* `1 <= nums[i], cost[i] <= 106`


<br>

### Hints

- Changing the elements into one of the numbers already existing in the array nums is optimal.
- Try finding the cost of changing the array into each element, and return the minimum value.

<br>

### Solution

```cpp
class Solution {
  public:
    long long minCost (vector <int>& nums, vector <int>& cost) {
      int n = nums.size();
      std::vector <int> order (n);
      std::vector <int64_t> dp (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int i, int j) {
        return nums[i] < nums[j];
      });
      
      int64_t left = cost[order[0]], right = 0;
      
      for (int i = 1, o = order[0]; i < n; ++i) {
        int j = order[i];
        dp[o] += int64_t(nums[j] - nums[o]) * cost[j];
        right += cost[j];
      }
      
      for (int i = 1; i < n; ++i) {
        int j = order[i];
        int k = order[i - 1];
        int64_t diff = nums[j] - nums[k];
        
        dp[j] = dp[k] - diff * right + diff * left;
        left += cost[j];
        right -= cost[j];
      }
      
      return *std::min_element(dp.begin(), dp.end());
    }
};
```

<br>

### Statistics

- total accepted: 5611
- total submissions: 20472
- acceptance rate: 27.4%
- likes: 241
- dislikes: 6

<br>

### Similar Problems

- [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii) (Medium)
- [Maximum Product of the Length of Two Palindromic Substrings](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings) (Hard)
- [Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups) (Easy)

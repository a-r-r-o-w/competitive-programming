# [2012] Sum of Beauty in the Array

**[array]**

### Statement

You are given a **0-indexed** integer array `nums`. For each index `i` (`1 <= i <= nums.length - 2`) the **beauty** of `nums[i]` equals:

* `2`, if `nums[j] < nums[i] < nums[k]`, for **all** `0 <= j < i` and for **all** `i < k <= nums.length - 1`.
* `1`, if `nums[i - 1] < nums[i] < nums[i + 1]`, and the previous condition is not satisfied.
* `0`, if none of the previous conditions holds.



Return *the **sum of beauty** of all* `nums[i]` *where* `1 <= i <= nums.length - 2`.


**Example 1:**

```

**Input:** nums = [1,2,3]
**Output:** 2
**Explanation:** For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 2.

```

**Example 2:**

```

**Input:** nums = [2,4,6,4]
**Output:** 1
**Explanation:** For each index i in the range 1 <= i <= 2:
- The beauty of nums[1] equals 1.
- The beauty of nums[2] equals 0.

```

**Example 3:**

```

**Input:** nums = [3,2,1]
**Output:** 0
**Explanation:** For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 0.

```

**Constraints:**
* `3 <= nums.length <= 105`
* `1 <= nums[i] <= 105`


<br>

### Hints

- Use suffix/prefix arrays.
- prefix[i] records the maximum value in range (0, i - 1) inclusive.
- suffix[i] records the minimum value in range (i + 1, n - 1) inclusive.

<br>

### Solution

```cpp
class Solution {
  public:
    int sumOfBeauties (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> maxleft (n), minright (n, 1 << 30);

      for (int i = 1; i < n; ++i)
        maxleft[i] = std::max(maxleft[i - 1], nums[i - 1]);
      
      for (int i = n - 2; i >= 0; --i)
        minright[i] = std::min(minright[i + 1], nums[i + 1]);
      
      int count = 0;

      for (int i = 1; i < n - 1; ++i) {
        if (maxleft[i] < nums[i] and nums[i] < minright[i])
          count += 2;
        else if (nums[i - 1] < nums[i] and nums[i] < nums[i + 1])
          count += 1;
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 17471
- total submissions: 37371
- acceptance rate: 46.8%
- likes: 426
- dislikes: 42

<br>

### Similar Problems

- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) (Easy)
- [Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals) (Medium)

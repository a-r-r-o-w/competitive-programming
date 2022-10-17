# [724] Find Pivot Index

**[array, prefix-sum]**

### Statement

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return *the **leftmost pivot index***. If no such index exists, return -1.


**Example 1:**

```

**Input:** nums = [1,7,3,6,5,6]
**Output:** 3
**Explanation:**
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

```

**Example 2:**

```

**Input:** nums = [1,2,3]
**Output:** -1
**Explanation:**
There is no index that satisfies the conditions in the problem statement.
```

**Example 3:**

```

**Input:** nums = [2,1,-1]
**Output:** 0
**Explanation:**
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-1000 <= nums[i] <= 1000`


**Note:** This question is the same as1991:<https://leetcode.com/problems/find-the-middle-index-in-array/>

<br>

### Hints

- We can precompute prefix sums P[i] = nums[0] + nums[1] + ... + nums[i-1].
Then for each index, the left sum is P[i], and the right sum is P[P.length - 1] - P[i] - nums[i].

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int pivotIndex (vector <int>& nums) {
      int left_sum = 0, right_sum = std::accumulate(nums.begin(), nums.end(), 0);
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        right_sum -= nums[i];
        if (left_sum == right_sum)
          return i;
        left_sum += nums[i];
      }
      
      return -1;
    }
};
```

<br>

### Statistics

- total accepted: 467175
- total submissions: 881135
- acceptance rate: 53.0%
- likes: 4473
- dislikes: 493

<br>

### Similar Problems

- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) (Medium)
- [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array) (Easy)
- [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array) (Medium)
- [Maximum Sum Score of Array](https://leetcode.com/problems/maximum-sum-score-of-array) (Medium)

# [2089] Find Target Indices After Sorting Array

**[array, binary-search, sorting]**

### Statement

You are given a **0-indexed** integer array `nums` and a target element `target`.

A **target index** is an index `i` such that `nums[i] == target`.

Return *a list of the target indices of* `nums` after *sorting* `nums` *in **non-decreasing** order*. If there are no target indices, return *an **empty** list*. The returned list must be sorted in **increasing** order.


**Example 1:**

```

**Input:** nums = [1,2,5,2,3], target = 2
**Output:** [1,2]
**Explanation:** After sorting, nums is [1,**2**,**2**,3,5].
The indices where nums[i] == 2 are 1 and 2.

```

**Example 2:**

```

**Input:** nums = [1,2,5,2,3], target = 3
**Output:** [3]
**Explanation:** After sorting, nums is [1,2,2,**3**,5].
The index where nums[i] == 3 is 3.

```

**Example 3:**

```

**Input:** nums = [1,2,5,2,3], target = 5
**Output:** [4]
**Explanation:** After sorting, nums is [1,2,2,3,**5**].
The index where nums[i] == 5 is 4.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `1 <= nums[i], target <= 100`


<br>

### Hints

- Try "sorting" the array first.
- Now find all indices in the array whose values are equal to target.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> targetIndices (vector <int>& nums, int target) {
      std::sort(nums.begin(), nums.end());
      auto lb = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      auto ub = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin();
      
      std::vector <int> ans (ub - lb);
      
      for (int i = 0; i < ub - lb; ++i)
        ans[i] = lb + i;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 71696
- total submissions: 92613
- acceptance rate: 77.4%
- likes: 853
- dislikes: 42

<br>

### Similar Problems

- [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) (Medium)
- [Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array) (Easy)

# [976] Largest Perimeter Triangle

**[array, math, greedy, sorting]**

### Statement

Given an integer array `nums`, return *the largest perimeter of a triangle with a non-zero area, formed from three of these lengths*. If it is impossible to form any triangle of a non-zero area, return `0`.


**Example 1:**

```

**Input:** nums = [2,1,2]
**Output:** 5

```

**Example 2:**

```

**Input:** nums = [1,2,1]
**Output:** 0

```

**Constraints:**
* `3 <= nums.length <= 10^4`
* `1 <= nums[i] <= 10^6`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int largestPerimeter (vector <int>& nums) {
      int n = nums.size();
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = n - 3; i >= 0; --i)
        if (nums[i] + nums[i + 1] > nums[i + 2])
          return nums[i] + nums[i + 1] + nums[i + 2];
      
      return 0;
    }
};
```

<br>

### Statistics

- total accepted: 105640
- total submissions: 200497
- acceptance rate: 52.7%
- likes: 1352
- dislikes: 197

<br>

### Similar Problems

- [Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area) (Easy)

# [611] Valid Triangle Number

**[array, two-pointers, binary-search, greedy, sorting]**

### Statement

Given an integer array `nums`, return *the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle*.


**Example 1:**

```

**Input:** nums = [2,2,3,4]
**Output:** 3
**Explanation:** Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

```

**Example 2:**

```

**Input:** nums = [4,2,3,4]
**Output:** 4

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int triangleNumber (vector <int>& nums) {
      int n = nums.size();
      int ans = 0;

      std::sort(nums.begin(), nums.end());

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          int s = nums[i] + nums[j];
          int p = std::lower_bound(nums.begin(), nums.end(), s) - nums.begin() - 1;
          int count = p - j;
          if (count > 0)
            ans += count;
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 171898
- total submissions: 339370
- acceptance rate: 50.7%
- likes: 3457
- dislikes: 189

<br />

### Similar Problems

- [3Sum Smaller](https://leetcode.com/problems/3sum-smaller) (Medium)

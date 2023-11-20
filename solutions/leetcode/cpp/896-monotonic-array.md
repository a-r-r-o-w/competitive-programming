# [896] Monotonic Array

**[array]**

### Statement

An array is **monotonic** if it is either monotone increasing or monotone decreasing.

An array `nums` is monotone increasing if for all `i <= j`, `nums[i] <= nums[j]`. An array `nums` is monotone decreasing if for all `i <= j`, `nums[i] >= nums[j]`.

Given an integer array `nums`, return `true` *if the given array is monotonic, or* `false` *otherwise*.


**Example 1:**

```

**Input:** nums = [1,2,2,3]
**Output:** true

```

**Example 2:**

```

**Input:** nums = [6,5,4,4]
**Output:** true

```

**Example 3:**

```

**Input:** nums = [1,3,2]
**Output:** false

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^5 <= nums[i] <= 10^5`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    bool isMonotonic(vector<int>& nums) {
      int n = nums.size();
      bool ascending = true, descending = true;

      for (int i = 0; i < n - 1 and (ascending or descending); ++i) {
        int j = n - i - 1;
        if (nums[i] > nums[i + 1])
          ascending = false;
        if (nums[j - 1] < nums[j])
          descending = false;
      }

      return ascending or descending;
    }
};
```

<br />

### Statistics

- total accepted: 325466
- total submissions: 542617
- acceptance rate: 60.0%
- likes: 2526
- dislikes: 76

<br />

### Similar Problems

- [Count Hills and Valleys in an Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array) (Easy)

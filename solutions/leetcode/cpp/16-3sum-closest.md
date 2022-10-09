# [16] 3Sum Closest

**[array, two-pointers, sorting]**

### Statement

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return *the sum of the three integers*.

You may assume that each input would have exactly one solution.


**Example 1:**

```

**Input:** nums = [-1,2,1,-4], target = 1
**Output:** 2
**Explanation:** The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```

**Example 2:**

```

**Input:** nums = [0,0,0], target = 1
**Output:** 0

```

**Constraints:**
* `3 <= nums.length <= 1000`
* `-1000 <= nums[i] <= 1000`
* `-104 <= target <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int threeSumClosest (vector<int>& nums, int target) {
      int n = nums.size();
      int best = 1 << 30;
      int s = 0;
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n - 2; ++i) {
        int low = i + 1, high = n - 1;
        int x = target - nums[i];
        while (low < high) {
          int sum = nums[low] + nums[high];
          if (sum < x)
            ++low;
          else
            --high;
          if (std::abs(sum - x) < best) {
            best = std::abs(sum - x);
            s = sum + nums[i];
          }
        }
      }
      
      return s;
    }
};
```

<br>

### Statistics

- total accepted: 809787
- total submissions: 1720883
- acceptance rate: 47.1%
- likes: 5936
- dislikes: 254

<br>

### Similar Problems

- [3Sum](https://leetcode.com/problems/3sum) (Medium)
- [3Sum Smaller](https://leetcode.com/problems/3sum-smaller) (Medium)

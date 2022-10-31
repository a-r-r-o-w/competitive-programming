# [2453] Destroy Sequential Targets



### Statement

You are given a **0-indexed** array `nums` consisting of positive integers, representing targets on a number line. You are also given an integer `space`.

You have a machine which can destroy targets. **Seeding** the machine with some `nums[i]` allows it to destroy all targets with values that can be represented as `nums[i] + c * space`, where `c` is any non-negative integer. You want to destroy the **maximum** number of targets in `nums`.

Return *the **minimum value** of* `nums[i]` *you can seed the machine with to destroy the maximum number of targets.*
**Example 1:**

```

**Input:** nums = [3,7,8,1,1,5], space = 2
**Output:** 1
**Explanation:** If we seed the machine with nums[3], then we destroy all targets equal to 1,3,5,7,9,... 
In this case, we would destroy 5 total targets (all except for nums[2]). 
It is impossible to destroy more than 5 targets, so we return nums[3].

```

**Example 2:**

```

**Input:** nums = [1,3,5,2,4,6], space = 2
**Output:** 1
**Explanation:** Seeding the machine with nums[0], or nums[3] destroys 3 targets. 
It is not possible to destroy more than 3 targets.
Since nums[0] is the minimal integer that can destroy 3 targets, we return 1.

```

**Example 3:**

```

**Input:** nums = [6,2,5], space = 100
**Output:** 2
**Explanation:** Whatever initial seed we select, we can only destroy 1 target. The minimal seed is nums[1].

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= space <=109`


<br>

### Hints

- Keep track of nums[i] modulo k.
- Iterate over nums in sorted order.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int destroyTargets (vector <int>& nums, int space) {
      std::map <int, std::pair <int, int>> have;
      int max = 0;
      
      for (int i: nums) {
        int j = i % space;
        
        if (have.count(j))
          have[j].second = std::min(have[j].second, i);
        else
          have[j].second = i;
        
        ++have[j].first;
        max = std::max(max, have[j].first);
      }
      
      int ans = 1 << 30;
      
      for (auto &[x, y]: have) {
        if (y.first == max)
          ans = std::min(ans, y.second);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 7187
- total submissions: 20821
- acceptance rate: 34.5%
- likes: 185
- dislikes: 9

<br>

### Similar Problems

- [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence) (Hard)
- [Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60) (Medium)
- [Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence) (Medium)
- [Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference) (Medium)

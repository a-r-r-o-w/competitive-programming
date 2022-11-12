# [334] Increasing Triplet Subsequence

**[array, greedy]**

### Statement

Given an integer array `nums`, return `true` *if there exists a triple of indices* `(i, j, k)` *such that* `i < j < k` *and* `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.


**Example 1:**

```

**Input:** nums = [1,2,3,4,5]
**Output:** true
**Explanation:** Any triplet where i < j < k is valid.

```

**Example 2:**

```

**Input:** nums = [5,4,3,2,1]
**Output:** false
**Explanation:** No triplet exists.

```

**Example 3:**

```

**Input:** nums = [2,1,5,0,4,6]
**Output:** true
**Explanation:** The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

```

**Constraints:**
* `1 <= nums.length <= 5 * 105`
* `-231 <= nums[i] <= 231 - 1`


**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space complexity?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool increasingTriplet (vector <int>& nums) {
      const int inf32 = std::numeric_limits <int>::max();
      
      int min1 = inf32, min2 = inf32;
      
      for (int i: nums) {
        if (i <= min1)
          min1 = i;
        else if (i <= min2)
          min2 = i;
        else
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 339016
- total submissions: 798870
- acceptance rate: 42.4%
- likes: 5505
- dislikes: 251

<br>

### Similar Problems

- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
- [Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets) (Easy)
- [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array) (Hard)

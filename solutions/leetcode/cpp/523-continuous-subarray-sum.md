# [523] Continuous Subarray Sum

**[array, hash-table, math, prefix-sum]**

### Statement

Given an integer array `nums` and an integer `k`, return `true` *if* `nums` *has a continuous subarray of size **at least two** whose elements sum up to a multiple of* `k`*, or* `false` *otherwise*.

An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is **always** a multiple of `k`.


**Example 1:**

```

**Input:** nums = [23,2,4,6,7], k = 6
**Output:** true
**Explanation:** [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

```

**Example 2:**

```

**Input:** nums = [23,2,6,4,7], k = 6
**Output:** true
**Explanation:** [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

```

**Example 3:**

```

**Input:** nums = [23,2,6,4,7], k = 13
**Output:** false

```

**Constraints:**
* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`
* `0 <= sum(nums[i]) <= 231 - 1`
* `1 <= k <= 231 - 1`


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
  
    bool checkSubarraySum (vector <int>& nums, int k) {
      int n = nums.size();
      int s = 0;
      std::map <int, int> have;
      
      have[0] = 0;
      
      for (int i = 0; i < n; ++i) {
        s += nums[i];
        s %= k;
        
        if (!have.count(s))
          have[s] = i + 1;
        else if (have[s] < i)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 351190
- total submissions: 1244420
- acceptance rate: 28.2%
- likes: 3674
- dislikes: 371

<br>

### Similar Problems

- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) (Medium)
- [Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous) (Hard)
- [Intervals Between Identical Elements](https://leetcode.com/problems/intervals-between-identical-elements) (Medium)

# [1027] Longest Arithmetic Subsequence

**[array, hash-table, binary-search, dynamic-programming]**

### Statement

Given an array `nums` of integers, return *the length of the longest arithmetic subsequence in* `nums`.

**Note** that:

* A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
* A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same value (for `0 <= i < seq.length - 1`).


**Example 1:**

```

**Input:** nums = [3,6,9,12]
**Output:** 4
**Explanation:**  The whole array is an arithmetic sequence with steps of length = 3.

```

**Example 2:**

```

**Input:** nums = [9,4,7,2,10]
**Output:** 3
**Explanation:**  The longest arithmetic subsequence is [4,7,10].

```

**Example 3:**

```

**Input:** nums = [20,1,15,3,10,5,8]
**Output:** 4
**Explanation:**  The longest arithmetic subsequence is [20,15,10,5].

```

**Constraints:**
* `2 <= nums.length <= 1000`
* `0 <= nums[i] <= 500`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int longestArithSeqLength (vector <int>& nums) {
      int n = nums.size(), max = 0;
      std::vector dp(n, std::unordered_map <int, int>());

      for (int r = 0; r < n; ++r) {
        for (int l = 0; l < r; ++l) {
          int d = nums[r] - nums[l];
          if (dp[l].count(d))
            dp[r][d] = 1 + dp[l][d];
          else
            dp[r][d] = 2;
          max = std::max(max, dp[r][d]);
        }
      }

      return max;
    }
};
```

<br />

### Statistics

- total accepted: 141202
- total submissions: 288633
- acceptance rate: 48.9%
- likes: 4003
- dislikes: 181

<br />

### Similar Problems

- [Destroy Sequential Targets](https://leetcode.com/problems/destroy-sequential-targets) (Medium)

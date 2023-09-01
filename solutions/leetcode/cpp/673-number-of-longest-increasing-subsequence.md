# [673] Number of Longest Increasing Subsequence

**[array, dynamic-programming, binary-indexed-tree, segment-tree]**

### Statement

Given an integer array`nums`, return *the number of longest increasing subsequences.*
**Notice** that the sequence has to be **strictly** increasing.


**Example 1:**

```

**Input:** nums = [1,3,5,4,7]
**Output:** 2
**Explanation:** The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

```

**Example 2:**

```

**Input:** nums = [2,2,2,2,2]
**Output:** 5
**Explanation:** The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

```

**Constraints:**
* `1 <= nums.length <= 2000`
* `-10^6 <= nums[i] <= 10^6`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int findNumberOfLIS (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> length (n, 1), count (n, 1);

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[j] < nums[i]) {
            if (length[j] + 1 == length[i])
              count[i] += count[j];
            else if (length[j] + 1 > length[i]) {
              length[i] = length[j] + 1;
              count[i] = count[j];
            }
          }
        }
      }

      int max = *std::max_element(length.begin(), length.end()), ans = 0;

      for (int i = 0; i < n; ++i) {
        if (length[i] == max)
          ans += count[i];
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 191112
- total submissions: 408009
- acceptance rate: 46.8%
- likes: 6085
- dislikes: 247

<br />

### Similar Problems

- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
- [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence) (Easy)
- [Longest Increasing Subsequence II](https://leetcode.com/problems/longest-increasing-subsequence-ii) (Hard)

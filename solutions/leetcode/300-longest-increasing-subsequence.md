# [300] Longest Increasing Subsequence

**[array, binary-search, dynamic-programming]**

### Statement

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.


**Example 1:**

```

**Input:** nums = [10,9,2,5,3,7,101,18]
**Output:** 4
**Explanation:** The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

```

**Example 2:**

```

**Input:** nums = [0,1,0,3,2,3]
**Output:** 4

```

**Example 3:**

```

**Input:** nums = [7,7,7,7,7,7,7]
**Output:** 1

```

**Constraints:**
* `1 <= nums.length <= 2500`
* `-10^4 <= nums[i] <= 10^4`


**Follow up:**Can you come up with an algorithm that runs in`O(n log(n))` time complexity?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int lengthOfLIS (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> ans;
      
      for (int i = 0; i < n; ++i) {
        auto lb = std::lower_bound(ans.begin(), ans.end(), nums[i]);
        if (lb == ans.end())
          ans.push_back(nums[i]);
        else
          *lb = nums[i];
      }
      
      return ans.size();
    }
};
```

<br>

### Statistics

- total accepted: 976302
- total submissions: 1924672
- acceptance rate: 50.7%
- likes: 13981
- dislikes: 256

<br>

### Similar Problems

- [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence) (Medium)
- [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes) (Hard)
- [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) (Medium)
- [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence) (Medium)
- [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings) (Medium)
- [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array) (Hard)
- [Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position) (Hard)
- [Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing) (Hard)
- [Longest Ideal Subsequence](https://leetcode.com/problems/longest-ideal-subsequence) (Medium)
- [Maximum Number of Books You Can Take](https://leetcode.com/problems/maximum-number-of-books-you-can-take) (Hard)

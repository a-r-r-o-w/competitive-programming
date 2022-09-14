# [2395] Find Subarrays With Equal Sum



### Statement

Given a **0-indexed** integer array `nums`, determine whether there exist **two** subarrays of length `2` with **equal** sum. Note that the two subarrays must begin at **different** indices.

Return `true` *if these subarrays exist, and* `false` *otherwise.*

A **subarray** is a contiguous non-empty sequence of elements within an array.


**Example 1:**

```

**Input:** nums = [4,2,4]
**Output:** true
**Explanation:** The subarrays with elements [4,2] and [2,4] have the same sum of 6.

```

**Example 2:**

```

**Input:** nums = [1,2,3,4,5]
**Output:** false
**Explanation:** No two subarrays of size 2 have the same sum.

```

**Example 3:**

```

**Input:** nums = [0,0,0]
**Output:** true
**Explanation:** The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.

```

**Constraints:**
* `2 <= nums.length <= 1000`
* `-10^9 <= nums[i] <= 10^9`


<br>

### Hints

- Use a counter to keep track of the subarray sums.
- Use a hashset to check if any two sums are equal.

<br>

### Solution

```cpp
class Solution {
  public:
    bool findSubarrays (vector <int>& nums) {
      std::map <int, int> have;
      
      for (int i = 0; i < (int)nums.size() - 1; ++i) {
        ++have[nums[i] + nums[i + 1]];
      }
      
      for (auto &[x, y]: have) {
        if (y >= 2)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 15810
- total submissions: 26427
- acceptance rate: 59.8%
- likes: 51
- dislikes: 1

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum) (Medium)
- [Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum) (Medium)

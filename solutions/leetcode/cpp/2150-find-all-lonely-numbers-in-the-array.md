# [2150] Find All Lonely Numbers in the Array

**[array, hash-table, counting]**

### Statement

You are given an integer array `nums`. A number `x` is **lonely** when it appears only **once**, and no **adjacent** numbers (i.e. `x + 1` and `x - 1)` appear in the array.

Return ***all** lonely numbers in* `nums`. You may return the answer in **any order**.


**Example 1:**

```

**Input:** nums = [10,6,5,8]
**Output:** [10,8]
**Explanation:** 
- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
- 5 is not a lonely number since 6 appears in nums and vice versa.
Hence, the lonely numbers in nums are [10, 8].
Note that [8, 10] may also be returned.

```

**Example 2:**

```

**Input:** nums = [1,3,5,3]
**Output:** [1,5]
**Explanation:** 
- 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
- 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
- 3 is not a lonely number since it appears twice.
Hence, the lonely numbers in nums are [1, 5].
Note that [5, 1] may also be returned.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^6`


<br />

### Hints

- For a given element x, how can you quickly check if x - 1 and x + 1 are present in the array without reiterating through the entire array?
- Use a set or a hash map.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> findLonely (vector <int>& nums) {
      int n = nums.size();
      std::map <int, int> have;
      std::vector <int> ans;

      for (int i = 0; i < n; ++i)
        ++have[nums[i]];
      for (int i = 0; i < n; ++i) {
        if (have[nums[i]] > 1)
          continue;
        if (!have.count(nums[i] - 1) and !have.count(nums[i] + 1))
          ans.push_back(nums[i]);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 33283
- total submissions: 54943
- acceptance rate: 60.6%
- likes: 437
- dislikes: 46

<br />

### Similar Problems

- [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element) (Medium)

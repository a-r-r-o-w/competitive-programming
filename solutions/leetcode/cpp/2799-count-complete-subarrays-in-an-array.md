# [2799] Count Complete Subarrays in an Array



### Statement

You are given an array `nums` consisting of **positive** integers.

We call a subarray of an array **complete** if the following condition is satisfied:

* The number of **distinct** elements in the subarray is equal to the number of distinct elements in the whole array.



Return *the number of **complete** subarrays*.

A **subarray** is a contiguous non-empty part of an array.


**Example 1:**

```

**Input:** nums = [1,3,1,2,2]
**Output:** 4
**Explanation:** The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

```

**Example 2:**

```

**Input:** nums = [5,5,5,5]
**Output:** 10
**Explanation:** The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 2000`


<br />

### Hints

- Let’s say k is the number of distinct elements in the array. Our goal is to find the number of subarrays with k distinct elements.
- Since the constraints are small, you can check every subarray.

<br />

### Solution

```cpp
class Solution {
  public:
    int countCompleteSubarrays (vector <int>& nums) {
      std::unordered_set <int> unique;
      int total = 0, n = nums.size(), ans = 0;
      
      for (int i: nums)
        unique.insert(i);
      total = unique.size();
      
      for (int i = 0; i < n; ++i) {
        unique.clear();
        for (int j = i; j < n; ++j) {
          unique.insert(nums[j]);
          if ((int)unique.size() == total)
            ++ans;
        }
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 18857
- total submissions: 30174
- acceptance rate: 62.5%
- likes: 194
- dislikes: 6

<br />

### Similar Problems

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) (Medium)
- [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers) (Hard)

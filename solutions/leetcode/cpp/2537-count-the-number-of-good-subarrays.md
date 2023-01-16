# [2537] Count the Number of Good Subarrays



### Statement

Given an integer array `nums` and an integer `k`, return *the number of **good** subarrays of* `nums`.

A subarray `arr` is **good** if it there are **at least** `k` pairs of indices `(i, j)` such that `i < j` and `arr[i] == arr[j]`.

A **subarray** is a contiguous **non-empty** sequence of elements within an array.


**Example 1:**

```

**Input:** nums = [1,1,1,1,1], k = 10
**Output:** 1
**Explanation:** The only good subarray is the array nums itself.

```

**Example 2:**

```

**Input:** nums = [3,1,4,3,2,2,4], k = 2
**Output:** 4
**Explanation:** There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i], k <= 109`


<br>

### Hints

- For a fixed index l, try to find the minimum value of index r, such that the subarray is not good
- When a number is added to a subarray, it increases the number of pairs by its previous appearances.
- When a number is removed from the subarray, it decreases the number of pairs by its remaining appearances.
- Maintain 2-pointers l and r such that we can keep in account the number of equal pairs.

<br>

### Solution

```cpp
class Solution {
  public:
    long long countGood (vector <int>& nums, int k) {
      int n = nums.size(), l = 0, r = 0;
      int64_t count = 0, total = 0;
      std::map <int64_t, int64_t> have;
      
      while (l < n) {
        while (r < n and total < k) {
          total += have[nums[r]];
          ++have[nums[r]];
          ++r;
        }
        
        if (total >= k)
          count += n - r + 1;
        
        --have[nums[l]];
        total -= have[nums[l]];
        ++l;
      }
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 4647
- total submissions: 12372
- acceptance rate: 37.6%
- likes: 121
- dislikes: 8

<br>

### Similar Problems

- [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings) (Medium)
- [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k) (Medium)

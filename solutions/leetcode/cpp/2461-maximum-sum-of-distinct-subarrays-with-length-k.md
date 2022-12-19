# [2461] Maximum Sum of Distinct Subarrays With Length K



### Statement

You are given an integer array `nums` and an integer `k`. Find the maximum subarray sum of all the subarrays of `nums` that meet the following conditions:

* The length of the subarray is `k`, and
* All the elements of the subarray are **distinct**.



Return *the maximum subarray sum of all the subarrays that meet the conditions**.* If no subarray meets the conditions, return `0`.

*A **subarray** is a contiguous non-empty sequence of elements within an array.*
**Example 1:**

```

**Input:** nums = [1,5,4,2,9,9,9], k = 3
**Output:** 15
**Explanation:** The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

```

**Example 2:**

```

**Input:** nums = [4,4,4], k = 3
**Output:** 0
**Explanation:** The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.

```

**Constraints:**
* `1 <= k <= nums.length <= 105`
* `1 <= nums[i] <= 105`


<br>

### Hints

- Which elements change when moving from the subarray of size k that ends at index i to the subarray of size k that ends at index i + 1?
- Only two elements change, the element at i + 1 is added into the subarray, and the element at i - k + 1 gets removed from the subarray.
- Iterate through each subarray of size k and keep track of the sum of the subarray and the frequency of each element.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    long long maximumSubarraySum (vector <int>& nums, int k) {
      int n = nums.size();
      int64_t max = 0, sum = 0;
      std::unordered_map <int, int> have;
      int l = 0, r = 0;
      
      while (r < n) {
        auto f = have.find(nums[r]);
        
        if (f != have.end()) {
          int x = f->second;
          while (l <= x) {
            have.erase(nums[l]);
            sum -= nums[l];
            ++l;
          }
        }
        
        have[nums[r]] = r;
        sum += nums[r];
        
        while (r - l + 1 > k) {
          have.erase(nums[l]);
          sum -= nums[l];
          ++l;
        }
        
        if (r - l + 1 == k)
          max = std::max(max, sum);
        
        ++r;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 11089
- total submissions: 36326
- acceptance rate: 30.5%
- likes: 204
- dislikes: 1

<br>

### Similar Problems

- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) (Medium)
- [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray) (Medium)
- [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string) (Medium)

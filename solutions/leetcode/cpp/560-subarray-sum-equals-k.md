# [560] Subarray Sum Equals K

**[array, hash-table, prefix-sum]**

### Statement

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.


**Example 1:**

```
**Input:** nums = [1,1,1], k = 2
**Output:** 2

```
**Example 2:**

```
**Input:** nums = [1,2,3], k = 3
**Output:** 2

```

**Constraints:**
* `1 <= nums.length <= 2 * 104`
* `-1000 <= nums[i] <= 1000`
* `-107 <= k <= 107`


<br>

### Hints

- Will Brute force work here? Try to optimize it.
- Can we optimize it by using some extra space?
- What about storing sum frequencies in a hash table? Will it be useful?
- sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.

Can we use this property to optimize it.

<br>

### Solution

```cpp
class Solution {
  public:
    int subarraySum (vector <int>& nums, int k) {
      int n = nums.size();
      int sum = 0;
      int ans = 0;
      std::unordered_map <int, int> have;
      
      for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sum == k)
          ans += 1;
        if (have.count(sum - k))
          ans += have[sum - k];
        have[sum] += 1;
      }
      
      // for (int l = 0; l < n; ++l) {
      //   int sum = 0;
      //   for (int r = l; r < n; ++r) {
      //     sum += nums[r];
      //     if (sum == k)
      //       ++ans;
      //   }
      // }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 819947
- total submissions: 1853940
- acceptance rate: 44.2%
- likes: 14244
- dislikes: 442

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum) (Medium)
- [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k) (Medium)
- [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) (Easy)
- [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k) (Medium)
- [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero) (Medium)
- [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages) (Medium)
- [Maximum Sum Score of Array](https://leetcode.com/problems/maximum-sum-score-of-array) (Medium)

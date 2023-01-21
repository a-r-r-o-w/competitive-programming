# [974] Subarray Sums Divisible by K

**[array, hash-table, prefix-sum]**

### Statement

Given an integer array `nums` and an integer `k`, return *the number of non-empty **subarrays** that have a sum divisible by* `k`.

A **subarray** is a **contiguous** part of an array.


**Example 1:**

```

**Input:** nums = [4,5,0,-2,-3,1], k = 5
**Output:** 7
**Explanation:** There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

```

**Example 2:**

```

**Input:** nums = [5], k = 9
**Output:** 0

```

**Constraints:**
* `1 <= nums.length <= 3 * 104`
* `-104 <= nums[i] <= 104`
* `2 <= k <= 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int subarraysDivByK (vector <int>& nums, int k) {
      int n = nums.size();
      std::vector <int> have (k);
      int count = 0, sum = 0;

      have[0] = 1;

      for (int i = 0; i < n; ++i) {
        sum = (sum + nums[i]) % k;
        if (sum < 0)
          sum += k;
        
        count += have[sum];
        ++have[sum];
      }

      return count;
    }
};
```

<br>

### Statistics

- total accepted: 146257
- total submissions: 271879
- acceptance rate: 53.8%
- likes: 4418
- dislikes: 172

<br>

### Similar Problems

- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) (Medium)
- [Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p) (Medium)
- [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs) (Medium)

# [2449] Minimum Number of Operations to Make Arrays Similar



### Statement

You are given two positive integer arrays `nums` and `target`, of the same length.

In one operation, you can choose any two **distinct** indices `i` and `j` where `0 <= i, j < nums.length` and:

* set `nums[i] = nums[i] + 2` and
* set `nums[j] = nums[j] - 2`.



Two arrays are considered to be **similar** if the frequency of each element is the same.

Return *the minimum number of operations required to make* `nums` *similar to* `target`. The test cases are generated such that `nums` can always be similar to `target`.


**Example 1:**

```

**Input:** nums = [8,12,6], target = [2,14,10]
**Output:** 2
**Explanation:** It is possible to make nums similar to target in two operations:
- Choose i = 0 and j = 2, nums = [10,12,4].
- Choose i = 1 and j = 2, nums = [10,14,2].
It can be shown that 2 is the minimum number of operations needed.

```

**Example 2:**

```

**Input:** nums = [1,2,5], target = [4,1,3]
**Output:** 1
**Explanation:** We can make nums similar to target in one operation:
- Choose i = 1 and j = 2, nums = [1,4,3].

```

**Example 3:**

```

**Input:** nums = [1,1,1,1,1], target = [1,1,1,1,1]
**Output:** 0
**Explanation:** The array nums is already similiar to target.

```

**Constraints:**
* `n == nums.length == target.length`
* `1 <= n <= 105`
* `1 <= nums[i], target[i] <= 106`
* It is possible to make `nums` similar to `target`.


<br>

### Hints

- Solve for even and odd numbers separately.
- Greedily match smallest even element from nums to smallest even element from target, then similarly next smallest element and so on.
- Similarly, match odd elements too.

<br>

### Solution

```cpp
class Solution {
public:
    long long makeSimilar (vector <int>& nums, vector <int>& target) {
      std::sort(nums.begin(), nums.end());
      std::sort(target.begin(), target.end());
      
      std::vector <int> odd_nums, even_nums;
      std::vector <int> odd_target, even_target;
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        (nums[i] & 1 ? odd_nums : even_nums).push_back(nums[i]);
        (target[i] & 1 ? odd_target : even_target).push_back(target[i]);
      }
      
      int64_t diff = 0;
      int p = odd_nums.size(), q = even_nums.size();
      
      for (int i = 0; i < p; ++i)
        diff += std::abs(odd_nums[i] - odd_target[i]);
      for (int i = 0; i < q; ++i)
        diff += std::abs(even_nums[i] - even_target[i]);
      
      return diff / 4;
    }
};
```

<br>

### Statistics

- total accepted: 4021
- total submissions: 6516
- acceptance rate: 61.7%
- likes: 107
- dislikes: 6

<br>

### Similar Problems

- [Minimum Operations to Make Array Equal](https://leetcode.com/problems/minimum-operations-to-make-array-equal) (Medium)

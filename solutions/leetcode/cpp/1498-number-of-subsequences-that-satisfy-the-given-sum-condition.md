# [1498] Number of Subsequences That Satisfy the Given Sum Condition

**[array, two-pointers, binary-search, sorting]**

### Statement

You are given an array of integers `nums` and an integer `target`.

Return *the number of **non-empty** subsequences of* `nums` *such that the sum of the minimum and maximum element on it is less or equal to* `target`. Since the answer may be too large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** nums = [3,5,6,7], target = 9
**Output:** 4
**Explanation:** There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

```

**Example 2:**

```

**Input:** nums = [3,3,6,8], target = 10
**Output:** 6
**Explanation:** There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

```

**Example 3:**

```

**Input:** nums = [2,3,3,4,6,7], target = 12
**Output:** 61
**Explanation:** There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^6`
* `1 <= target <= 10^6`


<br />

### Hints

- Sort the array nums.
- Use two pointers approach: Given an index i (choose it as the minimum in a subsequence) find the maximum j where j ≥ i and nums[i] +nums[j] ≤ target.
- Count the number of subsequences.

<br />

### Solution

```cpp
class Solution {
  public:
    int numSubseq (vector <int>& nums, int target) {
      const int mod = 1000000007;
      int n = nums.size(), r = n - 1;
      int64_t ans = 0;
      std::vector <int64_t> pow (n);
      
      pow[0] = 1;
      for (int i = 1; i < n; ++i)
        pow[i] = 2 * pow[i - 1] % mod;

      std::sort(nums.begin(), nums.end());

      for (int l = 0; l <= r; ++l) {
        if (nums[l] + nums[r] > target)
          --r, --l;
        else
          ans = (ans + pow[r - l]) % mod;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 78785
- total submissions: 180410
- acceptance rate: 43.7%
- likes: 3016
- dislikes: 262

<br />

### Similar Problems

None

# [1658] Minimum Operations to Reduce X to Zero

**[array, hash-table, binary-search, sliding-window, prefix-sum]**

### Statement

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it is possible**, otherwise, return* `-1`.


**Example 1:**

```

**Input:** nums = [1,1,4,2,3], x = 5
**Output:** 2
**Explanation:** The optimal solution is to remove the last two elements to reduce x to zero.

```

**Example 2:**

```

**Input:** nums = [5,6,7,8,9], x = 4
**Output:** -1

```

**Example 3:**

```

**Input:** nums = [3,2,20,1,1,3], x = 10
**Output:** 5
**Explanation:** The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^4`
* `1 <= x <= 10^9`


<br />

### Hints

- Think in reverse; instead of finding the minimum prefix + suffix, find the maximum subarray.
- Finding the maximum subarray is standard and can be done greedily.

<br />

### Solution

```cpp
class Solution {
  public:
    int minOperations(vector <int>& nums, int x) {
      int n = nums.size(), ans = 1 << 30;
      std::vector <int> prefix(n + 1), suffix(n + 1);

      for (int i = 0; i < n; ++i) {
        int j = n - i - 1;
        prefix[i + 1] += prefix[i] + nums[i];
        suffix[j] += suffix[j + 1] + nums[j];
      }

      if (prefix.back() == x)
        ans = n;

      for (int i = 0; i <= n; ++i) {
        int target = x - prefix[i];
        int low = i + 1, high = n + 1;
        while (low < high) {
          int mid = (low + high) / 2;
          if (suffix[mid] >= target)
            low = mid + 1;
          else
            high = mid;
        }
        if (low != i + 1 and target == suffix[low - 1])
          ans = std::min(ans, i + 1 + n - low);
      }

      return ans == (1 << 30) ? -1 : ans;
    }
};
```

<br />

### Statistics

- total accepted: 135578
- total submissions: 352510
- acceptance rate: 38.5%
- likes: 4580
- dislikes: 91

<br />

### Similar Problems

- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) (Medium)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) (Medium)
- [Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number) (Medium)
- [Removing Minimum Number of Magic Beans](https://leetcode.com/problems/removing-minimum-number-of-magic-beans) (Medium)
- [Minimum Operations to Make the Integer Zero](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero) (Medium)

# [1814] Count Nice Pairs in an Array

**[array, hash-table, math, counting]**

### Statement

You are given an array `nums` that consists of non-negative integers. Let us define `rev(x)` as the reverse of the non-negative integer `x`. For example, `rev(123) = 321`, and `rev(120) = 21`. A pair of indices `(i, j)` is **nice** if it satisfies all of the following conditions:

* `0 <= i < j < nums.length`
* `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`



Return *the number of nice pairs of indices*. Since that number can be too large, return it **modulo** `10^9 + 7`.


**Example 1:**

```

**Input:** nums = [42,11,1,97]
**Output:** 2
**Explanation:** The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.

```

**Example 2:**

```

**Input:** nums = [13,10,35,24,76]
**Output:** 4

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^9`


<br />

### Hints

- The condition can be rearranged to (nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])).
- Transform each nums[i] into (nums[i] - rev(nums[i])). Then, count the number of (i, j) pairs that have equal values.
- Keep a map storing the frequencies of values that you have seen so far. For each i, check if nums[i] is in the map. If it is, then add that count to the overall count. Then, increment the frequency of nums[i].

<br />

### Solution

```cpp
class Solution {
  public:
    int countNicePairs (vector <int>& nums) {
      constexpr int mod = 1000000007;

      auto rev = [] (int x) {
        int r = 0;
        while (x) { 
          r = r * 10 + x % 10;
          x /= 10;
        }
        return r;
      };

      std::map <int, int> freq;
      int64_t ans = 0;

      for (int i: nums)
        ++freq[i - rev(i)];
      
      for (auto &[k, v]: freq) {
        ans += int64_t(v) * (v - 1) / 2;
        ans %= mod;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 23174
- total submissions: 55095
- acceptance rate: 42.1%
- likes: 693
- dislikes: 27

<br />

### Similar Problems

- [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) (Medium)
- [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs) (Medium)
- [Number of Pairs Satisfying Inequality](https://leetcode.com/problems/number-of-pairs-satisfying-inequality) (Hard)

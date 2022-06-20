# [1695] Maximum Erasure Value

**[array, hash-table, sliding-window]**

### Statement

You are given an array of positive integers `nums` and want to erase a subarray containing**unique elements**. The **score** you get by erasing the subarray is equal to the **sum** of its elements.

Return *the **maximum score** you can get by erasing **exactly one** subarray.*

An array `b` is called to be a subarray of `a` if it forms a contiguous subsequence of `a`, that is, if it is equal to `a[l],a[l+1],...,a[r]` for some `(l,r)`.


**Example 1:**

```

**Input:** nums = [4,2,4,5,6]
**Output:** 17
**Explanation:** The optimal subarray here is [2,4,5,6].

```

**Example 2:**

```

**Input:** nums = [5,2,1,2,5,2,1,2,5]
**Output:** 8
**Explanation:** The optimal subarray here is [5,2,1] or [1,2,5].

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 104`


<br>

### Hints

- The main point here is for the subarray to contain unique elements for each index. Only the first subarrays starting from that index have unique elements.
- This can be solved using the two pointers technique

<br>

### Solution

```cpp
class Solution {
  public:
    int maximumUniqueSubarray (vector <int>& nums) {
      const int max = 10000 + 1;
      bool have[max] = {};
      
      int l = 0, sum = 0, best = 0;
      
      for (int i = 0; i < (int)nums.size(); ++i) {
        if (have[nums[i]]) {
          while (nums[l] != nums[i]) {
            sum -= nums[l];
            have[nums[l]] = false;
            ++l;
          }
          ++l;
        }
        else {
          have[nums[i]] = true;
          sum += nums[i];
          best = std::max(best, sum);
        }
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 96410
- total submissions: 166754
- acceptance rate: 57.8%
- likes: 2193
- dislikes: 35

<br>

### Similar Problems

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) (Medium)

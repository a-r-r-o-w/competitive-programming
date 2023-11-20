# [1493] Longest Subarray of 1's After Deleting One Element

**[array, dynamic-programming, sliding-window]**

### Statement

Given a binary array `nums`, you should delete one element from it.

Return *the size of the longest non-empty subarray containing only* `1`*'s in the resulting array*. Return `0` if there is no such subarray.


**Example 1:**

```

**Input:** nums = [1,1,0,1]
**Output:** 3
**Explanation:** After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

```

**Example 2:**

```

**Input:** nums = [0,1,1,1,0,1,1,0,1]
**Output:** 5
**Explanation:** After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

```

**Example 3:**

```

**Input:** nums = [1,1,1]
**Output:** 2
**Explanation:** You must delete one element.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `nums[i]` is either `0` or `1`.


<br />

### Hints

- Maintain a sliding window where there is at most one zero on it.

<br />

### Solution

```cpp
class Solution {
  public:
    int longestSubarray (vector <int>& nums) {
      int n = nums.size(), ans = 0;
      int prev_one_count = 0;
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        int one_count = 0, zero_count = 0;

        while (j < n and nums[j] == 0) {
          ++j;
          ++zero_count;
        }
        while (j < n and nums[j] == 1) {
          ++j;
          ++one_count;
        }
        if (zero_count <= 1)
          ans = std::max(ans, prev_one_count + one_count + zero_count - 1);
        else
          ans = std::max({ans, one_count, prev_one_count});
        prev_one_count = one_count;
        i = j - 1;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 129490
- total submissions: 197000
- acceptance rate: 65.7%
- likes: 2839
- dislikes: 49

<br />

### Similar Problems

None

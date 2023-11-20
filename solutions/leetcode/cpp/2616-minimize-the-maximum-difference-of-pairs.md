# [2616] Minimize the Maximum Difference of Pairs

**[array, binary-search, greedy]**

### Statement

You are given a **0-indexed** integer array `nums` and an integer `p`. Find `p` pairs of indices of `nums` such that the **maximum** difference amongst all the pairs is **minimized**. Also, ensure no index appears more than once amongst the `p` pairs.

Note that for a pair of elements at the index `i` and `j`, the difference of this pair is `|nums[i] - nums[j]|`, where `|x|` represents the **absolute** **value** of `x`.

Return *the **minimum** **maximum** difference among all* `p` *pairs.* We define the maximum of an empty set to be zero.


**Example 1:**

```

**Input:** nums = [10,1,2,7,1,3], p = 2
**Output:** 1
**Explanation:** The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

```

**Example 2:**

```

**Input:** nums = [4,2,1,2], p = 1
**Output:** 0
**Explanation:** Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^9`
* `0 <= p <= (nums.length)/2`


<br />

### Hints

- Can we use dynamic programming here?
- To minimize the answer, the array should be sorted first.
- The recurrence relation is fn(i, x) = min(fn(i+1, x), max(abs(nums[i]-nums[i+1]), fn(i+2, p-1)), and fn(0,p) gives the desired answer.

<br />

### Solution

```cpp
class Solution {
  public:
    int minimizeMax (vector <int>& nums, int p) {
      int n = nums.size();
      std::sort(nums.begin(), nums.end());

      auto cost = [&] (int x) {
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
          if (nums[i + 1] - nums[i] <= x) {
            ++count;
            ++i;
          }
        }
        return count >= p;
      };
      int low = 0, high = 1e9;

      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          high = mid;
        else
          low = mid + 1;
      }

      return low;
    }
};
```

<br />

### Statistics

- total accepted: 26768
- total submissions: 66992
- acceptance rate: 40.0%
- likes: 1144
- dislikes: 117

<br />

### Similar Problems

- [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference) (Easy)
- [Minimum Difference Between Largest and Smallest Value in Three Moves](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves) (Medium)

# [1906] Minimum Absolute Difference Queries

**[array, hash-table]**

### Statement

The **minimum absolute difference** of an array `a` is defined as the **minimum value** of `|a[i] - a[j]|`, where `0 <= i < j < a.length` and `a[i] != a[j]`. If all elements of `a` are the **same**, the minimum absolute difference is `-1`.

* For example, the minimum absolute difference of the array `[5,2,3,7,2]` is `|2 - 3| = 1`. Note that it is not `0` because `a[i]` and `a[j]` must be different.



You are given an integer array `nums` and the array `queries` where `queries[i] = [li, ri]`. For each query `i`, compute the **minimum absolute difference** of the **subarray** `nums[li...ri]` containing the elements of `nums` between the **0-based** indices `li` and `ri` (**inclusive**).

Return *an **array*** `ans` *where* `ans[i]` *is the answer to the* `ith` *query*.

A **subarray** is a contiguous sequence of elements in an array.

The value of `|x|` is defined as:

* `x` if `x >= 0`.
* `-x` if `x < 0`.


**Example 1:**

```

**Input:** nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
**Output:** [2,1,4,1]
**Explanation:** The queries are processed as follows:
- queries[0] = [0,1]: The subarray is [1,3] and the minimum absolute difference is |1-3| = 2.
- queries[1] = [1,2]: The subarray is [3,4] and the minimum absolute difference is |3-4| = 1.
- queries[2] = [2,3]: The subarray is [4,8] and the minimum absolute difference is |4-8| = 4.
- queries[3] = [0,3]: The subarray is [1,3,4,8] and the minimum absolute difference is |3-4| = 1.

```

**Example 2:**

```

**Input:** nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
**Output:** [-1,1,1,3]
**Explanation:** The queries are processed as follows:
- queries[0] = [2,3]: The subarray is [2,2] and the minimum absolute difference is -1 because all the
  elements are the same.
- queries[1] = [0,2]: The subarray is [4,5,2] and the minimum absolute difference is |4-5| = 1.
- queries[2] = [0,5]: The subarray is [4,5,2,2,7,10] and the minimum absolute difference is |4-5| = 1.
- queries[3] = [3,5]: The subarray is [2,7,10] and the minimum absolute difference is |7-10| = 3.

```

**Constraints:**
* `2 <= nums.length <= 105`
* `1 <= nums[i] <= 100`
* `1 <= queries.length <= 2* 104`
* `0 <= li < ri < nums.length`


<br>

### Hints

- How does the maximum value being 100 help us?
- How can we tell if a number exists in a given range?

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> minDifference (vector <int>& nums, vector <vector <int>>& queries) {
      constexpr int max = 100 + 1;
      constexpr int inf = 1 << 30;

      int n = nums.size();
      std::vector <std::vector <int>> freq (n + 1, std::vector <int> (max));
      std::vector <int> ans;
      ans.reserve(n);

      for (int i = 1; i <= n; ++i) {
        ++freq[i][nums[i - 1]];

        for (int j = 0; j < max; ++j)
          freq[i][j] += freq[i - 1][j];
      }

      for (auto &v: queries) {
        int p = v[0], q = v[1];
        auto f = freq[q + 1];

        for (int i = 0; i < max; ++i)
          f[i] -= freq[p][i];
        
        int first = -1, min = inf;

        for (int i = 0; i < max; ++i) {
          if (f[i] <= 0)
            continue;
          else if (first == -1)
            first = i;
          else {
            min = std::min(min, i - first);
            first = i;
          }
        }

        if (min == inf)
          min = -1;
        
        ans.push_back(min);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 9111
- total submissions: 20756
- acceptance rate: 43.9%
- likes: 449
- dislikes: 30

<br>

### Similar Problems

None

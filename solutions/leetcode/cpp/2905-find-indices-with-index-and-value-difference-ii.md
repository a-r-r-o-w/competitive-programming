# [2905] Find Indices With Index and Value Difference II



### Statement

You are given a **0-indexed** integer array `nums` having length `n`, an integer `indexDifference`, and an integer `valueDifference`.

Your task is to find **two** indices `i` and `j`, both in the range `[0, n - 1]`, that satisfy the following conditions:

* `abs(i - j) >= indexDifference`, and
* `abs(nums[i] - nums[j]) >= valueDifference`



Return *an integer array* `answer`, *where* `answer = [i, j]` *if there are two such indices*, *and* `answer = [-1, -1]` *otherwise*. If there are multiple choices for the two indices, return *any of them*.

**Note:** `i` and `j` may be **equal**.


**Example 1:**

```

**Input:** nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
**Output:** [0,3]
**Explanation:** In this example, i = 0 and j = 3 can be selected.
abs(0 - 3) >= 2 and abs(nums[0] - nums[3]) >= 4.
Hence, a valid answer is [0,3].
[3,0] is also a valid answer.

```

**Example 2:**

```

**Input:** nums = [2,1], indexDifference = 0, valueDifference = 0
**Output:** [0,0]
**Explanation:** In this example, i = 0 and j = 0 can be selected.
abs(0 - 0) >= 0 and abs(nums[0] - nums[0]) >= 0.
Hence, a valid answer is [0,0].
Other valid answers are [0,1], [1,0], and [1,1].

```

**Example 3:**

```

**Input:** nums = [1,2,3], indexDifference = 2, valueDifference = 4
**Output:** [-1,-1]
**Explanation:** In this example, it can be shown that it is impossible to find two indices that satisfy both conditions.
Hence, [-1,-1] is returned.
```

**Constraints:**
* `1 <= n == nums.length <= 10^5`
* `0 <= nums[i] <= 10^9`
* `0 <= indexDifference <= 10^5`
* `0 <= valueDifference <= 10^9`


<br />

### Hints

- For each index <code>i >= indexDifference</code>, keep the indices <code>j<sub>1</sub></code> and <code>j<sub>2</sub></code> in the range <code>[0, i - indexDifference]</code> such that <code>nums[j<sub>1</sub>]</code> and <code>nums[j<sub>2</sub>]</code> are the minimum and maximum values in the index range.
- Check if <code>abs(nums[i] - nums[j<sub>1</sub>]) >= valueDifference</code> or <code>abs(nums[i] - nums[j<sub>2</sub>]) >= valueDifference</code>.
- <code>j<sub>1</sub></code> and <code>j<sub>2</sub></code> can be updated dynamically, or they can be pre-computed since they are just prefix minimum and maximum.

<br />

### Solution

```cpp
class Solution {
  public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
      int n = nums.size();
      std::vector<std::pair<int, int>> v;
      
      for (int i = 0; i < n; ++i)
        v.emplace_back(nums[i], i);
      std::sort(v.begin(), v.end());
      
      std::vector<int> suffix_max(n), suffix_min(n);
      suffix_max[n - 1] = v[n - 1].second;
      suffix_min[n - 1] = v[n - 1].second;
      
      for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = std::max(suffix_max[i + 1], v[i].second);
        suffix_min[i] = std::min(suffix_min[i + 1], v[i].second);
      }
      
      for (int i = 0; i < n; ++i) {
        int look = v[i].first + valueDifference;
        // std::cout << i << ' ' << look << std::endl;
        auto index = std::lower_bound(v.begin(), v.end(), std::pair{look, -1}) - v.begin();
        // std::cout << "idx: " << index << std::endl;
        if (index >= n)
          break;
        int max = suffix_max[index], min = suffix_min[index];
        // std::cout << "this: " << v[i].second << ' ' << max << ' ' << min << '\n';
        if (std::abs(max - v[i].second) >= indexDifference)
          return {v[i].second, max};
        if (std::abs(min - v[i].second) >= indexDifference)
          return {v[i].second, min};
      }
      // std::cout << std::endl;
      
      return {-1, -1};
    }
};
```

<br />

### Statistics

- total accepted: 7784
- total submissions: 30020
- acceptance rate: 25.9%
- likes: 78
- dislikes: 2

<br />

### Similar Problems

- [Minimum Absolute Difference Between Elements With Constraint](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint) (Medium)

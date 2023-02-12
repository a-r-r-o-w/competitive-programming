# [2563] Count the Number of Fair Pairs



### Statement

Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return *the number of fair pairs*.

A pair `(i, j)` is **fair** if:

* `0 <= i < j < n`, and
* `lower <= nums[i] + nums[j] <= upper`


**Example 1:**

```

**Input:** nums = [0,1,7,4,4,5], lower = 3, upper = 6
**Output:** 6
**Explanation:** There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

```

**Example 2:**

```

**Input:** nums = [1,7,9,2,5], lower = 11, upper = 11
**Output:** 1
**Explanation:** There is a single fair pair: (2,3).

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `nums.length == n`
* `-10^9<= nums[i] <= 10^9`
* `-10^9<= lower <= upper <= 10^9`


<br />

### Hints

- Sort the array in ascending order.
- For each number in the array, keep track of the smallest and largest numbers in the array that can form a fair pair with this number.
- As you move to larger number, both boundaries move down.

<br />

### Solution

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T>
using ordered_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::greater <T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

class Solution {
  public:
    long long countFairPairs (vector <int>& nums, int lower, int upper) {
      int64_t ans = 0;
      int n = nums.size();
      ordered_set <std::pair <int, int>> have;
      
      for (int i = n - 1; i >= 0; --i) {
        int l = lower - nums[i], u = upper - nums[i];
        int lb = have.order_of_key({l, 0});
        int ub = have.order_of_key({u, n});
        // std::cout << i << ' ' << nums[i] << ' ' << l << ' ' << u << ' ' << lb << ' ' << ub << '\n';
        ans += lb - ub;
        have.insert({nums[i], i});
      }
      // std::cout << '\n';
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 9245
- total submissions: 34486
- acceptance rate: 26.8%
- likes: 230
- dislikes: 8

<br />

### Similar Problems

- [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum) (Hard)
- [Finding Pairs With a Certain Sum](https://leetcode.com/problems/finding-pairs-with-a-certain-sum) (Medium)
- [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k) (Easy)

# [2226] Maximum Candies Allocated to K Children

**[array, binary-search]**

### Statement

You are given a **0-indexed** integer array `candies`. Each element in the array denotes a pile of candies of size `candies[i]`. You can divide each pile into any number of **sub piles**, but you **cannot** merge two piles together.

You are also given an integer `k`. You should allocate piles of candies to `k` children such that each child gets the **same** number of candies. Each child can take **at most one** pile of candies and some piles of candies may go unused.

Return *the **maximum number of candies** each child can get.*
**Example 1:**

```

**Input:** candies = [5,8,6], k = 3
**Output:** 5
**Explanation:** We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.

```

**Example 2:**

```

**Input:** candies = [2,5], k = 11
**Output:** 0
**Explanation:** There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

```

**Constraints:**
* `1 <= candies.length <= 10^5`
* `1 <= candies[i] <= 10^7`
* `1 <= k <= 10^12`


<br />

### Hints

- For a fixed number of candies c, how can you check if each child can get c candies?
- Use binary search to find the maximum c as the answer.

<br />

### Solution

```cpp
class Solution {
  public:
    int maximumCandies (vector <int>& candies, long long k) {
      int low = 0, high = 1e9, n = candies.size();

      auto cost = [&] (int x) {
        if (x == 0)
          return true;
        int64_t have = 0;
        for (int i = 0; i < n; ++i) {
          have += candies[i] / x;
          if (have >= k)
            return true;
        }
        return false;
      };

      while (low < high) {
        int mid = (low + high) / 2;
        if (cost(mid))
          low = mid + 1;
        else
          high = mid;
      }

      return low - 1;
    }
};
```

<br />

### Statistics

- total accepted: 24929
- total submissions: 68192
- acceptance rate: 36.6%
- likes: 698
- dislikes: 33

<br />

### Similar Problems

- [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas) (Medium)
- [Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag) (Medium)
- [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time) (Medium)
- [Maximum Number of Removable Characters](https://leetcode.com/problems/maximum-number-of-removable-characters) (Medium)
- [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) (Medium)
- [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips) (Medium)
- [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array) (Medium)

# [2305] Fair Distribution of Cookies

**[array, dynamic-programming, backtracking, bit-manipulation, bitmask]**

### Statement

You are given an integer array `cookies`, where `cookies[i]` denotes the number of cookies in the `i^th` bag. You are also given an integer `k` that denotes the number of children to distribute **all** the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The **unfairness** of a distribution is defined as the **maximum** **total** cookies obtained by a single child in the distribution.

Return *the **minimum** unfairness of all distributions*.


**Example 1:**

```

**Input:** cookies = [8,15,10,20,8], k = 2
**Output:** 31
**Explanation:** One optimal distribution is [8,15,8] and [10,20]
- The 1^st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2^nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.

```

**Example 2:**

```

**Input:** cookies = [6,1,3,2,2,4,1,2], k = 3
**Output:** 7
**Explanation:** One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1^st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2^nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3^rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.

```

**Constraints:**
* `2 <= cookies.length <= 8`
* `1 <= cookies[i] <= 10^5`
* `2 <= k <= cookies.length`


<br />

### Hints

- We have to give each bag to one of the children. How can we enumerate all of the possibilities?
- Use recursion and keep track of the current number of cookies each child has. Once all the bags have been distributed, find the child with the most cookies.

<br />

### Solution

```cpp
class Solution {
  public:
    int distributeCookies (vector <int>& cookies, int k) {
      int n = cookies.size(), ans = 1 << 30;
      std::vector <int> given (k);

      auto dfs = [&] (auto self, int index, int max) -> void {
        if (index == n) {
          ans = std::min(ans, max);
          return;
        }
        for (int i = 0; i < k; ++i) {
          given[i] += cookies[index];
          self(self, index + 1, std::max(max, given[i]));
          given[i] -= cookies[index];
          if (given[i] == 0)
            break;
        }
      };

      dfs(dfs, 0, 0);

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 21203
- total submissions: 34062
- acceptance rate: 62.2%
- likes: 756
- dislikes: 39

<br />

### Similar Problems

- [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) (Hard)
- [Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum) (Hard)
- [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets) (Medium)
- [Minimum XOR Sum of Two Arrays](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays) (Hard)
- [The Number of Good Subsets](https://leetcode.com/problems/the-number-of-good-subsets) (Hard)
- [Minimum Number of Work Sessions to Finish the Tasks](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks) (Medium)
- [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) (Hard)
- [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns) (Medium)

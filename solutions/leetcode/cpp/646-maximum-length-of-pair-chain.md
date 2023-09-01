# [646] Maximum Length of Pair Chain

**[array, dynamic-programming, greedy, sorting]**

### Statement

You are given an array of `n` pairs `pairs` where `pairs[i] = [lefti, righti]` and `lefti < righti`.

A pair `p2 = [c, d]` **follows** a pair `p1 = [a, b]` if `b < c`. A **chain** of pairs can be formed in this fashion.

Return *the length longest chain which can be formed*.

You do not need to use up all the given intervals. You can select pairs in any order.


**Example 1:**

```

**Input:** pairs = [[1,2],[2,3],[3,4]]
**Output:** 2
**Explanation:** The longest chain is [1,2] -> [3,4].

```

**Example 2:**

```

**Input:** pairs = [[1,2],[7,8],[4,5]]
**Output:** 3
**Explanation:** The longest chain is [1,2] -> [4,5] -> [7,8].

```

**Constraints:**
* `n == pairs.length`
* `1 <= n <= 1000`
* `-1000 <= lefti < righti <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int findLongestChain(vector <vector <int>>& pairs) {
      int n = pairs.size();
      
      std::sort(pairs.begin(), pairs.end(), [] (auto &l, auto &r) {
        if (l[1] < r[1])
          return true;
        if (l[1] > r[1])
          return false;
        return l[0] > r[0];
      });

      int count = 0, prev = -(1 << 30);
      for (int i = 0; i < n; ++i) {
        if (pairs[i][0] > prev) {
          prev = pairs[i][1];
          ++count;
        }
      }

      return count;
    }
};
```

<br />

### Statistics

- total accepted: 168108
- total submissions: 289526
- acceptance rate: 58.1%
- likes: 3662
- dislikes: 123

<br />

### Similar Problems

- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
- [Non-decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences) (Medium)
- [Longest Non-decreasing Subarray From Two Arrays](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays) (Medium)

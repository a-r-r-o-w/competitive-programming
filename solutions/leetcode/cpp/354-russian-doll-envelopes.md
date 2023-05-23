# [354] Russian Doll Envelopes

**[array, binary-search, dynamic-programming, sorting]**

### Statement

You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return *the maximum number of envelopes you can Russian doll (i.e., put one inside the other)*.

**Note:** You cannot rotate an envelope.


**Example 1:**

```

**Input:** envelopes = [[5,4],[6,4],[6,7],[2,3]]
**Output:** 3
**Explanation:** The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

```

**Example 2:**

```

**Input:** envelopes = [[1,1],[1,1],[1,1]]
**Output:** 1

```

**Constraints:**
* `1 <= envelopes.length <= 10^5`
* `envelopes[i].length == 2`
* `1 <= wi, hi <= 10^5`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int maxEnvelopes (vector <vector <int>>& envelopes) {
      std::sort(envelopes.begin(), envelopes.end(), [&] (auto &l, auto &r) {
        if (l[0] < r[0])
          return true;
        if (l[0] > r[0])
          return false;
        return l[1] > r[1];
      });

      int n = envelopes.size();
      std::vector <int> dp;

      for (int i = 0; i < n; ++i) {
        int w = envelopes[i][0], h = envelopes[i][1];
        auto f = std::lower_bound(dp.begin(), dp.end(), h);
        if (f == dp.end())
          dp.push_back(h);
        else
          *f = h;
      }

      return dp.size();
    }
};
```

<br />

### Statistics

- total accepted: 187299
- total submissions: 494213
- acceptance rate: 37.9%
- likes: 5024
- dislikes: 123

<br />

### Similar Problems

- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) (Medium)
- [The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game) (Medium)

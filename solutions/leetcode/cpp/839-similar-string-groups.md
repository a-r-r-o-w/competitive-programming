# [839] Similar String Groups

**[array, string, depth-first-search, breadth-first-search, union-find]**

### Statement

Two strings `X`and `Y`are similar if we can swap two letters (in different positions) of `X`, so thatit equals `Y`. Also two strings `X` and `Y` are similar if they are equal.

For example, `"tars"`and `"rats"`are similar (swapping at positions `0` and `2`), and `"rats"` and `"arts"` are similar, but `"star"` is not similar to `"tars"`, `"rats"`, or `"arts"`.

Together, these form two connected groups by similarity: `{"tars", "rats", "arts"}` and `{"star"}`. Notice that `"tars"` and `"arts"` are in the same group even though they are not similar. Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list `strs` of strings where every string in `strs` is an anagram of every other string in `strs`. How many groups are there?


**Example 1:**

```

**Input:** strs = ["tars","rats","arts","star"]
**Output:** 2

```

**Example 2:**

```

**Input:** strs = ["omv","ovm"]
**Output:** 1

```

**Constraints:**
* `1 <= strs.length <= 300`
* `1 <= strs[i].length <= 300`
* `strs[i]` consists of lowercase letters only.
* All words in `strs` have the same length and are anagrams of each other.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int numSimilarGroups (vector <string>& strs) {
      int n = strs.size(), m = strs.front().length();
      std::vector <int> parent (n), rank (n);

      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v)
          return;
        if (rank[u] < rank[v])
          std::swap(u, v);
        ++rank[u];
        parent[v] = u;
      };

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          int diff = 0;
          for (int k = 0; k < m; ++k) {
            if (strs[i][k] != strs[j][k])
              ++diff;
          }
          if (diff == 0 or diff == 2)
            unite(i, j);
        }
      }

      std::unordered_set <int> unique;
      for (int i = 0; i < n; ++i)
        unique.insert(find(find, i));
      
      return unique.size();
    }
};
```

<br />

### Statistics

- total accepted: 83150
- total submissions: 162462
- acceptance rate: 51.2%
- likes: 1600
- dislikes: 189

<br />

### Similar Problems

- [Groups of Strings](https://leetcode.com/problems/groups-of-strings) (Hard)

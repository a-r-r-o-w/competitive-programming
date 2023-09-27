# [1202] Smallest String With Swaps

**[hash-table, string, depth-first-search, breadth-first-search, union-find]**

### Statement

You are given a string `s`, and an array of pairs of indices in the string`pairs`where`pairs[i] =[a, b]`indicates 2 indices(0-indexed) of the string.

You canswap the characters at any pair of indices in the given`pairs`**any number of times**.

Return thelexicographically smallest string that `s`can be changed to after using the swaps.


**Example 1:**

```

**Input:** s = "dcab", pairs = [[0,3],[1,2]]
**Output:** "bacd"
**Explaination:** 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

```

**Example 2:**

```

**Input:** s = "dcab", pairs = [[0,3],[1,2],[0,2]]
**Output:** "abcd"
**Explaination:** 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
```

**Example 3:**

```

**Input:** s = "cba", pairs = [[0,1],[1,2]]
**Output:** "abc"
**Explaination:** 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

```

**Constraints:**
* `1 <= s.length <= 10^5`
* `0 <= pairs.length <= 10^5`
* `0 <= pairs[i][0], pairs[i][1] <s.length`
* `s`only contains lower case English letters.


<br>

### Hints

- Think of it as a graph problem.
- Consider the pairs as connected nodes in the graph, what can you do with a connected component of indices ?
- We can sort each connected component alone to get the lexicographically minimum string.

<br>

### Solution

```cpp
class Solution {
  public:
    string smallestStringWithSwaps (string s, vector <vector <int>>& pairs) {
      int n = s.length();
      std::vector <int> parent (n), rank (n);

      std::iota(parent.begin(), parent.end(), 0);

      auto find = [&] (auto self, int u) -> int {
        return parent[u] = u == parent[u] ? u : self(self, parent[u]);
      };

      auto unite = [&] (int u, int v) {
        u = find(find, u);
        v = find(find, v);

        if (u == v)
          return;
        if (rank[u] < rank[v])
          std::swap(u, v);
        
        ++rank[u];
        parent[v] = u;
      };

      for (auto &p: pairs)
        unite(p[0], p[1]);
      
      std::unordered_map <int, std::pair <std::string, std::vector <int>>> buckets;

      for (int i = 0; i < n; ++i) {
        int p = find(find, i);
        buckets[p].first += s[i];
        buckets[p].second.push_back(i);
      }
      
      for (auto &[k, v]: buckets) {
        auto &[x, indices] = v;
        int n = x.length();
        
        std::sort(x.begin(), x.end());
        for (int i = 0; i < n; ++i)
          s[indices[i]] = x[i];
      }

      return s;
    }
};
```

<br>

### Statistics

- total accepted: 95171
- total submissions: 165142
- acceptance rate: 57.6%
- likes: 3225
- dislikes: 111

<br>

### Similar Problems

- [Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations) (Medium)
- [Process Restricted Friend Requests](https://leetcode.com/problems/process-restricted-friend-requests) (Hard)
- [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity) (Easy)

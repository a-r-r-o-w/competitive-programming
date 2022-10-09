# [990] Satisfiability of Equality Equations

**[array, string, union-find, graph]**

### Statement

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: `"xi==yi"` or `"xi!=yi"`.Here, `xi` and `yi` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` *if it is possible to assign integers to variable names so as to satisfy all the given equations, or* `false` *otherwise*.


**Example 1:**

```

**Input:** equations = ["a==b","b!=a"]
**Output:** false
**Explanation:** If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

```

**Example 2:**

```

**Input:** equations = ["b==a","a==b"]
**Output:** true
**Explanation:** We could assign a = 1 and b = 1 to satisfy both equations.

```

**Constraints:**
* `1 <= equations.length <= 500`
* `equations[i].length == 4`
* `equations[i][0]` is a lowercase letter.
* `equations[i][1]` is either `'='` or `'!'`.
* `equations[i][2]` is `'='`.
* `equations[i][3]` is a lowercase letter.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool equationsPossible (vector <string>& equations) {
      const int max = 26;
      
      std::vector <int> parent (max), rank (max);
      
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
        
        parent[v] = u;
        ++rank[u];
      };
      
      for (auto &e: equations) {
        int u = e.front() - 'a';
        int v = e.back() - 'a';
        
        if (e[1] == '=')
          unite(u, v);
      }
      
      for (int i = 0; i < max; ++i)
        find(find, i);
      
      for (auto &e: equations) {
        int u = e.front() - 'a';
        int v = e.back() - 'a';
        
        if (e[1] == '!' and parent[u] == parent[v])
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 69703
- total submissions: 137558
- acceptance rate: 50.7%
- likes: 2188
- dislikes: 30

<br>

### Similar Problems

None

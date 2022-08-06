# [77] Combinations

**[backtracking]**

### Statement

Given two integers `n` and `k`, return *all possible combinations of* `k` *numbers out of the range* `[1, n]`.

You may return the answer in **any order**.


**Example 1:**

```

**Input:** n = 4, k = 2
**Output:**
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

```

**Example 2:**

```

**Input:** n = 1, k = 1
**Output:** [[1]]

```

**Constraints:**
* `1 <= n <= 20`
* `1 <= k <= n`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> combine (int n, int k) {
      std::vector <std::vector <int>> ans;
      std::vector <int> current;
      current.reserve(k);
      
      auto dfs = [&] (auto self, int start) -> void {
        if ((int)current.size() == k) {
          ans.push_back(current);
          return;
        }
        
        for (int i = start; i <= n; ++i) {
          current.push_back(i);
          self(self, i + 1);
          current.pop_back();
        }
      };
      
      dfs(dfs, 1);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 567002
- total submissions: 869502
- acceptance rate: 65.2%
- likes: 4742
- dislikes: 156

<br>

### Similar Problems

- [Combination Sum](https://leetcode.com/problems/combination-sum) (Medium)
- [Permutations](https://leetcode.com/problems/permutations) (Medium)

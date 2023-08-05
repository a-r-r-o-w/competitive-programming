# [95] Unique Binary Search Trees II

**[dynamic-programming, backtracking, tree, binary-search-tree, binary-tree]**

### Statement

Given an integer `n`, return *all the structurally unique **BST'**s (binary search trees), which has exactly* `n` *nodes of unique values from* `1` *to* `n`. Return the answer in **any order**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```

**Input:** n = 3
**Output:** [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

```

**Example 2:**

```

**Input:** n = 1
**Output:** [[1]]

```

**Constraints:**
* `1 <= n <= 8`


<br />

### Hints

None

<br />

### Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    vector <TreeNode*> generateTrees (int n) {
      std::map <std::pair <int, int>, std::vector <TreeNode*>> dp;

      auto dfs = [&] (auto self, int l, int r) -> std::vector <TreeNode*> {
        std::vector <TreeNode*> trees;
        if (l > r) {
          trees.push_back(nullptr);
          return trees;
        }
        if (dp.count({l, r}))
          return dp[{l, r}];

        for (int i = l; i <= r; ++i) {
          auto lchild = self(self, l, i - 1);
          auto rchild = self(self, i + 1, r);

          for (auto &x: lchild) {
            for (auto &y: rchild) {
              TreeNode *node = new TreeNode(i, x, y);
              trees.push_back(node);
            }
          }
        }

        return dp[{l, r}] = trees;
      };

      return dfs(dfs, 1, n);
    }
};
```

<br />

### Statistics

- total accepted: 385791
- total submissions: 707185
- acceptance rate: 54.6%
- likes: 6742
- dislikes: 437

<br />

### Similar Problems

- [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) (Medium)
- [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses) (Medium)

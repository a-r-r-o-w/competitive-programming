# [894] All Possible Full Binary Trees

**[dynamic-programming, tree, recursion, memoization, binary-tree]**

### Statement

Given an integer `n`, return *a list of all possible **full binary trees** with* `n` *nodes*. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in **any order**.

A **full binary tree** is a binary tree where each node has exactly `0` or `2` children.


**Example 1:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png)

```

**Input:** n = 7
**Output:** [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

```

**Example 2:**

```

**Input:** n = 3
**Output:** [[0,0,0]]

```

**Constraints:**
* `1 <= n <= 20`


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
    vector <TreeNode*> allPossibleFBT (int n) {
      std::vector dp (n + 1, std::vector <TreeNode*>());
      
      auto generate = [&] (auto self, int n) -> std::vector <TreeNode*> {
        if (n % 2 == 0)
          return {};
        if (n == 1)
          return { new TreeNode() };
        if (!dp[n].empty())
          return dp[n];
        
        std::vector <TreeNode*> trees;

        for (int i = 1; i < n - 1; i += 2) {
          auto left = self(self, i);
          auto right = self(self, n - i - 1);

          for (auto &l: left) {
            for (auto &r: right) {
              TreeNode *node = new TreeNode(0, l, r);
              trees.push_back(node);
            }
          }
        }

        return dp[n] = trees;
      };

      return generate(generate, n);
    }
};
```

<br />

### Statistics

- total accepted: 133870
- total submissions: 164114
- acceptance rate: 81.6%
- likes: 4246
- dislikes: 287

<br />

### Similar Problems

None

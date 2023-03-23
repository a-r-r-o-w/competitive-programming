# [103] Binary Tree Zigzag Level Order Traversal

**[tree, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** [[3],[20,9],[15,7]]

```

**Example 2:**

```

**Input:** root = [1]
**Output:** [[1]]

```

**Example 3:**

```

**Input:** root = []
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 2000]`.
* `-100 <= Node.val <= 100`


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
    vector <vector <int>> zigzagLevelOrder (TreeNode* root) {
      std::queue <TreeNode*> q;
      std::vector <std::vector <int>> ans;
      std::vector <int> level;

      if (root != nullptr)
        q.push(root);
      
      while (!q.empty()) {
        int s = q.size();

        for (int i = 0; i < s; ++i) {
          auto u = q.front();
          q.pop();
          level.push_back(u->val);
          if (u->left != nullptr)
            q.push(u->left);
          if (u->right != nullptr)
            q.push(u->right);
        }

        if (ans.size() & 1)
          std::reverse(level.begin(), level.end());
        ans.emplace_back(std::move(level));
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 886552
- total submissions: 1583301
- acceptance rate: 56.0%
- likes: 8369
- dislikes: 220

<br />

### Similar Problems

- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) (Medium)

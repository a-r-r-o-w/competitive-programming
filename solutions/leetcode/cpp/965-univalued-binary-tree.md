# [965] Univalued Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

A binary tree is **uni-valued** if every node in the tree has the same value.

Given the `root` of a binary tree, return `true` *if the given tree is **uni-valued**, or* `false` *otherwise.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_1.png)

```

**Input:** root = [1,1,1,1,1,null,1]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_2.png)

```

**Input:** root = [2,2,2,5,2]
**Output:** false

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 100]`.
* `0 <= Node.val < 100`


<br>

### Hints

None

<br>

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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool isUnivalTree (TreeNode* root) {
      bool is_unival = true;
      int value = root->val;
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        is_unival &= value == node->val;
        if (node->left != nullptr)
          self(self, node->left);
        if (node->right != nullptr)
          self(self, node->right);
      };
      
      dfs(dfs, root);
      
      return is_unival;
    }
};
```

<br>

### Statistics

- total accepted: 167748
- total submissions: 242858
- acceptance rate: 69.1%
- likes: 1373
- dislikes: 56

<br>

### Similar Problems

- [Find All The Lonely Nodes](https://leetcode.com/problems/find-all-the-lonely-nodes) (Easy)

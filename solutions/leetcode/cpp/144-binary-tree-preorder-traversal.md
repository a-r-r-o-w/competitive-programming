# [144] Binary Tree Preorder Traversal

**[stack, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```

**Input:** root = [1,null,2,3]
**Output:** [1,2,3]

```

**Example 2:**

```

**Input:** root = []
**Output:** []

```

**Example 3:**

```

**Input:** root = [1]
**Output:** [1]

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`


**Follow up:** Recursive solution is trivial, could you do it iteratively?

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
    vector <int> preorderTraversal (TreeNode* root) {
      std::vector <int> order;
      
      auto dfs = [&] (auto self, TreeNode *node) -> void {
        if (node == nullptr)
          return;
        
        order.push_back(node->val);
        self(self, node->left);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 1077301
- total submissions: 1677546
- acceptance rate: 64.2%
- likes: 4958
- dislikes: 139

<br>

### Similar Problems

- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) (Easy)
- [Verify Preorder Sequence in Binary Search Tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree) (Medium)
- [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal) (Easy)

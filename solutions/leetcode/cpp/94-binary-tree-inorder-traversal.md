# [94] Binary Tree Inorder Traversal

**[stack, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```

**Input:** root = [1,null,2,3]
**Output:** [1,3,2]

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
    vector <int> inorderTraversal (TreeNode* root) {
      std::vector <int> order;
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node == nullptr)
          return;
        self(self, node->left);
        order.push_back(node->val);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 1557890
- total submissions: 2179990
- acceptance rate: 71.5%
- likes: 8265
- dislikes: 378

<br>

### Similar Problems

- [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) (Medium)
- [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) (Easy)
- [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) (Easy)
- [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) (Medium)
- [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) (Medium)
- [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii) (Hard)
- [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst) (Medium)
- [Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list) (Medium)
- [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) (Easy)

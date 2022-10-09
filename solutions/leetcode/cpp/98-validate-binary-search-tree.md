# [98] Validate Binary Search Tree

**[tree, depth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```

**Input:** root = [2,1,3]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```

**Input:** root = [5,1,4,null,null,3,6]
**Output:** false
**Explanation:** The root node's value is 5 but its right child's value is 4.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `-231 <= Node.val <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

**Inorder Traversal**

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
    bool isValidBST (TreeNode* root) {
      std::vector <int> order;
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node->left != nullptr)
          self(self, node->left);
        order.push_back(node->val);
        if (node->right != nullptr)
          self(self, node->right);
      };
      
      dfs(dfs, root);
      
      for (int i = 0; i < (int)order.size() - 1; ++i)
        if (order[i] >= order[i + 1])
          return false;
      
      return true;
    }
};
```

**Checking max in left subtree less than current node value and min in right subtree greater than current node value**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool isValidBST (TreeNode* root) {
      bool valid = true;
      
      auto dfs = [&] (auto self, TreeNode* node) -> std::pair <int, int> {
        int min = node->val;
        int max = node->val;
        
        if (node->left != nullptr) {
          auto [x, y] = self(self, node->left);
          min = std::min(min, x);
          max = std::max(max, y); // not required?
          if (y >= node->val)
            valid &= false;
        }
        
        if (node->right != nullptr) {
          auto [x, y] = self(self, node->right);
          min = std::min(min, x); // not required?
          max = std::max(max, y);
          if (x <= node->val)
            valid &= false;
        }
        
        return {min, max};
      };
      
      dfs(dfs, root);
      
      return valid;
    }
};
```

<br>

### Statistics

- total accepted: 1578927
- total submissions: 5052421
- acceptance rate: 31.3%
- likes: 11648
- dislikes: 966

<br>

### Similar Problems

- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) (Easy)
- [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree) (Easy)

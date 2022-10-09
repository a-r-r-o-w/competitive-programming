# [145] Binary Tree Postorder Traversal

**[stack, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of abinary tree, return *the postorder traversal of its nodes' values*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)

```

**Input:** root = [1,null,2,3]
**Output:** [3,2,1]

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
* The number of the nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`


**Follow up:** Recursive solution is trivial, could you do it iteratively?

<br>

### Hints

None

<br>

### Solution

**Recursive**

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
    vector <int> postorderTraversal (TreeNode* root) {
      std::vector <int> order;
      order.reserve(100);
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node->left != nullptr)
          self(self, node->left);
        if (node->right != nullptr)
          self(self, node->right);
        order.push_back(node->val);
      };
      
      if (root != nullptr)
        dfs(dfs, root);
      
      return order;
    }
};
```

**Iterative**

```cpp
class Solution {
  public:
    vector <int> postorderTraversal (TreeNode* root) {
      std::stack <std::pair <TreeNode*, bool>> s;
      std::vector <int> order;
      order.reserve(100);
      
      if (root != nullptr)
        s.push({root, false});
      
      while (!s.empty()) {
        auto &[node, visited] = s.top();
        
        if (visited) {
          order.push_back(node->val);
          s.pop();
        }
        else {
          if (node->right != nullptr)
            s.push({node->right, false});
          if (node->left != nullptr)
            s.push({node->left, false});
          visited = true;
        }
      }
      
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 777757
- total submissions: 1190026
- acceptance rate: 65.4%
- likes: 4603
- dislikes: 148

<br>

### Similar Problems

- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) (Easy)
- [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal) (Easy)

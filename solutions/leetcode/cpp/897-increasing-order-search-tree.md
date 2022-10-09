# [897] Increasing Order Search Tree

**[stack, tree, depth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a binary search tree, rearrange the tree in **in-order** so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg)

```

**Input:** root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
**Output:** [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg)

```

**Input:** root = [5,1,7]
**Output:** [1,null,5,null,7]

```

**Constraints:**
* The number of nodes in the given tree will be in the range `[1, 100]`.
* `0 <= Node.val <= 1000`


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
    TreeNode* increasingBST (TreeNode* root) {
      std::vector <TreeNode*> order;
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node == nullptr)
          return;
        
        self(self, node->left);
        std::cout << node->val << ' ';
        order.push_back(node);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      for (int i = 0; i < (int)order.size(); ++i) {
        if (i < (int)order.size() - 1)
          order[i]->right = order[i + 1];
        order[i]->left = nullptr;
      }
      
      return order[0];
    }
};
```

<br>

### Statistics

- total accepted: 221946
- total submissions: 283328
- acceptance rate: 78.3%
- likes: 3386
- dislikes: 633

<br>

### Similar Problems

None

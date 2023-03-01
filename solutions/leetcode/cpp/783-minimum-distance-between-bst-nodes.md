# [783] Minimum Distance Between BST Nodes

**[tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a Binary Search Tree (BST), return *the minimum difference between the values of any two different nodes in the tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```

**Input:** root = [4,2,6,1,3]
**Output:** 1

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```

**Input:** root = [1,0,48,null,null,12,49]
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 100]`.
* `0 <= Node.val <= 10^5`


**Note:** This question is the same as 530: <https://leetcode.com/problems/minimum-absolute-difference-in-bst/>

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
    int minDiffInBST (TreeNode *root) {
      std::vector <int> values;

      auto dfs = [&] (auto self, TreeNode *node) -> void {
        if (node == nullptr)
          return;
        self(self, node->left);
        values.push_back(node->val);
        self(self, node->right);
      };

      dfs(dfs, root);

      int n = values.size(), min = 1 << 30;
      for (int i = 0; i < n - 1; ++i)
        min = std::min(min, std::abs(values[i] - values[i + 1]));
      
      return min;
    }
};
```

<br />

### Statistics

- total accepted: 155079
- total submissions: 269915
- acceptance rate: 57.5%
- likes: 2192
- dislikes: 353

<br />

### Similar Problems

- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) (Easy)

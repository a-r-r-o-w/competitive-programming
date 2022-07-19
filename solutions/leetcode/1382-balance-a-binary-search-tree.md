# [1382] Balance a Binary Search Tree

**[divide-and-conquer, greedy, tree, depth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a binary search tree, return *a **balanced** binary search tree with the same node values*. If there is more than one answer, return **any of them**.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than `1`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg)

```

**Input:** root = [1,null,2,null,3,null,4,null,null]
**Output:** [2,1,3,null,null,null,4]
**Explanation:** This is not the only correct answer, [3,1,4,null,2] is also correct.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg)

```

**Input:** root = [2,1,3]
**Output:** [2,1,3]

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `1 <= Node.val <= 105`


<br>

### Hints

- Convert the tree to a sorted array using an in-order traversal.
- Construct a new balanced tree from the sorted array recursively.

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
    TreeNode* balanceBST (TreeNode* root) {
      std::vector <TreeNode*> order;
      
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node == nullptr)
          return;
        
        self(self, node->left);
        order.push_back(node);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      int n = order.size();
      
      auto build = [&] (auto self, int l, int r) -> TreeNode* {
        if (l > r)
          return nullptr;
        
        if (l == r) {
          order[l]->left = nullptr;
          order[l]->right = nullptr;
          return order[l];
        }
        
        int m = (l + r) / 2;
        order[m]->left = self(self, l, m - 1);
        order[m]->right = self(self, m + 1, r);
        
        return order[m];
      };
      
      return build(build, 0, n - 1);
    }
};
```

<br>

### Statistics

- total accepted: 99042
- total submissions: 123242
- acceptance rate: 80.4%
- likes: 2011
- dislikes: 57

<br>

### Similar Problems

None

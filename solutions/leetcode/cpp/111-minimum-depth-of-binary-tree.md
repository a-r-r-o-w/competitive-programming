# [111] Minimum Depth of Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:**A leaf is a node with no children.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** 2

```

**Example 2:**

```

**Input:** root = [2,null,3,null,4,null,5,null,6]
**Output:** 5

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 10^5]`.
* `-1000 <= Node.val <= 1000`


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
    int minDepth (TreeNode *root) {
      int ans = 1 << 30;

      auto dfs = [&] (auto self, TreeNode *node, int depth) -> void {
        if (node->left == nullptr and node->right == nullptr) {
          ans = std::min(ans, depth);
          return;
        }
        if (node->left != nullptr)
          self(self, node->left, depth + 1);
        if (node->right != nullptr)
          self(self, node->right, depth + 1);
      };

      if (root != nullptr)
        dfs(dfs, root, 1);
      if (ans == (1 << 30))
        ans = 0;
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 1004825
- total submissions: 2196307
- acceptance rate: 45.8%
- likes: 6449
- dislikes: 1186

<br />

### Similar Problems

- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) (Medium)
- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) (Easy)

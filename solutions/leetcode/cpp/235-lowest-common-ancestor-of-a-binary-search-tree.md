# [235] Lowest Common Ancestor of a Binary Search Tree

**[tree, depth-first-search, binary-search-tree, binary-tree]**

### Statement

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```

**Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
**Output:** 6
**Explanation:** The LCA of nodes 2 and 8 is 6.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```

**Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
**Output:** 2
**Explanation:** The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

```

**Example 3:**

```

**Input:** root = [2,1], p = 2, q = 1
**Output:** 2

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 105]`.
* `-109 <= Node.val <= 109`
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the BST.


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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
      auto dfs = [&] (auto self, TreeNode* node) -> TreeNode* {
        if (node->val > p->val and node->val > q->val)
          return self(self, node->left);
        if (node->val < p->val and node->val < q->val)
          return self(self, node->right);
        return node;
      };
      
      return dfs(dfs, root);
    }
};
```

<br>

### Statistics

- total accepted: 903326
- total submissions: 1532495
- acceptance rate: 58.9%
- likes: 7143
- dislikes: 217

<br>

### Similar Problems

- [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) (Medium)
- [Smallest Common Region](https://leetcode.com/problems/smallest-common-region) (Medium)
- [Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii) (Medium)
- [Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii) (Medium)
- [Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv) (Medium)

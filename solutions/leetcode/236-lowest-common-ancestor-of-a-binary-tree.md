# [236] Lowest Common Ancestor of a Binary Tree

**[tree, depth-first-search, binary-tree]**

### Statement

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```

**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
**Output:** 3
**Explanation:** The LCA of nodes 5 and 1 is 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```

**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
**Output:** 5
**Explanation:** The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

```

**Example 3:**

```

**Input:** root = [1,2], p = 1, q = 2
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 105]`.
* `-109 <= Node.val <= 109`
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the tree.


<br>

### Hints

None

<br>

### Solution

Using parent and depth

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

struct Node {
  TreeNode* node;
  int parent;
  int depth;
};

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
      std::unordered_map <int, Node> map;
      
      auto dfs = [&] (auto self, TreeNode* node, int p, int d) -> void {
        map[node->val] = {node, p, d};
        
        if (node->left != nullptr)
          self(self, node->left, node->val, d + 1);
        if (node->right != nullptr)
          self(self, node->right, node->val, d + 1);
      };
      
      dfs(dfs, root, -1, 0);
      
      int x = p->val, y = q->val;
      
      if (map[x].depth < map[y].depth)
        while (map[x].depth != map[y].depth)
          y = map[y].parent;
      else
        while (map[x].depth != map[y].depth)
          x = map[x].parent;
      
      while (x != y) {
        x = map[x].parent;
        y = map[y].parent;
      }
      
      return map[x].node;
    }
};
```

Recursively checking subtrees if node p and q exist

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == nullptr or root == p or root == q)
        return root;
      
      TreeNode* l = lowestCommonAncestor(root->left, p, q);
      TreeNode* r = lowestCommonAncestor(root->right, p, q);
      
      if (l != nullptr and r != nullptr)
        return root;
      else if (l != nullptr)
        return l;
      else if (r != nullptr)
        return r;
      else
        return nullptr;
    }
};
```

<br>

### Statistics

- total accepted: 1076769
- total submissions: 1904775
- acceptance rate: 56.5%
- likes: 10992
- dislikes: 289

<br>

### Similar Problems

- [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) (Easy)
- [Smallest Common Region](https://leetcode.com/problems/smallest-common-region) (Medium)
- [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) (Medium)
- [Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii) (Medium)
- [Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii) (Medium)
- [Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv) (Medium)
- [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another) (Medium)

# [543] Diameter of Binary Tree

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the length of the **diameter** of the tree*.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```

**Input:** root = [1,2,3,4,5]
**Output:** 3
**Explanation:** 3 is the length of the path [4,2,1,3] or [5,2,1,3].

```

**Example 2:**

```

**Input:** root = [1,2]
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `-100 <= Node.val <= 100`


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
    int diameterOfBinaryTree (TreeNode* root) {
      int max = 0;
      
      auto dfs = [&] (auto self, TreeNode* node) -> int {
        if (node == nullptr)
          return 0;
        int l = self(self, node->left);
        int r = self(self, node->right);
        max = std::max(max, l + r + 1);
        return std::max(l, r) + 1;
      };
      
      dfs(dfs, root);
      
      return max - 1;
    }
};
```

<br>

### Statistics

- total accepted: 790690
- total submissions: 1438944
- acceptance rate: 54.9%
- likes: 8525
- dislikes: 526

<br>

### Similar Problems

- [Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree) (Medium)
- [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) (Hard)

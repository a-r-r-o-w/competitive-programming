# [226] Invert Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, invert the tree, and return *its root*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

```

**Input:** root = [4,2,7,1,3,6,9]
**Output:** [4,7,2,9,6,3,1]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

```

**Input:** root = [2,1,3]
**Output:** [2,3,1]

```

**Example 3:**

```

**Input:** root = []
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 100]`.
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
    TreeNode* invertTree (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node) -> void {
        if (node == nullptr)
          return;
        std::swap(node->left, node->right);
        self(self, node->left);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      return root;
    }
};
```

<br>

### Statistics

- total accepted: 1127622
- total submissions: 1559232
- acceptance rate: 72.3%
- likes: 9005
- dislikes: 124

<br>

### Similar Problems

None

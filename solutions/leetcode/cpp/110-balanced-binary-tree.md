# [110] Balanced Binary Tree

**[tree, depth-first-search, binary-tree]**

### Statement

Given a binary tree, determine if it is **height-balanced**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```

**Input:** root = [1,2,2,3,3,null,null,4,4]
**Output:** false

```

**Example 3:**

```

**Input:** root = []
**Output:** true

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 5000]`.
* `-10^4 <= Node.val <= 10^4`


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
    bool isBalanced (TreeNode *root) {
      bool is_balanced = true;

      auto dfs = [&] (auto self, TreeNode *node) -> int {
        if (node == nullptr)
          return 0;
        int l = self(self, node->left);
        int r = self(self, node->right);
        if (std::abs(l - r) > 1)
          is_balanced = false;
        return 1 + std::max(l, r);
      };

      dfs(dfs, root);

      return is_balanced;
    }
};
```

<br />

### Statistics

- total accepted: 1182787
- total submissions: 2368505
- acceptance rate: 49.9%
- likes: 9513
- dislikes: 537

<br />

### Similar Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) (Easy)

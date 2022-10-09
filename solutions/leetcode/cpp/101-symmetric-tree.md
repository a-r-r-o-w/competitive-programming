# [101] Symmetric Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

```

**Input:** root = [1,2,2,3,4,4,3]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

```

**Input:** root = [1,2,2,null,3,null,3]
**Output:** false

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `-100 <= Node.val <= 100`


**Follow up:** Could you solve it both recursively and iteratively?

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
    bool isSymmetric (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* l, TreeNode* r) -> bool {
        if (l == nullptr)
          return r == nullptr;
        if (r == nullptr)
          return l == nullptr;
        if (l->val != r->val)
          return false;
        
        bool r1 = self(self, l->left, r->right);
        bool r2 = self(self, l->right, r->left);
        
        return r1 and r2;
      };
      
      return dfs(dfs, root->left, root->right);
    }
};
```

<br>

### Statistics

- total accepted: 1301800
- total submissions: 2497694
- acceptance rate: 52.1%
- likes: 10045
- dislikes: 243

<br>

### Similar Problems

None

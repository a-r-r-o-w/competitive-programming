# [100] Same Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

```

**Input:** p = [1,2,3], q = [1,2,3]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

```

**Input:** p = [1,2], q = [1,null,2]
**Output:** false

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

```

**Input:** p = [1,2,1], q = [1,1,2]
**Output:** false

```

**Constraints:**
* The number of nodes in both trees is in the range `[0, 100]`.
* `-104 <= Node.val <= 104`


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
    bool isSameTree (TreeNode* p, TreeNode* q) {
      auto dfs = [&] (auto self, TreeNode* pnode, TreeNode* qnode) -> bool {
        if (pnode == nullptr)
          return qnode == nullptr;
        if (qnode == nullptr)
          return pnode == nullptr;
        if (pnode->val != qnode->val)
          return false;
        
        bool lchild = self(self, pnode->left, qnode->left);
        bool rchild = self(self, pnode->right, qnode->right);
        
        return lchild and rchild;
      };
      
      return dfs(dfs, p, q);
    }
};
```

<br>

### Statistics

- total accepted: 1116042
- total submissions: 1997971
- acceptance rate: 55.9%
- likes: 6272
- dislikes: 143

<br>

### Similar Problems

None

# [814] Binary Tree Pruning

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the same tree where every subtree (of the given tree) not containing a* `1` *has been removed*.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.


**Example 1:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```

**Input:** root = [1,null,0,0,1]
**Output:** [1,null,0,null,1]
**Explanation:** 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

```

**Example 2:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```

**Input:** root = [1,0,1,0,0,0,1]
**Output:** [1,null,1,null,1]

```

**Example 3:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

```

**Input:** root = [1,1,0,1,1,0,1,0]
**Output:** [1,1,0,1,1,null,1]

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 200]`.
* `Node.val` is either `0` or `1`.


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
    TreeNode* pruneTree (TreeNode *root) {
      TreeNode dummy (1, root, nullptr);
      
      auto dfs = [&] (auto self, TreeNode *node) -> bool {
        if (node == nullptr)
          return false;
        
        bool result = node->val == 1;
        bool lchild = self(self, node->left);
        bool rchild = self(self, node->right);
        
        if (not lchild)
          node->left = nullptr;
        if (not rchild)
          node->right = nullptr;
        
        return result | lchild | rchild;
      };
      
      dfs(dfs, &dummy);
      
      return dummy.left;
    }
};
```

<br>

### Statistics

- total accepted: 174732
- total submissions: 243682
- acceptance rate: 71.7%
- likes: 3146
- dislikes: 83

<br>

### Similar Problems

None

# [105] Construct Binary Tree from Preorder and Inorder Traversal

**[array, hash-table, divide-and-conquer, tree, binary-tree]**

### Statement

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```

**Input:** preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
**Output:** [3,9,20,null,null,15,7]

```

**Example 2:**

```

**Input:** preorder = [-1], inorder = [-1]
**Output:** [-1]

```

**Constraints:**
* `1 <= preorder.length <= 3000`
* `inorder.length == preorder.length`
* `-3000 <= preorder[i], inorder[i] <= 3000`
* `preorder` and `inorder` consist of **unique** values.
* Each value of `inorder` also appears in `preorder`.
* `preorder` is **guaranteed** to be the preorder traversal of the tree.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.


<br>

### Hints

None

<br>

### Solution

**O(N^2) solution**

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
    TreeNode* buildTree (vector <int>& preorder, vector <int>& inorder) {
      int n = preorder.size();
      int index = 0;
      
      auto dfs = [&] (auto self, int begin, int end) -> TreeNode* {
        if (begin > end)
          return nullptr;
        
        TreeNode* node = new TreeNode(preorder[index]);
        ++index;
        
        if (begin == end)
          return node;
        
        int location = -1;
        
        for (int i = begin; i <= end; ++i) {
          if (inorder[i] == node->val) {
            location = i;
            break;
          }
        }
        
        node->left = self(self, begin, location - 1);
        node->right = self(self, location + 1, end);
        
        return node;
      };
      
      return dfs(dfs, 0, n - 1);
    }
};
```

**O(n) solution**

```cpp
class Solution {
  public:
    TreeNode* buildTree (vector <int>& preorder, vector <int>& inorder) {
      int n = preorder.size();
      int index = 0;
      std::unordered_map <int, int> location;
      
      for (int i = 0; i < n; ++i)
        location[inorder[i]] = i;
      
      auto dfs = [&] (auto self, int begin, int end) -> TreeNode* {
        if (begin > end)
          return nullptr;
        
        TreeNode* node = new TreeNode(preorder[index]);
        ++index;
        
        if (begin == end)
          return node;
        
        node->left = self(self, begin, location[node->val] - 1);
        node->right = self(self, location[node->val] + 1, end);
        
        return node;
      };
      
      return dfs(dfs, 0, n - 1);
    }
};
```

<br>

### Statistics

- total accepted: 787642
- total submissions: 1325713
- acceptance rate: 59.4%
- likes: 9937
- dislikes: 267

<br>

### Similar Problems

- [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) (Medium)

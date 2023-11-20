# [106] Construct Binary Tree from Inorder and Postorder Traversal

**[array, hash-table, divide-and-conquer, tree, binary-tree]**

### Statement

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```

**Input:** inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
**Output:** [3,9,20,null,null,15,7]

```

**Example 2:**

```

**Input:** inorder = [-1], postorder = [-1]
**Output:** [-1]

```

**Constraints:**
* `1 <= inorder.length <= 3000`
* `postorder.length == inorder.length`
* `-3000 <= inorder[i], postorder[i] <= 3000`
* `inorder` and `postorder` consist of **unique** values.
* Each value of `postorder` also appears in `inorder`.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.
* `postorder` is **guaranteed** to be the postorder traversal of the tree.


<br />

### Hints

None

<br />

### Solution

O(N^2)

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
    TreeNode* buildTree (vector <int>& inorder, vector <int>& postorder) {
      int n = inorder.size(), index = n - 1;

      auto dfs = [&] (auto self, int l, int r) -> TreeNode* {
        if (r < l)
          return nullptr;
        
        TreeNode* current = nullptr;
        
        for (int i = l; i <= r; ++i) {
          if (inorder[i] == postorder[index]) {
            current = new TreeNode(inorder[i]);
            --index;
            current->right = self(self, i + 1, r);
            current->left = self(self, l, i - 1);
            break;
          }
        }

        return current;
      };

      return dfs(dfs, 0, n - 1);
    }
};
```

O(N)

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
    TreeNode* buildTree (vector <int>& inorder, vector <int>& postorder) {
      int n = inorder.size(), index = n - 1;
      std::map <int, int> location;

      for (int i = 0; i < n; ++i)
        location[inorder[i]] = i;

      auto dfs = [&] (auto self, int l, int r) -> TreeNode* {
        if (r < l)
          return nullptr;
        
        int position = location[postorder[index]];
        TreeNode* current = new TreeNode(postorder[index--]);
        current->right = self(self, position + 1, r);
        current->left = self(self, l, position - 1);

        return current;
      };

      return dfs(dfs, 0, n - 1);
    }
};
```

<br />

### Statistics

- total accepted: 482304
- total submissions: 820649
- acceptance rate: 58.8%
- likes: 6218
- dislikes: 90

<br />

### Similar Problems

- [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) (Medium)

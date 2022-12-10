# [872] Leaf-Similar Trees

**[tree, depth-first-search, binary-tree]**

### Statement

Consider all the leaves of a binary tree, fromleft to right order, the values of thoseleaves form a **leaf value sequence***.*
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png)

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered *leaf-similar*if their leaf value sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg)

```

**Input:** root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg)

```

**Input:** root1 = [1,2,3], root2 = [1,3,2]
**Output:** false

```

**Constraints:**
* The number of nodes in each tree will be in the range `[1, 200]`.
* Both of the given trees will have values in the range `[0, 200]`.


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
    bool leafSimilar (TreeNode* root1, TreeNode* root2) {
      std::vector <int> leaf1, leaf2;

      auto dfs = [&] (auto self, TreeNode *node, std::vector <int> &l) -> void {
        if (node->left == nullptr and node->right == nullptr) {
          l.push_back(node->val);
          return;
        }
        if (node->left != nullptr)
          self(self, node->left, l);
        if (node->right != nullptr)
          self(self, node->right, l);
      };

      dfs(dfs, root1, leaf1);
      dfs(dfs, root2, leaf2);

      return leaf1 == leaf2;
    }
};
```

<br>

### Statistics

- total accepted: 186806
- total submissions: 286201
- acceptance rate: 65.3%
- likes: 2006
- dislikes: 59

<br>

### Similar Problems

None

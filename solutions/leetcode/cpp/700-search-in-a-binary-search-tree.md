# [700] Search in a Binary Search Tree

**[tree, binary-search-tree, binary-tree]**

### Statement

You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```

**Input:** root = [4,2,7,1,3], val = 2
**Output:** [2,1,3]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```

**Input:** root = [4,2,7,1,3], val = 5
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 5000]`.
* `1 <= Node.val <= 107`
* `root` is a binary search tree.
* `1 <= val <= 107`


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
    TreeNode* searchBST (TreeNode* root, int val) {
      while (root != nullptr) {
        if (root->val == val)
          return root;
        else if (root->val < val)
          root = root->right;
        else
          root = root->left;
      }
      
      return root;
    }
};
```

<br>

### Statistics

- total accepted: 550859
- total submissions: 715375
- acceptance rate: 77.0%
- likes: 3966
- dislikes: 156

<br>

### Similar Problems

- [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value) (Easy)
- [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree) (Medium)

# [968] Binary Tree Cameras

**[dynamic-programming, tree, depth-first-search, binary-tree]**

### Statement

You are given the `root` of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return *the minimum number of cameras needed to monitor all nodes of the tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png)

```

**Input:** root = [0,0,null,0,0]
**Output:** 1
**Explanation:** One camera is enough to monitor all nodes if placed as shown.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png)

```

**Input:** root = [0,0,null,0,null,0,null,null,0]
**Output:** 2
**Explanation:** At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `Node.val == 0`


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
    int minCameraCover(TreeNode* root) {
      // 0: does not have a camera and is not watched
      // 1: does not have a camera and is watched
      // 2: has a camera
      int cameras = 0;
      
      auto dfs = [&] (auto self, TreeNode* node) -> int {
        if (node == nullptr)
          return 2;
        int l = self(self, node->left);
        int r = self(self, node->right);
        if (l == 0 or r == 0) {
          ++cameras;
          return 1;
        }
        if (l == 1 or r == 1)
          return 2;
        return 0;
      };
      
      int r = dfs(dfs, root);
      
      return !r + cameras;
    }
};
```

<br>

### Statistics

- total accepted: 97434
- total submissions: 210722
- acceptance rate: 46.2%
- likes: 3936
- dislikes: 49

<br>

### Similar Problems

- [Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree) (Medium)

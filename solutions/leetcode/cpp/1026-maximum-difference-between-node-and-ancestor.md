# [1026] Maximum Difference Between Node and Ancestor

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, find the maximum value `v` for which there exist **different** nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b`or any child of `a` is an ancestor of `b`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg)

```

**Input:** root = [8,3,10,1,6,null,14,null,null,4,7,13]
**Output:** 7
**Explanation:** We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg)

```

**Input:** root = [1,null,2,null,0,3]
**Output:** 3

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 5000]`.
* `0 <= Node.val <= 105`


<br>

### Hints

- For each subtree, find the minimum value and maximum value of its descendants.

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
    int maxAncestorDiff (TreeNode *root) {
      int ans = 0;
      
      auto dfs = [&] (auto self, TreeNode *node, int min, int max) {
        if (node == nullptr)
          return;
        ans = std::max({ans, std::abs(node->val - min), std::abs(node->val - max)});
        self(self, node->left, std::min(min, node->val), std::max(max, node->val));
        self(self, node->right, std::min(min, node->val), std::max(max, node->val));
      };

      dfs(dfs, root, root->val, root->val);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 160234
- total submissions: 215293
- acceptance rate: 74.4%
- likes: 3134
- dislikes: 78

<br>

### Similar Problems

None

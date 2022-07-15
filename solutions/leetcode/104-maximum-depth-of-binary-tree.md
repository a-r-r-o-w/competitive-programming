# [104] Maximum Depth of Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *its maximum depth*.

A binary tree's **maximum depth**is the number of nodes along the longest path from the root node down to the farthest leaf node.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** 3

```

**Example 2:**

```

**Input:** root = [1,null,2]
**Output:** 2

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 104]`.
* `-100 <= Node.val <= 100`


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
    int maxDepth (TreeNode* root) {
      if (root == nullptr)
        return 0;
      return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

<br>

### Statistics

- total accepted: 1792368
- total submissions: 2475468
- acceptance rate: 72.4%
- likes: 7647
- dislikes: 131

<br>

### Similar Problems

- [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree) (Easy)
- [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) (Easy)
- [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree) (Easy)
- [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees) (Medium)

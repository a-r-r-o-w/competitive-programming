# [112] Path Sum

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```

**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
**Output:** true
**Explanation:** The root-to-leaf path with the target sum is shown.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```

**Input:** root = [1,2,3], targetSum = 5
**Output:** false
**Explanation:** There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

```

**Example 3:**

```

**Input:** root = [], targetSum = 0
**Output:** false
**Explanation:** Since the tree is empty, there are no root-to-leaf paths.

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 5000]`.
* `-1000 <= Node.val <= 1000`
* `-1000 <= targetSum <= 1000`


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
    bool hasPathSum (TreeNode* root, int targetSum) {
      auto dfs = [&] (auto self, TreeNode* node, int sum) -> bool {
        if (node == nullptr)
          return false;
        else if (node->left == nullptr and node->right == nullptr)
          return sum + node->val == targetSum;
        else if (node->left == nullptr)
          return self(self, node->right, sum + node->val);
        else if (node->right == nullptr)
          return self(self, node->left, sum + node->val);
        else {
          bool lchild = self(self, node->left, sum + node->val);
          bool rchild = self(self, node->right, sum + node->val);
          return lchild or rchild;
        }
      };
      
      return dfs(dfs, root, 0);
    }
};
```

<br>

### Statistics

- total accepted: 924353
- total submissions: 2007199
- acceptance rate: 46.1%
- likes: 5911
- dislikes: 805

<br>

### Similar Problems

- [Path Sum II](https://leetcode.com/problems/path-sum-ii) (Medium)
- [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) (Hard)
- [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) (Medium)
- [Path Sum III](https://leetcode.com/problems/path-sum-iii) (Medium)
- [Path Sum IV](https://leetcode.com/problems/path-sum-iv) (Medium)

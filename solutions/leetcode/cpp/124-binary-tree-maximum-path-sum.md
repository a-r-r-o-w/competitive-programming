# [124] Binary Tree Maximum Path Sum

**[dynamic-programming, tree, depth-first-search, binary-tree]**

### Statement

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum **path sum** of any **non-empty** path*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg)

```

**Input:** root = [1,2,3]
**Output:** 6
**Explanation:** The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)

```

**Input:** root = [-10,9,20,null,null,15,7]
**Output:** 42
**Explanation:** The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 3 * 104]`.
* `-1000 <= Node.val <= 1000`


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
    int maxPathSum (TreeNode *root) {
      const int inf32 = 1 << 30;
      int max = -inf32;

      auto max_path = [&] (auto self, TreeNode *node) -> int {
        if (node == nullptr)
          return 0;
        int l = std::max(0, self(self, node->left));
        int r = std::max(0, self(self, node->right));
        max = std::max({max, l + r + node->val});
        return node->val + std::max(l, r);
      };

      max_path(max_path, root);
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 876446
- total submissions: 2275154
- acceptance rate: 38.5%
- likes: 12350
- dislikes: 604

<br>

### Similar Problems

- [Path Sum](https://leetcode.com/problems/path-sum) (Easy)
- [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) (Medium)
- [Path Sum IV](https://leetcode.com/problems/path-sum-iv) (Medium)
- [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path) (Medium)
- [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees) (Medium)

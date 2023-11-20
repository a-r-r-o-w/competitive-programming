# [1372] Longest ZigZag Path in a Binary Tree

**[dynamic-programming, tree, depth-first-search, binary-tree]**

### Statement

You are given the `root` of a binary tree.

A ZigZag path for a binary tree is defined as follow:

* Choose **any** node in the binary tree and a direction (right or left).
* If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
* Change the direction from right to left or from left to right.
* Repeat the second and third steps until you can't move in the tree.



Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return *the longest **ZigZag** path contained in that tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png)

```

**Input:** root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
**Output:** 3
**Explanation:** Longest ZigZag path in blue nodes (right -> left -> right).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/01/22/sample_2_1702.png)

```

**Input:** root = [1,1,1,null,1,null,null,1,1,null,1]
**Output:** 4
**Explanation:** Longest ZigZag path in blue nodes (left -> right -> left -> right).

```

**Example 3:**

```

**Input:** root = [1]
**Output:** 0

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 5 * 10^4]`.
* `1 <= Node.val <= 100`


<br />

### Hints

- Create this function maxZigZag(node, direction) maximum zigzag given a node and direction (right or left).

<br />

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
    int longestZigZag (TreeNode* root) {
      int ans = 0;

      auto dfs = [&] (auto self, TreeNode *node, int direction, int steps) -> void {
        if (node == nullptr)
          return;
        ans = std::max(ans, steps);
        if (direction == -1) {
          self(self, node->left, +1, steps + 1);
          self(self, node->right, -1, 1);
        }
        else {
          self(self, node->left, +1, 1);
          self(self, node->right, -1, steps + 1);
        }
      };

      dfs(dfs, root, -1, 0);
      dfs(dfs, root, +1, 0);
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 89778
- total submissions: 134461
- acceptance rate: 66.8%
- likes: 2597
- dislikes: 48

<br />

### Similar Problems

None

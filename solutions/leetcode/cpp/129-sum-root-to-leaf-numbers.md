# [129] Sum Root to Leaf Numbers

**[tree, depth-first-search, binary-tree]**

### Statement

You are given the `root` of a binary tree containing digits from `0` to `9` only.

Each root-to-leaf path in the tree represents a number.

* For example, the root-to-leaf path `1 -> 2 -> 3` represents the number `123`.



Return *the total sum of all root-to-leaf numbers*. Test cases are generated so that the answer will fit in a **32-bit** integer.

A **leaf** node is a node with no children.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg)

```

**Input:** root = [1,2,3]
**Output:** 25
**Explanation:**
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg)

```

**Input:** root = [4,9,0,5,1]
**Output:** 1026
**Explanation:**
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `0 <= Node.val <= 9`
* The depth of the tree will not exceed `10`.


<br />

### Hints

None

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
    int sumNumbers  (TreeNode* root) {
      int sum = 0;

      auto dfs = [&] (auto self, TreeNode *node, int s) -> void {
        bool any = false;
        if (node->left != nullptr)
          self(self, node->left, s * 10 + node->val), any = true;
        if (node->right != nullptr)
          self(self, node->right, s * 10 + node->val), any = true;
        if (not any)
          sum += s * 10 + node->val;
      };

      dfs(dfs, root, 0);

      return sum;
    }
};
```

<br />

### Statistics

- total accepted: 535554
- total submissions: 903611
- acceptance rate: 59.3%
- likes: 5448
- dislikes: 96

<br />

### Similar Problems

- [Path Sum](https://leetcode.com/problems/path-sum) (Easy)
- [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) (Hard)
- [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf) (Medium)

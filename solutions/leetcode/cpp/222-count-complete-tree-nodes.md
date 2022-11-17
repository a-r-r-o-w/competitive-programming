# [222] Count Complete Tree Nodes

**[binary-search, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than`O(n)`time complexity.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

```

**Input:** root = [1,2,3,4,5,6]
**Output:** 6

```

**Example 2:**

```

**Input:** root = []
**Output:** 0

```

**Example 3:**

```

**Input:** root = [1]
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 5 * 104]`.
* `0 <= Node.val <= 5 * 104`
* The tree is guaranteed to be **complete**.


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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countNodes (TreeNode* root) {
      if (root == nullptr)
        return 0;
      
      TreeNode *left = root, *right = root;
      int h = 0;
      
      while (right != nullptr) {
        left = left->left;
        right = right->right;
        ++h;
      }
      
      if (left == nullptr)
        return (1 << h) - 1;
      
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

<br>

### Statistics

- total accepted: 466794
- total submissions: 805676
- acceptance rate: 57.9%
- likes: 6044
- dislikes: 344

<br>

### Similar Problems

- [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value) (Easy)

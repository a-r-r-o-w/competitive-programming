# [958] Check Completeness of a Binary Tree

**[tree, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, determine if it is a *complete binary tree*.

In a **[complete binary tree](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between `1` and `2^h` nodes inclusive at the last level `h`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)

```

**Input:** root = [1,2,3,4,5,6]
**Output:** true
**Explanation:** Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png)

```

**Input:** root = [1,2,3,4,5,null,7]
**Output:** false
**Explanation:** The node with value 7 isn't as far left as possible.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 100]`.
* `1 <= Node.val <= 1000`


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
    bool isCompleteTree (TreeNode* root) {
      std::vector <TreeNode*> q;
      int index = 0;
      q.push_back(root);

      while (index < (int)q.size() and q[index] != nullptr) {
        q.push_back(q[index]->left);
        q.push_back(q[index]->right);
        ++index;
      }

      while (index < (int)q.size()) {
        if (q[index] != nullptr)
          break;
        ++index;
      }

      return index == (int)q.size();
    }
};
```

<br />

### Statistics

- total accepted: 156202
- total submissions: 284851
- acceptance rate: 54.8%
- likes: 3031
- dislikes: 39

<br />

### Similar Problems

None

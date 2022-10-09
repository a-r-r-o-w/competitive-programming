# [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given two binary trees `original` and `cloned` and given a reference to a node `target` in the original tree.

The `cloned` tree is a **copy of** the `original` tree.

Return *a reference to the same node* in the `cloned` tree.

**Note** that you are **not allowed** to change any of the two trees or the `target` node and the answer **must be** a reference to a node in the `cloned` tree.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/02/21/e1.png)

```

**Input:** tree = [7,4,3,null,null,6,19], target = 3
**Output:** 3
**Explanation:** In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/02/21/e2.png)

```

**Input:** tree = [7], target =  7
**Output:** 7

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/02/21/e3.png)

```

**Input:** tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
**Output:** 4

```

**Constraints:**
* The number of nodes in the `tree` is in the range `[1, 104]`.
* The values of the nodes of the `tree` are unique.
* `target` node is a node from the `original` tree and is not `null`.


**Follow up:** Could you solve the problem if repeated values on the tree are allowed?

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      auto dfs = [&] (auto self, TreeNode* original_node, TreeNode* cloned_node) -> TreeNode* {
        if (original_node == nullptr)
          return nullptr;
        if (original_node == target)
          return cloned_node;
        auto l = self(self, original_node->left, cloned_node->left);
        auto r = self(self, original_node->right, cloned_node->right);
        if (l != nullptr)
          return l;
        if (r != nullptr)
          return r;
        return nullptr;
      };
      
      return dfs(dfs, original, cloned);
    }
};
```

<br>

### Statistics

- total accepted: 156948
- total submissions: 179845
- acceptance rate: 87.3%
- likes: 1234
- dislikes: 1550

<br>

### Similar Problems

None

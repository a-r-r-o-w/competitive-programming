# [1315] Sum of Nodes with Even-Valued Grandparent

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the sum of values of nodes with an **even-valued grandparent***. If there are no nodes with an **even-valued grandparent**, return `0`.

A **grandparent** of a node is the parent of its parent if it exists.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/10/even1-tree.jpg)

```

**Input:** root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
**Output:** 18
**Explanation:** The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/08/10/even2-tree.jpg)

```

**Input:** root = [1]
**Output:** 0

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `1 <= Node.val <= 100`


<br>

### Hints

- Traverse the tree keeping the parent and the grandparent.
- If the grandparent of the current node is even-valued, add the value of this node to the answer.

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
    int sumEvenGrandparent (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node, int parent, int grandparent) -> int {
        if (node == nullptr)
          return 0;
        
        int lchild = self(self, node->left, node->val, parent);
        int rchild = self(self, node->right, node->val, parent);
        int value = 0;
        
        if (grandparent % 2 == 0)
          value = node->val;
        
        return lchild + rchild + value;
      };
      
      return dfs(dfs, root, 1, 1);
    }
};
```

<br>

### Statistics

- total accepted: 107053
- total submissions: 125341
- acceptance rate: 85.4%
- likes: 1893
- dislikes: 60

<br>

### Similar Problems

None

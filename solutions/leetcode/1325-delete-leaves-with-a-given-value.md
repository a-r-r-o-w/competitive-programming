# [1325] Delete Leaves With a Given Value

**[tree, depth-first-search, binary-tree]**

### Statement

Given a binary tree `root` and an integer `target`, delete all the **leaf nodes** with value `target`.

Note that once you delete a leaf node with value `target`**,** if its parent node becomes a leaf node and has the value `target`, it should also be deleted (you need to continue doing that until you cannot).


**Example 1:**
**![](https://assets.leetcode.com/uploads/2020/01/09/sample_1_1684.png)**

```

**Input:** root = [1,2,3,2,null,2,4], target = 2
**Output:** [1,null,3,null,4]
**Explanation:** Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2020/01/09/sample_2_1684.png)**

```

**Input:** root = [1,3,3,3,2], target = 3
**Output:** [1,3,null,null,2]

```

**Example 3:**
**![](https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png)**

```

**Input:** root = [1,2,null,2,null,2], target = 2
**Output:** [1]
**Explanation:** Leaf nodes in green with value (target = 2) are removed at each step.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 3000]`.
* `1 <= Node.val, target <= 1000`


<br>

### Hints

- Use the DFS to reconstruct the tree such that no leaf node is equal to the target. If the leaf node is equal to the target, return an empty object instead.

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
  
    TreeNode* removeLeafNodes (TreeNode* root, int target) {
      if (root == nullptr)
        return nullptr;
      
      auto l = removeLeafNodes(root->left, target);
      auto r = removeLeafNodes(root->right, target);
      
      if (l == nullptr)
        root->left = nullptr;
      if (r == nullptr)
        root->right = nullptr;
      
      if (root->left == nullptr and root->right == nullptr and root->val == target)
        return nullptr;
      
      return root;
    }
};
```

<br>

### Statistics

- total accepted: 73101
- total submissions: 97760
- acceptance rate: 74.8%
- likes: 1577
- dislikes: 29

<br>

### Similar Problems

None

# [102] Binary Tree Level Order Traversal

**[tree, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** [[3],[9,20],[15,7]]

```

**Example 2:**

```

**Input:** root = [1]
**Output:** [[1]]

```

**Example 3:**

```

**Input:** root = []
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 2000]`.
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
    vector <vector <int>> levelOrder (TreeNode* root) {
      std::queue <TreeNode*> q;
      std::vector <std::vector <int>> levels;
      
      if (root != nullptr)
        q.push(root);
      
      while (!q.empty()) {
        levels.push_back({});
        
        int n = q.size();
        for (int i = 0; i < n; ++i) {
          auto top = q.front();
          q.pop();
          levels.back().push_back(top->val);
          
          if (top->left != nullptr)
            q.push(top->left);
          if (top->right != nullptr)
            q.push(top->right);
        }
      }
      
      return levels;
    }
};
```

<br>

### Statistics

- total accepted: 1362609
- total submissions: 2196746
- acceptance rate: 62.0%
- likes: 9384
- dislikes: 184

<br>

### Similar Problems

- [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal) (Medium)
- [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) (Medium)
- [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) (Easy)
- [Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal) (Medium)
- [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree) (Easy)
- [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) (Medium)
- [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree) (Easy)

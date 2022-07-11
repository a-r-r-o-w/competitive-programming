# [199] Binary Tree Right Side View

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```

**Input:** root = [1,2,3,null,5,null,4]
**Output:** [1,3,4]

```

**Example 2:**

```

**Input:** root = [1,null,3]
**Output:** [1,3]

```

**Example 3:**

```

**Input:** root = []
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`


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
    vector <int> rightSideView (TreeNode* root) {
      std::map <int, int> depth;
      
      auto dfs = [&] (auto self, TreeNode* node, int d) -> void {
        if (node == nullptr)
          return;
        depth[d] = node->val;
        self(self, node->left, d + 1);
        self(self, node->right, d + 1);
      };
      
      dfs(dfs, root, 0);
      
      std::vector <int> view;
      for (auto& [p, q]: depth)
        view.push_back(q);
      
      return view;
    }
};
```

**Memory optimised**

```cpp
class Solution {
  public:
    vector <int> rightSideView (TreeNode* root) {
      std::vector <int> view;
      
      auto dfs = [&] (auto self, TreeNode* node, int d) -> void {
        if (node == nullptr)
          return;
        if (d == (int)view.size())
          view.push_back(node->val);
        self(self, node->right, d + 1);
        self(self, node->left, d + 1);
      };
      
      dfs(dfs, root, 0);
      
      return view;
    }
};
```

<br>

### Statistics

- total accepted: 741964
- total submissions: 1228546
- acceptance rate: 60.4%
- likes: 7431
- dislikes: 411

<br>

### Similar Problems

- [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) (Medium)
- [Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree) (Medium)

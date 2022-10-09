# [1302] Deepest Leaves Sum

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the sum of values of its deepest leaves*.

**Example 1:**
![](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```

**Input:** root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
**Output:** 15

```

**Example 2:**

```

**Input:** root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
**Output:** 19

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `1 <= Node.val <= 100`


<br>

### Hints

- Traverse the tree to find the max depth.
- Traverse the tree again to compute the sum required.

<br>

### Solution

**DFS**

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
    int deepestLeavesSum (TreeNode* root) {
      std::map <int, std::vector <int>> depth;
      
      auto dfs = [&] (auto self, TreeNode* node, int d) -> void {
        if (node == nullptr)
          return;
        depth[d].push_back(node->val);
        self(self, node->left, d + 1);
        self(self, node->right, d + 1);
      };
      
      dfs(dfs, root, 0);
      
      int sum = 0;
      for (int i: depth.rbegin()->second)
        sum += i;
      
      return sum;
    }
};
```

**BFS**

```cpp
class Solution {
  public:
    int deepestLeavesSum (TreeNode* root) {
      std::queue <TreeNode*> q;
      int sum = 0;
      
      if (root != nullptr)
        q.push(root);
      
      while (!q.empty()) {
        int n = q.size();
        sum = 0;
        
        for (int i = 0; i < n; ++i) {
          auto x = q.front();
          q.pop();
          
          sum += x->val;
          if (x->left != nullptr)
            q.push(x->left);
          if (x->right != nullptr)
            q.push(x->right);
        }
      }
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 226456
- total submissions: 260120
- acceptance rate: 87.1%
- likes: 3377
- dislikes: 94

<br>

### Similar Problems

None

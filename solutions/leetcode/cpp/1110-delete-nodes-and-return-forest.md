# [1110] Delete Nodes And Return Forest

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in `to_delete`, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png)

```

**Input:** root = [1,2,3,4,5,6,7], to_delete = [3,5]
**Output:** [[1,2,null,4],[6],[7]]

```

**Example 2:**

```

**Input:** root = [1,2,4,null,3], to_delete = [3]
**Output:** [[1,2,4]]

```

**Constraints:**
* The number of nodes in the given tree is at most `1000`.
* Each node has a distinct value between `1` and `1000`.
* `to_delete.length <= 1000`
* `to_delete` contains distinct values between `1` and `1000`.


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
    vector <TreeNode*> delNodes (TreeNode *root, vector <int>& to_delete) {
      std::unordered_set <int> remove (to_delete.begin(), to_delete.end());
      std::vector <TreeNode*> ans;

      auto dfs = [&] (auto self, TreeNode *node, TreeNode **parent_child, bool delete_parent) -> void {
        if (node == nullptr)
          return;
        if (remove.count(node->val)) {
          self(self, node->left, nullptr, true);
          self(self, node->right, nullptr, true);
          delete node;
          if (parent_child != nullptr)
            *parent_child = nullptr;
        }
        else {
          if (delete_parent)
            ans.push_back(node);
          self(self, node->left, &node->left, false);
          self(self, node->right, &node->right, false);
        }
      };

      dfs(dfs, root, nullptr, true);

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 177494
- total submissions: 256072
- acceptance rate: 69.3%
- likes: 3275
- dislikes: 100

<br />

### Similar Problems

- [Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score) (Medium)

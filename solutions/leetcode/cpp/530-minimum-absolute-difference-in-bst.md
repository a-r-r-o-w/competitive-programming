# [530] Minimum Absolute Difference in BST

**[tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a Binary Search Tree (BST), return *the minimum absolute difference between the values of any two different nodes in the tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```

**Input:** root = [4,2,6,1,3]
**Output:** 1

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

```

**Input:** root = [1,0,48,null,null,12,49]
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 10^4]`.
* `0 <= Node.val <= 10^5`


**Note:** This question is the same as 783: <https://leetcode.com/problems/minimum-distance-between-bst-nodes/>

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
    int getMinimumDifference (TreeNode* root) {
      std::vector <int> values;

      auto dfs = [&] (auto self, TreeNode *node) -> void {
        if (node == nullptr)
          return;
        self(self, node->left);
        values.push_back(node->val);
        self(self, node->right);
      };

      dfs(dfs, root);

      int n = values.size(), ans = 1 << 30;
      for (int i = 0; i < n - 1; ++i)
        ans = std::min(ans, values[i + 1] - values[i]);
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 262185
- total submissions: 445989
- acceptance rate: 58.8%
- likes: 3619
- dislikes: 175

<br />

### Similar Problems

- [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array) (Medium)

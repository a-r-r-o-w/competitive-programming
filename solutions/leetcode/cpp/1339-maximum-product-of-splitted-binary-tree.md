# [1339] Maximum Product of Splitted Binary Tree

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return *the maximum product of the sums of the two subtrees*. Since the answer may be too large, return it **modulo** `109 + 7`.

**Note** that you need to maximize the answer before taking the mod and not after taking it.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png)

```

**Input:** root = [1,2,3,4,5,6]
**Output:** 110
**Explanation:** Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/01/21/sample_2_1699.png)

```

**Input:** root = [1,null,2,3,4,null,null,5,6]
**Output:** 90
**Explanation:** Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 5 * 104]`.
* `1 <= Node.val <= 104`


<br>

### Hints

- If we know the sum of a subtree, the answer is max( (total_sum - subtree_sum) * subtree_sum) in each node.

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
    int maxProduct (TreeNode *root) {
      std::unordered_map <TreeNode*, int64_t> sum;
      int64_t ans = 0;

      sum[nullptr] = 0;

      auto dfs = [&] (auto self, TreeNode *node) -> int {
        if (node == nullptr)
          return 0;
        int l = self(self, node->left);
        int r = self(self, node->right);
        int s = l + r + node->val;
        sum[node] = s;
        return s;
      };

      dfs(dfs, root);
      int64_t root_sum = sum[root];

      auto find = [&] (auto self, TreeNode *node) {
        if (node == nullptr)
          return;
        ans = std::max(ans, sum[node] * (root_sum - sum[node]));
        self(self, node->left);
        self(self, node->right);
      };

      find(find, root);

      return ans % 1000000007;
    }
};
```

<br>

### Statistics

- total accepted: 81339
- total submissions: 178669
- acceptance rate: 45.5%
- likes: 2064
- dislikes: 78

<br>

### Similar Problems

- [Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score) (Medium)

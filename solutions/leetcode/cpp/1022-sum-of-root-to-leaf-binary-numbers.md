# [1022] Sum of Root To Leaf Binary Numbers

**[tree, depth-first-search, binary-tree]**

### Statement

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

* For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.



For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return *the sum of these numbers*.

The test cases are generated so that the answer fits in a **32-bits** integer.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)

```

**Input:** root = [1,0,1,0,1,0,1]
**Output:** 22
**Explanation:** (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

```

**Example 2:**

```

**Input:** root = [0]
**Output:** 0

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `Node.val` is `0` or `1`.


<br>

### Hints

- Find each path, then transform that path to an integer in base 10.

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
  
    int sumRootToLeaf (TreeNode* root) {
      int ans = 0;
      
      auto dfs = [&] (auto self, TreeNode* node, int sum) -> void {
        int value = 2 * sum + node->val;
        
        if (node->left == nullptr and node->right == nullptr)
          ans += value;
        else if (node->left == nullptr)
          self(self, node->right, value);
        else if (node->right == nullptr)
          self(self, node->left, value);
        else {
          self(self, node->left, value);
          self(self, node->right, value);
        }
      };
      
      dfs(dfs, root, 0);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 169027
- total submissions: 228902
- acceptance rate: 73.8%
- likes: 2675
- dislikes: 156

<br>

### Similar Problems

None

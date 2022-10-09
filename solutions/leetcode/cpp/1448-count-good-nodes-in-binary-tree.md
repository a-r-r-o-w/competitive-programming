# [1448] Count Good Nodes in Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given a binary tree `root`, a node *X* in the tree is named**good** if in the path from root to *X* there are no nodes with a value *greater than* X.

Return the number of **good** nodes in the binary tree.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)**

```

**Input:** root = [3,1,4,3,null,1,5]
**Output:** 4
**Explanation:** Nodes in blue are **good**.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png)**

```

**Input:** root = [3,3,null,4,2]
**Output:** 3
**Explanation:** Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```

**Input:** root = [1]
**Output:** 1
**Explanation:** Root is considered as **good**.
```

**Constraints:**
* The number of nodes in the binary tree is in the range`[1, 10^5]`.
* Each node's value is between `[-10^4, 10^4]`.


<br>

### Hints

- Use DFS (Depth First Search) to traverse the tree, and constantly keep track of the current path maximum.

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
  
    int goodNodes (TreeNode* root) {
      const int inf32 = 1 << 30;
      int count = 0;
      
      auto dfs = [&] (auto self, TreeNode* node, int max) -> void {
        if (node->val >= max) {
          ++count;
          max = node->val;
        }
        
        if (node->left != nullptr)
          self(self, node->left, max);
        if (node->right != nullptr)
          self(self, node->right, max);
      };
      
      dfs(dfs, root, -inf32);
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 189766
- total submissions: 259942
- acceptance rate: 73.0%
- likes: 2719
- dislikes: 86

<br>

### Similar Problems

None

# [653] Two Sum IV - Input is a BST

**[hash-table, two-pointers, tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree]**

### Statement

Given the `root` of a Binary Search Tree and a target number `k`, return *`true` if there exist two elements in the BST such that their sum is equal to the given target*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg)

```

**Input:** root = [5,3,6,2,4,null,7], k = 9
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg)

```

**Input:** root = [5,3,6,2,4,null,7], k = 28
**Output:** false

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `-104<= Node.val <= 104`
* `root` is guaranteed to be a **valid** binary search tree.
* `-105<= k <= 105`


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
    bool findTarget (TreeNode* root, int k) {
      std::unordered_set <int> have;
      
      auto dfs = [&] (auto self, TreeNode *node) -> bool {
        if (have.count(k - node->val))
          return true;
        
        have.insert(node->val);
        bool result = false;
        
        if (node->left != nullptr)
          result |= self(self, node->left);
        if (node->right != nullptr)
          result |= self(self, node->right);
        
        return result;
      };
      
      return dfs(dfs, root);
    }
};
```

<br>

### Statistics

- total accepted: 355104
- total submissions: 598202
- acceptance rate: 59.4%
- likes: 4388
- dislikes: 213

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) (Medium)
- [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design) (Easy)
- [Two Sum BSTs](https://leetcode.com/problems/two-sum-bsts) (Medium)

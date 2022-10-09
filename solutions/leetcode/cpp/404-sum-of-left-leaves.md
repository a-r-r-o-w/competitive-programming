# [404] Sum of Left Leaves

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the sum of all left leaves.*

A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** 24
**Explanation:** There are two left leaves in the binary tree, with values 9 and 15 respectively.

```

**Example 2:**

```

**Input:** root = [1]
**Output:** 0

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `-1000 <= Node.val <= 1000`


<br>

### Hints

None

<br>

### Solution

**Recursive**

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
  
    int sumOfLeftLeaves (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node, bool is_left_child) -> int {
        if (node == nullptr)
          return 0;
        if (node->left == nullptr and node->right == nullptr)
          return is_left_child ? node->val : 0;
        return self(self, node->left, true) + self(self, node->right, false);
      };
      
      return dfs(dfs, root, false);
    }
};
```

**Iterative**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int sumOfLeftLeaves (TreeNode* root) {
      std::queue <std::pair <TreeNode*, bool>> q;
      int ans = 0;
      
      q.push({root, false});
      
      while (!q.empty()) {
        auto [node, is_left_child] = q.front();
        q.pop();
        
        if (node->left == nullptr and node->right == nullptr and is_left_child) {
          ans += node->val;
          continue;
        }
        
        if (node->left != nullptr)
          q.push({node->left, true});
        if (node->right != nullptr)
          q.push({node->right, false});
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 370793
- total submissions: 665628
- acceptance rate: 55.7%
- likes: 3584
- dislikes: 253

<br>

### Similar Problems

None

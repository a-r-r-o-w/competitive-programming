# [617] Merge Two Binary Trees

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

You are given two binary trees `root1` and `root2`.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return *the merged tree*.

**Note:** The merging process must start from the root nodes of both trees.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/05/merge.jpg)

```

**Input:** root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
**Output:** [3,4,5,5,4,null,7]

```

**Example 2:**

```

**Input:** root1 = [1], root2 = [1,2]
**Output:** [2,2]

```

**Constraints:**
* The number of nodes in both trees is in the range `[0, 2000]`.
* `-104 <= Node.val <= 104`


<br>

### Hints

None

<br>

### Solution

**Memory unsafe**

The solution modifies the input tree while the statement mentions that a new tree should be returned. This can cause memory errors because of issues like double free(), etc.

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
    TreeNode* mergeTrees (TreeNode* root1, TreeNode* root2) {
      auto dfs = [&] (auto self, TreeNode* node1, TreeNode* node2) -> TreeNode* {
        if (node1 == nullptr and node2 == nullptr)
          return nullptr;
        if (node1 == nullptr)
          return node2;
        if (node2 == nullptr)
          return node1;
        
        node1->val += node2->val;
        node1->left = self(self, node1->left, node2->left);
        node1->right = self(self, node1->right, node2->right);
        
        return node1;
      };
      
      return dfs(dfs, root1, root2);
    }
};
```

**Memory safe**

```cpp
class Solution {
  public:
    TreeNode* mergeTrees (TreeNode* root1, TreeNode* root2) {
      auto dfs = [&] (auto self, TreeNode* node1, TreeNode* node2) -> TreeNode* {
        if (node1 == nullptr and node2 == nullptr)
          return nullptr;
        
        if (node1 == nullptr) {
          auto newnode = new TreeNode (node2->val);
          newnode->left = self(self, nullptr, node2->left);
          newnode->right = self(self, nullptr, node2->right);
          return newnode;
        }
        
        if (node2 == nullptr) {
          auto newnode = new TreeNode (node1->val);
          newnode->left = self(self, node1->left, nullptr);
          newnode->right = self(self, node1->right, nullptr);
          return newnode;
        }
        
        auto newnode = new TreeNode (node1->val + node2->val);
        newnode->left = self(self, node1->left, node2->left);
        newnode->right = self(self, node1->right, node2->right);
        
        return newnode;
      };
      
      return dfs(dfs, root1, root2);
    }
};
```

<br>

### Statistics

- total accepted: 592760
- total submissions: 757804
- acceptance rate: 78.2%
- likes: 6903
- dislikes: 250

<br>

### Similar Problems

None

# [2415] Reverse Odd Levels of Binary Tree



### Statement

Given the `root` of a **perfect** binary tree, reverse the node values at each **odd** level of the tree.

* For example, suppose the node values at level 3 are `[2,1,3,4,7,11,29,18]`, then it should become `[18,29,11,7,4,3,1,2]`.



Return *the root of the reversed tree*.

A binary tree is **perfect** if all parent nodes have two children and all leaves are on the same level.

The **level** of a node is the number of edges along the path between it and the root node.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/07/28/first_case1.png)

```

**Input:** root = [2,3,5,8,13,21,34]
**Output:** [2,5,3,8,13,21,34]
**Explanation:** 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/07/28/second_case3.png)

```

**Input:** root = [7,13,11]
**Output:** [7,11,13]
**Explanation:** 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.

```

**Example 3:**

```

**Input:** root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
**Output:** [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
**Explanation:** 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 214]`.
* `0 <= Node.val <= 105`
* `root` is a **perfect** binary tree.


<br>

### Hints

- Try to solve recursively for each level independently.
- While performing a depth-first search, pass the left and right nodes (which should be paired) to the next level. If the current level is odd, then reverse their values, or else recursively move to the next level.

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
    TreeNode* reverseOddLevels (TreeNode* root) {
      std::queue <TreeNode*> q;
      int d = 0;
      
      q.push(root);
      
      while (!q.empty()) {
        int n = q.size();
        std::vector <int> values (n);
        
        for (int i = 0; i < n; ++i) {
          auto t = q.front();
          q.pop();
          q.push(t);
          values[i] = t->val;
        }
        
        for (int i = 0; i < n; ++i) {
          auto t = q.front();
          q.pop();
          
          if (d & 1)
            t->val = values[n - i - 1];
          
          if (t->left != nullptr) {
            q.push(t->left);
            q.push(t->right);
          }
        }
        
        ++d;
      }
      
      return root;
    }
};
```

<br>

### Statistics

- total accepted: 11876
- total submissions: 15705
- acceptance rate: 75.6%
- likes: 117
- dislikes: 2

<br>

### Similar Problems

- [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree) (Easy)

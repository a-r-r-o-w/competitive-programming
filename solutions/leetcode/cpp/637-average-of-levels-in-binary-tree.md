# [637] Average of Levels in Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

```

**Input:** root = [3,9,20,null,null,15,7]
**Output:** [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```

**Input:** root = [3,9,20,15,7]
**Output:** [3.00000,14.50000,11.00000]

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 104]`.
* `-231 <= Node.val <= 231 - 1`


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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <double> averageOfLevels (TreeNode* root) {
      std::vector <double> ans;
      std::queue <TreeNode*> q;
      
      q.push(root);
      
      while (!q.empty()) {
        double sum = 0;
        int n = q.size();
        
        for (int i = 0; i < n; ++i) {
          auto front = q.front();
          
          q.pop();
          sum += front->val;
          
          if (front->left != nullptr)
            q.push(front->left);
          if (front->right != nullptr)
            q.push(front->right);
        }
        
        ans.push_back(sum / n);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 285042
- total submissions: 412381
- acceptance rate: 69.1%
- likes: 3181
- dislikes: 248

<br>

### Similar Problems

- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) (Medium)
- [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) (Medium)

# [515] Find Largest Value in Each Tree Row

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *an array of the largest value in each row* of the tree **(0-indexed)**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)

```

**Input:** root = [1,3,2,5,3,null,9]
**Output:** [1,3,9]

```

**Example 2:**

```

**Input:** root = [1,2,3]
**Output:** [1,3]

```

**Constraints:**
* The number of nodes in the tree will be in the range `[0, 10^4]`.
* `-2^31 <= Node.val <= 2^31 - 1`


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
    vector<int> largestValues(TreeNode* root) {
      std::queue<TreeNode*> q;
      std::vector<int> ans;

      if (root != nullptr)
        q.push(root);
      
      while (!q.empty()) {
        int s = q.size(), max = std::numeric_limits<int>::min();
        
        while (s--) {
          auto u = q.front();
          q.pop();
          max = std::max(max, u->val);
          
          if (u->left != nullptr)
            q.push(u->left);
          if (u->right != nullptr)
            q.push(u->right);
        }

        ans.push_back(max);
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 306174
- total submissions: 466821
- acceptance rate: 65.6%
- likes: 3423
- dislikes: 105

<br />

### Similar Problems

None

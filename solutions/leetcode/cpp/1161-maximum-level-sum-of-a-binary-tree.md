# [1161] Maximum Level Sum of a Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `x` such that the sum of all the values of nodes at level `x` is **maximal**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)

```

**Input:** root = [1,7,0,7,-8,null,null]
**Output:** 2
**Explanation:** 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

```

**Example 2:**

```

**Input:** root = [989,null,10250,98693,-89388,null,null,null,-32127]
**Output:** 2

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 10^4]`.
* `-10^5 <= Node.val <= 10^5`


<br />

### Hints

- Calculate the sum for each level then find the level with the maximum sum.
- How can you traverse the tree ?
- How can you sum up the values for every level ?
- Use DFS or BFS to traverse the tree keeping the level of each node, and sum up those values with a map or a frequency array.

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
    int maxLevelSum (TreeNode* root) {
      std::queue <TreeNode*> q;
      int max = -(1 << 30), level = -1, depth = 1;

      q.push(root);

      while (!q.empty()) {
        int s = q.size(), sum = 0;

        for (int i = 0; i < s; ++i) {
          auto node = q.front();
          q.pop();
          sum += node->val;
          if (node->left != nullptr)
            q.push(node->left);
          if (node->right != nullptr)
            q.push(node->right);
        }

        if (sum > max) {
          max = sum;
          level = depth;
        }
        ++depth;
      }

      return level;
    }
};
```

<br />

### Statistics

- total accepted: 122787
- total submissions: 185996
- acceptance rate: 66.0%
- likes: 1803
- dislikes: 65

<br />

### Similar Problems

None

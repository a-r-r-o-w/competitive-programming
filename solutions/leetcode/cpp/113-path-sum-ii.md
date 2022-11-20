# [113] Path Sum II

**[backtracking, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree and an integer `targetSum`, return *all **root-to-leaf** paths where the sum of the node values in the path equals* `targetSum`*. Each path should be returned as a list of the node **values**, not node references*.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```

**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
**Output:** [[5,4,11,2],[5,8,4,5]]
**Explanation:** There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```

**Input:** root = [1,2,3], targetSum = 5
**Output:** []

```

**Example 3:**

```

**Input:** root = [1,2], targetSum = 0
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 5000]`.
* `-1000 <= Node.val <= 1000`
* `-1000 <= targetSum <= 1000`


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
    vector <vector <int>> pathSum (TreeNode *root, int targetSum) {
      std::vector <std::vector <int>> paths;
      std::vector <int> current_path;
      
      auto dfs = [&] (auto self, TreeNode *node, int sum) -> void {
        if (node == nullptr)
          return;
        
        sum += node->val;
        current_path.push_back(node->val);
        
        if (node->left == nullptr and node->right == nullptr) {
          if (sum == targetSum)
            paths.push_back(current_path);
        }
        else if (node->left == nullptr)
          self(self, node->right, sum);
        else if (node->right == nullptr)
          self(self, node->left, sum);
        else {
          self(self, node->left, sum);
          self(self, node->right, sum);
        }
        
        sum -= node->val;
        current_path.pop_back();
      };
      
      dfs(dfs, root, 0);
      
      return paths;
    }
};
```

<br>

### Statistics

- total accepted: 662853
- total submissions: 1185059
- acceptance rate: 55.9%
- likes: 5958
- dislikes: 124

<br>

### Similar Problems

- [Path Sum](https://leetcode.com/problems/path-sum) (Easy)
- [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths) (Easy)
- [Path Sum III](https://leetcode.com/problems/path-sum-iii) (Medium)
- [Path Sum IV](https://leetcode.com/problems/path-sum-iv) (Medium)
- [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another) (Medium)

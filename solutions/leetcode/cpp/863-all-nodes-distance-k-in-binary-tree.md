# [863] All Nodes Distance K in Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return *an array of the values of all nodes that have a distance* `k` *from the target node.*

You can return the answer in **any order**.


**Example 1:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)

```

**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
**Output:** [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

```

**Example 2:**

```

**Input:** root = [1], target = 1, k = 3
**Output:** []

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 500]`.
* `0 <= Node.val <= 500`
* All the values `Node.val` are **unique**.
* `target` is the value of one of the nodes in the tree.
* `0 <= k <= 1000`


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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    vector <int> distanceK (TreeNode *root, TreeNode *target, int k) {
      std::unordered_map <int, std::vector <int>> graph;

      auto dfs = [&] (auto self, TreeNode *node, TreeNode *parent) -> void {
        if (node == nullptr)
          return;
        graph[parent->val].push_back(node->val);
        graph[node->val].push_back(parent->val);
        self(self, node->left, node);
        self(self, node->right, node);
      };

      dfs(dfs, root->left, root);
      dfs(dfs, root->right, root);

      std::queue <int> q;
      std::unordered_set <int> visited;

      q.push(target->val);
      visited.insert(target->val);

      while (!q.empty() and k--) {
        int s = q.size();
        for (int i = 0; i < s; ++i) {
          int u = q.front();
          q.pop();
          for (int v: graph[u]) {
            if (visited.count(v))
              continue;
            q.push(v);
            visited.insert(v);
          }
        }
      }

      std::vector <int> ans;
      while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
      }
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 348989
- total submissions: 549589
- acceptance rate: 63.5%
- likes: 9620
- dislikes: 185

<br />

### Similar Problems

- [Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected) (Medium)

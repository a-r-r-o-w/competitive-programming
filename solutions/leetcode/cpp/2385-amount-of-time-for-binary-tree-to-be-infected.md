# [2385] Amount of Time for Binary Tree to Be Infected

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

You are given the `root` of a binary tree with **unique** values, and an integer `start`. At minute `0`, an **infection** starts from the node with value `start`.

Each minute, a node becomes infected if:

* The node is currently uninfected.
* The node is adjacent to an infected node.



Return *the number of minutes needed for the entire tree to be infected.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png)

```

**Input:** root = [1,5,3,null,4,10,6,9,2], start = 3
**Output:** 4
**Explanation:** The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png)

```

**Input:** root = [1], start = 1
**Output:** 0
**Explanation:** At minute 0, the only node in the tree is infected so we return 0.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 10^5]`.
* `1 <= Node.val <= 10^5`
* Each node has a **unique** value.
* A node with a value of `start` exists in the tree.


<br />

### Hints

- Convert the tree to an undirected graph to make it easier to handle.
- Use BFS starting at the start node to find the distance between each node and the start node. The answer is the maximum distance.

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
    int amountOfTime (TreeNode* root, int start) {
      std::map <int, std::vector <int>> graph;

      auto dfs = [&] (auto self, TreeNode *u, TreeNode *p) -> void {
        if (u == nullptr)
          return;
        if (p != nullptr) {
          graph[u->val].push_back(p->val);
          graph[p->val].push_back(u->val);
        }
        self(self, u->left, u);
        self(self, u->right, u);
      };

      dfs(dfs, root, nullptr);

      std::queue <int> q;
      std::set <int> visited;
      int depth = 0;

      q.push(start);
      visited.insert(start);

      while (!q.empty()) {
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
        ++depth;
      }

      return depth - 1;
    }
};
```

<br />

### Statistics

- total accepted: 23183
- total submissions: 40915
- acceptance rate: 56.7%
- likes: 967
- dislikes: 13

<br />

### Similar Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) (Easy)
- [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food) (Medium)
- [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree) (Medium)

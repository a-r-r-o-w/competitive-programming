# [2583] Kth Largest Sum in a Binary Tree



### Statement

You are given the `root` of a binary tree and a positive integer `k`.

The **level sum** in the tree is the sum of the values of the nodes that are on the **same** level.

Return *the* `k^th` ***largest** level sum in the tree (not necessarily distinct)*. If there are fewer than `k` levels in the tree, return `-1`.

**Note** that two nodes are on the same level if they have the same distance from the root.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png)

```

**Input:** root = [5,8,9,2,1,3,7,4,6], k = 2
**Output:** 13
**Explanation:** The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2^nd largest level sum is 13.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png)

```

**Input:** root = [1,2,null,3], k = 1
**Output:** 3
**Explanation:** The largest level sum is 3.

```

**Constraints:**
* The number of nodes in the tree is `n`.
* `2 <= n <= 10^5`
* `1 <= Node.val <= 10^6`
* `1 <= k <= n`


<br />

### Hints

- Find the sum of values of nodes on each level and return the kth largest one.
- To find the sum of the values of nodes on each level, you can use a DFS or BFS algorithm to traverse the tree and keep track of the level of each node.

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
    long long kthLargestLevelSum (TreeNode* root, int k) {
      std::vector <int64_t> sums;
      std::queue <TreeNode*> q;
      
      q.push(root);
      
      while (!q.empty()) {
        int s = q.size();
        int64_t sum = 0;
        
        for (int i = 0; i < s; ++i) {
          auto u = q.front();
          q.pop();
          sum += u->val;
          if (u->left != nullptr)
            q.push(u->left);
          if (u->right != nullptr)
            q.push(u->right);
        }
        
        sums.push_back(sum);
      }
      
      std::sort(sums.rbegin(), sums.rend());
      
      if (int(sums.size()) < k)
        return -1;
      return sums[k - 1];
    }
};
```

<br />

### Statistics

- total accepted: 10887
- total submissions: 24034
- acceptance rate: 45.3%
- likes: 59
- dislikes: 3

<br />

### Similar Problems

- [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) (Easy)
- [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) (Medium)

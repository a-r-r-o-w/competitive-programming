# [2471] Minimum Number of Operations to Sort a Binary Tree by Level



### Statement

You are given the `root` of a binary tree with **unique values**.

In one operation, you can choose any two nodes **at the same level** and swap their values.

Return *the minimum number of operations needed to make the values at each level sorted in a **strictly increasing order***.

The **level** of a node is the number of edges along the path between it and the root node*.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/09/18/image-20220918174006-2.png)

```

**Input:** root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
**Output:** 3
**Explanation:**
- Swap 4 and 3. The 2nd level becomes [3,4].
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/09/18/image-20220918174026-3.png)

```

**Input:** root = [1,3,2,7,6,5,4]
**Output:** 3
**Explanation:**
- Swap 3 and 2. The 2nd level becomes [2,3].
- Swap 7 and 4. The 3rd level becomes [4,6,5,7].
- Swap 6 and 5. The 3rd level becomes [4,5,6,7].
We used 3 operations so return 3.
It can be proven that 3 is the minimum number of operations needed.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2022/09/18/image-20220918174052-4.png)

```

**Input:** root = [1,2,3,4,5,6]
**Output:** 0
**Explanation:** Each level is already sorted in increasing order so return 0.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 105]`.
* `1 <= Node.val <= 105`
* All the values of the tree are **unique**.


<br>

### Hints

- We can group the values level by level and solve each group independently.
- Do BFS to group the value level by level.
- Find the minimum number of swaps to sort the array of each level.
- While iterating over the array, check the current element, and if not in the correct index, replace that element with the index of the element which should have come.

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
  
    int minimumOperations (TreeNode* root) {
      std::map <int, std::vector <int>> depth;
      
      auto dfs = [&] (auto self, TreeNode *node, int d) -> void {
        if (node == nullptr)
          return;
        depth[d].push_back(node->val);
        self(self, node->left, d + 1);
        self(self, node->right, d + 1);
      };
      
      dfs(dfs, root, 0);
      
      int ans = 0;
      
      for (auto &[d, v]: depth) {
        int n = v.size();
        std::vector <int> order (n), t = v;
        std::map <int, int> lookup;
        
        std::sort(t.begin(), t.end());
        
        for (int i = 0; i < n; ++i)
          lookup[v[i]] = i;
        
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
          if (v[i] == t[i])
            continue;
          
          int x = v[i];
          
          ++count;
          std::swap(v[i], v[lookup[t[i]]]);
          lookup[x] = lookup[t[i]];
          lookup[t[i]] = i;
        }
        
        ans += count;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 9126
- total submissions: 14688
- acceptance rate: 62.1%
- likes: 147
- dislikes: 1

<br>

### Similar Problems

- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) (Medium)
- [Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph) (Hard)

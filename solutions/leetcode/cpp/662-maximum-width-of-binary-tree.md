# [662] Maximum Width of Binary Tree

**[tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the **maximum width** of the given tree*.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of a **32-bit** signed integer.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg)

```

**Input:** root = [1,3,2,5,3,null,9]
**Output:** 4
**Explanation:** The maximum width exists in the third level with length 4 (5,3,null,9).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg)

```

**Input:** root = [1,3,2,5,null,null,9,6,null,7]
**Output:** 7
**Explanation:** The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg)

```

**Input:** root = [1,3,2,5]
**Output:** 2
**Explanation:** The maximum width exists in the second level with length 2 (3,2).

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 3000]`.
* `-100 <= Node.val <= 100`


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
    int widthOfBinaryTree (TreeNode* root) {
      int ans = 0;
      std::queue <std::pair <TreeNode*, int64_t>> q;
      q.emplace(root, 0);

      while (!q.empty()) {
        int s = q.size(), begin = q.front().second, end = q.back().second;
        ans = std::max(ans, end - begin + 1);

        for (int i = 0; i < s; ++i) {
          auto [u, v] = q.front();
          int index = v - begin;
          
          q.pop();
          if (u->left != nullptr)
            q.emplace(u->left, (int64_t)2 * index + 1);
          if (u->right != nullptr)
            q.emplace(u->right, (int64_t)2 * index + 2);
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 267971
- total submissions: 643350
- acceptance rate: 41.7%
- likes: 6936
- dislikes: 958

<br />

### Similar Problems

None

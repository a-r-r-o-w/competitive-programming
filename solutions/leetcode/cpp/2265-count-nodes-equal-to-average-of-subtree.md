# [2265] Count Nodes Equal to Average of Subtree

**[tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, return *the number of nodes where the value of the node is equal to the **average** of the values in its **subtree***.

**Note:**
* The **average** of `n` elements is the **sum** of the `n` elements divided by `n` and **rounded down** to the nearest integer.
* A **subtree** of `root` is a tree consisting of `root` and all of its descendants.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/03/15/image-20220315203925-1.png)

```

**Input:** root = [4,8,5,0,1,null,6]
**Output:** 5
**Explanation:** 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/03/26/image-20220326133920-1.png)

```

**Input:** root = [1]
**Output:** 1
**Explanation:** For the node with value 1: The average of its subtree is 1 / 1 = 1.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `0 <= Node.val <= 1000`


<br>

### Hints

- What information do we need to calculate the average? We need the sum of the values and the number of values.
- Create a recursive function that returns the size of a node’s subtree, and the sum of the values of its subtree.

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
    int averageOfSubtree (TreeNode* root) {
      int ans = 0;
      
      auto dfs = [&] (auto self, TreeNode* node) -> std::pair <int, int> {
        if (node == nullptr)
          return {0, 0};
        
        auto l = self(self, node->left);
        auto r = self(self, node->right);
        
        int sum = l.first + r.first + node->val;
        int count = l.second + r.second + 1;
        if (sum / count == node->val)
          ++ans;
        
        return {sum, count};
      };
      
      dfs(dfs, root);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 19904
- total submissions: 23293
- acceptance rate: 85.5%
- likes: 478
- dislikes: 9

<br>

### Similar Problems

- [Maximum Average Subtree](https://leetcode.com/problems/maximum-average-subtree) (Medium)
- [Insufficient Nodes in Root to Leaf Paths](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths) (Medium)
- [Count Nodes Equal to Sum of Descendants](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants) (Medium)

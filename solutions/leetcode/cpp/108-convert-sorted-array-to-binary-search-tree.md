# [108] Convert Sorted Array to Binary Search Tree

**[array, divide-and-conquer, tree, binary-search-tree, binary-tree]**

### Statement

Given an integer array `nums` where the elements are sorted in **ascending order**, convert *it to a **height-balanced** binary search tree*.

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

```

**Input:** nums = [-10,-3,0,5,9]
**Output:** [0,-3,9,-10,null,5]
**Explanation:** [0,-10,5,null,-3,null,9] is also accepted:
![](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```

**Input:** nums = [1,3]
**Output:** [3,1]
**Explanation:** [1,null,3] and [3,1] are both height-balanced BSTs.

```

**Constraints:**
* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in a **strictly increasing** order.


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
    TreeNode* sortedArrayToBST (vector <int>& nums) {
      int n = nums.size();
      
      auto dfs = [&] (auto self, int l, int r) -> TreeNode* {
        if (l >= r)
          return nullptr;
        int m = (l + r) / 2;
        TreeNode* x = new TreeNode(nums[m]);
        x->left = self(self, l, m);
        x->right = self(self, m + 1, r);
        return x;
      };
      
      return dfs(dfs, 0, n);
    }
};
```

<br>

### Statistics

- total accepted: 823737
- total submissions: 1213878
- acceptance rate: 67.9%
- likes: 7624
- dislikes: 392

<br>

### Similar Problems

- [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree) (Medium)

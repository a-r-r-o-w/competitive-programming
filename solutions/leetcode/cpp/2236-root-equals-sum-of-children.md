# [2236] Root Equals Sum of Children

**[tree, binary-tree]**

### Statement

You are given the `root` of a **binary tree** that consists of exactly `3` nodes: the root, its left child, and its right child.

Return `true` *if the value of the root is equal to the **sum** of the values of its two children, or* `false` *otherwise*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/04/08/graph3drawio.png)

```

**Input:** root = [10,4,6]
**Output:** true
**Explanation:** The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/04/08/graph3drawio-1.png)

```

**Input:** root = [5,3,1]
**Output:** false
**Explanation:** The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.

```

**Constraints:**
* The tree consists only of the root, its left child, and its right child.
* `-100 <= Node.val <= 100`


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
    bool checkTree (TreeNode* root) {
      return root->val == root->left->val + root->right->val;
    }
};
```

<br>

### Statistics

- total accepted: 42312
- total submissions: 47607
- acceptance rate: 88.9%
- likes: 310
- dislikes: 529

<br>

### Similar Problems

None

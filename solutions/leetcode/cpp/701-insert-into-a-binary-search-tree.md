# [701] Insert into a Binary Search Tree

**[tree, binary-search-tree, binary-tree]**

### Statement

You are given the `root` node of a binary search tree (BST) and a `value` to insert into the tree. Return *the root node of the BST after the insertion*. It is **guaranteed** that the new value does not exist in the original BST.

**Notice**that there may existmultiple valid ways for theinsertion, as long as the tree remains a BST after insertion. You can return **any of them**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg)

```

**Input:** root = [4,2,7,1,3], val = 5
**Output:** [4,2,7,1,3,5]
**Explanation:** Another accepted tree is:
![](https://assets.leetcode.com/uploads/2020/10/05/bst.jpg)

```

**Example 2:**

```

**Input:** root = [40,20,60,10,30,50,70], val = 25
**Output:** [40,20,60,10,30,50,70,null,null,25]

```

**Example 3:**

```

**Input:** root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
**Output:** [4,2,7,1,3,5]

```

**Constraints:**
* The number of nodes inthe tree will be in the range `[0,104]`.
* `-108 <= Node.val <= 108`
* All the values `Node.val` are **unique**.
* `-108 <= val <= 108`
* It's **guaranteed** that `val` does not exist in the original BST.


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
    TreeNode* insertIntoBST (TreeNode* root, int val) {
      TreeNode dummy (1 << 30, root, nullptr), *prev = &dummy;
      
      while (root != nullptr) {
        prev = root;
        if (root->val < val)
          root = root->right;
        else
          root = root->left;
      }
      
      if (prev->val < val)
        prev->right = new TreeNode(val);
      else
        prev->left = new TreeNode(val);
      
      return dummy.left;
    }
};
```

<br>

### Statistics

- total accepted: 348297
- total submissions: 466265
- acceptance rate: 74.7%
- likes: 3962
- dislikes: 151

<br>

### Similar Problems

- [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree) (Easy)

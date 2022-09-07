# [606] Construct String from Binary Tree

**[string, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg)

```

**Input:** root = [1,2,3,4]
**Output:** "1(2(4))(3)"
**Explanation:** Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/05/03/cons2-tree.jpg)

```

**Input:** root = [1,2,3,null,4]
**Output:** "1(2()(4))(3)"
**Explanation:** Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 10^4]`.
* `-1000 <= Node.val <= 1000`


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
    string tree2str (TreeNode *root) {
      std::string ans;
      
      auto dfs = [&] (auto self, TreeNode *node) -> void {
        ans += std::to_string(node->val);
        
        if (node->left != nullptr and node->right != nullptr) {
          ans += '(';
          self(self, node->left);
          ans += ')';
          ans += '(';
          self(self, node->right);
          ans += ')';
        }
        else if (node->left != nullptr) {
          ans += '(';
          self(self, node->left);
          ans += ')';
        }
        else if (node->right != nullptr) {
          ans += "()(";
          self(self, node->right);
          ans += ')';
        }
      };
      
      dfs(dfs, root);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 146079
- total submissions: 246661
- acceptance rate: 59.2%
- likes: 1622
- dislikes: 2035

<br>

### Similar Problems

- [Construct Binary Tree from String](https://leetcode.com/problems/construct-binary-tree-from-string) (Medium)
- [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees) (Medium)

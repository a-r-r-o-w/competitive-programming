# [1457] Pseudo-Palindromic Paths in a Binary Tree

**[bit-manipulation, tree, depth-first-search, breadth-first-search, binary-tree]**

### Statement

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be **pseudo-palindromic** if at least one permutation of the node values in the path is a palindrome.

*Return the number of **pseudo-palindromic** paths going from the root node to leaf nodes.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png)

```

**Input:** root = [2,3,1,3,1,null,1]
**Output:** 2 
**Explanation:** The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png)**

```

**Input:** root = [2,1,1,1,3,null,null,null,null,null,1]
**Output:** 1 
**Explanation:** The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

```

**Example 3:**

```

**Input:** root = [9]
**Output:** 1

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 105]`.
* `1 <= Node.val <= 9`


<br>

### Hints

- Note that the node values of a path form a palindrome if at most one digit has an odd frequency (parity).
- Use a Depth First Search (DFS) keeping the frequency (parity) of the digits. Once you are in a leaf node check if at most one digit has an odd frequency (parity).

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
  
    int pseudoPalindromicPaths (TreeNode* root) {
      int count = 0;
      std::vector <int> freq (10);
      
      auto dfs = [&] (auto self, TreeNode *node) -> void {
        int even = 0, odd = 0;
        bool has_left = true, has_right = true;
        
        ++freq[node->val];
        
        if (node->left != nullptr)
          self(self, node->left);
        else
          has_left = false;
        if (node->right != nullptr)
          self(self, node->right);
        else
          has_right = false;
        
        if (!has_left and !has_right) {
          for (int i = 0; i < 10; ++i)
            ++(freq[i] % 2 ? odd : even);

          if (odd <= 1)
            ++count;
        }
        
        --freq[node->val];
      };
      
      dfs(dfs, root);
      
      return count;
    }
};
```

<br>

### Statistics

- total accepted: 62723
- total submissions: 93109
- acceptance rate: 67.4%
- likes: 1258
- dislikes: 46

<br>

### Similar Problems

None

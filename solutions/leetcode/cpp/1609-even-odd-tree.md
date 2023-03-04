# [1609] Even Odd Tree

**[tree, breadth-first-search, binary-tree]**

### Statement

A binary tree is named **Even-Odd** if it meets the following conditions:

* The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.
* For every **even-indexed** level, all nodes at the level have **odd** integer values in **strictly increasing** order (from left to right).
* For every **odd-indexed** level, all nodes at the level have **even** integer values in **strictly decreasing** order (from left to right).



Given the `root` of a binary tree, *return* `true` *if the binary tree is **Even-Odd**, otherwise return* `false`*.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png)

```

**Input:** root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
**Output:** true
**Explanation:** The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png)

```

**Input:** root = [5,4,2,3,3,7]
**Output:** false
**Explanation:** The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png)

```

**Input:** root = [5,9,1,3,5,7]
**Output:** false
**Explanation:** Node values in the level 1 should be even integers.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 10^5]`.
* `1 <= Node.val <= 10^6`


<br />

### Hints

- Use the breadth-first search to go through all nodes layer by layer.

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
    bool isEvenOddTree (TreeNode* root) {
      std::queue <TreeNode*> q;
      std::vector <int> values;
      int depth = 0;

      q.push(root);
      
      while (not q.empty()) {
        int s = q.size();
        bool odd = false, even = false;
        
        for (int i = 0; i < s; ++i) {
          auto t = q.front();
          q.pop();
          values.push_back(t->val);
          if (t->val & 1)
            odd = true;
          else
            even = true;
          if (t->left != nullptr)
            q.push(t->left);
          if (t->right != nullptr)
            q.push(t->right);
        }

        if (depth & 1) {
          if (odd or not std::is_sorted(values.begin(), values.end(), std::greater_equal <int> ()))
            return false;
        }
        else {
          if (even or not std::is_sorted(values.begin(), values.end(), std::less_equal <int> ()))
            return false;
        }

        values.clear();
        ++depth;
      }

      return true;
    }
};
```

<br />

### Statistics

- total accepted: 41821
- total submissions: 77217
- acceptance rate: 54.2%
- likes: 957
- dislikes: 51

<br />

### Similar Problems

None

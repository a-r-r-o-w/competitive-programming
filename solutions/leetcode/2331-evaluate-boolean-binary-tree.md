# [2331] Evaluate Boolean Binary Tree

**[binary-search, tree, depth-first-search]**

### Statement

You are given the `root` of a **full binary tree** with the following properties:

* **Leaf nodes** have either the value `0` or `1`, where `0` represents `False` and `1` represents `True`.
* **Non-leaf nodes** have either the value `2` or `3`, where `2` represents the boolean `OR` and `3` represents the boolean `AND`.



The **evaluation** of a node is as follows:

* If the node is a leaf node, the evaluation is the **value** of the node, i.e. `True` or `False`.
* Otherwise, **evaluate** the node's two children and **apply** the boolean operation of its value with the children's evaluations.



Return *the boolean result of **evaluating** the* `root` *node.*

A **full binary tree** is a binary tree where each node has either `0` or `2` children.

A **leaf node** is a node that has zero children.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/05/16/example1drawio1.png)

```

**Input:** root = [2,1,3,null,null,0,1]
**Output:** true
**Explanation:** The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
```

**Example 2:**

```

**Input:** root = [0]
**Output:** false
**Explanation:** The root node is a leaf node and it evaluates to false, so we return false.

```

**Constraints:**
* The number of nodes in the tree is in the range `[1, 1000]`.
* `0 <= Node.val <= 3`
* Every node has either `0` or `2` children.
* Leaf nodes have a value of `0` or `1`.
* Non-leaf nodes have a value of `2` or `3`.


<br>

### Hints

- Traverse the tree using depth-first search in post-order.
- Can you use recursion to solve this easily?

<br>

### Solution

```
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
    bool evaluateTree (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node) -> bool {
        if (node->val == 0 or node->val == 1)
          return node->val;
        if (node->val == 2)
          return self(self, node->left) or self(self, node->right);
        return self(self, node->left) and self(self, node->right);
      };
      
      return dfs(dfs, root);
    }
};
```

<br>

### Statistics

- total accepted: 16913
- total submissions: 21449
- acceptance rate: 78.9%
- likes: 156
- dislikes: 2

<br>

### Similar Problems

- [Check If Two Expression Trees are Equivalent](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent) (Medium)
- [Design an Expression Tree With Evaluate Function](https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function) (Medium)
- [Minimum Flips in Binary Tree to Get Result](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result) (Hard)

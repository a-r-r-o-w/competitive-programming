# [114] Flatten Binary Tree to Linked List

**[linked-list, stack, tree, depth-first-search, binary-tree]**

### Statement

Given the `root` of a binary tree, flatten the tree into a "linked list":

* The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
* The "linked list" should be in the same order as a [**pre-order** **traversal**](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) of the binary tree.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

```

**Input:** root = [1,2,5,3,4,null,6]
**Output:** [1,null,2,null,3,null,4,null,5,null,6]

```

**Example 2:**

```

**Input:** root = []
**Output:** []

```

**Example 3:**

```

**Input:** root = [0]
**Output:** [0]

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 2000]`.
* `-100 <= Node.val <= 100`


**Follow up:** Can you flatten the tree in-place (with `O(1)` extra space)?

<br>

### Hints

- If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

<br>

### Solution

Thinking in terms of linked lists

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
  
    void flatten (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node) -> std::pair <TreeNode*, TreeNode*> {
        if (node->left != nullptr and node->right != nullptr) {
          auto [lhead, ltail] = self(self, node->left);
          auto [rhead, rtail] = self(self, node->right);
          
          ltail->right = rhead;
          node->left = nullptr;
          node->right = lhead;
          
          return {node, rtail};
        }
        else if (node->left != nullptr) {
          auto [lhead, ltail] = self(self, node->left);
          node->left = nullptr;
          node->right = lhead;
          return {node, ltail};
        }
        else if (node->right != nullptr) {
          auto [rhead, rtail] = self(self, node->right);
          return {node, rtail};
        }
        else
          return {node, node};
      };
      
      if (root != nullptr)
        dfs(dfs, root);
    }
};
```

Iterative

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    void flatten (TreeNode* root) {
      while (root != nullptr) {
        if (root->left != nullptr) {
          if (root->right != nullptr) {
            auto node = root->left;
            
            while (node->right != nullptr)
              node = node->right;
            
            node->right = root->right;
          }
          
          root->right = root->left;
          root->left = nullptr;
        }
        
        root = root->right;
      }
    }
};
```

<br>

### Statistics

- total accepted: 638406
- total submissions: 1084086
- acceptance rate: 58.9%
- likes: 7818
- dislikes: 471

<br>

### Similar Problems

- [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list) (Medium)
- [Correct a Binary Tree](https://leetcode.com/problems/correct-a-binary-tree) (Medium)

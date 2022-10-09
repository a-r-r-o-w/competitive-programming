# [589] N-ary Tree Preorder Traversal

**[stack, tree, depth-first-search]**

### Statement

Given the `root` of an n-ary tree, return *the preorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```

**Input:** root = [1,null,3,2,4,null,5,6]
**Output:** [1,3,5,6,2,4]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```

**Input:** root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
**Output:** [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

```

**Constraints:**
* The number of nodes in the tree is in the range `[0, 104]`.
* `0 <= Node.val <= 104`
* The height of the n-ary tree is less than or equal to `1000`.


**Follow up:** Recursive solution is trivial, could you do it iteratively?

<br>

### Hints

None

<br>

### Solution

Recursive

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> preorder (Node* root) {
      std::vector <int> order;
      order.reserve(10000);
      
      auto dfs = [&] (auto self, Node* node) -> void {
        order.push_back(node->val);
        
        for (auto c: node->children)
          self(self, c);
      };
      
      if (root != nullptr)
        dfs(dfs, root);
      
      return order;
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
  
    vector <int> preorder (Node* root) {
      std::stack <std::pair <int, Node*>> s;
      std::vector <int> order;
      order.reserve(10000);
      
      if (root != nullptr)
        s.push({0, root});
      
      while (!s.empty()) {
        auto &[index, node] = s.top();
        
        if (index == 0)
          order.push_back(node->val);
        if (index >= (int)node->children.size())
          s.pop();
        else {
          s.push({0, node->children[index]});
          ++index;
        }
      }
      
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 261711
- total submissions: 342589
- acceptance rate: 76.4%
- likes: 2006
- dislikes: 98

<br>

### Similar Problems

- [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) (Easy)
- [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) (Medium)
- [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal) (Easy)

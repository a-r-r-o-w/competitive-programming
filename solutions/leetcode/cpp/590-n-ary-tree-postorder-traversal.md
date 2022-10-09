# [590] N-ary Tree Postorder Traversal

**[stack, tree, depth-first-search]**

### Statement

Given the `root` of an n-ary tree, return *the postorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```

**Input:** root = [1,null,3,2,4,null,5,6]
**Output:** [5,6,3,2,4,1]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```

**Input:** root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
**Output:** [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

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
  
    vector <int> postorder (Node* root) {
      std::vector <int> order;
      order.reserve(10000);
      
      auto dfs = [&] (auto self, Node* node) -> void {
        for (auto c: node->children)
          self(self, c);
        
        order.push_back(node->val);
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
  
    vector <int> postorder (Node* root) {
      std::stack <Node*> s;
      std::vector <int> order;
      order.reserve(10000);
      
      if (root != nullptr)
        s.push(root);
      
      while (!s.empty()) {
        auto top = s.top();
        
        s.pop();
        order.push_back(top->val);
        
        for (auto c: top->children)
          s.push(c);
      }
      
      std::reverse(order.begin(), order.end());
      
      return order;
    }
};
```

Iterative without reversing

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> postorder (Node* root) {
      std::stack <std::pair <int, Node*>> s;
      std::vector <int> order;
      order.reserve(10000);
      
      if (root != nullptr)
        s.push({0, root});
      
      while (!s.empty()) {
        auto &[index, node] = s.top();
        
        if (index == (int)node->children.size()) {
          order.push_back(node->val);
          s.pop();
        }
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

- total accepted: 191751
- total submissions: 250408
- acceptance rate: 76.6%
- likes: 1709
- dislikes: 86

<br>

### Similar Problems

- [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) (Easy)
- [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) (Medium)
- [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal) (Easy)

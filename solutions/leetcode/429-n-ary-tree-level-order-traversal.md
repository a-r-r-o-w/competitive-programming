# [429] N-ary Tree Level Order Traversal

**[tree, breadth-first-search]**

### Statement

Given an n-ary tree, return the *level order* traversal of its nodes' values.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).*
**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```

**Input:** root = [1,null,3,2,4,null,5,6]
**Output:** [[1],[3,2,4],[5,6]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```

**Input:** root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
**Output:** [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

```

**Constraints:**
* The height of the n-ary tree is less than or equal to `1000`
* The total number of nodes is between `[0, 10^4]`


<br>

### Hints

None

<br>

### Solution

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
    vector <vector <int>> levelOrder (Node *root) {
      std::vector <std::vector <int>> order;
      std::vector <int> current;
      std::queue <Node*> q;
      
      if (root != nullptr)
        q.push(root);
      
      while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; ++i) {
          auto node = q.front();
          
          q.pop();
          current.push_back(node->val);
          
          for (auto &child: node->children)
            q.push(child);
        }
        
        order.push_back(current);
        current.clear();
      }
      
      return order;
    }
};
```

<br>

### Statistics

- total accepted: 226352
- total submissions: 323411
- acceptance rate: 70.0%
- likes: 2675
- dislikes: 108

<br>

### Similar Problems

- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) (Medium)
- [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal) (Easy)
- [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal) (Easy)
- [The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle) (Medium)

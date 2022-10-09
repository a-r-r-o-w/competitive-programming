# [559] Maximum Depth of N-ary Tree

**[tree, depth-first-search, breadth-first-search]**

### Statement

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).*
**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```

**Input:** root = [1,null,3,2,4,null,5,6]
**Output:** 3

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```

**Input:** root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
**Output:** 5

```

**Constraints:**
* The total number of nodes is in the range `[0, 104]`.
* The depth of the n-ary tree is less than or equal to `1000`.


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
    int maxDepth (Node* root) {
      auto dfs = [&] (auto self, Node* node) -> int {
        if (node == nullptr)
          return 0;
        
        int max = 0;
        for (Node* child: node->children)
          max = std::max(max, self(self, child));
        
        return 1 + max;
      };
      
      return dfs(dfs, root);
    }
};
```

<br>

### Statistics

- total accepted: 219748
- total submissions: 308147
- acceptance rate: 71.3%
- likes: 2097
- dislikes: 73

<br>

### Similar Problems

- [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree) (Easy)
- [The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle) (Medium)

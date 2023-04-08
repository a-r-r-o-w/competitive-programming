# [133] Clone Graph

**[hash-table, depth-first-search, breadth-first-search, graph]**

### Statement

Given a reference of a node in a **[connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph)** undirected graph.

Return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) (clone) of the graph.

Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.


```

class Node {
    public int val;
    public List<Node> neighbors;
}

```

**Test case format:**

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with `val == 1`, the second node with `val == 2`, and so on. The graph is represented in the test case using an adjacency list.

**An adjacency list** is a collection of unordered **lists** used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with `val = 1`. You must return the **copy of the given node** as a reference to the cloned graph.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)

```

**Input:** adjList = [[2,4],[1,3],[2,4],[1,3]]
**Output:** [[2,4],[1,3],[2,4],[1,3]]
**Explanation:** There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/01/07/graph.png)

```

**Input:** adjList = [[]]
**Output:** [[]]
**Explanation:** Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

```

**Example 3:**

```

**Input:** adjList = []
**Output:** []
**Explanation:** This an empty graph, it does not have any nodes.

```

**Constraints:**
* The number of nodes in the graph is in the range `[0, 100]`.
* `1 <= Node.val <= 100`
* `Node.val` is unique for each node.
* There are no repeated edges and no self-loops in the graph.
* The Graph is connected and all nodes can be visited starting from the given node.


<br />

### Hints

None

<br />

### Solution

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
    Node* cloneGraph (Node* node) {
      if (node == nullptr)
        return nullptr;
      if (node->neighbors.empty()) {
        return new Node(node->val);
      }

      std::map <Node*, Node*> map;

      auto dfs = [&] (auto self, Node *node) -> Node* {
        std::vector <Node*> neighbors;
        Node *clone = new Node(node->val);
        map[node] = clone;
        for (auto &next: node->neighbors) {
          if (map.count(next))
            neighbors.push_back(map[next]);
          else
            neighbors.push_back(self(self, next));
        }
        clone->neighbors.swap(neighbors);
        return clone;
      };

      return dfs(dfs, node);
    }
};
```

<br />

### Statistics

- total accepted: 945968
- total submissions: 1800467
- acceptance rate: 52.5%
- likes: 7864
- dislikes: 3206

<br />

### Similar Problems

- [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) (Medium)
- [Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer) (Medium)
- [Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree) (Medium)

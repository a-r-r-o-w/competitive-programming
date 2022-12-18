# [2509] Cycle Length Queries in a Tree



### Statement

You are given an integer `n`. There is a **complete binary tree** with `2n - 1` nodes. The root of that tree is the node with the value `1`, and every node with a value `val` in the range `[1, 2n - 1 - 1]` has two children where:

* The left node has the value `2 * val`, and
* The right node has the value `2 * val + 1`.



You are also given a 2D integer array `queries` of length `m`, where `queries[i] = [ai, bi]`. For each query, solve the following problem:

1. Add an edge between the nodes with values `ai` and `bi`.
2. Find the length of the cycle in the graph.
3. Remove the added edge between nodes with values `ai` and `bi`.


**Note** that:

* A **cycle** is a path that starts and ends at the same node, and each edge in the path is visited only once.
* The length of a cycle is the number of edges visited in the cycle.
* There could be multiple edges between two nodes in the tree after adding the edge of the query.



Return *an array* `answer` *of length* `m` *where* `answer[i]` *is the answer to the* `ith` *query.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/10/25/bexample1.png)

```

**Input:** n = 3, queries = [[5,3],[4,7],[2,3]]
**Output:** [4,5,3]
**Explanation:** The diagrams above show the tree of 23 - 1 nodes. Nodes colored in red describe the nodes in the cycle after adding the edge.
- After adding the edge between nodes 3 and 5, the graph contains a cycle of nodes [5,2,1,3]. Thus answer to the first query is 4. We delete the added edge and process the next query.
- After adding the edge between nodes 4 and 7, the graph contains a cycle of nodes [4,2,1,3,7]. Thus answer to the second query is 5. We delete the added edge and process the next query.
- After adding the edge between nodes 2 and 3, the graph contains a cycle of nodes [2,1,3]. Thus answer to the third query is 3. We delete the added edge.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/10/25/aexample2.png)

```

**Input:** n = 2, queries = [[1,2]]
**Output:** [2]
**Explanation:** The diagram above shows the tree of 22 - 1 nodes. Nodes colored in red describe the nodes in the cycle after adding the edge.
- After adding the edge between nodes 1 and 2, the graph contains a cycle of nodes [2,1]. Thus answer for the first query is 2. We delete the added edge.

```

**Constraints:**
* `2 <= n <= 30`
* `m == queries.length`
* `1 <= m <= 105`
* `queries[i].length == 2`
* `1 <= ai, bi <= 2n - 1`
* `ai != bi`


<br>

### Hints

- Find the distance between nodes “a” and “b”.
- distance(a, b) = depth(a) + depth(b) - 2 * LCA(a, b). Where depth(a) denotes depth from root to node “a” and LCA(a, b) denotes the lowest common ancestor of nodes “a” and “b”.
- To find LCA(a, b), iterate over all ancestors of node “a” and check if it is the ancestor of node “b” too. If so, take the one with maximum depth.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> cycleLengthQueries (int n, vector <vector <int>>& queries) {
      int m = queries.size();
      std::vector <int> ans (m);
      std::unordered_map <int, int> have;
      
      for (int i = 0; i < m; ++i) {
        int u = queries[i][0], v = queries[i][1];
        int l = 0, r = 0;
        bool done = false;
        
        while (u) {
          have[u] = l;
          ++l;
          u /= 2;
        }
        have[u] = l;
        
        while (v) {
          if (have.count(v)) {
            done = true;
            ans[i] = have[v] + r + 1;
            break;
          }
          ++r;
          v /= 2;
        }
        
        if (not done)
          ans[i] = l + r - 1;
        have.clear();
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 3424
- total submissions: 6642
- acceptance rate: 51.6%
- likes: 56
- dislikes: 14

<br>

### Similar Problems

- [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) (Medium)
- [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) (Medium)
- [Path In Zigzag Labelled Binary Tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree) (Medium)

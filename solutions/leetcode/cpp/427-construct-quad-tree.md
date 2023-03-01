# [427] Construct Quad Tree

**[array, divide-and-conquer, tree, matrix]**

### Statement

Given a `n * n` matrix `grid` of `0's` and `1's` only. We want to represent the `grid` with a Quad-Tree.

Return *the root of the Quad-Tree* representing the `grid`.

Notice that you can assign the value of a node to **True** or **False** when `isLeaf` is **False**, and both are **accepted** in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

* `val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
* `isLeaf`: True if the node is leaf node on the tree or False if the node has the four children.



```

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```


We can construct a Quad-Tree from a two-dimensional area using the following steps:

1. If the current grid has the same value (i.e all `1's` or all `0's`) set `isLeaf` True and set `val` to the value of the grid and set the four children to Null and stop.
2. If the current grid has different values, set `isLeaf` to False and set `val` to any value and divide the current grid into four sub-grids as shown in the photo.
3. Recurse for each of the children with the proper sub-grid.


![](https://assets.leetcode.com/uploads/2020/02/11/new_top.png)
If you want to know more about the Quad-Tree, you can refer to the [wiki](https://en.wikipedia.org/wiki/Quadtree).

**Quad-Tree format:**

The output represents the serialized format of a Quad-Tree using level order traversal, where `null` signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list `[isLeaf, val]`.

If the value of `isLeaf` or `val` is True we represent it as **1** in the list `[isLeaf, val]` and if the value of `isLeaf` or `val` is False we represent it as **0**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/02/11/grid1.png)

```

**Input:** grid = [[0,1],[1,0]]
**Output:** [[0,1],[1,0],[1,1],[1,1],[1,0]]
**Explanation:** The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
![](https://assets.leetcode.com/uploads/2020/02/12/e1tree.png)

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/02/12/e2mat.png)

```

**Input:** grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
**Output:** [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
**Explanation:** All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
![](https://assets.leetcode.com/uploads/2020/02/12/e2tree.png)

```

**Constraints:**
* `n == grid.length == grid[i].length`
* `n == 2^x` where `0 <= x <= 6`


<br />

### Hints

None

<br />

### Solution

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
  public:
    Node* construct (vector <vector <int>>& grid) {
      int n = grid.size();

      auto dfs = [&] (auto self, int l, int r, int u, int d) -> Node* {
        Node* node = new Node(grid[u][l], true);

        if (l == r and u == d)
          return node;

        bool has_one = false, has_zero = false;
        
        for (int i = u; i <= d; ++i) {
          for (int j = l; j <= r; ++j) {
            if (grid[i][j] == 1)
              has_one = true;
            else
              has_zero = true;
          }
        }

        if (has_one and has_zero) {
          node->isLeaf = false;
          node->topLeft = self(self, l, (l + r) / 2, u, (u + d) / 2);
          node->topRight = self(self, (l + r) / 2 + 1, r, u, (u + d) / 2);
          node->bottomLeft = self(self, l, (l + r) / 2, (u + d) / 2 + 1, d);
          node->bottomRight = self(self, (l + r) / 2 + 1, r, (u + d) / 2 + 1, d);
        }

        return node;
      };

      return dfs(dfs, 0, n - 1, 0, n - 1);
    }
};
```

<br />

### Statistics

- total accepted: 79185
- total submissions: 108991
- acceptance rate: 72.7%
- likes: 1061
- dislikes: 1465

<br />

### Similar Problems

None

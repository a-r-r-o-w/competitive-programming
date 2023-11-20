# [1104] Path In Zigzag Labelled Binary Tree

**[math, tree, binary-tree]**

### Statement

In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

![](https://assets.leetcode.com/uploads/2019/06/24/tree.png)

Given the `label` of a node in this tree, return the labels in the path from the root of the tree to thenode with that `label`.


**Example 1:**

```

**Input:** label = 14
**Output:** [1,3,4,14]

```

**Example 2:**

```

**Input:** label = 26
**Output:** [1,2,6,10,26]

```

**Constraints:**
* `1 <= label <= 10^6`


<br />

### Hints

- Based on the label of the current node, find what the label must be for the parent of that node.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> pathInZigZagTree (int label) {
      if (label == 1)
        return {label};
      
      int levels = 0;

      for (int i = label; i > 0; i /= 2)
        ++levels;
      
      --levels;
      int parent_left = 1 << (levels - 1), parent_right = (1 << levels) - 1;
      std::vector <int> path = {label};

      if (levels & 1)
        label = parent_right * 2 + 1 - (label - parent_left * 2);

      while (levels--) {
        if (levels % 2 == 0) {
          path.push_back(label / 2);
        }
        else {
          int offset = label / 2 - parent_left;
          path.push_back(parent_right - offset);
        }
        label /= 2;
        parent_left /= 2;
        parent_right /= 2;
      }

      std::reverse(path.begin(), path.end());

      return path;
    }
};
```

<br />

### Statistics

- total accepted: 38307
- total submissions: 51034
- acceptance rate: 75.1%
- likes: 1260
- dislikes: 292

<br />

### Similar Problems

- [Cycle Length Queries in a Tree](https://leetcode.com/problems/cycle-length-queries-in-a-tree) (Hard)

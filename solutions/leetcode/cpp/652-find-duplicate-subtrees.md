# [652] Find Duplicate Subtrees

**[hash-table, tree, depth-first-search, binary-tree]**

### Statement

Given the `root`of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/16/e1.jpg)

```

**Input:** root = [1,2,3,4,null,2,4,null,null,4]
**Output:** [[2,4],[4]]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/08/16/e2.jpg)

```

**Input:** root = [2,1,1]
**Output:** [[1]]

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/08/16/e33.jpg)

```

**Input:** root = [2,2,2,3,null,3,null]
**Output:** [[2,3],[3]]

```

**Constraints:**
* The number of the nodes in the tree will be in the range `[1, 5000]`
* `-200 <= Node.val <= 200`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    std::vector <TreeNode*> findDuplicateSubtrees (TreeNode* root) {
      std::unordered_map <std::string, std::vector <TreeNode*>> map;
      std::vector <TreeNode*> dups;

      auto serialize = [&] (auto self, TreeNode* node, std::unordered_map <std::string, std::vector <TreeNode*>> &map) -> std::string {
        if (node == nullptr)
          return "";
        
        std::string s = "(" + self(self, node->left, map) + std::to_string(node->val) + self(self, node->right, map) + ")";
        map[s].push_back(node);
        
        return s;
      };
      
      serialize(root, map);
      
      for (auto &[p, q]: map)
        if ((int)q.size() > 1)
          dups.push_back(it->second[0]);
      return dups;
    }
};
```

<br />

### Statistics

- total accepted: 225454
- total submissions: 382489
- acceptance rate: 58.9%
- likes: 5139
- dislikes: 411

<br />

### Similar Problems

- [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree) (Hard)
- [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst) (Medium)
- [Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree) (Easy)
- [Delete Duplicate Folders in System](https://leetcode.com/problems/delete-duplicate-folders-in-system) (Hard)

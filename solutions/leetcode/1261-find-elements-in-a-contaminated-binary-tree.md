# [1261] Find Elements in a Contaminated Binary Tree

**[hash-table, tree, depth-first-search, breadth-first-search, design, binary-tree]**

### Statement

Given a binary tree with the following rules:

1. `root.val == 0`
2. If `treeNode.val == x` and `treeNode.left != null`, then `treeNode.left.val == 2 * x + 1`
3. If `treeNode.val == x` and `treeNode.right != null`, then `treeNode.right.val == 2 * x + 2`



Now the binary tree is contaminated, which means all `treeNode.val` have been changed to `-1`.

Implement the `FindElements` class:

* `FindElements(TreeNode* root)` Initializes the object with a contaminated binary tree and recovers it.
* `bool find(int target)` Returns `true` if the `target` value exists in the recovered binary tree.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4-1.jpg)

```

**Input**
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
**Output**
[null,false,true]
**Explanation**
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4.jpg)

```

**Input**
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
**Output**
[null,true,true,false]
**Explanation**
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

**Example 3:**
![](https://assets.leetcode.com/uploads/2019/11/07/untitled-diagram-4-1-1.jpg)

```

**Input**
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
**Output**
[null,true,false,false,true]
**Explanation**
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True

```

**Constraints:**
* `TreeNode.val == -1`
* The height of the binary tree is less than or equal to `20`
* The total number of nodes is between `[1, 104]`
* Total calls of `find()` is between `[1, 104]`
* `0 <= target <= 106`


<br>

### Hints

- Use DFS to traverse the binary tree and recover it.
- Use a hashset to store TreeNode.val for finding.

<br>

### Solution

**DFS**

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

class FindElements {
  public:
    std::unordered_set <int> have;
  
    FindElements (TreeNode* root) {
      auto dfs = [&] (auto self, TreeNode* node, int value) -> void {
        if (node == nullptr)
          return;
        node->val = value;
        have.insert(value);
        self(self, node->left, 2 * value + 1);
        self(self, node->right, 2 * value + 2);
      };
      
      dfs(dfs, root, 0);
    }
    
    bool find (int target) {
      return have.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```

**BFS**

```cpp
class FindElements {
  public:
    std::unordered_set <int> have;
  
    FindElements (TreeNode* root) {
      std::queue <TreeNode*> q;
      root->val = 0;
      q.push(root);
      
      while (!q.empty()) {
        auto u = q.front();
        q.pop();
        have.insert(u->val);
        
        if (u->left != nullptr) {
          u->left->val = 2 * u->val + 1;
          q.push(u->left);
        }
        
        if (u->right != nullptr) {
          u->right->val = 2 * u->val + 2;
          q.push(u->right);
        }
      }
    }
    
    bool find (int target) {
      return have.count(target);
    }
};
```

**Sorting instead of hash set**

```cpp
class FindElements {
  public:
    std::vector <int> have;
  
    FindElements (TreeNode* root) {
      have.reserve(10000);
      
      std::queue <TreeNode*> q;
      root->val = 0;
      q.push(root);
      
      while (!q.empty()) {
        auto u = q.front();
        q.pop();
        have.push_back(u->val);
        
        if (u->left != nullptr) {
          u->left->val = 2 * u->val + 1;
          q.push(u->left);
        }
        
        if (u->right != nullptr) {
          u->right->val = 2 * u->val + 2;
          q.push(u->right);
        }
      }
      
      std::sort(have.begin(), have.end());
    }
    
    bool find (int target) {
      return *std::lower_bound(have.begin(), have.end(), target) == target;
    }
};
```

<br>

### Statistics

- total accepted: 46724
- total submissions: 61708
- acceptance rate: 75.7%
- likes: 670
- dislikes: 84

<br>

### Similar Problems

None

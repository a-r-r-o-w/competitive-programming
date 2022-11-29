# [2476] Closest Nodes Queries in a Binary Search Tree



### Statement

You are given the `root` of a **binary search tree** and an array `queries` of size `n` consisting of positive integers.

Find a **2D** array `answer` of size `n` where `answer[i] = [mini, maxi]`:

* `mini` is the **largest** value in the tree that is smaller than or equal to `queries[i]`. If a such value does not exist, add `-1` instead.
* `maxi` is the **smallest** value in the tree that is greater than or equal to `queries[i]`. If a such value does not exist, add `-1` instead.



Return *the array* `answer`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/09/28/bstreeedrawioo.png)

```

**Input:** root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
**Output:** [[2,2],[4,6],[15,-1]]
**Explanation:** We answer the queries in the following way:
- The largest number that is smaller or equal than 2 in the tree is 2, and the smallest number that is greater or equal than 2 is still 2. So the answer for the first query is [2,2].
- The largest number that is smaller or equal than 5 in the tree is 4, and the smallest number that is greater or equal than 5 is 6. So the answer for the second query is [4,6].
- The largest number that is smaller or equal than 16 in the tree is 15, and the smallest number that is greater or equal than 16 does not exist. So the answer for the third query is [15,-1].

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/09/28/bstttreee.png)

```

**Input:** root = [4,null,9], queries = [3]
**Output:** [[-1,4]]
**Explanation:** The largest number that is smaller or equal to 3 in the tree does not exist, and the smallest number that is greater or equal to 3 is 4. So the answer for the query is [-1,4].

```

**Constraints:**
* The number of nodes in the tree is in the range `[2, 105]`.
* `1 <= Node.val <= 106`
* `n == queries.length`
* `1 <= n <= 105`
* `1 <= queries[i] <= 106`


<br>

### Hints

- Try to first convert the tree into a sorted array.
- How do you solve each query in O(log(n)) time using the array of the tree?

<br>

### Solution

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

class Solution {
  public:
    vector <vector <int>> closestNodes (TreeNode* root, vector <int>& queries) {
      int n = queries.size();
      std::vector <int> have;
      
      auto dfs = [&] (auto self, TreeNode *node) -> void {
        if (node == nullptr)
          return;
        self(self, node->left);
        have.push_back(node->val);
        self(self, node->right);
      };
      
      dfs(dfs, root);
      
      std::vector <std::vector <int>> ans (n);
      
      for (int i = 0; i < n; ++i) {
        int q = queries[i];
        auto l = std::upper_bound(have.begin(), have.end(), q);
        auto r = std::lower_bound(have.begin(), have.end(), q);
        int min = -1, max = -1;
        
        if (l != have.begin())
          min = *(l - 1);
        if (r != have.end())
          max = *r;
        
        ans[i] = {min, max};
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 6808
- total submissions: 19424
- acceptance rate: 35.0%
- likes: 66
- dislikes: 39

<br>

### Similar Problems

- [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value) (Easy)
- [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii) (Hard)
- [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree) (Easy)

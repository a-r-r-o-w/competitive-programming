# [109] Convert Sorted List to Binary Search Tree

**[linked-list, divide-and-conquer, tree, binary-search-tree, binary-tree]**

### Statement

Given the `head` of a singly linked list where elements are sorted in **ascending order**, convert *it to a* ***height-balanced*** *binary search tree*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

```

**Input:** head = [-10,-3,0,5,9]
**Output:** [0,-3,9,-10,null,5]
**Explanation:** One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

```

**Example 2:**

```

**Input:** head = []
**Output:** []

```

**Constraints:**
* The number of nodes in `head` is in the range `[0, 2 * 10^4]`.
* `-10^5 <= Node.val <= 10^5`


<br />

### Hints

None

<br />

### Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST (ListNode* head) {
      if (head == nullptr)
        return nullptr;
      if (head->next == nullptr)
        return new TreeNode(head->val);
      
      ListNode *fast = head->next, *slow = head;

      while (fast->next != nullptr and fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      }

      ListNode *mid = slow->next;
      TreeNode *root = new TreeNode(mid->val);

      slow->next = nullptr;
      root->left = sortedListToBST(head);
      root->right = sortedListToBST(mid->next);
      return root;
    }
}
```

<br />

### Statistics

- total accepted: 453680
- total submissions: 762717
- acceptance rate: 59.5%
- likes: 6446
- dislikes: 140

<br />

### Similar Problems

- [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) (Easy)
- [Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions) (Medium)

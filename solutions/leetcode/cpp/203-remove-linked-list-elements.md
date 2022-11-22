# [203] Remove Linked List Elements

**[linked-list, recursion]**

### Statement

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg)

```

**Input:** head = [1,2,6,3,4,5,6], val = 6
**Output:** [1,2,3,4,5]

```

**Example 2:**

```

**Input:** head = [], val = 1
**Output:** []

```

**Example 3:**

```

**Input:** head = [7,7,7,7], val = 7
**Output:** []

```

**Constraints:**
* The number of nodes in the list is in the range `[0, 10^4]`.
* `1 <= Node.val <= 50`
* `0 <= val <= 50`


<br>

### Hints

None

<br>

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

class Solution {
  public:
    ListNode* removeElements (ListNode* head, int val) {
      ListNode dummy (-1, head), *node = &dummy, *prev = nullptr;
      
      while (node != nullptr) {
        ListNode *free = nullptr;
        if (node->val == val) {
          prev->next = node->next;
          free = node;
        }
        else
          prev = node;
        node = node->next;
        delete free;
      }
      
      return dummy.next;
    }
};
```

<br>

### Statistics

- total accepted: 790761
- total submissions: 1780314
- acceptance rate: 44.4%
- likes: 5852
- dislikes: 181

<br>

### Similar Problems

- [Remove Element](https://leetcode.com/problems/remove-element) (Easy)
- [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) (Medium)
- [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list) (Medium)

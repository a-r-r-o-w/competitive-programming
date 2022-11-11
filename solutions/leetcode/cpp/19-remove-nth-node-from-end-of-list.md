# [19] Remove Nth Node From End of List

**[linked-list, two-pointers]**

### Statement

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```

**Input:** head = [1,2,3,4,5], n = 2
**Output:** [1,2,3,5]

```

**Example 2:**

```

**Input:** head = [1], n = 1
**Output:** []

```

**Example 3:**

```

**Input:** head = [1,2], n = 1
**Output:** [1]

```

**Constraints:**
* The number of nodes in the list is `sz`.
* `1 <= sz <= 30`
* `0 <= Node.val <= 100`
* `1 <= n <= sz`


**Follow up:** Could you do this in one pass?

<br>

### Hints

- Maintain two pointers and update one with a delay of n steps.

<br>

### Solution

Two pass

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
    ListNode* removeNthFromEnd (ListNode* head, int n) {
      int count = 0;
      ListNode* node = head;
      
      while (node != nullptr) {
        node = node->next;
        ++count;
      }
      
      int r = count - n;
      
      if (r == 0) {
        ListNode* r = head->next;
        delete head;
        return r;
      }
      
      ListNode* prev = nullptr;
      node = head;
      
      while (r--) {
        prev = node;
        node = node->next;
      }
      
      prev->next = node->next;
      delete node;
      
      return head;
    }
};
```

One pass

```cpp
class Solution {
  public:
    ListNode* removeNthFromEnd (ListNode* head, int n) {
      ListNode *slow = head, *fast = head;
      
      for (int i = 0; i < n; ++i)
        fast = fast->next;
      
      if (fast == nullptr) {
        ListNode *r = slow->next;
        delete slow;
        return r;
      }
      
      ListNode* prev = nullptr;
      
      while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
      }
      
      prev->next = slow->next;
      delete slow;
      
      return head;
    }
};
```

<br>

### Statistics

- total accepted: 1620488
- total submissions: 4137958
- acceptance rate: 39.2%
- likes: 12221
- dislikes: 529

<br>

### Similar Problems

- [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) (Medium)
- [Delete N Nodes After M Nodes of a Linked List](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list) (Easy)
- [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list) (Medium)

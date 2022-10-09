# [92] Reverse Linked List II

**[linked-list]**

### Statement

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return *the reversed list*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

```

**Input:** head = [1,2,3,4,5], left = 2, right = 4
**Output:** [1,4,3,2,5]

```

**Example 2:**

```

**Input:** head = [5], left = 1, right = 1
**Output:** [5]

```

**Constraints:**
* The number of nodes in the list is `n`.
* `1 <= n <= 500`
* `-500 <= Node.val <= 500`
* `1 <= left <= right <= n`


**Follow up:** Could you do it in one pass?

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
  ListNode* reverseBetween (ListNode *head, int left, int right) {
      ListNode temp_head (0, head);
      ListNode *current = nullptr, *previous = &temp_head;
      
      for (int i = 0; i < left - 1; ++i)
        previous = previous->next;
      
      current = previous->next;
      
      for (int i = 0; i < right - left; ++i) {
        ListNode* temp = previous->next;
        previous->next = current->next;
        current->next = current->next->next;
        previous->next->next = temp;
      }
      
      return temp_head.next;
    }
};
```

<br>

### Statistics

- total accepted: 523227
- total submissions: 1178977
- acceptance rate: 44.4%
- likes: 7032
- dislikes: 315

<br>

### Similar Problems

- [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) (Easy)

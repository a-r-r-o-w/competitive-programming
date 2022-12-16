# [328] Odd Even Linked List

**[linked-list]**

### Statement

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problemin `O(1)`extra space complexity and `O(n)` time complexity.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

```

**Input:** head = [1,2,3,4,5]
**Output:** [1,3,5,2,4]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

```

**Input:** head = [2,1,3,5,6,4,7]
**Output:** [2,3,6,7,1,5,4]

```

**Constraints:**
* The number of nodes in the linked list is in the range `[0, 104]`.
* `-106 <= Node.val <= 106`


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
    ListNode* oddEvenList (ListNode *head) {
      if (head == nullptr)
        return head;
      
      ListNode *odd = head, *even_front = head->next, *even_back = head->next;

      while (even_back != nullptr and even_back->next != nullptr) {
        ListNode *t = even_back->next->next;
        odd->next = even_back->next;
        even_back->next->next = even_front;
        even_back->next = t;
        odd = odd->next;
        even_back = even_back->next;
      }

      return head;
    }
};
```

<br>

### Statistics

- total accepted: 633245
- total submissions: 1044464
- acceptance rate: 60.6%
- likes: 6935
- dislikes: 412

<br>

### Similar Problems

- [Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts) (Medium)

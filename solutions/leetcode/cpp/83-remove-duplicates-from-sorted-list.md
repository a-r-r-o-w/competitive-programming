# [83] Remove Duplicates from Sorted List

**[linked-list]**

### Statement

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```

**Input:** head = [1,1,2]
**Output:** [1,2]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```

**Input:** head = [1,1,2,3,3]
**Output:** [1,2,3]

```

**Constraints:**
* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.


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
    ListNode* deleteDuplicates (ListNode* head) {
      const int inf32 = 1 << 30;
      
      int prev_val = -inf32;
      ListNode dummy (inf32, head), *node = &dummy, *prev = nullptr;
      
      while (node != nullptr) {
        if (node->val == prev_val) {
          ListNode *del = node;
          prev->next = node->next;
          node = node->next;
          delete del;
        }
        else {
          prev_val = node->val;
          prev = node;
          node = node->next;
        }
      }
      
      return dummy.next;
    }
};
```

<br>

### Statistics

- total accepted: 977611
- total submissions: 1967281
- acceptance rate: 49.7%
- likes: 5749
- dislikes: 204

<br>

### Similar Problems

- [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) (Medium)
- [Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list) (Medium)

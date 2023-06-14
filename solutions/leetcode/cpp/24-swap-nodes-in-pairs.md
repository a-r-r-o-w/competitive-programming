# [24] Swap Nodes in Pairs

**[linked-list, recursion]**

### Statement

Given alinked list, swap every two adjacent nodes and return its head. You must solve the problem withoutmodifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

```

**Input:** head = [1,2,3,4]
**Output:** [2,1,4,3]

```

**Example 2:**

```

**Input:** head = []
**Output:** []

```

**Example 3:**

```

**Input:** head = [1]
**Output:** [1]

```

**Constraints:**
* The number of nodes in thelistis in the range `[0, 100]`.
* `0 <= Node.val <= 100`


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

class Solution {
  public:
    ListNode* swapPairs (ListNode* head) {
      if (head == nullptr or head->next == nullptr)
        return head;
      
      auto swap = [] (ListNode *node) -> ListNode* {
        if (node == nullptr or node->next == nullptr)
          return node;
        auto first = node, second = node->next;
        first->next = second->next;
        second->next = first;
        return second;
      };

      head = swap(head);
      
      ListNode *node = head->next->next, *prev = head->next;

      while (node != nullptr) {
        node = swap(node);
        prev->next = node;
        prev = node->next;
        if (node->next != nullptr)
          node = node->next->next;
        else
          break;
      }

      return head;
    }
};
```

<br />

### Statistics

- total accepted: 1146006
- total submissions: 1836743
- acceptance rate: 62.4%
- likes: 10382
- dislikes: 383

<br />

### Similar Problems

- [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) (Hard)
- [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) (Medium)

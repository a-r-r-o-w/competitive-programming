# [86] Partition List

**[linked-list, two-pointers]**

### Statement

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```

**Input:** head = [1,4,3,2,5,2], x = 3
**Output:** [1,2,2,4,3,5]

```

**Example 2:**

```

**Input:** head = [2,1], x = 2
**Output:** [1,2]

```

**Constraints:**
* The number of nodes in the list is in the range `[0, 200]`.
* `-100 <= Node.val <= 100`
* `-200 <= x <= 200`


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
    ListNode* partition(ListNode* head, int x) {
      ListNode *first = nullptr, *second = nullptr, *node = head, *start = nullptr;
      ListNode *first_head = nullptr, *second_head = nullptr;

      while (node != nullptr) {
        auto next = node->next;
        node->next = nullptr;
        if (node->val < x) {
          if (first_head == nullptr)
            first_head = node;
          if (first == nullptr)
            first = node;
          else {
            first->next = node;
            first = first->next;
          }
        }
        if (node->val >= x) {
          if (second_head == nullptr)
            second_head = node;
          if (second == nullptr)
            second = node;
          else {
            second->next = node;
            second = second->next;
          }
        }
        node = next;
      }

      if (second_head != nullptr)
        second->next = nullptr;
      if (first_head != nullptr) {
        first->next = second_head;
        return first_head;
      }
      else
        return second_head;
    }
};
```

<br />

### Statistics

- total accepted: 502451
- total submissions: 934098
- acceptance rate: 53.8%
- likes: 6291
- dislikes: 705

<br />

### Similar Problems

- [Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot) (Medium)

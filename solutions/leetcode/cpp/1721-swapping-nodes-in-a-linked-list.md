# [1721] Swapping Nodes in a Linked List

**[linked-list, two-pointers]**

### Statement

You are given the `head` of a linked list, and an integer `k`.

Return *the head of the linked list after **swapping** the values of the* `k^th` *node from the beginning and the* `k^th` *node from the end (the list is **1-indexed**).*
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```

**Input:** head = [1,2,3,4,5], k = 2
**Output:** [1,4,3,2,5]

```

**Example 2:**

```

**Input:** head = [7,9,6,6,7,8,3,0,9,5], k = 5
**Output:** [7,9,6,6,8,7,3,0,9,5]

```

**Constraints:**
* The number of nodes in the list is `n`.
* `1 <= k <= n <= 10^5`
* `0 <= Node.val <= 100`


<br />

### Hints

- We can transform the linked list to an array this should ease things up
- After transforming the linked list to an array it becomes as easy as swapping two integers in an array then rebuilding the linked list

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
    ListNode* swapNodes (ListNode* head, int k) {
      ListNode *node = head;
      ListNode *front = nullptr, *back = nullptr;
      int count = 0, index = 0;

      while (node != nullptr) {
        ++count;
        node = node->next;
      }
      node = head;
      while (node != nullptr) {
        ++index;
        if (index == k)
          front = node;
        if (index == count - k + 1)
          back = node;
        node = node->next;
      }
      std::swap(front->val, back->val);

      return head;
    }
};
```

<br />

### Statistics

- total accepted: 211340
- total submissions: 315415
- acceptance rate: 67.0%
- likes: 3789
- dislikes: 127

<br />

### Similar Problems

- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) (Medium)
- [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) (Medium)
- [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) (Hard)

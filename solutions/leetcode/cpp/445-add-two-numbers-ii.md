# [445] Add Two Numbers II

**[linked-list, math, stack]**

### Statement

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg)

```

**Input:** l1 = [7,2,4,3], l2 = [5,6,4]
**Output:** [7,8,0,7]

```

**Example 2:**

```

**Input:** l1 = [2,4,3], l2 = [5,6,4]
**Output:** [8,0,7]

```

**Example 3:**

```

**Input:** l1 = [0], l2 = [0]
**Output:** [0]

```

**Constraints:**
* The number of nodes in each linked list is in the range `[1, 100]`.
* `0 <= Node.val <= 9`
* It is guaranteed that the list represents a number that does not have leading zeros.


**Follow up:**Could you solve it without reversing the input lists?

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
    ListNode* addTwoNumbers (ListNode *l1, ListNode *l2) {
      std::stack <int> s1, s2;
      ListNode *node;

      node = l1;
      while (node != nullptr) {
        s1.push(node->val);
        node = node->next;
      }
      node = l2;
      while (node != nullptr) {
        s2.push(node->val);
        node = node->next;
      }

      ListNode *head = nullptr;
      int carry = 0;
      
      while (!s1.empty() and !s2.empty()) {
        int x = s1.top(), y = s2.top();
        s1.pop();
        s2.pop();
        int sum = x + y + carry;
        carry = sum / 10;
        ListNode *new_node = new ListNode(sum % 10, head);
        head = new_node;
      }
      while (!s1.empty()) {
        int x = s1.top();
        s1.pop();
        int sum = x + carry;
        carry = sum / 10;
        ListNode *new_node = new ListNode(sum % 10, head);
        head = new_node;
      }
      while (!s2.empty()) {
        int x = s2.top();
        s2.pop();
        int sum = x + carry;
        carry = sum / 10;
        ListNode *new_node = new ListNode(sum % 10, head);
        head = new_node;
      }
      if (carry > 0) {
        ListNode *new_node = new ListNode(carry, head);
        head = new_node;
      }

      return head;
    }
};
```

<br />

### Statistics

- total accepted: 418552
- total submissions: 688757
- acceptance rate: 60.8%
- likes: 5348
- dislikes: 264

<br />

### Similar Problems

- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) (Medium)
- [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists) (Medium)

# [2816] Double a Number Represented as a Linked List



### Statement

You are given the `head` of a **non-empty** linked list representing a non-negative integer without leading zeroes.

Return *the* `head` *of the linked list after **doubling** it*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2023/05/28/example.png)

```

**Input:** head = [1,8,9]
**Output:** [3,7,8]
**Explanation:** The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2023/05/28/example2.png)

```

**Input:** head = [9,9,9]
**Output:** [1,9,9,8]
**Explanation:** The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 

```

**Constraints:**
* The number of nodes in the list is in the range `[1, 10^4]`
* `0 <= Node.val <= 9`
* The input is generated such that the list represents a number that does not have leading zeros, except the number `0` itself.


<br />

### Hints

- Traverse the linked list from the least significant digit to the most significant digit and multiply each node's value by 2
- Handle any carry-over digits that may arise during the doubling process.
- If there is a carry-over digit on the most significant digit, create a new node with that value and point it to the start of the given linked list and return it.

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
    ListNode* doubleIt (ListNode* head) {
      std::stack <ListNode*> s;
      ListNode *node = head;
      
      while (node != nullptr) {
        s.push(node);
        node = node->next;
      }
      
      int carry = 0;
      while (!s.empty()) {
        ListNode *top = s.top();
        s.pop();
        int value = 2 * top->val + carry;
        carry = value / 10;
        value %= 10;
        top->val = value;
      }
      
      if (carry)
        head = new ListNode(carry, head);
      
      return head;
    }
};
```

<br />

### Statistics

- total accepted: 14961
- total submissions: 34202
- acceptance rate: 43.7%
- likes: 84
- dislikes: 0

<br />

### Similar Problems

- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) (Medium)
- [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list) (Medium)

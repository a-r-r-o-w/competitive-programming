# [2] Add Two Numbers

**[linked-list, math, recursion]**

### Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sumas a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```

**Input:** l1 = [2,4,3], l2 = [5,6,4]
**Output:** [7,0,8]
**Explanation:** 342 + 465 = 807.

```

**Example 2:**

```

**Input:** l1 = [0], l2 = [0]
**Output:** [0]

```

**Example 3:**

```

**Input:** l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
**Output:** [8,9,9,9,0,0,0,1]

```

**Constraints:**
* The number of nodes in each linked list is in the range `[1, 100]`.
* `0 <= Node.val <= 9`
* It is guaranteed that the list represents a number that does not have leading zeros.


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
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
      ListNode* sum = nullptr;
      ListNode* head = nullptr;
      bool carry = false;
      
      while (l1 != nullptr and l2 != nullptr) {
        if (sum == nullptr) {
          int s = l1->val + l2->val + carry;
          carry = s / 10;
          s = s % 10;
          
          sum = new ListNode(s);
          head = sum;
        }
        else {
          int s = l1->val + l2->val + carry;
          carry = s / 10;
          s = s % 10;
          
          sum->next = new ListNode(s);
          sum = sum->next;
        }
        
        l1 = l1->next;
        l2 = l2->next;
      }
      
      while (l1 != nullptr) {
        int s = l1->val + carry;
        carry = s / 10;
        s = s % 10;

        sum->next = new ListNode(s);
        sum = sum->next;
        l1 = l1->next;
      }
      
      while (l2 != nullptr) {
        int s = l2->val + carry;
        carry = s / 10;
        s = s % 10;

        sum->next = new ListNode(s);
        sum = sum->next;
        l2 = l2->next;
      }
      
      if (carry)
        sum->next = new ListNode(1);
      
      return head;
    }
};
```

<br>

### Statistics

- total accepted: 2797638
- total submissions: 7216461
- acceptance rate: 38.8%
- likes: 18611
- dislikes: 3788

<br>

### Similar Problems

- [Multiply Strings](https://leetcode.com/problems/multiply-strings) (Medium)
- [Add Binary](https://leetcode.com/problems/add-binary) (Easy)
- [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) (Medium)
- [Add Strings](https://leetcode.com/problems/add-strings) (Easy)
- [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii) (Medium)
- [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer) (Easy)
- [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists) (Medium)

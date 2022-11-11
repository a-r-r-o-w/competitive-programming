# [206] Reverse Linked List

**[linked-list, recursion]**

### Statement

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```

**Input:** head = [1,2,3,4,5]
**Output:** [5,4,3,2,1]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```

**Input:** head = [1,2]
**Output:** [2,1]

```

**Example 3:**

```

**Input:** head = []
**Output:** []

```

**Constraints:**
* The number of nodes in the list is the range `[0, 5000]`.
* `-5000 <= Node.val <= 5000`


**Follow up:** A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList (ListNode* head) {
      ListNode *prev = nullptr, *current = head;
      
      while (current != nullptr) {
        auto t = current->next;
        current->next = prev;
        prev = current;
        current = t;
      }
      
      return prev;
    }
};
```

<br>

### Statistics

- total accepted: 2483837
- total submissions: 3455814
- acceptance rate: 71.9%
- likes: 14322
- dislikes: 246

<br>

### Similar Problems

- [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) (Medium)
- [Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down) (Medium)
- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) (Easy)
- [Reverse Nodes in Even Length Groups](https://leetcode.com/problems/reverse-nodes-in-even-length-groups) (Medium)
- [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list) (Medium)

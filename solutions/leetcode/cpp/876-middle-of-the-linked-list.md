# [876] Middle of the Linked List

**[linked-list, two-pointers]**

### Statement

Given the `head` of a singly linked list, return *the middle node of the linked list*.

If there are two middle nodes, return **the second middle** node.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

```

**Input:** head = [1,2,3,4,5]
**Output:** [3,4,5]
**Explanation:** The middle node of the list is node 3.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

```

**Input:** head = [1,2,3,4,5,6]
**Output:** [4,5,6]
**Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one.

```

**Constraints:**
* The number of nodes in the list is in the range `[1, 100]`.
* `1 <= Node.val <= 100`


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
    ListNode* middleNode (ListNode* head) {
      ListNode *slow = head, *fast = head;
      
      while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      }
      
      return slow;
    }
};
```

<br>

### Statistics

- total accepted: 880601
- total submissions: 1196648
- acceptance rate: 73.6%
- likes: 6823
- dislikes: 182

<br>

### Similar Problems

- [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list) (Medium)
- [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list) (Medium)

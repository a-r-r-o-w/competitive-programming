# [2095] Delete the Middle Node of a Linked List

**[linked-list, two-pointers]**

### Statement

You are given the `head` of a linked list. **Delete** the **middle node**, and return *the* `head` *of the modified linked list*.

The **middle node** of a linked list of size `n` is the `⌊n / 2⌋th` node from the **start** using **0-based indexing**, where `⌊x⌋` denotes the largest integer less than or equal to `x`.

* For `n` = `1`, `2`, `3`, `4`, and `5`, the middle nodes are `0`, `1`, `1`, `2`, and `2`, respectively.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png)

```

**Input:** head = [1,3,4,7,1,2,6]
**Output:** [1,3,4,1,2,6]
**Explanation:**
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png)

```

**Input:** head = [1,2,3,4]
**Output:** [1,2,4]
**Explanation:**
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png)

```

**Input:** head = [2,1]
**Output:** [2]
**Explanation:**
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

**Constraints:**
* The number of nodes in the list is in the range `[1, 105]`.
* `1 <= Node.val <= 105`


<br>

### Hints

- If a point with a speed s moves n units in a given time, a point with speed 2 * s will move 2 * n units at the same time. Can you use this to find the middle node of a linked list?
- If you are given the middle node, the node before it, and the node after it, how can you modify the linked list?

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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    ListNode* deleteMiddle (ListNode* head) {
      if (head->next == nullptr) {
        delete head;
        return nullptr;
      }
      
      ListNode *slow = head, *fast = head, *prev = nullptr;
      
      while (fast != nullptr and fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      
      ListNode *x = prev->next->next;
      delete prev->next;
      prev->next = x;
      
      return head;
    }
};
```

<br>

### Statistics

- total accepted: 92686
- total submissions: 163967
- acceptance rate: 56.5%
- likes: 1565
- dislikes: 32

<br>

### Similar Problems

- [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) (Medium)
- [Reorder List](https://leetcode.com/problems/reorder-list) (Medium)
- [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) (Easy)
- [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) (Easy)

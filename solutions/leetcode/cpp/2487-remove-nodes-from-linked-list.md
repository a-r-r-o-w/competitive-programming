# [2487] Remove Nodes From Linked List

**[linked-list, stack, recursion, monotonic-stack]**

### Statement

You are given the `head` of a linked list.

Remove every node which has a node with a **strictly greater** value anywhere to the right side of it.

Return *the* `head` *of the modified linked list.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/10/02/drawio.png)

```

**Input:** head = [5,2,13,3,8]
**Output:** [13,8]
**Explanation:** The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

```

**Example 2:**

```

**Input:** head = [1,1,1,1]
**Output:** [1,1,1,1]
**Explanation:** Every node has value 1, so no nodes are removed.

```

**Constraints:**
* The number of the nodes in the given list is in the range `[1, 105]`.
* `1 <= Node.val <= 105`


<br>

### Hints

- Iterate on nodes in reversed order.
- When iterating in reversed order, save the maximum value that was passed before.

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
    ListNode* removeNodes (ListNode *head) {
      ListNode pseudo_head (1 << 30, head);
      std::stack <ListNode*> nodes;
      ListNode *node = &pseudo_head;
      
      while (node != nullptr) {
        nodes.push(node);
        node = node->next;
      }
      
      int max = 0;
      
      while (!nodes.empty()) {
        ListNode *top = nodes.top();
        nodes.pop();
        
        if (max > top->val) {
          nodes.top()->next = top->next;
          delete top;
        }
        else
          max = top->val;
      }
      
      return pseudo_head.next;
    }
};
```

<br>

### Statistics

- total accepted: 13138
- total submissions: 18461
- acceptance rate: 71.2%
- likes: 223
- dislikes: 3

<br>

### Similar Problems

- [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) (Easy)
- [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) (Medium)
- [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) (Easy)

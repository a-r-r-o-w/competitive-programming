# [2181] Merge Nodes in Between Zeros

**[linked-list, simulation]**

### Statement

You are given the `head` of a linked list, which contains a series of integers **separated** by `0`'s. The **beginning** and **end** of the linked list will have `Node.val == 0`.

For **every** two consecutive `0`'s, **merge** all the nodes lying in between them into a single node whose value is the **sum** of all the merged nodes. The modified list should not contain any `0`'s.

Return *the* `head` *of the modified linked list*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png)

```

**Input:** head = [0,3,1,0,4,5,2,0]
**Output:** [4,11]
**Explanation:** 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/02/02/ex2-1.png)

```

**Input:** head = [0,1,0,3,0,2,2,0]
**Output:** [1,3,4]
**Explanation:** 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

```

**Constraints:**
* The number of nodes in the list is in the range `[3, 2 * 105]`.
* `0 <= Node.val <= 1000`
* There are **no** two consecutive nodes with `Node.val == 0`.
* The **beginning** and **end** of the linked list have `Node.val == 0`.


<br>

### Hints

- How can you use two pointers to modify the original list into the new list?
- Have a pointer traverse the entire linked list, while another pointer looks at a node that is currently being modified.
- Keep on summing the values of the nodes between the traversal pointer and the modifying pointer until the former comes across a ‘0’. In that case, the modifying pointer is incremented to modify the next node.
- Do not forget to have the next pointer of the final node of the modified list point to null.

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
  
    ListNode* mergeNodes (ListNode* head) {
      auto prev = head;
      auto next = prev->next;
      
      while (next != nullptr) {
        if (next->val != 0)
          prev->val += next->val;
        else {
          prev->next = next->next == nullptr ? nullptr : next;
          prev = next;
        }
        next = next->next;
      }
      
      return head;
    }
};
```

<br>

### Statistics

- total accepted: 42313
- total submissions: 48740
- acceptance rate: 86.8%
- likes: 646
- dislikes: 19

<br>

### Similar Problems

- [Linked List Components](https://leetcode.com/problems/linked-list-components) (Medium)

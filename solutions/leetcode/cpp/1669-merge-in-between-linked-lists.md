# [1669] Merge In Between Linked Lists

**[linked-list]**

### Statement

You are given two linked lists: `list1` and `list2` of sizes `n` and `m` respectively.

Remove `list1`'s nodes from the `a^th` node to the `b^th` node, and put `list2` in their place.

The blue edges and nodes in the following figure indicate the result:
![](https://assets.leetcode.com/uploads/2020/11/05/fig1.png)
*Build the result list and return its head.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex1.png)

```

**Input:** list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
**Output:** [0,1,2,1000000,1000001,1000002,5]
**Explanation:** We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png)

```

**Input:** list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
**Output:** [0,1,1000000,1000001,1000002,1000003,1000004,6]
**Explanation:** The blue edges and nodes in the above figure indicate the result.

```

**Constraints:**
* `3 <= list1.length <= 10^4`
* `1 <= a <= b < list1.length - 1`
* `1 <= list2.length <= 10^4`


<br />

### Hints

- Check which edges need to be changed.
- Let the next node of the (a-1)th node of list1 be the 0-th node in list 2.
- Let the next node of the last node of list2 be the (b+1)-th node in list 1.

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
    ListNode* mergeInBetween (ListNode *list1, int a, int b, ListNode *list2) {
      int index = 0;
      ListNode *prev = nullptr, *current = list1;

      while (index < a) {
        prev = current;
        current = current->next;
        ++index;
      }

      ListNode *start = prev;

      while (index <= b) {
        ListNode *next = current->next;
        delete current;
        current = next;
        ++index;
      }

      start->next = list2;
      while (list2->next != nullptr)
        list2 = list2->next;
      list2->next = current;

      return list1;
    }
};
```

<br />

### Statistics

- total accepted: 67096
- total submissions: 90553
- acceptance rate: 74.1%
- likes: 1227
- dislikes: 157

<br />

### Similar Problems

None

# [21] Merge Two Sorted Lists

**[linked-list, recursion]**

### Statement

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```

**Input:** list1 = [1,2,4], list2 = [1,3,4]
**Output:** [1,1,2,3,4,4]

```

**Example 2:**

```

**Input:** list1 = [], list2 = []
**Output:** []

```

**Example 3:**

```

**Input:** list1 = [], list2 = [0]
**Output:** [0]

```

**Constraints:**
* The number of nodes in both lists is in the range `[0, 50]`.
* `-100 <= Node.val <= 100`
* Both `list1` and `list2` are sorted in **non-decreasing** order.


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
    ListNode* mergeTwoLists (ListNode* list1, ListNode* list2) {
      ListNode head (-(1 << 30)), *end = &head;
      
      while (list1 != nullptr and list2 != nullptr) {
        if (list1->val <= list2->val) {
          end->next = list1;
          list1 = list1->next;
        }
        else {
          end->next = list2;
          list2 = list2->next;
        }
        end = end->next;
      }
      
      end->next = list1 == nullptr ? list2 : list1;
      
      return head.next;
    }
};
```

<br>

### Statistics

- total accepted: 2568908
- total submissions: 4179969
- acceptance rate: 61.5%
- likes: 14614
- dislikes: 1292

<br>

### Similar Problems

- [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) (Hard)
- [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) (Easy)
- [Sort List](https://leetcode.com/problems/sort-list) (Medium)
- [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii) (Medium)
- [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists) (Medium)
- [Longest Common Subsequence Between Sorted Arrays](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays) (Medium)

# [23] Merge k Sorted Lists

**[linked-list, divide-and-conquer, heap-priority-queue, merge-sort]**

### Statement

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*
**Example 1:**

```

**Input:** lists = [[1,4,5],[1,3,4],[2,6]]
**Output:** [1,1,2,3,4,4,5,6]
**Explanation:** The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

```

**Example 2:**

```

**Input:** lists = []
**Output:** []

```

**Example 3:**

```

**Input:** lists = [[]]
**Output:** []

```

**Constraints:**
* `k == lists.length`
* `0 <= k <= 10^4`
* `0 <= lists[i].length <= 500`
* `-10^4 <= lists[i][j] <= 10^4`
* `lists[i]` is sorted in **ascending order**.
* The sum of `lists[i].length` will not exceed `10^4`.


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
    ListNode* mergeKLists (vector <ListNode*>& lists) {
      ListNode dummy, *head = &dummy;
      int k = lists.size();

      while (true) {
        bool have = false;
        int min = 1 << 30;
        ListNode **which = nullptr;

        for (int i = 0; i < k; ++i) {
          if (lists[i] == nullptr)
            continue;
          have = true;
          if (lists[i]->val < min) {
            min = lists[i]->val;
            which = &lists[i];
          }
        }

        if (not have)
          break;
        
        head->next = *which;
        head = head->next;
        *which = (*which)->next;
      }

      return dummy.next;
    }
};
```

<br />

### Statistics

- total accepted: 1563759
- total submissions: 3170020
- acceptance rate: 49.3%
- likes: 16102
- dislikes: 596

<br />

### Similar Problems

- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) (Easy)
- [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) (Medium)
- [Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or) (Medium)

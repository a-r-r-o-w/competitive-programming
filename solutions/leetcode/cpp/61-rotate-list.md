# [61] Rotate List

**[linked-list, two-pointers]**

### Statement

Given the `head` of a linkedlist, rotate the list to the right by `k` places.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

```

**Input:** head = [1,2,3,4,5], k = 2
**Output:** [4,5,1,2,3]

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)

```

**Input:** head = [0,1,2], k = 4
**Output:** [2,0,1]

```

**Constraints:**
* The number of nodes in the list is in the range `[0, 500]`.
* `-100 <= Node.val <= 100`
* `0 <= k <= 2 * 10^9`


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
    ListNode* rotateRight (ListNode* head, int k) {
      if (head == nullptr)
        return head;
      int length = 0;
      ListNode *node = head, *prev = nullptr;

      while (node != nullptr) {
        prev = node;
        node = node->next;
        ++length;
      }
      
      prev->next = head;
      node = head;
      k %= length;

      if (k > 0) {
        for (int i = 0; i < length - k; ++i) {
          prev = node;
          node = node->next;
        }
      }
      
      ListNode *ans = prev->next;
      prev->next = nullptr;
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 708617
- total submissions: 1962046
- acceptance rate: 36.1%
- likes: 7544
- dislikes: 1351

<br />

### Similar Problems

- [Rotate Array](https://leetcode.com/problems/rotate-array) (Medium)
- [Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts) (Medium)

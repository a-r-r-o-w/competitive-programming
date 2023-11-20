# [725] Split Linked List in Parts

**[linked-list]**

### Statement

Given the `head` of a singly linked list and an integer `k`, split the linked list into `k` consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return *an array of the* `k` *parts*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg)

```

**Input:** head = [1,2,3], k = 5
**Output:** [[1],[2],[3],[],[]]
**Explanation:**
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg)

```

**Input:** head = [1,2,3,4,5,6,7,8,9,10], k = 3
**Output:** [[1,2,3,4],[5,6,7],[8,9,10]]
**Explanation:**
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

```

**Constraints:**
* The number of nodes in the list is in the range `[0, 1000]`.
* `0 <= Node.val <= 1000`
* `1 <= k <= 50`


<br />

### Hints

- If there are N nodes in the list, and k parts, then every part has N/k elements, except the first N%k parts have an extra one.

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      std::priority_queue <std::pair <int, ListNode*>> pq;
      std::vector <ListNode*> v(k);
      ListNode *node = head;
      int length = 0;

      while (node != nullptr) {
        ++length;
        node = node->next;
      }

      int size = length / k, remain = length % k;
      node = head;

      for (int i = 0; i < k; ++i) {
        v[i] = node;
        for (int j = 0; j < size + (i < remain) - 1; ++j) {
          if (node != nullptr)
            node = node->next;
        }
        if (node != nullptr) {
          auto next_node = node->next;
          node->next = nullptr;
          node = next_node;
        }
      }

      return v;
    }
}
```

<br />

### Statistics

- total accepted: 130725
- total submissions: 220790
- acceptance rate: 59.2%
- likes: 2802
- dislikes: 256

<br />

### Similar Problems

- [Rotate List](https://leetcode.com/problems/rotate-list) (Medium)
- [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list) (Medium)
- [Split a Circular Linked List](https://leetcode.com/problems/split-a-circular-linked-list) (Medium)

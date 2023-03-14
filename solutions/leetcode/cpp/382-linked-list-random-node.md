# [382] Linked List Random Node

**[linked-list, math, reservoir-sampling, randomized]**

### Statement

Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

Implement the `Solution` class:

* `Solution(ListNode head)` Initializes the object with the head of the singly-linked list `head`.
* `int getRandom()` Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/16/getrand-linked-list.jpg)

```

**Input**
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
**Output**
[null, 1, 3, 2, 2, 3]

**Explanation**
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

```

**Constraints:**
* The number of nodes in the linked list will be in the range `[1, 10^4]`.
* `-10^4 <= Node.val <= 10^4`
* At most `10^4` calls will be made to `getRandom`.


**Follow up:**
* What if the linked list is extremely large and its length is unknown to you?
* Could you solve this efficiently without using extra space?


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
    ListNode *base = nullptr;
    std::mt19937 rng { std::random_device{}() };

  public:
    Solution (ListNode* head) {
      base = head;
    }
    
    int getRandom () {
      ListNode *node = base;
      int index = 0, ans = 0;

      while (node != nullptr) {
        std::uniform_int_distribution <> dist (0, index);
        if (dist(rng) == 0)
          ans = node->val;
        node = node->next;
        ++index;
      }

      return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

<br />

### Statistics

- total accepted: 187573
- total submissions: 307004
- acceptance rate: 61.1%
- likes: 2365
- dislikes: 557

<br />

### Similar Problems

- [Random Pick Index](https://leetcode.com/problems/random-pick-index) (Medium)

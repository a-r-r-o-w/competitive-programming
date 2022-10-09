# [234] Palindrome Linked List

**[linked-list, two-pointers, stack, recursion]**

### Statement

Given the `head` of a singly linked list, return `true` if it is a palindrome.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```

**Input:** head = [1,2,2,1]
**Output:** true

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```

**Input:** head = [1,2]
**Output:** false

```

**Constraints:**
* The number of nodes in the list is in the range `[1, 105]`.
* `0 <= Node.val <= 9`


**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    bool isPalindrome (ListNode* head) {
      ListNode *a = head, *b = head, *prev = nullptr;
      int count = 0;
      
      while (b != nullptr and b->next != nullptr) {
        ++count;
        b = b->next->next;
        
        ListNode* next = a->next;
        a->next = prev;
        prev = a;
        a = next;
      }
      
      int nodes = (b == nullptr ? 2 * count : 2 * count + 1);
      bool okay = true;
      
      if (nodes & 1)
        a = a->next;
      
      while (prev != nullptr) {
        if (a->val != prev->val) {
          okay = false;
          break;
        }
        prev = prev->next;
        a = a->next;
      }
      
      return okay;
    }
};
```

<br>

### Statistics

- total accepted: 1153845
- total submissions: 2369522
- acceptance rate: 48.7%
- likes: 11196
- dislikes: 635

<br>

### Similar Problems

- [Palindrome Number](https://leetcode.com/problems/palindrome-number) (Easy)
- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) (Easy)
- [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) (Easy)
- [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list) (Medium)

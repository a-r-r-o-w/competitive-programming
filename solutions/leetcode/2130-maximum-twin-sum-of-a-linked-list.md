# [2130] Maximum Twin Sum of a Linked List

**[linked-list, two-pointers, stack]**

### Statement

In a linked list of size `n`, where `n` is **even**, the `ith` node (**0-indexed**) of the linked list is known as the **twin** of the `(n-1-i)th` node, if `0 <= i <= (n / 2) - 1`.

* For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.



The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return *the **maximum twin sum** of the linked list*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png)

```

**Input:** head = [5,4,2,1]
**Output:** 6
**Explanation:**
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/12/03/eg2drawio.png)

```

**Input:** head = [4,2,2,3]
**Output:** 7
**Explanation:**
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/12/03/eg3drawio.png)

```

**Input:** head = [1,100000]
**Output:** 100001
**Explanation:**
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

```

**Constraints:**
* The number of nodes in the list is an **even** integer in the range `[2, 105]`.
* `1 <= Node.val <= 105`


<br>

### Hints

- How can "reversing" a part of the linked list help find the answer?
- We know that the nodes of the first half are twins of nodes in the second half, so try dividing the linked list in half and reverse the second half.
- How can two pointers be used to find every twin sum optimally?
- Use two different pointers pointing to the first nodes of the two halves of the linked list. The second pointer will point to the first node of the reversed half, which is the (n-1-i)th node in the original linked list. By moving both pointers forward at the same time, we find all twin sums.

<br>

### Solution

Storing values for each node in an array

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
  
    int pairSum (ListNode* head) {
      std::vector <int> values;
      
      while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
      }
      
      int n = values.size();
      int max = 0;
      
      for (int i = 0; i < n / 2; ++i)
        max = std::max(max, values[i] + values[n - i - 1]);
      
      return max;
    }
};
```

Recursion

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int pairSum (ListNode* head) {
      int max = 0;
      
      auto traverse = [&] (auto self, ListNode* node) -> void {
        if (node == nullptr)
          return;
        self(self, node->next);
        max = std::max(max, node->val + head->val);
        head = head->next;
      };
      
      traverse(traverse, head);
      
      return max;
    }
};
```

Two Pointers

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
  
    int pairSum (ListNode* head) {
      ListNode *slow = head, *fast = head;
      int count = 0;
      int max = 0;
      
      while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        ++count;
      }
      
      ListNode *prev = nullptr;
      
      while (slow != nullptr) {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
      }
      
      while (count--) {
        max = std::max(max, head->val + prev->val);
        head = head->next;
        prev = prev->next;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 54712
- total submissions: 66820
- acceptance rate: 81.9%
- likes: 923
- dislikes: 29

<br>

### Similar Problems

- [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) (Easy)
- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) (Easy)
- [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) (Easy)

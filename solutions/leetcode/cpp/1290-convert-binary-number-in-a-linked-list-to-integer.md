# [1290] Convert Binary Number in a Linked List to Integer

**[linked-list, math]**

### Statement

Given `head` which is a reference node to a singly-linked list. The value of each node in the linked list is either `0` or `1`. The linked list holds the binary representation of a number.

Return the *decimal value* of the number in the linked list.

The **most significant bit** is at the head of the linked list.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/12/05/graph-1.png)

```

**Input:** head = [1,0,1]
**Output:** 5
**Explanation:** (101) in base 2 = (5) in base 10

```

**Example 2:**

```

**Input:** head = [0]
**Output:** 0

```

**Constraints:**
* The Linked List is not empty.
* Number of nodes will not exceed `30`.
* Each node's value is either `0` or `1`.


<br>

### Hints

- Traverse the linked list and store all values in a string or array. convert the values obtained to decimal value.
- You can solve the problem in O(1) memory using bits operation. use shift left operation ( << ) and or operation ( | ) to get the decimal value in one operation.

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
    int getDecimalValue (ListNode* head) {
      int value = 0;
      
      while (head != nullptr) {
        value = (value << 1) | head->val;
        head = head->next;
      }
      
      return value;
    }
};
```

<br>

### Statistics

- total accepted: 317404
- total submissions: 384313
- acceptance rate: 82.6%
- likes: 2906
- dislikes: 135

<br>

### Similar Problems

None

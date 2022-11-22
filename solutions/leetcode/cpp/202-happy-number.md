# [202] Happy Number

**[hash-table, math, two-pointers]**

### Statement

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

* Starting with any positive integer, replace the number by the sum of the squares of its digits.
* Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
* Those numbers for which this process **ends in 1** are happy.



Return `true` *if* `n` *is a happy number, and* `false` *if not*.


**Example 1:**

```

**Input:** n = 19
**Output:** true
**Explanation:**
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

```

**Example 2:**

```

**Input:** n = 2
**Output:** false

```

**Constraints:**
* `1 <= n <= 2^31 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isHappy (int n) {
      std::set <int> have;
      
      while (true) {
        if (n == 1)
          break;
        
        int x = 0;
        
        while (n) {
          int r = n % 10;
          x += r * r;
          n /= 10;
        }
        
        n = x;
        
        if (have.count(n))
          return false;
        
        have.insert(n);
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 931642
- total submissions: 1722061
- acceptance rate: 54.1%
- likes: 6615
- dislikes: 828

<br>

### Similar Problems

- [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) (Easy)
- [Add Digits](https://leetcode.com/problems/add-digits) (Easy)
- [Ugly Number](https://leetcode.com/problems/ugly-number) (Easy)
- [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert) (Easy)

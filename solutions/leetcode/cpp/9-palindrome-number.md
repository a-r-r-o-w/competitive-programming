# [9] Palindrome Number

**[math]**

### Statement

Given an integer `x`, return `true` if `x` is palindrome integer.

An integer is a **palindrome** when it reads the same backward as forward.

* For example, `121` is a palindrome while `123` is not.


**Example 1:**

```

**Input:** x = 121
**Output:** true
**Explanation:** 121 reads as 121 from left to right and from right to left.

```

**Example 2:**

```

**Input:** x = -121
**Output:** false
**Explanation:** From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

**Example 3:**

```

**Input:** x = 10
**Output:** false
**Explanation:** Reads 01 from right to left. Therefore it is not a palindrome.

```

**Constraints:**
* `-231<= x <= 231- 1`


**Follow up:** Could you solve it without converting the integer to a string?

<br>

### Hints

- Beware of overflow when you reverse the integer.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPalindrome (int64_t n) {
      auto rev = [&] (int64_t x) {
        int64_t r = 0;
        while (x) {
          r = r * 10 + x % 10;
          x /= 10;
        }
        return r;
      };
      
      if (n < 0)
        return false;
      
      return n == rev(n);
    }
};
```

<br>

### Statistics

- total accepted: 2124359
- total submissions: 4048113
- acceptance rate: 52.5%
- likes: 5939
- dislikes: 2150

<br>

### Similar Problems

- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) (Easy)
- [Find Palindrome With Fixed Length](https://leetcode.com/problems/find-palindrome-with-fixed-length) (Medium)

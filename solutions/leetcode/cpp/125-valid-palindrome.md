# [125] Valid Palindrome

**[two-pointers, string]**

### Statement

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a **palindrome**, or* `false` *otherwise*.


**Example 1:**

```

**Input:** s = "A man, a plan, a canal: Panama"
**Output:** true
**Explanation:** "amanaplanacanalpanama" is a palindrome.

```

**Example 2:**

```

**Input:** s = "race a car"
**Output:** false
**Explanation:** "raceacar" is not a palindrome.

```

**Example 3:**

```

**Input:** s = " "
**Output:** true
**Explanation:** s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

```

**Constraints:**
* `1 <= s.length <= 2 * 105`
* `s` consists only of printable ASCII characters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool isPalindrome (string s) {
      std::string t;
      
      for (char c: s) {
        if (std::islower(c) or std::isdigit(c))
          t += c;
        else if (std::isupper(c))
          t += std::tolower(c);
      }
      
      int n = t.size();
      
      for (int i = 0; i < n / 2; ++i)
        if (t[i] != t[n - i - 1])
          return false;
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 1563947
- total submissions: 3611041
- acceptance rate: 43.3%
- likes: 4935
- dislikes: 6024

<br>

### Similar Problems

- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) (Easy)
- [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii) (Easy)
- [Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences) (Medium)
- [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array) (Easy)
- [Valid Palindrome IV](https://leetcode.com/problems/valid-palindrome-iv) (Medium)

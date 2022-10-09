# [2396] Strictly Palindromic Number



### Statement

An integer `n` is **strictly palindromic** if, for **every** base `b` between `2` and `n - 2` (**inclusive**), the string representation of the integer `n` in base `b` is **palindromic**.

Given an integer `n`, return `true` *if* `n` *is **strictly palindromic** and* `false` *otherwise*.

A string is **palindromic** if it reads the same forward and backward.


**Example 1:**

```

**Input:** n = 9
**Output:** false
**Explanation:** In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.

```

**Example 2:**

```

**Input:** n = 4
**Output:** false
**Explanation:** We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.


```

**Constraints:**
* `4 <= n <= 105`


<br>

### Hints

- Consider the representation of the given number in the base n - 2.
- The number n in base (n - 2) is always 12, which is not palindromic.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isStrictlyPalindromic (int n) {
      auto is_palindrome = [] (const std::string& s) {
        int k = s.size();
        
        for (int i = 0; i < k / 2; ++k)
          if (s[i] != s[k - i - 1])
            return false;
        
        return true;
      };
      
      std::string repr;
      
      for (int i = 2; i <= n - 2; ++i) {
        int j = i;
        
        while (j) {
          repr += '0' + (j % i);
          j /= i;
        }
        
        if (not is_palindrome(repr))
          return false;
        
        repr.clear();
      }
      
      return true;
    }
};
```

or

```cpp
class Solution {
  public:
    bool isStrictlyPalindromic (int n) {
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 15268
- total submissions: 18200
- acceptance rate: 83.9%
- likes: 45
- dislikes: 151

<br>

### Similar Problems

- [Palindrome Number](https://leetcode.com/problems/palindrome-number) (Easy)
- [Stone Game](https://leetcode.com/problems/stone-game) (Medium)

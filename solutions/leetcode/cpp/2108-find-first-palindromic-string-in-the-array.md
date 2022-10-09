# [2108] Find First Palindromic String in the Array

**[array, two-pointers, string]**

### Statement

Given an array of strings `words`, return *the first **palindromic** string in the array*. If there is no such string, return *an **empty string*** `""`.

A string is **palindromic** if it reads the same forward and backward.


**Example 1:**

```

**Input:** words = ["abc","car","ada","racecar","cool"]
**Output:** "ada"
**Explanation:** The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

```

**Example 2:**

```

**Input:** words = ["notapalindrome","racecar"]
**Output:** "racecar"
**Explanation:** The first and only string that is palindromic is "racecar".

```

**Example 3:**

```

**Input:** words = ["def","ghi"]
**Output:** ""
**Explanation:** There are no palindromic strings, so the empty string is returned.

```

**Constraints:**
* `1 <= words.length <= 100`
* `1 <= words[i].length <= 100`
* `words[i]` consists only of lowercase English letters.


<br>

### Hints

- Iterate through the elements in order. As soon as the current element is a palindrome, return it.
- To check if an element is a palindrome, can you reverse the string?

<br>

### Solution

```cpp
class Solution {
  public:
    string firstPalindrome (vector <string>& words) {
      for (auto &word: words) {
        int n = word.length();
        bool bad = false;
        
        for (int i = 0; i < n / 2; ++i)
          if (word[i] != word[n - i - 1]) {
            bad = true;
            break;
          }
        
        if (not bad)
          return word;
      }
      
      return "";
    }
};
```

<br>

### Statistics

- total accepted: 57224
- total submissions: 72787
- acceptance rate: 78.6%
- likes: 524
- dislikes: 14

<br>

### Similar Problems

- [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) (Easy)

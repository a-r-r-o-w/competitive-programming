# [344] Reverse String

**[two-pointers, string, recursion]**

### Statement

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.


**Example 1:**

```
**Input:** s = ["h","e","l","l","o"]
**Output:** ["o","l","l","e","h"]

```
**Example 2:**

```
**Input:** s = ["H","a","n","n","a","h"]
**Output:** ["h","a","n","n","a","H"]

```

**Constraints:**
* `1 <= s.length <= 105`
* `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).


<br>

### Hints

- The entire logic for reversing a string is based on using the opposite directional two-pointer approach!

<br>

### Solution

```cpp
class Solution {
  public:
    void reverseString (vector <char>& s) {
      int n = s.size();
      
      for (int i = 0; i < n / 2; ++i) {
        int t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
      }
    }
};
```

<br>

### Statistics

- total accepted: 1727618
- total submissions: 2285399
- acceptance rate: 75.6%
- likes: 5672
- dislikes: 980

<br>

### Similar Problems

- [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string) (Easy)
- [Reverse String II](https://leetcode.com/problems/reverse-string-ii) (Easy)

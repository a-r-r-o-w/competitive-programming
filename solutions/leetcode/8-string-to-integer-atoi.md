# [8] String to Integer (atoi)

**[string]**

### Statement

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm for `myAtoi(string s)` is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is `'-'` or `'+'`. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. `"123" -> 123`, `"0032" -> 32`). If no digits were read, then the integer is `0`. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range `[-231, 231 - 1]`, then clamp the integer so that it remains in the range. Specifically, integers less than `-231` should be clamped to `-231`, and integers greater than `231 - 1` should be clamped to `231 - 1`.
6. Return the integer as the final result.


**Note:**
* Only the space character `' '` is considered a whitespace character.
* **Do not ignore** any characters other than the leading whitespace or the rest of the string after the digits.


**Example 1:**

```

**Input:** s = "42"
**Output:** 42
**Explanation:** The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.

```

**Example 2:**

```

**Input:** s = "   -42"
**Output:** -42
**Explanation:**
Step 1: " -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

```

**Example 3:**

```

**Input:** s = "4193 with words"
**Output:** 4193
**Explanation:**
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.

```

**Constraints:**
* `0 <= s.length <= 200`
* `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int myAtoi (string s) {
      const int max = (1 << 31) - 1;
      const int min = -(1 << 31);
      
      int n = s.length();
      int value = 0;
      bool positive = true;
      bool pos = false;
      bool neg = false;
      bool has_digit_occurred = false;
      
      for (int i = 0; i < n; ++i) {
        if (has_digit_occurred and not (s[i] >= '0' and s[i] <= '9'))
          break;
        if (s[i] == ' ')
          continue;
        else if (s[i] == '-') {
          positive = false;
          neg = true;
          has_digit_occurred = true;
        }
        else if (s[i] == '+') {
          pos = true;
          has_digit_occurred = true;
        }
        else if (s[i] >= '0' and s[i] <= '9') {
          has_digit_occurred = true;
          if (positive) {
            if (value > max / 10 or (value == max / 10 and s[i] >= '8')) {
              value = max;
              break;
            }
            else
              value = value * 10 + (s[i] - '0');
          }
          else {
            if (value < min / 10 or (value == min / 10 and s[i] == '9')) {
              value = min;
              break;
            }
            else
              value = value * 10 - (s[i] - '0');
          }
        }
        else
          break;
      }
      
      return (pos and neg ? 0 : value);
    }
};
```

<br>

### Statistics

- total accepted: 1016381
- total submissions: 6144283
- acceptance rate: 16.5%
- likes: 1736
- dislikes: 5061

<br>

### Similar Problems

- [Reverse Integer](https://leetcode.com/problems/reverse-integer) (Medium)
- [Valid Number](https://leetcode.com/problems/valid-number) (Hard)
- [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) (Easy)

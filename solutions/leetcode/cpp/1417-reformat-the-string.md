# [1417] Reformat The String

**[string]**

### Statement

You are given an alphanumeric string `s`. (**Alphanumeric string** is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return *the reformatted string* or return **an empty string** if it is impossible to reformat the string.


**Example 1:**

```

**Input:** s = "a0b1c2"
**Output:** "0a1b2c"
**Explanation:** No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

```

**Example 2:**

```

**Input:** s = "leetcode"
**Output:** ""
**Explanation:** "leetcode" has only characters so we cannot separate them by digits.

```

**Example 3:**

```

**Input:** s = "1229857369"
**Output:** ""
**Explanation:** "1229857369" has only digits so we cannot separate them by characters.

```

**Constraints:**
* `1 <= s.length <= 500`
* `s` consists of only lowercase English letters and/or digits.


<br />

### Hints

- Count the number of letters and digits in the string. if cntLetters - cntDigits has any of the values [-1, 0, 1] we have an answer, otherwise we don't have any answer.
- Build the string anyway as you wish. Keep in mind that you need to start with the type that have more characters if cntLetters ≠ cntDigits.

<br />

### Solution

```cpp
class Solution {
  public:
    string reformat (string s) {
      std::vector <char> digits, chars;

      for (char c: s) {
        if (std::isdigit(c))
          digits.push_back(c);
        else
          chars.push_back(c);
      }

      if (std::abs((int)digits.size() - (int)chars.size()) > 1)
        return "";
      
      if (digits.size() < chars.size())
        std::swap(digits, chars);
      
      int i = 0, k = chars.size();
      std::string ans;

      while (i < k) {
        ans += digits[i];
        ans += chars[i];
        ++i;
      }
      if ((int)digits.size() > k)
        ans += digits.back();

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 48604
- total submissions: 88229
- acceptance rate: 55.1%
- likes: 485
- dislikes: 89

<br />

### Similar Problems

None

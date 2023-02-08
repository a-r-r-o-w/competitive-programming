# [6] Zigzag Conversion

**[string]**

### Statement

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)


```

P   A   H   N
A P L S I I G
Y   I   R

```


And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:


```

string convert(string s, int numRows);

```

**Example 1:**

```

**Input:** s = "PAYPALISHIRING", numRows = 3
**Output:** "PAHNAPLSIIGYIR"

```

**Example 2:**

```

**Input:** s = "PAYPALISHIRING", numRows = 4
**Output:** "PINALSIGYAHRPI"
**Explanation:**
P     I    N
A   L S  I G
Y A   H R
P     I

```

**Example 3:**

```

**Input:** s = "A", numRows = 1
**Output:** "A"

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
* `1 <= numRows <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    string convert (string s, int numRows) {
      constexpr int max = 1000;
      int n = s.length(), i = 0, l = 0;
      std::vector <std::vector <char>> grid (numRows, std::vector <char> (max, ' '));

      while (i < n) {
        for (int j = 0; j < numRows and i < n; ++i, ++j)
          grid[j][l] = s[i];
        ++l;
        for (int j = 1; j < numRows - 1 and i < n; ++i, ++j, ++l)
          grid[numRows - 1 - j][l] = s[i];
      }

      std::string ans;
      ans.reserve(n);

      for (auto &x: grid) {
        for (char c: x) {
          if (c == ' ')
            continue;
          ans += c;
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 919443
- total submissions: 2110952
- acceptance rate: 43.6%
- likes: 5009
- dislikes: 10649

<br />

### Similar Problems

None

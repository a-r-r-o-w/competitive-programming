# [168] Excel Sheet Column Title

**[math, string]**

### Statement

Given an integer `columnNumber`, return *its corresponding column title as it appears in an Excel sheet*.

For example:


```

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

```

**Example 1:**

```

**Input:** columnNumber = 1
**Output:** "A"

```

**Example 2:**

```

**Input:** columnNumber = 28
**Output:** "AB"

```

**Example 3:**

```

**Input:** columnNumber = 701
**Output:** "ZY"

```

**Constraints:**
* `1 <= columnNumber <= 2^31 - 1`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    string convertToTitle(int columnNumber) {
      std::string title;
      while (columnNumber) {
        --columnNumber;
        title += 'A' + (columnNumber % 26);
        columnNumber /= 26;
      }
      std::reverse(title.begin(), title.end());
      return title;
    }
};
```

<br />

### Statistics

- total accepted: 402818
- total submissions: 1098452
- acceptance rate: 36.7%
- likes: 4108
- dislikes: 583

<br />

### Similar Problems

- [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number) (Easy)
- [Cells in a Range on an Excel Sheet](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet) (Easy)

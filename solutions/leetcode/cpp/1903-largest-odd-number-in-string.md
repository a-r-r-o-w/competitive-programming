# [1903] Largest Odd Number in String

**[math, string, greedy]**

### Statement

You are given a string `num`, representing a large integer. Return *the **largest-valued odd** integer (as a string) that is a **non-empty substring** of* `num`*, or an empty string* `""` *if no odd integer exists*.

A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** num = "52"
**Output:** "5"
**Explanation:** The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

```

**Example 2:**

```

**Input:** num = "4206"
**Output:** ""
**Explanation:** There are no odd numbers in "4206".

```

**Example 3:**

```

**Input:** num = "35427"
**Output:** "35427"
**Explanation:** "35427" is already an odd number.

```

**Constraints:**
* `1 <= num.length <= 105`
* `num` only consists of digits and does not contain any leading zeros.


<br>

### Hints

- In what order should you iterate through the digits?
- If an odd number exists, where must the number start from?

<br>

### Solution

```cpp
class Solution {
  public:
    string largestOddNumber (string num) {
      int n = num.length() - 1;
      while (n >= 0) {
        if ((num[n] - '0') & 1)
          break;
        --n;
      }
      return num.substr(0, n + 1);
    }
};
```

or

```cpp
class Solution {
  public:
    string largestOddNumber (string num) {
      return num.substr(0, num.find_last_of("13579") + 1);
    }
};
```

<br>

### Statistics

- total accepted: 36941
- total submissions: 65775
- acceptance rate: 56.2%
- likes: 434
- dislikes: 37

<br>

### Similar Problems

- [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string) (Easy)

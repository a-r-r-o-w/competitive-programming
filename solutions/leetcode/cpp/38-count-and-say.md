# [38] Count and Say

**[string]**

### Statement

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

* `countAndSay(1) = "1"`
* `countAndSay(n)` is the way you would "say" the digit string from `countAndSay(n-1)`, which is then converted into a different digit string.



To determine how you "say" a digit string, split it into the **minimal** number of substrings such that each substring contains exactly **one** unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string `"3322251"`:
![](https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg)
Given a positive integer `n`, return *the* `nth` *term of the **count-and-say** sequence*.


**Example 1:**

```

**Input:** n = 1
**Output:** "1"
**Explanation:** This is the base case.

```

**Example 2:**

```

**Input:** n = 4
**Output:** "1211"
**Explanation:**
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

```

**Constraints:**
* `1 <= n <= 30`


<br>

### Hints

- Create a helper function that maps an integer to pairs of its digits and their frequencies. For example, if you call this function with "223314444411", then it maps it to an array of pairs [[2,2], [3,2], [1,1], [4,5], [1, 2]].
- Create another helper function that takes the array of pairs and creates a new integer. For example, if you call this function with [[2,2], [3,2], [1,1], [4,5], [1, 2]], it should create "22"+"23"+"11"+"54"+"21" = "2223115421".
- Now, with the two helper functions, you can start with "1" and call the two functions alternatively n-1 times. The answer is the last integer you will obtain.

<br>

### Solution

```cpp
class Solution {
  public:
    string countAndSay (int n) {
      if (n == 1)
        return "1";
      
      std::string x = countAndSay(n - 1);
      std::string result;
      
      for (int i = x.size() - 1; i >= 0;) {
        char r = x[i];
        int c = 0, c_rev = 0;
        
        while (i >= 0 and x[i] == r) {
          --i;
          ++c;
        }
        
        while (c) {
          c_rev = c_rev * 10 + c % 10;
          c /= 10;
        }
        
        result += r + std::to_string(c_rev);
      }
      
      std::reverse(result.begin(), result.end());
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 674223
- total submissions: 1358479
- acceptance rate: 49.6%
- likes: 2008
- dislikes: 4505

<br>

### Similar Problems

- [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings) (Medium)
- [String Compression](https://leetcode.com/problems/string-compression) (Medium)

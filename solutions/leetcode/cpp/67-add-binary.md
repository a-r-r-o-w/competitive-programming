# [67] Add Binary

**[math, string, bit-manipulation, simulation]**

### Statement

Given two binary strings `a` and `b`, return *their sum as a binary string*.


**Example 1:**

```
**Input:** a = "11", b = "1"
**Output:** "100"

```
**Example 2:**

```
**Input:** a = "1010", b = "1011"
**Output:** "10101"

```

**Constraints:**
* `1 <= a.length, b.length <= 104`
* `a` and `b` consistonly of `'0'` or `'1'` characters.
* Each string does not contain leading zeros except for the zero itself.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string addBinary (string a, string b) {
      if (a.size() > b.size())
        std::swap(a, b);
      
      int i = a.size() - 1, j = b.size() - 1;
      int carry = 0;
      std::string ans;
      
      while (i >= 0) {
        int sum = carry + a[i] + b[j] - 2 * '0';
        ans.push_back('0' + (sum % 2));
        carry = sum >> 1;
        --i;
        --j;
      }
      
      while (j >= 0) {
        int sum = carry + b[j] - '0';
        ans.push_back('0' + (sum % 2));
        carry = sum >> 1;
        --j;
      }
      
      if (carry)
        ans.push_back('1');
      
      std::reverse(ans.begin(), ans.end());
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 916460
- total submissions: 1794586
- acceptance rate: 51.1%
- likes: 5765
- dislikes: 616

<br>

### Similar Problems

- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) (Medium)
- [Multiply Strings](https://leetcode.com/problems/multiply-strings) (Medium)
- [Plus One](https://leetcode.com/problems/plus-one) (Easy)
- [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer) (Easy)

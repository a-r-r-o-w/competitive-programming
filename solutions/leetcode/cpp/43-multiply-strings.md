# [43] Multiply Strings

**[math, string, simulation]**

### Statement

Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note:**You must not use any built-in BigInteger library or convert the inputs to integer directly.


**Example 1:**

```
**Input:** num1 = "2", num2 = "3"
**Output:** "6"

```
**Example 2:**

```
**Input:** num1 = "123", num2 = "456"
**Output:** "56088"

```

**Constraints:**
* `1 <= num1.length, num2.length <= 200`
* `num1` and `num2` consist of digits only.
* Both `num1` and `num2`do not contain any leading zero, except the number `0` itself.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string multiply (string num1, string num2) {
      auto add = [] (std::string x, const std::string &y) {
        // assumes x is the bigger number in length
        // assumes number is present from LSD to MSD
        int n = x.length(), m = y.length(), carry = 0;

        for (int i = 0; i < n; ++i) {
          int a = x[i] - '0', b = i < m ? y[i] - '0' : 0;
          int sum = a + b + carry;
          x[i] = sum % 10 + '0';
          carry = sum / 10;
        }

        if (carry)
          x += carry + '0';

        return x;
      };

      std::reverse(num1.begin(), num1.end());
      std::reverse(num2.begin(), num2.end());

      if (num1.length() < num2.length())
        std::swap(num1, num2);

      int n = num1.length(), m = num2.length();
      std::string result;
      
      for (int i = 0; i < m; ++i) {
        std::string intermediate (i, '0');
        int carry = 0;

        for (int j = 0; j < n; ++j) {
          int a = num1[j] - '0', b = num2[i] - '0';
          int p = a * b + carry;
          intermediate += p % 10 + '0';
          carry = p / 10;
        }
        if (carry)
          intermediate += carry + '0';
        
        if (result.length() < intermediate.length())
          std::swap(result, intermediate);
        result = add(result, intermediate);
      }

      if (std::count(result.begin(), result.end(), '0') == result.length())
        return "0";

      std::reverse(result.begin(), result.end());

      return result;
    }
};
```

<br>

### Statistics

- total accepted: 619184
- total submissions: 1589090
- acceptance rate: 39.0%
- likes: 5654
- dislikes: 2476

<br>

### Similar Problems

- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) (Medium)
- [Plus One](https://leetcode.com/problems/plus-one) (Easy)
- [Add Binary](https://leetcode.com/problems/add-binary) (Easy)
- [Add Strings](https://leetcode.com/problems/add-strings) (Easy)
- [Apply Discount to Prices](https://leetcode.com/problems/apply-discount-to-prices) (Medium)

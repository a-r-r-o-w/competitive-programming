# [12] Integer to Roman

**[hash-table, math, string]**

### Statement

Roman numerals are represented by seven different symbols:`I`, `V`, `X`, `L`, `C`, `D` and `M`.


```

**Symbol**       **Value**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```


For example,`2` is written as `II`in Roman numeral, just two one's added together. `12` is written as`XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

* `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
* `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
* `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.



Given an integer, convert it to a roman numeral.


**Example 1:**

```

**Input:** num = 3
**Output:** "III"
**Explanation:** 3 is represented as 3 ones.

```

**Example 2:**

```

**Input:** num = 58
**Output:** "LVIII"
**Explanation:** L = 50, V = 5, III = 3.

```

**Example 3:**

```

**Input:** num = 1994
**Output:** "MCMXCIV"
**Explanation:** M = 1000, CM = 900, XC = 90 and IV = 4.

```

**Constraints:**
* `1 <= num <= 3999`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    std::vector <std::string> ones_place = {
      "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
    };

    std::vector <std::string> tens_place = {
      "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
    };

    std::vector <std::string> hundreds_place = {
      "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
    };

    std::vector <std::string> thousands_place = {
      "M", "MM", "MMM"
    };
  
    string intToRoman (int num) {
      if (num >= 1000)
        return thousands_place[num / 1000 - 1] + intToRoman(num % 1000);
      if (num >= 100)
        return hundreds_place[num / 100 - 1] + intToRoman(num % 100);
      if (num >= 10)
        return tens_place[num / 10 - 1] + intToRoman(num % 10);
      if (num >= 1)
        return ones_place[num - 1];
      return "";
    }
};
```

<br>

### Statistics

- total accepted: 859441
- total submissions: 1405617
- acceptance rate: 61.1%
- likes: 4576
- dislikes: 4727

<br>

### Similar Problems

- [Roman to Integer](https://leetcode.com/problems/roman-to-integer) (Easy)
- [Integer to English Words](https://leetcode.com/problems/integer-to-english-words) (Hard)

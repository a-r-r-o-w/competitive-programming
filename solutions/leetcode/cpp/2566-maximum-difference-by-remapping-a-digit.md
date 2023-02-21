# [2566] Maximum Difference by Remapping a Digit



### Statement

You are given an integer `num`. You know that Danny Mittal will sneakily **remap** one of the `10` possible digits (`0` to `9`) to another digit.

Return *the difference between the maximum and minimum**values Danny can make by remapping**exactly** **one** digit* *in* `num`.

**Notes:**
* When Danny remaps a digit d1to another digit d2, Danny replaces all occurrences of `d1`in `num`with `d2`.
* Danny can remap a digit to itself, in which case `num`does not change.
* Danny can remap different digits for obtaining minimum and maximum values respectively.
* The resulting number after remapping can contain leading zeroes.
* We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.


**Example 1:**

```

**Input:** num = 11891
**Output:** 99009
**Explanation:** 
To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.

```

**Example 2:**

```

**Input:** num = 90
**Output:** 99
**Explanation:**
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
```

**Constraints:**
* `1 <= num <= 10^8`


<br />

### Hints

- Try to remap the first non-zero digit to 9 to obtain the maximum number.
- Try to remap the first non-nine digit to 0 to obtain the minimum number.

<br />

### Solution

```cpp
class Solution {
  public:
    int minMaxDifference (int num) {
      auto x = std::to_string(num);
      int min = 1 << 30, max = 0, n = x.size();
      
      for (int i = 0; i < n; ++i) {
        std::string y = x, z = x;
        
        for (int j = 0; j < n; ++j) {
          if (y[j] == x[i])
            y[j] = '9';
          if (z[j] == x[i])
            z[j] = '0';
        }
        
        int a = std::stoi(y), b = std::stoi(z);
        max = std::max(max, a);
        min = std::min(min, b);
      }
      
      return max - min;
    }
};
```

<br />

### Statistics

- total accepted: 13374
- total submissions: 23099
- acceptance rate: 57.9%
- likes: 64
- dislikes: 18

<br />

### Similar Problems

None

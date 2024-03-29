# [1447] Simplified Fractions

**[math, string, number-theory]**

### Statement

Given an integer `n`, return *a list of all **simplified** fractions between* `0` *and* `1` *(exclusive) such that the denominator is less-than-or-equal-to* `n`. You can return the answer in **any order**.


**Example 1:**

```

**Input:** n = 2
**Output:** ["1/2"]
**Explanation:** "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

```

**Example 2:**

```

**Input:** n = 3
**Output:** ["1/2","1/3","2/3"]

```

**Example 3:**

```

**Input:** n = 4
**Output:** ["1/2","1/3","1/4","2/3","3/4"]
**Explanation:** "2/4" is not a simplified fraction because it can be simplified to "1/2".

```

**Constraints:**
* `1 <= n <= 100`


<br>

### Hints

- A fraction is fully simplified if there is no integer that divides cleanly into the numerator and denominator.
- In other words the greatest common divisor of the numerator and the denominator of a simplified fraction is 1.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> simplifiedFractions (int n) {
      std::vector <std::string> ans;
      
      for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
          if (std::gcd(i, j) != 1)
            continue;
          ans.push_back(std::to_string(j) + "/" + std::to_string(i));
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 23453
- total submissions: 36325
- acceptance rate: 64.6%
- likes: 290
- dislikes: 36

<br>

### Similar Problems

None

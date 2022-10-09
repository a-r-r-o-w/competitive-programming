# [869] Reordered Power of 2

**[math, sorting, counting, enumeration]**

### Statement

You are given an integer `n`. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` *if and only if we can do this so that the resulting number is a power of two*.


**Example 1:**

```

**Input:** n = 1
**Output:** true

```

**Example 2:**

```

**Input:** n = 10
**Output:** false

```

**Constraints:**
* `1 <= n <= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    std::vector <std::vector <int>> p2;
  
    Solution () {
      for (int i = 0; i < 30; ++i) {
        int k = 1 << i;
        std::vector <int> digits;
        
        while (k) {
          digits.push_back(k % 10);
          k /= 10;
        }
        
        std::sort(digits.begin(), digits.end());
        p2.push_back(digits);
      }
    }
  
    bool reorderedPowerOf2 (int n) {
      std::vector <int> digits;
      
      for (int i = n; i > 0; i /= 10)
        digits.push_back(i % 10);
      
      std::sort(digits.begin(), digits.end());
      
      for (int i = 0; i < 30; ++i) {
        if (p2[i] == digits)
          return true;
      }
      
      return false;
    }
};
```

<br>

### Statistics

- total accepted: 72942
- total submissions: 115317
- acceptance rate: 63.3%
- likes: 1385
- dislikes: 306

<br>

### Similar Problems

None

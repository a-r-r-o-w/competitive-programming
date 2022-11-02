# [537] Complex Number Multiplication

**[math, string, simulation]**

### Statement

A [complex number](https://en.wikipedia.org/wiki/Complex_number) can be represented as a string on the form `"**real**+**imaginary**i"` where:

* `real` is the real part and is an integer in the range `[-100, 100]`.
* `imaginary` is the imaginary part and is an integer in the range `[-100, 100]`.
* `i2 == -1`.



Given two complex numbers `num1` and `num2` as strings, return *a string of the complex number that represents their multiplications*.


**Example 1:**

```

**Input:** num1 = "1+1i", num2 = "1+1i"
**Output:** "0+2i"
**Explanation:** (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

```

**Example 2:**

```

**Input:** num1 = "1+-1i", num2 = "1+-1i"
**Output:** "0+-2i"
**Explanation:** (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

```

**Constraints:**
* `num1` and `num2` are valid complex numbers.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string complexNumberMultiply (string num1, string num2) {
      std::stringstream ss1 (num1), ss2 (num2);
      int a = 0, b = 0, x = 0, y = 0;
      char c;
      
      ss1 >> a >> c >> b;
      ss2 >> x >> c >> y;
      
      int p = a * x - b * y;
      int q = a * y + b * x;
      
      return std::to_string(p) + '+' + std::to_string(q) + 'i';
    }
};
```

<br>

### Statistics

- total accepted: 84125
- total submissions: 117961
- acceptance rate: 71.3%
- likes: 557
- dislikes: 1166

<br>

### Similar Problems

None

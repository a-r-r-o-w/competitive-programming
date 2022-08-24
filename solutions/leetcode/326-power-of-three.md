# [326] Power of Three

**[math, recursion]**

### Statement

Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.


**Example 1:**

```

**Input:** n = 27
**Output:** true

```

**Example 2:**

```

**Input:** n = 0
**Output:** false

```

**Example 3:**

```

**Input:** n = 9
**Output:** true

```

**Constraints:**
* `-2^31 <= n <= 2^31 - 1`


**Follow up:** Could you solve it without loops/recursion?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    const int largest_power_of_three = std::pow(3, 19);
  
    bool isPowerOfThree (int n) {
      if (n <= 0)
        return false;
      return largest_power_of_three % n == 0;
    }
};
```

<br>

### Statistics

- total accepted: 534434
- total submissions: 1201409
- acceptance rate: 44.5%
- likes: 1550
- dislikes: 157

<br>

### Similar Problems

- [Power of Two](https://leetcode.com/problems/power-of-two) (Easy)
- [Power of Four](https://leetcode.com/problems/power-of-four) (Easy)
- [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three) (Medium)

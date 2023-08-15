# [372] Super Pow

**[math, divide-and-conquer]**

### Statement

Your task is to calculate `ab` mod `1337` where `a` is a positive integer and `b` is an extremely large positive integer given in the form of an array.


**Example 1:**

```

**Input:** a = 2, b = [3]
**Output:** 8

```

**Example 2:**

```

**Input:** a = 2, b = [1,0]
**Output:** 1024

```

**Example 3:**

```

**Input:** a = 1, b = [4,3,3,8,5,2]
**Output:** 1

```

**Constraints:**
* `1 <= a <= 231 - 1`
* `1 <= b.length <= 2000`
* `0 <= b[i] <= 9`
* `b` does not contain leading zeros.


<br>

### Hints

None

<br>

### Solution

```py
class Solution:
  def superPow (self, a: int, b: List[int]) -> int:
    m = 1337
    phi = 1140
    return reduce(lambda x, y: x * y % m, [pow(a, pow(10, index) * x % phi, m) for index, x in enumerate(b[::-1])])
```

<br>

### Statistics

- total accepted: 54585
- total submissions: 147063
- acceptance rate: 37.1%
- likes: 606
- dislikes: 1218

<br>

### Similar Problems

- [Pow(x, n)](https://leetcode.com/problems/powx-n) (Medium)

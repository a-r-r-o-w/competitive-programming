# [858] Mirror Reflection

**[math, geometry]**

### Statement

There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p`and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0th` receptor.

Given the two integers `p` and `q`, return *the number of the receptor that the ray meets first*.

The test cases are guaranteed so that the ray will meet a receptor eventually.


**Example 1:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png)

```

**Input:** p = 2, q = 1
**Output:** 2
**Explanation:** The ray meets receptor 2 the first time it gets reflected back to the left wall.

```

**Example 2:**

```

**Input:** p = 3, q = 1
**Output:** 1

```

**Constraints:**
* `1 <= q <= p <= 1000`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int mirrorReflection (int p, int q) {
      while (p % 2 == 0 and q % 2 == 0) {
        p /= 2;
        q /= 2;
      }
      
      if (p % 2 == 1 and q % 2 == 1)
        return 1;
      else if (p % 2 == 1)
        return 0;
      return 2;
    }
};
```

<br>

### Statistics

- total accepted: 52891
- total submissions: 86147
- acceptance rate: 61.4%
- likes: 815
- dislikes: 1850

<br>

### Similar Problems

None

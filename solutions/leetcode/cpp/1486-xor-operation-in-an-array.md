# [1486] XOR Operation in an Array

**[math, bit-manipulation]**

### Statement

You are given an integer `n` and an integer `start`.

Define an array `nums` where `nums[i] = start + 2 * i` (**0-indexed**) and `n == nums.length`.

Return *the bitwise XOR of all elements of* `nums`.


**Example 1:**

```

**Input:** n = 5, start = 0
**Output:** 8
**Explanation:** Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.

```

**Example 2:**

```

**Input:** n = 4, start = 3
**Output:** 8
**Explanation:** Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.

```

**Constraints:**
* `1 <= n <= 1000`
* `0 <= start <= 1000`
* `n == nums.length`


<br>

### Hints

- Simulate the process, create an array nums and return the Bitwise XOR of all elements of it.

<br>

### Solution

```cpp
class Solution {
  public:
    int xorOperation (int n, int start) {
      int x = 0;
      
      for (int i = 0; i < n; ++i)
        x ^= start + 2 * i;
      
      return x;
    }
};
```

<br>

### Statistics

- total accepted: 128865
- total submissions: 153235
- acceptance rate: 84.1%
- likes: 893
- dislikes: 296

<br>

### Similar Problems

None

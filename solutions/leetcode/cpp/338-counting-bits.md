# [338] Counting Bits

**[dynamic-programming, bit-manipulation]**

### Statement

Given an integer `n`, return *an array* `ans` *of length* `n + 1` *such that for each* `i`(`0 <= i <= n`)*,* `ans[i]` *is the **number of*** `1`***'s** in the binary representation of* `i`.


**Example 1:**

```

**Input:** n = 2
**Output:** [0,1,1]
**Explanation:**
0 --> 0
1 --> 1
2 --> 10

```

**Example 2:**

```

**Input:** n = 5
**Output:** [0,1,1,2,1,2]
**Explanation:**
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

```

**Constraints:**
* `0 <= n <= 10^5`


**Follow up:**
* It is very easy to come up with a solution with a runtime of `O(n log n)`. Can you do it in linear time `O(n)` and possibly in a single pass?
* Can you do it without using any built-in function (i.e., like `__builtin_popcount` in C++)?


<br>

### Hints

- You should make use of what you have produced already.
- Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
- Or does the odd/even status of the number help you in calculating the number of 1s?

<br>

### Solution

O(n.log(n))

```cpp
class Solution {
  public:
    vector <int> countBits (int n) {
      std::vector <int> ans (n + 1);
      
      for (int i = 0; i <= n; ++i)
        ans[i] = __builtin_popcount(i);
      
      return ans;
    }
};
```

O(n)

```cpp
class Solution {
  public:
    vector <int> countBits (int n) {
      std::vector <int> ans (n + 1);
      
      for (int i = 0; i <= n; ++i)
        ans[i] = ans[i / 2] + (i & 1);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 647042
- total submissions: 863831
- acceptance rate: 74.9%
- likes: 7612
- dislikes: 358

<br>

### Similar Problems

- [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) (Easy)

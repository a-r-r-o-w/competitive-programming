# [96] Unique Binary Search Trees

**[math, dynamic-programming, tree, binary-search-tree, binary-tree]**

### Statement

Given an integer `n`, return *the number of structurally unique **BST'**s (binary search trees) which has exactly* `n` *nodes of unique values from* `1` *to* `n`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

```

**Input:** n = 3
**Output:** 5

```

**Example 2:**

```

**Input:** n = 1
**Output:** 1

```

**Constraints:**
* `1 <= n <= 19`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numTrees (int n) {
      std::vector <int> dp (n + 1);
      dp[0] = 1;
      dp[1] = 1;

      for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j)
          dp[i] += dp[j] * dp[i - j - 1];
      }

      return dp[n];
    }
};
```

<br>

### Statistics

- total accepted: 548711
- total submissions: 922831
- acceptance rate: 59.5%
- likes: 8668
- dislikes: 347

<br>

### Similar Problems

- [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii) (Medium)

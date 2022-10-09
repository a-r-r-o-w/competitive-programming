# [967] Numbers With Same Consecutive Differences

**[backtracking, breadth-first-search]**

### Statement

Return all **non-negative** integers of length `n` such that the absolute difference between every two consecutive digits is `k`.

Note that **every** number in the answer **must not** have leading zeros. For example, `01` has one leading zero and is invalid.

You may return the answer in **any order**.


**Example 1:**

```

**Input:** n = 3, k = 7
**Output:** [181,292,707,818,929]
**Explanation:** Note that 070 is not a valid number, because it has leading zeroes.

```

**Example 2:**

```

**Input:** n = 2, k = 1
**Output:** [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

```

**Constraints:**
* `2 <= n <= 9`
* `0 <= k <= 9`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> numsSameConsecDiff (int n, int k) {
      std::vector <int> ans;
      
      auto dfs = [&] (auto self, int num, int len) -> void {
        if (len == n) {
          ans.push_back(num);
          return;
        }
        
        if (num % 10 - k >= 0)
          self(self, num * 10 + num % 10 - k, len + 1);
        if (num % 10 + k <= 9 and k != 0)
          self(self, num * 10 + num % 10 + k, len + 1);
      };
      
      for (int i = 1; i < 10; ++i)
        dfs(dfs, i, 1);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 56383
- total submissions: 115173
- acceptance rate: 49.0%
- likes: 1049
- dislikes: 135

<br>

### Similar Problems

None

# [52] N-Queens II

**[backtracking]**

### Statement

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *the number of distinct solutions to the**n-queens puzzle***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```

**Input:** n = 4
**Output:** 2
**Explanation:** There are two distinct solutions to the 4-queens puzzle as shown.

```

**Example 2:**

```

**Input:** n = 1
**Output:** 1

```

**Constraints:**
* `1 <= n <= 9`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int totalNQueens (int n) {
      int col = 0, diag1 = 0, diag2 = 0;
      int ans = 0;
      
      auto dfs = [&] (auto self, int row) -> void {
        if (row == n) {
          ++ans;
          return;
        }
        
        for (int c = 0; c < n; ++c) {
          int d1 = row + c, d2 = row + n - c - 1;
          
          if ((col & (1 << c)) or (diag1 & (1 << d1)) or (diag2 & (1 << d2)))
            continue;
          
          col ^= 1 << c;
          diag1 ^= 1 << d1;
          diag2 ^= 1 << d2;
          
          self(self, row + 1);
          
          col ^= 1 << c;
          diag1 ^= 1 << d1;
          diag2 ^= 1 << d2;
        }
      };
      
      dfs(dfs, 0);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 287171
- total submissions: 404902
- acceptance rate: 70.9%
- likes: 2879
- dislikes: 233

<br>

### Similar Problems

- [N-Queens](https://leetcode.com/problems/n-queens) (Hard)

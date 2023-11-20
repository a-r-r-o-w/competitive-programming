# [1444] Number of Ways of Cutting a Pizza

**[array, dynamic-programming, memoization, matrix]**

### Statement

Given a rectangular pizza represented as a `rows x cols`matrix containing the following characters: `'A'` (an apple) and `'.'` (empty cell) and given the integer `k`. You have to cut the pizza into `k` pieces using `k-1` cuts.

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

*Return the number of ways of cutting the pizza such that each piece contains **at least** one apple.*Since the answer can be a huge number, return this modulo 10^9 + 7.


**Example 1:**
**![](https://assets.leetcode.com/uploads/2020/04/23/ways_to_cut_apple_1.png)**

```

**Input:** pizza = ["A..","AAA","..."], k = 3
**Output:** 3 
**Explanation:** The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.

```

**Example 2:**

```

**Input:** pizza = ["A..","AA.","..."], k = 3
**Output:** 1

```

**Example 3:**

```

**Input:** pizza = ["A..","A..","..."], k = 1
**Output:** 1

```

**Constraints:**
* `1 <= rows, cols <= 50`
* `rows ==pizza.length`
* `cols ==pizza[i].length`
* `1 <= k <= 10`
* `pizza` consists of characters `'A'`and `'.'` only.


<br />

### Hints

- Note that after each cut the remaining piece of pizza always has the lower right coordinate at (rows-1,cols-1).
- Use dynamic programming approach with states (row1, col1, c) which computes the number of ways of cutting the pizza using "c" cuts where the current piece of pizza has upper left coordinate at (row1,col1) and lower right coordinate at (rows-1,cols-1).
- For the transitions try all vertical and horizontal cuts such that the piece of pizza you have to give a person must contain at least one apple. The base case is when c=k-1.
- Additionally use a 2D dynamic programming to respond in O(1) if a piece of pizza contains at least one apple.

<br />

### Solution

```cpp
constexpr int mod = 1e9 + 7;

inline int add_mod (int64_t a, int64_t b) {
  int64_t c = a + b;
  if (c >= mod)
    c -= mod;
  return c;
}

class Solution {
  public:
    int ways (vector <string>& pizza, int k) {
      int rows = pizza.size(), cols = pizza.front().size();
      std::vector <std::vector <int>> contains (rows + 1, std::vector <int> (cols + 1));

      for (int i = rows - 1; i >= 0; --i) {
        for (int j = cols - 1; j >= 0; --j) {
          int have = pizza[i][j] == 'A';
          contains[i][j] = contains[i + 1][j] + contains[i][j + 1] - contains[i + 1][j + 1] + have;
        }
      }

      std::vector <std::vector <std::vector <int>>> dp (rows, std::vector <std::vector <int>> (cols, std::vector <int> (k, -1)));

      auto dfs = [&] (auto self, int r, int c, int cuts) -> int {
        if (dp[r][c][cuts] != -1)
          return dp[r][c][cuts];
        if (cuts == 0)
          return dp[r][c][cuts] = 1;
        int ret = 0;
        for (int i = r + 1; i < rows; ++i) {
          if (contains[r][c] - contains[i][c] > 0 and contains[i][c] > 0)
            ret = add_mod(ret, self(self, i, c, cuts - 1));
        }
        for (int i = c + 1; i < cols; ++i) {
          if (contains[r][c] - contains[r][i] > 0 and contains[r][i] > 0)
            ret = add_mod(ret, self(self, r, i, cuts - 1));
        }
        return dp[r][c][cuts] = ret;
      };

      return dfs(dfs, 0, 0, k - 1);
    }
};
```

<br />

### Statistics

- total accepted: 35382
- total submissions: 58831
- acceptance rate: 60.1%
- likes: 1033
- dislikes: 61

<br />

### Similar Problems

- [Selling Pieces of Wood](https://leetcode.com/problems/selling-pieces-of-wood) (Hard)

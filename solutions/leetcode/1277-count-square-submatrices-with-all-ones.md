
**[array, dynamic-programming, matrix]**

### Statement

Given a `m * n` matrix of ones and zeros, return how many **square** submatrices have all ones.


**Example 1:**

```

**Input:** matrix =
[
 [0,1,1,1],
 [1,1,1,1],
 [0,1,1,1]
]
**Output:** 15
**Explanation:** 
There are **10** squares of side 1.
There are **4** squares of side 2.
There is  **1** square of side 3.
Total number of squares = 10 + 4 + 1 = **15**.

```

**Example 2:**

```

**Input:** matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
**Output:** 7
**Explanation:** 
There are **6** squares of side 1.  
There is **1** square of side 2. 
Total number of squares = 6 + 1 = **7**.

```

**Constraints:**
* `1 <= arr.length<= 300`
* `1 <= arr[0].length<= 300`
* `0 <= arr[i][j] <= 1`


<br>

### Hints

- Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
- Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.

<br>

### Solution

**O(n^3)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countSquares (vector <vector <int>>& matrix) {
      int ans = 0;
      int m = matrix.size();
      int n = matrix.front().size();
      
      auto query = [&] (int t, int l, int b, int r) {
        int result = matrix[b][r];
        if (t and l)
          result -= matrix[t - 1][r] + matrix[b][l - 1] - matrix[t - 1][l - 1];
        else if (t)
          result -= matrix[t - 1][r];
        else if (l)
          result -= matrix[b][l - 1];
        return result;
      };
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i and j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + (matrix[i][j] == 1);
          }
          else if (i) {
            matrix[i][j] = matrix[i - 1][j] + (matrix[i][j] == 1);
          }
          else if (j) {
            matrix[i][j] = matrix[i][j - 1] + (matrix[i][j] == 1);
          }
          else if (matrix[i][j] == 1)
            matrix[i][j] = 1;
          
          int min = std::min(i, j);
          
          while (min >= 0) {
            ans += query(i - min, j - min, i, j) == (min + 1) * (min + 1);
            --min;
          }
        }
      }
      
      return ans;
    }
};
```

**O(n^2)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countSquares (vector <vector <int>>& matrix) {
      int ans = 0;
      int m = matrix.size();
      int n = matrix.front().size();
      
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i and j and matrix[i][j] == 1)
            matrix[i][j] = std::min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]}) + 1;
          ans += matrix[i][j];
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 173826
- total submissions: 233864
- acceptance rate: 74.3%
- likes: 3612
- dislikes: 64

<br>

### Similar Problems

- [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid) (Medium)
- [Count Fertile Pyramids in a Land](https://leetcode.com/problems/count-fertile-pyramids-in-a-land) (Hard)

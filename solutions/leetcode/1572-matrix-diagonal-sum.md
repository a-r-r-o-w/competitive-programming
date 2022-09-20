# [1572] Matrix Diagonal Sum

**[array, matrix]**

### Statement

Given asquarematrix`mat`, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png)

```

**Input:** mat = [[**1**,2,**3**],
             [4,**5**,6],
             [**7**,8,**9**]]
**Output:** 25
**Explanation:** Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

```

**Example 2:**

```

**Input:** mat = [[**1**,1,1,**1**],
             [1,**1**,**1**,1],
             [1,**1**,**1**,1],
             [**1**,1,1,**1**]]
**Output:** 8

```

**Example 3:**

```

**Input:** mat = [[**5**]]
**Output:** 5

```

**Constraints:**
* `n == mat.length == mat[i].length`
* `1 <= n <= 100`
* `1 <= mat[i][j] <= 100`


<br>

### Hints

- There will be overlap of elements in the primary and secondary diagonals if and only if the length of the matrix is odd, which is at the center.

<br>

### Solution

```cpp
class Solution {
  public:
    int diagonalSum (vector <vector <int>>& mat) {
      int n = mat.size();
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        ans += mat[i][i];
        if (i != n - i - 1)
          ans += mat[i][n - i - 1];
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 127950
- total submissions: 160963
- acceptance rate: 79.5%
- likes: 1421
- dislikes: 23

<br>

### Similar Problems

- [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) (Easy)
- [Check if Matrix Is X-Matrix](https://leetcode.com/problems/check-if-matrix-is-x-matrix) (Easy)

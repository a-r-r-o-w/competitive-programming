# [2661] First Completely Painted Row or Column



### Statement

You are given a **0-indexed** integer array `arr`, and an `m x n` integer **matrix** `mat`. `arr` and `mat` both contain **all** the integers in the range `[1, m * n]`.

Go through each index `i` in `arr` starting from index `0` and paint the cell in `mat` containing the integer `arr[i]`.

Return *the smallest index* `i` *at which either a row or a column will be completely painted in* `mat`.


**Example 1:**
![](image explanation for example 1)![image explanation for example 1](https://assets.leetcode.com/uploads/2023/01/18/grid1.jpg)

```

**Input:** arr = [1,3,4,2], mat = [[1,4],[2,3]]
**Output:** 2
**Explanation:** The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

```

**Example 2:**
![image explanation for example 2](https://assets.leetcode.com/uploads/2023/01/18/grid2.jpg)

```

**Input:** arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
**Output:** 3
**Explanation:** The second column becomes fully painted at arr[3].

```

**Constraints:**
* `m == mat.length`
* `n = mat[i].length`
* `arr.length == m * n`
* `1 <= m, n <= 10^5`
* `1 <= m * n <= 10^5`
* `1 <= arr[i], mat[r][c] <= m * n`
* All the integers of `arr` are **unique**.
* All the integers of `mat` are **unique**.


<br />

### Hints

- Can we use a frequency array?
- Pre-process the positions of the values in the matrix.
- Traverse the array and increment the corresponding row and column frequency using the pre-processed positions.
- If the row frequency becomes equal to the number of columns, or vice-versa return the current index.

<br />

### Solution

```cpp
class Solution {
  public:
    int firstCompleteIndex (vector <int>& arr, vector <vector <int>>& mat) {
      const int inf32 = 1 << 30;
      int m = mat.size(), n = mat.front().size(), mn = m * n;
      std::vector <int> index (mn);
      int ans = inf32;
      
      for (int i = 0; i < mn; ++i)
        index[arr[i] - 1] = i;
      for (int i = 0; i < m; ++i) {
        int max = -inf32;
        for (int j = 0; j < n; ++j)
          max = std::max(max, index[mat[i][j] - 1]);
        ans = std::min(ans, max);
      }
      for (int j = 0; j < n; ++j) {
        int max = -inf32;
        for (int i = 0; i < m; ++i)
          max = std::max(max, index[mat[i][j] - 1]);
        ans = std::min(ans, max);
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 7217
- total submissions: 15792
- acceptance rate: 45.7%
- likes: 47
- dislikes: 0

<br />

### Similar Problems

- [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) (Easy)
- [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column) (Medium)

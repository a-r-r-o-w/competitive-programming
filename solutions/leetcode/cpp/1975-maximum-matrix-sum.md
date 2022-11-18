# [1975] Maximum Matrix Sum

**[array, greedy, matrix]**

### Statement

You are given an `n x n` integer `matrix`. You can do the following operation **any** number of times:

* Choose any two **adjacent** elements of `matrix` and **multiply** each of them by `-1`.



Two elements are considered **adjacent** if and only if they share a **border**.

Your goal is to **maximize** the summation of the matrix's elements. Return *the **maximum** sum of the matrix's elements using the operation mentioned above.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png)

```

**Input:** matrix = [[1,-1],[-1,1]]
**Output:** 4
**Explanation:** We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png)

```

**Input:** matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
**Output:** 16
**Explanation:** We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.

```

**Constraints:**
* `n == matrix.length == matrix[i].length`
* `2 <= n <= 250`
* `-105 <= matrix[i][j] <= 105`


<br>

### Hints

- Try to use the operation so that each row has only one negative number.
- If you have only one negative element you cannot convert it to positive.

<br>

### Solution

```cpp
class Solution {
  public:
    long long maxMatrixSum (vector <vector <int>>& matrix) {
      int64_t sum = 0;
      int n = matrix.size(), min = 1 << 30, neg = 0;
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (matrix[i][j] < 0)
            ++neg;
          min = std::min(min, std::abs(matrix[i][j]));
          sum += std::abs(matrix[i][j]);
        }
      }
      
      if (neg & 1)
        sum -= 2 * min;
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 12260
- total submissions: 26803
- acceptance rate: 45.7%
- likes: 407
- dislikes: 18

<br>

### Similar Problems

None

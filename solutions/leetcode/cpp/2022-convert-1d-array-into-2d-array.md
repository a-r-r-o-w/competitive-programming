# [2022] Convert 1D Array Into 2D Array

**[array, matrix, simulation]**

### Statement

You are given a **0-indexed** 1-dimensional (1D) integer array `original`, and two integers, `m` and `n`. You are tasked with creating a 2-dimensional (2D) array with  `m` rows and `n` columns using **all** the elements from `original`.

The elements from indices `0` to `n - 1` (**inclusive**) of `original` should form the first row of the constructed 2D array, the elements from indices `n` to `2 * n - 1` (**inclusive**) should form the second row of the constructed 2D array, and so on.

Return *an* `m x n` *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/26/image-20210826114243-1.png)

```

**Input:** original = [1,2,3,4], m = 2, n = 2
**Output:** [[1,2],[3,4]]
**Explanation:** The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.

```

**Example 2:**

```

**Input:** original = [1,2,3], m = 1, n = 3
**Output:** [[1,2,3]]
**Explanation:** The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.

```

**Example 3:**

```

**Input:** original = [1,2], m = 1, n = 1
**Output:** []
**Explanation:** There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.

```

**Constraints:**
* `1 <= original.length <= 5 * 104`
* `1 <= original[i] <= 105`
* `1 <= m, n <= 4 * 104`


<br>

### Hints

- When is it possible to convert original into a 2D array and when is it impossible?
- It is possible if and only if m * n == original.length
- If it is possible to convert original to a 2D array, keep an index i such that original[i] is the next element to add to the 2D array.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> construct2DArray (vector <int>& original, int m, int n) {
      int k = original.size();

      if (k != m * n)
        return {};
      
      int i = 0, j = 0, index = 0;
      std::vector <std::vector <int>> grid (m, std::vector <int> (n));

      while (index < k) {
        grid[i][j] = original[index];
        ++index;
        ++j;
        if (j == n) {
          j = 0;
          ++i;
        }
      }

      return grid;
    }
};
```

<br>

### Statistics

- total accepted: 51351
- total submissions: 87636
- acceptance rate: 58.6%
- likes: 533
- dislikes: 38

<br>

### Similar Problems

- [Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix) (Easy)

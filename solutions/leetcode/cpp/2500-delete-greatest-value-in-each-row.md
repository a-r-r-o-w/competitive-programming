# [2500] Delete Greatest Value in Each Row



### Statement

You are given an `m x n` matrix `grid` consisting of positive integers.

Perform the following operation until `grid` becomes empty:

* Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
* Add the maximum of deleted elements to the answer.


**Note** that the number of columns decreases by one after each operation.

Return *the answer after performing the operations described above*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/10/19/q1ex1.jpg)

```

**Input:** grid = [[1,2,4],[3,3,1]]
**Output:** 8
**Explanation:** The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/10/19/q1ex2.jpg)

```

**Input:** grid = [[10]]
**Output:** 10
**Explanation:** The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.

```

**Constraints:**
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 100`


<br>

### Hints

- Iterate from the first to the last row and if there exist some unmarked cells, take a maximum from them and mark that cell as visited.
- Add a maximum of newly marked cells to answer and repeat that operation until the whole matrix becomes marked.

<br>

### Solution

```cpp
class Solution {
  public:
    int deleteGreatestValue (vector <vector <int>>& grid) {
      for (auto &g: grid)
        std::sort(g.begin(), g.end());
      
      int m = grid.size(), n = grid.front().size();
      int sum = 0;
      
      for (int i = 0; i < n; ++i) {
        int max = 0;
        for (int j = 0; j < m; ++j)
          max = std::max(max, grid[j][i]);
        sum += max;
      }
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 11768
- total submissions: 14258
- acceptance rate: 82.5%
- likes: 76
- dislikes: 7

<br>

### Similar Problems

- [Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs) (Medium)

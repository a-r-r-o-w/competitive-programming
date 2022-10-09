# [120] Triangle

**[array, dynamic-programming]**

### Statement

Given a `triangle` array, return *the minimum path sum from top to bottom*.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.


**Example 1:**

```

**Input:** triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
**Output:** 11
**Explanation:** The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

```

**Example 2:**

```

**Input:** triangle = [[-10]]
**Output:** -10

```

**Constraints:**
* `1 <= triangle.length <= 200`
* `triangle[0].length == 1`
* `triangle[i].length == triangle[i - 1].length + 1`
* `-104 <= triangle[i][j] <= 104`


**Follow up:** Could youdo this using only `O(n)` extra space, where `n` is the total number of rows in the triangle?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumTotal (vector <vector <int>>& triangle) {
      int n = triangle.size();
      
      for (int i = 1; i < n; ++i) {
        triangle[i][0] += triangle[i - 1][0];
        triangle[i][i] += triangle[i - 1][i - 1];
        for (int j = 1; j < i; ++j)
          triangle[i][j] += std::min(triangle[i - 1][j], triangle[i - 1][j - 1]);
      }
      
      return *std::min_element(triangle.back().begin(), triangle.back().end());
    }
};
```

<br>

### Statistics

- total accepted: 483450
- total submissions: 917036
- acceptance rate: 52.7%
- likes: 6236
- dislikes: 413

<br>

### Similar Problems

None

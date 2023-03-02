# [149] Max Points on a Line

**[array, hash-table, math, geometry]**

### Statement

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane, return *the maximum number of points that lie on the same straight line*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg)

```

**Input:** points = [[1,1],[2,2],[3,3]]
**Output:** 3

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg)

```

**Input:** points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
**Output:** 4

```

**Constraints:**
* `1 <= points.length <= 300`
* `points[i].length == 2`
* `-104 <= xi, yi <= 104`
* All the `points` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int maxPoints (vector <vector <int>>& points) {
      int n = points.size(), max = 0;

      if (n == 1)
        return 1;

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          int x = points[j][0] - points[i][0];
          int y = points[j][1] - points[i][1];
          int count = 0;

          for (int k = 0; k < n; ++k) {
            // y - y1 = m * (x - x1)
            int x_ = points[k][0] - points[i][0];
            int y_ = points[k][1] - points[i][1];
            if (y_ * x == y * x_)
              ++count;
          }

          max = std::max(max, count);
        }

      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 269516
- total submissions: 1208192
- acceptance rate: 22.3%
- likes: 1931
- dislikes: 278

<br>

### Similar Problems

- [Line Reflection](https://leetcode.com/problems/line-reflection) (Medium)
- [Minimum Number of Lines to Cover Points](https://leetcode.com/problems/minimum-number-of-lines-to-cover-points) (Medium)
- [Minimum Lines to Represent a Line Chart](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart) (Medium)

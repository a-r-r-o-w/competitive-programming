# [1637] Widest Vertical Area Between Two Points Containing No Points

**[array, sorting]**

### Statement

Given `n` `points` on a 2D plane where `points[i] = [xi, yi]`, Return*the **widest vertical area** between two points such that no points are inside the area.*

A **vertical area** is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The **widest vertical area** is the one with the maximum width.

Note that points **on the edge** of a vertical area **are not** considered included in the area.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/19/points3.png)​

```

**Input:** points = [[8,7],[9,9],[7,4],[9,7]]
**Output:** 1
**Explanation:** Both the red and the blue area are optimal.

```

**Example 2:**

```

**Input:** points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
**Output:** 3

```

**Constraints:**
* `n == points.length`
* `2 <= n <= 105`
* `points[i].length == 2`
* `0 <= xi, yi<= 109`


<br>

### Hints

- Try sorting the points
- Think is the y-axis of a point relevant

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    int maxWidthOfVerticalArea (vector <vector <int>>& points) {
      std::sort(points.begin(), points.end(), [] (auto &l, auto &r) {
        return l[0] < r[0];
      });
      
      int max = 0;
      
      for (int i = 0; i < (int)points.size() - 1; ++i)
        max = std::max(max, points[i + 1][0] - points[i][0]);
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 32206
- total submissions: 38290
- acceptance rate: 84.1%
- likes: 217
- dislikes: 579

<br>

### Similar Problems

None

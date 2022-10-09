# [1779] Find Nearest Point That Has the Same X or Y Coordinate

**[array]**

### Statement

You are given two integers, `x` and `y`, which represent your current location on a Cartesian grid: `(x, y)`. You are also given an array `points` where each `points[i] = [ai, bi]` represents that a point exists at `(ai, bi)`. A point is **valid** if it shares the same x-coordinate or the same y-coordinate as your location.

Return *the index **(0-indexed)** of the **valid** point with the smallest **Manhattan distance** from your current location*. If there are multiple, return *the valid point with the **smallest** index*. If there are no valid points, return `-1`.

The **Manhattan distance** between two points `(x1, y1)` and `(x2, y2)` is `abs(x1 - x2) + abs(y1 - y2)`.


**Example 1:**

```

**Input:** x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
**Output:** 2
**Explanation:** Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.
```

**Example 2:**

```

**Input:** x = 3, y = 4, points = [[3,4]]
**Output:** 0
**Explanation:** The answer is allowed to be on the same location as your current location.
```

**Example 3:**

```

**Input:** x = 3, y = 4, points = [[2,3]]
**Output:** -1
**Explanation:** There are no valid points.
```

**Constraints:**
* `1 <= points.length <= 104`
* `points[i].length == 2`
* `1 <= x, y, ai, bi <= 104`


<br>

### Hints

- Iterate through each point, and keep track of the current point with the smallest Manhattan distance from your current location.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int nearestValidPoint (int x, int y, vector <vector <int>>& points) {
      int dist = 1 << 30;
      int index = -1, i = 0;
      
      for (auto &p: points) {
        if (p[0] == x and std::abs(y - p[1]) < dist) {
          dist = std::abs(y - p[1]);
          index = i;
        }
        if (p[1] == y and std::abs(x - p[0]) < dist) {
          dist = std::abs(x - p[0]);
          index = i;
        }
        ++i;
      }
      
      return index;
    }
};
```

<br>

### Statistics

- total accepted: 68955
- total submissions: 102246
- acceptance rate: 67.4%
- likes: 544
- dislikes: 104

<br>

### Similar Problems

- [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) (Medium)

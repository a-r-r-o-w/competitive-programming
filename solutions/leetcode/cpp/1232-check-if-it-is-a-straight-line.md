# [1232] Check If It Is a Straight Line

**[array, math, geometry]**

### Statement

You are given an array`coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these pointsmake a straight line in the XY plane.




**Example 1:**
![](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)

```

**Input:** coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
**Output:** true

```

**Example 2:**
**![](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)**

```

**Input:** coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
**Output:** false

```

**Constraints:**
* `2 <=coordinates.length <= 1000`
* `coordinates[i].length == 2`
* `-10^4 <=coordinates[i][0],coordinates[i][1] <= 10^4`
* `coordinates`contains no duplicate point.


<br>

### Hints

- If there're only 2 points, return true.
- Check if all other points lie on the line defined by the first 2 points.
- Use cross product to check collinearity.

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkStraightLine (vector <vector <int>>& coordinates) {
      std::set <std::pair <int, int>> slope;
      int n = coordinates.size();
      
      auto sx = coordinates[0][0] - coordinates[1][0];
      auto sy = coordinates[0][1] - coordinates[1][1];
      
      for (int i = 1; i < n; ++i) {
        auto px = coordinates[0][0] - coordinates[i][0];
        auto py = coordinates[0][1] - coordinates[i][1];
        
        if (px * sy != py * sx)
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 128613
- total submissions: 310909
- acceptance rate: 41.4%
- likes: 1060
- dislikes: 160

<br>

### Similar Problems

None

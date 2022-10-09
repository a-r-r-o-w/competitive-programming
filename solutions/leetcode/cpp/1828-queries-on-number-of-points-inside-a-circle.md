# [1828] Queries on Number of Points Inside a Circle

**[array, math, geometry]**

### Statement

You are given an array `points` where `points[i] = [xi, yi]` is the coordinates of the `ith` point on a 2D plane. Multiple points can have the **same** coordinates.

You are also given an array `queries` where `queries[j] = [xj, yj, rj]` describes a circle centered at `(xj, yj)` with a radius of `rj`.

For each query `queries[j]`, compute the number of points **inside** the `jth` circle. Points **on the border** of the circle are considered **inside**.

Return *an array* `answer`*, where* `answer[j]` *is the answer to the* `jth` *query*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/25/chrome_2021-03-25_22-34-16.png)

```

**Input:** points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
**Output:** [3,2,2]
**Explanation:** The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/03/25/chrome_2021-03-25_22-42-07.png)

```

**Input:** points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
**Output:** [2,3,2,4]
**Explanation:** The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.

```

**Constraints:**
* `1 <= points.length <= 500`
* `points[i].length == 2`
* `0 <= x​​​​​​i, y​​​​​​i <= 500`
* `1 <= queries.length <= 500`
* `queries[j].length == 3`
* `0 <= xj, yj <= 500`
* `1 <= rj <= 500`
* All coordinates are integers.


**Follow up:** Could you find the answer for each query in better complexity than `O(n)`?

<br>

### Hints

- For a point to be inside a circle, the euclidean distance between it and the circle's center needs to be less than or equal to the radius.
- Brute force for each circle and iterate overall points and find those inside it.

<br>

### Solution

**Using the equation of a circle**

```cpp
class Solution {
  public:
    vector <int> countPoints (vector <vector <int>>& points, vector <vector <int>>& queries) {
      // eqn. of a circle: (x - xi) ** 2 + (y - yi) ** 2 = r ** 2
      
      std::vector <int> ans;
      
      for (auto& circle: queries) {
        ans.push_back(0);
        
        for (auto& point: points) {
          int p = point[0] - circle[0];
          int q = point[1] - circle[1];
          int r = circle[2];
          
          if (p * p + q * q <= r * r)
            ++ans.back();
        }
      }
      
      return ans;
    }
};
```

**Binary searching for optimal points range**

```cpp
class Solution {
  public:
    vector <int> countPoints (vector <vector <int>>& points, vector <vector <int>>& queries) {
      std::sort(points.begin(), points.end());
      
      std::vector <int> ans;
      int n = points.size();
      
      for (auto& circle: queries) {
        ans.push_back(0);
        
        int lowleft = 0, highleft = n;
        
        while (lowleft < highleft) {
          int mid = (lowleft + highleft) / 2;
          int x = points[mid][0];
          int y = points[mid][1];
          
          if (x < circle[0] - circle[2])
            lowleft = mid + 1;
          else
            highleft = mid;
        }
        
        int lowright = 0, highright = n;
        
        while (lowright < highright) {
          int mid = (lowright + highright) / 2;
          int x = points[mid][0];
          int y = points[mid][1];
          
          if (x <= circle[0] + circle[2])
            lowright = mid + 1;
          else
            highright = mid;
        }
        
        for (int i = lowleft; i < lowright; ++i) {
          int x = points[i][0];
          int y = points[i][1];
          int p = x - circle[0];
          int q = y - circle[1];
          int r = circle[2];
          
          if (p * p + q * q <= r * r)
            ++ans.back();
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 42242
- total submissions: 48896
- acceptance rate: 86.4%
- likes: 620
- dislikes: 57

<br>

### Similar Problems

- [Count Lattice Points Inside a Circle](https://leetcode.com/problems/count-lattice-points-inside-a-circle) (Medium)
- [Count Number of Rectangles Containing Each Point](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point) (Medium)

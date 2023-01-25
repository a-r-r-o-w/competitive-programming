# [973] K Closest Points to Origin

**[array, math, divide-and-conquer, geometry, sorting, heap-priority-queue, quickselect]**

### Statement

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be **unique** (except for the order that it is in).


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)

```

**Input:** points = [[1,3],[-2,2]], k = 1
**Output:** [[-2,2]]
**Explanation:**
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

```

**Example 2:**

```

**Input:** points = [[3,3],[5,-1],[-2,4]], k = 2
**Output:** [[3,3],[-2,4]]
**Explanation:** The answer [[-2,4],[3,3]] would also be accepted.

```

**Constraints:**
* `1 <= k <= points.length <= 104`
* `-104 < xi, yi < 104`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> kClosest (vector <vector <int>>& points, int k) {
      std::sort(points.begin(), points.end(), [] (auto &l, auto &r) {
        return l[0] * l[0] + l[1] * l[1] < r[0] * r[0] + r[1] * r[1];
      });
      points.resize(k);
      return points;
    }
};
```

<br>

### Statistics

- total accepted: 935526
- total submissions: 1421440
- acceptance rate: 65.8%
- likes: 7038
- dislikes: 259

<br>

### Similar Problems

- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) (Medium)
- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) (Medium)
- [Find Nearest Point That Has the Same X or Y Coordinate](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate) (Easy)

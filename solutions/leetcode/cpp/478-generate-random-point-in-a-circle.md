# [478] Generate Random Point in a Circle

**[math, geometry, rejection-sampling, randomized]**

### Statement

Given the radius and the position of the center of a circle, implement the function `randPoint` which generates a uniform random point inside the circle.

Implement the `Solution` class:

* `Solution(double radius, double x_center, double y_center)` initializes the object with the radius of the circle `radius` and the position of the center `(x_center, y_center)`.
* `randPoint()` returns a random point inside the circle. A point on the circumference of the circle is considered to be in the circle. The answer is returned as an array `[x, y]`.


**Example 1:**

```

**Input**
["Solution", "randPoint", "randPoint", "randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
**Output**
[null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]

**Explanation**
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint(); // return [-0.02493, -0.38077]
solution.randPoint(); // return [0.82314, 0.38945]
solution.randPoint(); // return [0.36572, 0.17248]

```

**Constraints:**
* `0 <radius <= 108`
* `-10^7 <= x_center, y_center <= 10^7`
* At most `3 * 104` calls will be made to `randPoint`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
    double pi = std::acos(-1);
    double r, x, y;
    std::mt19937 rng { std::random_device {}() };
    std::uniform_real_distribution <double> dist {0.0, 1.0};

  public:
    Solution (double radius, double x_center, double y_center) {
      r = radius;
      x = x_center;
      y = y_center;
    }
    
    vector <double> randPoint () {
      std::vector <double> point (2);
      double length = r * std::sqrt(dist(rng));
      double angle = 2 * pi * dist(rng);

      point[0] = x + length * std::cos(angle);
      point[1] = y + length * std::sin(angle);

      return point;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
```

<br>

### Statistics

- total accepted: 36154
- total submissions: 91436
- acceptance rate: 39.5%
- likes: 393
- dislikes: 713

<br>

### Similar Problems

- [Random Point in Non-overlapping Rectangles](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles) (Medium)

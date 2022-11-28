# [2481] Minimum Cuts to Divide a Circle



### Statement

A **valid cut** in a circle can be:

* A cut that is represented by a straight line that touches two points on the edge of the circle and passes through its center, or
* A cut that is represented by a straight line that touches one point on the edge of the circle and its center.



Some valid and invalid cuts are shown in the figures below.
![](https://assets.leetcode.com/uploads/2022/10/29/alldrawio.png)
Given the integer `n`, return *the **minimum** number of cuts needed to divide a circle into* `n` *equal slices*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/10/24/11drawio.png)

```

**Input:** n = 4
**Output:** 2
**Explanation:** 
The above figure shows how cutting the circle twice through the middle divides it into 4 equal slices.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/10/24/22drawio.png)

```

**Input:** n = 3
**Output:** 3
**Explanation:**
At least 3 cuts are needed to divide the circle into 3 equal slices. 
It can be shown that less than 3 cuts cannot result in 3 slices of equal size and shape.
Also note that the first cut will not divide the circle into distinct parts.

```

**Constraints:**
* `1 <= n <= 100`


<br>

### Hints

- Think about odd and even values separately.
- When will we not have to cut the circle at all?

<br>

### Solution

```cpp
class Solution {
  public:
    int numberOfCuts (int n) {
      if (n == 1)
        return 0;
      else if (n & 1)
        return n;
      else
        return n / 2;
    }
};
```

<br>

### Statistics

- total accepted: 11873
- total submissions: 23467
- acceptance rate: 50.6%
- likes: 52
- dislikes: 17

<br>

### Similar Problems

- [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple) (Easy)

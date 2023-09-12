# [2848] Points That Intersect With Cars



### Statement

You are given a **0-indexed** 2D integer array `nums` representing the coordinates of the cars parking on a number line. For any index `i`, `nums[i] = [starti, endi]` where `starti` is the starting point of the `i^th` car and `endi` is the ending point of the `i^th` car.

Return *the number of integer points on the line that are covered with **any part** of a car.*
**Example 1:**

```

**Input:** nums = [[3,6],[1,5],[4,7]]
**Output:** 7
**Explanation:** All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.

```

**Example 2:**

```

**Input:** nums = [[1,3],[5,8]]
**Output:** 7
**Explanation:** Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `nums[i].length == 2`
* `1 <= starti<= endi<= 100`


<br />

### Hints

- Sort the array according to first element and then starting from the <code>0<sup>th</sup></code> index remove the overlapping parts and return the count of non-overlapping points.

<br />

### Solution

```cpp
class Solution {
  public:
    int numberOfPoints(vector <vector <int>>& nums) {
      const int maxn = 100 + 42;
      int n = nums.size();
      std::vector <int> used(maxn);
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        ++used[nums[i][0]];
        --used[nums[i][1] + 1];
      }
      for (int i = 1; i < maxn; ++i) {
        used[i] += used[i - 1];
        if (used[i] > 0)
          ++ans;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 20707
- total submissions: 27901
- acceptance rate: 74.2%
- likes: 69
- dislikes: 2

<br />

### Similar Problems

- [Merge Intervals](https://leetcode.com/problems/merge-intervals) (Medium)
- [Meeting Rooms](https://leetcode.com/problems/meeting-rooms) (Easy)
- [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii) (Medium)

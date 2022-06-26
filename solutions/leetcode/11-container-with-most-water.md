# [11] Container With Most Water

**[array, two-pointers, greedy]**

### Statement

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.


**Example 1:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

```

**Input:** height = [1,8,6,2,5,4,8,3,7]
**Output:** 49
**Explanation:** The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

```

**Example 2:**

```

**Input:** height = [1,1]
**Output:** 1

```

**Constraints:**
* `n == height.length`
* `2 <= n <= 105`
* `0 <= height[i] <= 104`


<br>

### Hints

- The aim is to maximize the area formed between the vertical lines. The area of any container is calculated using the shorter line as length and the distance between the lines as the width of the rectangle.

<pre>
Area = length of shorter vertical line * distance between lines
</pre>

We can definitely get the maximum width container as the outermost lines have the maximum distance between them. However, this container <b>might not be the maximum in size</b> as one of the vertical lines of this container could be really short.

<br>
<img src="https://assets.leetcode.com/uploads/2019/10/20/hint_water_trap_1.png" width="500"/>

<br>
<img src="https://assets.leetcode.com/uploads/2019/10/20/hint_water_trap_2.png" width="500"/>
- Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxArea (vector <int>& height) {
      int n = height.size();
      int max = 0;
      
      // find min(a[i], a[j]) * (j - i) such that i < j
      // sort by a[i]
      // find maximum index in suffix of a[i] after sorting
      
      // for (int i = 0; i < n - 1; ++i) {
      //   for (int j = i + 1; j < n; ++j) {
      //     max = std::max(max, std::min(a[i], a[j]) * (j - i));
      //   }
      // }
      
      std::vector <int> order (n);
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return height[l] < height[r];
      });
      
      std::vector <bool> used (n);
      int l = 0, r = n - 1;
      
      for (int i = 0; i < n - 1; ++i) {
        int j = order[i];
        while (used[l])
          ++l;
        while (used[r])
          --r;
        max = std::max(max, std::max(std::abs(l - j), std::abs(r - j)) * height[j]);
        used[j] = true;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 1566345
- total submissions: 2897610
- acceptance rate: 54.1%
- likes: 17863
- dislikes: 975

<br>

### Similar Problems

- [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water) (Hard)

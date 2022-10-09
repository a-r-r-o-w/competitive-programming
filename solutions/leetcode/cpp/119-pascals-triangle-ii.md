# [119] Pascal's Triangle II

**[array, dynamic-programming]**

### Statement

Given an integer `rowIndex`, return the `rowIndexth` (**0-indexed**) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:
![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
**Example 1:**

```
**Input:** rowIndex = 3
**Output:** [1,3,3,1]

```
**Example 2:**

```
**Input:** rowIndex = 0
**Output:** [1]

```
**Example 3:**

```
**Input:** rowIndex = 1
**Output:** [1,1]

```

**Constraints:**
* `0 <= rowIndex <= 33`


**Follow up:** Could you optimize your algorithm to use only `O(rowIndex)` extra space?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> getRow (int rowIndex) {
      std::vector <int> x (rowIndex + 1, 1);
      for (int i = 0; i < rowIndex; ++i) {
        for (int j = i; j >= 1; --j)
          x[j] += x[j - 1];
      }
      return x;
    }
};
```

<br>

### Statistics

- total accepted: 535818
- total submissions: 923599
- acceptance rate: 58.0%
- likes: 2672
- dislikes: 271

<br>

### Similar Problems

- [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle) (Easy)
- [Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array) (Medium)

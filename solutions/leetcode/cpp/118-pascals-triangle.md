# [118] Pascal's Triangle

**[array, dynamic-programming]**

### Statement

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:
![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
**Example 1:**

```
**Input:** numRows = 5
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

```
**Example 2:**

```
**Input:** numRows = 1
**Output:** [[1]]

```

**Constraints:**
* `1 <= numRows <= 30`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> generate (int numRows) {
      std::vector <std::vector <int>> p;
      std::vector <int> x;
      
      x.reserve(numRows); // saves time in push_back
      x.push_back(1);
      int n = 1;
      
      for (int i = 0; i < numRows; ++i) {
        p.push_back(x);
        x.push_back(1);
        n += 1;
        for (int j = n - 2; j >= 1; --j)
          x[j] += x[j - 1];
      }
      
      return p;
    }
};
```

<br>

### Statistics

- total accepted: 827989
- total submissions: 1264883
- acceptance rate: 65.5%
- likes: 6065
- dislikes: 218

<br>

### Similar Problems

- [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii) (Easy)

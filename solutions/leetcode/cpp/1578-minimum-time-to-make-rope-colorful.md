# [1578] Minimum Time to Make Rope Colorful

**[array, string, dynamic-programming, greedy]**

### Statement

Alice has `n` balloons arranged on a rope. You are given a **0-indexed** string `colors` where `colors[i]` is the color of the `ith` balloon.

Alice wants the rope to be **colorful**. She does not want **two consecutive balloons** to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it **colorful**. You are given a **0-indexed** integer array `neededTime` where `neededTime[i]` is the time (in seconds) that Bob needs to remove the `ith` balloon from the rope.

Return *the **minimum time** Bob needs to make the rope **colorful***.


**Example 1:**
![](https://assets.leetcode.com/uploads/2021/12/13/ballon1.jpg)

```

**Input:** colors = "abaac", neededTime = [1,2,3,4,5]
**Output:** 3
**Explanation:** In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
```

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/12/13/balloon2.jpg)

```

**Input:** colors = "abc", neededTime = [1,2,3]
**Output:** 0
**Explanation:** The rope is already colorful. Bob does not need to remove any balloons from the rope.

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2021/12/13/balloon3.jpg)

```

**Input:** colors = "aabaa", neededTime = [1,2,3,4,1]
**Output:** 2
**Explanation:** Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.

```

**Constraints:**
* `n == colors.length == neededTime.length`
* `1 <= n <= 105`
* `1 <= neededTime[i] <= 104`
* `colors` contains only lowercase English letters.


<br>

### Hints

- Maintain the running sum and max value for repeated letters.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int minCost (string colors, vector <int>& neededTime) {
      int n = neededTime.size();
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        int sum = 0, max = 0;
        
        while (j < n and colors[i] == colors[j]) {
          sum += neededTime[j];
          max = std::max(max, neededTime[j]);
          ++j;
        }
        
        i = j - 1;
        ans += sum - max;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 75300
- total submissions: 123000
- acceptance rate: 61.2%
- likes: 1309
- dislikes: 49

<br>

### Similar Problems

None

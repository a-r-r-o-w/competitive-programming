# [2358] Maximum Number of Groups Entering a Competition



### Statement

You are given a positive integer array `grades` which represents the grades of students in a university. You would like to enter **all** these students into a competition in **ordered** non-empty groups, such that the ordering meets the following conditions:

* The sum of the grades of students in the `ith` group is **less than** the sum of the grades of students in the `(i + 1)th` group, for all groups (except the last).
* The total number of students in the `ith` group is **less than** the total number of students in the `(i + 1)th` group, for all groups (except the last).



Return *the **maximum** number of groups that can be formed*.


**Example 1:**

```

**Input:** grades = [10,6,12,7,3,5]
**Output:** 3
**Explanation:** The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.

```

**Example 2:**

```

**Input:** grades = [8,8]
**Output:** 1
**Explanation:** We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.

```

**Constraints:**
* `1 <= grades.length <= 10^5`
* `1 <= grades[i] <= 10^5`


<br>

### Hints

- Would it be easier to place the students into valid groups after sorting them based on their grades in ascending order?
- Notice that, after sorting, we can separate them into groups of sizes 1, 2, 3, and so on.
- If the last group is invalid, we can merge it with the previous group.
- This creates the maximum number of groups because we always greedily form the smallest possible group.

<br>

### Solution

**O(sqrt(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximumGroups (vector <int>& grades) {
      int n = grades.size();
      int ans = 0;
      
      while (ans * (ans + 1) / 2 <= n)
        ++ans;
      
      return ans - 1;
    }
};
```

**O(log(n))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maximumGroups (vector <int>& grades) {
      int n = grades.size();
      
      if (n == 1)
        return 1;
      
      int low = 0, high = n;
      
      while (low < high) {
        int64_t mid = (low + high) / 2;
        int64_t x = mid * (mid + 1) / 2;
        if (x <= n)
          low = mid + 1;
        else
          high = mid;
      }
      
      return low - 1;
    }
};
```

<br>

### Statistics

- total accepted: 9459
- total submissions: 15125
- acceptance rate: 62.5%
- likes: 51
- dislikes: 29

<br>

### Similar Problems

- [Maximum Height by Stacking Cuboids ](https://leetcode.com/problems/maximum-height-by-stacking-cuboids) (Hard)

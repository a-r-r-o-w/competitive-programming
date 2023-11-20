# [1035] Uncrossed Lines

**[array, dynamic-programming]**

### Statement

You are given two integer arrays `nums1` and `nums2`. We write the integers of `nums1` and `nums2` (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers `nums1[i]` and `nums2[j]` such that:

* `nums1[i] == nums2[j]`, and
* the line we draw does not intersect any other connecting (non-horizontal) line.



Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return *the maximum number of connecting lines we can draw in this way*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2019/04/26/142.png)

```

**Input:** nums1 = [1,4,2], nums2 = [1,2,4]
**Output:** 2
**Explanation:** We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.

```

**Example 2:**

```

**Input:** nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
**Output:** 3

```

**Example 3:**

```

**Input:** nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
**Output:** 2

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 500`
* `1 <= nums1[i], nums2[j] <= 2000`


<br />

### Hints

- Think dynamic programming.  Given an oracle dp(i,j) that tells us how many lines A[i:], B[j:]  [the sequence A[i], A[i+1], ... and B[j], B[j+1], ...] are uncrossed, can we write this as a recursion?

<br />

### Solution

O(nm) space

```cpp
class Solution {
  public:
    int maxUncrossedLines (vector <int>& nums1, vector <int>& nums2) {
      int n = nums1.size(), m = nums2.size();
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (m + 1));

      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (nums1[i - 1] == nums2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }

      return dp[n][m];
    }
};
```

O(min(n, m)) space

```cpp
class Solution {
  public:
    int maxUncrossedLines (vector <int>& nums1, vector <int>& nums2) {
      if (nums1.size() < nums2.size())
        std::swap(nums1, nums2);
      
      int n = nums1.size(), m = nums2.size();
      std::vector <std::vector <int>> dp (2, std::vector <int> (m + 1));

      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (nums1[i - 1] == nums2[j - 1])
            dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
          else
            dp[i % 2][j] = std::max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
      }

      return dp[n % 2][m];
    }
};
```

<br />

### Statistics

- total accepted: 88148
- total submissions: 146216
- acceptance rate: 60.3%
- likes: 2332
- dislikes: 31

<br />

### Similar Problems

- [Edit Distance](https://leetcode.com/problems/edit-distance) (Hard)

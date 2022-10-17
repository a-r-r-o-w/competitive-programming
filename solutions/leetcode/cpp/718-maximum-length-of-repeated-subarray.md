# [718] Maximum Length of Repeated Subarray

**[array, binary-search, dynamic-programming, sliding-window, rolling-hash, hash-function]**

### Statement

Given two integer arrays `nums1` and `nums2`, return *the maximum length of a subarray that appears in **both** arrays*.


**Example 1:**

```

**Input:** nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
**Output:** 3
**Explanation:** The repeated subarray with maximum length is [3,2,1].

```

**Example 2:**

```

**Input:** nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
**Output:** 5

```

**Constraints:**
* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 100`


<br>

### Hints

- Use dynamic programming.  dp[i][j] will be the answer for inputs A[i:], B[j:].

<br>

### Solution

**Time: O(n.m)**
**Space: O(n.m)**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findLength (vector <int>& nums1, vector <int>& nums2) {
      if (nums1.size() > nums2.size())
        std::swap(nums1, nums2);
      
      int n = nums1.size();
      int m = nums2.size();
      
      std::vector <std::vector <int>> dp (n + 1, std::vector <int> (m + 1));
      int max = 0;
      
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (nums1[i - 1] == nums2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = 0;
          max = std::max(max, dp[i][j]);
        }
      }
      
      return max;
    }
};
```

**Time: O(n.m)**
**Space: O(min(n, m))**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findLength (vector <int>& nums1, vector <int>& nums2) {
      if (nums1.size() < nums2.size())
        std::swap(nums1, nums2);
      
      int n = nums1.size();
      int m = nums2.size();
      
      std::vector <int> dp (m + 1);
      int max = 0;
      
      for (int i = 1; i <= n; ++i) {
        int prev = 0;
        
        for (int j = 1; j <= m; ++j) {
          if (nums1[i - 1] == nums2[j - 1]) {
            int t = dp[j];
            dp[j] = prev + 1;
            prev = t;
          }
          else {
            int t = dp[j];
            dp[j] = 0;
            prev = t;
          }
          max = std::max(max, dp[j]);
        }
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 214799
- total submissions: 417281
- acceptance rate: 51.5%
- likes: 5041
- dislikes: 123

<br>

### Similar Problems

- [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) (Medium)
- [Longest Common Subpath](https://leetcode.com/problems/longest-common-subpath) (Hard)

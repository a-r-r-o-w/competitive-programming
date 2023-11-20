# [1043] Partition Array for Maximum Sum

**[array, dynamic-programming]**

### Statement

Given an integer array `arr`, partition the array into (contiguous) subarrays of length **at most** `k`. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return *the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a **32-bit** integer.*
**Example 1:**

```

**Input:** arr = [1,15,7,9,2,5,10], k = 3
**Output:** 84
**Explanation:** arr becomes [15,15,15,9,10,10,10]

```

**Example 2:**

```

**Input:** arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
**Output:** 83

```

**Example 3:**

```

**Input:** arr = [1], k = 1
**Output:** 1

```

**Constraints:**
* `1 <= arr.length <= 500`
* `0 <= arr[i] <= 10^9`
* `1 <= k <= arr.length`


<br />

### Hints

- Think dynamic programming:  dp[i] will be the answer for array A[0], ..., A[i-1].
- For j = 1 .. k that keeps everything in bounds, dp[i] is the maximum of dp[i-j] + max(A[i-1], ..., A[i-j]) * j .

<br />

### Solution

O(N.K) Memory DP

```cpp
class Solution {
  public:
    int maxSumAfterPartitioning (vector <int>& arr, int k) {
      int n = arr.size();
      std::vector dp (n, std::vector(k + 1, -1));

      auto dfs = [&] (auto self, int index, int count, int max) -> int {
        if (index >= n)
          return count * max;
        if (dp[index][count] != -1)
          return dp[index][count];
        
        int ans = 0;
        
        if (count < k)
          ans = std::max(ans, self(self, index + 1, count + 1, std::max(max, arr[index])));
        ans = std::max(ans, count * max + self(self, index + 1, 1, arr[index]));

        return dp[index][count] = ans;
      };
      
      return dfs(dfs, 0, 0, 0);
    }
};
```

O(N) Memory DP

```cpp
class Solution {
  public:
    int maxSumAfterPartitioning (vector <int>& arr, int k) {
      int n = arr.size();
      std::vector dp (n + 1, 0LL);

      for (int i = 1; i <= n; ++i) {
        int max = 0;
        for (int j = 1; j <= k and j <= i; ++j) {
          max = std::max(max, arr[i - j]);
          dp[i] = std::max(dp[i], dp[i - j] + j * max);
        }
      }

      return dp[n];
    }
};
```

O(K) Memory DP

```cpp
class Solution {
  public:
    int maxSumAfterPartitioning (vector <int>& arr, int k) {
      int n = arr.size();
      std::vector dp (k, 0LL);

      for (int i = 1; i <= n; ++i) {
        int max = 0, ans = 0;
        for (int j = 1; j <= k and j <= i; ++j) {
          max = std::max(max, arr[i - j]);
          ans = std::max <int> (ans, dp[(i - j) % k] + j * max);
        }
        dp[i % k] = ans;
      }

      return dp[n % k];
    }
};
```

<br />

### Statistics

- total accepted: 75409
- total submissions: 105063
- acceptance rate: 71.8%
- likes: 3354
- dislikes: 236

<br />

### Similar Problems

- [Subsequence of Size K With the Largest Even Sum](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum) (Medium)

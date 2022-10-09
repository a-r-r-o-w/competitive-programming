# [1696] Jump Game VI

**[array, dynamic-programming, queue, sliding-window, heap-priority-queue, monotonic-queue]**

### Statement

You are given a **0-indexed** integer array `nums` and an integer `k`.

You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.

You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.

Return the **maximum score** you can get.


**Example 1:**

```

**Input:** nums = [1,-1,-2,4,-7,3], k = 2
**Output:** 7
**Explanation:** You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

```

**Example 2:**

```

**Input:** nums = [10,-5,-2,4,0,3], k = 3
**Output:** 17
**Explanation:** You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

```

**Example 3:**

```

**Input:** nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
**Output:** 0

```

**Constraints:**
* `1 <= nums.length, k <= 105`
* `-104 <= nums[i] <= 104`


<br>

### Hints

- Let dp[i] be "the maximum score to reach the end starting at index i". The answer for dp[i] is nums[i] + max{dp[i+j]} for 1 <= j <= k. That gives an `O(n*k)` solution.
- Instead of checking every j for every i, keep track of the largest dp[i] values in a heap and calculate dp[i] from right to left. When the largest value in the heap is out of bounds of the current index, remove it and keep checking.

<br>

### Solution

**O(n.log(k)) DP solution**

```cpp
class Solution {
  public:
    int maxResult (vector <int>& nums, int k) {
      int n = nums.size();
      std::vector <int> dp (n);
      std::multiset <int> max;
      
      dp[0] = nums[0];
      max.insert(dp[0]);
      
      for (int i = 1; i < n; ++i) {
        dp[i] = nums[i] + *max.rbegin();
        max.insert(dp[i]);
        if (i >= k)
          max.erase(max.find(dp[i - k]));
      }
      
      return dp[n - 1];
    }
};
```

**O(n) DP solution using monotonic queue**

```cpp
class Solution {
  public:
    int maxResult (vector <int>& nums, int k) {
      int n = nums.size();
      std::deque <int> dq;
      
      dq.push_back(0);
      
      for (int i = 1; i < n; ++i) {
        while (dq.front() + k < i)
          dq.pop_front();
        
        nums[i] += nums[dq.front()];
        
        while (!dq.empty() and nums[dq.back()] <= nums[i])
          dq.pop_back();
        
        dq.push_back(i);
      }
      
      return nums[n - 1];
    }
};
```

<br>

### Statistics

- total accepted: 67007
- total submissions: 150230
- acceptance rate: 44.6%
- likes: 2231
- dislikes: 82

<br>

### Similar Problems

- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) (Hard)
- [Jump Game VII](https://leetcode.com/problems/jump-game-vii) (Medium)
- [Jump Game VIII](https://leetcode.com/problems/jump-game-viii) (Medium)

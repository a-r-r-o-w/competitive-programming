# [239] Sliding Window Maximum

**[array, queue, sliding-window, heap-priority-queue, monotonic-queue]**

### Statement

You are given an array of integers`nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.


**Example 1:**

```

**Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3
**Output:** [3,3,5,5,6,7]
**Explanation:** 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       **3**
 1 [3  -1  -3] 5  3  6  7       **3**
 1  3 [-1  -3  5] 3  6  7       **5**
 1  3  -1 [-3  5  3] 6  7       **5**
 1  3  -1  -3 [5  3  6] 7       **6**
 1  3  -1  -3  5 [3  6  7]      **7**

```

**Example 2:**

```

**Input:** nums = [1], k = 1
**Output:** [1]

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`
* `1 <= k <= nums.length`


<br>

### Hints

- How about using a data structure such as deque (double-ended queue)?
- The queue size need not be the same as the window’s size.
- Remove redundant elements and the queue should store only elements that need to be considered.

<br>

### Solution

**Multiset**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> maxSlidingWindow (vector <int>& nums, int k) {
      int n = nums.size();
      std::multiset <int> have;
      std::vector <int> ans;
      
      ans.reserve(n - k + 1);
      
      for (int i = 0; i < k; ++i)
        have.insert(nums[i]);
      ans.push_back(*have.rbegin());
      
      for (int i = k; i < n; ++i) {
        have.erase(have.find(nums[i - k]));
        have.insert(nums[i]);
        ans.push_back(*have.rbegin());
      }
      
      return ans;
    }
};
```

**Dequeue**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <int> maxSlidingWindow (vector <int>& nums, int k) {
      int n = nums.size();
      std::deque <int> have;
      std::vector <int> ans;
      
      ans.reserve(n - k + 1);
      
      for (int i = 0; i < k; ++i) {
        while (!have.empty() and nums[i] >= nums[have.back()])
          have.pop_back();
        have.push_back(i);
      }
      
      ans.push_back(nums[have.front()]);
      
      for (int i = k; i < n; ++i) {
        while (!have.empty() and have.front() <= i - k)
          have.pop_front();
        
        while (!have.empty() and nums[i] >= nums[have.back()])
          have.pop_back();
        
        have.push_back(i);
        ans.push_back(nums[have.front()]);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 646092
- total submissions: 1388839
- acceptance rate: 46.5%
- likes: 11832
- dislikes: 381

<br>

### Similar Problems

- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) (Hard)
- [Min Stack](https://leetcode.com/problems/min-stack) (Medium)
- [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters) (Medium)
- [Paint House II](https://leetcode.com/problems/paint-house-ii) (Hard)
- [Jump Game VI](https://leetcode.com/problems/jump-game-vi) (Medium)
- [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget) (Hard)

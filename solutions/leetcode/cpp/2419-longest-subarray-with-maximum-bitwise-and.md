# [2419] Longest Subarray With Maximum Bitwise AND



### Statement

You are given an integer array `nums` of size `n`.

Consider a **non-empty** subarray from `nums` that has the **maximum** possible **bitwise AND**.

* In other words, let `k` be the maximum value of the bitwise AND of **any** subarray of `nums`. Then, only subarrays with a bitwise AND equal to `k` should be considered.



Return *the length of the **longest** such subarray*.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A **subarray** is a contiguous sequence of elements within an array.


**Example 1:**

```

**Input:** nums = [1,2,3,3,2,2]
**Output:** 2
**Explanation:**
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** 1
**Explanation:**
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^6`


<br>

### Hints

- Notice that the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
- What does that tell us about the nature of the subarray that we should choose?

<br>

### Solution

Simulating the process

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestSubarray (vector <int>& nums) {
      int n = nums.size();
      int pos = std::max_element(nums.begin(), nums.end()) - nums.begin();
      int max_count = 0;
      
      for (int i = 0; i < n; ++i) {
        if (nums[i] != nums[pos])
          continue;
        
        int l = i - 1, r = i + 1;
        int l_and = nums[pos], r_and = nums[pos];
        int count = 1;
        
        while (l >= 0 and nums[pos] == (l_and & nums[l])) {
          l_and &= nums[l];
          --l;
          ++count;
        }

        while (r < n and nums[pos] == (r_and & nums[r])) {
          r_and &= nums[r];
          ++r;
          ++count;
        }
        
        i = r;
        max_count = std::max(max_count, count);
      }
      
      return max_count;
    }
};
```

Finding max-length subarray with all elements equal to maximum in input

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestSubarray (vector <int>& nums) {
      int n = nums.size();
      int max = *std::max_element(nums.begin(), nums.end());
      int max_count = 0, count = 0;
      
      for (int i = 0; i < n; ++i) {
        if (nums[i] == max) {
          ++count;
          max_count = std::max(max_count, count);
        }
        else
          count = 0;
      }
      
      return max_count;
    }
};
```

<br>

### Statistics

- total accepted: 10943
- total submissions: 25576
- acceptance rate: 42.8%
- likes: 125
- dislikes: 10

<br>

### Similar Problems

- [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string) (Easy)
- [Remove Colored Pieces if Both Neighbors are the Same Color](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color) (Medium)
- [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets) (Medium)
- [Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or) (Medium)

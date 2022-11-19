# [594] Longest Harmonious Subsequence

**[array, hash-table, sorting]**

### Statement

We define a harmonious array as an array where the difference between its maximum value and its minimum value is **exactly** `1`.

Given an integer array `nums`, return *the length of its longest harmonious subsequence among all its possible subsequences*.

A **subsequence** of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** nums = [1,3,2,2,5,2,3,7]
**Output:** 5
**Explanation:** The longest harmonious subsequence is [3,2,2,2,3].

```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** 2

```

**Example 3:**

```

**Input:** nums = [1,1,1,1]
**Output:** 0

```

**Constraints:**
* `1 <= nums.length <= 2 * 104`
* `-109 <= nums[i] <= 109`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int findLHS (vector <int>& nums) {
      std::map <int, int> freq;
      int max = 0;
      
      for (int i: nums)
        ++freq[i];
      
      for (auto &[x, y]: freq) {
        auto f = freq.find(x + 1);
        if (f != freq.end())
          max = std::max(max, y + f->second);
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 126449
- total submissions: 237732
- acceptance rate: 53.2%
- likes: 1768
- dislikes: 164

<br>

### Similar Problems

None

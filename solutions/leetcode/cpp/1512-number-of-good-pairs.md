# [1512] Number of Good Pairs

**[array, hash-table, math, counting]**

### Statement

Given an array of integers `nums`, return *the number of **good pairs***.

A pair `(i, j)` is called *good* if `nums[i] == nums[j]` and `i` < `j`.


**Example 1:**

```

**Input:** nums = [1,2,3,1,1,3]
**Output:** 4
**Explanation:** There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

```

**Example 2:**

```

**Input:** nums = [1,1,1,1]
**Output:** 6
**Explanation:** Each pair in the array are *good*.

```

**Example 3:**

```

**Input:** nums = [1,2,3]
**Output:** 0

```

**Constraints:**
* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`


<br>

### Hints

- Count how many times each number appears. If a number appears n times, then n * (n – 1) // 2 good pairs can be made with this number.

<br>

### Solution

```cpp
class Solution {
  public:
    int numIdenticalPairs (vector <int>& nums) {
      std::unordered_map <int, int> freq;
      int ans = 0;
      
      for (int n: nums)
        ++freq[n];
      
      for (auto &[x, y]: freq)
        ans += y * (y - 1) / 2;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 323961
- total submissions: 367900
- acceptance rate: 88.1%
- likes: 2748
- dislikes: 150

<br>

### Similar Problems

- [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) (Medium)
- [Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter) (Medium)

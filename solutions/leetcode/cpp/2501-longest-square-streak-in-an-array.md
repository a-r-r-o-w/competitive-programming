# [2501] Longest Square Streak in an Array



### Statement

You are given an integer array `nums`. A subsequence of `nums` is called a **square streak** if:

* The length of the subsequence is at least `2`, and
* **after** sorting the subsequence, each element (except the first element) is the **square** of the previous number.



Return *the length of the **longest square streak** in* `nums`*, or return* `-1` *if there is no **square streak**.*

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** nums = [4,3,6,16,8,2]
**Output:** 3
**Explanation:** Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.

```

**Example 2:**

```

**Input:** nums = [2,3,5,6,7]
**Output:** -1
**Explanation:** There is no square streak in nums so return -1.

```

**Constraints:**
* `2 <= nums.length <= 105`
* `2 <= nums[i] <= 105`


<br>

### Hints

- With the constraints, the length of the longest square streak possible is 5.
- Store the elements of nums in a set to quickly check if it exists.
- Store the elements of nums in a set to quickly check if it exists.

<br>

### Solution

```cpp
class Solution {
  public:
    int longestSquareStreak (vector <int>& nums) {
      const int max_val = 100000 + 1;
      std::unordered_set <int> have (nums.begin(), nums.end());
      int max = -1;
      
      for (int i = 2; i < max_val; ++i) {
        int64_t j = i;
        int count = 0;
        while (have.count(j) and j < max_val) {
          j *= j;
          ++count;
        }
        if (count >= 2)
          max = std::max(max, count);
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 10348
- total submissions: 26473
- acceptance rate: 39.1%
- likes: 134
- dislikes: 2

<br>

### Similar Problems

None

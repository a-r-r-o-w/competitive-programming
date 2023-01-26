# [229] Majority Element II

**[array, hash-table, sorting, counting]**

### Statement

Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.


**Example 1:**

```

**Input:** nums = [3,2,3]
**Output:** [3]

```

**Example 2:**

```

**Input:** nums = [1]
**Output:** [1]

```

**Example 3:**

```

**Input:** nums = [1,2]
**Output:** [1,2]

```

**Constraints:**
* `1 <= nums.length <= 5 * 104`
* `-109 <= nums[i] <= 109`


**Follow up:** Could you solve the problem in linear time and in `O(1)` space?

<br>

### Hints

- How many majority elements could it possibly have?
<br/>
Do you have a better hint? <a href="mailto:admin@leetcode.com?subject=Hints for Majority Element II" target="_blank">Suggest it</a>!

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> majorityElement (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> ans;
      
      std::sort(nums.begin(), nums.end());

      for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and nums[i] == nums[j])
          ++j;
        int count = j - i;
        if (count > n / 3)
          ans.push_back(nums[i]);
        i = j - 1;
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 371630
- total submissions: 833277
- acceptance rate: 44.6%
- likes: 6641
- dislikes: 327

<br>

### Similar Problems

- [Majority Element](https://leetcode.com/problems/majority-element) (Easy)
- [Check If a Number Is Majority Element in a Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array) (Easy)
- [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) (Easy)

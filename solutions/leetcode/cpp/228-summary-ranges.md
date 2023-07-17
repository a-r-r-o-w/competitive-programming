# [228] Summary Ranges

**[array]**

### Statement

You are given a **sorted unique** integer array `nums`.

A **range** `[a,b]` is the set of all integers from `a` to `b` (inclusive).

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:

* `"a->b"` if `a != b`
* `"a"` if `a == b`


**Example 1:**

```

**Input:** nums = [0,1,2,4,5,7]
**Output:** ["0->2","4->5","7"]
**Explanation:** The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

```

**Example 2:**

```

**Input:** nums = [0,2,3,4,6,8,9]
**Output:** ["0","2->4","6","8->9"]
**Explanation:** The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

```

**Constraints:**
* `0 <= nums.length <= 20`
* `-2^31 <= nums[i] <= 2^31 - 1`
* All the values of `nums` are **unique**.
* `nums` is sorted in ascending order.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <string> summaryRanges (vector <int>& nums) {
      std::vector <std::string> ans;
      int n = nums.size();

      for (int i = 0; i < n; ++i) {
        int64_t j = i, value = nums[i];
        while (j < n and nums[j] == value) {
          ++value;
          ++j;
        }
        if (nums[i] != value - 1)
          ans.push_back(std::to_string(nums[i]) + "->" + std::to_string(value - 1));
        else
          ans.push_back(std::to_string(value - 1));
        i = j - 1;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 399685
- total submissions: 820895
- acceptance rate: 48.7%
- likes: 3262
- dislikes: 1719

<br />

### Similar Problems

- [Missing Ranges](https://leetcode.com/problems/missing-ranges) (Easy)
- [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals) (Hard)
- [Find Maximal Uncovered Ranges](https://leetcode.com/problems/find-maximal-uncovered-ranges) (Medium)

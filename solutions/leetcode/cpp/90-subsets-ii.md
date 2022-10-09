# [90] Subsets II

**[array, backtracking, bit-manipulation]**

### Statement

Given an integer array `nums` that may contain duplicates, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.


**Example 1:**

```
**Input:** nums = [1,2,2]
**Output:** [[],[1],[1,2],[1,2,2],[2],[2,2]]

```
**Example 2:**

```
**Input:** nums = [0]
**Output:** [[],[0]]

```

**Constraints:**
* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> subsetsWithDup (vector <int>& nums) {
      int n = nums.size();
      std::set <std::vector <int>> ans;
      std::vector <int> take;
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j))
            take.push_back(nums[j]);
        }
        ans.emplace(std::move(take));
      }
      
      return std::vector <std::vector <int>> (ans.begin(), ans.end());
    }
};
```

<br>

### Statistics

- total accepted: 601740
- total submissions: 1093348
- acceptance rate: 55.0%
- likes: 6670
- dislikes: 185

<br>

### Similar Problems

- [Subsets](https://leetcode.com/problems/subsets) (Medium)
- [Find Array Given Subset Sums](https://leetcode.com/problems/find-array-given-subset-sums) (Hard)

# [78] Subsets

**[array, backtracking, bit-manipulation]**

### Statement

Given an integer array `nums` of **unique** elements, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.


**Example 1:**

```

**Input:** nums = [1,2,3]
**Output:** [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

```

**Example 2:**

```

**Input:** nums = [0]
**Output:** [[],[0]]

```

**Constraints:**
* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`
* All the numbers of`nums` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> subsets (vector <int>& nums) {
      int n = nums.size();
      std::vector <std::vector <int>> ans;
      std::vector <int> take;
      
      for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j))
            take.push_back(nums[j]);
        }
        ans.emplace_back(std::move(take));
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1257102
- total submissions: 1709430
- acceptance rate: 73.5%
- likes: 12191
- dislikes: 176

<br>

### Similar Problems

- [Subsets II](https://leetcode.com/problems/subsets-ii) (Medium)
- [Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation) (Medium)
- [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation) (Medium)
- [Find Array Given Subset Sums](https://leetcode.com/problems/find-array-given-subset-sums) (Hard)
- [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets) (Medium)

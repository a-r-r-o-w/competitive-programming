# [47] Permutations II

**[array, backtracking]**

### Statement

Given a collection of numbers, `nums`,that might contain duplicates, return *all possible unique permutations **in any order**.*
**Example 1:**

```

**Input:** nums = [1,1,2]
**Output:**
[[1,1,2],
 [1,2,1],
 [2,1,1]]

```

**Example 2:**

```

**Input:** nums = [1,2,3]
**Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

**Constraints:**
* `1 <= nums.length <= 8`
* `-10 <= nums[i] <= 10`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> permuteUnique (vector <int>& nums) {
      std::set <std::vector <int>> perms;
      std::sort(nums.begin(), nums.end());
      do
        perms.insert(nums);
      while (std::next_permutation(nums.begin(), nums.end()));
      return std::vector <std::vector <int>> (perms.begin(), perms.end());
    }
};
```

<br>

### Statistics

- total accepted: 658583
- total submissions: 1184437
- acceptance rate: 55.6%
- likes: 5773
- dislikes: 100

<br>

### Similar Problems

- [Next Permutation](https://leetcode.com/problems/next-permutation) (Medium)
- [Permutations](https://leetcode.com/problems/permutations) (Medium)
- [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii) (Medium)
- [Number of Squareful Arrays](https://leetcode.com/problems/number-of-squareful-arrays) (Hard)

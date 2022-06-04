# [46] Permutations

**[array, backtracking]**

### Statement

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.


**Example 1:**

```
**Input:** nums = [1,2,3]
**Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```
**Example 2:**

```
**Input:** nums = [0,1]
**Output:** [[0,1],[1,0]]

```
**Example 3:**

```
**Input:** nums = [1]
**Output:** [[1]]

```

**Constraints:**
* `1 <= nums.length <= 6`
* `-10 <= nums[i] <= 10`
* All the integers of `nums` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector<int>> permute (vector <int>& nums) {
      std::vector <std::vector <int>> perms;
      
      std::sort(nums.begin(), nums.end());
      
      do
        perms.push_back(nums);
      while (std::next_permutation(nums.begin(), nums.end()));
      
      return perms;
    }
};
```

<br>

### Statistics

- total accepted: 1190545
- total submissions: 1637489
- acceptance rate: 72.7%
- likes: 10712
- dislikes: 192

<br>

### Similar Problems

- [Next Permutation](https://leetcode.com/problems/next-permutation) (Medium)
- [Permutations II](https://leetcode.com/problems/permutations-ii) (Medium)
- [Permutation Sequence](https://leetcode.com/problems/permutation-sequence) (Hard)
- [Combinations](https://leetcode.com/problems/combinations) (Medium)

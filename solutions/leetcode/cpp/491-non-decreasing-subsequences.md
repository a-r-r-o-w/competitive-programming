# [491] Non-decreasing Subsequences

**[array, hash-table, backtracking, bit-manipulation]**

### Statement

Given an integer array `nums`, return *all the different possible non-decreasing subsequences of the given array with at least two elements*. You may return the answer in **any order**.


**Example 1:**

```

**Input:** nums = [4,6,7,7]
**Output:** [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

```

**Example 2:**

```

**Input:** nums = [4,4,3,2,1]
**Output:** [[4,4]]

```

**Constraints:**
* `1 <= nums.length <= 15`
* `-100 <= nums[i] <= 100`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> findSubsequences (vector <int>& nums) {
      int n = nums.size();
      std::set <std::vector <int>> result;
      std::vector <int> v;

      for (int i = 0; i < 1 << n; ++i) {
        int prev = -100000000;
        bool bad = false;

        for (int j = 0; j < n; ++j) {
          if (i & (1 << j)) {
            if (nums[j] < prev) {
              bad = true;
              break;
            }
            prev = nums[j];
            v.push_back(nums[j]);
          }
        }

        if (not bad and (int)v.size() >= 2)
          result.insert(std::move(v));
        v.clear();
      }

      return std::vector <std::vector <int>> (result.begin(), result.end());
    }
};
```

<br>

### Statistics

- total accepted: 91659
- total submissions: 172384
- acceptance rate: 53.2%
- likes: 1945
- dislikes: 169

<br>

### Similar Problems

- [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) (Medium)

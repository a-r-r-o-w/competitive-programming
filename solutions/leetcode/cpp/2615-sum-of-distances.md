# [2615] Sum of Distances

**[array, hash-table, prefix-sum]**

### Statement

You are given a **0-indexed** integer array `nums`. There exists an array `arr` of length `nums.length`, where `arr[i]` is the sum of `|i - j|` over all `j` such that `nums[j] == nums[i]` and `j != i`. If there is no such `j`, set `arr[i]` to be `0`.

Return *the array* `arr`*.*
**Example 1:**

```

**Input:** nums = [1,3,1,1,2]
**Output:** [5,0,3,4,0]
**Explanation:** 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 


```

**Example 2:**

```

**Input:** nums = [0,5,3]
**Output:** [0,0,0]
**Explanation:** Since each element in nums is distinct, arr[i] = 0 for all i.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^9`


<br />

### Hints

- Can we use the prefix sum here?
- For each number x, collect all the indices where x occurs, and calculate the prefix sum of the array.
- For each occurrence of x, the indices to the right will be regular subtraction while the indices to the left will be reversed subtraction.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <long long> distance (vector <int>& nums) {
      std::map <int, std::vector <int>> indices;
      int n = nums.size();
      std::vector <long long> ans (n);
      
      for (int i = 0; i < n; ++i)
        indices[nums[i]].push_back(i);
      
      for (auto &[x, y]: indices) {
        int k = y.size();
        if (k == 1)
          continue;
        int64_t diff = 0;
        for (int i = 0; i < k; ++i)
          diff += y[i] - y[0];
        ans[y[0]] = diff;
        for (int i = 1; i < k; ++i) {
          diff -= int64_t(k - i - 1) * (y[i] - y[i - 1]);
          diff += int64_t(i - 1) * (y[i] - y[i - 1]);
          ans[y[i]] = diff;
        }
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 10116
- total submissions: 35587
- acceptance rate: 28.4%
- likes: 379
- dislikes: 57

<br />

### Similar Problems

- [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array) (Easy)
- [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) (Medium)
- [Minimum Operations to Make All Array Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal) (Medium)

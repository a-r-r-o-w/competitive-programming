# [1630] Arithmetic Subarrays

**[array, sorting]**

### Statement

A sequence of numbers is called **arithmetic** if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence `s` is arithmetic if and only if `s[i+1] - s[i] == s[1] - s[0]` for all valid `i`.

For example, these are **arithmetic** sequences:


```

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```


The following sequence is not **arithmetic**:


```

1, 1, 2, 5, 7
```


You are given an array of `n` integers, `nums`, and two arrays of `m` integers each, `l` and `r`, representing the `m` range queries, where the `ith` query is the range `[l[i], r[i]]`. All the arrays are **0-indexed**.

Return *a list of* `boolean` *elements* `answer`*, where* `answer[i]` *is* `true` *if the subarray* `nums[l[i]], nums[l[i]+1], ... , nums[r[i]]` *can be **rearranged** to form an **arithmetic** sequence, and* `false` *otherwise.*
**Example 1:**

```

**Input:** nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
**Output:** [true,false,true]
**Explanation:**
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
```

**Example 2:**

```

**Input:** nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
**Output:** [false,true,false,false,true,true]

```

**Constraints:**
* `n == nums.length`
* `m == l.length`
* `m == r.length`
* `2 <= n <= 500`
* `1 <= m <= 500`
* `0 <= l[i] < r[i] < n`
* `-105 <= nums[i] <= 105`


<br>

### Hints

- To check if a given sequence is arithmetic, just check that the difference between every two consecutive elements is the same.
- If and only if a set of numbers can make an arithmetic sequence, then its sorted version makes an arithmetic sequence. So to check a set of numbers, sort it, and check if that sequence is arithmetic.
- For each query, get the corresponding set of numbers which will be the sub-array represented by the query, sort it, and check if the result sequence is arithmetic.

<br>

### Solution

Sorting

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <bool> checkArithmeticSubarrays (vector <int>& nums, vector <int>& l, vector <int>& r) {
      int n = nums.size();
      int m = l.size();
      std::vector <int> current;
      std::vector <bool> ans (m, true);
      
      for (int i = 0; i < m; ++i) {
        for (int j = l[i]; j <= r[i]; ++j)
          current.push_back(nums[j]);
        
        std::sort(current.begin(), current.end());
        
        int d = current[1] - current[0];
        for (int j = 0; j < r[i] - l[i]; ++j)
          if (current[j + 1] - current[j] != d) {
            ans[i] = false;
            break;
          }
        
        current.clear();
      }
      
      return ans;
    }
};
```

Without sorting

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <bool> checkArithmeticSubarrays (vector <int>& nums, vector <int>& l, vector <int>& r) {
      int n = nums.size();
      int m = l.size();
      std::vector <int> current;
      std::vector <bool> ans (m, true);
      
      for (int i = 0; i < m; ++i) {
        auto [min, max] = std::minmax_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
        int len = r[i] - l[i] + 1, d = (*max - *min) / (len - 1);
        
        if (*min == *max)
          continue;
        else if ((*max - *min) % (len - 1) != 0)
          ans[i] = false;
        else {
          std::vector <bool> have (len);
          
          for (int j = l[i]; j <= r[i]; ++j) {
            if ((nums[j] - *min) % d != 0) {
              ans[i] = false;
              break;
            }
            have[(nums[j] - *min) / d] = true;
          }
          
          if (not std::all_of(have.begin(), have.end(), [] (auto b) {
            return b;
          }))
            ans[i] = false;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 38665
- total submissions: 48602
- acceptance rate: 79.6%
- likes: 736
- dislikes: 80

<br>

### Similar Problems

- [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices) (Medium)
- [Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence) (Easy)

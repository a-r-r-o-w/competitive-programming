# [446] Arithmetic Slices II - Subsequence

**[array, dynamic-programming]**

### Statement

Given an integer array `nums`, return *the number of all the **arithmetic subsequences** of* `nums`.

A sequence of numbers is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

* For example, `[1, 3, 5, 7, 9]`, `[7, 7, 7, 7]`, and `[3, -1, -5, -9]` are arithmetic sequences.
* For example, `[1, 1, 2, 5, 7]` is not an arithmetic sequence.



A **subsequence** of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

* For example, `[2,5,10]` is a subsequence of `[1,2,1,**2**,4,1,**5**,**10**]`.



The test cases are generated so that the answer fits in **32-bit** integer.


**Example 1:**

```

**Input:** nums = [2,4,6,8,10]
**Output:** 7
**Explanation:** All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

```

**Example 2:**

```

**Input:** nums = [7,7,7,7,7]
**Output:** 16
**Explanation:** Any subsequence of this array is arithmetic.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `-231 <= nums[i] <= 231 - 1`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numberOfArithmeticSlices (vector <int>& nums) {
      int n = nums.size();
      
      std::vector <std::map <int64_t, int>> freq (n);
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          int64_t x = nums[i];
          int64_t y = nums[j];
          int64_t diff = x - y;
          int s = freq[j].count(diff) ? freq[j][diff] : 0;
          freq[i][diff] += s + 1;
          ans += s;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 56919
- total submissions: 131988
- acceptance rate: 43.1%
- likes: 1854
- dislikes: 103

<br>

### Similar Problems

- [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices) (Medium)
- [Destroy Sequential Targets](https://leetcode.com/problems/destroy-sequential-targets) (Medium)
- [Count Palindromic Subsequences](https://leetcode.com/problems/count-palindromic-subsequences) (Hard)

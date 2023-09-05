# [1980] Find Unique Binary String

**[array, string, backtracking]**

### Statement

Given an array of strings `nums` containing `n` **unique** binary strings each of length `n`, return *a binary string of length* `n` *that **does not appear** in* `nums`*. If there are multiple answers, you may return **any** of them*.


**Example 1:**

```

**Input:** nums = ["01","10"]
**Output:** "11"
**Explanation:** "11" does not appear in nums. "00" would also be correct.

```

**Example 2:**

```

**Input:** nums = ["00","01"]
**Output:** "11"
**Explanation:** "11" does not appear in nums. "10" would also be correct.

```

**Example 3:**

```

**Input:** nums = ["111","011","001"]
**Output:** "101"
**Explanation:** "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

```

**Constraints:**
* `n == nums.length`
* `1 <= n <= 16`
* `nums[i].length == n`
* `nums[i]` is either `'0'` or `'1'`.
* All the strings of `nums` are **unique**.


<br>

### Hints

- We can convert the given strings into base 10 integers.
- Can we use recursion to generate all possible strings?

<br>

### Solution

```cpp
class Solution {
  public:
    string findDifferentBinaryString (vector <string>& nums) {
      int n = nums.size();
      std::string ans (n, ' ');
      
      for (int i = 0; i < n; ++i)
        ans[i] = '0' + '1' - nums[i][i];
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 31329
- total submissions: 48722
- acceptance rate: 64.3%
- likes: 761
- dislikes: 33

<br>

### Similar Problems

- [Missing Number](https://leetcode.com/problems/missing-number) (Easy)
- [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) (Easy)
- [Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist) (Hard)

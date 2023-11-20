# [2341] Maximum Number of Pairs in Array

**[array, hash-table, counting]**

### Statement

You are given a **0-indexed** integer array `nums`. In one operation, you may do the following:

* Choose **two** integers in `nums` that are **equal**.
* Remove both integers from `nums`, forming a **pair**.



The operation is done on `nums` as many times as possible.

Return *a **0-indexed** integer array* `answer` *of size* `2` *where* `answer[0]` *is the number of pairs that are formed and* `answer[1]` *is the number of leftover integers in* `nums` *after doing the operation as many times as possible*.


**Example 1:**

```

**Input:** nums = [1,3,2,1,3,2,2]
**Output:** [3,1]
**Explanation:**
Form a pair with nums[0] and nums[3] and remove them from nums. Now, nums = [3,2,3,2,2].
Form a pair with nums[0] and nums[2] and remove them from nums. Now, nums = [2,2,2].
Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [2].
No more pairs can be formed. A total of 3 pairs have been formed, and there is 1 number leftover in nums.

```

**Example 2:**

```

**Input:** nums = [1,1]
**Output:** [1,0]
**Explanation:** Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [].
No more pairs can be formed. A total of 1 pair has been formed, and there are 0 numbers leftover in nums.

```

**Example 3:**

```

**Input:** nums = [0]
**Output:** [0,1]
**Explanation:** No pairs can be formed, and there is 1 number leftover in nums.

```

**Constraints:**
* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`


<br>

### Hints

- What do we need to know to find how many pairs we can make? We need to know the frequency of each integer.
- When will there be a leftover number? When the frequency of an integer is an odd number.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> numberOfPairs (vector <int>& nums) {
      std::unordered_map <int, int> freq;
      std::vector <int> ans (2);
      
      for (int n: nums)
        ++freq[n];
      
      for (auto &[x, y]: freq) {
        ans[0] += y / 2;
        ans[1] += y % 2;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 31854
- total submissions: 41237
- acceptance rate: 77.2%
- likes: 245
- dislikes: 7

<br>

### Similar Problems

- [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) (Medium)
- [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) (Medium)
- [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) (Easy)

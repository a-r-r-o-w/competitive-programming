# [2592] Maximize Greatness of an Array



### Statement

You are given a 0-indexed integer array `nums`. You are allowed to permute `nums` into a new array `perm` of your choosing.

We define the **greatness** of `nums` be the number of indices `0 <= i < nums.length` for which `perm[i] > nums[i]`.

Return *the **maximum** possible greatness you can achieve after permuting* `nums`.


**Example 1:**

```

**Input:** nums = [1,3,5,2,1,3,1]
**Output:** 4
**Explanation:** One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
```

**Example 2:**

```

**Input:** nums = [1,2,3,4]
**Output:** 3
**Explanation:** We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.

```

**Constraints:**
* `1 <= nums.length <= 10^5`
* `0 <= nums[i] <= 10^9`


<br />

### Hints

- Can we use sorting and two pointers here?
- Assign every element the next bigger unused element as many times as possible.

<br />

### Solution

```cpp
class Solution {
  public:
    int maximizeGreatness (vector <int>& nums) {
      int n = nums.size(), count = 0, index = 0;
      
      std::sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n and index < n; ++i) {
        while (index < n and nums[i] >= nums[index])
          ++index;
        if (index < n)
          ++count, ++index;
      }
      
      return count;
    }
};
```

<br />

### Statistics

- total accepted: 11392
- total submissions: 20963
- acceptance rate: 54.3%
- likes: 175
- dislikes: 3

<br />

### Similar Problems

- [3Sum Smaller](https://leetcode.com/problems/3sum-smaller) (Medium)
- [Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers) (Medium)

# [1984] Minimum Difference Between Highest and Lowest of K Scores

**[array, sliding-window, sorting]**

### Statement

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the `ith` student. You are also given an integer `k`.

Pick the scores of any `k` students from the array so that the **difference** between the **highest** and the **lowest** of the `k` scores is **minimized**.

Return *the **minimum** possible difference*.


**Example 1:**

```

**Input:** nums = [90], k = 1
**Output:** 0
**Explanation:** There is one way to pick score(s) of one student:
- [**90**]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.

```

**Example 2:**

```

**Input:** nums = [9,4,1,7], k = 2
**Output:** 2
**Explanation:** There are six ways to pick score(s) of two students:
- [**9**,**4**,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [**9**,4,**1**,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [**9**,4,1,**7**]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,**4**,**1**,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,**4**,1,**7**]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,**1**,**7**]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
```

**Constraints:**
* `1 <= k <= nums.length <= 1000`
* `0 <= nums[i] <= 105`


<br>

### Hints

- For the difference between the highest and lowest element to be minimized, the k chosen scores need to be as close to each other as possible.
- What if the array was sorted?
- After sorting the scores, any contiguous k scores are as close to each other as possible.
- Apply a sliding window solution to iterate over each contiguous k scores, and find the minimum of the differences of all windows.

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumDifference (vector <int>& nums, int k) {
      int n = nums.size(), ans = 1 << 30;

      std::sort(nums.begin(), nums.end());

      for (int i = k - 1; i < n; ++i)
        ans = std::min(ans, nums[i] - nums[i - k + 1]);
      
      if (ans == 1 << 30)
        ans = 0;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 37328
- total submissions: 69104
- acceptance rate: 54.0%
- likes: 605
- dislikes: 98

<br>

### Similar Problems

- [Array Partition](https://leetcode.com/problems/array-partition) (Easy)

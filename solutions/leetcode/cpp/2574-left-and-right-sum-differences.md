# [2574] Left and Right Sum Differences



### Statement

Given a **0-indexed** integer array `nums`, find a **0-indexed** integer array `answer` where:

* `answer.length == nums.length`.
* `answer[i] = |leftSum[i] - rightSum[i]|`.



Where:

* `leftSum[i]` is the sum of elements to the left of the index `i` in the array `nums`. If there is no such element, `leftSum[i] = 0`.
* `rightSum[i]` is the sum of elements to the right of the index `i` in the array `nums`. If there is no such element, `rightSum[i] = 0`.



Return *the array* `answer`.


**Example 1:**

```

**Input:** nums = [10,4,8,3]
**Output:** [15,1,11,22]
**Explanation:** The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

```

**Example 2:**

```

**Input:** nums = [1]
**Output:** [0]
**Explanation:** The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 10^5`


<br />

### Hints

- For each index i, maintain two variables leftSum and rightSum.
- Iterate on the range j: [0 … i - 1] and add nums[j] to the leftSum and similarly iterate on the range j: [i + 1 … nums.length - 1] and add nums[j] to the rightSum.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> leftRigthDifference (vector <int>& nums) {
      int n = nums.size();
      std::vector <int> left (n), right (n), answer (n);

      for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1] + nums[i - 1];
        right[n - i - 1] = right[n - i] + nums[n - i];
      }
      for (int i = 0; i < n; ++i)
        answer[i] = std::abs(left[i] - right[i]);
      
      return answer;
    }
};
```

<br />

### Statistics

- total accepted: 15926
- total submissions: 17829
- acceptance rate: 89.3%
- likes: 75
- dislikes: 2

<br />

### Similar Problems

- [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) (Easy)
- [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array) (Easy)

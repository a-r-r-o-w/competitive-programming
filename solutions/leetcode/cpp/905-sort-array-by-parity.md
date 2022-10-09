# [905] Sort Array By Parity

**[array, two-pointers, sorting]**

### Statement

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return **any array** that satisfies this condition.


**Example 1:**

```

**Input:** nums = [3,1,2,4]
**Output:** [2,4,3,1]
**Explanation:** The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

```

**Example 2:**

```

**Input:** nums = [0]
**Output:** [0]

```

**Constraints:**
* `1 <= nums.length <= 5000`
* `0 <= nums[i] <= 5000`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector<int> sortArrayByParity (vector<int>& nums) {
      std::partition(nums.begin(), nums.end(), [] (int x) { return x % 2 == 0; });
      return nums;
    }
};
```

<br>

### Statistics

- total accepted: 519397
- total submissions: 685936
- acceptance rate: 75.7%
- likes: 3626
- dislikes: 123

<br>

### Similar Problems

- [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently) (Easy)
- [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity) (Easy)

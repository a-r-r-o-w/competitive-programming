# [1588] Sum of All Odd Length Subarrays

**[array, math, prefix-sum]**

### Statement

Given an array of positive integers `arr`, return *the sum of all possible **odd-length subarrays** of* `arr`.

A **subarray** is a contiguous subsequence of the array.


**Example 1:**

```

**Input:** arr = [1,4,2,5,3]
**Output:** 58
**Explanation:** The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
```

**Example 2:**

```

**Input:** arr = [1,2]
**Output:** 3
**Explanation:** There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
```

**Example 3:**

```

**Input:** arr = [10,11,12]
**Output:** 66

```

**Constraints:**
* `1 <= arr.length <= 100`
* `1 <= arr[i] <= 1000`


**Follow up:**

Could you solve this problem in O(n) time complexity?

<br>

### Hints

- You can brute force – try every (i,j) pair, and if the length is odd, go through and add the sum to the answer.

<br>

### Solution

```cpp
class Solution {
  public:
    int sumOddLengthSubarrays (vector <int>& arr) {
      int n = arr.size();
      int ans = 0;
      
      for (int l = 0; l < n; ++l) {
        int sum = 0;
        for (int r = l; r < n; ++r) {
          sum += arr[r];
          if ((r - l + 1) & 1)
            ans += sum;
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 115453
- total submissions: 138042
- acceptance rate: 83.6%
- likes: 2380
- dislikes: 181

<br>

### Similar Problems

None

# [376] Wiggle Subsequence

**[array, dynamic-programming, greedy]**

### Statement

A **wiggle sequence** is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

* For example, `[1, 7, 4, 9, 2, 5]` is a **wiggle sequence** because the differences `(6, -3, 5, -7, 3)` alternate between positive and negative.
* In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.



A **subsequence** is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array `nums`, return *the length of the longest **wiggle subsequence** of* `nums`.


**Example 1:**

```

**Input:** nums = [1,7,4,9,2,5]
**Output:** 6
**Explanation:** The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

```

**Example 2:**

```

**Input:** nums = [1,17,5,10,13,15,10,5,16,8]
**Output:** 7
**Explanation:** There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

```

**Example 3:**

```

**Input:** nums = [1,2,3,4,5,6,7,8,9]
**Output:** 2

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`


**Follow up:** Could you solve this in `O(n)` time?

<br>

### Hints

None

<br>

### Solution

**O(n^2) dp**

```cpp
class Solution {
  public:
    int wiggleMaxLength (vector <int>& nums) {
      int n = nums.size();
      
      std::vector <int> positive (n, 1);
      std::vector <int> negative (n, 1);
      
      for (int i = n - 1; i >= 0; --i) {
        int max_p = 0;
        int max_n = 0;
        for (int j = i + 1; j < n; ++j) {
          if (nums[j] > nums[i])
            max_n = std::max(max_n, negative[j]);
          else if (nums[j] < nums[i])
            max_p = std::max(max_p, positive[j]);
        }
        positive[i] = max_n + 1;
        negative[i] = max_p + 1;
      }
      
      return std::max(positive[0], negative[0]);
    }
};
```

**O(n) dp**

```cpp
class Solution {
  public:
    int wiggleMaxLength (vector <int>& nums) {
      int n = nums.size();
      
      std::vector <int> positive (n, 1);
      std::vector <int> negative (n, 1);
      
      for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
          positive[i] = negative[i - 1] + 1;
          negative[i] = negative[i - 1];
        }
        else if (nums[i] < nums[i - 1]){
          negative[i] = positive[i - 1] + 1;
          positive[i] = positive[i - 1];
        }
        else {
          positive[i] = positive[i - 1];
          negative[i] = negative[i - 1];
        }
      }
      
      return std::max(positive[n - 1], negative[n - 1]);
    }
};
```

**O(1) space dp**

```cpp
class Solution {
  public:
    int wiggleMaxLength (vector <int>& nums) {
      int n = nums.size();
      
      int positive = 1;
      int negative = 1;
      
      for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1])
          positive = negative + 1;
        else if (nums[i] < nums[i - 1])
          negative = positive + 1;
      }
      
      return std::max(positive, negative);
    }
};
```

<br>

### Statistics

- total accepted: 188616
- total submissions: 394530
- acceptance rate: 47.8%
- likes: 3979
- dislikes: 128

<br>

### Similar Problems

- [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign) (Medium)

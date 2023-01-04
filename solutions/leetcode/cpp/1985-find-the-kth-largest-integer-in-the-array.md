# [1985] Find the Kth Largest Integer in the Array

**[array, string, divide-and-conquer, sorting, heap-priority-queue, quickselect]**

### Statement

You are given an array of strings `nums` and an integer `k`. Each string in `nums` represents an integer without leading zeros.

Return *the string that represents the* `kth` ***largest integer** in* `nums`.

**Note**: Duplicate numbers should be counted distinctly. For example, if `nums` is `["1","2","2"]`, `"2"` is the first largest integer, `"2"` is the second-largest integer, and `"1"` is the third-largest integer.


**Example 1:**

```

**Input:** nums = ["3","6","7","10"], k = 4
**Output:** "3"
**Explanation:**
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".

```

**Example 2:**

```

**Input:** nums = ["2","21","12","1"], k = 3
**Output:** "2"
**Explanation:**
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".

```

**Example 3:**

```

**Input:** nums = ["0","0"], k = 2
**Output:** "0"
**Explanation:**
The numbers in nums sorted in non-decreasing order are ["0","0"].
The 2nd largest integer in nums is "0".

```

**Constraints:**
* `1 <= k <= nums.length <= 104`
* `1 <= nums[i].length <= 100`
* `nums[i]` consists of only digits.
* `nums[i]` will not have any leading zeros.


<br>

### Hints

- If two numbers have different lengths, which one will be larger?
- The longer number is the larger number.
- If two numbers have the same length, which one will be larger?
- Compare the two numbers starting from the most significant digit. Once you have found the first digit that differs, the one with the larger digit is the larger number.

<br>

### Solution

```cpp
class Solution {
  public:
    string kthLargestNumber (vector <string>& nums, int k) {
      std::sort(nums.begin(), nums.end(), [] (auto &l, auto &r) {
        if (l.size() < r.size())
          return true;
        if (l.size() > r.size())
          return false;
        for (int i = 0; i < (int)l.size(); ++i) {
          if (l[i] < r[i])
            return true;
          if (l[i] > r[i])
            return false;
        }
        return false;
      });

      return nums[nums.size() - k];
    }
};
```

<br>

### Statistics

- total accepted: 41848
- total submissions: 93659
- acceptance rate: 44.7%
- likes: 817
- dislikes: 103

<br>

### Similar Problems

- [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) (Medium)

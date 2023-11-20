# [1502] Can Make Arithmetic Progression From Sequence

**[array, sorting]**

### Statement

A sequence of numbers is called an **arithmetic progression** if the difference between any two consecutive elements is the same.

Given an array of numbers `arr`, return `true` *if the array can be rearranged to form an **arithmetic progression**. Otherwise, return* `false`.


**Example 1:**

```

**Input:** arr = [3,5,1]
**Output:** true
**Explanation:** We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

```

**Example 2:**

```

**Input:** arr = [1,2,4]
**Output:** false
**Explanation:** There is no way to reorder the elements to obtain an arithmetic progression.

```

**Constraints:**
* `2 <= arr.length <= 1000`
* `-10^6 <= arr[i] <= 10^6`


<br>

### Hints

- Consider that any valid arithmetic progression will be in sorted order.
- Sort the array, then check if the differences of all consecutive elements are equal.

<br>

### Solution

```cpp
class Solution {
  public:
    bool canMakeArithmeticProgression (vector <int>& arr) {
      std::sort(arr.begin(), arr.end());
      int n = arr.size();
      int d = arr[1] - arr[0];
      
      for (int i = 2; i < n; ++i) {
        if (arr[i] - arr[i - 1] != d)
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 100439
- total submissions: 146454
- acceptance rate: 68.6%
- likes: 806
- dislikes: 52

<br>

### Similar Problems

- [Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays) (Medium)

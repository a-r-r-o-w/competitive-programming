# [2121] Intervals Between Identical Elements

**[array, hash-table, prefix-sum]**

### Statement

You are given a **0-indexed** array of `n` integers `arr`.

The **interval** between two elements in `arr` is defined as the **absolute difference** between their indices. More formally, the **interval** between `arr[i]` and `arr[j]` is `|i - j|`.

Return *an array* `intervals` *of length* `n` *where* `intervals[i]` *is **the sum of intervals** between* `arr[i]` *and each element in* `arr` *with the same value as* `arr[i]`*.*
**Note:** `|x|` is the absolute value of `x`.


**Example 1:**

```

**Input:** arr = [2,1,3,1,2,3,3]
**Output:** [4,2,7,2,4,4,5]
**Explanation:**
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5

```

**Example 2:**

```

**Input:** arr = [10,5,10,10]
**Output:** [5,0,3,4]
**Explanation:**
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4

```

**Constraints:**
* `n == arr.length`
* `1 <= n <= 10^5`
* `1 <= arr[i] <= 10^5`


<br />

### Hints

- For each unique value found in the array, store a sorted list of indices of elements that have this value in the array.
- One way of doing this is to use a HashMap that maps the values to their list of indices. Update this mapping as you iterate through the array.
- Process each list of indices separately and get the sum of intervals for the elements of that value by utilizing prefix sums.
- For each element, keep track of the sum of indices of the identical elements that have come before and that will come after respectively. Use this to calculate the sum of intervals for that element to the rest of the elements with identical values.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <long long> getDistances (vector <int>& arr) {
      int n = arr.size();
      std::map <int, std::vector <int>> have;
      std::vector <long long> intervals (n);

      for (int i = 0; i < n; ++i)
        have[arr[i]].push_back(i);
      for (auto &[x, y]: have) {
        int s = y.size();
        int64_t sum = 0, left = 0, right = s - 1;
        for (int i = 0; i < s; ++i)
          sum += y[i] - y[0];
        intervals[y[0]] = sum;
        for (int i = 1; i < s; ++i) {
          int diff = y[i] - y[i - 1];
          ++left;
          sum += left * diff - right * diff;
          --right;
          intervals[y[i]] = sum;
        }
      }

      return intervals;
    }
};
```

<br />

### Statistics

- total accepted: 15047
- total submissions: 34829
- acceptance rate: 43.2%
- likes: 708
- dislikes: 28

<br />

### Similar Problems

- [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum) (Medium)

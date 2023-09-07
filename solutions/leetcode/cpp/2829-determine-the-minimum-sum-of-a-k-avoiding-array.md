# [2829] Determine the Minimum Sum of a k-avoiding Array

**[math, greedy]**

### Statement

You are given two integers,`n` and `k`.

An array of **distinct** positive integers is called a **k-avoiding** array if there does not exist any pair of distinct elements that sum to `k`.

Return *the **minimum** possible sum of a k-avoiding array of length* `n`.


**Example 1:**

```

**Input:** n = 5, k = 4
**Output:** 18
**Explanation:** Consider the k-avoiding array [1,2,4,5,6], which has a sum of 18.
It can be proven that there is no k-avoiding array with a sum less than 18.

```

**Example 2:**

```

**Input:** n = 2, k = 6
**Output:** 3
**Explanation:** We can construct the array [1,2], which has a sum of 3.
It can be proven that there is no k-avoiding array with a sum less than 3.

```

**Constraints:**
* `1 <= n, k <= 50`


<br />

### Hints

- <div class="_1l1MA">Try to start with the smallest possible integers.</div>
- <div class="_1l1MA">Check if the current number can be added to the array.</div>
- <div class="_1l1MA">To check if the current number can be added, keep track of already added numbers in a set.</div>
- <div class="_1l1MA">If the number <code>i</code> is added to the array, then <code>i + k</code> can not be added.</div>

<br />

### Solution

```cpp
class Solution {
  public:
    int minimumSum(int n, int k) {
      std::set <int> have;
      int x = 1, sum = 0;

      for (int i = 0; i < n; ++i) {
        while (true) {
          if (have.count(k - x)) {
            ++x;
            continue;
          }
          have.insert(x);
          sum += x;
          ++x;
          break;
        }
      }
      
      return sum;
    }
};
```

<br />

### Statistics

- total accepted: 23204
- total submissions: 39672
- acceptance rate: 58.5%
- likes: 188
- dislikes: 4

<br />

### Similar Problems

None

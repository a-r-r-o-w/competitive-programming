# [2554] Maximum Number of Integers to Choose From a Range I



### Statement

You are given an integer array `banned` and two integers `n` and `maxSum`. You are choosing some number of integers following the below rules:

* The chosen integers have to be in the range `[1, n]`.
* Each integer can be chosen **at most once**.
* The chosen integers should not be in the array `banned`.
* The sum of the chosen integers should not exceed `maxSum`.



Return *the **maximum** number of integers you can choose following the mentioned rules*.


**Example 1:**

```

**Input:** banned = [1,6,5], n = 5, maxSum = 6
**Output:** 2
**Explanation:** You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.

```

**Example 2:**

```

**Input:** banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
**Output:** 0
**Explanation:** You cannot choose any integer while following the mentioned conditions.

```

**Example 3:**

```

**Input:** banned = [11], n = 7, maxSum = 50
**Output:** 7
**Explanation:** You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.

```

**Constraints:**
* `1 <= banned.length <= 10^4`
* `1 <= banned[i], n <= 10^4`
* `1 <= maxSum <= 10^9`


<br />

### Hints

- Keep the banned numbers that are less than n in a set.
- Loop over the numbers from 1 to n and if the number is not banned, use it.
- Keep adding numbers while they are not banned, and their sum is less than k.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxCount (vector <int>& banned, int n, int maxSum) {
      int64_t sum = 0;
      int count = 0;
      std::unordered_set <int> remove (banned.begin(), banned.end());
      
      for (int i = 1; i <= n; ++i) {
        if (remove.count(i))
          continue;
        if (sum + i <= maxSum) {
          sum += i;
          ++count;
        }
        else
          break;
      }
      
      return count;
    }
};
```

<br />

### Statistics

- total accepted: 14043
- total submissions: 28341
- acceptance rate: 49.6%
- likes: 59
- dislikes: 4

<br />

### Similar Problems

- [First Missing Positive](https://leetcode.com/problems/first-missing-positive) (Hard)
- [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) (Easy)
- [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum) (Medium)
- [Replace Elements in an Array](https://leetcode.com/problems/replace-elements-in-an-array) (Medium)
- [Maximum Number of Integers to Choose From a Range II](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii) (Medium)

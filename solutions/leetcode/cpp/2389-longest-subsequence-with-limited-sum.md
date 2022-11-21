# [2389] Longest Subsequence With Limited Sum

**[array, binary-search, greedy, sorting, prefix-sum]**

### Statement

You are given an integer array `nums` of length `n`, and an integer array `queries` of length `m`.

Return *an array* `answer` *of length* `m` *where* `answer[i]` *is the **maximum** size of a **subsequence** that you can take from* `nums` *such that the **sum** of its elements is less than or equal to* `queries[i]`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** nums = [4,5,2,1], queries = [3,10,21]
**Output:** [2,3,4]
**Explanation:** We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.

```

**Example 2:**

```

**Input:** nums = [2,3,4,5], queries = [1]
**Output:** [0]
**Explanation:** The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
```

**Constraints:**
* `n == nums.length`
* `m == queries.length`
* `1 <= n, m <= 1000`
* `1 <= nums[i], queries[i] <= 106`


<br>

### Hints

- Solve each query independently.
- When solving a query, which elements of nums should you choose to make the subsequence as long as possible?
- Choose the smallest elements in nums that add up to a sum less than the query.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> answerQueries (vector <int>& nums, vector <int>& queries) {
      int n = nums.size(), m = queries.size();
      int i = 0, j = 0, sum = 0;
      std::vector <int> order (m);
      
      std::sort(nums.begin(), nums.end());
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return queries[l] < queries[r];
      });
      
      while (j < m) {
        while (i < n and sum + nums[i] <= queries[order[j]]) {
          sum += nums[i];
          ++i;
        }
        queries[order[j]] = i;
        ++j;
      }
      
      return queries;
    }
};
```

<br>

### Statistics

- total accepted: 26537
- total submissions: 41159
- acceptance rate: 64.5%
- likes: 398
- dislikes: 50

<br>

### Similar Problems

- [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number) (Easy)
- [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions) (Medium)

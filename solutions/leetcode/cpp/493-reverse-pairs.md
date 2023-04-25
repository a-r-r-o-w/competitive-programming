# [493] Reverse Pairs

**[array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set]**

### Statement

Given an integer array `nums`, return *the number of **reverse pairs** in the array*.

A **reverse pair** is a pair `(i, j)` where:

* `0 <= i < j < nums.length` and
* `nums[i] > 2 * nums[j]`.


**Example 1:**

```

**Input:** nums = [1,3,2,3,1]
**Output:** 2
**Explanation:** The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

```

**Example 2:**

```

**Input:** nums = [2,4,3,5,1]
**Output:** 3
**Explanation:** The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

```

**Constraints:**
* `1 <= nums.length <= 5 * 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`


<br />

### Hints

- Use the merge-sort technique.
- Divide the array into two parts and sort them.
- For each integer in the first part, count the number of integers that satisfy the condition from the second part. Use the pointer to help you in the counting process.

<br />

### Solution

```cpp
class Solution {
  public:
    int reversePairs (vector <int>& nums) {
      int ans = 0, n = nums.size();

      auto sort = [&] (auto self, int l, int r) -> std::vector <int64_t> {
        if (l == r)
          return { nums[l] };
        else {
          int m = (l + r) / 2;
          auto lchild = self(self, l, m);
          auto rchild = self(self, m + 1, r);
          std::vector <int64_t> result;
          
          int i = l, j = m + 1;

          while (j <= r) {
            while (i <= m and lchild[i - l] <= 2 * rchild[j - m - 1])
              ++i;
            ans += m - i + 1;
            ++j;
          }

          i = l, j = m + 1;

          while (i <= m and j <= r) {
            if (lchild[i - l] <= rchild[j - m - 1])
              result.push_back(lchild[i++ - l]);
            else
              result.push_back(rchild[j++ - m - 1]);
          }
          while (i <= m)
            result.push_back(lchild[i++ - l]);
          while (j <= r)
            result.push_back(rchild[j++ - m - 1]);
          return result;
        }
      };

      sort(sort, 0, n - 1);
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 120982
- total submissions: 392082
- acceptance rate: 30.9%
- likes: 4706
- dislikes: 221

<br />

### Similar Problems

- [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self) (Hard)
- [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum) (Hard)

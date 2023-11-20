# [1569] Number of Ways to Reorder Array to Get Same BST

**[array, math, divide-and-conquer, dynamic-programming, tree, union-find, binary-search-tree, memoization, combinatorics, binary-tree]**

### Statement

Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

* For example, given `nums = [2,1,3]`, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array `[2,3,1]` also yields the same BST but `[3,2,1]` yields a different BST.



Return *the number of ways to reorder* `nums` *such that the BST formed is identical to the original BST formed from* `nums`.

Since the answer may be very large, **return it modulo** `10^9 + 7`.


**Example 1:**
![](https://assets.leetcode.com/uploads/2020/08/12/bb.png)

```

**Input:** nums = [2,1,3]
**Output:** 1
**Explanation:** We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2020/08/12/ex1.png)

```

**Input:** nums = [3,4,5,1,2]
**Output:** 5
**Explanation:** The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]

```

**Example 3:**
![](https://assets.leetcode.com/uploads/2020/08/12/ex4.png)

```

**Input:** nums = [1,2,3]
**Output:** 0
**Explanation:** There are no other orderings of nums that will yield the same BST.

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= nums.length`
* All integers in `nums` are **distinct**.


<br />

### Hints

- Use a divide and conquer strategy.
- The first number will always be the root. Consider the numbers smaller and larger than the root separately. When merging the results together, how many ways can you order x elements in x+y positions?

<br />

### Solution

```cpp
class Solution {
  public:
    int numOfWays (vector <int>& nums) {
      const int mod = 1000000007;
      int n = nums.size();
      std::vector <std::vector <int64_t>> C (n + 1);

      for (int i = 0; i <= n; ++i) {
        C[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j)
          C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
      }

      auto dfs = [&] (auto self, std::vector <int>& v) -> int64_t {
        int k = v.size();
        if (k <= 2)
          return 1;
        
        std::vector <int> lchild, rchild;
        
        for (int i = 1; i < k; ++i) {
          if (v[i] < v[0])
            lchild.push_back(v[i]);
          else
            rchild.push_back(v[i]);
        }

        int64_t lans = self(self, lchild);
        int64_t rans = self(self, rchild);
        int64_t ans = lans * rans % mod;
        return ans * C[k - 1][lchild.size()] % mod;
      };

      return (dfs(dfs, nums) + mod - 1) % mod;
    }
};
```

<br />

### Statistics

- total accepted: 43745
- total submissions: 81435
- acceptance rate: 53.7%
- likes: 1478
- dislikes: 177

<br />

### Similar Problems

None

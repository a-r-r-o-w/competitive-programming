# [1187] Make Array Strictly Increasing

**[array, binary-search, dynamic-programming, sorting]**

### Statement

Given two integer arrays`arr1` and `arr2`, return the minimum number of operations (possibly zero) neededto make `arr1` strictly increasing.

In one operation, you can choose two indices`0 <=i < arr1.length`and`0 <= j < arr2.length`and do the assignment`arr1[i] = arr2[j]`.

If there is no way to make`arr1`strictly increasing,return`-1`.


**Example 1:**

```

**Input:** arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
**Output:** 1
**Explanation:** Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

```

**Example 2:**

```

**Input:** arr1 = [1,5,3,6,7], arr2 = [4,3,1]
**Output:** 2
**Explanation:** Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

```

**Example 3:**

```

**Input:** arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
**Output:** -1
**Explanation:** You can't make arr1 strictly increasing.
```

**Constraints:**
* `1 <= arr1.length, arr2.length <= 2000`
* `0 <= arr1[i], arr2[i] <= 10^9`




<br />

### Hints

- Use dynamic programming.
- The state would be the index in arr1 and the index of the previous element in arr2 after sorting it and removing duplicates.

<br />

### Solution

```cpp
class Solution {
  public:
    int makeArrayIncreasing (vector <int>& arr1, vector <int>& arr2) {
      // 1 4 5 5 6
      // 6 7
      // if arr1[i] <= arr1[i - 1]
      //   let k = index_upper_bound(arr1[i - 1])
      //   dp[i][k]
      // dp[i][j] = dp[]

      const int inf32 = 1 << 30;
      int n = arr1.size(), m = arr2.size();
      std::map <std::pair <int, int>, int> cache;

      std::sort(arr2.begin(), arr2.end());

      auto dfs = [&] (auto self, int i, int prev) -> int {
        if (i >= n)
          return 0;
        if (cache.count({i, prev}))
          return cache[{i, prev}];
        
        int ans = inf32;
        int k = std::upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        
        if (arr1[i] > prev)
          ans = self(self, i + 1, arr1[i]);
        if (k < m)
          ans = std::min(ans, 1 + self(self, i + 1, arr2[k]));
        
        return cache[{i, prev}] = ans;
      };

      int ans = dfs(dfs, 0, -1);
      return ans == inf32 ? -1 : ans;
    }
};
```

<br />

### Statistics

- total accepted: 46699
- total submissions: 78181
- acceptance rate: 59.7%
- likes: 1862
- dislikes: 40

<br />

### Similar Problems

- [Make Array Non-decreasing or Non-increasing](https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing) (Hard)

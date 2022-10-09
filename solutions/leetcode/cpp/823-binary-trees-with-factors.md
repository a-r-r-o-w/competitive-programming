# [823] Binary Trees With Factors

**[array, hash-table, dynamic-programming]**

### Statement

Given an array of unique integers, `arr`, where each integer `arr[i]` is strictly greater than `1`.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return *the number of binary trees we can make*. The answer may be too large so return the answer **modulo** `109 + 7`.


**Example 1:**

```

**Input:** arr = [2,4]
**Output:** 3
**Explanation:** We can make these trees: [2], [4], [4, 2, 2]
```

**Example 2:**

```

**Input:** arr = [2,4,5,10]
**Output:** 7
**Explanation:** We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
```

**Constraints:**
* `1 <= arr.length <= 1000`
* `2 <= arr[i] <= 109`
* All the values of `arr` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numFactoredBinaryTrees (vector <int>& arr) {
      const int mod = 1000000007;
      int n = arr.size();
      std::unordered_map <int, int> have;
      std::vector <int64_t> dp (n, 1);
      
      std::sort(arr.begin(), arr.end());
      
      for (int i = 0; i < n; ++i)
        have[arr[i]] = i;
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (arr[i] % arr[j] == 0) {
            int x = arr[i] / arr[j];
            if (have.count(x))
              dp[i] = (dp[i] + dp[j] * dp[have[x]]) % mod;
          }
        }
      }
      
      return std::accumulate(dp.begin(), dp.end(), (int64_t)0) % mod;
    }
};
```

<br>

### Statistics

- total accepted: 63395
- total submissions: 131803
- acceptance rate: 48.1%
- likes: 1804
- dislikes: 156

<br>

### Similar Problems

None

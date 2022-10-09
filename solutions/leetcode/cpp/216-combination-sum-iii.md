# [216] Combination Sum III

**[array, backtracking]**

### Statement

Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:

* Only numbers `1` through `9` are used.
* Each number is used **at most once**.



Return *a list of all possible valid combinations*. The list must not contain the same combination twice, and the combinations may be returned in any order.


**Example 1:**

```

**Input:** k = 3, n = 7
**Output:** [[1,2,4]]
**Explanation:**
1 + 2 + 4 = 7
There are no other valid combinations.
```

**Example 2:**

```

**Input:** k = 3, n = 9
**Output:** [[1,2,6],[1,3,5],[2,3,4]]
**Explanation:**
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

```

**Example 3:**

```

**Input:** k = 4, n = 1
**Output:** []
**Explanation:** There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

```

**Constraints:**
* `2 <= k <= 9`
* `1 <= n <= 60`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> combinationSum3 (int k, int n) {
      std::vector <std::vector <int>> ans;
      std::vector <int> current;
      
      current.reserve(k);
      
      auto dfs = [&] (auto self, int start, int sum) -> void {
        if ((int)current.size() == k) {
          if (sum == n)
            ans.push_back(current);
          return;
        }
        
        for (int i = start; i <= 9; ++i) {
          if (sum + i > n)
            break;
          current.push_back(i);
          self(self, i + 1, sum + i);
          current.pop_back();
        }
      };
      
      dfs(dfs, 1, 0);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 349724
- total submissions: 525124
- acceptance rate: 66.6%
- likes: 4006
- dislikes: 89

<br>

### Similar Problems

- [Combination Sum](https://leetcode.com/problems/combination-sum) (Medium)

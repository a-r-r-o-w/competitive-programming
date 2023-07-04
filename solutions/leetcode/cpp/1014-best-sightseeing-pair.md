# [1014] Best Sightseeing Pair

**[array, dynamic-programming]**

### Statement

You are given an integer array `values` where values[i] represents the value of the `ith` sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.

The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return *the maximum score of a pair of sightseeing spots*.


**Example 1:**

```

**Input:** values = [8,1,5,2,6]
**Output:** 11
**Explanation:** i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

```

**Example 2:**

```

**Input:** values = [1,2]
**Output:** 2

```

**Constraints:**
* `2 <= values.length <= 5 * 104`
* `1 <= values[i] <= 1000`


<br>

### Hints

- Can you tell the best sightseeing spot in one pass (ie. as you iterate over the input?)  What should we store or keep track of as we iterate to do this?

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxScoreSightseeingPair (vector <int>& values) {
      int n = values.size();
      int max_left = values[0], best = 0;
      
      for (int i = 1; i < n; ++i) {
        max_left = std::max(max_left, values[i - 1] + i - 1);
        best = std::max(best, max_left + values[i] - i);
      }
      
      return best;
    }
};
```

<br>

### Statistics

- total accepted: 72018
- total submissions: 121040
- acceptance rate: 59.5%
- likes: 2015
- dislikes: 44

<br>

### Similar Problems

None

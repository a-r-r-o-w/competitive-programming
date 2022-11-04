# [2418] Sort the People



### Statement

You are given an array of strings `names`, and an array `heights` that consists of **distinct** positive integers. Both arrays are of length `n`.

For each index `i`, `names[i]` and `heights[i]` denote the name and height of the `ith` person.

Return `names` *sorted in **descending** order by the people's heights*.


**Example 1:**

```

**Input:** names = ["Mary","John","Emma"], heights = [180,165,170]
**Output:** ["Mary","Emma","John"]
**Explanation:** Mary is the tallest, followed by Emma and John.

```

**Example 2:**

```

**Input:** names = ["Alice","Bob","Bob"], heights = [155,185,150]
**Output:** ["Bob","Alice","Bob"]
**Explanation:** The first Bob is the tallest, followed by Alice and the second Bob.

```

**Constraints:**
* `n == names.length == heights.length`
* `1 <= n <= 103`
* `1 <= names[i].length <= 20`
* `1 <= heights[i] <= 105`
* `names[i]` consists of lower and upper case English letters.
* All the values of `heights` are distinct.


<br>

### Hints

- Find the tallest person and swap with the first person, then find the second tallest person and swap with the second person, etc. Repeat until you fix all n people.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <string> sortPeople (vector <string>& names, vector <int>& heights) {
      int n = names.size();
      std::vector <int> order (n);
      std::vector <std::string> sorted (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int i, int j) {
        return heights[i] > heights[j];
      });
      
      for (int i = 0; i < n; ++i)
        sorted[i] = names[order[i]];
      
      return sorted;
    }
};
```

<br>

### Statistics

- total accepted: 15186
- total submissions: 18615
- acceptance rate: 81.6%
- likes: 68
- dislikes: 0

<br>

### Similar Problems

- [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) (Easy)

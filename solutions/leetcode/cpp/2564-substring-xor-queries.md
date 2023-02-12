# [2564] Substring XOR Queries



### Statement

You are given a **binary string** `s`, and a **2D** integer array `queries` where `queries[i] = [firsti, secondi]`.

For the `i^th` query, find the **shortest substring** of `s` whose **decimal value**, `val`, yields `secondi` when **bitwise XORed** with `firsti`. In other words, `val ^ firsti == secondi`.

The answer to the `i^th` query is the endpoints (**0-indexed**) of the substring `[lefti, righti]` or `[-1, -1]` if no such substring exists. If there are multiple answers, choose the one with the **minimum** `lefti`.

*Return an array* `ans` *where* `ans[i] = [lefti, righti]` *is the answer to the* `i^th` *query.*

A **substring** is a contiguous non-empty sequence of characters within a string.


**Example 1:**

```

**Input:** s = "101101", queries = [[0,5],[1,2]]
**Output:** [[0,2],[2,3]]
**Explanation:** For the first query the substring in range [0,2] is **"101"** which has a decimal value of **`5`**, and **`5 ^ 0 = 5`**, hence the answer to the first query is [0,2]. In the second query, the substring in range [2,3] is **"11",** and has a decimal value of **3**, and **3 `^ 1 = 2`**.So, [2,3] is returned for the second query. 


```

**Example 2:**

```

**Input:** s = "0101", queries = [[12,8]]
**Output:** [[-1,-1]]
**Explanation:** In this example there is no substring that answers the query, hence [-1,-1] is returned.

```

**Example 3:**

```

**Input:** s = "1", queries = [[4,5]]
**Output:** [[0,0]]
**Explanation:** For this example, the substring in range [0,0] has a decimal value of **`1`**, and **`1 ^ 4 = 5`**. So, the answer is [0,0].

```

**Constraints:**
* `1 <= s.length <= 10^4`
* `s[i]` is either `'0'` or `'1'`.
* `1 <= queries.length <= 10^5`
* `0 <= firsti, secondi <= 10^9`


<br />

### Hints

- You do not need to consider substrings having lengths greater than 30.
- Pre-process all substrings with lengths not greater than 30, and add the best endpoints to a dictionary.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> substringXorQueries (string s, vector <vector <int>>& queries) {
      std::vector <std::vector <int>> ans;
      std::map <int, std::pair <int, int>> have;
      int n = s.length();
      
      for (int i = 0; i < n; ++i) {
        int value = 0;
        for (int j = 0; j < 31 and i + j < n; ++j) {
          value = value * 2 + s[i + j] - '0';
          if (have.count(value)) {
            auto [start, len] = have[value];
            if (j < len)
              have[value] = {i, j};
          }
          else
            have[value] = {i, j};
        }
      }
      
      ans.reserve(queries.size());
      
      for (auto &q: queries) {
        int x = q[0] ^ q[1];
        auto f = have.find(x);
        if (f != have.end())
          ans.push_back({f->second.first, f->second.first + f->second.second});
        else
          ans.push_back({-1, -1});
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 5112
- total submissions: 17401
- acceptance rate: 29.4%
- likes: 109
- dislikes: 51

<br />

### Similar Problems

- [String Matching in an Array](https://leetcode.com/problems/string-matching-in-an-array) (Easy)

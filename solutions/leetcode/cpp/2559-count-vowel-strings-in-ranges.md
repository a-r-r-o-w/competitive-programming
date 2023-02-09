# [2559] Count Vowel Strings in Ranges



### Statement

You are given a **0-indexed** array of strings `words` and a 2D array of integers `queries`.

Each query `queries[i] = [li, ri]` asks us to find the number of strings present in the range `li` to `ri` (both **inclusive**) of `words` that start and end with a vowel.

Return an array `ans` of size `queries.length`, where `ans[i]` is the answer to the `i`^th query.

**Note** that the vowel letters are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.


**Example 1:**

```

**Input:** words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
**Output:** [2,3,0]
**Explanation:** The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

```

**Example 2:**

```

**Input:** words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
**Output:** [3,2,1]
**Explanation:** Every string satisfies the conditions, so we return [3,2,1].
```

**Constraints:**
* `1 <= words.length <= 10^5`
* `1 <= words[i].length <= 40`
* `words[i]` consists only of lowercase English letters.
* `sum(words[i].length) <= 3 * 10^5`
* `1 <= queries.length <= 10^5`
* `0 <= li <= ri <words.length`


<br />

### Hints

- Precompute the prefix sum of strings that start and end with vowels.
- Use unordered_set to store vowels.
- Check if the first and last characters of the string are present in the vowels set.
- Subtract prefix sum for range [l-1, r] to find the number of strings starting and ending with vowels.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> vowelStrings (vector <string>& words, vector <vector <int>>& queries) {
      int n = words.size();
      std::vector <int> pref (n + 1);
      
      auto is_vowel = [] (char c) -> bool {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
      };
      
      for (int i = 1; i <= n; ++i) {
        pref[i] = is_vowel(words[i - 1].front()) and is_vowel(words[i - 1].back());
        pref[i] += pref[i - 1];
      }
      
      std::vector <int> ans;
      
      for (auto &q: queries)
        ans.push_back(pref[q[1] + 1] - pref[q[0]]);
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 11308
- total submissions: 23661
- acceptance rate: 47.8%
- likes: 98
- dislikes: 3

<br />

### Similar Problems

- [Jump Game VII](https://leetcode.com/problems/jump-game-vii) (Medium)

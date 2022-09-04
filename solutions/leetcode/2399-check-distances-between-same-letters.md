# [2399] Check Distances Between Same Letters



### Statement

You are given a **0-indexed** string `s` consisting of only lowercase English letters, where each letter in `s` appears **exactly** **twice**. You are also given a **0-indexed** integer array `distance` of length `26`.

Each letter in the alphabet is numbered from `0` to `25` (i.e. `'a' -> 0`, `'b' -> 1`, `'c' -> 2`, ... , `'z' -> 25`).

In a **well-spaced** string, the number of letters between the two occurrences of the `ith` letter is `distance[i]`. If the `ith` letter does not appear in `s`, then `distance[i]` can be **ignored**.

Return `true` *if* `s` *is a **well-spaced** string, otherwise return* `false`.


**Example 1:**

```

**Input:** s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
**Output:** true
**Explanation:**
- 'a' appears at indices 0 and 2 so it satisfies distance[0] = 1.
- 'b' appears at indices 1 and 5 so it satisfies distance[1] = 3.
- 'c' appears at indices 3 and 4 so it satisfies distance[2] = 0.
Note that distance[3] = 5, but since 'd' does not appear in s, it can be ignored.
Return true because s is a well-spaced string.

```

**Example 2:**

```

**Input:** s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
**Output:** false
**Explanation:**
- 'a' appears at indices 0 and 1 so there are zero letters between them.
Because distance[0] = 1, s is not a well-spaced string.

```

**Constraints:**
* `2 <= s.length <= 52`
* `s` consists only of lowercase English letters.
* Each letter appears in `s` exactly twice.
* `distance.length == 26`
* `0 <= distance[i] <= 50`


<br>

### Hints

- Create an integer array of size 26 to keep track of the first occurrence of each letter.
- The number of letters between indices i and j is j - i - 1.

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkDistances (string s, vector <int>& distance) {
      int n = s.size();
      bool okay = true;
      
      for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        int first = -1;
        int second = -1;
        
        for (int j = 0; j < n; ++j) {
          if (s[j] == c) {
            if (first == -1)
              first = j;
            else if (second == -1)
              second = j;
          }
        }
        
        if (first == -1 or second == -1)
          continue;
        
        if (second - first - 1 != distance[i]) {
          okay = false;
          break;
        }
      }
      
      return okay;
    }
};
```

<br>

### Statistics

- total accepted: 14540
- total submissions: 20864
- acceptance rate: 69.7%
- likes: 59
- dislikes: 2

<br>

### Similar Problems

- [Two Sum](https://leetcode.com/problems/two-sum) (Easy)
- [Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character) (Easy)

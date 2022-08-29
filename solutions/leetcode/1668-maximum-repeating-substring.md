# [1668] Maximum Repeating Substring

**[string, string-matching]**

### Statement

For a string `sequence`, a string `word` is **`k`-repeating** if `word` concatenated `k` times is a substring of `sequence`. The `word`'s **maximum `k`-repeating value** is the highest value `k` where `word` is `k`-repeating in `sequence`. If `word` is not a substring of `sequence`, `word`'s maximum `k`-repeating value is `0`.

Given strings `sequence` and `word`, return *the **maximum `k`-repeating value** of `word` in `sequence`*.


**Example 1:**

```

**Input:** sequence = "ababc", word = "ab"
**Output:** 2
**Explanation:** "abab" is a substring in "ababc".

```

**Example 2:**

```

**Input:** sequence = "ababc", word = "ba"
**Output:** 1
**Explanation:** "ba" is a substring in "ababc". "baba" is not a substring in "ababc".

```

**Example 3:**

```

**Input:** sequence = "ababc", word = "ac"
**Output:** 0
**Explanation:** "ac" is not a substring in "ababc". 

```

**Constraints:**
* `1 <= sequence.length <= 100`
* `1 <= word.length <= 100`
* `sequence` and `word`contains only lowercase English letters.


<br>

### Hints

- The constraints are low enough for a brute force approach.
- Try every k value from 0 upwards until word is no longer k-repeating.

<br>

### Solution

**Brute force**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxRepeating (string sequence, string word) {
      int k = 0;
      std::string r = word;
      
      while (true) {
        if (sequence.find(r) == std::string::npos)
          break;
        ++k;
        r += word;
      }
      
      return k;
    }
};
```

**Z function**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int maxRepeating (string sequence, string word) {
      std::string x = word + '#' + sequence;
      int n = x.size(), m = word.size();
      std::vector <int> z (n);
      
      for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
          z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n and x[z[i]] == x[i + z[i]])
          ++z[i];
        if (i + z[i] - 1 > r) {
          l = i;
          r = i + z[i] - 1;
        }
      }
      
      int ans = 0;
      
      for (int i = 0; i < n; ++i) {
        if (z[i] == m) {
          int count = 0;
          int j = i;
          
          while (j < n and z[j] == m) {
            ++count;
            j += m;
          }
          
          ans = std::max(ans, count);
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 27154
- total submissions: 68404
- acceptance rate: 39.7%
- likes: 429
- dislikes: 147

<br>

### Similar Problems

- [Detect Pattern of Length M Repeated K or More Times](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times) (Easy)

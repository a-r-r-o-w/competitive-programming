# [5] Longest Palindromic Substring

**[string, dynamic-programming]**

### Statement

Given a string `s`, return *the longest palindromic substring* in `s`.


**Example 1:**

```

**Input:** s = "babad"
**Output:** "bab"
**Explanation:** "aba" is also a valid answer.

```

**Example 2:**

```

**Input:** s = "cbbd"
**Output:** "bb"

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s` consist of only digits and English letters.


<br>

### Hints

- How can we reuse a previously computed palindrome to compute a larger palindrome?
- If “aba” is a palindrome, is “xabax” a palindrome? Similarly is “xabay” a palindrome?
- Complexity based hint:</br>
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.

<br>

### Solution

Brute force

O(n^3)

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
    string longestPalindrome (string s) {
      int n = s.length();
      int max = 0;
      std::string ans;
      
      auto is_palindrome = [&] (const std::string &p) {
        int k = p.length();
        for (int i = 0; i < k / 2; ++i)
          if (p[i] != p[k - i - 1])
            return false;
        return true;
      };
      
      std::string current;
      
      for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
          current += s[r];
          
          if (r - l + 1 > max and is_palindrome(current)) {
            max = r - l + 1;
            ans = current;
          }
        }
        
        current.clear();
      }
      
      return ans;
    }
};
```

Binary searching max length of palindrome substring and checking for existence

O(n^2.log(n))

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string longestPalindrome (string s) {
      int n = s.length();
      
      auto is_palindrome = [&] (const std::string &p) {
        int k = p.length();
        for (int i = 0; i < k / 2; ++i)
          if (p[i] != p[k - i - 1])
            return false;
        return true;
      };
      
      auto cost = [&] (int len) {
        for (int l = 0; l + len - 1 < n; ++l)
          if (is_palindrome(s.substr(l, len)))
            return l;
        return -1;
      };
      
      int max = 1;
      int start = 0;
        
      int low = 1, high = n + 1;

      while (low < high) {
        int mid = (low + high) / 2;
        int r = cost(mid);
        bool found = true;

        if (r == -1) {
          if (mid + 1 < high) {
            r = cost(mid + 1);
            if (r == -1)
              found = false;
          }
          else
            found = false;
        }
        
        if (found) {
          if (mid > max) {
            max = mid;
            start = r;
          }
          low = mid + 1;
        }
        else
          high = mid;
      }
      
      return s.substr(start, max);
    }
};
```

Alternative binary search implementation

O(n^2.log(n))

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string longestPalindrome (string s) {
      int n = s.length();
      
      auto is_palindrome = [&] (const std::string &p) {
        int k = p.length();
        for (int i = 0; i < k / 2; ++i)
          if (p[i] != p[k - i - 1])
            return false;
        return true;
      };
      
      auto cost = [&] (int len) {
        for (int l = 0; l + len - 1 < n; ++l)
          if (is_palindrome(s.substr(l, len)))
            return l;
        return -1;
      };
      
      int max = 1;
      int start = 0;
        
      int low = 1, high = n + 1;

      while (low < high) {
        int mid = (low + high) / 2;
        int r = cost(mid);

        if (r == -1) {
          if (mid + 1 < high) {
            r = cost(mid + 1);
            if (r == -1)
              high = mid;
            else {
              if (mid + 1 > max) {
                max = mid + 1;
                start = r;
              }
              low = mid + 2;
            }
          }
          else
            high = mid;
        }
        else {
          if (mid > max) {
            max = mid;
            start = r;
          }
          low = mid + 1;
        }
      }
      
      return s.substr(start, max);
    }
};
```

Expanding palindromes about midpoint

O(n^2)

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string longestPalindrome (string s) {
      int n = s.length();
      int max = 1, start = 0;
      
      for (int mid = 0; mid < n; ++mid) {
        for (int x = 1; mid - x >= 0 and mid + x < n; ++x) {
          if (s[mid - x] != s[mid + x])
            break;
          
          int len = 2 * x + 1;
          
          if (len > max) {
            max = len;
            start = mid - x;
          }
        }
      }
      
      for (int mid = 0; mid < n; ++mid) {
        for (int x = 1; mid - x + 1 >= 0 and mid + x < n; ++x) {
          if (s[mid - x + 1] != s[mid + x])
            break;
          
          int len = 2 * x;
          
          if (len > max) {
            max = len;
            start = mid - x + 1;
          }
        }
      }
      
      return s.substr(start, max);
    }
};
```

Manacher algorithm

O(n)

```cpp
namespace arrow {
  namespace string {

    /**
     * @brief Z-function for a string finds an array of length n where the i-th element
     *        is the greatest number of characters starting from position i that coincides
     *        with a prefix of `s`
     *        - Time complexity: O(n.n)
     *        - Space complexity: O(n)
     * 
     * This is a naive implementation for calculating the Z-function
     * 
     * @param s std::string
     * @return std::vector <int32_t> Z-function of `s`
     */
    std::vector <int32_t> z_function_quadratic (const std::string &s) {
      int32_t n = s.size();
      std::vector <int32_t> z (n);

      for (int i = 1; i < n; ++i) {
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
          ++z[i];
      }

      return z;
    }

    /**
     * @brief Z-function for a string finds an array of length n where the i-th element
     *        is the greatest number of characters starting from position i that coincides
     *        with a prefix of `s`
     *        - Time complexity: O(n)
     *        - Space complexity: O(n)
     * 
     * @param s std::string
     * @return std::vector <int32_t> Z-function of `s`
     */
    std::vector <int32_t> z_function_linear (const std::string &s) {
      int32_t n = s.size();
      std::vector <int32_t> z (n);

      for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
          z[i] = std::min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
          ++z[i];
        
        if (i + z[i] - 1 > r) {
          l = i;
          r = i + z[i] - 1;
        }
      }

      return z;
    }

    /**
     * @brief Check if the string `pattern` occurs in the string `text`
     *          - Time complexity: O((m - n + 1).n)
     *          - Space complexity: O(1)
     * 
     * @param text std::string
     * @param pattern std::string
     * @return int32_t -1 if match not found else index of first match in range [0, text.length)
     */
    int32_t naive_find (const std::string &text, const std::string &pattern) {
      int32_t m = text.size(), n = pattern.size();

      for (int32_t i = 0; i + n - 1 < m; ++i) {
        bool bad = false;
        
        for (int32_t j = 0; j < n; ++j) {
          if (text[i + j] != pattern[j]) {
            bad = true;
            break;
          }
        }
        
        if (not bad)
          return i;
      }

      return -1;
    }

    /**
     * @brief Check if the string `pattern` occurs in the string `text`
     *        - Time complexity: O(m + n)
     *        - Space complexity: O(m + n)
     * 
     * @param text std::string
     * @param pattern std::string
     * @return int32_t -1 if match not found else index of first match in range [0, text.length)
     */
    int32_t z_function_find (const std::string &text, std::string pattern) {
      int32_t m = text.size(), n = pattern.size();

      pattern += '#';
      pattern += text;

      auto z = z_function_linear(pattern);

      for (int32_t i = 0; i < m; ++i)
        if (z[i + n + 1] == n)
          return i;
      return -1;
    }

    /**
     * @brief Check if the string `pattern` occurs in the string `text`
     *          - Time complexity: O(m + n)
     *          - Space complexity: O(n + alphabet.length)
     * 
     * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string-search_algorithm
     * 
     * Worst case runtime of this algorithm is O((m - n + 1).n)
     * 
     * Note: This implementation has a fixed alphabet size of 256
     * 
     * @param text 
     * @param pattern 
     * @return int32_t -1 if match not found else index of first match in range [0, text.length)
     */
    int32_t boyer_moore_find (const std::string &text, const std::string &pattern) {
      const int32_t alphabet_size = 256;
      int32_t m = text.size(), n = pattern.size();

      if (m < n)
        return -1;
      if (n == 0)
        return 0;
      
      // table for bad character rule
      std::array <int32_t, alphabet_size> bad_char_table;

      // tables for good suffix rule
      std::vector <int32_t> border_position (n + 1), good_suffix_table (n + 1);

      // characters that do not exist are represented as -1
      bad_char_table.fill(-1);

      // initialise table with last occurrences of each letter in `pattern`
      for (int32_t i = 0; i < n; ++i)
        bad_char_table[pattern[i]] = i;
      
      // strong good suffix rule 1
      // border: suffix of a string that is also a prefix of the string
      {
        int32_t i = n, j = n + 1;
        
        // the suffix epsilon (empty string) at position n has no border
        border_position[i] = j;
        
        while (i > 0) {
          // at this point, we know the border positions for [i, n] (n inclusive because empty string considered)
          // if character at position i - 1 is not equal to character at position j - 1, continue searching
          // to right of pattern for border
          while (j <= n and pattern[i - 1] != pattern[j - 1]) {
            // character preceding the occurrence of t in `pattern` is different than the mismatched character
            // in `pattern` => stop skipping occurrences and shift the pattern from i to j
            if (good_suffix_table[j] == 0)
              good_suffix_table[j] = j - i;
            
            // start position of border in suffix pattern[j:m]
            j = border_position[j];
          }

          // pattern[i - 1] matched with pattern[j - 1] => border is found. store beginning position
          --i;
          --j;
          border_position[i] = j;
        }
      }

      // strong good suffix rule 2
      {
        int32_t i = 0, j = border_position[0];

        while (i <= n) {
          // set the border position of first character of the pattern to all indices
          // with good suffix shift = 0
          if (good_suffix_table[i] == 0)
            good_suffix_table[i] = j;
          
          // suffix becomes shorter than border => use the next widest border
          if (i == j)
            j = border_position[j];
          
          ++i;
        }
      }

      int32_t i = 0, j = 0;

      while (i + n - 1 < m) {
        j = n - 1;
        
        // keep checking characters from end to start of substring text[i:i+n] and pattern[0:n]
        while (j >= 0 and text[i + j] == pattern[j])
          --j;
        
        // match found as pattern was completely traversed
        if (j < 0)
          return i;
        
        // shift by max possible shift from bad character rule and good suffix rule
        i += std::max(good_suffix_table[j + 1], j - bad_char_table[text[i + j]]);
      }

      return -1;
    }

    /**
     * @brief Check if the string `pattern` occurs in the string `text`
     *        - Time complexity: O(m + n)
     *            m = text.length
     *            n = pattern.length
     *        - Space complexity: O(alphabet.length)
     * 
     * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore%E2%80%93Horspool_algorithm
     * 
     * Worst case runtime of this algorithm is O(m.n)
     * 
     * Note: This implementation has a fixed alphabet size of 256
     * 
     * @param text std::string
     * @param pattern std::string
     * @return int32_t -1 if match not found else index of first match in range [0, text.length)
     */
    int32_t boyer_moore_horspool_find (const std::string &text, const std::string &pattern) {
      const int32_t alphabet_size = 256;
      int32_t m = text.size(), n = pattern.size();

      if (m < n)
        return -1;
      
      // table for bad character rule
      std::array <int32_t, alphabet_size> bad_char_table;

      // characters that do not exist are represented as -1
      bad_char_table.fill(-1);

      // initialise table with last occurrences of each letter in `pattern`
      for (int32_t i = 0; i < n; ++i)
        bad_char_table[pattern[i]] = i;
      
      int32_t i = 0, j = 0;

      while (i + n - 1 < m) {
        j = n - 1;

        // keep checking characters from end to start of substring text[i:i+n] and pattern[0:n]
        while (j >= 0 and text[i + j] == pattern[j])
          --j;
        
        // match found as pattern was completely traversed
        if (j < 0)
          return i;
        
        // shift pattern such that bad character from `text` is aligned with the last occurrence
        // of it in `pattern`
        // negative shift may be produced if last occurrence of bad character in `pattern` is
        // after the current character
        i += std::max(1, j - bad_char_table[text[i + j]]);
      }

      return -1;
    }

    /**
     * @brief Check if the string `pattern` occurs in the string `text`
     *        - Time complexity: O(m + n)
     *            m = text.length
     *            n = pattern.length
     *        - Space complexity: O(1)
     * 
     * https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm
     * 
     * Worst case runtime of this algorithm is O((m - n + 1).n)
     * 
     * Note: This implementation has a fixed alphabet size of 256. The base must be increased
     *       to support more characters
     * 
     * @param text std::string
     * @param pattern std::string
     * @return int32_t -1 if match not found else index of first match in range [0, text.length)
     */
    int32_t rabin_karp_find (const std::string &text, const std::string &pattern) {
      const int64_t base = 256;
      const int64_t modulo = 1'000'000'009;
      int32_t m = text.size(), n = pattern.size();

      if (m < n)
        return -1;
      if (n == 0)
        return 0;

      // h: pow(base, n - 1) % modulo to perform O(1) calculations
      // t: hash of substring text[i:i+n]
      // p: hash of substring pattern[0:n]
      int64_t h = 1, t = 0, p = 0;

      for (int32_t i = 0; i < n - 1; ++i) {
        h = (h * base) % modulo;
        t = (base * t + text[i]) % modulo;
        p = (base * p + pattern[i]) % modulo;
      }

      t = (base * t + text[n - 1]) % modulo;
      p = (base * p + pattern[n - 1]) % modulo;

      for (int32_t shift = 0; shift < m - n + 1; ++shift) {
        // spurious hit
        // naive comparison required as hashes may collide
        if (t == p) {
          bool bad = false;

          for (int32_t i = 0; i < n; ++i) {
            if (text[shift + i] != pattern[i]) {
              bad = true;
              break;
            }
          }

          if (not bad)
            return shift;
        }

        // O(1) calculation for next length `n` substring of `text`
        if (shift < m - n) {
          t = (base * (t - text[shift] * h) + text[shift + n]) % modulo;
          if (t < 0)
            t += modulo;
        }
      }

      return -1;
    }

    std::vector <int32_t> manacher_odd (const std::string &s) {
      int32_t n = s.length();
      std::vector <int32_t> d1 (n);

      for (int32_t i = 0, l = 0, r = -1; i < n; ++i) {
        d1[i] = i > r ? 1 : std::min(r - i + 1, d1[l + r - i]);

        while (i - d1[i] >= 0 and i + d1[i] < n and s[i - d1[i]] == s[i + d1[i]])
          ++d1[i];
        
        if (i + d1[i] - 1 > r) {
          l = i - d1[i] + 1;
          r = i + d1[i] - 1;
        }
      }

      return d1;
    }

    std::vector <int32_t> manacher_even (const std::string &s) {
      int32_t n = s.length();
      std::vector <int32_t> d2 (n);

      for (int32_t i = 0, l = 0, r = -1; i < n; ++i) {
        d2[i] = i > r ? 0 : std::min(r - i + 1, d2[l + r - i + 1]);

        while (i - d2[i] - 1 >= 0 and i + d2[i] < n and s[i - d2[i] - 1] == s[i + d2[i]])
          ++d2[i];
        
        if (i + d2[i] - 1 > r) {
          l = i - d2[i];
          r = i + d2[i] - 1;
        }
      }

      return d2;
    }

    std::tuple <std::vector <int32_t>, std::vector <int32_t>, std::vector <int32_t>> manacher (const std::string &s) {
      std::string t;

      t += '<';
      for (auto &c: s) {
        t += '#';
        t += c;
      }
      t += '#';
      t += '>';

      int32_t n = t.length();
      std::vector <int32_t> d (n);

      for (int32_t i = 1, l = 1, r = 1; i < n - 1; ++i) {
        d[i] = std::max(0, std::min(r - i, d[l + r - i]));
        
        while (t[i - d[i]] == t[i + d[i]])
          ++d[i];
        
        if (i + d[i] > r) {
          l = i - d[i];
          r = i + d[i];
        }
      }

      int32_t m = s.length();
      std::vector <int32_t> d1 (m);
      std::vector <int32_t> d2 (m);
      
      for (int i = 0; i < m; ++i) {
        d1[i] = d[2 * i + 2] / 2;
        d2[i] = (d[2 * i + 1] - 1) / 2;
      }

      return {d, d1, d2};
    }

  }
}

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    string longestPalindrome (string s) {
      int n = s.length();
      
      auto [d, d1, d2] = arrow::string::manacher(s);
      
      auto m1 = std::max_element(d1.begin(), d1.end());
      auto m2 = std::max_element(d2.begin(), d2.end());
      int pos1 = m1 - d1.begin();
      int pos2 = m2 - d2.begin();
      int len1 = 2 * *m1 - 1;
      int len2 = 2 * *m2;
      
      if (len1 > len2)
        return s.substr(pos1 - *m1 + 1, len1);
      return s.substr(pos2 - *m2, len2);
    }
};
```

<br>

### Statistics

- total accepted: 2033556
- total submissions: 6298174
- acceptance rate: 32.3%
- likes: 20636
- dislikes: 1182

<br>

### Similar Problems

- [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome) (Hard)
- [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation) (Easy)
- [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs) (Hard)
- [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) (Medium)
- [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings) (Medium)

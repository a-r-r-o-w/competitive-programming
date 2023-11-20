# [2131] Longest Palindrome by Concatenating Two Letter Words

**[array, hash-table, string, greedy, counting]**

### Statement

You are given an array of strings `words`. Each element of `words` consists of **two** lowercase English letters.

Create the **longest possible palindrome** by selecting some elements from `words` and concatenating them in **any order**. Each element can be selected **at most once**.

Return *the **length** of the longest palindrome that you can create*. If it is impossible to create any palindrome, return `0`.

A **palindrome** is a string that reads the same forward and backward.


**Example 1:**

```

**Input:** words = ["lc","cl","gg"]
**Output:** 6
**Explanation:** One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

```

**Example 2:**

```

**Input:** words = ["ab","ty","yt","lc","cl","ab"]
**Output:** 8
**Explanation:** One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

```

**Example 3:**

```

**Input:** words = ["cc","ll","xx"]
**Output:** 2
**Explanation:** One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".

```

**Constraints:**
* `1 <= words.length <= 105`
* `words[i].length == 2`
* `words[i]` consists of lowercase English letters.


<br>

### Hints

- A palindrome must be mirrored over the center. Suppose we have a palindrome. If we prepend the word "ab" on the left, what must we append on the right to keep it a palindrome?
- We must append "ba" on the right. The number of times we can do this is the minimum of (occurrences of "ab") and (occurrences of "ba").
- For words that are already palindromes, e.g. "aa", we can prepend and append these in pairs as described in the previous hint. We can also use exactly one in the middle to form an even longer palindrome.

<br>

### Solution

Using Multiset

```cpp
class Solution {
  public:
    int longestPalindrome (vector <string>& words) {
      std::multiset <std::pair <char, char>> have;
      int ans = 0;
      
      for (auto &word: words) {
        std::pair <char, char> check = {word[1], word[0]};
        auto f = have.find(check);
        
        if (f != have.end()) {
          ans += 4;
          have.erase(f);
        }
        else
          have.insert({word[0], word[1]});
      }
      
      for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        if (have.count({c, c})) {
          ans += 2;
          break;
        }
      }
      
      return ans;
    }
};
```

Optimising Multiset approach to reduce space required

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestPalindrome (vector <string>& words) {
      const int factor = 256;
      
      std::multiset <int> have;
      int ans = 0;
      
      for (auto &word: words) {
        int check = word[1] * factor + word[0];
        auto f = have.find(check);
        
        if (f != have.end()) {
          ans += 4;
          have.erase(f);
        }
        else
          have.insert(word[0] * factor + word[1]);
      }
      
      for (int i = 0; i < 26; ++i) {
        char c = i + 'a';
        int check = c * factor + c;
        
        if (have.count(check)) {
          ans += 2;
          break;
        }
      }
      
      return ans;
    }
};
```

Frequency counting of each string

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestPalindrome (vector <string>& words) {
      std::vector <std::vector <int>> have (26, std::vector <int> (26));
      int ans = 0;
      bool has_same = false;
      
      for (auto &word: words)
        ++have[word[0] - 'a'][word[1] - 'a'];
      
      for (int i = 0; i < 26; ++i) {
        for (int j = i; j < 26; ++j) {
          if (i == j) {
            if (have[i][j] & 1)
              has_same = true;
            ans += 2 * (have[i][j] / 2 * 2);
          }
          else
            ans += 4 * std::min(have[i][j], have[j][i]);
        }
      }
      
      ans += 2 * has_same;
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 59684
- total submissions: 127162
- acceptance rate: 46.9%
- likes: 1413
- dislikes: 27

<br>

### Similar Problems

- [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs) (Hard)
- [Longest Palindrome](https://leetcode.com/problems/longest-palindrome) (Easy)

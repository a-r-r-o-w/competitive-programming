# [336] Palindrome Pairs

**[array, hash-table, string, trie]**

### Statement

Given a list of **unique** words, return all the pairs of the***distinct*** indices `(i, j)` in the given list, so that the concatenation of the two words`words[i] + words[j]` is a palindrome.


**Example 1:**

```

**Input:** words = ["abcd","dcba","lls","s","sssll"]
**Output:** [[0,1],[1,0],[3,2],[2,4]]
**Explanation:** The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

```

**Example 2:**

```

**Input:** words = ["bat","tab","cat"]
**Output:** [[0,1],[1,0]]
**Explanation:** The palindromes are ["battab","tabbat"]

```

**Example 3:**

```

**Input:** words = ["a",""]
**Output:** [[0,1],[1,0]]

```

**Constraints:**
* `1 <= words.length <= 5000`
* `0 <= words[i].length <= 300`
* `words[i]` consists of lower-case English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
bool is_palindrome (const std::string &s, int l, int r) {
  while (l < r) {
    if (s[l] != s[r])
      return false;
    ++l;
    --r;
  }
  return true;
}

class trie {
  private:
    int index;
    std::vector <trie*> children;
    std::vector <int> indices;
  
  public:
    trie ()
      : index (-1),
        children (26, nullptr)
    { }

    void insert (const std::string &s, int index) {
      trie *node = this;
      int n = s.length();

      for (int i = n - 1; i >= 0; --i) {
        int pos = s[i] - 'a';

        if (is_palindrome(s, 0, i))
          node->indices.push_back(index);

        if (node->children[pos] == nullptr)
          node->children[pos] = new trie();

        node = node->children[pos];
      }

      node->index = index;
      node->indices.push_back(index);
    }

    void search (const std::string& s, int index, std::vector <std::vector <int>> &result) {
      trie *node = this;
      int n = s.length();

      for (int i = 0; i < n and node != nullptr; ++i) {
        if (node->index != -1 and node->index != index and is_palindrome(s, i, n - 1))
          result.push_back({index, node->index});
        node = node->children[s[i] - 'a'];
      }

      if (node != nullptr)
        for (int i: node->indices)
          if (i != index)
            result.push_back({index, i});
    }
};

class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <vector <int>> palindromePairs (vector <string>& words) {
      std::vector <std::vector <int>> result;
      trie t;
      int n = words.size();
      
      for (int i = 0; i < n; ++i)
        t.insert(words[i], i);
      
      for (int i = 0; i < n; ++i)
        t.search(words[i], i, result);
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 177721
- total submissions: 503217
- acceptance rate: 35.3%
- likes: 3800
- dislikes: 385

<br>

### Similar Problems

- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) (Medium)
- [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome) (Hard)
- [Longest Palindrome by Concatenating Two Letter Words](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words) (Medium)

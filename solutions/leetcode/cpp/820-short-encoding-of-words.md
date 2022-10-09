# [820] Short Encoding of Words

**[array, hash-table, string, trie]**

### Statement

A **valid encoding** of an array of `words` is any reference string `s` and array of indices `indices` such that:

* `words.length == indices.length`
* The reference string `s` ends with the `'#'` character.
* For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.



Given an array of `words`, return *the **length of the shortest reference string*** `s` *possible of any **valid encoding** of* `words`*.*
**Example 1:**

```

**Input:** words = ["time", "me", "bell"]
**Output:** 10
**Explanation:** A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

```

**Example 2:**

```

**Input:** words = ["t"]
**Output:** 2
**Explanation:** A valid encoding would be s = "t#" and indices = [0].

```

**Constraints:**
* `1 <= words.length <= 2000`
* `1 <= words[i].length <= 7`
* `words[i]` consists of only lowercase letters.


<br>

### Hints

None

<br>

### Solution

**Brute Force**

```cpp
class Solution {
  public:
    int minimumLengthEncoding (vector <string>& words) {
      int n = words.size();
      
      std::sort(words.begin(), words.end(), [&] (auto& l, auto& r) { return l.length() < r.length(); });
      std::vector <bool> removed (n);
      
      for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
          if (removed[j])
            continue;
          
          int p = words[i].length();
          int q = words[j].length();
          bool bad = false;
          
          for (int k = 0; k < p; ++k)
            if (words[i][p - k - 1] != words[j][q - k - 1]) {
              bad = true;
              break;
            }
          
          if (not bad)
            removed[i] = true;
        }
      }
      
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        if (removed[i])
          continue;
        ans += words[i].length() + 1;
      }
      
      return ans;
    }
};
```

**Trie**

```cpp
struct trie {
  std::vector <trie*> children;
  bool end;

  trie ()
    : children (std::vector <trie*> (26)),
      end (false) {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
  }

  ~trie () {
    for (int i = 0; i < 26; ++i)
      if (children[i] != nullptr)
        delete children[i];
  }

  void insert (const std::string& s) {
    trie* node = this;
    bool any_added = false;
    for (char c: s) {
      if (node->children[c - 'a'] == nullptr) {
        node->children[c - 'a'] = new trie();
        any_added = true;
      }
      node = node->children[c - 'a'];
    }
    end = true;
  }
  
  int get (int depth = 0) {
    bool are_all_null = true;
    int count = 0;
    for (int i = 0; i < 26; ++i) {
      if (children[i] == nullptr)
        continue;
      are_all_null = false;
      count += children[i]->get(depth + 1);
    }
    return are_all_null ? depth + 1 : count;
  }
};

class Solution {
  public:
    int minimumLengthEncoding (vector <string>& words) {
      int n = words.size();
      trie t;
      
      for (int i = 0; i < n; ++i) {
        std::reverse(words[i].begin(), words[i].end());
        t.insert(words[i]);
      }
      
      return t.get();
    }
};
```

<br>

### Statistics

- total accepted: 67260
- total submissions: 114813
- acceptance rate: 58.6%
- likes: 1207
- dislikes: 474

<br>

### Similar Problems

None

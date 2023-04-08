# [208] Implement Trie (Prefix Tree)

**[hash-table, string, design, trie]**

### Statement

A [**trie**](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

* `Trie()` Initializes the trie object.
* `void insert(String word)` Inserts the string `word` into the trie.
* `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
* `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.


**Example 1:**

```

**Input**
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
**Output**
[null, null, true, false, true, null, true]

**Explanation**
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

```

**Constraints:**
* `1 <= word.length, prefix.length <= 2000`
* `word` and `prefix` consist only of lowercase English letters.
* At most `3 * 10^4` calls **in total** will be made to `insert`, `search`, and `startsWith`.


<br />

### Hints

None

<br />

### Solution

```cpp
class Trie {
  private:
    std::vector <Trie*> children;
    bool is_terminal;

  public:
    Trie () {
      children.resize(26);
      is_terminal = false;
    }
    
    void insert (string word) {
      Trie *node = this;
      for (char c: word) {
        if (node->children[c - 'a'] == nullptr)
          node->children[c - 'a'] = new Trie();
        node = node->children[c - 'a'];
      }
      node->is_terminal = true;
    }
    
    bool search (string word) {
      Trie *node = this;
      for (char c: word) {
        if (node->children[c - 'a'] == nullptr)
          return false;
        node = node->children[c - 'a'];
      }
      return node->is_terminal;
    }
    
    bool startsWith (string prefix) {
      Trie *node = this;
      for (char c: prefix) {
        if (node->children[c - 'a'] == nullptr)
          return false;
        node = node->children[c - 'a'];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

<br />

### Statistics

- total accepted: 748484
- total submissions: 1213273
- acceptance rate: 61.7%
- likes: 9105
- dislikes: 111

<br />

### Similar Problems

- [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure) (Medium)
- [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system) (Hard)
- [Replace Words](https://leetcode.com/problems/replace-words) (Medium)
- [Implement Magic Dictionary](https://leetcode.com/problems/implement-magic-dictionary) (Medium)
- [Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings) (Hard)
- [Implement Trie II (Prefix Tree)](https://leetcode.com/problems/implement-trie-ii-prefix-tree) (Medium)

# [211] Design Add and Search Words Data Structure

**[string, depth-first-search, design, trie]**

### Statement

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

* `WordDictionary()`Initializes the object.
* `void addWord(word)` Adds `word` to the data structure, it can be matched later.
* `bool search(word)`Returns `true` if there is any string in the data structure that matches `word`or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.


**Example:**

```

**Input**
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
**Output**
[null,null,null,null,false,true,true,true]

**Explanation**
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

```

**Constraints:**
* `1 <= word.length <= 25`
* `word` in `addWord` consists of lowercase English letters.
* `word` in `search` consist of `'.'` or lowercase English letters.
* There will be at most `3` dots in `word` for `search` queries.
* At most `10^4` calls will be made to `addWord` and `search`.


<br />

### Hints

- You should be familiar with how a Trie works. If not, please work on this problem: <a href="https://leetcode.com/problems/implement-trie-prefix-tree/">Implement Trie (Prefix Tree)</a> first.

<br />

### Solution

```cpp
class WordDictionary {
    std::vector <WordDictionary*> children;
    bool is_word;

  public:
    WordDictionary () {
      children.resize(26);
      is_word = false;
    }
    
    void addWord (string word) {
      WordDictionary *node = this;
      for (char c: word) {
        c -= 'a';
        if (node->children[c] == nullptr)
          node->children[c] = new WordDictionary();
        node = node->children[c];
      }
      node->is_word = true;
    }
    
    bool search (string word) {
      return search(this, word, 0);
    }

    bool search (WordDictionary *node, const std::string &s, int index) {
      for (int i = index; i < (int)s.size(); ++i) {
        if (s[i] != '.') {
          if (node->children[s[i] - 'a'] == nullptr)
            return false;
          node = node->children[s[i] - 'a'];
        }
        else {
          bool exist = false;
          for (int j = 0; j < 26 and not exist; ++j) {
            if (node->children[j] != nullptr)
              exist |= search(node->children[j], s, i + 1);
          }
          return exist;
        }
      }
      return node->is_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

<br />

### Statistics

- total accepted: 496203
- total submissions: 1139641
- acceptance rate: 43.5%
- likes: 6438
- dislikes: 366

<br />

### Similar Problems

- [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree) (Medium)
- [Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search) (Hard)
- [Match Substring After Replacement](https://leetcode.com/problems/match-substring-after-replacement) (Hard)
- [Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings) (Hard)

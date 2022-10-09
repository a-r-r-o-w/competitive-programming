# [1268] Search Suggestions System

**[array, string, trie]**

### Statement

You are given an array of strings `products` and a string `searchWord`.

Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with `searchWord`. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return *a list of lists of the suggested products after each character of* `searchWord` *is typed*.


**Example 1:**

```

**Input:** products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
**Output:** [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
**Explanation:** products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

```

**Example 2:**

```

**Input:** products = ["havana"], searchWord = "havana"
**Output:** [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

```

**Example 3:**

```

**Input:** products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
**Output:** [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

```

**Constraints:**
* `1 <= products.length <= 1000`
* `1 <= products[i].length <= 3000`
* `1 <= sum(products[i].length) <= 2 * 104`
* All the strings of `products` are **unique**.
* `products[i]` consists of lowercase English letters.
* `1 <= searchWord.length <= 1000`
* `searchWord` consists of lowercase English letters.


<br>

### Hints

- Brute force is a good choice because length of the string is ≤ 1000.
- Binary search the answer.
- Use Trie data structure to store the best three matching. Traverse the Trie.

<br>

### Solution

```cpp
class Solution {
  public:
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
        for (char c: s) {
          if (node->children[c - 'a'] == nullptr)
            node->children[c - 'a'] = new trie();
          node = node->children[c - 'a'];
        }
        node->end = true;
      }
      
      void find_and_build (const std::string& s, int index, std::vector <std::string>& choices, std::string& word_so_far) {
        // std::cout << s << ' ' << index << ' ' << word_so_far << '\n';
        if (index < (int)s.length()) {
          if (children[s[index] - 'a'] == nullptr)
            return;
          if ((int)choices.size() < 3) {
            word_so_far.push_back(s[index]);
            children[s[index] - 'a']->find_and_build(s, index + 1, choices, word_so_far);
          }
        }
        else {
          if ((int)choices.size() >= 3)
            return;
          
          if (end)
            choices.push_back(word_so_far);
          
          for (int i = 0; i < 26; ++i) {
            if (children[i] == nullptr)
              continue;
            word_so_far.push_back(i + 'a');
            children[i]->find_and_build(s, index + 1, choices, word_so_far);
            word_so_far.pop_back();
          }
        }
      }
    };
  
    vector <vector <string>> suggestedProducts (vector <string>& products, string searchWord) {
      trie t;
      for (std::string& word: products)
        t.insert(word);
      
      std::vector <std::vector <std::string>> words;
      std::string s;
      int n = searchWord.length();
      s.reserve(n);
      
      for (int i = 0; i < n; ++i) {
        s += searchWord[i];
        std::vector <std::string> choices;
        std::string temp;
        t.find_and_build(s, 0, choices, temp);
        words.push_back(choices);
      }
      
      return words;
    }
};
```

<br>

### Statistics

- total accepted: 187463
- total submissions: 282285
- acceptance rate: 66.4%
- likes: 3070
- dislikes: 156

<br>

### Similar Problems

None

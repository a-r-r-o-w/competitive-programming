# [2490] Circular Sentence



### Statement

A **sentence** is a list of words that are separated by a **single** space with no leading or trailing spaces.

* For example, `"Hello World"`, `"HELLO"`, `"hello world hello world"` are all sentences.



Words consist of **only** uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is **circular** if:

* The last character of a word is equal to the first character of the next word.
* The last character of the last word is equal to the first character of the first word.



For example, `"leetcode exercises sound delightful"`, `"eetcode"`, `"leetcode eats soul"` are all circular sentences. However, `"Leetcode is cool"`, `"happy Leetcode"`, `"Leetcode"` and `"I like Leetcode"` are **not** circular sentences.

Given a string `sentence`, return `true` *if it is circular*. Otherwise, return `false`.


**Example 1:**

```

**Input:** sentence = "leetcode exercises sound delightful"
**Output:** true
**Explanation:** The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode'slast character is equal to exercises's first character.
- exercises'slast character is equal to sound's first character.
- sound'slast character is equal to delightful's first character.
- delightful'slast character is equal to leetcode's first character.
The sentence is circular.
```

**Example 2:**

```

**Input:** sentence = "eetcode"
**Output:** true
**Explanation:** The words in sentence are ["eetcode"].
- eetcode'slast character is equal to eetcode's first character.
The sentence is circular.
```

**Example 3:**

```

**Input:** sentence = "Leetcode is cool"
**Output:** false
**Explanation:** The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode'slast character is **not** equal to is's first character.
The sentence is **not** circular.
```

**Constraints:**
* `1 <= sentence.length <= 500`
* `sentence` consist of only lowercase and uppercase English letters and spaces.
* The words in `sentence` are separated by a single space.
* There are no leading or trailing spaces.


<br>

### Hints

- Check the character before the empty space and the character after the empty space.
- Check the first character and the last character of the sentence.

<br>

### Solution

```cpp
class Solution {
  public:
    bool isCircularSentence (string sentence) {
      std::vector <std::string> words;
      std::string word;
      
      sentence += ' ';
      int n = sentence.length();
      
      for (int i = 0; i < n; ++i) {
        if (sentence[i] != ' ')
          word += sentence[i];
        else
          words.emplace_back(std::move(word));
      }
      
      int k = words.size();
      
      for (int i = 0; i < k; ++i) {
        if (words[i].back() != words[(i + 1) % k].front())
          return false;
      }
      
      return true;
    }
};
```

<br>

### Statistics

- total accepted: 14113
- total submissions: 22284
- acceptance rate: 63.3%
- likes: 82
- dislikes: 0

<br>

### Similar Problems

- [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb) (Easy)

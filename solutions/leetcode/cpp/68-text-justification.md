# [68] Text Justification

**[array, string, simulation]**

### Statement

Given an array of strings `words` and a width `maxWidth`, format the text such that each line has exactly `maxWidth` characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly `maxWidth` characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

**Note:**
* A word is defined as a character sequence consisting of non-space characters only.
* Each word's length is guaranteed to be greater than `0` and not exceed `maxWidth`.
* The input array `words` contains at least one word.


**Example 1:**

```

**Input:** words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
**Output:**
[
 "This  is  an",
 "example of text",
 "justification. "
]
```

**Example 2:**

```

**Input:** words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
**Output:**
[
 "What  must  be",
 "acknowledgment ",
 "shall be    "
]
**Explanation:** Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
```

**Example 3:**

```

**Input:** words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
**Output:**
[
 "Science is what we",
  "understand   well",
 "enough to explain to",
 "a computer. Art is",
 "everything else we",
 "do         "
]
```

**Constraints:**
* `1 <= words.length <= 300`
* `1 <= words[i].length <= 20`
* `words[i]` consists of only English letters and symbols.
* `1 <= maxWidth <= 100`
* `words[i].length <= maxWidth`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <string> fullJustify(vector <string>& words, int maxWidth) {
      int n = words.size(), length = 0;
      std::vector <std::vector <std::string>> lines;
      std::vector <std::string> line;

      for (int i = 0; i < n; ++i) {
        int new_length = line.size() + length + words[i].length();
        if (new_length <= maxWidth) {
          line.push_back(words[i]);
          length += words[i].length();
        }
        else {
          lines.emplace_back(std::move(line));
          line.push_back(words[i]);
          length = words[i].length();
        }
      }
      lines.emplace_back(std::move(line));

      std::vector <std::string> ans;

      for (int i = 0; i < (int)lines.size() - 1; ++i) {
        int num_words = lines[i].size();
        int spaces = maxWidth;

        for (auto &word: lines[i])
          spaces -= word.length();
        
        int pairs = std::max(num_words - 1, 1);
        int spaces_per_pair = spaces / pairs;
        int extra_spaces = spaces % pairs;
        std::string x;

        for (auto &word: lines[i]) {
          int add_spaces = spaces_per_pair + (extra_spaces > 0);
          x += word;
          if (pairs > 0) {
            x += std::string(add_spaces, ' ');
            --extra_spaces;
            --pairs;
          }
        }

        ans.emplace_back(std::move(x));
      }

      std::string x;
      for (auto &word: lines.back())
        x += word + ' ';
      x.pop_back();
      x += std::string(maxWidth - x.length(), ' ');
      ans.emplace_back(std::move(x));

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 312952
- total submissions: 808049
- acceptance rate: 38.7%
- likes: 2585
- dislikes: 3711

<br />

### Similar Problems

- [Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words) (Easy)
- [Divide a String Into Groups of Size k](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k) (Easy)
- [Split Message Based on Limit](https://leetcode.com/problems/split-message-based-on-limit) (Hard)

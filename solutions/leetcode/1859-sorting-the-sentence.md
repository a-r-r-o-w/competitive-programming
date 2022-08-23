# [1859] Sorting the Sentence

**[string, sorting]**

### Statement

A **sentence** is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be **shuffled** by appending the **1-indexed word position** to each word then rearranging the words in the sentence.

* For example, the sentence `"This is a sentence"` can be shuffled as `"sentence4 a3 is2 This1"` or `"is2 sentence4 This1 a3"`.



Given a **shuffled sentence** `s` containing no more than `9` words, reconstruct and return *the original sentence*.


**Example 1:**

```

**Input:** s = "is2 sentence4 This1 a3"
**Output:** "This is a sentence"
**Explanation:** Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

```

**Example 2:**

```

**Input:** s = "Myself2 Me1 I4 and3"
**Output:** "Me Myself and I"
**Explanation:** Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

```

**Constraints:**
* `2 <= s.length <= 200`
* `s` consists of lowercase and uppercase English letters, spaces, and digits from `1` to `9`.
* The number of words in `s` is between `1` and `9`.
* The words in `s` are separated by a single space.
* `s` contains no leading or trailing spaces.


<br>

### Hints

- Divide the string into the words as an array of strings
- Sort the words by removing the last character from each word and sorting according to it

<br>

### Solution

```cpp
class Solution {
  public:
    string sortSentence (string s) {
      s += ' ';
      
      int n = s.length();
      std::map <int, std::string> seq;
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        std::string x;
        
        while (j + 1 < n and s[j + 1] != ' ') {
          x += s[j];
          ++j;
        }
        
        seq[s[j]] = x;
        i = j + 1;
      }
      
      std::string result;
      
      for (auto &[x, y]: seq) {
        result += y;
        result += ' ';
      }
      
      result.pop_back();
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 76368
- total submissions: 90536
- acceptance rate: 84.4%
- likes: 1156
- dislikes: 34

<br>

### Similar Problems

- [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) (Easy)

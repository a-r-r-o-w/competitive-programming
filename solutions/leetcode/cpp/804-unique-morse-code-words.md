# [804] Unique Morse Code Words

**[array, hash-table, string]**

### Statement

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

* `'a'` maps to `".-"`,
* `'b'` maps to `"-..."`,
* `'c'` maps to `"-.-."`, and so on.



For convenience, the full table for the `26` letters of the English alphabet is given below:


```

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```


Given an array of strings `words` where each word can be written as a concatenation of the Morse code of each letter.

* For example, `"cab"` can be written as `"-.-..--..."`, which is the concatenation of `"-.-."`, `".-"`, and `"-..."`. We will call such a concatenation the **transformation** of a word.



Return *the number of different **transformations** among all words we have*.


**Example 1:**

```

**Input:** words = ["gin","zen","gig","msg"]
**Output:** 2
**Explanation:** The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

```

**Example 2:**

```

**Input:** words = ["a"]
**Output:** 1

```

**Constraints:**
* `1 <= words.length <= 100`
* `1 <= words[i].length <= 12`
* `words[i]` consists of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    std::vector <std::string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    int uniqueMorseRepresentations (vector <string>& words) {
      std::transform(words.begin(), words.end(), words.begin(), [&] (auto &word) {
        std::string repr;
        for (char c: word)
          repr += alphabet[c - 'a'];
        return repr;
      });
      
      return std::unordered_set <std::string> (words.begin(), words.end()).size();
    }
};
```

<br>

### Statistics

- total accepted: 226925
- total submissions: 282763
- acceptance rate: 80.3%
- likes: 1313
- dislikes: 1088

<br>

### Similar Problems

None

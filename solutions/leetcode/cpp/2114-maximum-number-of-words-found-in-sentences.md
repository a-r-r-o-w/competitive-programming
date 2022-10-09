# [2114] Maximum Number of Words Found in Sentences

**[array, string]**

### Statement

A **sentence** is a list of **words** that are separated by a single spacewith no leading or trailing spaces.

You are given an array of strings `sentences`, where each `sentences[i]` represents a single **sentence**.

Return *the **maximum number of words** that appear in a single sentence*.


**Example 1:**

```

**Input:** sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
**Output:** 6
**Explanation:** 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.

```

**Example 2:**

```

**Input:** sentences = ["please wait", "continue to fight", "continue to win"]
**Output:** 3
**Explanation:** It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.

```

**Constraints:**
* `1 <= sentences.length <= 100`
* `1 <= sentences[i].length <= 100`
* `sentences[i]` consists only of lowercase English letters and `' '` only.
* `sentences[i]` does not have leading or trailing spaces.
* All the words in `sentences[i]` are separated by a single space.


<br>

### Hints

- Process each sentence separately and count the number of words by looking for the number of space characters in the sentence and adding it by 1.

<br>

### Solution

```cpp
class Solution {
  public:
    int mostWordsFound (vector <string>& sentences) {
      int max = 0;
      
      for (int i = 0; i < (int)sentences.size(); ++i) {
        int count = 0;
        
        for (char c: sentences[i])
          if (c == ' ')
            ++count;
        
        max = std::max(max, count);
      }
      
      return max + 1;
    }
};
```

<br>

### Statistics

- total accepted: 96934
- total submissions: 109564
- acceptance rate: 88.5%
- likes: 725
- dislikes: 23

<br>

### Similar Problems

- [Number of Valid Words in a Sentence](https://leetcode.com/problems/number-of-valid-words-in-a-sentence) (Easy)

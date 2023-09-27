# [1255] Maximum Score Words Formed by Letters

**[array, string, dynamic-programming, backtracking, bit-manipulation, bitmask]**

### Statement

Given a list of `words`, list of single`letters` (might be repeating)and `score`of every character.

Return the maximum score of **any** valid set of words formed by using the given letters (`words[i]` cannot be used twoor more times).

It is not necessary to use all characters in `letters` and each letter can only be used once. Score of letters`'a'`, `'b'`, `'c'`, ... ,`'z'` is given by`score[0]`, `score[1]`, ... , `score[25]` respectively.


**Example 1:**

```

**Input:** words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
**Output:** 23
**Explanation:**
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
```

**Example 2:**

```

**Input:** words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
**Output:** 27
**Explanation:**
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
```

**Example 3:**

```

**Input:** words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
**Output:** 0
**Explanation:**
Letter "e" can only be used once.
```

**Constraints:**
* `1 <= words.length <= 14`
* `1 <= words[i].length <= 15`
* `1 <= letters.length <= 100`
* `letters[i].length == 1`
* `score.length ==26`
* `0 <= score[i] <= 10`
* `words[i]`, `letters[i]`contains only lower case English letters.


<br />

### Hints

- Note that words.length is small. This means you can iterate over every subset of words (2^N).

<br />

### Solution

```cpp
class Solution {
  public:
    int maxScoreWords (vector <string>& words, vector <char>& letters, vector <int>& score) {
      int n = words.size(), ans = 0;
      std::vector <int> freq_letters (26), have (26);
      std::vector freq (n, std::vector(26, 0));

      for (char c: letters)
        ++freq_letters[c - 'a'];
      for (int i = 0; i < n; ++i) {
        for (char c: words[i])
          ++freq[i][c - 'a'];
      }

      for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (!(i & (1 << j)))
            continue;
          for (int k = 0; k < 26; ++k)
            have[k] += freq[j][k];
        }
        
        bool good = true;
        
        for (int k = 0; k < 26; ++k) {
          if (have[k] > freq_letters[k]) {
            good = false;
            break;
          }
        }

        if (good) {
          int sum = 0;
          for (int k = 0; k < 26; ++k)
            sum += score[k] * have[k];
          ans = std::max(ans, sum);
        }

        for (int k = 0; k < 26; ++k)
          have[k] = 0;
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 31375
- total submissions: 43365
- acceptance rate: 72.4%
- likes: 1074
- dislikes: 52

<br />

### Similar Problems

- [Maximum Good People Based on Statements](https://leetcode.com/problems/maximum-good-people-based-on-statements) (Hard)

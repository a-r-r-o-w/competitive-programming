# [187] Repeated DNA Sequences

**[hash-table, string, bit-manipulation, sliding-window, rolling-hash, hash-function]**

### Statement

The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.

* For example, `"ACGAATTCCG"` is a **DNA sequence**.



When studying **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a **DNA sequence**, return all the **`10`-letter-long** sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in **any order**.


**Example 1:**

```
**Input:** s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
**Output:** ["AAAAACCCCC","CCCCCAAAAA"]

```
**Example 2:**

```
**Input:** s = "AAAAAAAAAAAAA"
**Output:** ["AAAAAAAAAA"]

```

**Constraints:**
* `1 <= s.length <= 105`
* `s[i]` is either `'A'`, `'C'`, `'G'`, or `'T'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> findRepeatedDnaSequences (string s) {
      int n = s.length();
      std::vector <std::string> ans;
      std::unordered_map <std::string, int> have;
      std::string sub;

      if (n < 10)
        return {};
      
      for (int i = 0; i < n; ++i) {
        if (i + 9 >= n)
          break;
        have[s.substr(i, 10)] += 1;
      }

      for (auto &[x, y]: have) {
        if (y >= 2)
          ans.push_back(x);
      }

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 309361
- total submissions: 663996
- acceptance rate: 46.6%
- likes: 2649
- dislikes: 463

<br>

### Similar Problems

None

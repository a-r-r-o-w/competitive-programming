# [2325] Decode the Message

**[hash-table, string]**

### Statement

You are given the strings `key` and `message`, which represent a cipher key and a secret message, respectively. The steps to decode `message` are as follows:

1. Use the **first** appearance of all 26 lowercase English letters in `key` as the **order** of the substitution table.
2. Align the substitution table with the regular English alphabet.
3. Each letter in `message` is then **substituted** using the table.
4. Spaces `' '` are transformed to themselves.


* For example, given `key = "**hap**p**y** **bo**y"` (actual key would have **at least one** instance of each letter in the alphabet), we have the partial substitution table of (`'h' -> 'a'`, `'a' -> 'b'`, `'p' -> 'c'`, `'y' -> 'd'`, `'b' -> 'e'`, `'o' -> 'f'`).



Return *the decoded message*.


**Example 1:**
![](https://assets.leetcode.com/uploads/2022/05/08/ex1new4.jpg)

```

**Input:** key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
**Output:** "this is a secret"
**Explanation:** The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "**the** **quick** **brown** **f**o**x** **j**u**mps** o**v**er the **lazy** **d**o**g**".

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/05/08/ex2new.jpg)

```

**Input:** key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
**Output:** "the five boxing wizards jump quickly"
**Explanation:** The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "**eljuxhpwnyrdgtqkviszcfmabo**".

```

**Constraints:**
* `26 <= key.length <= 2000`
* `key` consists of lowercase English letters and `' '`.
* `key` contains every letter in the English alphabet (`'a'` to `'z'`) **at least once**.
* `1 <= message.length <= 2000`
* `message` consists of lowercase English letters and `' '`.


<br>

### Hints

- Iterate through the characters in the key to construct a mapping to the English alphabet.
- Make sure to check that the current character is not already in the mapping (only the first appearance is considered).
- Map the characters in the message according to the constructed mapping.

<br>

### Solution

```cpp
class Solution {
  public:
    string decodeMessage (string key, string message) {
      std::vector <bool> have (26);
      std::map <char, int> actual_key;
      int index = 0;
      
      for (char &c: key) {
        if (c == ' ')
          continue;
        if (have[c - 'a'])
          continue;
        have[c - 'a'] = true;
        actual_key[c - 'a'] = index++;
      }
      
      for (char &c: message) {
        if (c == ' ')
          continue;
        c = actual_key[c - 'a'] + 'a';
      }
      
      return message;
    }
};
```

<br>

### Statistics

- total accepted: 27427
- total submissions: 32570
- acceptance rate: 84.2%
- likes: 234
- dislikes: 33

<br>

### Similar Problems

None

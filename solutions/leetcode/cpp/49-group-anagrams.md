# [49] Group Anagrams

**[array, hash-table, string, sorting]**

### Statement

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


**Example 1:**

```
**Input:** strs = ["eat","tea","tan","ate","nat","bat"]
**Output:** [["bat"],["nat","tan"],["ate","eat","tea"]]

```
**Example 2:**

```
**Input:** strs = [""]
**Output:** [[""]]

```
**Example 3:**

```
**Input:** strs = ["a"]
**Output:** [["a"]]

```

**Constraints:**
* `1 <= strs.length <= 104`
* `0 <= strs[i].length <= 100`
* `strs[i]` consists of lowercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <string>> groupAnagrams (vector <string>& strs) {
      std::map <std::vector <int>, std::vector <std::string>> have;
      std::vector <int> freq (26);
      
      for (auto &word: strs) {
        for (auto &c: word)
          ++freq[c - 'a'];
        have[freq].push_back(word);
        freq.assign(26, 0);
      }
      
      std::vector <std::vector <std::string>> ans;
      
      for (auto &[x, y]: have)
        ans.emplace_back(std::move(y));
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 1666056
- total submissions: 2522423
- acceptance rate: 66.0%
- likes: 12401
- dislikes: 380

<br>

### Similar Problems

- [Valid Anagram](https://leetcode.com/problems/valid-anagram) (Easy)
- [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings) (Medium)
- [Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams) (Easy)

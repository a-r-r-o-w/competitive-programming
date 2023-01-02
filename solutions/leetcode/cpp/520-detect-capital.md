# [520] Detect Capital

**[string]**

### Statement

We define the usage of capitals in a word to be right when one of the following cases holds:

* All letters in this word are capitals, like `"USA"`.
* All letters in this word are not capitals, like `"leetcode"`.
* Only the first letter in this word is capital, like `"Google"`.



Given a string `word`, return `true` if the usage of capitals in it is right.


**Example 1:**

```
**Input:** word = "USA"
**Output:** true

```
**Example 2:**

```
**Input:** word = "FlaG"
**Output:** false

```

**Constraints:**
* `1 <= word.length <= 100`
* `word` consists of lowercase and uppercase English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool detectCapitalUse (string word) {
      bool is_upper = std::all_of(word.begin(), word.end(), [] (char c) {
        return std::isupper(c);
      });
      bool is_lower = std::all_of(word.begin(), word.end(), [] (char c) {
        return std::islower(c);
      });
      bool is_capitalized = std::all_of(word.begin() + 1, word.end(), [] (char c) {
        return std::islower(c);
      }) and std::isupper(word[0]);

      return is_upper or is_lower or is_capitalized;
    }
};
```

<br>

### Statistics

- total accepted: 309130
- total submissions: 549910
- acceptance rate: 56.2%
- likes: 2245
- dislikes: 403

<br>

### Similar Problems

- [Capitalize the Title](https://leetcode.com/problems/capitalize-the-title) (Easy)

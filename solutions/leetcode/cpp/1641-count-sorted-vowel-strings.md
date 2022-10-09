# [1641] Count Sorted Vowel Strings

**[dynamic-programming]**

### Statement

Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`*) and are **lexicographically sorted**.*

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.


**Example 1:**

```

**Input:** n = 1
**Output:** 5
**Explanation:** The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

```

**Example 2:**

```

**Input:** n = 2
**Output:** 15
**Explanation:** The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

```

**Example 3:**

```

**Input:** n = 33
**Output:** 66045

```

**Constraints:**
* `1 <= n <= 50`


<br>

### Hints

- For each character, its possible values will depend on the value of its previous character, because it needs to be not smaller than it.
- Think backtracking. Build a recursive function count(n, last_character) that counts the number of valid strings of length n and whose first characters are not less than last_character.
- In this recursive function, iterate on the possible characters for the first character, which will be all the vowels not less than last_character, and for each possible value c, increase the answer by count(n-1, c).

<br>

### Solution

**O(1) query, O(max) precomp**

```cpp
class Solution {
  public:
    const int max = 50;
    std::vector <int> dp;
  
    Solution ()
      : dp (std::vector <int> (max)) {
      int a[] = {1, 1, 1, 1, 1};
      for (int i = 0; i < max; ++i) {
        for (int j = 1; j < 5; ++j)
          a[j] += a[j - 1];
        dp[i] = a[5 - 1];
      }
    }
  
    int countVowelStrings (int n) {
      return dp[n - 1];
    }
};
```

**O(1)**

```cpp
class Solution {
  public:
    int countVowelStrings (int n) {
      return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
```

<br>

### Statistics

- total accepted: 138270
- total submissions: 178324
- acceptance rate: 77.5%
- likes: 2983
- dislikes: 64

<br>

### Similar Problems

None

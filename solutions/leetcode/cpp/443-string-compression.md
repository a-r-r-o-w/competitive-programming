# [443] String Compression

**[two-pointers, string]**

### Statement

Given an array of characters `chars`, compress it using the following algorithm:

Begin with an empty string `s`. For each group of **consecutive repeating characters** in `chars`:

* If the group's length is `1`, append the character to `s`.
* Otherwise, append the character followed by the group's length.



The compressed string `s` **should not be returned separately**, but instead, be stored **in the input character array `chars`**. Note that group lengths that are `10` or longer will be split into multiple characters in `chars`.

After you are done **modifying the input array,** return *the new length of the array*.

You must write an algorithm that uses only constant extra space.


**Example 1:**

```

**Input:** chars = ["a","a","b","b","c","c","c"]
**Output:** Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
**Explanation:** The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

```

**Example 2:**

```

**Input:** chars = ["a"]
**Output:** Return 1, and the first character of the input array should be: ["a"]
**Explanation:** The only group is "a", which remains uncompressed since it's a single character.

```

**Example 3:**

```

**Input:** chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
**Output:** Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
**Explanation:** The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
```

**Constraints:**
* `1 <= chars.length <= 2000`
* `chars[i]` is a lowercase English letter, uppercase English letter, digit, or symbol.


<br />

### Hints

- How do you know if you are at the end of a consecutive group of characters?

<br />

### Solution

```cpp
class Solution {
  public:
    int compress (vector <char>& chars) {
      int n = chars.size(), index = 0;
      
      for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and chars[i] == chars[j])
          ++j;
        chars[index] = chars[i];
        if (j - i == 1)
          ++index;
        else {
          int value = j - i, k = 1;
          while (value > 0) {
            chars[index + k] = value % 10 + '0';
            value /= 10;
            ++k;
          }
          std::reverse(chars.begin() + index + 1, chars.begin() + index + k);
          index += k;
        }
        i = j - 1;
      }

      return index;
    }
};
```

<br />

### Statistics

- total accepted: 317206
- total submissions: 634539
- acceptance rate: 50.0%
- likes: 3022
- dislikes: 5090

<br />

### Similar Problems

- [Count and Say](https://leetcode.com/problems/count-and-say) (Medium)
- [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings) (Medium)
- [Design Compressed String Iterator](https://leetcode.com/problems/design-compressed-string-iterator) (Easy)
- [Decompress Run-Length Encoded List](https://leetcode.com/problems/decompress-run-length-encoded-list) (Easy)

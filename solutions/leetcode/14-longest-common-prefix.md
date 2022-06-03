# [14] Longest Common Prefix

**[string]**

### Statement

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.


**Example 1:**

```

**Input:** strs = ["flower","flow","flight"]
**Output:** "fl"

```

**Example 2:**

```

**Input:** strs = ["dog","racecar","car"]
**Output:** ""
**Explanation:** There is no common prefix among the input strings.

```

**Constraints:**
* `1 <= strs.length <= 200`
* `0 <= strs[i].length <= 200`
* `strs[i]` consists of only lower-case English letters.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string longestCommonPrefix (vector <string>& v) {
      int n = v.size();
      int index = v[0].length();
      
      for (int i = 1; i < n; ++i) {
        int j = 0;
        while (j < (int)v[i].length() and j < (int)v[i - 1].length() and v[i][j] == v[i - 1][j])
          ++j;
        index = std::min(index, j);
      }
      
      if (index == 0)
        return "";
      
      return v[0].substr(0, index);
    }
};
```

<br>

### Statistics

- total accepted: 1614546
- total submissions: 4075392
- acceptance rate: 39.6%
- likes: 8219
- dislikes: 3045

<br>

### Similar Problems

None

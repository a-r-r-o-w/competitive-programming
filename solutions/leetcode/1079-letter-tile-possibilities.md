# [1079] Letter Tile Possibilities

**[string, backtracking]**

### Statement

You have `n``tiles`, where each tile has one letter `tiles[i]` printed on it.

Return *the number of possible non-empty sequences of letters* you can make using the letters printed on those `tiles`.


**Example 1:**

```

**Input:** tiles = "AAB"
**Output:** 8
**Explanation:** The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

```

**Example 2:**

```

**Input:** tiles = "AAABBC"
**Output:** 188

```

**Example 3:**

```

**Input:** tiles = "V"
**Output:** 1

```

**Constraints:**
* `1 <= tiles.length <= 7`
* `tiles` consists of uppercase English letters.


<br>

### Hints

- Try to build the string with a backtracking DFS by considering what you can put in every position.

<br>

### Solution

```cpp
class Solution {
  public:
    int numTilePossibilities (string tiles) {
      int n = tiles.length();
      int ans = 0;
      std::vector <int> freq (26);
      
      for (char c: tiles)
        ++freq[c - 'A'];
      
      auto dfs = [&] (auto self) -> void {
        for (int i = 0; i < 26; ++i) {
          if (freq[i]) {
            --freq[i];
            ++ans;
            self(self);
            ++freq[i];
          }
        }
      };
      
      dfs(dfs);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 73763
- total submissions: 96872
- acceptance rate: 76.1%
- likes: 1838
- dislikes: 51

<br>

### Similar Problems

None

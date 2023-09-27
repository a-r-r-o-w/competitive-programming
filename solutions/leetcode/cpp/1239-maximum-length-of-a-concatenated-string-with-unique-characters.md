# [1239] Maximum Length of a Concatenated String with Unique Characters

**[array, string, backtracking, bit-manipulation]**

### Statement

You are given an array of strings `arr`. A string `s` is formed by the **concatenation** of a **subsequence** of `arr` that has **unique characters**.

Return *the **maximum** possible length* of `s`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


**Example 1:**

```

**Input:** arr = ["un","iq","ue"]
**Output:** 4
**Explanation:** All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

```

**Example 2:**

```

**Input:** arr = ["cha","r","act","ers"]
**Output:** 6
**Explanation:** Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

```

**Example 3:**

```

**Input:** arr = ["abcdefghijklmnopqrstuvwxyz"]
**Output:** 26
**Explanation:** The only string in arr has all 26 characters.

```

**Constraints:**
* `1 <= arr.length <= 16`
* `1 <= arr[i].length <= 26`
* `arr[i]` contains only lowercase English letters.


<br>

### Hints

- You can try all combinations and keep mask of characters you have.
- You can use DP.

<br>

### Solution

```cpp
class Solution {
  public:
    int maxLength (vector <string>& arr) {
      int n = arr.size();
      std::vector <int> mask (n);
      
      for (int i = 0; i < n; ++i) {
        for (char c: arr[i])
          mask[i] |= 1 << (c - 'a');
      }
      
      int max = 0;
      
      for (int i = 0; i < 1 << n; ++i) {
        bool okay = true;
        int current_mask = 0;
        
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j)) {
            for (char c: arr[j]) {
              int mask = 1 << (c - 'a');
              
              if (current_mask & mask) {
                okay = false;
                goto end;
              }
              
              current_mask |= mask;
            }
            end:;
          }
        }
        
        if (okay)
          max = std::max(max, __builtin_popcount(current_mask));
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 118763
- total submissions: 234466
- acceptance rate: 50.7%
- likes: 2104
- dislikes: 165

<br>

### Similar Problems

None

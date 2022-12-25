# [2516] Take K of Each Character From Left and Right



### Statement

You are given a string `s` consisting of the characters `'a'`, `'b'`, and `'c'` and a non-negative integer `k`. Each minute, you may take either the **leftmost** character of `s`, or the **rightmost** character of `s`.

Return *the **minimum** number of minutes needed for you to take **at least*** `k` *of each character, or return* `-1` *if it is not possible to take* `k` *of each character.*
**Example 1:**

```

**Input:** s = "aabaaaacaabc", k = 2
**Output:** 8
**Explanation:** 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

```

**Example 2:**

```

**Input:** s = "a", k = 1
**Output:** -1
**Explanation:** It is not possible to take one 'b' or 'c' so return -1.

```

**Constraints:**
* `1 <= s.length <= 105`
* `s` consists of only the letters `'a'`, `'b'`, and `'c'`.
* `0 <= k <= s.length`


<br>

### Hints

- Start by counting the frequency of each character and checking if it is possible.
- If you take x characters from the left side, what is the minimum number of characters you need to take from the right side? Find this for all values of x in the range 0 ≤ x ≤ s.length.
- Use a two-pointers approach to avoid computing the same information multiple times.
- Start by counting the frequency of each character and checking if it is possible.
- If you take x characters from the left side, what is the minimum number of characters you need to take from the right side? Find this for all values of x in the range 0 ≤ x ≤ s.length.
- Use a two-pointers approach to avoid computing the same information multiple times.

<br>

### Solution

```cpp
class Solution {
  public:
    int takeCharacters (string s, int k) {
      struct node {
        int a = 0;
        int b = 0;
        int c = 0;
      };
      
      int n = s.length(), ans = 1 << 30;
      std::vector <node> pref, suff;
      
      pref.reserve(n + 1);
      suff.reserve(n + 1);
      pref.emplace_back(node{});
      suff.emplace_back(node{});
      
      for (int i = 0; i < n; ++i) {
        node p = pref.back();
        
        if (s[i] == 'a')
          ++p.a;
        else if (s[i] == 'b')
          ++p.b;
        else
          ++p.c;
        
        pref.push_back(p);
      }
      
      for (int i = n - 1; i >= 0; --i) {
        node p = suff.back();
        
        if (s[i] == 'a')
          ++p.a;
        else if (s[i] == 'b')
          ++p.b;
        else
          ++p.c;
        
        suff.push_back(p);
      }
      
      if (!(pref.back().a >= k and pref.back().b >= k and pref.back().c >= k))
        return -1;
      
      for (int i = 0; i <= n; ++i) {
        node p = pref[i];
        int low = i + 1, high = n + 1;
        
        while (low < high) {
          int mid = (low + high) / 2;
          int idx = n - mid;
          node q = suff[idx];
          
          if (p.a + q.a >= k and p.b + q.b >= k and p.c + q.c >= k)
            low = mid + 1;
          else
            high = mid;
        }
        
        int time = i + n - low + 1;
        ans = std::min(ans, time);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 3576
- total submissions: 14252
- acceptance rate: 25.1%
- likes: 134
- dislikes: 29

<br>

### Similar Problems

- [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) (Easy)
- [Reorder List](https://leetcode.com/problems/reorder-list) (Medium)
- [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb) (Easy)

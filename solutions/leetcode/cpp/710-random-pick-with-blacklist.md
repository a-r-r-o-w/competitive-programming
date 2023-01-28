# [710] Random Pick with Blacklist

**[array, hash-table, math, binary-search, sorting, randomized]**

### Statement

You are given an integer `n` and an array of **unique** integers `blacklist`. Design an algorithm to pick a random integer in the range `[0, n - 1]` that is **not** in `blacklist`. Any integer that is in the mentioned range and not in `blacklist` should be **equally likely** to be returned.

Optimize your algorithm such that it minimizes the number of calls to the **built-in** random function of your language.

Implement the `Solution` class:

* `Solution(int n, int[] blacklist)` Initializes the object with the integer `n` and the blacklisted integers `blacklist`.
* `int pick()` Returns a random integer in the range `[0, n - 1]` and not in `blacklist`.


**Example 1:**

```

**Input**
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
**Output**
[null, 0, 4, 1, 6, 1, 0, 4]

**Explanation**
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4

```

**Constraints:**
* `1 <= n <= 109`
* `0 <= blacklist.length <= min(105, n - 1)`
* `0 <= blacklist[i] < n`
* All the values of `blacklist` are **unique**.
* At most `2 * 104` calls will be made to `pick`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
    int length;
    std::unordered_set <int> removed;
    std::map <int, int> map;
    std::mt19937 rng { std::random_device {}() };
    std::uniform_int_distribution <> dist;
  
  public:
    Solution (int n, vector <int>& blacklist) {
      length = n - blacklist.size();
      
      for (int i: blacklist)
        removed.insert(i);
      
      std::sort(blacklist.begin(), blacklist.end());
      int j = 0;

      for (int i = length; i < n; ++i) {
        if (removed.count(i))
          continue;
        map[blacklist[j]] = i;
        ++j;
      }
    }
    
    int pick () {
      int index = std::uniform_int_distribution <> (0, length - 1) (rng);
      if (map.count(index))
        return map[index];
      return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
```

<br>

### Statistics

- total accepted: 34908
- total submissions: 103740
- acceptance rate: 33.6%
- likes: 751
- dislikes: 101

<br>

### Similar Problems

- [Random Pick Index](https://leetcode.com/problems/random-pick-index) (Medium)
- [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight) (Medium)
- [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string) (Medium)

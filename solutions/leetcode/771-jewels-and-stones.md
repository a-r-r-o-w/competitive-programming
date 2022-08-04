# [771] Jewels and Stones

**[hash-table, string]**

### Statement

You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.


**Example 1:**

```
**Input:** jewels = "aA", stones = "aAAbbbb"
**Output:** 3

```
**Example 2:**

```
**Input:** jewels = "z", stones = "ZZ"
**Output:** 0

```

**Constraints:**
* `1 <=jewels.length, stones.length <= 50`
* `jewels` and `stones` consist of only English letters.
* All the characters of`jewels` are **unique**.


<br>

### Hints

- For each stone, check if it is a jewel.

<br>

### Solution

```cpp
class Solution {
  public:
    int numJewelsInStones (string jewels, string stones) {
      std::unordered_set <char> s (jewels.begin(), jewels.end());
      int ans = 0;
      
      for (char c: stones)
        ans += s.count(c);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 764813
- total submissions: 870572
- acceptance rate: 87.9%
- likes: 3746
- dislikes: 498

<br>

### Similar Problems

None

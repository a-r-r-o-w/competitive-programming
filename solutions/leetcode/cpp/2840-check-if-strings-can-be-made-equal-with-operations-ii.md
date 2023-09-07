# [2840] Check if Strings Can be Made Equal With Operations II

**[hash-table, string, sorting]**

### Statement

You are given two strings `s1` and `s2`, both of length `n`, consisting of **lowercase** English letters.

You can apply the following operation on **any** of the two strings **any** number of times:

* Choose any two indices `i` and `j` such that `i < j` and the difference `j - i` is **even**, then **swap** the two characters at those indices in the string.



Return `true` *if you can make the strings* `s1` *and* `s2` *equal, and*`false` *otherwise*.


**Example 1:**

```

**Input:** s1 = "abcdba", s2 = "cabdab"
**Output:** true
**Explanation:** We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

```

**Example 2:**

```

**Input:** s1 = "abe", s2 = "bea"
**Output:** false
**Explanation:** It is not possible to make the two strings equal.

```

**Constraints:**
* `n == s1.length == s2.length`
* `1 <= n <= 10^5`
* `s1` and `s2` consist only of lowercase English letters.


<br />

### Hints

- <div class="_1l1MA">Characters in two positions can be swapped if and only if the two positions have the same parity.</div>
- <div class="_1l1MA">To be able to make the two strings equal, the characters at even and odd positions in the strings should be the same.</div>

<br />

### Solution

```cpp
class Solution {
  public:
    bool checkStrings(string s1, string s2) {
      std::vector <char> odd_s1, even_s1;
      std::vector <char> odd_s2, even_s2;
      int n = s1.length();
      
      for (int i = 0; i < n; ++i)
        (i & 1 ? odd_s1 : even_s1).push_back(s1[i]);
      for (int i = 0; i < n; ++i)
        (i & 1 ? odd_s2 : even_s2).push_back(s2[i]);
      std::sort(odd_s1.begin(), odd_s1.end());
      std::sort(odd_s2.begin(), odd_s2.end());
      std::sort(even_s1.begin(), even_s1.end());
      std::sort(even_s2.begin(), even_s2.end());
      
      return odd_s1 == odd_s2 and even_s1 == even_s2;
    }
};
```

<br />

### Statistics

- total accepted: 20345
- total submissions: 38127
- acceptance rate: 53.4%
- likes: 170
- dislikes: 2

<br />

### Similar Problems

None

# [2746] Decremental String Concatenation



### Statement

You are given a **0-indexed** array `words` containing `n` strings.

Let's define a **join** operation `join(x, y)` between two strings `x` and `y` as concatenating them into `xy`. However, if the last character of `x` is equal to the first character of `y`, one of them is **deleted**.

For example `join("ab", "ba") = "aba"` and `join("ab", "cde") = "abcde"`.

You are to perform `n - 1` **join** operations. Let `str0 = words[0]`. Starting from `i = 1` up to `i = n - 1`, for the `i^th` operation, you can do one of the following:

* Make `stri = join(stri - 1, words[i])`
* Make `stri = join(words[i], stri - 1)`



Your task is to **minimize** the length of `strn - 1`.

Return *an integer denoting the minimum possible length of* `strn - 1`.


**Example 1:**

```

**Input:** words = ["aa","ab","bc"]
**Output:** 4
**Explanation:** In this example, we can perform join operations in the following order to minimize the length of str2: 
str0 = "aa"
str1 = join(str0, "ab") = "aab"
str2 = join(str1, "bc") = "aabc" 
It can be shown that the minimum possible length of str2 is 4.
```

**Example 2:**

```

**Input:** words = ["ab","b"]
**Output:** 2
**Explanation:** In this example, str0 = "ab", there are two ways to get str1: 
join(str0, "b") = "ab" or join("b", str0) = "bab". 
The first string, "ab", has the minimum length. Hence, the answer is 2.

```

**Example 3:**

```

**Input:** words = ["aaa","c","aba"]
**Output:** 6
**Explanation:** In this example, we can perform join operations in the following order to minimize the length of str2: 
str0 = "aaa"
str1 = join(str0, "c") = "aaac"
str2 = join("aba", str1) = "abaaac"
It can be shown that the minimum possible length of str2 is 6.

```


**Constraints:**
* `1 <= words.length <= 1000`
* `1 <= words[i].length <= 50`
* Each character in `words[i]` is an English lowercase letter


<br />

### Hints

- Use dynamic programming with memoization.
- Notice that the first and last characters of a string are sufficient to determine the length of its concatenation with any other string.
- Define dp[i][first][last] as the shortest concatenation length of the first i words starting with a character first and ending with a character last. Convert characters to their ASCII codes if your programming language cannot implicitly convert them to array indices.

<br />

### Solution

```cpp
class Solution {
  public:
    int minimizeConcatenatedLength (vector <string>& words) {
      const int inf32 = 1 << 30;
      int n = words.size();
      std::vector dp(n, std::vector(26, std::vector(26, -1)));
      
      auto dfs = [&] (auto self, int index, char front, char back) -> int {
        if (index >= n)
          return 0;
        if (dp[index][front - 'a'][back - 'a'] != -1)
          return dp[index][front - 'a'][back - 'a'];
        int ans = inf32;
        if (front == words[index].back())
          ans = std::min <int> (ans, self(self, index + 1, words[index].front(), back) + words[index].length() - 1);
        if (back == words[index].front())
          ans = std::min <int> (ans, self(self, index + 1, front, words[index].back()) + words[index].length() - 1);
        ans = std::min <int> (ans, self(self, index + 1, front, words[index].back()) + words[index].length());
        ans = std::min <int> (ans, self(self, index + 1, words[index].front(), back) + words[index].length());
        return dp[index][front - 'a'][back - 'a'] = ans;
      };
      
      return dfs(dfs, 1, words[0].front(), words[0].back()) + words[0].length();
    }
};
```

<br />

### Statistics

- total accepted: 1933
- total submissions: 11681
- acceptance rate: 16.5%
- likes: 154
- dislikes: 16

<br />

### Similar Problems

- [Largest Merge Of Two Strings](https://leetcode.com/problems/largest-merge-of-two-strings) (Medium)

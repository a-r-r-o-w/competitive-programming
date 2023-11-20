# [2384] Largest Palindromic Number

**[hash-table, string, greedy]**

### Statement

You are given a string `num` consisting of digits only.

Return *the **largest palindromic** integer (in the form of a string) that can be formed using digits taken from* `num`. It should not contain **leading zeroes**.

**Notes:**
* You do **not** need to use all the digits of `num`, but you must use **at least** one digit.
* The digits can be reordered.


**Example 1:**

```

**Input:** num = "444947137"
**Output:** "7449447"
**Explanation:** 
Use the digits "4449477" from "**44494****7**13**7**" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.

```

**Example 2:**

```

**Input:** num = "00009"
**Output:** "9"
**Explanation:** 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

```

**Constraints:**
* `1 <= num.length <= 10^5`
* `num` consists of digits.


<br />

### Hints

- In order to form a valid palindrome, other than the middle digit in an odd-length palindrome, every digit needs to exist on both sides.
- A longer palindrome implies a larger valued palindrome. For palindromes of the same length, the larger digits should occur first.
- We can count the occurrences of each digit and build the palindrome starting from the ends. Starting from the larger digits, if there are still at least 2 occurrences of a digit, we can place these digits on each side.
- Make sure to consider the special case for the center digit (if any) and zeroes. There should not be leading zeroes.

<br />

### Solution

```cpp
class Solution {
  public:
    string largestPalindromic (string num) {
      std::vector <int> freq (10);
      for (char c: num)
        ++freq[c - '0'];
      
      std::string ans;
      bool have = false;

      for (int i = 9; i > 0; --i) {
        if (freq[i] & 1)
          have = true;
        if (freq[i] < 2)
          continue;
        ans += std::string(freq[i] / 2, i + '0');
      }
      if (!ans.empty() and freq[0] >= 2) {
        ans += std::string(freq[0] / 2 * 2, '0');
        freq[0] %= 2;
      }
      for (int i = 1; i <= 9; ++i) {
        if (freq[i] < 2)
          continue;
        ans += std::string(freq[i] / 2, i + '0');
      }
      int choose = -1;
      for (int i = 9; i >= 0; --i) {
        if (freq[i] & 1) {
          choose = i;
          break;
        }
      }
      if (choose != -1)
        ans.insert(ans.begin() + ans.size() / 2, choose + '0');
      else if (ans.empty())
        ans = "0";
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 20305
- total submissions: 65103
- acceptance rate: 31.2%
- likes: 444
- dislikes: 182

<br />

### Similar Problems

- [Longest Palindrome](https://leetcode.com/problems/longest-palindrome) (Easy)

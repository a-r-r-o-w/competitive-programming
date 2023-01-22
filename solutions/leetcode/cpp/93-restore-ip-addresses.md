# [93] Restore IP Addresses

**[string, backtracking]**

### Statement

A **valid IP address** consists of exactly four integers separated by single dots. Each integer is between `0` and `255` (**inclusive**) and cannot have leading zeros.

* For example, `"0.1.2.201"` and `"192.168.1.1"` are **valid** IP addresses, but `"0.011.255.245"`, `"192.168.1.312"` and `"192.168@1.1"` are **invalid** IP addresses.



Given a string `s` containing only digits, return *all possible valid IP addresses that can be formed by inserting dots into* `s`. You are **not** allowed to reorder or remove any digits in `s`. You may return the valid IP addresses in **any** order.


**Example 1:**

```

**Input:** s = "25525511135"
**Output:** ["255.255.11.135","255.255.111.35"]

```

**Example 2:**

```

**Input:** s = "0000"
**Output:** ["0.0.0.0"]

```

**Example 3:**

```

**Input:** s = "101023"
**Output:** ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

```

**Constraints:**
* `1 <= s.length <= 20`
* `s` consists of digits only.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> restoreIpAddresses (string s) {
      int n = s.length();
      std::vector <std::string> ans;

      for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
          for (int k = 1; k <= 3; ++k) {
            int l = n - i - j - k;
            if (l <= 0 or l > 3)
              continue;
            
            int a = std::stoi(s.substr(0, i));
            int b = std::stoi(s.substr(i, j));
            int c = std::stoi(s.substr(i + j, k));
            int d = std::stoi(s.substr(i + j + k, l));
            if (a > 255 or b > 255 or c > 255 or d > 255)
              continue;
            
            auto result = std::to_string(a) + '.' + std::to_string(b) + '.' + std::to_string(c) + '.' + std::to_string(d);

            if (result.length() == s.length() + 3)
              ans.emplace_back(std::move(result));
          }
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 378303
- total submissions: 814325
- acceptance rate: 46.5%
- likes: 4370
- dislikes: 728

<br>

### Similar Problems

- [IP to CIDR](https://leetcode.com/problems/ip-to-cidr) (Medium)

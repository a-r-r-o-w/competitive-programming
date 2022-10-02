# [929] Unique Email Addresses

**[array, hash-table, string]**

### Statement

Every **valid email** consists of a **local name** and a **domain name**, separated by the `'@'` sign. Besides lowercase letters, the email may contain one or more `'.'` or `'+'`.

* For example, in `"alice@leetcode.com"`, `"alice"` is the **local name**, and `"leetcode.com"` is the **domain name**.



If you add periods `'.'` between some characters in the **local name** part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule **does not apply** to **domain names**.

* For example, `"alice.z@leetcode.com"` and `"alicez@leetcode.com"` forward to the same email address.



If you add a plus `'+'` in the **local name**, everything after the first plus sign **will be ignored**. This allows certain emails to be filtered. Note that this rule **does not apply** to **domain names**.

* For example, `"m.y+name@email.com"` will be forwarded to `"my@email.com"`.



It is possible to use both of these rules at the same time.

Given an array of strings `emails` where we send one email to each `emails[i]`, return *the number of different addresses that actually receive mails*.


**Example 1:**

```

**Input:** emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
**Output:** 2
**Explanation:** "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

```

**Example 2:**

```

**Input:** emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
**Output:** 3

```

**Constraints:**
* `1 <= emails.length <= 100`
* `1 <= emails[i].length <= 100`
* `emails[i]` consist of lowercase English letters, `'+'`, `'.'` and `'@'`.
* Each `emails[i]` contains exactly one `'@'` character.
* All local and domain names are non-empty.
* Local names do not start with a `'+'` character.
* Domain names end with the `".com"` suffix.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int numUniqueEmails (vector <string>& emails) {
      std::set <std::string> unique;
      
      for (auto &s: emails) {
        int i = 0, n = s.length();
        std::string local_name, domain_name;
        bool at_found = false;
        
        while (i < n) {
          if (s[i] == '+') {
            if (not at_found) {
              at_found = true;
              while (s[i] != '@')
                ++i;
            }
          }
          else if (s[i] == '@') {
            at_found = true;
          }
          else {
            if (at_found)
              domain_name += s[i];
            else if (s[i] != '.')
              local_name += s[i];
          }
          ++i;
        }
        
        unique.insert(local_name + '@' + domain_name);
      }
      
      for (auto s: unique)
        std::cout << s << '\n';
      
      return unique.size();
    }
};
```

<br>

### Statistics

- total accepted: 382187
- total submissions: 568971
- acceptance rate: 67.2%
- likes: 1937
- dislikes: 256

<br>

### Similar Problems

None

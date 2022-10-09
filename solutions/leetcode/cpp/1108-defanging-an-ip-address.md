# [1108] Defanging an IP Address

**[string]**

### Statement

Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A *defangedIP address*replaces every period `"."` with `"[.]"`.


**Example 1:**

```
**Input:** address = "1.1.1.1"
**Output:** "1[.]1[.]1[.]1"

```
**Example 2:**

```
**Input:** address = "255.100.50.0"
**Output:** "255[.]100[.]50[.]0"

```

**Constraints:**
* The given `address` is a valid IPv4 address.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    string defangIPaddr (string address) {
      std::string result;
      
      for (char c: address) {
        if (c == '.')
          result += "[.]";
        else
          result += c;
      }
      
      return result;
    }
};
```

<br>

### Statistics

- total accepted: 429682
- total submissions: 481609
- acceptance rate: 89.2%
- likes: 1220
- dislikes: 1532

<br>

### Similar Problems

None

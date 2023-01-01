# [2522] Partition String Into Substrings With Values at Most K



### Statement

You are given a string `s` consisting of digits from `1` to `9` and an integer `k`.

A partition of a string `s` is called **good** if:

* Each digit of `s` is part of **exactly** one substring.
* The value of each substring is less than or equal to `k`.



Return *the **minimum** number of substrings in a **good** partition of* `s`. If no **good** partition of `s` exists, return `-1`.

**Note** that:

* The **value** of a string is its result when interpreted as an integer. For example, the value of `"123"` is `123` and the value of `"1"` is `1`.
* A **substring** is a contiguous sequence of characters within a string.


**Example 1:**

```

**Input:** s = "165462", k = 60
**Output:** 4
**Explanation:** We can partition the string into substrings "16", "54", "6", and "2". Each substring has a value less than or equal to k = 60.
It can be shown that we cannot partition the string into less than 4 substrings.

```

**Example 2:**

```

**Input:** s = "238182", k = 5
**Output:** -1
**Explanation:** There is no good partition for this string.

```

**Constraints:**
* `1 <= s.length <= 105`
* `s[i]` is a digit from `'1'` to `'9'`.
* `1 <= k <= 109`


.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    int minimumPartition (string s, int k) {
      int partitions = 0;
      int64_t value = 0;
      
      for (char digit: s) {
        digit -= '0';
        value = value * 10 + digit;
        
        if (value > k) {
          ++partitions;
          value = digit;
          if (value > k)
            return -1;
        }
      }
      
      if (value != 0)
        ++partitions;
      
      return partitions;
    }
};
```

<br>

### Statistics

- total accepted: 7141
- total submissions: 16150
- acceptance rate: 44.2%
- likes: 92
- dislikes: 26

<br>

### Similar Problems

None

# [1773] Count Items Matching a Rule

**[array, string]**

### Statement

You are given an array `items`, where each `items[i] = [typei, colori, namei]` describes the type, color, and name of the `ith` item. You are also given a rule represented by two strings, `ruleKey` and `ruleValue`.

The `ith` item is said to match the rule if **one** of the following is true:

* `ruleKey == "type"` and `ruleValue == typei`.
* `ruleKey == "color"` and `ruleValue == colori`.
* `ruleKey == "name"` and `ruleValue == namei`.



Return *the number of items that match the given rule*.


**Example 1:**

```

**Input:** items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
**Output:** 1
**Explanation:** There is only one item matching the given rule, which is ["computer","silver","lenovo"].

```

**Example 2:**

```

**Input:** items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
**Output:** 2
**Explanation:** There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
```

**Constraints:**
* `1 <= items.length <= 104`
* `1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10`
* `ruleKey` is equal to either `"type"`, `"color"`, or `"name"`.
* All strings consist only of lowercase letters.


<br>

### Hints

- Iterate on each item, and check if each one matches the rule according to the statement.

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int countMatches (vector <vector <string>>& items, string ruleKey, string ruleValue) {
      int ans = 0;
      bool is_type = false, is_color = false, is_name = false;
      
      if (ruleKey == "type")
        is_type = true;
      else if (ruleKey == "color")
        is_color = true;
      else
        is_name = true;
      
      for (auto &v: items) {
        if ((is_type and v[0] == ruleValue) or
            (is_color and v[1] == ruleValue) or
            (is_name and v[2] == ruleValue))
          ++ans;
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 116744
- total submissions: 138411
- acceptance rate: 84.3%
- likes: 1036
- dislikes: 122

<br>

### Similar Problems

None

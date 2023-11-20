# [2109] Adding Spaces to a String

**[array, string, simulation]**

### Statement

You are given a **0-indexed** string `s` and a **0-indexed** integer array `spaces` that describes the indices in the original string where spaces will be added. Each space should be inserted **before** the character at the given index.

* For example, given `s = "EnjoyYourCoffee"` and `spaces = [5, 9]`, we place spaces before `'Y'` and `'C'`, which are at indices `5` and `9` respectively. Thus, we obtain `"Enjoy **Y**our **C**offee"`.



Return*the modified string **after** the spaces have been added.*
**Example 1:**

```

**Input:** s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
**Output:** "Leetcode Helps Me Learn"
**Explanation:** 
The indices 8, 13, and 15 correspond to the underlined characters in "Leetcode**H**elps**M**e**L**earn".
We then place spaces before those characters.

```

**Example 2:**

```

**Input:** s = "icodeinpython", spaces = [1,5,7,9]
**Output:** "i code in py thon"
**Explanation:**
The indices 1, 5, 7, and 9 correspond to the underlined characters in "i**c**ode**i**n**p**y**t**hon".
We then place spaces before those characters.

```

**Example 3:**

```

**Input:** s = "spacing", spaces = [0,1,2,3,4,5,6]
**Output:** " s p a c i n g"
**Explanation:**
We are also able to place spaces before the first character of the string.

```

**Constraints:**
* `1 <= s.length <= 3 * 10^5`
* `s` consists only of lowercase and uppercase English letters.
* `1 <= spaces.length <= 3 * 10^5`
* `0 <= spaces[i] <= s.length - 1`
* All the values of `spaces` are **strictly increasing**.


<br />

### Hints

- Create a new string, initially empty, as the modified string. Iterate through the original string and append each character of the original string to the new string. However, each time you reach a character that requires a space before it, append a space before appending the character.
- Since the array of indices for the space locations is sorted, use a pointer to keep track of the next index to place a space. Only increment the pointer once a space has been appended.
- Ensure that your append operation can be done in O(1).

<br />

### Solution

```cpp
class Solution {
  public:
    string addSpaces (string s, vector <int>& spaces) {
      int index = 0, n = s.length(), m = spaces.size();
      std::string result;

      for (int i = 0; i < n; ++i) {
        if (index < m and i == spaces[index]) {
          result += ' ';
          ++index;
        }
        result += s[i];
      }

      return result;
    }
};
```

<br />

### Statistics

- total accepted: 30011
- total submissions: 53137
- acceptance rate: 56.5%
- likes: 410
- dislikes: 46

<br />

### Similar Problems

None

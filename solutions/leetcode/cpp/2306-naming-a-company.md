# [2306] Naming a Company

**[array, hash-table, string, bit-manipulation, enumeration]**

### Statement

You are given an array of strings `ideas` that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

1. Choose 2 **distinct** names from `ideas`, call them `ideaA` and `ideaB`.
2. Swap the first letters of `ideaA` and `ideaB` with each other.
3. If **both** of the new names are not found in the original `ideas`, then the name `ideaA ideaB` (the **concatenation** of `ideaA` and `ideaB`, separated by a space) is a valid company name.
4. Otherwise, it is not a valid name.



Return *the number of **distinct** valid names for the company*.


**Example 1:**

```

**Input:** ideas = ["coffee","donuts","time","toffee"]
**Output:** 6
**Explanation:** The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.

```

**Example 2:**

```

**Input:** ideas = ["lack","back"]
**Output:** 0
**Explanation:** There are no valid selections. Therefore, 0 is returned.

```

**Constraints:**
* `2 <= ideas.length <= 5 * 10^4`
* `1 <= ideas[i].length <= 10`
* `ideas[i]` consists of lowercase English letters.
* All the strings in `ideas` are **unique**.


<br />

### Hints

- How can we divide the ideas into groups to make it easier to find valid pairs?
- Group ideas that share the same suffix (all characters except the first) together and notice that a pair of ideas from the same group is invalid. What about pairs of ideas from different groups?
- The first letter of the idea in the first group must not be the first letter of an idea in the second group and vice versa.
- We can efficiently count the valid pairings for an idea if we already know how many ideas starting with a letter x are within a group that does not contain any ideas with starting letter y for all letters x and y.

<br />

### Solution

```cpp
class Solution {
  public:
    long long distinctNames (vector <string>& ideas) {
      int n = ideas.size();
      int64_t ans = 0;
      std::array <std::unordered_set <size_t>, 26> have;
      std::hash <std::string> hash;

      for (auto &idea: ideas)
        have[idea[0] - 'a'].insert(hash(idea.substr(1)));
      
      for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
          int64_t count1 = 0, count2 = 0;
          for (auto x: have[i]) {
            if (not have[j].count(x))
              ++count1;
          }
          for (auto x: have[j]) {
            if (not have[i].count(x))
              ++count2;
          }
          ans += 2 * count1 * count2;
        }
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 23598
- total submissions: 56250
- acceptance rate: 42.0%
- likes: 1008
- dislikes: 49

<br />

### Similar Problems

None

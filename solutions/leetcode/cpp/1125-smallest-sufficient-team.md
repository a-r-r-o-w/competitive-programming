# [1125] Smallest Sufficient Team

**[array, dynamic-programming, bit-manipulation, bitmask]**

### Statement

In a project, you have a list of required skills `req_skills`, and a list of people. The `i^th` person `people[i]` contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in `req_skills`, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

* For example, `team = [0, 1, 3]` represents the people with skills `people[0]`, `people[1]`, and `people[3]`.



Return *any sufficient team of the smallest possible size, represented by the index of each person*. You may return the answer in **any order**.

It is **guaranteed** an answer exists.


**Example 1:**

```
**Input:** req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
**Output:** [0,2]

```
**Example 2:**

```
**Input:** req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
**Output:** [1,2]

```

**Constraints:**
* `1 <= req_skills.length <= 16`
* `1 <= req_skills[i].length <= 16`
* `req_skills[i]` consists of lowercase English letters.
* All the strings of `req_skills` are **unique**.
* `1 <= people.length <= 60`
* `0 <= people[i].length <= 16`
* `1 <= people[i][j].length <= 16`
* `people[i][j]` consists of lowercase English letters.
* All the strings of `people[i]` are **unique**.
* Every skill in `people[i]` is a skill in `req_skills`.
* It is guaranteed a sufficient team exists.


<br />

### Hints

- Do a bitmask DP.
- For each person, for each set of skills, we can update our understanding of a minimum set of people needed to perform this set of skills.

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> smallestSufficientTeam (vector <string>& req_skills, vector <vector <string>>& people) {
      int n = req_skills.size(), m = people.size();
      std::unordered_map <std::string, int> skills_map;
      int k = 0;

      for (auto &s: req_skills)
        skills_map[s] = k++;

      for (auto &p: people) {
        for (auto &s: p) {
          if (skills_map.count(s))
            continue;
          skills_map[s] = k++;
        }
      }

      const int inf32 = 1 << 30;
      std::vector dp (1 << n, std::vector(m + 1, std::make_pair(inf32, std::make_pair(-1, -1))));

      dp[0][0].first = 0;

      for (int i = 0; i < 1 << n; ++i) {
        for (int j = 1; j <= m; ++j) {
          int skill_mask = 0;
          for (auto &s: people[j - 1])
            skill_mask |= 1 << skills_map[s];
          
          int remain_skills = i & (i ^ skill_mask);
          if (dp[i][j - 1].first < dp[remain_skills][j - 1].first + 1)
            dp[i][j] = dp[i][j - 1];
          else {
            dp[i][j].first = dp[remain_skills][j - 1].first + 1;
            dp[i][j].second = std::make_pair(remain_skills, j - 1);
          }
        }
      }

      std::unordered_set <int> ans;
      int x = (1 << n) - 1, y = m;

      while (x > 0 and y > 0) {
        auto [new_x, new_y] = dp[x][y].second;
        if (new_y != y)
          ans.insert(new_y);
        x = new_x;
        y = new_y;
      }

      return std::vector(ans.begin(), ans.end());
    }
};
```

<br />

### Statistics

- total accepted: 36377
- total submissions: 68597
- acceptance rate: 53.0%
- likes: 1502
- dislikes: 37

<br />

### Similar Problems

- [The Number of Good Subsets](https://leetcode.com/problems/the-number-of-good-subsets) (Hard)
- [Minimum Number of Work Sessions to Finish the Tasks](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks) (Medium)
- [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns) (Medium)

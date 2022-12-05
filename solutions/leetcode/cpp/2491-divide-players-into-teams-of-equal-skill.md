# [2491] Divide Players Into Teams of Equal Skill



### Statement

You are given a positive integer array `skill` of **even** length `n` where `skill[i]` denotes the skill of the `ith` player. Divide the players into `n / 2` teams of size `2` such that the total skill of each team is **equal**.

The **chemistry** of a team is equal to the **product** of the skills of the players on that team.

Return *the sum of the **chemistry** of all the teams, or return* `-1` *if there is no way to divide the players into teams such that the total skill of each team is equal.*
**Example 1:**

```

**Input:** skill = [3,2,5,1,3,4]
**Output:** 22
**Explanation:** 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

```

**Example 2:**

```

**Input:** skill = [3,4]
**Output:** 12
**Explanation:** 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.

```

**Example 3:**

```

**Input:** skill = [1,1,2,3]
**Output:** -1
**Explanation:** 
There is no way to divide the players into teams such that the total skill of each team is equal.

```

**Constraints:**
* `2 <= skill.length <= 105`
* `skill.length` is even.
* `1 <= skill[i] <= 1000`


<br>

### Hints

- Try sorting the skill array.
- It is always optimal to pair the weakest available player with the strongest available player.

<br>

### Solution

```cpp
class Solution {
  public:
    long long dividePlayers (vector <int>& skill) {
      std::sort(skill.begin(), skill.end());
      
      int n = skill.size(), team = skill.front() + skill.back();
      int64_t chemistry = 0;
      
      for (int i = 0; i < n / 2; ++i) {
        if (skill[i] + skill[n - i - 1] != team)
          return -1;
        chemistry += skill[i] * skill[n - i - 1];
      }
      
      return chemistry;
    }
};
```

<br>

### Statistics

- total accepted: 12881
- total submissions: 22359
- acceptance rate: 57.6%
- likes: 117
- dislikes: 1

<br>

### Similar Problems

- [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements) (Medium)
- [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs) (Medium)

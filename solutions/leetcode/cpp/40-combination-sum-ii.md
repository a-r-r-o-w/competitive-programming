# [40] Combination Sum II

**[array, backtracking]**

### Statement

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates`where the candidate numbers sum to `target`.

Each number in `candidates`may only be used **once** in the combination.

**Note:**The solution set must not contain duplicate combinations.


**Example 1:**

```

**Input:** candidates = [10,1,2,7,6,1,5], target = 8
**Output:** 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

**Example 2:**

```

**Input:** candidates = [2,5,2,1,2], target = 5
**Output:** 
[
[1,2,2],
[5]
]

```

**Constraints:**
* `1 <=candidates.length <= 100`
* `1 <=candidates[i] <= 50`
* `1 <= target <= 30`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> combinationSum2 (vector <int>& candidates, int target) {
      std::set <std::vector <int>> combinations;
      std::vector <int> take;

      std::sort(candidates.begin(), candidates.end());
      
      auto dp = [&] (auto self, int t, int index) -> void {
        if (t == 0) {
          combinations.insert(take);
          return;
        }

        for (int i = index; i < int(candidates.size()); ++i) {
          if (i > index and candidates[i] == candidates[i - 1])
            continue;
          if (t - candidates[i] < 0)
            break;
          take.push_back(candidates[i]);
          self(self, t - candidates[i], i + 1);
          take.pop_back();
        }
      };

      dp(dp, target, 0);
      
      return std::vector <std::vector <int>> (combinations.begin(), combinations.end());
    }
};
```

<br />

### Statistics

- total accepted: 702065
- total submissions: 1315344
- acceptance rate: 53.4%
- likes: 7816
- dislikes: 198

<br />

### Similar Problems

- [Combination Sum](https://leetcode.com/problems/combination-sum) (Medium)

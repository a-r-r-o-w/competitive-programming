# [506] Relative Ranks

**[array, sorting, heap-priority-queue]**

### Statement

You are given an integer array `score` of size `n`, where `score[i]` is the score of the `ith` athlete in a competition. All the scores are guaranteed to be **unique**.

The athletes are **placed** based on their scores, where the `1st` place athlete has the highest score, the `2nd` place athlete has the `2nd` highest score, and so on. The placement of each athlete determines their rank:

* The `1st` place athlete's rank is `"Gold Medal"`.
* The `2nd` place athlete's rank is `"Silver Medal"`.
* The `3rd` place athlete's rank is `"Bronze Medal"`.
* For the `4th` place to the `nth` place athlete, their rank is their placement number (i.e., the `xth` place athlete's rank is `"x"`).



Return an array `answer` of size `n` where `answer[i]` is the **rank** of the `ith` athlete.


**Example 1:**

```

**Input:** score = [5,4,3,2,1]
**Output:** ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
**Explanation:** The placements are [1st, 2nd, 3rd, 4th, 5th].
```

**Example 2:**

```

**Input:** score = [10,3,8,9,4]
**Output:** ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
**Explanation:** The placements are [1st, 5th, 3rd, 2nd, 4th].


```

**Constraints:**
* `n == score.length`
* `1 <= n <= 104`
* `0 <= score[i] <= 106`
* All the values in `score` are **unique**.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <string> findRelativeRanks (vector <int>& score) {
      int n = score.size();
      std::vector <std::string> ans (n);
      std::vector <int> order (n);
      
      std::iota(order.begin(), order.end(), 0);
      std::sort(order.begin(), order.end(), [&] (int l, int r) {
        return score[l] > score[r];
      });
      
      ans[order[0]] = "Gold Medal";
      
      if (n >= 2)
        ans[order[1]] = "Silver Medal";
      if (n >= 3)
        ans[order[2]] = "Bronze Medal";
      
      for (int i = 3; i < n; ++i)
        ans[order[i]] = std::to_string(i + 1);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 108054
- total submissions: 183131
- acceptance rate: 59.0%
- likes: 786
- dislikes: 41

<br>

### Similar Problems

None

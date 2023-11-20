# [1402] Reducing Dishes

**[array, dynamic-programming, greedy, sorting]**

### Statement

A chef has collected data on the `satisfaction` level of his `n` dishes. Chef can cook any dish in 1 unit of time.

**Like-time coefficient** of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. `time[i] * satisfaction[i]`.

Return *the maximum sum of **like-time coefficient** that the chef can obtain after dishes preparation*.

Dishes can be prepared in **any** order and the chef can discard some dishes to get this maximum value.


**Example 1:**

```

**Input:** satisfaction = [-1,-8,0,5,-9]
**Output:** 14
**Explanation:** After Removing the second and last dish, the maximum total **like-time coefficient** will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
```

**Example 2:**

```

**Input:** satisfaction = [4,3,2]
**Output:** 20
**Explanation:** Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

```

**Example 3:**

```

**Input:** satisfaction = [-1,-4,-5]
**Output:** 0
**Explanation:** People do not like the dishes. No dish is prepared.

```

**Constraints:**
* `n == satisfaction.length`
* `1 <= n <= 500`
* `-1000 <= satisfaction[i] <= 1000`


<br />

### Hints

- Use dynamic programming to find the optimal solution by saving the previous best like-time coefficient and its corresponding element sum.
- If adding the current element to the previous best like-time coefficient and its corresponding element sum would increase the best like-time coefficient, then go ahead and add it. Otherwise, keep the previous best like-time coefficient.

<br />

### Solution

```cpp
class Solution {
  public:
    int maxSatisfaction (vector <int>& satisfaction) {
      int n = satisfaction.size();
      int64_t sum = 0, ans = 0;
      std::vector <int64_t> suffix (n);
      
      std::sort(satisfaction.begin(), satisfaction.end());
      for (int i = 0; i < n; ++i)
        sum += int64_t(i + 1) * satisfaction[i];
      suffix[n - 1] = satisfaction[n - 1];
      for (int i = n - 2; i >= 0; --i)
        suffix[i] = suffix[i + 1] + satisfaction[i];
      for (int i = 0; i < n; ++i) {
        ans = std::max(ans, sum);
        sum -= suffix[i];
      }

      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 102774
- total submissions: 133726
- acceptance rate: 76.9%
- likes: 2648
- dislikes: 269

<br />

### Similar Problems

None

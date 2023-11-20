# [135] Candy

**[array, greedy]**

### Statement

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.



Return *the minimum number of candies you need to have to distribute the candies to the children*.


**Example 1:**

```

**Input:** ratings = [1,0,2]
**Output:** 5
**Explanation:** You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

```

**Example 2:**

```

**Input:** ratings = [1,2,2]
**Output:** 4
**Explanation:** You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

```

**Constraints:**
* `n == ratings.length`
* `1 <= n <= 2 * 10^4`
* `0 <= ratings[i] <= 2 * 10^4`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    int candy(vector <int>& ratings) {
      int n = ratings.size(), ans = n;
      int i = 1;

      while (i < n) {
        if (ratings[i] == ratings[i - 1]) {
          ++i;
          continue;
        }

        int inc = 0, j = i;
        while (j < n and ratings[j] > ratings[j - 1]) {
          ++inc;
          ans += inc;
          ++j;
        }

        int dec = 0;
        while (j < n and ratings[j] < ratings[j - 1]) {
          ++dec;
          ans += dec;
          ++j;
        }

        ans -= std::min(inc, dec);
        i = j;
      }
      
      return ans;
    }
};
```

<br />

### Statistics

- total accepted: 352704
- total submissions: 851708
- acceptance rate: 41.4%
- likes: 6257
- dislikes: 445

<br />

### Similar Problems

- [Minimize Maximum Value in a Grid](https://leetcode.com/problems/minimize-maximum-value-in-a-grid) (Hard)

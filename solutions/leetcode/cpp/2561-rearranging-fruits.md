# [2561] Rearranging Fruits



### Statement

You have two fruit baskets containing `n` fruits each. You are given two **0-indexed** integer arrays `basket1` and `basket2` representing the cost of fruit in each basket. You want to make both baskets **equal**. To do so, you can use the following operation as many times as you want:

* Chose two indices `i` and `j`, and swap the `i^th` fruit of `basket1` with the `j^th` fruit of `basket2`.
* The cost of the swap is `min(basket1[i],basket2[j])`.



Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return *the minimum cost to make both the baskets equal or* `-1` *if impossible.*
**Example 1:**

```

**Input:** basket1 = [4,2,2,2], basket2 = [1,4,1,2]
**Output:** 1
**Explanation:** Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.

```

**Example 2:**

```

**Input:** basket1 = [2,3,4,1], basket2 = [3,2,5,1]
**Output:** -1
**Explanation:** It can be shown that it is impossible to make both the baskets equal.

```

**Constraints:**
* `basket1.length == bakste2.length`
* `1 <= basket1.length <= 10^5`
* `1 <= basket1[i],basket2[i]<= 10^9`


<br />

### Hints

- Create two frequency maps for both arrays, and find the minimum element among all elements of both arrays.
- Check if the sum of frequencies of an element in both arrays is odd, if so return -1
- Store the elements that need to be swapped in a vector, and sort it.
- Can we reduce swapping cost with the help of minimum element?
- Calculate the minimum cost of swapping.

<br />

### Solution

```cpp
class Solution {
  public:
    long long minCost (vector <int>& basket1, vector <int>& basket2) {
      int n = basket1.size();
      std::map <int, int> freq;
      
      for (int i: basket1)
        ++freq[i];
      for (int i: basket2)
        --freq[i];
      
      std::vector <int> option1, option2;
      int min = freq.begin()->first, count = 0;
      
      for (auto &[x, y]: freq) {
        std::vector <int>& which = y < 0 ? option2 : option1;
        y = std::abs(y);
        
        if (y & 1)
          return -1;
        
        y /= 2;
        while (y--)
          which.push_back(x), ++count;
      }
      
      std::reverse(option2.begin(), option2.end());
      
      int64_t cost = 0;
      
      for (int i = 0; i < count / 2; ++i)
        cost += std::min(std::min(option1[i], option2[i]), 2 * min);
      
      return cost;
    }
};
```

<br />

### Statistics

- total accepted: 2161
- total submissions: 8549
- acceptance rate: 25.3%
- likes: 76
- dislikes: 5

<br />

### Similar Problems

- [The Latest Time to Catch a Bus](https://leetcode.com/problems/the-latest-time-to-catch-a-bus) (Medium)
- [Minimum Number of Operations to Make Arrays Similar](https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar) (Hard)

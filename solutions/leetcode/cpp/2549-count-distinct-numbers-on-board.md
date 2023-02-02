# [2549] Count Distinct Numbers on Board



### Statement

You are given a positive integer `n`, that is initially placed on a board. Every day, for `10^9` days, you perform the following procedure:

* For each number `x` present on the board, find all numbers `1 <= i <= n` such that `x % i == 1`.
* Then, place those numbers on the board.



Return *the number of **distinct** integers present on the board after* `10^9` *days have elapsed*.

**Note:**
* Once a number is placed on the board, it will remain on it until the end.
* `%`standsfor the modulo operation. For example,`14 % 3` is `2`.


**Example 1:**

```

**Input:** n = 5
**Output:** 4
**Explanation:** Initially, 5 is present on the board. 
The next day, 2 and 4 will be added since 5 % 2 == 1 and 5 % 4 == 1. 
After that day, 3 will be added to the board because 4 % 3 == 1. 
At the end of a billion days, the distinct numbers on the board will be 2, 3, 4, and 5. 

```

**Example 2:**

```

**Input:** n = 3
**Output:** 2
**Explanation:** 
Since 3 % 2 == 1, 2 will be added to the board. 
After a billion days, the only two distinct numbers on the board are 2 and 3. 

```

**Constraints:**
* `1 <= n <= 100`


<br />

### Hints

- For n > 2, n % (n - 1) == 1 thus n - 1 will be added on the board the next day.
- As the operations are performed for so long time, all the numbers lesser than n except 1 will be added to the board.
- What will happen if n == 1?

<br />

### Solution

```cpp
class Solution {
  public:
    int distinctIntegers (int n) {
      std::set <int> board;
      board.insert(n);
      
      while (true) {
        int oldsize = board.size();
        std::set <int> v;
        
        for (int i: board) {
          for (int j = 1; j <= n; ++j) {
            if (i % j == 1)
              v.insert(j);
          }
        }
        
        for (int i: v)
          board.insert(i);
        
        if ((int)board.size() == oldsize)
          break;
      }
      
      return board.size();
    }
};
```

<br />

### Statistics

- total accepted: 18015
- total submissions: 30892
- acceptance rate: 58.3%
- likes: 77
- dislikes: 76

<br />

### Similar Problems

- [Count of Matches in Tournament](https://leetcode.com/problems/count-of-matches-in-tournament) (Easy)

# [2591] Distribute Money to Maximum Children



### Statement

You are given an integer `money` denoting the amount of money (in dollars) that you have and another integer `children` denoting the number of children that you must distribute the money to.

You have to distribute the money according to the following rules:

* All money must be distributed.
* Everyone must receive at least `1` dollar.
* Nobody receives `4` dollars.



Return *the **maximum** number of children who may receive **exactly*** `8` *dollars if you distribute the money according to the aforementioned rules*. If there is no way to distribute the money, return `-1`.


**Example 1:**

```

**Input:** money = 20, children = 3
**Output:** 1
**Explanation:** 
The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
- 8 dollars to the first child.
- 9 dollars to the second child. 
- 3 dollars to the third child.
It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.

```

**Example 2:**

```

**Input:** money = 16, children = 2
**Output:** 2
**Explanation:** Each child can be given 8 dollars.

```

**Constraints:**
* `1 <= money <= 200`
* `2 <= children <= 30`


<br />

### Hints

- Can we distribute the money according to the rules if we give 'k' children exactly 8 dollars?
- Brute force to find the largest possible value of k, or return -1 if there doesn’t exist any such k.

<br />

### Solution

```cpp
class Solution {
  public:
    int distMoney (int money, int children) {
      if (money < children)
        return -1;
      if (money > children * 8)
        return children - 1;
      
      int count = 0;
      
      while (money > 0 and money - 8 >= children - 1) {
        ++count;
        money -= 8;
        --children;
      }
      if (money == 4 and children == 1)
        --count;
      
      return count;
    }
};
```

<br />

### Statistics

- total accepted: 12754
- total submissions: 72123
- acceptance rate: 17.7%
- likes: 76
- dislikes: 461

<br />

### Similar Problems

- [Distribute Candies to People](https://leetcode.com/problems/distribute-candies-to-people) (Easy)
- [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies) (Medium)
- [Calculate Money in Leetcode Bank](https://leetcode.com/problems/calculate-money-in-leetcode-bank) (Easy)

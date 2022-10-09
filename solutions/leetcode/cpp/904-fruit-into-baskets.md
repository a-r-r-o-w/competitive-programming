# [904] Fruit Into Baskets

**[array, hash-table, sliding-window]**

### Statement

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the **type** of fruit the `ith` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

* You only have **two** baskets, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.
* Starting from any tree of your choice, you must pick **exactly one fruit** from **every** tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
* Once you reach a tree with fruit that cannot fit in your baskets, you must stop.



Given the integer array `fruits`, return *the **maximum** number of fruits you can pick*.


**Example 1:**

```

**Input:** fruits = [1,2,1]
**Output:** 3
**Explanation:** We can pick from all 3 trees.

```

**Example 2:**

```

**Input:** fruits = [0,1,2,2]
**Output:** 3
**Explanation:** We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

```

**Example 3:**

```

**Input:** fruits = [1,2,3,2,2]
**Output:** 4
**Explanation:** We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

```

**Constraints:**
* `1 <= fruits.length <= 105`
* `0 <= fruits[i] < fruits.length`


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int totalFruit (vector <int>& fruits) {
      std::map <int, int> have;
      int n = fruits.size();
      int left = 0, max = 0;
      
      for (int i = 0; i < n; ++i) {
        ++have[fruits[i]];
        
        if ((int)have.size() > 2) {
          while ((int)have.size() > 2) {
            --have[fruits[left]];
            if (have[fruits[left]] == 0)
              have.erase(fruits[left]);
            ++left;
          }
        }
        
        int count = 0;
        for (auto [u, v]: have)
          count += v;
        
        max = std::max(max, count);
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 230857
- total submissions: 542526
- acceptance rate: 42.6%
- likes: 1498
- dislikes: 106

<br>

### Similar Problems

None

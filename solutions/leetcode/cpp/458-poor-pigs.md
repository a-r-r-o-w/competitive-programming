# [458] Poor Pigs

**[math, dynamic-programming, combinatorics]**

### Statement

There are `buckets` buckets of liquid, where **exactly one** of the buckets is poisonous. To figure out which one is poisonous, you feed some number of (poor) pigs the liquid to see whether they will die or not. Unfortunately, you only have `minutesToTest` minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

1. Choose some live pigs to feed.
2. For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time.
3. Wait for `minutesToDie` minutes. You may **not** feed any other pigs during this time.
4. After `minutesToDie` minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
5. Repeat this process until you run out of time.



Given `buckets`, `minutesToDie`, and `minutesToTest`, return *the **minimum** number of pigs needed to figure out which bucket is poisonous within the allotted time*.


**Example 1:**

```
**Input:** buckets = 1000, minutesToDie = 15, minutesToTest = 60
**Output:** 5

```
**Example 2:**

```
**Input:** buckets = 4, minutesToDie = 15, minutesToTest = 15
**Output:** 2

```
**Example 3:**

```
**Input:** buckets = 4, minutesToDie = 15, minutesToTest = 30
**Output:** 2

```

**Constraints:**
* `1 <= buckets <= 1000`
* `1 <=minutesToDie <=minutesToTest <= 100`


<br>

### Hints

- What if you only have one shot? Eg. 4 buckets, 15 mins to die, and 15 mins to test.
- How many states can we generate with x pigs and T tests?
- Find minimum <code>x</code> such that <code>(T+1)^x >= N</code>

<br>

### Solution

```cpp
class Solution {
  public:
    int poorPigs (int buckets, int minutesToDie, int minutesToTest) {
      int required = 0;
      int tests_performable = minutesToTest / minutesToDie;
      int states = tests_performable + 1;
      int buckets_covered = 1;
      
      while (buckets_covered < buckets) {
        buckets_covered *= states;
        ++required;
      }
      
      return required;
    }
};
```

<br>

### Statistics

- total accepted: 49326
- total submissions: 79838
- acceptance rate: 61.8%
- likes: 974
- dislikes: 2000

<br>

### Similar Problems

None

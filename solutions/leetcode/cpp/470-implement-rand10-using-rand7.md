# [470] Implement Rand10() Using Rand7()

**[math, rejection-sampling, randomized, probability-and-statistics]**

### Statement

Given the **API** `rand7()` that generates a uniform random integer in the range `[1, 7]`, write a function `rand10()` that generates a uniform random integer in the range `[1, 10]`. You can only call the API `rand7()`, and you shouldn't call any other API. Please **do not** use a language's built-in random API.

Each test case will have one **internal** argument `n`, the number of times that your implemented function `rand10()` will be called while testing. Note that this is **not an argument** passed to `rand10()`.


**Example 1:**

```
**Input:** n = 1
**Output:** [2]

```
**Example 2:**

```
**Input:** n = 2
**Output:** [2,8]

```
**Example 3:**

```
**Input:** n = 3
**Output:** [3,8,10]

```

**Constraints:**
* `1 <= n <= 105`


**Follow up:**
* What is the [expected value](https://en.wikipedia.org/wiki/Expected_value) for the number of calls to `rand7()` function?
* Could you minimize the number of calls to `rand7()`?


<br>

### Hints

None

<br>

### Solution

```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
  public:
    int rand10 () {
      int sum = -7;

      // 0-49
      for (int i = 0; i < 8; ++i)
        sum += rand7();
      
      return 1 + sum % 10;
    }
};
```

<br>

### Statistics

- total accepted: 69573
- total submissions: 149541
- acceptance rate: 46.5%
- likes: 970
- dislikes: 323

<br>

### Similar Problems

None

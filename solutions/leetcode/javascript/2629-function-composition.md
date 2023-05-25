# [2629] Function Composition



### Statement

Given an array of functions`[f1, f2, f3,..., fn]`, returna new function`fn`that is the **functioncomposition** of the array of functions.

The**functioncomposition**of`[f(x), g(x), h(x)]`is`fn(x) = f(g(h(x)))`.

The**functioncomposition**of an empty list of functions is the**identity function**`f(x) = x`.

You may assume eachfunctionin the array accepts one integer as inputand returns one integer as output.


**Example 1:**

```

**Input:** functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
**Output:** 65
**Explanation:**
Evaluating from right to left ...
Starting with x = 4.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65

```

**Example 2:**

```

**Input:** functions = [x => 10 * x, x => 10 * x, x => 10 * x], x = 1
**Output:** 1000
**Explanation:**
Evaluating from right to left ...
10 * (1) = 10
10 * (10) = 100
10 * (100) = 1000

```

**Example 3:**

```

**Input:** functions = [], x = 42
**Output:** 42
**Explanation:**
The composition of zero functions is the identity function
```

**Constraints:**
* `-1000 <= x <= 1000`
* `0 <= functions.length <= 1000`
* `all functions accept and return a single integer`


<br />

### Hints

- Start by returning a function that takes in a number and returns a number.
- Call each of the functions in the correct order. Each time passing the output of the previous function into the next function.

<br />

### Solution

```cpp
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
    let result = x;
    for (let i = functions.length - 1; i >= 0; --i)
      result = functions[i](result);
    return result;
  }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
```

<br />

### Statistics

- total accepted: 15958
- total submissions: 17415
- acceptance rate: 91.6%
- likes: 222
- dislikes: 9

<br />

### Similar Problems

- [Memoize](https://leetcode.com/problems/memoize) (Medium)
- [Counter](https://leetcode.com/problems/counter) (Easy)

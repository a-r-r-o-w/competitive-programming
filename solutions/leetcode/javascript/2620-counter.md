# [2620] Counter



### Statement

Given an integer`n`,return a `counter` function. This `counter` function initially returns`n`and then returns 1 more than the previous value every subsequent time it is called (`n`, `n + 1`, `n + 2`, etc).


**Example 1:**

```

**Input:** 
n = 10 
["call","call","call"]
**Output:** [10,11,12]
**Explanation:**counter() = 10 // The first time counter() is called, it returns n.
counter() = 11 // Returns 1 more than the previous time.
counter() = 12 // Returns 1 more than the previous time.

```

**Example 2:**

```

**Input:** 
n = -2
["call","call","call","call","call"]
**Output:** [-2,-1,0,1,2]
**Explanation:** counter() initially returns -2. Then increases after each sebsequent call.

```

**Constraints:**
* `-1000<= n <= 1000`
* `At most 1000 calls to counter() will be made`


<br />

### Hints

- In JavaScript, a function can return a closure. A closure is defined as a function and the variables declared around it (it's lexical environment).
- A count variable can be initialized in the outer function and mutated in the inner function.

<br />

### Solution

```cpp
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
      return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```

<br />

### Statistics

- total accepted: 35308
- total submissions: 40049
- acceptance rate: 88.2%
- likes: 369
- dislikes: 13

<br />

### Similar Problems

- [Memoize](https://leetcode.com/problems/memoize) (Medium)
- [Function Composition](https://leetcode.com/problems/function-composition) (Easy)
- [Counter II](https://leetcode.com/problems/counter-ii) (Easy)

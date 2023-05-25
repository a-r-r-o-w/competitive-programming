# [2665] Counter II



### Statement

Write a function`createCounter`. It should accept an initial integer`init`. It should return an object with three functions.

The three functions are:

* `increment()`increasesthe current value by 1 and then returns it.
* `decrement()`reduces the current value by 1 and then returns it.
* `reset()`sets the current value to`init`and then returns it.


**Example 1:**

```

**Input:** init = 5, calls = ["increment","reset","decrement"]
**Output:** [6,5,4]
**Explanation:**
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4

```

**Example 2:**

```

**Input:** init = 0, calls = ["increment","increment","decrement","reset","reset"]
**Output:** [1,2,1,0,0]
**Explanation:**
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0

```

**Constraints:**
* `-1000 <= init <= 1000`
* `total calls not to exceed 1000`


<br />

### Hints

- You can return an object with methods.
- Initialize a variable for currentCount. Inside these methods, add the appropriate logic which mutates currentCount.

<br />

### Solution

```cpp
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

var createCounter = function(init) {
  let real_init = init;
  return {
    increment: () => ++init,
    decrement: () => --init,
    reset: () => init = real_init
  };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
```

<br />

### Statistics

- total accepted: 14453
- total submissions: 16003
- acceptance rate: 90.3%
- likes: 233
- dislikes: 4

<br />

### Similar Problems

- [Counter](https://leetcode.com/problems/counter) (Easy)

# [2666] Allow One Function Call



### Statement

Given a function `fn`, return a new function that is identical to the original function except that it ensures`fn`iscalled at most once.

* The first time the returned function is called, it should return the same result as`fn`.
* Every subsequent time it is called, it should return`undefined`.


**Example 1:**

```

**Input:** fn = (a,b,c) => (a + b + c), calls = [[1,2,3],[2,3,6]]
**Output:** [{"calls":1,"value":6}]
**Explanation:**
const onceFn = once(fn);
onceFn(1, 2, 3); // 6
onceFn(2, 3, 6); // undefined, fn was not called

```

**Example 2:**

```

**Input:** fn = (a,b,c) => (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
**Output:** [{"calls":1,"value":140}]
**Explanation:**
const onceFn = once(fn);
onceFn(5, 7, 4); // 140
onceFn(2, 3, 6); // undefined, fn was not called
onceFn(4, 6, 8); // undefined, fn was not called

```

**Constraints:**
* `1 <= calls.length <= 10`
* `1 <= calls[i].length <= 100`
* `2 <= JSON.stringify(calls).length <= 1000`


<br />

### Hints

None

<br />

### Solution

```cpp
/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
  let called = false;
  return function(...args) {
    if (called)
      return undefined;
    called = true;
    return fn(...args);
  }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
```

<br />

### Statistics

- total accepted: 10033
- total submissions: 10878
- acceptance rate: 92.2%
- likes: 161
- dislikes: 8

<br />

### Similar Problems

None

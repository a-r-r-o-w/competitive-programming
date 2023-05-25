# [2623] Memoize



### Statement

Given a function `fn`, return a**memoized**version of that function.

A**memoized**function is a function that will never be called twice withthe same inputs. Instead it will returna cached value.

You can assume there are**3**possible input functions:`sum`**,** `fib`**,**and`factorial`**.**
* `sum`accepts two integers`a` and `b` and returns `a + b`.
* `fib`accepts asingle integer`n` andreturns`1` if `n <= 1` or`fib(n - 1) + fib(n - 2)`otherwise.
* `factorial`accepts a single integer`n` and returns `1`if`n <= 1`or`factorial(n - 1) * n`otherwise.


**Example 1:**

```

**Input**
"sum"
["call","call","getCallCount","call","getCallCount"]
[[2,2],[2,2],[],[1,2],[]]
**Output**
[4,4,1,3,2]

**Explanation**
const sum = (a, b) => a + b;
const memoizedSum = memoize(sum);
memoizedSum(2, 2); // Returns 4. sum() was called as (2, 2) was not seen before.
memoizedSum(2, 2); // Returns 4. However sum() was not called because the same inputs were seen before.
// Total call count: 1
memoizedSum(1, 2); // Returns 3. sum() was called as (1, 2) was not seen before.
// Total call count: 2

```

**Example 2:**

```

**Input**"factorial"
["call","call","call","getCallCount","call","getCallCount"]
[[2],[3],[2],[],[3],[]]
**Output**
[2,6,2,2,6,2]

**Explanation**
const factorial = (n) => (n <= 1) ? 1 : (n * factorial(n - 1));
const memoFactorial = memoize(factorial);
memoFactorial(2); // Returns 2.
memoFactorial(3); // Returns 6.
memoFactorial(2); // Returns 2. However factorial was not called because 2 was seen before.
// Total call count: 2
memoFactorial(3); // Returns 6. However factorial was not called because 3 was seen before.
// Total call count: 2

```

**Example 3:**

```

**Input**"fib"
["call","getCallCount"]
[[5],[]]
**Output**
[8,1]

**Explanation**fib(5) = 8
// Total call count: 1


```

**Constraints:**
* `0 <= a, b <= 10^5`
* `1 <= n <= 10`
* `at most 10^5function calls`
* `at most 10^5attempts to access callCount`
* `input function is sum, fib, or factorial`


<br />

### Hints

- You can create copy of a function by spreading function parameters. 

function outerFunction(passedFunction) {
  return newFunction(...params) {
    return passedFunction(...params);
  };
}
- params is an array. Since you know all values in the array are numbers, you can turn it into a string with JSON.stringify().
- In the outerFunction, you can declare a Map or Object. In the inner function you can avoid executing the passed function if the params have already been passed before.

<br />

### Solution

```cpp
/**
 * @param {Function} fn
 */
function memoize(fn) {
  let cache = new Map();
  return function(...args) {
    let args_json = JSON.stringify(args);
    if (cache.has(args_json))
      return cache.get(args_json)
    let result = fn(...args);
    cache.set(args_json, result);
    return result;
  }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
```

<br />

### Statistics

- total accepted: 5149
- total submissions: 8340
- acceptance rate: 61.7%
- likes: 97
- dislikes: 12

<br />

### Similar Problems

- [Counter](https://leetcode.com/problems/counter) (Easy)
- [Curry](https://leetcode.com/problems/curry) (Medium)
- [Function Composition](https://leetcode.com/problems/function-composition) (Easy)
- [Memoize II](https://leetcode.com/problems/memoize-ii) (Hard)

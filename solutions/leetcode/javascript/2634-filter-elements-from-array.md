# [2634] Filter Elements from Array



### Statement

Given an integer array`arr`and a filteringfunction`fn`,returna new array with a fewer or equal number of elements.

The returned array should only contain elements where`fn(arr[i],i)`evaluated to a truthy value.

Please solve it without the built-in `Array.filter` method.


**Example 1:**

```

**Input:** arr = [0,10,20,30], fn = function greaterThan10(n) { return n > 10; }
**Output:** [20,30]
**Explanation:**
const newArray = filter(arr, fn); // [20, 30]
The function filters out values that are not greater than 10
```

**Example 2:**

```

**Input:** arr = [1,2,3], fn = function firstIndex(n, i) { return i === 0; }
**Output:** [1]
**Explanation:**
fn can also accept the index of each element
In this case, the function removes elements not at index 0

```

**Example 3:**

```

**Input:** arr = [-2,-1,0,1,2], fn = function plusOne(n) { return n + 1 }
**Output:** [-2,0,1,2]
**Explanation:**
Falsey values such as 0 should be filtered out

```

**Constraints:**
* `0 <= arr.length <= 1000`
* `-10^9<= arr[i] <= 10^9`


<br />

### Hints

- Start by declaring a new array which will eventually be returned.
- In Javascript, there is the concept of "truthiness" and "falsiness". Values such as 0, undefined, null, and false are falsy. Most values are truthy: 1, {}, [], true, etc. In Javascript, the contents of if-statements don't need to be booleans. You can say "if ([1,2,3]) {}", and it's equivalent to saying 'if (true) {}".
- Loop over each element in the array. If fn(arr[i]) is truthy, push it to the array.

<br />

### Solution

```cpp
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
  let filtered_array = [];
  for (let i = 0; i < arr.length; ++i)
    if (fn(arr[i], i))
      filtered_array.push(arr[i]);
  return filtered_array;
};
```

<br />

### Statistics

- total accepted: 16507
- total submissions: 18643
- acceptance rate: 88.5%
- likes: 234
- dislikes: 12

<br />

### Similar Problems

- [Group By](https://leetcode.com/problems/group-by) (Medium)
- [Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array) (Easy)
- [Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation) (Easy)

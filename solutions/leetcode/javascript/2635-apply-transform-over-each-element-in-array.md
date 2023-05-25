# [2635] Apply Transform Over Each Element in Array



### Statement

Given an integer array`arr`and a mapping function`fn`, returna new array with a transformation applied to each element.

The returned array should be created such that`returnedArray[i] = fn(arr[i], i)`.

Please solve it without the built-in `Array.map` method.


**Example 1:**

```

**Input:** arr = [1,2,3], fn = function plusone(n) { return n + 1; }
**Output:** [2,3,4]
**Explanation:**
const newArray = map(arr, plusone); // [2,3,4]
The function increases each value in the array by one. 

```

**Example 2:**

```

**Input:** arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
**Output:** [1,3,5]
**Explanation:** The function increases each value by the index it resides in.

```

**Example 3:**

```

**Input:** arr = [10,20,30], fn = function constant() { return 42; }
**Output:** [42,42,42]
**Explanation:** The function always returns 42.

```

**Constraints:**
* `0 <= arr.length <= 1000`
* `-10^9<= arr[i] <= 10^9`
* `fn returns a number`


<br />

### Hints

- Start by creating an array that will eventually be returned.
- Loop over each element in the passed array. Push fn(arr[i]) to the returned array.

<br />

### Solution

```cpp
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var map = function(arr, fn) {
  for (let i = 0; i < arr.length; ++i)
    arr[i] = fn(arr[i], i);
  return arr;
};
```

<br />

### Statistics

- total accepted: 18512
- total submissions: 20434
- acceptance rate: 90.6%
- likes: 247
- dislikes: 12

<br />

### Similar Problems

- [Group By](https://leetcode.com/problems/group-by) (Medium)
- [Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array) (Easy)
- [Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation) (Easy)

# [1356] Sort Integers by The Number of 1 Bits

**[array, bit-manipulation, sorting, counting]**

### Statement

You are given an integer array `arr`. Sort the integers in the arrayin ascending order by the number of `1`'sin their binary representation and in case of two or more integers have the same number of `1`'s you have to sort them in ascending order.

Return *the array after sorting it*.


**Example 1:**

```

**Input:** arr = [0,1,2,3,4,5,6,7,8]
**Output:** [0,1,2,4,8,3,5,6,7]
**Explantion:** [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

```

**Example 2:**

```

**Input:** arr = [1024,512,256,128,64,32,16,8,4,2,1]
**Output:** [1,2,4,8,16,32,64,128,256,512,1024]
**Explantion:** All integers have 1 bit in the binary representation, you should just sort them in ascending order.

```

**Constraints:**
* `1 <= arr.length <= 500`
* `0 <= arr[i] <= 104`


<br>

### Hints

- Simulate the problem. Count the number of 1's in the binary representation of each integer.
- Sort by the number of 1's ascending and by the value in case of tie.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> sortByBits (vector <int>& arr) {
      std::sort(arr.begin(), arr.end(), [] (int l, int r) {
        int p = __builtin_popcount(l);
        int q = __builtin_popcount(r);
        if (p < q)
          return true;
        if (p > q)
          return false;
        return l < r;
      });

      return arr;
    }
};
```

<br>

### Statistics

- total accepted: 99211
- total submissions: 136969
- acceptance rate: 72.4%
- likes: 1450
- dislikes: 64

<br>

### Similar Problems

- [Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum) (Easy)

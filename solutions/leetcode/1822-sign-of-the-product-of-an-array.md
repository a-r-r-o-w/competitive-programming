# [1822] Sign of the Product of an Array

**[array, math]**

### Statement

There is a function `signFunc(x)` that returns:

* `1` if `x` is positive.
* `-1` if `x` is negative.
* `0` if `x` is equal to `0`.



You are given an integer array `nums`. Let `product` be the product of all values in the array `nums`.

Return `signFunc(product)`.


**Example 1:**

```

**Input:** nums = [-1,-2,-3,-4,3,2,1]
**Output:** 1
**Explanation:** The product of all values in the array is 144, and signFunc(144) = 1

```

**Example 2:**

```

**Input:** nums = [1,5,0,2,-3]
**Output:** 0
**Explanation:** The product of all values in the array is 0, and signFunc(0) = 0

```

**Example 3:**

```

**Input:** nums = [-1,1,-1,1,-1]
**Output:** -1
**Explanation:** The product of all values in the array is -1, and signFunc(-1) = -1

```

**Constraints:**
* `1 <= nums.length <= 1000`
* `-100 <= nums[i] <= 100`


<br>

### Hints

- If there is a 0 in the array the answer is 0
- To avoid overflow make all the negative numbers -1 and all positive numbers 1 and calculate the prod

<br>

### Solution

```cpp
class Solution {
  public:
    int arraySign (vector <int>& nums) {
      int parity = 1;
      
      std::for_each(nums.begin(), nums.end(), [&] (int x) {
        x = x < 0 ? -1 : x > 0 ? 1 : 0;
        parity *= x;
      });
      
      return parity;
    }
};
```

<br>

### Statistics

- total accepted: 127020
- total submissions: 190813
- acceptance rate: 66.6%
- likes: 718
- dislikes: 96

<br>

### Similar Problems

None

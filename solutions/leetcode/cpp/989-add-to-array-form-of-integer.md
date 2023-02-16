# [989] Add to Array-Form of Integer

**[array, math]**

### Statement

The **array-form** of an integer `num` is an array representing its digits in left to right order.

* For example, for `num = 1321`, the array form is `[1,3,2,1]`.



Given `num`, the **array-form** of an integer, and an integer `k`, return *the **array-form** of the integer* `num + k`.


**Example 1:**

```

**Input:** num = [1,2,0,0], k = 34
**Output:** [1,2,3,4]
**Explanation:** 1200 + 34 = 1234

```

**Example 2:**

```

**Input:** num = [2,7,4], k = 181
**Output:** [4,5,5]
**Explanation:** 274 + 181 = 455

```

**Example 3:**

```

**Input:** num = [2,1,5], k = 806
**Output:** [1,0,2,1]
**Explanation:** 215 + 806 = 1021

```

**Constraints:**
* `1 <= num.length <= 10^4`
* `0 <= num[i] <= 9`
* `num` does not contain any leading zeros except for the zero itself.
* `1 <= k <= 10^4`


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    vector <int> addToArrayForm (vector <int>& num, int k) {
      std::reverse(num.begin(), num.end());

      int n = num.size(), index = 0;

      while (k and index < n) {
        num[index] += k;
        k = num[index] / 10;
        num[index] %= 10;
        ++index;
      }

      while (k > 0) {
        num.push_back(k % 10);
        k /= 10;
      }

      std::reverse(num.begin(), num.end());

      return num;
    }
};
```

<br />

### Statistics

- total accepted: 188200
- total submissions: 402628
- acceptance rate: 46.7%
- likes: 2522
- dislikes: 218

<br />

### Similar Problems

- [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) (Medium)
- [Plus One](https://leetcode.com/problems/plus-one) (Easy)
- [Add Binary](https://leetcode.com/problems/add-binary) (Easy)
- [Add Strings](https://leetcode.com/problems/add-strings) (Easy)

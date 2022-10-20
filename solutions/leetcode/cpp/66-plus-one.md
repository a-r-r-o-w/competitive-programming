# [66] Plus One

**[array, math]**

### Statement

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return *the resulting array of digits*.


**Example 1:**

```

**Input:** digits = [1,2,3]
**Output:** [1,2,4]
**Explanation:** The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

```

**Example 2:**

```

**Input:** digits = [4,3,2,1]
**Output:** [4,3,2,2]
**Explanation:** The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

```

**Example 3:**

```

**Input:** digits = [9]
**Output:** [1,0]
**Explanation:** The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

```

**Constraints:**
* `1 <= digits.length <= 100`
* `0 <= digits[i] <= 9`
* `digits` does not contain any leading `0`'s.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> plusOne (vector <int>& digits) {
      bool carry = false;
      int n = digits.size();
      
      std::reverse(digits.begin(), digits.end());
      
      carry = digits[0] + 1 >= 10;
      digits[0] = (digits[0] + 1) % 10;
      
      for (int i = 1; i < n; ++i) {
        if (carry) {
          if (digits[i] + carry >= 10)
            digits[i] = 0;
          else {
            digits[i] += 1;
            carry = false;
          }
        }
      }
      
      if (carry)
        digits.push_back(1);
      
      std::reverse(digits.begin(), digits.end());
      
      return digits;
    }
};
```

<br>

### Statistics

- total accepted: 1389324
- total submissions: 3209418
- acceptance rate: 43.3%
- likes: 5374
- dislikes: 4480

<br>

### Similar Problems

- [Multiply Strings](https://leetcode.com/problems/multiply-strings) (Medium)
- [Add Binary](https://leetcode.com/problems/add-binary) (Easy)
- [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list) (Medium)
- [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer) (Easy)

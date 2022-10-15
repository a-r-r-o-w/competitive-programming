# [728] Self Dividing Numbers

**[math]**

### Statement

A **self-dividing number** is a number that is divisible by every digit it contains.

* For example, `128` is **a self-dividing number** because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.



A **self-dividing number** is not allowed to contain the digit zero.

Given two integers `left` and `right`, return *a list of all the **self-dividing numbers** in the range* `[left, right]`.


**Example 1:**

```
**Input:** left = 1, right = 22
**Output:** [1,2,3,4,5,6,7,8,9,11,12,15,22]

```
**Example 2:**

```
**Input:** left = 47, right = 85
**Output:** [48,55,66,77]

```

**Constraints:**
* `1 <= left <= right <= 104`


<br>

### Hints

- For each number in the range, check whether it is self dividing by converting that number to a character array (or string in Python), then checking that each digit is nonzero and divides the original number.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> selfDividingNumbers (int left, int right) {
      std::vector <int> ans;
      
      for (int i = left; i <= right; ++i) {
        int x = i;
        bool good = true;
        
        while (x) {
          if (x % 10 == 0 or i % (x % 10) != 0) {
            good = false;
            break;
          }
          x /= 10;
        }
        
        if (good)
          ans.push_back(i);
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 184746
- total submissions: 238663
- acceptance rate: 77.4%
- likes: 1247
- dislikes: 351

<br>

### Similar Problems

- [Perfect Number](https://leetcode.com/problems/perfect-number) (Easy)
- [Check if Number Has Equal Digit Count and Digit Value](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value) (Easy)

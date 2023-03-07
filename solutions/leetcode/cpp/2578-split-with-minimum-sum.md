# [2578] Split With Minimum Sum



### Statement

Given a positive integer `num`, split it into two non-negative integers `num1` and `num2` such that:

* The concatenation of `num1` and `num2` is a permutation of `num`.
	+ In other words, the sum of the number of occurrences of each digit in `num1` and `num2` is equal to the number of occurrences of that digit in `num`.
* `num1` and `num2` can contain leading zeros.



Return *the **minimum** possible sum of* `num1` *and* `num2`.

**Notes:**
* It is guaranteed that `num` does not contain any leading zeros.
* The order of occurrence of the digits in `num1` and `num2` may differ from the order of occurrence of `num`.


**Example 1:**

```

**Input:** num = 4325
**Output:** 59
**Explanation:** We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.

```

**Example 2:**

```

**Input:** num = 687
**Output:** 75
**Explanation:** We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.

```

**Constraints:**
* `10 <= num <= 10^9`


<br />

### Hints

- Sort the digits of num in non decreasing order.
- Assign digits to num1 and num2 alternatively.

<br />

### Solution

```cpp
class Solution {
  public:
    int splitNum (int num) {
      int p10 = 1, a = 0, b = 0;
      
      std::vector <int> digits;
      
      while (num) {
        digits.push_back(num % 10);
        num /= 10;
      }
      std::sort(digits.rbegin(), digits.rend());
      
      int n = digits.size();
      bool turn = true;
      
      for (int i = 0; i < n; ++i) {
        if (turn)
          a += p10 * digits[i];
        else
          b += p10 * digits[i];
        turn = !turn;
        if (turn)
          p10 *= 10;
      }
      
      return a + b;
    }
};
```

<br />

### Statistics

- total accepted: 11693
- total submissions: 17936
- acceptance rate: 65.2%
- likes: 52
- dislikes: 14

<br />

### Similar Problems

- [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum) (Medium)
- [Minimum Cost to Move Chips to The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position) (Easy)
- [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) (Hard)

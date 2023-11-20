# [1523] Count Odd Numbers in an Interval Range

**[math]**

### Statement

Given two non-negative integers `low` and `high`. Return the *count of odd numbers between* `low` *and* `high`*(inclusive)*.


**Example 1:**

```

**Input:** low = 3, high = 7
**Output:** 3
**Explanation:** The odd numbers between 3 and 7 are [3,5,7].
```

**Example 2:**

```

**Input:** low = 8, high = 10
**Output:** 1
**Explanation:** The odd numbers between 8 and 10 are [9].
```

**Constraints:**
* `0 <= low <= high<= 10^9`


<br>

### Hints

- If the range (high - low + 1) is even, the number of even and odd numbers in this range will be the same.
- If the range (high - low + 1) is odd, the solution will depend on the parity of high and low.

<br>

### Solution

```cpp
class Solution {
  public:
    int countOdds (int low, int high) {
      if (low % 2 == 0 and high % 2 == 0)
        return (high - low) / 2;
      else if (low % 2 == 0 or high % 2 == 0)
        return (high - low + 1) / 2;
      else
        return (high - low) / 2 + 1;
    }
};
```

or

```
class Solution {
  public:
    int countOdds (int low, int high) {
      return (high - low + (high & 1) + (low & 1)) / 2;
    }
};
```

<br>

### Statistics

- total accepted: 130784
- total submissions: 280634
- acceptance rate: 46.6%
- likes: 997
- dislikes: 73

<br>

### Similar Problems

None

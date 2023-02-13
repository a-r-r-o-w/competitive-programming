# [2544] Alternating Digit Sum



### Statement

You are given a positive integer `n`. Each digit of `n` has a sign according to the following rules:

* The **most significant digit** is assigned a **positive** sign.
* Each other digit has an opposite sign to its adjacent digits.



Return *the sum of all digits with their corresponding sign*.


**Example 1:**

```

**Input:** n = 521
**Output:** 4
**Explanation:** (+5) + (-2) + (+1) = 4.

```

**Example 2:**

```

**Input:** n = 111
**Output:** 1
**Explanation:** (+1) + (-1) + (+1) = 1.

```

**Example 3:**

```

**Input:** n = 886996
**Output:** 0
**Explanation:** (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

```

**Constraints:**
* `1 <= n <= 109`


.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}


<br>

### Hints

- The first step is to loop over the digits. We can convert the integer into a string, an array of digits, or just loop over its digits.
- Keep a variable sign that initially equals 1 and a variable answer that initially equals 0.
- Each time you loop over a digit i, add sign * i to answer, then multiply sign by -1.

<br>

### Solution

```cpp
class Solution {
  public:
    int alternateDigitSum (int n) {
      int count = 0, sum = 0;

      while (n) {
        int r = n % 10;
        n /= 10;
        sum += r * (count & 1 ? +1 : -1);
        ++count;
      }

      if (count & 1)
        sum = -sum;
      
      return sum;
    }
};
```

<br>

### Statistics

- total accepted: 17396
- total submissions: 25113
- acceptance rate: 69.3%
- likes: 77
- dislikes: 4

<br>

### Similar Problems

- [Add Digits](https://leetcode.com/problems/add-digits) (Easy)
- [Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits) (Easy)

# [551] Student Attendance Record I

**[string]**

### Statement

You are given a string `s` representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

* `'A'`: Absent.
* `'L'`: Late.
* `'P'`: Present.



The student is eligible for an attendance award if they meet **both** of the following criteria:

* The student was absent (`'A'`) for **strictly** fewer than 2 days **total**.
* The student was **never** late (`'L'`) for 3 or more **consecutive** days.



Return `true` *if the student is eligible for an attendance award, or* `false` *otherwise*.


**Example 1:**

```

**Input:** s = "PPALLP"
**Output:** true
**Explanation:** The student has fewer than 2 absences and was never late 3 or more consecutive days.

```

**Example 2:**

```

**Input:** s = "PPALLL"
**Output:** false
**Explanation:** The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.

```

**Constraints:**
* `1 <= s.length <= 1000`
* `s[i]` is either `'A'`, `'L'`, or `'P'`.


<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    bool checkRecord (string s) {
      int countA = 0, n = s.length();
      
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'A')
          ++countA;
        else if (s[i] == 'L') {
          int j = i;
          while (j < n and s[i] == s[j])
            ++j;
          if (j - i >= 3)
            return false;
          i = j - 1;
        }
      }
      
      return countA < 2;
    }
};
```

<br>

### Statistics

- total accepted: 163331
- total submissions: 339844
- acceptance rate: 48.1%
- likes: 440
- dislikes: 28

<br>

### Similar Problems

- [Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii) (Hard)

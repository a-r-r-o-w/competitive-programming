# [2545] Sort the Students by Their Kth Score



### Statement

There is a class with `m` students and `n` exams. You are given a **0-indexed** `m x n` integer matrix `score`, where each row represents one student and `score[i][j]` denotes the score the `ith` student got in the `jth` exam. The matrix `score` contains **distinct** integers only.

You are also given an integer `k`. Sort the students (i.e., the rows of the matrix) by their scores in the `kth`(**0-indexed**) exam from the highest to the lowest.

Return *the matrix after sorting it.*
**Example 1:**
![](https://assets.leetcode.com/uploads/2022/11/30/example1.png)

```

**Input:** score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
**Output:** [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
**Explanation:** In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
- The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
- The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.

```

**Example 2:**
![](https://assets.leetcode.com/uploads/2022/11/30/example2.png)

```

**Input:** score = [[3,4],[5,6]], k = 0
**Output:** [[5,6],[3,4]]
**Explanation:** In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 5 in exam 0, which is the highest score, so they got first place.
- The student with index 0 scored 3 in exam 0, which is the lowest score, so they got second place.

```

**Constraints:**
* `m == score.length`
* `n == score[i].length`
* `1 <= m, n <= 250`
* `1 <= score[i][j] <= 105`
* `score` consists of **distinct** integers.
* `0 <= k < n`


<br>

### Hints

- Find the row with the highest score in the kth exam and swap it with the first row.
- After fixing the first row, perform the same operation for the rest of the rows, and the matrix's rows will get sorted one by one.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <int>> sortTheStudents (vector <vector <int>>& score, int k) {
      std::sort(score.begin(), score.end(), [&] (auto &l, auto &r) {
        return l[k] > r[k];
      });
      return score;
    }
};
```

<br>

### Statistics

- total accepted: 15187
- total submissions: 17680
- acceptance rate: 85.9%
- likes: 104
- dislikes: 5

<br>

### Similar Problems

- [Erect the Fence](https://leetcode.com/problems/erect-the-fence) (Hard)
- [Custom Sort String](https://leetcode.com/problems/custom-sort-string) (Medium)
- [Sort the People](https://leetcode.com/problems/sort-the-people) (Easy)

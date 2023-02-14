# [2512] Reward Top K Students



### Statement

You are given two string arrays `positive_feedback` and `negative_feedback`, containing the words denoting positive and negative feedback, respectively. Note that **no** word is both positive and negative.

Initially every student has `0` points. Each positive word in a feedback report **increases** the points of a student by `3`, whereas each negative word **decreases** the points by `1`.

You are given `n` feedback reports, represented by a **0-indexed** string array `report`and a **0-indexed** integer array `student_id`, where `student_id[i]` represents the ID of the student who has received the feedback report `report[i]`. The ID of each student is **unique**.

Given an integer `k`, return *the top* `k` *students after ranking them in **non-increasing** order by their points*. In case more than one student has the same points, the one with the lower ID ranks higher.


**Example 1:**

```

**Input:** positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
**Output:** [1,2]
**Explanation:** 
Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.

```

**Example 2:**

```

**Input:** positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
**Output:** [2,1]
**Explanation:** 
- The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points. 
- The student with ID 2 has 1 positive feedback, so he has 3 points. 
Since student 2 has more points, [2,1] is returned.

```

**Constraints:**
* `1 <= positive_feedback.length, negative_feedback.length <= 104`
* `1 <= positive_feedback[i].length, negative_feedback[j].length <= 100`
* Both `positive_feedback[i]` and `negative_feedback[j]` consists of lowercase English letters.
* No word is present in both `positive_feedback` and `negative_feedback`.
* `n == report.length == student_id.length`
* `1 <= n <= 104`
* `report[i]` consists of lowercase English letters and spaces `' '`.
* There is a single space between consecutive words of `report[i]`.
* `1 <= report[i].length <= 100`
* `1 <= student_id[i] <= 109`
* All the values of `student_id[i]` are **unique**.
* `1 <= k <= n`


<br>

### Hints

- Hash the positive and negative feedback words separately.
- Calculate the points for each student’s feedback.
- Sort the students accordingly to find the top <em>k</em> among them.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <int> topStudents (vector <string>& positive_feedback, vector <string>& negative_feedback, vector <string>& report, vector <int>& student_id, int k) {
      std::unordered_set <std::string> pos (positive_feedback.begin(), positive_feedback.end());
      std::unordered_set <std::string> neg (negative_feedback.begin(), negative_feedback.end());
      std::vector <std::pair <int, int>> scores;
      std::string x;
      int index = 0;
      
      for (auto &s: report) {
        std::stringstream stream (s);
        int score = 0;
        
        while (stream >> x) {
          if (pos.count(x))
            score += 3;
          else if (neg.count(x))
            score -= 1;
        }
        
        scores.push_back({score, student_id[index]});
        ++index;
      }
      
      std::sort(scores.begin(), scores.end(), [] (auto &l, auto &r) {
        if (l.first > r.first)
          return true;
        if (l.first < r.first)
          return false;
        return l.second < r.second;
      });
      
      std::vector <int> ans;
      
      for (int i = 0; i < k; ++i)
        ans.push_back(scores[i].second);
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 6666
- total submissions: 15816
- acceptance rate: 42.1%
- likes: 77
- dislikes: 15

<br>

### Similar Problems

- [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height) (Medium)
- [K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range) (Medium)

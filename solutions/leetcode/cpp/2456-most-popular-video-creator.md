# [2456] Most Popular Video Creator



### Statement

You are given two string arrays `creators` and `ids`, and an integer array `views`, all of length `n`. The `ith` video on a platform was created by `creator[i]`, has an id of `ids[i]`, and has `views[i]` views.

The **popularity** of a creator is the **sum** of the number of views on **all** of the creator's videos. Find the creator with the **highest** popularity and the id of their **most** viewed video.

* If multiple creators have the highest popularity, find all of them.
* If multiple videos have the highest view count for a creator, find the lexicographically **smallest** id.



Return *a 2D array of strings* `answer` *where* `answer[i] = [creatori, idi]` *means that* `creatori` *has the **highest** popularity and* `idi` *is the id of their most popular video.* The answer can be returned in any order.


**Example 1:**

```

**Input:** creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
**Output:** [["alice","one"],["bob","two"]]
**Explanation:**
The popularity of alice is 5 + 5 = 10.
The popularity of bob is 10.
The popularity of chris is 4.
alice and bob are the most popular creators.
For bob, the video with the highest view count is "two".
For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.

```

**Example 2:**

```

**Input:** creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
**Output:** [["alice","b"]]
**Explanation:**
The videos with id "b" and "c" have the highest view count.
Since "b" is lexicographically smaller than "c", it is included in the answer.

```

**Constraints:**
* `n == creators.length == ids.length == views.length`
* `1 <= n <= 105`
* `1 <= creators[i].length, ids[i].length <= 5`
* `creators[i]` and `ids[i]` consist only of lowercase English letters.
* `0 <= views[i] <= 105`


<br>

### Hints

- Use a hash table to store and categorize videos based on their creator.
- For each creator, iterate through all their videos and use three variables to keep track of their popularity, their most popular video, and the id of their most popular video.

<br>

### Solution

```cpp
class Solution {
  public:
    vector <vector <string>> mostPopularCreator (vector <string>& creators, vector <string>& ids, vector <int>& views) {
      int n = creators.size();
      std::map <std::string, std::vector <std::pair <int, std::string>>> have;
      
      for (int i = 0; i < n; ++i)
        have[creators[i]].push_back({views[i], ids[i]});
      
      int64_t max = 0;
      std::vector <std::vector <std::string>> ans;
      
      for (auto &[p, q]: have)
        std::sort(q.begin(), q.end(), [&] (auto &l, auto &r) {
          if (l.first < r.first)
            return true;
          if (l.first > r.first)
            return false;
          return l.second > r.second;
        });
      
      for (auto &[p, q]: have) {
        int64_t sum = 0;
        
        for (auto &[x, y]: q)
          sum += x;
        
        if (sum >= max) {
          if (sum != max)
            ans.clear();
          max = sum;
          ans.push_back({p, q.back().second});
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 10624
- total submissions: 28861
- acceptance rate: 36.8%
- likes: 83
- dislikes: 236

<br>

### Similar Problems

- [Design Video Sharing Platform](https://leetcode.com/problems/design-video-sharing-platform) (Hard)
- [Design a Food Rating System](https://leetcode.com/problems/design-a-food-rating-system) (Medium)

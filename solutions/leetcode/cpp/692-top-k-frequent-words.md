# [692] Top K Frequent Words

**[hash-table, string, trie, sorting, heap-priority-queue, bucket-sort, counting]**

### Statement

Given an array of strings `words` and an integer `k`, return *the* `k` *most frequent strings*.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.


**Example 1:**

```

**Input:** words = ["i","love","leetcode","i","love","coding"], k = 2
**Output:** ["i","love"]
**Explanation:** "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

```

**Example 2:**

```

**Input:** words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
**Output:** ["the","is","sunny","day"]
**Explanation:** "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

```

**Constraints:**
* `1 <= words.length <= 500`
* `1 <= words[i].length <= 10`
* `words[i]` consists of lowercase English letters.
* `k` is in the range `[1, The number of **unique** words[i]]`


**Follow-up:** Could you solve it in `O(n log(k))` time and `O(n)` extra space?

<br>

### Hints

None

<br>

### Solution

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    vector <string> topKFrequent (vector <string>& words, int k) {
      std::map <std::string, int> freq;
      
      for (auto &word: words)
        ++freq[word];
      
      std::map <int, std::vector <std::string>> freq_inv;
      
      for (auto &[x, y]: freq)
        freq_inv[-y].push_back(x);
      
      std::vector <std::string> ans;
      
      for (auto &[x, y]: freq_inv) {
        if (k <= 0)
          break;
        
        for (auto &s: y) {
          if (k <= 0)
            break;
          --k;
          ans.push_back(s);
        }
      }
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 426540
- total submissions: 774496
- acceptance rate: 55.1%
- likes: 5159
- dislikes: 271

<br>

### Similar Problems

- [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) (Medium)
- [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) (Medium)
- [Sort Features by Popularity](https://leetcode.com/problems/sort-features-by-popularity) (Medium)
- [Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count) (Medium)
- [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array) (Easy)

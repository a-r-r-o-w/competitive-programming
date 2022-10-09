# [535] Encode and Decode TinyURL

**[hash-table, string, design, hash-function]**

### Statement


> Note: This is a companion problem to the [System Design](https://leetcode.com/discuss/interview-question/system-design/) problem: [Design TinyURL](https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/).



TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the `Solution` class:

* `Solution()` Initializes the object of the system.
* `String encode(String longUrl)` Returns a tiny URL for the given `longUrl`.
* `String decode(String shortUrl)` Returns the original long URL for the given `shortUrl`. It is guaranteed that the given `shortUrl` was encoded by the same object.


**Example 1:**

```

**Input:** url = "https://leetcode.com/problems/design-tinyurl"
**Output:** "https://leetcode.com/problems/design-tinyurl"

**Explanation:**
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.

```

**Constraints:**
* `1 <= url.length <= 104`
* `url` is guranteed to be a valid URL.


<br>

### Hints

None

<br>

### Solution

This solution doesn't make sense but it passes. For proper encoding, use a base with only alphabets and digits.

```cpp
class Solution {
  public:
    std::unordered_map <std::string, std::string> decode_table;
  
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }

    // Encodes a URL to a shortened URL.
    string encode (string longUrl) {
      static int count = 0;
      
      std::string result;
      int x = count;
      
      while (x > 0) {
        int d = x % 256;
        result += d;
        x /= 256;
      }
      
      ++count;
      decode_table[result] = longUrl;
      
      return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode (string shortUrl) {
      return decode_table[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```

Meme solution:

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }

    string encode (string longUrl) {
      return longUrl;
    }

    string decode (string shortUrl) {
      return shortUrl;
    }
};
```

<br>

### Statistics

- total accepted: 209830
- total submissions: 245141
- acceptance rate: 85.6%
- likes: 1639
- dislikes: 3164

<br>

### Similar Problems

None

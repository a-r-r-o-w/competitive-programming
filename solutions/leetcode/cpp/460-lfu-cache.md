# [460] LFU Cache

**[hash-table, linked-list, design, doubly-linked-list]**

### Statement

Design and implement a data structure for a [Least Frequently Used (LFU)](https://en.wikipedia.org/wiki/Least_frequently_used) cache.

Implement the `LFUCache` class:

* `LFUCache(int capacity)` Initializes the object with the `capacity` of the data structure.
* `int get(int key)` Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns `-1`.
* `void put(int key, int value)` Update the value of the `key` if present, or inserts the `key` if not already present. When the cache reaches its `capacity`, it should invalidate and remove the **least frequently used** key before inserting a new item. For this problem, when there is a **tie** (i.e., two or more keys with the same frequency), the **least recently used** `key` would be invalidated.



To determine the least frequently used key, a **use counter** is maintained for each key in the cache. The key with the smallest **use counter** is the least frequently used key.

When a key is first inserted into the cache, its **use counter** is set to `1` (due to the `put` operation). The **use counter** for a key in the cache is incremented either a `get` or `put` operation is called on it.

The functions`get`and`put`must each run in `O(1)` average time complexity.


**Example 1:**

```

**Input**
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
**Output**
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

**Explanation**
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

```

**Constraints:**
* `0 <= capacity<= 10^4`
* `0 <= key <= 10^5`
* `0 <= value <= 10^9`
* At most `2 * 10^5`calls will be made to `get` and `put`.




<br />

### Hints

None

<br />

### Solution

```cpp
class LFUCache {
  using lru_list = std::list <std::pair <int, int>>;

  int max_size;
  int min_freq;

  // maps key to (frequency, lru_list_iterator)
  std::unordered_map <int, std::pair <int, lru_list::iterator>> cache;

  // maps frequency to lru_list for multiple keys having same frequency
  std::unordered_map <int, lru_list> freq;

  public:
    LFUCache (int capacity) {
      max_size = capacity;
      min_freq = 0;
    }
    
    int get (int key) {
      auto f = cache.find(key);
      
      if (f == cache.end())
        return -1;
      
      auto [key_freq, key_iterator] = f->second;
      auto [_, value] = *key_iterator;

      freq[key_freq].erase(key_iterator);

      if (min_freq == key_freq and freq[key_freq].empty())
        ++min_freq;
      
      ++key_freq;
      freq[key_freq].push_back({key, value});
      cache[key] = {key_freq, std::prev(freq[key_freq].end())};
      
      return value;
    }
    
    void put (int key, int value) {
      if (max_size <= 0)
        return;
      
      auto f = cache.find(key);

      if (f != cache.end()) {
        auto &[key_freq, key_iterator] = f->second;
        auto &[_, oldvalue] = *key_iterator;
        oldvalue = value;
        get(key);
        return;
      }

      if ((int)cache.size() == max_size) {
        cache.erase(freq[min_freq].front().first);
        freq[min_freq].pop_front();
      }

      min_freq = 1;
      freq[min_freq].push_back({key, value});
      cache[key] = {min_freq, std::prev(freq[min_freq].end())};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

<br />

### Statistics

- total accepted: 203621
- total submissions: 478554
- acceptance rate: 42.5%
- likes: 4680
- dislikes: 291

<br />

### Similar Problems

- [LRU Cache](https://leetcode.com/problems/lru-cache) (Medium)
- [Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system) (Hard)

# [146] LRU Cache

**[hash-table, linked-list, design, doubly-linked-list]**

### Statement

Design a data structure that follows the constraints of a **[Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)**.

Implement the `LRUCache` class:

* `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
* `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
* `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.



The functions `get` and `put` must each run in `O(1)` average time complexity.


**Example 1:**

```

**Input**
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
**Output**
[null, null, null, 1, null, -1, null, -1, 3, 4]

**Explanation**
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

```

**Constraints:**
* `1 <= capacity <= 3000`
* `0 <= key <= 10^4`
* `0 <= value <= 10^5`
* At most `2 * 10^5` calls will be made to `get` and `put`.


<br />

### Hints

None

<br />

### Solution

```cpp
class LRUCache {
    using p = std::pair <int, int>;
    int capacity;
    std::unordered_map <int, std::list <p>::iterator> map;
    std::list <p> list;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }
    
    int get(int key) {
      if (map.count(key)) {
        int value = map[key]->second;
        list.erase(map[key]);
        list.emplace_front(key, value);
        map[key] = list.begin();
        return value;
      }
      return -1;
    }
    
    void put(int key, int value) {
      if (map.count(key)) {
        list.erase(map[key]);
        list.emplace_front(key, value);
        map[key] = list.begin();
      }
      else {
        if ((int)map.size() >= capacity) {
          map.erase(list.back().first);
          list.pop_back();
        }
        list.emplace_front(key, value);
        map[key] = list.begin();
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

<br />

### Statistics

- total accepted: 1374502
- total submissions: 3324692
- acceptance rate: 41.3%
- likes: 18530
- dislikes: 828

<br />

### Similar Problems

- [LFU Cache](https://leetcode.com/problems/lfu-cache) (Hard)
- [Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system) (Hard)
- [Design Compressed String Iterator](https://leetcode.com/problems/design-compressed-string-iterator) (Easy)
- [Design Most Recently Used Queue](https://leetcode.com/problems/design-most-recently-used-queue) (Medium)

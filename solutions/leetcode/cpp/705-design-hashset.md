# [705] Design HashSet

**[array, hash-table, linked-list, design, hash-function]**

### Statement

Design a HashSet without using any built-in hash table libraries.

Implement `MyHashSet` class:

* `void add(key)` Inserts the value `key` into the HashSet.
* `bool contains(key)` Returns whether the value `key` exists in the HashSet or not.
* `void remove(key)` Removes the value `key` in the HashSet. If `key` does not exist in the HashSet, do nothing.


**Example 1:**

```

**Input**
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
**Output**
[null, null, null, true, false, null, true, null, false]

**Explanation**
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
```

**Constraints:**
* `0 <= key <= 10^6`
* At most `10^4` calls will be made to `add`, `remove`, and `contains`.


<br />

### Hints

None

<br />

### Solution

```cpp
class MyHashSet {
    std::unordered_set <int> have;
  public:
    MyHashSet() {
      
    }
    
    void add (int key) {
      have.insert(key);
    }
    
    void remove (int key) {
      have.erase(key);
    }
    
    bool contains (int key) {
      return have.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

<br />

### Statistics

- total accepted: 335929
- total submissions: 498971
- acceptance rate: 67.3%
- likes: 3324
- dislikes: 271

<br />

### Similar Problems

- [Design HashMap](https://leetcode.com/problems/design-hashmap) (Easy)
- [Design Skiplist](https://leetcode.com/problems/design-skiplist) (Hard)

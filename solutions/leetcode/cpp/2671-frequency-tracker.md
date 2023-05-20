# [2671] Frequency Tracker



### Statement

Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.

Implement the `FrequencyTracker` class.

* `FrequencyTracker()`: Initializes the `FrequencyTracker` object with an empty array initially.
* `void add(int number)`: Adds `number` to the data structure.
* `void deleteOne(int number)`: Deletes **one** occurence of `number` from the data structure. The data structure **may not contain** `number`, and in this case nothing is deleted.
* `bool hasFrequency(int frequency)`: Returns `true` if there is a number in the data structure that occurs `frequency` number of times, otherwise, it returns `false`.


**Example 1:**

```

**Input**
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
**Output**
[null, null, null, true]

**Explanation**
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.add(3); // The data structure now contains [3, 3]
frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice


```

**Example 2:**

```

**Input**
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
**Output**
[null, null, null, false]

**Explanation**
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // The data structure now contains [1]
frequencyTracker.deleteOne(1); // The data structure becomes empty []
frequencyTracker.hasFrequency(1); // Returns false, because the data structure is empty


```

**Example 3:**

```

**Input**
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
**Output**
[null, false, null, true]

**Explanation**
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // Returns false, because the data structure is empty
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.hasFrequency(1); // Returns true, because 3 occurs once


```

**Constraints:**
* `1 <= number <= 10^5`
* `1 <= frequency <= 10^5`
* At most, `2 *10^5`calls will be made to `add`, `deleteOne`, and `hasFrequency`in **total**.


<br />

### Hints

- Put all the numbers in a hash map (or just an integer array given the number range is small) to maintain each number’s frequency dynamically.
- Put each frequency in another hash map (or just an integer array given the range is small, note there are only 200000 calls in total) to maintain each kind of frequency dynamically.
- Keep the 2 hash maps in sync.

<br />

### Solution

```cpp
class FrequencyTracker {
    std::unordered_map <int, int> freq;
    std::unordered_multiset <int> have;
  
  public:
    FrequencyTracker () {
        
    }
    
    void add (int number) {
      if (freq.count(number))
        have.erase(have.find(freq[number]));
      ++freq[number];
      have.insert(freq[number]);
    }
    
    void deleteOne (int number) {
      if (freq.count(number))
        have.erase(have.find(freq[number]));
      else
        return;
      --freq[number];
      if (freq[number] > 0)
        have.insert(freq[number]);
      else
        freq.erase(number);
    }
    
    bool hasFrequency (int frequency) {
      return have.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
```

<br />

### Statistics

- total accepted: 11126
- total submissions: 42033
- acceptance rate: 26.5%
- likes: 143
- dislikes: 12

<br />

### Similar Problems

None

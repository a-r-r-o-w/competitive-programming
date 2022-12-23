# [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

**[array, queue, sliding-window, heap-priority-queue, ordered-set, monotonic-queue]**

### Statement

Given an array of integers `nums` and an integer `limit`, return the size of the longest **non-empty** subarray such that the absolute difference between any two elements of this subarray is less than or equal to `limit`*.*
**Example 1:**

```

**Input:** nums = [8,2,4,7], limit = 4
**Output:** 2 
**Explanation:** All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

```

**Example 2:**

```

**Input:** nums = [10,1,2,4,7,2], limit = 5
**Output:** 4 
**Explanation:** The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

```

**Example 3:**

```

**Input:** nums = [4,2,2,2,4,4,2,2], limit = 0
**Output:** 3

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `0 <= limit <= 109`


<br>

### Hints

- Use a sliding window approach keeping the maximum and minimum value using a data structure like a multiset from STL in C++.
- More specifically, use the two pointer technique, moving the right pointer as far as possible to the right until the subarray is not valid (maxValue - minValue > limit), then moving the left pointer until the subarray is valid again (maxValue - minValue <= limit). Keep repeating this process.

<br>

### Solution

```cpp
namespace arrow {
  enum class tree_memory_layout {
    binary,
    euler_tour
  };

  template <
    class Type,
    tree_memory_layout impl_type = tree_memory_layout::binary
  >
  class segment_tree {
    private:
      std::vector <Type> tree;
      
      int base_size;
      const std::vector <Type>& base_ref;

      Type (*combine) (const Type&, const Type&);

    public:
      segment_tree (int base_size, const std::vector <Type>& base, Type (*combine) (const Type&, const Type&))
        : base_size (base_size),
          base_ref (base),
          combine (combine) {
        if constexpr (impl_type == tree_memory_layout::binary)
          tree.resize(4 * base_size, Type{});
        else
          tree.resize(2 * base_size, Type{});
        _build_impl(0, 0, base_size - 1);
      }

      void point_update (int position, const Type& value)
      { _point_update_impl(0, 0, base_size - 1, position, value); }

      Type point_query (int position)
      { return _point_query_impl(0, 0, base_size - 1, position); }

      Type range_query (int l, int r)
      { return _range_query_impl(0, 0, base_size - 1, l, r); }

      template <typename... ParamTypes>
      void custom_point_update (int position, const ParamTypes&... params)
      { _custom_point_update_impl(0, 0, base_size - 1, position, params...); }

      template <typename ReturnType, typename... ParamTypes>
      ReturnType custom_query (const ParamTypes&... params)
      { return _custom_query_impl <ReturnType> (0, 0, base_size - 1, params...); }

    private:
      int _get_leftchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
        if constexpr (impl_type == tree_memory_layout::binary)
          return 2 * v + 1;
        else
          return v + 1;
      }

      int _get_rightchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
        if constexpr (impl_type == tree_memory_layout::binary)
          return 2 * v + 2;
        else {
          int tm = (tl + tr) / 2;
          int node_count = tm - tl + 1;
          return v + 2 * node_count;
        }
      }

      void _build_impl (int v, int tl, int tr) {
        if (tl == tr) {
          tree[v] = base_ref[tl];
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        _build_impl(lchild, tl, tm);
        _build_impl(rchild, tm + 1, tr);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      void _point_update_impl (int v, int tl, int tr, int position, const Type& value) {
        if (tl == tr) {
          tree[v] = value;
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);
        
        if (position <= tm)
          _point_update_impl(lchild, tl, tm, position, value);
        else
          _point_update_impl(rchild, tm + 1, tr, position, value);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      Type _point_query_impl (int v, int tl, int tr, int position) {
        if (tl == tr)
          return tree[v];
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);
        
        if (position <= tm)
          return _point_query_impl(lchild, tl, tm, position);
        else
          return _point_query_impl(rchild, tm + 1, tr, position);
      }

      Type _range_query_impl (int v, int tl, int tr, int l, int r) {
        if (l > r)
          return {};
        
        if (tl == l and tr == r)
          return tree[v];
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        Type lval = _range_query_impl(lchild, tl, tm, l, std::min(r, tm));
        Type rval = _range_query_impl(rchild, tm + 1, tr, std::max(l, tm + 1), r);
        
        return combine(lval, rval);
      }

      void _custom_point_update_impl (int v, int tl, int tr, int position) {
        if (tl == tr) {
          throw std::runtime_error("undefined implementation");
          return;
        }

        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        if (position <= tm)
          _custom_point_update_impl(lchild, tl, tm, position);
        else
          _custom_point_update_impl(rchild, tm + 1, tr, position);
        
        tree[v] = combine(tree[lchild], tree[rchild]);
      }

      template <typename ReturnType>
      ReturnType _custom_query_impl (int v, int tl, int tr) {
        if (tl == tr) {
          throw std::runtime_error("undefined implementation");
          return ReturnType{};
        }
        
        int tm = (tl + tr) / 2;
        int lchild = _get_leftchild(v, tl, tr);
        int rchild = _get_rightchild(v, tl, tr);

        if (true)
          return _custom_query_impl <ReturnType> (lchild, tl, tm);
        else
          return _custom_query_impl <ReturnType> (rchild, tm + 1, tr);
      }
  };
};

class Solution {
  public:
    int longestSubarray (vector <int>& nums, int limit) {
      constexpr int inf32 = 1 << 30;

      struct node {
        int min = inf32;
        int max = -inf32;
      };

      int n = nums.size(), ans = 0, l = 0, r = 0;
      std::vector <node> nodes (n);

      for (int i = 0; i < n; ++i) {
        nodes[i].min = nums[i];
        nodes[i].max = nums[i];
      }

      arrow::segment_tree <node> tree (n, nodes, [] (auto l, auto r) {
        node result;
        result.min = std::min(l.min, r.min);
        result.max = std::max(l.max, r.max);
        return result;
      });
      int running_max = -inf32, running_min = inf32;

      while (r < n) {
        running_max = std::max(running_max, nums[r]);
        running_min = std::min(running_min, nums[r]);

        if (running_max - running_min > limit) {
          ans = std::max(ans, r - l);
          
          while (l < r) {
            ++l;
            node result = tree.range_query(l, r);
            if (result.max - result.min <= limit) {
              running_max = result.max;
              running_min = result.min;
              break;
            }
          }
        }
        else
          ++r;
      }

      ans = std::max(ans, r - l);

      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 103870
- total submissions: 215927
- acceptance rate: 48.1%
- likes: 2739
- dislikes: 112

<br>

### Similar Problems

- [Partition Array Such That Maximum Difference Is K](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k) (Medium)
- [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds) (Hard)

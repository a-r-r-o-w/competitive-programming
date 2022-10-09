# [2401] Longest Nice Subarray



### Statement

You are given an array `nums` consisting of **positive** integers.

We call a subarray of `nums` **nice** if the bitwise **AND** of every pair of elements that are in **different** positions in the subarray is equal to `0`.

Return *the length of the **longest** nice subarray*.

A **subarray** is a **contiguous** part of an array.

**Note** that subarrays of length `1` are always considered nice.


**Example 1:**

```

**Input:** nums = [1,3,8,48,10]
**Output:** 3
**Explanation:** The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
```

**Example 2:**

```

**Input:** nums = [3,1,5,11,13]
**Output:** 1
**Explanation:** The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

```

**Constraints:**
* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`


<br>

### Hints

- What is the maximum possible length of a nice subarray?
- The length of the longest nice subarray cannot exceed 30. Why is that?

<br>

### Solution

**Segment Tree**

Overkill! But it's a contest and I have a template ready so why bother? ;)

Use segment tree or BIT to query bitwise OR over ranges.

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
    int longestNiceSubarray (vector <int>& nums) {
      int n = nums.size(), i = 0, j = 0;
      int max = 0;
      std::vector <int64_t> x;
      
      arrow::segment_tree <int, arrow::tree_memory_layout::euler_tour> OR (n, nums, [] (auto l, auto r) {
        return l | r;
      });
      
      while (i < n) {
        while (j <= i and OR.range_query(j, i - 1) & nums[i])
          ++j;
        max = std::max(max, i - j + 1);
        ++i;
      }
      
      return max;
    }
};
```

**Sliding Window**

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int longestNiceSubarray (vector <int>& nums) {
      int n = nums.size(), i = 0, j = 0, OR = 0, max = 0;
      
      while (i < n) {
        while (j <= i and (OR & nums[i])) {
          OR ^= nums[j];
          ++j;
        }
        OR |= nums[i];
        max = std::max(max, i - j + 1);
        ++i;
      }
      
      return max;
    }
};
```

<br>

### Statistics

- total accepted: 7440
- total submissions: 18369
- acceptance rate: 40.5%
- likes: 173
- dislikes: 6

<br>

### Similar Problems

- [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) (Medium)
- [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) (Medium)
- [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-ors-of-subarrays) (Medium)
- [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets) (Medium)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) (Medium)
- [Get Equal Substrings Within Budget](https://leetcode.com/problems/get-equal-substrings-within-budget) (Medium)
- [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element) (Medium)
- [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order) (Medium)
- [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam) (Medium)

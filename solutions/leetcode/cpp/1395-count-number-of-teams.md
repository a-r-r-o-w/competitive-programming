# [1395] Count Number of Teams

**[array, dynamic-programming, binary-indexed-tree]**

### Statement

There are `n` soldiers standing in a line. Each soldier is assigned a **unique** `rating` value.

You have to form a team of 3 soldiers amongst them under the following rules:

* Choose 3 soldiers with index (`i`, `j`, `k`) with rating (`rating[i]`, `rating[j]`, `rating[k]`).
* A team is valid if: (`rating[i] < rating[j] < rating[k]`) or (`rating[i] > rating[j] > rating[k]`) where (`0 <= i < j < k < n`).



Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


**Example 1:**

```

**Input:** rating = [2,5,3,4,1]
**Output:** 3
**Explanation:** We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

```

**Example 2:**

```

**Input:** rating = [2,1,3]
**Output:** 0
**Explanation:** We can't form any team given the conditions.

```

**Example 3:**

```

**Input:** rating = [1,2,3,4]
**Output:** 4

```

**Constraints:**
* `n == rating.length`
* `3 <= n <= 1000`
* `1 <= rating[i] <= 105`
* All the integers in `rating` are **unique**.


<br>

### Hints

- BruteForce, check all possibilities.

<br>

### Solution

Counting smaller values to the left and larger values to the right for each element.

O(n^2)

```cpp
class Solution {
  public:
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numTeams (vector <int>& rating) {
      int n = rating.size();
      int64_t ans = 0;
      
      auto f = [&] () {
        for (int i = 0; i < n; ++i) {
          int smaller = 0, larger = 0;

          for (int j = 0; j < i; ++j) {
            if (rating[j] < rating[i])
              ++smaller;
          }

          for (int j = i + 1; j < n; ++j) {
            if (rating[j] > rating[i])
              ++larger;
          }

          ans += smaller * larger;
        }
      };
      
      f();
      std::reverse(rating.begin(), rating.end());
      f();
      
      return ans;
    }
};
```

Using segment tree to find lower and higher count

O(n.log(max)) time and space complexity where max is the biggest possible value a<sub>i</sub> (1e5 here).

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
    Solution () {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    }
  
    int numTeams (vector <int>& rating) {
      int n = rating.size();
      int64_t ans = 0;
      
      auto f = [&] () {
        const int max = 100000 + 1;
        
        struct node {
          int smaller = 0;
          int larger = 0;
        };
        
        arrow::segment_tree <node, arrow::tree_memory_layout::euler_tour> tree (
          max, std::vector <node> (max), [] (auto &l, auto &r) {
            node result;
            result.smaller = l.smaller + r.smaller;
            result.larger = l.larger + r.larger;
            return result;
          }
        );
        
        for (int i = 0; i < n; ++i)
          tree.point_update(rating[i], {0, 1});
        
        for (int i = 0; i < n; ++i) {
          node s = tree.range_query(0, rating[i] - 1);
          node l = tree.range_query(rating[i] + 1, max - 1);
          ans += s.smaller * l.larger;
          tree.point_update(rating[i], {1, 0});
        }
      };
      
      f();
      std::reverse(rating.begin(), rating.end());
      f();
      
      return ans;
    }
};
```

<br>

### Statistics

- total accepted: 92618
- total submissions: 135158
- acceptance rate: 68.5%
- likes: 2134
- dislikes: 167

<br>

### Similar Problems

None

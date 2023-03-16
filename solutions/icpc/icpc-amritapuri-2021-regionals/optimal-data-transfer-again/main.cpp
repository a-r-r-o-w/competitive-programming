/* Arrow */

#ifdef LOST_IN_SPACE
#  if   __cplusplus > 201703LL
#    include "lost_pch1.h" // C++20
#  elif __cplusplus > 201402LL
#    include "lost_pch2.h" // C++17
#  else
#    include "lost_pch3.h" // C++14
#  endif
#else
#  include <bits/stdc++.h>
#endif

constexpr bool is_multitest = true;
constexpr int32_t inf32 = int32_t(1) << 30;
constexpr int64_t inf64 = int64_t(1) << 60;

void solve ([[maybe_unused]] int _t) {
  int n, m;
  std::cin >> n >> m;

  std::vector <std::string> s (n);
  for (int i = 0; i < n; ++i)
    std::cin >> s[i];
  std::vector <std::tuple <int, int, int>> edges;
  
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int diff = 0;
      for (int k = 0; k < m; ++k) {
        if (s[i][k] != s[j][k])
          ++diff;
      }
      edges.emplace_back(diff, i, j);
    }
  }

  std::vector <int> parent (n), rank (n);
  int64_t ans = 0;

  std::iota(parent.begin(), parent.end(), 0);
  std::sort(edges.begin(), edges.end());

  auto find = [&] (auto self, int u) -> int {
    return parent[u] = u == parent[u] ? u : self(self, parent[u]);
  };

  auto unite = [&] (int u, int v, int w) {
    u = find(find, u);
    v = find(find, v);
    if (u == v)
      return;
    if (rank[u] < rank[v])
      std::swap(u, v);
    parent[v] = u;
    ++rank[u];
    ans += w;
  };

  for (auto &[w, u, v]: edges)
    unite(u, v, w);
  
  std::cout << s.front().size() + ans << '\n';
}

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int cases = 1;
  if (is_multitest)
    std::cin >> cases;
  for (int i = 0; i < cases; ++i)
    solve(i);

  return 0;
}


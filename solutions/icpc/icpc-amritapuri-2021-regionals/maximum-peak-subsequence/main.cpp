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
  int n, k;
  std::cin >> n >> k;

  std::vector <int> p (n);
  for (int i = 0; i < n; ++i)
    std::cin >> p[i];
  
  std::vector <int> peaks;
  for (int i = 1; i < n - 1; ++i) {
    if (p[i - 1] < p[i] and p[i + 1] < p[i])
      peaks.push_back(i);
  }

  if (peaks.empty()) {
    for (int i = 0; i < k; ++i)
      std::cout << p[i] << ' ';
    std::cout << '\n';
    return;
  }

  // i need 2x+1 values to have x peaks
  int count = 1;
  std::set <int> ans;
  
  ans.insert(peaks[0] - 1);

  if (count < k) {
    ans.insert(peaks[0]);
    ++count;
  }

  for (int i = 1; i < (int)peaks.size() and count < k; ++i) {
    bool found = false;
    for (int j = peaks[i - 1] + 1; j < peaks[i]; ++j) {
      if (p[j] < p[peaks[i - 1]] and p[j] < p[peaks[i]]) {
        ans.insert(j);
        ++count;
        found = true;
        break;
      }
    }
    if (not found)
      throw std::runtime_error("retard");
    if (count < k) {
      ans.insert(peaks[i]);;
      ++count;
    }
  }

  for (int i = peaks.back() + 1; i < n and count < k; ++i) {
    ans.insert(i);
    ++count;
  }

  for (int i = 0; i < n and count < k; ++i) {
    if (ans.count(i))
      continue;
    ans.insert(i);
    ++count;
  }

  for (int i: ans)
    std::cout << p[i] << ' ';

  std::cout << '\n';
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

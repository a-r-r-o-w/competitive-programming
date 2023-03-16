# Maximum Peak Subsequence

In a sequence `X[1], X[2], ... X[M]` with `M ≥ 3`, a peak is an index `2 ≤ i ≤ M - 1`, such that `X[i] > X[i - 1]` and `X[i] > X[i + 1]`.

You are given a permutation `P[1], P[2], ..., P[N]` and an integer `3 ≤ K ≤ N`. Find a subsequence of `P` of size `K`, with the maximum possible number of peaks. If there are multiple such subsequences, you can output any of them.

### Input Format

The first line contains `T`, the number of test cases. Then the testcases follow. For each test case,
- The first line contains `N` and `K` respectively.
- The second line contains N space separated integers `P[1], P[2], ..., P[N]`.

### Output Format

- `1 ≤ T ≤ 100000`
- `3 ≤ K ≤ N ≤ 500000`
- The sum of N over all testcases doesn't exceed 500000.
- `1 ≤ P[i] ≤ N`, and all values in `P` are distinct.

### Sample 0

**Input**

```
2
4 3
1 4 3 2
6 4
1 2 3 4 5 6
```

**Output**

```
1 4 2
1 2 3 4
```

**Explanation**

In the first testcase, there are following four subsequences of length 3
- 1, 4, 3 with 1 peak
- 1, 4, 2 with 1 peak
- 1, 3, 2 with 1 peak
- 4, 3, 2 with 0 peaks

Either of the first three subsequences is considered correct
- In the second testcase, any subsequence has 0 peaks.

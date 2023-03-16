# Optimal Data Transfer Again

Bob has `N` binary strings, each of length `M` on one of his servers `A` and wants to send all of them to his another server `B` one by one.

In one move, Bob can select a string and pay some cost for sending the entire string. He can decide to pay one of the following costs to send the string `X`:

- He can pay `1` Rupee per bit and hence spend `M` Rupees.
- He can intelligently select a string `Y` that was already sent in one of the previous moves, and pay cost equal to the diff between `Y` and `X`. The diff between two strings `X` and `Y` is defined as the number of indices `i` (`1 <= i <= M`) such that `X[i] ≠ Y[i]`.
Find the minimum cost to send all the strings to server B.

**Note:** While sending the first string, Bob has only one option - that is, to pay `M` rupees to send the string as no other string has been sent to server `B` yet.

### Input

The first line contains `T` - the number of testcases. The format of each testcase is as follows:
- The first line contains two space-separated integers: `N` and `M`, denoting the number of binary strings and the length of each binary string respectively.
- `N` lines follow, each containing a string of M characters, each denoting a binary string containing 0s and 1s.

### Output

For each testcase, print the minimum cost to send all strings to Server `B` on a new line.

### Constraints

- `1 <= T <= 100`
- `1 <= N <= 10^3`
- `1 <= M <= 100`

Sum of `N` across all testcases is <= `10^3`.

### Sample

**Input**

```
2
3 3
011
011
111
5 8
01101111
11100100
00010110
01111010
10110110
```

**Output**

```
4
20
```

**Explanation**

In the first testcase:

- We can first send the `111` string with cost `3` Rupees.
- The second string to be sent can be one of the `011` strings, which will be sent with cost `1` Rupee, as the diff of `111` and `011` is (`1 + 0 + 0`), which is equal to `1`.
- The third string can be the remaining `011` string. This will be sent with cost `0` Rupees. This is because it can be diff-ed with the second string that was sent earlier (`011`). This is optimal, compared to diff-ing with `111` which would incur a cost of `1` Rupee.

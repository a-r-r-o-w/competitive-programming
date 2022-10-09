# [195] Tenth Line

**[shell]**

### Statement

Given a text file`file.txt`, printjust the 10th line of thefile.

**Example:**

Assume that `file.txt` has the following content:


```

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10

```


Your script should output the tenth line, which is:


```

Line 10

```

**Note:**  

1. If the file contains less than 10 lines, what should you output?  

2. There's at least three different solutions. Try to explore all possibilities.

<br>

### Hints

None

<br>

### Solution

```cpp
cat file.txt | head -n 10 | tail -n +10
```

<br>

### Statistics

- total accepted: 77601
- total submissions: 236282
- acceptance rate: 32.8%
- likes: 283
- dislikes: 372

<br>

### Similar Problems

None

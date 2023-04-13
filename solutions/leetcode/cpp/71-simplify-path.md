# [71] Simplify Path

**[string, stack]**

### Statement

Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.

In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.

The **canonical path** should have the following format:

* The path starts with a single slash `'/'`.
* Any two directories are separated by a single slash `'/'`.
* The path does not end with a trailing `'/'`.
* The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`)



Return *the simplified **canonical path***.


**Example 1:**

```

**Input:** path = "/home/"
**Output:** "/home"
**Explanation:** Note that there is no trailing slash after the last directory name.

```

**Example 2:**

```

**Input:** path = "/../"
**Output:** "/"
**Explanation:** Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

```

**Example 3:**

```

**Input:** path = "/home//foo/"
**Output:** "/home/foo"
**Explanation:** In the canonical path, multiple consecutive slashes are replaced by a single one.

```

**Constraints:**
* `1 <= path.length <= 3000`
* `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`.
* `path` is a valid absolute Unix path.


<br />

### Hints

None

<br />

### Solution

```cpp
class Solution {
  public:
    string simplifyPath (string path) {
      int n = path.length();
      std::string result;

      if (path.front() != '/')
        result += '/';

      for (int i = 0; i < n; ++i) {
        if (path[i] == '/') {
          int j = i;
          while (j < n and path[j] == '/')
            ++j;
          i = j - 1;
          if (result.empty() or result.back() != '/')
            result += '/';
        }
        else if (path[i] == '.') {
          int j = i;
          while (j < n and path[j] == '.')
            ++j;
          int count = j - i;
          i = j - 1;
          if (count == 1) {
            if (i + 1 < n and path[i + 1] != '/')
              result += std::string(count, '.');
          }
          else if (count == 2) {
            if (i + 1 < n and path[i + 1] != '/')
              result += std::string(count, '.');
            else {
              int removed = 0;
              while (int(result.size()) > 1 and (result.back() != '/' or removed == 0)) {
                result.pop_back();
                ++removed;
              }
            }
          }
          else if (count > 2)
            result += std::string(count, '.');
        }
        else {
          int j = i;
          while (j < n and path[j] != '/') {
            result += path[j];
            ++j;
          }
          i = j - 1;
        }
      }

      if (int(result.size()) > 1 and result.back() == '/')
        result.pop_back();

      return result;
    }
};
```

<br />

### Statistics

- total accepted: 507847
- total submissions: 1282342
- acceptance rate: 39.6%
- likes: 3506
- dislikes: 687

<br />

### Similar Problems

None

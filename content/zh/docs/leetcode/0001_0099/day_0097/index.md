---
title: "day_0097 "
date: 2025-09-13T20:29:55+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---


{{< katex />}}


## LeetCode_0097 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i >= m and j >= n:
                return True
            k = i + j
            if i < m and s1[i] == s3[k] and dfs(i + 1, j):
                return True
            if j < n and s2[j] == s3[k] and dfs(i, j + 1):
                return True
            return False

        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        return dfs(0, 0)
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<int>> f(m + 1, vector<int>(n + 1, -1));
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i >= m && j >= n) {
                return true;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            f[i][j] = 0;
            int k = i + j;
            if (i < m && s1[i] == s3[k] && dfs(i + 1, j)) {
                f[i][j] = 1;
            }
            if (!f[i][j] && j < n && s2[j] == s3[k] && dfs(i, j + 1)) {
                f[i][j] = 1;
            }
            return f[i][j] == 1;
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Map<List<Integer>, Boolean> f = new HashMap<>();
    private String s1;
    private String s2;
    private String s3;
    private int m;
    private int n;

    public boolean isInterleave(String s1, String s2, String s3) {
        m = s1.length();
        n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i >= m && j >= n) {
            return true;
        }
        var key = List.of(i, j);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int k = i + j;
        boolean ans = false;
        if (i < m && s1.charAt(i) == s3.charAt(k) && dfs(i + 1, j)) {
            ans = true;
        }
        if (!ans && j < n && s2.charAt(j) == s3.charAt(k) && dfs(i, j + 1)) {
            ans = true;
        }
        f.put(key, ans);
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0097  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # 定义一个函数 dfs，使用缓存装饰器 @cache 进行记忆化递归，避免重复计算
        @cache
        def dfs(i: int, j: int) -> bool:
            # 如果 s1 和 s2 都遍历完（i >= m 且 j >= n），返回 True，表示匹配成功
            if i >= m and j >= n:
                return True
            # 计算当前 s3 中的字符索引 k，它等于 s1 和 s2 当前索引之和
            k = i + j
            # 如果当前 s1 的字符 s1[i] 等于 s3[k]，并且递归 dfs(i + 1, j) 返回 True，则返回 True
            if i < m and s1[i] == s3[k] and dfs(i + 1, j):
                return True
            # 如果当前 s2 的字符 s2[j] 等于 s3[k]，并且递归 dfs(i, j + 1) 返回 True，则返回 True
            if j < n and s2[j] == s3[k] and dfs(i, j + 1):
                return True
            # 如果以上条件都不满足，返回 False，表示当前路径无法匹配
            return False

        # 获取字符串 s1 和 s2 的长度
        m, n = len(s1), len(s2)
        # 如果 s1 和 s2 的长度之和不等于 s3 的长度，直接返回 False，无法交错匹配
        if m + n != len(s3):
            return False
        # 从索引 (0, 0) 开始递归判断是否可以交错匹配
        return dfs(0, 0)
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<int>> f(m + 1, vector<int>(n + 1, -1));
        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i >= m && j >= n) {
                return true;
            }
            if (f[i][j] != -1) {
                return f[i][j] == 1;
            }
            f[i][j] = 0;
            int k = i + j;
            if (i < m && s1[i] == s3[k] && dfs(i + 1, j)) {
                f[i][j] = 1;
            }
            if (!f[i][j] && j < n && s2[j] == s3[k] && dfs(i, j + 1)) {
                f[i][j] = 1;
            }
            return f[i][j] == 1;
        };
        return dfs(0, 0);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private Map<List<Integer>, Boolean> f = new HashMap<>();
    private String s1;
    private String s2;
    private String s3;
    private int m;
    private int n;

    public boolean isInterleave(String s1, String s2, String s3) {
        m = s1.length();
        n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i >= m && j >= n) {
            return true;
        }
        var key = List.of(i, j);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int k = i + j;
        boolean ans = false;
        if (i < m && s1.charAt(i) == s3.charAt(k) && dfs(i + 1, j)) {
            ans = true;
        }
        if (!ans && j < n && s2.charAt(j) == s3.charAt(k) && dfs(i, j + 1)) {
            ans = true;
        }
        f.put(key, ans);
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0097  数学解释

```python 
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            if i >= m and j >= n:
                return True
            k = i + j
            if i < m and s1[i] == s3[k] and dfs(i + 1, j):
                return True
            if j < n and s2[j] == s3[k] and dfs(i, j + 1):
                return True
            return False

        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        return dfs(0, 0)
```


这段代码的核心是解决一个经典的动态规划问题：**判断字符串 `s3` 是否是字符串 `s1` 和 `s2` 的交错（Interleaving）组成**。我们可以用数学思想来分析这段代码的逻辑。

---

### **问题描述**
给定三个字符串 `s1`, `s2`, 和 `s3`，判断是否存在一种方式，使得 `s3` 是由 `s1` 和 `s2` 按顺序交错组成的，且不打乱它们各自的字符顺序。

#### **数学建模**
1. 假设 `s1` 的长度为 \( m \)，`s2` 的长度为 \( n \)，`s3` 的长度为 \( m + n \)。
2. 如果 `s3` 是由 `s1` 和 `s2` 交错组成，那么对于任意位置 \( k \) 的 `s3`，它的前 \( k \) 个字符一定由 `s1` 的前 \( i \) 个字符和 `s2` 的前 \( j \) 个字符组成，且满足：
   \[
   i + j = k
   \]
3. 进一步地，`s3[k]` 的来源有两种可能：
   - 来自 `s1[i]`，如果 `s1[i] == s3[k]`，并且之前的状态 `(i-1, j)` 是有效的。
   - 来自 `s2[j]`，如果 `s2[j] == s3[k]`，并且之前的状态 `(i, j-1)` 是有效的。

这就形成了一个典型的动态规划问题：判断从状态 `(i, j)` 是否能到达状态 `(m, n)`。

---

### **代码解析**
代码使用了递归 + 记忆化搜索（`@cache`）的方式来解决这个问题，避免了重复计算。

#### **关键步骤**
1. **递归定义**
   函数 `dfs(i, j)` 表示：
   - 当前已经匹配了 `s1` 的前 `i` 个字符和 `s2` 的前 `j` 个字符。
   - 判断是否能继续匹配 `s3` 的前 \( k = i + j \) 个字符。

2. **递归终止条件**
   - 如果 `i >= m` 且 `j >= n`，说明 `s1` 和 `s2` 的所有字符都已经匹配完，返回 `True`。

3. **递归转移方程**
   - 如果 `i < m` 且 `s1[i] == s3[k]`，尝试从 `(i+1, j)` 继续匹配。如果成功，返回 `True`。
   - 如果 `j < n` 且 `s2[j] == s3[k]`，尝试从 `(i, j+1)` 继续匹配。如果成功，返回 `True`。

4. **初始条件**
   - 首先检查 `m + n == len(s3)`，如果不成立，直接返回 `False`，因为长度不匹配。

#### **代码实现中的数学思想**
- **状态空间**：状态由 `(i, j)` 表示，即当前匹配了 `s1` 的前 `i` 个字符和 `s2` 的前 `j` 个字符。
- **状态转移**：通过 `s1[i] == s3[k]` 或 `s2[j] == s3[k]` 的匹配关系，从一个状态转移到下一个状态。
- **记忆化**：通过 `@cache` 装饰器避免重复计算，优化时间复杂度。

---

### **复杂度分析**
1. **时间复杂度**
   - 每个状态 `(i, j)` 只会被计算一次，状态总数为 \( O(m \times n) \)。
   - 每次递归中，检查字符匹配的操作是 \( O(1) \)。
   - 因此，总时间复杂度为：
     \[
     O(m \times n)
     \]

2. **空间复杂度**
   - 递归调用的栈空间最深为 \( O(m + n) \)。
   - 记忆化存储的空间为 \( O(m \times n) \)。
   - 总空间复杂度为：
     \[
     O(m \times n)
     \]

---

### **总结**
这段代码利用动态规划的思想，将问题分解为更小的子问题（子字符串的匹配），并通过记忆化避免重复计算，从而高效地判断字符串 `s3` 是否是由 `s1` 和 `s2` 交错组成的。



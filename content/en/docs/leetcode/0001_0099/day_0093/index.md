---
title: "day_0093 "
date: 2025-09-13T21:12:25+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0093 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def check(i: int, j: int) -> int:
            if s[i] == "0" and i != j:
                return False
            return 0 <= int(s[i : j + 1]) <= 255

        def dfs(i: int):
            if i >= n and len(t) == 4:
                ans.append(".".join(t))
                return
            if i >= n or len(t) >= 4:
                return
            for j in range(i, min(i + 3, n)):
                if check(i, j):
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        ans = []
        t = []
        dfs(0)
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        vector<string> t;
        function<void(int)> dfs = [&](int i) {
            if (i >= n && t.size() == 4) {
                ans.push_back(t[0] + "." + t[1] + "." + t[2] + "." + t[3]);
                return;
            }
            if (i >= n || t.size() >= 4) {
                return;
            }
            int x = 0;
            for (int j = i; j < min(n, i + 3); ++j) {
                x = x * 10 + s[j] - '0';
                if (x > 255 || (j > i && s[i] == '0')) {
                    break;
                }
                t.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int n;
    private String s;
    private List<String> ans = new ArrayList<>();
    private List<String> t = new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {
        n = s.length();
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= n && t.size() == 4) {
            ans.add(String.join(".", t));
            return;
        }
        if (i >= n || t.size() >= 4) {
            return;
        }
        int x = 0;
        for (int j = i; j < Math.min(i + 3, n); ++j) {
            x = x * 10 + s.charAt(j) - '0';
            if (x > 255 || (s.charAt(i) == '0' && i != j)) {
                break;
            }
            t.add(s.substring(i, j + 1));
            dfs(j + 1);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0093  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}


```python
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # 定义一个方法来还原 IP 地址，输入是字符串 s，返回值是一个字符串列表

        def check(i: int, j: int) -> int:
            # 定义一个辅助函数，用于检查 s[i:j+1] 是否是合法的 IP 地址段
            if s[i] == "0" and i != j:
                # 如果段以 "0" 开头且长度大于 1，则不是合法的 IP 地址段
                return False
            return 0 <= int(s[i : j + 1]) <= 255
            # 如果段的整数值在 0 到 255 之间，则是合法的 IP 地址段

        def dfs(i: int):
            # 定义深度优先搜索（DFS）函数，i 表示当前搜索到的字符串索引
            if i >= n and len(t) == 4:
                # 如果字符串已完全分割且已经有 4 段
                ans.append(".".join(t))
                # 将分割的结果用 "." 拼接成 IP 地址，并加入结果列表
                return
            if i >= n or len(t) >= 4:
                # 如果字符串已经用完或段数已经达到 4 段但未完全分割，则直接返回
                return
            for j in range(i, min(i + 3, n)):
                # 枚举从索引 i 开始的每一段，长度为 1 到 3 个字符
                if check(i, j):
                    # 如果当前段合法
                    t.append(s[i : j + 1])
                    # 将当前段加入临时结果 t
                    dfs(j + 1)
                    # 递归处理剩余部分
                    t.pop()
                    # 回溯，移除最后加入的段

        n = len(s)
        # 获取字符串 s 的长度
        ans = []
        # 用于存储最终的结果列表
        t = []
        # 用于存储当前分割的临时结果
        dfs(0)
        # 从索引 0 开始进行深度优先搜索
        return ans
        # 返回所有可能的 IP 地址组合
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        vector<string> t;
        function<void(int)> dfs = [&](int i) {
            if (i >= n && t.size() == 4) {
                ans.push_back(t[0] + "." + t[1] + "." + t[2] + "." + t[3]);
                return;
            }
            if (i >= n || t.size() >= 4) {
                return;
            }
            int x = 0;
            for (int j = i; j < min(n, i + 3); ++j) {
                x = x * 10 + s[j] - '0';
                if (x > 255 || (j > i && s[i] == '0')) {
                    break;
                }
                t.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                t.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int n;
    private String s;
    private List<String> ans = new ArrayList<>();
    private List<String> t = new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {
        n = s.length();
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= n && t.size() == 4) {
            ans.add(String.join(".", t));
            return;
        }
        if (i >= n || t.size() >= 4) {
            return;
        }
        int x = 0;
        for (int j = i; j < Math.min(i + 3, n); ++j) {
            x = x * 10 + s.charAt(j) - '0';
            if (x > 255 || (s.charAt(i) == '0' && i != j)) {
                break;
            }
            t.add(s.substring(i, j + 1));
            dfs(j + 1);
            t.remove(t.size() - 1);
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0093  数学解释

```python 
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def check(i: int, j: int) -> int:
            if s[i] == "0" and i != j:
                return False
            return 0 <= int(s[i : j + 1]) <= 255

        def dfs(i: int):
            if i >= n and len(t) == 4:
                ans.append(".".join(t))
                return
            if i >= n or len(t) >= 4:
                return
            for j in range(i, min(i + 3, n)):
                if check(i, j):
                    t.append(s[i : j + 1])
                    dfs(j + 1)
                    t.pop()

        n = len(s)
        ans = []
        t = []
        dfs(0)
        return ans 
```


这段代码实现了一个算法，用于将一个字符串 `s` 分割成所有可能的有效 IPv4 地址形式。我们可以通过数学思想来解释它的核心逻辑和实现。

---

### **数学思想解释**

#### **1. 问题背景：IPv4 地址的数学性质**
- IPv4 地址由 4 段数字组成，每段是一个整数，范围为 `[0, 255]`。
- 每段之间用 `.` 分隔，例如 `192.168.0.1`。
- 每段数字可以有 1 到 3 位，且不能以 `0` 开头（除非数字是单独的 `0`）。
- 给定一个字符串 `s`，我们需要找到所有可能的方式将其分割成有效的 IPv4 地址。

#### **2. 问题的数学建模**
- 将字符串 `s` 分割成 4 段（`t1`, `t2`, `t3`, `t4`），满足以下条件：
  1. 每段数字在范围 `[0, 255]` 内。
  2. 每段数字的长度为 1 到 3。
  3. 整个字符串必须被完全使用。

#### **3. 使用深度优先搜索 (DFS)**
- 这段代码通过 **深度优先搜索 (DFS)** 来探索所有可能的分割方式。
- DFS 的思想是从字符串的起始位置开始，尝试将字符串分割成不同长度的段（1 到 3 个字符），并检查当前段是否满足有效性条件。
- 如果当前段有效，则递归继续处理剩余的字符串，直到构造出 4 段有效的地址。

#### **4. 关键的数学条件**
- 有效性检查函数 `check(i, j)`：
  - 如果数字段以 `0` 开头且长度大于 1，则无效。
  - 如果数字段的整数值不在 `[0, 255]` 范围内，则无效。
  - 通过这些数学条件，过滤掉不符合 IPv4 规则的分割方式。

---

### **代码逻辑分解**

#### **函数 `check(i, j)`**
```python
def check(i: int, j: int) -> int:
    if s[i] == "0" and i != j:
        return False
    return 0 <= int(s[i : j + 1]) <= 255
```
- 这是一个辅助函数，用于判断从字符串 `s` 的第 `i` 到 `j` 个字符组成的子串是否是有效的 IPv4 地址段。
- 数学思想：
  1. 如果子串以 `0` 开头（`s[i] == "0"`）且长度大于 1（`i != j`），则无效。
  2. 将子串转换为整数，判断其是否在 `[0, 255]` 范围内。

#### **函数 `dfs(i)`**
```python
def dfs(i: int):
    if i >= n and len(t) == 4:
        ans.append(".".join(t))
        return
    if i >= n or len(t) >= 4:
        return
    for j in range(i, min(i + 3, n)):
        if check(i, j):
            t.append(s[i : j + 1])
            dfs(j + 1)
            t.pop()
```
- 这是深度优先搜索的核心函数。
- 参数 `i` 表示当前处理到字符串的第 `i` 个字符。
- 数学思想：
  1. 终止条件：
     - 如果已经分割出 4 段（`len(t) == 4`）且字符串刚好用完（`i >= n`），将当前分割结果加入答案。
     - 如果字符串未用完但已经分割出 4 段（`len(t) >= 4`），或者字符串已用完但分割不足 4 段，则直接返回。
  2. 枚举当前段的长度：
     - 遍历 `j`，尝试将字符串的第 `i` 到 `j` 个字符作为当前段（长度为 1 到 3）。
     - 调用 `check(i, j)` 检查当前段是否有效。
     - 如果有效，将当前段加入临时结果 `t`，递归处理剩余字符串（`dfs(j + 1)`）。
     - 回溯时移除当前段（`t.pop()`），尝试其他分割方式。

#### **主函数**
```python
n = len(s)
ans = []
t = []
dfs(0)
return ans
```
- 初始化变量：
  - `n` 是字符串的长度。
  - `ans` 用于存储所有可能的 IPv4 地址。
  - `t` 是一个临时列表，用于存储当前正在构造的 IPv4 地址段。
- 调用 `dfs(0)` 从字符串的起始位置开始分割。
- 返回所有可能的分割结果。

---

### **数学性质总结**
1. **分治思想**：
   - 通过将字符串分割成 4 段，递归地解决子问题。
   - 每次尝试将字符串的某一部分作为一个段，剩余部分递归处理。

2. **剪枝优化**：
   - 使用 `check(i, j)` 函数提前过滤掉不可能的分割方式，避免无效的递归。

3. **搜索空间**：
   - 对于长度为 `n` 的字符串，理论上最多有 `O(3^4)` 种分割方式（每段最多 3 个字符，4 段）。
   - 通过有效性检查和递归剪枝，大大减少了搜索空间。

---

### **复杂度分析**
1. **时间复杂度**：
   - 最坏情况下，每个字符最多参与 3 次分割，每次分割需要检查有效性，因此复杂度为 `O(3^4)`。
   - 实际复杂度更低，因为有效性检查和剪枝会减少递归深度。

2. **空间复杂度**：
   - 递归栈的深度为 `O(4)`，每次递归需要存储临时结果 `t`。

---

### **例子分析**
假设输入字符串为 `s = "25525511135"`，我们可以通过 DFS 得到以下分割结果：
```
["255.255.11.135", "255.255.111.35"]
```
每个结果都满足 IPv4 地址的数学性质。

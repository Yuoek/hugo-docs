---
title: "day_0022 "
date: 2025-09-14T11:05:53+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0022 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(l, r, t):
            if l > n or r > n or l < r:
                return
            if l == n and r == n:
                ans.append(t)
                return
            dfs(l + 1, r, t + '(')
            dfs(l, r + 1, t + ')')

        ans = []
        dfs(0, 0, '')
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string t) {
            if (l > n || r > n || l < r) return;
            if (l == n && r == n) {
                ans.push_back(t);
                return;
            }
            dfs(l + 1, r, t + "(");
            dfs(l, r + 1, t + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<String> ans = new ArrayList<>();
    private int n;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs(0, 0, "");
        return ans;
    }

    private void dfs(int l, int r, String t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.add(t);
            return;
        }
        dfs(l + 1, r, t + "(");
        dfs(l, r + 1, t + ")");
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0022  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(l, r, t):  # 定义深度优先搜索函数，l: 左括号数量，r: 右括号数量，t: 当前生成的字符串
            if l > n or r > n or l < r:  # 终止条件：左括号或右括号超过n个，或右括号多于左括号（不合法）
                return
            if l == n and r == n:  # 如果左右括号都达到n个，说明生成了一个有效组合
                ans.append(t)  # 将当前字符串加入结果列表
                return
            dfs(l + 1, r, t + '(')  # 选择添加左括号，继续递归
            dfs(l, r + 1, t + ')')  # 选择添加右括号，继续递归

        ans = []  # 初始化结果列表
        dfs(0, 0, '')  # 从0个左括号、0个右括号、空字符串开始搜索
        return ans  # 返回所有有效的括号组合
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string t) {
            if (l > n || r > n || l < r) return;
            if (l == n && r == n) {
                ans.push_back(t);
                return;
            }
            dfs(l + 1, r, t + "(");
            dfs(l, r + 1, t + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private List<String> ans = new ArrayList<>();
    private int n;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs(0, 0, "");
        return ans;
    }

    private void dfs(int l, int r, String t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.add(t);
            return;
        }
        dfs(l + 1, r, t + "(");
        dfs(l, r + 1, t + ")");
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0022  数学解释

```python 
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(l, r, t):
            if l > n or r > n or l < r:
                return
            if l == n and r == n:
                ans.append(t)
                return
            dfs(l + 1, r, t + '(')
            dfs(l, r + 1, t + ')')

        ans = []
        dfs(0, 0, '')
        return ans 
```


这段代码使用了**回溯法（Backtracking）** 和**深度优先搜索（DFS）** 的数学思想来生成所有有效的括号组合。

### 数学思想解析：

1. **组合数学中的约束条件**：
   - 左括号数 `l` 必须始终 ≥ 右括号数 `r`（即 `l < r` 时无效）
   - 左右括号数都不能超过 n（即 `l > n` 或 `r > n` 时无效）
   - 当 `l == n` 且 `r == n` 时得到一个有效解

2. **状态空间搜索**：
   - 将问题建模为在状态空间中的搜索，每个状态由 `(l, r, t)` 表示
   - 从初始状态 `(0, 0, "")` 开始
   - 每一步有两种选择：添加左括号或添加右括号

3. **剪枝策略**：
   - 当 `l < r` 时提前终止（右括号多于左括号，无效）
   - 当 `l > n` 或 `r > n` 时提前终止（超出数量限制）

4. **递归树结构**：
   - 构建了一棵二叉树，每个节点代表一个中间状态
   - 左分支对应添加左括号
   - 右分支对应添加右括号

### 数学性质：
- 解的总数是**卡特兰数（Catalan Number）**：Cₙ = (2n)!/((n+1)!n!)
- 算法的时间复杂度为 O(4ⁿ/√n)，空间复杂度为 O(n)

这种方法通过系统性地探索所有可能的选择，同时利用约束条件进行剪枝，确保只生成有效的括号组合，体现了**穷举搜索与约束满足**的数学思想。


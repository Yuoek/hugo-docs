---
title: "day_0096 "
date: 2025-09-13T20:48:19+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---


{{< katex />}}


## LeetCode_0096 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def numTrees(self, n: int) -> int:
        f = [1] + [0] * n
        for i in range(n + 1):
            for j in range(i):
                f[i] += f[j] * f[i - j - 1]
        return f[n] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int numTrees(int n) {
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0096  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def numTrees(self, n: int) -> int:
        # 定义一个数组 f，用于存储从 0 到 n 节点数的不同二叉搜索树的个数
        # 初始化 f[0] 为 1（空树只有一种情况），其余初始化为 0
        f = [1] + [0] * n
        
        # 遍历从 0 到 n 的每个节点数 i，计算不同二叉搜索树的个数
        for i in range(n + 1):
            # 对于每个 i，遍历从 0 到 i-1 的每个节点数 j，计算以 j 为根的情况
            for j in range(i):
                # f[i] 的值累加以 j 为根时，左子树有 j 个节点，右子树有 i-j-1 个节点的乘积
                f[i] += f[j] * f[i - j - 1]
        
        # 返回 f[n]，即有 n 个节点时的不同二叉搜索树的个数
        return f[n] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int numTrees(int n) {
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0096  数学解释

```python 
class Solution:
    def numTrees(self, n: int) -> int:
        f = [1] + [0] * n
        for i in range(n + 1):
            for j in range(i):
                f[i] += f[j] * f[i - j - 1]
        return f[n] 
```


这段代码的核心思想是使用动态规划（Dynamic Programming）来计算卡塔兰数（Catalan Number），并解决一个经典的组合数学问题：**有 `n` 个节点，能构成多少种不同的二叉搜索树（BST）**。

我们用数学思想来解释这段代码的原理：

---

### 1. 问题的数学建模
设 `f[i]` 表示由 `i` 个节点可以组成的不同二叉搜索树的数量。我们需要求 `f[n]`。

根据二叉搜索树的性质，根节点将二叉搜索树分为左子树和右子树：
- 左子树的节点数可以是 `0` 到 `i-1`。
- 右子树的节点数是 `i-1` 减去左子树的节点数。

因此，二叉搜索树的总数可以通过以下公式递归计算：
\\[
f[i] = \sum_{j=0}^{i-1} f[j] \cdot f[i-j-1]
\\]
其中：
- `f[j]` 表示左子树的组合数（有 `j` 个节点）。
- `f[i-j-1]` 表示右子树的组合数（有 `i-j-1` 个节点）。
- 对于每一个可能的根节点（从 1 到 `i`），都要将左子树和右子树的组合数相乘并累加。

初始条件：
- 当 `i = 0` 时，空树是一种有效的树，因此 `f[0] = 1`。

---

### 2. 动态规划的实现
代码中使用动态规划的方法，逐步计算 `f[0], f[1], ..., f[n]`：

#### 初始化
```python
f = [1] + [0] * n
```
- 创建一个长度为 `n+1` 的数组 `f`，其中 `f[0] = 1` 表示空树的情况。
- 其余的值初始化为 `0`。

#### 递推关系
```python
for i in range(n + 1):
    for j in range(i):
        f[i] += f[j] * f[i - j - 1]
```
- 外层循环 `for i in range(n + 1)`：计算 `f[0], f[1], ..., f[n]`。
- 内层循环 `for j in range(i)`：枚举根节点将树分为左子树和右子树的所有可能情况。
  - `f[j]` 表示左子树的组合数。
  - `f[i-j-1]` 表示右子树的组合数。
  - 将两者相乘，并累加到 `f[i]`。

#### 返回结果
```python
return f[n]
```
- 最终返回 `f[n]`，即有 `n` 个节点的二叉搜索树的总数。

---

### 3. 数学背景：卡塔兰数
这段代码实际上是在计算第 `n` 个卡塔兰数，卡塔兰数的公式为：
\[
C_n = \frac{1}{n+1} \binom{2n}{n}
\]
或者递推公式：
\[
C_n = \sum_{i=0}^{n-1} C_i \cdot C_{n-i-1}
\]

---

### 4. 举例：`n = 3`
我们用代码计算 `f[3]`：
- 初始化：`f = [1, 0, 0, 0]`
- 计算 `f[1]`：
  - `f[1] = f[0] * f[0] = 1`
  - 更新：`f = [1, 1, 0, 0]`
- 计算 `f[2]`：
  - `f[2] = f[0] * f[1] + f[1] * f[0] = 1 * 1 + 1 * 1 = 2`
  - 更新：`f = [1, 1, 2, 0]`
- 计算 `f[3]`：
  - `f[3] = f[0] * f[2] + f[1] * f[1] + f[2] * f[0] = 1 * 2 + 1 * 1 + 2 * 1 = 5`
  - 更新：`f = [1, 1, 2, 5]`

最终返回 `f[3] = 5`。

---

### 5. 总结
这段代码利用动态规划高效地计算了卡塔兰数，解决了组合数学中二叉搜索树计数的问题。数学思想体现在：
- 通过递归公式分解问题。
- 动态规划避免了重复计算。
- 使用组合数学的性质来解决实际问题。



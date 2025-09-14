---
title: "day_0060 "
date: 2025-09-14T09:31:06+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0060 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []
        vis = [False] * (n + 1)
        for i in range(n):
            fact = 1
            for j in range(1, n - i):
                fact *= j
            for j in range(1, n + 1):
                if not vis[j]:
                    if k > fact:
                        k -= fact
                    else:
                        ans.append(str(j))
                        vis[j] = True
                        break
        return ''.join(ans) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        bitset<10> vis;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) fact *= j;
            for (int j = 1; j <= n; ++j) {
                if (vis[j]) continue;
                if (k > fact)
                    k -= fact;
                else {
                    ans += to_string(j);
                    vis[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.append(j);
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0060  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []  # 存储最终结果的列表
        vis = [False] * (n + 1)  # 标记数组，记录数字是否已被使用
        for i in range(n):  # 遍历n次，每次确定一个数字
            fact = 1  # 计算阶乘，表示剩余数字的排列数
            for j in range(1, n - i):  # 计算(n-i-1)!的阶乘值
                fact *= j
            for j in range(1, n + 1):  # 遍历所有数字
                if not vis[j]:  # 如果数字j未被使用
                    if k > fact:  # 如果k大于当前分支的排列数
                        k -= fact  # 跳过这个分支，减去对应的排列数
                    else:  # 找到正确的分支
                        ans.append(str(j))  # 将数字j加入结果
                        vis[j] = True  # 标记数字j为已使用
                        break  # 跳出内层循环
        return ''.join(ans)  # 将列表转换为字符串返回
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        bitset<10> vis;
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) fact *= j;
            for (int j = 1; j <= n; ++j) {
                if (vis[j]) continue;
                if (k > fact)
                    k -= fact;
                else {
                    ans += to_string(j);
                    vis[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < n; ++i) {
            int fact = 1;
            for (int j = 1; j < n - i; ++j) {
                fact *= j;
            }
            for (int j = 1; j <= n; ++j) {
                if (!vis[j]) {
                    if (k > fact) {
                        k -= fact;
                    } else {
                        ans.append(j);
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0060  数学解释

```python 
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = []
        vis = [False] * (n + 1)
        for i in range(n):
            fact = 1
            for j in range(1, n - i):
                fact *= j
            for j in range(1, n + 1):
                if not vis[j]:
                    if k > fact:
                        k -= fact
                    else:
                        ans.append(str(j))
                        vis[j] = True
                        break
        return ''.join(ans) 
```


这段代码使用了**阶乘数系统（Factorial Number System）** 的数学思想来解决排列问题。

## 核心数学思想

### 1. 阶乘数系统（Factorial Number System）
- 任何整数 k 都可以唯一表示为：`k = a₁·1! + a₂·2! + a₃·3! + ... + aₙ·n!`
- 其中 0 ≤ aᵢ ≤ i，aᵢ 就是阶乘数系统中的系数

### 2. 排列与阶乘的关系
- 对于 n 个不同元素的排列，共有 n! 种可能
- 每个位置的选择可以用阶乘数来表示：
  - 第1位：有 n 种选择，对应 (n-1)! 种后续排列
  - 第2位：有 n-1 种选择，对应 (n-2)! 种后续排列
  - 以此类推...

## 代码执行逻辑

### 外层循环 (i from 0 to n-1)
确定排列的每一位数字

### 内层第一部分：计算阶乘
```python
fact = 1
for j in range(1, n - i):
    fact *= j  # 计算 (n-i-1)!
```

### 内层第二部分：选择数字
```python
for j in range(1, n + 1):
    if not vis[j]:  # 只考虑未使用的数字
        if k > fact:
            k -= fact  # 跳过 fact 个排列
        else:
            ans.append(str(j))  # 找到当前位的数字
            vis[j] = True      # 标记为已使用
            break
```

## 数学解释示例
以 n=4, k=9 为例：
- 第1位：有 3! = 6 种排列以每个数字开头
- k=9 > 6，所以跳过以1开头的6种排列，k=9-6=3
- 第2位：有 2! = 2 种排列以每个剩余数字开头
- k=3 > 2，跳过以2开头的2种排列，k=3-2=1
- 第3位：有 1! = 1 种排列以每个剩余数字开头
- k=1 ≤ 1，选择当前最小的未使用数字
- 最终得到排列 "2314"

这种方法的时间复杂度为 O(n²)，空间复杂度为 O(n)，通过数学优化避免了生成所有排列的低效方法。



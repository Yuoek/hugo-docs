---
title: "day_0161 "
date: 2025-09-21T09:06:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0161 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if len(s) < len(t):
            return self.isOneEditDistance(t, s)
        m, n = len(s), len(t)
        if m - n > 1:
            return False
        for i, c in enumerate(t):
            if c != s[i]:
                return s[i + 1 :] == t[i + 1 :] if m == n else s[i + 1 :] == t[i:]
        return m == n + 1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0161  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if len(s) < len(t):  # 确保s是较长的字符串，方便后续处理
            return self.isOneEditDistance(t, s)
        m, n = len(s), len(t)  # 获取两个字符串的长度
        if m - n > 1:  # 如果长度差大于1，肯定不满足一次编辑距离
            return False
        for i, c in enumerate(t):  # 遍历较短的字符串t
            if c != s[i]:  # 找到第一个不同的字符位置
                return s[i + 1 :] == t[i + 1 :] if m == n else s[i + 1 :] == t[i:]  # 根据长度是否相等选择不同的比较方式
        return m == n + 1  # 如果前面字符都相同，检查是否刚好多一个字符
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0161  数学解释

```python 
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if len(s) < len(t):
            return self.isOneEditDistance(t, s)
        m, n = len(s), len(t)
        if m - n > 1:
            return False
        for i, c in enumerate(t):
            if c != s[i]:
                return s[i + 1 :] == t[i + 1 :] if m == n else s[i + 1 :] == t[i:]
        return m == n + 1 
```


这段代码使用了**双指针思想**和**贪心思想**来解决判断两个字符串是否相差一个编辑距离的问题。

## 数学思想解析：

### 1. 对称性思想
```python
if len(s) < len(t):
    return self.isOneEditDistance(t, s)
```
这里利用了问题的对称性：如果s比t短，交换参数位置，确保s总是较长或等长的字符串，简化后续处理。

### 2. 边界条件思想
```python
if m - n > 1:
    return False
```
数学上的排除法：如果长度差超过1，直接返回False，因为无法通过单次编辑达到。

### 3. 贪心匹配思想
```python
for i, c in enumerate(t):
    if c != s[i]:
        return s[i + 1 :] == t[i + 1 :] if m == n else s[i + 1 :] == t[i:]
```
核心算法思想：
- **长度相等时**：找到第一个不同字符，检查剩余子串是否完全相同（替换操作）
- **长度不等时**：找到第一个不同字符，检查s的剩余部分是否等于t的当前剩余部分（删除操作）

### 4. 特殊情况处理
```python
return m == n + 1
```
如果循环结束都没有找到不同字符，说明t是s的前缀，此时只有当s比t长1时才满足条件（在末尾添加一个字符）

## 时间复杂度分析：
- 最坏情况：O(min(m, n))，其中m和n分别是两个字符串的长度
- 空间复杂度：O(1)，只使用了常数级别的额外空间

这个算法巧妙地利用了字符串比较的特性，通过一次遍历就能判断出是否满足单次编辑距离的条件。



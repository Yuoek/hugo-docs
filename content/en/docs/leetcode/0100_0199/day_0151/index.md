---
title: "day_0151 "
date: 2025-09-21T09:24:31+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0151 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def reverseWords(self, s: str) -> str:
        words = []
        i, n = 0, len(s)
        while i < n:
            while i < n and s[i] == " ":
                i += 1
            if i < n:
                j = i
                while j < n and s[j] != " ":
                    j += 1
                words.append(s[i:j])
                i = j
        return " ".join(words[::-1]) 
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

## LeetCode_0151  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        words = []  # 存储单词的列表
        i, n = 0, len(s)  # i是当前索引，n是字符串长度
        
        while i < n:  # 遍历整个字符串
            # 跳过连续的空格
            while i < n and s[i] == " ":
                i += 1
            
            # 如果还有字符，提取单词
            if i < n:
                j = i  # j指向单词的结束位置
                # 找到单词的结束位置
                while j < n and s[j] != " ":
                    j += 1
                # 将单词添加到列表中
                words.append(s[i:j])
                i = j  # 移动索引到当前单词结束位置
        
        # 反转单词列表并用空格连接
        return " ".join(words[::-1]) 
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

## LeetCode_0151  数学解释

```python 
class Solution:
    def reverseWords(self, s: str) -> str:
        words = []
        i, n = 0, len(s)
        while i < n:
            while i < n and s[i] == " ":
                i += 1
            if i < n:
                j = i
                while j < n and s[j] != " ":
                    j += 1
                words.append(s[i:j])
                i = j
        return " ".join(words[::-1]) 
```


这段代码实现的是字符串中单词的反转，体现了以下数学思想：

## 1. 双指针思想（区间划分）
代码使用双指针`i`和`j`来识别和提取单词：
- `i`指向单词的起始位置
- `j`指向单词的结束位置（下一个空格或字符串末尾）

这类似于数学中的区间划分，将字符串划分为多个不相交的区间`[i, j)`，每个区间对应一个单词。

## 2. 集合操作思想
代码将提取的单词存储在列表`words`中，这类似于数学中的集合操作：
- 遍历字符串，识别并收集所有非空单词
- 忽略空格字符（空元素）

## 3. 逆序操作
`words[::-1]`实现了列表的逆序，这对应于数学中的序列反转操作：
- 如果原单词序列为：w₁, w₂, w₃, ..., wₙ
- 反转后变为：wₙ, wₙ₋₁, ..., w₁

## 4. 算法复杂度分析
从数学角度分析时间复杂度：
- 外层循环：O(n)
- 内层循环：每个字符最多被访问两次
- 总体时间复杂度：O(n)
- 空间复杂度：O(n)（存储所有单词）

## 5. 集合论视角
整个过程可以看作：
- 输入：字符串集合 S
- 操作：过滤空字符 → 划分单词子集 → 反转子集顺序
- 输出：反转后的单词序列

这种双指针+集合操作的方法既高效又直观，体现了算法设计中空间换时间的常见策略。



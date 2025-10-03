---
title: "day_0186 "
date: 2025-09-21T08:13:55+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0186 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1) 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s, i, j);
            }
        }
        reverse(s, 0, n - 1);
    }

    private void reverse(char[] s, int i, int j) {
        for (; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0186  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}


```python 
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):  # 定义反转字符数组指定区间的辅助函数
            while i < j:
                s[i], s[j] = s[j], s[i]  # 交换首尾字符
                i, j = i + 1, j - 1  # 向中间移动指针

        i, n = 0, len(s)  # i记录单词起始位置，n为数组长度
        for j, c in enumerate(s):  # 遍历字符数组
            if c == " ":  # 遇到空格表示一个单词结束
                reverse(i, j - 1)  # 反转当前单词
                i = j + 1  # 更新下一个单词的起始位置
            elif j == n - 1:  # 处理最后一个单词（没有空格结尾）
                reverse(i, j)  # 反转最后一个单词
        reverse(0, n - 1)  # 最后整体反转整个字符数组
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1) 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s, i, j);
            }
        }
        reverse(s, 0, n - 1);
    }

    private void reverse(char[] s, int i, int j) {
        for (; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0186  数学解释

```python 
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1) 
```


这段代码实现了原地反转字符串中的单词顺序，体现了以下数学思想：

## 1. 对称变换思想
`reverse()`函数通过双指针交换实现对称反转，体现了数学中的对称变换概念：
- 对于区间[i, j]，将第i个与第j个元素交换，i+1与j-1交换，直到中间点
- 这种对称交换操作类似于数学中的轴对称变换

## 2. 分治与分段处理
代码采用分段处理策略，体现了分治思想：
- 先将整个字符串按空格分割成单词段
- 对每个单词段分别进行反转操作
- 最后对整个字符串进行整体反转

## 3. 复合变换的分解
整个过程可以看作三个变换的复合：
```
原始： [w1][w2][w3]...[wn]
步骤1：对每个单词反转 → [1w][2w][3w]...[nw]
步骤2：整体反转 → [wn]...[w3][w2][w1]
```

## 4. 双指针技术的数学本质
`i`和`j`指针的移动体现了区间划分的数学思想：
- `i`标记当前单词的起始位置
- `j`遍历寻找单词结束位置（空格或字符串末尾）
- 这种区间划分确保了每个单词被正确处理

## 5. 不变量的保持
算法保持了字符串的字符集合不变，只改变了字符的相对位置关系，体现了数学变换中保持某些性质不变的思想。

这种算法的时间复杂度为O(n)，空间复杂度为O(1)，通过巧妙的变换组合实现了高效的原位操作。


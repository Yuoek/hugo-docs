---
title: "day_0058 "
date: 2025-09-14T09:47:42+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0058 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
        j = i
        while j >= 0 and s[j] != ' ':
            j -= 1
        return i - j 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (~i && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (~j && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s.charAt(j) != ' ') {
            --j;
        }
        return i - j;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0058  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1  # 从字符串末尾开始
        while i >= 0 and s[i] == ' ':  # 跳过末尾的空格
            i -= 1
        j = i  # 记录最后一个单词的结束位置
        while j >= 0 and s[j] != ' ':  # 向前查找单词的开始位置
            j -= 1
        return i - j  # 计算并返回最后一个单词的长度
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (~i && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (~j && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s.charAt(j) != ' ') {
            --j;
        }
        return i - j;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0058  数学解释

```python 
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i -= 1
        j = i
        while j >= 0 and s[j] != ' ':
            j -= 1
        return i - j 
```


这段代码使用了**双指针逆向扫描**的数学思想来解决"最后一个单词的长度"问题。具体分析如下：

## 数学思想：逆向遍历与边界定位

### 1. 逆向思维
代码从字符串末尾开始向前扫描，这是关键策略：
- 避免了处理字符串开头可能存在的空格
- 直接定位到最后一个单词的结束位置

### 2. 双指针定位法
使用两个指针 `i` 和 `j` 来精确确定单词的边界：

**第一步：定位单词结尾 (i指针)**
```python
while i >= 0 and s[i] == ' ':
    i -= 1
```
- 从字符串末尾开始，跳过所有尾部空格
- `i` 最终指向最后一个单词的最后一个字符

**第二步：定位单词开头 (j指针)**
```python
while j >= 0 and s[j] != ' ':
    j -= 1
```
- 从 `i` 的位置继续向前扫描，直到遇到空格或字符串开头
- `j` 最终指向最后一个单词的前一个位置（空格或-1）

### 3. 距离计算
```python
return i - j
```
- 利用指针位置的差值直接得到单词长度
- 数学原理：`结束位置 - 开始位置 = 长度`

### 4. 时间复杂度分析
- 最坏情况：O(n)，其中n为字符串长度
- 最佳情况：O(1)（如果字符串很短或没有尾部空格）

这种解法体现了**空间优化**的思想，只使用常数空间（两个指针变量），同时通过逆向遍历避免了不必要的正向处理。



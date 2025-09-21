---
title: "day_0125 "
date: 2025-09-21T10:11:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0125 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i, j = i + 1, j - 1
        return True 
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

## LeetCode_0125  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1  # 初始化左右指针，i指向字符串开头，j指向字符串末尾
        while i < j:  # 当左指针小于右指针时循环
            if not s[i].isalnum():  # 如果左指针指向的字符不是字母或数字
                i += 1  # 左指针右移，跳过该字符
            elif not s[j].isalnum():  # 如果右指针指向的字符不是字母或数字
                j -= 1  # 右指针左移，跳过该字符
            elif s[i].lower() != s[j].lower():  # 如果左右指针指向的字符（忽略大小写）不相等
                return False  # 不是回文，返回False
            else:  # 如果左右指针指向的字符相等
                i, j = i + 1, j - 1  # 同时移动左右指针向中间靠拢
        return True  # 所有字符都匹配，是回文，返回True
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

## LeetCode_0125  数学解释

```python 
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if not s[i].isalnum():
                i += 1
            elif not s[j].isalnum():
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i, j = i + 1, j - 1
        return True 
```

 
这段代码使用了**双指针法**和**对称性验证**的数学思想：

## 核心数学思想：

1. **双指针对称遍历**：使用两个指针从字符串两端向中间移动，验证对称位置的字符是否相同
2. **回文对称性**：回文字符串具有镜像对称性质，即 s[i] = s[n-1-i]

## 具体实现逻辑：

- **初始化**：i从0开始（左指针），j从len(s)-1开始（右指针）
- **过滤非字母数字字符**：使用isalnum()跳过空格、标点等无效字符
- **大小写统一**：使用lower()将字符统一为小写进行比较
- **对称验证**：比较s[i]和s[j]，如果不相等则不是回文
- **收敛条件**：当i >= j时，说明所有对称位置都已验证通过

## 数学复杂度：
- 时间复杂度：O(n)，每个字符最多被访问一次
- 空间复杂度：O(1)，只使用了常数级别的额外空间

这种方法高效地利用了回文的对称性质，避免了创建新字符串的内存开销。

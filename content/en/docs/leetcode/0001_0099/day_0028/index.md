---
title: "day_0028 "
date: 2025-09-14T10:54:29+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0028 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i : i + m] == needle:
                return i
        return -1 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
private:
    vector<int> Next(string str) {
        vector<int> n(str.length());
        n[0] = -1;
        int i = 0, pre = -1;
        int len = str.length();
        while (i < len) {
            while (pre >= 0 && str[i] != str[pre])
                pre = n[pre];
            ++i, ++pre;
            if (i >= len)
                break;
            if (str[i] == str[pre])
                n[i] = n[pre];
            else
                n[i] = pre;
        }
        return n;
    }

public:
    int strStr(string haystack, string needle) {
        if (0 == needle.length())
            return 0;

        vector<int> n(Next(needle));

        int len = haystack.length() - needle.length() + 1;
        for (int i = 0; i < len; ++i) {
            int j = 0, k = i;
            while (j < needle.length() && k < haystack.length()) {
                if (haystack[k] != needle[j]) {
                    if (n[j] >= 0) {
                        j = n[j];
                        continue;
                    } else
                        break;
                }
                ++k, ++j;
            }
            if (j >= needle.length())
                return k - j;
        }

        return -1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int strStr(String haystack, String needle) {
        if ("".equals(needle)) {
            return 0;
        }

        int len1 = haystack.length();
        int len2 = needle.length();
        int p = 0;
        int q = 0;
        while (p < len1) {
            if (haystack.charAt(p) == needle.charAt(q)) {
                if (len2 == 1) {
                    return p;
                }
                ++p;
                ++q;
            } else {
                p -= q - 1;
                q = 0;
            }

            if (q == len2) {
                return p - q;
            }
        }
        return -1;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0028  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)  # 获取haystack和needle的长度
        for i in range(n - m + 1):  # 遍历所有可能的起始位置
            if haystack[i : i + m] == needle:  # 检查当前位置开始的子串是否匹配needle
                return i  # 匹配成功，返回起始索引
        return -1  # 遍历结束未找到匹配，返回-1
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
private:
    vector<int> Next(string str) {
        vector<int> n(str.length());
        n[0] = -1;
        int i = 0, pre = -1;
        int len = str.length();
        while (i < len) {
            while (pre >= 0 && str[i] != str[pre])
                pre = n[pre];
            ++i, ++pre;
            if (i >= len)
                break;
            if (str[i] == str[pre])
                n[i] = n[pre];
            else
                n[i] = pre;
        }
        return n;
    }

public:
    int strStr(string haystack, string needle) {
        if (0 == needle.length())
            return 0;

        vector<int> n(Next(needle));

        int len = haystack.length() - needle.length() + 1;
        for (int i = 0; i < len; ++i) {
            int j = 0, k = i;
            while (j < needle.length() && k < haystack.length()) {
                if (haystack[k] != needle[j]) {
                    if (n[j] >= 0) {
                        j = n[j];
                        continue;
                    } else
                        break;
                }
                ++k, ++j;
            }
            if (j >= needle.length())
                return k - j;
        }

        return -1;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int strStr(String haystack, String needle) {
        if ("".equals(needle)) {
            return 0;
        }

        int len1 = haystack.length();
        int len2 = needle.length();
        int p = 0;
        int q = 0;
        while (p < len1) {
            if (haystack.charAt(p) == needle.charAt(q)) {
                if (len2 == 1) {
                    return p;
                }
                ++p;
                ++q;
            } else {
                p -= q - 1;
                q = 0;
            }

            if (q == len2) {
                return p - q;
            }
        }
        return -1;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0028  数学解释

```python 
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i : i + m] == needle:
                return i
        return -1 
```


这段代码实现了字符串匹配算法，其数学思想可以解释为：

## 数学原理：穷举搜索法（Brute-Force Search）

### 1. 组合数学思想
代码通过遍历所有可能的起始位置来寻找匹配子串，这体现了**组合数学中的排列组合思想**：
- 从长度为n的字符串haystack中，找出所有长度为m的可能子串
- 可能的起始位置数量为：n - m + 1

### 2. 集合论视角
- 定义集合 S = {所有可能的起始位置 i | 0 ≤ i ≤ n - m}
- 寻找满足条件的元素：i ∈ S 使得 haystack[i:i+m] = needle
- 如果找到，返回最小的i（因为按顺序遍历）
- 如果S为空集（即n < m）或没有满足条件的元素，返回-1

### 3. 时间复杂度分析
- 最坏情况：O((n-m+1)×m) = O(n×m)
- 最好情况：O(1)（needle在开头就匹配）
- 平均情况：取决于字符串的相似度

### 4. 空间复杂度
- O(1)，只使用了常数级别的额外空间

### 5. 算法正确性证明
该算法能够找到所有可能的匹配位置，因为：
- 遍历了所有可能的起始位置（0到n-m）
- 对每个位置，检查长度为m的子串是否完全匹配needle
- 由于是顺序遍历，找到的第一个匹配位置就是最小的索引值

这是一种简单但有效的字符串匹配方法，虽然在某些情况下效率不高，但实现简单且易于理解。

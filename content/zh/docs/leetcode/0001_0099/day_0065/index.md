---
title: "day_0065 "
date: 2025-09-14T09:20:26+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0065 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        i = 0
        if s[i] in '+-':
            i += 1
        if i == n:
            return False
        if s[i] == '.' and (i + 1 == n or s[i + 1] in 'eE'):
            return False
        dot = e = 0
        j = i
        while j < n:
            if s[j] == '.':
                if e or dot:
                    return False
                dot += 1
            elif s[j] in 'eE':
                if e or j == i or j == n - 1:
                    return False
                e += 1
                if s[j + 1] in '+-':
                    j += 1
                    if j == n - 1:
                        return False
            elif not s[j].isnumeric():
                return False
            j += 1
        return True 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == n) return false;
        if (s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) return false;
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '.') {
                if (e || dot) return false;
                ++dot;
            } else if (s[j] == 'e' || s[j] == 'E') {
                if (e || j == i || j == n - 1) return false;
                ++e;
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    if (++j == n - 1) return false;
                }
            } else if (s[j] < '0' || s[j] > '9')
                return false;
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isNumber(String s) {
        int n = s.length();
        int i = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            ++i;
        }
        if (i == n) {
            return false;
        }
        if (s.charAt(i) == '.'
            && (i + 1 == n || s.charAt(i + 1) == 'e' || s.charAt(i + 1) == 'E')) {
            return false;
        }
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s.charAt(j) == '.') {
                if (e > 0 || dot > 0) {
                    return false;
                }
                ++dot;
            } else if (s.charAt(j) == 'e' || s.charAt(j) == 'E') {
                if (e > 0 || j == i || j == n - 1) {
                    return false;
                }
                ++e;
                if (s.charAt(j + 1) == '+' || s.charAt(j + 1) == '-') {
                    if (++j == n - 1) {
                        return false;
                    }
                }
            } else if (s.charAt(j) < '0' || s.charAt(j) > '9') {
                return false;
            }
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0065  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)  # 获取字符串长度
        i = 0  # 初始化索引指针
        if s[i] in '+-':  # 检查开头是否有正负号
            i += 1  # 跳过正负号
        if i == n:  # 如果只有正负号没有数字
            return False  # 返回无效
        if s[i] == '.' and (i + 1 == n or s[i + 1] in 'eE'):  # 检查小数点后是否为空或跟着e/E
            return False  # 返回无效
        dot = e = 0  # 初始化小数点和小写e的计数器
        j = i  # 从当前位置开始遍历
        while j < n:  # 遍历整个字符串
            if s[j] == '.':  # 遇到小数点
                if e or dot:  # 如果已经存在e或小数点
                    return False  # 返回无效
                dot += 1  # 记录小数点出现
            elif s[j] in 'eE':  # 遇到指数符号
                if e or j == i or j == n - 1:  # 如果已经存在e，或者e在开头，或者e在结尾
                    return False  # 返回无效
                e += 1  # 记录e出现
                if s[j + 1] in '+-':  # 检查e后面是否有正负号
                    j += 1  # 跳过正负号
                    if j == n - 1:  # 如果正负号是最后一个字符
                        return False  # 返回无效
            elif not s[j].isnumeric():  # 如果不是数字字符
                return False  # 返回无效
            j += 1  # 移动到下一个字符
        return True  # 所有检查通过，返回有效
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == n) return false;
        if (s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) return false;
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '.') {
                if (e || dot) return false;
                ++dot;
            } else if (s[j] == 'e' || s[j] == 'E') {
                if (e || j == i || j == n - 1) return false;
                ++e;
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    if (++j == n - 1) return false;
                }
            } else if (s[j] < '0' || s[j] > '9')
                return false;
        }
        return true;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isNumber(String s) {
        int n = s.length();
        int i = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            ++i;
        }
        if (i == n) {
            return false;
        }
        if (s.charAt(i) == '.'
            && (i + 1 == n || s.charAt(i + 1) == 'e' || s.charAt(i + 1) == 'E')) {
            return false;
        }
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s.charAt(j) == '.') {
                if (e > 0 || dot > 0) {
                    return false;
                }
                ++dot;
            } else if (s.charAt(j) == 'e' || s.charAt(j) == 'E') {
                if (e > 0 || j == i || j == n - 1) {
                    return false;
                }
                ++e;
                if (s.charAt(j + 1) == '+' || s.charAt(j + 1) == '-') {
                    if (++j == n - 1) {
                        return false;
                    }
                }
            } else if (s.charAt(j) < '0' || s.charAt(j) > '9') {
                return false;
            }
        }
        return true;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0065  数学解释

```python 
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        i = 0
        if s[i] in '+-':
            i += 1
        if i == n:
            return False
        if s[i] == '.' and (i + 1 == n or s[i + 1] in 'eE'):
            return False
        dot = e = 0
        j = i
        while j < n:
            if s[j] == '.':
                if e or dot:
                    return False
                dot += 1
            elif s[j] in 'eE':
                if e or j == i or j == n - 1:
                    return False
                e += 1
                if s[j + 1] in '+-':
                    j += 1
                    if j == n - 1:
                        return False
            elif not s[j].isnumeric():
                return False
            j += 1
        return True 
```


这段代码实现了一个判断字符串是否为有效数字的函数。让我用数学思想来解释其逻辑：

## 有限状态自动机思想

代码实现了一个**确定性有限自动机(DFA)**，通过状态转移来验证数字格式：

### 初始状态处理
1. **符号位检查**：允许开头的'+'或'-'（类似于数学中的正负号）
2. **边界检查**：确保符号后还有内容（不能只有符号）

### 核心验证逻辑
代码维护两个计数器：
- `dot`：小数点出现次数（数学中只能有1个小数点）
- `e`：科学计数法标记出现次数（数学中只能有1个指数标记）

### 状态转移规则
1. **遇到小数点**：
   - 不能在指数部分之后（e之后不能有小数点）
   - 不能重复出现（数学中数字最多1个小数点）

2. **遇到指数标记**：
   - 不能重复出现
   - 不能在开头或结尾（e前后必须有数字）
   - 允许e后接符号（如"1e-2"）

3. **数字验证**：
   - 所有非特殊字符必须是数字（数学中的数字字符）

### 数学等价性
这相当于验证字符串是否满足正则表达式：
`[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?`

代码通过**逐步状态转移**和**约束条件检查**，确保输入字符串符合数学上有效数字的定义，体现了**形式语言与自动机理论**在编程中的实际应用。



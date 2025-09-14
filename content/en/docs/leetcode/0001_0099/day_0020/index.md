---
title: "day_0020 "
date: 2025-09-14T11:09:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0020 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        d = {'()', '[]', '{}'}
        for c in s:
            if c in '({[':
                stk.append(c)
            elif not stk or stk.pop() + c not in d:
                return False
        return not stk 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (stk.isEmpty() || !match(stk.pop(), c)) {
                return false;
            }
        }
        return stk.isEmpty();
    }

    private boolean match(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0020  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []  # 使用栈来存储左括号
        d = {'()', '[]', '{}'}  # 定义有效的括号对集合
        for c in s:  # 遍历字符串中的每个字符
            if c in '({[':  # 如果是左括号
                stk.append(c)  # 压入栈中
            elif not stk or stk.pop() + c not in d:  # 如果是右括号且栈为空或括号不匹配
                return False  # 返回无效
        return not stk  # 检查栈是否为空，为空则所有括号都匹配
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push_back(c);
            else if (stk.empty() || !match(stk.back(), c))
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else if (stk.isEmpty() || !match(stk.pop(), c)) {
                return false;
            }
        }
        return stk.isEmpty();
    }

    private boolean match(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0020  数学解释

```python 
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        d = {'()', '[]', '{}'}
        for c in s:
            if c in '({[':
                stk.append(c)
            elif not stk or stk.pop() + c not in d:
                return False
        return not stk 
```


这段代码使用了**栈(stack)**这一数据结构和**哈希集合(hash set)**来实现括号匹配验证，体现了以下数学思想：

1. **栈的LIFO特性**（后进先出）：
   - 数学上对应着**最近匹配原则** - 最后打开的括号必须最先闭合
   - 这反映了括号嵌套的层次结构：`{ [ ( ) ] }`

2. **集合运算的高效性**：
   - 使用集合`d = {'()', '[]', '{}'}`来存储有效的括号对
   - 数学上体现了**成员关系测试**的思想，`not in`操作的时间复杂度为O(1)

3. **布尔逻辑与条件判断**：
   - `not stk or stk.pop() + c not in d` 体现了逻辑或运算
   - 最终`return not stk`确保所有开括号都被正确闭合

4. **字符串的组合验证**：
   - `stk.pop() + c`将栈顶元素与当前字符组合成字符串
   - 验证这个组合是否在有效括号集合中

**算法正确性证明思路**：
- 如果字符串有效，所有开括号都会被压入栈并在遇到匹配的闭括号时弹出
- 如果遇到不匹配的闭括号或栈为空时遇到闭括号，立即返回False
- 最终栈必须为空才能返回True，确保没有未闭合的开括号

这个解决方案的时间复杂度为O(n)，空间复杂度为O(n)，是验证括号有效性的经典算法实现。

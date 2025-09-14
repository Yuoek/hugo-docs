---
title: "day_0071 "
date: 2025-09-14T08:56:08+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0071 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []
        for s in path.split('/'):
            if not s or s == '.':
                continue
            if s == '..':
                if stk:
                    stk.pop()
            else:
                stk.append(s)
        return '/' + '/'.join(stk) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;
        stringstream ss(path);
        string t;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") {
                continue;
            }
            if (t == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(t);
            }
        }
        if (stk.empty()) {
            return "/";
        }
        string ans;
        for (auto& s : stk) {
            ans += "/" + s;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String simplifyPath(String path) {
        Deque<String> stk = new ArrayDeque<>();
        for (String s : path.split("/")) {
            if ("".equals(s) || ".".equals(s)) {
                continue;
            }
            if ("..".equals(s)) {
                stk.pollLast();
            } else {
                stk.offerLast(s);
            }
        }
        return "/" + String.join("/", stk);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0071  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []  # 使用栈来存储有效的路径部分
        for s in path.split('/'):  # 按'/'分割路径字符串
            if not s or s == '.':  # 忽略空字符串和当前目录'.'
                continue
            if s == '..':  # 遇到上级目录'..'
                if stk:  # 如果栈不为空
                    stk.pop()  # 弹出栈顶元素（返回上一级目录）
            else:
                stk.append(s)  # 将有效的目录名压入栈中
        return '/' + '/'.join(stk)  # 用'/'连接栈中元素并返回绝对路径
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;
        stringstream ss(path);
        string t;
        while (getline(ss, t, '/')) {
            if (t == "" || t == ".") {
                continue;
            }
            if (t == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(t);
            }
        }
        if (stk.empty()) {
            return "/";
        }
        string ans;
        for (auto& s : stk) {
            ans += "/" + s;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String simplifyPath(String path) {
        Deque<String> stk = new ArrayDeque<>();
        for (String s : path.split("/")) {
            if ("".equals(s) || ".".equals(s)) {
                continue;
            }
            if ("..".equals(s)) {
                stk.pollLast();
            } else {
                stk.offerLast(s);
            }
        }
        return "/" + String.join("/", stk);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0071  数学解释

```python 
class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []
        for s in path.split('/'):
            if not s or s == '.':
                continue
            if s == '..':
                if stk:
                    stk.pop()
            else:
                stk.append(s)
        return '/' + '/'.join(stk) 
```


这段代码使用了**栈数据结构**和**字符串分割**的数学思想来解决Unix路径简化问题。

核心数学思想：
1. **栈的LIFO特性**：利用栈的后进先出特性来处理目录层级关系
2. **状态机思想**：将路径分解为不同状态（目录名、"."、".."、空字符串）
3. **集合划分**：将路径字符串按"/"分割成不同的子字符串集合

算法步骤的数学解释：
- 将路径按"/"分割得到字符串集合：`path.split('/')`
- 对每个字符串元素进行分类处理：
  - 空字符串或"."：保持当前状态（数学上的恒等操作）
  - ".."：回退到上一级目录（栈的pop操作，相当于状态回退）
  - 其他字符串：进入新目录（栈的push操作，相当于状态推进）

最终通过`'/'.join(stk)`将栈中元素重新连接，形成简化后的规范路径。

这种解法的时间复杂度为O(n)，空间复杂度为O(n)，其中n为路径长度，体现了用合适的数据结构高效解决问题的数学思想。


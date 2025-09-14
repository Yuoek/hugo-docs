---
title: "day_0006 "
date: 2025-09-14T11:38:44+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0006 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        g = [[] for _ in range(numRows)]
        i, k = 0, -1
        for c in s:
            g[i].append(c)
            if i == 0 or i == numRows - 1:
                k = -k
            i += k
        return ''.join(chain(*g)) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> g(numRows);
        int i = 0, k = -1;
        for (char c : s) {
            g[i] += c;
            if (i == 0 || i == numRows - 1) {
                k = -k;
            }
            i += k;
        }
        string ans;
        for (auto& t : g) {
            ans += t;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuilder[] g = new StringBuilder[numRows];
        Arrays.setAll(g, k -> new StringBuilder());
        int i = 0, k = -1;
        for (char c : s.toCharArray()) {
            g[i].append(c);
            if (i == 0 || i == numRows - 1) {
                k = -k;
            }
            i += k;
        }
        return String.join("", g);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0006  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:  # 如果只有一行，直接返回原字符串
            return s
        g = [[] for _ in range(numRows)]  # 创建numRows个空列表，用于存储每行的字符
        i, k = 0, -1  # i表示当前行索引，k表示方向（1向下，-1向上）
        for c in s:  # 遍历字符串中的每个字符
            g[i].append(c)  # 将字符添加到对应行的列表中
            if i == 0 or i == numRows - 1:  # 如果到达顶部或底部
                k = -k  # 反转方向
            i += k  # 移动到下一行
        return ''.join(chain(*g))  # 将所有行的字符连接成一个字符串返回
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> g(numRows);
        int i = 0, k = -1;
        for (char c : s) {
            g[i] += c;
            if (i == 0 || i == numRows - 1) {
                k = -k;
            }
            i += k;
        }
        string ans;
        for (auto& t : g) {
            ans += t;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuilder[] g = new StringBuilder[numRows];
        Arrays.setAll(g, k -> new StringBuilder());
        int i = 0, k = -1;
        for (char c : s.toCharArray()) {
            g[i].append(c);
            if (i == 0 || i == numRows - 1) {
                k = -k;
            }
            i += k;
        }
        return String.join("", g);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0006  数学解释

```python 
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        g = [[] for _ in range(numRows)]
        i, k = 0, -1
        for c in s:
            g[i].append(c)
            if i == 0 or i == numRows - 1:
                k = -k
            i += k
        return ''.join(chain(*g)) 
```


这段代码实现了Z字形变换，其数学思想可以解释为：

## 核心思想：周期性运动与方向反转

### 1. 周期性运动模式
Z字形变换本质上是一个在有限行数范围内的周期性上下运动：
- 当运动到底部时（i = numRows-1），方向反转向上
- 当运动到顶部时（i = 0），方向反转向下

### 2. 数学建模
这可以看作是一个**有界振荡系统**：
- **状态变量**：当前行索引 i
- **控制参数**：方向变量 k（±1）
- **边界条件**：i ∈ [0, numRows-1]
- **触发条件**：当 i 到达边界时，k 取反（k = -k）

### 3. 离散数学表示
运动轨迹可以描述为：
```
iₜ₊₁ = iₜ + kₜ
kₜ₊₁ = { -kₜ, 当 iₜ = 0 或 iₜ = numRows-1
        kₜ,   否则 }
```

### 4. 算法复杂度
- **时间复杂度**：O(n)，每个字符处理一次
- **空间复杂度**：O(n)，存储所有字符

### 5. 数学优化
代码通过简单的方向反转机制，避免了复杂的数学计算，用最简洁的方式实现了Z字形的遍历路径，体现了**用简单规则描述复杂模式**的数学思想。


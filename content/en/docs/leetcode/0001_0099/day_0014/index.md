---
title: "day_0014 "
date: 2025-09-14T11:23:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0014 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        for i in range(len(strs[0])):
            for s in strs[1:]:
                if len(s) <= i or s[i] != strs[0][i]:
                    return s[:i]
        return strs[0] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].length() <= i || strs[j].charAt(i) != strs[0].charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0014  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # 遍历第一个字符串的每个字符
        for i in range(len(strs[0])):
            # 检查其他所有字符串
            for s in strs[1:]:
                # 如果当前字符串长度不够或者字符不匹配
                if len(s) <= i or s[i] != strs[0][i]:
                    # 返回当前已匹配的前缀部分
                    return s[:i]
        # 如果第一个字符串的所有字符都匹配成功，返回整个第一个字符串
        return strs[0] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < n; ++j) {
                if (strs[j].length() <= i || strs[j].charAt(i) != strs[0].charAt(i)) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0014  数学解释

```python 
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        for i in range(len(strs[0])):
            for s in strs[1:]:
                if len(s) <= i or s[i] != strs[0][i]:
                    return s[:i]
        return strs[0] 
```


这段代码使用了**贪心算法**的思想来寻找字符串数组中的最长公共前缀。

## 数学思想解释：

### 1. **贪心选择性质**
代码采用逐字符比较的方式，从第一个字符串的第一个字符开始，依次检查所有字符串在相同位置上的字符是否相同。这是一种**局部最优选择**：如果当前字符在所有字符串中都相同，就继续检查下一个字符；一旦发现不匹配，立即返回当前已匹配的前缀。

### 2. **数学归纳法思维**
- **基础情况**：空字符串数组（虽然代码假设至少有一个字符串）
- **归纳步骤**：假设前i个字符是公共前缀，验证第i+1个字符是否也是公共的
- **终止条件**：当发现某个位置字符不匹配或某个字符串长度不足时终止

### 3. **最坏情况分析**
- 时间复杂度：O(n*m)，其中n是字符串数量，m是最短字符串长度
- 空间复杂度：O(1)，只使用了常数级别的额外空间

### 4. **边界处理**
- 处理了字符串长度不一致的情况（`len(s) <= i`）
- 处理了空字符串数组的情况（虽然代码假设至少有一个字符串）

这种算法体现了**逐步构建解**的思想，每一步都确保当前字符满足公共前缀的条件，直到无法继续扩展为止，最终得到的就是最优解（最长公共前缀）。



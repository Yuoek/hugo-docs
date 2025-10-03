---
title: "day_0012 "
date: 2025-09-14T11:27:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0012 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def intToRoman(self, num: int) -> str:
        cs = ('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
        vs = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        ans = []
        for c, v in zip(cs, vs):
            while num >= v:
                num -= v
                ans.append(c)
        return ''.join(ans) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string intToRoman(int num) {
        vector<string> cs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            while (num >= vs[i]) {
                num -= vs[i];
                ans += cs[i];
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String intToRoman(int num) {
        List<String> cs
            = List.of("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I");
        List<Integer> vs = List.of(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1);
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = cs.size(); i < n; ++i) {
            while (num >= vs.get(i)) {
                num -= vs.get(i);
                ans.append(cs.get(i));
            }
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0012  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def intToRoman(self, num: int) -> str:
        # 定义罗马数字符号和对应的数值
        cs = ('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
        vs = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        
        ans = []  # 存储结果的列表
        
        # 遍历每个罗马数字符号和对应的数值
        for c, v in zip(cs, vs):
            # 当当前数值小于等于剩余数字时，重复添加对应的罗马数字
            while num >= v:
                num -= v      # 减去已转换的数值
                ans.append(c)  # 添加对应的罗马数字符号
        
        return ''.join(ans)  # 将列表中的字符连接成字符串返回
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string intToRoman(int num) {
        vector<string> cs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> vs = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            while (num >= vs[i]) {
                num -= vs[i];
                ans += cs[i];
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String intToRoman(int num) {
        List<String> cs
            = List.of("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I");
        List<Integer> vs = List.of(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1);
        StringBuilder ans = new StringBuilder();
        for (int i = 0, n = cs.size(); i < n; ++i) {
            while (num >= vs.get(i)) {
                num -= vs.get(i);
                ans.append(cs.get(i));
            }
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0012  数学解释

```python 
class Solution:
    def intToRoman(self, num: int) -> str:
        cs = ('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
        vs = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        ans = []
        for c, v in zip(cs, vs):
            while num >= v:
                num -= v
                ans.append(c)
        return ''.join(ans) 
```


这段代码使用了**贪心算法**的数学思想来解决整数转罗马数字的问题。

## 核心思想
贪心算法：在每一步选择当前最优解，希望通过局部最优达到全局最优。

## 具体实现分析

1. **数据结构设计**：
   - `cs`：按从大到小顺序排列的罗马数字符号
   - `vs`：对应的数值，与`cs`一一对应
   - 这种排列确保了优先使用较大的数值单位

2. **贪心策略**：
   - 从最大的数值单位（1000）开始尝试
   - 只要当前数值`num`大于等于某个单位值`v`，就减去该值并记录对应的罗马符号
   - 重复此过程直到`num`为0

3. **数学原理**：
   - 罗马数字的表示规则要求：较大的符号在前，较小的在后
   - 通过从大到小遍历，确保总是使用当前可用的最大数值单位
   - 这种贪心选择能够保证结果的正确性和最优性

## 为什么贪心算法有效？
因为罗马数字的表示具有**无后效性**：选择较大的数值单位不会影响后续的选择，且总能得到正确的表示。

## 时间复杂度
O(1)，因为罗马数字的单位数量是固定的（13个），与输入数字大小无关。

## 空间复杂度
O(1)，只使用了固定大小的数组和字符串构建器。

这种解法巧妙地利用了罗马数字的表示特性和贪心算法的优势，简洁高效地解决了问题。

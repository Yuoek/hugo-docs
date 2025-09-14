---
title: "day_0013 "
date: 2025-09-14T11:25:28+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0013 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        return sum((-1 if d[a] < d[b] else 1) * d[a] for a, b in pairwise(s)) + d[s[-1]] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> nums{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = nums[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            int sign = nums[s[i]] < nums[s[i + 1]] ? -1 : 1;
            ans += sign * nums[s[i]];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int romanToInt(String s) {
        String cs = "IVXLCDM";
        int[] vs = {1, 5, 10, 50, 100, 500, 1000};
        Map<Character, Integer> d = new HashMap<>();
        for (int i = 0; i < vs.length; ++i) {
            d.put(cs.charAt(i), vs[i]);
        }
        int n = s.length();
        int ans = d.get(s.charAt(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            int sign = d.get(s.charAt(i)) < d.get(s.charAt(i + 1)) ? -1 : 1;
            ans += sign * d.get(s.charAt(i));
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0013  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def romanToInt(self, s: str) -> int:
        # 创建罗马数字到整数的映射字典
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        # 使用pairwise遍历相邻字符对，根据规则计算值（如果前一个字符小于后一个，则减前一个值，否则加前一个值），最后加上最后一个字符的值
        return sum((-1 if d[a] < d[b] else 1) * d[a] for a, b in pairwise(s)) + d[s[-1]] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> nums{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int ans = nums[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            int sign = nums[s[i]] < nums[s[i + 1]] ? -1 : 1;
            ans += sign * nums[s[i]];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int romanToInt(String s) {
        String cs = "IVXLCDM";
        int[] vs = {1, 5, 10, 50, 100, 500, 1000};
        Map<Character, Integer> d = new HashMap<>();
        for (int i = 0; i < vs.length; ++i) {
            d.put(cs.charAt(i), vs[i]);
        }
        int n = s.length();
        int ans = d.get(s.charAt(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            int sign = d.get(s.charAt(i)) < d.get(s.charAt(i + 1)) ? -1 : 1;
            ans += sign * d.get(s.charAt(i));
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0013  数学解释

```python 
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        return sum((-1 if d[a] < d[b] else 1) * d[a] for a, b in pairwise(s)) + d[s[-1]] 
```


这段代码使用了**贪心算法**和**数学归纳法**的思想来解决罗马数字转整数问题：

## 核心数学思想

### 1. 贪心选择性质
- 从左到右扫描罗马数字，每次处理两个相邻字符
- 对于每对字符 `(a, b)`，如果 `a < b`（如 IV=4），则减去 `a` 的值
- 如果 `a ≥ b`（如 VI=6），则加上 `a` 的值

### 2. 数学归纳法结构
- 基础情况：最后一个字符总是加（因为没有后续字符可比较）
- 归纳步骤：对于前 n-1 个字符，通过相邻比较确定加减符号
- 最终结果 = 前 n-1 个字符的符号加权和 + 最后一个字符的值

### 3. 数学表达式
```
result = Σ [sign(a_i, a_{i+1}) × value(a_i)] + value(a_n)
其中 sign(a, b) = -1 当 value(a) < value(b)，否则为 1
```

## 算法复杂度
- **时间复杂度**: O(n)，只需遍历字符串一次
- **空间复杂度**: O(1)，只使用了固定大小的字典

这种解法巧妙地利用了罗马数字的减法规则，通过相邻字符的比较来确定加减操作，体现了数学中"局部最优选择导致全局最优解"的贪心思想。


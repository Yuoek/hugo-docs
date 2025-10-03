---
title: "day_0029 "
date: 2025-09-14T10:52:25+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0029 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def divide(self, a: int, b: int) -> int:
        if b == 1:
            return a
        if a == -(2**31) and b == -1:
            return 2**31 - 1
        sign = (a > 0 and b > 0) or (a < 0 and b < 0)
        a = -a if a > 0 else a
        b = -b if b > 0 else b
        ans = 0
        while a <= b:
            x = b
            cnt = 1
            while x >= (-(2**30)) and a <= (x << 1):
                x <<= 1
                cnt <<= 1
            a -= x
            ans += cnt
        return ans if sign else -ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (Integer.MIN_VALUE >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0029  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def divide(self, a: int, b: int) -> int:
        if b == 1:
            return a
        if a == -(2**31) and b == -1:
            return 2**31 - 1
        sign = (a > 0 and b > 0) or (a < 0 and b < 0)
        a = -a if a > 0 else a
        b = -b if b > 0 else b
        ans = 0
        while a <= b:
            x = b
            cnt = 1
            while x >= (-(2**30)) and a <= (x << 1):
                x <<= 1
                cnt <<= 1
            a -= x
            ans += cnt
        return ans if sign else -ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (Integer.MIN_VALUE >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0029  数学解释

```python 
class Solution:
    def divide(self, a: int, b: int) -> int:
        if b == 1:  # 如果除数是1，直接返回被除数
            return a
        if a == -(2**31) and b == -1:  # 处理32位整数的最小值除以-1的特殊情况
            return 2**31 - 1
        sign = (a > 0 and b > 0) or (a < 0 and b < 0)  # 判断结果的正负号
        a = -a if a > 0 else a  # 将被除数转为负数（避免正数溢出）
        b = -b if b > 0 else b  # 将除数转为负数
        ans = 0  # 初始化结果
        while a <= b:  # 当被除数大于等于除数时继续循环
            x = b  # 当前除数倍数
            cnt = 1  # 当前倍数对应的商
            while x >= (-(2**30)) and a <= (x << 1):  # 找到最大的除数倍数（不超过被除数）
                x <<= 1  # 除数翻倍
                cnt <<= 1  # 商相应翻倍
            a -= x  # 减去当前最大的除数倍数
            ans += cnt  # 累加商
        return ans if sign else -ans  # 根据符号返回最终结果
```

这段代码实现的是整数除法（不使用乘法、除法和取模运算符），其数学思想主要基于以下原理：

## 核心数学思想：二进制分解与移位运算

### 1. 符号处理
- 通过判断被除数a和除数b的符号是否相同来确定结果的符号
- 将a和b都转换为负数来处理（避免正数边界问题）

### 2. 快速除法算法
- **基本原理**：任何数都可以表示为二进制形式，除法可以分解为多个2的幂次方的和
- **数学表达式**：a ÷ b = 2ⁿ + 2ⁿ⁻¹ + ... + 2⁰

### 3. 移位运算的数学意义
- `x << 1` 等价于 x × 2（二进制左移一位）
- `cnt << 1` 等价于 cnt × 2（记录倍数关系）

### 4. 算法步骤的数学解释
1. **外层循环**：当a ≤ b时（因为都是负数，所以实际是|a| ≥ |b|）
2. **内层循环**：找到最大的2的幂次k，使得 b × 2ᵏ ≤ a
   - 通过不断左移（乘以2）来快速逼近
3. **减法操作**：a = a - (b × 2ᵏ)，这相当于从被除数中减去当前最大的倍数
4. **累加结果**：ans = ans + 2ᵏ

### 5. 数学优化
- 使用移位运算代替乘法，时间复杂度从O(n)优化到O(log n)
- 处理边界情况：32位整数的最小值(-2³¹)除以-1的特殊情况

### 6. 数学等价性
代码实现的算法在数学上等价于：
```
result = 0
while |a| ≥ |b|:
    k = max{2ⁿ | |b|×2ⁿ ≤ |a|}
    result += 2ⁿ
    a = a - b×2ⁿ
```

这种算法体现了**分治思想**和**二进制分解**的数学原理，通过将除法问题转化为多个2的幂次方的组合来高效求解。



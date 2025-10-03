---
title: "day_0050 "
date: 2025-09-14T10:02:00+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0050 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def qpow(a: float, n: int) -> float:
            ans = 1
            while n:
                if n & 1:
                    ans *= a
                a *= a
                n >>= 1
            return ans

        return qpow(x, n) if n >= 0 else 1 / qpow(x, -n) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    double myPow(double x, int n) {
        auto qpow = [](double a, long long n) {
            double ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long) n);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public double myPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long) n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a;
            }
            a = a * a;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0050  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def qpow(a: float, n: int) -> float:
            ans = 1  # 初始化结果为1
            while n:  # 当n不为0时循环
                if n & 1:  # 如果n是奇数（二进制最后一位为1）
                    ans *= a  # 将当前a乘入结果
                a *= a  # a自乘（相当于a的平方）
                n >>= 1  # n右移一位（相当于n除以2）
            return ans

        return qpow(x, n) if n >= 0 else 1 / qpow(x, -n)  # 处理正负指数情况
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    double myPow(double x, int n) {
        auto qpow = [](double a, long long n) {
            double ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long) n);
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public double myPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long) n);
    }

    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a;
            }
            a = a * a;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0050  数学解释

```python 
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def qpow(a: float, n: int) -> float:
            ans = 1
            while n:
                if n & 1:
                    ans *= a
                a *= a
                n >>= 1
            return ans

        return qpow(x, n) if n >= 0 else 1 / qpow(x, -n) 
```


这段代码实现了快速幂算法来计算 x 的 n 次幂，其数学思想主要基于：

## 1. 二进制分解思想
将指数 n 用二进制表示，比如：
- 13 = 1101₂ = 8 + 4 + 1
- x¹³ = x⁸ × x⁴ × x¹

## 2. 幂的乘法性质
利用幂运算的性质：x^(a+b) = x^a × x^b

## 3. 迭代平方技巧
通过不断平方底数来快速计算高次幂：
- 每次循环中：a = a²（计算 x¹, x², x⁴, x⁸, ...）
- 当 n 的二进制位为 1 时，将对应的幂乘入结果

## 4. 负指数处理
利用数学恒等式：x⁻ⁿ = 1/xⁿ

## 时间复杂度分析
- 传统方法：O(n) 次乘法
- 快速幂：O(log n) 次乘法（因为 n 的二进制位数是 log₂n）

这种算法将指数运算的时间复杂度从线性降低到对数级别，是计算机科学中经典的优化技巧。



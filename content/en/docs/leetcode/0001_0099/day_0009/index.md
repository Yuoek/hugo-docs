---
title: "day_0009 "
date: 2025-09-14T11:32:30+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0009 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x and x % 10 == 0):
            return False
        y = 0
        while y < x:
            y = y * 10 + x % 10
            x //= 10
        return x in (y, y // 10) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x && x % 10 == 0)) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
        }
        return x == y || x == y / 10;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
        }
        return x == y || x == y / 10;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0009  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x and x % 10 == 0):  # 负数或者以0结尾的正数都不是回文数
            return False
        y = 0  # 初始化反转数字变量
        while y < x:  # 当反转数字小于原数字时继续循环
            y = y * 10 + x % 10  # 将原数字的最后一位加到反转数字上
            x //= 10  # 原数字去掉最后一位
        return x in (y, y // 10)  # 比较反转数字和剩余原数字是否相等
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x && x % 10 == 0)) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
        }
        return x == y || x == y / 10;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
        }
        return x == y || x == y / 10;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0009  数学解释

```python 
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x and x % 10 == 0):
            return False
        y = 0
        while y < x:
            y = y * 10 + x % 10
            x //= 10
        return x in (y, y // 10) 
```


这段代码使用了**双指针思想**和**数学运算**来判断一个整数是否为回文数：

1. **边界条件处理**（数学排除法）：
   - 负数不可能是回文数（`x < 0`）
   - 非零数但以0结尾的不可能是回文数（`x % 10 == 0`）

2. **核心算法**（数字反转比较）：
   - 使用**双指针思想**：将数字从中间"拆分"，同时从两端向中间比较
   - 通过数学运算构建反转的后半部分数字 `y`
   - 循环条件 `y < x` 确保只处理数字的一半（避免完全反转）

3. **回文判断**（对称性检验）：
   - 对于偶数位数字：`x == y`（前后完全对称）
   - 对于奇数位数字：`x == y // 10`（中间数字不需要比较）

**数学原理**：通过不断取模和整除操作，将原数字的后半部分反转，然后与前半部分比较，利用回文数的对称特性进行验证。

这种方法的时间复杂度为 O(log₁₀n)，空间复杂度为 O(1)，是判断回文数的高效算法。


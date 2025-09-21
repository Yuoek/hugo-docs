---
title: "day_0190 "
date: 2025-09-21T08:03:53+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0190 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans |= (n & 1) << (31 - i)
            n >>= 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32 && n; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32 && n != 0; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>>= 1;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0190  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0  # 初始化结果变量为0
        for i in range(32):  # 遍历32位（因为n是32位无符号整数）
            ans |= (n & 1) << (31 - i)  # 获取n的最低位，然后左移到对应位置，合并到结果中
            n >>= 1  # n右移1位，处理下一位
        return ans  # 返回反转后的结果
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32 && n; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32 && n != 0; ++i) {
            ans |= (n & 1) << (31 - i);
            n >>>= 1;
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0190  数学解释

```python 
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans |= (n & 1) << (31 - i)
            n >>= 1
        return ans 
```


这段代码使用**位运算**和**循环移位**的数学思想来实现32位无符号整数的位反转。

核心数学思想：
1. **逐位提取**：通过 `n & 1` 获取n的最低位（第0位）
2. **位对齐**：将提取的位左移 `(31 - i)` 位，使其到达反转后的正确位置
3. **位累积**：使用 `|=` 操作将每个处理后的位合并到结果中
4. **移位处理**：每次循环后 `n >>= 1` 将n右移一位，处理下一个位

数学过程：
- 第i次循环处理原数的第i位，将其放置到结果的第(31-i)位
- 相当于构建映射：f(i) = 31 - i（位位置映射）
- 最终完成从最低位到最高位的完全反转

时间复杂度：O(1)（固定32次循环）
空间复杂度：O(1)（只使用常数空间）


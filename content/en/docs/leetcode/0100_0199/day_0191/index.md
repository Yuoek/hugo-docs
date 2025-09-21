---
title: "day_0191 "
date: 2025-09-21T08:00:48+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0191 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n &= n - 1
            ans += 1
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
}  
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0191  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0  # 初始化计数器，用于统计1的个数
        while n:  # 当n不为0时循环
            n &= n - 1  # 清除最低位的1（Brian Kernighan算法）
            ans += 1  # 每清除一个1，计数器加1
        return ans  # 返回1的总个数
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
}  
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0191  数学解释

```python 
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n &= n - 1
            ans += 1
        return ans 
```


这段代码使用了**Brian Kernighan算法**来计算二进制数中1的个数（汉明重量），其数学思想是：

**核心数学原理**：`n & (n-1)` 操作会将n的最低位的1变为0

**数学解释**：
1. 对于任意二进制数n，n-1会将最低位的1变为0，并将该位之后的所有0变为1
2. 按位与操作 `n & (n-1)` 会消除最低位的1，同时保持其他位不变
3. 每次执行这个操作就消除一个1，计数器加1
4. 当n变为0时，说明所有1都被消除

**示例**（以n=13为例，二进制为1101）：
- 第一次：1101 & 1100 = 1100 (消除最低位的1)
- 第二次：1100 & 1011 = 1000 (消除下一个1)  
- 第三次：1000 & 0111 = 0000 (消除最后一个1)

**时间复杂度**：O(k)，其中k是二进制表示中1的个数，比遍历所有位的O(32)更高效

**数学优势**：这种方法巧妙地利用了二进制数的位运算特性，避免了逐位检查，效率更高。

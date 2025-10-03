---
title: "day_0066 "
date: 2025-09-14T09:18:34+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0066 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            digits[i] += 1
            digits[i] %= 10
            if digits[i] != 0:
                return digits
        return [1] + digits 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = n - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0066  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)  # 获取数字列表的长度
        for i in range(n - 1, -1, -1):  # 从最后一位开始向前遍历
            digits[i] += 1  # 当前位加1
            digits[i] %= 10  # 如果加1后等于10，取模得到0
            if digits[i] != 0:  # 如果当前位不为0，说明没有进位，直接返回
                return digits
        return [1] + digits  # 如果所有位都进位了，在最前面添加1
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = n - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0066  数学解释

```python 
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            digits[i] += 1
            digits[i] %= 10
            if digits[i] != 0:
                return digits
        return [1] + digits 
```


这段代码实现的是"加一"操作，可以用**进位制的数学思想**来解释：

## 核心数学思想：十进制进位制

### 1. 问题本质
给定一个表示数字的数组（如 [1,2,3] 表示 123），实现加一操作

### 2. 算法思路
从**最低位（最右边）开始处理**，模拟手工加法运算：
- 当前位加1
- 如果结果小于10，直接返回（无进位）
- 如果等于10，则当前位变为0，并向高位进位（继续循环）

### 3. 数学原理
- **模运算**：`digits[i] %= 10` 确保每位数字在0-9范围内
- **进位机制**：当某位变为0时，表示产生了进位，需要继续处理更高位
- **最高位进位**：如果所有位都处理完还有进位（即首位也变成了0），需要在最前面补1

### 4. 特殊情况处理
当数字为 999...9 时，加一会变成 1000...0，这就是最后一行 `return [1] + digits` 的数学意义

### 5. 时间复杂度
O(n)，其中n是数字的位数，最坏情况下需要处理所有位

这种解法巧妙地运用了十进制数的进位特性，通过反向遍历和模运算高效地解决了问题。



---
title: "day_0043 "
date: 2025-09-14T10:19:50+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0043 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        arr = [0] * (m + n)
        for i in range(m - 1, -1, -1):
            a = int(num1[i])
            for j in range(n - 1, -1, -1):
                b = int(num2[j])
                arr[i + j + 1] += a * b
        for i in range(m + n - 1, 0, -1):
            arr[i - 1] += arr[i] // 10
            arr[i] %= 10
        i = 0 if arr[0] else 1
        return "".join(str(x) for x in arr[i:]) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.size() - 1; i; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] ? 0 : 1;
        string ans;
        for (; i < arr.size(); ++i) {
            ans += '0' + arr[i];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String multiply(String num1, String num2) {
        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }
        int m = num1.length(), n = num2.length();
        int[] arr = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            int a = num1.charAt(i) - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2.charAt(j) - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.length - 1; i > 0; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] == 0 ? 1 : 0;
        StringBuilder ans = new StringBuilder();
        for (; i < arr.length; ++i) {
            ans.append(arr[i]);
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0043  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":  # 如果任一数字为0，直接返回"0"
            return "0"
        m, n = len(num1), len(num2)  # 获取两个数字字符串的长度
        arr = [0] * (m + n)  # 创建足够长的数组来存储乘积结果
        
        # 从右到左遍历两个数字的每一位
        for i in range(m - 1, -1, -1):
            a = int(num1[i])  # 获取num1当前位的数字
            for j in range(n - 1, -1, -1):
                b = int(num2[j])  # 获取num2当前位的数字
                arr[i + j + 1] += a * b  # 将乘积加到对应位置
        
        # 处理进位
        for i in range(m + n - 1, 0, -1):
            arr[i - 1] += arr[i] // 10  # 将当前位的进位加到前一位
            arr[i] %= 10  # 当前位只保留个位数
        
        # 跳过前导零
        i = 0 if arr[0] else 1  # 如果第一位不为0则从0开始，否则从1开始
        return "".join(str(x) for x in arr[i:])  # 将数组转换为字符串返回
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; --i) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.size() - 1; i; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] ? 0 : 1;
        string ans;
        for (; i < arr.size(); ++i) {
            ans += '0' + arr[i];
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String multiply(String num1, String num2) {
        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }
        int m = num1.length(), n = num2.length();
        int[] arr = new int[m + n];
        for (int i = m - 1; i >= 0; --i) {
            int a = num1.charAt(i) - '0';
            for (int j = n - 1; j >= 0; --j) {
                int b = num2.charAt(j) - '0';
                arr[i + j + 1] += a * b;
            }
        }
        for (int i = arr.length - 1; i > 0; --i) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        int i = arr[0] == 0 ? 1 : 0;
        StringBuilder ans = new StringBuilder();
        for (; i < arr.length; ++i) {
            ans.append(arr[i]);
        }
        return ans.toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0043  数学解释

```python 
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        arr = [0] * (m + n)
        for i in range(m - 1, -1, -1):
            a = int(num1[i])
            for j in range(n - 1, -1, -1):
                b = int(num2[j])
                arr[i + j + 1] += a * b
        for i in range(m + n - 1, 0, -1):
            arr[i - 1] += arr[i] // 10
            arr[i] %= 10
        i = 0 if arr[0] else 1
        return "".join(str(x) for x in arr[i:]) 
```


这段代码实现的是大数乘法，主要运用了以下数学思想：

## 1. 竖式乘法思想
代码模拟了手工竖式乘法的过程：
- 从右到左逐位相乘（双重循环）
- 将乘积结果存储在对应的位置（arr[i+j+1]）
- 最后处理进位

## 2. 位置值原理
利用了数字的位置值概念：
- 第i位（从右数）的数字实际值为：数字 × 10ⁱ
- 两个数字相乘时，位置i和位置j的乘积应该放在位置i+j+1

## 3. 数组存储优化
使用长度为m+n的数组来存储中间结果：
- 两个m位和n位的数相乘，结果最多为m+n位
- 避免了字符串操作的复杂性

## 4. 进位处理
采用从右向左的进位处理：
- 从最低位开始处理进位
- 当前位的值取模10作为该位的最终值
- 进位加到前一位

## 5. 零值优化
开头检查0的情况，直接返回"0"，避免不必要的计算

这种实现方式的时间复杂度为O(m×n)，空间复杂度为O(m+n)，是处理大数乘法的经典方法。



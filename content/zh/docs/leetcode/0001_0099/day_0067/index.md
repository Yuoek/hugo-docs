---
title: "day_0067 "
date: 2025-09-14T09:17:02+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0067 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String addBinary(String a, String b) {
        var sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += (i >= 0 ? a.charAt(i) - '0' : 0) + (j >= 0 ? b.charAt(j) - '0' : 0);
            sb.append(carry % 2);
            carry /= 2;
        }
        return sb.reverse().toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0067  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 将二进制字符串a和b转换为十进制整数
        # 将两个整数相加得到十进制结果
        # 将结果转换为二进制字符串，并去掉前两位'0b'
        return bin(int(a, 2) + int(b, 2))[2:] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public String addBinary(String a, String b) {
        var sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += (i >= 0 ? a.charAt(i) - '0' : 0) + (j >= 0 ? b.charAt(j) - '0' : 0);
            sb.append(carry % 2);
            carry /= 2;
        }
        return sb.reverse().toString();
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0067  数学解释

```python 
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:] 
```


这段代码使用了**进制转换**的数学思想来解决二进制加法问题。

具体数学思想：
1. **进制转换原理**：将二进制字符串转换为十进制整数（`int(a, 2)`和`int(b, 2)`）
2. **十进制加法运算**：在十进制数域内进行加法运算（`+`操作）
3. **结果转换回二进制**：将十进制结果转换回二进制字符串（`bin()`函数）
4. **字符串处理**：去除二进制字符串的前缀"0b"（`[2:]`切片操作）

数学本质：利用**不同进制数之间的等价关系**，将二进制加法问题转换为更简单的十进制加法问题，然后再转换回二进制表示。

这种方法体现了**问题转换**的数学思想 - 通过将问题转换到不同的表示域（从二进制到十进制再回到二进制）来简化计算过程。



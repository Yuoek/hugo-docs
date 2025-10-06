---
title: "1256_EncodeNumber"
date: 2025-10-06T00:42:37+08:00
weight: 1256
tags: [位运算, 数学, 字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1256. 加密数字 🔒](https://leetcode.cn/problems/encode-number)

[English Version](../en/1256-56/1256_EncodeNumber)

## 题目描述

<!-- description:start -->

<p>给你一个非负整数 <code>num</code> ，返回它的「加密字符串」。</p>

<p>加密的过程是把一个整数用某个未知函数进行转化，你需要从下表推测出该转化函数：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1256.Encode%20Number/images/encode_number.png" style="height: 360px; width: 164px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 23
<strong>输出：</strong>&quot;1000&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 107
<strong>输出：</strong>&quot;101100&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^9</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

我们将 $num$ 加一，然后将其转换为二进制字符串，去掉最高位的 $1$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为 $num$ 的大小。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def encode(self, num: int) -> str:
        return bin(num + 1)[3:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String encode(int num) {
        return Integer.toBinaryString(num + 1).substring(1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string encode(int num) {
        bitset<32> bs(++num);
        string ans = bs.to_string();
        int i = 0;
        while (ans[i] == '0') {
            ++i;
        }
        return ans.substr(i + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func encode(num int) string {
	num++
	s := strconv.FormatInt(int64(num), 2)
	return s[1:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function encode(num: number): string {
    ++num;
    let s = num.toString(2);
    return s.slice(1);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def encode(self, num: int) -> str:
        return bin(num + 1)[3:]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String encode(int num) {
        return Integer.toBinaryString(num + 1).substring(1);
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    string encode(int num) {
        bitset<32> bs(++num);
        string ans = bs.to_string();
        int i = 0;
        while (ans[i] == '0') {
            ++i;
        }
        return ans.substr(i + 1);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
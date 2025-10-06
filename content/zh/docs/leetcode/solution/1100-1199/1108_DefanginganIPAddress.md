---
title: "1108_DefanginganIPAddress"
date: 2025-10-06T00:42:37+08:00
weight: 1108
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1108. IP 地址无效化](https://leetcode.cn/problems/defanging-an-ip-address)

[English Version](../en/1108-08/1108_DefanginganIPAddress)

## 题目描述

<!-- description:start -->

<p>给你一个有效的 <a href="https://baike.baidu.com/item/IPv4" target="_blank">IPv4</a> 地址&nbsp;<code>address</code>，返回这个 IP 地址的无效化版本。</p>

<p>所谓无效化&nbsp;IP 地址，其实就是用&nbsp;<code>&quot;[.]&quot;</code>&nbsp;代替了每个 <code>&quot;.&quot;</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>address = &quot;1.1.1.1&quot;
<strong>输出：</strong>&quot;1[.]1[.]1[.]1&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>address = &quot;255.100.50.0&quot;
<strong>输出：</strong>&quot;255[.]100[.]50[.]0&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给出的&nbsp;<code>address</code>&nbsp;是一个有效的 IPv4 地址</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：直接替换

我们直接将字符串中的 `'.'` 替换为 `'[.]'` 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

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
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = address.size(); i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func defangIPaddr(address string) string {
	return strings.Replace(address, ".", "[.]", -1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function defangIPaddr(address: string): string {
    return address.split('.').join('[.]');
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
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
    string defangIPaddr(string address) {
        for (int i = address.size(); i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
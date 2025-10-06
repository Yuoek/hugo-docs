---
title: "1108_DefanginganIPAddress"
date: 2025-10-06T00:42:37+08:00
weight: 1108
tags: [String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1108. Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address)

[中文文档](/solution/1100-1199/1108.Defanging%20an%20IP%20Address/README.md)

## Description

<!-- description:start -->

<p>Given a valid (IPv4) IP <code>address</code>, return a defanged version of that IP address.</p>

<p>A <em>defanged&nbsp;IP address</em>&nbsp;replaces every period <code>&quot;.&quot;</code> with <code>&quot;[.]&quot;</code>.</p>

<p>&nbsp;</p>

<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> address = "1.1.1.1"

<strong>Output:</strong> "1[.]1[.]1[.]1"

</pre><p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> address = "255.100.50.0"

<strong>Output:</strong> "255[.]100[.]50[.]0"

</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>

    <li>The given <code>address</code> is a valid IPv4 address.</li>

</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Direct Replacement

We can directly replace the `'.'` in the string with `'[.]'`.

The time complexity is $O(n)$, where $n$ is the length of the string. Ignoring the space consumption of the answer, the space complexity is $O(1)$.

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
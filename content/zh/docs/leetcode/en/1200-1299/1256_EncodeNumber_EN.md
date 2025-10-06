---
title: "1256_EncodeNumber"
date: 2025-10-06T00:42:37+08:00
weight: 1256
tags: [Bit Manipulation, Math, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1256. Encode Number 🔒](https://leetcode.com/problems/encode-number)

[中文文档](/solution/1200-1299/1256.Encode%20Number/README.md)

## Description

<!-- description:start -->

<p>Given a non-negative integer <code>num</code>, Return its <em>encoding</em> string.</p>

<p>The encoding is done by converting the integer to a string using a secret function that you should deduce from the following table:</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1256.Encode%20Number/images/encode_number.png" style="width: 164px; height: 360px;" /></p>

<p>&nbsp;</p>

<p><strong class="example">Example 1:</strong></p>

<pre>

<strong>Input:</strong> num = 23

<strong>Output:</strong> &quot;1000&quot;

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>

<strong>Input:</strong> num = 107

<strong>Output:</strong> &quot;101100&quot;

</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>

    <li><code>0 &lt;= num &lt;= 10^9</code></li>

</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Bit Manipulation

We add one to $num$, then convert it to a binary string and remove the highest bit $1$.

The time complexity is $O(\log n)$, and the space complexity is $O(\log n)$. Where $n$ is the size of $num$.

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
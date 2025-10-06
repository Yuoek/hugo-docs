---
title: "1716_CalculateMoneyinLeetcodeBank"
date: 2025-10-06T00:42:37+08:00
weight: 1716
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1716. 计算力扣银行的钱](https://leetcode.cn/problems/calculate-money-in-leetcode-bank)

[English Version](../en/1716-16/1716_CalculateMoneyinLeetcodeBank)

## 题目描述

<!-- description:start -->

<p>Hercy 想要为购买第一辆车存钱。他 <strong>每天</strong> 都往力扣银行里存钱。</p>

<p>最开始，他在周一的时候存入 <code>1</code> 块钱。从周二到周日，他每天都比前一天多存入 <code>1</code> 块钱。在接下来每一个周一，他都会比 <strong>前一个周一</strong> 多存入 <code>1</code> 块钱。<span style=""> </span></p>

<p>给你 <code>n</code> ，请你返回在第 <code>n</code> 天结束的时候他在力扣银行总共存了多少块钱。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 4
<b>输出：</b>10
<b>解释：</b>第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 10
<b>输出：</b>37
<b>解释：</b>第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 20
<b>输出：</b>96
<b>解释：</b>第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def totalMoney(self, n: int) -> int:
        a, b = divmod(n, 7)
        return (28 + 28 + 7 * (a - 1)) * a // 2 + (a * 2 + b + 1) * b // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalMoney(n int) int {
	a, b := n/7, n%7
	return (28+28+7*(a-1))*a/2 + (a*2+b+1)*b/2
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def totalMoney(self, n: int) -> int:
        a, b = divmod(n, 7)
        return (28 + 28 + 7 * (a - 1)) * a // 2 + (a * 2 + b + 1) * b // 2
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
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
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
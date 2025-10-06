---
title: "2769_FindtheMaximumAchievableNumber"
date: 2025-10-06T00:42:37+08:00
weight: 2769
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2769. 找出最大的可达成数字](https://leetcode.cn/problems/find-the-maximum-achievable-number)

[English Version](../en/2769-69/2769_FindtheMaximumAchievableNumber)

## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>num</code> 和 <code>t</code> 。如果整数 <code>x</code> 可以在执行下述操作 <strong>不超过</strong> <code>t</code> 次的情况下变为与 <code>num</code> 相等，则称其为 <strong>可达成数字</strong> ：</p>

<ul>
	<li>每次操作将 <code>x</code> 的值增加或减少 <code>1</code> ，同时可以选择将 <code>num</code> 的值增加或减少 <code>1</code> 。</li>
</ul>

<p>返回所有可达成数字中的 <strong>最大</strong> 值 <code>x</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num = 4, t = 1</p>

<p><strong>输出：</strong>6</p>

<p><strong>解释：</strong></p>

<p>执行下述操作可以使最大可达成数字等于 <code>num</code> ：</p>

<ul>
	<li>最大可达成数字减少 1 ，同时 <code>num</code> 增加 1 。</li>
</ul>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num = 3, t = 2</p>

<p><strong>输出：</strong>7</p>

<p><strong>解释：</strong></p>

<p>执行两次下述操作可以使最大可达成数字等于 num ：</p>

<ul>
	<li>最大可达成数字减少 1 ，同时 <code>num</code> 增加 1。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num, t&nbsp;&lt;= 50</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学

我们注意到，每次操作可以将 $x$ 减少 $1$，同时将 $num$ 增加 $1$，这样 $x$ 和 $num$ 的差值就会减少 $2$，而最多可以操作 $t$ 次，所以最大可达成数字为 $num + t \times 2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

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
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + t * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func theMaximumAchievableX(num int, t int) int {
	return num + t*2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function theMaximumAchievableX(num: number, t: number): number {
    return num + t * 2;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + t * 2
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
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
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
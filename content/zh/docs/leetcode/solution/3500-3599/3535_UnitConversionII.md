---
title: "3535_UnitConversionII"
date: 2025-10-06T00:42:37+08:00
weight: 3535
tags: [深度优先搜索, 广度优先搜索, 图, 数组, 数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3535. 单位转换 II 🔒](https://leetcode.cn/problems/unit-conversion-ii)

[English Version](../en/3535-35/3535_UnitConversionII)

## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 种单位，编号从 <code>0</code> 到 <code>n - 1</code>。</p>

<p>给定一个二维整数数组 <code>conversions</code>，长度为 <code>n - 1</code>，其中 <code>conversions[i] = [sourceUnit<sub>i</sub>, targetUnit<sub>i</sub>, conversionFactor<sub>i</sub>]</code>&nbsp;，表示一个&nbsp;<code>sourceUnit<sub>i</sub></code> 类型的单位等于 <code>conversionFactor<sub>i</sub></code> 个 <code>targetUnit<sub>i</sub></code> 类型的单位。</p>

<p>同时给定一个长度为&nbsp;<code>q</code>&nbsp;的 2 维整数数组&nbsp;<code>queries</code>，其中&nbsp;<code>queries[i] = [unitA<sub>i</sub>, unitB<sub>i</sub>]</code>。</p>

<p>返回一个长度为 <code>q</code>&nbsp;的数组&nbsp;<code face="monospace">answer</code>，其中&nbsp;<code>answer[i]</code>&nbsp;表示多少个&nbsp;<code>unitB<sub>i</sub></code>&nbsp;类型的单位等于 1 个&nbsp;<code>unitA<sub>i</sub></code>&nbsp;类型的单位，并且当&nbsp;<code>p</code>&nbsp;和&nbsp;<code>q</code>&nbsp;互质的时候可以表示为 <code>p/q</code>。以&nbsp;<code>pq<sup>-1</sup></code>&nbsp;返回每个&nbsp;<code>answer[i]</code>&nbsp;对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取模</strong>&nbsp;的值，其中&nbsp;<code>q<sup>-1</sup></code>&nbsp;表示&nbsp;<code>q</code> 模&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;的乘法逆元。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>conversions = [[0,1,2],[0,2,6]], queries = [[1,2],[1,0]]</span></p>

<p><span class="example-io"><b>输出：</b>[3,500000004]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>在第一次查询中，我们可以反向使用&nbsp;<code>conversions[0]</code>，然后使用&nbsp;<code>conversions[1]</code>&nbsp;将单位 1 转换为 3 个单位的类型 2。</li>
	<li>在第二次查询中，我们可以反向使用 <code>conversions[0]</code>&nbsp;将单位 1 转换为 1/2 个单位的类型 0。我们返回&nbsp;500000004 因为它是 2 的乘法逆元。</li>
</ul>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3500-3599/3535.Unit%20Conversion%20II/images/example1.png" style="width: 500px; height: 500px;" /></div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>conversions = [[0,1,2],[0,2,6],[0,3,8],[2,4,2],[2,5,4],[3,6,3]], queries = [[1,2],[0,4],[6,5],[4,6],[6,1]]</span></p>

<p><span class="example-io"><b>输出：</b>[3,12,1,2,83333334]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>在第一次查询中，我们可以反向使用&nbsp;<code>conversions[0]</code>，然后使用&nbsp;<code>conversions[1]</code> 将单位 1 转换为 3 个单位的类型 2。</li>
	<li>在第二次查询中，我们可以使用 <code>conversions[1]</code>，然后使用&nbsp;<code>conversions[3]</code> 将单位 0 转换为&nbsp;12 个单位的类型 4。</li>
	<li>在第三次查询中，我们可以使用&nbsp;<code>conversions[5]</code>，反向使用&nbsp;<code>conversions[2]</code>，<code>conversions[1]</code>，然后使用&nbsp;<code>conversions[4]</code> 将单位 6 转换为 1 个单位的类型 5。</li>
	<li>在第四次查询中，我们可以反向使用&nbsp;<code>conversions[3]</code>，反向使用&nbsp;<code>conversions[1]</code>，<code>conversions[2]</code>，然后使用&nbsp;<code>conversions[5]</code>&nbsp;将单位 4 转换为 2 个单位的类型 6。</li>
	<li>在第五次查询中，我们可以反向使用&nbsp;<code>conversions[5]</code>，反向使用&nbsp;<code>conversions[2]</code>，然后使用&nbsp;<code>conversions[0]</code> 将单位 6 转换为 1/12 个单位的类型 1。我们返回&nbsp;83333334 因为它是 12 的乘法逆元。</li>
</ul>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3500-3599/3535.Unit%20Conversion%20II/images/example2.png" style="width: 504px; height: 493px;" /></div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>conversions.length == n - 1</code></li>
	<li><code>0 &lt;= sourceUnit<sub>i</sub>, targetUnit<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= conversionFactor<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= q &lt;= 10<sup>5</sup></code></li>
	<li><code>queries.length == q</code></li>
	<li><code>0 &lt;= unitA<sub>i</sub>, unitB<sub>i</sub> &lt; n</code></li>
	<li>保证&nbsp;0 单位可以通过正向或反向转换的组合唯一地转换为任何其他单位。</li>
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

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}

{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}

{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}

{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
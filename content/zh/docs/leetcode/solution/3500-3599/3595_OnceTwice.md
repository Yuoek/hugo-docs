---
title: "3595_OnceTwice"
date: 2025-10-06T00:42:37+08:00
weight: 3595
tags: [位运算, 数组]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3595. 一次或两次 🔒](https://leetcode.cn/problems/once-twice)

[English Version](../en/3595-95/3595_OnceTwice)

## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;<code>nums</code>。在这个数组中：</p>

<ul>
	<li>
	<p>有一个元素出现了 <strong>恰好 1&nbsp;</strong><strong>次</strong>。</p>
	</li>
	<li>
	<p>有一个元素出现了 <strong>恰好 2&nbsp;</strong><strong>次</strong>。</p>
	</li>
	<li>
	<p>其它所有元素都出现了 <strong>恰好 3 次</strong>。</p>
	</li>
</ul>

<p>返回一个长度为 2 的整数数组，其中第一个元素是只出现 <strong>1 次</strong>&nbsp;的那个元素，第二个元素是只出现 <strong>2 次</strong>&nbsp;的那个元素。</p>

<p>你的解决方案必须在 <strong>O(n) 时间</strong>&nbsp;与 <strong>O(1)</strong>&nbsp;空间中运行。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,2,3,2,5,5,5,7,7]</span></p>

<p><span class="example-io"><b>输出：</b>[3,7]</span></p>

<p><strong>解释：</strong></p>

<p>元素 3&nbsp;出现了 <strong>1 次</strong>，元素 7&nbsp;出现了 <strong>2 次</strong>。其余所有元素都出现了 <strong>3 次</strong>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,4,6,4,9,9,9,6,8]</span></p>

<p><span class="example-io"><b>输出：</b>[8,6]</span></p>

<p><strong>解释：</strong></p>

<p>元素 8 出现了 <strong>1 次</strong>，元素 6 出现了 <strong>2 次</strong>。其余所有元素都出现了 <strong>3 次</strong>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums.length</code>&nbsp;是 3 的倍数。</li>
	<li>恰好有一个元素出现 1 次，一个元素出现 2 次，其余所有元素都出现了 3 次。</li>
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
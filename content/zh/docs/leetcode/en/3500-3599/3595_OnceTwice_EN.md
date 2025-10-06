---
title: "3595_OnceTwice"
date: 2025-10-06T00:42:37+08:00
weight: 3595
tags: [Bit Manipulation, Array]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [3595. Once Twice 🔒](https://leetcode.com/problems/once-twice)

[中文文档](/solution/3500-3599/3595.Once%20Twice/README.md)

## Description

<!-- description:start -->

<p>You are given an integer array <code>nums</code>. In this array:</p>

<ul>
	<li>
	<p>Exactly one element appears <strong>once</strong>.</p>
	</li>
	<li>
	<p>Exactly one element appears <strong>twice</strong>.</p>
	</li>
	<li>
	<p>All other elements appear <strong>exactly three times</strong>.</p>
	</li>
</ul>

<p>Return an integer array of length 2, where the first element is the one that appears <strong>once</strong>, and the second is the one that appears <strong>twice</strong>.</p>

<p>Your solution must run in <strong>O(n)</strong> time and <strong>O(1)</strong> space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,2,3,2,5,5,5,7,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,7]</span></p>

<p><strong>Explanation:</strong></p>

<p>The element 3 appears <b>once</b>, and the element 7 appears <b>twice</b>. The remaining elements each appear <b>three times</b>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,4,6,4,9,9,9,6,8]</span></p>

<p><strong>Output:</strong> <span class="example-io">[8,6]</span></p>

<p><strong>Explanation:</strong></p>

<p>The element 8 appears <b>once</b>, and the element 6 appears <b>twice</b>. The remaining elements each appear <b>three times</b>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums.length</code> is a multiple of 3.</li>
	<li>Exactly one element appears once, one element appears twice, and all other elements appear three times.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

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
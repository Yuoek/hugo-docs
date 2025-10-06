---
title: "3656_DetermineifaSimpleGraphExists"
date: 2025-10-06T00:42:37+08:00
weight: 3656
tags: []
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [3656. Determine if a Simple Graph Exists 🔒](https://leetcode.com/problems/determine-if-a-simple-graph-exists)

[中文文档](/solution/3600-3699/3656.Determine%20if%20a%20Simple%20Graph%20Exists/README.md)

## Description

<!-- description:start -->

<p>You are given an integer array <code>degrees</code>, where <code>degrees[i]</code> represents the desired degree of the <code>i<sup>th</sup></code> vertex.</p>

<p>Your task is to determine if there exists an <strong>undirected simple</strong> graph with <strong>exactly</strong> these vertex degrees.</p>

<p>A <strong>simple</strong> graph has no self-loops or parallel edges between the same pair of vertices.</p>

<p>Return <code>true</code> if such a graph exists, otherwise return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">degrees = [3,1,2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3600-3699/3656.Determine%20if%20a%20Simple%20Graph%20Exists/images/screenshot-2025-08-13-at-24347-am.png" style="width: 200px; height: 132px;" />​​​​​​​</p>

<p>One possible undirected simple graph is:</p>

<ul>
	<li>Edges: <code>(0, 1), (0, 2), (0, 3), (2, 3)</code></li>
	<li>Degrees: <code>deg(0) = 3</code>, <code>deg(1) = 1</code>, <code>deg(2) = 2</code>, <code>deg(3) = 2</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">degrees = [1,3,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li><code>degrees[1] = 3</code> and <code>degrees[2] = 3</code> means they must be connected to all other vertices.</li>
	<li>This requires <code>degrees[0]</code> and <code>degrees[3]</code> to be at least 2, but both are equal to 1, which contradicts the requirement.</li>
	<li>Thus, the answer is <code>false</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == degrees.length &lt;= 10<sup>​​​​​​​5</sup></code></li>
	<li><code>0 &lt;= degrees[i] &lt;= n - 1</code></li>
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
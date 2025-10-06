---
title: "3241_TimeTakentoMarkAllNodes"
date: 2025-10-06T00:42:37+08:00
weight: 3241
tags: [Tree, Depth-First Search, Graph, Dynamic Programming]
---


{{< katex />}}

{{< badge title="Difficulty" value="Hard" >}}

<!-- problem:start -->

# [3241. Time Taken to Mark All Nodes](https://leetcode.com/problems/time-taken-to-mark-all-nodes)

[中文文档](/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/README.md)

## Description

<!-- description:start -->

<p>There exists an <strong>undirected</strong> tree with <code>n</code> nodes numbered <code>0</code> to <code>n - 1</code>. You are given a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates that there is an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> in the tree.</p>

<p>Initially, <strong>all</strong> nodes are <strong>unmarked</strong>. For each node <code>i</code>:</p>

<ul>
	<li>If <code>i</code> is odd, the node will get marked at time <code>x</code> if there is <strong>at least</strong> one node <em>adjacent</em> to it which was marked at time <code>x - 1</code>.</li>
	<li>If <code>i</code> is even, the node will get marked at time <code>x</code> if there is <strong>at least</strong> one node <em>adjacent</em> to it which was marked at time <code>x - 2</code>.</li>
</ul>

<p>Return an array <code>times</code> where <code>times[i]</code> is the time when all nodes get marked in the tree, if you mark node <code>i</code> at time <code>t = 0</code>.</p>

<p><strong>Note</strong> that the answer for each <code>times[i]</code> is <strong>independent</strong>, i.e. when you mark node <code>i</code> all other nodes are <em>unmarked</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1],[0,2]]</span></p>

<p><strong>Output:</strong> [2,4,3]</p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122236.png" style="width: 500px; height: 241px;" /></p>

<ul>
	<li>For <code>i = 0</code>:

    <ul>
    	<li>Node 1 is marked at <code>t = 1</code>, and Node 2 at <code>t = 2</code>.</li>
    </ul>
    </li>
    <li>For <code>i = 1</code>:
    <ul>
    	<li>Node 0 is marked at <code>t = 2</code>, and Node 2 at <code>t = 4</code>.</li>
    </ul>
    </li>
    <li>For <code>i = 2</code>:
    <ul>
    	<li>Node 0 is marked at <code>t = 2</code>, and Node 1 at <code>t = 3</code>.</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1]]</span></p>

<p><strong>Output:</strong> [1,2]</p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122249.png" style="width: 500px; height: 257px;" /></p>

<ul>
	<li>For <code>i = 0</code>:

    <ul>
    	<li>Node 1 is marked at <code>t = 1</code>.</li>
    </ul>
    </li>
    <li>For <code>i = 1</code>:
    <ul>
    	<li>Node 0 is marked at <code>t = 2</code>.</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = </span>[[2,4],[0,1],[2,3],[0,2]]</p>

<p><strong>Output:</strong> [4,6,3,5,5]</p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-03-210550.png" style="height: 266px; width: 500px;" /></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
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
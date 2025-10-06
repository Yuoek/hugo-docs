---
title: "3241_TimeTakentoMarkAllNodes"
date: 2025-10-06T00:42:37+08:00
weight: 3241
tags: [树, 深度优先搜索, 图, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [3241. 标记所有节点需要的时间](https://leetcode.cn/problems/time-taken-to-mark-all-nodes)

[English Version](../en/3241-41/3241_TimeTakentoMarkAllNodes)

## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>无向</strong>&nbsp;树，树中节点从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。同时给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code>&nbsp;在树中有一条边。</p>

<p>一开始，<strong>所有</strong>&nbsp;节点都 <strong>未标记</strong>&nbsp;。对于节点 <code>i</code>&nbsp;：</p>

<ul>
	<li>当&nbsp;<code>i</code>&nbsp;是奇数时，如果时刻 <code>x - 1</code>&nbsp;该节点有 <strong>至少</strong>&nbsp;一个相邻节点已经被标记了，那么节点 <code>i</code>&nbsp;会在时刻 <code>x</code>&nbsp;被标记。</li>
	<li>当&nbsp;<code>i</code>&nbsp;是偶数时，如果时刻 <code>x - 2</code>&nbsp;该节点有 <strong>至少</strong>&nbsp;一个相邻节点已经被标记了，那么节点 <code>i</code>&nbsp;会在时刻 <code>x</code>&nbsp;被标记。</li>
</ul>

<p>请你返回一个数组&nbsp;<code>times</code>&nbsp;，表示如果你在时刻 <code>t = 0</code>&nbsp;标记节点 <code>i</code>&nbsp;，那么时刻 <code>times[i]</code>&nbsp;时，树中所有节点都会被标记。</p>

<p>请注意，每个 <code>times[i]</code> 的答案都是独立的，即当你标记节点 <code>i</code> 时，所有其他节点都未标记。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1],[0,2]]</span></p>

<p><b>输出：</b>[2,4,3]</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122236.png" style="width: 500px; height: 241px;" /></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;：

    <ul>
    	<li>节点 1 在时刻&nbsp;<code>t = 1</code>&nbsp;被标记，节点 2 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 1</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记，节点 2 在时刻&nbsp;<code>t = 4</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 2</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记，节点 1 在时刻&nbsp;<code>t = 3</code>&nbsp;被标记。</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1]]</span></p>

<p><b>输出：</b>[1,2]</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122249.png" style="width: 500px; height: 257px;" /></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;：

    <ul>
    	<li>节点 1 在时刻&nbsp;<code>t = 1</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 1</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记。</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = </span>[[2,4],[0,1],[2,3],[0,2]]</p>

<p><b>输出：</b>[4,6,3,5,5]</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-03-210550.png" style="height: 266px; width: 500px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;表示一棵合法的树。</li>
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
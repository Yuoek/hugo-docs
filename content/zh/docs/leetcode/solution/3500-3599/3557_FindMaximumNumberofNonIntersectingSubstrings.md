---
title: "3557_FindMaximumNumberofNonIntersectingSubstrings"
date: 2025-10-06T00:42:37+08:00
weight: 3557
tags: [贪心, 哈希表, 字符串, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3557. 不相交子字符串的最大数量](https://leetcode.cn/problems/find-maximum-number-of-non-intersecting-substrings)

[English Version](../en/3557-57/3557_FindMaximumNumberofNonIntersectingSubstrings)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>word</code>。</p>

<p>返回以&nbsp;<strong>首尾字母相同&nbsp;</strong>且&nbsp;<strong>长度至少为 4&nbsp;</strong>的&nbsp;<strong>不相交子字符串&nbsp;</strong>的最大数量。</p>

<p><strong>子字符串&nbsp;</strong>是字符串中连续的&nbsp;<b>非空&nbsp;</b>字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">word = "abcdeafdef"</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>两个子字符串是 <code>"abcdea"</code> 和 <code>"fdef"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">word = "bcdaaaab"</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>唯一的子字符串是 <code>"aaaa"</code>。注意我们&nbsp;<strong>不能&nbsp;</strong>同时选择 <code>"bcdaaaab"</code>，因为它和另一个子字符串有重叠。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
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
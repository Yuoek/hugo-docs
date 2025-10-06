---
title: "3389_MinimumOperationstoMakeCharacterFrequenciesEqual"
date: 2025-10-06T00:42:37+08:00
weight: 3389
tags: [Hash Table, String, Dynamic Programming, Counting, Enumeration]
---


{{< katex />}}

{{< badge title="Difficulty" value="Hard" >}}

<!-- problem:start -->

# [3389. Minimum Operations to Make Character Frequencies Equal](https://leetcode.com/problems/minimum-operations-to-make-character-frequencies-equal)

[中文文档](/solution/3300-3399/3389.Minimum%20Operations%20to%20Make%20Character%20Frequencies%20Equal/README.md)

## Description

<!-- description:start -->

<p>You are given a string <code>s</code>.</p>

<p>A string <code>t</code> is called <strong>good</strong> if all characters of <code>t</code> occur the same number of times.</p>

<p>You can perform the following operations <strong>any number of times</strong>:</p>

<ul>
	<li>Delete a character from <code>s</code>.</li>
	<li>Insert a character in <code>s</code>.</li>
	<li>Change a character in <code>s</code> to its next letter in the alphabet.</li>
</ul>

<p><strong>Note</strong> that you cannot change <code>&#39;z&#39;</code> to <code>&#39;a&#39;</code> using the third operation.</p>

<p>Return<em> </em>the <strong>minimum</strong> number of operations required to make <code>s</code> <strong>good</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;acab&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>We can make <code>s</code> good by deleting one occurrence of character <code>&#39;a&#39;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;wddw&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>We do not need to perform any operations since <code>s</code> is initially good.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aaabc&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can make <code>s</code> good by applying these operations:</p>

<ul>
	<li>Change one occurrence of <code>&#39;a&#39;</code> to <code>&#39;b&#39;</code></li>
	<li>Insert one occurrence of <code>&#39;c&#39;</code> into <code>s</code></li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 2&nbsp;* 10<sup>4</sup></code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
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
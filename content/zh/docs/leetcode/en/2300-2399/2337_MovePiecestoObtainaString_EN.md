---
title: "2337_MovePiecestoObtainaString"
date: 2025-10-06T00:42:37+08:00
weight: 2337
tags: [Two Pointers, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [2337. Move Pieces to Obtain a String](https://leetcode.com/problems/move-pieces-to-obtain-a-string)

[中文文档](/solution/2300-2399/2337.Move%20Pieces%20to%20Obtain%20a%20String/README.md)

## Description

<!-- description:start -->

<p>You are given two strings <code>start</code> and <code>target</code>, both of length <code>n</code>. Each string consists <strong>only</strong> of the characters <code>&#39;L&#39;</code>, <code>&#39;R&#39;</code>, and <code>&#39;_&#39;</code> where:</p>

<ul>
	<li>The characters <code>&#39;L&#39;</code> and <code>&#39;R&#39;</code> represent pieces, where a piece <code>&#39;L&#39;</code> can move to the <strong>left</strong> only if there is a <strong>blank</strong> space directly to its left, and a piece <code>&#39;R&#39;</code> can move to the <strong>right</strong> only if there is a <strong>blank</strong> space directly to its right.</li>
	<li>The character <code>&#39;_&#39;</code> represents a blank space that can be occupied by <strong>any</strong> of the <code>&#39;L&#39;</code> or <code>&#39;R&#39;</code> pieces.</li>
</ul>

<p>Return <code>true</code> <em>if it is possible to obtain the string</em> <code>target</code><em> by moving the pieces of the string </em><code>start</code><em> <strong>any</strong> number of times</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;_L__R__R_&quot;, target = &quot;L______RR&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to &quot;<strong>L</strong>___R__R_&quot;.
- Move the last piece one step to the right, start becomes equal to &quot;L___R___<strong>R</strong>&quot;.
- Move the second piece three steps to the right, start becomes equal to &quot;L______<strong>R</strong>R&quot;.
Since it is possible to get the string target from start, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;R_L_&quot;, target = &quot;__LR&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> The &#39;R&#39; piece in the string start can move one step to the right to obtain &quot;_<strong>R</strong>L_&quot;.
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> start = &quot;_R&quot;, target = &quot;R_&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == start.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>start</code> and <code>target</code> consist of the characters <code>&#39;L&#39;</code>, <code>&#39;R&#39;</code>, and <code>&#39;_&#39;</code>.</li>
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



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

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
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != target[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == '_') {
                ++i;
            }
            while (j < n && target.charAt(j) == '_') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canChange(start string, target string) bool {
	n := len(start)
	i, j := 0, 0
	for {
		for i < n && start[i] == '_' {
			i++
		}
		for j < n && target[j] == '_' {
			j++
		}
		if i == n && j == n {
			return true
		}
		if i == n || j == n || start[i] != target[j] {
			return false
		}
		if start[i] == 'L' && i < j {
			return false
		}
		if start[i] == 'R' && i > j {
			return false
		}
		i, j = i+1, j+1
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canChange(start: string, target: string): boolean {
    const n = start.length;
    let [i, j] = [0, 0];
    while (1) {
        while (i < n && start[i] === '_') {
            ++i;
        }
        while (j < n && target[j] === '_') {
            ++j;
        }
        if (i === n && j === n) {
            return true;
        }
        if (i === n || j === n || start[i] !== target[j]) {
            return false;
        }
        if ((start[i] === 'L' && i < j) || (start[i] === 'R' && i > j)) {
            return false;
        }
        ++i;
        ++j;
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        i = j = 0
        while 1:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1
            if i >= n and j >= n:
                return True
            if i >= n or j >= n or start[i] != target[j]:
                return False
            if start[i] == 'L' and i < j:
                return False
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start.charAt(i) == '_') {
                ++i;
            }
            while (j < n && target.charAt(j) == '_') {
                ++j;
            }
            if (i == n && j == n) {
                return true;
            }
            if (i == n || j == n || start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (start.charAt(i) == 'L' && i < j || start.charAt(i) == 'R' && i > j) {
                return false;
            }
            ++i;
            ++j;
        }
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
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;
            if (i == n && j == n) return true;
            if (i == n || j == n || start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
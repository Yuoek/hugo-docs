---
title: "2259_RemoveDigitFromNumbertoMaximizeResult"
date: 2025-10-06T00:42:37+08:00
weight: 2259
tags: [Greedy, String, Enumeration]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2259. Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result)

[中文文档](/solution/2200-2299/2259.Remove%20Digit%20From%20Number%20to%20Maximize%20Result/README.md)

## Description

<!-- description:start -->

<p>You are given a string <code>number</code> representing a <strong>positive integer</strong> and a character <code>digit</code>.</p>

<p>Return <em>the resulting string after removing <strong>exactly one occurrence</strong> of </em><code>digit</code><em> from </em><code>number</code><em> such that the value of the resulting string in <strong>decimal</strong> form is <strong>maximized</strong></em>. The test cases are generated such that <code>digit</code> occurs at least once in <code>number</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> number = &quot;123&quot;, digit = &quot;3&quot;
<strong>Output:</strong> &quot;12&quot;
<strong>Explanation:</strong> There is only one &#39;3&#39; in &quot;123&quot;. After removing &#39;3&#39;, the result is &quot;12&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> number = &quot;1231&quot;, digit = &quot;1&quot;
<strong>Output:</strong> &quot;231&quot;
<strong>Explanation:</strong> We can remove the first &#39;1&#39; to get &quot;231&quot; or remove the second &#39;1&#39; to get &quot;123&quot;.
Since 231 &gt; 123, we return &quot;231&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> number = &quot;551&quot;, digit = &quot;5&quot;
<strong>Output:</strong> &quot;51&quot;
<strong>Explanation:</strong> We can remove either the first or second &#39;5&#39; from &quot;551&quot;.
Both result in the string &quot;51&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= number.length &lt;= 100</code></li>
	<li><code>number</code> consists of digits from <code>&#39;1&#39;</code> to <code>&#39;9&#39;</code>.</li>
	<li><code>digit</code> is a digit from <code>&#39;1&#39;</code> to <code>&#39;9&#39;</code>.</li>
	<li><code>digit</code> occurs at least once in <code>number</code>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Brute Force Enumeration

We can enumerate all positions $\textit{i}$ in the string $\textit{number}$. If $\textit{number}[i] = \textit{digit}$, we take the prefix $\textit{number}[0:i]$ and the suffix $\textit{number}[i+1:]$ of $\textit{number}$ and concatenate them. This gives the result after removing $\textit{number}[i]$. We then take the maximum of all possible results.

The time complexity is $O(n^2)$, and the space complexity is $O(n)$. Here, $n$ is the length of the string $\textit{number}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### PHP



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Greedy

We can enumerate all positions $\textit{i}$ in the string $\textit{number}$. If $\textit{number}[i] = \textit{digit}$, we record the last occurrence position of $\textit{digit}$ as $\textit{last}$. If $\textit{i} + 1 < \textit{n}$ and $\textit{number}[i] < \textit{number}[i + 1]$, then we can directly return $\textit{number}[0:i] + \textit{number}[i+1:]$ as the result after removing $\textit{number}[i]$. This is because if $\textit{number}[i] < \textit{number}[i + 1]$, removing $\textit{number}[i]$ will result in a larger number.

After the traversal, we return $\textit{number}[0:\textit{last}] + \textit{number}[\textit{last}+1:]$.

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
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        last = -1
        n = len(number)
        for i, d in enumerate(number):
            if d == digit:
                last = i
                if i + 1 < n and d < number[i + 1]:
                    break
        return number[:last] + number[last + 1 :]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeDigit(String number, char digit) {
        int last = -1;
        int n = number.length();
        for (int i = 0; i < n; ++i) {
            char d = number.charAt(i);
            if (d == digit) {
                last = i;
                if (i + 1 < n && d < number.charAt(i + 1)) {
                    break;
                }
            }
        }
        return number.substring(0, last) + number.substring(last + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int last = -1;
        for (int i = 0; i < n; ++i) {
            char d = number[i];
            if (d == digit) {
                last = i;
                if (i + 1 < n && number[i] < number[i + 1]) {
                    break;
                }
            }
        }
        return number.substr(0, last) + number.substr(last + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDigit(number string, digit byte) string {
	last := -1
	n := len(number)
	for i := range number {
		if number[i] == digit {
			last = i
			if i+1 < n && number[i] < number[i+1] {
				break
			}
		}
	}
	return number[:last] + number[last+1:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeDigit(number: string, digit: string): string {
    const n = number.length;
    let last = -1;
    for (let i = 0; i < n; ++i) {
        if (number[i] === digit) {
            last = i;
            if (i + 1 < n && number[i] < number[i + 1]) {
                break;
            }
        }
    }
    return number.substring(0, last) + number.substring(last + 1);
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $number
     * @param String $digit
     * @return String
     */
    function removeDigit($number, $digit) {
        $max = 0;
        for ($i = 0; $i < strlen($number); $i++) {
            if ($number[$i] == $digit) {
                $tmp = substr($number, 0, $i) . substr($number, $i + 1);
                if ($tmp > $max) {
                    $max = $tmp;
                }
            }
        }
        return $max;
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        last = -1
        n = len(number)
        for i, d in enumerate(number):
            if d == digit:
                last = i
                if i + 1 < n and d < number[i + 1]:
                    break
        return number[:last] + number[last + 1 :]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String removeDigit(String number, char digit) {
        int last = -1;
        int n = number.length();
        for (int i = 0; i < n; ++i) {
            char d = number.charAt(i);
            if (d == digit) {
                last = i;
                if (i + 1 < n && d < number.charAt(i + 1)) {
                    break;
                }
            }
        }
        return number.substring(0, last) + number.substring(last + 1);
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
    string removeDigit(string number, char digit) {
        int n = number.size();
        int last = -1;
        for (int i = 0; i < n; ++i) {
            char d = number[i];
            if (d == digit) {
                last = i;
                if (i + 1 < n && number[i] < number[i + 1]) {
                    break;
                }
            }
        }
        return number.substr(0, last) + number.substr(last + 1);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
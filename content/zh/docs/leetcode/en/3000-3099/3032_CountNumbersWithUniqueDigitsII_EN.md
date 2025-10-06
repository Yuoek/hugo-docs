---
title: "3032_CountNumbersWithUniqueDigitsII"
date: 2025-10-06T00:42:37+08:00
weight: 3032
tags: [Hash Table, Math, Dynamic Programming]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [3032. Count Numbers With Unique Digits II 🔒](https://leetcode.com/problems/count-numbers-with-unique-digits-ii)

[中文文档](/solution/3000-3099/3032.Count%20Numbers%20With%20Unique%20Digits%20II/README.md)

## Description

<!-- description:start -->

Given two <strong>positive</strong> integers <code>a</code> and <code>b</code>, return <em>the count of numbers having&nbsp;<strong>unique</strong> digits in the range</em> <code>[a, b]</code> <em>(<strong>inclusive</strong>).</em>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> a = 1, b = 20
<strong>Output:</strong> 19
<strong>Explanation:</strong> All the numbers in the range [1, 20] have unique digits except 11. Hence, the answer is 19.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> a = 9, b = 19
<strong>Output:</strong> 10
<strong>Explanation:</strong> All the numbers in the range [9, 19] have unique digits except 11. Hence, the answer is 10. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> a = 80, b = 120
<strong>Output:</strong> 27
<strong>Explanation:</strong> There are 41 numbers in the range [80, 120], 27 of which have unique digits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a &lt;= b &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: State Compression + Digit DP

The problem asks to count how many numbers in the range $[a, b]$ have unique digits. We can solve this problem using state compression and digit DP.

We can use a function $f(n)$ to count how many numbers in the range $[1, n]$ have unique digits. Then the answer is $f(b) - f(a - 1)$.

In addition, we can use a binary number to record the digits that have appeared in the number. For example, if the digits $1, 3, 5$ have appeared in the number, we can use $10101$ to represent this state.

Next, we use memoization search to implement digit DP. We search from the starting point to the bottom layer to get the number of schemes, return the answer layer by layer and accumulate it, and finally get the final answer from the search starting point.

The basic steps are as follows:

1. We convert the number $n$ into a string $num$, where $num[0]$ is the highest digit and $num[len - 1]$ is the lowest digit.
2. Based on the problem information, we design a function $dfs(pos, mask, limit)$, where $pos$ represents the current processing position, $mask$ represents the digits that have appeared in the current number, and $limit$ represents whether there is a limit at the current position. If $limit$ is true, then the digit at the current position cannot exceed $num[pos]$.

The answer is $dfs(0, 0, true)$.

The time complexity is $O(m \times 2^{10} \times 10)$, and the space complexity is $O(m \times 2^{10})$. Where $m$ is the number of digits in $b$.

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
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberCount(a int, b int) int {
	count := 0
	for num := a; num <= b; num++ {
		if hasUniqueDigits(num) {
			count++
		}
	}
	return count
}
func hasUniqueDigits(num int) bool {
	digits := strconv.Itoa(num)
	seen := make(map[rune]bool)
	for _, digit := range digits {
		if seen[digit] {
			return false
		}
		seen[digit] = true
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberCount(a: number, b: number): number {
    let count: number = 0;
    for (let num = a; num <= b; num++) {
        if (hasUniqueDigits(num)) {
            count++;
        }
    }
    return count;
}
function hasUniqueDigits(num: number): boolean {
    const digits: Set<string> = new Set(num.toString().split(''));
    return digits.size === num.toString().length;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
        }
        return true;
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
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
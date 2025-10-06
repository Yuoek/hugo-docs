---
title: "2578_SplitWithMinimumSum"
date: 2025-10-06T00:42:37+08:00
weight: 2578
tags: [Greedy, Math, Sorting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2578. Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum)

[中文文档](/solution/2500-2599/2578.Split%20With%20Minimum%20Sum/README.md)

## Description

<!-- description:start -->

<p>Given a positive integer <code>num</code>, split it into two non-negative integers <code>num1</code> and <code>num2</code> such that:</p>

<ul>
	<li>The concatenation of <code>num1</code> and <code>num2</code> is a permutation of <code>num</code>.

    <ul>
    	<li>In other words, the sum of the number of occurrences of each digit in <code>num1</code> and <code>num2</code> is equal to the number of occurrences of that digit in <code>num</code>.</li>
    </ul>
    </li>
    <li><code>num1</code> and <code>num2</code> can contain leading zeros.</li>

</ul>

<p>Return <em>the <strong>minimum</strong> possible sum of</em> <code>num1</code> <em>and</em> <code>num2</code>.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li>It is guaranteed that <code>num</code> does not contain any leading zeros.</li>
	<li>The order of occurrence of the digits in <code>num1</code> and <code>num2</code> may differ from the order of occurrence of <code>num</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = 4325
<strong>Output:</strong> 59
<strong>Explanation:</strong> We can split 4325 so that <code>num1</code> is 24 and <code>num2</code> is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = 687
<strong>Output:</strong> 75
<strong>Explanation:</strong> We can split 687 so that <code>num1</code> is 68 and <code>num2</code> is 7, which would give an optimal sum of 75.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>10 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Counting + Greedy

First, we use a hash table or array $cnt$ to count the occurrences of each digit in $num$, and use a variable $n$ to record the number of digits in $num$.

Next, we enumerate all the digits $i$ in $nums$, and alternately allocate the digits in $cnt$ to $num1$ and $num2$ in ascending order, recording them in an array $ans$ of length $2$. Finally, we return the sum of the two numbers in $ans$.

The time complexity is $O(n)$, and the space complexity is $O(C)$. Where $n$ is the number of digits in $num$; and $C$ is the number of different digits in $num$, in this problem, $C \leq 10$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Sorting + Greedy

We can convert $num$ to a string or character array, then sort it, and then alternately allocate the digits in the sorted array to $num1$ and $num2$ in ascending order. Finally, we return the sum of $num1$ and $num2$.

The time complexity is $O(n \times \log n)$, and the space complexity is $O(n)$. Where $n$ is the number of digits in $num$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitNum(num int) int {
	s := []byte(strconv.Itoa(num))
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	ans := [2]int{}
	for i, c := range s {
		ans[i&1] = ans[i&1]*10 + int(c-'0')
	}
	return ans[0] + ans[1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitNum(num: number): number {
    const s: string[] = String(num).split('');
    s.sort();
    const ans: number[] = Array(2).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ans[i & 1] = ans[i & 1] * 10 + Number(s[i]);
    }
    return ans[0] + ans[1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn split_num(num: i32) -> i32 {
        let mut s = num.to_string().into_bytes();
        s.sort_unstable();

        let mut ans = vec![0; 2];
        for (i, c) in s.iter().enumerate() {
            ans[i & 1] = ans[i & 1] * 10 + ((c - b'0') as i32);
        }

        ans[0] + ans[1]
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
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
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
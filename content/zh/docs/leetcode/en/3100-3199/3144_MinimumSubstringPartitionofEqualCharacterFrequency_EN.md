---
title: "3144_MinimumSubstringPartitionofEqualCharacterFrequency"
date: 2025-10-06T00:42:37+08:00
weight: 3144
tags: [Hash Table, String, Dynamic Programming, Counting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [3144. Minimum Substring Partition of Equal Character Frequency](https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency)

[中文文档](/solution/3100-3199/3144.Minimum%20Substring%20Partition%20of%20Equal%20Character%20Frequency/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>s</code>, you need to partition it into one or more <strong>balanced</strong> <span data-keyword="substring">substrings</span>. For example, if <code>s == &quot;ababcc&quot;</code> then <code>(&quot;abab&quot;, &quot;c&quot;, &quot;c&quot;)</code>, <code>(&quot;ab&quot;, &quot;abc&quot;, &quot;c&quot;)</code>, and <code>(&quot;ababcc&quot;)</code> are all valid partitions, but <code>(&quot;a&quot;, <strong>&quot;bab&quot;</strong>, &quot;cc&quot;)</code>, <code>(<strong>&quot;aba&quot;</strong>, &quot;bc&quot;, &quot;c&quot;)</code>, and <code>(&quot;ab&quot;, <strong>&quot;abcc&quot;</strong>)</code> are not. The unbalanced substrings are bolded.</p>

<p>Return the <strong>minimum</strong> number of substrings that you can partition <code>s</code> into.</p>

<p><strong>Note:</strong> A <strong>balanced</strong> string is a string where each character in the string occurs the same number of times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;fabccddg&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>We can partition the string <code>s</code> into 3 substrings in one of the following ways: <code>(&quot;fab, &quot;ccdd&quot;, &quot;g&quot;)</code>, or <code>(&quot;fabc&quot;, &quot;cd&quot;, &quot;dg&quot;)</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abababaccddb&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>We can partition the string <code>s</code> into 2 substrings like so: <code>(&quot;abab&quot;, &quot;abaccddb&quot;)</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists only of English lowercase letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Memoized Search + Hash Table

We design a function $\textit{dfs}(i)$, which represents the minimum number of substrings starting from $s[i]$. The answer is $\textit{dfs}(0)$.

The calculation process of the function $\textit{dfs}(i)$ is as follows:

If $i \geq n$, it means all characters have been processed, so return $0$.

Otherwise, we maintain a hash table $\textit{cnt}$ to represent the frequency of each character in the current substring. Additionally, we maintain a hash table $\textit{freq}$ to represent the frequency of each character's occurrence count.

Then we enumerate $j$ from $i$ to $n-1$, representing the end position of the current substring. For each $j$, we update $\textit{cnt}$ and $\textit{freq}$, then check if the size of $\textit{freq}$ is $1$. If it is, we can split from $j+1$, and the answer is $1 + \textit{dfs}(j+1)$. We take the minimum answer among all $j$ as the return value of the function.

To avoid repeated calculations, we use memoized search.

The time complexity is $O(n^2)$, and the space complexity is $O(n \times |\Sigma|)$. Here, $n$ is the length of the string $s$, and $|\Sigma|$ represents the size of the character set, which is $26$ in this problem.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Memoized Search (Optimization)

We can optimize Solution 1 by not maintaining the $\textit{freq}$ hash table. Instead, we only need to maintain a hash table $\textit{cnt}$, which represents the frequency of each character in the current substring. Additionally, we maintain two variables $k$ and $m$ to represent the number of distinct characters in the current substring and the maximum frequency of any character, respectively. For a substring $s[i..j]$, if $j-i+1 = m \times k$, then this substring is a balanced substring.

The time complexity is $O(n^2)$, and the space complexity is $O(n \times |\Sigma|)$. Here, $n$ is the length of the string $s$, and $|\Sigma|$ represents the size of the character set, which is $26$ in this problem.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: Dynamic Programming

We can convert the memoized search into dynamic programming. Define the state $f[i]$ as the minimum number of substrings required to partition the first $i$ characters. Initially, $f[0] = 0$, and the rest $f[i] = +\infty$ or $f[i] = n$.

Next, we enumerate $i$ from $0$ to $n-1$. For each $i$, we maintain a hash table $\textit{cnt}$ to represent the frequency of each character in the current substring. Additionally, we maintain two variables $k$ and $m$ to represent the number of distinct characters in the current substring and the maximum frequency of any character, respectively. For a substring $s[j..i]$, if $i-j+1 = m \times k$, then this substring is a balanced substring. At this point, we can partition from $j$, so $f[i+1] = \min(f[i+1], f[j] + 1)$.

The final answer is $f[n]$.

The time complexity is $O(n^2)$, and the space complexity is $O(n + |\Sigma|)$. Here, $n$ is the length of the string $s$, and $|\Sigma|$ represents the size of the character set, which is $26$ in this problem.

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
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(n):
            cnt = defaultdict(int)
            m = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                m = max(m, cnt[s[j]])
                if i - j + 1 == len(cnt) * m:
                    f[i + 1] = min(f[i + 1], f[j] + 1)
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int[] f = new int[n + 1];
        Arrays.fill(f, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            int k = 0, m = 0;
            for (int j = i; j >= 0; --j) {
                k += ++cnt[cs[j] - 'a'] == 1 ? 1 : 0;
                m = Math.max(m, cnt[cs[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
                }
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            int k = 0, m = 0;
            for (int j = i; ~j; --j) {
                k += ++cnt[s[j] - 'a'] == 1;
                m = max(m, cnt[s[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n+1)
	for i := range f {
		f[i] = n
	}
	f[0] = 0
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		k, m := 0, 0
		for j := i; j >= 0; j-- {
			x := int(s[j] - 'a')
			cnt[x]++
			if cnt[x] == 1 {
				k++
			}
			m = max(m, cnt[x])
			if i-j+1 == k*m {
				f[i+1] = min(f[i+1], 1+f[j])
			}
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSubstringsInPartition(s: string): number {
    const n = s.length;
    const f: number[] = Array(n + 1).fill(n);
    f[0] = 0;
    for (let i = 0; i < n; ++i) {
        const cnt: number[] = Array(26).fill(0);
        let [k, m] = [0, 0];
        for (let j = i; ~j; --j) {
            const x = s.charCodeAt(j) - 97;
            k += ++cnt[x] === 1 ? 1 : 0;
            m = Math.max(m, cnt[x]);
            if (i - j + 1 === k * m) {
                f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
            }
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(n):
            cnt = defaultdict(int)
            m = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                m = max(m, cnt[s[j]])
                if i - j + 1 == len(cnt) * m:
                    f[i + 1] = min(f[i + 1], f[j] + 1)
        return f[n]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int[] f = new int[n + 1];
        Arrays.fill(f, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            int k = 0, m = 0;
            for (int j = i; j >= 0; --j) {
                k += ++cnt[cs[j] - 'a'] == 1 ? 1 : 0;
                m = Math.max(m, cnt[cs[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
                }
            }
        }
        return f[n];
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
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            int k = 0, m = 0;
            for (int j = i; ~j; --j) {
                k += ++cnt[s[j] - 'a'] == 1;
                m = max(m, cnt[s[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
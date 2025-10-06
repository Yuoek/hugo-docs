---
title: "3144_MinimumSubstringPartitionofEqualCharacterFrequency"
date: 2025-10-06T00:42:37+08:00
weight: 3144
tags: [哈希表, 字符串, 动态规划, 计数]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3144. 分割字符频率相等的最少子字符串](https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency)

[English Version](../en/3144-44/3144_MinimumSubstringPartitionofEqualCharacterFrequency)

## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，你需要将它分割成一个或者更多的&nbsp;<strong>平衡</strong>&nbsp;子字符串。比方说，<code>s == "ababcc"</code>&nbsp;那么&nbsp;<code>("abab", "c", "c")</code>&nbsp;，<code>("ab", "abc", "c")</code>&nbsp;和&nbsp;<code>("ababcc")</code>&nbsp;都是合法分割，但是&nbsp;<code>("a", <strong>"bab"</strong>, "cc")</code>&nbsp;，<code>(<strong>"aba"</strong>, "bc", "c")</code>&nbsp;和&nbsp;<code>("ab", <strong>"abcc"</strong>)</code>&nbsp;不是，不平衡的子字符串用粗体表示。</p>

<p>请你返回 <code>s</code>&nbsp;<strong>最少</strong> 能分割成多少个平衡子字符串。</p>

<p><b>注意：</b>一个 <strong>平衡</strong>&nbsp;字符串指的是字符串中所有字符出现的次数都相同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "fabccddg"</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将 <code>s</code>&nbsp;分割成 3 个子字符串：<code>("fab, "ccdd", "g")</code>&nbsp;或者&nbsp;<code>("fabc", "cd", "dg")</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abababaccddb"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将&nbsp;<code>s</code>&nbsp;分割成 2 个子字符串：<code>("abab", "abaccddb")</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 哈希表

我们设计一个函数 $\textit{dfs}(i)$，表示从字符串 $s[i]$ 开始分割的最少子字符串数量。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的计算过程如下：

如果 $i \geq n$，表示已经处理完了所有字符，返回 $0$。

否则，我们维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，我们还维护一个哈希表 $\textit{freq}$，表示每个字符出现的次数的频率。

然后我们枚举 $j$ 从 $i$ 到 $n-1$，表示当前子字符串的结束位置。对于每个 $j$，我们更新 $\textit{cnt}$ 和 $\textit{freq}$，然后判断 $\textit{freq}$ 的大小是否为 $1$，如果是的话，我们可以从 $j+1$ 开始分割，此时答案为 $1 + \textit{dfs}(j+1)$，我们取所有 $j$ 中答案的最小值作为函数的返回值。

为了避免重复计算，我们使用记忆化搜索。

时间复杂度 $O(n^2)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：记忆化搜索（优化）

我们可以对方法一进行优化，不需要维护 $\textit{freq}$ 哈希表，只需要维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，维护两个变量 $k$ 和 $m$ 分别表示当前子字符串中的字符种类数和出现次数最多的字符的出现次数。对于一个子串 $s[i..j]$，如果 $j-i+1 = m \times k$，那么这个子串就是一个平衡子串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划

我们可以将记忆化搜索转换为动态规划，定义状态 $f[i]$ 对前 $i$ 个字符进行分割的最少子字符串数量。初始时 $f[0] = 0$，其余 $f[i] = +\infty$ 或者 $f[i] = n$。

接下来我们枚举 $i$ 从 $0$ 到 $n-1$，对于每个 $i$，我们维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，我们维护两个变量 $k$ 和 $m$ 分别表示当前子字符串中的字符种类数和出现次数最多的字符的出现次数。对于一个子串 $s[j..i]$，如果 $i-j+1 = m \times k$，那么这个子串就是一个平衡子串。此时我们可以从 $j$ 开始分割，那么 $f[i+1] = \min(f[i+1], f[j] + 1)$。

最终答案为 $f[n]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n + |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

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
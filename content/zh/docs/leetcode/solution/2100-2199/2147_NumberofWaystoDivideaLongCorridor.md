---
title: "2147_NumberofWaystoDivideaLongCorridor"
date: 2025-10-06T00:42:37+08:00
weight: 2147
tags: [数学, 字符串, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [2147. 分隔长廊的方案数](https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor)

[English Version](../en/2147-47/2147_NumberofWaystoDivideaLongCorridor)

## 题目描述

<!-- description:start -->

<p>在一个图书馆的长廊里，有一些座位和装饰植物排成一列。给你一个下标从 <strong>0</strong>&nbsp;开始，长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>corridor</code>&nbsp;，它包含字母&nbsp;<code>'S'</code> 和&nbsp;<code>'P'</code>&nbsp;，其中每个&nbsp;<code>'S'</code>&nbsp;表示一个座位，每个&nbsp;<code>'P'</code>&nbsp;表示一株植物。</p>

<p>在下标 <code>0</code>&nbsp;的左边和下标 <code>n - 1</code>&nbsp;的右边 <strong>已经</strong>&nbsp;分别各放了一个屏风。你还需要额外放置一些屏风。每一个位置&nbsp;<code>i - 1</code> 和&nbsp;<code>i</code>&nbsp;之间（<code>1 &lt;= i &lt;= n - 1</code>），至多能放一个屏风。</p>

<p>请你将走廊用屏风划分为若干段，且每一段内都 <strong>恰好有两个座位</strong>&nbsp;，而每一段内植物的数目没有要求。可能有多种划分方案，如果两个方案中有任何一个屏风的位置不同，那么它们被视为 <strong>不同</strong> 方案。</p>

<p>请你返回划分走廊的方案数。由于答案可能很大，请你返回它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。如果没有任何方案，请返回&nbsp;<code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/1.png" style="width: 410px; height: 199px;"></p>

<pre><b>输入：</b>corridor = "SSPPSPS"
<b>输出：</b>3
<b>解释：</b>总共有 3 种不同分隔走廊的方案。
上图中黑色的竖线表示已经放置好的屏风。
上图每种方案中，每一段都恰好有 <strong>两个</strong>&nbsp;座位。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/2.png" style="width: 357px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "PPSPSP"
<b>输出：</b>1
<b>解释：</b>只有 1 种分隔走廊的方案，就是不放置任何屏风。
放置任何的屏风都会导致有一段无法恰好有 2 个座位。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/3.png" style="width: 115px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "S"
<b>输出：</b>0
<b>解释：</b>没有任何方案，因为总是有一段无法恰好有 2 个座位。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == corridor.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>corridor[i]</code>&nbsp;要么是&nbsp;<code>'S'</code>&nbsp;，要么是&nbsp;<code>'P'</code> 。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, k)$，表示在走廊的第 $i$ 个位置，已经放置了 $k$ 个屏风的情况下，划分走廊的方案数。那么答案就是 $\textit{dfs}(0, 0)$。

函数 $\textit{dfs}(i, k)$ 的计算过程如下：

如果 $i \geq \textit{len}(\textit{corridor})$，表示已经遍历完了走廊，此时如果 $k = 2$，说明找到了一种划分走廊的方案，返回 $1$，否则返回 $0$；

否则，我们需要考虑当前位置 $i$ 的情况：

-   如果 $\textit{corridor}[i] = \text{'S'}$，表示当前位置是一个座位，我们将 $k$ 加 $1$；
-   如果 $k > 2$，表示当前位置放置的屏风数量超过了 $2$，返回 $0$；
-   否则，我们可以选择不放置屏风，即 $\textit{dfs}(i + 1, k)$；如果 $k = 2$，我们还可以选择放置屏风，即 $\textit{dfs}(i + 1, 0)$；我们将这两种情况的结果相加并取模 $10^9 + 7$，即 $\textit{ans} = (\textit{ans} + \textit{dfs}(i + 1, k)) \bmod \text{mod}$。

最后，我们返回 $\textit{dfs}(0, 0)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是走廊的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们可以将每两个座位划分为一组。在相邻的两组座位之间，如果前一组的最后一个座位和后一组的第一个座位之间的距离为 $x$，那么就有 $x$ 种放置屏风的方案。

我们遍历走廊，用一个变量 $\textit{cnt}$ 记录当前座位数，用一个变量 $\textit{last}$ 记录上一个座位的位置。

当遍历到一个座位时，我们将 $\textit{cnt}$ 加 $1$，如果 $\textit{cnt}$ 大于 $2$ 且 $\textit{cnt}$ 为奇数，那么我们就需要在 $\textit{last}$ 和当前座位之间放置一个屏风，此时的方案数就是 $\textit{ans} \times (i - \textit{last})$，其中 $\textit{ans}$ 是之前的方案数。然后，我们更新 $\textit{last}$ 为当前座位的位置 $i$。

最后，如果 $\textit{cnt}$ 大于 $0$ 且 $\textit{cnt}$ 为偶数，那么返回 $\textit{ans}$，否则返回 $0$。

时间复杂度 $O(n)$，其中 $n$ 是走廊的长度。空间复杂度 $O(1)$。

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
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        ans, cnt, last = 1, 0, 0
        for i, c in enumerate(corridor):
            if c == "S":
                cnt += 1
                if cnt > 2 and cnt % 2:
                    ans = ans * (i - last) % mod
                last = i
        return ans if cnt and cnt % 2 == 0 else 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfWays(String corridor) {
        final int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor.charAt(i) == 'S') {
                if (++cnt > 2 && cnt % 2 == 1) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? (int) ans : 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                if (++cnt > 2 && cnt % 2) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? ans : 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(corridor string) int {
	const mod int = 1e9 + 7
	ans, cnt, last := 1, 0, 0
	for i, c := range corridor {
		if c == 'S' {
			cnt++
			if cnt > 2 && cnt%2 == 1 {
				ans = ans * (i - last) % mod
			}
			last = i
		}
	}
	if cnt > 0 && cnt%2 == 0 {
		return ans
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWays(corridor: string): number {
    const mod = 10 ** 9 + 7;
    const n = corridor.length;
    let [ans, cnt, last] = [1, 0, 0];
    for (let i = 0; i < n; ++i) {
        if (corridor[i] === 'S') {
            if (++cnt > 2 && cnt % 2) {
                ans = (ans * (i - last)) % mod;
            }
            last = i;
        }
    }
    return cnt > 0 && cnt % 2 === 0 ? ans : 0;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        ans, cnt, last = 1, 0, 0
        for i, c in enumerate(corridor):
            if c == "S":
                cnt += 1
                if cnt > 2 and cnt % 2:
                    ans = ans * (i - last) % mod
                last = i
        return ans if cnt and cnt % 2 == 0 else 0
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int numberOfWays(String corridor) {
        final int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor.charAt(i) == 'S') {
                if (++cnt > 2 && cnt % 2 == 1) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? (int) ans : 0;
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
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                if (++cnt > 2 && cnt % 2) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? ans : 0;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
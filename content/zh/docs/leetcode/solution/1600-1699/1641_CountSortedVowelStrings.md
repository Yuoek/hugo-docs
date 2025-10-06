---
title: "1641_CountSortedVowelStrings"
date: 2025-10-06T00:42:37+08:00
weight: 1641
tags: [数学, 动态规划, 组合数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1641. 统计字典序元音字符串的数目](https://leetcode.cn/problems/count-sorted-vowel-strings)

[English Version](../en/1641-41/1641_CountSortedVowelStrings)

## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，请返回长度为 <code>n</code> 、仅由元音 (<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>) 组成且按 <strong>字典序排列</strong> 的字符串数量。</p>

<p>字符串 <code>s</code> 按 <strong>字典序排列</strong> 需要满足：对于所有有效的 <code>i</code>，<code>s[i]</code> 在字母表中的位置总是与 <code>s[i+1]</code> 相同或在 <code>s[i+1]</code> 之前。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>5
<strong>解释：</strong>仅由元音组成的 5 个字典序字符串为 <code>["a","e","i","o","u"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>15
<strong>解释：</strong>仅由元音组成的 15 个字典序字符串为
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 33
<strong>输出：</strong>66045
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 50</code> </li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示当前已经选了 $i$ 个元音字母，且最后一个元音字母是 $j$ 的方案数。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $i \ge n$，说明已经选了 $n$ 个元音字母，返回 $1$。
-   否则，枚举 $j$ 后面的元音字母，即 $k \in [j, 4]$，并将 $dfs(i + 1, k)$ 的结果累加，即 $dfs(i, j) = \sum_{k = j}^4 dfs(i + 1, k)$。

过程中，我们可以使用记忆化搜索，将已经计算过的 $dfs(i, j)$ 的结果保存起来，避免重复计算。

时间复杂度 $O(n \times C^2)$，空间复杂度 $O(n \times C)$。其中 $n$ 为题目给定的整数，而 $C$ 是元音字母的数量，本题中 $C = 5$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 前缀和

定义 $f[i][j]$ 表示当前已经选了 $i$ 个元音字母，且最后一个元音字母是 $j$ 的方案数。初始时 $f[1][j]=1$。答案是 $\sum_{j = 0}^4 f[n][j]$。

我们可以发现 $f[i][j]$ 只与 $f[i - 1][j]$ 有关，因此可以将二维数组压缩为一维数组，从而优化空间复杂度。

时间复杂度 $O(n \times C)$，空间复杂度 $O(C)$。其中 $n$ 为题目给定的整数，而 $C$ 是元音字母的数量，本题中 $C = 5$。

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
    def countVowelStrings(self, n: int) -> int:
        f = [1] * 5
        for _ in range(n - 1):
            s = 0
            for j in range(5):
                s += f[j]
                f[j] = s
        return sum(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countVowelStrings(int n) {
        int[] f = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return Arrays.stream(f).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int f[5] = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return accumulate(f, f + 5, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countVowelStrings(n int) (ans int) {
	f := [5]int{1, 1, 1, 1, 1}
	for i := 0; i < n-1; i++ {
		s := 0
		for j := 0; j < 5; j++ {
			s += f[j]
			f[j] = s
		}
	}
	for _, v := range f {
		ans += v
	}
	return
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countVowelStrings(self, n: int) -> int:
        f = [1] * 5
        for _ in range(n - 1):
            s = 0
            for j in range(5):
                s += f[j]
                f[j] = s
        return sum(f)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countVowelStrings(int n) {
        int[] f = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return Arrays.stream(f).sum();
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
    int countVowelStrings(int n) {
        int f[5] = {1, 1, 1, 1, 1};
        for (int i = 0; i < n - 1; ++i) {
            int s = 0;
            for (int j = 0; j < 5; ++j) {
                s += f[j];
                f[j] = s;
            }
        }
        return accumulate(f, f + 5, 0);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
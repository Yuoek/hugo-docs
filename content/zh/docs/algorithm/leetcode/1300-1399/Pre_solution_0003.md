---
title: "1320_二指输入的的最小距离"
date: 2025-10-08T18:37:12+08:00
weight: 3
tags: [二叉树, 动态规划, 字符串, 排序, 数学, 数据库, 数组, 树, 模拟, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [1320_二指输入的的最小距离](#1320)
#### [字符串](#1320)
#### [动态规划](#1320)
### [1321_餐馆营业额变化增长](#1321)
#### [数据库](#1321)
### [1322_广告效果 🔒](#1322)
#### [数据库](#1322)
### [1323_6 和 9 组成的最大数字](#1323)
#### [贪心](#1323)
#### [数学](#1323)
### [1324_竖直打印单词](#1324)
#### [数组](#1324)
#### [字符串](#1324)
#### [模拟](#1324)
### [1325_删除给定值的叶子节点](#1325)
#### [树](#1325)
#### [深度优先搜索](#1325)
#### [二叉树](#1325)
### [1326_灌溉花园的最少水龙头数目](#1326)
#### [贪心](#1326)
#### [数组](#1326)
#### [动态规划](#1326)
### [1327_列出指定时间段内所有的下单产品](#1327)
#### [数据库](#1327)
### [1328_破坏回文串](#1328)
#### [贪心](#1328)
#### [字符串](#1328)
### [1329_将矩阵按对角线排序](#1329)
#### [数组](#1329)
#### [矩阵](#1329)
#### [排序](#1329)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1320_二指输入的的最小距离
___
#### 字符串
___
#### 动态规划
---
### 1321_餐馆营业额变化增长
___
#### 数据库
---
### 1322_广告效果 🔒
___
#### 数据库
---
### 1323_6 和 9 组成的最大数字
___
#### 贪心
___
#### 数学
---
### 1324_竖直打印单词
___
#### 数组
___
#### 字符串
___
#### 模拟
---
### 1325_删除给定值的叶子节点
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1326_灌溉花园的最少水龙头数目
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 1327_列出指定时间段内所有的下单产品
___
#### 数据库
---
### 1328_破坏回文串
___
#### 贪心
___
#### 字符串
---
### 1329_将矩阵按对角线排序
___
#### 数组
___
#### 矩阵
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [1320. 二指输入的的最小距离](https://leetcode.cn/problems/minimum-distance-to-type-a-word-using-two-fingers){#1320}

{{< tabs "1320" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(a: int, b: int) -> int:
            x1, y1 = divmod(a, 6)
            x2, y2 = divmod(b, 6)
            return abs(x1 - x2) + abs(y1 - y2)

        n = len(word)
        f = [[[inf] * 26 for _ in range(26)] for _ in range(n)]
        for j in range(26):
            f[0][ord(word[0]) - ord('A')][j] = 0
            f[0][j][ord(word[0]) - ord('A')] = 0
        for i in range(1, n):
            a, b = ord(word[i - 1]) - ord('A'), ord(word[i]) - ord('A')
            d = dist(a, b)
            for j in range(26):
                f[i][b][j] = min(f[i][b][j], f[i - 1][a][j] + d)
                f[i][j][b] = min(f[i][j][b], f[i - 1][j][a] + d)
                if j == a:
                    for k in range(26):
                        t = dist(k, b)
                        f[i][b][j] = min(f[i][b][j], f[i - 1][k][a] + t)
                        f[i][j][b] = min(f[i][j][b], f[i - 1][a][k] + t)
        a = min(f[n - 1][ord(word[-1]) - ord('A')])
        b = min(f[n - 1][j][ord(word[-1]) - ord('A')] for j in range(26))
        return int(min(a, b))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDistance(String word) {
        int n = word.length();
        final int inf = 1 << 30;
        int[][][] f = new int[n][26][26];
        for (int[][] g : f) {
            for (int[] h : g) {
                Arrays.fill(h, inf);
            }
        }
        for (int j = 0; j < 26; ++j) {
            f[0][word.charAt(0) - 'A'][j] = 0;
            f[0][j][word.charAt(0) - 'A'] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int a = word.charAt(i - 1) - 'A';
            int b = word.charAt(i) - 'A';
            int d = dist(a, b);
            for (int j = 0; j < 26; ++j) {
                f[i][b][j] = Math.min(f[i][b][j], f[i - 1][a][j] + d);
                f[i][j][b] = Math.min(f[i][j][b], f[i - 1][j][a] + d);
                if (j == a) {
                    for (int k = 0; k < 26; ++k) {
                        int t = dist(k, b);
                        f[i][b][j] = Math.min(f[i][b][j], f[i - 1][k][a] + t);
                        f[i][j][b] = Math.min(f[i][j][b], f[i - 1][a][k] + t);
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 26; ++j) {
            ans = Math.min(ans, f[n - 1][j][word.charAt(n - 1) - 'A']);
            ans = Math.min(ans, f[n - 1][word.charAt(n - 1) - 'A'][j]);
        }
        return ans;
    }

    private int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        const int inf = 1 << 30;
        vector<vector<vector<int>>> f(n, vector<vector<int>>(26, vector<int>(26, inf)));
        for (int j = 0; j < 26; ++j) {
            f[0][word[0] - 'A'][j] = 0;
            f[0][j][word[0] - 'A'] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int a = word[i - 1] - 'A';
            int b = word[i] - 'A';
            int d = dist(a, b);
            for (int j = 0; j < 26; ++j) {
                f[i][b][j] = min(f[i][b][j], f[i - 1][a][j] + d);
                f[i][j][b] = min(f[i][j][b], f[i - 1][j][a] + d);
                if (j == a) {
                    for (int k = 0; k < 26; ++k) {
                        int t = dist(k, b);
                        f[i][b][j] = min(f[i][b][j], f[i - 1][k][a] + t);
                        f[i][j][b] = min(f[i][j][b], f[i - 1][a][k] + t);
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 26; ++j) {
            ans = min(ans, f[n - 1][word[n - 1] - 'A'][j]);
            ans = min(ans, f[n - 1][j][word[n - 1] - 'A']);
        }
        return ans;
    }

    int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDistance(word string) int {
	n := len(word)
	f := make([][26][26]int, n)
	const inf = 1 << 30
	for i := range f {
		for j := range f[i] {
			for k := range f[i][j] {
				f[i][j][k] = inf
			}
		}
	}
	for j := range f[0] {
		f[0][word[0]-'A'][j] = 0
		f[0][j][word[0]-'A'] = 0
	}
	dist := func(a, b int) int {
		x1, y1 := a/6, a%6
		x2, y2 := b/6, b%6
		return abs(x1-x2) + abs(y1-y2)
	}
	for i := 1; i < n; i++ {
		a, b := int(word[i-1]-'A'), int(word[i]-'A')
		d := dist(a, b)
		for j := 0; j < 26; j++ {
			f[i][b][j] = min(f[i][b][j], f[i-1][a][j]+d)
			f[i][j][b] = min(f[i][j][b], f[i-1][j][a]+d)
			if j == a {
				for k := 0; k < 26; k++ {
					t := dist(k, b)
					f[i][b][j] = min(f[i][b][j], f[i-1][k][a]+t)
					f[i][j][b] = min(f[i][j][b], f[i-1][a][k]+t)
				}
			}
		}
	}
	ans := inf
	for j := 0; j < 26; j++ {
		ans = min(ans, f[n-1][word[n-1]-'A'][j])
		ans = min(ans, f[n-1][j][word[n-1]-'A'])
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1320.Minimum%20Distance%20to%20Type%20a%20Word%20Using%20Two%20Fingers/images/leetcode_keyboard.png" /></p>

<p>二指输入法定制键盘在 <strong>X-Y</strong> 平面上的布局如上图所示，其中每个大写英文字母都位于某个坐标处。</p>

<ul>
	<li>例如字母&nbsp;<strong>A</strong>&nbsp;位于坐标&nbsp;<strong>(0,0)</strong>，字母&nbsp;<strong>B</strong>&nbsp;位于坐标&nbsp;<strong>(0,1)</strong>，字母&nbsp;<strong>P</strong>&nbsp;位于坐标&nbsp;<strong>(2,3)</strong>&nbsp;且字母 <strong>Z</strong>&nbsp;位于坐标&nbsp;<strong>(4,1)</strong>。</li>
</ul>

<p>给你一个待输入字符串&nbsp;<code>word</code>，请你计算并返回在仅使用两根手指的情况下，键入该字符串需要的最小移动总距离。</p>

<p>坐标<code>&nbsp;<strong>(x<sub>1</sub>,y<sub>1</sub>)</strong> </code>和 <code><strong>(x<sub>2</sub>,y<sub>2</sub>)</strong></code> 之间的 <strong>距离</strong> 是&nbsp;<code><strong>|x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|</strong></code>。&nbsp;</p>

<p><strong>注意</strong>，两根手指的起始位置是零代价的，不计入移动总距离。你的两根手指的起始位置也不必从首字母或者前两个字母开始。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "CAKE"
<strong>输出：</strong>3
<strong>解释： 
</strong>使用两根手指输入 "CAKE" 的最佳方案之一是： 
手指 1 在字母 'C' 上 -&gt; 移动距离 = 0 
手指 1 在字母 'A' 上 -&gt; 移动距离 = 从字母 'C' 到字母 'A' 的距离 = 2 
手指 2 在字母 'K' 上 -&gt; 移动距离 = 0 
手指 2 在字母 'E' 上 -&gt; 移动距离 = 从字母 'K' 到字母 'E' 的距离  = 1 
总距离 = 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "HAPPY"
<strong>输出：</strong>6
<strong>解释： </strong>
使用两根手指输入 "HAPPY" 的最佳方案之一是：
手指 1 在字母 'H' 上 -&gt; 移动距离 = 0
手指 1 在字母 'A' 上 -&gt; 移动距离 = 从字母 'H' 到字母 'A' 的距离 = 2
手指 2 在字母 'P' 上 -&gt; 移动距离 = 0
手指 2 在字母 'P' 上 -&gt; 移动距离 = 从字母 'P' 到字母 'P' 的距离 = 0
手指 1 在字母 'Y' 上 -&gt; 移动距离 = 从字母 'A' 到字母 'Y' 的距离 = 4
总距离 = 6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= word.length &lt;= 300</code></li>
	<li>每个 <code>word[i]</code>&nbsp;都是一个大写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j][k]$ 表示输入完 $\textit{word}[i]$，且手指 $1$ 位于位置 $j$，手指 $2$ 位于位置 $k$ 时，最小的移动距离。这里的位置 $j$ 和 $k$ 表示的是字母对应的数字，取值范围为 $[0,..25]$。初始时 $f[i][j][k]=\infty$。

我们实现一个函数 $\textit{dist}(a, b)$，表示位置 $a$ 和位置 $b$ 之间的距离，即 $\textit{dist}(a, b) = |\frac{a}{6} - \frac{b}{6}| + |a \bmod 6 - b \bmod 6|$。

接下来，我们考虑输入 $\textit{word}[0]$，即只有一个字母的的情况，此时有两种选择：

-   手指 $1$ 位于 $\textit{word}[0]$ 所在的位置，手指 $2$ 位于任意位置，此时 $f[0][\textit{word}[0]][k] = 0$，其中 $k \in [0,..25]$。
-   手指 $2$ 位于 $\textit{word}[0]$ 所在的位置，手指 $1$ 位于任意位置，此时 $f[0][k][\textit{word}[0]] = 0$，其中 $k \in [0,..25]$。

然后我们考虑输入 $\textit{word}[1,..n-1]$，我们记上一个字母和当前字母所在的位置分别为 $a$ 和 $b$，接下来我们进行分情况讨论：

如果当前手指 $1$ 位于位置 $b$，我们枚举手指 $2$ 的位置 $j$，假如上一个位置 $a$ 也是手指 $1$ 的位置，那么此时有 $f[i][b][j]=\min(f[i][b][j], f[i-1][a][j]+\textit{dist}(a, b))$。如果手指 $2$ 的位置与上一个位置 $a$ 相同，即 $j=a$，那么我们枚举上一个位置的手指 $1$ 所在的位置 $k$，此时有 $f[i][j][j]=\min(f[i][b][j], f[i-1][k][a]+\textit{dist}(k, b))$。

同理，如果当前手指 $2$ 位于位置 $b$，我们枚举手指 $1$ 的位置 $j$，假如上一个位置 $a$ 也是手指 $2$ 的位置，那么此时有 $f[i][j][b]=\min(f[i][j][b], f[i-1][j][a]+\textit{dist}(a, b))$。如果手指 $1$ 的位置与上一个位置 $a$ 相同，即 $j=a$，那么我们枚举上一个位置的手指 $2$ 所在的位置 $k$，此时有 $f[i][j][b]=\min(f[i][j][b], f[i-1][a][k]+\textit{dist}(k, b))$。

最后，我们枚举最后一个位置的手指 $1$ 和手指 $2$ 所在的位置，取最小值即为答案。

时间复杂度 $O(n \times |\Sigma|^2)$，空间复杂度 $O(n \times |\Sigma|^2)$。其中 $n$ 为字符串 $\textit{word}$ 的长度，而 $|\Sigma|$ 为字母表的大小，本题中 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(a: int, b: int) -> int:
            x1, y1 = divmod(a, 6)
            x2, y2 = divmod(b, 6)
            return abs(x1 - x2) + abs(y1 - y2)

        n = len(word)
        f = [[[inf] * 26 for _ in range(26)] for _ in range(n)]
        for j in range(26):
            f[0][ord(word[0]) - ord('A')][j] = 0
            f[0][j][ord(word[0]) - ord('A')] = 0
        for i in range(1, n):
            a, b = ord(word[i - 1]) - ord('A'), ord(word[i]) - ord('A')
            d = dist(a, b)
            for j in range(26):
                f[i][b][j] = min(f[i][b][j], f[i - 1][a][j] + d)
                f[i][j][b] = min(f[i][j][b], f[i - 1][j][a] + d)
                if j == a:
                    for k in range(26):
                        t = dist(k, b)
                        f[i][b][j] = min(f[i][b][j], f[i - 1][k][a] + t)
                        f[i][j][b] = min(f[i][j][b], f[i - 1][a][k] + t)
        a = min(f[n - 1][ord(word[-1]) - ord('A')])
        b = min(f[n - 1][j][ord(word[-1]) - ord('A')] for j in range(26))
        return int(min(a, b))
```

#### Java

```java
class Solution {
    public int minimumDistance(String word) {
        int n = word.length();
        final int inf = 1 << 30;
        int[][][] f = new int[n][26][26];
        for (int[][] g : f) {
            for (int[] h : g) {
                Arrays.fill(h, inf);
            }
        }
        for (int j = 0; j < 26; ++j) {
            f[0][word.charAt(0) - 'A'][j] = 0;
            f[0][j][word.charAt(0) - 'A'] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int a = word.charAt(i - 1) - 'A';
            int b = word.charAt(i) - 'A';
            int d = dist(a, b);
            for (int j = 0; j < 26; ++j) {
                f[i][b][j] = Math.min(f[i][b][j], f[i - 1][a][j] + d);
                f[i][j][b] = Math.min(f[i][j][b], f[i - 1][j][a] + d);
                if (j == a) {
                    for (int k = 0; k < 26; ++k) {
                        int t = dist(k, b);
                        f[i][b][j] = Math.min(f[i][b][j], f[i - 1][k][a] + t);
                        f[i][j][b] = Math.min(f[i][j][b], f[i - 1][a][k] + t);
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 26; ++j) {
            ans = Math.min(ans, f[n - 1][j][word.charAt(n - 1) - 'A']);
            ans = Math.min(ans, f[n - 1][word.charAt(n - 1) - 'A'][j]);
        }
        return ans;
    }

    private int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        const int inf = 1 << 30;
        vector<vector<vector<int>>> f(n, vector<vector<int>>(26, vector<int>(26, inf)));
        for (int j = 0; j < 26; ++j) {
            f[0][word[0] - 'A'][j] = 0;
            f[0][j][word[0] - 'A'] = 0;
        }
        for (int i = 1; i < n; ++i) {
            int a = word[i - 1] - 'A';
            int b = word[i] - 'A';
            int d = dist(a, b);
            for (int j = 0; j < 26; ++j) {
                f[i][b][j] = min(f[i][b][j], f[i - 1][a][j] + d);
                f[i][j][b] = min(f[i][j][b], f[i - 1][j][a] + d);
                if (j == a) {
                    for (int k = 0; k < 26; ++k) {
                        int t = dist(k, b);
                        f[i][b][j] = min(f[i][b][j], f[i - 1][k][a] + t);
                        f[i][j][b] = min(f[i][j][b], f[i - 1][a][k] + t);
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < 26; ++j) {
            ans = min(ans, f[n - 1][word[n - 1] - 'A'][j]);
            ans = min(ans, f[n - 1][j][word[n - 1] - 'A']);
        }
        return ans;
    }

    int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
```

#### Go

```go
func minimumDistance(word string) int {
	n := len(word)
	f := make([][26][26]int, n)
	const inf = 1 << 30
	for i := range f {
		for j := range f[i] {
			for k := range f[i][j] {
				f[i][j][k] = inf
			}
		}
	}
	for j := range f[0] {
		f[0][word[0]-'A'][j] = 0
		f[0][j][word[0]-'A'] = 0
	}
	dist := func(a, b int) int {
		x1, y1 := a/6, a%6
		x2, y2 := b/6, b%6
		return abs(x1-x2) + abs(y1-y2)
	}
	for i := 1; i < n; i++ {
		a, b := int(word[i-1]-'A'), int(word[i]-'A')
		d := dist(a, b)
		for j := 0; j < 26; j++ {
			f[i][b][j] = min(f[i][b][j], f[i-1][a][j]+d)
			f[i][j][b] = min(f[i][j][b], f[i-1][j][a]+d)
			if j == a {
				for k := 0; k < 26; k++ {
					t := dist(k, b)
					f[i][b][j] = min(f[i][b][j], f[i-1][k][a]+t)
					f[i][j][b] = min(f[i][j][b], f[i-1][a][k]+t)
				}
			}
		}
	}
	ans := inf
	for j := 0; j < 26; j++ {
		ans = min(ans, f[n-1][word[n-1]-'A'][j])
		ans = min(ans, f[n-1][j][word[n-1]-'A'])
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1321. 餐馆营业额变化增长](https://leetcode.cn/problems/restaurant-growth){#1321}

{{< tabs "1321" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    a.visited_on,
    SUM(b.amount) AS amount,
    ROUND(SUM(b.amount) / 7, 2) AS average_amount
FROM
    (SELECT DISTINCT visited_on FROM customer) AS a
    JOIN customer AS b ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
WHERE a.visited_on >= (SELECT MIN(visited_on) FROM customer) + 6
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Customer</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
| visited_on    | date    |
| amount        | int     |
+---------------+---------+
在 SQL 中，(customer_id, visited_on) 是该表的主键。
该表包含一家餐馆的顾客交易数据。
visited_on 表示 (customer_id) 的顾客在 visited_on 那天访问了餐馆。
amount 是一个顾客某一天的消费总额。
</pre>

<p>&nbsp;</p>

<p>你是餐馆的老板，现在你想分析一下可能的营业额变化增长（每天至少有一位顾客）。</p>

<p>计算以 7 天（某日期 + 该日期前的 6 天）为一个时间段的顾客消费平均值。<code>average_amount</code>&nbsp;要 <strong>保留两位小数。</strong></p>

<p>结果按 <code>visited_on</code>&nbsp;<strong>升序排序</strong>。</p>

<p>返回结果格式的例子如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Customer 表:
+-------------+--------------+--------------+-------------+
| customer_id | name         | visited_on   | amount      |
+-------------+--------------+--------------+-------------+
| 1           | Jhon         | 2019-01-01   | 100         |
| 2           | Daniel       | 2019-01-02   | 110         |
| 3           | Jade         | 2019-01-03   | 120         |
| 4           | Khaled       | 2019-01-04   | 130         |
| 5           | Winston      | 2019-01-05   | 110         | 
| 6           | Elvis        | 2019-01-06   | 140         | 
| 7           | Anna         | 2019-01-07   | 150         |
| 8           | Maria        | 2019-01-08   | 80          |
| 9           | Jaze         | 2019-01-09   | 110         | 
| 1           | Jhon         | 2019-01-10   | 130         | 
| 3           | Jade         | 2019-01-10   | 150         | 
+-------------+--------------+--------------+-------------+
<strong>输出：</strong>
+--------------+--------------+----------------+
| visited_on   | amount       | average_amount |
+--------------+--------------+----------------+
| 2019-01-07   | 860          | 122.86         |
| 2019-01-08   | 840          | 120            |
| 2019-01-09   | 840          | 120            |
| 2019-01-10   | 1000         | 142.86         |
+--------------+--------------+----------------+
<strong>解释：</strong>
第一个七天消费平均值从 2019-01-01 到 2019-01-07 是restaurant-growth/restaurant-growth/ (100 + 110 + 120 + 130 + 110 + 140 + 150)/7 = 122.86
第二个七天消费平均值从 2019-01-02 到 2019-01-08 是 (110 + 120 + 130 + 110 + 140 + 150 + 80)/7 = 120
第三个七天消费平均值从 2019-01-03 到 2019-01-09 是 (120 + 130 + 110 + 140 + 150 + 80 + 110)/7 = 120
第四个七天消费平均值从 2019-01-04 到 2019-01-10 是 (130 + 110 + 140 + 150 + 80 + 110 + 130 + 150)/7 = 142.86</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            visited_on,
            SUM(amount) OVER (
                ORDER BY visited_on
                ROWS 6 PRECEDING
            ) AS amount,
            RANK() OVER (
                ORDER BY visited_on
                ROWS 6 PRECEDING
            ) AS rk
        FROM
            (
                SELECT visited_on, SUM(amount) AS amount
                FROM Customer
                GROUP BY visited_on
            ) AS tt
    )
SELECT visited_on, amount, ROUND(amount / 7, 2) AS average_amount
FROM t
WHERE rk > 6;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    a.visited_on,
    SUM(b.amount) AS amount,
    ROUND(SUM(b.amount) / 7, 2) AS average_amount
FROM
    (SELECT DISTINCT visited_on FROM customer) AS a
    JOIN customer AS b ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
WHERE a.visited_on >= (SELECT MIN(visited_on) FROM customer) + 6
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1322. 广告效果 🔒](https://leetcode.cn/problems/ads-performance){#1322}

{{< tabs "1322" >}}

{{% tab "sql" %}}
```sql
SELECT
    ad_id,
    ROUND(IFNULL(SUM(action = 'Clicked') / SUM(action IN('Clicked', 'Viewed')) * 100, 0), 2) AS ctr
FROM Ads
GROUP BY 1
ORDER BY 2 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Ads</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| ad_id         | int     |
| user_id       | int     |
| action        | enum    |
+---------------+---------+
(ad_id, user_id) 是该表的主键(具有唯一值的列的组合)
该表的每一行包含一条广告的 ID(ad_id)，用户的 ID(user_id) 和用户对广告采取的行为 (action)
action 列是一个枚举类型 ('Clicked', 'Viewed', 'Ignored') 。
</pre>

<p>&nbsp;</p>

<p>一家公司正在运营这些广告并想计算每条广告的效果。</p>

<p>广告效果用点击通过率（Click-Through Rate：CTR）来衡量，公式如下:</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1322.Ads%20Performance/images/sql1.png" style="height: 55px; width: 600px;" /></p>

<p>编写解决方案找出每一条广告的&nbsp;<code>ctr</code>&nbsp;，<code>ctr</code>&nbsp;要 <strong>保留两位小数</strong> 。</p>

<p>返回结果需要按&nbsp;<code>ctr</code>&nbsp;<strong>降序</strong>、按&nbsp;<code>ad_id</code>&nbsp;<strong>升序&nbsp;</strong>进行排序。</p>

<p>返回结果示例如下：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Ads 表:
+-------+---------+---------+
| ad_id | user_id | action  |
+-------+---------+---------+
| 1     | 1       | Clicked |
| 2     | 2       | Clicked |
| 3     | 3       | Viewed  |
| 5     | 5       | Ignored |
| 1     | 7       | Ignored |
| 2     | 7       | Viewed  |
| 3     | 5       | Clicked |
| 1     | 4       | Viewed  |
| 2     | 11      | Viewed  |
| 1     | 2       | Clicked |
+-------+---------+---------+
<strong>输出：</strong>
+-------+-------+
| ad_id | ctr   |
+-------+-------+
| 1     | 66.67 |
| 3     | 50.00 |
| 2     | 33.33 |
| 5     | 0.00  |
+-------+-------+
<strong>解释：</strong>
对于 ad_id = 1, ctr = (2/(2+1)) * 100 = 66.67
对于 ad_id = 2, ctr = (1/(1+2)) * 100 = 33.33
对于 ad_id = 3, ctr = (1/(1+1)) * 100 = 50.00
对于 ad_id = 5, ctr = 0.00, 注意 ad_id = 5 没有被点击 (Clicked) 或查看 (Viewed) 过
注意我们不关心 action 为 Ingnored 的广告
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    ad_id,
    ROUND(IFNULL(SUM(action = 'Clicked') / SUM(action IN('Clicked', 'Viewed')) * 100, 0), 2) AS ctr
FROM Ads
GROUP BY 1
ORDER BY 2 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1323. 6 和 9 组成的最大数字](https://leetcode.cn/problems/maximum-69-number){#1323}

{{< tabs "1323" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximum69Number(self, num: int) -> int:
        return int(str(num).replace("6", "9", 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximum69Number(int num) {
        return Integer.valueOf(String.valueOf(num).replaceFirst("6", "9"));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        for (char& ch : s) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximum69Number(num int) int {
	s := strings.Replace(strconv.Itoa(num), "6", "9", 1)
	ans, _ := strconv.Atoi(s)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximum69Number(num: number): number {
    return Number((num + '').replace('6', '9'));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        num.to_string().replacen('6', "9", 1).parse().unwrap()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $num
     * @return Integer
     */
    function maximum69Number($num) {
        $num = strval($num);
        $n = strpos($num, '6');
        $num[$n] = 9;
        return intval($num);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int maximum69Number(int num) {
    char buf[12];
    sprintf(buf, "%d", num);
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '6') {
            buf[i] = '9';
            break;
        }
    }
    int ans;
    sscanf(buf, "%d", &ans);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由数字 6 和 9 组成的正整数&nbsp;<code>num</code>。</p>

<p>你最多只能翻转一位数字，将 6 变成&nbsp;9，或者把&nbsp;9 变成&nbsp;6 。</p>

<p>请返回你可以得到的最大数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 9669
<strong>输出：</strong>9969
<strong>解释：</strong>
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9996
<strong>输出：</strong>9999
<strong>解释：</strong>将最后一位从 6 变到 9，其结果 9999 是最大的数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 9999
<strong>输出：</strong>9999
<strong>解释：</strong>无需改变就已经是最大的数字了。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^4</code></li>
	<li><code>num</code>&nbsp;每一位上的数字都是 6 或者&nbsp;9 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们将数组转换为字符串，然后从左到右遍历字符串，找到第一个出现的 $6$，将其替换为 $9$，然后返回转换后的字符串对应的整数即可。

时间复杂度 $O(\log \textit{num})$，空间复杂度 $O(\log \textit{num})$。其中 $\textit{num}$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximum69Number(self, num: int) -> int:
        return int(str(num).replace("6", "9", 1))
```

#### Java

```java
class Solution {
    public int maximum69Number(int num) {
        return Integer.valueOf(String.valueOf(num).replaceFirst("6", "9"));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        for (char& ch : s) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};
```

#### Go

```go
func maximum69Number(num int) int {
	s := strings.Replace(strconv.Itoa(num), "6", "9", 1)
	ans, _ := strconv.Atoi(s)
	return ans
}
```

#### TypeScript

```ts
function maximum69Number(num: number): number {
    return Number((num + '').replace('6', '9'));
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        num.to_string().replacen('6', "9", 1).parse().unwrap()
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $num
     * @return Integer
     */
    function maximum69Number($num) {
        $num = strval($num);
        $n = strpos($num, '6');
        $num[$n] = 9;
        return intval($num);
    }
}
```

#### C

```c
int maximum69Number(int num) {
    char buf[12];
    sprintf(buf, "%d", num);
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '6') {
            buf[i] = '9';
            break;
        }
    }
    int ans;
    sscanf(buf, "%d", &ans);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1324. 竖直打印单词](https://leetcode.cn/problems/print-words-vertically){#1324}

{{< tabs "1324" >}}

{{% tab "python" %}}
```python
class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split()
        n = max(len(w) for w in words)
        ans = []
        for j in range(n):
            t = [w[j] if j < len(w) else ' ' for w in words]
            while t[-1] == ' ':
                t.pop()
            ans.append(''.join(t))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int n = 0;
        for (var w : words) {
            n = Math.max(n, w.length());
        }
        List<String> ans = new ArrayList<>();
        for (int j = 0; j < n; ++j) {
            StringBuilder t = new StringBuilder();
            for (var w : words) {
                t.append(j < w.length() ? w.charAt(j) : ' ');
            }
            while (t.length() > 0 && t.charAt(t.length() - 1) == ' ') {
                t.deleteCharAt(t.length() - 1);
            }
            ans.add(t.toString());
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        int n = 0;
        while (ss >> word) {
            words.emplace_back(word);
            n = max(n, (int) word.size());
        }
        vector<string> ans;
        for (int j = 0; j < n; ++j) {
            string t;
            for (auto& w : words) {
                t += j < w.size() ? w[j] : ' ';
            }
            while (t.size() && t.back() == ' ') {
                t.pop_back();
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func printVertically(s string) (ans []string) {
	words := strings.Split(s, " ")
	n := 0
	for _, w := range words {
		n = max(n, len(w))
	}
	for j := 0; j < n; j++ {
		t := []byte{}
		for _, w := range words {
			if j < len(w) {
				t = append(t, w[j])
			} else {
				t = append(t, ' ')
			}
		}
		for len(t) > 0 && t[len(t)-1] == ' ' {
			t = t[:len(t)-1]
		}
		ans = append(ans, string(t))
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>。请你按照单词在 <code>s</code> 中的出现顺序将它们全部竖直返回。<br>
单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。<br>
每个单词只能放在一列上，每一列中也只能有一个单词。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;HOW ARE YOU&quot;
<strong>输出：</strong>[&quot;HAY&quot;,&quot;ORO&quot;,&quot;WEU&quot;]
<strong>解释：</strong>每个单词都应该竖直打印。 
 &quot;HAY&quot;
&nbsp;&quot;ORO&quot;
&nbsp;&quot;WEU&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;TO BE OR NOT TO BE&quot;
<strong>输出：</strong>[&quot;TBONTB&quot;,&quot;OEROOE&quot;,&quot;   T&quot;]
<strong>解释：</strong>题目允许使用空格补位，但不允许输出末尾出现空格。
&quot;TBONTB&quot;
&quot;OEROOE&quot;
&quot;   T&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;CONTEST IS COMING&quot;
<strong>输出：</strong>[&quot;CIC&quot;,&quot;OSO&quot;,&quot;N M&quot;,&quot;T I&quot;,&quot;E N&quot;,&quot;S G&quot;,&quot;T&quot;]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code>&nbsp;仅含大写英文字母。</li>
	<li>题目数据保证两个单词之间只有一个空格。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先将字符串 $s$ 按空格分割成单词数组 $words$，然后遍历单词数组，找出最长的单词长度 $n$。

接下来我们从第 $1$ 到第 $n$ 个字符，分别从单词数组中取出对应的字符，如果当前单词长度不足，则用空格补齐，放到一个字符串 $t$ 中。最后将 $t$ 去掉末尾的空格，加入答案数组中即可。

时间复杂度 $O(m)$，空间复杂度 $O(m)$。其中 $m$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split()
        n = max(len(w) for w in words)
        ans = []
        for j in range(n):
            t = [w[j] if j < len(w) else ' ' for w in words]
            while t[-1] == ' ':
                t.pop()
            ans.append(''.join(t))
        return ans
```

#### Java

```java
class Solution {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int n = 0;
        for (var w : words) {
            n = Math.max(n, w.length());
        }
        List<String> ans = new ArrayList<>();
        for (int j = 0; j < n; ++j) {
            StringBuilder t = new StringBuilder();
            for (var w : words) {
                t.append(j < w.length() ? w.charAt(j) : ' ');
            }
            while (t.length() > 0 && t.charAt(t.length() - 1) == ' ') {
                t.deleteCharAt(t.length() - 1);
            }
            ans.add(t.toString());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        int n = 0;
        while (ss >> word) {
            words.emplace_back(word);
            n = max(n, (int) word.size());
        }
        vector<string> ans;
        for (int j = 0; j < n; ++j) {
            string t;
            for (auto& w : words) {
                t += j < w.size() ? w[j] : ' ';
            }
            while (t.size() && t.back() == ' ') {
                t.pop_back();
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
func printVertically(s string) (ans []string) {
	words := strings.Split(s, " ")
	n := 0
	for _, w := range words {
		n = max(n, len(w))
	}
	for j := 0; j < n; j++ {
		t := []byte{}
		for _, w := range words {
			if j < len(w) {
				t = append(t, w[j])
			} else {
				t = append(t, ' ')
			}
		}
		for len(t) > 0 && t[len(t)-1] == ' ' {
			t = t[:len(t)-1]
		}
		ans = append(ans, string(t))
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1325. 删除给定值的叶子节点](https://leetcode.cn/problems/delete-leaves-with-a-given-value){#1325}

{{< tabs "1325" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        if root.left is None and root.right is None and root.val == target:
            return None
        return root
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) {
            return null;
        }
        root.left = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);
        if (root.left == null && root.right == null && root.val == target) {
            return null;
        }
        return root;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }
        return root;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func removeLeafNodes(root *TreeNode, target int) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = removeLeafNodes(root.Left, target)
	root.Right = removeLeafNodes(root.Right, target)
	if root.Left == nil && root.Right == nil && root.Val == target {
		return nil
	}
	return root
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function removeLeafNodes(root: TreeNode | null, target: number): TreeNode | null {
    if (!root) {
        return null;
    }
    root.left = removeLeafNodes(root.left, target);
    root.right = removeLeafNodes(root.right, target);
    if (!root.left && !root.right && root.val == target) {
        return null;
    }
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵以&nbsp;<code>root</code>&nbsp;为根的二叉树和一个整数&nbsp;<code>target</code>&nbsp;，请你删除所有值为&nbsp;<code>target</code> 的&nbsp;<strong>叶子节点</strong> 。</p>

<p>注意，一旦删除值为&nbsp;<code>target</code>&nbsp;的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是&nbsp;<code>target</code> ，那么这个节点也应该被删除。</p>

<p>也就是说，你需要重复此过程直到不能继续删除。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1325.Delete%20Leaves%20With%20a%20Given%20Value/images/sample_1_1684.png" style="width: 500px; height: 112px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,2,null,2,4], target = 2
<strong>输出：</strong>[1,null,3,null,4]
<strong>解释：
</strong>上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1325.Delete%20Leaves%20With%20a%20Given%20Value/images/sample_2_1684.png" style="width: 400px; height: 154px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,3,3,3,2], target = 3
<strong>输出：</strong>[1,3,null,null,2]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1325.Delete%20Leaves%20With%20a%20Given%20Value/images/sample_3_1684.png" style="width: 450px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,null,2,null,2], target = 2
<strong>输出：</strong>[1]
<strong>解释：</strong>每一步都删除一个绿色的叶子节点（值为 2）。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数量的范围是 <code>[1, 3000]</code>。</li>
	<li><code>1 &lt;= Node.val, target &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先判断 $root$ 节点是否为空，若为空，则返回空。

否则，递归地处理 $root$ 的左右子树，即调用 `root.left = removeLeafNodes(root.left, target)` 和 `root.right = removeLeafNodes(root.right, target)`。

然后判断 $root$ 节点是否为叶子节点，即判断 $root.left$ 和 $root.right$ 是否为空，且 $root.val$ 是否等于 $target$。若是，则返回空，否则返回 $root$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        if root.left is None and root.right is None and root.val == target:
            return None
        return root
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) {
            return null;
        }
        root.left = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);
        if (root.left == null && root.right == null && root.val == target) {
            return null;
        }
        return root;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }
        return root;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func removeLeafNodes(root *TreeNode, target int) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left = removeLeafNodes(root.Left, target)
	root.Right = removeLeafNodes(root.Right, target)
	if root.Left == nil && root.Right == nil && root.Val == target {
		return nil
	}
	return root
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function removeLeafNodes(root: TreeNode | null, target: number): TreeNode | null {
    if (!root) {
        return null;
    }
    root.left = removeLeafNodes(root.left, target);
    root.right = removeLeafNodes(root.right, target);
    if (!root.left && !root.right && root.val == target) {
        return null;
    }
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1326. 灌溉花园的最少水龙头数目](https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden){#1326}

{{< tabs "1326" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        last = [0] * (n + 1)
        for i, x in enumerate(ranges):
            l, r = max(0, i - x), i + x
            last[l] = max(last[l], r)

        ans = mx = pre = 0
        for i in range(n):
            mx = max(mx, last[i])
            if mx <= i:
                return -1
            if pre == i:
                ans += 1
                pre = mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTaps(int n, int[] ranges) {
        int[] last = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            int l = Math.max(0, i - ranges[i]), r = i + ranges[i];
            last[l] = Math.max(last[l], r);
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> last(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            int l = max(0, i - ranges[i]), r = i + ranges[i];
            last[l] = max(last[l], r);
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTaps(n int, ranges []int) (ans int) {
	last := make([]int, n+1)
	for i, x := range ranges {
		l, r := max(0, i-x), i+x
		last[l] = max(last[l], r)
	}
	var pre, mx int
	for i, j := range last[:n] {
		mx = max(mx, j)
		if mx <= i {
			return -1
		}
		if pre == i {
			ans++
			pre = mx
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minTaps(n: number, ranges: number[]): number {
    const last = new Array(n + 1).fill(0);
    for (let i = 0; i < n + 1; ++i) {
        const l = Math.max(0, i - ranges[i]);
        const r = i + ranges[i];
        last[l] = Math.max(last[l], r);
    }
    let ans = 0;
    let mx = 0;
    let pre = 0;
    for (let i = 0; i < n; ++i) {
        mx = Math.max(mx, last[i]);
        if (mx <= i) {
            return -1;
        }
        if (pre == i) {
            ++ans;
            pre = mx;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let mut last = vec![0; (n + 1) as usize];
        let mut ans = 0;
        let mut mx = 0;
        let mut pre = 0;

        // Initialize the last vector
        for (i, &r) in ranges.iter().enumerate() {
            if (i as i32) - r >= 0 {
                last[((i as i32) - r) as usize] =
                    std::cmp::max(last[((i as i32) - r) as usize], (i as i32) + r);
            } else {
                last[0] = std::cmp::max(last[0], (i as i32) + r);
            }
        }

        for i in 0..n as usize {
            mx = std::cmp::max(mx, last[i]);
            if mx <= (i as i32) {
                return -1;
            }
            if pre == (i as i32) {
                ans += 1;
                pre = mx;
            }
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在 x 轴上有一个一维的花园。花园长度为&nbsp;<code>n</code>，从点&nbsp;<code>0</code>&nbsp;开始，到点&nbsp;<code>n</code>&nbsp;结束。</p>

<p>花园里总共有&nbsp;<code>n + 1</code> 个水龙头，分别位于&nbsp;<code>[0, 1, ..., n]</code> 。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和一个长度为&nbsp;<code>n + 1</code> 的整数数组&nbsp;<code>ranges</code>&nbsp;，其中&nbsp;<code>ranges[i]</code> （下标从 0 开始）表示：如果打开点&nbsp;<code>i</code>&nbsp;处的水龙头，可以灌溉的区域为&nbsp;<code>[i -&nbsp; ranges[i], i + ranges[i]]</code>&nbsp;。</p>

<p>请你返回可以灌溉整个花园的&nbsp;<strong>最少水龙头数目</strong>&nbsp;。如果花园始终存在无法灌溉到的地方，请你返回&nbsp;<strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1326.Minimum%20Number%20of%20Taps%20to%20Open%20to%20Water%20a%20Garden/images/1685_example_1.png" /></p>

<pre>
<strong>输入：</strong>n = 5, ranges = [3,4,1,1,0,0]
<strong>输出：</strong>1
<strong>解释：
</strong>点 0 处的水龙头可以灌溉区间 [-3,3]
点 1 处的水龙头可以灌溉区间 [-3,5]
点 2 处的水龙头可以灌溉区间 [1,3]
点 3 处的水龙头可以灌溉区间 [2,4]
点 4 处的水龙头可以灌溉区间 [4,4]
点 5 处的水龙头可以灌溉区间 [5,5]
只需要打开点 1 处的水龙头即可灌溉整个花园 [0,5] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, ranges = [0,0,0,0]
<strong>输出：</strong>-1
<strong>解释：</strong>即使打开所有水龙头，你也无法灌溉整个花园。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>ranges.length == n + 1</code></li>
	<li><code>0 &lt;= ranges[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们注意到，对于所有能覆盖某个左端点的水龙头，选择能覆盖最远右端点的那个水龙头是最优的。

因此，我们可以先预处理数组 $ranges$，对于第 $i$ 个水龙头，它能覆盖的左端点 $l = \max(0, i - ranges[i])$，右端点 $r = i + ranges[i]$，我们算出所有能覆盖左端点 $l$ 的水龙头中，右端点最大的那个位置，记录在数组 $last[i]$ 中。

然后我们定义以下三个变量，其中：

-   变量 $ans$ 表示最终答案，即最少水龙头数目；
-   变量 $mx$ 表示当前能覆盖的最远右端点；
-   变量 $pre$ 表示上一个水龙头覆盖的最远右端点。

我们在 $[0,...n-1]$ 的范围内遍历所有位置，对于当前位置 $i$，我们用 $last[i]$ 更新 $mx$，即 $mx = \max(mx, last[i])$。

-   如果 $mx \leq i$，说明无法覆盖下一个位置，返回 $-1$。
-   如果 $pre = i$，说明需要使用一个新的子区间，因此我们将 $ans$ 加 $1$，并且更新 $pre = mx$。

遍历结束后，返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为花园的长度。

相似题目：

-   [45. 跳跃游戏 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0045.Jump%20Game%20II/README.md)
-   [55. 跳跃游戏](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0055.Jump%20Game/README.md)
-   [1024. 视频拼接](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1024.Video%20Stitching/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        last = [0] * (n + 1)
        for i, x in enumerate(ranges):
            l, r = max(0, i - x), i + x
            last[l] = max(last[l], r)

        ans = mx = pre = 0
        for i in range(n):
            mx = max(mx, last[i])
            if mx <= i:
                return -1
            if pre == i:
                ans += 1
                pre = mx
        return ans
```

#### Java

```java
class Solution {
    public int minTaps(int n, int[] ranges) {
        int[] last = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            int l = Math.max(0, i - ranges[i]), r = i + ranges[i];
            last[l] = Math.max(last[l], r);
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            mx = Math.max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> last(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            int l = max(0, i - ranges[i]), r = i + ranges[i];
            last[l] = max(last[l], r);
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minTaps(n int, ranges []int) (ans int) {
	last := make([]int, n+1)
	for i, x := range ranges {
		l, r := max(0, i-x), i+x
		last[l] = max(last[l], r)
	}
	var pre, mx int
	for i, j := range last[:n] {
		mx = max(mx, j)
		if mx <= i {
			return -1
		}
		if pre == i {
			ans++
			pre = mx
		}
	}
	return
}
```

#### TypeScript

```ts
function minTaps(n: number, ranges: number[]): number {
    const last = new Array(n + 1).fill(0);
    for (let i = 0; i < n + 1; ++i) {
        const l = Math.max(0, i - ranges[i]);
        const r = i + ranges[i];
        last[l] = Math.max(last[l], r);
    }
    let ans = 0;
    let mx = 0;
    let pre = 0;
    for (let i = 0; i < n; ++i) {
        mx = Math.max(mx, last[i]);
        if (mx <= i) {
            return -1;
        }
        if (pre == i) {
            ++ans;
            pre = mx;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let mut last = vec![0; (n + 1) as usize];
        let mut ans = 0;
        let mut mx = 0;
        let mut pre = 0;

        // Initialize the last vector
        for (i, &r) in ranges.iter().enumerate() {
            if (i as i32) - r >= 0 {
                last[((i as i32) - r) as usize] =
                    std::cmp::max(last[((i as i32) - r) as usize], (i as i32) + r);
            } else {
                last[0] = std::cmp::max(last[0], (i as i32) + r);
            }
        }

        for i in 0..n as usize {
            mx = std::cmp::max(mx, last[i]);
            if mx <= (i as i32) {
                return -1;
            }
            if pre == (i as i32) {
                ans += 1;
                pre = mx;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1327. 列出指定时间段内所有的下单产品](https://leetcode.cn/problems/list-the-products-ordered-in-a-period){#1327}

{{< tabs "1327" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM
    Orders AS o
    JOIN Products AS p ON o.product_id = p.product_id
WHERE DATE_FORMAT(order_date, '%Y-%m') = '2020-02'
GROUP BY o.product_id
HAVING unit >= 100;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Products</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| product_id       | int     |
| product_name     | varchar |
| product_category | varchar |
+------------------+---------+
product_id 是该表主键(具有唯一值的列)。
该表包含该公司产品的数据。
</pre>

<p>&nbsp;</p>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| order_date    | date    |
| unit          | int     |
+---------------+---------+
该表可能包含重复行。
product_id 是表单 Products 的外键（reference 列）。
unit 是在日期 order_date 内下单产品的数目。
</pre>

<p>&nbsp;</p>

<p>写一个解决方案，要求获取在 2020 年 2 月份下单的数量不少于 100 的产品的名字和数目。</p>

<p>返回结果表单的 <strong>顺序无要求 </strong>。</p>

<p>查询结果的格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Products 表:
+-------------+-----------------------+------------------+
| product_id  | product_name          | product_category |
+-------------+-----------------------+------------------+
| 1           | Leetcode Solutions    | Book             |
| 2           | Jewels of Stringology | Book             |
| 3           | HP                    | Laptop           |
| 4           | Lenovo                | Laptop           |
| 5           | Leetcode Kit          | T-shirt          |
+-------------+-----------------------+------------------+
Orders 表:
+--------------+--------------+----------+
| product_id   | order_date   | unit     |
+--------------+--------------+----------+
| 1            | 2020-02-05   | 60       |
| 1            | 2020-02-10   | 70       |
| 2            | 2020-01-18   | 30       |
| 2            | 2020-02-11   | 80       |
| 3            | 2020-02-17   | 2        |
| 3            | 2020-02-24   | 3        |
| 4            | 2020-03-01   | 20       |
| 4            | 2020-03-04   | 30       |
| 4            | 2020-03-04   | 60       |
| 5            | 2020-02-25   | 50       |
| 5            | 2020-02-27   | 50       |
| 5            | 2020-03-01   | 50       |
+--------------+--------------+----------+
<strong>输出：</strong>
+--------------------+---------+
| product_name       | unit    |
+--------------------+---------+
| Leetcode Solutions | 130     |
| Leetcode Kit       | 100     |
+--------------------+---------+
<strong>解释：</strong>
2020 年 2 月份下单 product_id = 1 的产品的数目总和为 (60 + 70) = 130 。
2020 年 2 月份下单 product_id = 2 的产品的数目总和为 80 。
2020 年 2 月份下单 product_id = 3 的产品的数目总和为 (2 + 3) = 5 。
2020 年 2 月份 product_id = 4 的产品并没有下单。
2020 年 2 月份下单 product_id = 5 的产品的数目总和为 (50 + 50) = 100 。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM
    Orders AS o
    JOIN Products AS p ON o.product_id = p.product_id
WHERE DATE_FORMAT(order_date, '%Y-%m') = '2020-02'
GROUP BY o.product_id
HAVING unit >= 100;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1328. 破坏回文串](https://leetcode.cn/problems/break-a-palindrome){#1328}

{{< tabs "1328" >}}

{{% tab "python" %}}
```python
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n == 1:
            return ""
        s = list(palindrome)
        i = 0
        while i < n // 2 and s[i] == "a":
            i += 1
        if i == n // 2:
            s[-1] = "b"
        else:
            s[i] = "a"
        return "".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        if (n == 1) {
            return "";
        }
        char[] s = palindrome.toCharArray();
        int i = 0;
        while (i < n / 2 && s[i] == 'a') {
            ++i;
        }
        if (i == n / 2) {
            s[n - 1] = 'b';
        } else {
            s[i] = 'a';
        }
        return String.valueOf(s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        int i = 0;
        while (i < n / 2 && palindrome[i] == 'a') {
            ++i;
        }
        if (i == n / 2) {
            palindrome[n - 1] = 'b';
        } else {
            palindrome[i] = 'a';
        }
        return palindrome;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func breakPalindrome(palindrome string) string {
	n := len(palindrome)
	if n == 1 {
		return ""
	}
	i := 0
	s := []byte(palindrome)
	for i < n/2 && s[i] == 'a' {
		i++
	}
	if i == n/2 {
		s[n-1] = 'b'
	} else {
		s[i] = 'a'
	}
	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function breakPalindrome(palindrome: string): string {
    const n = palindrome.length;
    if (n === 1) {
        return '';
    }
    const s = palindrome.split('');
    let i = 0;
    while (i < n >> 1 && s[i] === 'a') {
        i++;
    }
    if (i == n >> 1) {
        s[n - 1] = 'b';
    } else {
        s[i] = 'a';
    }
    return s.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn break_palindrome(palindrome: String) -> String {
        let n = palindrome.len();
        if n == 1 {
            return "".to_string();
        }
        let mut s: Vec<char> = palindrome.chars().collect();
        let mut i = 0;

        while i < n / 2 && s[i] == 'a' {
            i += 1;
        }

        if i == n / 2 {
            s[n - 1] = 'b';
        } else {
            s[i] = 'a';
        }

        s.into_iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由小写英文字母组成的回文字符串&nbsp;<code>palindrome</code> ，请你将其中&nbsp;<strong>一个</strong> 字符用任意小写英文字母替换，使得结果字符串的 <strong>字典序最小</strong> ，且&nbsp;<strong>不是</strong>&nbsp;回文串。</p>

<p>请你返回结果字符串。如果无法做到，则返回一个 <strong>空串</strong> 。</p>

<p>如果两个字符串长度相同，那么字符串 <code>a</code> 字典序比字符串 <code>b</code> 小可以这样定义：在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，字符串 <code>a</code> 中的字符严格小于 <code>b</code> 中的对应字符。例如，<code>"abcc”</code> 字典序比 <code>"abcd"</code> 小，因为不同的第一个位置是在第四个字符，显然 <code>'c'</code> 比 <code>'d'</code> 小。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>palindrome = "abccba"
<strong>输出：</strong>"aaccba"
<strong>解释：</strong>存在多种方法可以使 "abccba" 不是回文，例如 "<em><strong>z</strong></em>bccba", "a<em><strong>a</strong></em>ccba", 和 "ab<em><strong>a</strong></em>cba" 。
在所有方法中，"aaccba" 的字典序最小。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>palindrome = "a"
<strong>输出：</strong>""
<strong>解释：</strong>不存在替换一个字符使 "a" 变成非回文的方法，所以返回空字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= palindrome.length &lt;= 1000</code></li>
	<li><code>palindrome</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先判断字符串的长度是否为 $1$，若是则直接返回空串。

否则，我们从左到右遍历字符串的前半部分，找到第一个不为 `'a'` 的字符，将其改为 `'a'` 即可。如果不存在这样的字符，那么我们将最后一个字符改为 `'b'` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n == 1:
            return ""
        s = list(palindrome)
        i = 0
        while i < n // 2 and s[i] == "a":
            i += 1
        if i == n // 2:
            s[-1] = "b"
        else:
            s[i] = "a"
        return "".join(s)
```

#### Java

```java
class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        if (n == 1) {
            return "";
        }
        char[] s = palindrome.toCharArray();
        int i = 0;
        while (i < n / 2 && s[i] == 'a') {
            ++i;
        }
        if (i == n / 2) {
            s[n - 1] = 'b';
        } else {
            s[i] = 'a';
        }
        return String.valueOf(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        int i = 0;
        while (i < n / 2 && palindrome[i] == 'a') {
            ++i;
        }
        if (i == n / 2) {
            palindrome[n - 1] = 'b';
        } else {
            palindrome[i] = 'a';
        }
        return palindrome;
    }
};
```

#### Go

```go
func breakPalindrome(palindrome string) string {
	n := len(palindrome)
	if n == 1 {
		return ""
	}
	i := 0
	s := []byte(palindrome)
	for i < n/2 && s[i] == 'a' {
		i++
	}
	if i == n/2 {
		s[n-1] = 'b'
	} else {
		s[i] = 'a'
	}
	return string(s)
}
```

#### TypeScript

```ts
function breakPalindrome(palindrome: string): string {
    const n = palindrome.length;
    if (n === 1) {
        return '';
    }
    const s = palindrome.split('');
    let i = 0;
    while (i < n >> 1 && s[i] === 'a') {
        i++;
    }
    if (i == n >> 1) {
        s[n - 1] = 'b';
    } else {
        s[i] = 'a';
    }
    return s.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn break_palindrome(palindrome: String) -> String {
        let n = palindrome.len();
        if n == 1 {
            return "".to_string();
        }
        let mut s: Vec<char> = palindrome.chars().collect();
        let mut i = 0;

        while i < n / 2 && s[i] == 'a' {
            i += 1;
        }

        if i == n / 2 {
            s[n - 1] = 'b';
        } else {
            s[i] = 'a';
        }

        s.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1329. 将矩阵按对角线排序](https://leetcode.cn/problems/sort-the-matrix-diagonally){#1329}

{{< tabs "1329" >}}

{{% tab "python" %}}
```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        g = [[] for _ in range(m + n)]
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                g[m - i + j].append(x)
        for e in g:
            e.sort(reverse=True)
        for i in range(m):
            for j in range(n):
                mat[i][j] = g[m - i + j].pop()
        return mat
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        List<Integer>[] g = new List[m + n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[m - i + j].add(mat[i][j]);
            }
        }
        for (var e : g) {
            Collections.sort(e, (a, b) -> b - a);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = g[m - i + j].removeLast();
            }
        }
        return mat;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> g[m + n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[m - i + j].push_back(mat[i][j]);
            }
        }
        for (auto& e : g) {
            sort(e.rbegin(), e.rend());
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = g[m - i + j].back();
                g[m - i + j].pop_back();
            }
        }
        return mat;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func diagonalSort(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	g := make([][]int, m+n)
	for i, row := range mat {
		for j, x := range row {
			g[m-i+j] = append(g[m-i+j], x)
		}
	}
	for _, e := range g {
		sort.Sort(sort.Reverse(sort.IntSlice(e)))
	}
	for i, row := range mat {
		for j := range row {
			k := len(g[m-i+j])
			mat[i][j] = g[m-i+j][k-1]
			g[m-i+j] = g[m-i+j][:k-1]
		}
	}
	return mat
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function diagonalSort(mat: number[][]): number[][] {
    const [m, n] = [mat.length, mat[0].length];
    const g: number[][] = Array.from({ length: m + n }, () => []);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            g[m - i + j].push(mat[i][j]);
        }
    }
    for (const e of g) {
        e.sort((a, b) => b - a);
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            mat[i][j] = g[m - i + j].pop()!;
        }
    }
    return mat;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut g: Vec<Vec<i32>> = vec![vec![]; m + n];
        for i in 0..m {
            for j in 0..n {
                g[m - i + j].push(mat[i][j]);
            }
        }
        for e in &mut g {
            e.sort_by(|a, b| b.cmp(a));
        }
        for i in 0..m {
            for j in 0..n {
                mat[i][j] = g[m - i + j].pop().unwrap();
            }
        }
        mat
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] DiagonalSort(int[][] mat) {
        int m = mat.Length;
        int n = mat[0].Length;
        List<List<int>> g = new List<List<int>>();
        for (int i = 0; i < m + n; i++) {
            g.Add(new List<int>());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[m - i + j].Add(mat[i][j]);
            }
        }
        foreach (var e in g) {
            e.Sort((a, b) => b.CompareTo(a));
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = g[m - i + j][g[m - i + j].Count - 1];
                g[m - i + j].RemoveAt(g[m - i + j].Count - 1);
                mat[i][j] = val;
            }
        }
        return mat;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>矩阵对角线</strong> 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，沿右下方向一直到矩阵末尾的元素。例如，矩阵 <code>mat</code> 有 <code>6</code> 行 <code>3</code> 列，从 <code>mat[2][0]</code> 开始的 <strong>矩阵对角线</strong> 将会经过 <code>mat[2][0]</code>、<code>mat[3][1]</code> 和 <code>mat[4][2]</code> 。</p>

<p>给你一个 <code>m * n</code> 的整数矩阵 <code>mat</code> ，请你将同一条 <strong>矩阵对角线 </strong>上的元素按升序排序后，返回排好序的矩阵。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1329.Sort%20the%20Matrix%20Diagonally/images/1482_example_1_2.png" style="height: 198px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>输出：</strong>[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
<strong>输出：</strong>[[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>1 <= mat[i][j] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以将矩阵中的每条对角线看作一个数组，然后对这些数组进行排序，最后再将排序后的元素填回原矩阵中。

具体地，我们记矩阵的行数为 $m$，列数为 $n$。由于同一条对角线上的任意两个元素 $(i_1, j_1)$ 和 $(i_2, j_2)$ 满足 $j_1 - i_1 = j_2 - i_2$，我们可以根据 $j - i$ 的值来确定每条对角线。为了保证值为正数，我们加上一个偏移量 $m$，即 $m - i + j$。

最后，我们将每条对角线上的元素排序后填回原矩阵中即可。

时间复杂度 $O(m \times n \times \log \min(m, n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        g = [[] for _ in range(m + n)]
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                g[m - i + j].append(x)
        for e in g:
            e.sort(reverse=True)
        for i in range(m):
            for j in range(n):
                mat[i][j] = g[m - i + j].pop()
        return mat
```

#### Java

```java
class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        List<Integer>[] g = new List[m + n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[m - i + j].add(mat[i][j]);
            }
        }
        for (var e : g) {
            Collections.sort(e, (a, b) -> b - a);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = g[m - i + j].removeLast();
            }
        }
        return mat;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> g[m + n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[m - i + j].push_back(mat[i][j]);
            }
        }
        for (auto& e : g) {
            sort(e.rbegin(), e.rend());
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = g[m - i + j].back();
                g[m - i + j].pop_back();
            }
        }
        return mat;
    }
};
```

#### Go

```go
func diagonalSort(mat [][]int) [][]int {
	m, n := len(mat), len(mat[0])
	g := make([][]int, m+n)
	for i, row := range mat {
		for j, x := range row {
			g[m-i+j] = append(g[m-i+j], x)
		}
	}
	for _, e := range g {
		sort.Sort(sort.Reverse(sort.IntSlice(e)))
	}
	for i, row := range mat {
		for j := range row {
			k := len(g[m-i+j])
			mat[i][j] = g[m-i+j][k-1]
			g[m-i+j] = g[m-i+j][:k-1]
		}
	}
	return mat
}
```

#### TypeScript

```ts
function diagonalSort(mat: number[][]): number[][] {
    const [m, n] = [mat.length, mat[0].length];
    const g: number[][] = Array.from({ length: m + n }, () => []);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            g[m - i + j].push(mat[i][j]);
        }
    }
    for (const e of g) {
        e.sort((a, b) => b - a);
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            mat[i][j] = g[m - i + j].pop()!;
        }
    }
    return mat;
}
```

#### Rust

```rust
impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut g: Vec<Vec<i32>> = vec![vec![]; m + n];
        for i in 0..m {
            for j in 0..n {
                g[m - i + j].push(mat[i][j]);
            }
        }
        for e in &mut g {
            e.sort_by(|a, b| b.cmp(a));
        }
        for i in 0..m {
            for j in 0..n {
                mat[i][j] = g[m - i + j].pop().unwrap();
            }
        }
        mat
    }
}
```

#### C#

```cs
public class Solution {
    public int[][] DiagonalSort(int[][] mat) {
        int m = mat.Length;
        int n = mat[0].Length;
        List<List<int>> g = new List<List<int>>();
        for (int i = 0; i < m + n; i++) {
            g.Add(new List<int>());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[m - i + j].Add(mat[i][j]);
            }
        }
        foreach (var e in g) {
            e.Sort((a, b) => b.CompareTo(a));
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = g[m - i + j][g[m - i + j].Count - 1];
                g[m - i + j].RemoveAt(g[m - i + j].Count - 1);
                mat[i][j] = val;
            }
        }
        return mat;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

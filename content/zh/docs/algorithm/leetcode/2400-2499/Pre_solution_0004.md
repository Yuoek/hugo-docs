---
title: "2430_对字母串可执行的最大删除数"
date: 2025-10-08T18:39:18+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希函数, 哈希表, 字符串, 字符串匹配, 数学, 数组, 数论, 枚举, 栈, 滚动哈希, 矩阵, 贪心]
---

{{< markmap >}}
### [2430_对字母串可执行的最大删除数](#2430)
#### [字符串](#2430)
#### [动态规划](#2430)
#### [字符串匹配](#2430)
#### [哈希函数](#2430)
#### [滚动哈希](#2430)
### [2431_最大限度地提高购买水果的口味 🔒](#2431)
#### [数组](#2431)
#### [动态规划](#2431)
### [2432_处理用时最长的那个任务的员工](#2432)
#### [数组](#2432)
### [2433_找出前缀异或的原始数组](#2433)
#### [位运算](#2433)
#### [数组](#2433)
### [2434_使用机器人打印字典序最小的字符串](#2434)
#### [栈](#2434)
#### [贪心](#2434)
#### [哈希表](#2434)
#### [字符串](#2434)
### [2435_矩阵中和能被 K 整除的路径](#2435)
#### [数组](#2435)
#### [动态规划](#2435)
#### [矩阵](#2435)
### [2436_使子数组最大公约数大于一的最小分割数 🔒](#2436)
#### [贪心](#2436)
#### [数组](#2436)
#### [数学](#2436)
#### [动态规划](#2436)
#### [数论](#2436)
### [2437_有效时间的数目](#2437)
#### [字符串](#2437)
#### [枚举](#2437)
### [2438_二的幂数组中查询范围内的乘积](#2438)
#### [位运算](#2438)
#### [数组](#2438)
#### [前缀和](#2438)
### [2439_最小化数组中的最大值](#2439)
#### [贪心](#2439)
#### [数组](#2439)
#### [二分查找](#2439)
#### [动态规划](#2439)
#### [前缀和](#2439)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2430_对字母串可执行的最大删除数
___
#### 字符串
___
#### 动态规划
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 2431_最大限度地提高购买水果的口味 🔒
___
#### 数组
___
#### 动态规划
---
### 2432_处理用时最长的那个任务的员工
___
#### 数组
---
### 2433_找出前缀异或的原始数组
___
#### 位运算
___
#### 数组
---
### 2434_使用机器人打印字典序最小的字符串
___
#### 栈
___
#### 贪心
___
#### 哈希表
___
#### 字符串
---
### 2435_矩阵中和能被 K 整除的路径
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2436_使子数组最大公约数大于一的最小分割数 🔒
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 数论
---
### 2437_有效时间的数目
___
#### 字符串
___
#### 枚举
---
### 2438_二的幂数组中查询范围内的乘积
___
#### 位运算
___
#### 数组
___
#### 前缀和
---
### 2439_最小化数组中的最大值
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希函数 | 哈希表 |
| 字符串 | 字符串匹配 | 数学 |
| 数组 | 数论 | 枚举 |
| 栈 | 滚动哈希 | 矩阵 |
| 贪心 |  |  |

# [2430. 对字母串可执行的最大删除数](https://leetcode.cn/problems/maximum-deletions-on-a-string){#2430}

{{< tabs "2430" >}}

{{% tab "python" %}}
```python
class Solution:
    def deleteString(self, s: str) -> int:
        n = len(s)
        g = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    g[i][j] = g[i + 1][j + 1] + 1

        f = [1] * n
        for i in range(n - 1, -1, -1):
            for j in range(1, (n - i) // 2 + 1):
                if g[i][i + j] >= j:
                    f[i] = max(f[i], f[i + j] + 1)
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int deleteString(String s) {
        int n = s.length();
        int[][] g = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        int[] f = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            f[i] = 1;
            for (int j = 1; j <= (n - i) / 2; ++j) {
                if (g[i][i + j] >= j) {
                    f[i] = Math.max(f[i], f[i + j] + 1);
                }
            }
        }
        return f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        int g[n + 1][n + 1];
        memset(g, 0, sizeof(g));
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        int f[n];
        for (int i = n - 1; ~i; --i) {
            f[i] = 1;
            for (int j = 1; j <= (n - i) / 2; ++j) {
                if (g[i][i + j] >= j) {
                    f[i] = max(f[i], f[i + j] + 1);
                }
            }
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func deleteString(s string) int {
	n := len(s)
	g := make([][]int, n+1)
	for i := range g {
		g[i] = make([]int, n+1)
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				g[i][j] = g[i+1][j+1] + 1
			}
		}
	}
	f := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		f[i] = 1
		for j := 1; j <= (n-i)/2; j++ {
			if g[i][i+j] >= j {
				f[i] = max(f[i], f[i+j]+1)
			}
		}
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function deleteString(s: string): number {
    const n = s.length;
    const f: number[] = new Array(n).fill(1);
    for (let i = n - 1; i >= 0; --i) {
        for (let j = 1; j <= (n - i) >> 1; ++j) {
            if (s.slice(i, i + j) === s.slice(i + j, i + j + j)) {
                f[i] = Math.max(f[i], f[i + j] + 1);
            }
        }
    }
    return f[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。在一步操作中，你可以：</p>

<ul>
	<li>删除 <strong>整个字符串</strong> <code>s</code> ，或者</li>
	<li>对于满足&nbsp;<code>1 &lt;= i &lt;= s.length / 2</code> 的任意 <code>i</code> ，如果 <code>s</code> 中的 <strong>前</strong> <code>i</code> 个字母和接下来的 <code>i</code> 个字母 <strong>相等</strong> ，删除 <strong>前</strong> <code>i</code> 个字母。</li>
</ul>

<p>例如，如果 <code>s = "ababc"</code> ，那么在一步操作中，你可以删除 <code>s</code> 的前两个字母得到 <code>"abc"</code> ，因为 <code>s</code> 的前两个字母和接下来的两个字母都等于 <code>"ab"</code> 。</p>

<p>返回删除 <code>s</code> 所需的最大操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcabcdabc"
<strong>输出：</strong>2
<strong>解释：</strong>
- 删除前 3 个字母（"abc"），因为它们和接下来 3 个字母相等。现在，s = "abcdabc"。
- 删除全部字母。
一共用了 2 步操作，所以返回 2 。可以证明 2 是所需的最大操作数。
注意，在第二步操作中无法再次删除 "abc" ，因为 "abc" 的下一次出现并不是位于接下来的 3 个字母。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabaab"
<strong>输出：</strong>4
<strong>解释：</strong>
- 删除第一个字母（"a"），因为它和接下来的字母相等。现在，s = "aabaab"。
- 删除前 3 个字母（"aab"），因为它们和接下来 3 个字母相等。现在，s = "aab"。 
- 删除第一个字母（"a"），因为它和接下来的字母相等。现在，s = "ab"。
- 删除全部字母。
一共用了 4 步操作，所以返回 4 。可以证明 4 是所需的最大操作数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaaa"
<strong>输出：</strong>5
<strong>解释：</strong>在每一步操作中，都可以仅删除 s 的第一个字母。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 4000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示删除 $s[i..]$ 所有字符所需的最大操作数，那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \geq n$，那么 $dfs(i) = 0$，直接返回。
-   否则，我们枚举字符串的长度 $j$，其中 $1 \leq j \leq (n-1)/2$，如果 $s[i..i+j] = s[i+j..i+j+j]$，那么我们可以删除 $s[i..i+j]$，此时 $dfs(i)=max(dfs(i), dfs(i+j)+1)$。我们需要枚举所有的 $j$，求 $dfs(i)$ 的最大值即可。

这里我们需要快速判断 $s[i..i+j]$ 与 $s[i+j..i+j+j]$ 是否相等，我们可以预处理出字符串 $s$ 的所有最长公共前缀，即 $g[i][j]$ 表示 $s[i..]$ 与 $s[j..]$ 的最长公共前缀的长度。这样我们就可以快速判断 $s[i..i+j]$ 与 $s[i+j..i+j+j]$ 是否相等，即 $g[i][i+j] \geq j$。

为了避免重复计算，我们可以使用记忆化搜索，用一个数组 $f$ 记录函数 $dfs(i)$ 的值。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deleteString(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i == n:
                return 0
            ans = 1
            for j in range(1, (n - i) // 2 + 1):
                if s[i : i + j] == s[i + j : i + j + j]:
                    ans = max(ans, 1 + dfs(i + j))
            return ans

        n = len(s)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int n;
    private Integer[] f;
    private int[][] g;

    public int deleteString(String s) {
        n = s.length();
        f = new Integer[n];
        g = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        return dfs(0);
    }

    private int dfs(int i) {
        if (i == n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        f[i] = 1;
        for (int j = 1; j <= (n - i) / 2; ++j) {
            if (g[i][i + j] >= j) {
                f[i] = Math.max(f[i], 1 + dfs(i + j));
            }
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        int g[n + 1][n + 1];
        memset(g, 0, sizeof(g));
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        int f[n];
        memset(f, 0, sizeof(f));
        function<int(int)> dfs = [&](int i) -> int {
            if (i == n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            f[i] = 1;
            for (int j = 1; j <= (n - i) / 2; ++j) {
                if (g[i][i + j] >= j) {
                    f[i] = max(f[i], 1 + dfs(i + j));
                }
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func deleteString(s string) int {
	n := len(s)
	g := make([][]int, n+1)
	for i := range g {
		g[i] = make([]int, n+1)
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				g[i][j] = g[i+1][j+1] + 1
			}
		}
	}
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i == n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		f[i] = 1
		for j := 1; j <= (n-i)/2; j++ {
			if g[i][i+j] >= j {
				f[i] = max(f[i], dfs(i+j)+1)
			}
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function deleteString(s: string): number {
    const n = s.length;
    const f: number[] = new Array(n).fill(0);
    const dfs = (i: number): number => {
        if (i == n) {
            return 0;
        }
        if (f[i] > 0) {
            return f[i];
        }
        f[i] = 1;
        for (let j = 1; j <= (n - i) >> 1; ++j) {
            if (s.slice(i, i + j) == s.slice(i + j, i + j + j)) {
                f[i] = Math.max(f[i], dfs(i + j) + 1);
            }
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一的记忆化搜索改为动态规划，定义 $f[i]$ 表示删除 $s[i..]$ 所有字符所需的最大操作数，初始时 $f[i]=1$，答案为 $f[0]$。

我们可以从后往前枚举 $i$，对于每个 $i$，我们枚举字符串的长度 $j$，其中 $1 \leq j \leq (n-1)/2$，如果 $s[i..i+j] = s[i+j..i+j+j]$，那么我们可以删除 $s[i..i+j]$，此时 $f[i]=max(f[i], f[i+j]+1)$。我们需要枚举所有的 $j$，求 $f[i]$ 的最大值即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deleteString(self, s: str) -> int:
        n = len(s)
        g = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    g[i][j] = g[i + 1][j + 1] + 1

        f = [1] * n
        for i in range(n - 1, -1, -1):
            for j in range(1, (n - i) // 2 + 1):
                if g[i][i + j] >= j:
                    f[i] = max(f[i], f[i + j] + 1)
        return f[0]
```

#### Java

```java
class Solution {
    public int deleteString(String s) {
        int n = s.length();
        int[][] g = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        int[] f = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            f[i] = 1;
            for (int j = 1; j <= (n - i) / 2; ++j) {
                if (g[i][i + j] >= j) {
                    f[i] = Math.max(f[i], f[i + j] + 1);
                }
            }
        }
        return f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        int g[n + 1][n + 1];
        memset(g, 0, sizeof(g));
        for (int i = n - 1; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                }
            }
        }
        int f[n];
        for (int i = n - 1; ~i; --i) {
            f[i] = 1;
            for (int j = 1; j <= (n - i) / 2; ++j) {
                if (g[i][i + j] >= j) {
                    f[i] = max(f[i], f[i + j] + 1);
                }
            }
        }
        return f[0];
    }
};
```

#### Go

```go
func deleteString(s string) int {
	n := len(s)
	g := make([][]int, n+1)
	for i := range g {
		g[i] = make([]int, n+1)
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				g[i][j] = g[i+1][j+1] + 1
			}
		}
	}
	f := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		f[i] = 1
		for j := 1; j <= (n-i)/2; j++ {
			if g[i][i+j] >= j {
				f[i] = max(f[i], f[i+j]+1)
			}
		}
	}
	return f[0]
}
```

#### TypeScript

```ts
function deleteString(s: string): number {
    const n = s.length;
    const f: number[] = new Array(n).fill(1);
    for (let i = n - 1; i >= 0; --i) {
        for (let j = 1; j <= (n - i) >> 1; ++j) {
            if (s.slice(i, i + j) === s.slice(i + j, i + j + j)) {
                f[i] = Math.max(f[i], f[i + j] + 1);
            }
        }
    }
    return f[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2431. 最大限度地提高购买水果的口味 🔒](https://leetcode.cn/problems/maximize-total-tastiness-of-purchased-fruits){#2431}

{{< tabs "2431" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTastiness(
        self, price: List[int], tastiness: List[int], maxAmount: int, maxCoupons: int
    ) -> int:
        @cache
        def dfs(i, j, k):
            if i == len(price):
                return 0
            ans = dfs(i + 1, j, k)
            if j >= price[i]:
                ans = max(ans, dfs(i + 1, j - price[i], k) + tastiness[i])
            if j >= price[i] // 2 and k:
                ans = max(ans, dfs(i + 1, j - price[i] // 2, k - 1) + tastiness[i])
            return ans

        return dfs(0, maxAmount, maxCoupons)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][][] f;
    private int[] price;
    private int[] tastiness;
    private int n;

    public int maxTastiness(int[] price, int[] tastiness, int maxAmount, int maxCoupons) {
        n = price.length;
        this.price = price;
        this.tastiness = tastiness;
        f = new int[n][maxAmount + 1][maxCoupons + 1];
        return dfs(0, maxAmount, maxCoupons);
    }

    private int dfs(int i, int j, int k) {
        if (i == n) {
            return 0;
        }
        if (f[i][j][k] != 0) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (j >= price[i]) {
            ans = Math.max(ans, dfs(i + 1, j - price[i], k) + tastiness[i]);
        }
        if (j >= price[i] / 2 && k > 0) {
            ans = Math.max(ans, dfs(i + 1, j - price[i] / 2, k - 1) + tastiness[i]);
        }
        f[i][j][k] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        memset(f, 0, sizeof f);
        function<int(int i, int j, int k)> dfs;
        dfs = [&](int i, int j, int k) {
            if (i == n) return 0;
            if (f[i][j][k]) return f[i][j][k];
            int ans = dfs(i + 1, j, k);
            if (j >= price[i]) ans = max(ans, dfs(i + 1, j - price[i], k) + tastiness[i]);
            if (j >= price[i] / 2 && k) ans = max(ans, dfs(i + 1, j - price[i] / 2, k - 1) + tastiness[i]);
            f[i][j][k] = ans;
            return ans;
        };
        return dfs(0, maxAmount, maxCoupons);
    }

private:
    int f[101][1001][6];
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTastiness(price []int, tastiness []int, maxAmount int, maxCoupons int) int {
	n := len(price)
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, maxAmount+1)
		for j := range f[i] {
			f[i][j] = make([]int, maxCoupons+1)
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i == n {
			return 0
		}
		if f[i][j][k] != 0 {
			return f[i][j][k]
		}
		ans := dfs(i+1, j, k)
		if j >= price[i] {
			ans = max(ans, dfs(i+1, j-price[i], k)+tastiness[i])
		}
		if j >= price[i]/2 && k > 0 {
			ans = max(ans, dfs(i+1, j-price[i]/2, k-1)+tastiness[i])
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, maxAmount, maxCoupons)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有两个非负整数数组 <code>price</code> 和 <code>tastiness</code>，两个数组的长度都是 <code>n</code>。同时给你两个非负整数 <code>maxAmount</code> 和 <code>maxCoupons</code>。</p>

<p data-group="1-1">对于范围 <code>[0, n - 1]</code>&nbsp;中的每一个整数 <code>i</code>:</p>

<ul>
	<li>
	<p data-group="1-1"><code>price[i]</code>&nbsp;描述了第 <code>i</code> 个水果的价格。</p>
	</li>
	<li><code>tastiness[i]</code> 描述了第 <code>i</code> 个水果的味道。</li>
</ul>

<p>你想购买一些水果，这样总的味道是最大的，总价不超过 <code>maxAmount</code>。</p>

<p>此外，你还可以用优惠券以&nbsp;<strong>半价 </strong>购买水果 (向下取整到最接近的整数)。您最多可以使用 <code>maxCoupons</code>&nbsp;次该优惠券。</p>

<p>返回可购买的最大总口味。</p>

<p><strong>注意:</strong></p>

<ul>
	<li>每个水果最多只能购买一次。</li>
	<li>一个水果你最多只能用一次折价券。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> price = [10,20,20], tastiness = [5,8,8], maxAmount = 20, maxCoupons = 1
<strong>输出:</strong> 13
<strong>解释:</strong> 可以用以下方法来达到总口味:
- 无优惠券买第一个水果，总价= 0 + 10，总口味= 0 + 5。
- 用优惠券买第二个水果，总价= 10 + 10，总口味= 5 + 8。
- 不购买第三个水果，总价= 20，总口味= 13。
可以证明 13 是所能得到的最大总口味。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> price = [10,15,7], tastiness = [5,8,20], maxAmount = 10, maxCoupons = 2
<strong>输出:</strong> 28
<strong>解释:</strong> 可以用以下方法使总口味达到 20:
- 不买第一个水果，这样总价= 0，总口味= 0。
- 用优惠券买第二个水果，总价= 0 + 7，总口味= 0 + 8。
- 用优惠券买第三个水果，总价= 7 + 3，总口味= 8 + 20。
可以证明，28 是所能得到的最大总口味。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == price.length == tastiness.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= price[i], tastiness[i], maxAmount &lt;= 1000</code></li>
	<li><code>0 &lt;= maxCoupons &lt;= 5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计函数 $dfs(i, j, k)$ 表示从第 $i$ 个水果开始，剩余 $j$ 元钱，剩余 $k$ 张优惠券时，最大的总美味度。

对于第 $i$ 个水果，可以选择购买或者不购买，如果购买，那么可以选择使用优惠券或者不使用优惠券。

如果不购买，那么最大总美味度是 $dfs(i + 1, j, k)$；

如果购买，如果不使用优惠券（需要满足 $j\ge price[i]$），那么最大总美味度是 $dfs(i + 1, j - price[i], k) + tastiness[i]$；如果使用优惠券（需要满足 $k\gt 0$ 并且 $j\ge \lfloor \frac{price[i]}{2} \rfloor$），那么最大总美味度是 $dfs(i + 1, j - \lfloor \frac{price[i]}{2} \rfloor, k - 1) + tastiness[i]$。

最终的答案是 $dfs(0, maxAmount, maxCoupons)$。

时间复杂度 $O(n \times maxAmount \times maxCoupons)$。其中 $n$ 是水果的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTastiness(
        self, price: List[int], tastiness: List[int], maxAmount: int, maxCoupons: int
    ) -> int:
        @cache
        def dfs(i, j, k):
            if i == len(price):
                return 0
            ans = dfs(i + 1, j, k)
            if j >= price[i]:
                ans = max(ans, dfs(i + 1, j - price[i], k) + tastiness[i])
            if j >= price[i] // 2 and k:
                ans = max(ans, dfs(i + 1, j - price[i] // 2, k - 1) + tastiness[i])
            return ans

        return dfs(0, maxAmount, maxCoupons)
```

#### Java

```java
class Solution {
    private int[][][] f;
    private int[] price;
    private int[] tastiness;
    private int n;

    public int maxTastiness(int[] price, int[] tastiness, int maxAmount, int maxCoupons) {
        n = price.length;
        this.price = price;
        this.tastiness = tastiness;
        f = new int[n][maxAmount + 1][maxCoupons + 1];
        return dfs(0, maxAmount, maxCoupons);
    }

    private int dfs(int i, int j, int k) {
        if (i == n) {
            return 0;
        }
        if (f[i][j][k] != 0) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (j >= price[i]) {
            ans = Math.max(ans, dfs(i + 1, j - price[i], k) + tastiness[i]);
        }
        if (j >= price[i] / 2 && k > 0) {
            ans = Math.max(ans, dfs(i + 1, j - price[i] / 2, k - 1) + tastiness[i]);
        }
        f[i][j][k] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        memset(f, 0, sizeof f);
        function<int(int i, int j, int k)> dfs;
        dfs = [&](int i, int j, int k) {
            if (i == n) return 0;
            if (f[i][j][k]) return f[i][j][k];
            int ans = dfs(i + 1, j, k);
            if (j >= price[i]) ans = max(ans, dfs(i + 1, j - price[i], k) + tastiness[i]);
            if (j >= price[i] / 2 && k) ans = max(ans, dfs(i + 1, j - price[i] / 2, k - 1) + tastiness[i]);
            f[i][j][k] = ans;
            return ans;
        };
        return dfs(0, maxAmount, maxCoupons);
    }

private:
    int f[101][1001][6];
};
```

#### Go

```go
func maxTastiness(price []int, tastiness []int, maxAmount int, maxCoupons int) int {
	n := len(price)
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, maxAmount+1)
		for j := range f[i] {
			f[i][j] = make([]int, maxCoupons+1)
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i == n {
			return 0
		}
		if f[i][j][k] != 0 {
			return f[i][j][k]
		}
		ans := dfs(i+1, j, k)
		if j >= price[i] {
			ans = max(ans, dfs(i+1, j-price[i], k)+tastiness[i])
		}
		if j >= price[i]/2 && k > 0 {
			ans = max(ans, dfs(i+1, j-price[i]/2, k-1)+tastiness[i])
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, maxAmount, maxCoupons)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2432. 处理用时最长的那个任务的员工](https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task){#2432}

{{< tabs "2432" >}}

{{% tab "python" %}}
```python
class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        last = mx = ans = 0
        for uid, t in logs:
            t -= last
            if mx < t or (mx == t and ans > uid):
                ans, mx = uid, t
            last += t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int ans = 0;
        int last = 0, mx = 0;
        for (int[] log : logs) {
            int uid = log[0], t = log[1];
            t -= last;
            if (mx < t || (mx == t && ans > uid)) {
                ans = uid;
                mx = t;
            }
            last += t;
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
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0, mx = 0, last = 0;
        for (auto& log : logs) {
            int uid = log[0], t = log[1];
            t -= last;
            if (mx < t || (mx == t && ans > uid)) {
                mx = t;
                ans = uid;
            }
            last += t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hardestWorker(n int, logs [][]int) (ans int) {
	var mx, last int
	for _, log := range logs {
		uid, t := log[0], log[1]
		t -= last
		if mx < t || (mx == t && uid < ans) {
			mx = t
			ans = uid
		}
		last += t
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hardestWorker(n: number, logs: number[][]): number {
    let [ans, mx, last] = [0, 0, 0];
    for (let [uid, t] of logs) {
        t -= last;
        if (mx < t || (mx == t && ans > uid)) {
            ans = uid;
            mx = t;
        }
        last += t;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn hardest_worker(n: i32, logs: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        let mut last = 0;

        for log in logs {
            let uid = log[0];
            let t = log[1];

            let diff = t - last;
            last = t;

            if diff > mx || (diff == mx && uid < ans) {
                ans = uid;
                mx = diff;
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int hardestWorker(int n, int** logs, int logsSize, int* logsColSize) {
    int res = 0;
    int max = 0;
    int pre = 0;
    for (int i = 0; i < logsSize; i++) {
        int t = logs[i][1] - pre;
        if (t > max || (t == max && res > logs[i][0])) {
            res = logs[i][0];
            max = t;
        }
        pre = logs[i][1];
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>共有 <code>n</code> 位员工，每位员工都有一个从 <code>0</code> 到 <code>n - 1</code> 的唯一 id 。</p>

<p>给你一个二维整数数组 <code>logs</code> ，其中 <code>logs[i] = [id<sub>i</sub>, leaveTime<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>id<sub>i</sub></code> 是处理第 <code>i</code> 个任务的员工的 id ，且</li>
	<li><code>leaveTime<sub>i</sub></code> 是员工完成第 <code>i</code> 个任务的时刻。所有 <code>leaveTime<sub>i</sub></code> 的值都是 <strong>唯一</strong> 的。</li>
</ul>

<p>注意，第 <code>i</code> 个任务在第 <code>(i - 1)</code> 个任务结束后立即开始，且第 <code>0</code> 个任务从时刻 <code>0</code> 开始。</p>

<p>返回处理用时最长的那个任务的员工的 id 。如果存在两个或多个员工同时满足，则返回几人中 <strong>最小</strong> 的 id 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, logs = [[0,3],[2,5],[0,9],[1,15]]
<strong>输出：</strong>1
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 3 结束，共计 3 个单位时间。
任务 1 于时刻 3 开始，且在时刻 5 结束，共计 2 个单位时间。
任务 2 于时刻 5 开始，且在时刻 9 结束，共计 4 个单位时间。
任务 3 于时刻 9 开始，且在时刻 15 结束，共计 6 个单位时间。
时间最长的任务是任务 3 ，而 id 为 1 的员工是处理此任务的员工，所以返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 26, logs = [[1,1],[3,7],[2,12],[7,17]]
<strong>输出：</strong>3
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 1 结束，共计 1 个单位时间。
任务 1 于时刻 1 开始，且在时刻 7 结束，共计 6 个单位时间。
任务 2 于时刻 7 开始，且在时刻 12 结束，共计 5 个单位时间。
任务 3 于时刻 12 开始，且在时刻 17 结束，共计 5 个单位时间。
时间最长的任务是任务 1 ，而 id 为 3 的员工是处理此任务的员工，所以返回 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, logs = [[0,10],[1,20]]
<strong>输出：</strong>0
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 10 结束，共计 10 个单位时间。
任务 1 于时刻 10 开始，且在时刻 20 结束，共计 10 个单位时间。
时间最长的任务是任务 0 和 1 ，处理这两个任务的员工的 id 分别是 0 和 1 ，所以返回最小的 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= logs.length &lt;= 500</code></li>
	<li><code>logs[i].length == 2</code></li>
	<li><code>0 &lt;= id<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= leaveTime<sub>i</sub> &lt;= 500</code></li>
	<li><code>id<sub>i</sub> != id<sub>i + 1</sub></code></li>
	<li><code>leaveTime<sub>i</sub></code> 按严格递增顺序排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们用变量 $last$ 记录上一个任务的结束时间，用变量 $mx$ 记录最长的工作时间，用变量 $ans$ 记录工作时间最长且 $id$ 最小的员工。初始时，三个变量均为 $0$。

接下来，遍历数组 $logs$，对于每个员工，我们将员工完成任务的时间减去上一个任务的结束时间，即可得到该员工的工作时间 $t$。如果 $mx$ 小于 $t$，或者 $mx$ 等于 $t$ 且该员工的 $id$ 小于 $ans$，则更新 $mx$ 和 $ans$。然后我们将 $last$ 更新为上一个任务的结束时间加上 $t$。继续遍历，直到遍历完整个数组。

最后返回答案 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $logs$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        last = mx = ans = 0
        for uid, t in logs:
            t -= last
            if mx < t or (mx == t and ans > uid):
                ans, mx = uid, t
            last += t
        return ans
```

#### Java

```java
class Solution {
    public int hardestWorker(int n, int[][] logs) {
        int ans = 0;
        int last = 0, mx = 0;
        for (int[] log : logs) {
            int uid = log[0], t = log[1];
            t -= last;
            if (mx < t || (mx == t && ans > uid)) {
                ans = uid;
                mx = t;
            }
            last += t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0, mx = 0, last = 0;
        for (auto& log : logs) {
            int uid = log[0], t = log[1];
            t -= last;
            if (mx < t || (mx == t && ans > uid)) {
                mx = t;
                ans = uid;
            }
            last += t;
        }
        return ans;
    }
};
```

#### Go

```go
func hardestWorker(n int, logs [][]int) (ans int) {
	var mx, last int
	for _, log := range logs {
		uid, t := log[0], log[1]
		t -= last
		if mx < t || (mx == t && uid < ans) {
			mx = t
			ans = uid
		}
		last += t
	}
	return
}
```

#### TypeScript

```ts
function hardestWorker(n: number, logs: number[][]): number {
    let [ans, mx, last] = [0, 0, 0];
    for (let [uid, t] of logs) {
        t -= last;
        if (mx < t || (mx == t && ans > uid)) {
            ans = uid;
            mx = t;
        }
        last += t;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn hardest_worker(n: i32, logs: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let mut max = 0;
        let mut pre = 0;
        for log in logs.iter() {
            let t = log[1] - pre;
            if t > max || (t == max && res > log[0]) {
                res = log[0];
                max = t;
            }
            pre = log[1];
        }
        res
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int hardestWorker(int n, int** logs, int logsSize, int* logsColSize) {
    int res = 0;
    int max = 0;
    int pre = 0;
    for (int i = 0; i < logsSize; i++) {
        int t = logs[i][1] - pre;
        if (t > max || (t == max && res > logs[i][0])) {
            res = logs[i][0];
            max = t;
        }
        pre = logs[i][1];
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn hardest_worker(n: i32, logs: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        let mut last = 0;

        for log in logs {
            let uid = log[0];
            let t = log[1];

            let diff = t - last;
            last = t;

            if diff > mx || (diff == mx && uid < ans) {
                ans = uid;
                mx = diff;
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

# [2433. 找出前缀异或的原始数组](https://leetcode.cn/problems/find-the-original-array-of-prefix-xor){#2433}

{{< tabs "2433" >}}

{{% tab "python" %}}
```python
class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        return [a ^ b for a, b in pairwise([0] + pref)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        int[] ans = new int[n];
        ans[0] = pref[0];
        for (int i = 1; i < n; ++i) {
            ans[i] = pref[i - 1] ^ pref[i];
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
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans = {pref[0]};
        for (int i = 1; i < n; ++i) {
            ans.push_back(pref[i - 1] ^ pref[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findArray(pref []int) []int {
	n := len(pref)
	ans := []int{pref[0]}
	for i := 1; i < n; i++ {
		ans = append(ans, pref[i-1]^pref[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findArray(pref: number[]): number[] {
    let ans = pref.slice();
    for (let i = 1; i < pref.length; i++) {
        ans[i] = pref[i - 1] ^ pref[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_array(pref: Vec<i32>) -> Vec<i32> {
        let n = pref.len();
        let mut res = vec![0; n];
        res[0] = pref[0];
        for i in 1..n {
            res[i] = pref[i] ^ pref[i - 1];
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize) {
    int* res = (int*) malloc(sizeof(int) * prefSize);
    res[0] = pref[0];
    for (int i = 1; i < prefSize; i++) {
        res[i] = pref[i - 1] ^ pref[i];
    }
    *returnSize = prefSize;
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的 <strong>整数</strong> 数组 <code>pref</code> 。找出并返回满足下述条件且长度为 <code>n</code> 的数组<em> </em><code>arr</code> ：</p>

<ul>
	<li><code>pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]</code>.</li>
</ul>

<p>注意 <code>^</code> 表示 <strong>按位异或</strong>（bitwise-xor）运算。</p>

<p>可以证明答案是 <strong>唯一</strong> 的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>pref = [5,2,0,3,1]
<strong>输出：</strong>[5,7,2,3,2]
<strong>解释：</strong>从数组 [5,7,2,3,2] 可以得到如下结果：
- pref[0] = 5
- pref[1] = 5 ^ 7 = 2
- pref[2] = 5 ^ 7 ^ 2 = 0
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pref = [13]
<strong>输出：</strong>[13]
<strong>解释：</strong>pref[0] = arr[0] = 13
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pref.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= pref[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据题意，我们有式子一：

$$
pref[i]=arr[0] \oplus arr[1] \oplus \cdots \oplus arr[i]
$$

所以，也就有式子二：

$$
pref[i-1]=arr[0] \oplus arr[1] \oplus \cdots \oplus arr[i-1]
$$

我们将式子一二进行异或运算，得到：

$$
pref[i] \oplus pref[i-1]=arr[i]
$$

即答案数组的每一项都是前缀异或数组的相邻两项进行异或运算得到的。

时间复杂度 $O(n)$，其中 $n$ 为前缀异或数组的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        return [a ^ b for a, b in pairwise([0] + pref)]
```

#### Java

```java
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        int[] ans = new int[n];
        ans[0] = pref[0];
        for (int i = 1; i < n; ++i) {
            ans[i] = pref[i - 1] ^ pref[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans = {pref[0]};
        for (int i = 1; i < n; ++i) {
            ans.push_back(pref[i - 1] ^ pref[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func findArray(pref []int) []int {
	n := len(pref)
	ans := []int{pref[0]}
	for i := 1; i < n; i++ {
		ans = append(ans, pref[i-1]^pref[i])
	}
	return ans
}
```

#### TypeScript

```ts
function findArray(pref: number[]): number[] {
    let ans = pref.slice();
    for (let i = 1; i < pref.length; i++) {
        ans[i] = pref[i - 1] ^ pref[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_array(pref: Vec<i32>) -> Vec<i32> {
        let n = pref.len();
        let mut res = vec![0; n];
        res[0] = pref[0];
        for i in 1..n {
            res[i] = pref[i] ^ pref[i - 1];
        }
        res
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize) {
    int* res = (int*) malloc(sizeof(int) * prefSize);
    res[0] = pref[0];
    for (int i = 1; i < prefSize; i++) {
        res[i] = pref[i - 1] ^ pref[i];
    }
    *returnSize = prefSize;
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2434. 使用机器人打印字典序最小的字符串](https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string){#2434}

{{< tabs "2434" >}}

{{% tab "python" %}}
```python
class Solution:
    def robotWithString(self, s: str) -> str:
        cnt = Counter(s)
        ans = []
        stk = []
        mi = 'a'
        for c in s:
            cnt[c] -= 1
            while mi < 'z' and cnt[mi] == 0:
                mi = chr(ord(mi) + 1)
            stk.append(c)
            while stk and stk[-1] <= mi:
                ans.append(stk.pop())
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String robotWithString(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        Deque<Character> stk = new ArrayDeque<>();
        char mi = 'a';
        for (char c : s.toCharArray()) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) {
                ++mi;
            }
            stk.push(c);
            while (!stk.isEmpty() && stk.peek() <= mi) {
                ans.append(stk.pop());
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string robotWithString(string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        char mi = 'a';
        string stk;
        string ans;
        for (char& c : s) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) ++mi;
            stk += c;
            while (!stk.empty() && stk.back() <= mi) {
                ans += stk.back();
                stk.pop_back();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func robotWithString(s string) string {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	mi := byte('a')
	stk := []byte{}
	ans := []byte{}
	for i := range s {
		cnt[s[i]-'a']--
		for mi < 'z' && cnt[mi-'a'] == 0 {
			mi++
		}
		stk = append(stk, s[i])
		for len(stk) > 0 && stk[len(stk)-1] <= mi {
			ans = append(ans, stk[len(stk)-1])
			stk = stk[:len(stk)-1]
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function robotWithString(s: string): string {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    const ans: string[] = [];
    const stk: string[] = [];
    let mi = 'a';
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) - 1);
        while (mi < 'z' && (cnt.get(mi) || 0) === 0) {
            mi = String.fromCharCode(mi.charCodeAt(0) + 1);
        }
        stk.push(c);
        while (stk.length > 0 && stk[stk.length - 1] <= mi) {
            ans.push(stk.pop()!);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn robot_with_string(s: String) -> String {
        let mut cnt = [0; 26];
        for &c in s.as_bytes() {
            cnt[(c - b'a') as usize] += 1;
        }

        let mut ans = Vec::with_capacity(s.len());
        let mut stk = Vec::new();
        let mut mi = 0;

        for &c in s.as_bytes() {
            cnt[(c - b'a') as usize] -= 1;
            while mi < 26 && cnt[mi] == 0 {
                mi += 1;
            }
            stk.push(c);
            while let Some(&top) = stk.last() {
                if (top - b'a') as usize <= mi {
                    ans.push(stk.pop().unwrap());
                } else {
                    break;
                }
            }
        }

        String::from_utf8(ans).unwrap()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和一个机器人，机器人当前有一个空字符串&nbsp;<code>t</code>&nbsp;。执行以下操作之一，直到&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;<strong>都变成空字符串：</strong></p>

<ul>
	<li>删除字符串&nbsp;<code>s</code>&nbsp;的 <strong>第一个</strong>&nbsp;字符，并将该字符给机器人。机器人把这个字符添加到 <code>t</code>&nbsp;的尾部。</li>
	<li>删除字符串&nbsp;<code>t</code>&nbsp;的&nbsp;<strong>最后一个</strong>&nbsp;字符，并将该字符给机器人。机器人将该字符写到纸上。</li>
</ul>

<p>请你返回纸上能写出的字典序最小的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "zza"
<b>输出：</b>"azz"
<b>解释：</b>用 p 表示写出来的字符串。
一开始，p="" ，s="zza" ，t="" 。
执行第一个操作三次，得到 p="" ，s="" ，t="zza" 。
执行第二个操作三次，得到 p="azz" ，s="" ，t="" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "bac"
<b>输出：</b>"abc"
<b>解释：</b>用 p 表示写出来的字符串。
执行第一个操作两次，得到 p="" ，s="c" ，t="ba" 。
执行第二个操作两次，得到 p="ab" ，s="c" ，t="" 。
执行第一个操作，得到 p="ab" ，s="" ，t="c" 。
执行第二个操作，得到 p="abc" ，s="" ，t="" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "bdda"
<b>输出：</b>"addb"
<b>解释：</b>用 p 表示写出来的字符串。
一开始，p="" ，s="bdda" ，t="" 。
执行第一个操作四次，得到 p="" ，s="" ，t="bdda" 。
执行第二个操作四次，得到 p="addb" ，s="" ，t="" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 栈

题目可以转化为，给定一个字符串序列，在借助一个辅助栈的情况下，将其转化为字典序最小的字符串序列。

我们可以用数组 $\textit{cnt}$ 维护字符串 $s$ 中每个字符的出现次数，用栈 $\textit{stk}$ 作为题目中的辅助栈，用变量 $\textit{mi}$ 维护还未遍历到的字符串中最小的字符。

遍历字符串 $s$，对于每个字符 $c$，我们先将字符 $c$ 在数组 $\textit{cnt}$ 中的出现次数减一，更新 $\textit{mi}$。然后将字符 $c$ 入栈，此时如果栈顶元素小于等于 $\textit{mi}$，则循环将栈顶元素出栈，并将出栈的字符加入答案。

遍历结束，返回答案即可。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 为字符集大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def robotWithString(self, s: str) -> str:
        cnt = Counter(s)
        ans = []
        stk = []
        mi = 'a'
        for c in s:
            cnt[c] -= 1
            while mi < 'z' and cnt[mi] == 0:
                mi = chr(ord(mi) + 1)
            stk.append(c)
            while stk and stk[-1] <= mi:
                ans.append(stk.pop())
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String robotWithString(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        Deque<Character> stk = new ArrayDeque<>();
        char mi = 'a';
        for (char c : s.toCharArray()) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) {
                ++mi;
            }
            stk.push(c);
            while (!stk.isEmpty() && stk.peek() <= mi) {
                ans.append(stk.pop());
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string robotWithString(string s) {
        int cnt[26] = {0};
        for (char& c : s) ++cnt[c - 'a'];
        char mi = 'a';
        string stk;
        string ans;
        for (char& c : s) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) ++mi;
            stk += c;
            while (!stk.empty() && stk.back() <= mi) {
                ans += stk.back();
                stk.pop_back();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func robotWithString(s string) string {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	mi := byte('a')
	stk := []byte{}
	ans := []byte{}
	for i := range s {
		cnt[s[i]-'a']--
		for mi < 'z' && cnt[mi-'a'] == 0 {
			mi++
		}
		stk = append(stk, s[i])
		for len(stk) > 0 && stk[len(stk)-1] <= mi {
			ans = append(ans, stk[len(stk)-1])
			stk = stk[:len(stk)-1]
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function robotWithString(s: string): string {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    const ans: string[] = [];
    const stk: string[] = [];
    let mi = 'a';
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) - 1);
        while (mi < 'z' && (cnt.get(mi) || 0) === 0) {
            mi = String.fromCharCode(mi.charCodeAt(0) + 1);
        }
        stk.push(c);
        while (stk.length > 0 && stk[stk.length - 1] <= mi) {
            ans.push(stk.pop()!);
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn robot_with_string(s: String) -> String {
        let mut cnt = [0; 26];
        for &c in s.as_bytes() {
            cnt[(c - b'a') as usize] += 1;
        }

        let mut ans = Vec::with_capacity(s.len());
        let mut stk = Vec::new();
        let mut mi = 0;

        for &c in s.as_bytes() {
            cnt[(c - b'a') as usize] -= 1;
            while mi < 26 && cnt[mi] == 0 {
                mi += 1;
            }
            stk.push(c);
            while let Some(&top) = stk.last() {
                if (top - b'a') as usize <= mi {
                    ans.push(stk.pop().unwrap());
                } else {
                    break;
                }
            }
        }

        String::from_utf8(ans).unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2435. 矩阵中和能被 K 整除的路径](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k){#2435}

{{< tabs "2435" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[0] * k for _ in range(n)] for _ in range(m)]
        dp[0][0][grid[0][0] % k] = 1
        mod = 10**9 + 7
        for i in range(m):
            for j in range(n):
                for s in range(k):
                    t = ((s - grid[i][j] % k) + k) % k
                    if i:
                        dp[i][j][s] += dp[i - 1][j][t]
                    if j:
                        dp[i][j][s] += dp[i][j - 1][t]
                    dp[i][j][s] %= mod
        return dp[-1][-1][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][][] dp = new int[m][n][k];
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int s = 0; s < k; ++s) {
                    int t = ((s - grid[i][j] % k) + k) % k;
                    if (i > 0) {
                        dp[i][j][s] += dp[i - 1][j][t];
                    }
                    if (j > 0) {
                        dp[i][j][s] += dp[i][j - 1][t];
                    }
                    dp[i][j][s] %= MOD;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int s = 0; s < k; ++s) {
                    int t = ((s - grid[i][j] % k) + k) % k;
                    if (i) dp[i][j][s] += dp[i - 1][j][t];
                    if (j) dp[i][j][s] += dp[i][j - 1][t];
                    dp[i][j][s] %= mod;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPaths(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	var mod int = 1e9 + 7
	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, k)
		}
	}
	dp[0][0][grid[0][0]%k] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for s := 0; s < k; s++ {
				t := ((s - grid[i][j]%k) + k) % k
				if i > 0 {
					dp[i][j][s] += dp[i-1][j][t]
				}
				if j > 0 {
					dp[i][j][s] += dp[i][j-1][t]
				}
				dp[i][j][s] %= mod
			}
		}
	}
	return dp[m-1][n-1][0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPaths(grid: number[][], k: number): number {
    const MOD = 10 ** 9 + 7;
    const m = grid.length,
        n = grid[0].length;
    let ans = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => new Array(k).fill(0)),
    );
    ans[0][1][0] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let v = 0; v < k; v++) {
                let key = (grid[i][j] + v) % k;
                ans[i + 1][j + 1][key] =
                    (ans[i][j + 1][v] + ans[i + 1][j][v] + ans[i + 1][j + 1][key]) % MOD;
            }
        }
    }
    return ans[m][n][0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;整数矩阵&nbsp;<code>grid</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。你从起点&nbsp;<code>(0, 0)</code>&nbsp;出发，每一步只能往 <strong>下</strong>&nbsp;或者往 <strong>右</strong>&nbsp;，你想要到达终点&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</p>

<p>请你返回路径和能被 <code>k</code>&nbsp;整除的路径数目，由于答案可能很大，返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2435.Paths%20in%20Matrix%20Whose%20Sum%20Is%20Divisible%20by%20K/images/image-20220813183124-1.png" style="width: 437px; height: 200px;"></p>

<pre><b>输入：</b>grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
<b>输出：</b>2
<b>解释：</b>有两条路径满足路径上元素的和能被 k 整除。
第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。
</pre>

<p><strong>示例 2：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2435.Paths%20in%20Matrix%20Whose%20Sum%20Is%20Divisible%20by%20K/images/image-20220817112930-3.png" style="height: 85px; width: 132px;">
<pre><b>输入：</b>grid = [[0,0]], k = 5
<b>输出：</b>1
<b>解释：</b>红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。
</pre>

<p><strong>示例 3：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2435.Paths%20in%20Matrix%20Whose%20Sum%20Is%20Divisible%20by%20K/images/image-20220812224605-3.png" style="width: 257px; height: 200px;">
<pre><b>输入：</b>grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
<b>输出：</b>10
<b>解释：</b>每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

设计函数 `dfs(i, j, s)` 表示从 `(i, j)` 出发，初始路径和模 $k$ 的结果为 $s$ 的路径数目。

对于每个位置 $(i, j)$，我们可以选择向右或向下移动，因此有：

$$
dfs(i, j, s) = dfs(i + 1, j, (s + grid[i][j]) \bmod k) + dfs(i, j + 1, (s + grid[i][j]) \bmod k)
$$

答案为 `dfs(0, 0, 0)`。记忆化搜索即可。

时间复杂度 $O(m \times n \times k)$，空间复杂度 $O(m \times n \times k)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数，而 $k$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        @cache
        def dfs(i, j, s):
            if i < 0 or i >= m or j < 0 or j >= n:
                return 0
            s = (s + grid[i][j]) % k
            if i == m - 1 and j == n - 1:
                return int(s == 0)
            ans = dfs(i + 1, j, s) + dfs(i, j + 1, s)
            return ans % mod

        m, n = len(grid), len(grid[0])
        mod = 10**9 + 7
        ans = dfs(0, 0, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int k;
    private static final int MOD = (int) 1e9 + 7;
    private int[][] grid;
    private int[][][] f;

    public int numberOfPaths(int[][] grid, int k) {
        this.grid = grid;
        this.k = k;
        m = grid.length;
        n = grid[0].length;
        f = new int[m][n][k];
        for (var a : f) {
            for (var b : a) {
                Arrays.fill(b, -1);
            }
        }
        return dfs(0, 0, 0);
    }

    private int dfs(int i, int j, int s) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        s = (s + grid[i][j]) % k;
        if (f[i][j][s] != -1) {
            return f[i][j][s];
        }
        if (i == m - 1 && j == n - 1) {
            return s == 0 ? 1 : 0;
        }
        int ans = dfs(i + 1, j, s) + dfs(i, j + 1, s);
        ans %= MOD;
        f[i][j][s] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(k, -1)));
        function<int(int, int, int)> dfs;
        dfs = [&](int i, int j, int s) {
            if (i < 0 || i >= m || j < 0 || j >= n) return 0;
            s = (s + grid[i][j]) % k;
            if (i == m - 1 && j == n - 1) return s == 0 ? 1 : 0;
            if (f[i][j][s] != -1) return f[i][j][s];
            int ans = dfs(i + 1, j, s) + dfs(i, j + 1, s);
            ans %= mod;
            f[i][j][s] = ans;
            return ans;
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func numberOfPaths(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	var mod int = 1e9 + 7
	f := make([][][]int, m)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, k)
			for x := 0; x < k; x++ {
				f[i][j][x] = -1
			}
		}
	}
	var dfs func(i, j, s int) int
	dfs = func(i, j, s int) int {
		if i < 0 || i >= m || j < 0 || j >= n {
			return 0
		}
		s = (s + grid[i][j]) % k
		if i == m-1 && j == n-1 {
			if s == 0 {
				return 1
			}
			return 0
		}
		if f[i][j][s] != -1 {
			return f[i][j][s]
		}
		ans := dfs(i+1, j, s) + dfs(i, j+1, s)
		ans %= mod
		f[i][j][s] = ans
		return ans
	}
	return dfs(0, 0, 0)
}
```

#### TypeScript

```ts
function numberOfPaths(grid: number[][], k: number): number {
    const MOD = 10 ** 9 + 7;
    const m = grid.length,
        n = grid[0].length;
    let ans = Array.from({ length: m + 1 }, () =>
        Array.from({ length: n + 1 }, () => new Array(k).fill(0)),
    );
    ans[0][1][0] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let v = 0; v < k; v++) {
                let key = (grid[i][j] + v) % k;
                ans[i + 1][j + 1][key] =
                    (ans[i][j + 1][v] + ans[i + 1][j][v] + ans[i + 1][j + 1][key]) % MOD;
            }
        }
    }
    return ans[m][n][0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划求解。

定义状态 $dp[i][j][s]$ 表示从起点 $(0, 0)$ 出发，到达位置 $(i, j)$，路径和模 $k$ 等于 $s$ 的路径数目。

初始值 $dp[0][0][grid[0][0] \bmod k] = 1$，答案为 $dp[m - 1][n - 1][0]$。

我们可以得到状态转移方程：

$$
dp[i][j][s] = dp[i - 1][j][(s - grid[i][j])\bmod k] + dp[i][j - 1][(s - grid[i][j])\bmod k]
$$

时间复杂度 $O(m \times n \times k)$，空间复杂度 $O(m \times n \times k)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数，而 $k$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[[0] * k for _ in range(n)] for _ in range(m)]
        dp[0][0][grid[0][0] % k] = 1
        mod = 10**9 + 7
        for i in range(m):
            for j in range(n):
                for s in range(k):
                    t = ((s - grid[i][j] % k) + k) % k
                    if i:
                        dp[i][j][s] += dp[i - 1][j][t]
                    if j:
                        dp[i][j][s] += dp[i][j - 1][t]
                    dp[i][j][s] %= mod
        return dp[-1][-1][0]
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][][] dp = new int[m][n][k];
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int s = 0; s < k; ++s) {
                    int t = ((s - grid[i][j] % k) + k) % k;
                    if (i > 0) {
                        dp[i][j][s] += dp[i - 1][j][t];
                    }
                    if (j > 0) {
                        dp[i][j][s] += dp[i][j - 1][t];
                    }
                    dp[i][j][s] %= MOD;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int s = 0; s < k; ++s) {
                    int t = ((s - grid[i][j] % k) + k) % k;
                    if (i) dp[i][j][s] += dp[i - 1][j][t];
                    if (j) dp[i][j][s] += dp[i][j - 1][t];
                    dp[i][j][s] %= mod;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
```

#### Go

```go
func numberOfPaths(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	var mod int = 1e9 + 7
	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, k)
		}
	}
	dp[0][0][grid[0][0]%k] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for s := 0; s < k; s++ {
				t := ((s - grid[i][j]%k) + k) % k
				if i > 0 {
					dp[i][j][s] += dp[i-1][j][t]
				}
				if j > 0 {
					dp[i][j][s] += dp[i][j-1][t]
				}
				dp[i][j][s] %= mod
			}
		}
	}
	return dp[m-1][n-1][0]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2436. 使子数组最大公约数大于一的最小分割数 🔒](https://leetcode.cn/problems/minimum-split-into-subarrays-with-gcd-greater-than-one){#2436}

{{< tabs "2436" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSplits(self, nums: List[int]) -> int:
        ans, g = 1, 0
        for x in nums:
            g = gcd(g, x)
            if g == 1:
                ans += 1
                g = x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSplits(int[] nums) {
        int ans = 1, g = 0;
        for (int x : nums) {
            g = gcd(g, x);
            if (g == 1) {
                ++ans;
                g = x;
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int ans = 1, g = 0;
        for (int x : nums) {
            g = gcd(g, x);
            if (g == 1) {
                ++ans;
                g = x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSplits(nums []int) int {
	ans, g := 1, 0
	for _, x := range nums {
		g = gcd(g, x)
		if g == 1 {
			ans++
			g = x
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSplits(nums: number[]): number {
    let ans = 1;
    let g = 0;
    for (const x of nums) {
        g = gcd(g, x);
        if (g == 1) {
            ++ans;
            g = x;
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b ? gcd(b, a % b) : a;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由正整数组成的数组 <code>nums</code>。</p>

<p>将数组拆分为&nbsp;<strong>一个或多个&nbsp;</strong>互相不覆盖的子数组，如下所示:</p>

<ul>
	<li>数组中的每个元素都&nbsp;<strong>只属于一个&nbsp;</strong>子数组，并且</li>
	<li>每个子数组元素的 <strong>最大公约数</strong> 严格大于 <code>1</code>。</li>
</ul>

<p>返回<em>拆分后可获得的子数组的最小数目。</em></p>

<p><b>注意</b>:</p>

<ul>
	<li>子数组的 <strong>最大公约数&nbsp;</strong>是能将子数组中所有元素整除的最大正整数。</li>
	<li>
	<p data-group="1-1"><strong>子数组&nbsp;</strong>是数组的连续部分。</p>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [12,6,3,14,8]
<strong>输出:</strong> 2
<strong>解释:</strong> 我们可以把数组分成子数组:[12,6,3] 和 [14,8]。
- 12、6、3 的最大公约数是 3，严格大于 1。
- 14 和 8 的最大公约数是 2，严格来说大于 1。
可以看出，如果不拆分数组将使最大公约数 = 1。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,12,6,14]
<strong>输出:</strong> 1
<strong>解释:</strong> 我们可以将数组拆分为一个子数组，即整个数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>2 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 数学

对于数组中的每个元素，如果它与前面的元素的最大公约数为 $1$，那么它需要作为一个新的子数组的第一个元素。否则，它可以与前面的元素放在同一个子数组中。

因此，我们先初始化一个变量 $g$，表示当前子数组的最大公约数。初始时 $g=0$，答案变量 $ans=1$。

接下来，我们从前往后遍历数组，维护当前子数组的最大公约数 $g$。如果当前元素 $x$ 与 $g$ 的最大公约数为 $1$，那么我们需要将当前元素作为一个新的子数组的第一个元素，因此，答案加 $1$，并将 $g$ 更新为 $x$。否则，当前元素可以与前面的元素放在同一个子数组中。继续遍历数组，直到遍历结束。

时间复杂度 $O(n \times \log m)$，其中 $n$ 和 $m$ 分别是数组的长度和数组中元素的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSplits(self, nums: List[int]) -> int:
        ans, g = 1, 0
        for x in nums:
            g = gcd(g, x)
            if g == 1:
                ans += 1
                g = x
        return ans
```

#### Java

```java
class Solution {
    public int minimumSplits(int[] nums) {
        int ans = 1, g = 0;
        for (int x : nums) {
            g = gcd(g, x);
            if (g == 1) {
                ++ans;
                g = x;
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int ans = 1, g = 0;
        for (int x : nums) {
            g = gcd(g, x);
            if (g == 1) {
                ++ans;
                g = x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumSplits(nums []int) int {
	ans, g := 1, 0
	for _, x := range nums {
		g = gcd(g, x)
		if g == 1 {
			ans++
			g = x
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function minimumSplits(nums: number[]): number {
    let ans = 1;
    let g = 0;
    for (const x of nums) {
        g = gcd(g, x);
        if (g == 1) {
            ++ans;
            g = x;
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b ? gcd(b, a % b) : a;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2437. 有效时间的数目](https://leetcode.cn/problems/number-of-valid-clock-times){#2437}

{{< tabs "2437" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTime(self, time: str) -> int:
        def f(s: str, m: int) -> int:
            cnt = 0
            for i in range(m):
                a = s[0] == '?' or (int(s[0]) == i // 10)
                b = s[1] == '?' or (int(s[1]) == i % 10)
                cnt += a and b
            return cnt

        return f(time[:2], 24) * f(time[3:], 60)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTime(String time) {
        return f(time.substring(0, 2), 24) * f(time.substring(3), 60);
    }

    private int f(String s, int m) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            boolean a = s.charAt(0) == '?' || s.charAt(0) - '0' == i / 10;
            boolean b = s.charAt(1) == '?' || s.charAt(1) - '0' == i % 10;
            cnt += a && b ? 1 : 0;
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countTime(string time) {
        auto f = [](string s, int m) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                bool a = s[0] == '?' || s[0] - '0' == i / 10;
                bool b = s[1] == '?' || s[1] - '0' == i % 10;
                cnt += a && b;
            }
            return cnt;
        };
        return f(time.substr(0, 2), 24) * f(time.substr(3, 2), 60);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countTime(time string) int {
	f := func(s string, m int) (cnt int) {
		for i := 0; i < m; i++ {
			a := s[0] == '?' || int(s[0]-'0') == i/10
			b := s[1] == '?' || int(s[1]-'0') == i%10
			if a && b {
				cnt++
			}
		}
		return
	}
	return f(time[:2], 24) * f(time[3:], 60)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTime(time: string): number {
    const f = (s: string, m: number): number => {
        let cnt = 0;
        for (let i = 0; i < m; ++i) {
            const a = s[0] === '?' || s[0] === Math.floor(i / 10).toString();
            const b = s[1] === '?' || s[1] === (i % 10).toString();
            if (a && b) {
                ++cnt;
            }
        }
        return cnt;
    };
    return f(time.slice(0, 2), 24) * f(time.slice(3), 60);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_time(time: String) -> i32 {
        let f = |s: &str, m: usize| -> i32 {
            let mut cnt = 0;
            let first = s.chars().nth(0).unwrap();
            let second = s.chars().nth(1).unwrap();

            for i in 0..m {
                let a = first == '?' || (first.to_digit(10).unwrap() as usize) == i / 10;

                let b = second == '?' || (second.to_digit(10).unwrap() as usize) == i % 10;

                if a && b {
                    cnt += 1;
                }
            }

            cnt
        };

        f(&time[..2], 24) * f(&time[3..], 60)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为&nbsp;<code>5</code>&nbsp;的字符串&nbsp;<code>time</code>&nbsp;，表示一个电子时钟当前的时间，格式为&nbsp;<code>"hh:mm"</code>&nbsp;。<strong>最早</strong>&nbsp;可能的时间是&nbsp;<code>"00:00"</code>&nbsp;，<strong>最晚</strong>&nbsp;可能的时间是&nbsp;<code>"23:59"</code>&nbsp;。</p>

<p>在字符串&nbsp;<code>time</code>&nbsp;中，被字符&nbsp;<code>?</code>&nbsp;替换掉的数位是 <strong>未知的</strong>&nbsp;，被替换的数字可能是&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;中的任何一个。</p>

<p>请你返回一个整数<em>&nbsp;</em><code>answer</code>&nbsp;，将每一个 <code>?</code>&nbsp;都用<em>&nbsp;</em><code>0</code>&nbsp;到<em>&nbsp;</em><code>9</code>&nbsp;中一个数字替换后，可以得到的有效时间的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>time = "?5:00"
<b>输出：</b>2
<b>解释：</b>我们可以将 ? 替换成 0 或 1 ，得到 "05:00" 或者 "15:00" 。注意我们不能替换成 2 ，因为时间 "25:00" 是无效时间。所以我们有两个选择。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>time = "0?:0?"
<b>输出：</b>100
<b>解释：</b>两个 ? 都可以被 0 到 9 之间的任意数字替换，所以我们总共有 100 种选择。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>time = "??:??"
<b>输出：</b>1440
<b>解释：</b>小时总共有 24 种选择，分钟总共有 60 种选择。所以总共有 24 * 60 = 1440 种选择。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>time</code>&nbsp;是一个长度为 <code>5</code>&nbsp;的有效字符串，格式为&nbsp;<code>"hh:mm"</code>&nbsp;。</li>
	<li><code>"00" &lt;= hh &lt;= "23"</code></li>
	<li><code>"00" &lt;= mm &lt;= "59"</code></li>
	<li>字符串中有的数位是&nbsp;<code>'?'</code>&nbsp;，需要用&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;之间的数字替换。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以直接枚举从 $00:00$ 到 $23:59$ 的所有时间，然后判断每个时间是否有效，是则答案加一。

枚举结束后将答案返回即可。

时间复杂度 $O(24 \times 60)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTime(self, time: str) -> int:
        def check(s: str, t: str) -> bool:
            return all(a == b or b == '?' for a, b in zip(s, t))

        return sum(
            check(f'{h:02d}:{m:02d}', time) for h in range(24) for m in range(60)
        )
```

#### Java

```java
class Solution {
    public int countTime(String time) {
        int ans = 0;
        for (int h = 0; h < 24; ++h) {
            for (int m = 0; m < 60; ++m) {
                String s = String.format("%02d:%02d", h, m);
                int ok = 1;
                for (int i = 0; i < 5; ++i) {
                    if (s.charAt(i) != time.charAt(i) && time.charAt(i) != '?') {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
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
    int countTime(string time) {
        int ans = 0;
        for (int h = 0; h < 24; ++h) {
            for (int m = 0; m < 60; ++m) {
                char s[20];
                sprintf(s, "%02d:%02d", h, m);
                int ok = 1;
                for (int i = 0; i < 5; ++i) {
                    if (s[i] != time[i] && time[i] != '?') {
                        ok = 0;
                        break;
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countTime(time string) int {
	ans := 0
	for h := 0; h < 24; h++ {
		for m := 0; m < 60; m++ {
			s := fmt.Sprintf("%02d:%02d", h, m)
			ok := 1
			for i := 0; i < 5; i++ {
				if s[i] != time[i] && time[i] != '?' {
					ok = 0
					break
				}
			}
			ans += ok
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countTime(time: string): number {
    let ans = 0;
    for (let h = 0; h < 24; ++h) {
        for (let m = 0; m < 60; ++m) {
            const s = `${h}`.padStart(2, '0') + ':' + `${m}`.padStart(2, '0');
            let ok = 1;
            for (let i = 0; i < 5; ++i) {
                if (s[i] !== time[i] && time[i] !== '?') {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_time(time: String) -> i32 {
        let mut ans = 0;

        for i in 0..24 {
            for j in 0..60 {
                let mut ok = true;
                let t = format!("{:02}:{:02}", i, j);

                for (k, ch) in time.chars().enumerate() {
                    if ch != '?' && ch != t.chars().nth(k).unwrap() {
                        ok = false;
                    }
                }

                if ok {
                    ans += 1;
                }
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

我们可以分开枚举小时和分钟，统计有多少个小时和分钟满足条件，然后将二者相乘即可。

时间复杂度 $O(24 + 60)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTime(self, time: str) -> int:
        def f(s: str, m: int) -> int:
            cnt = 0
            for i in range(m):
                a = s[0] == '?' or (int(s[0]) == i // 10)
                b = s[1] == '?' or (int(s[1]) == i % 10)
                cnt += a and b
            return cnt

        return f(time[:2], 24) * f(time[3:], 60)
```

#### Java

```java
class Solution {
    public int countTime(String time) {
        return f(time.substring(0, 2), 24) * f(time.substring(3), 60);
    }

    private int f(String s, int m) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            boolean a = s.charAt(0) == '?' || s.charAt(0) - '0' == i / 10;
            boolean b = s.charAt(1) == '?' || s.charAt(1) - '0' == i % 10;
            cnt += a && b ? 1 : 0;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countTime(string time) {
        auto f = [](string s, int m) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                bool a = s[0] == '?' || s[0] - '0' == i / 10;
                bool b = s[1] == '?' || s[1] - '0' == i % 10;
                cnt += a && b;
            }
            return cnt;
        };
        return f(time.substr(0, 2), 24) * f(time.substr(3, 2), 60);
    }
};
```

#### Go

```go
func countTime(time string) int {
	f := func(s string, m int) (cnt int) {
		for i := 0; i < m; i++ {
			a := s[0] == '?' || int(s[0]-'0') == i/10
			b := s[1] == '?' || int(s[1]-'0') == i%10
			if a && b {
				cnt++
			}
		}
		return
	}
	return f(time[:2], 24) * f(time[3:], 60)
}
```

#### TypeScript

```ts
function countTime(time: string): number {
    const f = (s: string, m: number): number => {
        let cnt = 0;
        for (let i = 0; i < m; ++i) {
            const a = s[0] === '?' || s[0] === Math.floor(i / 10).toString();
            const b = s[1] === '?' || s[1] === (i % 10).toString();
            if (a && b) {
                ++cnt;
            }
        }
        return cnt;
    };
    return f(time.slice(0, 2), 24) * f(time.slice(3), 60);
}
```

#### Rust

```rust
impl Solution {
    pub fn count_time(time: String) -> i32 {
        let f = |s: &str, m: usize| -> i32 {
            let mut cnt = 0;
            let first = s.chars().nth(0).unwrap();
            let second = s.chars().nth(1).unwrap();

            for i in 0..m {
                let a = first == '?' || (first.to_digit(10).unwrap() as usize) == i / 10;

                let b = second == '?' || (second.to_digit(10).unwrap() as usize) == i % 10;

                if a && b {
                    cnt += 1;
                }
            }

            cnt
        };

        f(&time[..2], 24) * f(&time[3..], 60)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2438. 二的幂数组中查询范围内的乘积](https://leetcode.cn/problems/range-product-queries-of-powers){#2438}

{{< tabs "2438" >}}

{{% tab "python" %}}
```python
class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        powers = []
        while n:
            x = n & -n
            powers.append(x)
            n -= x
        mod = 10**9 + 7
        ans = []
        for l, r in queries:
            x = 1
            for i in range(l, r + 1):
                x = x * powers[i] % mod
            ans.append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] productQueries(int n, int[][] queries) {
        int[] powers = new int[Integer.bitCount(n)];
        for (int i = 0; n > 0; ++i) {
            int x = n & -n;
            powers[i] = x;
            n -= x;
        }
        int m = queries.length;
        int[] ans = new int[m];
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            long x = 1;
            for (int j = l; j <= r; ++j) {
                x = x * powers[j] % mod;
            }
            ans[i] = (int) x;
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
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        while (n) {
            int x = n & -n;
            powers.push_back(x);
            n -= x;
        }
        vector<int> ans;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long x = 1;
            for (int j = l; j <= r; ++j) {
                x = x * powers[j] % mod;
            }
            ans.push_back(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func productQueries(n int, queries [][]int) []int {
	var powers []int
	for n > 0 {
		x := n & -n
		powers = append(powers, x)
		n -= x
	}
	const mod = 1_000_000_007
	ans := make([]int, 0, len(queries))
	for _, q := range queries {
		l, r := q[0], q[1]
		x := 1
		for j := l; j <= r; j++ {
			x = x * powers[j] % mod
		}
		ans = append(ans, x)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function productQueries(n: number, queries: number[][]): number[] {
    const powers: number[] = [];
    while (n > 0) {
        const x = n & -n;
        powers.push(x);
        n -= x;
    }
    const mod = 1_000_000_007;
    const ans: number[] = [];
    for (const [l, r] of queries) {
        let x = 1;
        for (let j = l; j <= r; j++) {
            x = (x * powers[j]) % mod;
        }
        ans.push(x);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn product_queries(mut n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut powers = Vec::new();
        while n > 0 {
            let x = n & -n;
            powers.push(x);
            n -= x;
        }
        let modulo = 1_000_000_007;
        let mut ans = Vec::with_capacity(queries.len());
        for q in queries {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let mut x: i64 = 1;
            for j in l..=r {
                x = x * powers[j] as i64 % modulo;
            }
            ans.push(x as i32);
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

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，你需要找到一个下标从&nbsp;<strong>0</strong>&nbsp;开始的数组&nbsp;<code>powers</code>&nbsp;，它包含 <strong>最少</strong>&nbsp;数目的 <code>2</code>&nbsp;的幂，且它们的和为&nbsp;<code>n</code>&nbsp;。<code>powers</code>&nbsp;数组是&nbsp;<strong>非递减</strong>&nbsp;顺序的。根据前面描述，构造&nbsp;<code>powers</code>&nbsp;数组的方法是唯一的。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;，其中&nbsp;<code>queries[i]</code>&nbsp;表示请你求出满足&nbsp;<code>left<sub>i</sub> &lt;= j &lt;= right<sub>i</sub></code>&nbsp;的所有&nbsp;<code>powers[j]</code>&nbsp;的乘积。</p>

<p>请你返回一个数组<em>&nbsp;</em><code>answers</code>&nbsp;，长度与<em>&nbsp;</em><code>queries</code>&nbsp;的长度相同，其中<em>&nbsp;</em><code>answers[i]</code>是第<em>&nbsp;</em><code>i</code>&nbsp;个查询的答案。由于查询的结果可能非常大，请你将每个&nbsp;<code>answers[i]</code>&nbsp;都对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 15, queries = [[0,1],[2,2],[0,3]]
<b>输出：</b>[2,4,64]
<strong>解释：</strong>
对于 n = 15 ，得到 powers = [1,2,4,8] 。没法得到元素数目更少的数组。
第 1 个查询的答案：powers[0] * powers[1] = 1 * 2 = 2 。
第 2 个查询的答案：powers[2] = 4 。
第 3 个查询的答案：powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64 。
每个答案对 10<sup>9</sup> + 7 取余得到的结果都相同，所以返回 [2,4,64] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 2, queries = [[0,0]]
<b>输出：</b>[2]
<strong>解释：</strong>
对于 n = 2, powers = [2] 。
唯一一个查询的答案是 powers[0] = 2 。答案对 10<sup>9</sup> + 7 取余后结果相同，所以返回 [2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt; powers.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算 + 模拟

我们可以使用位运算（Lowbit）来得到 $\textit{powers}$ 数组，然后通过模拟的方式求出每个查询的答案。

首先，对于给定的正整数 $n$，我们通过 $n \& -n$ 可以快速得到二进制表示中最低位的 $1$ 对应的数值，也就是当前数的最小 $2$ 的幂因子。对 $n$ 反复执行这个操作并减去该值，就能依次得到所有置位的 $2$ 的幂，形成 $\textit{powers}$ 数组。这个数组是递增的，且长度等于 $n$ 的二进制表示中 $1$ 的个数。

接下来，我们需要处理每个查询。对于当前查询 $(l, r)$，我们需要计算

$$
\textit{answers}[i] = \prod_{j=l}^{r} \textit{powers}[j]
$$

其中 $\textit{answers}[i]$ 是第 $i$ 个查询的答案。由于查询的结果可能非常大，我们需要对每个答案取模 $10^9 + 7$。

时间复杂度 $O(m \times \log n)$，其中 $m$ 为数组 $\textit{queries}$ 的长度。忽略答案的空间消耗，空间复杂度 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        powers = []
        while n:
            x = n & -n
            powers.append(x)
            n -= x
        mod = 10**9 + 7
        ans = []
        for l, r in queries:
            x = 1
            for i in range(l, r + 1):
                x = x * powers[i] % mod
            ans.append(x)
        return ans
```

#### Java

```java
class Solution {
    public int[] productQueries(int n, int[][] queries) {
        int[] powers = new int[Integer.bitCount(n)];
        for (int i = 0; n > 0; ++i) {
            int x = n & -n;
            powers[i] = x;
            n -= x;
        }
        int m = queries.length;
        int[] ans = new int[m];
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            long x = 1;
            for (int j = l; j <= r; ++j) {
                x = x * powers[j] % mod;
            }
            ans[i] = (int) x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        while (n) {
            int x = n & -n;
            powers.push_back(x);
            n -= x;
        }
        vector<int> ans;
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long long x = 1;
            for (int j = l; j <= r; ++j) {
                x = x * powers[j] % mod;
            }
            ans.push_back(x);
        }
        return ans;
    }
};
```

#### Go

```go
func productQueries(n int, queries [][]int) []int {
	var powers []int
	for n > 0 {
		x := n & -n
		powers = append(powers, x)
		n -= x
	}
	const mod = 1_000_000_007
	ans := make([]int, 0, len(queries))
	for _, q := range queries {
		l, r := q[0], q[1]
		x := 1
		for j := l; j <= r; j++ {
			x = x * powers[j] % mod
		}
		ans = append(ans, x)
	}
	return ans
}
```

#### TypeScript

```ts
function productQueries(n: number, queries: number[][]): number[] {
    const powers: number[] = [];
    while (n > 0) {
        const x = n & -n;
        powers.push(x);
        n -= x;
    }
    const mod = 1_000_000_007;
    const ans: number[] = [];
    for (const [l, r] of queries) {
        let x = 1;
        for (let j = l; j <= r; j++) {
            x = (x * powers[j]) % mod;
        }
        ans.push(x);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn product_queries(mut n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut powers = Vec::new();
        while n > 0 {
            let x = n & -n;
            powers.push(x);
            n -= x;
        }
        let modulo = 1_000_000_007;
        let mut ans = Vec::with_capacity(queries.len());
        for q in queries {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let mut x: i64 = 1;
            for j in l..=r {
                x = x * powers[j] as i64 % modulo;
            }
            ans.push(x as i32);
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

# [2439. 最小化数组中的最大值](https://leetcode.cn/problems/minimize-maximum-of-array){#2439}

{{< tabs "2439" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        def check(mx):
            d = 0
            for x in nums[:0:-1]:
                d = max(0, d + x - mx)
            return nums[0] + d <= mx

        left, right = 0, max(nums)
        while left < right:
            mid = (left + right) >> 1
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public int minimizeArrayValue(int[] nums) {
        this.nums = nums;
        int left = 0, right = max(nums);
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int mx) {
        long d = 0;
        for (int i = nums.length - 1; i > 0; --i) {
            d = Math.max(0, d + nums[i] - mx);
        }
        return nums[0] + d <= mx;
    }

    private int max(int[] nums) {
        int v = nums[0];
        for (int x : nums) {
            v = Math.max(v, x);
        }
        return v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        auto check = [&](int mx) {
            long d = 0;
            for (int i = nums.size() - 1; i; --i) {
                d = max(0l, d + nums[i] - mx);
            }
            return nums[0] + d <= mx;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeArrayValue(nums []int) int {
	check := func(mx int) bool {
		d := 0
		for i := len(nums) - 1; i > 0; i-- {
			d = max(0, nums[i]+d-mx)
		}
		return nums[0]+d <= mx
	}

	left, right := 0, slices.Max(nums)
	for left < right {
		mid := (left + right) >> 1
		if check(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，它含有&nbsp;<code>n</code>&nbsp;个非负整数。</p>

<p>每一步操作中，你需要：</p>

<ul>
	<li>选择一个满足&nbsp;<code>1 &lt;= i &lt; n</code>&nbsp;的整数 <code>i</code>&nbsp;，且&nbsp;<code>nums[i] &gt; 0</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[i]</code>&nbsp;减 1 。</li>
	<li>将&nbsp;<code>nums[i - 1]</code>&nbsp;加 1 。</li>
</ul>

<p>你可以对数组执行 <strong>任意</strong>&nbsp;次上述操作，请你返回可以得到的 <code>nums</code>&nbsp;数组中<b>&nbsp;最大值</b>&nbsp;<strong>最小</strong> 为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,7,1,6]
<b>输出：</b>5
<strong>解释：</strong>
一串最优操作是：
1. 选择 i = 1 ，nums 变为 [4,6,1,6] 。
2. 选择 i = 3 ，nums 变为 [4,6,2,5] 。
3. 选择 i = 1 ，nums 变为 [5,5,2,5] 。
nums 中最大值为 5 。无法得到比 5 更小的最大值。
所以我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [10,1]
<b>输出：</b>10
<strong>解释：</strong>
最优解是不改动 nums ，10 是最大值，所以返回 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

最小化数组的最大值，容易想到二分查找。我们二分枚举数组的最大值 $mx$，找到一个满足题目要求的、且值最小的 $mx$ 即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 为数组的长度，而 $M$ 为数组中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        def check(mx):
            d = 0
            for x in nums[:0:-1]:
                d = max(0, d + x - mx)
            return nums[0] + d <= mx

        left, right = 0, max(nums)
        while left < right:
            mid = (left + right) >> 1
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left
```

#### Java

```java
class Solution {
    private int[] nums;

    public int minimizeArrayValue(int[] nums) {
        this.nums = nums;
        int left = 0, right = max(nums);
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int mx) {
        long d = 0;
        for (int i = nums.length - 1; i > 0; --i) {
            d = Math.max(0, d + nums[i] - mx);
        }
        return nums[0] + d <= mx;
    }

    private int max(int[] nums) {
        int v = nums[0];
        for (int x : nums) {
            v = Math.max(v, x);
        }
        return v;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        auto check = [&](int mx) {
            long d = 0;
            for (int i = nums.size() - 1; i; --i) {
                d = max(0l, d + nums[i] - mx);
            }
            return nums[0] + d <= mx;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
```

#### Go

```go
func minimizeArrayValue(nums []int) int {
	check := func(mx int) bool {
		d := 0
		for i := len(nums) - 1; i > 0; i-- {
			d = max(0, nums[i]+d-mx)
		}
		return nums[0]+d <= mx
	}

	left, right := 0, slices.Max(nums)
	for left < right {
		mid := (left + right) >> 1
		if check(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

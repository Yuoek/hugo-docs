---
title: "0990_等式方程的可满足性"
date: 2025-10-08T18:36:43+08:00
weight: 10
tags: [二叉树, 位运算, 前缀和, 动态规划, 哈希表, 回溯, 图, 字符串, 并查集, 广度优先搜索, 数学, 数组, 树, 模拟, 深度优先搜索, 滑动窗口, 状态压缩, 矩阵, 计数, 贪心, 队列]
---

{{< markmap >}}
### [0990_等式方程的可满足性](#990)
#### [并查集](#990)
#### [图](#990)
#### [数组](#990)
#### [字符串](#990)
### [0991_坏了的计算器](#991)
#### [贪心](#991)
#### [数学](#991)
### [0992_K 个不同整数的子数组](#992)
#### [数组](#992)
#### [哈希表](#992)
#### [计数](#992)
#### [滑动窗口](#992)
### [0993_二叉树的堂兄弟节点](#993)
#### [树](#993)
#### [深度优先搜索](#993)
#### [广度优先搜索](#993)
#### [二叉树](#993)
### [0994_腐烂的橘子](#994)
#### [广度优先搜索](#994)
#### [数组](#994)
#### [矩阵](#994)
### [0995_K 连续位的最小翻转次数](#995)
#### [位运算](#995)
#### [队列](#995)
#### [数组](#995)
#### [前缀和](#995)
#### [滑动窗口](#995)
### [0996_平方数组的数目](#996)
#### [位运算](#996)
#### [数组](#996)
#### [哈希表](#996)
#### [数学](#996)
#### [动态规划](#996)
#### [回溯](#996)
#### [状态压缩](#996)
### [0997_找到小镇的法官](#997)
#### [图](#997)
#### [数组](#997)
#### [哈希表](#997)
### [0998_最大二叉树 II](#998)
#### [树](#998)
#### [二叉树](#998)
### [0999_可以被一步捕获的棋子数](#999)
#### [数组](#999)
#### [矩阵](#999)
#### [模拟](#999)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0990_等式方程的可满足性
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 字符串
---
### 0991_坏了的计算器
___
#### 贪心
___
#### 数学
---
### 0992_K 个不同整数的子数组
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 滑动窗口
---
### 0993_二叉树的堂兄弟节点
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0994_腐烂的橘子
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0995_K 连续位的最小翻转次数
___
#### 位运算
___
#### 队列
___
#### 数组
___
#### 前缀和
___
#### 滑动窗口
---
### 0996_平方数组的数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0997_找到小镇的法官
___
#### 图
___
#### 数组
___
#### 哈希表
---
### 0998_最大二叉树 II
___
#### 树
___
#### 二叉树
---
### 0999_可以被一步捕获的棋子数
___
#### 数组
___
#### 矩阵
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 回溯 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 数学 | 数组 |
| 树 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 状态压缩 | 矩阵 |
| 计数 | 贪心 | 队列 |

# [990. 等式方程的可满足性](https://leetcode.cn/problems/satisfiability-of-equality-equations){#990}

{{< tabs "990" >}}

{{% tab "python" %}}
```python
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(26))
        for e in equations:
            a, b = ord(e[0]) - ord('a'), ord(e[-1]) - ord('a')
            if e[1] == '=':
                p[find(a)] = find(b)
        for e in equations:
            a, b = ord(e[0]) - ord('a'), ord(e[-1]) - ord('a')
            if e[1] == '!' and find(a) == find(b):
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean equationsPossible(String[] equations) {
        p = new int[26];
        for (int i = 0; i < 26; ++i) {
            p[i] = i;
        }
        for (String e : equations) {
            int a = e.charAt(0) - 'a', b = e.charAt(3) - 'a';
            if (e.charAt(1) == '=') {
                p[find(a)] = find(b);
            }
        }
        for (String e : equations) {
            int a = e.charAt(0) - 'a', b = e.charAt(3) - 'a';
            if (e.charAt(1) == '!' && find(a) == find(b)) {
                return false;
            }
        }
        return true;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> p;

    bool equationsPossible(vector<string>& equations) {
        p.resize(26);
        for (int i = 0; i < 26; ++i) p[i] = i;
        for (auto& e : equations) {
            int a = e[0] - 'a', b = e[3] - 'a';
            if (e[1] == '=') p[find(a)] = find(b);
        }
        for (auto& e : equations) {
            int a = e[0] - 'a', b = e[3] - 'a';
            if (e[1] == '!' && find(a) == find(b)) return false;
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equationsPossible(equations []string) bool {
	p := make([]int, 26)
	for i := 1; i < 26; i++ {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range equations {
		a, b := int(e[0]-'a'), int(e[3]-'a')
		if e[1] == '=' {
			p[find(a)] = find(b)
		}
	}
	for _, e := range equations {
		a, b := int(e[0]-'a'), int(e[3]-'a')
		if e[1] == '!' && find(a) == find(b) {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    private parent: number[];

    constructor() {
        this.parent = Array.from({ length: 26 }).map((_, i) => i);
    }

    find(index: number) {
        if (this.parent[index] === index) {
            return index;
        }
        this.parent[index] = this.find(this.parent[index]);
        return this.parent[index];
    }

    union(index1: number, index2: number) {
        this.parent[this.find(index1)] = this.find(index2);
    }
}

function equationsPossible(equations: string[]): boolean {
    const uf = new UnionFind();
    for (const [a, s, _, b] of equations) {
        if (s === '=') {
            const index1 = a.charCodeAt(0) - 'a'.charCodeAt(0);
            const index2 = b.charCodeAt(0) - 'a'.charCodeAt(0);
            uf.union(index1, index2);
        }
    }
    for (const [a, s, _, b] of equations) {
        if (s === '!') {
            const index1 = a.charCodeAt(0) - 'a'.charCodeAt(0);
            const index2 = b.charCodeAt(0) - 'a'.charCodeAt(0);
            if (uf.find(index1) === uf.find(index2)) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 <code>equations[i]</code> 的长度为 <code>4</code>，并采用两种不同的形式之一：<code>&quot;a==b&quot;</code> 或&nbsp;<code>&quot;a!=b&quot;</code>。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。</p>

<p>只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回&nbsp;<code>true</code>，否则返回 <code>false</code>。&nbsp;</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[&quot;a==b&quot;,&quot;b!=a&quot;]
<strong>输出：</strong>false
<strong>解释：</strong>如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[&quot;b==a&quot;,&quot;a==b&quot;]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[&quot;a==b&quot;,&quot;b==c&quot;,&quot;a==c&quot;]
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>[&quot;a==b&quot;,&quot;b!=c&quot;,&quot;c==a&quot;]
<strong>输出：</strong>false
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>[&quot;c==c&quot;,&quot;b==d&quot;,&quot;x!=z&quot;]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= equations.length &lt;= 500</code></li>
	<li><code>equations[i].length == 4</code></li>
	<li><code>equations[i][0]</code> 和&nbsp;<code>equations[i][3]</code>&nbsp;是小写字母</li>
	<li><code>equations[i][1]</code> 要么是&nbsp;<code>&#39;=&#39;</code>，要么是&nbsp;<code>&#39;!&#39;</code></li>
	<li><code>equations[i][2]</code>&nbsp;是&nbsp;<code>&#39;=&#39;</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(26))
        for e in equations:
            a, b = ord(e[0]) - ord('a'), ord(e[-1]) - ord('a')
            if e[1] == '=':
                p[find(a)] = find(b)
        for e in equations:
            a, b = ord(e[0]) - ord('a'), ord(e[-1]) - ord('a')
            if e[1] == '!' and find(a) == find(b):
                return False
        return True
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean equationsPossible(String[] equations) {
        p = new int[26];
        for (int i = 0; i < 26; ++i) {
            p[i] = i;
        }
        for (String e : equations) {
            int a = e.charAt(0) - 'a', b = e.charAt(3) - 'a';
            if (e.charAt(1) == '=') {
                p[find(a)] = find(b);
            }
        }
        for (String e : equations) {
            int a = e.charAt(0) - 'a', b = e.charAt(3) - 'a';
            if (e.charAt(1) == '!' && find(a) == find(b)) {
                return false;
            }
        }
        return true;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> p;

    bool equationsPossible(vector<string>& equations) {
        p.resize(26);
        for (int i = 0; i < 26; ++i) p[i] = i;
        for (auto& e : equations) {
            int a = e[0] - 'a', b = e[3] - 'a';
            if (e[1] == '=') p[find(a)] = find(b);
        }
        for (auto& e : equations) {
            int a = e[0] - 'a', b = e[3] - 'a';
            if (e[1] == '!' && find(a) == find(b)) return false;
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```

#### Go

```go
func equationsPossible(equations []string) bool {
	p := make([]int, 26)
	for i := 1; i < 26; i++ {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range equations {
		a, b := int(e[0]-'a'), int(e[3]-'a')
		if e[1] == '=' {
			p[find(a)] = find(b)
		}
	}
	for _, e := range equations {
		a, b := int(e[0]-'a'), int(e[3]-'a')
		if e[1] == '!' && find(a) == find(b) {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
class UnionFind {
    private parent: number[];

    constructor() {
        this.parent = Array.from({ length: 26 }).map((_, i) => i);
    }

    find(index: number) {
        if (this.parent[index] === index) {
            return index;
        }
        this.parent[index] = this.find(this.parent[index]);
        return this.parent[index];
    }

    union(index1: number, index2: number) {
        this.parent[this.find(index1)] = this.find(index2);
    }
}

function equationsPossible(equations: string[]): boolean {
    const uf = new UnionFind();
    for (const [a, s, _, b] of equations) {
        if (s === '=') {
            const index1 = a.charCodeAt(0) - 'a'.charCodeAt(0);
            const index2 = b.charCodeAt(0) - 'a'.charCodeAt(0);
            uf.union(index1, index2);
        }
    }
    for (const [a, s, _, b] of equations) {
        if (s === '!') {
            const index1 = a.charCodeAt(0) - 'a'.charCodeAt(0);
            const index2 = b.charCodeAt(0) - 'a'.charCodeAt(0);
            if (uf.find(index1) === uf.find(index2)) {
                return false;
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [991. 坏了的计算器](https://leetcode.cn/problems/broken-calculator){#991}

{{< tabs "991" >}}

{{% tab "python" %}}
```python
class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        ans = 0
        while startValue < target:
            if target & 1:
                target += 1
            else:
                target >>= 1
            ans += 1
        ans += startValue - target
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if ((target & 1) == 1) {
                target++;
            } else {
                target >>= 1;
            }
            ans += 1;
        }
        ans += startValue - target;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if (target & 1) {
                target++;
            } else {
                target >>= 1;
            }
            ++ans;
        }
        ans += startValue - target;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func brokenCalc(startValue int, target int) (ans int) {
	for startValue < target {
		if target&1 == 1 {
			target++
		} else {
			target >>= 1
		}
		ans++
	}
	ans += startValue - target
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function brokenCalc(startValue: number, target: number): number {
    let ans = 0;
    for (; startValue < target; ++ans) {
        if (target & 1) {
            ++target;
        } else {
            target >>= 1;
        }
    }
    ans += startValue - target;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在显示着数字&nbsp;<code>startValue</code>&nbsp;的坏计算器上，我们可以执行以下两种操作：</p>

<ul>
	<li><strong>双倍（Double）：</strong>将显示屏上的数字乘 2；</li>
	<li><strong>递减（Decrement）：</strong>将显示屏上的数字减 <code>1</code> 。</li>
</ul>

<p>给定两个整数&nbsp;<code>startValue</code>&nbsp;和&nbsp;<code>target</code>&nbsp;。返回显示数字&nbsp;<code>target</code>&nbsp;所需的最小操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>startValue = 2, target = 3
<strong>输出：</strong>2
<strong>解释：</strong>先进行双倍运算，然后再进行递减运算 {2 -&gt; 4 -&gt; 3}.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>startValue = 5, target = 8
<strong>输出：</strong>2
<strong>解释：</strong>先递减，再双倍 {5 -&gt; 4 -&gt; 8}.
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>startValue = 3, target = 10
<strong>输出：</strong>3
<strong>解释：</strong>先双倍，然后递减，再双倍 {3 -&gt; 6 -&gt; 5 -&gt; 10}.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= startValue, target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向计算

我们可以采用逆向计算的方式，从 $\textit{target}$ 开始，如果 $\textit{target}$ 是奇数，那么 $\textit{target} = \textit{target} + 1$，否则 $\textit{target} = \textit{target} / 2$，累加操作次数，直到 $\textit{target} \leq \textit{startValue}$，此时的操作次数加上 $\textit{startValue} - \textit{target}$ 即为最终结果。

时间复杂度 $O(\log n)$，其中 $n$ 为 $\textit{target}$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        ans = 0
        while startValue < target:
            if target & 1:
                target += 1
            else:
                target >>= 1
            ans += 1
        ans += startValue - target
        return ans
```

#### Java

```java
class Solution {
    public int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if ((target & 1) == 1) {
                target++;
            } else {
                target >>= 1;
            }
            ans += 1;
        }
        ans += startValue - target;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if (target & 1) {
                target++;
            } else {
                target >>= 1;
            }
            ++ans;
        }
        ans += startValue - target;
        return ans;
    }
};
```

#### Go

```go
func brokenCalc(startValue int, target int) (ans int) {
	for startValue < target {
		if target&1 == 1 {
			target++
		} else {
			target >>= 1
		}
		ans++
	}
	ans += startValue - target
	return
}
```

#### TypeScript

```ts
function brokenCalc(startValue: number, target: number): number {
    let ans = 0;
    for (; startValue < target; ++ans) {
        if (target & 1) {
            ++target;
        } else {
            target >>= 1;
        }
    }
    ans += startValue - target;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [992. K 个不同整数的子数组](https://leetcode.cn/problems/subarrays-with-k-different-integers){#992}

{{< tabs "992" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def f(k):
            pos = [0] * len(nums)
            cnt = Counter()
            j = 0
            for i, x in enumerate(nums):
                cnt[x] += 1
                while len(cnt) > k:
                    cnt[nums[j]] -= 1
                    if cnt[nums[j]] == 0:
                        cnt.pop(nums[j])
                    j += 1
                pos[i] = j
            return pos

        return sum(a - b for a, b in zip(f(k - 1), f(k)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int[] left = f(nums, k);
        int[] right = f(nums, k - 1);
        int ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            ans += right[i] - left[i];
        }
        return ans;
    }

    private int[] f(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        int[] pos = new int[n];
        int s = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++s;
            }
            for (; s > k; ++j) {
                if (--cnt[nums[j]] == 0) {
                    --s;
                }
            }
            pos[i] = j;
        }
        return pos;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> left = f(nums, k);
        vector<int> right = f(nums, k - 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += right[i] - left[i];
        }
        return ans;
    }

    vector<int> f(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos(n);
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        int s = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++s;
            }
            for (; s > k; ++j) {
                if (--cnt[nums[j]] == 0) {
                    --s;
                }
            }
            pos[i] = j;
        }
        return pos;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subarraysWithKDistinct(nums []int, k int) (ans int) {
	f := func(k int) []int {
		n := len(nums)
		pos := make([]int, n)
		cnt := make([]int, n+1)
		s, j := 0, 0
		for i, x := range nums {
			cnt[x]++
			if cnt[x] == 1 {
				s++
			}
			for ; s > k; j++ {
				cnt[nums[j]]--
				if cnt[nums[j]] == 0 {
					s--
				}
			}
			pos[i] = j
		}
		return pos
	}
	left, right := f(k), f(k-1)
	for i := range left {
		ans += right[i] - left[i]
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

<p>给定一个正整数数组 <code>nums</code>和一个整数 <code>k</code>，返回 <code>nums</code> 中 「<strong>好子数组」</strong><em>&nbsp;</em>的数目。</p>

<p>如果 <code>nums</code>&nbsp;的某个子数组中不同整数的个数恰好为 <code>k</code>，则称 <code>nums</code>&nbsp;的这个连续、不一定不同的子数组为 <strong>「</strong><strong>好子数组 」</strong>。</p>

<ul>
	<li>例如，<code>[1,2,3,1,2]</code> 中有&nbsp;<code>3</code>&nbsp;个不同的整数：<code>1</code>，<code>2</code>，以及&nbsp;<code>3</code>。</li>
</ul>

<p><strong>子数组</strong> 是数组的 <strong>连续</strong> 部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2,3], k = 2
<strong>输出：</strong>7
<strong>解释：</strong>恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,3,4], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们遍历数组 $nums$，对于每个 $i$，我们需要找到最小的 $j_1$，使得 $nums[j_1], nums[j_1 + 1], \dots, nums[i]$ 中不同的整数个数小于等于 $k$，以及最小的 $j_2$，使得 $nums[j_2], nums[j_2 + 1], \dots, nums[i]$ 中不同的整数个数小于等于 $k-1$。那么 $j_2 - j_1$ 就是以 $i$ 结尾的满足条件的子数组的个数。

在实现上，我们定义一个函数 $f(k)$，表示 $nums$ 中每个位置 $i$ 对应的最小的 $j$，使得 $nums[j], nums[j + 1], \dots, nums[i]$ 中不同的整数个数小于等于 $k$。该函数可以通过双指针实现，具体实现见代码。

然后我们调用 $f(k)$ 和 $f(k-1)$，计算出每个位置对应的 $j_1$ 和 $j_2$，然后计算出以每个位置 $i$ 结尾的满足条件的子数组的个数，最后求和即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def f(k):
            pos = [0] * len(nums)
            cnt = Counter()
            j = 0
            for i, x in enumerate(nums):
                cnt[x] += 1
                while len(cnt) > k:
                    cnt[nums[j]] -= 1
                    if cnt[nums[j]] == 0:
                        cnt.pop(nums[j])
                    j += 1
                pos[i] = j
            return pos

        return sum(a - b for a, b in zip(f(k - 1), f(k)))
```

#### Java

```java
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        int[] left = f(nums, k);
        int[] right = f(nums, k - 1);
        int ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            ans += right[i] - left[i];
        }
        return ans;
    }

    private int[] f(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        int[] pos = new int[n];
        int s = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++s;
            }
            for (; s > k; ++j) {
                if (--cnt[nums[j]] == 0) {
                    --s;
                }
            }
            pos[i] = j;
        }
        return pos;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> left = f(nums, k);
        vector<int> right = f(nums, k - 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += right[i] - left[i];
        }
        return ans;
    }

    vector<int> f(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos(n);
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        int s = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (++cnt[nums[i]] == 1) {
                ++s;
            }
            for (; s > k; ++j) {
                if (--cnt[nums[j]] == 0) {
                    --s;
                }
            }
            pos[i] = j;
        }
        return pos;
    }
};
```

#### Go

```go
func subarraysWithKDistinct(nums []int, k int) (ans int) {
	f := func(k int) []int {
		n := len(nums)
		pos := make([]int, n)
		cnt := make([]int, n+1)
		s, j := 0, 0
		for i, x := range nums {
			cnt[x]++
			if cnt[x] == 1 {
				s++
			}
			for ; s > k; j++ {
				cnt[nums[j]]--
				if cnt[nums[j]] == 0 {
					s--
				}
			}
			pos[i] = j
		}
		return pos
	}
	left, right := f(k), f(k-1)
	for i := range left {
		ans += right[i] - left[i]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [993. 二叉树的堂兄弟节点](https://leetcode.cn/problems/cousins-in-binary-tree){#993}

{{< tabs "993" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        def dfs(root, parent, depth):
            if root is None:
                return
            if root.val == x:
                st[0] = (parent, depth)
            elif root.val == y:
                st[1] = (parent, depth)
            dfs(root.left, root, depth + 1)
            dfs(root.right, root, depth + 1)

        st = [None, None]
        dfs(root, None, 0)
        return st[0][0] != st[1][0] and st[0][1] == st[1][1]
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
    private int x, y;
    private int d1, d2;
    private TreeNode p1, p2;

    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, null, 0);
        return p1 != p2 && d1 == d2;
    }

    private void dfs(TreeNode root, TreeNode parent, int depth) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            d1 = depth;
            p1 = parent;
        } else if (root.val == y) {
            d2 = depth;
            p2 = parent;
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
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
    bool isCousins(TreeNode* root, int x, int y) {
        int d1, d2;
        TreeNode* p1;
        TreeNode* p2;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* root, TreeNode* parent, int depth) {
            if (!root) {
                return;
            }
            if (root->val == x) {
                d1 = depth;
                p1 = parent;
            } else if (root->val == y) {
                d2 = depth;
                p2 = parent;
            }
            dfs(root->left, root, depth + 1);
            dfs(root->right, root, depth + 1);
        };
        dfs(root, nullptr, 0);
        return p1 != p2 && d1 == d2;
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
func isCousins(root *TreeNode, x int, y int) bool {
	var d1, d2 int
	var p1, p2 *TreeNode
	var dfs func(root, parent *TreeNode, depth int)
	dfs = func(root, parent *TreeNode, depth int) {
		if root == nil {
			return
		}
		if root.Val == x {
			d1, p1 = depth, parent
		} else if root.Val == y {
			d2, p2 = depth, parent
		}
		dfs(root.Left, root, depth+1)
		dfs(root.Right, root, depth+1)
	}
	dfs(root, nil, 0)
	return d1 == d2 && p1 != p2
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

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
    let [d1, d2, p1, p2] = [0, 0, null, null];
    const dfs = (root: TreeNode | null, parent: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (root.val === x) {
            [d1, p1] = [depth, parent];
        } else if (root.val === y) {
            [d2, p2] = [depth, parent];
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
    };
    dfs(root, null, 0);
    return d1 === d2 && p1 !== p2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在二叉树中，根节点位于深度 <code>0</code> 处，每个深度为 <code>k</code> 的节点的子节点位于深度 <code>k+1</code> 处。</p>

<p>如果二叉树的两个节点深度相同，但<strong> 父节点不同</strong> ，则它们是一对<em>堂兄弟节点</em>。</p>

<p>我们给出了具有唯一值的二叉树的根节点 <code>root</code> ，以及树中两个不同节点的值 <code>x</code> 和 <code>y</code> 。</p>

<p>只有与值 <code>x</code> 和 <code>y</code> 对应的节点是堂兄弟节点时，才返回 <code>true</code> 。否则，返回 <code>false</code>。</p>

<p> </p>

<p><strong>示例 1：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-01.png" style="height: 160px; width: 180px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4], x = 4, y = 3
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-02.png" style="height: 160px; width: 201px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4,null,5], x = 5, y = 4
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0993.Cousins%20in%20Binary%20Tree/images/q1248-03.png" style="height: 160px; width: 156px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4], x = 2, y = 3
<strong>输出：</strong>false</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点数介于 <code>2</code> 到 <code>100</code> 之间。</li>
	<li>每个节点的值都是唯一的、范围为 <code>1</code> 到 <code>100</code> 的整数。</li>
</ul>

<p> </p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 $q$，队列中存储的是节点和其父节点。初始时，将根节点和空节点放入队列中。

每次从队列中取出一个节点，如果该节点的值为 $x$ 或 $y$，则记录该节点的父节点和深度。如果该节点的左右子节点不为空，则将左右子节点和该节点放入队列中。

当队列中所有节点都处理完毕后，如果 $x$ 和 $y$ 的深度相同且父节点不同，则返回 $true$，否则返回 $false$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        q = deque([(root, None)])
        depth = 0
        p1 = p2 = None
        d1 = d2 = None
        while q:
            for _ in range(len(q)):
                node, parent = q.popleft()
                if node.val == x:
                    p1, d1 = parent, depth
                elif node.val == y:
                    p2, d2 = parent, depth
                if node.left:
                    q.append((node.left, node))
                if node.right:
                    q.append((node.right, node))
            depth += 1
        return p1 != p2 and d1 == d2
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
    public boolean isCousins(TreeNode root, int x, int y) {
        Deque<TreeNode[]> q = new ArrayDeque<>();
        q.offer(new TreeNode[] {root, null});
        int d1 = 0, d2 = 0;
        TreeNode p1 = null, p2 = null;
        for (int depth = 0; !q.isEmpty(); ++depth) {
            for (int n = q.size(); n > 0; --n) {
                TreeNode[] t = q.poll();
                TreeNode node = t[0], parent = t[1];
                if (node.val == x) {
                    d1 = depth;
                    p1 = parent;
                } else if (node.val == y) {
                    d2 = depth;
                    p2 = parent;
                }
                if (node.left != null) {
                    q.offer(new TreeNode[] {node.left, node});
                }
                if (node.right != null) {
                    q.offer(new TreeNode[] {node.right, node});
                }
            }
        }
        return p1 != p2 && d1 == d2;
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        int d1 = 0, d2 = 0;
        TreeNode *p1 = nullptr, *p2 = nullptr;
        for (int depth = 0; q.size(); ++depth) {
            for (int n = q.size(); n; --n) {
                auto [node, parent] = q.front();
                q.pop();
                if (node->val == x) {
                    d1 = depth;
                    p1 = parent;
                } else if (node->val == y) {
                    d2 = depth;
                    p2 = parent;
                }
                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }
        }
        return d1 == d2 && p1 != p2;
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
func isCousins(root *TreeNode, x int, y int) bool {
	type pair struct{ node, parent *TreeNode }
	var d1, d2 int
	var p1, p2 *TreeNode
	q := []pair{{root, nil}}
	for depth := 0; len(q) > 0; depth++ {
		for n := len(q); n > 0; n-- {
			node, parent := q[0].node, q[0].parent
			q = q[1:]
			if node.Val == x {
				d1, p1 = depth, parent
			} else if node.Val == y {
				d2, p2 = depth, parent
			}
			if node.Left != nil {
				q = append(q, pair{node.Left, node})
			}
			if node.Right != nil {
				q = append(q, pair{node.Right, node})
			}
		}
	}
	return d1 == d2 && p1 != p2
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

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
    let [d1, d2] = [0, 0];
    let [p1, p2] = [null, null];
    const q: [TreeNode, TreeNode][] = [[root, null]];
    for (let depth = 0; q.length > 0; ++depth) {
        const t: [TreeNode, TreeNode][] = [];
        for (const [node, parent] of q) {
            if (node.val === x) {
                [d1, p1] = [depth, parent];
            } else if (node.val === y) {
                [d2, p2] = [depth, parent];
            }
            if (node.left) {
                t.push([node.left, node]);
            }
            if (node.right) {
                t.push([node.right, node]);
            }
        }
        q.splice(0, q.length, ...t);
    }
    return d1 === d2 && p1 !== p2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们设计一个函数 $dfs(root, parent, depth)$，表示从根节点 $root$ 出发，其父节点为 $parent$，深度为 $depth$，进行深度优先搜索。

在函数中，我们首先判断当前节点是否为空，如果为空，则直接返回。如果当前节点的值为 $x$ 或 $y$，则记录该节点的父节点和深度。然后对当前节点的左右子节点分别调用函数 $dfs$，其中父节点为当前节点，深度为当前深度加 $1$。即 $dfs(root.left, root, depth + 1)$ 和 $dfs(root.right, root, depth + 1)$。

当整棵二叉树遍历完毕后，如果 $x$ 和 $y$ 的深度相同且父节点不同，则返回 $true$，否则返回 $false$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        def dfs(root, parent, depth):
            if root is None:
                return
            if root.val == x:
                st[0] = (parent, depth)
            elif root.val == y:
                st[1] = (parent, depth)
            dfs(root.left, root, depth + 1)
            dfs(root.right, root, depth + 1)

        st = [None, None]
        dfs(root, None, 0)
        return st[0][0] != st[1][0] and st[0][1] == st[1][1]
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
    private int x, y;
    private int d1, d2;
    private TreeNode p1, p2;

    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        dfs(root, null, 0);
        return p1 != p2 && d1 == d2;
    }

    private void dfs(TreeNode root, TreeNode parent, int depth) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            d1 = depth;
            p1 = parent;
        } else if (root.val == y) {
            d2 = depth;
            p2 = parent;
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
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
    bool isCousins(TreeNode* root, int x, int y) {
        int d1, d2;
        TreeNode* p1;
        TreeNode* p2;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* root, TreeNode* parent, int depth) {
            if (!root) {
                return;
            }
            if (root->val == x) {
                d1 = depth;
                p1 = parent;
            } else if (root->val == y) {
                d2 = depth;
                p2 = parent;
            }
            dfs(root->left, root, depth + 1);
            dfs(root->right, root, depth + 1);
        };
        dfs(root, nullptr, 0);
        return p1 != p2 && d1 == d2;
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
func isCousins(root *TreeNode, x int, y int) bool {
	var d1, d2 int
	var p1, p2 *TreeNode
	var dfs func(root, parent *TreeNode, depth int)
	dfs = func(root, parent *TreeNode, depth int) {
		if root == nil {
			return
		}
		if root.Val == x {
			d1, p1 = depth, parent
		} else if root.Val == y {
			d2, p2 = depth, parent
		}
		dfs(root.Left, root, depth+1)
		dfs(root.Right, root, depth+1)
	}
	dfs(root, nil, 0)
	return d1 == d2 && p1 != p2
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

function isCousins(root: TreeNode | null, x: number, y: number): boolean {
    let [d1, d2, p1, p2] = [0, 0, null, null];
    const dfs = (root: TreeNode | null, parent: TreeNode | null, depth: number) => {
        if (!root) {
            return;
        }
        if (root.val === x) {
            [d1, p1] = [depth, parent];
        } else if (root.val === y) {
            [d2, p2] = [depth, parent];
        }
        dfs(root.left, root, depth + 1);
        dfs(root.right, root, depth + 1);
    };
    dfs(root, null, 0);
    return d1 === d2 && p1 !== p2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [994. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges){#994}

{{< tabs "994" >}}

{{% tab "python" %}}
```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = 0
        q = deque()
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 2:
                    q.append((i, j))
                elif x == 1:
                    cnt += 1
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        while q and cnt:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                        grid[x][y] = 2
                        q.append((x, y))
                        cnt -= 1
                        if cnt == 0:
                            return ans
        return -1 if cnt else 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                } else if (grid[i][j] == 2) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int ans = 1; !q.isEmpty() && cnt > 0; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                for (int d = 0; d < 4; ++d) {
                    int x = p[0] + dirs[d], y = p[1] + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.offer(new int[] {x, y});
                        if (--cnt == 0) {
                            return ans;
                        }
                    }
                }
            }
        }
        return cnt > 0 ? -1 : 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }
        const int dirs[5] = {-1, 0, 1, 0, -1};
        for (int ans = 1; q.size() && cnt; ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.emplace(x, y);
                        if (--cnt == 0) {
                            return ans;
                        }
                    }
                }
            }
        }
        return cnt > 0 ? -1 : 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func orangesRotting(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := [][2]int{}
	cnt := 0
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				cnt++
			} else if x == 2 {
				q = append(q, [2]int{i, j})
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for ans := 1; len(q) > 0 && cnt > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			for d := 0; d < 4; d++ {
				x, y := p[0]+dirs[d], p[1]+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
					grid[x][y] = 2
					q = append(q, [2]int{x, y})
					if cnt--; cnt == 0 {
						return ans
					}
				}
			}
		}
	}
	if cnt > 0 {
		return -1
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function orangesRotting(grid: number[][]): number {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const q: number[][] = [];
    let cnt: number = 0;
    for (let i: number = 0; i < m; ++i) {
        for (let j: number = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                cnt++;
            } else if (grid[i][j] === 2) {
                q.push([i, j]);
            }
        }
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (let ans = 1; q.length && cnt; ++ans) {
        const t: number[][] = [];
        for (const [i, j] of q) {
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                    grid[x][y] = 2;
                    t.push([x, y]);
                    if (--cnt === 0) {
                        return ans;
                    }
                }
            }
        }
        q.splice(0, q.length, ...t);
    }
    return cnt > 0 ? -1 : 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut q = VecDeque::new();
        let mut cnt = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    cnt += 1;
                } else if grid[i][j] == 2 {
                    q.push_back((i, j));
                }
            }
        }

        let dirs = [-1, 0, 1, 0, -1];
        for ans in 1.. {
            if q.is_empty() || cnt == 0 {
                break;
            }
            let mut size = q.len();
            for _ in 0..size {
                let (x, y) = q.pop_front().unwrap();
                for d in 0..4 {
                    let nx = x as isize + dirs[d] as isize;
                    let ny = y as isize + dirs[d + 1] as isize;
                    if nx >= 0 && nx < m as isize && ny >= 0 && ny < n as isize {
                        let nx = nx as usize;
                        let ny = ny as usize;
                        if grid[nx][ny] == 1 {
                            grid[nx][ny] = 2;
                            q.push_back((nx, ny));
                            cnt -= 1;
                            if cnt == 0 {
                                return ans;
                            }
                        }
                    }
                }
            }
        }
        if cnt > 0 {
            -1
        } else {
            0
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let q = [];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                cnt++;
            } else if (grid[i][j] === 2) {
                q.push([i, j]);
            }
        }
    }

    const dirs = [-1, 0, 1, 0, -1];
    for (let ans = 1; q.length && cnt; ++ans) {
        let t = [];
        for (const [i, j] of q) {
            for (let d = 0; d < 4; ++d) {
                const x = i + dirs[d];
                const y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                    grid[x][y] = 2;
                    t.push([x, y]);
                    if (--cnt === 0) {
                        return ans;
                    }
                }
            }
        }
        q = [...t];
    }

    return cnt > 0 ? -1 : 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在给定的&nbsp;<code>m x n</code>&nbsp;网格<meta charset="UTF-8" />&nbsp;<code>grid</code>&nbsp;中，每个单元格可以有以下三个值之一：</p>

<ul>
	<li>值&nbsp;<code>0</code>&nbsp;代表空单元格；</li>
	<li>值&nbsp;<code>1</code>&nbsp;代表新鲜橘子；</li>
	<li>值&nbsp;<code>2</code>&nbsp;代表腐烂的橘子。</li>
</ul>

<p>每分钟，腐烂的橘子&nbsp;<strong>周围&nbsp;4 个方向上相邻</strong> 的新鲜橘子都会腐烂。</p>

<p>返回 <em>直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回&nbsp;<code>-1</code></em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0994.Rotting%20Oranges/images/oranges.png" style="height: 137px; width: 650px;" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[2,1,1],[1,1,0],[0,1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[2,1,1],[0,1,1],[1,0,1]]
<strong>输出：</strong>-1
<strong>解释：</strong>左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,2]]
<strong>输出：</strong>0
<strong>解释：</strong>因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>grid[i][j]</code> 仅为&nbsp;<code>0</code>、<code>1</code>&nbsp;或&nbsp;<code>2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们首先遍历一遍整个网格，统计出新鲜橘子的数量，记为 $\textit{cnt}$，并且将所有腐烂的橘子的坐标加入队列 $q$ 中。

接下来，我们进行广度优先搜索，每一轮搜索，我们将队列中的所有腐烂的橘子向四个方向腐烂新鲜橘子，直到队列为空或者新鲜橘子的数量为 $0$ 为止。

最后，如果新鲜橘子的数量为 $0$，则返回当前的轮数，否则返回 $-1$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = 0
        q = deque()
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 2:
                    q.append((i, j))
                elif x == 1:
                    cnt += 1
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        while q and cnt:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                        grid[x][y] = 2
                        q.append((x, y))
                        cnt -= 1
                        if cnt == 0:
                            return ans
        return -1 if cnt else 0
```

#### Java

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                } else if (grid[i][j] == 2) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int ans = 1; !q.isEmpty() && cnt > 0; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                for (int d = 0; d < 4; ++d) {
                    int x = p[0] + dirs[d], y = p[1] + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.offer(new int[] {x, y});
                        if (--cnt == 0) {
                            return ans;
                        }
                    }
                }
            }
        }
        return cnt > 0 ? -1 : 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                } else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }
        const int dirs[5] = {-1, 0, 1, 0, -1};
        for (int ans = 1; q.size() && cnt; ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.emplace(x, y);
                        if (--cnt == 0) {
                            return ans;
                        }
                    }
                }
            }
        }
        return cnt > 0 ? -1 : 0;
    }
};
```

#### Go

```go
func orangesRotting(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := [][2]int{}
	cnt := 0
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				cnt++
			} else if x == 2 {
				q = append(q, [2]int{i, j})
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for ans := 1; len(q) > 0 && cnt > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			for d := 0; d < 4; d++ {
				x, y := p[0]+dirs[d], p[1]+dirs[d+1]
				if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
					grid[x][y] = 2
					q = append(q, [2]int{x, y})
					if cnt--; cnt == 0 {
						return ans
					}
				}
			}
		}
	}
	if cnt > 0 {
		return -1
	}
	return 0
}
```

#### TypeScript

```ts
function orangesRotting(grid: number[][]): number {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const q: number[][] = [];
    let cnt: number = 0;
    for (let i: number = 0; i < m; ++i) {
        for (let j: number = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                cnt++;
            } else if (grid[i][j] === 2) {
                q.push([i, j]);
            }
        }
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (let ans = 1; q.length && cnt; ++ans) {
        const t: number[][] = [];
        for (const [i, j] of q) {
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                    grid[x][y] = 2;
                    t.push([x, y]);
                    if (--cnt === 0) {
                        return ans;
                    }
                }
            }
        }
        q.splice(0, q.length, ...t);
    }
    return cnt > 0 ? -1 : 0;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn oranges_rotting(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut q = VecDeque::new();
        let mut cnt = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    cnt += 1;
                } else if grid[i][j] == 2 {
                    q.push_back((i, j));
                }
            }
        }

        let dirs = [-1, 0, 1, 0, -1];
        for ans in 1.. {
            if q.is_empty() || cnt == 0 {
                break;
            }
            let mut size = q.len();
            for _ in 0..size {
                let (x, y) = q.pop_front().unwrap();
                for d in 0..4 {
                    let nx = x as isize + dirs[d] as isize;
                    let ny = y as isize + dirs[d + 1] as isize;
                    if nx >= 0 && nx < m as isize && ny >= 0 && ny < n as isize {
                        let nx = nx as usize;
                        let ny = ny as usize;
                        if grid[nx][ny] == 1 {
                            grid[nx][ny] = 2;
                            q.push_back((nx, ny));
                            cnt -= 1;
                            if cnt == 0 {
                                return ans;
                            }
                        }
                    }
                }
            }
        }
        if cnt > 0 {
            -1
        } else {
            0
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let q = [];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                cnt++;
            } else if (grid[i][j] === 2) {
                q.push([i, j]);
            }
        }
    }

    const dirs = [-1, 0, 1, 0, -1];
    for (let ans = 1; q.length && cnt; ++ans) {
        let t = [];
        for (const [i, j] of q) {
            for (let d = 0; d < 4; ++d) {
                const x = i + dirs[d];
                const y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                    grid[x][y] = 2;
                    t.push([x, y]);
                    if (--cnt === 0) {
                        return ans;
                    }
                }
            }
        }
        q = [...t];
    }

    return cnt > 0 ? -1 : 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [995. K 连续位的最小翻转次数](https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips){#995}

{{< tabs "995" >}}

{{% tab "python" %}}
```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        ans = flipped = 0
        for i, x in enumerate(nums):
            if i >= k and nums[i - k] == -1:
                flipped ^= 1
            if x == flipped:
                if i + k > len(nums):
                    return -1
                flipped ^= 1
                ans += 1
                nums[i] = -1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k] == -1) {
                flipped ^= 1;
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipped ^= 1;
                ++ans;
                nums[i] = -1;
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
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k] == -1) {
                flipped ^= 1;
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipped ^= 1;
                ++ans;
                nums[i] = -1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minKBitFlips(nums []int, k int) (ans int) {
	flipped := 0
	for i, x := range nums {
		if i >= k && nums[i-k] == -1 {
			flipped ^= 1
		}
		if flipped == x {
			if i+k > len(nums) {
				return -1
			}
			flipped ^= 1
			ans++
			nums[i] = -1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minKBitFlips(nums: number[], k: number): number {
    const n = nums.length;
    let [ans, flipped] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (nums[i - k] === -1) {
            flipped ^= 1;
        }
        if (nums[i] === flipped) {
            if (i + k > n) {
                return -1;
            }
            flipped ^= 1;
            ++ans;
            nums[i] = -1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_k_bit_flips(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let mut flipped = 0;
        let k = k as usize;

        for i in 0..nums.len() {
            if i >= k && nums[i - k] == -1 {
                flipped ^= 1;
            }
            if flipped == nums[i] {
                if i + k > nums.len() {
                    return -1;
                }
                flipped ^= 1;
                ans += 1;
                nums[i] = -1;
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

<p>给定一个二进制数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p><strong>k位翻转</strong> 就是从 <code>nums</code> 中选择一个长度为 <code>k</code> 的 <strong>子数组</strong> ，同时把子数组中的每一个 <code>0</code> 都改成 <code>1</code> ，把子数组中的每一个 <code>1</code> 都改成 <code>0</code> 。</p>

<p>返回数组中不存在 <code>0</code> 所需的最小 <strong>k位翻转</strong> 次数。如果不可能，则返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><strong>子数组</strong> 是数组的 <strong>连续</strong> 部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0], K = 1
<strong>输出：</strong>2
<strong>解释：</strong>先翻转 A[0]，然后翻转 A[2]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,0], K = 2
<strong>输出：</strong>-1
<strong>解释：</strong>无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0,1,0,1,1,0], K = 3
<strong>输出：</strong>3
<strong>解释：</strong>
翻转 A[0],A[1],A[2]:&nbsp;A变成 [1,1,1,1,0,1,1,0]
翻转 A[4],A[5],A[6]:&nbsp;A变成 [1,1,1,1,1,0,0,0]
翻转 A[5],A[6],A[7]:&nbsp;A变成 [1,1,1,1,1,1,1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们注意到，对于若干个连续的元素进行反转，其结果与对这些元素进行反转的次序无关。因此我们可以贪心地考虑每个位置需要进行反转的次数。

我们不妨从左到右处理数组。

假设当前我们需要处理位置 $i$，而位置 $i$ 左侧的元素已经被处理完毕，如果 $i$ 位置的元素为 $0$，那么我们必须进行反转操作，我们需要将 $[i,..i+k-1]$ 区间内的元素进行反转。这里我们用一个差分数组 $d$ 来维护每个位置的反转次数，那么判断当前位置 $i$ 是否需要反转，只需要看 $s = \sum_{j=0}^{i}d[j]$ 以及 $nums[i]$ 的奇偶性，如果 $s$ 与 $nums[i]$ 奇偶性相同，那么位置 $i$ 的元素仍然为 $0$，需要进行反转。此时我们判断一下 $i+k$ 是否超出了数组的长度，如果超出了数组的长度，那么就无法完成目标，返回 $-1$。否则我们令 $d[i]$ 增加 $1$，同时令 $d[i+k]$ 减少 $1$，然后将答案增加 $1$，并且 $s$ 增加 $1$。

这样当我们处理完数组中的所有元素时，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。这里 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        d = [0] * (n + 1)
        ans = s = 0
        for i, x in enumerate(nums):
            s += d[i]
            if s % 2 == x:
                if i + k > n:
                    return -1
                d[i] += 1
                d[i + k] -= 1
                s += 1
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int[] d = new int[n + 1];
        int ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                ++d[i];
                --d[i + k];
                ++s;
                ++ans;
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
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int d[n + 1];
        memset(d, 0, sizeof(d));
        int ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            s += d[i];
            if (s % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                ++d[i];
                --d[i + k];
                ++s;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minKBitFlips(nums []int, k int) (ans int) {
	n := len(nums)
	d := make([]int, n+1)
	s := 0
	for i, x := range nums {
		s += d[i]
		if s%2 == x {
			if i+k > n {
				return -1
			}
			d[i]++
			d[i+k]--
			s++
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minKBitFlips(nums: number[], k: number): number {
    const n = nums.length;
    const d: number[] = Array(n + 1).fill(0);
    let [ans, s] = [0, 0];
    for (let i = 0; i < n; ++i) {
        s += d[i];
        if (s % 2 === nums[i]) {
            if (i + k > n) {
                return -1;
            }
            d[i]++;
            d[i + k]--;
            s++;
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_k_bit_flips(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut d = vec![0; n + 1];
        let mut ans = 0;
        let mut s = 0;
        for i in 0..n {
            s += d[i];
            if s % 2 == nums[i] {
                if i + (k as usize) > n {
                    return -1;
                }
                d[i] += 1;
                d[i + (k as usize)] -= 1;
                s += 1;
                ans += 1;
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：滑动窗口

我们可以用一个变量 $\textit{flipped}$ 来表示当前位置是否翻转，如果 $\textit{flipped}$ 为 $1$，表示当前位置已经翻转，否则表示当前位置未翻转。对于翻转过的位置，我们可以将其值设置为 $-1$，这样我们就可以区分出哪些位置已经翻转过了。

接下来我们从左到右遍历数组，对于每个位置 $i$，如果 $i \geq k$ 且 $i-k$ 位置的元素为 $-1$，那么当前位置的翻转状态应该与前一个位置的翻转状态相反。即 $\textit{flipped} = \textit{flipped} \oplus 1$。如果当前位置的元素与当前位置的翻转状态相同，那么我们需要翻转当前位置，此时我们判断一下 $i+k$ 是否超出了数组的长度，如果超出了数组的长度，那么就无法完成目标，返回 $-1$。否则我们将当前位置的翻转状态取反，同时将答案增加 $1$，并且将当前位置的元素设置为 $-1$。

这样当我们处理完数组中的所有元素时，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        ans = flipped = 0
        for i, x in enumerate(nums):
            if i >= k and nums[i - k] == -1:
                flipped ^= 1
            if x == flipped:
                if i + k > len(nums):
                    return -1
                flipped ^= 1
                ans += 1
                nums[i] = -1
        return ans
```

#### Java

```java
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k] == -1) {
                flipped ^= 1;
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipped ^= 1;
                ++ans;
                nums[i] = -1;
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
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k] == -1) {
                flipped ^= 1;
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipped ^= 1;
                ++ans;
                nums[i] = -1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minKBitFlips(nums []int, k int) (ans int) {
	flipped := 0
	for i, x := range nums {
		if i >= k && nums[i-k] == -1 {
			flipped ^= 1
		}
		if flipped == x {
			if i+k > len(nums) {
				return -1
			}
			flipped ^= 1
			ans++
			nums[i] = -1
		}
	}
	return
}
```

#### TypeScript

```ts
function minKBitFlips(nums: number[], k: number): number {
    const n = nums.length;
    let [ans, flipped] = [0, 0];
    for (let i = 0; i < n; i++) {
        if (nums[i - k] === -1) {
            flipped ^= 1;
        }
        if (nums[i] === flipped) {
            if (i + k > n) {
                return -1;
            }
            flipped ^= 1;
            ++ans;
            nums[i] = -1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_k_bit_flips(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let mut flipped = 0;
        let k = k as usize;

        for i in 0..nums.len() {
            if i >= k && nums[i - k] == -1 {
                flipped ^= 1;
            }
            if flipped == nums[i] {
                if i + k > nums.len() {
                    return -1;
                }
                flipped ^= 1;
                ans += 1;
                nums[i] = -1;
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

# [996. 平方数组的数目](https://leetcode.cn/problems/number-of-squareful-arrays){#996}

{{< tabs "996" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSquarefulPerms(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(1 << n)]
        for j in range(n):
            f[1 << j][j] = 1
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for k in range(n):
                        if (i >> k & 1) and k != j:
                            s = nums[j] + nums[k]
                            t = int(sqrt(s))
                            if t * t == s:
                                f[i][j] += f[i ^ (1 << j)][k]

        ans = sum(f[(1 << n) - 1][j] for j in range(n))
        for v in Counter(nums).values():
            ans //= factorial(v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSquarefulPerms(int[] nums) {
        int n = nums.length;
        int[][] f = new int[1 << n][n];
        for (int j = 0; j < n; ++j) {
            f[1 << j][j] = 1;
        }
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (int k = 0; k < n; ++k) {
                        if ((i >> k & 1) == 1 && k != j) {
                            int s = nums[j] + nums[k];
                            int t = (int) Math.sqrt(s);
                            if (t * t == s) {
                                f[i][j] += f[i ^ (1 << j)][k];
                            }
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += f[(1 << n) - 1][j];
        }
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int[] g = new int[13];
        g[0] = 1;
        for (int i = 1; i < 13; ++i) {
            g[i] = g[i - 1] * i;
        }
        for (int v : cnt.values()) {
            ans /= g[v];
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int f[1 << n][n];
        memset(f, 0, sizeof(f));
        for (int j = 0; j < n; ++j) {
            f[1 << j][j] = 1;
        }
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (int k = 0; k < n; ++k) {
                        if ((i >> k & 1) == 1 && k != j) {
                            int s = nums[j] + nums[k];
                            int t = sqrt(s);
                            if (t * t == s) {
                                f[i][j] += f[i ^ (1 << j)][k];
                            }
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += f[(1 << n) - 1][j];
        }
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int g[13] = {1};
        for (int i = 1; i < 13; ++i) {
            g[i] = g[i - 1] * i;
        }
        for (auto& [_, v] : cnt) {
            ans /= g[v];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSquarefulPerms(nums []int) (ans int) {
	n := len(nums)
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for j := range nums {
		f[1<<j][j] = 1
	}
	for i := 0; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for k := 0; k < n; k++ {
					if i>>k&1 == 1 && k != j {
						s := nums[j] + nums[k]
						t := int(math.Sqrt(float64(s)))
						if t*t == s {
							f[i][j] += f[i^(1<<j)][k]
						}
					}
				}
			}
		}
	}
	for j := 0; j < n; j++ {
		ans += f[(1<<n)-1][j]
	}
	g := [13]int{1}
	for i := 1; i < 13; i++ {
		g[i] = g[i-1] * i
	}
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for _, v := range cnt {
		ans /= g[v]
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

<p>如果一个数组的任意两个相邻元素之和都是 <strong>完全平方数 </strong>，则该数组称为 <strong>平方数组 </strong>。</p>

<p>给定一个整数数组 <code>nums</code>，返回所有属于 <strong>平方数组 </strong>的 <code>nums</code> 的排列数量。</p>

<p>如果存在某个索引 <code>i</code> 使得 <code>perm1[i] != perm2[i]</code>，则认为两个排列 <code>perm1</code> 和 <code>perm2</code> 不同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,17,8]
<strong>输出：</strong>2
<strong>解释：</strong>[1,8,17] 和 [17,8,1] 是有效的排列。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 12</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制状态压缩 + 动态规划

注意到，数组 $nums$ 的长度 $n$ 不超过 $12$，因此我们可以用一个二进制数表示当前所选的数字的状态，若第 $i$ 位为 $1$，则表示当前选择了第 $i$ 个数字，否则表示当前没有选择第 $i$ 个数字。

我们定义 $f[i][j]$ 表示当前所选的数字的状态为 $i$，且最后一个数字为 $nums[j]$ 的方案数。那么答案就是 $\sum_{j=0}^{n-1} f[2^n-1][j]$。由于最后求解的是排列数，因此还需要除以每个数字出现的次数的阶乘。

接下来，我们考虑如何进行状态转移。

假设当前所选的数字的状态为 $i$，最后一个数字为 $nums[j]$，那么我们可以枚举 $i$ 的每一位为 $1$ 的数字作为倒数第二个数，不妨设为 $nums[k]$，那么我们只需要判断 $nums[j]+nums[k]$ 是否为完全平方数即可，若是，方案数 $f[i][j]$ 就可以加上 $f[i \oplus 2^j][k]$，其中 $i \oplus 2^j$ 表示将 $i$ 的第 $j$ 位取反，即表示将 $nums[j]$ 从当前所选的数字中去除。

最后，我们还需要除以每个数字出现的次数的阶乘，因为我们在枚举 $i$ 的每一位为 $1$ 的数字时，可能会重复计算某些排列，因此需要除以每个数字出现的次数的阶乘。

时间复杂度 $O(2^n \times n^2)，空间复杂度 O(2^n \times n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSquarefulPerms(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(1 << n)]
        for j in range(n):
            f[1 << j][j] = 1
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for k in range(n):
                        if (i >> k & 1) and k != j:
                            s = nums[j] + nums[k]
                            t = int(sqrt(s))
                            if t * t == s:
                                f[i][j] += f[i ^ (1 << j)][k]

        ans = sum(f[(1 << n) - 1][j] for j in range(n))
        for v in Counter(nums).values():
            ans //= factorial(v)
        return ans
```

#### Java

```java
class Solution {
    public int numSquarefulPerms(int[] nums) {
        int n = nums.length;
        int[][] f = new int[1 << n][n];
        for (int j = 0; j < n; ++j) {
            f[1 << j][j] = 1;
        }
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (int k = 0; k < n; ++k) {
                        if ((i >> k & 1) == 1 && k != j) {
                            int s = nums[j] + nums[k];
                            int t = (int) Math.sqrt(s);
                            if (t * t == s) {
                                f[i][j] += f[i ^ (1 << j)][k];
                            }
                        }
                    }
                }
            }
        }
        long ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += f[(1 << n) - 1][j];
        }
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int[] g = new int[13];
        g[0] = 1;
        for (int i = 1; i < 13; ++i) {
            g[i] = g[i - 1] * i;
        }
        for (int v : cnt.values()) {
            ans /= g[v];
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int f[1 << n][n];
        memset(f, 0, sizeof(f));
        for (int j = 0; j < n; ++j) {
            f[1 << j][j] = 1;
        }
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (int k = 0; k < n; ++k) {
                        if ((i >> k & 1) == 1 && k != j) {
                            int s = nums[j] + nums[k];
                            int t = sqrt(s);
                            if (t * t == s) {
                                f[i][j] += f[i ^ (1 << j)][k];
                            }
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += f[(1 << n) - 1][j];
        }
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int g[13] = {1};
        for (int i = 1; i < 13; ++i) {
            g[i] = g[i - 1] * i;
        }
        for (auto& [_, v] : cnt) {
            ans /= g[v];
        }
        return ans;
    }
};
```

#### Go

```go
func numSquarefulPerms(nums []int) (ans int) {
	n := len(nums)
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for j := range nums {
		f[1<<j][j] = 1
	}
	for i := 0; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for k := 0; k < n; k++ {
					if i>>k&1 == 1 && k != j {
						s := nums[j] + nums[k]
						t := int(math.Sqrt(float64(s)))
						if t*t == s {
							f[i][j] += f[i^(1<<j)][k]
						}
					}
				}
			}
		}
	}
	for j := 0; j < n; j++ {
		ans += f[(1<<n)-1][j]
	}
	g := [13]int{1}
	for i := 1; i < 13; i++ {
		g[i] = g[i-1] * i
	}
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for _, v := range cnt {
		ans /= g[v]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [997. 找到小镇的法官](https://leetcode.cn/problems/find-the-town-judge){#997}

{{< tabs "997" >}}

{{% tab "python" %}}
```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        cnt1 = [0] * (n + 1)
        cnt2 = [0] * (n + 1)
        for a, b in trust:
            cnt1[a] += 1
            cnt2[b] += 1
        for i in range(1, n + 1):
            if cnt1[i] == 0 and cnt2[i] == n - 1:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] cnt1 = new int[n + 1];
        int[] cnt2 = new int[n + 1];
        for (var t : trust) {
            int a = t[0], b = t[1];
            ++cnt1[a];
            ++cnt2[b];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt1[i] == 0 && cnt2[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt1(n + 1);
        vector<int> cnt2(n + 1);
        for (auto& t : trust) {
            int a = t[0], b = t[1];
            ++cnt1[a];
            ++cnt2[b];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt1[i] == 0 && cnt2[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findJudge(n int, trust [][]int) int {
	cnt1 := make([]int, n+1)
	cnt2 := make([]int, n+1)
	for _, t := range trust {
		a, b := t[0], t[1]
		cnt1[a]++
		cnt2[b]++
	}
	for i := 1; i <= n; i++ {
		if cnt1[i] == 0 && cnt2[i] == n-1 {
			return i
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findJudge(n: number, trust: number[][]): number {
    const cnt1: number[] = new Array(n + 1).fill(0);
    const cnt2: number[] = new Array(n + 1).fill(0);
    for (const [a, b] of trust) {
        ++cnt1[a];
        ++cnt2[b];
    }
    for (let i = 1; i <= n; ++i) {
        if (cnt1[i] === 0 && cnt2[i] === n - 1) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut cnt1 = vec![0; (n + 1) as usize];
        let mut cnt2 = vec![0; (n + 1) as usize];

        for t in trust.iter() {
            let a = t[0] as usize;
            let b = t[1] as usize;
            cnt1[a] += 1;
            cnt2[b] += 1;
        }

        for i in 1..=n as usize {
            if cnt1[i] == 0 && cnt2[i] == (n as usize) - 1 {
                return i as i32;
            }
        }

        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>小镇里有 <code>n</code> 个人，按从 <code>1</code> 到 <code>n</code> 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。</p>

<p>如果小镇法官真的存在，那么：</p>

<ol>
	<li>小镇法官不会信任任何人。</li>
	<li>每个人（除了小镇法官）都信任这位小镇法官。</li>
	<li>只有一个人同时满足属性 <strong>1</strong> 和属性 <strong>2</strong> 。</li>
</ol>

<p>给你一个数组 <code>trust</code> ，其中 <code>trust[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示编号为 <code>a<sub>i</sub></code> 的人信任编号为 <code>b<sub>i</sub></code> 的人。</p>

<p>如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, trust = [[1,2]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, trust = [[1,3],[2,3]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3, trust = [[1,3],[2,3],[3,1]]
<strong>输出：</strong>-1
</pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= trust.length &lt;= 10<sup>4</sup></code></li>
	<li><code>trust[i].length == 2</code></li>
	<li><code>trust</code> 中的所有<code>trust[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> <strong>互不相同</strong></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们创建两个长度为 $n + 1$ 的数组 $cnt1$ 和 $cnt2$，分别表示每个人信任的人数和被信任的人数。

接下来，我们遍历数组 $trust$，对于每一项 $[a_i, b_i]$，我们将 $cnt1[a_i]$ 和 $cnt2[b_i]$ 分别加 $1$。

最后，我们在 $[1,..n]$ 范围内枚举每个人 $i$，如果 $cnt1[i] = 0$ 且 $cnt2[i] = n - 1$，则说明 $i$ 是小镇法官，返回 $i$ 即可。否则遍历结束后，返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $trust$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        cnt1 = [0] * (n + 1)
        cnt2 = [0] * (n + 1)
        for a, b in trust:
            cnt1[a] += 1
            cnt2[b] += 1
        for i in range(1, n + 1):
            if cnt1[i] == 0 and cnt2[i] == n - 1:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] cnt1 = new int[n + 1];
        int[] cnt2 = new int[n + 1];
        for (var t : trust) {
            int a = t[0], b = t[1];
            ++cnt1[a];
            ++cnt2[b];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt1[i] == 0 && cnt2[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt1(n + 1);
        vector<int> cnt2(n + 1);
        for (auto& t : trust) {
            int a = t[0], b = t[1];
            ++cnt1[a];
            ++cnt2[b];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt1[i] == 0 && cnt2[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func findJudge(n int, trust [][]int) int {
	cnt1 := make([]int, n+1)
	cnt2 := make([]int, n+1)
	for _, t := range trust {
		a, b := t[0], t[1]
		cnt1[a]++
		cnt2[b]++
	}
	for i := 1; i <= n; i++ {
		if cnt1[i] == 0 && cnt2[i] == n-1 {
			return i
		}
	}
	return -1
}
```

#### TypeScript

```ts
function findJudge(n: number, trust: number[][]): number {
    const cnt1: number[] = new Array(n + 1).fill(0);
    const cnt2: number[] = new Array(n + 1).fill(0);
    for (const [a, b] of trust) {
        ++cnt1[a];
        ++cnt2[b];
    }
    for (let i = 1; i <= n; ++i) {
        if (cnt1[i] === 0 && cnt2[i] === n - 1) {
            return i;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut cnt1 = vec![0; (n + 1) as usize];
        let mut cnt2 = vec![0; (n + 1) as usize];

        for t in trust.iter() {
            let a = t[0] as usize;
            let b = t[1] as usize;
            cnt1[a] += 1;
            cnt2[b] += 1;
        }

        for i in 1..=n as usize {
            if cnt1[i] == 0 && cnt2[i] == (n as usize) - 1 {
                return i as i32;
            }
        }

        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [998. 最大二叉树 II](https://leetcode.cn/problems/maximum-binary-tree-ii){#998}

{{< tabs "998" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoMaxTree(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        if root.val < val:
            return TreeNode(val, root)
        curr = root
        node = TreeNode(val)
        while curr.right and curr.right.val > val:
            curr = curr.right
        node.left = curr.right
        curr.right = node
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root.val < val) {
            return new TreeNode(val, root, null);
        }
        TreeNode curr = root;
        TreeNode node = new TreeNode(val);
        while (curr.right != null && curr.right.val > val) {
            curr = curr.right;
        }
        node.left = curr.right;
        curr.right = node;
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root->val < val) return new TreeNode(val, root, nullptr);
        TreeNode* curr = root;
        TreeNode* node = new TreeNode(val);
        while (curr->right && curr->right->val > val) curr = curr->right;
        node->left = curr->right;
        curr->right = node;
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
func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	if root.Val < val {
		return &TreeNode{val, root, nil}
	}
	node := &TreeNode{Val: val}
	curr := root
	for curr.Right != nil && curr.Right.Val > val {
		curr = curr.Right
	}
	node.Left = curr.Right
	curr.Right = node
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

function insertIntoMaxTree(root: TreeNode | null, val: number): TreeNode | null {
    if (root.val < val) {
        return new TreeNode(val, root);
    }
    const node = new TreeNode(val);
    let curr = root;
    while (curr.right && curr.right.val > val) {
        curr = curr.right;
    }
    node.left = curr.right;
    curr.right = node;
    return root;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn insert_into_max_tree(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() || root.as_ref().unwrap().as_ref().borrow().val < val {
            return Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: root.take(),
                right: None,
            })));
        }
        {
            let mut root = root.as_ref().unwrap().as_ref().borrow_mut();
            root.right = Self::insert_into_max_tree(root.right.take(), val);
        }
        root
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val) {
    if (!root || root->val < val) {
        struct TreeNode* res = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        res->val = val;
        res->left = root;
        res->right = NULL;
        return res;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>最大树</strong> 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。</p>

<p>给你最大树的根节点 <code>root</code> 和一个整数 <code>val</code> 。</p>

<p>就像 <a href="https://leetcode.cn/problems/maximum-binary-tree/" target="_blank">之前的问题</a> 那样，给定的树是利用 <code>Construct(a)</code>&nbsp;例程从列表&nbsp;<code>a</code>（<code>root = Construct(a)</code>）递归地构建的：</p>

<ul>
	<li>如果 <code>a</code> 为空，返回&nbsp;<code>null</code> 。</li>
	<li>否则，令&nbsp;<code>a[i]</code> 作为 <code>a</code> 的最大元素。创建一个值为&nbsp;<code>a[i]</code>&nbsp;的根节点 <code>root</code> 。</li>
	<li><code>root</code>&nbsp;的左子树将被构建为&nbsp;<code>Construct([a[0], a[1], ..., a[i - 1]])</code> 。</li>
	<li><code>root</code>&nbsp;的右子树将被构建为&nbsp;<code>Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]])</code> 。</li>
	<li>返回&nbsp;<code>root</code> 。</li>
</ul>

<p>请注意，题目没有直接给出 <code>a</code> ，只是给出一个根节点&nbsp;<code>root = Construct(a)</code> 。</p>

<p>假设 <code>b</code> 是 <code>a</code> 的副本，并在末尾附加值 <code>val</code>。题目数据保证 <code>b</code> 中的值互不相同。</p>

<p>返回&nbsp;<code>Construct(b)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-1-1.png" style="height: 160px; width: 159px;" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-1-2.png" style="height: 160px; width: 169px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [4,1,3,null,null,2], val = 5
<strong>输出：</strong>[5,4,null,1,3,null,null,2]
<strong>解释：</strong>a = [1,4,2,3], b = [1,4,2,3,5]</pre>

<p><strong>示例 2：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-2-1.png" style="height: 160px; width: 180px;" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-2-2.png" style="height: 160px; width: 214px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [5,2,4,null,1], val = 3
<strong>输出：</strong>[5,2,4,null,1,null,3]
<strong>解释：</strong>a = [2,1,5,4], b = [2,1,5,4,3]</pre>

<p><strong>示例 3：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-3-1.png" style="height: 160px; width: 180px;" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0998.Maximum%20Binary%20Tree%20II/images/maximum-binary-tree-3-2.png" style="height: 160px; width: 201px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [5,2,3,null,1], val = 4
<strong>输出：</strong>[5,2,4,null,1,3]
<strong>解释：</strong>a = [2,1,5,3], b = [2,1,5,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 100]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
	<li>树中的所有值 <strong>互不相同</strong></li>
	<li><code>1 &lt;= val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

如果 $val$ 是最大数，那么将 $val$ 作为新的根节点，$root$ 作为新的根节点的左子树。

如果 $val$ 不是最大数，由于 $val$ 是在最后追加的数，那么一定是在 $root$ 的右边，所以将 $val$ 作为新节点插入 $root$ 的右子树即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树的节点数。

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
    def insertIntoMaxTree(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        if root is None or root.val < val:
            return TreeNode(val, root)
        root.right = self.insertIntoMaxTree(root.right, val)
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null || root.val < val) {
            return new TreeNode(val, root, null);
        }
        root.right = insertIntoMaxTree(root.right, val);
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root || root->val < val) return new TreeNode(val, root, nullptr);
        root->right = insertIntoMaxTree(root->right, val);
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
func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	if root == nil || root.Val < val {
		return &TreeNode{val, root, nil}
	}
	root.Right = insertIntoMaxTree(root.Right, val)
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

function insertIntoMaxTree(root: TreeNode | null, val: number): TreeNode | null {
    if (!root || root.val < val) {
        return new TreeNode(val, root);
    }
    root.right = insertIntoMaxTree(root.right, val);
    return root;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn insert_into_max_tree(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() || root.as_ref().unwrap().as_ref().borrow().val < val {
            return Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: root.take(),
                right: None,
            })));
        }
        {
            let mut root = root.as_ref().unwrap().as_ref().borrow_mut();
            root.right = Self::insert_into_max_tree(root.right.take(), val);
        }
        root
    }
}
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val) {
    if (!root || root->val < val) {
        struct TreeNode* res = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        res->val = val;
        res->left = root;
        res->right = NULL;
        return res;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代

搜索右子树，找到 $curr.val \gt val \gt curr.right.val$ 的节点，然后创建新的节点 $node$，把 $node.left$ 指向 $curr.right$，然后 $curr.right$ 指向 $node$。

最后返回 $root$。

时间复杂度 $O(n)$，其中 $n$ 是树的节点数。空间复杂度 $O(1)$。

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
    def insertIntoMaxTree(
        self, root: Optional[TreeNode], val: int
    ) -> Optional[TreeNode]:
        if root.val < val:
            return TreeNode(val, root)
        curr = root
        node = TreeNode(val)
        while curr.right and curr.right.val > val:
            curr = curr.right
        node.left = curr.right
        curr.right = node
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root.val < val) {
            return new TreeNode(val, root, null);
        }
        TreeNode curr = root;
        TreeNode node = new TreeNode(val);
        while (curr.right != null && curr.right.val > val) {
            curr = curr.right;
        }
        node.left = curr.right;
        curr.right = node;
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root->val < val) return new TreeNode(val, root, nullptr);
        TreeNode* curr = root;
        TreeNode* node = new TreeNode(val);
        while (curr->right && curr->right->val > val) curr = curr->right;
        node->left = curr->right;
        curr->right = node;
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
func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	if root.Val < val {
		return &TreeNode{val, root, nil}
	}
	node := &TreeNode{Val: val}
	curr := root
	for curr.Right != nil && curr.Right.Val > val {
		curr = curr.Right
	}
	node.Left = curr.Right
	curr.Right = node
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

function insertIntoMaxTree(root: TreeNode | null, val: number): TreeNode | null {
    if (root.val < val) {
        return new TreeNode(val, root);
    }
    const node = new TreeNode(val);
    let curr = root;
    while (curr.right && curr.right.val > val) {
        curr = curr.right;
    }
    node.left = curr.right;
    curr.right = node;
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [999. 可以被一步捕获的棋子数](https://leetcode.cn/problems/available-captures-for-rook){#999}

{{< tabs "999" >}}

{{% tab "python" %}}
```python
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        dirs = (-1, 0, 1, 0, -1)
        n = len(board)
        for i in range(n):
            for j in range(n):
                if board[i][j] == "R":
                    ans = 0
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        while 0 <= x < n and 0 <= y < n and board[x][y] != "B":
                            if board[x][y] == "p":
                                ans += 1
                                break
                            x, y = x + a, y + b
                    return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numRookCaptures(char[][] board) {
        final int[] dirs = {-1, 0, 1, 0, -1};
        int n = board.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    int ans = 0;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B') {
                            if (board[x][y] == 'p') {
                                ++ans;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const int dirs[5] = {-1, 0, 1, 0, -1};
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    int ans = 0;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B') {
                            if (board[x][y] == 'p') {
                                ++ans;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numRookCaptures(board [][]byte) (ans int) {
    dirs := []int{-1, 0, 1, 0, -1}
    n := len(board)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == 'R' {
                for k := 0; k < 4; k++ {
                    x, y := i + dirs[k], j + dirs[k+1]
                    for x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B' {
                        if board[x][y] == 'p' {
                            ans++
                            break
                        }
                        x += dirs[k]
                        y += dirs[k+1]
                    }
                }
                return
            }
        }
    }
    return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numRookCaptures(board: string[][]): number {
    const dirs = [-1, 0, 1, 0, -1];
    const n = board.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'R') {
                let ans = 0;
                for (let k = 0; k < 4; k++) {
                    let [x, y] = [i + dirs[k], j + dirs[k + 1]];
                    while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] !== 'B') {
                        if (board[x][y] === 'p') {
                            ans++;
                            break;
                        }
                        x += dirs[k];
                        y += dirs[k + 1];
                    }
                }
                return ans;
            }
        }
    }
    return 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let dirs = [-1, 0, 1, 0, -1];
        let n = board.len();
        for i in 0..n {
            for j in 0..n {
                if board[i][j] == 'R' {
                    let mut ans = 0;
                    for k in 0..4 {
                        let mut x = i as i32 + dirs[k];
                        let mut y = j as i32 + dirs[k + 1];
                        while x >= 0
                            && x < n as i32
                            && y >= 0
                            && y < n as i32
                            && board[x as usize][y as usize] != 'B'
                        {
                            if board[x as usize][y as usize] == 'p' {
                                ans += 1;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个&nbsp;<code>8 x 8</code> 的棋盘，<strong>只有一个</strong> 白色的车，用字符 <code>'R'</code> 表示。棋盘上还可能存在白色的象&nbsp;<code>'B'</code>&nbsp;以及黑色的卒&nbsp;<code>'p'</code>。空方块用字符 <code>'.'</code>&nbsp;表示。</p>

<p>车可以按水平或竖直方向（上，下，左，右）移动任意个方格直到它遇到另一个棋子或棋盘的边界。如果它能够在一次移动中移动到棋子的方格，则能够 <strong>吃掉</strong> 棋子。</p>

<p>注意：车不能穿过其它棋子，比如象和卒。这意味着如果有其它棋子挡住了路径，车就不能够吃掉棋子。</p>

<p>返回白车 <strong>攻击</strong>&nbsp;范围内 <strong>兵的数量</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0999.Available%20Captures%20for%20Rook/images/1253_example_1_improved.png" style="height: 305px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释：
</strong>在本例中，车能够吃掉所有的卒。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0999.Available%20Captures%20for%20Rook/images/1253_example_2_improved.png" style="height: 306px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>0
<strong>解释：
</strong>象阻止了车吃掉任何卒。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0999.Available%20Captures%20for%20Rook/images/1253_example_3_improved.png" style="height: 305px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
<strong>输出：</strong>3
<strong>解释： </strong>
车可以吃掉位置 b5，d6 和 f5 的卒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>board.length == 8</code></li>
	<li><code>board[i].length == 8</code></li>
	<li><code>board[i][j]</code> 可以是&nbsp;<code>'R'</code>，<code>'.'</code>，<code>'B'</code>&nbsp;或&nbsp;<code>'p'</code></li>
	<li>只有一个格子上存在&nbsp;<code>board[i][j] == 'R'</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先遍历棋盘，找到车的位置 $(i, j)$，然后从 $(i, j)$ 出发，向上下左右四个方向遍历：

-   如果不是边界且不是象，则继续向前走；
-   如果是卒，则答案加一，并停止该方向的遍历。

遍历完四个方向后，即可得到答案。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是棋盘的行数和列数，本题中 $m = n = 8$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        dirs = (-1, 0, 1, 0, -1)
        n = len(board)
        for i in range(n):
            for j in range(n):
                if board[i][j] == "R":
                    ans = 0
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        while 0 <= x < n and 0 <= y < n and board[x][y] != "B":
                            if board[x][y] == "p":
                                ans += 1
                                break
                            x, y = x + a, y + b
                    return ans
```

#### Java

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        final int[] dirs = {-1, 0, 1, 0, -1};
        int n = board.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    int ans = 0;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B') {
                            if (board[x][y] == 'p') {
                                ++ans;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        const int dirs[5] = {-1, 0, 1, 0, -1};
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    int ans = 0;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B') {
                            if (board[x][y] == 'p') {
                                ++ans;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func numRookCaptures(board [][]byte) (ans int) {
    dirs := []int{-1, 0, 1, 0, -1}
    n := len(board)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == 'R' {
                for k := 0; k < 4; k++ {
                    x, y := i + dirs[k], j + dirs[k+1]
                    for x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'B' {
                        if board[x][y] == 'p' {
                            ans++
                            break
                        }
                        x += dirs[k]
                        y += dirs[k+1]
                    }
                }
                return
            }
        }
    }
    return
}
```

#### TypeScript

```ts
function numRookCaptures(board: string[][]): number {
    const dirs = [-1, 0, 1, 0, -1];
    const n = board.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === 'R') {
                let ans = 0;
                for (let k = 0; k < 4; k++) {
                    let [x, y] = [i + dirs[k], j + dirs[k + 1]];
                    while (x >= 0 && x < n && y >= 0 && y < n && board[x][y] !== 'B') {
                        if (board[x][y] === 'p') {
                            ans++;
                            break;
                        }
                        x += dirs[k];
                        y += dirs[k + 1];
                    }
                }
                return ans;
            }
        }
    }
    return 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let dirs = [-1, 0, 1, 0, -1];
        let n = board.len();
        for i in 0..n {
            for j in 0..n {
                if board[i][j] == 'R' {
                    let mut ans = 0;
                    for k in 0..4 {
                        let mut x = i as i32 + dirs[k];
                        let mut y = j as i32 + dirs[k + 1];
                        while x >= 0
                            && x < n as i32
                            && y >= 0
                            && y < n as i32
                            && board[x as usize][y as usize] != 'B'
                        {
                            if board[x as usize][y as usize] == 'p' {
                                ans += 1;
                                break;
                            }
                            x += dirs[k];
                            y += dirs[k + 1];
                        }
                    }
                    return ans;
                }
            }
        }
        0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

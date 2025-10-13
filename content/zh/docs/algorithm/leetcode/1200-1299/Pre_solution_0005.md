---
title: "1240_铺瓷砖"
date: 2025-10-08T18:37:06+08:00
weight: 5
tags: [前缀和, 动态规划, 哈希表, 回溯, 图, 多线程, 字符串, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 滑动窗口, 设计, 贪心]
---

{{< markmap >}}
### [1240_铺瓷砖](#1240)
#### [回溯](#1240)
### [1241_每个帖子的评论数 🔒](#1241)
#### [数据库](#1241)
### [1242_多线程网页爬虫 🔒](#1242)
#### [深度优先搜索](#1242)
#### [广度优先搜索](#1242)
#### [多线程](#1242)
### [1243_数组变换 🔒](#1243)
#### [数组](#1243)
#### [模拟](#1243)
### [1244_力扣排行榜 🔒](#1244)
#### [设计](#1244)
#### [哈希表](#1244)
#### [排序](#1244)
### [1245_树的直径 🔒](#1245)
#### [树](#1245)
#### [深度优先搜索](#1245)
#### [广度优先搜索](#1245)
#### [图](#1245)
#### [拓扑排序](#1245)
### [1246_删除回文子数组 🔒](#1246)
#### [数组](#1246)
#### [动态规划](#1246)
### [1247_交换字符使得字符串相同](#1247)
#### [贪心](#1247)
#### [数学](#1247)
#### [字符串](#1247)
### [1248_统计「优美子数组」](#1248)
#### [数组](#1248)
#### [哈希表](#1248)
#### [数学](#1248)
#### [前缀和](#1248)
#### [滑动窗口](#1248)
### [1249_移除无效的括号](#1249)
#### [栈](#1249)
#### [字符串](#1249)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1240_铺瓷砖
___
#### 回溯
---
### 1241_每个帖子的评论数 🔒
___
#### 数据库
---
### 1242_多线程网页爬虫 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 多线程
---
### 1243_数组变换 🔒
___
#### 数组
___
#### 模拟
---
### 1244_力扣排行榜 🔒
___
#### 设计
___
#### 哈希表
___
#### 排序
---
### 1245_树的直径 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 1246_删除回文子数组 🔒
___
#### 数组
___
#### 动态规划
---
### 1247_交换字符使得字符串相同
___
#### 贪心
___
#### 数学
___
#### 字符串
---
### 1248_统计「优美子数组」
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 前缀和
___
#### 滑动窗口
---
### 1249_移除无效的括号
___
#### 栈
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 回溯 | 图 | 多线程 |
| 字符串 | 广度优先搜索 | 拓扑排序 |
| 排序 | 数学 | 数据库 |
| 数组 | 栈 | 树 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 设计 | 贪心 |  |

# [1240. 铺瓷砖](https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares){#1240}

{{< tabs "1240" >}}

{{% tab "python" %}}
```python
class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        def dfs(i: int, j: int, t: int):
            nonlocal ans
            if j == m:
                i += 1
                j = 0
            if i == n:
                ans = t
                return
            if filled[i] >> j & 1:
                dfs(i, j + 1, t)
            elif t + 1 < ans:
                r = c = 0
                for k in range(i, n):
                    if filled[k] >> j & 1:
                        break
                    r += 1
                for k in range(j, m):
                    if filled[i] >> k & 1:
                        break
                    c += 1
                mx = min(r, c)
                for x in range(i, i + mx):
                    for y in range(j, j + mx):
                        filled[x] |= 1 << y
                for w in range(mx, 0, -1):
                    dfs(i, j + w, t + 1)
                    for k in range(w):
                        filled[i + w - 1] ^= 1 << (j + k)
                        if k < w - 1:
                            filled[i + k] ^= 1 << (j + w - 1)

        ans = n * m
        filled = [0] * n
        dfs(0, 0, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int m;
    private int[] filled;
    private int ans;

    public int tilingRectangle(int n, int m) {
        this.n = n;
        this.m = m;
        ans = n * m;
        filled = new int[n];
        dfs(0, 0, 0);
        return ans;
    }

    private void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j & 1) == 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if ((filled[k] >> j & 1) == 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if ((filled[i] >> k & 1) == 1) {
                    break;
                }
                ++c;
            }
            int mx = Math.min(r, c);
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (int w = mx; w > 0; --w) {
                dfs(i, j + w, t + 1);
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int tilingRectangle(int n, int m) {
        memset(filled, 0, sizeof(filled));
        this->n = n;
        this->m = m;
        ans = n * m;
        dfs(0, 0, 0);
        return ans;
    }

private:
    int filled[13];
    int n, m;
    int ans;

    void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if (filled[i] >> j & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if (filled[k] >> j & 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if (filled[i] >> k & 1) {
                    break;
                }
                ++c;
            }
            int mx = min(r, c);
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (int w = mx; w; --w) {
                dfs(i, j + w, t + 1);
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tilingRectangle(n int, m int) int {
	ans := n * m
	filled := make([]int, n)
	var dfs func(i, j, t int)
	dfs = func(i, j, t int) {
		if j == m {
			i++
			j = 0
		}
		if i == n {
			ans = t
			return
		}
		if filled[i]>>j&1 == 1 {
			dfs(i, j+1, t)
		} else if t+1 < ans {
			var r, c int
			for k := i; k < n; k++ {
				if filled[k]>>j&1 == 1 {
					break
				}
				r++
			}
			for k := j; k < m; k++ {
				if filled[i]>>k&1 == 1 {
					break
				}
				c++
			}
			mx := min(r, c)
			for x := i; x < i+mx; x++ {
				for y := j; y < j+mx; y++ {
					filled[x] |= 1 << y
				}
			}
			for w := mx; w > 0; w-- {
				dfs(i, j+w, t+1)
				for k := 0; k < w; k++ {
					filled[i+w-1] ^= 1 << (j + k)
					if k < w-1 {
						filled[i+k] ^= 1 << (j + w - 1)
					}
				}
			}
		}
	}
	dfs(0, 0, 0)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tilingRectangle(n: number, m: number): number {
    let ans = n * m;
    const filled: number[] = new Array(n).fill(0);
    const dfs = (i: number, j: number, t: number) => {
        if (j === m) {
            ++i;
            j = 0;
        }
        if (i === n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j) & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            let [r, c] = [0, 0];
            for (let k = i; k < n; ++k) {
                if ((filled[k] >> j) & 1) {
                    break;
                }
                ++r;
            }
            for (let k = j; k < m; ++k) {
                if ((filled[i] >> k) & 1) {
                    break;
                }
                ++c;
            }
            const mx = Math.min(r, c);
            for (let x = i; x < i + mx; ++x) {
                for (let y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (let w = mx; w > 0; --w) {
                dfs(i, j + w, t + 1);
                for (let k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    };
    dfs(0, 0, 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个大小为&nbsp;<code>n</code>&nbsp;x&nbsp;<code>m</code>&nbsp;的长方形，返回贴满矩形所需的整数边正方形的最小数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1240.Tiling%20a%20Rectangle%20with%20the%20Fewest%20Squares/images/sample_11_1592.png" style="height: 106px; width: 154px;" /></p>

<pre>
<strong>输入：</strong>n = 2, m = 3
<strong>输出：</strong>3
<code><strong>解释：</strong>需要<strong> </strong>3</code> 个正方形来覆盖长方形。
<code>     2</code> 个 <code>1x1 的正方形</code>
<code>     1</code> 个 <code>2x2 的正方形</code></pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1240.Tiling%20a%20Rectangle%20with%20the%20Fewest%20Squares/images/sample_22_1592.png" style="height: 126px; width: 224px;" /></p>

<pre>
<strong>输入：</strong>n = 5, m = 8
<strong>输出：</strong>5
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1240.Tiling%20a%20Rectangle%20with%20the%20Fewest%20Squares/images/sample_33_1592.png" style="height: 189px; width: 224px;" /></p>

<pre>
<strong>输入：</strong>n = 11, m = 13
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 13</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归回溯 + 状态压缩

我们可以按位置进行递归回溯，过程中我们用一个变量 $t$ 记录当前使用的瓷砖数。

-   如果 $j = m$，即第 $i$ 行已经被完全填充，则递归到下一行，即 $(i + 1, 0)$。
-   如果 $i = n$，则表示所有位置都已经被填充，我们更新答案并返回。
-   如果当前位置 $(i, j)$ 已经被填充，则直接递归到下一个位置 $(i, j + 1)$。
-   否则，我们枚举当前位置 $(i, j)$ 可以填充的最大正方形的边长 $w$，并将当前位置 $(i, j)$ 到 $(i + w - 1, j + w - 1)$ 的位置全部填充，然后递归到下一个位置 $(i, j + w)$。在回溯时，我们需要将当前位置 $(i, j)$ 到 $(i + w - 1, j + w - 1)$ 的位置全部清空。

由于每个位置只有两种状态：填充或者未填充，因此我们可以使用一个整数来表示当前位置的状态。我们使用一个长度为 $n$ 的整数数组 $filled$，其中 $filled[i]$ 表示第 $i$ 行的状态。如果 $filled[i]$ 的第 $j$ 位为 $1$，则表示第 $i$ 行第 $j$ 列已经被填充，否则表示未填充。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        def dfs(i: int, j: int, t: int):
            nonlocal ans
            if j == m:
                i += 1
                j = 0
            if i == n:
                ans = t
                return
            if filled[i] >> j & 1:
                dfs(i, j + 1, t)
            elif t + 1 < ans:
                r = c = 0
                for k in range(i, n):
                    if filled[k] >> j & 1:
                        break
                    r += 1
                for k in range(j, m):
                    if filled[i] >> k & 1:
                        break
                    c += 1
                mx = r if r < c else c
                for w in range(1, mx + 1):
                    for k in range(w):
                        filled[i + w - 1] |= 1 << (j + k)
                        filled[i + k] |= 1 << (j + w - 1)
                    dfs(i, j + w, t + 1)
                for x in range(i, i + mx):
                    for y in range(j, j + mx):
                        filled[x] ^= 1 << y

        ans = n * m
        filled = [0] * n
        dfs(0, 0, 0)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int m;
    private int[] filled;
    private int ans;

    public int tilingRectangle(int n, int m) {
        this.n = n;
        this.m = m;
        ans = n * m;
        filled = new int[n];
        dfs(0, 0, 0);
        return ans;
    }

    private void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j & 1) == 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if ((filled[k] >> j & 1) == 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if ((filled[i] >> k & 1) == 1) {
                    break;
                }
                ++c;
            }
            int mx = Math.min(r, c);
            for (int w = 1; w <= mx; ++w) {
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] |= 1 << (j + k);
                    filled[i + k] |= 1 << (j + w - 1);
                }
                dfs(i, j + w, t + 1);
            }
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] ^= 1 << y;
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tilingRectangle(int n, int m) {
        memset(filled, 0, sizeof(filled));
        this->n = n;
        this->m = m;
        ans = n * m;
        dfs(0, 0, 0);
        return ans;
    }

private:
    int filled[13];
    int n, m;
    int ans;

    void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if (filled[i] >> j & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if (filled[k] >> j & 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if (filled[i] >> k & 1) {
                    break;
                }
                ++c;
            }
            int mx = min(r, c);
            for (int w = 1; w <= mx; ++w) {
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] |= 1 << (j + k);
                    filled[i + k] |= 1 << (j + w - 1);
                }
                dfs(i, j + w, t + 1);
            }
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] ^= 1 << y;
                }
            }
        }
    }
};
```

#### Go

```go
func tilingRectangle(n int, m int) int {
	ans := n * m
	filled := make([]int, n)
	var dfs func(i, j, t int)
	dfs = func(i, j, t int) {
		if j == m {
			i++
			j = 0
		}
		if i == n {
			ans = t
			return
		}
		if filled[i]>>j&1 == 1 {
			dfs(i, j+1, t)
		} else if t+1 < ans {
			var r, c int
			for k := i; k < n; k++ {
				if filled[k]>>j&1 == 1 {
					break
				}
				r++
			}
			for k := j; k < m; k++ {
				if filled[i]>>k&1 == 1 {
					break
				}
				c++
			}
			mx := min(r, c)
			for w := 1; w <= mx; w++ {
				for k := 0; k < w; k++ {
					filled[i+w-1] |= 1 << (j + k)
					filled[i+k] |= 1 << (j + w - 1)
				}
				dfs(i, j+w, t+1)
			}
			for x := i; x < i+mx; x++ {
				for y := j; y < j+mx; y++ {
					filled[x] ^= 1 << y
				}
			}
		}
	}
	dfs(0, 0, 0)
	return ans
}
```

#### TypeScript

```ts
function tilingRectangle(n: number, m: number): number {
    let ans = n * m;
    const filled: number[] = new Array(n).fill(0);
    const dfs = (i: number, j: number, t: number) => {
        if (j === m) {
            ++i;
            j = 0;
        }
        if (i === n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j) & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            let [r, c] = [0, 0];
            for (let k = i; k < n; ++k) {
                if ((filled[k] >> j) & 1) {
                    break;
                }
                ++r;
            }
            for (let k = j; k < m; ++k) {
                if ((filled[i] >> k) & 1) {
                    break;
                }
                ++c;
            }
            const mx = Math.min(r, c);
            for (let w = 1; w <= mx; ++w) {
                for (let k = 0; k < w; ++k) {
                    filled[i + w - 1] |= 1 << (j + k);
                    filled[i + k] |= 1 << (j + w - 1);
                }
                dfs(i, j + w, t + 1);
            }
            for (let x = i; x < i + mx; ++x) {
                for (let y = j; y < j + mx; ++y) {
                    filled[x] ^= 1 << y;
                }
            }
        }
    };
    dfs(0, 0, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        def dfs(i: int, j: int, t: int):
            nonlocal ans
            if j == m:
                i += 1
                j = 0
            if i == n:
                ans = t
                return
            if filled[i] >> j & 1:
                dfs(i, j + 1, t)
            elif t + 1 < ans:
                r = c = 0
                for k in range(i, n):
                    if filled[k] >> j & 1:
                        break
                    r += 1
                for k in range(j, m):
                    if filled[i] >> k & 1:
                        break
                    c += 1
                mx = min(r, c)
                for x in range(i, i + mx):
                    for y in range(j, j + mx):
                        filled[x] |= 1 << y
                for w in range(mx, 0, -1):
                    dfs(i, j + w, t + 1)
                    for k in range(w):
                        filled[i + w - 1] ^= 1 << (j + k)
                        if k < w - 1:
                            filled[i + k] ^= 1 << (j + w - 1)

        ans = n * m
        filled = [0] * n
        dfs(0, 0, 0)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int m;
    private int[] filled;
    private int ans;

    public int tilingRectangle(int n, int m) {
        this.n = n;
        this.m = m;
        ans = n * m;
        filled = new int[n];
        dfs(0, 0, 0);
        return ans;
    }

    private void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j & 1) == 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if ((filled[k] >> j & 1) == 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if ((filled[i] >> k & 1) == 1) {
                    break;
                }
                ++c;
            }
            int mx = Math.min(r, c);
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (int w = mx; w > 0; --w) {
                dfs(i, j + w, t + 1);
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tilingRectangle(int n, int m) {
        memset(filled, 0, sizeof(filled));
        this->n = n;
        this->m = m;
        ans = n * m;
        dfs(0, 0, 0);
        return ans;
    }

private:
    int filled[13];
    int n, m;
    int ans;

    void dfs(int i, int j, int t) {
        if (j == m) {
            ++i;
            j = 0;
        }
        if (i == n) {
            ans = t;
            return;
        }
        if (filled[i] >> j & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            int r = 0, c = 0;
            for (int k = i; k < n; ++k) {
                if (filled[k] >> j & 1) {
                    break;
                }
                ++r;
            }
            for (int k = j; k < m; ++k) {
                if (filled[i] >> k & 1) {
                    break;
                }
                ++c;
            }
            int mx = min(r, c);
            for (int x = i; x < i + mx; ++x) {
                for (int y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (int w = mx; w; --w) {
                dfs(i, j + w, t + 1);
                for (int k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func tilingRectangle(n int, m int) int {
	ans := n * m
	filled := make([]int, n)
	var dfs func(i, j, t int)
	dfs = func(i, j, t int) {
		if j == m {
			i++
			j = 0
		}
		if i == n {
			ans = t
			return
		}
		if filled[i]>>j&1 == 1 {
			dfs(i, j+1, t)
		} else if t+1 < ans {
			var r, c int
			for k := i; k < n; k++ {
				if filled[k]>>j&1 == 1 {
					break
				}
				r++
			}
			for k := j; k < m; k++ {
				if filled[i]>>k&1 == 1 {
					break
				}
				c++
			}
			mx := min(r, c)
			for x := i; x < i+mx; x++ {
				for y := j; y < j+mx; y++ {
					filled[x] |= 1 << y
				}
			}
			for w := mx; w > 0; w-- {
				dfs(i, j+w, t+1)
				for k := 0; k < w; k++ {
					filled[i+w-1] ^= 1 << (j + k)
					if k < w-1 {
						filled[i+k] ^= 1 << (j + w - 1)
					}
				}
			}
		}
	}
	dfs(0, 0, 0)
	return ans
}
```

#### TypeScript

```ts
function tilingRectangle(n: number, m: number): number {
    let ans = n * m;
    const filled: number[] = new Array(n).fill(0);
    const dfs = (i: number, j: number, t: number) => {
        if (j === m) {
            ++i;
            j = 0;
        }
        if (i === n) {
            ans = t;
            return;
        }
        if ((filled[i] >> j) & 1) {
            dfs(i, j + 1, t);
        } else if (t + 1 < ans) {
            let [r, c] = [0, 0];
            for (let k = i; k < n; ++k) {
                if ((filled[k] >> j) & 1) {
                    break;
                }
                ++r;
            }
            for (let k = j; k < m; ++k) {
                if ((filled[i] >> k) & 1) {
                    break;
                }
                ++c;
            }
            const mx = Math.min(r, c);
            for (let x = i; x < i + mx; ++x) {
                for (let y = j; y < j + mx; ++y) {
                    filled[x] |= 1 << y;
                }
            }
            for (let w = mx; w > 0; --w) {
                dfs(i, j + w, t + 1);
                for (let k = 0; k < w; ++k) {
                    filled[i + w - 1] ^= 1 << (j + k);
                    if (k < w - 1) {
                        filled[i + k] ^= 1 << (j + w - 1);
                    }
                }
            }
        }
    };
    dfs(0, 0, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1241. 每个帖子的评论数 🔒](https://leetcode.cn/problems/number-of-comments-per-post){#1241}

{{< tabs "1241" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT DISTINCT s1.sub_id AS post_id, s2.sub_id AS sub_id
        FROM
            Submissions AS s1
            LEFT JOIN Submissions AS s2 ON s1.sub_id = s2.parent_id
        WHERE s1.parent_id IS NULL
    )
SELECT post_id, COUNT(sub_id) AS number_of_comments
FROM t
GROUP BY post_id
ORDER BY post_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表&nbsp;<code>Submissions</code>&nbsp;：</p>

<pre>
+---------------+----------+
| 列名          | 类型     |
+---------------+----------+
| sub_id        | int      |
| parent_id     | int      |
+---------------+----------+
上表可能会出现重复的行。
每行可以是一个帖子或对该帖子的评论。
如果这是一篇帖子，则 parent_id 为 null。
如果这是一条评论，则 parent_id 对应帖子的 sub_id。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案以查找每个帖子的评论数。</p>

<p>结果表应包含帖子的&nbsp;<code>post_id</code> 和对应的评论数&nbsp;<code>number_of_comments</code> 。</p>

<p><code>Submissions</code> 可能包含重复的评论。你应该统计出每个帖子的 <strong>唯一评论</strong> 的数目。</p>

<p><code>Submissions</code> 可能包含重复的帖子。你应该将它们视为一个帖子。</p>

<p>返回结果表应该按 <code>post_id</code> <strong>升序排序</strong>。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Submissions table:
+---------+------------+
| sub_id  | parent_id  |
+---------+------------+
| 1       | Null       |
| 2       | Null       |
| 1       | Null       |
| 12      | Null       |
| 3       | 1          |
| 5       | 2          |
| 3       | 1          |
| 4       | 1          |
| 9       | 1          |
| 10      | 2          |
| 6       | 7          |
+---------+------------+
<strong>输出：</strong>
+---------+--------------------+
| post_id | number_of_comments |
+---------+--------------------+
| 1       | 3                  |
| 2       | 2                  |
| 12      | 0                  |
+---------+--------------------+
<strong>解释：</strong>
表中 ID 为 1 的帖子有 ID 为 3、4 和 9 的三个评论。表中 ID 为 3 的评论重复出现了，所以我们只对它进行了一次计数。
表中 ID 为 2 的帖子有 ID 为 5 和 10 的两个评论。
表中 ID 为 12 的帖子没有评论。
表中 ID 为 6 的评论是对 ID 为 7 的已删除帖子的评论，因此我们将其忽略。</pre>

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
        SELECT DISTINCT s1.sub_id AS post_id, s2.sub_id AS sub_id
        FROM
            Submissions AS s1
            LEFT JOIN Submissions AS s2 ON s1.sub_id = s2.parent_id
        WHERE s1.parent_id IS NULL
    )
SELECT post_id, COUNT(sub_id) AS number_of_comments
FROM t
GROUP BY post_id
ORDER BY post_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1242. 多线程网页爬虫 🔒](https://leetcode.cn/problems/web-crawler-multithreaded){#1242}

{{< tabs "1242" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个初始地址&nbsp;<code>startUrl</code>&nbsp;和一个 HTML 解析器接口&nbsp;<code>HtmlParser</code>，请你实现一个&nbsp;<strong>多线程的网页爬虫</strong>，用于获取与&nbsp;<code>startUrl</code>&nbsp;有&nbsp;<strong>相同主机名&nbsp;</strong>的所有链接。&nbsp;</p>

<p>以&nbsp;<strong>任意&nbsp;</strong>顺序返回爬虫获取的路径。</p>

<p>爬虫应该遵循：</p>

<ul>
	<li>从&nbsp;<code>startUrl</code>&nbsp;开始</li>
	<li>调用&nbsp;<code>HtmlParser.getUrls(url)</code> 从指定网页路径获得的所有路径。</li>
	<li>不要抓取相同的链接两次。</li>
	<li>仅浏览与&nbsp;<code>startUrl</code>&nbsp;<strong>相同主机名&nbsp;</strong>的链接。</li>
</ul>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/16e463265c7086cb?w=975&amp;h=266&amp;f=png&amp;s=24624" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/urlhostname.png" style="height:164px; width:600px" /></p>

<p>如上图所示，主机名是&nbsp;<code>example.org</code>&nbsp;。简单起见，你可以假设所有链接都采用&nbsp;<strong>http 协议</strong>，并且没有指定&nbsp;<strong>端口号</strong>。举个例子，链接&nbsp;<code>http://leetcode.com/problems</code> 和链接&nbsp;<code>http://leetcode.com/contest</code> 属于同一个&nbsp;<strong>主机名</strong>， 而&nbsp;<code>http://example.org/test</code>&nbsp;与&nbsp;<code>http://example.com/abc</code> 并不属于同一个&nbsp;<strong>主机名</strong>。</p>

<p><code>HtmlParser</code> 的接口定义如下：</p>

<pre>
interface HtmlParser {
  // Return a list of all urls from a webpage of given <em>url</em>.
  // This is a blocking call, that means it will do HTTP request and return when this request is finished.
  public List&lt;String&gt; getUrls(String url);
}</pre>

<p>注意一点，<code>getUrls(String url)</code>&nbsp;模拟执行一个HTTP的请求。 你可以将它当做一个阻塞式的方法，直到请求结束。&nbsp;<code>getUrls(String url)</code>&nbsp;保证会在&nbsp;<strong>15ms&nbsp;</strong>内返回所有的路径。 单线程的方案会超过时间限制，你能用多线程方案做的更好吗？</p>

<p>对于问题所需的功能，下面提供了两个例子。为了方便自定义测试，你可以声明三个变量&nbsp;<code>urls</code>，<code>edges</code>&nbsp;和&nbsp;<code>startUrl</code>。但要注意你只能在代码中访问&nbsp;<code>startUrl</code>，并不能直接访问&nbsp;<code>urls</code>&nbsp;和&nbsp;<code>edges</code>。</p>

<p>&nbsp;</p>

<p><strong>拓展问题：</strong></p>

<ol>
	<li>假设我们要要抓取 10000 个节点和 10 亿个路径。并且在每个节点部署相同的的软件。软件可以发现所有的节点。我们必须尽可能减少机器之间的通讯，并确保每个节点负载均衡。你将如何设计这个网页爬虫？</li>
	<li>如果有一个节点发生故障不工作该怎么办？</li>
	<li>如何确认爬虫任务已经完成？</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/sample_2_1497.png" style="height:287px; width:600px" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/16e46559da0c446a?w=875&amp;h=418&amp;f=png&amp;s=43518" /></p>

<pre>
<strong>输入：
</strong>urls = [
&nbsp; &quot;http://news.yahoo.com&quot;,
&nbsp; &quot;http://news.yahoo.com/news&quot;,
&nbsp; &quot;http://news.yahoo.com/news/topics/&quot;,
&nbsp; &quot;http://news.google.com&quot;,
&nbsp; &quot;http://news.yahoo.com/us&quot;
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = &quot;http://news.yahoo.com/news/topics/&quot;
<strong>输出：</strong>[
&nbsp; &quot;http://news.yahoo.com&quot;,
&nbsp; &quot;http://news.yahoo.com/news&quot;,
&nbsp; &quot;http://news.yahoo.com/news/topics/&quot;,
&nbsp; &quot;http://news.yahoo.com/us&quot;
]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/16e4657b399a5fd2?w=654&amp;h=431&amp;f=png&amp;s=33838" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1242.Web%20Crawler%20Multithreaded/images/sample_3_1497.png" style="height:395px; width:530px" /></strong></p>

<pre>
<strong>输入：</strong>
urls = [
&nbsp; &quot;http://news.yahoo.com&quot;,
&nbsp; &quot;http://news.yahoo.com/news&quot;,
&nbsp; &quot;http://news.yahoo.com/news/topics/&quot;,
&nbsp; &quot;http://news.google.com&quot;
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = &quot;http://news.google.com&quot;
<strong>输出：</strong>[&quot;http://news.google.com&quot;]
<strong>解释：</strong>startUrl 链接与其他页面不共享一个主机名。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= urls.length &lt;= 1000</code></li>
	<li><code>1 &lt;= urls[i].length &lt;= 300</code></li>
	<li><code>startUrl</code>&nbsp;是&nbsp;<code>urls</code>&nbsp;中的一个。</li>
	<li>主机名的长度必须为 1 到 63 个字符（包括点 <code>.</code> 在内），只能包含从 &ldquo;a&rdquo; 到 &ldquo;z&rdquo; 的 ASCII 字母和 &ldquo;0&rdquo; 到 &ldquo;9&rdquo; 的数字，以及中划线 &ldquo;-&rdquo;。</li>
	<li>主机名开头和结尾不能是中划线 &ldquo;-&rdquo;。</li>
	<li>参考资料：<a href="https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames">https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames</a></li>
	<li>你可以假设路径都是不重复的。</li>
</ul>

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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1243. 数组变换 🔒](https://leetcode.cn/problems/array-transformation){#1243}

{{< tabs "1243" >}}

{{% tab "python" %}}
```python
class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        f = True
        while f:
            f = False
            t = arr[:]
            for i in range(1, len(t) - 1):
                if t[i] > t[i - 1] and t[i] > t[i + 1]:
                    arr[i] -= 1
                    f = True
                if t[i] < t[i - 1] and t[i] < t[i + 1]:
                    arr[i] += 1
                    f = True
        return arr
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> transformArray(int[] arr) {
        boolean f = true;
        while (f) {
            f = false;
            int[] t = arr.clone();
            for (int i = 1; i < t.length - 1; ++i) {
                if (t[i] > t[i - 1] && t[i] > t[i + 1]) {
                    --arr[i];
                    f = true;
                }
                if (t[i] < t[i - 1] && t[i] < t[i + 1]) {
                    ++arr[i];
                    f = true;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : arr) {
            ans.add(x);
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
    vector<int> transformArray(vector<int>& arr) {
        bool f = true;
        while (f) {
            f = false;
            vector<int> t = arr;
            for (int i = 1; i < arr.size() - 1; ++i) {
                if (t[i] > t[i - 1] && t[i] > t[i + 1]) {
                    --arr[i];
                    f = true;
                }
                if (t[i] < t[i - 1] && t[i] < t[i + 1]) {
                    ++arr[i];
                    f = true;
                }
            }
        }
        return arr;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func transformArray(arr []int) []int {
	f := true
	for f {
		f = false
		t := make([]int, len(arr))
		copy(t, arr)
		for i := 1; i < len(arr)-1; i++ {
			if t[i] > t[i-1] && t[i] > t[i+1] {
				arr[i]--
				f = true
			}
			if t[i] < t[i-1] && t[i] < t[i+1] {
				arr[i]++
				f = true
			}
		}
	}
	return arr
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>首先，给你一个初始数组 <code>arr</code>。然后，每天你都要根据前一天的数组生成一个新的数组。</p>

<p>第&nbsp;<code>i</code>&nbsp;天所生成的数组，是由你对第&nbsp;<code>i-1</code>&nbsp;天的数组进行如下操作所得的：</p>

<ol>
	<li>假如一个元素小于它的左右邻居，那么该元素自增 <code>1</code>。</li>
	<li>假如一个元素大于它的左右邻居，那么该元素自减 <code>1</code>。</li>
	<li>首、尾元素 <strong>永不</strong>&nbsp;改变。</li>
</ol>

<p>过些时日，你会发现数组将会不再发生变化，请返回最终所得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[6,2,3,4]
<strong>输出：</strong>[6,3,3,4]
<strong>解释：</strong>
第一天，数组从 [6,2,3,4] 变为 [6,3,3,4]。
无法再对该数组进行更多操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[1,6,3,4,3,5]
<strong>输出：</strong>[1,4,4,4,4,5]
<strong>解释：</strong>
第一天，数组从 [1,6,3,4,3,5] 变为 [1,5,4,3,4,5]。
第二天，数组从 [1,5,4,3,4,5] 变为 [1,4,4,4,4,5]。
无法再对该数组进行更多操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

每次模拟一天，对于每个元素，如果它大于左右邻居，则自减 1，否则自增 1。如果数组在某一天不再发生变化，则返回该数组。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为数组长度和数组元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        f = True
        while f:
            f = False
            t = arr[:]
            for i in range(1, len(t) - 1):
                if t[i] > t[i - 1] and t[i] > t[i + 1]:
                    arr[i] -= 1
                    f = True
                if t[i] < t[i - 1] and t[i] < t[i + 1]:
                    arr[i] += 1
                    f = True
        return arr
```

#### Java

```java
class Solution {
    public List<Integer> transformArray(int[] arr) {
        boolean f = true;
        while (f) {
            f = false;
            int[] t = arr.clone();
            for (int i = 1; i < t.length - 1; ++i) {
                if (t[i] > t[i - 1] && t[i] > t[i + 1]) {
                    --arr[i];
                    f = true;
                }
                if (t[i] < t[i - 1] && t[i] < t[i + 1]) {
                    ++arr[i];
                    f = true;
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : arr) {
            ans.add(x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool f = true;
        while (f) {
            f = false;
            vector<int> t = arr;
            for (int i = 1; i < arr.size() - 1; ++i) {
                if (t[i] > t[i - 1] && t[i] > t[i + 1]) {
                    --arr[i];
                    f = true;
                }
                if (t[i] < t[i - 1] && t[i] < t[i + 1]) {
                    ++arr[i];
                    f = true;
                }
            }
        }
        return arr;
    }
};
```

#### Go

```go
func transformArray(arr []int) []int {
	f := true
	for f {
		f = false
		t := make([]int, len(arr))
		copy(t, arr)
		for i := 1; i < len(arr)-1; i++ {
			if t[i] > t[i-1] && t[i] > t[i+1] {
				arr[i]--
				f = true
			}
			if t[i] < t[i-1] && t[i] < t[i+1] {
				arr[i]++
				f = true
			}
		}
	}
	return arr
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1244. 力扣排行榜 🔒](https://leetcode.cn/problems/design-a-leaderboard){#1244}

{{< tabs "1244" >}}

{{% tab "python" %}}
```python
class Leaderboard:
    def __init__(self):
        self.d = defaultdict(int)
        self.rank = SortedList()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.d:
            self.d[playerId] = score
            self.rank.add(score)
        else:
            self.rank.remove(self.d[playerId])
            self.d[playerId] += score
            self.rank.add(self.d[playerId])

    def top(self, K: int) -> int:
        return sum(self.rank[-K:])

    def reset(self, playerId: int) -> None:
        self.rank.remove(self.d.pop(playerId))


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Leaderboard {
    private Map<Integer, Integer> d = new HashMap<>();
    private TreeMap<Integer, Integer> rank = new TreeMap<>((a, b) -> b - a);

    public Leaderboard() {
    }

    public void addScore(int playerId, int score) {
        d.merge(playerId, score, Integer::sum);
        int newScore = d.get(playerId);
        if (newScore != score) {
            rank.merge(newScore - score, -1, Integer::sum);
        }
        rank.merge(newScore, 1, Integer::sum);
    }

    public int top(int K) {
        int ans = 0;
        for (var e : rank.entrySet()) {
            int score = e.getKey(), cnt = e.getValue();
            cnt = Math.min(cnt, K);
            ans += score * cnt;
            K -= cnt;
            if (K == 0) {
                break;
            }
        }
        return ans;
    }

    public void reset(int playerId) {
        int score = d.remove(playerId);
        if (rank.merge(score, -1, Integer::sum) == 0) {
            rank.remove(score);
        }
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Leaderboard {
public:
    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        d[playerId] += score;
        int newScore = d[playerId];
        if (newScore != score) {
            rank.erase(rank.find(newScore - score));
        }
        rank.insert(newScore);
    }

    int top(int K) {
        int ans = 0;
        for (auto& x : rank) {
            ans += x;
            if (--K == 0) {
                break;
            }
        }
        return ans;
    }

    void reset(int playerId) {
        int score = d[playerId];
        d.erase(playerId);
        rank.erase(rank.find(score));
    }

private:
    unordered_map<int, int> d;
    multiset<int, greater<int>> rank;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BTreeMap;

#[allow(dead_code)]
struct Leaderboard {
    /// This also keeps track of the top K players since it's implicitly sorted
    record_map: BTreeMap<i32, i32>,
}

impl Leaderboard {
    #[allow(dead_code)]
    fn new() -> Self {
        Self {
            record_map: BTreeMap::new(),
        }
    }

    #[allow(dead_code)]
    fn add_score(&mut self, player_id: i32, score: i32) {
        if self.record_map.contains_key(&player_id) {
            // The player exists, just add the score
            self.record_map
                .insert(player_id, self.record_map.get(&player_id).unwrap() + score);
        } else {
            // Add the new player to the map
            self.record_map.insert(player_id, score);
        }
    }

    #[allow(dead_code)]
    fn top(&self, k: i32) -> i32 {
        let mut cur_vec: Vec<(i32, i32)> = self.record_map.iter().map(|(k, v)| (*k, *v)).collect();
        cur_vec.sort_by(|lhs, rhs| rhs.1.cmp(&lhs.1));
        // Iterate reversely for K
        let mut sum = 0;
        let mut i = 0;
        for (_, value) in &cur_vec {
            if i == k {
                break;
            }
            sum += value;
            i += 1;
        }

        sum
    }

    #[allow(dead_code)]
    fn reset(&mut self, player_id: i32) {
        // The player is ensured to exist in the board
        // Just set the score to 0
        self.record_map.insert(player_id, 0);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>新一轮的「力扣杯」编程大赛即将启动，为了动态显示参赛者的得分数据，需要设计一个排行榜 Leaderboard。</p>

<p>请你帮忙来设计这个 <code>Leaderboard</code> 类，使得它有如下 3 个函数：</p>

<ol>
	<li><code>addScore(playerId, score)</code>：

    <ul>
    	<li>假如参赛者已经在排行榜上，就给他的当前得分增加 <code>score</code> 点分值并更新排行。</li>
    	<li>假如该参赛者不在排行榜上，就把他添加到榜单上，并且将分数设置为 <code>score</code>。</li>
    </ul>
    </li>
    <li><code>top(K)</code>：返回前 <code>K</code> 名参赛者的 <strong>得分总和</strong>。</li>
    <li><code>reset(playerId)</code>：将指定参赛者的成绩清零（换句话说，将其从排行榜中删除）。题目保证在调用此函数前，该参赛者已有成绩，并且在榜单上。</li>

</ol>

<p>请注意，在初始状态下，排行榜是空的。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入： </strong>
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
<strong>输出：</strong>
[null,null,null,null,null,null,73,null,null,null,141]

<strong>解释： </strong>
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= playerId, K <= 10000</code></li>
	<li>题目保证 <code>K</code> 小于或等于当前参赛者的数量</li>
	<li><code>1 <= score <= 100</code></li>
	<li>最多进行 <code>1000</code> 次函数调用</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序列表

我们用哈希表 $d$ 记录每个参赛者的分数，用有序列表 $rank$ 记录所有参赛者的分数。

当调用 `addScore` 函数时，我们先判断参赛者是否在哈希表 $d$ 中，如果不在，我们将其分数加入有序列表 $rank$ 中，否则我们先将其分数从有序列表 $rank$ 中删除，再将其分数加入有序列表 $rank$ 中，最后更新哈希表 $d$ 中的分数。时间复杂度 $O(\log n)$。

当调用 `top` 函数时，我们直接返回有序列表 $rank$ 中前 $K$ 个元素的和。时间复杂度 $O(K \times \log n)$。

当调用 `reset` 函数时，我们先移除哈希表 $d$ 中的参赛者，再将其分数从有序列表 $rank$ 中移除。时间复杂度 $O(\log n)$。

空间复杂度 $O(n)$。其中 $n$ 为参赛者的数量。

<!-- tabs:start -->

#### Python3

```python
class Leaderboard:
    def __init__(self):
        self.d = defaultdict(int)
        self.rank = SortedList()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.d:
            self.d[playerId] = score
            self.rank.add(score)
        else:
            self.rank.remove(self.d[playerId])
            self.d[playerId] += score
            self.rank.add(self.d[playerId])

    def top(self, K: int) -> int:
        return sum(self.rank[-K:])

    def reset(self, playerId: int) -> None:
        self.rank.remove(self.d.pop(playerId))


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
```

#### Java

```java
class Leaderboard {
    private Map<Integer, Integer> d = new HashMap<>();
    private TreeMap<Integer, Integer> rank = new TreeMap<>((a, b) -> b - a);

    public Leaderboard() {
    }

    public void addScore(int playerId, int score) {
        d.merge(playerId, score, Integer::sum);
        int newScore = d.get(playerId);
        if (newScore != score) {
            rank.merge(newScore - score, -1, Integer::sum);
        }
        rank.merge(newScore, 1, Integer::sum);
    }

    public int top(int K) {
        int ans = 0;
        for (var e : rank.entrySet()) {
            int score = e.getKey(), cnt = e.getValue();
            cnt = Math.min(cnt, K);
            ans += score * cnt;
            K -= cnt;
            if (K == 0) {
                break;
            }
        }
        return ans;
    }

    public void reset(int playerId) {
        int score = d.remove(playerId);
        if (rank.merge(score, -1, Integer::sum) == 0) {
            rank.remove(score);
        }
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */
```

#### C++

```cpp
class Leaderboard {
public:
    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        d[playerId] += score;
        int newScore = d[playerId];
        if (newScore != score) {
            rank.erase(rank.find(newScore - score));
        }
        rank.insert(newScore);
    }

    int top(int K) {
        int ans = 0;
        for (auto& x : rank) {
            ans += x;
            if (--K == 0) {
                break;
            }
        }
        return ans;
    }

    void reset(int playerId) {
        int score = d[playerId];
        d.erase(playerId);
        rank.erase(rank.find(score));
    }

private:
    unordered_map<int, int> d;
    multiset<int, greater<int>> rank;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
```

#### Rust

```rust
use std::collections::BTreeMap;

#[allow(dead_code)]
struct Leaderboard {
    /// This also keeps track of the top K players since it's implicitly sorted
    record_map: BTreeMap<i32, i32>,
}

impl Leaderboard {
    #[allow(dead_code)]
    fn new() -> Self {
        Self {
            record_map: BTreeMap::new(),
        }
    }

    #[allow(dead_code)]
    fn add_score(&mut self, player_id: i32, score: i32) {
        if self.record_map.contains_key(&player_id) {
            // The player exists, just add the score
            self.record_map
                .insert(player_id, self.record_map.get(&player_id).unwrap() + score);
        } else {
            // Add the new player to the map
            self.record_map.insert(player_id, score);
        }
    }

    #[allow(dead_code)]
    fn top(&self, k: i32) -> i32 {
        let mut cur_vec: Vec<(i32, i32)> = self.record_map.iter().map(|(k, v)| (*k, *v)).collect();
        cur_vec.sort_by(|lhs, rhs| rhs.1.cmp(&lhs.1));
        // Iterate reversely for K
        let mut sum = 0;
        let mut i = 0;
        for (_, value) in &cur_vec {
            if i == k {
                break;
            }
            sum += value;
            i += 1;
        }

        sum
    }

    #[allow(dead_code)]
    fn reset(&mut self, player_id: i32) {
        // The player is ensured to exist in the board
        // Just set the score to 0
        self.record_map.insert(player_id, 0);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1245. 树的直径 🔒](https://leetcode.cn/problems/tree-diameter){#1245}

{{< tabs "1245" >}}

{{% tab "python" %}}
```python
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int, t: int):
            for j in g[i]:
                if j != fa:
                    dfs(j, i, t + 1)
            nonlocal ans, a
            if ans < t:
                ans = t
                a = i

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = a = 0
        dfs(0, -1, 0)
        dfs(a, -1, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private int a;

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int t) {
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0, a = 0;
        auto dfs = [&](this auto&& dfs, int i, int fa, int t) -> void {
            for (int j : g[i]) {
                if (j != fa) {
                    dfs(j, i, t + 1);
                }
            }
            if (ans < t) {
                ans = t;
                a = i;
            }
        };
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func treeDiameter(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	a := 0
	var dfs func(i, fa, t int)
	dfs = func(i, fa, t int) {
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i, t+1)
			}
		}
		if ans < t {
			ans = t
			a = i
		}
	}
	dfs(0, -1, 0)
	dfs(a, -1, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function treeDiameter(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let [ans, a] = [0, 0];
    const dfs = (i: number, fa: number, t: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    };
    dfs(0, -1, 0);
    dfs(a, -1, 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你这棵「无向树」，请你测算并返回它的「直径」：这棵树上最长简单路径的 <strong>边数</strong>。</p>

<p>我们用一个由所有「边」组成的数组 <code>edges</code>&nbsp;来表示一棵无向树，其中&nbsp;<code>edges[i] = [u, v]</code>&nbsp;表示节点&nbsp;<code>u</code> 和 <code>v</code>&nbsp;之间的双向边。</p>

<p>树上的节点都已经用&nbsp;<code>{0, 1, ..., edges.length}</code>&nbsp;中的数做了标记，每个节点上的标记都是独一无二的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1245.Tree%20Diameter/images/1397_example_1.png" style="height: 233px; width: 226px;"></p>

<pre><strong>输入：</strong>edges = [[0,1],[0,2]]
<strong>输出：</strong>2
<strong>解释：</strong>
这棵树上最长的路径是 1 - 0 - 2，边数为 2。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1245.Tree%20Diameter/images/1397_example_2.png" style="height: 316px; width: 350px;"></p>

<pre><strong>输入：</strong>edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
<strong>输出：</strong>4
<strong>解释： </strong>
这棵树上最长的路径是 3 - 2 - 1 - 4 - 5，边数为 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= edges.length &lt;&nbsp;10^4</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li><code>0 &lt;= edges[i][j] &lt;= edges.length</code></li>
	<li><code>edges</code>&nbsp;会形成一棵无向树</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们首先任选一个节点，从该节点开始进行深度优先搜索，找到距离该节点最远的节点，记为节点 $a$。然后从节点 $a$ 开始进行深度优先搜索，找到距离节点 $a$ 最远的节点，记为节点 $b$。可以证明，节点 $a$ 和节点 $b$ 之间的路径即为树的直径。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

相似题目：

-   [1522. N 叉树的直径 🔒](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1522.Diameter%20of%20N-Ary%20Tree/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int, t: int):
            for j in g[i]:
                if j != fa:
                    dfs(j, i, t + 1)
            nonlocal ans, a
            if ans < t:
                ans = t
                a = i

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = a = 0
        dfs(0, -1, 0)
        dfs(a, -1, 0)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private int a;

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int t) {
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0, a = 0;
        auto dfs = [&](this auto&& dfs, int i, int fa, int t) -> void {
            for (int j : g[i]) {
                if (j != fa) {
                    dfs(j, i, t + 1);
                }
            }
            if (ans < t) {
                ans = t;
                a = i;
            }
        };
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }
};
```

#### Go

```go
func treeDiameter(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	a := 0
	var dfs func(i, fa, t int)
	dfs = func(i, fa, t int) {
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i, t+1)
			}
		}
		if ans < t {
			ans = t
			a = i
		}
	}
	dfs(0, -1, 0)
	dfs(a, -1, 0)
	return
}
```

#### TypeScript

```ts
function treeDiameter(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let [ans, a] = [0, 0];
    const dfs = (i: number, fa: number, t: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    };
    dfs(0, -1, 0);
    dfs(a, -1, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1246. 删除回文子数组 🔒](https://leetcode.cn/problems/palindrome-removal){#1246}

{{< tabs "1246" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if i + 1 == j:
                    f[i][j] = 1 if arr[i] == arr[j] else 2
                else:
                    t = f[i + 1][j - 1] if arr[i] == arr[j] else inf
                    for k in range(i, j):
                        t = min(t, f[i][k] + f[k + 1][j])
                    f[i][j] = t
        return f[0][n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumMoves(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (i + 1 == j) {
                    f[i][j] = arr[i] == arr[j] ? 1 : 2;
                } else {
                    int t = arr[i] == arr[j] ? f[i + 1][j - 1] : 1 << 30;
                    for (int k = i; k < j; ++k) {
                        t = Math.min(t, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = t;
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (i + 1 == j) {
                    f[i][j] = arr[i] == arr[j] ? 1 : 2;
                } else {
                    int t = arr[i] == arr[j] ? f[i + 1][j - 1] : 1 << 30;
                    for (int k = i; k < j; ++k) {
                        t = min(t, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = t;
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMoves(arr []int) int {
	n := len(arr)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if i+1 == j {
				f[i][j] = 2
				if arr[i] == arr[j] {
					f[i][j] = 1
				}
			} else {
				t := 1 << 30
				if arr[i] == arr[j] {
					t = f[i+1][j-1]
				}
				for k := i; k < j; k++ {
					t = min(t, f[i][k]+f[k+1][j])
				}
				f[i][j] = t
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoves(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }

    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (i + 1 === j) {
                f[i][j] = arr[i] === arr[j] ? 1 : 2;
            } else {
                let t = arr[i] === arr[j] ? f[i + 1][j - 1] : Infinity;
                for (let k = i; k < j; ++k) {
                    t = Math.min(t, f[i][k] + f[k + 1][j]);
                }
                f[i][j] = t;
            }
        }
    }

    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>，每一次操作你都可以选择并删除它的一个 <strong>回文</strong> 子数组&nbsp;<code>arr[i], arr[i+1], ..., arr[j]</code>（ <code>i &lt;= j</code>）。</p>

<p>注意，每当你删除掉一个子数组，右侧元素都会自行向前移动填补空位。</p>

<p>请你计算并返回从数组中删除所有数字所需的最少操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,4,1,5]
<strong>输出：</strong>3
<strong>解释：</strong>先删除 [4]，然后删除 [1,3,1]，最后再删除 [5]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（区间 DP）

我们定义 $f[i][j]$ 表示删除下标区间 $[i,..j]$ 内的所有数字所需的最少操作次数。初始时 $f[i][i] = 1$，表示只有一个数字时，需要执行一次删除操作。

对于 $f[i][j]$，如果 $i + 1 = j$，即只有两个数字时，如果 $arr[i]=arr[j]$，则 $f[i][j] = 1$，否则 $f[i][j] = 2$。

对于超过两个数字的情况，如果 $arr[i]=arr[j]$，那么 $f[i][j]$ 可以取 $f[i + 1][j - 1]$，或者我们可以在下标范围 $[i,..j-1]$ 范围内枚举 $k$，取 $f[i][k] + f[k + 1][j]$ 的最小值。将最小值赋给 $f[i][j]$。

答案即为 $f[0][n - 1]$。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if i + 1 == j:
                    f[i][j] = 1 if arr[i] == arr[j] else 2
                else:
                    t = f[i + 1][j - 1] if arr[i] == arr[j] else inf
                    for k in range(i, j):
                        t = min(t, f[i][k] + f[k + 1][j])
                    f[i][j] = t
        return f[0][n - 1]
```

#### Java

```java
class Solution {
    public int minimumMoves(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (i + 1 == j) {
                    f[i][j] = arr[i] == arr[j] ? 1 : 2;
                } else {
                    int t = arr[i] == arr[j] ? f[i + 1][j - 1] : 1 << 30;
                    for (int k = i; k < j; ++k) {
                        t = Math.min(t, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = t;
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (i + 1 == j) {
                    f[i][j] = arr[i] == arr[j] ? 1 : 2;
                } else {
                    int t = arr[i] == arr[j] ? f[i + 1][j - 1] : 1 << 30;
                    for (int k = i; k < j; ++k) {
                        t = min(t, f[i][k] + f[k + 1][j]);
                    }
                    f[i][j] = t;
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func minimumMoves(arr []int) int {
	n := len(arr)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if i+1 == j {
				f[i][j] = 2
				if arr[i] == arr[j] {
					f[i][j] = 1
				}
			} else {
				t := 1 << 30
				if arr[i] == arr[j] {
					t = f[i+1][j-1]
				}
				for k := i; k < j; k++ {
					t = min(t, f[i][k]+f[k+1][j])
				}
				f[i][j] = t
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function minimumMoves(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }

    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (i + 1 === j) {
                f[i][j] = arr[i] === arr[j] ? 1 : 2;
            } else {
                let t = arr[i] === arr[j] ? f[i + 1][j - 1] : Infinity;
                for (let k = i; k < j; ++k) {
                    t = Math.min(t, f[i][k] + f[k + 1][j]);
                }
                f[i][j] = t;
            }
        }
    }

    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1247. 交换字符使得字符串相同](https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal){#1247}

{{< tabs "1247" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        xy = yx = 0
        for a, b in zip(s1, s2):
            xy += a < b
            yx += a > b
        if (xy + yx) % 2:
            return -1
        return xy // 2 + yx // 2 + xy % 2 + yx % 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSwap(String s1, String s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.length(); ++i) {
            char a = s1.charAt(i), b = s2.charAt(i);
            if (a < b) {
                ++xy;
            }
            if (a > b) {
                ++yx;
            }
        }
        if ((xy + yx) % 2 == 1) {
            return -1;
        }
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            xy += a < b;
            yx += a > b;
        }
        if ((xy + yx) % 2) {
            return -1;
        }
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSwap(s1 string, s2 string) int {
	xy, yx := 0, 0
	for i := range s1 {
		if s1[i] < s2[i] {
			xy++
		}
		if s1[i] > s2[i] {
			yx++
		}
	}
	if (xy+yx)%2 == 1 {
		return -1
	}
	return xy/2 + yx/2 + xy%2 + yx%2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSwap(s1: string, s2: string): number {
    let xy = 0,
        yx = 0;

    for (let i = 0; i < s1.length; ++i) {
        const a = s1[i],
            b = s2[i];
        xy += a < b ? 1 : 0;
        yx += a > b ? 1 : 0;
    }

    if ((xy + yx) % 2 !== 0) {
        return -1;
    }

    return Math.floor(xy / 2) + Math.floor(yx / 2) + (xy % 2) + (yx % 2);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var minimumSwap = function (s1, s2) {
    let xy = 0,
        yx = 0;
    for (let i = 0; i < s1.length; ++i) {
        const a = s1[i],
            b = s2[i];
        if (a < b) {
            ++xy;
        }
        if (a > b) {
            ++yx;
        }
    }
    if ((xy + yx) % 2 === 1) {
        return -1;
    }
    return Math.floor(xy / 2) + Math.floor(yx / 2) + (xy % 2) + (yx % 2);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有两个长度相同的字符串&nbsp;<code>s1</code> 和&nbsp;<code>s2</code>，且它们其中&nbsp;<strong>只含有</strong>&nbsp;字符&nbsp;<code>"x"</code> 和&nbsp;<code>"y"</code>，你需要通过「交换字符」的方式使这两个字符串相同。</p>

<p>每次「交换字符」的时候，你都可以在两个字符串中各选一个字符进行交换。</p>

<p>交换只能发生在两个不同的字符串之间，绝对不能发生在同一个字符串内部。也就是说，我们可以交换&nbsp;<code>s1[i]</code> 和&nbsp;<code>s2[j]</code>，但不能交换&nbsp;<code>s1[i]</code> 和&nbsp;<code>s1[j]</code>。</p>

<p>最后，请你返回使 <code>s1</code> 和 <code>s2</code> 相同的最小交换次数，如果没有方法能够使得这两个字符串相同，则返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "xx", s2 = "yy"
<strong>输出：</strong>1
<strong>解释：
</strong>交换 s1[0] 和 s2[1]，得到 s1 = "yx"，s2 = "yx"。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "xy", s2 = "yx"
<strong>输出：</strong>2
<strong>解释：
</strong>交换 s1[0] 和 s2[0]，得到 s1 = "yy"，s2 = "xx" 。
交换 s1[0] 和 s2[1]，得到 s1 = "xy"，s2 = "xy" 。
注意，你不能交换 s1[0] 和 s1[1] 使得 s1 变成 "yx"，因为我们只能交换属于两个不同字符串的字符。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s1 = "xx", s2 = "xy"
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 1000</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1, s2</code>&nbsp;只包含&nbsp;<code>'x'</code>&nbsp;或&nbsp;<code>'y'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，两个字符串 $s_1$ 和 $s_2$ 都只包含字符 $x$ 和 $y$，且长度相同，因此可以将 $s_1$ 和 $s_2$ 中的字符一一对应起来，即 $s_1[i]$ 和 $s_2[i]$。

如果 $s_1[i] = s_2[i]$，则不需要交换，直接跳过即可。如果 $s_1[i] \neq s_2[i]$，则需要交换，我们统计 $s_1[i]$ 和 $s_2[i]$ 的组合情况，即 $s_1[i] = x$ 且 $s_2[i] = y$ 的情况，记为 $xy$，对于 $s_1[i] = y$ 且 $s_2[i] = x$ 的情况，记为 $yx$。

如果 $xy + yx$ 为奇数，则无法完成交换，返回 $-1$。如果 $xy + yx$ 为偶数，则需要交换的次数为 $\left \lfloor \frac{x}{2} \right \rfloor$ + $\left \lfloor \frac{y}{2} \right \rfloor$ + $xy \bmod{2}$ + $yx \bmod{2}$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s_1$ 和 $s_2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        xy = yx = 0
        for a, b in zip(s1, s2):
            xy += a < b
            yx += a > b
        if (xy + yx) % 2:
            return -1
        return xy // 2 + yx // 2 + xy % 2 + yx % 2
```

#### Java

```java
class Solution {
    public int minimumSwap(String s1, String s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.length(); ++i) {
            char a = s1.charAt(i), b = s2.charAt(i);
            if (a < b) {
                ++xy;
            }
            if (a > b) {
                ++yx;
            }
        }
        if ((xy + yx) % 2 == 1) {
            return -1;
        }
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            xy += a < b;
            yx += a > b;
        }
        if ((xy + yx) % 2) {
            return -1;
        }
        return xy / 2 + yx / 2 + xy % 2 + yx % 2;
    }
};
```

#### Go

```go
func minimumSwap(s1 string, s2 string) int {
	xy, yx := 0, 0
	for i := range s1 {
		if s1[i] < s2[i] {
			xy++
		}
		if s1[i] > s2[i] {
			yx++
		}
	}
	if (xy+yx)%2 == 1 {
		return -1
	}
	return xy/2 + yx/2 + xy%2 + yx%2
}
```

#### TypeScript

```ts
function minimumSwap(s1: string, s2: string): number {
    let xy = 0,
        yx = 0;

    for (let i = 0; i < s1.length; ++i) {
        const a = s1[i],
            b = s2[i];
        xy += a < b ? 1 : 0;
        yx += a > b ? 1 : 0;
    }

    if ((xy + yx) % 2 !== 0) {
        return -1;
    }

    return Math.floor(xy / 2) + Math.floor(yx / 2) + (xy % 2) + (yx % 2);
}
```

#### JavaScript

```js
var minimumSwap = function (s1, s2) {
    let xy = 0,
        yx = 0;
    for (let i = 0; i < s1.length; ++i) {
        const a = s1[i],
            b = s2[i];
        if (a < b) {
            ++xy;
        }
        if (a > b) {
            ++yx;
        }
    }
    if ((xy + yx) % 2 === 1) {
        return -1;
    }
    return Math.floor(xy / 2) + Math.floor(yx / 2) + (xy % 2) + (yx % 2);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1248. 统计「优美子数组」](https://leetcode.cn/problems/count-number-of-nice-subarrays){#1248}

{{< tabs "1248" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = t = 0
        for v in nums:
            t += v & 1
            ans += cnt[t - k]
            cnt[t] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int& v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSubarrays(nums []int, k int) (ans int) {
	n := len(nums)
	cnt := make([]int, n+1)
	cnt[0] = 1
	t := 0
	for _, v := range nums {
		t += v & 1
		if t >= k {
			ans += cnt[t-k]
		}
		cnt[t]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSubarrays(nums: number[], k: number): number {
    const n = nums.length;
    const cnt = Array(n + 1).fill(0);
    cnt[0] = 1;
    let [t, ans] = [0, 0];
    for (const v of nums) {
        t += v & 1;
        ans += cnt[t - k] ?? 0;
        cnt[t] += 1;
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code> 和一个整数 <code>k</code>。如果某个连续子数组中恰好有 <code>k</code> 个奇数数字，我们就认为这个子数组是「<strong>优美子数组</strong>」。</p>

<p>请返回这个数组中 <strong>「优美子数组」</strong> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,1,1], k = 3
<strong>输出：</strong>2
<strong>解释：</strong>包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,6], k = 1
<strong>输出：</strong>0
<strong>解释：</strong>数列中不包含任何奇数，所以不存在优美子数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,1,2,2,1,2,2,2], k = 2
<strong>输出：</strong>16
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 数组或哈希表

题目求子数组中恰好有 $k$ 个奇数的子数组个数，我们可以求出每个前缀数组中奇数的个数 $t$，记录在数组或哈希表 $cnt$ 中。对于每个前缀数组，我们只需要求出前缀数组中奇数个数为 $t-k$ 的前缀数组个数，即为以当前前缀数组结尾的子数组个数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        cnt = Counter({0: 1})
        ans = t = 0
        for v in nums:
            t += v & 1
            ans += cnt[t - k]
            cnt[t] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int& v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSubarrays(nums []int, k int) (ans int) {
	n := len(nums)
	cnt := make([]int, n+1)
	cnt[0] = 1
	t := 0
	for _, v := range nums {
		t += v & 1
		if t >= k {
			ans += cnt[t-k]
		}
		cnt[t]++
	}
	return
}
```

#### TypeScript

```ts
function numberOfSubarrays(nums: number[], k: number): number {
    const n = nums.length;
    const cnt = Array(n + 1).fill(0);
    cnt[0] = 1;
    let [t, ans] = [0, 0];
    for (const v of nums) {
        t += v & 1;
        ans += cnt[t - k] ?? 0;
        cnt[t] += 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1249. 移除无效的括号](https://leetcode.cn/problems/minimum-remove-to-make-valid-parentheses){#1249}

{{< tabs "1249" >}}

{{% tab "python" %}}
```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        x = 0
        for c in s:
            if c == ')' and x == 0:
                continue
            if c == '(':
                x += 1
            elif c == ')':
                x -= 1
            stk.append(c)
        x = 0
        ans = []
        for c in stk[::-1]:
            if c == '(' and x == 0:
                continue
            if c == ')':
                x += 1
            elif c == '(':
                x -= 1
            ans.append(c)
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == ')' && x == 0) {
                continue;
            }
            if (c == '(') {
                ++x;
            } else if (c == ')') {
                --x;
            }
            stk.push(c);
        }
        StringBuilder ans = new StringBuilder();
        x = 0;
        while (!stk.isEmpty()) {
            char c = stk.pop();
            if (c == '(' && x == 0) {
                continue;
            }
            if (c == ')') {
                ++x;
            } else if (c == '(') {
                --x;
            }
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string stk;
        int x = 0;
        for (char& c : s) {
            if (c == ')' && x == 0) continue;
            if (c == '(')
                ++x;
            else if (c == ')')
                --x;
            stk.push_back(c);
        }
        string ans;
        x = 0;
        while (stk.size()) {
            char c = stk.back();
            stk.pop_back();
            if (c == '(' && x == 0) continue;
            if (c == ')')
                ++x;
            else if (c == '(')
                --x;
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minRemoveToMakeValid(s string) string {
	stk := []byte{}
	x := 0
	for i := range s {
		c := s[i]
		if c == ')' && x == 0 {
			continue
		}
		if c == '(' {
			x++
		} else if c == ')' {
			x--
		}
		stk = append(stk, c)
	}
	ans := []byte{}
	x = 0
	for i := len(stk) - 1; i >= 0; i-- {
		c := stk[i]
		if c == '(' && x == 0 {
			continue
		}
		if c == ')' {
			x++
		} else if c == '(' {
			x--
		}
		ans = append(ans, c)
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minRemoveToMakeValid(s: string): string {
    let left = 0;
    let right = 0;
    for (const c of s) {
        if (c === '(') {
            left++;
        } else if (c === ')') {
            if (right < left) {
                right++;
            }
        }
    }

    let hasLeft = 0;
    let res = '';
    for (const c of s) {
        if (c === '(') {
            if (hasLeft < right) {
                hasLeft++;
                res += c;
            }
        } else if (c === ')') {
            if (hasLeft != 0 && right !== 0) {
                right--;
                hasLeft--;
                res += c;
            }
        } else {
            res += c;
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let bs = s.as_bytes();
        let mut right = {
            let mut left = 0;
            let mut right = 0;
            for c in bs.iter() {
                match c {
                    &b'(' => {
                        left += 1;
                    }
                    &b')' if right < left => {
                        right += 1;
                    }
                    _ => {}
                }
            }
            right
        };
        let mut has_left = 0;
        let mut res = vec![];
        for c in bs.iter() {
            match c {
                &b'(' => {
                    if has_left < right {
                        has_left += 1;
                        res.push(*c);
                    }
                }
                &b')' => {
                    if has_left != 0 && right != 0 {
                        right -= 1;
                        has_left -= 1;
                        res.push(*c);
                    }
                }
                _ => {
                    res.push(*c);
                }
            }
        }
        String::from_utf8_lossy(&res).to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>'('</code>、<code>')'</code> 和小写字母组成的字符串 <code>s</code>。</p>

<p>你需要从字符串中删除最少数目的 <code>'('</code> 或者 <code>')'</code>&nbsp;（可以删除任意位置的括号)，使得剩下的「括号字符串」有效。</p>

<p>请返回任意一个合法字符串。</p>

<p>有效「括号字符串」应当符合以下&nbsp;<strong>任意一条&nbsp;</strong>要求：</p>

<ul>
	<li>空字符串或只包含小写字母的字符串</li>
	<li>可以被写作&nbsp;<code>AB</code>（<code>A</code>&nbsp;连接&nbsp;<code>B</code>）的字符串，其中&nbsp;<code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;都是有效「括号字符串」</li>
	<li>可以被写作&nbsp;<code>(A)</code>&nbsp;的字符串，其中&nbsp;<code>A</code>&nbsp;是一个有效的「括号字符串」</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "lee(t(c)o)de)"
<strong>输出：</strong>"lee(t(c)o)de"
<strong>解释：</strong>"lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a)b(c)d"
<strong>输出：</strong>"ab(c)d"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "))(("
<strong>输出：</strong>""
<strong>解释：</strong>空字符串也是有效的
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;可能是&nbsp;<code>'('</code>、<code>')'</code>&nbsp;或英文小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两遍扫描

我们先从左向右扫描，将多余的右括号删除，再从右向左扫描，将多余的左括号删除。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

相似题目：

-   [678. 有效的括号字符串](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0678.Valid%20Parenthesis%20String/README.md)
-   [2116. 判断一个括号字符串是否有效](https://github.com/doocs/leetcode/blob/main/solution/2100-2199/2116.Check%20if%20a%20Parentheses%20String%20Can%20Be%20Valid/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        x = 0
        for c in s:
            if c == ')' and x == 0:
                continue
            if c == '(':
                x += 1
            elif c == ')':
                x -= 1
            stk.append(c)
        x = 0
        ans = []
        for c in stk[::-1]:
            if c == '(' and x == 0:
                continue
            if c == ')':
                x += 1
            elif c == '(':
                x -= 1
            ans.append(c)
        return ''.join(ans[::-1])
```

#### Java

```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        Deque<Character> stk = new ArrayDeque<>();
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == ')' && x == 0) {
                continue;
            }
            if (c == '(') {
                ++x;
            } else if (c == ')') {
                --x;
            }
            stk.push(c);
        }
        StringBuilder ans = new StringBuilder();
        x = 0;
        while (!stk.isEmpty()) {
            char c = stk.pop();
            if (c == '(' && x == 0) {
                continue;
            }
            if (c == ')') {
                ++x;
            } else if (c == '(') {
                --x;
            }
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string stk;
        int x = 0;
        for (char& c : s) {
            if (c == ')' && x == 0) continue;
            if (c == '(')
                ++x;
            else if (c == ')')
                --x;
            stk.push_back(c);
        }
        string ans;
        x = 0;
        while (stk.size()) {
            char c = stk.back();
            stk.pop_back();
            if (c == '(' && x == 0) continue;
            if (c == ')')
                ++x;
            else if (c == '(')
                --x;
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func minRemoveToMakeValid(s string) string {
	stk := []byte{}
	x := 0
	for i := range s {
		c := s[i]
		if c == ')' && x == 0 {
			continue
		}
		if c == '(' {
			x++
		} else if c == ')' {
			x--
		}
		stk = append(stk, c)
	}
	ans := []byte{}
	x = 0
	for i := len(stk) - 1; i >= 0; i-- {
		c := stk[i]
		if c == '(' && x == 0 {
			continue
		}
		if c == ')' {
			x++
		} else if c == '(' {
			x--
		}
		ans = append(ans, c)
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function minRemoveToMakeValid(s: string): string {
    let left = 0;
    let right = 0;
    for (const c of s) {
        if (c === '(') {
            left++;
        } else if (c === ')') {
            if (right < left) {
                right++;
            }
        }
    }

    let hasLeft = 0;
    let res = '';
    for (const c of s) {
        if (c === '(') {
            if (hasLeft < right) {
                hasLeft++;
                res += c;
            }
        } else if (c === ')') {
            if (hasLeft != 0 && right !== 0) {
                right--;
                hasLeft--;
                res += c;
            }
        } else {
            res += c;
        }
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let bs = s.as_bytes();
        let mut right = {
            let mut left = 0;
            let mut right = 0;
            for c in bs.iter() {
                match c {
                    &b'(' => {
                        left += 1;
                    }
                    &b')' if right < left => {
                        right += 1;
                    }
                    _ => {}
                }
            }
            right
        };
        let mut has_left = 0;
        let mut res = vec![];
        for c in bs.iter() {
            match c {
                &b'(' => {
                    if has_left < right {
                        has_left += 1;
                        res.push(*c);
                    }
                }
                &b')' => {
                    if has_left != 0 && right != 0 {
                        right -= 1;
                        has_left -= 1;
                        res.push(*c);
                    }
                }
                _ => {
                    res.push(*c);
                }
            }
        }
        String::from_utf8_lossy(&res).to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

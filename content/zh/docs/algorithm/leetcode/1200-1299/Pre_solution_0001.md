---
title: "1200_最小绝对差"
date: 2025-10-08T18:37:06+08:00
weight: 1
tags: [二分查找, 前缀和, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 数论, 栈, 深度优先搜索, 滑动窗口, 组合数学, 设计, 链表]
---

{{< markmap >}}
### [1200_最小绝对差](#1200)
#### [数组](#1200)
#### [排序](#1200)
### [1201_丑数 III](#1201)
#### [数学](#1201)
#### [二分查找](#1201)
#### [组合数学](#1201)
#### [数论](#1201)
### [1202_交换字符串中的元素](#1202)
#### [深度优先搜索](#1202)
#### [广度优先搜索](#1202)
#### [并查集](#1202)
#### [数组](#1202)
#### [哈希表](#1202)
#### [字符串](#1202)
#### [排序](#1202)
### [1203_项目管理](#1203)
#### [深度优先搜索](#1203)
#### [广度优先搜索](#1203)
#### [图](#1203)
#### [拓扑排序](#1203)
### [1204_最后一个能进入巴士的人](#1204)
#### [数据库](#1204)
### [1205_每月交易 II 🔒](#1205)
#### [数据库](#1205)
### [1206_设计跳表](#1206)
#### [设计](#1206)
#### [链表](#1206)
### [1207_独一无二的出现次数](#1207)
#### [数组](#1207)
#### [哈希表](#1207)
### [1208_尽可能使字符串相等](#1208)
#### [字符串](#1208)
#### [二分查找](#1208)
#### [前缀和](#1208)
#### [滑动窗口](#1208)
### [1209_删除字符串中的所有相邻重复项 II](#1209)
#### [栈](#1209)
#### [字符串](#1209)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1200_最小绝对差
___
#### 数组
___
#### 排序
---
### 1201_丑数 III
___
#### 数学
___
#### 二分查找
___
#### 组合数学
___
#### 数论
---
### 1202_交换字符串中的元素
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1203_项目管理
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 1204_最后一个能进入巴士的人
___
#### 数据库
---
### 1205_每月交易 II 🔒
___
#### 数据库
---
### 1206_设计跳表
___
#### 设计
___
#### 链表
---
### 1207_独一无二的出现次数
___
#### 数组
___
#### 哈希表
---
### 1208_尽可能使字符串相等
___
#### 字符串
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 1209_删除字符串中的所有相邻重复项 II
___
#### 栈
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 哈希表 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 拓扑排序 | 排序 |
| 数学 | 数据库 | 数组 |
| 数论 | 栈 | 深度优先搜索 |
| 滑动窗口 | 组合数学 | 设计 |
| 链表 |  |  |

# [1200. 最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference){#1200}

{{< tabs "1200" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        mi = min(b - a for a, b in pairwise(arr))
        return [[a, b] for a, b in pairwise(arr) if b - a == mi]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int mi = 1 << 30;
        for (int i = 0; i < n - 1; ++i) {
            mi = Math.min(mi, arr[i + 1] - arr[i]);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == mi) {
                ans.add(List.of(arr[i], arr[i + 1]));
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mi = 1 << 30;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            mi = min(mi, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == mi) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumAbsDifference(arr []int) (ans [][]int) {
	sort.Ints(arr)
	mi := 1 << 30
	n := len(arr)
	for i := 0; i < n-1; i++ {
		if t := arr[i+1] - arr[i]; t < mi {
			mi = t
		}
	}
	for i := 0; i < n-1; i++ {
		if arr[i+1]-arr[i] == mi {
			ans = append(ans, []int{arr[i], arr[i+1]})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumAbsDifference(arr: number[]): number[][] {
    arr.sort((a, b) => a - b);
    let mi = 1 << 30;
    const n = arr.length;
    for (let i = 0; i < n - 1; ++i) {
        mi = Math.min(mi, arr[i + 1] - arr[i]);
    }
    const ans: number[][] = [];
    for (let i = 0; i < n - 1; ++i) {
        if (arr[i + 1] - arr[i] === mi) {
            ans.push([arr[i], arr[i + 1]]);
        }
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

<p>给你个整数数组&nbsp;<code>arr</code>，其中每个元素都 <strong>不相同</strong>。</p>

<p>请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。</p>

<p>每对元素对 <code>[a,b</code>] 如下：</p>

<ul>
	<li><code>a ,&nbsp;b</code>&nbsp;均为数组&nbsp;<code>arr</code>&nbsp;中的元素</li>
	<li><code>a &lt; b</code></li>
	<li><code>b - a</code>&nbsp;等于 <code>arr</code> 中任意两个元素的最小绝对差</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [4,2,1,3]
<strong>输出：</strong>[[1,2],[2,3],[3,4]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,3,6,10,15]
<strong>输出：</strong>[[1,3]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,8,-10,23,19,-4,-14,27]
<strong>输出：</strong>[[-14,-10],[19,23],[23,27]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>-10^6 &lt;= arr[i] &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

根据题目描述，我们需要找出数组 $arr$ 中任意两个元素的最小绝对差，因此我们可以先对数组 $arr$ 排序，随后遍历相邻元素，得到最小绝对差 $mi$。

最后我们再遍历相邻元素，找出所有最小绝对差等于 $mi$ 的元素对。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        mi = min(b - a for a, b in pairwise(arr))
        return [[a, b] for a, b in pairwise(arr) if b - a == mi]
```

#### Java

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int mi = 1 << 30;
        for (int i = 0; i < n - 1; ++i) {
            mi = Math.min(mi, arr[i + 1] - arr[i]);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == mi) {
                ans.add(List.of(arr[i], arr[i + 1]));
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mi = 1 << 30;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            mi = min(mi, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == mi) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumAbsDifference(arr []int) (ans [][]int) {
	sort.Ints(arr)
	mi := 1 << 30
	n := len(arr)
	for i := 0; i < n-1; i++ {
		if t := arr[i+1] - arr[i]; t < mi {
			mi = t
		}
	}
	for i := 0; i < n-1; i++ {
		if arr[i+1]-arr[i] == mi {
			ans = append(ans, []int{arr[i], arr[i+1]})
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumAbsDifference(arr: number[]): number[][] {
    arr.sort((a, b) => a - b);
    let mi = 1 << 30;
    const n = arr.length;
    for (let i = 0; i < n - 1; ++i) {
        mi = Math.min(mi, arr[i + 1] - arr[i]);
    }
    const ans: number[][] = [];
    for (let i = 0; i < n - 1; ++i) {
        if (arr[i + 1] - arr[i] === mi) {
            ans.push([arr[i], arr[i + 1]]);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1201. 丑数 III](https://leetcode.cn/problems/ugly-number-iii){#1201}

{{< tabs "1201" >}}

{{% tab "python" %}}
```python
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        ab = lcm(a, b)
        bc = lcm(b, c)
        ac = lcm(a, c)
        abc = lcm(a, b, c)
        l, r = 1, 2 * 10**9
        while l < r:
            mid = (l + r) >> 1
            if (
                mid // a
                + mid // b
                + mid // c
                - mid // ab
                - mid // bc
                - mid // ac
                + mid // abc
                >= n
            ):
                r = mid
            else:
                l = mid + 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long ab = lcm(a, b);
        long bc = lcm(b, c);
        long ac = lcm(a, c);
        long abc = lcm(ab, c);
        long l = 1, r = 2000000000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) l;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);
        long long l = 1, r = 2000000000;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nthUglyNumber(n int, a int, b int, c int) int {
	ab, bc, ac := lcm(a, b), lcm(b, c), lcm(a, c)
	abc := lcm(ab, c)
	var l, r int = 1, 2e9
	for l < r {
		mid := (l + r) >> 1
		if mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc >= n {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nthUglyNumber(n: number, a: number, b: number, c: number): number {
    const ab = lcm(BigInt(a), BigInt(b));
    const bc = lcm(BigInt(b), BigInt(c));
    const ac = lcm(BigInt(a), BigInt(c));
    const abc = lcm(BigInt(a), bc);
    let l = 1n;
    let r = BigInt(2e9);
    while (l < r) {
        const mid = (l + r) >> 1n;
        const count =
            mid / BigInt(a) +
            mid / BigInt(b) +
            mid / BigInt(c) -
            mid / ab -
            mid / bc -
            mid / ac +
            mid / abc;
        if (count >= BigInt(n)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }
    return Number(l);
}

function gcd(a: bigint, b: bigint): bigint {
    return b === 0n ? a : gcd(b, a % b);
}

function lcm(a: bigint, b: bigint): bigint {
    return (a * b) / gcd(a, b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>丑数是可以被&nbsp;<code>a</code>&nbsp;<strong>或</strong>&nbsp;<code>b</code>&nbsp;<strong>或</strong> <code>c</code>&nbsp;整除的 <strong>正整数</strong> 。</p>

<p>给你四个整数：<code>n</code> 、<code>a</code> 、<code>b</code> 、<code>c</code> ，请你设计一个算法来找出第&nbsp;<code>n</code>&nbsp;个丑数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, a = 2, b = 3, c = 5
<strong>输出：</strong>4
<strong>解释：</strong>丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, a = 2, b = 3, c = 4
<strong>输出：</strong>6
<strong>解释：</strong>丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, a = 2, b = 11, c = 13
<strong>输出：</strong>10
<strong>解释：</strong>丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, a, b, c &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= a * b * c &lt;= 10<sup>18</sup></code></li>
	<li>本题结果在&nbsp;<code>[1,&nbsp;2 * 10<sup>9</sup>]</code>&nbsp;的范围内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 容斥原理

我们可以将题目转换为：找到最小的正整数 $x$，使得小于等于 $x$ 的丑数个数恰好为 $n$ 个。

对于一个正整数 $x$，能被 $a$ 整除的数有 $\left\lfloor \frac{x}{a} \right\rfloor$ 个，能被 $b$ 整除的数有 $\left\lfloor \frac{x}{b} \right\rfloor$ 个，能被 $c$ 整除的数有 $\left\lfloor \frac{x}{c} \right\rfloor$ 个，能被 $a$ 和 $b$ 同时整除的数有 $\left\lfloor \frac{x}{lcm(a, b)} \right\rfloor$ 个，能被 $a$ 和 $c$ 同时整除的数有 $\left\lfloor \frac{x}{lcm(a, c)} \right\rfloor$ 个，能被 $b$ 和 $c$ 同时整除的数有 $\left\lfloor \frac{x}{lcm(b, c)} \right\rfloor$ 个，能被 $a$, $b$ 和 $c$ 同时整除的数有 $\left\lfloor \frac{x}{lcm(a, b, c)} \right\rfloor$ 个。根据容斥原理，小于等于 $x$ 的丑数个数为：

$$
\left\lfloor \frac{x}{a} \right\rfloor + \left\lfloor \frac{x}{b} \right\rfloor + \left\lfloor \frac{x}{c} \right\rfloor - \left\lfloor \frac{x}{lcm(a, b)} \right\rfloor - \left\lfloor \frac{x}{lcm(a, c)} \right\rfloor - \left\lfloor \frac{x}{lcm(b, c)} \right\rfloor + \left\lfloor \frac{x}{lcm(a, b, c)} \right\rfloor
$$

我们可以使用二分查找的方法找到最小的正整数 $x$，使得小于等于 $x$ 的丑数个数恰好为 $n$ 个。

定义二分查找的左边界为 $l=1$，右边界为 $r=2 \times 10^9$，其中 $2 \times 10^9$ 是题目给定的最大值。在二分查找的每一步中，我们找出中间数 $mid$，如果小于等于 $mid$ 的丑数个数大于等于 $n$，那么说明最小的正整数 $x$ 落在 $[l,mid]$ 区间内，否则落在 $[mid+1,r]$ 区间内。在二分查找的过程中，我们需要不断更新小于等于 $mid$ 的丑数个数，直到找到最小的正整数 $x$。

时间复杂度 $O(\log m)$，其中 $m = 2 \times 10^9$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        ab = lcm(a, b)
        bc = lcm(b, c)
        ac = lcm(a, c)
        abc = lcm(a, b, c)
        l, r = 1, 2 * 10**9
        while l < r:
            mid = (l + r) >> 1
            if (
                mid // a
                + mid // b
                + mid // c
                - mid // ab
                - mid // bc
                - mid // ac
                + mid // abc
                >= n
            ):
                r = mid
            else:
                l = mid + 1
        return l
```

#### Java

```java
class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long ab = lcm(a, b);
        long bc = lcm(b, c);
        long ac = lcm(a, c);
        long abc = lcm(ab, c);
        long l = 1, r = 2000000000;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) l;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);
        long long l = 1, r = 2000000000;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```

#### Go

```go
func nthUglyNumber(n int, a int, b int, c int) int {
	ab, bc, ac := lcm(a, b), lcm(b, c), lcm(a, c)
	abc := lcm(ab, c)
	var l, r int = 1, 2e9
	for l < r {
		mid := (l + r) >> 1
		if mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc >= n {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```

#### TypeScript

```ts
function nthUglyNumber(n: number, a: number, b: number, c: number): number {
    const ab = lcm(BigInt(a), BigInt(b));
    const bc = lcm(BigInt(b), BigInt(c));
    const ac = lcm(BigInt(a), BigInt(c));
    const abc = lcm(BigInt(a), bc);
    let l = 1n;
    let r = BigInt(2e9);
    while (l < r) {
        const mid = (l + r) >> 1n;
        const count =
            mid / BigInt(a) +
            mid / BigInt(b) +
            mid / BigInt(c) -
            mid / ab -
            mid / bc -
            mid / ac +
            mid / abc;
        if (count >= BigInt(n)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }
    return Number(l);
}

function gcd(a: bigint, b: bigint): bigint {
    return b === 0n ? a : gcd(b, a % b);
}

function lcm(a: bigint, b: bigint): bigint {
    return (a * b) / gcd(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1202. 交换字符串中的元素](https://leetcode.cn/problems/smallest-string-with-swaps){#1202}

{{< tabs "1202" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(s)
        p = list(range(n))
        for a, b in pairs:
            p[find(a)] = find(b)
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[find(i)].append(c)
        for i in d.keys():
            d[i].sort(reverse=True)
        return "".join(d[find(i)].pop() for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        p = new int[n];
        List<Character>[] d = new List[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            d[i] = new ArrayList<>();
        }
        for (var pair : pairs) {
            int a = pair.get(0), b = pair.get(1);
            p[find(a)] = find(b);
        }
        char[] cs = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            d[find(i)].add(cs[i]);
        }
        for (var e : d) {
            e.sort((a, b) -> b - a);
        }
        for (int i = 0; i < n; ++i) {
            var e = d[find(i)];
            cs[i] = e.remove(e.size() - 1);
        }
        return String.valueOf(cs);
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        int p[n];
        iota(p, p + n, 0);
        vector<char> d[n];
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto e : pairs) {
            int a = e[0], b = e[1];
            p[find(a)] = find(b);
        }
        for (int i = 0; i < n; ++i) {
            d[find(i)].push_back(s[i]);
        }
        for (auto& e : d) {
            sort(e.rbegin(), e.rend());
        }
        for (int i = 0; i < n; ++i) {
            auto& e = d[find(i)];
            s[i] = e.back();
            e.pop_back();
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	p := make([]int, n)
	d := make([][]byte, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, pair := range pairs {
		a, b := pair[0], pair[1]
		p[find(a)] = find(b)
	}
	cs := []byte(s)
	for i, c := range cs {
		j := find(i)
		d[j] = append(d[j], c)
	}
	for i := range d {
		sort.Slice(d[i], func(a, b int) bool { return d[i][a] > d[i][b] })
	}
	for i := range cs {
		j := find(i)
		cs[i] = d[j][len(d[j])-1]
		d[j] = d[j][:len(d[j])-1]
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestStringWithSwaps(s: string, pairs: number[][]): string {
    const n = s.length;
    const p = new Array(n).fill(0).map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    const d: string[][] = new Array(n).fill(0).map(() => []);
    for (const [a, b] of pairs) {
        p[find(a)] = find(b);
    }
    for (let i = 0; i < n; ++i) {
        d[find(i)].push(s[i]);
    }
    for (const e of d) {
        e.sort((a, b) => b.charCodeAt(0) - a.charCodeAt(0));
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        ans.push(d[find(i)].pop()!);
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn smallest_string_with_swaps(s: String, pairs: Vec<Vec<i32>>) -> String {
        let n = s.as_bytes().len();
        let s = s.as_bytes();
        let mut disjoint_set: Vec<usize> = vec![0; n];
        let mut str_vec: Vec<Vec<u8>> = vec![Vec::new(); n];
        let mut ret_str = String::new();

        // Initialize the disjoint set
        for i in 0..n {
            disjoint_set[i] = i;
        }

        // Union the pairs
        for pair in pairs {
            Self::union(pair[0] as usize, pair[1] as usize, &mut disjoint_set);
        }

        // Initialize the return vector
        for (i, c) in s.iter().enumerate() {
            let p_c = Self::find(i, &mut disjoint_set);
            str_vec[p_c].push(*c);
        }

        // Sort the return vector in reverse order
        for cur_vec in &mut str_vec {
            cur_vec.sort();
            cur_vec.reverse();
        }

        // Construct the return string
        for i in 0..n {
            let index = Self::find(i, &mut disjoint_set);
            ret_str.push(str_vec[index].last().unwrap().clone() as char);
            str_vec[index].pop();
        }

        ret_str
    }

    #[allow(dead_code)]
    fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Self::find(d_set[x], d_set);
        }
        d_set[x]
    }

    #[allow(dead_code)]
    fn union(x: usize, y: usize, d_set: &mut Vec<usize>) {
        let p_x = Self::find(x, d_set);
        let p_y = Self::find(y, d_set);
        d_set[p_x] = p_y;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>，以及该字符串中的一些「索引对」数组&nbsp;<code>pairs</code>，其中&nbsp;<code>pairs[i] =&nbsp;[a, b]</code>&nbsp;表示字符串中的两个索引（编号从 0 开始）。</p>

<p>你可以 <strong>任意多次交换</strong> 在&nbsp;<code>pairs</code>&nbsp;中任意一对索引处的字符。</p>

<p>返回在经过若干次交换后，<code>s</code>&nbsp;可以变成的按字典序最小的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>s = &quot;dcab&quot;, pairs = [[0,3],[1,2]]
<strong>输出：</strong>&quot;bacd&quot;
<strong>解释：</strong> 
交换 s[0] 和 s[3], s = &quot;bcad&quot;
交换 s[1] 和 s[2], s = &quot;bacd&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;dcab&quot;, pairs = [[0,3],[1,2],[0,2]]
<strong>输出：</strong>&quot;abcd&quot;
<strong>解释：</strong>
交换 s[0] 和 s[3], s = &quot;bcad&quot;
交换 s[0] 和 s[2], s = &quot;acbd&quot;
交换 s[1] 和 s[2], s = &quot;abcd&quot;</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;cba&quot;, pairs = [[0,1],[1,2]]
<strong>输出：</strong>&quot;abc&quot;
<strong>解释：</strong>
交换 s[0] 和 s[1], s = &quot;bca&quot;
交换 s[1] 和 s[2], s = &quot;bac&quot;
交换 s[0] 和 s[1], s = &quot;abc&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= pairs[i][0], pairs[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们注意到，索引对具有传递性，即如果 $a$ 与 $b$ 可交换，而 $b$ 与 $c$ 可交换，那么 $a$ 与 $c$ 也可交换。因此，我们可以考虑使用并查集维护这些索引对的连通性，将属于同一个连通分量的字符按照字典序排序。

最后，遍历字符串，对于当前位置的字符，我们将其替换为该连通分量中最小的字符，然后从该连通分量中取出该字符，继续遍历字符串即可。

时间复杂度 $O(n \times \log n + m \times \alpha(m))$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为字符串的长度和索引对的数量，而 $\alpha$ 为阿克曼函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(s)
        p = list(range(n))
        for a, b in pairs:
            p[find(a)] = find(b)
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[find(i)].append(c)
        for i in d.keys():
            d[i].sort(reverse=True)
        return "".join(d[find(i)].pop() for i in range(n))
```

#### Java

```java
class Solution {
    private int[] p;

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        p = new int[n];
        List<Character>[] d = new List[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            d[i] = new ArrayList<>();
        }
        for (var pair : pairs) {
            int a = pair.get(0), b = pair.get(1);
            p[find(a)] = find(b);
        }
        char[] cs = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            d[find(i)].add(cs[i]);
        }
        for (var e : d) {
            e.sort((a, b) -> b - a);
        }
        for (int i = 0; i < n; ++i) {
            var e = d[find(i)];
            cs[i] = e.remove(e.size() - 1);
        }
        return String.valueOf(cs);
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        int p[n];
        iota(p, p + n, 0);
        vector<char> d[n];
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto e : pairs) {
            int a = e[0], b = e[1];
            p[find(a)] = find(b);
        }
        for (int i = 0; i < n; ++i) {
            d[find(i)].push_back(s[i]);
        }
        for (auto& e : d) {
            sort(e.rbegin(), e.rend());
        }
        for (int i = 0; i < n; ++i) {
            auto& e = d[find(i)];
            s[i] = e.back();
            e.pop_back();
        }
        return s;
    }
};
```

#### Go

```go
func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	p := make([]int, n)
	d := make([][]byte, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, pair := range pairs {
		a, b := pair[0], pair[1]
		p[find(a)] = find(b)
	}
	cs := []byte(s)
	for i, c := range cs {
		j := find(i)
		d[j] = append(d[j], c)
	}
	for i := range d {
		sort.Slice(d[i], func(a, b int) bool { return d[i][a] > d[i][b] })
	}
	for i := range cs {
		j := find(i)
		cs[i] = d[j][len(d[j])-1]
		d[j] = d[j][:len(d[j])-1]
	}
	return string(cs)
}
```

#### TypeScript

```ts
function smallestStringWithSwaps(s: string, pairs: number[][]): string {
    const n = s.length;
    const p = new Array(n).fill(0).map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    const d: string[][] = new Array(n).fill(0).map(() => []);
    for (const [a, b] of pairs) {
        p[find(a)] = find(b);
    }
    for (let i = 0; i < n; ++i) {
        d[find(i)].push(s[i]);
    }
    for (const e of d) {
        e.sort((a, b) => b.charCodeAt(0) - a.charCodeAt(0));
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        ans.push(d[find(i)].pop()!);
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn smallest_string_with_swaps(s: String, pairs: Vec<Vec<i32>>) -> String {
        let n = s.as_bytes().len();
        let s = s.as_bytes();
        let mut disjoint_set: Vec<usize> = vec![0; n];
        let mut str_vec: Vec<Vec<u8>> = vec![Vec::new(); n];
        let mut ret_str = String::new();

        // Initialize the disjoint set
        for i in 0..n {
            disjoint_set[i] = i;
        }

        // Union the pairs
        for pair in pairs {
            Self::union(pair[0] as usize, pair[1] as usize, &mut disjoint_set);
        }

        // Initialize the return vector
        for (i, c) in s.iter().enumerate() {
            let p_c = Self::find(i, &mut disjoint_set);
            str_vec[p_c].push(*c);
        }

        // Sort the return vector in reverse order
        for cur_vec in &mut str_vec {
            cur_vec.sort();
            cur_vec.reverse();
        }

        // Construct the return string
        for i in 0..n {
            let index = Self::find(i, &mut disjoint_set);
            ret_str.push(str_vec[index].last().unwrap().clone() as char);
            str_vec[index].pop();
        }

        ret_str
    }

    #[allow(dead_code)]
    fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Self::find(d_set[x], d_set);
        }
        d_set[x]
    }

    #[allow(dead_code)]
    fn union(x: usize, y: usize, d_set: &mut Vec<usize>) {
        let p_x = Self::find(x, d_set);
        let p_y = Self::find(y, d_set);
        d_set[p_x] = p_y;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1203. 项目管理](https://leetcode.cn/problems/sort-items-by-groups-respecting-dependencies){#1203}

{{< tabs "1203" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortItems(
        self, n: int, m: int, group: List[int], beforeItems: List[List[int]]
    ) -> List[int]:
        def topo_sort(degree, graph, items):
            q = deque(i for _, i in enumerate(items) if degree[i] == 0)
            res = []
            while q:
                i = q.popleft()
                res.append(i)
                for j in graph[i]:
                    degree[j] -= 1
                    if degree[j] == 0:
                        q.append(j)
            return res if len(res) == len(items) else []

        idx = m
        group_items = [[] for _ in range(n + m)]
        for i, g in enumerate(group):
            if g == -1:
                group[i] = idx
                idx += 1
            group_items[group[i]].append(i)

        item_degree = [0] * n
        group_degree = [0] * (n + m)
        item_graph = [[] for _ in range(n)]
        group_graph = [[] for _ in range(n + m)]
        for i, gi in enumerate(group):
            for j in beforeItems[i]:
                gj = group[j]
                if gi == gj:
                    item_degree[i] += 1
                    item_graph[j].append(i)
                else:
                    group_degree[gi] += 1
                    group_graph[gj].append(gi)

        group_order = topo_sort(group_degree, group_graph, range(n + m))
        if not group_order:
            return []
        ans = []
        for gi in group_order:
            items = group_items[gi]
            item_order = topo_sort(item_degree, item_graph, items)
            if len(items) != len(item_order):
                return []
            ans.extend(item_order)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        int idx = m;
        List<Integer>[] groupItems = new List[n + m];
        int[] itemDegree = new int[n];
        int[] groupDegree = new int[n + m];
        List<Integer>[] itemGraph = new List[n];
        List<Integer>[] groupGraph = new List[n + m];
        Arrays.setAll(groupItems, k -> new ArrayList<>());
        Arrays.setAll(itemGraph, k -> new ArrayList<>());
        Arrays.setAll(groupGraph, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = idx++;
            }
            groupItems[group[i]].add(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems.get(i)) {
                if (group[i] == group[j]) {
                    ++itemDegree[i];
                    itemGraph[j].add(i);
                } else {
                    ++groupDegree[group[i]];
                    groupGraph[group[j]].add(group[i]);
                }
            }
        }
        List<Integer> items = new ArrayList<>();
        for (int i = 0; i < n + m; ++i) {
            items.add(i);
        }
        var groupOrder = topoSort(groupDegree, groupGraph, items);
        if (groupOrder.isEmpty()) {
            return new int[0];
        }
        List<Integer> ans = new ArrayList<>();
        for (int gi : groupOrder) {
            items = groupItems[gi];
            var itemOrder = topoSort(itemDegree, itemGraph, items);
            if (itemOrder.size() != items.size()) {
                return new int[0];
            }
            ans.addAll(itemOrder);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }

    private List<Integer> topoSort(int[] degree, List<Integer>[] graph, List<Integer> items) {
        Deque<Integer> q = new ArrayDeque<>();
        for (int i : items) {
            if (degree[i] == 0) {
                q.offer(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int i = q.poll();
            ans.add(i);
            for (int j : graph[i]) {
                if (--degree[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return ans.size() == items.size() ? ans : List.of();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int idx = m;
        vector<vector<int>> groupItems(n + m);
        vector<int> itemDegree(n);
        vector<int> groupDegree(n + m);
        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(n + m);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = idx++;
            }
            groupItems[group[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) {
                    ++itemDegree[i];
                    itemGraph[j].push_back(i);
                } else {
                    ++groupDegree[group[i]];
                    groupGraph[group[j]].push_back(group[i]);
                }
            }
        }
        vector<int> items(n + m);
        iota(items.begin(), items.end(), 0);
        auto topoSort = [](vector<vector<int>>& graph, vector<int>& degree, vector<int>& items) -> vector<int> {
            queue<int> q;
            for (int& i : items) {
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> ans;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ans.push_back(i);
                for (int& j : graph[i]) {
                    if (--degree[j] == 0) {
                        q.push(j);
                    }
                }
            }
            return ans.size() == items.size() ? ans : vector<int>();
        };
        auto groupOrder = topoSort(groupGraph, groupDegree, items);
        if (groupOrder.empty()) {
            return vector<int>();
        }
        vector<int> ans;
        for (int& gi : groupOrder) {
            items = groupItems[gi];
            auto itemOrder = topoSort(itemGraph, itemDegree, items);
            if (items.size() != itemOrder.size()) {
                return vector<int>();
            }
            ans.insert(ans.end(), itemOrder.begin(), itemOrder.end());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortItems(n int, m int, group []int, beforeItems [][]int) []int {
	idx := m
	groupItems := make([][]int, n+m)
	itemDegree := make([]int, n)
	groupDegree := make([]int, n+m)
	itemGraph := make([][]int, n)
	groupGraph := make([][]int, n+m)
	for i, g := range group {
		if g == -1 {
			group[i] = idx
			idx++
		}
		groupItems[group[i]] = append(groupItems[group[i]], i)
	}
	for i, gi := range group {
		for _, j := range beforeItems[i] {
			gj := group[j]
			if gi == gj {
				itemDegree[i]++
				itemGraph[j] = append(itemGraph[j], i)
			} else {
				groupDegree[gi]++
				groupGraph[gj] = append(groupGraph[gj], gi)
			}
		}
	}
	items := make([]int, n+m)
	for i := range items {
		items[i] = i
	}
	topoSort := func(degree []int, graph [][]int, items []int) []int {
		q := []int{}
		for _, i := range items {
			if degree[i] == 0 {
				q = append(q, i)
			}
		}
		ans := []int{}
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			ans = append(ans, i)
			for _, j := range graph[i] {
				degree[j]--
				if degree[j] == 0 {
					q = append(q, j)
				}
			}
		}
		return ans
	}
	groupOrder := topoSort(groupDegree, groupGraph, items)
	if len(groupOrder) != len(items) {
		return nil
	}
	ans := []int{}
	for _, gi := range groupOrder {
		items = groupItems[gi]
		itemOrder := topoSort(itemDegree, itemGraph, items)
		if len(items) != len(itemOrder) {
			return nil
		}
		ans = append(ans, itemOrder...)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortItems(n: number, m: number, group: number[], beforeItems: number[][]): number[] {
    let idx = m;
    const groupItems: number[][] = new Array(n + m).fill(0).map(() => []);
    const itemDegree: number[] = new Array(n).fill(0);
    const gorupDegree: number[] = new Array(n + m).fill(0);
    const itemGraph: number[][] = new Array(n).fill(0).map(() => []);
    const groupGraph: number[][] = new Array(n + m).fill(0).map(() => []);
    for (let i = 0; i < n; ++i) {
        if (group[i] === -1) {
            group[i] = idx++;
        }
        groupItems[group[i]].push(i);
    }
    for (let i = 0; i < n; ++i) {
        for (const j of beforeItems[i]) {
            if (group[i] === group[j]) {
                ++itemDegree[i];
                itemGraph[j].push(i);
            } else {
                ++gorupDegree[group[i]];
                groupGraph[group[j]].push(group[i]);
            }
        }
    }
    let items = new Array(n + m).fill(0).map((_, i) => i);
    const topoSort = (graph: number[][], degree: number[], items: number[]): number[] => {
        const q: number[] = [];
        for (const i of items) {
            if (degree[i] === 0) {
                q.push(i);
            }
        }
        const ans: number[] = [];
        while (q.length) {
            const i = q.pop()!;
            ans.push(i);
            for (const j of graph[i]) {
                if (--degree[j] === 0) {
                    q.push(j);
                }
            }
        }
        return ans.length === items.length ? ans : [];
    };
    const groupOrder = topoSort(groupGraph, gorupDegree, items);
    if (groupOrder.length === 0) {
        return [];
    }
    const ans: number[] = [];
    for (const gi of groupOrder) {
        items = groupItems[gi];
        const itemOrder = topoSort(itemGraph, itemDegree, items);
        if (itemOrder.length !== items.length) {
            return [];
        }
        ans.push(...itemOrder);
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

<p>有 <code>n</code> 个项目，每个项目或者不属于任何小组，或者属于 <code>m</code> 个小组之一。<code>group[i]</code> 表示第 <code>i</code> 个项目所属的小组，如果第 <code>i</code> 个项目不属于任何小组，则 <code>group[i]</code> 等于 <code>-1</code>。项目和小组都是从零开始编号的。可能存在小组不负责任何项目，即没有任何项目属于这个小组。</p>

<p>请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：</p>

<ul>
	<li>同一小组的项目，排序后在列表中彼此相邻。</li>
	<li>项目之间存在一定的依赖关系，我们用一个列表 <code>beforeItems</code> 来表示，其中 <code>beforeItems[i]</code> 表示在进行第 <code>i</code> 个项目前（位于第 <code>i</code> 个项目左侧）应该完成的所有项目。</li>
</ul>

<p>如果存在多个解决方案，只需要返回其中任意一个即可。如果没有合适的解决方案，就请返回一个 <strong>空列表 </strong>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1203.Sort%20Items%20by%20Groups%20Respecting%20Dependencies/images/1359_ex1.png" style="height: 181px; width: 191px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
<strong>输出：</strong>[6,3,4,1,5,2,0,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
<strong>输出：</strong>[]
<strong>解释：</strong>与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m <= n <= 3 * 10<sup>4</sup></code></li>
	<li><code>group.length == beforeItems.length == n</code></li>
	<li><code>-1 <= group[i] <= m - 1</code></li>
	<li><code>0 <= beforeItems[i].length <= n - 1</code></li>
	<li><code>0 <= beforeItems[i][j] <= n - 1</code></li>
	<li><code>i != beforeItems[i][j]</code></li>
	<li><code>beforeItems[i]</code> 不含重复元素</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们先遍历数组 $group$，对于每个项目，如果其不属于任何小组，则将其新建一个小组，编号为 $m$，并将 $m$ 的值加一。这样我们就能保证所有项目都属于某个小组了。然后，我们用一个数组 $groupItems$ 记录每个小组包含的项目，数组下标为小组编号，数组值为包含的项目列表。

接下来，我们需要建图。对于每个项目，我们需要建立两种图，一种是项目间的图，一种是小组间的图。我们遍历数组 $group$，对于当前项目 $i$，它所在的小组为 $group[i]$，我们遍历 $beforeItems[i]$，对于其中的每个项目 $j$，如果 $group[i] = group[j]$，说明 $i$ 和 $j$ 属于同一小组，我们在项目图中添加一条 $j \to i$ 的边，否则说明 $i$ 和 $j$ 属于不同的小组，我们在小组间的图中添加一条 $group[j] \to group[i]$ 的边，并且更新对应的入度数组。

接下来，我们先对小组间的图进行拓扑排序，得到排序后的小组列表 $groupOrder$，如果排序后的列表长度不等于小组总数，说明无法完成排序，返回空列表。否则，我们遍历 $groupOrder$，对于其中的每个小组 $gi$，我们将该小组包含的项目列表 $groupItems[gi]$ 进行拓扑排序，得到排序后的项目列表 $itemOrder$，如果排序后的列表长度不等于该小组包含的项目总数，说明无法完成排序，返回空列表。否则，我们将 $itemOrder$ 中的项目加入答案数组中，最终返回该答案数组即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是项目总数和小组总数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortItems(
        self, n: int, m: int, group: List[int], beforeItems: List[List[int]]
    ) -> List[int]:
        def topo_sort(degree, graph, items):
            q = deque(i for _, i in enumerate(items) if degree[i] == 0)
            res = []
            while q:
                i = q.popleft()
                res.append(i)
                for j in graph[i]:
                    degree[j] -= 1
                    if degree[j] == 0:
                        q.append(j)
            return res if len(res) == len(items) else []

        idx = m
        group_items = [[] for _ in range(n + m)]
        for i, g in enumerate(group):
            if g == -1:
                group[i] = idx
                idx += 1
            group_items[group[i]].append(i)

        item_degree = [0] * n
        group_degree = [0] * (n + m)
        item_graph = [[] for _ in range(n)]
        group_graph = [[] for _ in range(n + m)]
        for i, gi in enumerate(group):
            for j in beforeItems[i]:
                gj = group[j]
                if gi == gj:
                    item_degree[i] += 1
                    item_graph[j].append(i)
                else:
                    group_degree[gi] += 1
                    group_graph[gj].append(gi)

        group_order = topo_sort(group_degree, group_graph, range(n + m))
        if not group_order:
            return []
        ans = []
        for gi in group_order:
            items = group_items[gi]
            item_order = topo_sort(item_degree, item_graph, items)
            if len(items) != len(item_order):
                return []
            ans.extend(item_order)
        return ans
```

#### Java

```java
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        int idx = m;
        List<Integer>[] groupItems = new List[n + m];
        int[] itemDegree = new int[n];
        int[] groupDegree = new int[n + m];
        List<Integer>[] itemGraph = new List[n];
        List<Integer>[] groupGraph = new List[n + m];
        Arrays.setAll(groupItems, k -> new ArrayList<>());
        Arrays.setAll(itemGraph, k -> new ArrayList<>());
        Arrays.setAll(groupGraph, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = idx++;
            }
            groupItems[group[i]].add(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems.get(i)) {
                if (group[i] == group[j]) {
                    ++itemDegree[i];
                    itemGraph[j].add(i);
                } else {
                    ++groupDegree[group[i]];
                    groupGraph[group[j]].add(group[i]);
                }
            }
        }
        List<Integer> items = new ArrayList<>();
        for (int i = 0; i < n + m; ++i) {
            items.add(i);
        }
        var groupOrder = topoSort(groupDegree, groupGraph, items);
        if (groupOrder.isEmpty()) {
            return new int[0];
        }
        List<Integer> ans = new ArrayList<>();
        for (int gi : groupOrder) {
            items = groupItems[gi];
            var itemOrder = topoSort(itemDegree, itemGraph, items);
            if (itemOrder.size() != items.size()) {
                return new int[0];
            }
            ans.addAll(itemOrder);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }

    private List<Integer> topoSort(int[] degree, List<Integer>[] graph, List<Integer> items) {
        Deque<Integer> q = new ArrayDeque<>();
        for (int i : items) {
            if (degree[i] == 0) {
                q.offer(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            int i = q.poll();
            ans.add(i);
            for (int j : graph[i]) {
                if (--degree[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return ans.size() == items.size() ? ans : List.of();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int idx = m;
        vector<vector<int>> groupItems(n + m);
        vector<int> itemDegree(n);
        vector<int> groupDegree(n + m);
        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(n + m);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = idx++;
            }
            groupItems[group[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) {
                    ++itemDegree[i];
                    itemGraph[j].push_back(i);
                } else {
                    ++groupDegree[group[i]];
                    groupGraph[group[j]].push_back(group[i]);
                }
            }
        }
        vector<int> items(n + m);
        iota(items.begin(), items.end(), 0);
        auto topoSort = [](vector<vector<int>>& graph, vector<int>& degree, vector<int>& items) -> vector<int> {
            queue<int> q;
            for (int& i : items) {
                if (degree[i] == 0) {
                    q.push(i);
                }
            }
            vector<int> ans;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                ans.push_back(i);
                for (int& j : graph[i]) {
                    if (--degree[j] == 0) {
                        q.push(j);
                    }
                }
            }
            return ans.size() == items.size() ? ans : vector<int>();
        };
        auto groupOrder = topoSort(groupGraph, groupDegree, items);
        if (groupOrder.empty()) {
            return vector<int>();
        }
        vector<int> ans;
        for (int& gi : groupOrder) {
            items = groupItems[gi];
            auto itemOrder = topoSort(itemGraph, itemDegree, items);
            if (items.size() != itemOrder.size()) {
                return vector<int>();
            }
            ans.insert(ans.end(), itemOrder.begin(), itemOrder.end());
        }
        return ans;
    }
};
```

#### Go

```go
func sortItems(n int, m int, group []int, beforeItems [][]int) []int {
	idx := m
	groupItems := make([][]int, n+m)
	itemDegree := make([]int, n)
	groupDegree := make([]int, n+m)
	itemGraph := make([][]int, n)
	groupGraph := make([][]int, n+m)
	for i, g := range group {
		if g == -1 {
			group[i] = idx
			idx++
		}
		groupItems[group[i]] = append(groupItems[group[i]], i)
	}
	for i, gi := range group {
		for _, j := range beforeItems[i] {
			gj := group[j]
			if gi == gj {
				itemDegree[i]++
				itemGraph[j] = append(itemGraph[j], i)
			} else {
				groupDegree[gi]++
				groupGraph[gj] = append(groupGraph[gj], gi)
			}
		}
	}
	items := make([]int, n+m)
	for i := range items {
		items[i] = i
	}
	topoSort := func(degree []int, graph [][]int, items []int) []int {
		q := []int{}
		for _, i := range items {
			if degree[i] == 0 {
				q = append(q, i)
			}
		}
		ans := []int{}
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			ans = append(ans, i)
			for _, j := range graph[i] {
				degree[j]--
				if degree[j] == 0 {
					q = append(q, j)
				}
			}
		}
		return ans
	}
	groupOrder := topoSort(groupDegree, groupGraph, items)
	if len(groupOrder) != len(items) {
		return nil
	}
	ans := []int{}
	for _, gi := range groupOrder {
		items = groupItems[gi]
		itemOrder := topoSort(itemDegree, itemGraph, items)
		if len(items) != len(itemOrder) {
			return nil
		}
		ans = append(ans, itemOrder...)
	}
	return ans
}
```

#### TypeScript

```ts
function sortItems(n: number, m: number, group: number[], beforeItems: number[][]): number[] {
    let idx = m;
    const groupItems: number[][] = new Array(n + m).fill(0).map(() => []);
    const itemDegree: number[] = new Array(n).fill(0);
    const gorupDegree: number[] = new Array(n + m).fill(0);
    const itemGraph: number[][] = new Array(n).fill(0).map(() => []);
    const groupGraph: number[][] = new Array(n + m).fill(0).map(() => []);
    for (let i = 0; i < n; ++i) {
        if (group[i] === -1) {
            group[i] = idx++;
        }
        groupItems[group[i]].push(i);
    }
    for (let i = 0; i < n; ++i) {
        for (const j of beforeItems[i]) {
            if (group[i] === group[j]) {
                ++itemDegree[i];
                itemGraph[j].push(i);
            } else {
                ++gorupDegree[group[i]];
                groupGraph[group[j]].push(group[i]);
            }
        }
    }
    let items = new Array(n + m).fill(0).map((_, i) => i);
    const topoSort = (graph: number[][], degree: number[], items: number[]): number[] => {
        const q: number[] = [];
        for (const i of items) {
            if (degree[i] === 0) {
                q.push(i);
            }
        }
        const ans: number[] = [];
        while (q.length) {
            const i = q.pop()!;
            ans.push(i);
            for (const j of graph[i]) {
                if (--degree[j] === 0) {
                    q.push(j);
                }
            }
        }
        return ans.length === items.length ? ans : [];
    };
    const groupOrder = topoSort(groupGraph, gorupDegree, items);
    if (groupOrder.length === 0) {
        return [];
    }
    const ans: number[] = [];
    for (const gi of groupOrder) {
        items = groupItems[gi];
        const itemOrder = topoSort(itemGraph, itemDegree, items);
        if (itemOrder.length !== items.length) {
            return [];
        }
        ans.push(...itemOrder);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1204. 最后一个能进入巴士的人](https://leetcode.cn/problems/last-person-to-fit-in-the-bus){#1204}

{{< tabs "1204" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            person_name,
            SUM(weight) OVER (ORDER BY turn) AS s
        FROM Queue
    )
SELECT person_name
FROM T
WHERE s <= 1000
ORDER BY s DESC
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Queue</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| person_name | varchar |
| weight      | int     |
| turn        | int     |
+-------------+---------+
person_id 是这个表具有唯一值的列。
该表展示了所有候车乘客的信息。
表中 person_id 和 turn 列将包含从 1 到 n 的所有数字，其中 n 是表中的行数。
turn 决定了候车乘客上巴士的顺序，其中 turn=1 表示第一个上巴士，turn=n 表示最后一个上巴士。
weight 表示候车乘客的体重，以千克为单位。
</pre>

<p>&nbsp;</p>

<p>有一队乘客在等着上巴士。然而，巴士有<code>1000</code>&nbsp; <strong>千克</strong> 的重量限制，所以其中一部分乘客可能无法上巴士。</p>

<p>编写解决方案找出 <strong>最后一个</strong> 上巴士且不超过重量限制的乘客，并报告 <code>person_name</code> 。题目测试用例确保顺位第一的人可以上巴士且不会超重。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Queue 表
+-----------+-------------+--------+------+
| person_id | person_name | weight | turn |
+-----------+-------------+--------+------+
| 5         | Alice       | 250    | 1    |
| 4         | Bob         | 175    | 5    |
| 3         | Alex        | 350    | 2    |
| 6         | John Cena   | 400    | 3    |
| 1         | Winston     | 500    | 6    |
| 2         | Marie       | 200    | 4    |
+-----------+-------------+--------+------+
<strong>输出：</strong>
+-------------+
| person_name |
+-------------+
| John Cena   |
+-------------+
<strong>解释：</strong>
为了简化，Queue 表按 turn 列由小到大排序。
+------+----+-----------+--------+--------------+
| Turn | ID | Name      | Weight | Total Weight |
+------+----+-----------+--------+--------------+
| 1    | 5  | Alice     | 250    | 250          |
| 2    | 3  | Alex      | 350    | 600          |
| 3    | 6  | John Cena | 400    | 1000         | (最后一个上巴士)
| 4    | 2  | Marie     | 200    | 1200         | (无法上巴士)
| 5    | 4  | Bob       | 175    | ___          |
| 6    | 1  | Winston   | 500    | ___          |
+------+----+-----------+--------+--------------+</pre>

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
SELECT a.person_name
FROM
    Queue AS a,
    Queue AS b
WHERE a.turn >= b.turn
GROUP BY a.person_id
HAVING SUM(b.weight) <= 1000
ORDER BY a.turn DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            person_name,
            SUM(weight) OVER (ORDER BY turn) AS s
        FROM Queue
    )
SELECT person_name
FROM T
WHERE s <= 1000
ORDER BY s DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1205. 每月交易 II 🔒](https://leetcode.cn/problems/monthly-transactions-ii){#1205}

{{< tabs "1205" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT * FROM Transactions
        UNION
        SELECT id, country, 'chargeback', amount, c.trans_date
        FROM
            Transactions AS t
            JOIN Chargebacks AS c ON t.id = c.trans_id
    )
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    SUM(state = 'approved') AS approved_count,
    SUM(IF(state = 'approved', amount, 0)) AS approved_amount,
    SUM(state = 'chargeback') AS chargeback_count,
    SUM(IF(state = 'chargeback', amount, 0)) AS chargeback_amount
FROM T
GROUP BY 1, 2
HAVING approved_amount OR chargeback_amount;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Transactions</code> 记录表</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| id             | int     |
| country        | varchar |
| state          | enum    |
| amount         | int     |
| trans_date     | date    |
+----------------+---------+
id 是这个表的主键。
该表包含有关传入事务的信息。
状态列是枚举类型，值为 [approved、declined] 其中之一的列。</pre>

<p><code>Chargebacks</code> 表</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| trans_id       | int     |
| trans_date     | date    |
+----------------+---------+
退单包含有关放置在事务表中的某些事务的传入退单的基本信息。
trans_id 是 transactions 表的 id 列的外键（reference 列）。
每项退单都对应于之前进行的交易，即使未经批准。</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，找出每个国家/地区的每月交易信息：已批准交易的数量及其总金额、退单的数量及其总金额。</p>

<p><strong>注意：</strong>在你的解决方案中，只需显示给定月份和国家，忽略所有为零的行。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Transactions 表：
+-----+---------+----------+--------+------------+
| id  | country | state    | amount | trans_date |
+-----+---------+----------+--------+------------+
| 101 | US      | approved | 1000   | 2019-05-18 |
| 102 | US      | declined | 2000   | 2019-05-19 |
| 103 | US      | approved | 3000   | 2019-06-10 |
| 104 | US      | declined | 4000   | 2019-06-13 |
| 105 | US      | approved | 5000   | 2019-06-15 |
+-----+---------+----------+--------+------------+
Chargebacks 表：
+----------+------------+
| trans_id | trans_date |
+----------+------------+
| 102      | 2019-05-29 |
| 101      | 2019-06-30 |
| 105      | 2019-09-18 |
+----------+------------+
<strong>输出：</strong>
+---------+---------+----------------+-----------------+------------------+-------------------+
| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
+---------+---------+----------------+-----------------+------------------+-------------------+
| 2019-05 | US      | 1              | 1000            | 1                | 2000              |
| 2019-06 | US      | 2              | 8000            | 1                | 1000              |
| 2019-09 | US      | 0              | 0               | 1                | 5000              |
+---------+---------+----------------+-----------------+------------------+-------------------+</pre>

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
    T AS (
        SELECT * FROM Transactions
        UNION
        SELECT id, country, 'chargeback', amount, c.trans_date
        FROM
            Transactions AS t
            JOIN Chargebacks AS c ON t.id = c.trans_id
    )
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    SUM(state = 'approved') AS approved_count,
    SUM(IF(state = 'approved', amount, 0)) AS approved_amount,
    SUM(state = 'chargeback') AS chargeback_count,
    SUM(IF(state = 'chargeback', amount, 0)) AS chargeback_amount
FROM T
GROUP BY 1, 2
HAVING approved_amount OR chargeback_amount;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1206. 设计跳表](https://leetcode.cn/problems/design-skiplist){#1206}

{{< tabs "1206" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ['val', 'next']

    def __init__(self, val: int, level: int):
        self.val = val
        self.next = [None] * level


class Skiplist:
    max_level = 32
    p = 0.25

    def __init__(self):
        self.head = Node(-1, self.max_level)
        self.level = 0

    def search(self, target: int) -> bool:
        curr = self.head
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, target)
            if curr.next[i] and curr.next[i].val == target:
                return True
        return False

    def add(self, num: int) -> None:
        curr = self.head
        level = self.random_level()
        node = Node(num, level)
        self.level = max(self.level, level)
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, num)
            if i < level:
                node.next[i] = curr.next[i]
                curr.next[i] = node

    def erase(self, num: int) -> bool:
        curr = self.head
        ok = False
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, num)
            if curr.next[i] and curr.next[i].val == num:
                curr.next[i] = curr.next[i].next[i]
                ok = True
        while self.level > 1 and self.head.next[self.level - 1] is None:
            self.level -= 1
        return ok

    def find_closest(self, curr: Node, level: int, target: int) -> Node:
        while curr.next[level] and curr.next[level].val < target:
            curr = curr.next[level]
        return curr

    def random_level(self) -> int:
        level = 1
        while level < self.max_level and random.random() < self.p:
            level += 1
        return level


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Skiplist {
    private static final int MAX_LEVEL = 32;
    private static final double P = 0.25;
    private static final Random RANDOM = new Random();
    private final Node head = new Node(-1, MAX_LEVEL);
    private int level = 0;

    public Skiplist() {
    }

    public boolean search(int target) {
        Node curr = head;
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, target);
            if (curr.next[i] != null && curr.next[i].val == target) {
                return true;
            }
        }
        return false;
    }

    public void add(int num) {
        Node curr = head;
        int lv = randomLevel();
        Node node = new Node(num, lv);
        level = Math.max(level, lv);
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, num);
            if (i < lv) {
                node.next[i] = curr.next[i];
                curr.next[i] = node;
            }
        }
    }

    public boolean erase(int num) {
        Node curr = head;
        boolean ok = false;
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, num);
            if (curr.next[i] != null && curr.next[i].val == num) {
                curr.next[i] = curr.next[i].next[i];
                ok = true;
            }
        }
        while (level > 1 && head.next[level - 1] == null) {
            --level;
        }
        return ok;
    }

    private Node findClosest(Node curr, int level, int target) {
        while (curr.next[level] != null && curr.next[level].val < target) {
            curr = curr.next[level];
        }
        return curr;
    }

    private static int randomLevel() {
        int level = 1;
        while (level < MAX_LEVEL && RANDOM.nextDouble() < P) {
            ++level;
        }
        return level;
    }

    static class Node {
        int val;
        Node[] next;

        Node(int val, int level) {
            this.val = val;
            next = new Node[level];
        }
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
struct Node {
    int val;
    vector<Node*> next;
    Node(int v, int level)
        : val(v)
        , next(level, nullptr) {}
};

class Skiplist {
public:
    const int p = RAND_MAX / 4;
    const int maxLevel = 32;
    Node* head;
    int level;

    Skiplist() {
        head = new Node(-1, maxLevel);
        level = 0;
    }

    bool search(int target) {
        Node* curr = head;
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, target);
            if (curr->next[i] && curr->next[i]->val == target) return true;
        }
        return false;
    }

    void add(int num) {
        Node* curr = head;
        int lv = randomLevel();
        Node* node = new Node(num, lv);
        level = max(level, lv);
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, num);
            if (i < lv) {
                node->next[i] = curr->next[i];
                curr->next[i] = node;
            }
        }
    }

    bool erase(int num) {
        Node* curr = head;
        bool ok = false;
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, num);
            if (curr->next[i] && curr->next[i]->val == num) {
                curr->next[i] = curr->next[i]->next[i];
                ok = true;
            }
        }
        while (level > 1 && !head->next[level - 1]) --level;
        return ok;
    }

    Node* findClosest(Node* curr, int level, int target) {
        while (curr->next[level] && curr->next[level]->val < target) curr = curr->next[level];
        return curr;
    }

    int randomLevel() {
        int lv = 1;
        while (lv < maxLevel && rand() < p) ++lv;
        return lv;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
func init() { rand.Seed(time.Now().UnixNano()) }

const (
	maxLevel = 16
	p        = 0.5
)

type node struct {
	val  int
	next []*node
}

func newNode(val, level int) *node {
	return &node{
		val:  val,
		next: make([]*node, level),
	}
}

type Skiplist struct {
	head  *node
	level int
}

func Constructor() Skiplist {
	return Skiplist{
		head:  newNode(-1, maxLevel),
		level: 1,
	}
}

func (this *Skiplist) Search(target int) bool {
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, target)
		if p.next[i] != nil && p.next[i].val == target {
			return true
		}
	}
	return false
}

func (this *Skiplist) Add(num int) {
	level := randomLevel()
	if level > this.level {
		this.level = level
	}
	node := newNode(num, level)
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, num)
		if i < level {
			node.next[i] = p.next[i]
			p.next[i] = node
		}
	}
}

func (this *Skiplist) Erase(num int) bool {
	ok := false
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, num)
		if p.next[i] != nil && p.next[i].val == num {
			p.next[i] = p.next[i].next[i]
			ok = true
		}
	}
	for this.level > 1 && this.head.next[this.level-1] == nil {
		this.level--
	}
	return ok
}

func findClosest(p *node, level, target int) *node {
	for p.next[level] != nil && p.next[level].val < target {
		p = p.next[level]
	}
	return p
}

func randomLevel() int {
	level := 1
	for level < maxLevel && rand.Float64() < p {
		level++
	}
	return level
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Search(target);
 * obj.Add(num);
 * param_3 := obj.Erase(num);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    val: number;
    next: (Node | null)[];

    constructor(val: number, level: number) {
        this.val = val;
        this.next = Array(level).fill(null);
    }
}

class Skiplist {
    private static maxLevel: number = 32;
    private static p: number = 0.25;
    private head: Node;
    private level: number;

    constructor() {
        this.head = new Node(-1, Skiplist.maxLevel);
        this.level = 0;
    }

    search(target: number): boolean {
        let curr = this.head;
        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, target);
            if (curr.next[i] && curr.next[i]!.val === target) {
                return true;
            }
        }
        return false;
    }

    add(num: number): void {
        let curr = this.head;
        const level = this.randomLevel();
        const node = new Node(num, level);
        this.level = Math.max(this.level, level);

        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, num);
            if (i < level) {
                node.next[i] = curr.next[i];
                curr.next[i] = node;
            }
        }
    }

    erase(num: number): boolean {
        let curr = this.head;
        let ok = false;

        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, num);
            if (curr.next[i] && curr.next[i]!.val === num) {
                curr.next[i] = curr.next[i]!.next[i];
                ok = true;
            }
        }

        while (this.level > 1 && this.head.next[this.level - 1] === null) {
            this.level--;
        }

        return ok;
    }

    private findClosest(curr: Node, level: number, target: number): Node {
        while (curr.next[level] && curr.next[level]!.val < target) {
            curr = curr.next[level]!;
        }
        return curr;
    }

    private randomLevel(): number {
        let level = 1;
        while (level < Skiplist.maxLevel && Math.random() < Skiplist.p) {
            level++;
        }
        return level;
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * var obj = new Skiplist()
 * var param_1 = obj.search(target)
 * obj.add(num)
 * var param_3 = obj.erase(num)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>不使用任何库函数，设计一个 <strong>跳表</strong> 。</p>

<p><strong>跳表</strong> 是在 <code>O(log(n))</code> 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。</p>

<p>例如，一个跳表包含 <code>[30, 40, 50, 60, 70, 90]</code> ，然后增加 <code>80</code>、<code>45</code> 到跳表中，以下图的方式操作：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1206.Design%20Skiplist/images/1702370216-mKQcTt-1506_skiplist.gif" style="width: 500px; height: 173px;" /></p>

<p>跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 <code>O(n)</code>。跳表的每一个操作的平均时间复杂度是 <code>O(log(n))</code>，空间复杂度是 <code>O(n)</code>。</p>

<p>了解更多 :&nbsp;<a href="https://oi-wiki.org/ds/skiplist/" target="_blank">https://oi-wiki.org/ds/skiplist/</a></p>

<p>在本题中，你的设计应该要包含这些函数：</p>

<ul>
	<li><code>bool search(int target)</code> : 返回target是否存在于跳表中。</li>
	<li><code>void add(int num)</code>:&nbsp;插入一个元素到跳表。</li>
	<li><code>bool erase(int num)</code>: 在跳表中删除一个值，如果&nbsp;<code>num</code>&nbsp;不存在，直接返回false. 如果存在多个&nbsp;<code>num</code>&nbsp;，删除其中任意一个即可。</li>
</ul>

<p>注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入</b>
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
<strong>输出</strong>
[null, null, null, null, false, null, true, false, true, false]

<strong>解释</strong>
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= num, target &lt;= 2 * 10<sup>4</sup></code></li>
	<li>调用<code>search</code>, <code>add</code>, &nbsp;<code>erase</code>操作次数不大于&nbsp;<code>5 * 10<sup>4</sup></code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数据结构

跳表的核心思想是使用多个“层级”来存储数据，每一层都相当于一个索引。数据从底层的链表开始逐渐上升到更高层级的链表，最终形成一个多层链表结构。每一层的节点只包含部分数据，这样就可以通过跳跃来减少查找的时间。

在这个问题中，我们使用一个 $\textit{Node}$ 类来表示跳表的节点，每个节点包含一个 $\textit{val}$ 域和一个 $\textit{next}$ 数组，数组的长度为 $\textit{level}$，表示当前节点在每一层的下一个节点。我们使用一个 $\textit{Skiplist}$ 类来实现跳表的操作。

跳表包含一个头节点 $\textit{head}$ 和当前的最大层数 $\textit{level}$。头节点的值设为 $-1$，用于标识链表的起始位置。我们使用一个动态数组 $\textit{next}$ 来存储指向后继节点的指针。

对于 $\textit{search}$ 操作，我们从跳表的最高层开始，逐层向下遍历，直到找到目标节点或者确定目标节点不存在。每层都通过 $\textit{find\_closest}$ 方法跳跃到最接近目标的节点。

对于 $\textit{add}$ 操作，我们首先随机决定新节点的层数。然后，从最高层开始，逐层找到每层中最接近新值的节点，并在相应位置插入新节点。如果插入的层数大于当前跳表的最大层数，我们需要更新跳表的层数。

对于 $\textit{erase}$ 操作，类似于查找操作，遍历跳表的每一层，找到需要删除的节点并删除它。删除节点时需要更新每一层的 $\textit{next}$ 指针。如果跳表的最高层没有节点，则需要减少跳表的层数。

另外，我们定义了一个 $\textit{random\_level}$ 方法来随机决定新节点的层数。该方法会生成一个 $[1, \textit{max\_level}]$ 之间的随机数，直到生成的随机数大于等于 $\textit{p}$ 为止。还有一个 $\textit{find\_closest}$ 方法用于查找每一层中最接近目标值的节点。

上述操作的时间复杂度为 $O(\log n)$，其中 $n$ 为跳表的节点数。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ['val', 'next']

    def __init__(self, val: int, level: int):
        self.val = val
        self.next = [None] * level


class Skiplist:
    max_level = 32
    p = 0.25

    def __init__(self):
        self.head = Node(-1, self.max_level)
        self.level = 0

    def search(self, target: int) -> bool:
        curr = self.head
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, target)
            if curr.next[i] and curr.next[i].val == target:
                return True
        return False

    def add(self, num: int) -> None:
        curr = self.head
        level = self.random_level()
        node = Node(num, level)
        self.level = max(self.level, level)
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, num)
            if i < level:
                node.next[i] = curr.next[i]
                curr.next[i] = node

    def erase(self, num: int) -> bool:
        curr = self.head
        ok = False
        for i in range(self.level - 1, -1, -1):
            curr = self.find_closest(curr, i, num)
            if curr.next[i] and curr.next[i].val == num:
                curr.next[i] = curr.next[i].next[i]
                ok = True
        while self.level > 1 and self.head.next[self.level - 1] is None:
            self.level -= 1
        return ok

    def find_closest(self, curr: Node, level: int, target: int) -> Node:
        while curr.next[level] and curr.next[level].val < target:
            curr = curr.next[level]
        return curr

    def random_level(self) -> int:
        level = 1
        while level < self.max_level and random.random() < self.p:
            level += 1
        return level


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
```

#### Java

```java
class Skiplist {
    private static final int MAX_LEVEL = 32;
    private static final double P = 0.25;
    private static final Random RANDOM = new Random();
    private final Node head = new Node(-1, MAX_LEVEL);
    private int level = 0;

    public Skiplist() {
    }

    public boolean search(int target) {
        Node curr = head;
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, target);
            if (curr.next[i] != null && curr.next[i].val == target) {
                return true;
            }
        }
        return false;
    }

    public void add(int num) {
        Node curr = head;
        int lv = randomLevel();
        Node node = new Node(num, lv);
        level = Math.max(level, lv);
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, num);
            if (i < lv) {
                node.next[i] = curr.next[i];
                curr.next[i] = node;
            }
        }
    }

    public boolean erase(int num) {
        Node curr = head;
        boolean ok = false;
        for (int i = level - 1; i >= 0; --i) {
            curr = findClosest(curr, i, num);
            if (curr.next[i] != null && curr.next[i].val == num) {
                curr.next[i] = curr.next[i].next[i];
                ok = true;
            }
        }
        while (level > 1 && head.next[level - 1] == null) {
            --level;
        }
        return ok;
    }

    private Node findClosest(Node curr, int level, int target) {
        while (curr.next[level] != null && curr.next[level].val < target) {
            curr = curr.next[level];
        }
        return curr;
    }

    private static int randomLevel() {
        int level = 1;
        while (level < MAX_LEVEL && RANDOM.nextDouble() < P) {
            ++level;
        }
        return level;
    }

    static class Node {
        int val;
        Node[] next;

        Node(int val, int level) {
            this.val = val;
            next = new Node[level];
        }
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
```

#### C++

```cpp
struct Node {
    int val;
    vector<Node*> next;
    Node(int v, int level)
        : val(v)
        , next(level, nullptr) {}
};

class Skiplist {
public:
    const int p = RAND_MAX / 4;
    const int maxLevel = 32;
    Node* head;
    int level;

    Skiplist() {
        head = new Node(-1, maxLevel);
        level = 0;
    }

    bool search(int target) {
        Node* curr = head;
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, target);
            if (curr->next[i] && curr->next[i]->val == target) return true;
        }
        return false;
    }

    void add(int num) {
        Node* curr = head;
        int lv = randomLevel();
        Node* node = new Node(num, lv);
        level = max(level, lv);
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, num);
            if (i < lv) {
                node->next[i] = curr->next[i];
                curr->next[i] = node;
            }
        }
    }

    bool erase(int num) {
        Node* curr = head;
        bool ok = false;
        for (int i = level - 1; ~i; --i) {
            curr = findClosest(curr, i, num);
            if (curr->next[i] && curr->next[i]->val == num) {
                curr->next[i] = curr->next[i]->next[i];
                ok = true;
            }
        }
        while (level > 1 && !head->next[level - 1]) --level;
        return ok;
    }

    Node* findClosest(Node* curr, int level, int target) {
        while (curr->next[level] && curr->next[level]->val < target) curr = curr->next[level];
        return curr;
    }

    int randomLevel() {
        int lv = 1;
        while (lv < maxLevel && rand() < p) ++lv;
        return lv;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```

#### Go

```go
func init() { rand.Seed(time.Now().UnixNano()) }

const (
	maxLevel = 16
	p        = 0.5
)

type node struct {
	val  int
	next []*node
}

func newNode(val, level int) *node {
	return &node{
		val:  val,
		next: make([]*node, level),
	}
}

type Skiplist struct {
	head  *node
	level int
}

func Constructor() Skiplist {
	return Skiplist{
		head:  newNode(-1, maxLevel),
		level: 1,
	}
}

func (this *Skiplist) Search(target int) bool {
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, target)
		if p.next[i] != nil && p.next[i].val == target {
			return true
		}
	}
	return false
}

func (this *Skiplist) Add(num int) {
	level := randomLevel()
	if level > this.level {
		this.level = level
	}
	node := newNode(num, level)
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, num)
		if i < level {
			node.next[i] = p.next[i]
			p.next[i] = node
		}
	}
}

func (this *Skiplist) Erase(num int) bool {
	ok := false
	p := this.head
	for i := this.level - 1; i >= 0; i-- {
		p = findClosest(p, i, num)
		if p.next[i] != nil && p.next[i].val == num {
			p.next[i] = p.next[i].next[i]
			ok = true
		}
	}
	for this.level > 1 && this.head.next[this.level-1] == nil {
		this.level--
	}
	return ok
}

func findClosest(p *node, level, target int) *node {
	for p.next[level] != nil && p.next[level].val < target {
		p = p.next[level]
	}
	return p
}

func randomLevel() int {
	level := 1
	for level < maxLevel && rand.Float64() < p {
		level++
	}
	return level
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Search(target);
 * obj.Add(num);
 * param_3 := obj.Erase(num);
 */
```

#### TypeScript

```ts
class Node {
    val: number;
    next: (Node | null)[];

    constructor(val: number, level: number) {
        this.val = val;
        this.next = Array(level).fill(null);
    }
}

class Skiplist {
    private static maxLevel: number = 32;
    private static p: number = 0.25;
    private head: Node;
    private level: number;

    constructor() {
        this.head = new Node(-1, Skiplist.maxLevel);
        this.level = 0;
    }

    search(target: number): boolean {
        let curr = this.head;
        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, target);
            if (curr.next[i] && curr.next[i]!.val === target) {
                return true;
            }
        }
        return false;
    }

    add(num: number): void {
        let curr = this.head;
        const level = this.randomLevel();
        const node = new Node(num, level);
        this.level = Math.max(this.level, level);

        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, num);
            if (i < level) {
                node.next[i] = curr.next[i];
                curr.next[i] = node;
            }
        }
    }

    erase(num: number): boolean {
        let curr = this.head;
        let ok = false;

        for (let i = this.level - 1; i >= 0; i--) {
            curr = this.findClosest(curr, i, num);
            if (curr.next[i] && curr.next[i]!.val === num) {
                curr.next[i] = curr.next[i]!.next[i];
                ok = true;
            }
        }

        while (this.level > 1 && this.head.next[this.level - 1] === null) {
            this.level--;
        }

        return ok;
    }

    private findClosest(curr: Node, level: number, target: number): Node {
        while (curr.next[level] && curr.next[level]!.val < target) {
            curr = curr.next[level]!;
        }
        return curr;
    }

    private randomLevel(): number {
        let level = 1;
        while (level < Skiplist.maxLevel && Math.random() < Skiplist.p) {
            level++;
        }
        return level;
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * var obj = new Skiplist()
 * var param_1 = obj.search(target)
 * obj.add(num)
 * var param_3 = obj.erase(num)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1207. 独一无二的出现次数](https://leetcode.cn/problems/unique-number-of-occurrences){#1207}

{{< tabs "1207" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = Counter(arr)
        return len(set(cnt.values())) == len(cnt)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) {
            cnt.merge(x, 1, Integer::sum);
        }
        return new HashSet<>(cnt.values()).size() == cnt.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        unordered_set<int> vis;
        for (auto& [_, v] : cnt) {
            if (vis.count(v)) {
                return false;
            }
            vis.insert(v);
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uniqueOccurrences(arr []int) bool {
	cnt := map[int]int{}
	for _, x := range arr {
		cnt[x]++
	}
	vis := map[int]bool{}
	for _, v := range cnt {
		if vis[v] {
			return false
		}
		vis[v] = true
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uniqueOccurrences(arr: number[]): boolean {
    const cnt: Map<number, number> = new Map();
    for (const x of arr) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return cnt.size === new Set(cnt.values()).size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>，如果每个数的出现次数都是独一无二的，就返回&nbsp;<code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,2,1,1,3]
<strong>输出：</strong>true
<strong>解释：</strong>在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [-3,0,1,-3,1,1,1,-3,10,0]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 1000</code></li>
	<li><code>-1000 &lt;= arr[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 $cnt$ 统计数组 $arr$ 中每个数的出现次数，然后用哈希表 $vis$ 统计出现次数的种类，最后判断 $cnt$ 和 $vis$ 的大小是否相等即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = Counter(arr)
        return len(set(cnt.values())) == len(cnt)
```

#### Java

```java
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) {
            cnt.merge(x, 1, Integer::sum);
        }
        return new HashSet<>(cnt.values()).size() == cnt.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        unordered_set<int> vis;
        for (auto& [_, v] : cnt) {
            if (vis.count(v)) {
                return false;
            }
            vis.insert(v);
        }
        return true;
    }
};
```

#### Go

```go
func uniqueOccurrences(arr []int) bool {
	cnt := map[int]int{}
	for _, x := range arr {
		cnt[x]++
	}
	vis := map[int]bool{}
	for _, v := range cnt {
		if vis[v] {
			return false
		}
		vis[v] = true
	}
	return true
}
```

#### TypeScript

```ts
function uniqueOccurrences(arr: number[]): boolean {
    const cnt: Map<number, number> = new Map();
    for (const x of arr) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return cnt.size === new Set(cnt.values()).size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1208. 尽可能使字符串相等](https://leetcode.cn/problems/get-equal-substrings-within-budget){#1208}

{{< tabs "1208" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        cost = l = 0
        for a, b in zip(s, t):
            cost += abs(ord(a) - ord(b))
            if cost > maxCost:
                cost -= abs(ord(s[l]) - ord(t[l]))
                l += 1
        return len(s) - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int cost = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            cost += Math.abs(s.charAt(r) - t.charAt(r));
            if (cost > maxCost) {
                cost -= Math.abs(s.charAt(l) - t.charAt(l));
                ++l;
            }
        }
        return n - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int cost = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            cost += abs(s[r] - t[r]);
            if (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                ++l;
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalSubstring(s string, t string, maxCost int) int {
	n := len(s)
	var cost, l int
	for r := range s {
		cost += abs(int(s[r]) - int(t[r]))
		if cost > maxCost {
			cost -= abs(int(s[l]) - int(t[l]))
			l++
		}
	}
	return n - l
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function equalSubstring(s: string, t: string, maxCost: number): number {
    const getCost = (i: number) => Math.abs(s[i].charCodeAt(0) - t[i].charCodeAt(0));
    const n = s.length;
    let cost = 0;
    let l = 0;
    for (let r = 0; r < n; ++r) {
        cost += getCost(r);
        if (cost > maxCost) {
            cost -= getCost(l++);
        }
    }
    return n - l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个长度相同的字符串，<code>s</code> 和 <code>t</code>。</p>

<p>将 <code>s</code> 中的第 <code>i</code> 个字符变到 <code>t</code> 中的第 <code>i</code> 个字符需要 <code>|s[i] - t[i]|</code> 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。</p>

<p>用于变更字符串的最大预算是 <code>maxCost</code>。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。</p>

<p>如果你可以将 <code>s</code> 的子字符串转化为它在 <code>t</code> 中对应的子字符串，则返回可以转化的最大长度。</p>

<p>如果 <code>s</code> 中没有子字符串可以转化成 <code>t</code> 中对应的子字符串，则返回 <code>0</code>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", t = "bcdf", maxCost = 3
<strong>输出：</strong>3
<strong>解释：</strong>s<strong> </strong>中的<strong> </strong>"abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", t = "cdef", maxCost = 3
<strong>输出：</strong>1
<strong>解释：</strong>s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为<code> 1。</code>
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", t = "acde", maxCost = 0
<strong>输出：</strong>1
<strong>解释：</strong>a -> a, cost = 0，字符串未发生变化，所以最大长度为 1。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length, t.length <= 10^5</code></li>
	<li><code>0 <= maxCost <= 10^6</code></li>
	<li><code>s</code> 和 <code>t</code> 都只含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 二分查找

我们可以创建一个长度为 $n + 1$ 的数组 $f$，其中 $f[i]$ 表示字符串 $s$ 的前 $i$ 个字符与字符串 $t$ 的前 $i$ 个字符的 ASCII 码值的差的绝对值之和。这样，我们就可以通过 $f[j + 1] - f[i]$ 来计算字符串 $s$ 的第 $i$ 个字符到第 $j$ 个字符的 ASCII 码值的差的绝对值之和，其中 $0 \leq i \leq j < n$。

注意到长度具有单调性，即如果存在长度为 $x$ 的子串满足条件，那么长度为 $x - 1$ 的子串也一定满足条件。因此，我们可以使用二分查找的方法来求解最大长度。

我们定义函数 $check(x)$，表示是否存在长度为 $x$ 的子串满足条件。在该函数中，我们只需要枚举所有长度为 $x$ 的子串，判断其是否满足条件即可。如果存在满足条件的子串，那么函数返回 `true`，否则返回 `false`。

接下来，我们定义二分查找的左边界 $l$ 为 $0$，右边界 $r$ 为 $n$。在每一步中，我们令 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，如果函数 $check(mid)$ 的返回值为 `true`，那么我们将左边界更新为 $mid$，否则我们将右边界更新为 $mid - 1$。在二分查找结束后，我们得到的左边界即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        def check(x):
            for i in range(n):
                j = i + mid - 1
                if j < n and f[j + 1] - f[i] <= maxCost:
                    return True
            return False

        n = len(s)
        f = list(accumulate((abs(ord(a) - ord(b)) for a, b in zip(s, t)), initial=0))
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int maxCost;
    private int[] f;
    private int n;

    public int equalSubstring(String s, String t, int maxCost) {
        n = s.length();
        f = new int[n + 1];
        this.maxCost = maxCost;
        for (int i = 0; i < n; ++i) {
            int x = Math.abs(s.charAt(i) - t.charAt(i));
            f[i + 1] = f[i] + x;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int x) {
        for (int i = 0; i + x - 1 < n; ++i) {
            int j = i + x - 1;
            if (f[j + 1] - f[i] <= maxCost) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            f[i + 1] = f[i] + abs(s[i] - t[i]);
        }
        auto check = [&](int x) -> bool {
            for (int i = 0; i + x - 1 < n; ++i) {
                int j = i + x - 1;
                if (f[j + 1] - f[i] <= maxCost) {
                    return true;
                }
            }
            return false;
        };
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func equalSubstring(s string, t string, maxCost int) int {
	n := len(s)
	f := make([]int, n+1)
	for i, a := range s {
		f[i+1] = f[i] + abs(int(a)-int(t[i]))
	}
	check := func(x int) bool {
		for i := 0; i+x-1 < n; i++ {
			if f[i+x]-f[i] <= maxCost {
				return true
			}
		}
		return false
	}
	l, r := 0, n
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function equalSubstring(s: string, t: string, maxCost: number): number {
    const n = s.length;
    const f = Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        f[i + 1] = f[i] + Math.abs(s.charCodeAt(i) - t.charCodeAt(i));
    }

    const check = (x: number): boolean => {
        for (let i = 0; i + x - 1 < n; i++) {
            if (f[i + x] - f[i] <= maxCost) {
                return true;
            }
        }
        return false;
    };

    let l = 0,
        r = n;
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

我们可以维护两个指针 $l$ 和 $r$，初始时 $l = r = 0$；维护一个变量 $\textit{cost}$，表示下标区间 $[l,..r]$ 之间的 ASCII 码值的差的绝对值之和。在每一步中，我们将 $r$ 向右移动一位，然后更新 $\textit{cost} = \textit{cost} + |s[r] - t[r]|$。如果 $\textit{cost} \gt \textit{maxCost}$，那么我们就循环将 $l$ 向右移动一位，并且减少 $\textit{cost}$ 的值，直到 $\textit{cost} \leq \textit{maxCost}$。然后我们更新答案，即 $\textit{ans} = \max(\textit{ans}, r - l + 1)$。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        ans = cost = l = 0
        for r in range(n):
            cost += abs(ord(s[r]) - ord(t[r]))
            while cost > maxCost:
                cost -= abs(ord(s[l]) - ord(t[l]))
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```

#### Java

```java
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int ans = 0, cost = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            cost += Math.abs(s.charAt(r) - t.charAt(r));
            while (cost > maxCost) {
                cost -= Math.abs(s.charAt(l) - t.charAt(l));
                ++l;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int ans = 0, cost = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            cost += abs(s[r] - t[r]);
            while (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func equalSubstring(s string, t string, maxCost int) (ans int) {
	var cost, l int
	for r := range s {
		cost += abs(int(s[r]) - int(t[r]))
		for ; cost > maxCost; l++ {
			cost -= abs(int(s[l]) - int(t[l]))
		}
		ans = max(ans, r-l+1)
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function equalSubstring(s: string, t: string, maxCost: number): number {
    const getCost = (i: number) => Math.abs(s[i].charCodeAt(0) - t[i].charCodeAt(0));
    const n = s.length;
    let ans = 0,
        cost = 0;
    for (let l = 0, r = 0; r < n; ++r) {
        cost += getCost(r);
        while (cost > maxCost) {
            cost -= getCost(l++);
        }
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：双指针的另一种写法

在方法二中，双指针维护的区间可能变短，也可能变长，由于题目只需要求出最大长度，我们可以维护一个单调变长的区间。

具体地，我们用两个指针 $l$ 和 $r$ 指向区间的左右端点，初始时 $l = r = 0$。在每一步中，我们将 $r$ 向右移动一位，然后更新 $\textit{cost} = \textit{cost} + |s[r] - t[r]|$。如果 $\textit{cost} \gt \textit{maxCost}$，那么我们就将 $l$ 向右移动一位，并且减少 $\textit{cost}$ 的值。

最后返回 $n - l$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        cost = l = 0
        for a, b in zip(s, t):
            cost += abs(ord(a) - ord(b))
            if cost > maxCost:
                cost -= abs(ord(s[l]) - ord(t[l]))
                l += 1
        return len(s) - l
```

#### Java

```java
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int cost = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            cost += Math.abs(s.charAt(r) - t.charAt(r));
            if (cost > maxCost) {
                cost -= Math.abs(s.charAt(l) - t.charAt(l));
                ++l;
            }
        }
        return n - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int cost = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            cost += abs(s[r] - t[r]);
            if (cost > maxCost) {
                cost -= abs(s[l] - t[l]);
                ++l;
            }
        }
        return n - l;
    }
};
```

#### Go

```go
func equalSubstring(s string, t string, maxCost int) int {
	n := len(s)
	var cost, l int
	for r := range s {
		cost += abs(int(s[r]) - int(t[r]))
		if cost > maxCost {
			cost -= abs(int(s[l]) - int(t[l]))
			l++
		}
	}
	return n - l
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function equalSubstring(s: string, t: string, maxCost: number): number {
    const getCost = (i: number) => Math.abs(s[i].charCodeAt(0) - t[i].charCodeAt(0));
    const n = s.length;
    let cost = 0;
    let l = 0;
    for (let r = 0; r < n; ++r) {
        cost += getCost(r);
        if (cost > maxCost) {
            cost -= getCost(l++);
        }
    }
    return n - l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1209. 删除字符串中的所有相邻重复项 II](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii){#1209}

{{< tabs "1209" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stk = []
        for c in s:
            if stk and stk[-1][0] == c:
                stk[-1][1] = (stk[-1][1] + 1) % k
                if stk[-1][1] == 0:
                    stk.pop()
            else:
                stk.append([c, 1])
        ans = [c * v for c, v in stk]
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeDuplicates(String s, int k) {
        Deque<int[]> stk = new ArrayDeque<>();
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            if (!stk.isEmpty() && stk.peek()[0] == j) {
                stk.peek()[1] = (stk.peek()[1] + 1) % k;
                if (stk.peek()[1] == 0) {
                    stk.pop();
                }
            } else {
                stk.push(new int[] {j, 1});
            }
        }
        StringBuilder ans = new StringBuilder();
        for (var e : stk) {
            char c = (char) (e[0] + 'a');
            for (int i = 0; i < e[1]; ++i) {
                ans.append(c);
            }
        }
        ans.reverse();
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (char& c : s) {
            if (stk.size() && stk.back().first == c) {
                stk.back().second = (stk.back().second + 1) % k;
                if (stk.back().second == 0) {
                    stk.pop_back();
                }
            } else {
                stk.push_back({c, 1});
            }
        }
        string ans;
        for (auto [c, v] : stk) {
            ans += string(v, c);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDuplicates(s string, k int) string {
	stk := []pair{}
	for _, c := range s {
		if len(stk) > 0 && stk[len(stk)-1].c == c {
			stk[len(stk)-1].v = (stk[len(stk)-1].v + 1) % k
			if stk[len(stk)-1].v == 0 {
				stk = stk[:len(stk)-1]
			}
		} else {
			stk = append(stk, pair{c, 1})
		}
	}
	ans := []rune{}
	for _, e := range stk {
		for i := 0; i < e.v; i++ {
			ans = append(ans, e.c)
		}
	}
	return string(ans)
}

type pair struct {
	c rune
	v int
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>，「<code>k</code> 倍重复项删除操作」将会从 <code>s</code>&nbsp;中选择&nbsp;<code>k</code>&nbsp;个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。</p>

<p>你需要对&nbsp;<code>s</code>&nbsp;重复进行无限次这样的删除操作，直到无法继续为止。</p>

<p>在执行完所有删除操作后，返回最终得到的字符串。</p>

<p>本题答案保证唯一。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcd&quot;, k = 2
<strong>输出：</strong>&quot;abcd&quot;
<strong>解释：</strong>没有要删除的内容。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;deeedbbcccbdaa&quot;, k = 3
<strong>输出：</strong>&quot;aa&quot;
<strong>解释： 
</strong>先删除 &quot;eee&quot; 和 &quot;ccc&quot;，得到 &quot;ddbbbdaa&quot;
再删除 &quot;bbb&quot;，得到 &quot;dddaa&quot;
最后删除 &quot;ddd&quot;，得到 &quot;aa&quot;</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;pbbcggttciiippooaais&quot;, k = 2
<strong>输出：</strong>&quot;ps&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>2 &lt;= k &lt;= 10^4</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们可以遍历字符串 $s$，维护一个栈，栈中存储的是字符和该字符出现的次数。当遍历到字符 $c$ 时，如果栈顶元素的字符和 $c$ 相同，则将栈顶元素的次数加一，否则将字符 $c$ 和次数 $1$ 入栈。当栈顶元素的次数等于 $k$ 时，将栈顶元素出栈。

遍历完字符串 $s$ 后，栈中存储的就是最终结果。我们可以将栈中的元素依次弹出，拼接成字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stk = []
        for c in s:
            if stk and stk[-1][0] == c:
                stk[-1][1] = (stk[-1][1] + 1) % k
                if stk[-1][1] == 0:
                    stk.pop()
            else:
                stk.append([c, 1])
        ans = [c * v for c, v in stk]
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String removeDuplicates(String s, int k) {
        Deque<int[]> stk = new ArrayDeque<>();
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            if (!stk.isEmpty() && stk.peek()[0] == j) {
                stk.peek()[1] = (stk.peek()[1] + 1) % k;
                if (stk.peek()[1] == 0) {
                    stk.pop();
                }
            } else {
                stk.push(new int[] {j, 1});
            }
        }
        StringBuilder ans = new StringBuilder();
        for (var e : stk) {
            char c = (char) (e[0] + 'a');
            for (int i = 0; i < e[1]; ++i) {
                ans.append(c);
            }
        }
        ans.reverse();
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (char& c : s) {
            if (stk.size() && stk.back().first == c) {
                stk.back().second = (stk.back().second + 1) % k;
                if (stk.back().second == 0) {
                    stk.pop_back();
                }
            } else {
                stk.push_back({c, 1});
            }
        }
        string ans;
        for (auto [c, v] : stk) {
            ans += string(v, c);
        }
        return ans;
    }
};
```

#### Go

```go
func removeDuplicates(s string, k int) string {
	stk := []pair{}
	for _, c := range s {
		if len(stk) > 0 && stk[len(stk)-1].c == c {
			stk[len(stk)-1].v = (stk[len(stk)-1].v + 1) % k
			if stk[len(stk)-1].v == 0 {
				stk = stk[:len(stk)-1]
			}
		} else {
			stk = append(stk, pair{c, 1})
		}
	}
	ans := []rune{}
	for _, e := range stk {
		for i := 0; i < e.v; i++ {
			ans = append(ans, e.c)
		}
	}
	return string(ans)
}

type pair struct {
	c rune
	v int
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

---
title: "2040_两个有序数组的第 K 小乘积"
date: 2025-10-08T18:38:57+08:00
weight: 5
tags: [二分查找, 二叉树, 位运算, 双指针, 哈希表, 回溯, 图, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 最短路, 枚举, 树, 模拟, 深度优先搜索, 计数, 设计, 链表]
---

{{< markmap >}}
### [2040_两个有序数组的第 K 小乘积](#2040)
#### [数组](#2040)
#### [二分查找](#2040)
### [2041_面试中被录取的候选人 🔒](#2041)
#### [数据库](#2041)
### [2042_检查句子中的数字是否递增](#2042)
#### [字符串](#2042)
### [2043_简易银行系统](#2043)
#### [设计](#2043)
#### [数组](#2043)
#### [哈希表](#2043)
#### [模拟](#2043)
### [2044_统计按位或能得到最大值的子集数目](#2044)
#### [位运算](#2044)
#### [数组](#2044)
#### [回溯](#2044)
#### [枚举](#2044)
### [2045_到达目的地的第二短时间](#2045)
#### [广度优先搜索](#2045)
#### [图](#2045)
#### [最短路](#2045)
### [2046_给按照绝对值排序的链表排序 🔒](#2046)
#### [链表](#2046)
#### [双指针](#2046)
#### [排序](#2046)
### [2047_句子中的有效单词数](#2047)
#### [字符串](#2047)
### [2048_下一个更大的数值平衡数](#2048)
#### [哈希表](#2048)
#### [数学](#2048)
#### [回溯](#2048)
#### [计数](#2048)
#### [枚举](#2048)
### [2049_统计最高分的节点数目](#2049)
#### [树](#2049)
#### [深度优先搜索](#2049)
#### [数组](#2049)
#### [二叉树](#2049)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2040_两个有序数组的第 K 小乘积
___
#### 数组
___
#### 二分查找
---
### 2041_面试中被录取的候选人 🔒
___
#### 数据库
---
### 2042_检查句子中的数字是否递增
___
#### 字符串
---
### 2043_简易银行系统
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2044_统计按位或能得到最大值的子集数目
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 枚举
---
### 2045_到达目的地的第二短时间
___
#### 广度优先搜索
___
#### 图
___
#### 最短路
---
### 2046_给按照绝对值排序的链表排序 🔒
___
#### 链表
___
#### 双指针
___
#### 排序
---
### 2047_句子中的有效单词数
___
#### 字符串
---
### 2048_下一个更大的数值平衡数
___
#### 哈希表
___
#### 数学
___
#### 回溯
___
#### 计数
___
#### 枚举
---
### 2049_统计最高分的节点数目
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 双指针 | 哈希表 | 回溯 |
| 图 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 最短路 | 枚举 |
| 树 | 模拟 | 深度优先搜索 |
| 计数 | 设计 | 链表 |

# [2040. 两个有序数组的第 K 小乘积](https://leetcode.cn/problems/kth-smallest-product-of-two-sorted-arrays){#2040}

{{< tabs "2040" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def count(p: int) -> int:
            cnt = 0
            n = len(nums2)
            for x in nums1:
                if x > 0:
                    cnt += bisect_right(nums2, p / x)
                elif x < 0:
                    cnt += n - bisect_left(nums2, p / x)
                else:
                    cnt += n * int(p >= 0)
            return cnt

        mx = max(abs(nums1[0]), abs(nums1[-1])) * max(abs(nums2[0]), abs(nums2[-1]))
        return bisect_left(range(-mx, mx + 1), k, key=count) - mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums1;
    private int[] nums2;

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        int m = nums1.length;
        int n = nums2.length;
        int a = Math.max(Math.abs(nums1[0]), Math.abs(nums1[m - 1]));
        int b = Math.max(Math.abs(nums2[0]), Math.abs(nums2[n - 1]));
        long r = (long) a * b;
        long l = (long) -a * b;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (count(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private long count(long p) {
        long cnt = 0;
        int n = nums2.length;
        for (int x : nums1) {
            if (x > 0) {
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if ((long) x * nums2[mid] > p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += l;
            } else if (x < 0) {
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if ((long) x * nums2[mid] <= p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += n - l;
            } else if (p >= 0) {
                cnt += n;
            }
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
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int m = nums1.size(), n = nums2.size();
        int a = max(abs(nums1[0]), abs(nums1[m - 1]));
        int b = max(abs(nums2[0]), abs(nums2[n - 1]));
        long long r = 1LL * a * b;
        long long l = -r;
        auto count = [&](long long p) {
            long long cnt = 0;
            for (int x : nums1) {
                if (x > 0) {
                    int l = 0, r = n;
                    while (l < r) {
                        int mid = (l + r) >> 1;
                        if (1LL * x * nums2[mid] > p) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    cnt += l;
                } else if (x < 0) {
                    int l = 0, r = n;
                    while (l < r) {
                        int mid = (l + r) >> 1;
                        if (1LL * x * nums2[mid] <= p) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    cnt += n - l;
                } else if (p >= 0) {
                    cnt += n;
                }
            }
            return cnt;
        };
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (count(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthSmallestProduct(nums1 []int, nums2 []int, k int64) int64 {
	m := len(nums1)
	n := len(nums2)
	a := max(abs(nums1[0]), abs(nums1[m-1]))
	b := max(abs(nums2[0]), abs(nums2[n-1]))
	r := int64(a) * int64(b)
	l := -r

	count := func(p int64) int64 {
		var cnt int64
		for _, x := range nums1 {
			if x > 0 {
				l, r := 0, n
				for l < r {
					mid := (l + r) >> 1
					if int64(x)*int64(nums2[mid]) > p {
						r = mid
					} else {
						l = mid + 1
					}
				}
				cnt += int64(l)
			} else if x < 0 {
				l, r := 0, n
				for l < r {
					mid := (l + r) >> 1
					if int64(x)*int64(nums2[mid]) <= p {
						r = mid
					} else {
						l = mid + 1
					}
				}
				cnt += int64(n - l)
			} else if p >= 0 {
				cnt += int64(n)
			}
		}
		return cnt
	}

	for l < r {
		mid := (l + r) >> 1
		if count(mid) >= k {
			r = mid
		} else {
			l = mid + 1
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
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthSmallestProduct(nums1: number[], nums2: number[], k: number): number {
    const m = nums1.length;
    const n = nums2.length;

    const a = BigInt(Math.max(Math.abs(nums1[0]), Math.abs(nums1[m - 1])));
    const b = BigInt(Math.max(Math.abs(nums2[0]), Math.abs(nums2[n - 1])));

    let l = -a * b;
    let r = a * b;

    const count = (p: bigint): bigint => {
        let cnt = 0n;
        for (const x of nums1) {
            const bx = BigInt(x);
            if (bx > 0n) {
                let l = 0,
                    r = n;
                while (l < r) {
                    const mid = (l + r) >> 1;
                    const prod = bx * BigInt(nums2[mid]);
                    if (prod > p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += BigInt(l);
            } else if (bx < 0n) {
                let l = 0,
                    r = n;
                while (l < r) {
                    const mid = (l + r) >> 1;
                    const prod = bx * BigInt(nums2[mid]);
                    if (prod <= p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += BigInt(n - l);
            } else if (p >= 0n) {
                cnt += BigInt(n);
            }
        }
        return cnt;
    };

    while (l < r) {
        const mid = (l + r) >> 1n;
        if (count(mid) >= BigInt(k)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }

    return Number(l);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn kth_smallest_product(nums1: Vec<i32>, nums2: Vec<i32>, k: i64) -> i64 {
        let m = nums1.len();
        let n = nums2.len();
        let a = nums1[0].abs().max(nums1[m - 1].abs()) as i64;
        let b = nums2[0].abs().max(nums2[n - 1].abs()) as i64;
        let mut l = -a * b;
        let mut r = a * b;

        let count = |p: i64| -> i64 {
            let mut cnt = 0i64;
            for &x in &nums1 {
                if x > 0 {
                    let mut left = 0;
                    let mut right = n;
                    while left < right {
                        let mid = (left + right) / 2;
                        if (x as i64) * (nums2[mid] as i64) > p {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    }
                    cnt += left as i64;
                } else if x < 0 {
                    let mut left = 0;
                    let mut right = n;
                    while left < right {
                        let mid = (left + right) / 2;
                        if (x as i64) * (nums2[mid] as i64) <= p {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    }
                    cnt += (n - left) as i64;
                } else if p >= 0 {
                    cnt += n as i64;
                }
            }
            cnt
        };

        while l < r {
            let mid = l + (r - l) / 2;
            if count(mid) >= k {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你两个 <strong>从小到大排好序</strong>&nbsp;且下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;以及一个整数&nbsp;<code>k</code>&nbsp;，请你返回第<em>&nbsp;</em><code>k</code>&nbsp;（从 <strong>1</strong>&nbsp;开始编号）小的&nbsp;<code>nums1[i] \* nums2[j]</code><em>&nbsp;</em>的乘积，其中<em>&nbsp;</em><code>0 &lt;= i &lt; nums1.length</code><em> </em>且<em> </em><code>0 &lt;= j &lt; nums2.length</code>&nbsp;。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [2,5], nums2 = [3,4], k = 2
<b>输出：</b>8
<b>解释：</b>第 2 小的乘积计算如下：
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
第 2 小的乘积为 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
<b>输出：</b>0
<strong>解释：</strong>第 6 小的乘积计算如下：
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
第 6 小的乘积为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
<b>输出：</b>-6
<b>解释：</b>第 3 小的乘积计算如下：
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
第 3 小的乘积为 -6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums1.length * nums2.length</code></li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是从小到大排好序的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以二分枚举乘积的值 $p$，定义二分的区间为 $[l, r]$，其中 $l = -\textit{max}(|\textit{nums1}[0]|, |\textit{nums1}[n - 1]|) \times \textit{max}(|\textit{nums2}[0]|, |\textit{nums2}[n - 1]|)$, $r = -l$。

对于每个 $p$，我们计算出乘积小于等于 $p$ 的乘积的个数，如果这个个数大于等于 $k$，那么说明第 $k$ 小的乘积一定小于等于 $p$，我们就可以将区间右端点缩小到 $p$，否则我们将区间左端点增大到 $p + 1$。

那么问题的关键就是如何计算乘积小于等于 $p$ 的乘积的个数。我们可以枚举 $\textit{nums1}$ 中的每个数 $x$，分类讨论：

-   如果 $x > 0$，那么 $x \times \textit{nums2}[i]$ 随着 $i$ 的增大是单调递增的，我们可以使用二分查找找到最小的 $i$，使得 $x \times \textit{nums2}[i] > p$，那么 $i$ 就是小于等于 $p$ 的乘积的个数，累加到个数 $\textit{cnt}$ 中；
-   如果 $x < 0$，那么 $x \times \textit{nums2}[i]$ 随着 $i$ 的增大是单调递减的，我们可以使用二分查找找到最小的 $i$，使得 $x \times \textit{nums2}[i] \leq p$，那么 $n - i$ 就是小于等于 $p$ 的乘积的个数，累加到个数 $\textit{cnt}$ 中；
-   如果 $x = 0$，那么 $x \times \textit{nums2}[i] = 0$，如果 $p \geq 0$，那么 $n$ 就是小于等于 $p$ 的乘积的个数，累加到个数 $\textit{cnt}$ 中。

这样我们就可以通过二分查找找到第 $k$ 小的乘积。

时间复杂度 $O(m \times \log n \times \log M)$，其中 $m$ 和 $n$ 分别为 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度，而 $M$ 为 $\textit{nums1}$ 和 $\textit{nums2}$ 中的最大值的绝对值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def count(p: int) -> int:
            cnt = 0
            n = len(nums2)
            for x in nums1:
                if x > 0:
                    cnt += bisect_right(nums2, p / x)
                elif x < 0:
                    cnt += n - bisect_left(nums2, p / x)
                else:
                    cnt += n * int(p >= 0)
            return cnt

        mx = max(abs(nums1[0]), abs(nums1[-1])) * max(abs(nums2[0]), abs(nums2[-1]))
        return bisect_left(range(-mx, mx + 1), k, key=count) - mx
```

#### Java

```java
class Solution {
    private int[] nums1;
    private int[] nums2;

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        int m = nums1.length;
        int n = nums2.length;
        int a = Math.max(Math.abs(nums1[0]), Math.abs(nums1[m - 1]));
        int b = Math.max(Math.abs(nums2[0]), Math.abs(nums2[n - 1]));
        long r = (long) a * b;
        long l = (long) -a * b;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (count(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private long count(long p) {
        long cnt = 0;
        int n = nums2.length;
        for (int x : nums1) {
            if (x > 0) {
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if ((long) x * nums2[mid] > p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += l;
            } else if (x < 0) {
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if ((long) x * nums2[mid] <= p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += n - l;
            } else if (p >= 0) {
                cnt += n;
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int m = nums1.size(), n = nums2.size();
        int a = max(abs(nums1[0]), abs(nums1[m - 1]));
        int b = max(abs(nums2[0]), abs(nums2[n - 1]));
        long long r = 1LL * a * b;
        long long l = -r;
        auto count = [&](long long p) {
            long long cnt = 0;
            for (int x : nums1) {
                if (x > 0) {
                    int l = 0, r = n;
                    while (l < r) {
                        int mid = (l + r) >> 1;
                        if (1LL * x * nums2[mid] > p) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    cnt += l;
                } else if (x < 0) {
                    int l = 0, r = n;
                    while (l < r) {
                        int mid = (l + r) >> 1;
                        if (1LL * x * nums2[mid] <= p) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    cnt += n - l;
                } else if (p >= 0) {
                    cnt += n;
                }
            }
            return cnt;
        };
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (count(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func kthSmallestProduct(nums1 []int, nums2 []int, k int64) int64 {
	m := len(nums1)
	n := len(nums2)
	a := max(abs(nums1[0]), abs(nums1[m-1]))
	b := max(abs(nums2[0]), abs(nums2[n-1]))
	r := int64(a) * int64(b)
	l := -r

	count := func(p int64) int64 {
		var cnt int64
		for _, x := range nums1 {
			if x > 0 {
				l, r := 0, n
				for l < r {
					mid := (l + r) >> 1
					if int64(x)*int64(nums2[mid]) > p {
						r = mid
					} else {
						l = mid + 1
					}
				}
				cnt += int64(l)
			} else if x < 0 {
				l, r := 0, n
				for l < r {
					mid := (l + r) >> 1
					if int64(x)*int64(nums2[mid]) <= p {
						r = mid
					} else {
						l = mid + 1
					}
				}
				cnt += int64(n - l)
			} else if p >= 0 {
				cnt += int64(n)
			}
		}
		return cnt
	}

	for l < r {
		mid := (l + r) >> 1
		if count(mid) >= k {
			r = mid
		} else {
			l = mid + 1
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
function kthSmallestProduct(nums1: number[], nums2: number[], k: number): number {
    const m = nums1.length;
    const n = nums2.length;

    const a = BigInt(Math.max(Math.abs(nums1[0]), Math.abs(nums1[m - 1])));
    const b = BigInt(Math.max(Math.abs(nums2[0]), Math.abs(nums2[n - 1])));

    let l = -a * b;
    let r = a * b;

    const count = (p: bigint): bigint => {
        let cnt = 0n;
        for (const x of nums1) {
            const bx = BigInt(x);
            if (bx > 0n) {
                let l = 0,
                    r = n;
                while (l < r) {
                    const mid = (l + r) >> 1;
                    const prod = bx * BigInt(nums2[mid]);
                    if (prod > p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += BigInt(l);
            } else if (bx < 0n) {
                let l = 0,
                    r = n;
                while (l < r) {
                    const mid = (l + r) >> 1;
                    const prod = bx * BigInt(nums2[mid]);
                    if (prod <= p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += BigInt(n - l);
            } else if (p >= 0n) {
                cnt += BigInt(n);
            }
        }
        return cnt;
    };

    while (l < r) {
        const mid = (l + r) >> 1n;
        if (count(mid) >= BigInt(k)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }

    return Number(l);
}
```

#### Rust

```rust
impl Solution {
    pub fn kth_smallest_product(nums1: Vec<i32>, nums2: Vec<i32>, k: i64) -> i64 {
        let m = nums1.len();
        let n = nums2.len();
        let a = nums1[0].abs().max(nums1[m - 1].abs()) as i64;
        let b = nums2[0].abs().max(nums2[n - 1].abs()) as i64;
        let mut l = -a * b;
        let mut r = a * b;

        let count = |p: i64| -> i64 {
            let mut cnt = 0i64;
            for &x in &nums1 {
                if x > 0 {
                    let mut left = 0;
                    let mut right = n;
                    while left < right {
                        let mid = (left + right) / 2;
                        if (x as i64) * (nums2[mid] as i64) > p {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    }
                    cnt += left as i64;
                } else if x < 0 {
                    let mut left = 0;
                    let mut right = n;
                    while left < right {
                        let mid = (left + right) / 2;
                        if (x as i64) * (nums2[mid] as i64) <= p {
                            right = mid;
                        } else {
                            left = mid + 1;
                        }
                    }
                    cnt += (n - left) as i64;
                } else if p >= 0 {
                    cnt += n as i64;
                }
            }
            cnt
        };

        while l < r {
            let mid = l + (r - l) / 2;
            if count(mid) >= k {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2041. 面试中被录取的候选人 🔒](https://leetcode.cn/problems/accepted-candidates-from-the-interviews){#2041}

{{< tabs "2041" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT candidate_id
FROM
    Candidates
    JOIN Rounds USING (interview_id)
WHERE years_of_exp >= 2
GROUP BY 1
HAVING SUM(score) > 15;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def accepted_candidates(candidates: pd.DataFrame, rounds: pd.DataFrame) -> pd.DataFrame:
    merged_df = pd.merge(candidates, rounds, on="interview_id")
    filtered_df = merged_df[merged_df["years_of_exp"] >= 2]
    grouped_df = filtered_df.groupby("candidate_id").agg({"score": "sum"})
    return grouped_df[grouped_df["score"] > 15].reset_index()[["candidate_id"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Candidates</code></p>

<pre>
+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| candidate_id | int      |
| name         | varchar  |
| years_of_exp | int      |
| interview_id | int      |
+--------------+----------+
candidate_id 是这个表的主键（具有唯一值的列）。
该表的每一行都表示候选人的姓名、工作年限以及面试 ID 。
</pre>

<p>&nbsp;</p>

<p>表：<code>Rounds</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| interview_id | int  |
| round_id     | int  |
| score        | int  |
+--------------+------+
(interview_id, round_id）是本表的主键（具有唯一值的列的组合）。
本表的每一行都表示一轮面试的分数
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出 <strong>至少有两年</strong> 工作经验、且面试分数之和 <strong>严格大于 <code>15</code>&nbsp;</strong>的候选人的 ID<strong> 。</strong></p>

<p>可以以 <strong>任何顺序 </strong>返回结果表。</p>

<p>查询结果的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Candidates table:
+--------------+---------+--------------+--------------+
| candidate_id | name    | years_of_exp | interview_id |
+--------------+---------+--------------+--------------+
| 11           | Atticus | 1            | 101          |
| 9            | Ruben   | 6            | 104          |
| 6            | Aliza   | 10           | 109          |
| 8            | Alfredo | 0            | 107          |
+--------------+---------+--------------+--------------+
Rounds table:
+--------------+----------+-------+
| interview_id | round_id | score |
+--------------+----------+-------+
| 109          | 3        | 4     |
| 101          | 2        | 8     |
| 109          | 4        | 1     |
| 107          | 1        | 3     |
| 104          | 3        | 6     |
| 109          | 1        | 4     |
| 104          | 4        | 7     |
| 104          | 1        | 2     |
| 109          | 2        | 1     |
| 104          | 2        | 7     |
| 107          | 2        | 3     |
| 101          | 1        | 8     |
+--------------+----------+-------+
<strong>输出：</strong>
+--------------+
| candidate_id |
+--------------+
| 9            |
+--------------+
<strong>解释：</strong>
- 候选人 11 ：总分是 16 ，1 年工作经验。由于工作年限，不列入结果表。
- 候选人 9 ：总分是 22 ，6 年工作经验。列入结果表。
- 候选人 6 ：总分是 10 ，10 年工作经验。由于分数不足，不列入结果表。
- 候选人 8 ：总分是 6 ，0 年工作经验。由于工作年限和分数，不列入结果表。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：连接表 + 分组 + 过滤

我们可以将 `Candidates` 表和 `Rounds` 表按照 `interview_id` 进行连接，筛选出工作年限至少为 2 年的候选人，然后按照 `candidate_id` 进行分组，计算每个候选人的总分，最后筛选出总分大于 15 分的候选人。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT candidate_id
FROM
    Candidates
    JOIN Rounds USING (interview_id)
WHERE years_of_exp >= 2
GROUP BY 1
HAVING SUM(score) > 15;
```

#### Pandas

```python
import pandas as pd


def accepted_candidates(candidates: pd.DataFrame, rounds: pd.DataFrame) -> pd.DataFrame:
    merged_df = pd.merge(candidates, rounds, on="interview_id")
    filtered_df = merged_df[merged_df["years_of_exp"] >= 2]
    grouped_df = filtered_df.groupby("candidate_id").agg({"score": "sum"})
    return grouped_df[grouped_df["score"] > 15].reset_index()[["candidate_id"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2042. 检查句子中的数字是否递增](https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence){#2042}

{{< tabs "2042" >}}

{{% tab "python" %}}
```python
class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        pre = 0
        for t in s.split():
            if t[0].isdigit():
                if (cur := int(t)) <= pre:
                    return False
                pre = cur
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean areNumbersAscending(String s) {
        int pre = 0;
        for (var t : s.split(" ")) {
            if (t.charAt(0) <= '9') {
                int cur = Integer.parseInt(t);
                if (pre >= cur) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0;
        istringstream is(s);
        string t;
        while (is >> t) {
            if (isdigit(t[0])) {
                int cur = stoi(t);
                if (pre >= cur) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areNumbersAscending(s string) bool {
	pre := 0
	for _, t := range strings.Split(s, " ") {
		if t[0] <= '9' {
			cur, _ := strconv.Atoi(t)
			if pre >= cur {
				return false
			}
			pre = cur
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areNumbersAscending(s: string): boolean {
    let pre = -1;
    for (const cur of s.split(' ')) {
        if (cur[0] <= '9') {
            const num = Number(cur);
            if (num <= pre) {
                return false;
            }
            pre = num;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let mut pre = -1;
        for cur in s.split(' ') {
            if cur.as_bytes()[0] <= b'9' {
                let num = cur.parse::<i32>().unwrap();
                if num <= pre {
                    return false;
                }
                pre = num;
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool areNumbersAscending(char* s) {
    int pre = -1;
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            cur = cur * 10 + s[i] - '0';
        } else {
            if (cur != 0) {
                if (cur <= pre) {
                    return 0;
                }
                pre = cur;
                cur = 0;
            }
        }
    }
    if (cur != 0 && cur <= pre) {
        return 0;
    }
    return 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>句子是由若干 <strong>token</strong> 组成的一个列表，<strong>token</strong> 间用 <strong>单个</strong> 空格分隔，句子没有前导或尾随空格。每个 token 要么是一个由数字 <code>0-9</code> 组成的不含前导零的 <strong>正整数</strong>&nbsp;，要么是一个由小写英文字母组成的 <strong>单词</strong> 。</p>

<ul>
	<li>示例，<code>"a puppy has 2 eyes 4 legs"</code> 是一个由 7 个 token 组成的句子：<code>"2"</code> 和 <code>"4"</code> 是数字，其他像&nbsp;<code>"puppy"</code> 这样的 tokens 属于单词。</li>
</ul>

<p>给你一个表示句子的字符串 <code>s</code> ，你需要检查 <code>s</code> 中的 <strong>全部</strong> 数字是否从左到右严格递增（即，除了最后一个数字，<code>s</code> 中的 <strong>每个</strong> 数字都严格小于它 <strong>右侧</strong> 的数字）。</p>

<p>如果满足题目要求，返回 <code>true</code>&nbsp;，否则，返回<em> </em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2042.Check%20if%20Numbers%20Are%20Ascending%20in%20a%20Sentence/images/example1.png" style="width: 637px; height: 48px;" /></p>

<pre>
<strong>输入：</strong>s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的数字是：1, 3, 4, 6, 12 。
这些数字是按从左到右严格递增的 1 &lt; 3 &lt; 4 &lt; 6 &lt; 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "hello world 5 x 5"
<strong>输出：</strong>false
<strong>解释：</strong>句子中的数字是：<em><strong>5</strong></em>, <strong><em>5</em></strong> 。这些数字不是严格递增的。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="example-3" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2042.Check%20if%20Numbers%20Are%20Ascending%20in%20a%20Sentence/images/example3.png" style="width: 794px; height: 48px;" /></p>

<pre>
<strong>输入：</strong>s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
<strong>输出：</strong>false
<strong>解释：</strong>s 中的数字是：7, <em><strong>51</strong></em>, <em><strong>50</strong></em>, 60 。这些数字不是严格递增的。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "4 5 11 26"
<strong>输出：</strong>true
<strong>解释：</strong>s 中的数字是：4, 5, 11, 26 。
这些数字是按从左到右严格递增的：4 &lt; 5 &lt; 11 &lt; 26 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code> 由小写英文字母、空格和数字 <code>0</code> 到 <code>9</code> 组成（包含 <code>0</code> 和 <code>9</code>）</li>
	<li><code>s</code> 中数字 token 的数目在 <code>2</code> 和 <code>100</code> 之间（包含 <code>2</code> 和 <code>100</code>）</li>
	<li><code>s</code> 中的 token 之间由单个空格分隔</li>
	<li><code>s</code> 中至少有 <strong>两个</strong> 数字</li>
	<li><code>s</code> 中的每个数字都是一个 <strong>小于</strong> <code>100</code> 的 <strong>正</strong> 数，且不含前导零</li>
	<li><code>s</code> 不含前导或尾随空格</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以将字符串 $s$ 按空格分割成若干个单词。然后遍历每个单词，判断其是否为数字，若是数字，则将其转换为整数，与前一个数字比较，若不严格递增，返回 `false`，否则，将当前数字赋值给前一个数字，继续遍历。

遍历结束，说明字符串中的数字严格递增，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        pre = 0
        for t in s.split():
            if t[0].isdigit():
                if (cur := int(t)) <= pre:
                    return False
                pre = cur
        return True
```

#### Java

```java
class Solution {
    public boolean areNumbersAscending(String s) {
        int pre = 0;
        for (var t : s.split(" ")) {
            if (t.charAt(0) <= '9') {
                int cur = Integer.parseInt(t);
                if (pre >= cur) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0;
        istringstream is(s);
        string t;
        while (is >> t) {
            if (isdigit(t[0])) {
                int cur = stoi(t);
                if (pre >= cur) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};
```

#### Go

```go
func areNumbersAscending(s string) bool {
	pre := 0
	for _, t := range strings.Split(s, " ") {
		if t[0] <= '9' {
			cur, _ := strconv.Atoi(t)
			if pre >= cur {
				return false
			}
			pre = cur
		}
	}
	return true
}
```

#### TypeScript

```ts
function areNumbersAscending(s: string): boolean {
    let pre = -1;
    for (const cur of s.split(' ')) {
        if (cur[0] <= '9') {
            const num = Number(cur);
            if (num <= pre) {
                return false;
            }
            pre = num;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let mut pre = -1;
        for cur in s.split(' ') {
            if cur.as_bytes()[0] <= b'9' {
                let num = cur.parse::<i32>().unwrap();
                if num <= pre {
                    return false;
                }
                pre = num;
            }
        }
        true
    }
}
```

#### C

```c
bool areNumbersAscending(char* s) {
    int pre = -1;
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            cur = cur * 10 + s[i] - '0';
        } else {
            if (cur != 0) {
                if (cur <= pre) {
                    return 0;
                }
                pre = cur;
                cur = 0;
            }
        }
    }
    if (cur != 0 && cur <= pre) {
        return 0;
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2043. 简易银行系统](https://leetcode.cn/problems/simple-bank-system){#2043}

{{< tabs "2043" >}}

{{% tab "python" %}}
```python
class Bank:
    def __init__(self, balance: List[int]):
        self.balance = balance
        self.n = len(balance)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if account1 > self.n or account2 > self.n or self.balance[account1 - 1] < money:
            return False
        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if account > self.n:
            return False
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if account > self.n or self.balance[account - 1] < money:
            return False
        self.balance[account - 1] -= money
        return True


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Bank {
    private long[] balance;
    private int n;

    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account > n) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account > n || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > n) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > n || balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Bank struct {
	balance []int64
	n       int
}

func Constructor(balance []int64) Bank {
	return Bank{balance, len(balance)}
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 > this.n || account2 > this.n || this.balance[account1-1] < money {
		return false
	}
	this.balance[account1-1] -= money
	this.balance[account2-1] += money
	return true
}

func (this *Bank) Deposit(account int, money int64) bool {
	if account > this.n {
		return false
	}
	this.balance[account-1] += money
	return true
}

func (this *Bank) Withdraw(account int, money int64) bool {
	if account > this.n || this.balance[account-1] < money {
		return false
	}
	this.balance[account-1] -= money
	return true
}

/**
 * Your Bank object will be instantiated and called as such:
 * obj := Constructor(balance);
 * param_1 := obj.Transfer(account1,account2,money);
 * param_2 := obj.Deposit(account,money);
 * param_3 := obj.Withdraw(account,money);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Bank {
    balance: number[];
    constructor(balance: number[]) {
        this.balance = balance;
    }

    transfer(account1: number, account2: number, money: number): boolean {
        if (
            account1 > this.balance.length ||
            account2 > this.balance.length ||
            money > this.balance[account1 - 1]
        )
            return false;
        this.balance[account1 - 1] -= money;
        this.balance[account2 - 1] += money;
        return true;
    }

    deposit(account: number, money: number): boolean {
        if (account > this.balance.length) return false;
        this.balance[account - 1] += money;
        return true;
    }

    withdraw(account: number, money: number): boolean {
        if (account > this.balance.length || money > this.balance[account - 1]) {
            return false;
        }
        this.balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Bank {
    balance: Vec<i64>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {
    fn new(balance: Vec<i64>) -> Self {
        Bank { balance }
    }

    fn transfer(&mut self, account1: i32, account2: i32, money: i64) -> bool {
        let (account1, account2, n) = (account1 as usize, account2 as usize, self.balance.len());
        if n < account1 || n < account2 {
            return false;
        }
        if self.balance[account1 - 1] < money {
            return false;
        }
        self.balance[account1 - 1] -= money;
        self.balance[account2 - 1] += money;
        true
    }

    fn deposit(&mut self, account: i32, money: i64) -> bool {
        let (account, n) = (account as usize, self.balance.len());
        if n < account {
            return false;
        }
        self.balance[account - 1] += money;
        true
    }

    fn withdraw(&mut self, account: i32, money: i64) -> bool {
        let (account, n) = (account as usize, self.balance.len());
        if n < account {
            return false;
        }
        if self.balance[account - 1] < money {
            return false;
        }
        self.balance[account - 1] -= money;
        true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的任务是为一个很受欢迎的银行设计一款程序，以自动化执行所有传入的交易（转账，存款和取款）。银行共有 <code>n</code> 个账户，编号从 <code>1</code> 到 <code>n</code> 。每个账号的初始余额存储在一个下标从 <strong>0</strong> 开始的整数数组 <code>balance</code>&nbsp;中，其中第 <code>(i + 1)</code> 个账户的初始余额是 <code>balance[i]</code> 。</p>

<p>请你执行所有 <strong>有效的</strong> 交易。如果满足下面全部条件，则交易 <strong>有效</strong> ：</p>

<ul>
	<li>指定的账户数量在 <code>1</code> 和 <code>n</code> 之间，且</li>
	<li>取款或者转账需要的钱的总数 <strong>小于或者等于</strong> 账户余额。</li>
</ul>

<p>实现 <code>Bank</code> 类：</p>

<ul>
	<li><code>Bank(long[] balance)</code> 使用下标从 <strong>0</strong> 开始的整数数组 <code>balance</code> 初始化该对象。</li>
	<li><code>boolean transfer(int account1, int account2, long money)</code> 从编号为&nbsp;<code>account1</code> 的账户向编号为 <code>account2</code> 的账户转帐 <code>money</code> 美元。如果交易成功，返回 <code>true</code> ，否则，返回 <code>false</code> 。</li>
	<li><code>boolean deposit(int account, long money)</code> 向编号为&nbsp;<code>account</code> 的账户存款 <code>money</code> 美元。如果交易成功，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>boolean withdraw(int account, long money)</code> 从编号为 <code>account</code> 的账户取款 <code>money</code> 美元。如果交易成功，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>：
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
<strong>输出：</strong>
[null, true, true, true, false, false]

<strong>解释：</strong>
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // 返回 true ，账户 3 的余额是 $20 ，所以可以取款 $10 。
                         // 账户 3 余额为 $20 - $10 = $10 。
bank.transfer(5, 1, 20); // 返回 true ，账户 5 的余额是 $30 ，所以可以转账 $20 。
                         // 账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
bank.deposit(5, 20);     // 返回 true ，可以向账户 5 存款 $20 。
                         // 账户 5 的余额为 $10 + $20 = $30 。
bank.transfer(3, 4, 15); // 返回 false ，账户 3 的当前余额是 $10 。
                         // 所以无法转账 $15 。
bank.withdraw(10, 50);   // 返回 false ，交易无效，因为账户 10 并不存在。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == balance.length</code></li>
	<li><code>1 &lt;= n, account, account1, account2 &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= balance[i], money &lt;= 10<sup>12</sup></code></li>
	<li><code>transfer</code>, <code>deposit</code>, <code>withdraw</code> 三个函数，<strong>每个</strong> 最多调用 <code>10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意，我们可以使用一个数组 `balance` 来模拟银行账户的余额，数组下标从 0 开始，数组的值表示账户的余额。

-   初始化时，我们将 `balance` 数组赋给成员变量 `this.balance`，并将 `balance` 的长度赋给成员变量 `this.n`。
-   `transfer` 函数中，如果 `account1` 或 `account2` 大于 `n` 或 `balance[account1 - 1]` 小于 `money`，则返回 `false`，否则，将 `balance[account1 - 1]` 减去 `money`，将 `balance[account2 - 1]` 加上 `money`，并返回 `true`。
-   `deposit` 函数中，如果 `account` 大于 `n`，则返回 `false`，否则，将 `balance[account - 1]` 加上 `money`，并返回 `true`。
-   `withdraw` 函数中，如果 `account` 大于 `n` 或 `balance[account - 1]` 小于 `money`，则返回 `false`，否则，将 `balance[account - 1]` 减去 `money`，并返回 `true`。

以上操作的时间复杂度均为 $O(1)$，空间复杂度为 $O(n)$。其中，$n$ 为 `balance` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Bank:
    def __init__(self, balance: List[int]):
        self.balance = balance
        self.n = len(balance)

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if account1 > self.n or account2 > self.n or self.balance[account1 - 1] < money:
            return False
        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if account > self.n:
            return False
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if account > self.n or self.balance[account - 1] < money:
            return False
        self.balance[account - 1] -= money
        return True


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
```

#### Java

```java
class Bank {
    private long[] balance;
    private int n;

    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account > n) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account > n || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
```

#### C++

```cpp
class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long>& balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > n) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > n || balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
```

#### Go

```go
type Bank struct {
	balance []int64
	n       int
}

func Constructor(balance []int64) Bank {
	return Bank{balance, len(balance)}
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 > this.n || account2 > this.n || this.balance[account1-1] < money {
		return false
	}
	this.balance[account1-1] -= money
	this.balance[account2-1] += money
	return true
}

func (this *Bank) Deposit(account int, money int64) bool {
	if account > this.n {
		return false
	}
	this.balance[account-1] += money
	return true
}

func (this *Bank) Withdraw(account int, money int64) bool {
	if account > this.n || this.balance[account-1] < money {
		return false
	}
	this.balance[account-1] -= money
	return true
}

/**
 * Your Bank object will be instantiated and called as such:
 * obj := Constructor(balance);
 * param_1 := obj.Transfer(account1,account2,money);
 * param_2 := obj.Deposit(account,money);
 * param_3 := obj.Withdraw(account,money);
 */
```

#### TypeScript

```ts
class Bank {
    balance: number[];
    constructor(balance: number[]) {
        this.balance = balance;
    }

    transfer(account1: number, account2: number, money: number): boolean {
        if (
            account1 > this.balance.length ||
            account2 > this.balance.length ||
            money > this.balance[account1 - 1]
        )
            return false;
        this.balance[account1 - 1] -= money;
        this.balance[account2 - 1] += money;
        return true;
    }

    deposit(account: number, money: number): boolean {
        if (account > this.balance.length) return false;
        this.balance[account - 1] += money;
        return true;
    }

    withdraw(account: number, money: number): boolean {
        if (account > this.balance.length || money > this.balance[account - 1]) {
            return false;
        }
        this.balance[account - 1] -= money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
```

#### Rust

```rust
struct Bank {
    balance: Vec<i64>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {
    fn new(balance: Vec<i64>) -> Self {
        Bank { balance }
    }

    fn transfer(&mut self, account1: i32, account2: i32, money: i64) -> bool {
        let (account1, account2, n) = (account1 as usize, account2 as usize, self.balance.len());
        if n < account1 || n < account2 {
            return false;
        }
        if self.balance[account1 - 1] < money {
            return false;
        }
        self.balance[account1 - 1] -= money;
        self.balance[account2 - 1] += money;
        true
    }

    fn deposit(&mut self, account: i32, money: i64) -> bool {
        let (account, n) = (account as usize, self.balance.len());
        if n < account {
            return false;
        }
        self.balance[account - 1] += money;
        true
    }

    fn withdraw(&mut self, account: i32, money: i64) -> bool {
        let (account, n) = (account as usize, self.balance.len());
        if n < account {
            return false;
        }
        if self.balance[account - 1] < money {
            return false;
        }
        self.balance[account - 1] -= money;
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2044. 统计按位或能得到最大值的子集数目](https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets){#2044}

{{< tabs "2044" >}}

{{% tab "python" %}}
```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        mx = 0
        for mask in range(1 << n):
            t = 0
            for i, v in enumerate(nums):
                if (mask >> i) & 1:
                    t |= v
            if mx < t:
                mx = t
                ans = 1
            elif mx == t:
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int mx = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 1) {
                    t |= nums[i];
                }
            }
            if (mx < t) {
                mx = t;
                ans = 1;
            } else if (mx == t) {
                ++ans;
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
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    t |= nums[i];
                }
            }
            if (mx < t) {
                mx = t;
                ans = 1;
            } else if (mx == t)
                ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countMaxOrSubsets(nums []int) (ans int) {
	n := len(nums)
	mx := 0

	for mask := 0; mask < (1 << n); mask++ {
		t := 0
		for i, v := range nums {
			if (mask>>i)&1 == 1 {
				t |= v
			}
		}
		if mx < t {
			mx = t
			ans = 1
		} else if mx == t {
			ans++
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countMaxOrSubsets(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    let mx = 0;

    for (let mask = 0; mask < 1 << n; mask++) {
        let t = 0;
        for (let i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                t |= nums[i];
            }
        }
        if (mx < t) {
            mx = t;
            ans = 1;
        } else if (mx === t) {
            ans++;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut mx = 0;

        for mask in 0..(1 << n) {
            let mut t = 0;
            for i in 0..n {
                if (mask >> i) & 1 == 1 {
                    t |= nums[i];
                }
            }
            if mx < t {
                mx = t;
                ans = 1;
            } else if mx == t {
                ans += 1;
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

<p>给你一个整数数组 <code>nums</code> ，请你找出 <code>nums</code> 子集 <strong>按位或</strong> 可能得到的<strong> </strong><strong>最大值</strong> ，并返回按位或能得到最大值的 <strong>不同非空子集的数目</strong> 。</p>

<p>如果数组 <code>a</code> 可以由数组 <code>b</code> 删除一些元素（或不删除）得到，则认为数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>子集</strong> 。如果选中的元素下标位置不一样，则认为两个子集 <strong>不同</strong> 。</p>

<p>对数组 <code>a</code> 执行 <strong>按位或</strong>&nbsp;，结果等于 <code>a[0] <strong>OR</strong> a[1] <strong>OR</strong> ... <strong>OR</strong> a[a.length - 1]</code>（下标从 <strong>0</strong> 开始）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1]
<strong>输出：</strong>2
<strong>解释：</strong>子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2]
<strong>输出：</strong>7
<strong>解释：</strong>[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 2<sup>3</sup> - 1 = 7 个子集。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,5]
<strong>输出：</strong>6
<strong>解释：</strong>子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 16</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

数组 $\textit{nums}$ 中按位或的最大值 $\textit{mx}$ 可以通过对数组中所有元素按位或得到。

然后我们可以使用深度优先搜索来枚举所有子集，统计按位或等于 $\textit{mx}$ 的子集个数。我们设计一个函数 $\text{dfs(i, t)}$，表示从下标 $\textit{i}$ 开始，当前按位或的值为 $\textit{t}$ 的子集个数。初始时 $\textit{i} = 0$, $\textit{t} = 0$。

在函数 $\text{dfs(i, t)}$ 中，如果 $\textit{i}$ 等于数组长度，说明已经枚举完所有元素，此时如果 $\textit{t}$ 等于 $\textit{mx}$，则答案加一。否则，我们可以选择不包含当前元素 $\textit{nums[i]}$，或者包含当前元素 $\textit{nums[i]}$，因此我们可以递归调用 $\text{dfs(i + 1, t)}$ 和 $\text{dfs(i + 1, t | nums[i])}$。

最后返回答案即可。

时间复杂度 $O(2^n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        def dfs(i, t):
            nonlocal ans, mx
            if i == len(nums):
                if t == mx:
                    ans += 1
                return
            dfs(i + 1, t)
            dfs(i + 1, t | nums[i])

        ans = 0
        mx = reduce(lambda x, y: x | y, nums)
        dfs(0, 0)
        return ans
```

#### Java

```java
class Solution {
    private int mx;
    private int ans;
    private int[] nums;

    public int countMaxOrSubsets(int[] nums) {
        mx = 0;
        for (int x : nums) {
            mx |= x;
        }
        this.nums = nums;
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int t) {
        if (i == nums.length) {
            if (t == mx) {
                ++ans;
            }
            return;
        }
        dfs(i + 1, t);
        dfs(i + 1, t | nums[i]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        int mx = accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
        auto dfs = [&](this auto&& dfs, int i, int t) {
            if (i == nums.size()) {
                if (t == mx) {
                    ans++;
                }
                return;
            }
            dfs(i + 1, t);
            dfs(i + 1, t | nums[i]);
        };
        dfs(0, 0);
        return ans;
    }
};
```

#### Go

```go
func countMaxOrSubsets(nums []int) (ans int) {
	mx := 0
	for _, x := range nums {
		mx |= x
	}

	var dfs func(i, t int)
	dfs = func(i, t int) {
		if i == len(nums) {
			if t == mx {
				ans++
			}
			return
		}
		dfs(i+1, t)
		dfs(i+1, t|nums[i])
	}

	dfs(0, 0)
	return
}
```

#### TypeScript

```ts
function countMaxOrSubsets(nums: number[]): number {
    let ans = 0;
    const mx = nums.reduce((x, y) => x | y, 0);

    const dfs = (i: number, t: number) => {
        if (i === nums.length) {
            if (t === mx) {
                ans++;
            }
            return;
        }
        dfs(i + 1, t);
        dfs(i + 1, t | nums[i]);
    };

    dfs(0, 0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mx = nums.iter().fold(0, |x, &y| x | y);

        fn dfs(i: usize, t: i32, nums: &Vec<i32>, mx: i32, ans: &mut i32) {
            if i == nums.len() {
                if t == mx {
                    *ans += 1;
                }
                return;
            }
            dfs(i + 1, t, nums, mx, ans);
            dfs(i + 1, t | nums[i], nums, mx, ans);
        }

        dfs(0, 0, &nums, mx, &mut ans);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制枚举

我们可以使用二进制枚举来统计所有子集的按位或结果。对于长度为 $n$ 的数组 $\textit{nums}$，我们可以使用一个整数 $\textit{mask}$ 来表示一个子集，其中 $\textit{mask}$ 的第 $i$ 位为 1 表示包含元素 $\textit{nums[i]}$，为 0 则表示不包含。

我们可以遍历所有可能的 $\textit{mask}$，从 $0$ 到 $2^n - 1$。对于每个 $\textit{mask}$，我们可以计算出对应子集的按位或结果，并更新最大值 $\textit{mx}$ 和答案 $\textit{ans}$。

时间复杂度 $O(2^n \cdot n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        mx = 0
        for mask in range(1 << n):
            t = 0
            for i, v in enumerate(nums):
                if (mask >> i) & 1:
                    t |= v
            if mx < t:
                mx = t
                ans = 1
            elif mx == t:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int mx = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 1) {
                    t |= nums[i];
                }
            }
            if (mx < t) {
                mx = t;
                ans = 1;
            } else if (mx == t) {
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
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = 0;
        for (int mask = 1; mask < 1 << n; ++mask) {
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    t |= nums[i];
                }
            }
            if (mx < t) {
                mx = t;
                ans = 1;
            } else if (mx == t)
                ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func countMaxOrSubsets(nums []int) (ans int) {
	n := len(nums)
	mx := 0

	for mask := 0; mask < (1 << n); mask++ {
		t := 0
		for i, v := range nums {
			if (mask>>i)&1 == 1 {
				t |= v
			}
		}
		if mx < t {
			mx = t
			ans = 1
		} else if mx == t {
			ans++
		}
	}

	return
}
```

#### TypeScript

```ts
function countMaxOrSubsets(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    let mx = 0;

    for (let mask = 0; mask < 1 << n; mask++) {
        let t = 0;
        for (let i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                t |= nums[i];
            }
        }
        if (mx < t) {
            mx = t;
            ans = 1;
        } else if (mx === t) {
            ans++;
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut mx = 0;

        for mask in 0..(1 << n) {
            let mut t = 0;
            for i in 0..n {
                if (mask >> i) & 1 == 1 {
                    t |= nums[i];
                }
            }
            if mx < t {
                mx = t;
                ans = 1;
            } else if mx == t {
                ans += 1;
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

# [2045. 到达目的地的第二短时间](https://leetcode.cn/problems/second-minimum-time-to-reach-destination){#2045}

{{< tabs "2045" >}}

{{% tab "python" %}}
```python
class Solution:
    def secondMinimum(
        self, n: int, edges: List[List[int]], time: int, change: int
    ) -> int:
        g = defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)
        q = deque([(1, 0)])
        dist = [[inf] * 2 for _ in range(n + 1)]
        dist[1][1] = 0
        while q:
            u, d = q.popleft()
            for v in g[u]:
                if d + 1 < dist[v][0]:
                    dist[v][0] = d + 1
                    q.append((v, d + 1))
                elif dist[v][0] < d + 1 < dist[v][1]:
                    dist[v][1] = d + 1
                    if v == n:
                        break
                    q.append((v, d + 1))
        ans = 0
        for i in range(dist[n][1]):
            ans += time
            if i < dist[n][1] - 1 and (ans // change) % 2 == 1:
                ans = (ans + change) // change * change
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<int[]> q = new LinkedList<>();
        q.offerLast(new int[] {1, 0});
        int[][] dist = new int[n + 1][2];
        for (int i = 0; i < n + 1; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[1][1] = 0;
        while (!q.isEmpty()) {
            int[] e = q.pollFirst();
            int u = e[0], d = e[1];
            for (int v : g[u]) {
                if (d + 1 < dist[v][0]) {
                    dist[v][0] = d + 1;
                    q.offerLast(new int[] {v, d + 1});
                } else if (dist[v][0] < d + 1 && d + 1 < dist[v][1]) {
                    dist[v][1] = d + 1;
                    if (v == n) {
                        break;
                    }
                    q.offerLast(new int[] {v, d + 1});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < dist[n][1]; ++i) {
            ans += time;
            if (i < dist[n][1] - 1 && (ans / change) % 2 == 1) {
                ans = (ans + change) / change * change;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>城市用一个 <strong>双向连通</strong> 图表示，图中有 <code>n</code> 个节点，从 <code>1</code> 到 <code>n</code> 编号（包含 <code>1</code> 和 <code>n</code>）。图中的边用一个二维整数数组 <code>edges</code> 表示，其中每个 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示一条节点&nbsp;<code>u<sub>i</sub></code> 和节点&nbsp;<code>v<sub>i</sub></code> 之间的双向连通边。每组节点对由 <strong>最多一条</strong> 边连通，顶点不存在连接到自身的边。穿过任意一条边的时间是 <code>time</code>&nbsp;分钟。</p>

<p>每个节点都有一个交通信号灯，每 <code>change</code> 分钟改变一次，从绿色变成红色，再由红色变成绿色，循环往复。所有信号灯都&nbsp;<strong>同时</strong> 改变。你可以在 <strong>任何时候</strong> 进入某个节点，但是 <strong>只能</strong> 在节点&nbsp;<strong>信号灯是绿色时</strong> 才能离开。如果信号灯是&nbsp; <strong>绿色</strong> ，你 <strong>不能</strong> 在节点等待，必须离开。</p>

<p><strong>第二小的值</strong> 是&nbsp;<strong>严格大于</strong> 最小值的所有值中最小的值。</p>

<ul>
	<li>例如，<code>[2, 3, 4]</code> 中第二小的值是 <code>3</code> ，而 <code>[2, 2, 4]</code> 中第二小的值是 <code>4</code> 。</li>
</ul>

<p>给你 <code>n</code>、<code>edges</code>、<code>time</code> 和 <code>change</code> ，返回从节点 <code>1</code> 到节点 <code>n</code> 需要的 <strong>第二短时间</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>你可以 <strong>任意次</strong> 穿过任意顶点，<strong>包括</strong> <code>1</code> 和 <code>n</code> 。</li>
	<li>你可以假设在 <strong>启程时</strong> ，所有信号灯刚刚变成 <strong>绿色</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2045.Second%20Minimum%20Time%20to%20Reach%20Destination/images/e1.png" style="width: 200px; height: 250px;" />        <img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2045.Second%20Minimum%20Time%20to%20Reach%20Destination/images/e2.png" style="width: 200px; height: 250px;" /></p>

<pre>
<strong>输入：</strong>n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
<strong>输出：</strong>13
<strong>解释：</strong>
上面的左图展现了给出的城市交通图。
右图中的蓝色路径是最短时间路径。
花费的时间是：
- 从节点 1 开始，总花费时间=0
- 1 -&gt; 4：3 分钟，总花费时间=3
- 4 -&gt; 5：3 分钟，总花费时间=6
因此需要的最小时间是 6 分钟。

右图中的红色路径是第二短时间路径。
- 从节点 1 开始，总花费时间=0
- 1 -&gt; 3：3 分钟，总花费时间=3
- 3 -&gt; 4：3 分钟，总花费时间=6
- 在节点 4 等待 4 分钟，总花费时间=10
- 4 -&gt; 5：3 分钟，总花费时间=13
因此第二短时间是 13 分钟。      
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2045.Second%20Minimum%20Time%20to%20Reach%20Destination/images/eg2.png" style="width: 225px; height: 50px;" /></p>

<pre>
<strong>输入：</strong>n = 2, edges = [[1,2]], time = 3, change = 2
<strong>输出：</strong>11
<strong>解释：</strong>
最短时间路径是 1 -&gt; 2 ，总花费时间 = 3 分钟
第二短时间路径是 1 -&gt; 2 -&gt; 1 -&gt; 2 ，总花费时间 = 11 分钟</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>n - 1 &lt;= edges.length &lt;= min(2 * 10<sup>4</sup>, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>不含重复边</li>
	<li>每个节点都可以从其他节点直接或者间接到达</li>
	<li><code>1 &lt;= time, change &lt;= 10<sup>3</sup></code></li>
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
class Solution:
    def secondMinimum(
        self, n: int, edges: List[List[int]], time: int, change: int
    ) -> int:
        g = defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)
        q = deque([(1, 0)])
        dist = [[inf] * 2 for _ in range(n + 1)]
        dist[1][1] = 0
        while q:
            u, d = q.popleft()
            for v in g[u]:
                if d + 1 < dist[v][0]:
                    dist[v][0] = d + 1
                    q.append((v, d + 1))
                elif dist[v][0] < d + 1 < dist[v][1]:
                    dist[v][1] = d + 1
                    if v == n:
                        break
                    q.append((v, d + 1))
        ans = 0
        for i in range(dist[n][1]):
            ans += time
            if i < dist[n][1] - 1 and (ans // change) % 2 == 1:
                ans = (ans + change) // change * change
        return ans
```

#### Java

```java
class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<int[]> q = new LinkedList<>();
        q.offerLast(new int[] {1, 0});
        int[][] dist = new int[n + 1][2];
        for (int i = 0; i < n + 1; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[1][1] = 0;
        while (!q.isEmpty()) {
            int[] e = q.pollFirst();
            int u = e[0], d = e[1];
            for (int v : g[u]) {
                if (d + 1 < dist[v][0]) {
                    dist[v][0] = d + 1;
                    q.offerLast(new int[] {v, d + 1});
                } else if (dist[v][0] < d + 1 && d + 1 < dist[v][1]) {
                    dist[v][1] = d + 1;
                    if (v == n) {
                        break;
                    }
                    q.offerLast(new int[] {v, d + 1});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < dist[n][1]; ++i) {
            ans += time;
            if (i < dist[n][1] - 1 && (ans / change) % 2 == 1) {
                ans = (ans + change) / change * change;
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2046. 给按照绝对值排序的链表排序 🔒](https://leetcode.cn/problems/sort-linked-list-already-sorted-using-absolute-values){#2046}

{{< tabs "2046" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = head, head.next
        while curr:
            if curr.val < 0:
                t = curr.next
                prev.next = t
                curr.next = head
                head = curr
                curr = t
            else:
                prev, curr = curr, curr.next
        return head
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortLinkedList(ListNode head) {
        ListNode prev = head, curr = head.next;
        while (curr != null) {
            if (curr.val < 0) {
                ListNode t = curr.next;
                prev.next = t;
                curr.next = head;
                head = curr;
                curr = t;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val < 0) {
                auto t = curr->next;
                prev->next = t;
                curr->next = head;
                head = curr;
                curr = t;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortLinkedList(head *ListNode) *ListNode {
	prev, curr := head, head.Next
	for curr != nil {
		if curr.Val < 0 {
			t := curr.Next
			prev.Next = t
			curr.Next = head
			head = curr
			curr = t
		} else {
			prev, curr = curr, curr.Next
		}
	}
	return head
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function sortLinkedList(head: ListNode | null): ListNode | null {
    let [prev, curr] = [head, head.next];
    while (curr !== null) {
        if (curr.val < 0) {
            const t = curr.next;
            prev.next = t;
            curr.next = head;
            head = curr;
            curr = t;
        } else {
            [prev, curr] = [curr, curr.next];
        }
    }
    return head;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个链表的头结点&nbsp;<code>head</code>&nbsp;，这个链表是根据结点的<strong>绝对值</strong>进行<strong>升序</strong>排序, 返回重新根据<strong>节点的值</strong>进行<strong>升序</strong>排序的链表。

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2046.Sort%20Linked%20List%20Already%20Sorted%20Using%20Absolute%20Values/images/image-20211017201240-3.png" style="width: 621px; height: 250px;">
<pre><strong>输入:</strong> head = [0,2,-5,5,10,-10]
<strong>输出:</strong> [-10,-5,0,2,5,10]
<strong>解释:</strong>
根据结点的值的绝对值排序的链表是 [0,2,-5,5,10,-10].
根据结点的值排序的链表是 [-10,-5,0,2,5,10].
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2046.Sort%20Linked%20List%20Already%20Sorted%20Using%20Absolute%20Values/images/image-20211017201318-4.png" style="width: 338px; height: 250px;"></p>

<pre><strong>输入:</strong> head = [0,1,2]
<strong>输出:</strong> [0,1,2]
<strong>解释:</strong>
这个链表已经是升序的了。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> head = [1]
<strong>输出:</strong> [1]
<strong>解释:</strong>
这个链表已经是升序的了。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>链表节点数的范围是&nbsp;<code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
	<li><code>head</code>&nbsp;是根据结点绝对值升序排列好的链表.</li>
</ul>

<p>&nbsp;</p>
<strong>进阶:</strong>

<ul>
	<li>你可以在<code>O(n)</code>的时间复杂度之内解决这个问题吗?</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：头插法

我们先默认第一个点已经排序完毕，然后从第二个点开始，遇到值为负数的节点，采用头插法；非负数，则继续往下遍历即可。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = head, head.next
        while curr:
            if curr.val < 0:
                t = curr.next
                prev.next = t
                curr.next = head
                head = curr
                curr = t
            else:
                prev, curr = curr, curr.next
        return head
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortLinkedList(ListNode head) {
        ListNode prev = head, curr = head.next;
        while (curr != null) {
            if (curr.val < 0) {
                ListNode t = curr.next;
                prev.next = t;
                curr.next = head;
                head = curr;
                curr = t;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        return head;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val < 0) {
                auto t = curr->next;
                prev->next = t;
                curr->next = head;
                head = curr;
                curr = t;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortLinkedList(head *ListNode) *ListNode {
	prev, curr := head, head.Next
	for curr != nil {
		if curr.Val < 0 {
			t := curr.Next
			prev.Next = t
			curr.Next = head
			head = curr
			curr = t
		} else {
			prev, curr = curr, curr.Next
		}
	}
	return head
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function sortLinkedList(head: ListNode | null): ListNode | null {
    let [prev, curr] = [head, head.next];
    while (curr !== null) {
        if (curr.val < 0) {
            const t = curr.next;
            prev.next = t;
            curr.next = head;
            head = curr;
            curr = t;
        } else {
            [prev, curr] = [curr, curr.next];
        }
    }
    return head;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2047. 句子中的有效单词数](https://leetcode.cn/problems/number-of-valid-words-in-a-sentence){#2047}

{{< tabs "2047" >}}

{{% tab "python" %}}
```python
class Solution:
    def countValidWords(self, sentence: str) -> int:
        def check(s: str) -> bool:
            st = False
            for i, c in enumerate(s):
                if c.isdigit() or (c in "!.," and i < len(s) - 1):
                    return False
                if c == "-":
                    if (
                        st
                        or i in (0, len(s) - 1)
                        or not s[i - 1].isalpha()
                        or not s[i + 1].isalpha()
                    ):
                        return False
                    st = True
            return True

        return sum(check(s) for s in sentence.split())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countValidWords(String sentence) {
        int ans = 0;
        for (String s : sentence.split(" ")) {
            ans += check(s.toCharArray());
        }
        return ans;
    }

    private int check(char[] s) {
        if (s.length == 0) {
            return 0;
        }
        boolean st = false;
        for (int i = 0; i < s.length; ++i) {
            if (Character.isDigit(s[i])) {
                return 0;
            }
            if ((s[i] == '!' || s[i] == '.' || s[i] == ',') && i < s.length - 1) {
                return 0;
            }
            if (s[i] == '-') {
                if (st || i == 0 || i == s.length - 1) {
                    return 0;
                }
                if (!Character.isAlphabetic(s[i - 1]) || !Character.isAlphabetic(s[i + 1])) {
                    return 0;
                }
                st = true;
            }
        }
        return 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countValidWords(string sentence) {
        auto check = [](const string& s) -> int {
            bool st = false;
            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    return 0;
                }
                if ((s[i] == '!' || s[i] == '.' || s[i] == ',') && i < s.length() - 1) {
                    return 0;
                }
                if (s[i] == '-') {
                    if (st || i == 0 || i == s.length() - 1) {
                        return 0;
                    }
                    if (!isalpha(s[i - 1]) || !isalpha(s[i + 1])) {
                        return 0;
                    }
                    st = true;
                }
            }
            return 1;
        };

        int ans = 0;
        stringstream ss(sentence);
        string s;
        while (ss >> s) {
            ans += check(s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countValidWords(sentence string) (ans int) {
	check := func(s string) int {
		if len(s) == 0 {
			return 0
		}
		st := false
		for i, r := range s {
			if unicode.IsDigit(r) {
				return 0
			}
			if (r == '!' || r == '.' || r == ',') && i < len(s)-1 {
				return 0
			}
			if r == '-' {
				if st || i == 0 || i == len(s)-1 {
					return 0
				}
				if !unicode.IsLetter(rune(s[i-1])) || !unicode.IsLetter(rune(s[i+1])) {
					return 0
				}
				st = true
			}
		}
		return 1
	}
	for _, s := range strings.Fields(sentence) {
		ans += check(s)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countValidWords(sentence: string): number {
    const check = (s: string): number => {
        if (s.length === 0) {
            return 0;
        }
        let st = false;
        for (let i = 0; i < s.length; ++i) {
            if (/\d/.test(s[i])) {
                return 0;
            }
            if (['!', '.', ','].includes(s[i]) && i < s.length - 1) {
                return 0;
            }
            if (s[i] === '-') {
                if (st || [0, s.length - 1].includes(i)) {
                    return 0;
                }
                if (!/[a-zA-Z]/.test(s[i - 1]) || !/[a-zA-Z]/.test(s[i + 1])) {
                    return 0;
                }
                st = true;
            }
        }
        return 1;
    };
    return sentence.split(/\s+/).reduce((acc, s) => acc + check(s), 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>句子仅由小写字母（<code>'a'</code> 到 <code>'z'</code>）、数字（<code>'0'</code> 到 <code>'9'</code>）、连字符（<code>'-'</code>）、标点符号（<code>'!'</code>、<code>'.'</code> 和 <code>','</code>）以及空格（<code>' '</code>）组成。每个句子可以根据空格分解成 <strong>一个或者多个 token</strong> ，这些 token 之间由一个或者多个空格 <code>' '</code> 分隔。</p>

<p>如果一个 token 同时满足下述条件，则认为这个 token 是一个有效单词：</p>

<ul>
	<li>仅由小写字母、连字符和/或标点（不含数字）组成。</li>
	<li><strong>至多一个</strong> 连字符 <code>'-'</code> 。如果存在，连字符两侧应当都存在小写字母（<code>"a-b"</code> 是一个有效单词，但 <code>"-ab"</code> 和 <code>"ab-"</code> 不是有效单词）。</li>
	<li><strong>至多一个 </strong>标点符号。如果存在，标点符号应当位于 token 的 <strong>末尾</strong> 。</li>
</ul>

<p>这里给出几个有效单词的例子：<code>"a-b."</code>、<code>"afad"</code>、<code>"ba-c"</code>、<code>"a!"</code> 和 <code>"!"</code> 。</p>

<p>给你一个字符串 <code>sentence</code> ，请你找出并返回<em> </em><code>sentence</code> 中<strong> 有效单词的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "<em><strong>cat</strong></em> <em><strong>and</strong></em>  <em><strong>dog</strong></em>"
<strong>输出：</strong>3
<strong>解释：</strong>句子中的有效单词是 "cat"、"and" 和 "dog"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "!this  1-s b8d!"
<strong>输出：</strong>0
<strong>解释：</strong>句子中没有有效单词
"!this" 不是有效单词，因为它以一个标点开头
"1-s" 和 "b8d" 也不是有效单词，因为它们都包含数字
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = "<em><strong>alice</strong></em> <em><strong>and</strong></em>  <em><strong>bob</strong></em> <em><strong>are</strong></em> <em><strong>playing</strong></em> stone-game10"
<strong>输出：</strong>5
<strong>解释：</strong>句子中的有效单词是 "alice"、"and"、"bob"、"are" 和 "playing"
"stone-game10" 不是有效单词，因为它含有数字
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 1000</code></li>
	<li><code>sentence</code> 由小写英文字母、数字（<code>0-9</code>）、以及字符（<code>' '</code>、<code>'-'</code>、<code>'!'</code>、<code>'.'</code> 和 <code>','</code>）组成</li>
	<li>句子中至少有 <code>1</code> 个 token</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们首先将句子按空格分割成单词，然后对每个单词进行检查，判断是否为有效单词。

对于每个单词，我们可以使用一个布尔变量 $\textit{st}$ 来记录是否已经出现过连字符，然后遍历单词中的每个字符，根据题目描述的规则进行判断。

对于每个字符 $s[i]$，我们有以下几种情况：

-   如果 $s[i]$ 是数字，那么 $s$ 不是有效单词，直接返回 $\text{false}$；
-   如果 $s[i]$ 是标点符号（'!'、'.'、','）且 $i < \text{len}(s) - 1$，那么 $s$ 不是有效单词，直接返回 $\text{false}$；
-   如果 $s[i]$ 是连字符，那么我们需要判断是否满足以下条件：
    -   连字符只能出现一次；
    -   连字符不能出现在单词的开头或结尾；
    -   连字符两侧必须是字母；
-   如果 $s[i]$ 是字母，那么我们不需要做任何处理。

最后，我们统计出句子中的有效单词数即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是句子的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countValidWords(self, sentence: str) -> int:
        def check(s: str) -> bool:
            st = False
            for i, c in enumerate(s):
                if c.isdigit() or (c in "!.," and i < len(s) - 1):
                    return False
                if c == "-":
                    if (
                        st
                        or i in (0, len(s) - 1)
                        or not s[i - 1].isalpha()
                        or not s[i + 1].isalpha()
                    ):
                        return False
                    st = True
            return True

        return sum(check(s) for s in sentence.split())
```

#### Java

```java
class Solution {
    public int countValidWords(String sentence) {
        int ans = 0;
        for (String s : sentence.split(" ")) {
            ans += check(s.toCharArray());
        }
        return ans;
    }

    private int check(char[] s) {
        if (s.length == 0) {
            return 0;
        }
        boolean st = false;
        for (int i = 0; i < s.length; ++i) {
            if (Character.isDigit(s[i])) {
                return 0;
            }
            if ((s[i] == '!' || s[i] == '.' || s[i] == ',') && i < s.length - 1) {
                return 0;
            }
            if (s[i] == '-') {
                if (st || i == 0 || i == s.length - 1) {
                    return 0;
                }
                if (!Character.isAlphabetic(s[i - 1]) || !Character.isAlphabetic(s[i + 1])) {
                    return 0;
                }
                st = true;
            }
        }
        return 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countValidWords(string sentence) {
        auto check = [](const string& s) -> int {
            bool st = false;
            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    return 0;
                }
                if ((s[i] == '!' || s[i] == '.' || s[i] == ',') && i < s.length() - 1) {
                    return 0;
                }
                if (s[i] == '-') {
                    if (st || i == 0 || i == s.length() - 1) {
                        return 0;
                    }
                    if (!isalpha(s[i - 1]) || !isalpha(s[i + 1])) {
                        return 0;
                    }
                    st = true;
                }
            }
            return 1;
        };

        int ans = 0;
        stringstream ss(sentence);
        string s;
        while (ss >> s) {
            ans += check(s);
        }
        return ans;
    }
};
```

#### Go

```go
func countValidWords(sentence string) (ans int) {
	check := func(s string) int {
		if len(s) == 0 {
			return 0
		}
		st := false
		for i, r := range s {
			if unicode.IsDigit(r) {
				return 0
			}
			if (r == '!' || r == '.' || r == ',') && i < len(s)-1 {
				return 0
			}
			if r == '-' {
				if st || i == 0 || i == len(s)-1 {
					return 0
				}
				if !unicode.IsLetter(rune(s[i-1])) || !unicode.IsLetter(rune(s[i+1])) {
					return 0
				}
				st = true
			}
		}
		return 1
	}
	for _, s := range strings.Fields(sentence) {
		ans += check(s)
	}
	return ans
}
```

#### TypeScript

```ts
function countValidWords(sentence: string): number {
    const check = (s: string): number => {
        if (s.length === 0) {
            return 0;
        }
        let st = false;
        for (let i = 0; i < s.length; ++i) {
            if (/\d/.test(s[i])) {
                return 0;
            }
            if (['!', '.', ','].includes(s[i]) && i < s.length - 1) {
                return 0;
            }
            if (s[i] === '-') {
                if (st || [0, s.length - 1].includes(i)) {
                    return 0;
                }
                if (!/[a-zA-Z]/.test(s[i - 1]) || !/[a-zA-Z]/.test(s[i + 1])) {
                    return 0;
                }
                st = true;
            }
        }
        return 1;
    };
    return sentence.split(/\s+/).reduce((acc, s) => acc + check(s), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2048. 下一个更大的数值平衡数](https://leetcode.cn/problems/next-greater-numerically-balanced-number){#2048}

{{< tabs "2048" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for x in count(n + 1):
            y = x
            cnt = [0] * 10
            while y:
                y, v = divmod(y, 10)
                cnt[v] += 1
            if all(v == 0 or i == v for i, v in enumerate(cnt)):
                return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nextBeautifulNumber(int n) {
        for (int x = n + 1;; ++x) {
            int[] cnt = new int[10];
            for (int y = x; y > 0; y /= 10) {
                ++cnt[y % 10];
            }
            boolean ok = true;
            for (int y = x; y > 0; y /= 10) {
                if (y % 10 != cnt[y % 10]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return x;
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
    int nextBeautifulNumber(int n) {
        for (int x = n + 1;; ++x) {
            int cnt[10]{};
            for (int y = x; y > 0; y /= 10) {
                ++cnt[y % 10];
            }
            bool ok = true;
            for (int y = x; y > 0; y /= 10) {
                if (y % 10 != cnt[y % 10]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return x;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextBeautifulNumber(n int) int {
	for x := n + 1; ; x++ {
		cnt := [10]int{}
		for y := x; y > 0; y /= 10 {
			cnt[y%10]++
		}
		ok := true
		for y := x; y > 0; y /= 10 {
			if y%10 != cnt[y%10] {
				ok = false
				break
			}
		}
		if ok {
			return x
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextBeautifulNumber(n: number): number {
    for (let x = n + 1; ; ++x) {
        const cnt: number[] = Array(10).fill(0);
        for (let y = x; y > 0; y = (y / 10) | 0) {
            cnt[y % 10]++;
        }
        let ok = true;
        for (let i = 0; i < 10; ++i) {
            if (cnt[i] && cnt[i] !== i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return x;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果整数&nbsp; <code>x</code> 满足：对于每个数位&nbsp;<code>d</code> ，这个数位&nbsp;<strong>恰好</strong> 在 <code>x</code> 中出现 <code>d</code> 次。那么整数 <code>x</code> 就是一个 <strong>数值平衡数</strong> 。</p>

<p>给你一个整数 <code>n</code> ，请你返回 <strong>严格大于</strong> <code>n</code> 的 <strong>最小数值平衡数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>22
<strong>解释：</strong>
22 是一个数值平衡数，因为：
- 数字 2 出现 2 次 
这也是严格大于 1 的最小数值平衡数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1000
<strong>输出：</strong>1333
<strong>解释：</strong>
1333 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。 
这也是严格大于 1000 的最小数值平衡数。
注意，1022 不能作为本输入的答案，因为数字 0 的出现次数超过了 0 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3000
<strong>输出：</strong>3133
<strong>解释：</strong>
3133 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。 
这也是严格大于 3000 的最小数值平衡数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们注意到，题目中 $n$ 的范围是 $[0, 10^6]$，而大于 $10^6$ 的其中一个数值平衡数是 $1224444$，因此我们直接枚举 $x \in [n + 1, ..]$，然后判断 $x$ 是否是数值平衡数即可。枚举的 $x$ 一定不会超过 $1224444$。

时间复杂度 $O(M - n)$，其中 $M = 1224444$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for x in count(n + 1):
            y = x
            cnt = [0] * 10
            while y:
                y, v = divmod(y, 10)
                cnt[v] += 1
            if all(v == 0 or i == v for i, v in enumerate(cnt)):
                return x
```

#### Java

```java
class Solution {
    public int nextBeautifulNumber(int n) {
        for (int x = n + 1;; ++x) {
            int[] cnt = new int[10];
            for (int y = x; y > 0; y /= 10) {
                ++cnt[y % 10];
            }
            boolean ok = true;
            for (int y = x; y > 0; y /= 10) {
                if (y % 10 != cnt[y % 10]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return x;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int x = n + 1;; ++x) {
            int cnt[10]{};
            for (int y = x; y > 0; y /= 10) {
                ++cnt[y % 10];
            }
            bool ok = true;
            for (int y = x; y > 0; y /= 10) {
                if (y % 10 != cnt[y % 10]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return x;
            }
        }
    }
};
```

#### Go

```go
func nextBeautifulNumber(n int) int {
	for x := n + 1; ; x++ {
		cnt := [10]int{}
		for y := x; y > 0; y /= 10 {
			cnt[y%10]++
		}
		ok := true
		for y := x; y > 0; y /= 10 {
			if y%10 != cnt[y%10] {
				ok = false
				break
			}
		}
		if ok {
			return x
		}
	}
}
```

#### TypeScript

```ts
function nextBeautifulNumber(n: number): number {
    for (let x = n + 1; ; ++x) {
        const cnt: number[] = Array(10).fill(0);
        for (let y = x; y > 0; y = (y / 10) | 0) {
            cnt[y % 10]++;
        }
        let ok = true;
        for (let i = 0; i < 10; ++i) {
            if (cnt[i] && cnt[i] !== i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return x;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2049. 统计最高分的节点数目](https://leetcode.cn/problems/count-nodes-with-the-highest-score){#2049}

{{< tabs "2049" >}}

{{% tab "python" %}}
```python
class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        def dfs(i: int, fa: int):
            cnt = score = 1
            for j in g[i]:
                if j != fa:
                    t = dfs(j, i)
                    score *= t
                    cnt += t
            if n - cnt:
                score *= n - cnt
            nonlocal ans, mx
            if mx < score:
                mx = score
                ans = 1
            elif mx == score:
                ans += 1
            return cnt

        n = len(parents)
        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parents[i]].append(i)
        ans = mx = 0
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private long mx;
    private int n;

    public int countHighestScoreNodes(int[] parents) {
        n = parents.length;
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            g[parents[i]].add(i);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int i, int fa) {
        int cnt = 1;
        long score = 1;
        for (int j : g[i]) {
            if (j != fa) {
                int t = dfs(j, i);
                cnt += t;
                score *= t;
            }
        }
        if (n - cnt > 0) {
            score *= n - cnt;
        }
        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx == score) {
            ++ans;
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
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> g[n];
        for (int i = 1; i < n; ++i) {
            g[parents[i]].push_back(i);
        }
        int ans = 0;
        long long mx = 0;
        function<int(int, int)> dfs = [&](int i, int fa) {
            long long score = 1;
            int cnt = 1;
            for (int j : g[i]) {
                if (j != fa) {
                    int t = dfs(j, i);
                    cnt += t;
                    score *= t;
                }
            }
            if (n - cnt) {
                score *= n - cnt;
            }
            if (mx < score) {
                mx = score;
                ans = 1;
            } else if (mx == score) {
                ++ans;
            }
            return cnt;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countHighestScoreNodes(parents []int) (ans int) {
	n := len(parents)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		g[parents[i]] = append(g[parents[i]], i)
	}
	mx := 0
	var dfs func(i, fa int) int
	dfs = func(i, fa int) int {
		cnt, score := 1, 1
		for _, j := range g[i] {
			if j != fa {
				t := dfs(j, i)
				cnt += t
				score *= t
			}
		}
		if n-cnt > 0 {
			score *= n - cnt
		}
		if mx < score {
			mx = score
			ans = 1
		} else if mx == score {
			ans++
		}
		return cnt
	}
	dfs(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countHighestScoreNodes(parents: number[]): number {
    const n = parents.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; i++) {
        g[parents[i]].push(i);
    }
    let [ans, mx] = [0, 0];
    const dfs = (i: number, fa: number): number => {
        let [cnt, score] = [1, 1];
        for (const j of g[i]) {
            if (j !== fa) {
                const t = dfs(j, i);
                cnt += t;
                score *= t;
            }
        }
        if (n - cnt) {
            score *= n - cnt;
        }
        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx === score) {
            ans++;
        }
        return cnt;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<int>[] g;
    private int ans;
    private long mx;
    private int n;

    public int CountHighestScoreNodes(int[] parents) {
        n = parents.Length;
        g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
        }
        for (int i = 1; i < n; ++i) {
            g[parents[i]].Add(i);
        }

        Dfs(0, -1);
        return ans;
    }

    private int Dfs(int i, int fa) {
        int cnt = 1;
        long score = 1;

        foreach (int j in g[i]) {
            if (j != fa) {
                int t = Dfs(j, i);
                cnt += t;
                score *= t;
            }
        }

        if (n - cnt > 0) {
            score *= n - cnt;
        }

        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx == score) {
            ++ans;
        }

        return cnt;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵根节点为 <code>0</code> 的&nbsp;<strong>二叉树</strong>&nbsp;，它总共有 <code>n</code>&nbsp;个节点，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。同时给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>parents</code>&nbsp;表示这棵树，其中&nbsp;<code>parents[i]</code>&nbsp;是节点 <code>i</code>&nbsp;的父节点。由于节点 <code>0</code>&nbsp;是根，所以&nbsp;<code>parents[0] == -1</code>&nbsp;。</p>

<p>一个子树的 <strong>大小</strong>&nbsp;为这个子树内节点的数目。每个节点都有一个与之关联的&nbsp;<strong>分数</strong>&nbsp;。求出某个节点分数的方法是，将这个节点和与它相连的边全部 <strong>删除</strong>&nbsp;，剩余部分是若干个 <strong>非空</strong>&nbsp;子树，这个节点的 <strong>分数</strong>&nbsp;为所有这些子树 <strong>大小的乘积</strong>&nbsp;。</p>

<p>请你返回有 <strong>最高得分</strong>&nbsp;节点的 <strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<p><img alt="example-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2049.Count%20Nodes%20With%20the%20Highest%20Score/images/example-1.png" style="width: 604px; height: 266px;"></p>

<pre><b>输入：</b>parents = [-1,2,0,2,0]
<b>输出：</b>3
<strong>解释：</strong>
- 节点 0 的分数为：3 * 1 = 3
- 节点 1 的分数为：4 = 4
- 节点 2 的分数为：1 * 1 * 2 = 2
- 节点 3 的分数为：4 = 4
- 节点 4 的分数为：4 = 4
最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="example-2" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2049.Count%20Nodes%20With%20the%20Highest%20Score/images/example-2.png" style="width: 95px; height: 143px;"></p>

<pre><b>输入：</b>parents = [-1,2,0]
<b>输出：</b>2
<strong>解释：</strong>
- 节点 0 的分数为：2 = 2
- 节点 1 的分数为：2 = 2
- 节点 2 的分数为：1 * 1 = 1
最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parents.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>parents[0] == -1</code></li>
	<li>对于&nbsp;<code>i != 0</code>&nbsp;，有&nbsp;<code>0 &lt;= parents[i] &lt;= n - 1</code></li>
	<li><code>parents</code>&nbsp;表示一棵二叉树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据给定的父节点数组 `parents` 构建图 $g$，其中 $g[i]$ 表示节点 $i$ 的所有子节点。定义变量 $ans$ 表示最高得分的节点数目，变量 $mx$ 表示最高得分。

然后，我们设计一个函数 $dfs(i, fa)$，它的作用是计算节点 $i$ 的分数，并返回以节点 $i$ 为根的子树的节点数目。

函数 $dfs(i, fa)$ 的计算过程如下：

我们首先初始化变量 $cnt = 1$，表示以节点 $i$ 为根的子树的节点数目；变量 $score = 1$，表示以节点 $i$ 初始分数。

接下来，我们遍历节点 $i$ 的所有子节点 $j$，如果 $j$ 不是节点 $i$ 的父节点 $fa$，那么我们递归调用 $dfs(j, i)$，并将返回值累乘到 $score$ 中，同时将返回值累加到 $cnt$ 中。

遍历完子节点后，如果 $n - cnt > 0$，那么我们将 $n - cnt$ 累乘到 $score$ 中。

然后，我们判断 $mx$ 是否小于 $score$，如果小于，那么我们将 $mx$ 更新为 $score$，并将 $ans$ 更新为 $1$；如果等于，那么我们将 $ans$ 更新为 $ans + 1$。

最后，我们返回 $cnt$。

最终，我们调用 $dfs(0, -1)$，并返回 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        def dfs(i: int, fa: int):
            cnt = score = 1
            for j in g[i]:
                if j != fa:
                    t = dfs(j, i)
                    score *= t
                    cnt += t
            if n - cnt:
                score *= n - cnt
            nonlocal ans, mx
            if mx < score:
                mx = score
                ans = 1
            elif mx == score:
                ans += 1
            return cnt

        n = len(parents)
        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parents[i]].append(i)
        ans = mx = 0
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private long mx;
    private int n;

    public int countHighestScoreNodes(int[] parents) {
        n = parents.length;
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            g[parents[i]].add(i);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int i, int fa) {
        int cnt = 1;
        long score = 1;
        for (int j : g[i]) {
            if (j != fa) {
                int t = dfs(j, i);
                cnt += t;
                score *= t;
            }
        }
        if (n - cnt > 0) {
            score *= n - cnt;
        }
        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx == score) {
            ++ans;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> g[n];
        for (int i = 1; i < n; ++i) {
            g[parents[i]].push_back(i);
        }
        int ans = 0;
        long long mx = 0;
        function<int(int, int)> dfs = [&](int i, int fa) {
            long long score = 1;
            int cnt = 1;
            for (int j : g[i]) {
                if (j != fa) {
                    int t = dfs(j, i);
                    cnt += t;
                    score *= t;
                }
            }
            if (n - cnt) {
                score *= n - cnt;
            }
            if (mx < score) {
                mx = score;
                ans = 1;
            } else if (mx == score) {
                ++ans;
            }
            return cnt;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func countHighestScoreNodes(parents []int) (ans int) {
	n := len(parents)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		g[parents[i]] = append(g[parents[i]], i)
	}
	mx := 0
	var dfs func(i, fa int) int
	dfs = func(i, fa int) int {
		cnt, score := 1, 1
		for _, j := range g[i] {
			if j != fa {
				t := dfs(j, i)
				cnt += t
				score *= t
			}
		}
		if n-cnt > 0 {
			score *= n - cnt
		}
		if mx < score {
			mx = score
			ans = 1
		} else if mx == score {
			ans++
		}
		return cnt
	}
	dfs(0, -1)
	return
}
```

#### TypeScript

```ts
function countHighestScoreNodes(parents: number[]): number {
    const n = parents.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; i++) {
        g[parents[i]].push(i);
    }
    let [ans, mx] = [0, 0];
    const dfs = (i: number, fa: number): number => {
        let [cnt, score] = [1, 1];
        for (const j of g[i]) {
            if (j !== fa) {
                const t = dfs(j, i);
                cnt += t;
                score *= t;
            }
        }
        if (n - cnt) {
            score *= n - cnt;
        }
        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx === score) {
            ans++;
        }
        return cnt;
    };
    dfs(0, -1);
    return ans;
}
```

#### C#

```cs
public class Solution {
    private List<int>[] g;
    private int ans;
    private long mx;
    private int n;

    public int CountHighestScoreNodes(int[] parents) {
        n = parents.Length;
        g = new List<int>[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new List<int>();
        }
        for (int i = 1; i < n; ++i) {
            g[parents[i]].Add(i);
        }

        Dfs(0, -1);
        return ans;
    }

    private int Dfs(int i, int fa) {
        int cnt = 1;
        long score = 1;

        foreach (int j in g[i]) {
            if (j != fa) {
                int t = Dfs(j, i);
                cnt += t;
                score *= t;
            }
        }

        if (n - cnt > 0) {
            score *= n - cnt;
        }

        if (mx < score) {
            mx = score;
            ans = 1;
        } else if (mx == score) {
            ++ans;
        }

        return cnt;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

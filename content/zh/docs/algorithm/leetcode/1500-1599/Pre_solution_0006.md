---
title: "1550_存在连续三个奇数的数组"
date: 2025-10-08T18:37:33+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 哈希函数, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 深度优先搜索, 滚动哈希, 矩阵, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [1550_存在连续三个奇数的数组](#1550)
#### [数组](#1550)
### [1551_使数组中所有元素相等的最小操作数](#1551)
#### [数学](#1551)
### [1552_两球之间的磁力](#1552)
#### [数组](#1552)
#### [二分查找](#1552)
#### [排序](#1552)
### [1553_吃掉 N 个橘子的最少天数](#1553)
#### [记忆化搜索](#1553)
#### [动态规划](#1553)
### [1554_只有一个不同字符的字符串 🔒](#1554)
#### [哈希表](#1554)
#### [字符串](#1554)
#### [哈希函数](#1554)
#### [滚动哈希](#1554)
### [1555_银行账户概要 🔒](#1555)
#### [数据库](#1555)
### [1556_千位分隔数](#1556)
#### [字符串](#1556)
### [1557_可以到达所有点的最少点数目](#1557)
#### [图](#1557)
### [1558_得到目标数组的最少函数调用次数](#1558)
#### [贪心](#1558)
#### [位运算](#1558)
#### [数组](#1558)
### [1559_二维网格图中探测环](#1559)
#### [深度优先搜索](#1559)
#### [广度优先搜索](#1559)
#### [并查集](#1559)
#### [数组](#1559)
#### [矩阵](#1559)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1550_存在连续三个奇数的数组
___
#### 数组
---
### 1551_使数组中所有元素相等的最小操作数
___
#### 数学
---
### 1552_两球之间的磁力
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 1553_吃掉 N 个橘子的最少天数
___
#### 记忆化搜索
___
#### 动态规划
---
### 1554_只有一个不同字符的字符串 🔒
___
#### 哈希表
___
#### 字符串
___
#### 哈希函数
___
#### 滚动哈希
---
### 1555_银行账户概要 🔒
___
#### 数据库
---
### 1556_千位分隔数
___
#### 字符串
---
### 1557_可以到达所有点的最少点数目
___
#### 图
---
### 1558_得到目标数组的最少函数调用次数
___
#### 贪心
___
#### 位运算
___
#### 数组
---
### 1559_二维网格图中探测环
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 哈希函数 | 哈希表 | 图 |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 深度优先搜索 | 滚动哈希 |
| 矩阵 | 记忆化搜索 | 贪心 |

# [1550. 存在连续三个奇数的数组](https://leetcode.cn/problems/three-consecutive-odds){#1550}

{{< tabs "1550" >}}

{{% tab "python" %}}
```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        return any(x & arr[i + 1] & arr[i + 2] & 1 for i, x in enumerate(arr[:-2]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        for (int i = 2, n = arr.length; i < n; ++i) {
            if ((arr[i - 2] & arr[i - 1] & arr[i] & 1) == 1) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2, n = arr.size(); i < n; ++i) {
            if (arr[i - 2] & arr[i - 1] & arr[i] & 1) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func threeConsecutiveOdds(arr []int) bool {
	for i, n := 2, len(arr); i < n; i++ {
		if arr[i-2]&arr[i-1]&arr[i]&1 == 1 {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function threeConsecutiveOdds(arr: number[]): boolean {
    const n = arr.length;
    for (let i = 2; i < n; ++i) {
        if (arr[i - 2] & arr[i - 1] & arr[i] & 1) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code>，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,6,4,1]
<strong>输出：</strong>false
<strong>解释：</strong>不存在连续三个元素都是奇数的情况。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,34,3,4,5,7,23,12]
<strong>输出：</strong>true
<strong>解释：</strong>存在连续三个元素都是奇数的情况，即 [5,7,23] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历 + 计数

我们用一个变量 $\textit{cnt}$ 记录当前连续奇数的个数。

接下来，我们遍历数组，如果当前元素是奇数，则 $\textit{cnt}$ 加一，如果 $\textit{cnt}$ 等于 3，则返回 $\textit{True}$。如果当前元素是偶数，则 $\textit{cnt}$ 置零。

遍历结束后，如果没有找到连续三个奇数，则返回 $\textit{False}$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        cnt = 0
        for x in arr:
            if x & 1:
                cnt += 1
                if cnt == 3:
                    return True
            else:
                cnt = 0
        return False
```

#### Java

```java
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int cnt = 0;
        for (int x : arr) {
            if (x % 2 == 1) {
                if (++cnt == 3) {
                    return true;
                }
            } else {
                cnt = 0;
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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int x : arr) {
            if (x & 1) {
                if (++cnt == 3) {
                    return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
```

#### Go

```go
func threeConsecutiveOdds(arr []int) bool {
	cnt := 0
	for _, x := range arr {
		if x&1 == 1 {
			cnt++
			if cnt == 3 {
				return true
			}
		} else {
			cnt = 0
		}
	}
	return false
}
```

#### TypeScript

```ts
function threeConsecutiveOdds(arr: number[]): boolean {
    let cnt = 0;
    for (const x of arr) {
        if (x & 1) {
            if (++cnt == 3) {
                return true;
            }
        } else {
            cnt = 0;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：遍历 + 位运算

根据位运算的性质，两个数进行按位与运算是奇数，当且仅当两个数都是奇数。如果有连续三个数按位与运算的结果是奇数，那么这三个数都是奇数。

因此，我们只需要遍历数组，判断是否存在连续三个数的按位与结果是否是奇数即可，如果存在则返回 $\textit{True}$，否则返回 $\textit{False}$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        return any(x & arr[i + 1] & arr[i + 2] & 1 for i, x in enumerate(arr[:-2]))
```

#### Java

```java
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        for (int i = 2, n = arr.length; i < n; ++i) {
            if ((arr[i - 2] & arr[i - 1] & arr[i] & 1) == 1) {
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
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2, n = arr.size(); i < n; ++i) {
            if (arr[i - 2] & arr[i - 1] & arr[i] & 1) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func threeConsecutiveOdds(arr []int) bool {
	for i, n := 2, len(arr); i < n; i++ {
		if arr[i-2]&arr[i-1]&arr[i]&1 == 1 {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function threeConsecutiveOdds(arr: number[]): boolean {
    const n = arr.length;
    for (let i = 2; i < n; ++i) {
        if (arr[i - 2] & arr[i - 1] & arr[i] & 1) {
            return true;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1551. 使数组中所有元素相等的最小操作数](https://leetcode.cn/problems/minimum-operations-to-make-array-equal){#1551}

{{< tabs "1551" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, n: int) -> int:
        return sum(n - (i << 1 | 1) for i in range(n >> 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            ans += n - (i << 1 | 1);
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
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            ans += n - (i << 1 | 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(n int) (ans int) {
	for i := 0; i < n>>1; i++ {
		ans += n - (i<<1 | 1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(n: number): number {
    let ans = 0;
    for (let i = 0; i < n >> 1; ++i) {
        ans += n - ((i << 1) | 1);
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

<p>存在一个长度为 <code>n</code> 的数组 <code>arr</code> ，其中 <code>arr[i] = (2 * i) + 1</code> （ <code>0 &lt;= i &lt; n</code> ）。</p>

<p>一次操作中，你可以选出两个下标，记作 <code>x</code> 和 <code>y</code> （ <code>0 &lt;= x, y &lt; n</code> ）并使 <code>arr[x]</code> 减去 <code>1</code> 、<code>arr[y]</code> 加上 <code>1</code> （即 <code>arr[x] -=1 </code>且 <code>arr[y] += 1</code> ）。最终的目标是使数组中的所有元素都 <strong>相等</strong> 。题目测试用例将会 <strong>保证</strong> ：在执行若干步操作后，数组中的所有元素最终可以全部相等。</p>

<p>给你一个整数 <code>n</code>，即数组的长度。请你返回使数组 <code>arr</code> 中所有元素相等所需的 <strong>最小操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>arr = [1, 3, 5]
第一次操作选出 x = 2 和 y = 0，使数组变为 [2, 3, 4]
第二次操作继续选出 x = 2 和 y = 0，数组将会变成 [3, 3, 3]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

根据题目描述，数组 $arr$ 是一个首项为 $1$，公差为 $2$ 的等差数列。那么数组前 $n$ 项的和为：

$$
\begin{aligned}
S_n &= \frac{n}{2} \times (a_1 + a_n) \\
&= \frac{n}{2} \times (1 + (2n - 1)) \\
&= n^2
\end{aligned}
$$

由于一次操作中，一个数减一，另一个数加一，数组中所有元素的和不变。因此，数组中所有元素相等时，每个元素的值为 $S_n / n = n$。那么，数组中所有元素相等所需的最小操作数为：

$$
\sum_{i=0}{\frac{n}{2}} (n - (2i + 1))
$$

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, n: int) -> int:
        return sum(n - (i << 1 | 1) for i in range(n >> 1))
```

#### Java

```java
class Solution {
    public int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            ans += n - (i << 1 | 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            ans += n - (i << 1 | 1);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(n int) (ans int) {
	for i := 0; i < n>>1; i++ {
		ans += n - (i<<1 | 1)
	}
	return
}
```

#### TypeScript

```ts
function minOperations(n: number): number {
    let ans = 0;
    for (let i = 0; i < n >> 1; ++i) {
        ans += n - ((i << 1) | 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1552. 两球之间的磁力](https://leetcode.cn/problems/magnetic-force-between-two-balls){#1552}

{{< tabs "1552" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def check(f: int) -> bool:
            prev = -inf
            cnt = 0
            for curr in position:
                if curr - prev >= f:
                    prev = curr
                    cnt += 1
            return cnt < m

        position.sort()
        l, r = 1, position[-1]
        return bisect_left(range(l, r + 1), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] position;

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        this.position = position;
        int l = 1, r = position[position.length - 1];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (count(mid) >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private int count(int f) {
        int prev = position[0];
        int cnt = 1;
        for (int curr : position) {
            if (curr - prev >= f) {
                ++cnt;
                prev = curr;
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
    int maxDistance(vector<int>& position, int m) {
        ranges::sort(position);
        int l = 1, r = position.back();
        auto count = [&](int f) {
            int prev = position[0];
            int cnt = 1;
            for (int& curr : position) {
                if (curr - prev >= f) {
                    prev = curr;
                    cnt++;
                }
            }
            return cnt;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (count(mid) >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistance(position []int, m int) int {
	sort.Ints(position)
	return sort.Search(position[len(position)-1], func(f int) bool {
		prev := position[0]
		cnt := 1
		for _, curr := range position {
			if curr-prev >= f {
				cnt++
				prev = curr
			}
		}
		return cnt < m
	}) - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDistance(position: number[], m: number): number {
    position.sort((a, b) => a - b);
    let [l, r] = [1, position.at(-1)!];
    const count = (f: number): number => {
        let cnt = 1;
        let prev = position[0];
        for (const curr of position) {
            if (curr - prev >= f) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (count(mid) >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function (position, m) {
    position.sort((a, b) => a - b);
    let [l, r] = [1, position.at(-1)];
    const count = f => {
        let cnt = 1;
        let prev = position[0];
        for (const curr of position) {
            if (curr - prev >= f) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (count(mid) >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有&nbsp;<code>n</code>&nbsp;个空的篮子，第&nbsp;<code>i</code>&nbsp;个篮子的位置在&nbsp;<code>position[i]</code>&nbsp;，Morty&nbsp;想把&nbsp;<code>m</code>&nbsp;个球放到这些篮子里，使得任意两球间&nbsp;<strong>最小磁力</strong>&nbsp;最大。</p>

<p>已知两个球如果分别位于&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;，那么它们之间的磁力为&nbsp;<code>|x - y|</code>&nbsp;。</p>

<p>给你一个整数数组&nbsp;<code>position</code>&nbsp;和一个整数&nbsp;<code>m</code>&nbsp;，请你返回最大化的最小磁力。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1552.Magnetic%20Force%20Between%20Two%20Balls/images/q3v1.jpg" style="height: 195px; width: 562px;"></p>

<pre><strong>输入：</strong>position = [1,2,3,4,7], m = 3
<strong>输出：</strong>3
<strong>解释：</strong>将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>position = [5,4,3,2,1,1000000000], m = 2
<strong>输出：</strong>999999999
<strong>解释：</strong>我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == position.length</code></li>
	<li><code>2 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= position[i] &lt;= 10^9</code></li>
	<li>所有&nbsp;<code>position</code>&nbsp;中的整数 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>2 &lt;= m &lt;= position.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，任意两球间的最小磁力越大，能够放入的球的数量就越少，这存在着单调性。我们可以使用二分查找，找到最大的最小磁力，使得能够放入的球的数量不小于 $m$。

我们首先对篮子的位置进行排序，然后使用二分查找的方法，定义二分查找的左边界 $l = 1$，右边界 $r = \textit{position}[n - 1]$，其中 $n$ 为篮子的数量。在每次二分查找的过程中，我们计算取中值 $m = (l + r + 1) / 2$，然后判断是否存在一种放置球的方法，使得能够放入的球的数量不小于 $m$。

问题转换为判断一个给定的最小磁力 $f$ 是否能够放入 $m$ 个球。我们可以从左到右遍历篮子的位置，如果上一个球的位置与当前篮子的位置的距离大于等于 $f$，则说明可以在当前篮子放置一个球。最后判断放置的球的数量是否不小于 $m$ 即可。

时间复杂度 $O(n \times \log n + n \times \log M)$，空间复杂度 $O(\log n)$。其中 $n$ 和 $M$ 分别为篮子的数量和篮子的位置的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def check(f: int) -> bool:
            prev = -inf
            cnt = 0
            for curr in position:
                if curr - prev >= f:
                    prev = curr
                    cnt += 1
            return cnt < m

        position.sort()
        l, r = 1, position[-1]
        return bisect_left(range(l, r + 1), True, key=check)
```

#### Java

```java
class Solution {
    private int[] position;

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        this.position = position;
        int l = 1, r = position[position.length - 1];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (count(mid) >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private int count(int f) {
        int prev = position[0];
        int cnt = 1;
        for (int curr : position) {
            if (curr - prev >= f) {
                ++cnt;
                prev = curr;
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
    int maxDistance(vector<int>& position, int m) {
        ranges::sort(position);
        int l = 1, r = position.back();
        auto count = [&](int f) {
            int prev = position[0];
            int cnt = 1;
            for (int& curr : position) {
                if (curr - prev >= f) {
                    prev = curr;
                    cnt++;
                }
            }
            return cnt;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (count(mid) >= m) {
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
func maxDistance(position []int, m int) int {
	sort.Ints(position)
	return sort.Search(position[len(position)-1], func(f int) bool {
		prev := position[0]
		cnt := 1
		for _, curr := range position {
			if curr-prev >= f {
				cnt++
				prev = curr
			}
		}
		return cnt < m
	}) - 1
}
```

#### TypeScript

```ts
function maxDistance(position: number[], m: number): number {
    position.sort((a, b) => a - b);
    let [l, r] = [1, position.at(-1)!];
    const count = (f: number): number => {
        let cnt = 1;
        let prev = position[0];
        for (const curr of position) {
            if (curr - prev >= f) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (count(mid) >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

#### JavaScript

```js
/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function (position, m) {
    position.sort((a, b) => a - b);
    let [l, r] = [1, position.at(-1)];
    const count = f => {
        let cnt = 1;
        let prev = position[0];
        for (const curr of position) {
            if (curr - prev >= f) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (count(mid) >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1553. 吃掉 N 个橘子的最少天数](https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges){#1553}

{{< tabs "1553" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDays(self, n: int) -> int:
        @cache
        def dfs(n: int) -> int:
            if n < 2:
                return n
            return 1 + min(n % 2 + dfs(n // 2), n % 3 + dfs(n // 3))

        return dfs(n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, Integer> f = new HashMap<>();

    public int minDays(int n) {
        return dfs(n);
    }

    private int dfs(int n) {
        if (n < 2) {
            return n;
        }
        if (f.containsKey(n)) {
            return f.get(n);
        }
        int res = 1 + Math.min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        f.put(n, res);
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    unordered_map<int, int> f;

    int minDays(int n) {
        return dfs(n);
    }

    int dfs(int n) {
        if (n < 2) {
            return n;
        }
        if (f.count(n)) {
            return f[n];
        }
        int res = 1 + min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        f[n] = res;
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDays(n int) int {
	f := map[int]int{0: 0, 1: 1}
	var dfs func(int) int
	dfs = func(n int) int {
		if v, ok := f[n]; ok {
			return v
		}
		res := 1 + min(n%2+dfs(n/2), n%3+dfs(n/3))
		f[n] = res
		return res
	}
	return dfs(n)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDays(n: number): number {
    const f: Record<number, number> = {};
    const dfs = (n: number): number => {
        if (n < 2) {
            return n;
        }
        if (f[n] !== undefined) {
            return f[n];
        }
        f[n] = 1 + Math.min((n % 2) + dfs((n / 2) | 0), (n % 3) + dfs((n / 3) | 0));
        return f[n];
    };
    return dfs(n);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>厨房里总共有 <code>n</code>&nbsp;个橘子，你决定每一天选择如下方式之一吃这些橘子：</p>

<ul>
	<li>吃掉一个橘子。</li>
	<li>如果剩余橘子数 <code>n</code>&nbsp;能被 2 整除，那么你可以吃掉 <code>n/2</code> 个橘子。</li>
	<li>如果剩余橘子数&nbsp;<code>n</code>&nbsp;能被 3 整除，那么你可以吃掉 <code>2*(n/3)</code> 个橘子。</li>
</ul>

<p>每天你只能从以上 3 种方案中选择一种方案。</p>

<p>请你返回吃掉所有 <code>n</code>&nbsp;个橘子的最少天数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 10
<strong>输出：</strong>4
<strong>解释：</strong>你总共有 10 个橘子。
第 1 天：吃 1 个橘子，剩余橘子数 10 - 1 = 9。
第 2 天：吃 6 个橘子，剩余橘子数 9 - 2*(9/3) = 9 - 6 = 3。（9 可以被 3 整除）
第 3 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。
第 4 天：吃掉最后 1 个橘子，剩余橘子数 1 - 1 = 0。
你需要至少 4 天吃掉 10 个橘子。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>3
<strong>解释：</strong>你总共有 6 个橘子。
第 1 天：吃 3 个橘子，剩余橘子数 6 - 6/2 = 6 - 3 = 3。（6 可以被 2 整除）
第 2 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。（3 可以被 3 整除）
第 3 天：吃掉剩余 1 个橘子，剩余橘子数 1 - 1 = 0。
你至少需要 3 天吃掉 6 个橘子。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 56
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2*10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

根据题目描述，对于每个 $n$，我们可以选择三种方式之一：

1. 将 $n$ 减少 $1$；
2. 如果 $n$ 能被 $2$ 整除，将 $n$ 的值除以 $2$；
3. 如果 $n$ 能被 $3$ 整除，将 $n$ 的值除以 $3$。

因此，问题等价于求解通过上述三种方式，将 $n$ 减少到 $0$ 的最少天数。

我们设计一个函数 $dfs(n)$，表示将 $n$ 减少到 $0$ 的最少天数。函数 $dfs(n)$ 的执行过程如下：

1. 如果 $n < 2$，返回 $n$；
2. 否则，我们可以先通过 $n \bmod 2$ 次操作 $1$，将 $n$ 减少到 $2$ 的倍数，然后执行操作 $2$，将 $n$ 减少到 $n/2$；我们也可以先通过 $n \bmod 3$ 次操作 $1$，将 $n$ 减少到 $3$ 的倍数，然后执行操作 $3$，将 $n$ 减少到 $n/3$。我们选择上述两种方式中最少的一种，即 $1 + \min(n \bmod 2 + dfs(n/2), n \bmod 3 + dfs(n/3))$。

为了避免重复计算，我们使用记忆化搜索的方法，将已经计算过的 $dfs(n)$ 的值存储在哈希表中。

时间复杂度 $O(\log^2 n)$，空间复杂度 $O(\log^2 n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDays(self, n: int) -> int:
        @cache
        def dfs(n: int) -> int:
            if n < 2:
                return n
            return 1 + min(n % 2 + dfs(n // 2), n % 3 + dfs(n // 3))

        return dfs(n)
```

#### Java

```java
class Solution {
    private Map<Integer, Integer> f = new HashMap<>();

    public int minDays(int n) {
        return dfs(n);
    }

    private int dfs(int n) {
        if (n < 2) {
            return n;
        }
        if (f.containsKey(n)) {
            return f.get(n);
        }
        int res = 1 + Math.min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        f.put(n, res);
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    unordered_map<int, int> f;

    int minDays(int n) {
        return dfs(n);
    }

    int dfs(int n) {
        if (n < 2) {
            return n;
        }
        if (f.count(n)) {
            return f[n];
        }
        int res = 1 + min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        f[n] = res;
        return res;
    }
};
```

#### Go

```go
func minDays(n int) int {
	f := map[int]int{0: 0, 1: 1}
	var dfs func(int) int
	dfs = func(n int) int {
		if v, ok := f[n]; ok {
			return v
		}
		res := 1 + min(n%2+dfs(n/2), n%3+dfs(n/3))
		f[n] = res
		return res
	}
	return dfs(n)
}
```

#### TypeScript

```ts
function minDays(n: number): number {
    const f: Record<number, number> = {};
    const dfs = (n: number): number => {
        if (n < 2) {
            return n;
        }
        if (f[n] !== undefined) {
            return f[n];
        }
        f[n] = 1 + Math.min((n % 2) + dfs((n / 2) | 0), (n % 3) + dfs((n / 3) | 0));
        return f[n];
    };
    return dfs(n);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1554. 只有一个不同字符的字符串 🔒](https://leetcode.cn/problems/strings-differ-by-one-character){#1554}

{{< tabs "1554" >}}

{{% tab "python" %}}
```python
class Solution:
    def differByOne(self, dict: List[str]) -> bool:
        s = set()
        for word in dict:
            for i in range(len(word)):
                t = word[:i] + "*" + word[i + 1 :]
                if t in s:
                    return True
                s.add(t)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean differByOne(String[] dict) {
        Set<String> s = new HashSet<>();
        for (String word : dict) {
            for (int i = 0; i < word.length(); ++i) {
                String t = word.substring(0, i) + "*" + word.substring(i + 1);
                if (s.contains(t)) {
                    return true;
                }
                s.add(t);
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> s;
        for (auto word : dict) {
            for (int i = 0; i < word.size(); ++i) {
                auto t = word;
                t[i] = '*';
                if (s.count(t)) return true;
                s.insert(t);
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func differByOne(dict []string) bool {
	s := make(map[string]bool)
	for _, word := range dict {
		for i := range word {
			t := word[:i] + "*" + word[i+1:]
			if s[t] {
				return true
			}
			s[t] = true
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串列表&nbsp;<code>dict</code> ，其中所有字符串的长度都相同。</p>

<p>当存在两个字符串在相同索引处只有一个字符不同时，返回 <code>True</code> ，否则返回 <code>False</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dict = ["abcd","acbd", "aacd"]
<strong>输出：</strong>true
<strong>解释：</strong>字符串 "a<strong>b</strong>cd" 和 "a<strong>a</strong>cd" 只在索引 1 处有一个不同的字符。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dict = ["ab","cd","yz"]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>dict = ["abcd","cccc","abyd","abab"]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>dict</code>&nbsp;中的字符数小于或等于&nbsp;<code>10^5</code>&nbsp;。</li>
	<li><code>dict[i].length == dict[j].length</code></li>
	<li><code>dict[i]</code>&nbsp;是互不相同的。</li>
	<li><code>dict[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以以 <code>O(n*m)</code> 的复杂度解决问题吗？其中 n 是列表 <code>dict</code> 的长度，<code>m</code> 是字符串的长度。</p>

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
    def differByOne(self, dict: List[str]) -> bool:
        s = set()
        for word in dict:
            for i in range(len(word)):
                t = word[:i] + "*" + word[i + 1 :]
                if t in s:
                    return True
                s.add(t)
        return False
```

#### Java

```java
class Solution {
    public boolean differByOne(String[] dict) {
        Set<String> s = new HashSet<>();
        for (String word : dict) {
            for (int i = 0; i < word.length(); ++i) {
                String t = word.substring(0, i) + "*" + word.substring(i + 1);
                if (s.contains(t)) {
                    return true;
                }
                s.add(t);
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
    bool differByOne(vector<string>& dict) {
        unordered_set<string> s;
        for (auto word : dict) {
            for (int i = 0; i < word.size(); ++i) {
                auto t = word;
                t[i] = '*';
                if (s.count(t)) return true;
                s.insert(t);
            }
        }
        return false;
    }
};
```

#### Go

```go
func differByOne(dict []string) bool {
	s := make(map[string]bool)
	for _, word := range dict {
		for i := range word {
			t := word[:i] + "*" + word[i+1:]
			if s[t] {
				return true
			}
			s[t] = true
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1555. 银行账户概要 🔒](https://leetcode.cn/problems/bank-account-summary){#1555}

{{< tabs "1555" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    t.user_id,
    user_name,
    SUM(t.credit) AS credit,
    IF(SUM(t.credit) < 0, 'Yes', 'No') AS credit_limit_breached
FROM
    (
        SELECT paid_by AS user_id, -amount AS credit FROM Transactions
        UNION ALL
        SELECT paid_to AS user_id, amount AS credit FROM Transactions
        UNION ALL
        SELECT user_id, credit FROM Users
    ) AS t
    JOIN Users AS u ON t.user_id = u.user_id
GROUP BY t.user_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>用户表：&nbsp;<code>Users</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| user_id      | int     |
| user_name    | varchar |
| credit       | int     |
+--------------+---------+
user_id 是这个表的主键（具有唯一值的列）。
表中的每一列包含每一个用户当前的额度信息。</pre>

<p>&nbsp;</p>

<p>交易表：<code>Transactions</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| trans_id      | int     |
| paid_by       | int     |
| paid_to       | int     |
| amount        | int     |
| transacted_on | date    |
+---------------+---------+
trans_id 是这个表的主键（具有唯一值的列）。
表中的每一列包含银行的交易信息。
ID 为 paid_by 的用户给 ID 为 paid_to 的用户转账。
</pre>

<p>&nbsp;</p>

<p>力扣银行 (LCB) 帮助程序员们完成虚拟支付。我们的银行在表&nbsp;<em>Transaction</em>&nbsp;中记录每条交易信息，我们要查询每个用户的当前余额，并检查他们是否已透支（当前额度小于 0）。</p>

<p>编写解决方案报告：</p>

<ul>
	<li><code>user_id</code>&nbsp;用户 ID</li>
	<li><code>user_name</code>&nbsp;用户名</li>
	<li><code>credit</code>&nbsp;完成交易后的余额</li>
	<li><code>credit_limit_breached</code>&nbsp;检查是否透支 （"Yes" 或&nbsp;"No"）</li>
</ul>

<p>以<strong>任意</strong>顺序返回结果表。</p>

<p>结果格式见如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Users</code> 表：
+------------+--------------+-------------+
| user_id    | user_name    | credit      |
+------------+--------------+-------------+
| 1          | Moustafa     | 100         |
| 2          | Jonathan     | 200         |
| 3          | Winston      | 10000       |
| 4          | Luis         | 800         | 
+------------+--------------+-------------+

<code>Transactions</code> 表：
+------------+------------+------------+----------+---------------+
| trans_id   | paid_by    | paid_to    | amount   | transacted_on |
+------------+------------+------------+----------+---------------+
| 1          | 1          | 3          | 400      | 2020-08-01    |
| 2          | 3          | 2          | 500      | 2020-08-02    |
| 3          | 2          | 1          | 200      | 2020-08-03    |
+------------+------------+------------+----------+---------------+

<strong>输出：</strong>
+------------+------------+------------+-----------------------+
| <code>user_id </code>   | <code>user_name</code>  | <code>credit </code>    | <code>credit_limit_breached</code> |
+------------+------------+------------+-----------------------+
| 1          | Moustafa   | -100       | Yes                   | 
| 2          | Jonathan   | 500        | No                    |
| 3          | Winston    | 9900       | No                    |
| 4          | Luis       | 800        | No                    |
+------------+------------+------------+-----------------------+
Moustafa 在 "2020-08-01" 支付了 $400 并在 "2020-08-03" 收到了 $200 ，当前额度 (100 -400 +200) = -$100
Jonathan 在 "2020-08-02" 收到了 $500 并在 "2020-08-08" 支付了 $200 ，当前额度 (200 +500 -200) = $500
Winston 在 "2020-08-01" 收到了 $400 并在 "2020-08-03" 支付了 $500 ，当前额度 (10000 +400 -500) = $9900
Luis 未收到任何转账信息，额度 = $800</pre>

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
SELECT
    t.user_id,
    user_name,
    SUM(t.credit) AS credit,
    IF(SUM(t.credit) < 0, 'Yes', 'No') AS credit_limit_breached
FROM
    (
        SELECT paid_by AS user_id, -amount AS credit FROM Transactions
        UNION ALL
        SELECT paid_to AS user_id, amount AS credit FROM Transactions
        UNION ALL
        SELECT user_id, credit FROM Users
    ) AS t
    JOIN Users AS u ON t.user_id = u.user_id
GROUP BY t.user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1556. 千位分隔数](https://leetcode.cn/problems/thousand-separator){#1556}

{{< tabs "1556" >}}

{{% tab "python" %}}
```python
class Solution:
    def thousandSeparator(self, n: int) -> str:
        cnt = 0
        ans = []
        while 1:
            n, v = divmod(n, 10)
            ans.append(str(v))
            cnt += 1
            if n == 0:
                break
            if cnt == 3:
                ans.append('.')
                cnt = 0
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String thousandSeparator(int n) {
        int cnt = 0;
        StringBuilder ans = new StringBuilder();
        while (true) {
            int v = n % 10;
            n /= 10;
            ans.append(v);
            ++cnt;
            if (n == 0) {
                break;
            }
            if (cnt == 3) {
                ans.append('.');
                cnt = 0;
            }
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
    string thousandSeparator(int n) {
        int cnt = 0;
        string ans;
        while (1) {
            int v = n % 10;
            n /= 10;
            ans += to_string(v);
            if (n == 0) break;
            if (++cnt == 3) {
                ans += '.';
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func thousandSeparator(n int) string {
	cnt := 0
	ans := []byte{}
	for {
		v := n % 10
		n /= 10
		ans = append(ans, byte('0'+v))
		if n == 0 {
			break
		}
		cnt++
		if cnt == 3 {
			ans = append(ans, '.')
			cnt = 0
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>，请你每隔三位添加点（即 &quot;.&quot; 符号）作为千位分隔符，并将结果以字符串格式返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 987
<strong>输出：</strong>&quot;987&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1234
<strong>输出：</strong>&quot;1.234&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 123456789
<strong>输出：</strong>&quot;123.456.789&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 0
<strong>输出：</strong>&quot;0&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt; 2^31</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接按照题目要求模拟即可。

时间复杂度 $O(\log n)$，忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def thousandSeparator(self, n: int) -> str:
        cnt = 0
        ans = []
        while 1:
            n, v = divmod(n, 10)
            ans.append(str(v))
            cnt += 1
            if n == 0:
                break
            if cnt == 3:
                ans.append('.')
                cnt = 0
        return ''.join(ans[::-1])
```

#### Java

```java
class Solution {
    public String thousandSeparator(int n) {
        int cnt = 0;
        StringBuilder ans = new StringBuilder();
        while (true) {
            int v = n % 10;
            n /= 10;
            ans.append(v);
            ++cnt;
            if (n == 0) {
                break;
            }
            if (cnt == 3) {
                ans.append('.');
                cnt = 0;
            }
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string thousandSeparator(int n) {
        int cnt = 0;
        string ans;
        while (1) {
            int v = n % 10;
            n /= 10;
            ans += to_string(v);
            if (n == 0) break;
            if (++cnt == 3) {
                ans += '.';
                cnt = 0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func thousandSeparator(n int) string {
	cnt := 0
	ans := []byte{}
	for {
		v := n % 10
		n /= 10
		ans = append(ans, byte('0'+v))
		if n == 0 {
			break
		}
		cnt++
		if cnt == 3 {
			ans = append(ans, '.')
			cnt = 0
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1557. 可以到达所有点的最少点数目](https://leetcode.cn/problems/minimum-number-of-vertices-to-reach-all-nodes){#1557}

{{< tabs "1557" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        cnt = Counter(t for _, t in edges)
        return [i for i in range(n) if cnt[i] == 0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        var cnt = new int[n];
        for (var e : edges) {
            ++cnt[e.get(1)];
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                ans.add(i);
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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n);
        for (auto& e : edges) {
            ++cnt[e[1]];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSmallestSetOfVertices(n int, edges [][]int) (ans []int) {
	cnt := make([]int, n)
	for _, e := range edges {
		cnt[e[1]]++
	}
	for i, c := range cnt {
		if c == 0 {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSmallestSetOfVertices(n: number, edges: number[][]): number[] {
    const cnt: number[] = new Array(n).fill(0);
    for (const [_, t] of edges) {
        cnt[t]++;
    }
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (cnt[i] === 0) {
            ans.push(i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_smallest_set_of_vertices(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut arr = vec![true; n as usize];
        edges.iter().for_each(|edge| {
            arr[edge[1] as usize] = false;
        });
        arr.iter()
            .enumerate()
            .filter_map(|(i, &v)| if v { Some(i as i32) } else { None })
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>有向无环图</strong>&nbsp;， <code>n</code>&nbsp;个节点编号为 <code>0</code>&nbsp;到 <code>n-1</code>&nbsp;，以及一个边数组 <code>edges</code>&nbsp;，其中 <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示一条从点&nbsp;&nbsp;<code>from<sub>i</sub></code>&nbsp;到点&nbsp;<code>to<sub>i</sub></code>&nbsp;的有向边。</p>

<p>找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。</p>

<p>你可以以任意顺序返回这些节点编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1557.Minimum%20Number%20of%20Vertices%20to%20Reach%20All%20Nodes/images/5480e1.png" style="height: 181px; width: 231px;"></p>

<pre><strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
<strong>输出：</strong>[0,3]
<strong>解释：</strong>从单个节点出发无法到达所有节点。从 0 出发我们可以到达 [0,1,2,5] 。从 3 出发我们可以到达 [3,4,2,5] 。所以我们输出 [0,3] 。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1557.Minimum%20Number%20of%20Vertices%20to%20Reach%20All%20Nodes/images/5480e2.png" style="height: 201px; width: 201px;"></p>

<pre><strong>输入：</strong>n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
<strong>输出：</strong>[0,2,3]
<strong>解释：</strong>注意到节点 0，3 和 2 无法从其他节点到达，所以我们必须将它们包含在结果点集中，这些点都能到达节点 1 和 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10^5, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i,</sub>&nbsp;to<sub>i</sub> &lt; n</code></li>
	<li>所有点对&nbsp;<code>(from<sub>i</sub>, to<sub>i</sub>)</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计入度为 0 的点

我们注意到，所有入度为 $0$ 的点都一定属于最小点集，因为它们没有任何入边。而由于题目给定的是一张有向无环图，因此所有入度不为 $0$ 的点一定存在一条入边，也即一定能从某个入度为 $0$ 的点出发到达。因此我们只需要找到所有入度为 $0$ 的点即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        cnt = Counter(t for _, t in edges)
        return [i for i in range(n) if cnt[i] == 0]
```

#### Java

```java
class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        var cnt = new int[n];
        for (var e : edges) {
            ++cnt[e.get(1)];
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                ans.add(i);
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
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n);
        for (auto& e : edges) {
            ++cnt[e[1]];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findSmallestSetOfVertices(n int, edges [][]int) (ans []int) {
	cnt := make([]int, n)
	for _, e := range edges {
		cnt[e[1]]++
	}
	for i, c := range cnt {
		if c == 0 {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findSmallestSetOfVertices(n: number, edges: number[][]): number[] {
    const cnt: number[] = new Array(n).fill(0);
    for (const [_, t] of edges) {
        cnt[t]++;
    }
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (cnt[i] === 0) {
            ans.push(i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_smallest_set_of_vertices(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut arr = vec![true; n as usize];
        edges.iter().for_each(|edge| {
            arr[edge[1] as usize] = false;
        });
        arr.iter()
            .enumerate()
            .filter_map(|(i, &v)| if v { Some(i as i32) } else { None })
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1558. 得到目标数组的最少函数调用次数](https://leetcode.cn/problems/minimum-numbers-of-function-calls-to-make-target-array){#1558}

{{< tabs "1558" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return sum(v.bit_count() for v in nums) + max(0, max(nums).bit_length() - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int mx = 0;
        for (int v : nums) {
            mx = Math.max(mx, v);
            ans += Integer.bitCount(v);
        }
        ans += Integer.toBinaryString(mx).length() - 1;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int mx = 0;
        for (int v : nums) {
            mx = max(mx, v);
            ans += __builtin_popcount(v);
        }
        if (mx) ans += 31 - __builtin_clz(mx);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) int {
	ans, mx := 0, 0
	for _, v := range nums {
		mx = max(mx, v)
		for v > 0 {
			ans += v & 1
			v >>= 1
		}
	}
	if mx > 0 {
		for mx > 0 {
			ans++
			mx >>= 1
		}
		ans--
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1558.Minimum%20Numbers%20of%20Function%20Calls%20to%20Make%20Target%20Array/images/sample_2_1887.png" style="height:294px; width:573px" /></p>

<p>给你一个与 <code>nums</code>&nbsp;大小相同且初始值全为 0 的数组 <code>arr</code> ，请你调用以上函数得到整数数组 <code>nums</code>&nbsp;。</p>

<p>请你返回将 <code>arr</code>&nbsp;变成 <code>nums</code>&nbsp;的最少函数调用次数。</p>

<p>答案保证在 32 位有符号整数以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5]
<strong>输出：</strong>5
<strong>解释：</strong>给第二个数加 1 ：[0, 0] 变成 [0, 1] （1 次操作）。
将所有数字乘以 2 ：[0, 1] -&gt; [0, 2] -&gt; [0, 4] （2 次操作）。
给两个数字都加 1 ：[0, 4] -&gt; [1, 4] -&gt; <strong>[1, 5]</strong> （2 次操作）。
总操作次数为：1 + 2 + 2 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2]
<strong>输出：</strong>3
<strong>解释：</strong>给两个数字都加 1 ：[0, 0] -&gt; [0, 1] -&gt; [1, 1] （2 次操作）。
将所有数字乘以 2 ： [1, 1] -&gt; <strong>[2, 2]</strong> （1 次操作）。
总操作次数为： 2 + 1 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,5]
<strong>输出：</strong>6
<strong>解释：</strong>（初始）[0,0,0] -&gt; [1,0,0] -&gt; [1,0,1] -&gt; [2,0,2] -&gt; [2,1,2] -&gt; [4,2,4] -&gt; <strong>[4,2,5] </strong>（nums 数组）。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,2,4]
<strong>输出：</strong>7
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,8,16]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10^9</code></li>
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
    def minOperations(self, nums: List[int]) -> int:
        return sum(v.bit_count() for v in nums) + max(0, max(nums).bit_length() - 1)
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int mx = 0;
        for (int v : nums) {
            mx = Math.max(mx, v);
            ans += Integer.bitCount(v);
        }
        ans += Integer.toBinaryString(mx).length() - 1;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int mx = 0;
        for (int v : nums) {
            mx = max(mx, v);
            ans += __builtin_popcount(v);
        }
        if (mx) ans += 31 - __builtin_clz(mx);
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) int {
	ans, mx := 0, 0
	for _, v := range nums {
		mx = max(mx, v)
		for v > 0 {
			ans += v & 1
			v >>= 1
		}
	}
	if mx > 0 {
		for mx > 0 {
			ans++
			mx >>= 1
		}
		ans--
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1559. 二维网格图中探测环](https://leetcode.cn/problems/detect-cycles-in-2d-grid){#1559}

{{< tabs "1559" >}}

{{% tab "python" %}}
```python
class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def dfs(x: int, y: int, px: int, py: int) -> bool:
            vis[x][y] = True
            for dx, dy in pairwise(dirs):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    if grid[nx][ny] != grid[x][y] or (nx == px and ny == py):
                        continue
                    if vis[nx][ny] or dfs(nx, ny, x, y):
                        return True
            return False

        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        dirs = (-1, 0, 1, 0, -1)
        for i in range(m):
            for j in range(n):
                if vis[i][j]:
                    continue
                if dfs(i, j, -1, -1):
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[][] grid;
    private boolean[][] vis;
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int m;
    private int n;

    public boolean containsCycle(char[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        vis = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int x, int y, int px, int py) {
        vis[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dirs[k], ny = y + dirs[k + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                    continue;
                }
                if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        const vector<int> dirs = {-1, 0, 1, 0, -1};
        auto dfs = [&](this auto&& dfs, int x, int y, int px, int py) -> bool {
            vis[x][y] = true;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                        continue;
                    }
                    if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                        return true;
                    }
                }
            }
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func containsCycle(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := []int{-1, 0, 1, 0, -1}
	var dfs func(x, y, px, py int) bool
	dfs = func(x, y, px, py int) bool {
		vis[x][y] = true
		for k := 0; k < 4; k++ {
			nx, ny := x+dirs[k], y+dirs[k+1]
			if nx >= 0 && nx < m && ny >= 0 && ny < n {
				if grid[nx][ny] != grid[x][y] || (nx == px && ny == py) {
					continue
				}
				if vis[nx][ny] || dfs(nx, ny, x, y) {
					return true
				}
			}
		}
		return false
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if !vis[i][j] && dfs(i, j, -1, -1) {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function containsCycle(grid: string[][]): boolean {
    const [m, n] = [grid.length, grid[0].length];
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    const dfs = (x: number, y: number, px: number, py: number): boolean => {
        vis[x][y] = true;
        const dirs = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; k++) {
            const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] !== grid[x][y] || (nx === px && ny === py)) {
                    continue;
                }
                if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                    return true;
                }
            }
        }
        return false;
    };
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!vis[i][j] && dfs(i, j, -1, -1)) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut vis = vec![vec![false; n]; m];
        let dirs = vec![-1, 0, 1, 0, -1];

        fn dfs(
            x: usize,
            y: usize,
            px: isize,
            py: isize,
            grid: &Vec<Vec<char>>,
            vis: &mut Vec<Vec<bool>>,
            dirs: &Vec<isize>,
        ) -> bool {
            vis[x][y] = true;
            for k in 0..4 {
                let nx = (x as isize + dirs[k]) as usize;
                let ny = (y as isize + dirs[k + 1]) as usize;
                if nx < grid.len() && ny < grid[0].len() {
                    if grid[nx][ny] != grid[x][y] || (nx as isize == px && ny as isize == py) {
                        continue;
                    }
                    if vis[nx][ny] || dfs(nx, ny, x as isize, y as isize, grid, vis, dirs) {
                        return true;
                    }
                }
            }
            false
        }

        for i in 0..m {
            for j in 0..n {
                if !vis[i][j] && dfs(i, j, -1, -1, &grid, &mut vis, &dirs) {
                    return true;
                }
            }
        }
        false
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function (grid) {
    const [m, n] = [grid.length, grid[0].length];
    const vis = Array.from({ length: m }, () => Array(n).fill(false));
    const dirs = [-1, 0, 1, 0, -1];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!vis[i][j]) {
                const q = [[i, j, -1, -1]];
                vis[i][j] = true;
                for (const [x, y, px, py] of q) {
                    for (let k = 0; k < 4; k++) {
                        const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            if (grid[nx][ny] !== grid[x][y] || (nx === px && ny === py)) {
                                continue;
                            }
                            if (vis[nx][ny]) {
                                return true;
                            }
                            q.push([nx, ny, x, y]);
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return false;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维字符网格数组&nbsp;<code>grid</code>&nbsp;，大小为&nbsp;<code>m x n</code>&nbsp;，你需要检查&nbsp;<code>grid</code>&nbsp;中是否存在 <strong>相同值</strong> 形成的环。</p>

<p>一个环是一条开始和结束于同一个格子的长度 <strong>大于等于 4</strong>&nbsp;的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 <strong>相同的值&nbsp;</strong>。</p>

<p>同时，你也不能回到上一次移动时所在的格子。比方说，环&nbsp;&nbsp;<code>(1, 1) -&gt; (1, 2) -&gt; (1, 1)</code>&nbsp;是不合法的，因为从 <code>(1, 2)</code>&nbsp;移动到 <code>(1, 1)</code> 回到了上一次移动时的格子。</p>

<p>如果 <code>grid</code>&nbsp;中有相同值形成的环，请你返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1559.Detect%20Cycles%20in%202D%20Grid/images/5482e1.png" style="height: 152px; width: 231px;"></strong></p>

<pre><strong>输入：</strong>grid = [[&quot;a&quot;,&quot;a&quot;,&quot;a&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;a&quot;],[&quot;a&quot;,&quot;a&quot;,&quot;a&quot;,&quot;a&quot;]]
<strong>输出：</strong>true
<strong>解释：</strong>如下图所示，有 2 个用不同颜色标出来的环：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1559.Detect%20Cycles%20in%202D%20Grid/images/5482e11.png" style="height: 163px; width: 225px;">
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1559.Detect%20Cycles%20in%202D%20Grid/images/5482e2.png" style="height: 154px; width: 236px;"></strong></p>

<pre><strong>输入：</strong>grid = [[&quot;c&quot;,&quot;c&quot;,&quot;c&quot;,&quot;a&quot;],[&quot;c&quot;,&quot;d&quot;,&quot;c&quot;,&quot;c&quot;],[&quot;c&quot;,&quot;c&quot;,&quot;e&quot;,&quot;c&quot;],[&quot;f&quot;,&quot;c&quot;,&quot;c&quot;,&quot;c&quot;]]
<strong>输出：</strong>true
<strong>解释：</strong>如下图所示，只有高亮所示的一个合法环：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1559.Detect%20Cycles%20in%202D%20Grid/images/5482e22.png" style="height: 157px; width: 229px;">
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1559.Detect%20Cycles%20in%202D%20Grid/images/5482e3.png" style="height: 120px; width: 183px;"></strong></p>

<pre><strong>输入：</strong>grid = [[&quot;a&quot;,&quot;b&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;z&quot;,&quot;b&quot;],[&quot;b&quot;,&quot;b&quot;,&quot;a&quot;]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>grid</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以遍历二维网格中的每一个格子，对于每一个格子，如果格子 $grid[i][j]$ 未被访问过，我们就从该格子开始进行广度优先搜索，搜索过程中，我们需要记录每一个格子的父节点，以及上一个格子的坐标，如果下一个格子的值与当前格子的值相同，且不是上一个格子，并且已经被访问过，那么就说明存在环，返回 $\textit{true}$。遍历完所有格子后，如果没有找到环，返回 $\textit{false}$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        dirs = (-1, 0, 1, 0, -1)
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if vis[i][j]:
                    continue
                vis[i][j] = True
                q = [(i, j, -1, -1)]
                while q:
                    x, y, px, py = q.pop()
                    for dx, dy in pairwise(dirs):
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < m and 0 <= ny < n:
                            if grid[nx][ny] != grid[i][j] or (nx == px and ny == py):
                                continue
                            if vis[nx][ny]:
                                return True
                            vis[nx][ny] = True
                            q.append((nx, ny, x, y))
        return False
```

#### Java

```java
class Solution {
    public boolean containsCycle(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    Deque<int[]> q = new ArrayDeque<>();
                    q.offer(new int[] {i, j, -1, -1});
                    vis[i][j] = true;
                    while (!q.isEmpty()) {
                        int[] p = q.poll();
                        int x = p[0], y = p[1], px = p[2], py = p[3];
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dirs[k], ny = y + dirs[k + 1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                                    continue;
                                }
                                if (vis[nx][ny]) {
                                    return true;
                                }
                                q.offer(new int[] {nx, ny, x, y});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        const vector<int> dirs = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    queue<array<int, 4>> q;
                    q.push({i, j, -1, -1});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int x = p[0], y = p[1], px = p[2], py = p[3];

                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dirs[k], ny = y + dirs[k + 1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                                    continue;
                                }
                                if (vis[nx][ny]) {
                                    return true;
                                }
                                q.push({nx, ny, x, y});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func containsCycle(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := []int{-1, 0, 1, 0, -1}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if !vis[i][j] {
				q := [][]int{{i, j, -1, -1}}
				vis[i][j] = true

				for len(q) > 0 {
					p := q[0]
					q = q[1:]
					x, y, px, py := p[0], p[1], p[2], p[3]

					for k := 0; k < 4; k++ {
						nx, ny := x+dirs[k], y+dirs[k+1]
						if nx >= 0 && nx < m && ny >= 0 && ny < n {
							if grid[nx][ny] != grid[x][y] || (nx == px && ny == py) {
								continue
							}
							if vis[nx][ny] {
								return true
							}
							q = append(q, []int{nx, ny, x, y})
							vis[nx][ny] = true
						}
					}
				}
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function containsCycle(grid: string[][]): boolean {
    const [m, n] = [grid.length, grid[0].length];
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    const dirs = [-1, 0, 1, 0, -1];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!vis[i][j]) {
                const q: [number, number, number, number][] = [[i, j, -1, -1]];
                vis[i][j] = true;
                for (const [x, y, px, py] of q) {
                    for (let k = 0; k < 4; k++) {
                        const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            if (grid[nx][ny] !== grid[x][y] || (nx === px && ny === py)) {
                                continue;
                            }
                            if (vis[nx][ny]) {
                                return true;
                            }
                            q.push([nx, ny, x, y]);
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut vis = vec![vec![false; n]; m];
        let dirs = vec![-1, 0, 1, 0, -1];

        for i in 0..m {
            for j in 0..n {
                if !vis[i][j] {
                    let mut q = vec![(i as isize, j as isize, -1, -1)];
                    vis[i][j] = true;

                    while !q.is_empty() {
                        let (x, y, px, py) = q.pop().unwrap();

                        for k in 0..4 {
                            let nx = x + dirs[k];
                            let ny = y + dirs[k + 1];
                            if nx >= 0 && nx < m as isize && ny >= 0 && ny < n as isize {
                                let nx = nx as usize;
                                let ny = ny as usize;
                                if grid[nx][ny] != grid[x as usize][y as usize]
                                    || (nx == px as usize && ny == py as usize)
                                {
                                    continue;
                                }
                                if vis[nx][ny] {
                                    return true;
                                }
                                q.push((nx as isize, ny as isize, x, y));
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        false
    }
}
```

#### JavaScript

```js
/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function (grid) {
    const [m, n] = [grid.length, grid[0].length];
    const vis = Array.from({ length: m }, () => Array(n).fill(false));
    const dirs = [-1, 0, 1, 0, -1];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!vis[i][j]) {
                const q = [[i, j, -1, -1]];
                vis[i][j] = true;
                for (const [x, y, px, py] of q) {
                    for (let k = 0; k < 4; k++) {
                        const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                            if (grid[nx][ny] !== grid[x][y] || (nx === px && ny === py)) {
                                continue;
                            }
                            if (vis[nx][ny]) {
                                return true;
                            }
                            q.push([nx, ny, x, y]);
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return false;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们可以遍历二维网格中的每一个格子，对于每一个格子，如果格子 $grid[i][j]$ 未被访问过，我们就从该格子开始进行深度优先搜索，搜索过程中，我们需要记录每一个格子的父节点，以及上一个格子的坐标，如果下一个格子的值与当前格子的值相同，且不是上一个格子，并且已经被访问过，那么就说明存在环，返回 $\textit{true}$。遍历完所有格子后，如果没有找到环，返回 $\textit{false}$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def dfs(x: int, y: int, px: int, py: int) -> bool:
            vis[x][y] = True
            for dx, dy in pairwise(dirs):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    if grid[nx][ny] != grid[x][y] or (nx == px and ny == py):
                        continue
                    if vis[nx][ny] or dfs(nx, ny, x, y):
                        return True
            return False

        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        dirs = (-1, 0, 1, 0, -1)
        for i in range(m):
            for j in range(n):
                if vis[i][j]:
                    continue
                if dfs(i, j, -1, -1):
                    return True
        return False
```

#### Java

```java
class Solution {
    private char[][] grid;
    private boolean[][] vis;
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int m;
    private int n;

    public boolean containsCycle(char[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        vis = new boolean[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(int x, int y, int px, int py) {
        vis[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dirs[k], ny = y + dirs[k + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                    continue;
                }
                if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                    return true;
                }
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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        const vector<int> dirs = {-1, 0, 1, 0, -1};
        auto dfs = [&](this auto&& dfs, int x, int y, int px, int py) -> bool {
            vis[x][y] = true;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                        continue;
                    }
                    if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                        return true;
                    }
                }
            }
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func containsCycle(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := []int{-1, 0, 1, 0, -1}
	var dfs func(x, y, px, py int) bool
	dfs = func(x, y, px, py int) bool {
		vis[x][y] = true
		for k := 0; k < 4; k++ {
			nx, ny := x+dirs[k], y+dirs[k+1]
			if nx >= 0 && nx < m && ny >= 0 && ny < n {
				if grid[nx][ny] != grid[x][y] || (nx == px && ny == py) {
					continue
				}
				if vis[nx][ny] || dfs(nx, ny, x, y) {
					return true
				}
			}
		}
		return false
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if !vis[i][j] && dfs(i, j, -1, -1) {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function containsCycle(grid: string[][]): boolean {
    const [m, n] = [grid.length, grid[0].length];
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    const dfs = (x: number, y: number, px: number, py: number): boolean => {
        vis[x][y] = true;
        const dirs = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; k++) {
            const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] !== grid[x][y] || (nx === px && ny === py)) {
                    continue;
                }
                if (vis[nx][ny] || dfs(nx, ny, x, y)) {
                    return true;
                }
            }
        }
        return false;
    };
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!vis[i][j] && dfs(i, j, -1, -1)) {
                return true;
            }
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn contains_cycle(grid: Vec<Vec<char>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut vis = vec![vec![false; n]; m];
        let dirs = vec![-1, 0, 1, 0, -1];

        fn dfs(
            x: usize,
            y: usize,
            px: isize,
            py: isize,
            grid: &Vec<Vec<char>>,
            vis: &mut Vec<Vec<bool>>,
            dirs: &Vec<isize>,
        ) -> bool {
            vis[x][y] = true;
            for k in 0..4 {
                let nx = (x as isize + dirs[k]) as usize;
                let ny = (y as isize + dirs[k + 1]) as usize;
                if nx < grid.len() && ny < grid[0].len() {
                    if grid[nx][ny] != grid[x][y] || (nx as isize == px && ny as isize == py) {
                        continue;
                    }
                    if vis[nx][ny] || dfs(nx, ny, x as isize, y as isize, grid, vis, dirs) {
                        return true;
                    }
                }
            }
            false
        }

        for i in 0..m {
            for j in 0..n {
                if !vis[i][j] && dfs(i, j, -1, -1, &grid, &mut vis, &dirs) {
                    return true;
                }
            }
        }
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

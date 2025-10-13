---
title: "1870_准时到达的列车最小时速"
date: 2025-10-08T18:38:27+08:00
weight: 8
tags: [二分查找, 位运算, 前缀和, 动态规划, 博弈, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 滑动窗口, 状态压缩, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1870_准时到达的列车最小时速](#1870)
#### [数组](#1870)
#### [二分查找](#1870)
### [1871_跳跃游戏 VII](#1871)
#### [字符串](#1871)
#### [动态规划](#1871)
#### [前缀和](#1871)
#### [滑动窗口](#1871)
### [1872_石子游戏 VIII](#1872)
#### [数组](#1872)
#### [数学](#1872)
#### [动态规划](#1872)
#### [博弈](#1872)
#### [前缀和](#1872)
### [1873_计算特殊奖金](#1873)
#### [数据库](#1873)
### [1874_两个数组的最小乘积和 🔒](#1874)
#### [贪心](#1874)
#### [数组](#1874)
#### [排序](#1874)
### [1875_将工资相同的雇员分组 🔒](#1875)
#### [数据库](#1875)
### [1876_长度为三且各字符不同的子字符串](#1876)
#### [哈希表](#1876)
#### [字符串](#1876)
#### [计数](#1876)
#### [滑动窗口](#1876)
### [1877_数组中最大数对和的最小值](#1877)
#### [贪心](#1877)
#### [数组](#1877)
#### [双指针](#1877)
#### [排序](#1877)
### [1878_矩阵中最大的三个菱形和](#1878)
#### [数组](#1878)
#### [数学](#1878)
#### [矩阵](#1878)
#### [前缀和](#1878)
#### [排序](#1878)
#### [堆（优先队列）](#1878)
### [1879_两个数组最小的异或值之和](#1879)
#### [位运算](#1879)
#### [数组](#1879)
#### [动态规划](#1879)
#### [状态压缩](#1879)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1870_准时到达的列车最小时速
___
#### 数组
___
#### 二分查找
---
### 1871_跳跃游戏 VII
___
#### 字符串
___
#### 动态规划
___
#### 前缀和
___
#### 滑动窗口
---
### 1872_石子游戏 VIII
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
___
#### 前缀和
---
### 1873_计算特殊奖金
___
#### 数据库
---
### 1874_两个数组的最小乘积和 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1875_将工资相同的雇员分组 🔒
___
#### 数据库
---
### 1876_长度为三且各字符不同的子字符串
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 滑动窗口
---
### 1877_数组中最大数对和的最小值
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 1878_矩阵中最大的三个菱形和
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 前缀和
___
#### 排序
___
#### 堆（优先队列）
---
### 1879_两个数组最小的异或值之和
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 博弈 | 双指针 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 滑动窗口 | 状态压缩 |
| 矩阵 | 计数 | 贪心 |

# [1870. 准时到达的列车最小时速](https://leetcode.cn/problems/minimum-speed-to-arrive-on-time){#1870}

{{< tabs "1870" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def check(v: int) -> bool:
            s = 0
            for i, d in enumerate(dist):
                t = d / v
                s += t if i == len(dist) - 1 else ceil(t)
            return s <= hour

        if len(dist) > ceil(hour):
            return -1
        r = 10**7 + 1
        ans = bisect_left(range(1, r), True, key=check) + 1
        return -1 if ans == r else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        if (dist.length > Math.ceil(hour)) {
            return -1;
        }
        final int m = (int) 1e7;
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(dist, mid, hour)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }

    private boolean check(int[] dist, int v, double hour) {
        double s = 0;
        int n = dist.length;
        for (int i = 0; i < n; ++i) {
            double t = dist[i] * 1.0 / v;
            s += i == n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) {
            return -1;
        }
        const int m = 1e7;
        int l = 1, r = m + 1;
        int n = dist.size();
        auto check = [&](int v) {
            double s = 0;
            for (int i = 0; i < n; ++i) {
                double t = dist[i] * 1.0 / v;
                s += i == n - 1 ? t : ceil(t);
            }
            return s <= hour;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSpeedOnTime(dist []int, hour float64) int {
	if float64(len(dist)) > math.Ceil(hour) {
		return -1
	}
	const m int = 1e7
	n := len(dist)
	ans := sort.Search(m+1, func(v int) bool {
		v++
		s := 0.0
		for i, d := range dist {
			t := float64(d) / float64(v)
			if i == n-1 {
				s += t
			} else {
				s += math.Ceil(t)
			}
		}
		return s <= hour
	}) + 1
	if ans > m {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSpeedOnTime(dist: number[], hour: number): number {
    if (dist.length > Math.ceil(hour)) {
        return -1;
    }
    const n = dist.length;
    const m = 10 ** 7;
    const check = (v: number): boolean => {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            const t = dist[i] / v;
            s += i === n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    };
    let [l, r] = [1, m + 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
        if dist.len() as f64 > hour.ceil() {
            return -1;
        }
        const M: i32 = 10_000_000;
        let (mut l, mut r) = (1, M + 1);
        let n = dist.len();
        let check = |v: i32| -> bool {
            let mut s = 0.0;
            for i in 0..n {
                let t = dist[i] as f64 / v as f64;
                s += if i == n - 1 { t } else { t.ceil() };
            }
            s <= hour
        };
        while l < r {
            let mid = (l + r) / 2;
            if check(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if l > M {
            -1
        } else {
            l
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} dist
 * @param {number} hour
 * @return {number}
 */
var minSpeedOnTime = function (dist, hour) {
    if (dist.length > Math.ceil(hour)) {
        return -1;
    }
    const n = dist.length;
    const m = 10 ** 7;
    const check = v => {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            const t = dist[i] / v;
            s += i === n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    };
    let [l, r] = [1, m + 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
};
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun minSpeedOnTime(dist: IntArray, hour: Double): Int {
        val n = dist.size
        if (n > Math.ceil(hour)) {
            return -1
        }
        val m = 1e7.toInt()
        var left = 1
        var right = m + 1
        while (left < right) {
            val middle = (left + right) / 2
            var time = 0.0
            dist.forEachIndexed { i, item ->
                val t = item.toDouble() / middle
                time += if (i == n - 1) t else Math.ceil(t)
            }
            if (time > hour) {
                left = middle + 1
            } else {
                right = middle
            }
        }
        return if (left > m) -1 else left
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个浮点数 <code>hour</code> ，表示你到达办公室可用的总通勤时间。要到达办公室，你必须按给定次序乘坐 <code>n</code> 趟列车。另给你一个长度为 <code>n</code> 的整数数组 <code>dist</code> ，其中 <code>dist[i]</code> 表示第 <code>i</code> 趟列车的行驶距离（单位是千米）。</p>

<p>每趟列车均只能在整点发车，所以你可能需要在两趟列车之间等待一段时间。</p>

<ul>
	<li>例如，第 <code>1</code> 趟列车需要 <code>1.5</code> 小时，那你必须再等待 <code>0.5</code> 小时，搭乘在第 2 小时发车的第 <code>2</code> 趟列车。</li>
</ul>

<p>返回能满足你在时限前到达办公室所要求全部列车的<strong> 最小正整数 </strong>时速（单位：千米每小时），如果无法准时到达，则返回 <code>-1</code> 。</p>

<p>生成的测试用例保证答案不超过 <code>10<sup>7</sup></code> ，且 <code>hour</code> 的 <strong>小数点后最多存在两位数字</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 6
<strong>输出：</strong>1
<strong>解释：</strong>速度为 1 时：
- 第 1 趟列车运行需要 1/1 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 1 小时发车的列车。第 2 趟列车运行需要 3/1 = 3 小时。
- 由于是在整数时间到达，可以立即换乘在第 4 小时发车的列车。第 3 趟列车运行需要 2/1 = 2 小时。
- 你将会恰好在第 6 小时到达。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 2.7
<strong>输出：</strong>3
<strong>解释：</strong>速度为 3 时：
- 第 1 趟列车运行需要 1/3 = 0.33333 小时。
- 由于不是在整数时间到达，故需要等待至第 1 小时才能搭乘列车。第 2 趟列车运行需要 3/3 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 2 小时发车的列车。第 3 趟列车运行需要 2/3 = 0.66667 小时。
- 你将会在第 2.66667 小时到达。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 1.9
<strong>输出：</strong>-1
<strong>解释：</strong>不可能准时到达，因为第 3 趟列车最早是在第 2 小时发车。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dist.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= dist[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= hour &lt;= 10<sup>9</sup></code></li>
	<li><code>hours</code> 中，小数点后最多存在两位数字</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果一个速度值 $v$ 能够使得我们在规定时间内到达，那么对于任意 $v' > v$，我们也一定能在规定时间内到达。这存在着单调性，因此我们可以使用二分查找，找到最小的满足条件的速度值。

在二分查找之前，我们需要先判断是否有可能在规定时间内到达。如果列车数量大于向上取整的规定时间，那么一定无法在规定时间内到达，直接返回 $-1$。

接下来，我们定义二分的左右边界为 $l = 1$, $r = 10^7 + 1$，然后我们每次取中间值 $\textit{mid} = \frac{l + r}{2}$，判断是否满足条件。如果满足条件，我们将右边界移动到 $\textit{mid}$，否则将左边界移动到 $\textit{mid} + 1$。

问题转化为判断一个速度值 $v$ 是否能够在规定时间内到达。我们可以遍历每一趟列车，计算每一趟列车的运行时间 $t = \frac{d}{v}$，如果是最后一趟列车，我们直接加上 $t$，否则我们向上取整加上 $t$。最后判断总时间是否小于等于规定时间，如果是则说明满足条件。

二分结束后，如果左边界超过了 $10^7$，说明无法在规定时间内到达，返回 $-1$，否则返回左边界。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别为列车数量和速度的上界。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def check(v: int) -> bool:
            s = 0
            for i, d in enumerate(dist):
                t = d / v
                s += t if i == len(dist) - 1 else ceil(t)
            return s <= hour

        if len(dist) > ceil(hour):
            return -1
        r = 10**7 + 1
        ans = bisect_left(range(1, r), True, key=check) + 1
        return -1 if ans == r else ans
```

#### Java

```java
class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        if (dist.length > Math.ceil(hour)) {
            return -1;
        }
        final int m = (int) 1e7;
        int l = 1, r = m + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(dist, mid, hour)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }

    private boolean check(int[] dist, int v, double hour) {
        double s = 0;
        int n = dist.length;
        for (int i = 0; i < n; ++i) {
            double t = dist[i] * 1.0 / v;
            s += i == n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) {
            return -1;
        }
        const int m = 1e7;
        int l = 1, r = m + 1;
        int n = dist.size();
        auto check = [&](int v) {
            double s = 0;
            for (int i = 0; i < n; ++i) {
                double t = dist[i] * 1.0 / v;
                s += i == n - 1 ? t : ceil(t);
            }
            return s <= hour;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l > m ? -1 : l;
    }
};
```

#### Go

```go
func minSpeedOnTime(dist []int, hour float64) int {
	if float64(len(dist)) > math.Ceil(hour) {
		return -1
	}
	const m int = 1e7
	n := len(dist)
	ans := sort.Search(m+1, func(v int) bool {
		v++
		s := 0.0
		for i, d := range dist {
			t := float64(d) / float64(v)
			if i == n-1 {
				s += t
			} else {
				s += math.Ceil(t)
			}
		}
		return s <= hour
	}) + 1
	if ans > m {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minSpeedOnTime(dist: number[], hour: number): number {
    if (dist.length > Math.ceil(hour)) {
        return -1;
    }
    const n = dist.length;
    const m = 10 ** 7;
    const check = (v: number): boolean => {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            const t = dist[i] / v;
            s += i === n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    };
    let [l, r] = [1, m + 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_speed_on_time(dist: Vec<i32>, hour: f64) -> i32 {
        if dist.len() as f64 > hour.ceil() {
            return -1;
        }
        const M: i32 = 10_000_000;
        let (mut l, mut r) = (1, M + 1);
        let n = dist.len();
        let check = |v: i32| -> bool {
            let mut s = 0.0;
            for i in 0..n {
                let t = dist[i] as f64 / v as f64;
                s += if i == n - 1 { t } else { t.ceil() };
            }
            s <= hour
        };
        while l < r {
            let mid = (l + r) / 2;
            if check(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if l > M {
            -1
        } else {
            l
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} dist
 * @param {number} hour
 * @return {number}
 */
var minSpeedOnTime = function (dist, hour) {
    if (dist.length > Math.ceil(hour)) {
        return -1;
    }
    const n = dist.length;
    const m = 10 ** 7;
    const check = v => {
        let s = 0;
        for (let i = 0; i < n; ++i) {
            const t = dist[i] / v;
            s += i === n - 1 ? t : Math.ceil(t);
        }
        return s <= hour;
    };
    let [l, r] = [1, m + 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l > m ? -1 : l;
};
```

#### Kotlin

```kotlin
class Solution {
    fun minSpeedOnTime(dist: IntArray, hour: Double): Int {
        val n = dist.size
        if (n > Math.ceil(hour)) {
            return -1
        }
        val m = 1e7.toInt()
        var left = 1
        var right = m + 1
        while (left < right) {
            val middle = (left + right) / 2
            var time = 0.0
            dist.forEachIndexed { i, item ->
                val t = item.toDouble() / middle
                time += if (i == n - 1) t else Math.ceil(t)
            }
            if (time > hour) {
                left = middle + 1
            } else {
                right = middle
            }
        }
        return if (left > m) -1 else left
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1871. 跳跃游戏 VII](https://leetcode.cn/problems/jump-game-vii){#1871}

{{< tabs "1871" >}}

{{% tab "python" %}}
```python
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        pre = [0] * (n + 1)
        pre[1] = 1
        f = [True] + [False] * (n - 1)
        for i in range(1, n):
            if s[i] == "0":
                l, r = max(0, i - maxJump), i - minJump
                f[i] = l <= r and pre[r + 1] - pre[l] > 0
            pre[i + 1] = pre[i] + f[i]
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        int[] pre = new int[n + 1];
        pre[1] = 1;
        boolean[] f = new boolean[n];
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == '0') {
                int l = Math.max(0, i - maxJump);
                int r = i - minJump;
                f[i] = l <= r && pre[r + 1] - pre[l] > 0;
            }
            pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int pre[n + 1];
        memset(pre, 0, sizeof(pre));
        pre[1] = 1;
        bool f[n];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                int l = max(0, i - maxJump);
                int r = i - minJump;
                f[i] = l <= r && pre[r + 1] - pre[l];
            }
            pre[i + 1] = pre[i] + f[i];
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canReach(s string, minJump int, maxJump int) bool {
	n := len(s)
	pre := make([]int, n+1)
	pre[1] = 1
	f := make([]bool, n)
	f[0] = true
	for i := 1; i < n; i++ {
		if s[i] == '0' {
			l, r := max(0, i-maxJump), i-minJump
			f[i] = l <= r && pre[r+1]-pre[l] > 0
		}
		pre[i+1] = pre[i]
		if f[i] {
			pre[i+1]++
		}
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canReach(s: string, minJump: number, maxJump: number): boolean {
    const n = s.length;
    const pre: number[] = Array(n + 1).fill(0);
    pre[1] = 1;
    const f: boolean[] = Array(n).fill(false);
    f[0] = true;
    for (let i = 1; i < n; ++i) {
        if (s[i] === '0') {
            const [l, r] = [Math.max(0, i - maxJump), i - minJump];
            f[i] = l <= r && pre[r + 1] - pre[l] > 0;
        }
        pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
    }
    return f[n - 1];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} minJump
 * @param {number} maxJump
 * @return {boolean}
 */
var canReach = function (s, minJump, maxJump) {
    const n = s.length;
    const pre = Array(n + 1).fill(0);
    pre[1] = 1;
    const f = Array(n).fill(false);
    f[0] = true;
    for (let i = 1; i < n; ++i) {
        if (s[i] === '0') {
            const [l, r] = [Math.max(0, i - maxJump), i - minJump];
            f[i] = l <= r && pre[r + 1] - pre[l] > 0;
        }
        pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
    }
    return f[n - 1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0 </strong>开始的二进制字符串 <code>s</code> 和两个整数 <code>minJump</code> 和 <code>maxJump</code> 。一开始，你在下标 <code>0</code> 处，且该位置的值一定为 <code>'0'</code> 。当同时满足如下条件时，你可以从下标 <code>i</code> 移动到下标 <code>j</code> 处：</p>

<ul>
	<li><code>i + minJump <= j <= min(i + maxJump, s.length - 1)</code> 且</li>
	<li><code>s[j] == '0'</code>.</li>
</ul>

<p>如果你可以到达 <code>s</code> 的下标<i> </i><code>s.length - 1</code> 处，请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "<strong>0</strong>11<strong>0</strong>1<strong>0</strong>", minJump = 2, maxJump = 3
<b>输出：</b>true
<strong>解释：</strong>
第一步，从下标 0 移动到下标 3 。
第二步，从下标 3 移动到下标 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "01101110", minJump = 2, maxJump = 3
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 要么是 <code>'0'</code> ，要么是 <code>'1'</code></li>
	<li><code>s[0] == '0'</code></li>
	<li><code>1 <= minJump <= maxJump < s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 动态规划

我们定义一个长度为 $n+1$ 的前缀和数组 $pre$，其中 $pre[i]$ 表示 $s$ 的前 $i$ 个位置中能够到达的个数。定义一个长度为 $n$ 的布尔数组 $f$，其中 $f[i]$ 表示 $s[i]$ 是否能够到达。初始时 $pre[1] = 1$，而 $f[0] = true$。

考虑 $i \in [1, n)$，如果 $s[i] = 0$，那么我们需要判断 $s$ 的前 $i$ 个位置中是否存在一个位置 $j$，满足 $j$ 能够到达且 $j$ 到 $i$ 的距离在 $[minJump, maxJump]$ 之间。如果存在这样的位置 $j$，那么我们就有 $f[i] = true$，否则 $f[i] = false$。在判断 $j$ 是否存在时，我们可以通过前缀和数组 $pre$ 在 $O(1)$ 的时间内判断是否存在这样的位置 $j$。

最终答案即为 $f[n-1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        pre = [0] * (n + 1)
        pre[1] = 1
        f = [True] + [False] * (n - 1)
        for i in range(1, n):
            if s[i] == "0":
                l, r = max(0, i - maxJump), i - minJump
                f[i] = l <= r and pre[r + 1] - pre[l] > 0
            pre[i + 1] = pre[i] + f[i]
        return f[-1]
```

#### Java

```java
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        int[] pre = new int[n + 1];
        pre[1] = 1;
        boolean[] f = new boolean[n];
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == '0') {
                int l = Math.max(0, i - maxJump);
                int r = i - minJump;
                f[i] = l <= r && pre[r + 1] - pre[l] > 0;
            }
            pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int pre[n + 1];
        memset(pre, 0, sizeof(pre));
        pre[1] = 1;
        bool f[n];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                int l = max(0, i - maxJump);
                int r = i - minJump;
                f[i] = l <= r && pre[r + 1] - pre[l];
            }
            pre[i + 1] = pre[i] + f[i];
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func canReach(s string, minJump int, maxJump int) bool {
	n := len(s)
	pre := make([]int, n+1)
	pre[1] = 1
	f := make([]bool, n)
	f[0] = true
	for i := 1; i < n; i++ {
		if s[i] == '0' {
			l, r := max(0, i-maxJump), i-minJump
			f[i] = l <= r && pre[r+1]-pre[l] > 0
		}
		pre[i+1] = pre[i]
		if f[i] {
			pre[i+1]++
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function canReach(s: string, minJump: number, maxJump: number): boolean {
    const n = s.length;
    const pre: number[] = Array(n + 1).fill(0);
    pre[1] = 1;
    const f: boolean[] = Array(n).fill(false);
    f[0] = true;
    for (let i = 1; i < n; ++i) {
        if (s[i] === '0') {
            const [l, r] = [Math.max(0, i - maxJump), i - minJump];
            f[i] = l <= r && pre[r + 1] - pre[l] > 0;
        }
        pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
    }
    return f[n - 1];
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} minJump
 * @param {number} maxJump
 * @return {boolean}
 */
var canReach = function (s, minJump, maxJump) {
    const n = s.length;
    const pre = Array(n + 1).fill(0);
    pre[1] = 1;
    const f = Array(n).fill(false);
    f[0] = true;
    for (let i = 1; i < n; ++i) {
        if (s[i] === '0') {
            const [l, r] = [Math.max(0, i - maxJump), i - minJump];
            f[i] = l <= r && pre[r + 1] - pre[l] > 0;
        }
        pre[i + 1] = pre[i] + (f[i] ? 1 : 0);
    }
    return f[n - 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1872. 石子游戏 VIII](https://leetcode.cn/problems/stone-game-viii){#1872}

{{< tabs "1872" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        s = list(accumulate(stones))
        f = s[-1]
        for i in range(len(s) - 2, 0, -1):
            f = max(f, s[i] - f)
        return f
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int f = stones[n - 1];
        for (int i = n - 2; i > 0; --i) {
            f = Math.max(f, stones[i] - f);
        }
        return f;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int f = stones.back();
        for (int i = n - 2; i; --i) {
            f = max(f, stones[i] - f);
        }
        return f;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameVIII(stones []int) int {
	n := len(stones)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	for i := 1; i < n; i++ {
		stones[i] += stones[i-1]
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n-1 {
			return stones[i]
		}
		if f[i] == -1 {
			f[i] = max(dfs(i+1), stones[i]-dfs(i+1))
		}
		return f[i]
	}
	return dfs(1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameVIII(stones: number[]): number {
    const n = stones.length;
    for (let i = 1; i < n; ++i) {
        stones[i] += stones[i - 1];
    }
    let f = stones[n - 1];
    for (let i = n - 2; i; --i) {
        f = Math.max(f, stones[i] - f);
    }
    return f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 玩一个游戏，两人轮流操作， <strong>Alice 先手</strong> 。</p>

<p>总共有 <code>n</code> 个石子排成一行。轮到某个玩家的回合时，如果石子的数目 <strong>大于 1</strong> ，他将执行以下操作：</p>

<ol>
	<li>选择一个整数 <code>x &gt; 1</code> ，并且 <strong>移除</strong> 最左边的 <code>x</code> 个石子。</li>
	<li>将<strong> 移除</strong> 的石子价值之 <strong>和</strong> 累加到该玩家的分数中。</li>
	<li>将一个 <strong>新的石子</strong> 放在最左边，且新石子的值为被移除石子值之和。</li>
</ol>

<p>当只剩下 <strong>一个</strong> 石子时，游戏结束。</p>

<p>Alice 和 Bob 的 <strong>分数之差</strong> 为 <code>(Alice 的分数 - Bob 的分数)</code> 。 Alice 的目标是<strong> 最大化</strong> 分数差，Bob 的目标是 <strong>最小化</strong> 分数差。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>stones</code> ，其中 <code>stones[i]</code> 是 <strong>从左边起</strong> 第 <code>i</code> 个石子的价值。请你返回在双方都采用 <strong>最优</strong> 策略的情况下，Alice 和 Bob 的 <strong>分数之差</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>stones = [-1,2,-3,4,-5]
<b>输出：</b>5
<strong>解释：</strong>
- Alice 移除最左边的 4 个石子，得分增加 (-1) + 2 + (-3) + 4 = 2 ，并且将一个价值为 2 的石子放在最左边。stones = [2,-5] 。
- Bob 移除最左边的 2 个石子，得分增加 2 + (-5) = -3 ，并且将一个价值为 -3 的石子放在最左边。stones = [-3] 。
两者分数之差为 2 - (-3) = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>stones = [7,-6,5,10,5,-2,-6]
<b>输出：</b>13
<b>解释：</b>
- Alice 移除所有石子，得分增加 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 ，并且将一个价值为 13 的石子放在最左边。stones = [13] 。
两者分数之差为 13 - 0 = 13 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>stones = [-10,-12]
<b>输出：</b>-22
<strong>解释：</strong>
- Alice 只有一种操作，就是移除所有石子。得分增加 (-10) + (-12) = -22 ，并且将一个价值为 -22 的石子放在最左边。stones = [-22] 。
两者分数之差为 (-22) - 0 = -22 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 记忆化搜索

根据题目描述，每次取走最左边的 $x$ 个石子，把它们的和加到自己的分数中，然后把一个价值为这个和的石子放在最左边，相当于把这 $x$ 个石子合并成了一个价值为这个和的石子，前缀和不变。

我们可以用一个长度为 $n$ 的前缀和数组 $s$ 来表示数组 $stones$ 的前缀和，其中 $s[i]$ 表示 $stones[0..i]$ 的元素和。

接下来，我们设计一个函数 $dfs(i)$，表示当前从 $stones[i:]$ 中取石子，返回当前玩家能得到的最大分数差。

函数 $dfs(i)$ 的执行过程如下：

-   如果 $i \geq n - 1$，说明当前只能取走全部石子，因此返回 $s[n - 1]$。
-   否则，我们可以选择从 $stones[i + 1:]$ 中取走全部石子，得到的分数差为 $dfs(i + 1)$；也可以选择取走 $stones[:i]$ 的石子，得到的分数差为 $s[i] - dfs(i + 1)$。我们取两种情况中的最大值，即为当前玩家能得到的最大分数差。

最终，我们可以得到 Alice 和 Bob 的分数之差为 $dfs(1)$，即 $Alice$ 必须从 $stones[1:]$ 中取石子开始游戏。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $stones$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(stones) - 1:
                return s[-1]
            return max(dfs(i + 1), s[i] - dfs(i + 1))

        s = list(accumulate(stones))
        return dfs(1)
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] s;
    private int n;

    public int stoneGameVIII(int[] stones) {
        n = stones.length;
        f = new Integer[n];
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        s = stones;
        return dfs(1);
    }

    private int dfs(int i) {
        if (i >= n - 1) {
            return s[i];
        }
        if (f[i] == null) {
            f[i] = Math.max(dfs(i + 1), s[i] - dfs(i + 1));
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int f[n];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n - 1) {
                return stones[i];
            }
            if (f[i] == -1) {
                f[i] = max(dfs(i + 1), stones[i] - dfs(i + 1));
            }
            return f[i];
        };
        return dfs(1);
    }
};
```

#### Go

```go
func stoneGameVIII(stones []int) int {
	n := len(stones)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	for i := 1; i < n; i++ {
		stones[i] += stones[i-1]
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n-1 {
			return stones[i]
		}
		if f[i] == -1 {
			f[i] = max(dfs(i+1), stones[i]-dfs(i+1))
		}
		return f[i]
	}
	return dfs(1)
}
```

#### TypeScript

```ts
function stoneGameVIII(stones: number[]): number {
    const n = stones.length;
    const f: number[] = Array(n).fill(-1);
    for (let i = 1; i < n; ++i) {
        stones[i] += stones[i - 1];
    }
    const dfs = (i: number): number => {
        if (i >= n - 1) {
            return stones[i];
        }
        if (f[i] === -1) {
            f[i] = Math.max(dfs(i + 1), stones[i] - dfs(i + 1));
        }
        return f[i];
    };
    return dfs(1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀和 + 动态规划

我们也可以使用动态规划的方法来解决这个问题。

与方法一类似，我们先用一个长度为 $n$ 的前缀和数组 $s$ 来表示数组 $stones$ 的前缀和，其中 $s[i]$ 表示 $stones[0..i]$ 的元素和。

我们定义 $f[i]$ 表示当前从 $stones[i:]$ 中取石子，返回当前玩家能得到的最大分数差。

若玩家选择取走 $stones[:i]$ 的石子，那么获得的分数为 $s[i]$，此时另一个玩家会在 $stones[i+1:]$ 中取石子，那么另一个玩家能得到的最大分数差为 $f[i+1]$，因此当前玩家能得到的最大分数差为 $s[i] - f[i+1]$。

若玩家选择从 $stones[i+1:]$ 中取石子，那么获得的最大分数差为 $f[i+1]$。

因此我们可以得到状态转移方程：

$$
f[i] = \max\{s[i] - f[i+1], f[i+1]\}
$$

最终，我们可以得到 Alice 和 Bob 的分数之差为 $f[1]$，即 $Alice$ 必须从 $stones[1:]$ 中取石子开始游戏。

我们注意到 $f[i]$ 只与 $f[i+1]$ 有关，因此我们只需要使用一个变量 $f$ 来表示 $f[i]$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $stones$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        s = list(accumulate(stones))
        f = s[-1]
        for i in range(len(s) - 2, 0, -1):
            f = max(f, s[i] - f)
        return f
```

#### Java

```java
class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int f = stones[n - 1];
        for (int i = n - 2; i > 0; --i) {
            f = Math.max(f, stones[i] - f);
        }
        return f;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int f = stones.back();
        for (int i = n - 2; i; --i) {
            f = max(f, stones[i] - f);
        }
        return f;
    }
};
```

#### TypeScript

```ts
function stoneGameVIII(stones: number[]): number {
    const n = stones.length;
    for (let i = 1; i < n; ++i) {
        stones[i] += stones[i - 1];
    }
    let f = stones[n - 1];
    for (let i = n - 2; i; --i) {
        f = Math.max(f, stones[i] - f);
    }
    return f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1873. 计算特殊奖金](https://leetcode.cn/problems/calculate-special-bonus){#1873}

{{< tabs "1873" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    employee_id,
    IF(
        employee_id % 2 = 0
        OR LEFT(name, 1) = 'M',
        0,
        salary
    ) AS bonus
FROM
    employees
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+-------------+---------+
| 列名        | 类型     |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id 是这个表的主键(具有唯一值的列)。
此表的每一行给出了雇员id ，名字和薪水。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，计算每个雇员的奖金。如果一个雇员的 id 是 <strong>奇数</strong> 并且他的名字不是以 <code>'M'</code> <strong>开头</strong>，那么他的奖金是他工资的 <code>100%</code> ，否则奖金为 <code>0</code> 。</p>

<p>返回的结果按照&nbsp;<code>employee_id</code>&nbsp;排序。</p>

<p>返回结果格式如下面的例子所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Employees 表:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3800   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7700   |
+-------------+---------+--------+
<strong>输出：</strong>
+-------------+-------+
| employee_id | bonus |
+-------------+-------+
| 2           | 0     |
| 3           | 0     |
| 7           | 7400  |
| 8           | 0     |
| 9           | 7700  |
+-------------+-------+
<strong>解释：</strong>
因为雇员id是偶数，所以雇员id 是2和8的两个雇员得到的奖金是0。
雇员id为3的因为他的名字以'M'开头，所以，奖金是0。
其他的雇员得到了百分之百的奖金。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：IF 语句 + ORDER BY 子句

我们可以使用 `IF` 语句来判断奖金的计算方式，然后使用 `ORDER BY` 将结果按照 `employee_id` 排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    employee_id,
    IF(
        employee_id % 2 = 0
        OR LEFT(name, 1) = 'M',
        0,
        salary
    ) AS bonus
FROM
    employees
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1874. 两个数组的最小乘积和 🔒](https://leetcode.cn/problems/minimize-product-sum-of-two-arrays){#1874}

{{< tabs "1874" >}}

{{% tab "python" %}}
```python
class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort(reverse=True)
        return sum(x * y for x, y in zip(nums1, nums2))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minProductSum(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int n = nums1.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums1[i] * nums2[n - i - 1];
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
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2, greater<int>());
        int n = nums1.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums1[i] * nums2[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minProductSum(nums1 []int, nums2 []int) (ans int) {
	sort.Ints(nums1)
	sort.Ints(nums2)
	for i, x := range nums1 {
		ans += x * nums2[len(nums2)-1-i]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minProductSum(nums1: number[], nums2: number[]): number {
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < nums1.length; ++i) {
        ans += nums1[i] * nums2[i];
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

<p>给定两个<strong>长度相等</strong>的数组<code>a</code>和<code>b</code>，它们的<strong>乘积和</strong>为数组中所有的<code>a[i] * b[i]</code>之和，其中<code>0 &lt;= i &lt; a.length</code>。</p>

<ul>
	<li>比如<code>a = [1,2,3,4]</code>，<code>b = [5,2,3,1]</code>时，它们的<strong>乘积和</strong>为<code>1*5 + 2*2 + 3*3 + 4*1 = 22</code></li>
</ul>

<p>现有两个长度都为<code>n</code>的数组<code>nums1</code>和<code>nums2</code>，你可以以<strong>任意顺序排序</strong><code>nums1</code>，请返回它们的<strong>最小乘积和</strong>。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums1 = [5,3,4,2], nums2 = [4,2,2,5]
<strong>输出:</strong> 40
<strong>解释: </strong>将 num1 重新排列为 [3,5,4,2] 后，可由<b> </b>[3,5,4,2] 和 [4,2,2,5] 得到最小乘积和 3*4 + 5*2 + 4*2 + 2*5 = 40。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
<strong>输出:</strong> 65
<strong>解释:</strong> 将 num1 重新排列为 [5,7,4,1,2] 后，可由<b> </b>[5,7,4,1,2] 和 [3,2,4,8,6] 得到最小乘积和 5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65。
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

由于两个数组都是正整数，要使得乘积和最小，我们可以将两个数组中的最大值和最小值相乘，次大值和次小值相乘，以此类推。

因此，我们将数组 $\textit{nums1}$ 按照升序排序，将数组 $\textit{nums2}$ 按照降序排序，然后将两个数组对应位置的元素相乘，累加即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $\textit{nums1}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        nums1.sort()
        nums2.sort(reverse=True)
        return sum(x * y for x, y in zip(nums1, nums2))
```

#### Java

```java
class Solution {
    public int minProductSum(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int n = nums1.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums1[i] * nums2[n - i - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2, greater<int>());
        int n = nums1.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums1[i] * nums2[i];
        }
        return ans;
    }
};
```

#### Go

```go
func minProductSum(nums1 []int, nums2 []int) (ans int) {
	sort.Ints(nums1)
	sort.Ints(nums2)
	for i, x := range nums1 {
		ans += x * nums2[len(nums2)-1-i]
	}
	return
}
```

#### TypeScript

```ts
function minProductSum(nums1: number[], nums2: number[]): number {
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < nums1.length; ++i) {
        ans += nums1[i] * nums2[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1875. 将工资相同的雇员分组 🔒](https://leetcode.cn/problems/group-employees-of-the-same-salary){#1875}

{{< tabs "1875" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT salary
        FROM Employees
        GROUP BY salary
        HAVING COUNT(1) > 1
    ),
    T AS (
        SELECT salary, ROW_NUMBER() OVER (ORDER BY salary) AS team_id
        FROM S
    )
SELECT e.*, t.team_id
FROM
    Employees AS e
    JOIN T AS t ON e.salary = t.salary
ORDER BY 4, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id 是这张表具有唯一值的列.
这个表格的每一行包含雇员 ID, 姓名和工资信息.
</pre>

<p>&nbsp;</p>

<p>这家公司想要将&nbsp;<strong>工资相同&nbsp;</strong>的雇员划分到同一个组中。每个组需要满足如下要求：</p>

<ul>
	<li>每个组需要由&nbsp;<strong>至少两个&nbsp;</strong>雇员组成。</li>
	<li>同一个组中的所有雇员的&nbsp;<strong>工资相同</strong>。</li>
	<li>工资相同的所有雇员必须被分到同一个组中。</li>
	<li>如果某位雇员的工资是独一无二的，那么它&nbsp;<strong>不&nbsp;</strong>被分配到任何一个组中。</li>
	<li>组ID的设定基于这个组的工资相对于其他组的&nbsp;<strong>工资的排名</strong>，即工资&nbsp;<strong>最低&nbsp;</strong>的组满足&nbsp;<code>team_id = 1</code>&nbsp;。注意，排名时&nbsp;<strong>不需要考虑&nbsp;</strong>没有组的雇员的工资。</li>
</ul>

<p>编写一个解决方案来获取每一个被分配到组中的雇员的&nbsp;<code>team_id</code> 。</p>

<p>返回的结果表按照&nbsp;<code>team_id</code>&nbsp;<b>升序排列。</b>如果相同，则按照&nbsp;<code>employee_id</code>&nbsp;<strong>升序排列</strong>。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employees 表:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3000   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7400   |
+-------------+---------+--------+
<strong>输出：</strong>
+-------------+---------+--------+---------+
| employee_id | name    | salary | team_id |
+-------------+---------+--------+---------+
| 2           | Meir    | 3000   | 1       |
| 3           | Michael | 3000   | 1       |
| 7           | Addilyn | 7400   | 2       |
| 9           | Kannon  | 7400   | 2       |
+-------------+---------+--------+---------+
<strong>解释：</strong>
Meir (employee_id=2) 和 Michael (employee_id=3) 在同一个组中，因为他们的工资都是3000。
Addilyn (employee_id=7) 和 Kannon (employee_id=9) 在同一个组中，因为他们的工资都是7400。
Juan (employee_id=8) 不在任何一个组中，因为他的工资为6100，是独一无二的（即：没有人和他的工资相同）。
组ID按照如下方式分配（基于工资排名，较低的排在前面）:
- team_id=1: Meir 和 Michael, 工资是3000
- team_id=2: Addilyn 和 Kannon, 工资是7400
Juan的工资(6100)没有被计算在排名中，因为他不属于任何一个组。</pre>

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
    S AS (
        SELECT salary
        FROM Employees
        GROUP BY salary
        HAVING COUNT(1) > 1
    ),
    T AS (
        SELECT salary, ROW_NUMBER() OVER (ORDER BY salary) AS team_id
        FROM S
    )
SELECT e.*, t.team_id
FROM
    Employees AS e
    JOIN T AS t ON e.salary = t.salary
ORDER BY 4, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1876. 长度为三且各字符不同的子字符串](https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters){#1876}

{{< tabs "1876" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        ans = mask = l = 0
        for r, x in enumerate(map(lambda c: ord(c) - 97, s)):
            while mask >> x & 1:
                y = ord(s[l]) - 97
                mask ^= 1 << y
                l += 1
            mask |= 1 << x
            ans += int(r - l + 1 >= 3)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countGoodSubstrings(String s) {
        int ans = 0;
        int n = s.length();
        for (int l = 0, r = 0, mask = 0; r < n; ++r) {
            int x = s.charAt(r) - 'a';
            while ((mask >> x & 1) == 1) {
                int y = s.charAt(l++) - 'a';
                mask ^= 1 << y;
            }
            mask |= 1 << x;
            ans += r - l + 1 >= 3 ? 1 : 0;
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
    int countGoodSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for (int l = 0, r = 0, mask = 0; r < n; ++r) {
            int x = s[r] - 'a';
            while ((mask >> x & 1) == 1) {
                int y = s[l++] - 'a';
                mask ^= 1 << y;
            }
            mask |= 1 << x;
            ans += r - l + 1 >= 3 ? 1 : 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGoodSubstrings(s string) (ans int) {
	mask, l := 0, 0
	for r, c := range s {
		x := int(c - 'a')
		for (mask>>x)&1 == 1 {
			y := int(s[l] - 'a')
			l++
			mask ^= 1 << y
		}
		mask |= 1 << x
		if r-l+1 >= 3 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodSubstrings(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let l = 0, r = 0, mask = 0; r < n; ++r) {
        const x = s.charCodeAt(r) - 'a'.charCodeAt(0);
        while ((mask >> x) & 1) {
            const y = s.charCodeAt(l++) - 'a'.charCodeAt(0);
            mask ^= 1 << y;
        }
        mask |= 1 << x;
        ans += r - l + 1 >= 3 ? 1 : 0;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function countGoodSubstrings($s) {
        $ans = 0;
        $n = strlen($s);
        $l = 0;
        $r = 0;
        $mask = 0;

        while ($r < $n) {
            $x = ord($s[$r]) - ord('a');
            while (($mask >> $x) & 1) {
                $y = ord($s[$l++]) - ord('a');
                $mask ^= 1 << $y;
            }
            $mask |= 1 << $x;
            if ($r - $l + 1 >= 3) {
                $ans++;
            }
            $r++;
        }

        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个字符串不含有任何重复字符，我们称这个字符串为 <strong>好</strong> 字符串。</p>

<p>给你一个字符串 <code>s</code> ，请你返回 <code>s</code> 中长度为 <strong>3</strong> 的 <strong>好子字符串</strong> 的数量。</p>

<p>注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中。</p>

<p><strong>子字符串</strong> 是一个字符串中连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "xyzzaz"
<b>输出：</b>1
<b>解释：</b>总共有 4 个长度为 3 的子字符串："xyz"，"yzz"，"zza" 和 "zaz" 。
唯一的长度为 3 的好子字符串是 "xyz" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "aababcabc"
<b>输出：</b>4
<b>解释：</b>总共有 7 个长度为 3 的子字符串："aab"，"aba"，"bab"，"abc"，"bca"，"cab" 和 "abc" 。
好子字符串包括 "abc"，"bca"，"cab" 和 "abc" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s</code>​​​​​​ 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们可以维护一个滑动窗口，使得窗口内的字符不重复。初始时，我们用一个长度为 $26$ 的二进制整数 $\textit{mask}$ 表示窗口内的字符，其中第 $i$ 位为 $1$ 表示字符 $i$ 在窗口内出现过，否则表示字符 $i$ 在窗口内没有出现过。

然后，我们遍历字符串 $s$，对于每一个位置 $r$，如果 $\textit{s}[r]$ 在窗口内出现过，我们需要将窗口的左边界 $l$ 右移，直到窗口内不再有重复的字符。在这之后，我们将 $\textit{s}[r]$ 加入窗口内，此时如果窗口的长度大于等于 $3$，那么我们就找到了一个以 $\textit{s}[r]$ 结尾的长度为 $3$ 的好子字符串。

遍历结束后，我们就找到了所有的好子字符串的数量。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

> 该解法可以拓展到长度为 $k$ 的好子字符串的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        ans = mask = l = 0
        for r, x in enumerate(map(lambda c: ord(c) - 97, s)):
            while mask >> x & 1:
                y = ord(s[l]) - 97
                mask ^= 1 << y
                l += 1
            mask |= 1 << x
            ans += int(r - l + 1 >= 3)
        return ans
```

#### Java

```java
class Solution {
    public int countGoodSubstrings(String s) {
        int ans = 0;
        int n = s.length();
        for (int l = 0, r = 0, mask = 0; r < n; ++r) {
            int x = s.charAt(r) - 'a';
            while ((mask >> x & 1) == 1) {
                int y = s.charAt(l++) - 'a';
                mask ^= 1 << y;
            }
            mask |= 1 << x;
            ans += r - l + 1 >= 3 ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for (int l = 0, r = 0, mask = 0; r < n; ++r) {
            int x = s[r] - 'a';
            while ((mask >> x & 1) == 1) {
                int y = s[l++] - 'a';
                mask ^= 1 << y;
            }
            mask |= 1 << x;
            ans += r - l + 1 >= 3 ? 1 : 0;
        }
        return ans;
    }
};
```

#### Go

```go
func countGoodSubstrings(s string) (ans int) {
	mask, l := 0, 0
	for r, c := range s {
		x := int(c - 'a')
		for (mask>>x)&1 == 1 {
			y := int(s[l] - 'a')
			l++
			mask ^= 1 << y
		}
		mask |= 1 << x
		if r-l+1 >= 3 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countGoodSubstrings(s: string): number {
    let ans = 0;
    const n = s.length;
    for (let l = 0, r = 0, mask = 0; r < n; ++r) {
        const x = s.charCodeAt(r) - 'a'.charCodeAt(0);
        while ((mask >> x) & 1) {
            const y = s.charCodeAt(l++) - 'a'.charCodeAt(0);
            mask ^= 1 << y;
        }
        mask |= 1 << x;
        ans += r - l + 1 >= 3 ? 1 : 0;
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function countGoodSubstrings($s) {
        $ans = 0;
        $n = strlen($s);
        $l = 0;
        $r = 0;
        $mask = 0;

        while ($r < $n) {
            $x = ord($s[$r]) - ord('a');
            while (($mask >> $x) & 1) {
                $y = ord($s[$l++]) - ord('a');
                $mask ^= 1 << $y;
            }
            $mask |= 1 << $x;
            if ($r - $l + 1 >= 3) {
                $ans++;
            }
            $r++;
        }

        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1877. 数组中最大数对和的最小值](https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array){#1877}

{{< tabs "1877" >}}

{{% tab "python" %}}
```python
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return max(x + nums[-i - 1] for i, x in enumerate(nums[: len(nums) >> 1]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for (int i = 0; i < n >> 1; ++i) {
            ans = Math.max(ans, nums[i] + nums[n - i - 1]);
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
    int minPairSum(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, n = nums.size();
        for (int i = 0; i < n >> 1; ++i) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minPairSum(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for i, x := range nums[:n>>1] {
		ans = max(ans, x+nums[n-1-i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minPairSum(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        ans = Math.max(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut ans = 0;
        let n = nums.len();
        for i in 0..n / 2 {
            ans = ans.max(nums[i] + nums[n - i - 1]);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function (nums) {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        ans = Math.max(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinPairSum(int[] nums) {
        Array.Sort(nums);
        int ans = 0, n = nums.Length;
        for (int i = 0; i < n >> 1; ++i) {
            ans = Math.Max(ans, nums[i] + nums[n - i - 1]);
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

<p>一个数对 <code>(a,b)</code> 的 <strong>数对和</strong> 等于 <code>a + b</code> 。<strong>最大数对和</strong> 是一个数对数组中最大的 <strong>数对和</strong> 。</p>

<ul>
	<li>比方说，如果我们有数对 <code>(1,5)</code> ，<code>(2,3)</code> 和 <code>(4,4)</code>，<strong>最大数对和</strong> 为 <code>max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8</code> 。</li>
</ul>

<p>给你一个长度为 <strong>偶数</strong> <code>n</code> 的数组 <code>nums</code> ，请你将 <code>nums</code> 中的元素分成 <code>n / 2</code> 个数对，使得：</p>

<ul>
	<li><code>nums</code> 中每个元素 <strong>恰好</strong> 在 <strong>一个</strong> 数对中，且</li>
	<li><strong>最大数对和</strong> 的值 <strong>最小</strong> 。</li>
</ul>

<p>请你在最优数对划分的方案下，返回最小的 <strong>最大数对和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,5,2,3]
<b>输出：</b>7
<b>解释：</b>数组中的元素可以分为数对 (3,3) 和 (5,2) 。
最大数对和为 max(3+3, 5+2) = max(6, 7) = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,5,4,2,4,6]
<b>输出：</b>8
<b>解释：</b>数组中的元素可以分为数对 (3,5)，(4,4) 和 (6,2) 。
最大数对和为 max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 是 <strong>偶数</strong> 。</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

要使得数组中最大数对和的值最小，那么我们可以将数组中最小的数和最大的数配对，次小的数和次大的数配对，依此类推。

因此，我们可以先对数组进行排序，然后使用两个指针分别指向数组的两端，求出两个指针指向的数的和，更新最大数对和的值，然后将左指针右移一位，右指针左移一位，继续进行操作，直到两个指针相遇为止，即可得到最小的最大数对和。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return max(x + nums[-i - 1] for i, x in enumerate(nums[: len(nums) >> 1]))
```

#### Java

```java
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for (int i = 0; i < n >> 1; ++i) {
            ans = Math.max(ans, nums[i] + nums[n - i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, n = nums.size();
        for (int i = 0; i < n >> 1; ++i) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func minPairSum(nums []int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	for i, x := range nums[:n>>1] {
		ans = max(ans, x+nums[n-1-i])
	}
	return
}
```

#### TypeScript

```ts
function minPairSum(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        ans = Math.max(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_pair_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut ans = 0;
        let n = nums.len();
        for i in 0..n / 2 {
            ans = ans.max(nums[i] + nums[n - i - 1]);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var minPairSum = function (nums) {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        ans = Math.max(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MinPairSum(int[] nums) {
        Array.Sort(nums);
        int ans = 0, n = nums.Length;
        for (int i = 0; i < n >> 1; ++i) {
            ans = Math.Max(ans, nums[i] + nums[n - i - 1]);
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

# [1878. 矩阵中最大的三个菱形和](https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid){#1878}

{{< tabs "1878" >}}

{{% tab "python" %}}
```python
class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        s1 = [[0] * (n + 2) for _ in range(m + 1)]
        s2 = [[0] * (n + 2) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s1[i][j] = s1[i - 1][j - 1] + x
                s2[i][j] = s2[i - 1][j + 1] + x
        ss = SortedSet()
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                l = min(i - 1, m - i, j - 1, n - j)
                ss.add(x)
                for k in range(1, l + 1):
                    a = s1[i + k][j] - s1[i][j - k]
                    b = s1[i][j + k] - s1[i - k][j]
                    c = s2[i][j - k] - s2[i - k][j]
                    d = s2[i + k][j] - s2[i][j + k]
                    ss.add(
                        a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]
                    )
                while len(ss) > 3:
                    ss.remove(ss[0])
        return list(ss)[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] s1 = new int[m + 1][n + 2];
        int[][] s2 = new int[m + 1][n + 2];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        TreeSet<Integer> ss = new TreeSet<>();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = Math.min(Math.min(i - 1, m - i), Math.min(j - 1, n - j));
                ss.add(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.add(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.pollFirst();
                }
            }
        }
        int[] ans = new int[ss.size()];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = ss.pollLast();
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
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s1(m + 1, vector<int>(n + 2));
        vector<vector<int>> s2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> ss;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = min({i - 1, m - i, j - 1, n - j});
                ss.insert(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.erase(ss.begin());
                }
            }
        }
        return vector<int>(ss.rbegin(), ss.rend());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getBiggestThree(grid [][]int) []int {
	m, n := len(grid), len(grid[0])
	s1 := make([][]int, m+1)
	s2 := make([][]int, m+1)
	for i := range s1 {
		s1[i] = make([]int, n+2)
		s2[i] = make([]int, n+2)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s1[i][j] = s1[i-1][j-1] + grid[i-1][j-1]
			s2[i][j] = s2[i-1][j+1] + grid[i-1][j-1]
		}
	}

	ss := treemap.NewWithIntComparator()
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			l := min(i-1, m-i, j-1, n-j)
			ss.Put(grid[i-1][j-1], nil)
			for k := 1; k <= l; k++ {
				a := s1[i+k][j] - s1[i][j-k]
				b := s1[i][j+k] - s1[i-k][j]
				c := s2[i][j-k] - s2[i-k][j]
				d := s2[i+k][j] - s2[i][j+k]
				ss.Put(a+b+c+d-grid[i+k-1][j-1]+grid[i-k-1][j-1], nil)
			}
			for ss.Size() > 3 {
				x, _ := ss.Min()
				ss.Remove(x.(int))
			}
		}
	}
	ans := make([]int, ss.Size())
	for i, k := range ss.Keys() {
		ans[len(ans)-i-1] = k.(int)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getBiggestThree(grid: number[][]): number[] {
    const m = grid.length;
    const n = grid[0].length;
    const s1: number[][] = Array.from({ length: m + 1 }, () => Array(n + 2).fill(0));
    const s2: number[][] = Array.from({ length: m + 1 }, () => Array(n + 2).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
            s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }
    const ss = new TreeSet<number>();
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const l = Math.min(i - 1, m - i, j - 1, n - j);
            ss.add(grid[i - 1][j - 1]);
            for (let k = 1; k <= l; ++k) {
                const a = s1[i + k][j] - s1[i][j - k];
                const b = s1[i][j + k] - s1[i - k][j];
                const c = s2[i][j - k] - s2[i - k][j];
                const d = s2[i + k][j] - s2[i][j + k];
                ss.add(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
            }
            while (ss.size() > 3) {
                ss.shift();
            }
        }
    }
    return [...ss].reverse();
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>grid</code> 。</p>

<p><strong>菱形和</strong> 指的是 <code>grid</code> 中一个正菱形 <strong>边界</strong> 上的元素之和。本题中的菱形必须为正方形旋转45度，且四个角都在一个格子当中。下图是四个可行的菱形，每个菱形和应该包含的格子都用了相应颜色标注在图中。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1878.Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/images/pc73-q4-desc-2.png" style="width: 385px; height: 385px;" />
<p> </p>

<p>注意，菱形可以是一个面积为 0 的区域，如上图中右下角的紫色菱形所示。</p>

<p>请你按照 <strong>降序</strong> 返回 <code>grid</code> 中三个最大的 <strong>互不相同的菱形和</strong> 。如果不同的和少于三个，则将它们全部返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1878.Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/images/pc73-q4-ex1.png" style="width: 360px; height: 361px;" />
<pre>
<b>输入：</b>grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
<b>输出：</b>[228,216,211]
<b>解释：</b>最大的三个菱形和如上图所示。
- 蓝色：20 + 3 + 200 + 5 = 228
- 红色：200 + 2 + 10 + 4 = 216
- 绿色：5 + 200 + 4 + 2 = 211
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1878.Get%20Biggest%20Three%20Rhombus%20Sums%20in%20a%20Grid/images/pc73-q4-ex2.png" style="width: 217px; height: 217px;" />
<pre>
<b>输入：</b>grid = [[1,2,3],[4,5,6],[7,8,9]]
<b>输出：</b>[20,9,8]
<b>解释：</b>最大的三个菱形和如上图所示。
- 蓝色：4 + 2 + 6 + 8 = 20
- 红色：9 （右下角红色的面积为 0 的菱形）
- 绿色：8 （下方中央面积为 0 的菱形）
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>grid = [[7,7,7]]
<b>输出：</b>[7]
<b>解释：</b>所有三个可能的菱形和都相同，所以返回 [7] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>1 <= grid[i][j] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举菱形中心点 + 前缀和 + 有序集合

我们可以预处理得到两个前缀和数组 $s_1$ 和 $s_2$，其中 $s_1[i][j]$ 表示以 $(i, j)$ 为末尾的左上对角线上的元素之和，而 $s_2[i][j]$ 表示以 $(i, j)$ 为末尾的右上对角线上的元素之和。

接下来，我们枚举每个位置 $(i, j)$，先将 $grid[i][j]$ 加入有序集合 $ss$ 中，然后枚举菱形的边长 $k$，那么以 $(i, j)$ 为中心点、边长为 $k$ 的菱形的和为：

$$
\begin{aligned}
&\quad s_1[i + k][j] - s_1[i][j - k] + s_1[i][j + k] - s_1[i - k][j] \\
&+ s_2[i][j - k] - s_2[i - k][j] + s_2[i + k][j] - s_2[i][j + k] \\
&- grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]
\end{aligned}
$$

我们将这个值加入有序集合 $ss$ 中，同时保证有序集合 $ss$ 的大小不超过 $3$，最后将有序集合 $ss$ 中的元素逆序输出即可。

时间复杂度 $O(m \times n \times \min(m, n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        s1 = [[0] * (n + 2) for _ in range(m + 1)]
        s2 = [[0] * (n + 2) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s1[i][j] = s1[i - 1][j - 1] + x
                s2[i][j] = s2[i - 1][j + 1] + x
        ss = SortedSet()
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                l = min(i - 1, m - i, j - 1, n - j)
                ss.add(x)
                for k in range(1, l + 1):
                    a = s1[i + k][j] - s1[i][j - k]
                    b = s1[i][j + k] - s1[i - k][j]
                    c = s2[i][j - k] - s2[i - k][j]
                    d = s2[i + k][j] - s2[i][j + k]
                    ss.add(
                        a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]
                    )
                while len(ss) > 3:
                    ss.remove(ss[0])
        return list(ss)[::-1]
```

#### Java

```java
class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] s1 = new int[m + 1][n + 2];
        int[][] s2 = new int[m + 1][n + 2];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        TreeSet<Integer> ss = new TreeSet<>();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = Math.min(Math.min(i - 1, m - i), Math.min(j - 1, n - j));
                ss.add(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.add(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.pollFirst();
                }
            }
        }
        int[] ans = new int[ss.size()];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = ss.pollLast();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s1(m + 1, vector<int>(n + 2));
        vector<vector<int>> s2(m + 1, vector<int>(n + 2));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> ss;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = min({i - 1, m - i, j - 1, n - j});
                ss.insert(grid[i - 1][j - 1]);
                for (int k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.erase(ss.begin());
                }
            }
        }
        return vector<int>(ss.rbegin(), ss.rend());
    }
};
```

#### Go

```go
func getBiggestThree(grid [][]int) []int {
	m, n := len(grid), len(grid[0])
	s1 := make([][]int, m+1)
	s2 := make([][]int, m+1)
	for i := range s1 {
		s1[i] = make([]int, n+2)
		s2[i] = make([]int, n+2)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s1[i][j] = s1[i-1][j-1] + grid[i-1][j-1]
			s2[i][j] = s2[i-1][j+1] + grid[i-1][j-1]
		}
	}

	ss := treemap.NewWithIntComparator()
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			l := min(i-1, m-i, j-1, n-j)
			ss.Put(grid[i-1][j-1], nil)
			for k := 1; k <= l; k++ {
				a := s1[i+k][j] - s1[i][j-k]
				b := s1[i][j+k] - s1[i-k][j]
				c := s2[i][j-k] - s2[i-k][j]
				d := s2[i+k][j] - s2[i][j+k]
				ss.Put(a+b+c+d-grid[i+k-1][j-1]+grid[i-k-1][j-1], nil)
			}
			for ss.Size() > 3 {
				x, _ := ss.Min()
				ss.Remove(x.(int))
			}
		}
	}
	ans := make([]int, ss.Size())
	for i, k := range ss.Keys() {
		ans[len(ans)-i-1] = k.(int)
	}
	return ans
}
```

#### TypeScript

```ts
function getBiggestThree(grid: number[][]): number[] {
    const m = grid.length;
    const n = grid[0].length;
    const s1: number[][] = Array.from({ length: m + 1 }, () => Array(n + 2).fill(0));
    const s2: number[][] = Array.from({ length: m + 1 }, () => Array(n + 2).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
            s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }
    const ss = new TreeSet<number>();
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const l = Math.min(i - 1, m - i, j - 1, n - j);
            ss.add(grid[i - 1][j - 1]);
            for (let k = 1; k <= l; ++k) {
                const a = s1[i + k][j] - s1[i][j - k];
                const b = s1[i][j + k] - s1[i - k][j];
                const c = s2[i][j - k] - s2[i - k][j];
                const d = s2[i + k][j] - s2[i][j + k];
                ss.add(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
            }
            while (ss.size() > 3) {
                ss.shift();
            }
        }
    }
    return [...ss].reverse();
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1879. 两个数组最小的异或值之和](https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays){#1879}

{{< tabs "1879" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums2)
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            k = i.bit_count() - 1
            for j in range(n):
                if i >> j & 1:
                    f[i] = min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]))
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int k = Integer.bitCount(i) - 1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int k = __builtin_popcount(i) - 1;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for i := 0; i < 1<<n; i++ {
		k := bits.OnesCount(uint(i)) - 1
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				f[i] = min(f[i], f[i^1<<j]+(nums1[k]^nums2[j]))
			}
		}
	}
	return f[(1<<n)-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumXORSum(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f: number[] = Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        const k = bitCount(i) - 1;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                f[i] = Math.min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
            }
        }
    }
    return f[(1 << n) - 1];
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code> ，它们长度都为 <code>n</code> 。</p>

<p>两个数组的 <strong>异或值之和</strong> 为 <code>(nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1])</code> （<strong>下标从 0 开始</strong>）。</p>

<ul>
	<li>比方说，<code>[1,2,3]</code> 和 <code>[3,2,1]</code> 的 <strong>异或值之和</strong> 等于 <code>(1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4</code> 。</li>
</ul>

<p>请你将 <code>nums2</code> 中的元素重新排列，使得 <strong>异或值之和</strong> <strong>最小</strong> 。</p>

<p>请你返回重新排列之后的 <strong>异或值之和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2], nums2 = [2,3]
<b>输出：</b>2
<b>解释：</b>将 <code>nums2</code> 重新排列得到 <code>[3,2] 。</code>
异或值之和为 (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,0,3], nums2 = [5,3,4]
<b>输出：</b>8
<b>解释：</b>将 <code>nums2 重新排列得到</code> <code>[5,4,3] 。</code>
异或值之和为 (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 14</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们注意到 $n \leq 14$，因此，我们可以考虑使用状态压缩动态规划的方法求解本题。

我们用一个长度为 $n$ 的二进制数表示当前的状态，第 $i$ 位为 $1$ 表示 $nums2[i]$ 已经被选择，为 $0$ 表示 $nums2[i]$ 还未被选择。

我们定义 $f[i][j]$ 表示 $nums1$ 的前 $i$ 个数中，选择了 $nums2$ 的 $i$ 个数，且当前所选数字的状态为 $j$ 时，数组 $nums1$ 和 $nums2$ 的异或值之和的最小值。初始时 $f[0][0]=0$，其余 $f[i][j]=+\infty$。

我们可以枚举 $nums1$ 的第 $i$ 个数 $x$，然后在 $[0,2^n)$ 的范围内枚举状态 $j$，转移方程为 $f[i][j]=\min(f[i][j],f[i-1][j\oplus 2^k]+(x\oplus nums2[k]))$，其中 $k$ 是 $j$ 的二进制表示中的某个 $1$ 所在的位置。

最后答案为 $f[n][2^n-1]$。

时间复杂度 $O(n^2 \times 2^n)$，空间复杂度 $O(n \times 2^n)$。其中 $n$ 是数组的长度。

我们注意到，状态 $f[i][j]$ 只与 $f[i-1][j\oplus 2^k]$ 有关，因此我们去掉第一维，将空间复杂度优化到 $O(2^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums2)
        f = [[inf] * (1 << n) for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(nums1, 1):
            for j in range(1 << n):
                for k in range(n):
                    if j >> k & 1:
                        f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + (x ^ nums2[k]))
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[][] f = new int[n + 1][1 << n];
        for (var g : f) {
            Arrays.fill(g, 1 << 30);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((j >> k & 1) == 1) {
                        f[i][j]
                            = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + (nums1[i - 1] ^ nums2[k]));
                    }
                }
            }
        }
        return f[n][(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f[n + 1][1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j >> k & 1) {
                        f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + (nums1[i - 1] ^ nums2[k]));
                    }
                }
            }
        }
        return f[n][(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, 1<<n)
		for j := range f[i] {
			f[i][j] = 1 << 30
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 0; j < 1<<n; j++ {
			for k := 0; k < n; k++ {
				if j>>k&1 == 1 {
					f[i][j] = min(f[i][j], f[i-1][j^(1<<k)]+(nums1[i-1]^nums2[k]))
				}
			}
		}
	}
	return f[n][(1<<n)-1]
}
```

#### TypeScript

```ts
function minimumXORSum(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(1 << n).fill(1 << 30));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            for (let k = 0; k < n; ++k) {
                if (((j >> k) & 1) === 1) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + (nums1[i - 1] ^ nums2[k]));
                }
            }
        }
    }
    return f[n][(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩动态规划（枚举优化）

我们也可以直接在 $[0, 2^n)$ 范围内枚举状态 $i$，假设 $i$ 的二进制表示中有 $k$ 个 $1$，那么当前枚举的就是 $nums1$ 的第 $k$ 个数，下标为 $k-1$。状态转移方程为 $f[i]=\min(f[i],f[i\oplus 2^j]+(nums1[k-1]\oplus nums2[j]))$，其中 $j$ 是 $i$ 的二进制表示中的某个 $1$ 所在的位置。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums2)
        f = [inf] * (1 << n)
        f[0] = 0
        for x in nums1:
            for j in range((1 << n) - 1, -1, -1):
                for k in range(n):
                    if j >> k & 1:
                        f[j] = min(f[j], f[j ^ (1 << k)] + (x ^ nums2[k]))
        return f[-1]
```

#### Java

```java
class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int x : nums1) {
            for (int j = (1 << n) - 1; j >= 0; --j) {
                for (int k = 0; k < n; ++k) {
                    if ((j >> k & 1) == 1) {
                        f[j] = Math.min(f[j], f[j ^ (1 << k)] + (x ^ nums2[k]));
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int x : nums1) {
            for (int j = (1 << n) - 1; ~j; --j) {
                for (int k = 0; k < n; ++k) {
                    if (j >> k & 1) {
                        f[j] = min(f[j], f[j ^ (1 << k)] + (x ^ nums2[k]));
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for _, x := range nums1 {
		for j := (1 << n) - 1; j >= 0; j-- {
			for k := 0; k < n; k++ {
				if j>>k&1 == 1 {
					f[j] = min(f[j], f[j^(1<<k)]+(x^nums2[k]))
				}
			}
		}
	}
	return f[(1<<n)-1]
}
```

#### TypeScript

```ts
function minimumXORSum(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f: number[] = Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (const x of nums1) {
        for (let j = (1 << n) - 1; ~j; --j) {
            for (let k = 0; k < n; ++k) {
                if (((j >> k) & 1) === 1) {
                    f[j] = Math.min(f[j], f[j ^ (1 << k)] + (x ^ nums2[k]));
                }
            }
        }
    }
    return f[(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums2)
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            k = i.bit_count() - 1
            for j in range(n):
                if i >> j & 1:
                    f[i] = min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]))
        return f[-1]
```

#### Java

```java
class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int k = Integer.bitCount(i) - 1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int k = __builtin_popcount(i) - 1;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for i := 0; i < 1<<n; i++ {
		k := bits.OnesCount(uint(i)) - 1
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				f[i] = min(f[i], f[i^1<<j]+(nums1[k]^nums2[j]))
			}
		}
	}
	return f[(1<<n)-1]
}
```

#### TypeScript

```ts
function minimumXORSum(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const f: number[] = Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        const k = bitCount(i) - 1;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                f[i] = Math.min(f[i], f[i ^ (1 << j)] + (nums1[k] ^ nums2[j]));
            }
        }
    }
    return f[(1 << n) - 1];
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

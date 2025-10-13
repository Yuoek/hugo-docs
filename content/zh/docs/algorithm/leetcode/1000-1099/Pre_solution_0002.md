---
title: "1010_总持续时间可被 60 整除的歌曲"
date: 2025-10-08T18:36:50+08:00
weight: 2
tags: [二分查找, 位运算, 动态规划, 单调栈, 哈希表, 字符串, 数学, 数组, 栈, 滑动窗口, 计数, 贪心, 链表]
---

{{< markmap >}}
### [1010_总持续时间可被 60 整除的歌曲](#1010)
#### [数组](#1010)
#### [哈希表](#1010)
#### [计数](#1010)
### [1011_在 D 天内送达包裹的能力](#1011)
#### [数组](#1011)
#### [二分查找](#1011)
### [1012_至少有 1 位重复的数字](#1012)
#### [数学](#1012)
#### [动态规划](#1012)
### [1013_将数组分成和相等的三个部分](#1013)
#### [贪心](#1013)
#### [数组](#1013)
### [1014_最佳观光组合](#1014)
#### [数组](#1014)
#### [动态规划](#1014)
### [1015_可被 K 整除的最小整数](#1015)
#### [哈希表](#1015)
#### [数学](#1015)
### [1016_子串能表示从 1 到 N 数字的二进制串](#1016)
#### [位运算](#1016)
#### [哈希表](#1016)
#### [字符串](#1016)
#### [滑动窗口](#1016)
### [1017_负二进制转换](#1017)
#### [数学](#1017)
### [1018_可被 5 整除的二进制前缀](#1018)
#### [位运算](#1018)
#### [数组](#1018)
### [1019_链表中的下一个更大节点](#1019)
#### [栈](#1019)
#### [数组](#1019)
#### [链表](#1019)
#### [单调栈](#1019)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1010_总持续时间可被 60 整除的歌曲
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1011_在 D 天内送达包裹的能力
___
#### 数组
___
#### 二分查找
---
### 1012_至少有 1 位重复的数字
___
#### 数学
___
#### 动态规划
---
### 1013_将数组分成和相等的三个部分
___
#### 贪心
___
#### 数组
---
### 1014_最佳观光组合
___
#### 数组
___
#### 动态规划
---
### 1015_可被 K 整除的最小整数
___
#### 哈希表
___
#### 数学
---
### 1016_子串能表示从 1 到 N 数字的二进制串
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 1017_负二进制转换
___
#### 数学
---
### 1018_可被 5 整除的二进制前缀
___
#### 位运算
___
#### 数组
---
### 1019_链表中的下一个更大节点
___
#### 栈
___
#### 数组
___
#### 链表
___
#### 单调栈
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 哈希表 | 字符串 |
| 数学 | 数组 | 栈 |
| 滑动窗口 | 计数 | 贪心 |
| 链表 |  |  |

# [1010. 总持续时间可被 60 整除的歌曲](https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60){#1010}

{{< tabs "1010" >}}

{{% tab "python" %}}
```python
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in time:
            x %= 60
            y = (60 - x) % 60
            ans += cnt[y]
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        int ans = 0;
        for (int x : time) {
            x %= 60;
            int y = (60 - x) % 60;
            ans += cnt[y];
            ++cnt[x];
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
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60]{};
        int ans = 0;
        for (int x : time) {
            x %= 60;
            int y = (60 - x) % 60;
            ans += cnt[y];
            ++cnt[x];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numPairsDivisibleBy60(time []int) (ans int) {
	cnt := [60]int{}
	for _, x := range time {
		x %= 60
		y := (60 - x) % 60
		ans += cnt[y]
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numPairsDivisibleBy60(time: number[]): number {
    const cnt: number[] = new Array(60).fill(0);
    let ans: number = 0;
    for (let x of time) {
        x %= 60;
        const y = (60 - x) % 60;
        ans += cnt[y];
        ++cnt[x];
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

<p>在歌曲列表中，第 <code>i</code> 首歌曲的持续时间为 <code>time[i]</code> 秒。</p>

<p>返回其总持续时间（以秒为单位）可被 <code>60</code> 整除的歌曲对的数量。形式上，我们希望下标数字 <code>i</code> 和 <code>j</code> 满足&nbsp; <code>i &lt; j</code> 且有&nbsp;<code>(time[i] + time[j]) % 60 == 0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>time = [30,20,150,100,40]
<strong>输出：</strong>3
<strong>解释：</strong>这三对的总持续时间可被 60 整除：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>time = [60,60,60]
<strong>输出：</strong>3
<strong>解释：</strong>所有三对的总持续时间都是 120，可以被 60 整除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 6 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 计数

如果一个数对 $(a, b)$ 之和能被 $60$ 整除，即 $(a + b) \bmod 60 = 0$，那么 $(a \bmod 60 + b \bmod 60) \bmod 60 = 0$，不妨记 $x=a \bmod 60$, $y = b \bmod 60$，那么有 $(x + y) \bmod 60 = 0$，即 $y=(60 - x) \bmod 60$。

因此，我们可以遍历歌曲列表，用一个长度为 $60$ 的数组 $cnt$ 记录每个余数 $x$ 出现的次数。对于当前的 $x$，如果数组 $cnt$ 中存在余数 $y = (60 - x) \bmod 60$，那么将 $cnt[y]$ 累加进答案中。然后，将 $x$ 在数组 $cnt$ 中的出现次数加 $1$。继续遍历，直到遍历完整个歌曲列表。

遍历结束后，即可得到满足条件的歌曲对数目。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是歌曲列表的长度；而 $C$ 是余数的可能取值，这里 $C=60$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = Counter(t % 60 for t in time)
        ans = sum(cnt[x] * cnt[60 - x] for x in range(1, 30))
        ans += cnt[0] * (cnt[0] - 1) // 2
        ans += cnt[30] * (cnt[30] - 1) // 2
        return ans
```

#### Java

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        for (int t : time) {
            ++cnt[t % 60];
        }
        int ans = 0;
        for (int x = 1; x < 30; ++x) {
            ans += cnt[x] * cnt[60 - x];
        }
        ans += (long) cnt[0] * (cnt[0] - 1) / 2;
        ans += (long) cnt[30] * (cnt[30] - 1) / 2;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60]{};
        for (int& t : time) {
            ++cnt[t % 60];
        }
        int ans = 0;
        for (int x = 1; x < 30; ++x) {
            ans += cnt[x] * cnt[60 - x];
        }
        ans += 1LL * cnt[0] * (cnt[0] - 1) / 2;
        ans += 1LL * cnt[30] * (cnt[30] - 1) / 2;
        return ans;
    }
};
```

#### Go

```go
func numPairsDivisibleBy60(time []int) (ans int) {
	cnt := [60]int{}
	for _, t := range time {
		cnt[t%60]++
	}
	for x := 1; x < 30; x++ {
		ans += cnt[x] * cnt[60-x]
	}
	ans += cnt[0] * (cnt[0] - 1) / 2
	ans += cnt[30] * (cnt[30] - 1) / 2
	return
}
```

#### TypeScript

```ts
function numPairsDivisibleBy60(time: number[]): number {
    const cnt: number[] = new Array(60).fill(0);
    for (const t of time) {
        ++cnt[t % 60];
    }
    let ans = 0;
    for (let x = 1; x < 30; ++x) {
        ans += cnt[x] * cnt[60 - x];
    }
    ans += (cnt[0] * (cnt[0] - 1)) / 2;
    ans += (cnt[30] * (cnt[30] - 1)) / 2;
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
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in time:
            x %= 60
            y = (60 - x) % 60
            ans += cnt[y]
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        int ans = 0;
        for (int x : time) {
            x %= 60;
            int y = (60 - x) % 60;
            ans += cnt[y];
            ++cnt[x];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[60]{};
        int ans = 0;
        for (int x : time) {
            x %= 60;
            int y = (60 - x) % 60;
            ans += cnt[y];
            ++cnt[x];
        }
        return ans;
    }
};
```

#### Go

```go
func numPairsDivisibleBy60(time []int) (ans int) {
	cnt := [60]int{}
	for _, x := range time {
		x %= 60
		y := (60 - x) % 60
		ans += cnt[y]
		cnt[x]++
	}
	return
}
```

#### TypeScript

```ts
function numPairsDivisibleBy60(time: number[]): number {
    const cnt: number[] = new Array(60).fill(0);
    let ans: number = 0;
    for (let x of time) {
        x %= 60;
        const y = (60 - x) % 60;
        ans += cnt[y];
        ++cnt[x];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1011. 在 D 天内送达包裹的能力](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days){#1011}

{{< tabs "1011" >}}

{{% tab "python" %}}
```python
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def check(mx):
            ws, cnt = 0, 1
            for w in weights:
                ws += w
                if ws > mx:
                    cnt += 1
                    ws = w
            return cnt <= days

        left, right = max(weights), sum(weights) + 1
        return left + bisect_left(range(left, right), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0, right = 0;
        for (int w : weights) {
            left = Math.max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid, weights, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int mx, int[] weights, int days) {
        int ws = 0, cnt = 1;
        for (int w : weights) {
            ws += w;
            if (ws > mx) {
                ws = w;
                ++cnt;
            }
        }
        return cnt <= days;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (auto& w : weights) {
            left = max(left, w);
            right += w;
        }
        auto check = [&](int mx) {
            int ws = 0, cnt = 1;
            for (auto& w : weights) {
                ws += w;
                if (ws > mx) {
                    ws = w;
                    ++cnt;
                }
            }
            return cnt <= days;
        };
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
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shipWithinDays(weights []int, days int) int {
	var left, right int
	for _, w := range weights {
		if left < w {
			left = w
		}
		right += w
	}
	return left + sort.Search(right, func(mx int) bool {
		mx += left
		ws, cnt := 0, 1
		for _, w := range weights {
			ws += w
			if ws > mx {
				ws = w
				cnt++
			}
		}
		return cnt <= days
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shipWithinDays(weights: number[], days: number): number {
    let left = 0;
    let right = 0;
    for (const w of weights) {
        left = Math.max(left, w);
        right += w;
    }
    const check = (mx: number) => {
        let ws = 0;
        let cnt = 1;
        for (const w of weights) {
            ws += w;
            if (ws > mx) {
                ws = w;
                ++cnt;
            }
        }
        return cnt <= days;
    };
    while (left < right) {
        const mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>传送带上的包裹必须在 <code>days</code> 天内从一个港口运送到另一个港口。</p>

<p>传送带上的第 <code>i</code>&nbsp;个包裹的重量为&nbsp;<code>weights[i]</code>。每一天，我们都会按给出重量（<code>weights</code>）的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。</p>

<p>返回能在 <code>days</code> 天内将传送带上的所有包裹送达的船的最低运载能力。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>weights = [1,2,3,4,5,6,7,8,9,10], days = 5
<strong>输出：</strong>15
<strong>解释：</strong>
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>weights = [3,2,2,4,1,4], days = 3
<strong>输出：</strong>6
<strong>解释：</strong>
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>weights = [1,2,3,1,1], days = 4
<strong>输出：</strong>3
<strong>解释：</strong>
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= weights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果运载能力 $x$ 能够在 $days$ 天内运送完所有包裹，那么运载能力 $x + 1$ 也能在 $days$ 天内运送完所有包裹。也即是说，随着运载能力的增加，运送天数只会减少，不会增加。这存在一个单调性，因此我们可以使用二分查找的方法来寻找最小的运载能力。

我们定义二分查找的左边界 $left= \max\limits_{i=0}^{n-1} weights[i]$，右边界 $right = \sum\limits_{i=0}^{n-1} weights[i]$。然后二分枚举运载能力 $x$，判断是否能在 $days$ 天内运送完所有包裹。如果能，那么我们将右边界调整为 $x$，否则将左边界调整为 $x + 1$。

判断是否能在 $days$ 天内运送完所有包裹的方法是，我们从左到右遍历包裹，将当前包裹加入当前运载能力的船上，如果当前船的运载能力超过了 $x$，那么我们将当前包裹放到下一天的船上，同时天数加一。如果天数超过了 $days$，那么我们返回 $false$，否则返回 $true$。

时间复杂度 $O(n \times \log \sum\limits_{i=0}^{n-1} weights[i])$，空间复杂度 $O(1)$。其中 $n$ 为包裹数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def check(mx):
            ws, cnt = 0, 1
            for w in weights:
                ws += w
                if ws > mx:
                    cnt += 1
                    ws = w
            return cnt <= days

        left, right = max(weights), sum(weights) + 1
        return left + bisect_left(range(left, right), True, key=check)
```

#### Java

```java
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0, right = 0;
        for (int w : weights) {
            left = Math.max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid, weights, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int mx, int[] weights, int days) {
        int ws = 0, cnt = 1;
        for (int w : weights) {
            ws += w;
            if (ws > mx) {
                ws = w;
                ++cnt;
            }
        }
        return cnt <= days;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (auto& w : weights) {
            left = max(left, w);
            right += w;
        }
        auto check = [&](int mx) {
            int ws = 0, cnt = 1;
            for (auto& w : weights) {
                ws += w;
                if (ws > mx) {
                    ws = w;
                    ++cnt;
                }
            }
            return cnt <= days;
        };
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
};
```

#### Go

```go
func shipWithinDays(weights []int, days int) int {
	var left, right int
	for _, w := range weights {
		if left < w {
			left = w
		}
		right += w
	}
	return left + sort.Search(right, func(mx int) bool {
		mx += left
		ws, cnt := 0, 1
		for _, w := range weights {
			ws += w
			if ws > mx {
				ws = w
				cnt++
			}
		}
		return cnt <= days
	})
}
```

#### TypeScript

```ts
function shipWithinDays(weights: number[], days: number): number {
    let left = 0;
    let right = 0;
    for (const w of weights) {
        left = Math.max(left, w);
        right += w;
    }
    const check = (mx: number) => {
        let ws = 0;
        let cnt = 1;
        for (const w of weights) {
            ws += w;
            if (ws > mx) {
                ws = w;
                ++cnt;
            }
        }
        return cnt <= days;
    };
    while (left < right) {
        const mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits){#1012}

{{< tabs "1012" >}}

{{% tab "python" %}}
```python
class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool, limit: bool) -> int:
            if i >= len(s):
                return lead ^ 1
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if lead and j == 0:
                    ans += dfs(i + 1, mask, True, False)
                elif mask >> j & 1 ^ 1:
                    ans += dfs(i + 1, mask | 1 << j, False, limit and j == up)
            return ans

        s = str(n)
        return n - dfs(0, 0, True, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int numDupDigitsAtMostN(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][1 << 10];
        return n - dfs(0, 0, true, true);
    }

    private int dfs(int i, int mask, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i][mask] != null) {
            return f[i][mask];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (lead && j == 0) {
                ans += dfs(i + 1, mask, true, false);
            } else if ((mask >> j & 1) == 0) {
                ans += dfs(i + 1, mask | 1 << j, false, limit && j == up);
            }
        }
        if (!lead && !limit) {
            f[i][mask] = ans;
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
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!lead && !limit && f[i][mask] != -1) {
                return f[i][mask];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else if (mask >> j & 1 ^ 1) {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return n - dfs(0, 0, true, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numDupDigitsAtMostN(n int) int {
	s := []byte(strconv.Itoa(n))
	m := len(s)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, 1<<10)
		for j := range f[i] {
			f[i][j] = -1
		}
	}

	var dfs func(i, mask int, lead, limit bool) int
	dfs = func(i, mask int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[i][mask] != -1 {
			return f[i][mask]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if lead && j == 0 {
				ans += dfs(i+1, mask, true, limit && j == up)
			} else if mask>>j&1 == 0 {
				ans += dfs(i+1, mask|(1<<j), false, limit && j == up)
			}
		}
		if !lead && !limit {
			f[i][mask] = ans
		}
		return ans
	}
	return n - dfs(0, 0, true, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numDupDigitsAtMostN(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f = Array.from({ length: m }, () => Array(1 << 10).fill(-1));

    const dfs = (i: number, mask: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i][mask] !== -1) {
            return f[i][mask];
        }
        const up = limit ? parseInt(s[i]) : 9;
        let ans = 0;
        for (let j = 0; j <= up; j++) {
            if (lead && j === 0) {
                ans += dfs(i + 1, mask, true, limit && j === up);
            } else if (((mask >> j) & 1) === 0) {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j === up);
            }
        }
        if (!lead && !limit) {
            f[i][mask] = ans;
        }
        return ans;
    };

    return n - dfs(0, 0, true, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定正整数&nbsp;<code>n</code>，返回在<em>&nbsp;</em><code>[1, n]</code><em>&nbsp;</em>范围内具有 <strong>至少 1 位</strong> 重复数字的正整数的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 20
<strong>输出：</strong>1
<strong>解释：</strong>具有至少 1 位重复数字的正数（&lt;= 20）只有 11 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 100
<strong>输出：</strong>10
<strong>解释：</strong>具有至少 1 位重复数字的正数（&lt;= 100）有 11，22，33，44，55，66，77，88，99 和 100 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1000
<strong>输出：</strong>262
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 数位 DP

题目要求统计 $[1,..n]$ 中至少有一位重复的数字的个数，我们可以换一种思路，用一个函数 $f(n)$ 统计 $[1,..n]$ 中没有重复数字的个数，那么答案就是 $n - f(n)$。

另外，我们可以用一个二进制数来记录数字中出现过的数字，比如数字中出现了 $1$, $2$, $4$，那么对应的二进制数就是 $\underline{1}0\underline{1}\underline{1}0$。

接下来，我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

我们将数字 $n$ 转为字符串 $s$，接下来，我们设计一个函数 $\textit{dfs}(i, \textit{mask}, \textit{lead}, \textit{limit})$，其中：

-   数字 $i$ 表示当前处理的数字下标，从 $0$ 开始。
-   数字 $\textit{mask}$ 表示当前数字中出现过的数字，用二进制数表示。其中 $\textit{mask}$ 的二进制的第 $j$ 位为 $1$ 表示数字 $j$ 出现过，为 $0$ 表示数字 $j$ 没有出现过。
-   布尔值 $\textit{lead}$ 表示是否只包含前导零。
-   布尔值 $\textit{limit}$ 表示当前位置是否受到上界的限制。

函数的执行过程如下：

如果 $i$ 大于等于 $m$，说明我们已经处理完了所有的位数，此时如果 $\textit{lead}$ 为真，说明当前的数字是前导零，我们应当返回 $0$；否则，我们应当返回 $1$。

否则，我们计算当前位置的上界 $\textit{up}$，如果 $\textit{limit}$ 为真，则 $up$ 为 $s[i]$ 对应的数字，否则 $up$ 为 $9$。

然后，我们在 $[0, \textit{up}]$ 的范围内枚举当前位置的数字 $j$，如果 $j$ 为 $0$ 且 $\textit{lead}$ 为真，我们递归计算 $\textit{dfs}(i + 1, \textit{mask}, \text{true}, \textit{limit} \wedge j = \textit{up})$；否则，如果 $\textit{mask}$ 的第 $j$ 位为 $0$，我们递归计算 $\textit{dfs}(i + 1, \textit{mask} \,|\, 2^j, \text{false}, \textit{limit} \wedge j = \textit{up})$。累加所有的结果即为答案。

答案为 $n - \textit{dfs}(0, 0, \text{true}, \text{true})$。

时间复杂度 $O(\log n \times 2^D \times D)$，空间复杂度 $O(\log n \times 2^D)$。其中 $D = 10$。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool, limit: bool) -> int:
            if i >= len(s):
                return lead ^ 1
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if lead and j == 0:
                    ans += dfs(i + 1, mask, True, False)
                elif mask >> j & 1 ^ 1:
                    ans += dfs(i + 1, mask | 1 << j, False, limit and j == up)
            return ans

        s = str(n)
        return n - dfs(0, 0, True, True)
```

#### Java

```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int numDupDigitsAtMostN(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][1 << 10];
        return n - dfs(0, 0, true, true);
    }

    private int dfs(int i, int mask, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i][mask] != null) {
            return f[i][mask];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (lead && j == 0) {
                ans += dfs(i + 1, mask, true, false);
            } else if ((mask >> j & 1) == 0) {
                ans += dfs(i + 1, mask | 1 << j, false, limit && j == up);
            }
        }
        if (!lead && !limit) {
            f[i][mask] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ^ 1;
            }
            if (!lead && !limit && f[i][mask] != -1) {
                return f[i][mask];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (lead && j == 0) {
                    ans += dfs(i + 1, mask, true, limit && j == up);
                } else if (mask >> j & 1 ^ 1) {
                    ans += dfs(i + 1, mask | (1 << j), false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return n - dfs(0, 0, true, true);
    }
};
```

#### Go

```go
func numDupDigitsAtMostN(n int) int {
	s := []byte(strconv.Itoa(n))
	m := len(s)
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, 1<<10)
		for j := range f[i] {
			f[i][j] = -1
		}
	}

	var dfs func(i, mask int, lead, limit bool) int
	dfs = func(i, mask int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[i][mask] != -1 {
			return f[i][mask]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if lead && j == 0 {
				ans += dfs(i+1, mask, true, limit && j == up)
			} else if mask>>j&1 == 0 {
				ans += dfs(i+1, mask|(1<<j), false, limit && j == up)
			}
		}
		if !lead && !limit {
			f[i][mask] = ans
		}
		return ans
	}
	return n - dfs(0, 0, true, true)
}
```

#### TypeScript

```ts
function numDupDigitsAtMostN(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f = Array.from({ length: m }, () => Array(1 << 10).fill(-1));

    const dfs = (i: number, mask: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i][mask] !== -1) {
            return f[i][mask];
        }
        const up = limit ? parseInt(s[i]) : 9;
        let ans = 0;
        for (let j = 0; j <= up; j++) {
            if (lead && j === 0) {
                ans += dfs(i + 1, mask, true, limit && j === up);
            } else if (((mask >> j) & 1) === 0) {
                ans += dfs(i + 1, mask | (1 << j), false, limit && j === up);
            }
        }
        if (!lead && !limit) {
            f[i][mask] = ans;
        }
        return ans;
    };

    return n - dfs(0, 0, true, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1013. 将数组分成和相等的三个部分](https://leetcode.cn/problems/partition-array-into-three-parts-with-equal-sum){#1013}

{{< tabs "1013" >}}

{{% tab "python" %}}
```python
class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        s, mod = divmod(sum(arr), 3)
        if mod:
            return False
        cnt = t = 0
        for x in arr:
            t += x
            if t == s:
                cnt += 1
                t = 0
        return cnt >= 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int s = Arrays.stream(arr).sum();
        if (s % 3 != 0) {
            return false;
        }
        s /= 3;
        int cnt = 0, t = 0;
        for (int x : arr) {
            t += x;
            if (t == s) {
                cnt++;
                t = 0;
            }
        }
        return cnt >= 3;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3) {
            return false;
        }
        s /= 3;
        int cnt = 0, t = 0;
        for (int x : arr) {
            t += x;
            if (t == s) {
                t = 0;
                cnt++;
            }
        }
        return cnt >= 3;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canThreePartsEqualSum(arr []int) bool {
	s := 0
	for _, x := range arr {
		s += x
	}
	if s%3 != 0 {
		return false
	}
	s /= 3
	cnt, t := 0, 0
	for _, x := range arr {
		t += x
		if t == s {
			cnt++
			t = 0
		}
	}
	return cnt >= 3
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canThreePartsEqualSum(arr: number[]): boolean {
    let s = arr.reduce((a, b) => a + b);
    if (s % 3) {
        return false;
    }
    s = (s / 3) | 0;
    let [cnt, t] = [0, 0];
    for (const x of arr) {
        t += x;
        if (t == s) {
            cnt++;
            t = 0;
        }
    }
    return cnt >= 3;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum: i32 = arr.iter().sum();
        let s = sum / 3;
        let mod_val = sum % 3;
        if mod_val != 0 {
            return false;
        }

        let mut cnt = 0;
        let mut t = 0;
        for &x in &arr {
            t += x;
            if t == s {
                cnt += 1;
                t = 0;
            }
        }

        cnt >= 3
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code>，只有可以将其划分为三个和相等的 <strong>非空</strong> 部分时才返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>形式上，如果可以找出索引 <code>i + 1 < j</code> 且满足 <code>(arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])</code> 就可以将数组三等分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,2,1,-6,6,-7,9,1,2,0,1]
<strong>输出：</strong>true
<strong>解释：</strong>0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [0,2,1,-6,6,7,9,-1,2,0,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,3,6,5,-2,2,5,1,-9,4]
<strong>输出：</strong>true
<strong>解释：</strong>3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= arr.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> <= arr[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历求和

我们先求出整个数组的和，然后判断和是否能被 3 整除，如果不能，直接返回 $\textit{false}$。

否则，我们记 $\textit{s}$ 表示每部分的和，用一个变量 $\textit{cnt}$ 记录当前已经找到的部分数，另一个变量 $\textit{t}$ 记录当前部分的和。初始时 $\textit{cnt} = 0$, $t = 0$。

然后我们遍历数组，对于每个元素 $x$，我们将 $t$ 加上 $x$，如果 $t$ 等于 $s$，说明找到了一部分，将 $\textit{cnt}$ 加一，然后将 $t$ 置为 0。

最后判断 $\textit{cnt}$ 是否大于等于 3 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        s, mod = divmod(sum(arr), 3)
        if mod:
            return False
        cnt = t = 0
        for x in arr:
            t += x
            if t == s:
                cnt += 1
                t = 0
        return cnt >= 3
```

#### Java

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int s = Arrays.stream(arr).sum();
        if (s % 3 != 0) {
            return false;
        }
        s /= 3;
        int cnt = 0, t = 0;
        for (int x : arr) {
            t += x;
            if (t == s) {
                cnt++;
                t = 0;
            }
        }
        return cnt >= 3;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int s = accumulate(arr.begin(), arr.end(), 0);
        if (s % 3) {
            return false;
        }
        s /= 3;
        int cnt = 0, t = 0;
        for (int x : arr) {
            t += x;
            if (t == s) {
                t = 0;
                cnt++;
            }
        }
        return cnt >= 3;
    }
};
```

#### Go

```go
func canThreePartsEqualSum(arr []int) bool {
	s := 0
	for _, x := range arr {
		s += x
	}
	if s%3 != 0 {
		return false
	}
	s /= 3
	cnt, t := 0, 0
	for _, x := range arr {
		t += x
		if t == s {
			cnt++
			t = 0
		}
	}
	return cnt >= 3
}
```

#### TypeScript

```ts
function canThreePartsEqualSum(arr: number[]): boolean {
    let s = arr.reduce((a, b) => a + b);
    if (s % 3) {
        return false;
    }
    s = (s / 3) | 0;
    let [cnt, t] = [0, 0];
    for (const x of arr) {
        t += x;
        if (t == s) {
            cnt++;
            t = 0;
        }
    }
    return cnt >= 3;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum: i32 = arr.iter().sum();
        let s = sum / 3;
        let mod_val = sum % 3;
        if mod_val != 0 {
            return false;
        }

        let mut cnt = 0;
        let mut t = 0;
        for &x in &arr {
            t += x;
            if t == s {
                cnt += 1;
                t = 0;
            }
        }

        cnt >= 3
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1014. 最佳观光组合](https://leetcode.cn/problems/best-sightseeing-pair){#1014}

{{< tabs "1014" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        ans = mx = 0
        for j, x in enumerate(values):
            ans = max(ans, mx + x - j)
            mx = max(mx, x + j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = 0, mx = 0;
        for (int j = 0; j < values.length; ++j) {
            ans = Math.max(ans, mx + values[j] - j);
            mx = Math.max(mx, values[j] + j);
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
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = 0;
        for (int j = 0; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScoreSightseeingPair(values []int) (ans int) {
	mx := 0
	for j, x := range values {
		ans = max(ans, mx+x-j)
		mx = max(mx, x+j)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScoreSightseeingPair(values: number[]): number {
    let [ans, mx] = [0, 0];
    for (let j = 0; j < values.length; ++j) {
        ans = Math.max(ans, mx + values[j] - j);
        mx = Math.max(mx, values[j] + j);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for (j, &x) in values.iter().enumerate() {
            ans = ans.max(mx + x - j as i32);
            mx = mx.max(x + j as i32);
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

<p>给你一个正整数数组 <code>values</code>，其中 <code>values[i]</code> 表示第 <code>i</code> 个观光景点的评分，并且两个景点 <code>i</code> 和 <code>j</code> 之间的 <strong>距离</strong> 为 <code>j - i</code>。</p>

<p>一对景点（<code>i < j</code>）组成的观光组合的得分为 <code>values[i] + values[j] + i - j</code> ，也就是景点的评分之和<strong> 减去 </strong>它们两者之间的距离。</p>

<p>返回一对观光景点能取得的最高分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>values = [8,1,5,2,6]
<strong>输出：</strong>11
<strong>解释：</strong>i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2]
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= values.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>1 <= values[i] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以从左到右枚举 $j$，同时维护 $j$ 左侧元素中 $values[i] + i$ 的最大值 $mx$，这样对于每个 $j$，最大得分为 $mx + values[j] - j$。我们取所有位置的最大得分的最大值即为答案。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{values}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        ans = mx = 0
        for j, x in enumerate(values):
            ans = max(ans, mx + x - j)
            mx = max(mx, x + j)
        return ans
```

#### Java

```java
class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = 0, mx = 0;
        for (int j = 0; j < values.length; ++j) {
            ans = Math.max(ans, mx + values[j] - j);
            mx = Math.max(mx, values[j] + j);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, mx = 0;
        for (int j = 0; j < values.size(); ++j) {
            ans = max(ans, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }
        return ans;
    }
};
```

#### Go

```go
func maxScoreSightseeingPair(values []int) (ans int) {
	mx := 0
	for j, x := range values {
		ans = max(ans, mx+x-j)
		mx = max(mx, x+j)
	}
	return
}
```

#### TypeScript

```ts
function maxScoreSightseeingPair(values: number[]): number {
    let [ans, mx] = [0, 0];
    for (let j = 0; j < values.length; ++j) {
        ans = Math.max(ans, mx + values[j] - j);
        mx = Math.max(mx, values[j] + j);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for (j, &x) in values.iter().enumerate() {
            ans = ans.max(mx + x - j as i32);
            mx = mx.max(x + j as i32);
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

# [1015. 可被 K 整除的最小整数](https://leetcode.cn/problems/smallest-integer-divisible-by-k){#1015}

{{< tabs "1015" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        n = 1 % k
        for i in range(1, k + 1):
            if n == 0:
                return i
            n = (n * 10 + 1) % k
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestRepunitDivByK(int k) {
        int n = 1 % k;
        for (int i = 1; i <= k; ++i) {
            if (n == 0) {
                return i;
            }
            n = (n * 10 + 1) % k;
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
    int smallestRepunitDivByK(int k) {
        int n = 1 % k;
        for (int i = 1; i <= k; ++i) {
            if (n == 0) {
                return i;
            }
            n = (n * 10 + 1) % k;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestRepunitDivByK(k int) int {
	n := 1 % k
	for i := 1; i <= k; i++ {
		if n == 0 {
			return i
		}
		n = (n*10 + 1) % k
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestRepunitDivByK(k: number): number {
    let n = 1 % k;
    for (let i = 1; i <= k; ++i) {
        if (n === 0) {
            return i;
        }
        n = (n * 10 + 1) % k;
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定正整数 <code>k</code>&nbsp;，你需要找出可以被 <code>k</code>&nbsp;整除的、仅包含数字 <code><strong>1</strong></code> 的最 <strong>小</strong> 正整数 <code>n</code>&nbsp;的长度。</p>

<p>返回 <code>n</code>&nbsp;的长度。如果不存在这样的 <code>n</code>&nbsp;，就返回-1。</p>

<p><strong>注意：</strong> <code>n</code> 可能不符合 64 位带符号整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 1
<strong>输出：</strong>1
<strong>解释：</strong>最小的答案是 n = 1，其长度为 1。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 2
<strong>输出：</strong>-1
<strong>解释：</strong>不存在可被 2 整除的正整数 n 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>k = 3
<strong>输出：</strong>3
<strong>解释：</strong>最小的答案是 n = 111，其长度为 3。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们注意到，正整数 $n$ 初始值为 $1$，每次乘以 $10$ 后再加 $1$，即 $n = n \times 10 + 1$，而 $(n \times 10 + 1) \bmod k = ((n \bmod k) \times 10 + 1) \bmod k$，因此我们可以通过计算 $n \bmod k$ 来判断 $n$ 是否能被 $k$ 整除。

我们从 $n = 1$ 开始，每次计算 $n \bmod k$，直到 $n \bmod k = 0$，此时 $n$ 就是我们要求的最小正整数，其长度即为 $n$ 的位数。否则，我们更新 $n = (n \times 10 + 1) \bmod k$。如果循环 $k$ 次后，仍然没有找到 $n \bmod k = 0$，则说明不存在这样的 $n$，返回 $-1$。

时间复杂度 $O(k)$，空间复杂度 $O(1)$。其中 $k$ 为给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        n = 1 % k
        for i in range(1, k + 1):
            if n == 0:
                return i
            n = (n * 10 + 1) % k
        return -1
```

#### Java

```java
class Solution {
    public int smallestRepunitDivByK(int k) {
        int n = 1 % k;
        for (int i = 1; i <= k; ++i) {
            if (n == 0) {
                return i;
            }
            n = (n * 10 + 1) % k;
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 1 % k;
        for (int i = 1; i <= k; ++i) {
            if (n == 0) {
                return i;
            }
            n = (n * 10 + 1) % k;
        }
        return -1;
    }
};
```

#### Go

```go
func smallestRepunitDivByK(k int) int {
	n := 1 % k
	for i := 1; i <= k; i++ {
		if n == 0 {
			return i
		}
		n = (n*10 + 1) % k
	}
	return -1
}
```

#### TypeScript

```ts
function smallestRepunitDivByK(k: number): number {
    let n = 1 % k;
    for (let i = 1; i <= k; ++i) {
        if (n === 0) {
            return i;
        }
        n = (n * 10 + 1) % k;
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1016. 子串能表示从 1 到 N 数字的二进制串](https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n){#1016}

{{< tabs "1016" >}}

{{% tab "python" %}}
```python
class Solution:
    def queryString(self, s: str, n: int) -> bool:
        if n > 1000:
            return False
        return all(bin(i)[2:] in s for i in range(n, n // 2, -1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean queryString(String s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; i--) {
            if (!s.contains(Integer.toBinaryString(i))) {
                return false;
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
    bool queryString(string s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; --i) {
            string b = bitset<32>(i).to_string();
            b = b.substr(b.find_first_not_of('0'));
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func queryString(s string, n int) bool {
	if n > 1000 {
		return false
	}
	for i := n; i > n/2; i-- {
		if !strings.Contains(s, strconv.FormatInt(int64(i), 2)) {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function queryString(s: string, n: number): boolean {
    if (n > 1000) {
        return false;
    }
    for (let i = n; i > n / 2; --i) {
        if (s.indexOf(i.toString(2)) === -1) {
            return false;
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

<p>给定一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个正整数&nbsp;<code>n</code>，如果对于&nbsp;<code>[1, n]</code>&nbsp;范围内的每个整数，<em>其二进制表示都是&nbsp;<code>s</code> 的 <strong>子字符串</strong> ，就返回 <code>true</code>，否则返回 <code>false</code>&nbsp;</em>。</p>

<p><strong>子字符串</strong>&nbsp;是字符串中连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", n = 3
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0110", n = 4
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code>&nbsp;不是&nbsp;<code>'0'</code>&nbsp;就是&nbsp;<code>'1'</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到，字符串 $s$ 的长度不超过 $1000$，所以字符串 $s$ 能表示不超过 $1000$ 个 二进制整数，因此，如果 $n \gt 1000$，那么 $s$ 肯定不能表示 $[1,.. n]$ 范围内的所有整数的二进制表示。

另外，对于一个整数 $x$，如果 $x$ 的二进制表示是 $s$ 的子串，那么 $\lfloor x / 2 \rfloor$ 的二进制表示也是 $s$ 的子串。因此，我们只需要判断 $[\lfloor n / 2 \rfloor + 1,.. n]$ 范围内的整数的二进制表示是否是 $s$ 的子串即可。

时间复杂度 $O(m^2 \times \log m)$，空间复杂度 $O(\log n)$，其中 $m$ 是字符串 $s$ 的长度，而 $n$ 为题目给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def queryString(self, s: str, n: int) -> bool:
        if n > 1000:
            return False
        return all(bin(i)[2:] in s for i in range(n, n // 2, -1))
```

#### Java

```java
class Solution {
    public boolean queryString(String s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; i--) {
            if (!s.contains(Integer.toBinaryString(i))) {
                return false;
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
    bool queryString(string s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; --i) {
            string b = bitset<32>(i).to_string();
            b = b.substr(b.find_first_not_of('0'));
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func queryString(s string, n int) bool {
	if n > 1000 {
		return false
	}
	for i := n; i > n/2; i-- {
		if !strings.Contains(s, strconv.FormatInt(int64(i), 2)) {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function queryString(s: string, n: number): boolean {
    if (n > 1000) {
        return false;
    }
    for (let i = n; i > n / 2; --i) {
        if (s.indexOf(i.toString(2)) === -1) {
            return false;
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

# [1017. 负二进制转换](https://leetcode.cn/problems/convert-to-base-2){#1017}

{{< tabs "1017" >}}

{{% tab "python" %}}
```python
class Solution:
    def baseNeg2(self, n: int) -> str:
        k = 1
        ans = []
        while n:
            if n % 2:
                ans.append('1')
                n -= k
            else:
                ans.append('0')
            n //= 2
            k *= -1
        return ''.join(ans[::-1]) or '0'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        StringBuilder ans = new StringBuilder();
        while (n != 0) {
            if (n % 2 != 0) {
                ans.append(1);
                n -= k;
            } else {
                ans.append(0);
            }
            k *= -1;
            n /= 2;
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
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        string ans;
        while (n) {
            if (n % 2) {
                ans.push_back('1');
                n -= k;
            } else {
                ans.push_back('0');
            }
            k *= -1;
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func baseNeg2(n int) string {
	if n == 0 {
		return "0"
	}
	ans := []byte{}
	k := 1
	for n != 0 {
		if n%2 != 0 {
			ans = append(ans, '1')
			n -= k
		} else {
			ans = append(ans, '0')
		}
		k *= -1
		n /= 2
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
function baseNeg2(n: number): string {
    if (n === 0) {
        return '0';
    }
    let k = 1;
    const ans: string[] = [];
    while (n) {
        if (n % 2) {
            ans.push('1');
            n -= k;
        } else {
            ans.push('0');
        }
        k *= -1;
        n /= 2;
    }
    return ans.reverse().join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn base_neg2(n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }
        let mut k = 1;
        let mut ans = String::new();
        let mut num = n;
        while num != 0 {
            if num % 2 != 0 {
                ans.push('1');
                num -= k;
            } else {
                ans.push('0');
            }
            k *= -1;
            num /= 2;
        }
        ans.chars().rev().collect::<String>()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string BaseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        StringBuilder ans = new StringBuilder();
        int num = n;
        while (num != 0) {
            if (num % 2 != 0) {
                ans.Append('1');
                num -= k;
            } else {
                ans.Append('0');
            }
            k *= -1;
            num /= 2;
        }
        char[] cs = ans.ToString().ToCharArray();
        Array.Reverse(cs);
        return new string(cs);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，以二进制字符串的形式返回该整数的 <strong>负二进制（<code>base -2</code>）</strong>表示。</p>

<p><strong>注意，</strong>除非字符串就是&nbsp;<code>"0"</code>，否则返回的字符串中不能含有前导零。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>"110"
<strong>解释：</strong>(-2)<sup>2</sup> + (-2)<sup>1</sup> = 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>"111"
<strong>解释：</strong>(-2)<sup>2</sup> + (-2)<sup>1</sup> + (-2)<sup>0</sup> = 3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>"100"
<strong>解释：</strong>(-2)<sup>2</sup> = 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以判断 $n$ 从低位到高位的每一位，如果该位为 $1$，那么答案的该位为 $1$，否则为 $0$。如果该位为 $1$，那么我们需要将 $n$ 减去 $k$。接下来我们更新 $n = \lfloor n / 2 \rfloor$, $k = -k$。继续判断下一位。

最后，我们将答案反转后返回即可。

时间复杂度 $O(\log n)$，其中 $n$ 为给定的整数。忽略答案的空间消耗，空间复杂度 $O(1)$。

相似题目：

-   [1073. 负二进制数相加](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1073.Adding%20Two%20Negabinary%20Numbers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def baseNeg2(self, n: int) -> str:
        k = 1
        ans = []
        while n:
            if n % 2:
                ans.append('1')
                n -= k
            else:
                ans.append('0')
            n //= 2
            k *= -1
        return ''.join(ans[::-1]) or '0'
```

#### Java

```java
class Solution {
    public String baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        StringBuilder ans = new StringBuilder();
        while (n != 0) {
            if (n % 2 != 0) {
                ans.append(1);
                n -= k;
            } else {
                ans.append(0);
            }
            k *= -1;
            n /= 2;
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        string ans;
        while (n) {
            if (n % 2) {
                ans.push_back('1');
                n -= k;
            } else {
                ans.push_back('0');
            }
            k *= -1;
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func baseNeg2(n int) string {
	if n == 0 {
		return "0"
	}
	ans := []byte{}
	k := 1
	for n != 0 {
		if n%2 != 0 {
			ans = append(ans, '1')
			n -= k
		} else {
			ans = append(ans, '0')
		}
		k *= -1
		n /= 2
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function baseNeg2(n: number): string {
    if (n === 0) {
        return '0';
    }
    let k = 1;
    const ans: string[] = [];
    while (n) {
        if (n % 2) {
            ans.push('1');
            n -= k;
        } else {
            ans.push('0');
        }
        k *= -1;
        n /= 2;
    }
    return ans.reverse().join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn base_neg2(n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }
        let mut k = 1;
        let mut ans = String::new();
        let mut num = n;
        while num != 0 {
            if num % 2 != 0 {
                ans.push('1');
                num -= k;
            } else {
                ans.push('0');
            }
            k *= -1;
            num /= 2;
        }
        ans.chars().rev().collect::<String>()
    }
}
```

#### C#

```cs
public class Solution {
    public string BaseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int k = 1;
        StringBuilder ans = new StringBuilder();
        int num = n;
        while (num != 0) {
            if (num % 2 != 0) {
                ans.Append('1');
                num -= k;
            } else {
                ans.Append('0');
            }
            k *= -1;
            num /= 2;
        }
        char[] cs = ans.ToString().ToCharArray();
        Array.Reverse(cs);
        return new string(cs);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1018. 可被 5 整除的二进制前缀](https://leetcode.cn/problems/binary-prefix-divisible-by-5){#1018}

{{< tabs "1018" >}}

{{% tab "python" %}}
```python
class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        x = 0
        for v in nums:
            x = (x << 1 | v) % 5
            ans.append(x == 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.add(x == 0);
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
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func prefixesDivBy5(nums []int) (ans []bool) {
	x := 0
	for _, v := range nums {
		x = (x<<1 | v) % 5
		ans = append(ans, x == 0)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function prefixesDivBy5(nums: number[]): boolean[] {
    const ans: boolean[] = [];
    let x = 0;
    for (const v of nums) {
        x = ((x << 1) | v) % 5;
        ans.push(x === 0);
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

<p>给定一个二进制数组 <code>nums</code> (&nbsp;<strong>索引从0开始&nbsp;</strong>)。</p>

<p>我们将<code>x<sub>i</sub></code>&nbsp;定义为其二进制表示形式为子数组&nbsp;<code>nums[0..i]</code>&nbsp;(从最高有效位到最低有效位)。</p>

<ul>
	<li>例如，如果 <code>nums =[1,0,1]</code> ，那么&nbsp;<code>x<sub>0</sub>&nbsp;= 1</code>,&nbsp;<code>x<sub>1</sub>&nbsp;= 2</code>, 和&nbsp;<code>x<sub>2</sub>&nbsp;= 5</code>。</li>
</ul>

<p>返回布尔值列表&nbsp;<code>answer</code>，只有当&nbsp;<code>x<sub>i</sub></code><em>&nbsp;</em>可以被 <code>5</code>&nbsp;整除时，答案&nbsp;<code>answer[i]</code> 为&nbsp;<code>true</code>，否则为 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,1]
<strong>输出：</strong>[true,false,false]
<strong>解释：</strong>
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>[false,false,false]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code><sup>&nbsp;</sup></li>
	<li><code>nums[i]</code>&nbsp;仅为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个变量 $x$ 来表示当前的二进制前缀，然后遍历数组 $nums$，对于每个元素 $v$，我们将 $x$ 左移一位，然后加上 $v$，再对 $5$ 取模，判断是否等于 $0$，如果等于 $0$，则说明当前的二进制前缀可以被 $5$ 整除，我们将 $\textit{true}$ 加入答案数组，否则将 $\textit{false}$ 加入答案数组。

时间复杂度 $O(n)$，忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        x = 0
        for v in nums:
            x = (x << 1 | v) % 5
            ans.append(x == 0)
        return ans
```

#### Java

```java
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.add(x == 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (int v : nums) {
            x = (x << 1 | v) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};
```

#### Go

```go
func prefixesDivBy5(nums []int) (ans []bool) {
	x := 0
	for _, v := range nums {
		x = (x<<1 | v) % 5
		ans = append(ans, x == 0)
	}
	return
}
```

#### TypeScript

```ts
function prefixesDivBy5(nums: number[]): boolean[] {
    const ans: boolean[] = [];
    let x = 0;
    for (const v of nums) {
        x = ((x << 1) | v) % 5;
        ans.push(x === 0);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1019. 链表中的下一个更大节点](https://leetcode.cn/problems/next-greater-node-in-linked-list){#1019}

{{< tabs "1019" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        stk = []
        n = len(nums)
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            while stk and stk[-1] <= nums[i]:
                stk.pop()
            if stk:
                ans[i] = stk[-1]
            stk.append(nums[i])
        return ans
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
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        for (; head != null; head = head.next) {
            nums.add(head.val);
        }
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.size();
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() <= nums.get(i)) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                ans[i] = stk.peek();
            }
            stk.push(nums.get(i));
        }
        return ans;
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
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
func nextLargerNodes(head *ListNode) []int {
	nums := []int{}
	for ; head != nil; head = head.Next {
		nums = append(nums, head.Val)
	}
	stk := []int{}
	n := len(nums)
	ans := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && stk[len(stk)-1] <= nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[i] = stk[len(stk)-1]
		}
		stk = append(stk, nums[i])
	}
	return ans
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

function nextLargerNodes(head: ListNode | null): number[] {
    const nums: number[] = [];
    while (head) {
        nums.push(head.val);
        head = head.next;
    }
    const stk: number[] = [];
    const n = nums.length;
    const ans: number[] = Array(n).fill(0);
    for (let i = n - 1; ~i; --i) {
        while (stk.length && stk.at(-1)! <= nums[i]) {
            stk.pop();
        }
        ans[i] = stk.length ? stk.at(-1)! : 0;
        stk.push(nums[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::VecDeque;
impl Solution {
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut nums = Vec::new();
        let mut current = &head;
        while let Some(node) = current {
            nums.push(node.val);
            current = &node.next;
        }

        let mut stk = VecDeque::new();
        let n = nums.len();
        let mut ans = vec![0; n];
        for i in (0..n).rev() {
            while !stk.is_empty() && stk.back().copied().unwrap() <= nums[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                ans[i] = top;
            }
            stk.push_back(nums[i]);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nextLargerNodes = function (head) {
    const nums = [];
    while (head) {
        nums.push(head.val);
        head = head.next;
    }
    const stk = [];
    const n = nums.length;
    const ans = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && stk[stk.length - 1] <= nums[i]) {
            stk.pop();
        }
        ans[i] = stk.length ? stk[stk.length - 1] : 0;
        stk.push(nums[i]);
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为&nbsp;<code>n</code>&nbsp;的链表&nbsp;<code>head</code></p>

<p>对于列表中的每个节点，查找下一个 <strong>更大节点</strong> 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 <strong>严格大于</strong> 它的值。</p>

<p>返回一个整数数组 <code>answer</code> ，其中 <code>answer[i]</code> 是第 <code>i</code> 个节点( <strong>从1开始</strong> )的下一个更大的节点的值。如果第 <code>i</code> 个节点没有下一个更大的节点，设置&nbsp;<code>answer[i] = 0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1019.Next%20Greater%20Node%20In%20Linked%20List/images/linkedlistnext1.jpg" /></p>

<pre>
<strong>输入：</strong>head = [2,1,5]
<strong>输出：</strong>[5,5,0]
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1019.Next%20Greater%20Node%20In%20Linked%20List/images/linkedlistnext2.jpg" /></p>

<pre>
<strong>输入：</strong>head = [2,7,4,3,5]
<strong>输出：</strong>[7,0,5,5,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数为&nbsp;<code>n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

题目要求找到链表中每个节点的下一个更大的节点，即找到链表中每个节点的右边第一个比它大的节点。我们先遍历链表，将链表中的值存入数组 $nums$ 中。那么对于数组 $nums$ 中的每个元素，我们只需要找到它右边第一个比它大的元素即可。求下一个更大的元素的问题可以使用单调栈来解决。

我们从后往前遍历数组 $nums$，维护一个从栈底到栈顶单调递减的栈 $stk$，遍历过程中，如果栈顶元素小于等于当前元素，则循环将栈顶元素出栈，直到栈顶元素大于当前元素或者栈为空。

如果此时栈为空，则说明当前元素没有下一个更大的元素，否则当前元素的下一个更大的元素就是栈顶元素，更新答案数组 $ans$。然后将当前元素入栈，继续遍历。

遍历结束后，返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        stk = []
        n = len(nums)
        ans = [0] * n
        for i in range(n - 1, -1, -1):
            while stk and stk[-1] <= nums[i]:
                stk.pop()
            if stk:
                ans[i] = stk[-1]
            stk.append(nums[i])
        return ans
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
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        for (; head != null; head = head.next) {
            nums.add(head.val);
        }
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.size();
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() <= nums.get(i)) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                ans[i] = stk.peek();
            }
            stk.push(nums.get(i));
        }
        return ans;
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        for (; head; head = head->next) {
            nums.push_back(head->val);
        }
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
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
func nextLargerNodes(head *ListNode) []int {
	nums := []int{}
	for ; head != nil; head = head.Next {
		nums = append(nums, head.Val)
	}
	stk := []int{}
	n := len(nums)
	ans := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && stk[len(stk)-1] <= nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			ans[i] = stk[len(stk)-1]
		}
		stk = append(stk, nums[i])
	}
	return ans
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

function nextLargerNodes(head: ListNode | null): number[] {
    const nums: number[] = [];
    while (head) {
        nums.push(head.val);
        head = head.next;
    }
    const stk: number[] = [];
    const n = nums.length;
    const ans: number[] = Array(n).fill(0);
    for (let i = n - 1; ~i; --i) {
        while (stk.length && stk.at(-1)! <= nums[i]) {
            stk.pop();
        }
        ans[i] = stk.length ? stk.at(-1)! : 0;
        stk.push(nums[i]);
    }
    return ans;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::VecDeque;
impl Solution {
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut nums = Vec::new();
        let mut current = &head;
        while let Some(node) = current {
            nums.push(node.val);
            current = &node.next;
        }

        let mut stk = VecDeque::new();
        let n = nums.len();
        let mut ans = vec![0; n];
        for i in (0..n).rev() {
            while !stk.is_empty() && stk.back().copied().unwrap() <= nums[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                ans[i] = top;
            }
            stk.push_back(nums[i]);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nextLargerNodes = function (head) {
    const nums = [];
    while (head) {
        nums.push(head.val);
        head = head.next;
    }
    const stk = [];
    const n = nums.length;
    const ans = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && stk[stk.length - 1] <= nums[i]) {
            stk.pop();
        }
        ans[i] = stk.length ? stk[stk.length - 1] : 0;
        stk.push(nums[i]);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

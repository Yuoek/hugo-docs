---
title: "2730_找到最长的半重复子字符串"
date: 2025-10-08T18:39:33+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 单调栈, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 最短路, 枚举, 栈, 树状数组, 模拟, 滑动窗口, 矩阵, 线段树, 脑筋急转弯, 贪心]
---

{{< markmap >}}
### [2730_找到最长的半重复子字符串](#2730)
#### [字符串](#2730)
#### [滑动窗口](#2730)
### [2731_移动机器人](#2731)
#### [脑筋急转弯](#2731)
#### [数组](#2731)
#### [前缀和](#2731)
#### [排序](#2731)
### [2732_找到矩阵中的好子集](#2732)
#### [位运算](#2732)
#### [数组](#2732)
#### [哈希表](#2732)
#### [矩阵](#2732)
### [2733_既不是最小值也不是最大值](#2733)
#### [数组](#2733)
#### [排序](#2733)
### [2734_执行子串操作后的字典序最小字符串](#2734)
#### [贪心](#2734)
#### [字符串](#2734)
### [2735_收集巧克力](#2735)
#### [数组](#2735)
#### [枚举](#2735)
### [2736_最大和查询](#2736)
#### [栈](#2736)
#### [树状数组](#2736)
#### [线段树](#2736)
#### [数组](#2736)
#### [二分查找](#2736)
#### [排序](#2736)
#### [单调栈](#2736)
### [2737_找到最近的标记节点 🔒](#2737)
#### [图](#2737)
#### [数组](#2737)
#### [最短路](#2737)
#### [堆（优先队列）](#2737)
### [2738_统计文本中单词的出现次数 🔒](#2738)
#### [数据库](#2738)
### [2739_总行驶距离](#2739)
#### [数学](#2739)
#### [模拟](#2739)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2730_找到最长的半重复子字符串
___
#### 字符串
___
#### 滑动窗口
---
### 2731_移动机器人
___
#### 脑筋急转弯
___
#### 数组
___
#### 前缀和
___
#### 排序
---
### 2732_找到矩阵中的好子集
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 2733_既不是最小值也不是最大值
___
#### 数组
___
#### 排序
---
### 2734_执行子串操作后的字典序最小字符串
___
#### 贪心
___
#### 字符串
---
### 2735_收集巧克力
___
#### 数组
___
#### 枚举
---
### 2736_最大和查询
___
#### 栈
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 排序
___
#### 单调栈
---
### 2737_找到最近的标记节点 🔒
___
#### 图
___
#### 数组
___
#### 最短路
___
#### 堆（优先队列）
---
### 2738_统计文本中单词的出现次数 🔒
___
#### 数据库
---
### 2739_总行驶距离
___
#### 数学
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 单调栈 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 最短路 | 枚举 | 栈 |
| 树状数组 | 模拟 | 滑动窗口 |
| 矩阵 | 线段树 | 脑筋急转弯 |
| 贪心 |  |  |

# [2730. 找到最长的半重复子字符串](https://leetcode.cn/problems/find-the-longest-semi-repetitive-substring){#2730}

{{< tabs "2730" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        cnt = l = 0
        for i in range(1, n):
            cnt += s[i] == s[i - 1]
            if cnt > 1:
                cnt -= s[l] == s[l + 1]
                l += 1
        return n - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s.charAt(i) == s.charAt(i - 1) ? 1 : 0;
            if (cnt > 1) {
                cnt -= s.charAt(l) == s.charAt(++l) ? 1 : 0;
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
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            if (cnt > 1) {
                cnt -= s[l] == s[++l] ? 1 : 0;
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSemiRepetitiveSubstring(s string) (ans int) {
	cnt, l := 0, 0
	for i, c := range s[1:] {
		if byte(c) == s[i] {
			cnt++
		}
		if cnt > 1 {
			if s[l] == s[l+1] {
				cnt--
			}
			l++
		}
	}
	return len(s) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSemiRepetitiveSubstring(s: string): number {
    const n = s.length;
    let [cnt, l] = [0, 0];
    for (let i = 1; i < n; ++i) {
        cnt += s[i] === s[i - 1] ? 1 : 0;
        if (cnt > 1) {
            cnt -= s[l] === s[l + 1] ? 1 : 0;
            ++l;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，这个字符串只包含&nbsp;<code>0</code>&nbsp;到&nbsp;<code>9</code>&nbsp;的数字字符。</p>

<p>如果一个字符串&nbsp;<code>t</code>&nbsp;中至多有一对相邻字符是相等的，那么称这个字符串 <code>t</code> 是 <strong>半重复的</strong>&nbsp;。例如，<code>"0010"</code>&nbsp;、<code>"002020"</code>&nbsp;、<code>"0123"</code>&nbsp;、<code>"2002"</code>&nbsp;和 <code>"54944"</code>&nbsp;是半重复字符串，而 <code>"00101022"</code>&nbsp;（相邻的相同数字对是 00 和 22）和 <code>"1101234883"</code>&nbsp;（相邻的相同数字对是 11 和 88）不是半重复字符串。</p>

<p>请你返回 <code>s</code>&nbsp;中最长 <strong>半重复</strong>&nbsp;<span data-keyword="substring-nonempty">子字符串</span> 的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "52233"</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>最长的半重复子字符串是 "5223"。整个字符串 "52233" 有两个相邻的相同数字对 22 和 33，但最多只能选取一个。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "5494"</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;是一个半重复字符串。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "1111111"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>最长的半重复子字符串是 "11"。子字符串 "111" 有两个相邻的相同数字对，但最多允许选取一个。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '9'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用双指针维护一个区间 $s[j..i]$，使得区间内最多只有一个相邻字符相等，初始时 $j = 0$, $i = 1$。初始化答案 $ans = 1$。

我们用 $cnt$ 记录区间内相邻字符相等的个数，如果 $cnt \gt 1$，那么我们就需要移动左指针 $j$，直到 $cnt \le 1$。每一次，我们更新答案为 $ans = \max(ans, i - j + 1)$。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        ans, n = 1, len(s)
        cnt = j = 0
        for i in range(1, n):
            cnt += s[i] == s[i - 1]
            while cnt > 1:
                cnt -= s[j] == s[j + 1]
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int ans = 1, n = s.length();
        for (int i = 1, j = 0, cnt = 0; i < n; ++i) {
            cnt += s.charAt(i) == s.charAt(i - 1) ? 1 : 0;
            for (; cnt > 1; ++j) {
                cnt -= s.charAt(j) == s.charAt(j + 1) ? 1 : 0;
            }
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, n = s.size();
        for (int i = 1, j = 0, cnt = 0; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            for (; cnt > 1; ++j) {
                cnt -= s[j] == s[j + 1] ? 1 : 0;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func longestSemiRepetitiveSubstring(s string) (ans int) {
	ans = 1
	for i, j, cnt := 1, 0, 0; i < len(s); i++ {
		if s[i] == s[i-1] {
			cnt++
		}
		for ; cnt > 1; j++ {
			if s[j] == s[j+1] {
				cnt--
			}
		}
		ans = max(ans, i-j+1)
	}
	return
}
```

#### TypeScript

```ts
function longestSemiRepetitiveSubstring(s: string): number {
    const n = s.length;
    let ans = 1;
    for (let i = 1, j = 0, cnt = 0; i < n; ++i) {
        cnt += s[i] === s[i - 1] ? 1 : 0;
        for (; cnt > 1; ++j) {
            cnt -= s[j] === s[j + 1] ? 1 : 0;
        }
        ans = Math.max(ans, i - j + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针（优化）

由于题目只需要我们找到最长的半重复子字符串的长度，因此，每次当区间内相邻字符相等的个数超过 $1$ 时，我们可以只移动左指针 $l$ 一次，右指针 $r$ 继续向右移动。这样可以保证子字符串的长度不会减小。

最后答案为 $n - l$，其中 $n$ 是字符串的长度。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        cnt = l = 0
        for i in range(1, n):
            cnt += s[i] == s[i - 1]
            if cnt > 1:
                cnt -= s[l] == s[l + 1]
                l += 1
        return n - l
```

#### Java

```java
class Solution {
    public int longestSemiRepetitiveSubstring(String s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s.charAt(i) == s.charAt(i - 1) ? 1 : 0;
            if (cnt > 1) {
                cnt -= s.charAt(l) == s.charAt(++l) ? 1 : 0;
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
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            if (cnt > 1) {
                cnt -= s[l] == s[++l] ? 1 : 0;
            }
        }
        return n - l;
    }
};
```

#### Go

```go
func longestSemiRepetitiveSubstring(s string) (ans int) {
	cnt, l := 0, 0
	for i, c := range s[1:] {
		if byte(c) == s[i] {
			cnt++
		}
		if cnt > 1 {
			if s[l] == s[l+1] {
				cnt--
			}
			l++
		}
	}
	return len(s) - l
}
```

#### TypeScript

```ts
function longestSemiRepetitiveSubstring(s: string): number {
    const n = s.length;
    let [cnt, l] = [0, 0];
    for (let i = 1; i < n; ++i) {
        cnt += s[i] === s[i - 1] ? 1 : 0;
        if (cnt > 1) {
            cnt -= s[l] === s[l + 1] ? 1 : 0;
            ++l;
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

# [2731. 移动机器人](https://leetcode.cn/problems/movement-of-robots){#2731}

{{< tabs "2731" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        mod = 10**9 + 7
        for i, c in enumerate(s):
            nums[i] += d if c == "R" else -d
        nums.sort()
        ans = s = 0
        for i, x in enumerate(nums):
            ans += i * x - s
            s += x
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumDistance(int[] nums, String s, int d) {
        int n = nums.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = (long) nums[i] + (s.charAt(i) == 'L' ? -d : d);
        }
        Arrays.sort(arr);
        long ans = 0, sum = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + i * arr[i] - sum) % mod;
            sum += arr[i];
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
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = 1LL * nums[i] + (s[i] == 'L' ? -d : d);
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        long long sum = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + i * arr[i] - sum) % mod;
            sum += arr[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumDistance(nums []int, s string, d int) (ans int) {
	for i, c := range s {
		if c == 'R' {
			nums[i] += d
		} else {
			nums[i] -= d
		}
	}
	sort.Ints(nums)
	sum := 0
	const mod int = 1e9 + 7
	for i, x := range nums {
		ans = (ans + i*x - sum) % mod
		sum += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumDistance(nums: number[], s: string, d: number): number {
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        nums[i] += s[i] === 'L' ? -d : d;
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let sum = 0;
    const mod = 1e9 + 7;
    for (let i = 0; i < n; ++i) {
        ans = (ans + i * nums[i] - sum) % mod;
        sum += nums[i];
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

<p>有一些机器人分布在一条无限长的数轴上，他们初始坐标用一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;表示。当你给机器人下达命令时，它们以每秒钟一单位的速度开始移动。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，每个字符按顺序分别表示每个机器人移动的方向。<code>'L'</code>&nbsp;表示机器人往左或者数轴的负方向移动，<code>'R'</code>&nbsp;表示机器人往右或者数轴的正方向移动。</p>

<p>当两个机器人相撞时，它们开始沿着原本相反的方向移动。</p>

<p>请你返回指令重复执行 <code>d</code>&nbsp;秒后，所有机器人之间两两距离之和。由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p><b>注意：</b></p>

<ul>
	<li>对于坐标在&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;的两个机器人，<code>(i,j)</code>&nbsp;和&nbsp;<code>(j,i)</code>&nbsp;视为相同的坐标对。也就是说，机器人视为无差别的。</li>
	<li>当机器人相撞时，它们 <strong>立即改变</strong>&nbsp;它们的前进方向，这个过程不消耗任何时间。</li>
	<li>
	<p>当两个机器人在同一时刻占据相同的位置时，就会相撞。</p>

    <ul>
    	<li>
    	<p>例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 2 并往左移动，下一秒，它们都将占据位置 1，并改变方向。再下一秒钟后，第一个机器人位于位置 0 并往左移动，而另一个机器人位于位置 2 并往右移动。</p>
    	</li>
    	<li>
    	<p>例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 1 并往左移动，下一秒，第一个机器人位于位置 0 并往左行驶，而另一个机器人位于位置 1 并往右移动。</p>
    	</li>
    </ul>
    </li>

</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [-2,0,2], s = "RLL", d = 3
<b>输出：</b>8
<b>解释：</b>
1 秒后，机器人的位置为 [-1,-1,1] 。现在下标为 0 的机器人开始往左移动，下标为 1 的机器人开始往右移动。
2 秒后，机器人的位置为 [-2,0,0] 。现在下标为 1 的机器人开始往左移动，下标为 2 的机器人开始往右移动。
3 秒后，机器人的位置为 [-3,-1,1] 。
下标为 0 和 1 的机器人之间距离为 abs(-3 - (-1)) = 2 。
下标为 0 和 2 的机器人之间的距离为 abs(-3 - 1) = 4 。
下标为 1 和 2 的机器人之间的距离为 abs(-1 - 1) = 2 。
所有机器人对之间的总距离为 2 + 4 + 2 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,0], s = "RL", d = 2
<b>输出：</b>5
<b>解释：</b>
1 秒后，机器人的位置为 [2,-1] 。
2 秒后，机器人的位置为 [3,-2] 。
两个机器人的距离为 abs(-2 - 3) = 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2 * 10<sup>9</sup>&nbsp;&lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li><code>0 &lt;= d &lt;= 10<sup>9</sup></code></li>
	<li><code>nums.length == s.length&nbsp;</code></li>
	<li><code>s</code>&nbsp;只包含&nbsp;<code>'L'</code> 和 <code>'R'</code>&nbsp;。</li>
	<li><code>nums[i]</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯 + 排序

两个机器人相撞后，它们会立即改变方向，实际上相当于两个机器人继续往原来的方向移动。因此，我们遍历数组 $nums$，按照字符串 $s$ 的指令，将每个机器人的位置加上或减去 $d$，然后对数组 $nums$ 进行排序。

接下来，我们从小到大枚举每个机器人的位置，计算出当前机器人与前面所有机器人的距离之和，即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是机器人的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        mod = 10**9 + 7
        for i, c in enumerate(s):
            nums[i] += d if c == "R" else -d
        nums.sort()
        ans = s = 0
        for i, x in enumerate(nums):
            ans += i * x - s
            s += x
        return ans % mod
```

#### Java

```java
class Solution {
    public int sumDistance(int[] nums, String s, int d) {
        int n = nums.length;
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = (long) nums[i] + (s.charAt(i) == 'L' ? -d : d);
        }
        Arrays.sort(arr);
        long ans = 0, sum = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + i * arr[i] - sum) % mod;
            sum += arr[i];
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = 1LL * nums[i] + (s[i] == 'L' ? -d : d);
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        long long sum = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + i * arr[i] - sum) % mod;
            sum += arr[i];
        }
        return ans;
    }
};
```

#### Go

```go
func sumDistance(nums []int, s string, d int) (ans int) {
	for i, c := range s {
		if c == 'R' {
			nums[i] += d
		} else {
			nums[i] -= d
		}
	}
	sort.Ints(nums)
	sum := 0
	const mod int = 1e9 + 7
	for i, x := range nums {
		ans = (ans + i*x - sum) % mod
		sum += x
	}
	return
}
```

#### TypeScript

```ts
function sumDistance(nums: number[], s: string, d: number): number {
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        nums[i] += s[i] === 'L' ? -d : d;
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let sum = 0;
    const mod = 1e9 + 7;
    for (let i = 0; i < n; ++i) {
        ans = (ans + i * nums[i] - sum) % mod;
        sum += nums[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2732. 找到矩阵中的好子集](https://leetcode.cn/problems/find-a-good-subset-of-the-matrix){#2732}

{{< tabs "2732" >}}

{{% tab "python" %}}
```python
class Solution:
    def goodSubsetofBinaryMatrix(self, grid: List[List[int]]) -> List[int]:
        g = {}
        for i, row in enumerate(grid):
            mask = 0
            for j, x in enumerate(row):
                mask |= x << j
            if mask == 0:
                return [i]
            g[mask] = i
        for a, i in g.items():
            for b, j in g.items():
                if (a & b) == 0:
                    return sorted([i, j])
        return []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        Map<Integer, Integer> g = new HashMap<>();
        for (int i = 0; i < grid.length; ++i) {
            int mask = 0;
            for (int j = 0; j < grid[0].length; ++j) {
                mask |= grid[i][j] << j;
            }
            if (mask == 0) {
                return List.of(i);
            }
            g.put(mask, i);
        }
        for (var e1 : g.entrySet()) {
            for (var e2 : g.entrySet()) {
                if ((e1.getKey() & e2.getKey()) == 0) {
                    int i = e1.getValue(), j = e2.getValue();
                    return List.of(Math.min(i, j), Math.max(i, j));
                }
            }
        }
        return List.of();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> g;
        for (int i = 0; i < grid.size(); ++i) {
            int mask = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                mask |= grid[i][j] << j;
            }
            if (mask == 0) {
                return {i};
            }
            g[mask] = i;
        }
        for (auto& [a, i] : g) {
            for (auto& [b, j] : g) {
                if ((a & b) == 0) {
                    return {min(i, j), max(i, j)};
                }
            }
        }
        return {};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func goodSubsetofBinaryMatrix(grid [][]int) []int {
	g := map[int]int{}
	for i, row := range grid {
		mask := 0
		for j, x := range row {
			mask |= x << j
		}
		if mask == 0 {
			return []int{i}
		}
		g[mask] = i
	}
	for a, i := range g {
		for b, j := range g {
			if a&b == 0 {
				return []int{min(i, j), max(i, j)}
			}
		}
	}
	return []int{}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function goodSubsetofBinaryMatrix(grid: number[][]): number[] {
    const g: Map<number, number> = new Map();
    const m = grid.length;
    const n = grid[0].length;
    for (let i = 0; i < m; ++i) {
        let mask = 0;
        for (let j = 0; j < n; ++j) {
            mask |= grid[i][j] << j;
        }
        if (!mask) {
            return [i];
        }
        g.set(mask, i);
    }
    for (const [a, i] of g.entries()) {
        for (const [b, j] of g.entries()) {
            if ((a & b) === 0) {
                return [Math.min(i, j), Math.max(i, j)];
            }
        }
    }
    return [];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn good_subsetof_binary_matrix(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut g: HashMap<i32, i32> = HashMap::new();
        for (i, row) in grid.iter().enumerate() {
            let mut mask = 0;
            for (j, &x) in row.iter().enumerate() {
                mask |= x << j;
            }
            if mask == 0 {
                return vec![i as i32];
            }
            g.insert(mask, i as i32);
        }

        for (&a, &i) in g.iter() {
            for (&b, &j) in g.iter() {
                if (a & b) == 0 {
                    return vec![i.min(j), i.max(j)];
                }
            }
        }

        vec![]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>从原矩阵中选出若干行构成一个行的 <strong>非空&nbsp;</strong>子集，如果子集中任何一列的和至多为子集大小的一半，那么我们称这个子集是 <strong>好子集</strong>。</p>

<p>更正式的，如果选出来的行子集大小（即行的数量）为 k，那么每一列的和至多为&nbsp;<code>floor(k / 2)</code>&nbsp;。</p>

<p>请你返回一个整数数组，它包含好子集的行下标，请你将其&nbsp;<b>升序</b>&nbsp;返回。</p>

<p>如果有多个好子集，你可以返回任意一个。如果没有好子集，请你返回一个空数组。</p>

<p>一个矩阵 <code>grid</code>&nbsp;的行 <strong>子集</strong> ，是删除 <code>grid</code>&nbsp;中某些（也可能不删除）行后，剩余行构成的元素集合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
<b>输出：</b>[0,1]
<b>解释：</b>我们可以选择第 0 和第 1 行构成一个好子集。
选出来的子集大小为 2 。
- 第 0&nbsp;列的和为 0 + 0 = 0 ，小于等于子集大小的一半。
- 第 1&nbsp;列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
- 第 2&nbsp;列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
- 第 3&nbsp;列的和为 0 + 1 = 1 ，小于等于子集大小的一半。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>grid = [[0]]
<b>输出：</b>[0]
<strong>解释：</strong>我们可以选择第 0 行构成一个好子集。
选出来的子集大小为 1 。
- 第 0 列的和为 0 ，小于等于子集大小的一半。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>grid = [[1,1,1],[1,1,1]]
<b>输出：</b>[]
<b>解释：</b>没有办法得到一个好子集。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= n &lt;= 5</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

我们可以从小到大考虑答案选择的行数 $k$。

-   如果 $k = 1$，每一列的和最大为 $0$，那么必须满足有一行的所有元素都是 $0$，否则无法满足条件。
-   如果 $k = 2$，每一列的和最大为 $1$，那么必须存在有两行，且这两行的元素按位与之后的结果是 $0$，否则无法满足条件。
-   如果 $k = 3$，每一列的和最大也是 $1$。如果 $k = 2$ 不满足条件，那么 $k = 3$ 也一定不满足条件，所以我们不需要考虑所有 $k \gt 2$ 且 $k$ 为奇数的情况。
-   如果 $k = 4$，每一列的和最大为 $2$，此时一定是 $k = 2$ 不满足条件，也就是说，任意选取两行，都存在至少一个列的和为 $2$。我们在 $4$ 行中任意选取 $2$ 行，一共有 $C_4^2 = 6$ 种选法，那么存在至少 $6$ 个 $2$ 的列。由于列数 $n \le 5$，所以一定存在至少一列的和大于 $2$，所以 $k = 4$ 也不满足条件。
-   对于 $k \gt 4$ 且 $k$ 为偶数的情况，我们可以得出同样的结论，即 $k$ 一定不满足条件。

综上所述，我们只需要考虑 $k = 1$ 和 $k = 2$ 的情况即可。即判断是否有一行全为 $0$，或者是否存在两行按位与之后的结果为 $0$。

时间复杂度 $O(m \times n + 4^n)$，空间复杂度 $O(2^n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def goodSubsetofBinaryMatrix(self, grid: List[List[int]]) -> List[int]:
        g = {}
        for i, row in enumerate(grid):
            mask = 0
            for j, x in enumerate(row):
                mask |= x << j
            if mask == 0:
                return [i]
            g[mask] = i
        for a, i in g.items():
            for b, j in g.items():
                if (a & b) == 0:
                    return sorted([i, j])
        return []
```

#### Java

```java
class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        Map<Integer, Integer> g = new HashMap<>();
        for (int i = 0; i < grid.length; ++i) {
            int mask = 0;
            for (int j = 0; j < grid[0].length; ++j) {
                mask |= grid[i][j] << j;
            }
            if (mask == 0) {
                return List.of(i);
            }
            g.put(mask, i);
        }
        for (var e1 : g.entrySet()) {
            for (var e2 : g.entrySet()) {
                if ((e1.getKey() & e2.getKey()) == 0) {
                    int i = e1.getValue(), j = e2.getValue();
                    return List.of(Math.min(i, j), Math.max(i, j));
                }
            }
        }
        return List.of();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> g;
        for (int i = 0; i < grid.size(); ++i) {
            int mask = 0;
            for (int j = 0; j < grid[0].size(); ++j) {
                mask |= grid[i][j] << j;
            }
            if (mask == 0) {
                return {i};
            }
            g[mask] = i;
        }
        for (auto& [a, i] : g) {
            for (auto& [b, j] : g) {
                if ((a & b) == 0) {
                    return {min(i, j), max(i, j)};
                }
            }
        }
        return {};
    }
};
```

#### Go

```go
func goodSubsetofBinaryMatrix(grid [][]int) []int {
	g := map[int]int{}
	for i, row := range grid {
		mask := 0
		for j, x := range row {
			mask |= x << j
		}
		if mask == 0 {
			return []int{i}
		}
		g[mask] = i
	}
	for a, i := range g {
		for b, j := range g {
			if a&b == 0 {
				return []int{min(i, j), max(i, j)}
			}
		}
	}
	return []int{}
}
```

#### TypeScript

```ts
function goodSubsetofBinaryMatrix(grid: number[][]): number[] {
    const g: Map<number, number> = new Map();
    const m = grid.length;
    const n = grid[0].length;
    for (let i = 0; i < m; ++i) {
        let mask = 0;
        for (let j = 0; j < n; ++j) {
            mask |= grid[i][j] << j;
        }
        if (!mask) {
            return [i];
        }
        g.set(mask, i);
    }
    for (const [a, i] of g.entries()) {
        for (const [b, j] of g.entries()) {
            if ((a & b) === 0) {
                return [Math.min(i, j), Math.max(i, j)];
            }
        }
    }
    return [];
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn good_subsetof_binary_matrix(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut g: HashMap<i32, i32> = HashMap::new();
        for (i, row) in grid.iter().enumerate() {
            let mut mask = 0;
            for (j, &x) in row.iter().enumerate() {
                mask |= x << j;
            }
            if mask == 0 {
                return vec![i as i32];
            }
            g.insert(mask, i as i32);
        }

        for (&a, &i) in g.iter() {
            for (&b, &j) in g.iter() {
                if (a & b) == 0 {
                    return vec![i.min(j), i.max(j)];
                }
            }
        }

        vec![]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2733. 既不是最小值也不是最大值](https://leetcode.cn/problems/neither-minimum-nor-maximum){#2733}

{{< tabs "2733" >}}

{{% tab "python" %}}
```python
class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        for x in nums:
            if x != mi and x != mx:
                return x
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findNonMinOrMax(int[] nums) {
        int mi = 100, mx = 0;
        for (int x : nums) {
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        for (int x : nums) {
            if (x != mi && x != mx) {
                return x;
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
    int findNonMinOrMax(vector<int>& nums) {
        auto [mi, mx] = minmax_element(nums.begin(), nums.end());
        for (int x : nums) {
            if (x != *mi && x != *mx) {
                return x;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findNonMinOrMax(nums []int) int {
	mi, mx := slices.Min(nums), slices.Max(nums)
	for _, x := range nums {
		if x != mi && x != mx {
			return x
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_non_min_or_max(nums: Vec<i32>) -> i32 {
        let mut mi = 100;
        let mut mx = 0;

        for &ele in nums.iter() {
            if ele < mi {
                mi = ele;
            }
            if ele > mx {
                mx = ele;
            }
        }

        for &ele in nums.iter() {
            if ele != mi && ele != mx {
                return ele;
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

<p>给你一个整数数组 <code>nums</code> ，数组由 <strong>不同正整数</strong> 组成，请你找出并返回数组中 <strong>任一</strong> 既不是 <strong>最小值</strong> 也不是 <strong>最大值</strong> 的数字，如果不存在这样的数字，返回 <strong><code>-1</code></strong> 。</p>

<p>返回所选整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,1,4]
<strong>输出：</strong>2
<strong>解释：</strong>在这个示例中，最小值是 1 ，最大值是 4 。因此，2 或 3 都是有效答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2]
<strong>输出：</strong>-1
<strong>解释：</strong>由于不存在既不是最大值也不是最小值的数字，我们无法选出满足题目给定条件的数字。因此，不存在答案，返回 -1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>2
<strong>解释：</strong>2 既不是最小值，也不是最大值，这个示例只有这一个有效答案。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code> 中的所有数字互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以先找到数组中的最小值和最大值，分别记为 $mi$ 和 $mx$。然后遍历数组，找到第一个不等于 $mi$ 且不等于 $mx$ 的数字，返回即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        return next((x for x in nums if x != mi and x != mx), -1)
```

#### Java

```java
class Solution {
    public int findNonMinOrMax(int[] nums) {
        int mi = 100, mx = 0;
        for (int x : nums) {
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        for (int x : nums) {
            if (x != mi && x != mx) {
                return x;
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
    int findNonMinOrMax(vector<int>& nums) {
        auto [mi, mx] = minmax_element(nums.begin(), nums.end());
        for (int x : nums) {
            if (x != *mi && x != *mx) {
                return x;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func findNonMinOrMax(nums []int) int {
	mi, mx := slices.Min(nums), slices.Max(nums)
	for _, x := range nums {
		if x != mi && x != mx {
			return x
		}
	}
	return -1
}
```

#### Rust

```rust
impl Solution {
    pub fn find_non_min_or_max(nums: Vec<i32>) -> i32 {
        let mut mi = 100;
        let mut mx = 0;

        for &ele in nums.iter() {
            if ele < mi {
                mi = ele;
            }
            if ele > mx {
                mx = ele;
            }
        }

        for &ele in nums.iter() {
            if ele != mi && ele != mx {
                return ele;
            }
        }

        -1
    }
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
    def findNonMinOrMax(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        for x in nums:
            if x != mi and x != mx:
                return x
        return -1
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2734. 执行子串操作后的字典序最小字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation){#2734}

{{< tabs "2734" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestString(self, s: str) -> str:
        n = len(s)
        i = 0
        while i < n and s[i] == "a":
            i += 1
        if i == n:
            return s[:-1] + "z"
        j = i
        while j < n and s[j] != "a":
            j += 1
        return s[:i] + "".join(chr(ord(c) - 1) for c in s[i:j]) + s[j:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String smallestString(String s) {
        int n = s.length();
        int i = 0;
        while (i < n && s.charAt(i) == 'a') {
            ++i;
        }
        if (i == n) {
            return s.substring(0, n - 1) + "z";
        }
        int j = i;
        char[] cs = s.toCharArray();
        while (j < n && cs[j] != 'a') {
            cs[j] = (char) (cs[j] - 1);
            ++j;
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a') {
            ++i;
        }
        if (i == n) {
            s[n - 1] = 'z';
            return s;
        }
        int j = i;
        while (j < n && s[j] != 'a') {
            s[j] = s[j] - 1;
            ++j;
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestString(s string) string {
	n := len(s)
	i := 0
	for i < n && s[i] == 'a' {
		i++
	}
	cs := []byte(s)
	if i == n {
		cs[n-1] = 'z'
		return string(cs)
	}
	j := i
	for j < n && cs[j] != 'a' {
		cs[j] = cs[j] - 1
		j++
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestString(s: string): string {
    const cs: string[] = s.split('');
    const n: number = cs.length;
    let i: number = 0;
    while (i < n && cs[i] === 'a') {
        i++;
    }

    if (i === n) {
        cs[n - 1] = 'z';
        return cs.join('');
    }

    let j: number = i;
    while (j < n && cs[j] !== 'a') {
        const c: number = cs[j].charCodeAt(0);
        cs[j] = String.fromCharCode(c - 1);
        j++;
    }

    return cs.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_string(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        let mut i = 0;

        while i < n && cs[i] == 'a' {
            i += 1;
        }

        if i == n {
            cs[n - 1] = 'z';
            return cs.into_iter().collect();
        }

        let mut j = i;
        while j < n && cs[j] != 'a' {
            cs[j] = ((cs[j] as u8) - 1) as char;
            j += 1;
        }

        cs.into_iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。在一步操作中，你可以完成以下行为：</p>

<ul>
	<li>选择&nbsp;<code>s</code> 的任一非空子字符串，可能是整个字符串，接着将字符串中的每一个字符替换为英文字母表中的前一个字符。例如，'b' 用 'a' 替换，'a' 用 'z' 替换。</li>
</ul>

<p>返回执行上述操作 <strong>恰好一次</strong> 后可以获得的 <strong>字典序最小</strong> 的字符串。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>
现有长度相同的两个字符串 <code>x</code> 和 字符串 <code>y</code> ，在满足&nbsp;<code>x[i] != y[i]</code> 的第一个位置 <code>i</code> 上，如果&nbsp; <code>x[i]</code> 在字母表中先于 <code>y[i]</code> 出现，则认为字符串 <code>x</code> 比字符串 <code>y</code> <strong>字典序更小</strong> 。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "cbabc"
<strong>输出：</strong>"baabc"
<strong>解释：</strong>我们选择从下标 0 开始、到下标 1 结束的子字符串执行操作。 
可以证明最终得到的字符串是字典序最小的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "acbbc"
<strong>输出：</strong>"abaab"
<strong>解释：</strong>我们选择从下标 1 开始、到下标 4 结束的子字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>"kddsbncd"
<strong>解释：</strong>我们选择整个字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以从左到右遍历字符串 $s$，找到第一个不是 'a' 的字符所在的位置 $i$，然后找到从 $i$ 开始的第一个 'a' 字符所在的位置 $j$，将 $s[i:j]$ 中的字符都减一，最后返回处理后的字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestString(self, s: str) -> str:
        n = len(s)
        i = 0
        while i < n and s[i] == "a":
            i += 1
        if i == n:
            return s[:-1] + "z"
        j = i
        while j < n and s[j] != "a":
            j += 1
        return s[:i] + "".join(chr(ord(c) - 1) for c in s[i:j]) + s[j:]
```

#### Java

```java
class Solution {
    public String smallestString(String s) {
        int n = s.length();
        int i = 0;
        while (i < n && s.charAt(i) == 'a') {
            ++i;
        }
        if (i == n) {
            return s.substring(0, n - 1) + "z";
        }
        int j = i;
        char[] cs = s.toCharArray();
        while (j < n && cs[j] != 'a') {
            cs[j] = (char) (cs[j] - 1);
            ++j;
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a') {
            ++i;
        }
        if (i == n) {
            s[n - 1] = 'z';
            return s;
        }
        int j = i;
        while (j < n && s[j] != 'a') {
            s[j] = s[j] - 1;
            ++j;
        }
        return s;
    }
};
```

#### Go

```go
func smallestString(s string) string {
	n := len(s)
	i := 0
	for i < n && s[i] == 'a' {
		i++
	}
	cs := []byte(s)
	if i == n {
		cs[n-1] = 'z'
		return string(cs)
	}
	j := i
	for j < n && cs[j] != 'a' {
		cs[j] = cs[j] - 1
		j++
	}
	return string(cs)
}
```

#### TypeScript

```ts
function smallestString(s: string): string {
    const cs: string[] = s.split('');
    const n: number = cs.length;
    let i: number = 0;
    while (i < n && cs[i] === 'a') {
        i++;
    }

    if (i === n) {
        cs[n - 1] = 'z';
        return cs.join('');
    }

    let j: number = i;
    while (j < n && cs[j] !== 'a') {
        const c: number = cs[j].charCodeAt(0);
        cs[j] = String.fromCharCode(c - 1);
        j++;
    }

    return cs.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_string(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        let mut i = 0;

        while i < n && cs[i] == 'a' {
            i += 1;
        }

        if i == n {
            cs[n - 1] = 'z';
            return cs.into_iter().collect();
        }

        let mut j = i;
        while j < n && cs[j] != 'a' {
            cs[j] = ((cs[j] as u8) - 1) as char;
            j += 1;
        }

        cs.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2735. 收集巧克力](https://leetcode.cn/problems/collecting-chocolates){#2735}

{{< tabs "2735" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        for i, v in enumerate(nums):
            f[i][0] = v
            for j in range(1, n):
                f[i][j] = min(f[i][j - 1], nums[(i - j) % n])
        return min(sum(f[i][j] for i in range(n)) + x * j for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minCost(int[] nums, int x) {
        int n = nums.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }
        long ans = 1L << 60;
        for (int j = 0; j < n; ++j) {
            long cost = 1L * x * j;
            for (int i = 0; i < n; ++i) {
                cost += f[i][j];
            }
            ans = Math.min(ans, cost);
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
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        int f[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }
        long long ans = 1LL << 60;
        for (int j = 0; j < n; ++j) {
            long long cost = 1LL * x * j;
            for (int i = 0; i < n; ++i) {
                cost += f[i][j];
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(nums []int, x int) int64 {
	n := len(nums)
	f := make([][]int, n)
	for i, v := range nums {
		f[i] = make([]int, n)
		f[i][0] = v
		for j := 1; j < n; j++ {
			f[i][j] = min(f[i][j-1], nums[(i-j+n)%n])
		}
	}
	ans := 1 << 60
	for j := 0; j < n; j++ {
		cost := x * j
		for i := 0; i < n; i++ {
			cost += f[i][j]
		}
		ans = min(ans, cost)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(nums: number[], x: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][0] = nums[i];
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i][j - 1], nums[(i - j + n) % n]);
        }
    }
    let ans = Infinity;
    for (let j = 0; j < n; ++j) {
        let cost = x * j;
        for (let i = 0; i < n; ++i) {
            cost += f[i][j];
        }
        ans = Math.min(ans, cost);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_cost(nums: Vec<i32>, x: i32) -> i64 {
        let n = nums.len();
        let mut f = vec![vec![0; n]; n];
        for i in 0..n {
            f[i][0] = nums[i];
            for j in 1..n {
                f[i][j] = f[i][j - 1].min(nums[(i - j + n) % n]);
            }
        }
        let mut ans = i64::MAX;
        for j in 0..n {
            let mut cost = (x as i64) * (j as i64);
            for i in 0..n {
                cost += f[i][j] as i64;
            }
            ans = ans.min(cost);
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

<p>给你一个长度为 <code>n</code>、下标从 <strong>0</strong> 开始的整数数组 <code>nums</code>，<code>nums[i]</code> 表示收集位于下标 <code>i</code> 处的巧克力成本。每个巧克力都对应一个不同的类型，最初，位于下标 <code>i</code> 的巧克力就对应第 <code>i</code> 个类型。</p>

<p>在一步操作中，你可以用成本 <code>x</code> 执行下述行为：</p>

<ul>
	<li>同时修改所有巧克力的类型，将巧克力的类型&nbsp;<code>i<sup>th</sup></code>&nbsp;修改为类型&nbsp;<code>((i + 1) mod n)<sup>th</sup></code>。</li>
</ul>

<p>假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [20,1,15], x = 5
<strong>输出：</strong>13
<strong>解释：</strong>最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], x = 4
<strong>输出：</strong>6
<strong>解释：</strong>我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= x &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们考虑枚举操作的次数，定义 $f[i][j]$ 表示第 $i$ 个巧克力进行了 $j$ 次操作后的最小成本。

对于第 $i$ 个巧克力：

-   如果 $j = 0$，即没有进行操作，那么 $f[i][j] = nums[i]$；
-   如果 $0 \lt j \leq n-1$，那么它的最小成本就是下标范围为 $[i,.. (i - j + n) \bmod n]$ 的最小成本，即 $f[i][j] = \min\{nums[i], nums[i - 1], \cdots, nums[(i - j + n) \bmod n]\}$，或者可以写成 $f[i][j] = \min\{f[i][j - 1], nums[(i - j + n) \bmod n]\}$。
-   如果 $j \ge n$，由于当 $j = n - 1$ 时，已经覆盖了所有最小成本，如果 $j$ 继续增大，那么最小成本不会再变化，但是操作次数的增加却会导致最终的成本增加，因此，我们不需要考虑 $j \ge n$ 的情况。

综上，我们可以得到状态转移方程：

$$
f[i][j] =
\begin{cases}
nums[i] ,& j = 0 \\
\min(f[i][j - 1], nums[(i - j + n) \bmod n]) ,& 0 \lt j \leq n - 1
\end{cases}
$$

最后，我们只需要枚举操作的次数 $j$，计算出每种操作次数下的最小成本，取最小值即可。即答案为 $\min\limits_{0 \leq j \leq n - 1} \sum\limits_{i = 0}^{n - 1} f[i][j] + x \times j$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        for i, v in enumerate(nums):
            f[i][0] = v
            for j in range(1, n):
                f[i][j] = min(f[i][j - 1], nums[(i - j) % n])
        return min(sum(f[i][j] for i in range(n)) + x * j for j in range(n))
```

#### Java

```java
class Solution {
    public long minCost(int[] nums, int x) {
        int n = nums.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }
        long ans = 1L << 60;
        for (int j = 0; j < n; ++j) {
            long cost = 1L * x * j;
            for (int i = 0; i < n; ++i) {
                cost += f[i][j];
            }
            ans = Math.min(ans, cost);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        int f[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }
        long long ans = 1LL << 60;
        for (int j = 0; j < n; ++j) {
            long long cost = 1LL * x * j;
            for (int i = 0; i < n; ++i) {
                cost += f[i][j];
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(nums []int, x int) int64 {
	n := len(nums)
	f := make([][]int, n)
	for i, v := range nums {
		f[i] = make([]int, n)
		f[i][0] = v
		for j := 1; j < n; j++ {
			f[i][j] = min(f[i][j-1], nums[(i-j+n)%n])
		}
	}
	ans := 1 << 60
	for j := 0; j < n; j++ {
		cost := x * j
		for i := 0; i < n; i++ {
			cost += f[i][j]
		}
		ans = min(ans, cost)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function minCost(nums: number[], x: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][0] = nums[i];
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i][j - 1], nums[(i - j + n) % n]);
        }
    }
    let ans = Infinity;
    for (let j = 0; j < n; ++j) {
        let cost = x * j;
        for (let i = 0; i < n; ++i) {
            cost += f[i][j];
        }
        ans = Math.min(ans, cost);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_cost(nums: Vec<i32>, x: i32) -> i64 {
        let n = nums.len();
        let mut f = vec![vec![0; n]; n];
        for i in 0..n {
            f[i][0] = nums[i];
            for j in 1..n {
                f[i][j] = f[i][j - 1].min(nums[(i - j + n) % n]);
            }
        }
        let mut ans = i64::MAX;
        for j in 0..n {
            let mut cost = (x as i64) * (j as i64);
            for i in 0..n {
                cost += f[i][j] as i64;
            }
            ans = ans.min(cost);
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

# [2736. 最大和查询](https://leetcode.cn/problems/maximum-sum-queries){#2736}

{{< tabs "2736" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [-1] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = -1
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maximumSumQueries(
        self, nums1: List[int], nums2: List[int], queries: List[List[int]]
    ) -> List[int]:
        nums = sorted(zip(nums1, nums2), key=lambda x: -x[0])
        nums2.sort()
        n, m = len(nums1), len(queries)
        ans = [-1] * m
        j = 0
        tree = BinaryIndexedTree(n)
        for i in sorted(range(m), key=lambda i: -queries[i][0]):
            x, y = queries[i]
            while j < n and nums[j][0] >= x:
                k = n - bisect_left(nums2, nums[j][1])
                tree.update(k, nums[j][0] + nums[j][1])
                j += 1
            k = n - bisect_left(nums2, y)
            ans[i] = tree.query(k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        Arrays.fill(c, -1);
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = -1;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int[] maximumSumQueries(int[] nums1, int[] nums2, int[][] queries) {
        int n = nums1.length;
        int[][] nums = new int[n][0];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1[i], nums2[i]};
        }
        Arrays.sort(nums, (a, b) -> b[0] - a[0]);
        Arrays.sort(nums2);
        int m = queries.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[j][0] - queries[i][0]);
        int[] ans = new int[m];
        int j = 0;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i : idx) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < n && nums[j][0] >= x; ++j) {
                int k = n - Arrays.binarySearch(nums2, nums[j][1]);
                tree.update(k, nums[j][0] + nums[j][1]);
            }
            int p = Arrays.binarySearch(nums2, y);
            int k = p >= 0 ? n - p : n + p + 1;
            ans[i] = tree.query(k);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, -1);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = -1;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> nums;
        int n = nums1.size(), m = queries.size();
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(-nums1[i], nums2[i]);
        }
        sort(nums.begin(), nums.end());
        sort(nums2.begin(), nums2.end());
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return queries[j][0] < queries[i][0]; });
        vector<int> ans(m);
        int j = 0;
        BinaryIndexedTree tree(n);
        for (int i : idx) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < n && -nums[j].first >= x; ++j) {
                int k = nums2.end() - lower_bound(nums2.begin(), nums2.end(), nums[j].second);
                tree.update(k, -nums[j].first + nums[j].second);
            }
            int k = nums2.end() - lower_bound(nums2.begin(), nums2.end(), y);
            ans[i] = tree.query(k);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = -1
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := -1
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maximumSumQueries(nums1 []int, nums2 []int, queries [][]int) []int {
	n, m := len(nums1), len(queries)
	nums := make([][2]int, n)
	for i := range nums {
		nums[i] = [2]int{nums1[i], nums2[i]}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[j][0] < nums[i][0] })
	sort.Ints(nums2)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[j]][0] < queries[idx[i]][0] })
	tree := NewBinaryIndexedTree(n)
	ans := make([]int, m)
	j := 0
	for _, i := range idx {
		x, y := queries[i][0], queries[i][1]
		for ; j < n && nums[j][0] >= x; j++ {
			k := n - sort.SearchInts(nums2, nums[j][1])
			tree.update(k, nums[j][0]+nums[j][1])
		}
		k := n - sort.SearchInts(nums2, y)
		ans[i] = tree.query(k)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(-1);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = -1;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maximumSumQueries(nums1: number[], nums2: number[], queries: number[][]): number[] {
    const n = nums1.length;
    const m = queries.length;
    const nums: [number, number][] = [];
    for (let i = 0; i < n; ++i) {
        nums.push([nums1[i], nums2[i]]);
    }
    nums.sort((a, b) => b[0] - a[0]);
    nums2.sort((a, b) => a - b);
    const idx: number[] = Array(m)
        .fill(0)
        .map((_, i) => i);
    idx.sort((i, j) => queries[j][0] - queries[i][0]);
    const ans: number[] = Array(m).fill(0);
    let j = 0;
    const search = (x: number) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums2[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const tree = new BinaryIndexedTree(n);
    for (const i of idx) {
        const [x, y] = queries[i];
        for (; j < n && nums[j][0] >= x; ++j) {
            const k = n - search(nums[j][1]);
            tree.update(k, nums[j][0] + nums[j][1]);
        }
        const k = n - search(y);
        ans[i] = tree.query(k);
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

<p>给你两个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，另给你一个下标从 <strong>1</strong> 开始的二维数组 <code>queries</code> ，其中 <code>queries[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。</p>

<p>对于第 <code>i</code> 个查询，在所有满足 <code>nums1[j] &gt;= x<sub>i</sub></code> 且 <code>nums2[j] &gt;= y<sub>i</sub></code> 的下标 <code>j</code> <code>(0 &lt;= j &lt; n)</code> 中，找出 <code>nums1[j] + nums2[j]</code> 的 <strong>最大值</strong> ，如果不存在满足条件的 <code>j</code> 则返回 <strong>-1</strong> 。</p>

<p>返回数组<em> </em><code>answer</code><em> ，</em>其中<em> </em><code>answer[i]</code><em> </em>是第 <code>i</code> 个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums1 = [4,3,1,2], nums2 = [2,4,9,5], queries = [[4,1],[1,3],[2,5]]
<strong>输出：</strong>[6,10,7]
<strong>解释：</strong>
对于第 1 个查询：<code>x<sub>i</sub> = 4</code>&nbsp;且&nbsp;<code>y<sub>i</sub> = 1</code> ，可以选择下标&nbsp;<code>j = 0</code>&nbsp;，此时 <code>nums1[j] &gt;= 4</code>&nbsp;且&nbsp;<code>nums2[j] &gt;= 1</code> 。<code>nums1[j] + nums2[j]</code>&nbsp;等于 6 ，可以证明 6 是可以获得的最大值。
对于第 2 个查询：<code>x<sub>i</sub> = 1</code>&nbsp;且&nbsp;<code>y<sub>i</sub> = 3</code> ，可以选择下标&nbsp;<code>j = 2</code>&nbsp;，此时 <code>nums1[j] &gt;= 1</code>&nbsp;且&nbsp;<code>nums2[j] &gt;= 3</code> 。<code>nums1[j] + nums2[j]</code>&nbsp;等于 10 ，可以证明 10 是可以获得的最大值。
对于第 3 个查询：<code>x<sub>i</sub> = 2</code>&nbsp;且&nbsp;<code>y<sub>i</sub> = 5</code> ，可以选择下标&nbsp;<code>j = 3</code>&nbsp;，此时 <code>nums1[j] &gt;= 2</code>&nbsp;且&nbsp;<code>nums2[j] &gt;= 5</code> 。<code>nums1[j] + nums2[j]</code>&nbsp;等于 7 ，可以证明 7 是可以获得的最大值。
因此，我们返回&nbsp;<code>[6,10,7]</code> 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
<strong>输出：</strong>[9,9,9]
<strong>解释：</strong>对于这个示例，我们可以选择下标&nbsp;<code>j = 2</code>&nbsp;，该下标可以满足每个查询的限制。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>示例中的查询 <code>x<sub>i</sub></code> = 3 且 <code>y<sub>i</sub></code> = 3 。对于每个下标 j ，都只满足 nums1[j] &lt; <code>x<sub>i</sub></code> 或者 nums2[j] &lt; <code>y<sub>i</sub></code> 。因此，不存在答案。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums1.length == nums2.length</code>&nbsp;</li>
	<li><code>n ==&nbsp;nums1.length&nbsp;</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup>&nbsp;</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length ==&nbsp;2</code></li>
	<li><code>x<sub>i</sub>&nbsp;== queries[i][1]</code></li>
	<li><code>y<sub>i</sub> == queries[i][2]</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

本题属于二维偏序问题。

二维偏序是这样一类问题：给定若干个点对 $(a_1, b_1)$, $(a_2, b_2)$, $\cdots$, $(a_n, b_n)$，并定义某种偏序关系，现在给定点 $(a_i, b_i)$，求满足偏序关系的点对 $(a_j, b_j)$ 中的数量/最值。即：

$$
\left(a_{j}, b_{j}\right) \prec\left(a_{i}, b_{i}\right) \stackrel{\text { def }}{=} a_{j} \lesseqgtr a_{i} \text { and } b_{j} \lesseqgtr b_{i}
$$

二维偏序的一般解决方法是排序一维，用数据结构处理第二维（这种数据结构一般是树状数组）。

对于本题，我们可以创建一个数组 $nums$，其中 $nums[i]=(nums_1[i], nums_2[i])$，然后对 $nums$ 按照 $nums_1$ 从大到小的顺序排序，将查询 $queries$ 也按照 $x$ 从大到小的顺序排序。

接下来，遍历每个查询 $queries[i] = (x, y)$，对于当前查询，我们循环将 $nums$ 中所有大于等于 $x$ 的元素的 $nums_2$ 的值插入到树状数组中，树状数组维护的是离散化后的 $nums_2$ 的区间中 $nums_1 + nums_2$ 的最大值。那么我们只需要在树状数组中查询大于等于离散化后的 $y$ 区间对应的最大值即可。注意，由于树状数组维护的是前缀最大值，所以我们在实现上，可以将 $nums_2$ 反序插入到树状数组中。

时间复杂度 $O((n + m) \times \log n + m \times \log m)$，空间复杂度 $O(n + m)$。其中 $n$ 是数组 $nums$ 的长度，而 $m$ 是数组 $queries$ 的长度。

相似题目：

-   [2940. 找到 Alice 和 Bob 可以相遇的建筑](https://github.com/doocs/leetcode/blob/main/solution/2900-2999/2940.Find%20Building%20Where%20Alice%20and%20Bob%20Can%20Meet/README.md)

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [-1] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = -1
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maximumSumQueries(
        self, nums1: List[int], nums2: List[int], queries: List[List[int]]
    ) -> List[int]:
        nums = sorted(zip(nums1, nums2), key=lambda x: -x[0])
        nums2.sort()
        n, m = len(nums1), len(queries)
        ans = [-1] * m
        j = 0
        tree = BinaryIndexedTree(n)
        for i in sorted(range(m), key=lambda i: -queries[i][0]):
            x, y = queries[i]
            while j < n and nums[j][0] >= x:
                k = n - bisect_left(nums2, nums[j][1])
                tree.update(k, nums[j][0] + nums[j][1])
                j += 1
            k = n - bisect_left(nums2, y)
            ans[i] = tree.query(k)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        Arrays.fill(c, -1);
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = -1;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int[] maximumSumQueries(int[] nums1, int[] nums2, int[][] queries) {
        int n = nums1.length;
        int[][] nums = new int[n][0];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1[i], nums2[i]};
        }
        Arrays.sort(nums, (a, b) -> b[0] - a[0]);
        Arrays.sort(nums2);
        int m = queries.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[j][0] - queries[i][0]);
        int[] ans = new int[m];
        int j = 0;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i : idx) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < n && nums[j][0] >= x; ++j) {
                int k = n - Arrays.binarySearch(nums2, nums[j][1]);
                tree.update(k, nums[j][0] + nums[j][1]);
            }
            int p = Arrays.binarySearch(nums2, y);
            int k = p >= 0 ? n - p : n + p + 1;
            ans[i] = tree.query(k);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, -1);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = -1;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> nums;
        int n = nums1.size(), m = queries.size();
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(-nums1[i], nums2[i]);
        }
        sort(nums.begin(), nums.end());
        sort(nums2.begin(), nums2.end());
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return queries[j][0] < queries[i][0]; });
        vector<int> ans(m);
        int j = 0;
        BinaryIndexedTree tree(n);
        for (int i : idx) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < n && -nums[j].first >= x; ++j) {
                int k = nums2.end() - lower_bound(nums2.begin(), nums2.end(), nums[j].second);
                tree.update(k, -nums[j].first + nums[j].second);
            }
            int k = nums2.end() - lower_bound(nums2.begin(), nums2.end(), y);
            ans[i] = tree.query(k);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = -1
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := -1
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maximumSumQueries(nums1 []int, nums2 []int, queries [][]int) []int {
	n, m := len(nums1), len(queries)
	nums := make([][2]int, n)
	for i := range nums {
		nums[i] = [2]int{nums1[i], nums2[i]}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[j][0] < nums[i][0] })
	sort.Ints(nums2)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[j]][0] < queries[idx[i]][0] })
	tree := NewBinaryIndexedTree(n)
	ans := make([]int, m)
	j := 0
	for _, i := range idx {
		x, y := queries[i][0], queries[i][1]
		for ; j < n && nums[j][0] >= x; j++ {
			k := n - sort.SearchInts(nums2, nums[j][1])
			tree.update(k, nums[j][0]+nums[j][1])
		}
		k := n - sort.SearchInts(nums2, y)
		ans[i] = tree.query(k)
	}
	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(-1);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = -1;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maximumSumQueries(nums1: number[], nums2: number[], queries: number[][]): number[] {
    const n = nums1.length;
    const m = queries.length;
    const nums: [number, number][] = [];
    for (let i = 0; i < n; ++i) {
        nums.push([nums1[i], nums2[i]]);
    }
    nums.sort((a, b) => b[0] - a[0]);
    nums2.sort((a, b) => a - b);
    const idx: number[] = Array(m)
        .fill(0)
        .map((_, i) => i);
    idx.sort((i, j) => queries[j][0] - queries[i][0]);
    const ans: number[] = Array(m).fill(0);
    let j = 0;
    const search = (x: number) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums2[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const tree = new BinaryIndexedTree(n);
    for (const i of idx) {
        const [x, y] = queries[i];
        for (; j < n && nums[j][0] >= x; ++j) {
            const k = n - search(nums[j][1]);
            tree.update(k, nums[j][0] + nums[j][1]);
        }
        const k = n - search(y);
        ans[i] = tree.query(k);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2737. 找到最近的标记节点 🔒](https://leetcode.cn/problems/find-the-closest-marked-node){#2737}

{{< tabs "2737" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDistance(
        self, n: int, edges: List[List[int]], s: int, marked: List[int]
    ) -> int:
        g = [[inf] * n for _ in range(n)]
        for u, v, w in edges:
            g[u][v] = min(g[u][v], w)
        dist = [inf] * n
        vis = [False] * n
        dist[s] = 0
        for _ in range(n):
            t = -1
            for j in range(n):
                if not vis[j] and (t == -1 or dist[t] > dist[j]):
                    t = j
            vis[t] = True
            for j in range(n):
                dist[j] = min(dist[j], dist[t] + g[t][j])
        ans = min(dist[i] for i in marked)
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDistance(int n, List<List<Integer>> edges, int s, int[] marked) {
        final int inf = 1 << 29;
        int[][] g = new int[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : edges) {
            int u = e.get(0), v = e.get(1), w = e.get(2);
            g[u][v] = Math.min(g[u][v], w);
        }
        int[] dist = new int[n];
        Arrays.fill(dist, inf);
        dist[s] = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = inf;
        for (int i : marked) {
            ans = Math.min(ans, dist[i]);
        }
        return ans >= inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        const int inf = 1 << 29;
        vector<vector<int>> g(n, vector<int>(n, inf));
        vector<int> dist(n, inf);
        dist[s] = 0;
        vector<bool> vis(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u][v] = min(g[u][v], w);
        }
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = inf;
        for (int i : marked) {
            ans = min(ans, dist[i]);
        }
        return ans >= inf ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDistance(n int, edges [][]int, s int, marked []int) int {
	const inf = 1 << 29
	g := make([][]int, n)
	dist := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
		dist[i] = inf
	}
	dist[s] = 0
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u][v] = min(g[u][v], w)
	}
	vis := make([]bool, n)
	for _ = range g {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[j] < dist[t]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			dist[j] = min(dist[j], dist[t]+g[t][j])
		}
	}
	ans := inf
	for _, i := range marked {
		ans = min(ans, dist[i])
	}
	if ans >= inf {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDistance(n: number, edges: number[][], s: number, marked: number[]): number {
    const inf = 1 << 29;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(inf));
    const dist: number[] = Array(n).fill(inf);
    const vis: boolean[] = Array(n).fill(false);
    for (const [u, v, w] of edges) {
        g[u][v] = Math.min(g[u][v], w);
    }
    dist[s] = 0;
    for (let i = 0; i < n; ++i) {
        let t = -1;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        vis[t] = true;
        for (let j = 0; j < n; ++j) {
            dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
        }
    }
    let ans = inf;
    for (const i of marked) {
        ans = Math.min(ans, dist[i]);
    }
    return ans >= inf ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数 <code>n</code> ，表示一个 <strong>索引从 0 开始的有向加权</strong> 图的节点数量，以及一个 <strong>索引从 0 开始的二维数组</strong> <code>edges</code> ，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code> 表示从节点 <code>u<sub>i</sub></code> 到节点 <code>v<sub>i</sub></code> 的一条权重为 <code>w<sub>i</sub></code> 的边。</p>

<p>并给定一个节点 <code>s</code> 和一个节点数组 <code>marked</code> ；你的任务是找到从 <code>s</code> 到 <code>marked</code> 中 <strong>任何</strong> 节点的 <strong>最短</strong> 距离。</p>

<p>返回一个整数，表示从 <code>s</code> 到 <code>marked</code> 中任何节点的最短距离，如果从 s 到任何标记节点没有路径，则返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>n = 4, edges = [[0,1,1],[1,2,3],[2,3,2],[0,3,4]], s = 0, marked = [2,3]
<b>输出：</b>4
<b>解释：</b>从节点 0（绿色节点）到节点 2（红色节点）有一条路径，即 0-&gt;1-&gt;2，距离为 1 + 3 = 4。 
从节点 0 到节点 3（红色节点）有两条路径，即 0-&gt;1-&gt;2-&gt;3 和 0-&gt;3，分别距离为 1 + 3 + 2 = 6 和 4。 
它们中的最小值是 4。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2737.Find%20the%20Closest%20Marked%20Node/images/image_2023-06-13_16-34-38.png" style="width: 185px; height: 180px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 5, edges = [[0,1,2],[0,2,4],[1,3,1],[2,3,3],[3,4,2]], s = 1, marked = [0,4]
<b>输出：</b>3
<b>解释：</b>从节点 1（绿色节点）到节点 0（红色节点）没有路径。 
从节点 1 到节点 4（红色节点）有一条路径，即 1-&gt;3-&gt;4，距离为 1 + 2 = 3。 
因此答案是 3。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2737.Find%20the%20Closest%20Marked%20Node/images/image_2023-06-13_16-35-13.png" style="width: 300px; height: 285px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 4, edges = [[0,1,1],[1,2,3],[2,3,2]], s = 3, marked = [0,1]
<b>输出：</b>-1
<b>解释：</b>从节点 3（绿色节点）到任何一个标记节点（红色节点）都没有路径，因此答案是 -1。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2737.Find%20the%20Closest%20Marked%20Node/images/image_2023-06-13_16-35-47.png" style="width: 420px; height: 80px;" /></p>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= edges.length &lt;= 10<sup>4</sup></code></li>
	<li><code>edges[i].length = 3</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li><code>1 &lt;= edges[i][2] &lt;=&nbsp;10<sup>6</sup></code></li>
	<li><code>1 &lt;= marked.length&nbsp;&lt;= n - 1</code></li>
	<li><code>0 &lt;= s, marked[i]&nbsp;&lt;= n - 1</code></li>
	<li><code>s != marked[i]</code></li>
	<li>如果&nbsp;<code>i != j</code>&nbsp;则&nbsp;<code>marked[i] != marked[j]</code></li>
	<li>图中可能有 <strong>重复的边 。</strong></li>
	<li>图的生成不会出现 <strong>自环</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijkstra 算法

我们先根据题目中提供的边的信息，建立一个邻接矩阵 $g$，其中 $g[i][j]$ 表示节点 $i$ 到节点 $j$ 的距离，如果不存在这样的边，则 $g[i][j]$ 为正无穷。

然后我们就可以使用 Dijkstra 算法求出从起点 $s$ 到所有节点的最短距离，记为 $dist$。

最后我们遍历所有的标记节点，找到距离最小的标记节点，如果距离为正无穷，则返回 $-1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDistance(
        self, n: int, edges: List[List[int]], s: int, marked: List[int]
    ) -> int:
        g = [[inf] * n for _ in range(n)]
        for u, v, w in edges:
            g[u][v] = min(g[u][v], w)
        dist = [inf] * n
        vis = [False] * n
        dist[s] = 0
        for _ in range(n):
            t = -1
            for j in range(n):
                if not vis[j] and (t == -1 or dist[t] > dist[j]):
                    t = j
            vis[t] = True
            for j in range(n):
                dist[j] = min(dist[j], dist[t] + g[t][j])
        ans = min(dist[i] for i in marked)
        return -1 if ans >= inf else ans
```

#### Java

```java
class Solution {
    public int minimumDistance(int n, List<List<Integer>> edges, int s, int[] marked) {
        final int inf = 1 << 29;
        int[][] g = new int[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : edges) {
            int u = e.get(0), v = e.get(1), w = e.get(2);
            g[u][v] = Math.min(g[u][v], w);
        }
        int[] dist = new int[n];
        Arrays.fill(dist, inf);
        dist[s] = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = inf;
        for (int i : marked) {
            ans = Math.min(ans, dist[i]);
        }
        return ans >= inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        const int inf = 1 << 29;
        vector<vector<int>> g(n, vector<int>(n, inf));
        vector<int> dist(n, inf);
        dist[s] = 0;
        vector<bool> vis(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u][v] = min(g[u][v], w);
        }
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = inf;
        for (int i : marked) {
            ans = min(ans, dist[i]);
        }
        return ans >= inf ? -1 : ans;
    }
};
```

#### Go

```go
func minimumDistance(n int, edges [][]int, s int, marked []int) int {
	const inf = 1 << 29
	g := make([][]int, n)
	dist := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
		dist[i] = inf
	}
	dist[s] = 0
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u][v] = min(g[u][v], w)
	}
	vis := make([]bool, n)
	for _ = range g {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[j] < dist[t]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			dist[j] = min(dist[j], dist[t]+g[t][j])
		}
	}
	ans := inf
	for _, i := range marked {
		ans = min(ans, dist[i])
	}
	if ans >= inf {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDistance(n: number, edges: number[][], s: number, marked: number[]): number {
    const inf = 1 << 29;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(inf));
    const dist: number[] = Array(n).fill(inf);
    const vis: boolean[] = Array(n).fill(false);
    for (const [u, v, w] of edges) {
        g[u][v] = Math.min(g[u][v], w);
    }
    dist[s] = 0;
    for (let i = 0; i < n; ++i) {
        let t = -1;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        vis[t] = true;
        for (let j = 0; j < n; ++j) {
            dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
        }
    }
    let ans = inf;
    for (const i of marked) {
        ans = Math.min(ans, dist[i]);
    }
    return ans >= inf ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2738. 统计文本中单词的出现次数 🔒](https://leetcode.cn/problems/count-occurrences-in-text){#2738}

{{< tabs "2738" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT 'bull' AS word, COUNT(*) AS count
FROM Files
WHERE content LIKE '% bull %'
UNION
SELECT 'bear' AS word, COUNT(*) AS count
FROM Files
WHERE content LIKE '% bear %';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Files</code></font></p>

<pre>
+-------------+---------+
| 列名        | 类型    |
+-- ----------+---------+
| file_name   | varchar |
| content     | text    |
+-------------+---------+
file_name 为该表的主键（具有唯一值的列）。
每行包含 file_name 和该文件的内容。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出单词 <strong>'bull' </strong>和 <strong>'bear'</strong> 作为 <strong>独立词</strong> 有出现的文件数量，不考虑任何它出现在两侧没有空格的情况（例如，'bullet',&nbsp;'bears', 'bull.'，或者 'bear'&nbsp;在句首或句尾&nbsp;<strong>不会</strong> 被考虑）。</p>

<p>返回单词 'bull' 和 'bear' 以及它们对应的出现文件数量，<strong>顺序没有限制</strong>&nbsp;。</p>

<p>结果的格式如下所示：</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Files 表:
+------------+----------------------------------------------------------------------------------+
| file_name  | contenet                                                                         | 
+------------+----------------------------------------------------------------------------------+
| draft1.txt | The stock exchange predicts a bull market which would make many investors happy. | 
| draft2.txt | The stock exchange predicts a bull market which would make many investors happy, |
|&nbsp;           | but analysts warn of possibility of too much optimism and that in fact we are    |
|&nbsp;           | awaiting a bear market.                                                          | 
| draft3.txt | The stock exchange predicts a bull market which would make many investors happy, |
|&nbsp;           | but analysts warn of possibility of too much optimism and that in fact we are    |
|&nbsp;           | awaiting a bear market. As always predicting the future market is an uncertain   |
|            | game and all investors should follow their instincts and best practices.         | 
+------------+----------------------------------------------------------------------------------+
<strong>输出：</strong>&nbsp;
+------+-------+
| word | count | &nbsp;
+------+-------+
| bull |&nbsp;3     |&nbsp;
| bear |&nbsp;2     | 
+------+-------+
<b>解释：</b>
- 单词 "bull" 在 "draft1.txt" 中出现1次，在 "draft2.txt" 中出现 1 次，在 "draft3.txt" 中出现 1 次。因此，单词 "bull" 出现在 3 个文件中。
- 单词 "bear" 在 "draft2.txt" 中出现1次，在 "draft3.txt" 中出现 1 次。因此，单词 "bear" 出现在 2 个文件中。</pre>

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
SELECT 'bull' AS word, COUNT(*) AS count
FROM Files
WHERE content LIKE '% bull %'
UNION
SELECT 'bear' AS word, COUNT(*) AS count
FROM Files
WHERE content LIKE '% bear %';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2739. 总行驶距离](https://leetcode.cn/problems/total-distance-traveled){#2739}

{{< tabs "2739" >}}

{{% tab "python" %}}
```python
class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        ans = cur = 0
        while mainTank:
            cur += 1
            ans += 10
            mainTank -= 1
            if cur % 5 == 0 and additionalTank:
                additionalTank -= 1
                mainTank += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0, cur = 0;
        while (mainTank > 0) {
            cur++;
            ans += 10;
            mainTank--;
            if (cur % 5 == 0 && additionalTank > 0) {
                additionalTank--;
                mainTank++;
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
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0, cur = 0;
        while (mainTank > 0) {
            cur++;
            ans += 10;
            mainTank--;
            if (cur % 5 == 0 && additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distanceTraveled(mainTank int, additionalTank int) (ans int) {
	cur := 0
	for mainTank > 0 {
		cur++
		ans += 10
		mainTank--
		if cur%5 == 0 && additionalTank > 0 {
			additionalTank--
			mainTank++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn distance_traveled(mut main_tank: i32, mut additional_tank: i32) -> i32 {
        let mut cur = 0;
        let mut ans = 0;

        while main_tank > 0 {
            cur += 1;
            main_tank -= 1;
            ans += 10;

            if cur % 5 == 0 && additional_tank > 0 {
                additional_tank -= 1;
                main_tank += 1;
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var distanceTraveled = function (mainTank, additionalTank) {
    let ans = 0,
        cur = 0;
    while (mainTank) {
        cur++;
        ans += 10;
        mainTank--;
        if (cur % 5 === 0 && additionalTank) {
            additionalTank--;
            mainTank++;
        }
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

<p>卡车有两个油箱。给你两个整数，<code>mainTank</code> 表示主油箱中的燃料（以升为单位），<code>additionalTank</code> 表示副油箱中的燃料（以升为单位）。</p>

<p>该卡车每耗费 <code>1</code> 升燃料都可以行驶 <code>10</code> km。每当主油箱使用了 <code>5</code> 升燃料时，如果副油箱至少有 <code>1</code> 升燃料，则会将 <code>1</code> 升燃料从副油箱转移到主油箱。</p>

<p>返回卡车可以行驶的最大距离。</p>

<p>注意：从副油箱向主油箱注入燃料不是连续行为。这一事件会在每消耗 <code>5</code> 升燃料时突然且立即发生。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mainTank = 5, additionalTank = 10
<strong>输出：</strong>60
<strong>解释：</strong>
在用掉 5 升燃料后，主油箱中燃料还剩下 (5 - 5 + 1) = 1 升，行驶距离为 50km 。
在用掉剩下的 1 升燃料后，没有新的燃料注入到主油箱中，主油箱变为空。
总行驶距离为 60km 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mainTank = 1, additionalTank = 2
<strong>输出：</strong>10
<strong>解释：</strong>
在用掉 1 升燃料后，主油箱变为空。
总行驶距离为 10km 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mainTank, additionalTank &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟卡车的行驶过程，每次消耗 $1$ 升主油箱中的燃料，行驶 $10$ 公里。每当主油箱中的燃料消耗 $5$ 升时，如果副油箱中有燃料，则将副油箱中的 $1$ 升燃料转移到主油箱中。一直模拟到主油箱中的燃料消耗完为止。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是主油箱和副油箱中的燃料数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        ans = cur = 0
        while mainTank:
            cur += 1
            ans += 10
            mainTank -= 1
            if cur % 5 == 0 and additionalTank:
                additionalTank -= 1
                mainTank += 1
        return ans
```

#### Java

```java
class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0, cur = 0;
        while (mainTank > 0) {
            cur++;
            ans += 10;
            mainTank--;
            if (cur % 5 == 0 && additionalTank > 0) {
                additionalTank--;
                mainTank++;
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
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0, cur = 0;
        while (mainTank > 0) {
            cur++;
            ans += 10;
            mainTank--;
            if (cur % 5 == 0 && additionalTank > 0) {
                additionalTank--;
                mainTank++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func distanceTraveled(mainTank int, additionalTank int) (ans int) {
	cur := 0
	for mainTank > 0 {
		cur++
		ans += 10
		mainTank--
		if cur%5 == 0 && additionalTank > 0 {
			additionalTank--
			mainTank++
		}
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn distance_traveled(mut main_tank: i32, mut additional_tank: i32) -> i32 {
        let mut cur = 0;
        let mut ans = 0;

        while main_tank > 0 {
            cur += 1;
            main_tank -= 1;
            ans += 10;

            if cur % 5 == 0 && additional_tank > 0 {
                additional_tank -= 1;
                main_tank += 1;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
var distanceTraveled = function (mainTank, additionalTank) {
    let ans = 0,
        cur = 0;
    while (mainTank) {
        cur++;
        ans += 10;
        mainTank--;
        if (cur % 5 === 0 && additionalTank) {
            additionalTank--;
            mainTank++;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

---
title: "1750_删除字符串两端相同字符后的最短长度"
date: 2025-10-08T18:38:17+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 有序集合, 栈, 树状数组, 状态压缩, 设计, 贪心]
---

{{< markmap >}}
### [1750_删除字符串两端相同字符后的最短长度](#1750)
#### [双指针](#1750)
#### [字符串](#1750)
### [1751_最多可以参加的会议数目 II](#1751)
#### [数组](#1751)
#### [二分查找](#1751)
#### [动态规划](#1751)
#### [排序](#1751)
### [1752_检查数组是否经排序和轮转得到](#1752)
#### [数组](#1752)
### [1753_移除石子的最大得分](#1753)
#### [贪心](#1753)
#### [数学](#1753)
#### [堆（优先队列）](#1753)
### [1754_构造字典序最大的合并字符串](#1754)
#### [贪心](#1754)
#### [双指针](#1754)
#### [字符串](#1754)
### [1755_最接近目标值的子序列和](#1755)
#### [位运算](#1755)
#### [数组](#1755)
#### [双指针](#1755)
#### [动态规划](#1755)
#### [状态压缩](#1755)
#### [排序](#1755)
### [1756_设计最近使用（MRU）队列 🔒](#1756)
#### [栈](#1756)
#### [设计](#1756)
#### [树状数组](#1756)
#### [数组](#1756)
#### [哈希表](#1756)
#### [有序集合](#1756)
### [1757_可回收且低脂的产品](#1757)
#### [数据库](#1757)
### [1758_生成交替二进制字符串的最少操作数](#1758)
#### [字符串](#1758)
### [1759_统计同质子字符串的数目](#1759)
#### [数学](#1759)
#### [字符串](#1759)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1750_删除字符串两端相同字符后的最短长度
___
#### 双指针
___
#### 字符串
---
### 1751_最多可以参加的会议数目 II
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 1752_检查数组是否经排序和轮转得到
___
#### 数组
---
### 1753_移除石子的最大得分
___
#### 贪心
___
#### 数学
___
#### 堆（优先队列）
---
### 1754_构造字典序最大的合并字符串
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 1755_最接近目标值的子序列和
___
#### 位运算
___
#### 数组
___
#### 双指针
___
#### 动态规划
___
#### 状态压缩
___
#### 排序
---
### 1756_设计最近使用（MRU）队列 🔒
___
#### 栈
___
#### 设计
___
#### 树状数组
___
#### 数组
___
#### 哈希表
___
#### 有序集合
---
### 1757_可回收且低脂的产品
___
#### 数据库
---
### 1758_生成交替二进制字符串的最少操作数
___
#### 字符串
---
### 1759_统计同质子字符串的数目
___
#### 数学
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数据库 | 数组 | 有序集合 |
| 栈 | 树状数组 | 状态压缩 |
| 设计 | 贪心 |  |

# [1750. 删除字符串两端相同字符后的最短长度](https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends){#1750}

{{< tabs "1750" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumLength(self, s: str) -> int:
        i, j = 0, len(s) - 1
        while i < j and s[i] == s[j]:
            while i + 1 < j and s[i] == s[i + 1]:
                i += 1
            while i < j - 1 and s[j - 1] == s[j]:
                j -= 1
            i, j = i + 1, j - 1
        return max(0, j - i + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumLength(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j && s.charAt(i) == s.charAt(j)) {
            while (i + 1 < j && s.charAt(i) == s.charAt(i + 1)) {
                ++i;
            }
            while (i < j - 1 && s.charAt(j) == s.charAt(j - 1)) {
                --j;
            }
            ++i;
            --j;
        }
        return Math.max(0, j - i + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            while (i + 1 < j && s[i] == s[i + 1]) {
                ++i;
            }
            while (i < j - 1 && s[j] == s[j - 1]) {
                --j;
            }
            ++i;
            --j;
        }
        return max(0, j - i + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumLength(s string) int {
	i, j := 0, len(s)-1
	for i < j && s[i] == s[j] {
		for i+1 < j && s[i] == s[i+1] {
			i++
		}
		for i < j-1 && s[j] == s[j-1] {
			j--
		}
		i, j = i+1, j-1
	}
	return max(0, j-i+1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumLength(s: string): number {
    let i = 0;
    let j = s.length - 1;
    while (i < j && s[i] === s[j]) {
        while (i + 1 < j && s[i + 1] === s[i]) {
            ++i;
        }
        while (i < j - 1 && s[j - 1] === s[j]) {
            --j;
        }
        ++i;
        --j;
    }
    return Math.max(0, j - i + 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut start = 0;
        let mut end = n - 1;
        while start < end && s[start] == s[end] {
            while start + 1 < end && s[start] == s[start + 1] {
                start += 1;
            }
            while start < end - 1 && s[end] == s[end - 1] {
                end -= 1;
            }
            start += 1;
            end -= 1;
        }
        (0).max(end - start + 1) as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minimumLength(char* s) {
    int n = strlen(s);
    int start = 0;
    int end = n - 1;
    while (start < end && s[start] == s[end]) {
        while (start + 1 < end && s[start] == s[start + 1]) {
            start++;
        }
        while (start < end - 1 && s[end] == s[end - 1]) {
            end--;
        }
        start++;
        end--;
    }
    if (start > end) {
        return 0;
    }
    return end - start + 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个只包含字符 <code>'a'</code>，<code>'b'</code> 和 <code>'c'</code> 的字符串 <code>s</code> ，你可以执行下面这个操作（5 个步骤）任意次：</p>

<ol>
	<li>选择字符串 <code>s</code> 一个 <strong>非空</strong> 的前缀，这个前缀的所有字符都相同。</li>
	<li>选择字符串 <code>s</code> 一个 <strong>非空</strong> 的后缀，这个后缀的所有字符都相同。</li>
	<li>前缀和后缀在字符串中任意位置都不能有交集。</li>
	<li>前缀和后缀包含的所有字符都要相同。</li>
	<li>同时删除前缀和后缀。</li>
</ol>

<p>请你返回对字符串 <code>s</code> 执行上面操作任意次以后（可能 0 次），能得到的 <strong>最短长度</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "ca"
<b>输出：</b>2
<strong>解释：</strong>你没法删除任何一个字符，所以字符串长度仍然保持不变。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "cabaabac"
<b>输出：</b>0
<b>解释：</b>最优操作序列为：
- 选择前缀 "c" 和后缀 "c" 并删除它们，得到 s = "abaaba" 。
- 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "baab" 。
- 选择前缀 "b" 和后缀 "b" 并删除它们，得到 s = "aa" 。
- 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "" 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "aabccabba"
<b>输出：</b>3
<b>解释：</b>最优操作序列为：
- 选择前缀 "aa" 和后缀 "a" 并删除它们，得到 s = "bccabb" 。
- 选择前缀 "b" 和后缀 "bb" 并删除它们，得到 s = "cca" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s</code> 只包含字符 <code>'a'</code>，<code>'b'</code> 和 <code>'c'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们定义两个指针 $i$ 和 $j$ 分别指向字符串 $s$ 的头部和尾部，然后向中间移动，直到 $i$ 和 $j$ 指向的字符不相等，此时 $\max(0, j - i + 1)$ 即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        i, j = 0, len(s) - 1
        while i < j and s[i] == s[j]:
            while i + 1 < j and s[i] == s[i + 1]:
                i += 1
            while i < j - 1 and s[j - 1] == s[j]:
                j -= 1
            i, j = i + 1, j - 1
        return max(0, j - i + 1)
```

#### Java

```java
class Solution {
    public int minimumLength(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j && s.charAt(i) == s.charAt(j)) {
            while (i + 1 < j && s.charAt(i) == s.charAt(i + 1)) {
                ++i;
            }
            while (i < j - 1 && s.charAt(j) == s.charAt(j - 1)) {
                --j;
            }
            ++i;
            --j;
        }
        return Math.max(0, j - i + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            while (i + 1 < j && s[i] == s[i + 1]) {
                ++i;
            }
            while (i < j - 1 && s[j] == s[j - 1]) {
                --j;
            }
            ++i;
            --j;
        }
        return max(0, j - i + 1);
    }
};
```

#### Go

```go
func minimumLength(s string) int {
	i, j := 0, len(s)-1
	for i < j && s[i] == s[j] {
		for i+1 < j && s[i] == s[i+1] {
			i++
		}
		for i < j-1 && s[j] == s[j-1] {
			j--
		}
		i, j = i+1, j-1
	}
	return max(0, j-i+1)
}
```

#### TypeScript

```ts
function minimumLength(s: string): number {
    let i = 0;
    let j = s.length - 1;
    while (i < j && s[i] === s[j]) {
        while (i + 1 < j && s[i + 1] === s[i]) {
            ++i;
        }
        while (i < j - 1 && s[j - 1] === s[j]) {
            --j;
        }
        ++i;
        --j;
    }
    return Math.max(0, j - i + 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut start = 0;
        let mut end = n - 1;
        while start < end && s[start] == s[end] {
            while start + 1 < end && s[start] == s[start + 1] {
                start += 1;
            }
            while start < end - 1 && s[end] == s[end - 1] {
                end -= 1;
            }
            start += 1;
            end -= 1;
        }
        (0).max(end - start + 1) as i32
    }
}
```

#### C

```c
int minimumLength(char* s) {
    int n = strlen(s);
    int start = 0;
    int end = n - 1;
    while (start < end && s[start] == s[end]) {
        while (start + 1 < end && s[start] == s[start + 1]) {
            start++;
        }
        while (start < end - 1 && s[end] == s[end - 1]) {
            end--;
        }
        start++;
        end--;
    }
    if (start > end) {
        return 0;
    }
    return end - start + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1751. 最多可以参加的会议数目 II](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii){#1751}

{{< tabs "1751" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[1])
        n = len(events)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i, (st, _, val) in enumerate(events, 1):
            p = bisect_left(events, st, hi=i - 1, key=lambda x: x[1])
            for j in range(1, k + 1):
                f[i][j] = max(f[i - 1][j], f[p][j - 1] + val)
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int n = events.length;
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            int st = events[i - 1][0], val = events[i - 1][2];
            int p = search(events, st, i - 1);
            for (int j = 1; j <= k; ++j) {
                f[i][j] = Math.max(f[i - 1][j], f[p][j - 1] + val);
            }
        }
        return f[n][k];
    }

    private int search(int[][] events, int x, int hi) {
        int l = 0, r = hi;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (events[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int n = events.size();
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int st = events[i - 1][0], val = events[i - 1][2];
            vector<int> t = {st};
            int p = lower_bound(events.begin(), events.begin() + i - 1, t, [](const auto& a, const auto& b) { return a[1] < b[0]; }) - events.begin();
            for (int j = 1; j <= k; ++j) {
                f[i][j] = max(f[i - 1][j], f[p][j - 1] + val);
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxValue(events [][]int, k int) int {
	sort.Slice(events, func(i, j int) bool { return events[i][1] < events[j][1] })
	n := len(events)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		st, val := events[i-1][0], events[i-1][2]
		p := sort.Search(i, func(j int) bool { return events[j][1] >= st })
		for j := 1; j <= k; j++ {
			f[i][j] = max(f[i-1][j], f[p][j-1]+val)
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxValue(events: number[][], k: number): number {
    events.sort((a, b) => a[1] - b[1]);
    const n = events.length;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const search = (x: number, hi: number): number => {
        let l = 0;
        let r = hi;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (events[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        const [st, _, val] = events[i - 1];
        const p = search(st, i - 1);
        for (let j = 1; j <= k; ++j) {
            f[i][j] = Math.max(f[i - 1][j], f[p][j - 1] + val);
        }
    }
    return f[n][k];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_value(mut events: Vec<Vec<i32>>, k: i32) -> i32 {
        events.sort_by_key(|e| e[1]);
        let n = events.len();
        let mut f = vec![vec![0; (k + 1) as usize]; n + 1];

        for i in 1..=n {
            let st = events[i - 1][0];
            let val = events[i - 1][2];
            let p = search(&events, st, i - 1);
            for j in 1..=k as usize {
                f[i][j] = f[i - 1][j].max(f[p][j - 1] + val);
            }
        }

        f[n][k as usize]
    }
}

fn search(events: &Vec<Vec<i32>>, x: i32, hi: usize) -> usize {
    let mut l = 0;
    let mut r = hi;
    while l < r {
        let mid = (l + r) / 2;
        if events[mid][1] >= x {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    l
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>events</code> 数组，其中 <code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>, value<sub>i</sub>]</code> ，表示第 <code>i</code> 个会议在 <code>startDay<sub>i</sub></code><sub> </sub>天开始，第 <code>endDay<sub>i</sub></code> 天结束，如果你参加这个会议，你能得到价值 <code>value<sub>i</sub></code> 。同时给你一个整数 <code>k</code> 表示你能参加的最多会议数目。</p>

<p>你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 <strong>完整</strong> 地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。</p>

<p>请你返回能得到的会议价值 <strong>最大和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1751.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20II/images/screenshot-2021-01-11-at-60048-pm.png" style="width: 400px; height: 103px;" /></p>

<pre>
<b>输入：</b>events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
<b>输出：</b>7
<strong>解释：</strong>选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1751.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20II/images/screenshot-2021-01-11-at-60150-pm.png" style="width: 400px; height: 103px;" /></p>

<pre>
<b>输入：</b>events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
<b>输出：</b>10
<b>解释：</b>参加会议 2 ，得到价值和为 10 。
你没法再参加别的会议了，因为跟会议 2 有重叠。你 <strong>不</strong> 需要参加满 k 个会议。</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1751.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20II/images/screenshot-2021-01-11-at-60703-pm.png" style="width: 400px; height: 126px;" /></strong></p>

<pre>
<b>输入：</b>events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
<b>输出：</b>9
<b>解释：</b>尽管会议互不重叠，你只能参加 3 个会议，所以选择价值最大的 3 个会议。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= events.length</code></li>
	<li><code>1 <= k * events.length <= 10<sup>6</sup></code></li>
	<li><code>1 <= startDay<sub>i</sub> <= endDay<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>1 <= value<sub>i</sub> <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二分查找

我们先将会议按照开始时间从小到大排序，然后设计一个函数 $\text{dfs}(i, k)$ 表示从第 $i$ 个会议开始，最多参加 $k$ 个会议的最大价值和。答案即为 $\text{dfs}(0, k)$。

函数 $\text{dfs}(i, k)$ 的计算过程如下：

如果不参加第 $i$ 个会议，那么最大价值和就是 $\text{dfs}(i + 1, k)$；如果参加第 $i$ 个会议，我们可以通过二分查找，找到第一个开始时间大于第 $i$ 个会议结束时间的会议，记为 $j$，那么最大价值和就是 $\text{dfs}(j, k - 1) + \text{value}[i]$。取二者的较大值即可。即：

$$
\text{dfs}(i, k) = \max(\text{dfs}(i + 1, k), \text{dfs}(j, k - 1) + \text{value}[i])
$$

其中 $j$ 为第一个开始时间大于第 $i$ 个会议结束时间的会议，可以通过二分查找得到。

由于函数 $\text{dfs}(i, k)$ 的计算过程中，会调用 $\text{dfs}(i + 1, k)$ 和 $\text{dfs}(j, k - 1)$，因此我们可以使用记忆化搜索，将计算过的值保存下来，避免重复计算。

时间复杂度 $O(n \times \log n + n \times k)$，空间复杂度 $O(n \times k)$，其中 $n$ 为会议数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        @cache
        def dfs(i: int, k: int) -> int:
            if i >= len(events):
                return 0
            _, ed, val = events[i]
            ans = dfs(i + 1, k)
            if k:
                j = bisect_right(events, ed, lo=i + 1, key=lambda x: x[0])
                ans = max(ans, dfs(j, k - 1) + val)
            return ans

        events.sort()
        return dfs(0, k)
```

#### Java

```java
class Solution {
    private int[][] events;
    private int[][] f;
    private int n;

    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        this.events = events;
        n = events.length;
        f = new int[n][k + 1];
        return dfs(0, k);
    }

    private int dfs(int i, int k) {
        if (i >= n || k <= 0) {
            return 0;
        }
        if (f[i][k] != 0) {
            return f[i][k];
        }
        int j = search(events, events[i][1], i + 1);
        int ans = Math.max(dfs(i + 1, k), dfs(j, k - 1) + events[i][2]);
        return f[i][k] = ans;
    }

    private int search(int[][] events, int x, int lo) {
        int l = lo, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (events[mid][0] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        ranges::sort(events);
        int n = events.size();
        int f[n][k + 1];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int k) -> int {
            if (i >= n || k <= 0) {
                return 0;
            }
            if (f[i][k] > 0) {
                return f[i][k];
            }

            int ed = events[i][1], val = events[i][2];
            vector<int> t = {ed};

            int p = upper_bound(events.begin() + i + 1, events.end(), t,
                        [](const auto& a, const auto& b) { return a[0] < b[0]; })
                - events.begin();

            f[i][k] = max(dfs(i + 1, k), dfs(p, k - 1) + val);
            return f[i][k];
        };

        return dfs(0, k);
    }
};
```

#### Go

```go
func maxValue(events [][]int, k int) int {
	sort.Slice(events, func(i, j int) bool { return events[i][0] < events[j][0] })
	n := len(events)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	var dfs func(i, k int) int
	dfs = func(i, k int) int {
		if i >= n || k <= 0 {
			return 0
		}
		if f[i][k] > 0 {
			return f[i][k]
		}
		j := sort.Search(n, func(h int) bool { return events[h][0] > events[i][1] })
		ans := max(dfs(i+1, k), dfs(j, k-1)+events[i][2])
		f[i][k] = ans
		return ans
	}
	return dfs(0, k)
}
```

#### TypeScript

```ts
function maxValue(events: number[][], k: number): number {
    events.sort((a, b) => a[0] - b[0]);
    const n = events.length;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));

    const dfs = (i: number, k: number): number => {
        if (i >= n || k <= 0) {
            return 0;
        }
        if (f[i][k] > 0) {
            return f[i][k];
        }

        const ed = events[i][1],
            val = events[i][2];

        let left = i + 1,
            right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (events[mid][0] > ed) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const p = left;

        f[i][k] = Math.max(dfs(i + 1, k), dfs(p, k - 1) + val);
        return f[i][k];
    };

    return dfs(0, k);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_value(mut events: Vec<Vec<i32>>, k: i32) -> i32 {
        events.sort_by_key(|e| e[0]);
        let n = events.len();
        let mut f = vec![vec![0; (k + 1) as usize]; n];

        fn dfs(i: usize, k: i32, events: &Vec<Vec<i32>>, f: &mut Vec<Vec<i32>>, n: usize) -> i32 {
            if i >= n || k <= 0 {
                return 0;
            }
            if f[i][k as usize] != 0 {
                return f[i][k as usize];
            }
            let j = search(events, events[i][1], i + 1, n);
            let ans = dfs(i + 1, k, events, f, n).max(dfs(j, k - 1, events, f, n) + events[i][2]);
            f[i][k as usize] = ans;
            ans
        }

        fn search(events: &Vec<Vec<i32>>, x: i32, lo: usize, n: usize) -> usize {
            let mut l = lo;
            let mut r = n;
            while l < r {
                let mid = (l + r) / 2;
                if events[mid][0] > x {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            l
        }

        dfs(0, k, &events, &mut f, n)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 二分查找

我们可以将方法一中的记忆化搜索改为动态规划。

先将会议排序，这次我们按照结束时间从小到大排序。然后定义 $f[i][j]$ 表示前 $i$ 个会议中，最多参加 $j$ 个会议的最大价值和。答案即为 $f[n][k]$。

对于第 $i$ 个会议，我们可以选择参加或者不参加。如果不参加，那么最大价值和就是 $f[i][j]$，如果参加，我们可以通过二分查找，找到最后一个结束时间小于第 $i$ 个会议开始时间的会议，记为 $h$，那么最大价值和就是 $f[h + 1][j - 1] + \text{value}[i]$。取二者的较大值即可。即：

$$
f[i + 1][j] = \max(f[i][j], f[h + 1][j - 1] + \text{value}[i])
$$

其中 $h$ 为最后一个结束时间小于第 $i$ 个会议开始时间的会议，可以通过二分查找得到。

时间复杂度 $O(n \times \log n + n \times k)$，空间复杂度 $O(n \times k)$，其中 $n$ 为会议数量。

相似题目：

-   [1235. 规划兼职工作](https://github.com/doocs/leetcode/blob/main/solution/1200-1299/1235.Maximum%20Profit%20in%20Job%20Scheduling/README.md)
-   [2008. 出租车的最大盈利](https://github.com/doocs/leetcode/blob/main/solution/2000-2099/2008.Maximum%20Earnings%20From%20Taxi/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[1])
        n = len(events)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i, (st, _, val) in enumerate(events, 1):
            p = bisect_left(events, st, hi=i - 1, key=lambda x: x[1])
            for j in range(1, k + 1):
                f[i][j] = max(f[i - 1][j], f[p][j - 1] + val)
        return f[n][k]
```

#### Java

```java
class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int n = events.length;
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; ++i) {
            int st = events[i - 1][0], val = events[i - 1][2];
            int p = search(events, st, i - 1);
            for (int j = 1; j <= k; ++j) {
                f[i][j] = Math.max(f[i - 1][j], f[p][j - 1] + val);
            }
        }
        return f[n][k];
    }

    private int search(int[][] events, int x, int hi) {
        int l = 0, r = hi;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (events[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int n = events.size();
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int st = events[i - 1][0], val = events[i - 1][2];
            vector<int> t = {st};
            int p = lower_bound(events.begin(), events.begin() + i - 1, t, [](const auto& a, const auto& b) { return a[1] < b[0]; }) - events.begin();
            for (int j = 1; j <= k; ++j) {
                f[i][j] = max(f[i - 1][j], f[p][j - 1] + val);
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func maxValue(events [][]int, k int) int {
	sort.Slice(events, func(i, j int) bool { return events[i][1] < events[j][1] })
	n := len(events)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		st, val := events[i-1][0], events[i-1][2]
		p := sort.Search(i, func(j int) bool { return events[j][1] >= st })
		for j := 1; j <= k; j++ {
			f[i][j] = max(f[i-1][j], f[p][j-1]+val)
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function maxValue(events: number[][], k: number): number {
    events.sort((a, b) => a[1] - b[1]);
    const n = events.length;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    const search = (x: number, hi: number): number => {
        let l = 0;
        let r = hi;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (events[mid][1] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        const [st, _, val] = events[i - 1];
        const p = search(st, i - 1);
        for (let j = 1; j <= k; ++j) {
            f[i][j] = Math.max(f[i - 1][j], f[p][j - 1] + val);
        }
    }
    return f[n][k];
}
```

#### Rust

```rust
impl Solution {
    pub fn max_value(mut events: Vec<Vec<i32>>, k: i32) -> i32 {
        events.sort_by_key(|e| e[1]);
        let n = events.len();
        let mut f = vec![vec![0; (k + 1) as usize]; n + 1];

        for i in 1..=n {
            let st = events[i - 1][0];
            let val = events[i - 1][2];
            let p = search(&events, st, i - 1);
            for j in 1..=k as usize {
                f[i][j] = f[i - 1][j].max(f[p][j - 1] + val);
            }
        }

        f[n][k as usize]
    }
}

fn search(events: &Vec<Vec<i32>>, x: i32, hi: usize) -> usize {
    let mut l = 0;
    let mut r = hi;
    while l < r {
        let mid = (l + r) / 2;
        if events[mid][1] >= x {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    l
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1752. 检查数组是否经排序和轮转得到](https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated){#1752}

{{< tabs "1752" >}}

{{% tab "python" %}}
```python
class Solution:
    def check(self, nums: List[int]) -> bool:
        return sum(nums[i - 1] > v for i, v in enumerate(nums)) <= 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean check(int[] nums) {
        int cnt = 0;
        for (int i = 0, n = nums.length; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                ++cnt;
            }
        }
        return cnt <= 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func check(nums []int) bool {
	cnt := 0
	for i, v := range nums {
		if v > nums[(i+1)%len(nums)] {
			cnt++
		}
	}
	return cnt <= 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function check(nums: number[]): boolean {
    const n = nums.length;
    return nums.reduce((r, v, i) => r + (v > nums[(i + 1) % n] ? 1 : 0), 0) <= 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut count = 0;
        for i in 0..n {
            if nums[i] > nums[(i + 1) % n] {
                count += 1;
            }
        }
        count <= 1
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool check(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }
    }
    return count <= 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> 。<code>nums</code> 的源数组中，所有元素与 <code>nums</code> 相同，但按非递减顺序排列。</p>

<p>如果&nbsp;<code>nums</code> 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 <code>true</code><em> </em>；否则，返回 <code>false</code> 。</p>

<p>源数组中可能存在 <strong>重复项</strong> 。</p>

<p><strong>注意：</strong>数组 <code>A</code> 在轮转 <code>x</code> 个位置后得到长度相同的数组 <code>B</code> ，使得对于每一个有效的下标&nbsp;<code>i</code>，满足&nbsp;<code>B[i] == A[(i+x) % A.length]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,1,2]
<strong>输出：</strong>true
<strong>解释：</strong>[1,2,3,4,5] 为有序的源数组。
可以轮转 x = 2 个位置，使新数组从值为 3 的元素开始：[3,4,5,1,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3,4]
<strong>输出：</strong>false
<strong>解释：</strong>源数组无法经轮转得到 nums 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>true
<strong>解释：</strong>[1,2,3] 为有序的源数组。
可以轮转 x = 0 个位置（即不轮转）得到 nums 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

要满足题目要求，那么数组 `nums` 中最多只能存在一个元素，其值大于下一个元素，即 $nums[i] \gt nums[i + 1]$。如果存在多个这样的元素，那么数组 `nums` 无法通过轮转得到。

注意，数组 `nums` 最后一个元素的下一个元素是数组 `nums` 的第一个元素。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def check(self, nums: List[int]) -> bool:
        return sum(nums[i - 1] > v for i, v in enumerate(nums)) <= 1
```

#### Java

```java
class Solution {
    public boolean check(int[] nums) {
        int cnt = 0;
        for (int i = 0, n = nums.length; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                ++cnt;
            }
        }
        return cnt <= 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};
```

#### Go

```go
func check(nums []int) bool {
	cnt := 0
	for i, v := range nums {
		if v > nums[(i+1)%len(nums)] {
			cnt++
		}
	}
	return cnt <= 1
}
```

#### TypeScript

```ts
function check(nums: number[]): boolean {
    const n = nums.length;
    return nums.reduce((r, v, i) => r + (v > nums[(i + 1) % n] ? 1 : 0), 0) <= 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut count = 0;
        for i in 0..n {
            if nums[i] > nums[(i + 1) % n] {
                count += 1;
            }
        }
        count <= 1
    }
}
```

#### C

```c
bool check(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }
    }
    return count <= 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1753. 移除石子的最大得分](https://leetcode.cn/problems/maximum-score-from-removing-stones){#1753}

{{< tabs "1753" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        a, b, c = sorted([a, b, c])
        if a + b < c:
            return a + b
        return (a + b + c) >> 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumScore(int a, int b, int c) {
        int[] s = new int[] {a, b, c};
        Arrays.sort(s);
        if (s[0] + s[1] < s[2]) {
            return s[0] + s[1];
        }
        return (a + b + c) >> 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        if (s[0] + s[1] < s[2]) return s[0] + s[1];
        return (a + b + c) >> 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumScore(a int, b int, c int) int {
	s := []int{a, b, c}
	sort.Ints(s)
	if s[0]+s[1] < s[2] {
		return s[0] + s[1]
	}
	return (a + b + c) >> 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在玩一个单人游戏，面前放置着大小分别为 <code>a</code>​​​​​​、<code>b</code> 和 <code>c</code>​​​​​​ 的 <strong>三堆</strong> 石子。</p>

<p>每回合你都要从两个 <strong>不同的非空堆</strong> 中取出一颗石子，并在得分上加 <code>1</code> 分。当存在 <strong>两个或更多</strong> 的空堆时，游戏停止。</p>

<p>给你三个整数 <code>a</code> 、<code>b</code> 和 <code>c</code> ，返回可以得到的 <strong>最大分数</strong> 。</p>
 

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = 4, c = 6
<strong>输出：</strong>6
<strong>解释：</strong>石子起始状态是 (2, 4, 6) ，最优的一组操作是：
- 从第一和第三堆取，石子状态现在是 (1, 4, 5)
- 从第一和第三堆取，石子状态现在是 (0, 4, 4)
- 从第二和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：6 分 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 4, b = 4, c = 6
<strong>输出：</strong>7
<strong>解释：</strong>石子起始状态是 (4, 4, 6) ，最优的一组操作是：
- 从第一和第二堆取，石子状态现在是 (3, 3, 6)
- 从第一和第三堆取，石子状态现在是 (2, 3, 5)
- 从第一和第三堆取，石子状态现在是 (1, 3, 4)
- 从第一和第三堆取，石子状态现在是 (0, 3, 3)
- 从第二和第三堆取，石子状态现在是 (0, 2, 2)
- 从第二和第三堆取，石子状态现在是 (0, 1, 1)
- 从第二和第三堆取，石子状态现在是 (0, 0, 0)
总分：7 分 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 8, c = 8
<strong>输出：</strong>8
<strong>解释：</strong>最优的一组操作是连续从第二和第三堆取 8 回合，直到将它们取空。
注意，由于第二和第三堆已经空了，游戏结束，不能继续从第一堆中取石子。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= a, b, c <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 模拟

每次贪心地从最大的两堆石子中取石头，直到至少有两堆石子为空。

时间复杂度 $O(n)$，其中 $n$ 为石子总数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        s = sorted([a, b, c])
        ans = 0
        while s[1]:
            ans += 1
            s[1] -= 1
            s[2] -= 1
            s.sort()
        return ans
```

#### Java

```java
class Solution {
    public int maximumScore(int a, int b, int c) {
        int[] s = new int[] {a, b, c};
        Arrays.sort(s);
        int ans = 0;
        while (s[1] > 0) {
            ++ans;
            s[1]--;
            s[2]--;
            Arrays.sort(s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        int ans = 0;
        while (s[1]) {
            ++ans;
            s[1]--;
            s[2]--;
            sort(s.begin(), s.end());
        }
        return ans;
    }
};
```

#### Go

```go
func maximumScore(a int, b int, c int) (ans int) {
	s := []int{a, b, c}
	sort.Ints(s)
	for s[1] > 0 {
		ans++
		s[1]--
		s[2]--
		sort.Ints(s)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 数学

我们不妨设 $a \le b \le c$，那么：

-   当 $a + b \le c$ 时，我们可以先从 $a$, $c$ 两堆中取石头，得到分数 $a$；再从 $b$, $c$ 两堆中取石头，得到分数 $b$，总分数为 $a + b$；
-   当 $a + b \gt c$ 时，这时我们每次会从 $c$ 以及 $a$ 和 $b$ 中较大的那一堆中取石头，最终将 $c$ 取空。此时 $a$ 和 $b$ 的大小差最多为 $1$。我们再从 $a$, $b$ 两堆中取石头，直到不能取为止，总分数为 $\left \lfloor \frac{a + b + c}{2}  \right \rfloor$。

时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        a, b, c = sorted([a, b, c])
        if a + b < c:
            return a + b
        return (a + b + c) >> 1
```

#### Java

```java
class Solution {
    public int maximumScore(int a, int b, int c) {
        int[] s = new int[] {a, b, c};
        Arrays.sort(s);
        if (s[0] + s[1] < s[2]) {
            return s[0] + s[1];
        }
        return (a + b + c) >> 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        if (s[0] + s[1] < s[2]) return s[0] + s[1];
        return (a + b + c) >> 1;
    }
};
```

#### Go

```go
func maximumScore(a int, b int, c int) int {
	s := []int{a, b, c}
	sort.Ints(s)
	if s[0]+s[1] < s[2] {
		return s[0] + s[1]
	}
	return (a + b + c) >> 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1754. 构造字典序最大的合并字符串](https://leetcode.cn/problems/largest-merge-of-two-strings){#1754}

{{< tabs "1754" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        i = j = 0
        ans = []
        while i < len(word1) and j < len(word2):
            if word1[i:] > word2[j:]:
                ans.append(word1[i])
                i += 1
            else:
                ans.append(word2[j])
                j += 1
        ans.append(word1[i:])
        ans.append(word2[j:])
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestMerge(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < m && j < n) {
            boolean gt = word1.substring(i).compareTo(word2.substring(j)) > 0;
            ans.append(gt ? word1.charAt(i++) : word2.charAt(j++));
        }
        ans.append(word1.substring(i));
        ans.append(word2.substring(j));
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string ans;
        while (i < m && j < n) {
            bool gt = word1.substr(i) > word2.substr(j);
            ans += gt ? word1[i++] : word2[j++];
        }
        ans += word1.substr(i);
        ans += word2.substr(j);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestMerge(word1 string, word2 string) string {
	m, n := len(word1), len(word2)
	i, j := 0, 0
	var ans strings.Builder
	for i < m && j < n {
		if word1[i:] > word2[j:] {
			ans.WriteByte(word1[i])
			i++
		} else {
			ans.WriteByte(word2[j])
			j++
		}
	}
	ans.WriteString(word1[i:])
	ans.WriteString(word2[j:])
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestMerge(word1: string, word2: string): string {
    const m = word1.length;
    const n = word2.length;
    let ans = '';
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        ans += word1.slice(i) > word2.slice(j) ? word1[i++] : word2[j++];
    }
    ans += word1.slice(i);
    ans += word2.slice(j);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn largest_merge(word1: String, word2: String) -> String {
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        let m = word1.len();
        let n = word2.len();
        let mut ans = String::new();
        let mut i = 0;
        let mut j = 0;
        while i < m && j < n {
            if word1[i..] > word2[j..] {
                ans.push(word1[i] as char);
                i += 1;
            } else {
                ans.push(word2[j] as char);
                j += 1;
            }
        }
        word1[i..].iter().for_each(|c| ans.push(*c as char));
        word2[j..].iter().for_each(|c| ans.push(*c as char));
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* largestMerge(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int i = 0;
    int j = 0;
    char* ans = malloc((m + n + 1) * sizeof(char));
    while (i < m && j < n) {
        int k = 0;
        while (word1[i + k] && word2[j + k] && word1[i + k] == word2[j + k]) {
            k++;
        }
        if (word1[i + k] > word2[j + k]) {
            ans[i + j] = word1[i];
            i++;
        } else {
            ans[i + j] = word2[j];
            j++;
        };
    }
    while (word1[i]) {
        ans[i + j] = word1[i];
        i++;
    }
    while (word2[j]) {
        ans[i + j] = word2[j];
        j++;
    }
    ans[m + n] = '\0';
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>word1</code> 和 <code>word2</code> 。你需要按下述方式构造一个新字符串 <code>merge</code> ：如果 <code>word1</code> 或 <code>word2</code> 非空，选择 <strong>下面选项之一</strong> 继续操作：</p>

<ul>
	<li>如果 <code>word1</code> 非空，将 <code>word1</code> 中的第一个字符附加到 <code>merge</code> 的末尾，并将其从 <code>word1</code> 中移除。

    <ul>
    	<li>例如，<code>word1 = "abc" </code>且 <code>merge = "dv"</code> ，在执行此选项操作之后，<code>word1 = "bc"</code> ，同时 <code>merge = "dva"</code> 。</li>
    </ul>
    </li>
    <li>如果 <code>word2</code> 非空，将 <code>word2</code> 中的第一个字符附加到 <code>merge</code> 的末尾，并将其从 <code>word2</code> 中移除。
    <ul>
    	<li>例如，<code>word2 = "abc" </code>且 <code>merge = ""</code> ，在执行此选项操作之后，<code>word2 = "bc"</code> ，同时 <code>merge = "a"</code> 。</li>
    </ul>
    </li>

</ul>

<p>返回你可以构造的字典序 <strong>最大</strong> 的合并字符串<em> </em><code>merge</code><em> 。</em></p>

<p>长度相同的两个字符串 <code>a</code> 和 <code>b</code> 比较字典序大小，如果在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置，<code>a</code> 中字符在字母表中的出现顺序位于 <code>b</code> 中相应字符之后，就认为字符串 <code>a</code> 按字典序比字符串 <code>b</code> 更大。例如，<code>"abcd"</code> 按字典序比 <code>"abcc"</code> 更大，因为两个字符串出现不同的第一个位置是第四个字符，而 <code>d</code> 在字母表中的出现顺序位于 <code>c</code> 之后。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "cabaa", word2 = "bcaaa"
<strong>输出：</strong>"cbcabaaaaa"
<strong>解释：</strong>构造字典序最大的合并字符串，可行的一种方法如下所示：
- 从 word1 中取第一个字符：merge = "c"，word1 = "abaa"，word2 = "bcaaa"
- 从 word2 中取第一个字符：merge = "cb"，word1 = "abaa"，word2 = "caaa"
- 从 word2 中取第一个字符：merge = "cbc"，word1 = "abaa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbca"，word1 = "baa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbcab"，word1 = "aa"，word2 = "aaa"
- 将 word1 和 word2 中剩下的 5 个 a 附加到 merge 的末尾。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abcabc", word2 = "abdcaba"
<strong>输出：</strong>"abdcabcabcaba"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 3000</code></li>
	<li><code>word1</code> 和 <code>word2</code> 仅由小写英文组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

我们用指针 $i$ 和 $j$ 分别指向字符串 `word1` 和 `word2` 的第一个字符。然后循环，每次比较 $word1[i:]$ 和 $word2[j:]$ 的大小，如果 $word1[i:]$ 比 $word2[j:]$ 大，那么我们就将 $word1[i]$ 加入答案，否则我们就将 $word2[j]$ 加入答案。循环，直至 $i$ 到达字符串 `word1` 的末尾，或者 $j$ 到达字符串 `word2` 的末尾。

然后我们将剩余的字符串加入答案即可。

时间复杂度 $O(n^2)$。其中 $n$ 是字符串 `word1` 和 `word2` 的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        i = j = 0
        ans = []
        while i < len(word1) and j < len(word2):
            if word1[i:] > word2[j:]:
                ans.append(word1[i])
                i += 1
            else:
                ans.append(word2[j])
                j += 1
        ans.append(word1[i:])
        ans.append(word2[j:])
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String largestMerge(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < m && j < n) {
            boolean gt = word1.substring(i).compareTo(word2.substring(j)) > 0;
            ans.append(gt ? word1.charAt(i++) : word2.charAt(j++));
        }
        ans.append(word1.substring(i));
        ans.append(word2.substring(j));
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string ans;
        while (i < m && j < n) {
            bool gt = word1.substr(i) > word2.substr(j);
            ans += gt ? word1[i++] : word2[j++];
        }
        ans += word1.substr(i);
        ans += word2.substr(j);
        return ans;
    }
};
```

#### Go

```go
func largestMerge(word1 string, word2 string) string {
	m, n := len(word1), len(word2)
	i, j := 0, 0
	var ans strings.Builder
	for i < m && j < n {
		if word1[i:] > word2[j:] {
			ans.WriteByte(word1[i])
			i++
		} else {
			ans.WriteByte(word2[j])
			j++
		}
	}
	ans.WriteString(word1[i:])
	ans.WriteString(word2[j:])
	return ans.String()
}
```

#### TypeScript

```ts
function largestMerge(word1: string, word2: string): string {
    const m = word1.length;
    const n = word2.length;
    let ans = '';
    let i = 0;
    let j = 0;
    while (i < m && j < n) {
        ans += word1.slice(i) > word2.slice(j) ? word1[i++] : word2[j++];
    }
    ans += word1.slice(i);
    ans += word2.slice(j);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn largest_merge(word1: String, word2: String) -> String {
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        let m = word1.len();
        let n = word2.len();
        let mut ans = String::new();
        let mut i = 0;
        let mut j = 0;
        while i < m && j < n {
            if word1[i..] > word2[j..] {
                ans.push(word1[i] as char);
                i += 1;
            } else {
                ans.push(word2[j] as char);
                j += 1;
            }
        }
        word1[i..].iter().for_each(|c| ans.push(*c as char));
        word2[j..].iter().for_each(|c| ans.push(*c as char));
        ans
    }
}
```

#### C

```c
char* largestMerge(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int i = 0;
    int j = 0;
    char* ans = malloc((m + n + 1) * sizeof(char));
    while (i < m && j < n) {
        int k = 0;
        while (word1[i + k] && word2[j + k] && word1[i + k] == word2[j + k]) {
            k++;
        }
        if (word1[i + k] > word2[j + k]) {
            ans[i + j] = word1[i];
            i++;
        } else {
            ans[i + j] = word2[j];
            j++;
        };
    }
    while (word1[i]) {
        ans[i + j] = word1[i];
        i++;
    }
    while (word2[j]) {
        ans[i + j] = word2[j];
        j++;
    }
    ans[m + n] = '\0';
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1755. 最接近目标值的子序列和](https://leetcode.cn/problems/closest-subsequence-sum){#1755}

{{< tabs "1755" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        def dfs(arr, res, i, s):
            if i == len(arr):
                res.add(s)
                return
            dfs(arr, res, i + 1, s)
            dfs(arr, res, i + 1, s + arr[i])

        n = len(nums)
        left, right = set(), set()
        dfs(nums[: n >> 1], left, 0, 0)
        dfs(nums[n >> 1 :], right, 0, 0)
        right = sorted(right)
        ans = inf
        for l in left:
            x = goal - l
            i = bisect_left(right, x)
            if i < len(right):
                ans = min(ans, abs(x - right[i]))
            if i:
                ans = min(ans, abs(x - right[i - 1]))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        Set<Integer> left = new HashSet<>();
        Set<Integer> right = new HashSet<>();
        dfs(nums, 0, n >> 1, 0, left);
        dfs(nums, n >> 1, n, 0, right);
        List<Integer> rs = new ArrayList<>(right);
        Collections.sort(rs);
        int ans = Integer.MAX_VALUE;
        for (int x : left) {
            int y = goal - x;
            int l = 0, r = rs.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (rs.get(mid) >= y) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l < rs.size()) {
                ans = Math.min(ans, Math.abs(y - rs.get(l)));
            }
            if (l > 0) {
                ans = Math.min(ans, Math.abs(y - rs.get(l - 1)));
            }
        }
        return ans;
    }

    private void dfs(int[] arr, int i, int n, int s, Set<Integer> res) {
        if (i == n) {
            res.add(s);
            return;
        }
        dfs(arr, i + 1, n, s, res);
        dfs(arr, i + 1, n, s + arr[i], res);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        dfs(nums, left, 0, n >> 1, 0);
        dfs(nums, right, n >> 1, n, 0);
        sort(right.begin(), right.end());
        int ans = INT_MAX;
        for (int x : left) {
            int y = goal - x;
            int idx = lower_bound(right.begin(), right.end(), y) - right.begin();
            if (idx < right.size()) ans = min(ans, abs(y - right[idx]));
            if (idx) ans = min(ans, abs(y - right[idx - 1]));
        }
        return ans;
    }

private:
    void dfs(vector<int>& arr, vector<int>& res, int i, int n, int s) {
        if (i == n) {
            res.emplace_back(s);
            return;
        }
        dfs(arr, res, i + 1, n, s);
        dfs(arr, res, i + 1, n, s + arr[i]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAbsDifference(nums []int, goal int) int {
	n := len(nums)
	left := []int{}
	right := []int{}
	dfs(nums[:n>>1], &left, 0, 0)
	dfs(nums[n>>1:], &right, 0, 0)
	sort.Ints(right)
	ans := math.MaxInt32
	for _, x := range left {
		y := goal - x
		l, r := 0, len(right)
		for l < r {
			mid := (l + r) >> 1
			if right[mid] >= y {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if l < len(right) {
			ans = min(ans, abs(y-right[l]))
		}
		if l > 0 {
			ans = min(ans, abs(y-right[l-1]))
		}
	}
	return ans
}

func dfs(arr []int, res *[]int, i, s int) {
	if i == len(arr) {
		*res = append(*res, s)
		return
	}
	dfs(arr, res, i+1, s)
	dfs(arr, res, i+1, s+arr[i])
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

<p>给你一个整数数组 <code>nums</code> 和一个目标值 <code>goal</code> 。</p>

<p>你需要从 <code>nums</code> 中选出一个子序列，使子序列元素总和最接近 <code>goal</code> 。也就是说，如果子序列元素和为 <code>sum</code> ，你需要 <strong>最小化绝对差</strong> <code>abs(sum - goal)</code> 。</p>

<p>返回 <code>abs(sum - goal)</code> 可能的 <strong>最小值</strong> 。</p>

<p>注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [5,-7,3,5], goal = 6
<strong>输出：</strong>0
<strong>解释：</strong>选择整个数组作为选出的子序列，元素和为 6 。
子序列和与目标值相等，所以绝对差为 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [7,-9,15,-2], goal = -5
<strong>输出：</strong>1
<strong>解释：</strong>选出子序列 [7,-9,-2] ，元素和为 -4 。
绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3], goal = -7
<strong>输出：</strong>7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 40</code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= goal &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 二分查找

每个数选或不选两种可能，所以 $n$ 个数就有 $2^n$ 种组合，由于 $n$ 最大为 $40$，枚举 $2^{40}$ 种组合显然会超时。

我们可以把数组分成左右两部分，分别求出两部分所有子序列和，记为 $left$ 和 $right$。最后，只需找到最接近 $goal$ 的 $left[i] + right[j]$。

时间复杂度 $O(n\times 2^{n/2})$。

相似题目：

-   [1774. 最接近目标价格的甜点成本](https://github.com/doocs/leetcode/blob/main/solution/1700-1799/1774.Closest%20Dessert%20Cost/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        left = set()
        right = set()

        self.getSubSeqSum(0, 0, nums[: n // 2], left)
        self.getSubSeqSum(0, 0, nums[n // 2 :], right)

        result = inf
        right = sorted(right)
        rl = len(right)

        for l in left:
            remaining = goal - l
            idx = bisect_left(right, remaining)

            if idx < rl:
                result = min(result, abs(remaining - right[idx]))

            if idx > 0:
                result = min(result, abs(remaining - right[idx - 1]))

        return result

    def getSubSeqSum(self, i: int, curr: int, arr: List[int], result: Set[int]):
        if i == len(arr):
            result.add(curr)
            return

        self.getSubSeqSum(i + 1, curr, arr, result)
        self.getSubSeqSum(i + 1, curr + arr[i], arr, result)
```

#### Java

```java
class Solution {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        List<Integer> lsum = new ArrayList<>();
        List<Integer> rsum = new ArrayList<>();
        dfs(nums, lsum, 0, n / 2, 0);
        dfs(nums, rsum, n / 2, n, 0);

        rsum.sort(Integer::compareTo);
        int res = Integer.MAX_VALUE;

        for (Integer x : lsum) {
            int target = goal - x;
            int left = 0, right = rsum.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (rsum.get(mid) < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < rsum.size()) {
                res = Math.min(res, Math.abs(target - rsum.get(left)));
            }
            if (left > 0) {
                res = Math.min(res, Math.abs(target - rsum.get(left - 1)));
            }
        }

        return res;
    }

    private void dfs(int[] nums, List<Integer> sum, int i, int n, int cur) {
        if (i == n) {
            sum.add(cur);
            return;
        }

        dfs(nums, sum, i + 1, n, cur);
        dfs(nums, sum, i + 1, n, cur + nums[i]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> lsum;
        vector<int> rsum;
        dfs(nums, lsum, 0, n / 2, 0);
        dfs(nums, rsum, n / 2, n, 0);

        sort(rsum.begin(), rsum.end());
        int res = INT_MAX;

        for (int x : lsum) {
            int target = goal - x;
            int left = 0, right = rsum.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (rsum[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < rsum.size()) {
                res = min(res, abs(target - rsum[left]));
            }
            if (left > 0) {
                res = min(res, abs(target - rsum[left - 1]));
            }
        }

        return res;
    }

private:
    void dfs(vector<int>& nums, vector<int>& sum, int i, int n, int cur) {
        if (i == n) {
            sum.emplace_back(cur);
            return;
        }

        dfs(nums, sum, i + 1, n, cur);
        dfs(nums, sum, i + 1, n, cur + nums[i]);
    }
};
```

#### Go

```go
func minAbsDifference(nums []int, goal int) int {
	n := len(nums)
	lsum := make([]int, 0)
	rsum := make([]int, 0)

	dfs(nums[:n/2], &lsum, 0, 0)
	dfs(nums[n/2:], &rsum, 0, 0)

	sort.Ints(rsum)
	res := math.MaxInt32

	for _, x := range lsum {
		t := goal - x
		l, r := 0, len(rsum)
		for l < r {
			m := int(uint(l+r) >> 1)
			if rsum[m] < t {
				l = m + 1
			} else {
				r = m
			}
		}
		if l < len(rsum) {
			res = min(res, abs(t-rsum[l]))
		}
		if l > 0 {
			res = min(res, abs(t-rsum[l-1]))
		}
	}

	return res
}

func dfs(nums []int, sum *[]int, i, cur int) {
	if i == len(nums) {
		*sum = append(*sum, cur)
		return
	}

	dfs(nums, sum, i+1, cur)
	dfs(nums, sum, i+1, cur+nums[i])
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

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        def dfs(arr, res, i, s):
            if i == len(arr):
                res.add(s)
                return
            dfs(arr, res, i + 1, s)
            dfs(arr, res, i + 1, s + arr[i])

        n = len(nums)
        left, right = set(), set()
        dfs(nums[: n >> 1], left, 0, 0)
        dfs(nums[n >> 1 :], right, 0, 0)
        right = sorted(right)
        ans = inf
        for l in left:
            x = goal - l
            i = bisect_left(right, x)
            if i < len(right):
                ans = min(ans, abs(x - right[i]))
            if i:
                ans = min(ans, abs(x - right[i - 1]))
        return ans
```

#### Java

```java
class Solution {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        Set<Integer> left = new HashSet<>();
        Set<Integer> right = new HashSet<>();
        dfs(nums, 0, n >> 1, 0, left);
        dfs(nums, n >> 1, n, 0, right);
        List<Integer> rs = new ArrayList<>(right);
        Collections.sort(rs);
        int ans = Integer.MAX_VALUE;
        for (int x : left) {
            int y = goal - x;
            int l = 0, r = rs.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (rs.get(mid) >= y) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l < rs.size()) {
                ans = Math.min(ans, Math.abs(y - rs.get(l)));
            }
            if (l > 0) {
                ans = Math.min(ans, Math.abs(y - rs.get(l - 1)));
            }
        }
        return ans;
    }

    private void dfs(int[] arr, int i, int n, int s, Set<Integer> res) {
        if (i == n) {
            res.add(s);
            return;
        }
        dfs(arr, i + 1, n, s, res);
        dfs(arr, i + 1, n, s + arr[i], res);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        dfs(nums, left, 0, n >> 1, 0);
        dfs(nums, right, n >> 1, n, 0);
        sort(right.begin(), right.end());
        int ans = INT_MAX;
        for (int x : left) {
            int y = goal - x;
            int idx = lower_bound(right.begin(), right.end(), y) - right.begin();
            if (idx < right.size()) ans = min(ans, abs(y - right[idx]));
            if (idx) ans = min(ans, abs(y - right[idx - 1]));
        }
        return ans;
    }

private:
    void dfs(vector<int>& arr, vector<int>& res, int i, int n, int s) {
        if (i == n) {
            res.emplace_back(s);
            return;
        }
        dfs(arr, res, i + 1, n, s);
        dfs(arr, res, i + 1, n, s + arr[i]);
    }
};
```

#### Go

```go
func minAbsDifference(nums []int, goal int) int {
	n := len(nums)
	left := []int{}
	right := []int{}
	dfs(nums[:n>>1], &left, 0, 0)
	dfs(nums[n>>1:], &right, 0, 0)
	sort.Ints(right)
	ans := math.MaxInt32
	for _, x := range left {
		y := goal - x
		l, r := 0, len(right)
		for l < r {
			mid := (l + r) >> 1
			if right[mid] >= y {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if l < len(right) {
			ans = min(ans, abs(y-right[l]))
		}
		if l > 0 {
			ans = min(ans, abs(y-right[l-1]))
		}
	}
	return ans
}

func dfs(arr []int, res *[]int, i, s int) {
	if i == len(arr) {
		*res = append(*res, s)
		return
	}
	dfs(arr, res, i+1, s)
	dfs(arr, res, i+1, s+arr[i])
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

# [1756. 设计最近使用（MRU）队列 🔒](https://leetcode.cn/problems/design-most-recently-used-queue){#1756}

{{< tabs "1756" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class MRUQueue:
    def __init__(self, n: int):
        self.q = list(range(n + 1))
        self.tree = BinaryIndexedTree(n + 2010)

    def fetch(self, k: int) -> int:
        l, r = 1, len(self.q)
        while l < r:
            mid = (l + r) >> 1
            if mid - self.tree.query(mid) >= k:
                r = mid
            else:
                l = mid + 1
        x = self.q[l]
        self.q.append(x)
        self.tree.update(l, 1)
        return x


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class MRUQueue {
    private int n;
    private int[] q;
    private BinaryIndexedTree tree;

    public MRUQueue(int n) {
        this.n = n;
        q = new int[n + 2010];
        for (int i = 1; i <= n; ++i) {
            q[i] = i;
        }
        tree = new BinaryIndexedTree(n + 2010);
    }

    public int fetch(int k) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - tree.query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int x = q[l];
        q[++n] = x;
        tree.update(l, 1);
        return x;
    }
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue obj = new MRUQueue(n);
 * int param_1 = obj.fetch(k);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class MRUQueue {
public:
    MRUQueue(int n) {
        q.resize(n + 1);
        iota(q.begin() + 1, q.end(), 1);
        tree = new BinaryIndexedTree(n + 2010);
    }

    int fetch(int k) {
        int l = 1, r = q.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - tree->query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int x = q[l];
        q.push_back(x);
        tree->update(l, 1);
        return x;
    }

private:
    vector<int> q;
    BinaryIndexedTree* tree;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

type MRUQueue struct {
	q    []int
	tree *BinaryIndexedTree
}

func Constructor(n int) MRUQueue {
	q := make([]int, n+1)
	for i := 1; i <= n; i++ {
		q[i] = i
	}
	return MRUQueue{q, newBinaryIndexedTree(n + 2010)}
}

func (this *MRUQueue) Fetch(k int) int {
	l, r := 1, len(this.q)
	for l < r {
		mid := (l + r) >> 1
		if mid-this.tree.query(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	x := this.q[l]
	this.q = append(this.q, x)
	this.tree.update(l, 1)
	return x
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Fetch(k);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    public update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    public query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

class MRUQueue {
    private q: number[];
    private tree: BinaryIndexedTree;

    constructor(n: number) {
        this.q = new Array(n + 1);
        for (let i = 1; i <= n; ++i) {
            this.q[i] = i;
        }
        this.tree = new BinaryIndexedTree(n + 2010);
    }

    fetch(k: number): number {
        let l = 1;
        let r = this.q.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (mid - this.tree.query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        const x = this.q[l];
        this.q.push(x);
        this.tree.update(l, 1);
        return x;
    }
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * var obj = new MRUQueue(n)
 * var param_1 = obj.fetch(k)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一种类似队列的数据结构，该数据结构将最近使用的元素移到队列尾部。</p>

<p>实现 <code>MRUQueue</code> 类：</p>

<ul>
	<li><code>MRUQueue(int n)</code>  使用 <code>n</code> 个元素： <code>[1,2,3,...,n]</code> 构造 <code>MRUQueue</code> 。</li>
	<li><code>fetch(int k)</code> 将第 <code>k</code> 个元素<strong>（从 1 开始索引）</strong>移到队尾，并返回该元素。</li>
</ul>

<p> </p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
<strong>输出：</strong>
[null, 3, 6, 2, 2]

<strong>解释：</strong>
MRUQueue mRUQueue = new MRUQueue(8); // 初始化队列为 [1,2,3,4,5,6,7,8]。
mRUQueue.fetch(3); // 将第 3 个元素 (3) 移到队尾，使队列变为 [1,2,4,5,6,7,8,3] 并返回该元素。
mRUQueue.fetch(5); // 将第 5 个元素 (6) 移到队尾，使队列变为 [1,2,4,5,7,8,3,6] 并返回该元素。
mRUQueue.fetch(2); // 将第 2 个元素 (2) 移到队尾，使队列变为 [1,4,5,7,8,3,6,2] 并返回该元素。
mRUQueue.fetch(8); // 第 8 个元素 (2) 已经在队列尾部了，所以直接返回该元素即可。
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 <= n <= 2000</code></li>
	<li><code>1 <= k <= n</code></li>
	<li>最多调用 <code>2000</code> 次 <code>fetch</code></li>
</ul>

<p> </p>
<b>进阶：</b>找到每次 <code>fetch</code> 的复杂度为 <code>O(n)</code> 的算法比较简单。你可以找到每次 <code>fetch</code> 的复杂度更佳的算法吗？

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组 + 二分查找

我们用一个数组 $q$ 维护当前队列中的元素，移动第 $k$ 个元素时，我们考虑不删除该元素，而是直接将其追加到数组末尾。如果不删除，我们如何知道第 $k$ 个元素在数组 $q$ 中的位置呢？

我们可以用一个树状数组维护数组 $q$ 中每个位置的元素是否被删除，如果第 $i$ 个位置的元素被删除，那么我们更新树状数组中的第 $i$ 个位置，表示该位置被移动的次数增加 $1$。这样，我们每次要删除第 $k$ 个元素时，可以用二分查找，找到第一个满足 $i - tree.query(i) \geq k$ 的位置 $i$，即为第 $k$ 个元素在数组 $q$ 中的位置。不妨记 $x=q[i]$，那么我们将 $x$ 追加到数组 $q$ 的末尾，同时更新树状数组中第 $i$ 个位置的值，表示该位置被移动的次数增加 $1$。最后，我们返回 $x$ 即可。

时间复杂度 $(\log ^2 n)$，空间复杂度 $O(n)$。其中 $n$ 为队列的长度。

<!-- tabs:start -->

#### Python3

```python
class MRUQueue:
    def __init__(self, n: int):
        self.q = list(range(1, n + 1))

    def fetch(self, k: int) -> int:
        ans = self.q[k - 1]
        self.q[k - 1 : k] = []
        self.q.append(ans)
        return ans


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class MRUQueue {
    private int n;
    private int[] q;
    private BinaryIndexedTree tree;

    public MRUQueue(int n) {
        this.n = n;
        q = new int[n + 2010];
        for (int i = 1; i <= n; ++i) {
            q[i] = i;
        }
        tree = new BinaryIndexedTree(n + 2010);
    }

    public int fetch(int k) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - tree.query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int x = q[l];
        q[++n] = x;
        tree.update(l, 1);
        return x;
    }
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue obj = new MRUQueue(n);
 * int param_1 = obj.fetch(k);
 */
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class MRUQueue {
public:
    MRUQueue(int n) {
        q.resize(n + 1);
        iota(q.begin() + 1, q.end(), 1);
        tree = new BinaryIndexedTree(n + 2010);
    }

    int fetch(int k) {
        int l = 1, r = q.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - tree->query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int x = q[l];
        q.push_back(x);
        tree->update(l, 1);
        return x;
    }

private:
    vector<int> q;
    BinaryIndexedTree* tree;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

type MRUQueue struct {
	q    []int
	tree *BinaryIndexedTree
}

func Constructor(n int) MRUQueue {
	q := make([]int, n+1)
	for i := 1; i <= n; i++ {
		q[i] = i
	}
	return MRUQueue{q, newBinaryIndexedTree(n + 2010)}
}

func (this *MRUQueue) Fetch(k int) int {
	l, r := 1, len(this.q)
	for l < r {
		mid := (l + r) >> 1
		if mid-this.tree.query(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	x := this.q[l]
	this.q = append(this.q, x)
	this.tree.update(l, 1)
	return x
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Fetch(k);
 */
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    public update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    public query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

class MRUQueue {
    private q: number[];
    private tree: BinaryIndexedTree;

    constructor(n: number) {
        this.q = new Array(n + 1);
        for (let i = 1; i <= n; ++i) {
            this.q[i] = i;
        }
        this.tree = new BinaryIndexedTree(n + 2010);
    }

    fetch(k: number): number {
        let l = 1;
        let r = this.q.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (mid - this.tree.query(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        const x = this.q[l];
        this.q.push(x);
        this.tree.update(l, 1);
        return x;
    }
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * var obj = new MRUQueue(n)
 * var param_1 = obj.fetch(k)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class MRUQueue:
    def __init__(self, n: int):
        self.q = list(range(n + 1))
        self.tree = BinaryIndexedTree(n + 2010)

    def fetch(self, k: int) -> int:
        l, r = 1, len(self.q)
        while l < r:
            mid = (l + r) >> 1
            if mid - self.tree.query(mid) >= k:
                r = mid
            else:
                l = mid + 1
        x = self.q[l]
        self.q.append(x)
        self.tree.update(l, 1)
        return x


# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1757. 可回收且低脂的产品](https://leetcode.cn/problems/recyclable-and-low-fat-products){#1757}

{{< tabs "1757" >}}

{{% tab "python" %}}
```python
import pandas as pd


def find_products(products: pd.DataFrame) -> pd.DataFrame:
    rs = products[(products["low_fats"] == "Y") & (products["recyclable"] == "Y")]
    rs = rs[["product_id"]]
    return rs
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
SELECT
    product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
<code>product_id</code> 是该表的主键（具有唯一值的列）。
low_fats 是枚举类型，取值为以下两种 ('Y', 'N')，其中 'Y' 表示该产品是低脂产品，'N' 表示不是低脂产品。
recyclable 是枚举类型，取值为以下两种 ('Y', 'N')，其中 'Y' 表示该产品可回收，而 'N' 表示不可回收。</pre>

<p>&nbsp;</p>

<p>编写解决方案找出既是低脂又是可回收的产品编号。</p>

<p>返回结果 <strong>无顺序要求</strong> 。</p>

<p>返回结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Products 表：
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
<strong>输出：</strong>
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
<strong>解释：</strong>
只有产品 id 为 1 和 3 的产品，既是低脂又是可回收的产品。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件筛选

我们直接筛选出 `low_fats` 为 `Y` 且 `recyclable` 为 `Y` 的产品编号即可。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def find_products(products: pd.DataFrame) -> pd.DataFrame:
    rs = products[(products["low_fats"] == "Y") & (products["recyclable"] == "Y")]
    rs = rs[["product_id"]]
    return rs
```

#### MySQL

```sql
SELECT
    product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1758. 生成交替二进制字符串的最少操作数](https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string){#1758}

{{< tabs "1758" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, s: str) -> int:
        cnt = sum(c != '01'[i & 1] for i, c in enumerate(s))
        return min(cnt, len(s) - cnt)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(String s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt += (s.charAt(i) != "01".charAt(i & 1) ? 1 : 0);
        }
        return Math.min(cnt, n - cnt);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) cnt += s[i] != "01"[i & 1];
        return min(cnt, n - cnt);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(s string) int {
	cnt := 0
	for i, c := range s {
		if c != []rune("01")[i&1] {
			cnt++
		}
	}
	return min(cnt, len(s)-cnt)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(s: string): number {
    const n = s.length;
    let count = 0;
    for (let i = 0; i < n; i++) {
        count += s[i] !== '01'[i & 1] ? 1 : 0;
    }
    return Math.min(count, n - count);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let cs = [b'0', b'1'];
        let mut count = 0;
        for i in 0..n {
            count += if s[i] != cs[i & 1] { 1 } else { 0 };
        }
        count.min(n - count) as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minOperations(char* s) {
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += s[i] != ('0' + (i & 1)) ? 0 : 1;
    }
    return min(count, n - count);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅由字符 <code>'0'</code> 和 <code>'1'</code> 组成的字符串 <code>s</code> 。一步操作中，你可以将任一 <code>'0'</code> 变成 <code>'1'</code> ，或者将 <code>'1'</code> 变成 <code>'0'</code> 。</p>

<p><strong>交替字符串</strong> 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 <code>"010"</code> 是交替字符串，而字符串 <code>"0100"</code> 不是。</p>

<p>返回使 <code>s</code> 变成 <strong>交替字符串</strong> 所需的 <strong>最少</strong> 操作数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "0100"
<strong>输出：</strong>1
<strong>解释：</strong>如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "10"
<strong>输出：</strong>0
<strong>解释：</strong>s 已经是交替字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "1111"
<strong>输出：</strong>2
<strong>解释：</strong>需要 2 步操作得到 "0101" 或 "1010" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

根据题意，如果得到交替字符串 `01010101...` 所需要的操作数为 $cnt$，那么得到交替字符串 `10101010...` 所需要的操作数为 $n - cnt$。

因此，我们只需要遍历一次字符串 $s$，统计出 $cnt$ 的值，那么答案即为 $\min(cnt, n - cnt)$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, s: str) -> int:
        cnt = sum(c != '01'[i & 1] for i, c in enumerate(s))
        return min(cnt, len(s) - cnt)
```

#### Java

```java
class Solution {
    public int minOperations(String s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt += (s.charAt(i) != "01".charAt(i & 1) ? 1 : 0);
        }
        return Math.min(cnt, n - cnt);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) cnt += s[i] != "01"[i & 1];
        return min(cnt, n - cnt);
    }
};
```

#### Go

```go
func minOperations(s string) int {
	cnt := 0
	for i, c := range s {
		if c != []rune("01")[i&1] {
			cnt++
		}
	}
	return min(cnt, len(s)-cnt)
}
```

#### TypeScript

```ts
function minOperations(s: string): number {
    const n = s.length;
    let count = 0;
    for (let i = 0; i < n; i++) {
        count += s[i] !== '01'[i & 1] ? 1 : 0;
    }
    return Math.min(count, n - count);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let cs = [b'0', b'1'];
        let mut count = 0;
        for i in 0..n {
            count += if s[i] != cs[i & 1] { 1 } else { 0 };
        }
        count.min(n - count) as i32
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minOperations(char* s) {
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += s[i] != ('0' + (i & 1)) ? 0 : 1;
    }
    return min(count, n - count);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1759. 统计同质子字符串的数目](https://leetcode.cn/problems/count-number-of-homogenous-substrings){#1759}

{{< tabs "1759" >}}

{{% tab "python" %}}
```python
class Solution:
    def countHomogenous(self, s: str) -> int:
        mod = 10**9 + 7
        ans = cnt = 1
        for a, b in pairwise(s):
            cnt = cnt + 1 if a == b else 1
            ans = (ans + cnt) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countHomogenous(String s) {
        int n = s.length();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s.charAt(i) == s.charAt(i - 1) ? cnt + 1 : 1;
            ans = (ans + cnt) % MOD;
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
    const int mod = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countHomogenous(s string) int {
	n := len(s)
	const mod int = 1e9 + 7
	ans, cnt := 1, 1
	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			cnt++
		} else {
			cnt = 1
		}
		ans = (ans + cnt) % mod
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countHomogenous(s: string): number {
    const mod = 1e9 + 7;
    const n = s.length;
    let ans = 0;
    for (let i = 0, j = 0; j < n; j++) {
        if (s[i] !== s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % mod;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_homogenous(s: String) -> i32 {
        const MOD: usize = (1e9 as usize) + 7;
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        for j in 0..n {
            if s[i] != s[j] {
                i = j;
            }
            ans = (ans + j - i + 1) % MOD;
        }
        ans as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountHomogenous(string s) {
        long MOD = 1000000007;
        long ans = 0;
        for (int i = 0, j = 0; i < s.Length; i = j) {
            j = i;
            while (j < s.Length && s[j] == s[i]) {
                ++j;
            }
            int cnt = j - i;
            ans += (long) (1 + cnt) * cnt / 2;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countHomogenous(char* s) {
    int MOD = 1e9 + 7;
    int ans = 0;
    for (int i = 0, j = 0; s[j]; j++) {
        if (s[i] != s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % MOD;
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

<p>给你一个字符串 <code>s</code> ，返回<em> </em><code>s</code><em> </em>中 <strong>同质子字符串</strong> 的数目。由于答案可能很大，只需返回对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>后的结果。</p>

<p><strong>同质字符串</strong> 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同质字符串。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abbcccaa"
<strong>输出：</strong>13
<strong>解释：</strong>同质子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "xy"
<strong>输出：</strong>2
<strong>解释：</strong>同质子字符串是 "x" 和 "y" 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "zzzzz"
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写字符串组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

遍历字符串 $s$，用指针 $i$ 指向当前字符，指针 $j$ 指向下一个不同的字符，那么 $[i,..j-1]$ 区间内的字符都是相同的，假设 $cnt=j-i$，那么该区间内的同构子字符串个数为 $\frac{(1 + cnt) \times cnt}{2}$，将其累加到答案中即可。继续遍历，直到指针 $i$ 到达字符串末尾。

遍历完字符串 $s$ 后，返回答案即可。注意答案的取模操作。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countHomogenous(self, s: str) -> int:
        mod = 10**9 + 7
        i, n = 0, len(s)
        ans = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            cnt = j - i
            ans += (1 + cnt) * cnt // 2
            ans %= mod
            i = j
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countHomogenous(String s) {
        int n = s.length();
        long ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            int cnt = j - i;
            ans += (long) (1 + cnt) * cnt / 2;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();
        long ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            while (j < n && s[j] == s[i]) ++j;
            int cnt = j - i;
            ans += 1ll * (1 + cnt) * cnt / 2;
            ans %= mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countHomogenous(s string) (ans int) {
	n := len(s)
	const mod int = 1e9 + 7
	for i, j := 0, 0; i < n; i = j {
		j = i
		for j < n && s[j] == s[i] {
			j++
		}
		cnt := j - i
		ans += (1 + cnt) * cnt / 2
		ans %= mod
	}
	return
}
```

#### TypeScript

```ts
function countHomogenous(s: string): number {
    const mod = 1e9 + 7;
    const n = s.length;
    let ans = 0;
    for (let i = 0, j = 0; j < n; j++) {
        if (s[i] !== s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % mod;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_homogenous(s: String) -> i32 {
        const MOD: usize = (1e9 as usize) + 7;
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        for j in 0..n {
            if s[i] != s[j] {
                i = j;
            }
            ans = (ans + j - i + 1) % MOD;
        }
        ans as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int CountHomogenous(string s) {
        long MOD = 1000000007;
        long ans = 0;
        for (int i = 0, j = 0; i < s.Length; i = j) {
            j = i;
            while (j < s.Length && s[j] == s[i]) {
                ++j;
            }
            int cnt = j - i;
            ans += (long) (1 + cnt) * cnt / 2;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```

#### C

```c
int countHomogenous(char* s) {
    int MOD = 1e9 + 7;
    int ans = 0;
    for (int i = 0, j = 0; s[j]; j++) {
        if (s[i] != s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % MOD;
    }
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
    def countHomogenous(self, s: str) -> int:
        mod = 10**9 + 7
        ans = cnt = 1
        for a, b in pairwise(s):
            cnt = cnt + 1 if a == b else 1
            ans = (ans + cnt) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countHomogenous(String s) {
        int n = s.length();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s.charAt(i) == s.charAt(i - 1) ? cnt + 1 : 1;
            ans = (ans + cnt) % MOD;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countHomogenous(s string) int {
	n := len(s)
	const mod int = 1e9 + 7
	ans, cnt := 1, 1
	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			cnt++
		} else {
			cnt = 1
		}
		ans = (ans + cnt) % mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

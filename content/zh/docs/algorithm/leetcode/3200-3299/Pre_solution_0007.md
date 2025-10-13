---
title: "3260_找出最大的 N 位 K 回文数"
date: 2025-10-08T18:40:15+08:00
weight: 7
tags: [二分查找, 前缀和, 动态规划, 双向链表, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 数论, 枚举, 模拟, 滑动窗口, 计数, 贪心, 链表]
---

{{< markmap >}}
### [3260_找出最大的 N 位 K 回文数](#3260)
#### [贪心](#3260)
#### [数学](#3260)
#### [字符串](#3260)
#### [动态规划](#3260)
#### [数论](#3260)
### [3261_统计满足 K 约束的子字符串数量 II](#3261)
#### [数组](#3261)
#### [字符串](#3261)
#### [二分查找](#3261)
#### [前缀和](#3261)
#### [滑动窗口](#3261)
### [3262_查找重叠的班次 🔒](#3262)
#### [数据库](#3262)
### [3263_将双链表转换为数组 I 🔒](#3263)
#### [数组](#3263)
#### [链表](#3263)
#### [双向链表](#3263)
### [3264_K 次乘运算后的最终数组 I](#3264)
#### [数组](#3264)
#### [数学](#3264)
#### [模拟](#3264)
#### [堆（优先队列）](#3264)
### [3265_统计近似相等数对 I](#3265)
#### [数组](#3265)
#### [哈希表](#3265)
#### [计数](#3265)
#### [枚举](#3265)
#### [排序](#3265)
### [3266_K 次乘运算后的最终数组 II](#3266)
#### [数组](#3266)
#### [模拟](#3266)
#### [堆（优先队列）](#3266)
### [3267_统计近似相等数对 II](#3267)
#### [数组](#3267)
#### [哈希表](#3267)
#### [计数](#3267)
#### [枚举](#3267)
#### [排序](#3267)
### [3268_查找重叠的班次 II 🔒](#3268)
#### [数据库](#3268)
### [3269_构建两个递增数组 🔒](#3269)
#### [数组](#3269)
#### [动态规划](#3269)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3260_找出最大的 N 位 K 回文数
___
#### 贪心
___
#### 数学
___
#### 字符串
___
#### 动态规划
___
#### 数论
---
### 3261_统计满足 K 约束的子字符串数量 II
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 3262_查找重叠的班次 🔒
___
#### 数据库
---
### 3263_将双链表转换为数组 I 🔒
___
#### 数组
___
#### 链表
___
#### 双向链表
---
### 3264_K 次乘运算后的最终数组 I
___
#### 数组
___
#### 数学
___
#### 模拟
___
#### 堆（优先队列）
---
### 3265_统计近似相等数对 I
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 枚举
___
#### 排序
---
### 3266_K 次乘运算后的最终数组 II
___
#### 数组
___
#### 模拟
___
#### 堆（优先队列）
---
### 3267_统计近似相等数对 II
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 枚举
___
#### 排序
---
### 3268_查找重叠的班次 II 🔒
___
#### 数据库
---
### 3269_构建两个递增数组 🔒
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双向链表 | 哈希表 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 枚举 | 模拟 | 滑动窗口 |
| 计数 | 贪心 | 链表 |

# [3260. 找出最大的 N 位 K 回文数](https://leetcode.cn/problems/find-the-largest-palindrome-divisible-by-k){#3260}

{{< tabs "3260" >}}

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

<p>给你两个 <strong>正整数</strong> <code>n</code> 和 <code>k</code>。</p>

<p>如果整数 <code>x</code> 满足以下全部条件，则该整数是一个 <strong>k 回文数</strong>：</p>

<ul>
	<li><code>x</code> 是一个 <span data-keyword="palindrome-integer">回文数</span>。</li>
	<li><code>x</code> 可以被 <code>k</code> 整除。</li>
</ul>

<p>以字符串形式返回 <strong>最大的&nbsp;</strong> <code>n</code> 位 <strong>k 回文数</strong>。</p>

<p><strong>注意</strong>，该整数 <strong>不 </strong>含前导零。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 3, k = 5</span></p>

<p><strong>输出：</strong> <span class="example-io">"595"</span></p>

<p><strong>解释：</strong></p>

<p>595 是最大的 3 位 k 回文数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 1, k = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">"8"</span></p>

<p><strong>解释：</strong></p>

<p>1 位 k 回文数只有 4 和 8。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5, k = 6</span></p>

<p><strong>输出：</strong> <span class="example-io">"89898"</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 9</code></li>
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

# [3261. 统计满足 K 约束的子字符串数量 II](https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii){#3261}

{{< tabs "3261" >}}

{{% tab "python" %}}
```python
class Solution:
    def countKConstraintSubstrings(
        self, s: str, k: int, queries: List[List[int]]
    ) -> List[int]:
        cnt = [0, 0]
        i, n = 0, len(s)
        d = [n] * n
        pre = [0] * (n + 1)
        for j, x in enumerate(map(int, s)):
            cnt[x] += 1
            while cnt[0] > k and cnt[1] > k:
                d[i] = j
                cnt[int(s[i])] -= 1
                i += 1
            pre[j + 1] = pre[j] + j - i + 1
        ans = []
        for l, r in queries:
            p = min(r + 1, d[l])
            a = (1 + p - l) * (p - l) // 2
            b = pre[r + 1] - pre[p]
            ans.append(a + b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] countKConstraintSubstrings(String s, int k, int[][] queries) {
        int[] cnt = new int[2];
        int n = s.length();
        int[] d = new int[n];
        Arrays.fill(d, n);
        long[] pre = new long[n + 1];
        for (int i = 0, j = 0; j < n; ++j) {
            cnt[s.charAt(j) - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                d[i] = j;
                cnt[s.charAt(i++) - '0']--;
            }
            pre[j + 1] = pre[j] + j - i + 1;
        }
        int m = queries.length;
        long[] ans = new long[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            int p = Math.min(r + 1, d[l]);
            long a = (1L + p - l) * (p - l) / 2;
            long b = pre[r + 1] - pre[p];
            ans[i] = a + b;
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
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int cnt[2]{};
        int n = s.size();
        vector<int> d(n, n);
        long long pre[n + 1];
        pre[0] = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            cnt[s[j] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                d[i] = j;
                cnt[s[i++] - '0']--;
            }
            pre[j + 1] = pre[j] + j - i + 1;
        }
        vector<long long> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int p = min(r + 1, d[l]);
            long long a = (1LL + p - l) * (p - l) / 2;
            long long b = pre[r + 1] - pre[p];
            ans.push_back(a + b);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKConstraintSubstrings(s string, k int, queries [][]int) (ans []int64) {
	cnt := [2]int{}
	n := len(s)
	d := make([]int, n)
	for i := range d {
		d[i] = n
	}
	pre := make([]int, n+1)
	for i, j := 0, 0; j < n; j++ {
		cnt[s[j]-'0']++
		for cnt[0] > k && cnt[1] > k {
			d[i] = j
			cnt[s[i]-'0']--
			i++
		}
		pre[j+1] = pre[j] + j - i + 1
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		p := min(r+1, d[l])
		a := (1 + p - l) * (p - l) / 2
		b := pre[r+1] - pre[p]
		ans = append(ans, int64(a+b))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKConstraintSubstrings(s: string, k: number, queries: number[][]): number[] {
    const cnt: [number, number] = [0, 0];
    const n = s.length;
    const d: number[] = Array(n).fill(n);
    const pre: number[] = Array(n + 1).fill(0);
    for (let i = 0, j = 0; j < n; ++j) {
        cnt[+s[j]]++;
        while (Math.min(cnt[0], cnt[1]) > k) {
            d[i] = j;
            cnt[+s[i++]]--;
        }
        pre[j + 1] = pre[j] + j - i + 1;
    }
    const ans: number[] = [];
    for (const [l, r] of queries) {
        const p = Math.min(r + 1, d[l]);
        const a = ((1 + p - l) * (p - l)) / 2;
        const b = pre[r + 1] - pre[p];
        ans.push(a + b);
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

<p>给你一个 <strong>二进制</strong> 字符串 <code>s</code> 和一个整数 <code>k</code>。</p>

<p>另给你一个二维整数数组 <code>queries</code> ，其中 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> 。</p>

<p>如果一个 <strong>二进制字符串</strong> 满足以下任一条件，则认为该字符串满足 <strong>k 约束</strong>：</p>

<ul>
	<li>字符串中 <code>0</code> 的数量最多为 <code>k</code>。</li>
	<li>字符串中 <code>1</code> 的数量最多为 <code>k</code>。</li>
</ul>

<p>返回一个整数数组 <code>answer</code> ，其中 <code>answer[i]</code> 表示 <code>s[l<sub>i</sub>..r<sub>i</sub>]</code> 中满足 <strong>k 约束</strong> 的 <span data-keyword="substring-nonempty">子字符串</span> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "0001111", k = 2, queries = [[0,6]]</span></p>

<p><strong>输出：</strong><span class="example-io">[26]</span></p>

<p><strong>解释：</strong></p>

<p>对于查询 <code>[0, 6]</code>， <code>s[0..6] = "0001111"</code> 的所有子字符串中，除 <code>s[0..5] = "000111"</code> 和 <code>s[0..6] = "0001111"</code> 外，其余子字符串都满足 k 约束。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]</span></p>

<p><strong>输出：</strong><span class="example-io">[15,9,3]</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串中，长度大于 3 的子字符串都不满足 k 约束。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i] == [l<sub>i</sub>, r<sub>i</sub>]</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; s.length</code></li>
	<li>所有查询互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 前缀和

我们用两个变量 $\textit{cnt0}$ 和 $\textit{cnt1}$ 分别记录当前窗口内的 $0$ 和 $1$ 的个数，指针 $i$ 和 $j$ 分别标识窗口的左右边界。用一个数组 $d$ 记录每个位置 $i$ 右边第一个不满足 $k$ 约束的位置，初始时 $d[i] = n$。另外，用一个长度为 $n + 1$ 的前缀和数组 $\textit{pre}[i]$ 记录以前 $i$ 个位置作为右边界的满足 $k$ 约束的子字符串的个数。

当我们右移窗口时，如果窗口内的 $0$ 和 $1$ 的个数都大于 $k$，我们将 $d[i]$ 更新为 $j$，表示位置 $i$ 右边第一个不满足 $k$ 约束的位置。然后我们将 $i$ 右移一位，直到窗口内的 $0$ 和 $1$ 的个数都不大于 $k$。此时，我们可以计算出以 $j$ 为右边界的满足 $k$ 约束的子字符串的个数，即 $j - i + 1$，我们更新到前缀和数组中。

最后，对于每个查询 $[l, r]$，我们首先找出 $l$ 右边第一个不满足 $k$ 约束的位置 $p$，那么 $p = \min(r + 1, d[l])$，那么 $[l, p - 1]$ 的所有子字符串都满足 $k$ 约束，个数为 $(1 + p - l) \times (p - l) / 2$，然后，我们计算以 $[p, r]$ 为右边界的满足 $k$ 约束的子字符串的个数，即 $\textit{pre}[r + 1] - \textit{pre}[p]$，最后将两者相加即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 的长度和查询数组 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKConstraintSubstrings(
        self, s: str, k: int, queries: List[List[int]]
    ) -> List[int]:
        cnt = [0, 0]
        i, n = 0, len(s)
        d = [n] * n
        pre = [0] * (n + 1)
        for j, x in enumerate(map(int, s)):
            cnt[x] += 1
            while cnt[0] > k and cnt[1] > k:
                d[i] = j
                cnt[int(s[i])] -= 1
                i += 1
            pre[j + 1] = pre[j] + j - i + 1
        ans = []
        for l, r in queries:
            p = min(r + 1, d[l])
            a = (1 + p - l) * (p - l) // 2
            b = pre[r + 1] - pre[p]
            ans.append(a + b)
        return ans
```

#### Java

```java
class Solution {
    public long[] countKConstraintSubstrings(String s, int k, int[][] queries) {
        int[] cnt = new int[2];
        int n = s.length();
        int[] d = new int[n];
        Arrays.fill(d, n);
        long[] pre = new long[n + 1];
        for (int i = 0, j = 0; j < n; ++j) {
            cnt[s.charAt(j) - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                d[i] = j;
                cnt[s.charAt(i++) - '0']--;
            }
            pre[j + 1] = pre[j] + j - i + 1;
        }
        int m = queries.length;
        long[] ans = new long[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            int p = Math.min(r + 1, d[l]);
            long a = (1L + p - l) * (p - l) / 2;
            long b = pre[r + 1] - pre[p];
            ans[i] = a + b;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int cnt[2]{};
        int n = s.size();
        vector<int> d(n, n);
        long long pre[n + 1];
        pre[0] = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            cnt[s[j] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                d[i] = j;
                cnt[s[i++] - '0']--;
            }
            pre[j + 1] = pre[j] + j - i + 1;
        }
        vector<long long> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int p = min(r + 1, d[l]);
            long long a = (1LL + p - l) * (p - l) / 2;
            long long b = pre[r + 1] - pre[p];
            ans.push_back(a + b);
        }
        return ans;
    }
};
```

#### Go

```go
func countKConstraintSubstrings(s string, k int, queries [][]int) (ans []int64) {
	cnt := [2]int{}
	n := len(s)
	d := make([]int, n)
	for i := range d {
		d[i] = n
	}
	pre := make([]int, n+1)
	for i, j := 0, 0; j < n; j++ {
		cnt[s[j]-'0']++
		for cnt[0] > k && cnt[1] > k {
			d[i] = j
			cnt[s[i]-'0']--
			i++
		}
		pre[j+1] = pre[j] + j - i + 1
	}
	for _, q := range queries {
		l, r := q[0], q[1]
		p := min(r+1, d[l])
		a := (1 + p - l) * (p - l) / 2
		b := pre[r+1] - pre[p]
		ans = append(ans, int64(a+b))
	}
	return
}
```

#### TypeScript

```ts
function countKConstraintSubstrings(s: string, k: number, queries: number[][]): number[] {
    const cnt: [number, number] = [0, 0];
    const n = s.length;
    const d: number[] = Array(n).fill(n);
    const pre: number[] = Array(n + 1).fill(0);
    for (let i = 0, j = 0; j < n; ++j) {
        cnt[+s[j]]++;
        while (Math.min(cnt[0], cnt[1]) > k) {
            d[i] = j;
            cnt[+s[i++]]--;
        }
        pre[j + 1] = pre[j] + j - i + 1;
    }
    const ans: number[] = [];
    for (const [l, r] of queries) {
        const p = Math.min(r + 1, d[l]);
        const a = ((1 + p - l) * (p - l)) / 2;
        const b = pre[r + 1] - pre[p];
        ans.push(a + b);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3262. 查找重叠的班次 🔒](https://leetcode.cn/problems/find-overlapping-shifts){#3262}

{{< tabs "3262" >}}

{{% tab "sql" %}}
```sql
SELECT
    t1.employee_id,
    COUNT(*) AS overlapping_shifts
FROM
    EmployeeShifts t1
    JOIN EmployeeShifts t2
        ON t1.employee_id = t2.employee_id
        AND t1.start_time < t2.start_time
        AND t1.end_time > t2.start_time
GROUP BY 1
HAVING overlapping_shifts > 0
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_overlapping_shifts(employee_shifts: pd.DataFrame) -> pd.DataFrame:
    merged_shifts = employee_shifts.merge(
        employee_shifts, on="employee_id", suffixes=("_t1", "_t2")
    )
    overlapping_shifts = merged_shifts[
        (merged_shifts["start_time_t1"] < merged_shifts["start_time_t2"])
        & (merged_shifts["end_time_t1"] > merged_shifts["start_time_t2"])
    ]
    result = (
        overlapping_shifts.groupby("employee_id")
        .size()
        .reset_index(name="overlapping_shifts")
    )
    result = result[result["overlapping_shifts"] > 0]
    result = result.sort_values("employee_id").reset_index(drop=True)
    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>EmployeeShifts</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| start_time       | time    |
| end_time         | time    |
+------------------+---------+
(employee_id, start_time) 是此表的唯一主键。
这张表包含员工的排班工作，包括特定日期的开始和结束时间。
</pre>

<p>编写一个解决方案来为每个员工计算&nbsp;<strong>重叠排班</strong>&nbsp;的数量。如果一个排班的&nbsp;<code>end_time</code>&nbsp;比另一个排班的&nbsp;<code>start_time</code>&nbsp;<strong>更晚&nbsp;</strong>则认为两个排班重叠。</p>

<p>返回结果表以&nbsp;<code>employee_id</code> <strong>升序&nbsp;</strong>排序。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><b>示例：</b></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>EmployeeShifts</code> 表：</p>

<pre class="example-io">
+-------------+------------+----------+
| employee_id | start_time | end_time |
+-------------+------------+----------+
| 1           | 08:00:00   | 12:00:00 |
| 1           | 11:00:00   | 15:00:00 |
| 1           | 14:00:00   | 18:00:00 |
| 2           | 09:00:00   | 17:00:00 |
| 2           | 16:00:00   | 20:00:00 |
| 3           | 10:00:00   | 12:00:00 |
| 3           | 13:00:00   | 15:00:00 |
| 3           | 16:00:00   | 18:00:00 |
| 4           | 08:00:00   | 10:00:00 |
| 4           | 09:00:00   | 11:00:00 |
+-------------+------------+----------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+--------------------+
| employee_id | overlapping_shifts |
+-------------+--------------------+
| 1           | 2                  |
| 2           | 1                  |
| 4           | 1                  |
+-------------+--------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>员工 1 有 3 个排班：
	<ul>
		<li>08:00:00 到 12:00:00</li>
		<li>11:00:00 到 15:00:00</li>
		<li>14:00:00 到 18:00:00</li>
	</ul>
	第一个排班与第二个排班重叠，第二个排班与第三个排班重叠，因此有 2&nbsp;个重叠排班。</li>
	<li>员工 2&nbsp;有 2 个排班：
	<ul>
		<li>09:00:00 到 17:00:00</li>
		<li>16:00:00 到 20:00:00</li>
	</ul>
	这些排班彼此重叠，因此有 1 个重叠排班。</li>
	<li>员工 3 有 3 个排班：
	<ul>
		<li>10:00:00 到 12:00:00</li>
		<li>13:00:00 到 15:00:00</li>
		<li>16:00:00 到 18:00:00</li>
	</ul>
	这些排班没有重叠，所以员工 3 不包含在输出中。</li>
	<li>员工 4 有 2 个排班：
	<ul>
		<li>08:00:00 到 10:00:00</li>
		<li>09:00:00 到 11:00:00</li>
	</ul>
	这些排班彼此重叠，因此有 1 个重叠排班。</li>
</ul>

<p>输出展示了 employee_id 和至少有一个重叠排班的员工的重叠排班的数量，以 employee_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接 + 分组计数

我们首先使用自连接，将 `EmployeeShifts` 表连接自身。通过连接条件，确保只比较同一个员工的班次，并且检查班次之间是否存在重叠。

1. `t1.start_time < t1.start_time`：确保第一个班次的开始时间早于第二个班次的结束时间。
1. `t1.end_time > t2.start_time`：确保第一个班次的结束时间晚于第二个班次的开始时间。

接下来，我们对数据按照 `employee_id` 进行分组，统计每个员工的重叠班次数量。

最后，我们筛选出重叠班次数量大于 $0$ 的员工，并按照 `employee_id` 进行升序排序。

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    t1.employee_id,
    COUNT(*) AS overlapping_shifts
FROM
    EmployeeShifts t1
    JOIN EmployeeShifts t2
        ON t1.employee_id = t2.employee_id
        AND t1.start_time < t2.start_time
        AND t1.end_time > t2.start_time
GROUP BY 1
HAVING overlapping_shifts > 0
ORDER BY 1;
```

#### Pandas

```python
import pandas as pd


def find_overlapping_shifts(employee_shifts: pd.DataFrame) -> pd.DataFrame:
    merged_shifts = employee_shifts.merge(
        employee_shifts, on="employee_id", suffixes=("_t1", "_t2")
    )
    overlapping_shifts = merged_shifts[
        (merged_shifts["start_time_t1"] < merged_shifts["start_time_t2"])
        & (merged_shifts["end_time_t1"] > merged_shifts["start_time_t2"])
    ]
    result = (
        overlapping_shifts.groupby("employee_id")
        .size()
        .reset_index(name="overlapping_shifts")
    )
    result = result[result["overlapping_shifts"] > 0]
    result = result.sort_values("employee_id").reset_index(drop=True)
    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3263. 将双链表转换为数组 I 🔒](https://leetcode.cn/problems/convert-doubly-linked-list-to-array-i){#3263}

{{< tabs "3263" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next
"""


class Solution:
    def toArray(self, root: "Optional[Node]") -> List[int]:
        ans = []
        while root:
            ans.append(root.val)
            root = root.next
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};
*/

class Solution {
    public int[] toArray(Node head) {
        List<Integer> ans = new ArrayList<>();
        for (; head != null; head = head.next) {
            ans.add(head.val);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
    vector<int> toArray(Node* head) {
        vector<int> ans;
        for (; head; head = head->next) {
            ans.push_back(head->val);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Prev *Node
 * }
 */

func toArray(head *Node) (ans []int) {
	for ; head != nil; head = head.Next {
		ans = append(ans, head.Val)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     prev: _Node | null
 *     next: _Node | null
 *
 *     constructor(val?: number, prev? : _Node, next? : _Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.prev = (prev===undefined ? null : prev);
 *         this.next = (next===undefined ? null : next);
 *     }
 * }
 */

function toArray(head: _Node | null): number[] {
    const ans: number[] = [];
    for (; head; head = head.next) {
        ans.push(head.val);
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

<p>给定一个 <strong>双链表&nbsp;</strong>的&nbsp;<code>head</code>&nbsp;节点，其中的节点具有指向下一个节点的指针和上一个节点的指针。</p>

<p>返回一个 <strong>按顺序</strong> 包含链表中元素的整数数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>head = [1,2,3,4,3,2,1]</span></p>

<p><span class="example-io"><b>输出：</b>[1,2,3,4,3,2,1]</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>head = [2,2,2,2,2]</span></p>

<p><span class="example-io"><b>输出：</b>[2,2,2,2,2]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>head = [3,2,3,2,3,2]</span></p>

<p><span class="example-io"><b>输出：</b>[3,2,3,2,3,2]</span></p>
</div>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li>给定链表中节点的数量在&nbsp;<code>[1, 50]</code>&nbsp;范围。</li>
	<li><code>1 &lt;= Node.val &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们可以直接遍历链表，将节点的值依次添加到答案数组 $\textit{ans}$ 中。

遍历结束后，返回答案数组 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next
"""


class Solution:
    def toArray(self, root: "Optional[Node]") -> List[int]:
        ans = []
        while root:
            ans.append(root.val)
            root = root.next
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};
*/

class Solution {
    public int[] toArray(Node head) {
        List<Integer> ans = new ArrayList<>();
        for (; head != null; head = head.next) {
            ans.add(head.val);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```

#### C++

```cpp
/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
    vector<int> toArray(Node* head) {
        vector<int> ans;
        for (; head; head = head->next) {
            ans.push_back(head->val);
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Prev *Node
 * }
 */

func toArray(head *Node) (ans []int) {
	for ; head != nil; head = head.Next {
		ans = append(ans, head.Val)
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     prev: _Node | null
 *     next: _Node | null
 *
 *     constructor(val?: number, prev? : _Node, next? : _Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.prev = (prev===undefined ? null : prev);
 *         this.next = (next===undefined ? null : next);
 *     }
 * }
 */

function toArray(head: _Node | null): number[] {
    const ans: number[] = [];
    for (; head; head = head.next) {
        ans.push(head.val);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3264. K 次乘运算后的最终数组 I](https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i){#3264}

{{< tabs "3264" >}}

{{% tab "python" %}}
```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        pq = [(x, i) for i, x in enumerate(nums)]
        heapify(pq)
        for _ in range(k):
            _, i = heappop(pq)
            nums[i] *= multiplier
            heappush(pq, (nums[i], i))
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Integer> pq
            = new PriorityQueue<>((i, j) -> nums[i] - nums[j] == 0 ? i - j : nums[i] - nums[j]);
        for (int i = 0; i < nums.length; i++) {
            pq.offer(i);
        }
        while (k-- > 0) {
            int i = pq.poll();
            nums[i] *= multiplier;
            pq.offer(i);
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [&nums](int i, int j) {
            return nums[i] == nums[j] ? i > j : nums[i] > nums[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            pq.push(i);
        }

        while (k--) {
            int i = pq.top();
            pq.pop();
            nums[i] *= multiplier;
            pq.push(i);
        }

        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getFinalState(nums []int, k int, multiplier int) []int {
	h := &hp{nums: nums}
	for i := range nums {
		heap.Push(h, i)
	}

	for k > 0 {
		i := heap.Pop(h).(int)
		nums[i] *= multiplier
		heap.Push(h, i)
		k--
	}

	return nums
}

type hp struct {
	sort.IntSlice
	nums []int
}

func (h *hp) Less(i, j int) bool {
	if h.nums[h.IntSlice[i]] == h.nums[h.IntSlice[j]] {
		return h.IntSlice[i] < h.IntSlice[j]
	}
	return h.nums[h.IntSlice[i]] < h.nums[h.IntSlice[j]]
}

func (h *hp) Pop() any {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[:n-1]
	return x
}

func (h *hp) Push(x any) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getFinalState(nums: number[], k: number, multiplier: number): number[] {
    const pq = new PriorityQueue<number>((i, j) =>
        nums[i] === nums[j] ? i - j : nums[i] - nums[j],
    );

    for (let i = 0; i < nums.length; ++i) {
        pq.enqueue(i);
    }
    while (k--) {
        const i = pq.dequeue()!;
        nums[i] *= multiplier;
        pq.enqueue(i);
    }
    return nums;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数&nbsp;<code>k</code>&nbsp;&nbsp;和一个整数&nbsp;<code>multiplier</code>&nbsp;。</p>

<p>你需要对 <code>nums</code>&nbsp;执行 <code>k</code>&nbsp;次操作，每次操作中：</p>

<ul>
	<li>找到 <code>nums</code>&nbsp;中的 <strong>最小</strong>&nbsp;值&nbsp;<code>x</code>&nbsp;，如果存在多个最小值，选择最 <strong>前面</strong>&nbsp;的一个。</li>
	<li>将 <code>x</code>&nbsp;替换为&nbsp;<code>x * multiplier</code>&nbsp;。</li>
</ul>

<p>请你返回执行完 <code>k</code>&nbsp;次乘运算之后，最终的 <code>nums</code>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,3,5,6], k = 5, multiplier = 2</span></p>

<p><span class="example-io"><b>输出：</b>[8,4,6,5,6]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[2, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[4, 4, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>4 次操作后</td>
			<td>[4, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>5 次操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span>nums = [1,2], k = 3, multiplier = 4</p>

<p><span class="example-io"><b>输出：</b></span>[16,8]</p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[4, 2]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 8]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[16, 8]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>1 &lt;= multiplier &lt;= 5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）+ 模拟

我们可以用一个小根堆来维护数组 $\textit{nums}$ 中的元素，每次从小根堆中取出最小值，将其乘以 $\textit{multiplier}$ 后再放回小根堆中。在实现过程中，我们往小根堆插入的是元素的下标，然后自定义比较函数，使得小根堆按照 $\textit{nums}$ 中元素的大小作为第一关键字，下标作为第二关键字进行排序。

最后，我们返回数组 $\textit{nums}$ 即可。

时间复杂度 $O((n + k) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        pq = [(x, i) for i, x in enumerate(nums)]
        heapify(pq)
        for _ in range(k):
            _, i = heappop(pq)
            nums[i] *= multiplier
            heappush(pq, (nums[i], i))
        return nums
```

#### Java

```java
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Integer> pq
            = new PriorityQueue<>((i, j) -> nums[i] - nums[j] == 0 ? i - j : nums[i] - nums[j]);
        for (int i = 0; i < nums.length; i++) {
            pq.offer(i);
        }
        while (k-- > 0) {
            int i = pq.poll();
            nums[i] *= multiplier;
            pq.offer(i);
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [&nums](int i, int j) {
            return nums[i] == nums[j] ? i > j : nums[i] > nums[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            pq.push(i);
        }

        while (k--) {
            int i = pq.top();
            pq.pop();
            nums[i] *= multiplier;
            pq.push(i);
        }

        return nums;
    }
};
```

#### Go

```go
func getFinalState(nums []int, k int, multiplier int) []int {
	h := &hp{nums: nums}
	for i := range nums {
		heap.Push(h, i)
	}

	for k > 0 {
		i := heap.Pop(h).(int)
		nums[i] *= multiplier
		heap.Push(h, i)
		k--
	}

	return nums
}

type hp struct {
	sort.IntSlice
	nums []int
}

func (h *hp) Less(i, j int) bool {
	if h.nums[h.IntSlice[i]] == h.nums[h.IntSlice[j]] {
		return h.IntSlice[i] < h.IntSlice[j]
	}
	return h.nums[h.IntSlice[i]] < h.nums[h.IntSlice[j]]
}

func (h *hp) Pop() any {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[:n-1]
	return x
}

func (h *hp) Push(x any) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
```

#### TypeScript

```ts
function getFinalState(nums: number[], k: number, multiplier: number): number[] {
    const pq = new PriorityQueue<number>((i, j) =>
        nums[i] === nums[j] ? i - j : nums[i] - nums[j],
    );

    for (let i = 0; i < nums.length; ++i) {
        pq.enqueue(i);
    }
    while (k--) {
        const i = pq.dequeue()!;
        nums[i] *= multiplier;
        pq.enqueue(i);
    }
    return nums;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3265. 统计近似相等数对 I](https://leetcode.cn/problems/count-almost-equal-pairs-i){#3265}

{{< tabs "3265" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = defaultdict(int)
        for x in nums:
            vis = {x}
            s = list(str(x))
            for j in range(len(s)):
                for i in range(j):
                    s[i], s[j] = s[j], s[i]
                    vis.add(int("".join(s)))
                    s[i], s[j] = s[j], s[i]
            ans += sum(cnt[x] for x in vis)
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPairs(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            Set<Integer> vis = new HashSet<>();
            vis.add(x);
            char[] s = String.valueOf(x).toCharArray();
            for (int j = 0; j < s.length; ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s, i, j);
                    vis.add(Integer.parseInt(String.valueOf(s)));
                    swap(s, i, j);
                }
            }
            for (int y : vis) {
                ans += cnt.getOrDefault(y, 0);
            }
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int x : nums) {
            unordered_set<int> vis = {x};
            string s = to_string(x);

            for (int j = 0; j < s.length(); ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s[i], s[j]);
                    vis.insert(stoi(s));
                    swap(s[i], s[j]);
                }
            }

            for (int y : vis) {
                ans += cnt[y];
            }
            cnt[x]++;
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := make(map[int]int)

	for _, x := range nums {
		vis := make(map[int]struct{})
		vis[x] = struct{}{}
		s := []rune(strconv.Itoa(x))

		for j := 0; j < len(s); j++ {
			for i := 0; i < j; i++ {
				s[i], s[j] = s[j], s[i]
				y, _ := strconv.Atoi(string(s))
				vis[y] = struct{}{}
				s[i], s[j] = s[j], s[i]
			}
		}

		for y := range vis {
			ans += cnt[y]
		}
		cnt[x]++
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const cnt = new Map<number, number>();

    for (const x of nums) {
        const vis = new Set<number>();
        vis.add(x);
        const s = x.toString().split('');

        for (let j = 0; j < s.length; j++) {
            for (let i = 0; i < j; i++) {
                [s[i], s[j]] = [s[j], s[i]];
                vis.add(+s.join(''));
                [s[i], s[j]] = [s[j], s[i]];
            }
        }

        for (const y of vis) {
            ans += cnt.get(y) || 0;
        }
        cnt.set(x, (cnt.get(x) || 0) + 1);
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

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果我们执行以下操作 <strong>至多一次</strong>&nbsp;可以让两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;相等，那么我们称这个数对是 <strong>近似相等</strong>&nbsp;的：</p>

<ul>
	<li>选择&nbsp;<code>x</code> <strong>或者</strong>&nbsp;<code>y</code> &nbsp;之一，将这个数字中的两个数位交换。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中，下标 <code>i</code>&nbsp;和 <code>j</code>&nbsp;满足&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>nums[i]</code> 和&nbsp;<code>nums[j]</code> <strong>近似相等</strong>&nbsp;的数对数目。</p>

<p><b>注意</b>&nbsp;，执行操作后一个整数可以有前导 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,12,30,17,21]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>近似相等数对包括：</p>

<ul>
	<li>3 和 30 。交换 30 中的数位 3 和 0 ，得到 3 。</li>
	<li>12 和 21 。交换12 中的数位 1 和 2 ，得到 21 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p>数组中的任意两个元素都是近似相等的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [123,231]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>我们无法通过交换 123&nbsp;或者 231 中的两个数位得到另一个数。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

我们可以枚举每一个数，然后对于每一个数，我们可以枚举每一对不同的数位，然后交换这两个数位，得到一个新的数，记录到一个哈希表 $\textit{vis}$ 中，表示这个数至多进行一次交换后的所有可能的数。然后计算前面枚举过的数中有多少个数在哈希表 $\textit{vis}$ 中，累加到答案中。接下来，我们将当前枚举的数加入到哈希表 $\textit{cnt}$ 中，表示当前枚举的数的个数。

这样枚举，会少统计一些数对，比如 $[100, 1]$，因为 $100$ 交换后的数是 $1$，而此前枚举过数不包含 $1$，因此会少统计一些数对。我们只需要在枚举之前，将数组排序，即可解决这个问题。

时间复杂度 $O(n \times (\log n + \log^3 M))$，空间复杂度 $O(n + \log^2 M)$。其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $M$ 是数组 $\textit{nums}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = defaultdict(int)
        for x in nums:
            vis = {x}
            s = list(str(x))
            for j in range(len(s)):
                for i in range(j):
                    s[i], s[j] = s[j], s[i]
                    vis.add(int("".join(s)))
                    s[i], s[j] = s[j], s[i]
            ans += sum(cnt[x] for x in vis)
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countPairs(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            Set<Integer> vis = new HashSet<>();
            vis.add(x);
            char[] s = String.valueOf(x).toCharArray();
            for (int j = 0; j < s.length; ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s, i, j);
                    vis.add(Integer.parseInt(String.valueOf(s)));
                    swap(s, i, j);
                }
            }
            for (int y : vis) {
                ans += cnt.getOrDefault(y, 0);
            }
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int x : nums) {
            unordered_set<int> vis = {x};
            string s = to_string(x);

            for (int j = 0; j < s.length(); ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s[i], s[j]);
                    vis.insert(stoi(s));
                    swap(s[i], s[j]);
                }
            }

            for (int y : vis) {
                ans += cnt[y];
            }
            cnt[x]++;
        }

        return ans;
    }
};
```

#### Go

```go
func countPairs(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := make(map[int]int)

	for _, x := range nums {
		vis := make(map[int]struct{})
		vis[x] = struct{}{}
		s := []rune(strconv.Itoa(x))

		for j := 0; j < len(s); j++ {
			for i := 0; i < j; i++ {
				s[i], s[j] = s[j], s[i]
				y, _ := strconv.Atoi(string(s))
				vis[y] = struct{}{}
				s[i], s[j] = s[j], s[i]
			}
		}

		for y := range vis {
			ans += cnt[y]
		}
		cnt[x]++
	}

	return
}
```

#### TypeScript

```ts
function countPairs(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const cnt = new Map<number, number>();

    for (const x of nums) {
        const vis = new Set<number>();
        vis.add(x);
        const s = x.toString().split('');

        for (let j = 0; j < s.length; j++) {
            for (let i = 0; i < j; i++) {
                [s[i], s[j]] = [s[j], s[i]];
                vis.add(+s.join(''));
                [s[i], s[j]] = [s[j], s[i]];
            }
        }

        for (const y of vis) {
            ans += cnt.get(y) || 0;
        }
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3266. K 次乘运算后的最终数组 II](https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-ii){#3266}

{{< tabs "3266" >}}

{{% tab "python" %}}
```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        if multiplier == 1:
            return nums
        pq = [(x, i) for i, x in enumerate(nums)]
        heapify(pq)
        m = max(nums)
        while k and pq[0][0] < m:
            x, i = heappop(pq)
            heappush(pq, (x * multiplier, i))
            k -= 1
        n = len(nums)
        mod = 10**9 + 7
        pq.sort()
        for i, (x, j) in enumerate(pq):
            nums[j] = x * pow(multiplier, k // n + int(i < k % n), mod) % mod
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] == b[0] ? Long.compare(a[1], b[1]) : Long.compare(a[0], b[0]));
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        for (int i = 0; i < n; ++i) {
            pq.offer(new long[] {nums[i], i});
        }
        for (; k > 0 && pq.peek()[0] < m; --k) {
            long[] p = pq.poll();
            p[0] *= multiplier;
            pq.offer(p);
        }
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            long[] p = pq.poll();
            long x = p[0];
            int j = (int) p[1];
            nums[j] = (int) ((x % mod) * qpow(multiplier, k / n + (i < k % n ? 1 : 0), mod) % mod);
        }
        return nums;
    }

    private int qpow(long a, long n, long mod) {
        long ans = 1 % mod;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }

        using ll = long long;
        using pli = pair<ll, int>;
        auto cmp = [](const pli& a, const pli& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pli, vector<pli>, decltype(cmp)> pq(cmp);

        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        while (k > 0 && pq.top().first < m) {
            auto p = pq.top();
            pq.pop();
            p.first *= multiplier;
            pq.emplace(p);
            --k;
        }

        auto qpow = [&](ll a, ll n, ll mod) {
            ll ans = 1 % mod;
            a = a % mod;
            while (n > 0) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
                n >>= 1;
            }
            return ans;
        };

        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            auto p = pq.top();
            pq.pop();
            long long x = p.first;
            int j = p.second;
            nums[j] = static_cast<int>((x % mod) * qpow(multiplier, k / n + (i < k % n ? 1 : 0), mod) % mod);
        }

        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getFinalState(nums []int, k int, multiplier int) []int {
	if multiplier == 1 {
		return nums
	}
	n := len(nums)
	pq := make(hp, n)
	for i, x := range nums {
		pq[i] = pair{x, i}
	}
	heap.Init(&pq)
	m := slices.Max(nums)
	for ; k > 0 && pq[0].x < m; k-- {
		x := pq[0]
		heap.Pop(&pq)
		x.x *= multiplier
		heap.Push(&pq, x)
	}
	const mod int = 1e9 + 7

	for i := range nums {
		p := heap.Pop(&pq).(pair)
		x, j := p.x, p.i
		power := k / n
		if i < k%n {
			power++
		}
		nums[j] = (x % mod) * qpow(multiplier, power, mod) % mod
	}
	return nums
}

func qpow(a, n, mod int) int {
	ans := 1 % mod
	a = a % mod
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		n >>= 1
	}
	return int(ans)
}

type pair struct{ x, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x < h[j].x || h[i].x == h[j].x && h[i].i < h[j].i }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return x }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数&nbsp;<code>k</code>&nbsp;&nbsp;和一个整数&nbsp;<code>multiplier</code>&nbsp;。</p>

<p>你需要对 <code>nums</code>&nbsp;执行 <code>k</code>&nbsp;次操作，每次操作中：</p>

<ul>
	<li>找到 <code>nums</code>&nbsp;中的 <strong>最小</strong>&nbsp;值&nbsp;<code>x</code>&nbsp;，如果存在多个最小值，选择最 <strong>前面</strong>&nbsp;的一个。</li>
	<li>将 <code>x</code>&nbsp;替换为&nbsp;<code>x * multiplier</code>&nbsp;。</li>
</ul>

<p><code>k</code>&nbsp;次操作以后，你需要将 <code>nums</code>&nbsp;中每一个数值对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余。</p>

<p>请你返回执行完 <code>k</code>&nbsp;次乘运算以及取余运算之后，最终的 <code>nums</code>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,3,5,6], k = 5, multiplier = 2</span></p>

<p><span class="example-io"><b>输出：</b>[8,4,6,5,6]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[2, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[4, 4, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>4 次操作后</td>
			<td>[4, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>5 次操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>取余操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [100000,2000], k = 2, multiplier = 1000000</span></p>

<p><span class="example-io"><b>输出：</b>[999999307,999999993]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[100000, 2000000000]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[100000000000, 2000000000]</td>
		</tr>
		<tr>
			<td>取余操作后</td>
			<td>[999999307, 999999993]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= multiplier &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）+ 模拟

我们记数组 $\textit{nums}$ 的长度为 $n$，最大值为 $m$。

我们首先通过利用优先队列（小根堆），模拟操作，直到完成 $k$ 次操作或者堆中所有元素都大于等于 $m$。

此时，数组所有元素值都小于 $m \times \textit{multiplier}$，由于 $1 \leq m \leq 10^9$ 且 $1 \leq \textit{multiplier} \leq 10^6$，所以 $m \times \textit{multiplier} \leq 10^{15}$，是在 $64$ 位整数范围内的。

接下来，我们的每一次操作，都会将数组中的最小元素变成最大元素，因此在每 $n$ 次连续操作后，数组中的每个元素都恰好执行了一次乘法操作。

因此，我们在模拟过后，剩余 $k$ 次操作，那么数组中最小的 $k \bmod n$ 个元素将会执行 $\lfloor k / n \rfloor + 1$ 次乘法操作，其余的元素将会执行 $\lfloor k / n \rfloor$ 次乘法操作。

最后，我们将数组中的每个元素乘上对应的乘法次数，再取模 $10^9 + 7$ 即可，可以通过快速幂来计算。

时间复杂度 $O(n \times \log n \times \log M + n \times \log k)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $M$ 为数组 $\textit{nums}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        if multiplier == 1:
            return nums
        pq = [(x, i) for i, x in enumerate(nums)]
        heapify(pq)
        m = max(nums)
        while k and pq[0][0] < m:
            x, i = heappop(pq)
            heappush(pq, (x * multiplier, i))
            k -= 1
        n = len(nums)
        mod = 10**9 + 7
        pq.sort()
        for i, (x, j) in enumerate(pq):
            nums[j] = x * pow(multiplier, k // n + int(i < k % n), mod) % mod
        return nums
```

#### Java

```java
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] == b[0] ? Long.compare(a[1], b[1]) : Long.compare(a[0], b[0]));
        int n = nums.length;
        int m = Arrays.stream(nums).max().getAsInt();
        for (int i = 0; i < n; ++i) {
            pq.offer(new long[] {nums[i], i});
        }
        for (; k > 0 && pq.peek()[0] < m; --k) {
            long[] p = pq.poll();
            p[0] *= multiplier;
            pq.offer(p);
        }
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            long[] p = pq.poll();
            long x = p[0];
            int j = (int) p[1];
            nums[j] = (int) ((x % mod) * qpow(multiplier, k / n + (i < k % n ? 1 : 0), mod) % mod);
        }
        return nums;
    }

    private int qpow(long a, long n, long mod) {
        long ans = 1 % mod;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }

        using ll = long long;
        using pli = pair<ll, int>;
        auto cmp = [](const pli& a, const pli& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pli, vector<pli>, decltype(cmp)> pq(cmp);

        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        while (k > 0 && pq.top().first < m) {
            auto p = pq.top();
            pq.pop();
            p.first *= multiplier;
            pq.emplace(p);
            --k;
        }

        auto qpow = [&](ll a, ll n, ll mod) {
            ll ans = 1 % mod;
            a = a % mod;
            while (n > 0) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
                n >>= 1;
            }
            return ans;
        };

        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            auto p = pq.top();
            pq.pop();
            long long x = p.first;
            int j = p.second;
            nums[j] = static_cast<int>((x % mod) * qpow(multiplier, k / n + (i < k % n ? 1 : 0), mod) % mod);
        }

        return nums;
    }
};
```

#### Go

```go
func getFinalState(nums []int, k int, multiplier int) []int {
	if multiplier == 1 {
		return nums
	}
	n := len(nums)
	pq := make(hp, n)
	for i, x := range nums {
		pq[i] = pair{x, i}
	}
	heap.Init(&pq)
	m := slices.Max(nums)
	for ; k > 0 && pq[0].x < m; k-- {
		x := pq[0]
		heap.Pop(&pq)
		x.x *= multiplier
		heap.Push(&pq, x)
	}
	const mod int = 1e9 + 7

	for i := range nums {
		p := heap.Pop(&pq).(pair)
		x, j := p.x, p.i
		power := k / n
		if i < k%n {
			power++
		}
		nums[j] = (x % mod) * qpow(multiplier, power, mod) % mod
	}
	return nums
}

func qpow(a, n, mod int) int {
	ans := 1 % mod
	a = a % mod
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		n >>= 1
	}
	return int(ans)
}

type pair struct{ x, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x < h[j].x || h[i].x == h[j].x && h[i].i < h[j].i }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return x }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3267. 统计近似相等数对 II](https://leetcode.cn/problems/count-almost-equal-pairs-ii){#3267}

{{< tabs "3267" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = defaultdict(int)
        for x in nums:
            vis = {x}
            s = list(str(x))
            m = len(s)
            for j in range(m):
                for i in range(j):
                    s[i], s[j] = s[j], s[i]
                    vis.add(int("".join(s)))
                    for q in range(i + 1, m):
                        for p in range(i + 1, q):
                            s[p], s[q] = s[q], s[p]
                            vis.add(int("".join(s)))
                            s[p], s[q] = s[q], s[p]
                    s[i], s[j] = s[j], s[i]
            ans += sum(cnt[x] for x in vis)
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPairs(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            Set<Integer> vis = new HashSet<>();
            vis.add(x);
            char[] s = String.valueOf(x).toCharArray();
            for (int j = 0; j < s.length; ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s, i, j);
                    vis.add(Integer.parseInt(String.valueOf(s)));
                    for (int q = i; q < s.length; ++q) {
                        for (int p = i; p < q; ++p) {
                            swap(s, p, q);
                            vis.add(Integer.parseInt(String.valueOf(s)));
                            swap(s, p, q);
                        }
                    }
                    swap(s, i, j);
                }
            }
            for (int y : vis) {
                ans += cnt.getOrDefault(y, 0);
            }
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int x : nums) {
            unordered_set<int> vis = {x};
            string s = to_string(x);

            for (int j = 0; j < s.length(); ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s[i], s[j]);
                    vis.insert(stoi(s));
                    for (int q = i + 1; q < s.length(); ++q) {
                        for (int p = i + 1; p < q; ++p) {
                            swap(s[p], s[q]);
                            vis.insert(stoi(s));
                            swap(s[p], s[q]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }

            for (int y : vis) {
                ans += cnt[y];
            }
            cnt[x]++;
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := make(map[int]int)

	for _, x := range nums {
		vis := make(map[int]struct{})
		vis[x] = struct{}{}
		s := []rune(strconv.Itoa(x))

		for j := 0; j < len(s); j++ {
			for i := 0; i < j; i++ {
				s[i], s[j] = s[j], s[i]
				y, _ := strconv.Atoi(string(s))
				vis[y] = struct{}{}
				for q := i + 1; q < len(s); q++ {
					for p := i + 1; p < q; p++ {
						s[p], s[q] = s[q], s[p]
						z, _ := strconv.Atoi(string(s))
						vis[z] = struct{}{}
						s[p], s[q] = s[q], s[p]
					}
				}
				s[i], s[j] = s[j], s[i]
			}
		}

		for y := range vis {
			ans += cnt[y]
		}
		cnt[x]++
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const cnt = new Map<number, number>();

    for (const x of nums) {
        const vis = new Set<number>();
        vis.add(x);
        const s = x.toString().split('');

        for (let j = 0; j < s.length; j++) {
            for (let i = 0; i < j; i++) {
                [s[i], s[j]] = [s[j], s[i]];
                vis.add(+s.join(''));
                for (let q = i + 1; q < s.length; ++q) {
                    for (let p = i + 1; p < q; ++p) {
                        [s[p], s[q]] = [s[q], s[p]];
                        vis.add(+s.join(''));
                        [s[p], s[q]] = [s[q], s[p]];
                    }
                }
                [s[i], s[j]] = [s[j], s[i]];
            }
        }

        for (const y of vis) {
            ans += cnt.get(y) || 0;
        }
        cnt.set(x, (cnt.get(x) || 0) + 1);
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

<p><strong>注意：</strong>在这个问题中，操作次数增加为至多&nbsp;<strong>两次</strong>&nbsp;。</p>

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果我们执行以下操作 <strong>至多<u>两次</u></strong>&nbsp;可以让两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;相等，那么我们称这个数对是 <strong>近似相等</strong>&nbsp;的：</p>

<ul>
	<li>选择&nbsp;<code>x</code> <strong>或者</strong>&nbsp;<code>y</code> &nbsp;之一，将这个数字中的两个数位交换。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中，下标 <code>i</code>&nbsp;和 <code>j</code>&nbsp;满足&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>nums[i]</code> 和&nbsp;<code>nums[j]</code> <strong>近似相等</strong>&nbsp;的数对数目。</p>

<p><b>注意</b>&nbsp;，执行操作后得到的整数可以有前导 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1023,2310,2130,213]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>近似相等数对包括：</p>

<ul>
	<li>1023 和 2310 。交换 1023 中数位 1 和 2 ，然后交换数位 0 和 3 ，得到 2310 。</li>
	<li>1023 和 213 。交换 1023 中数位 1 和 0 ，然后交换数位 1 和 2 ，得到 0213 ，也就是 213 。</li>
	<li>2310 和 213 。交换 2310 中数位 2 和 0 ，然后交换数位 3 和 2 ，得到 0213 ，也就是 213 。</li>
	<li>2310 和 2130 。交换 2310 中数位 3 和 1 ，得到 2130 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,10,100]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>近似相等数对包括：</p>

<ul>
	<li>1 和 10 。交换 10 中数位 1 和 0&nbsp;，得到 01 ，也就是 1&nbsp;。</li>
	<li>1 和 100 。交换 100 中数位 1 和从左往右的第二个 0 ，得到 001 ，也就是 1 。</li>
	<li>10 和 100 。交换 100 中数位 1 和从左往右的第一个 0 ，得到 010 ，也就是 10 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>1 &lt;= nums[i] &lt;&nbsp;10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

我们可以枚举每一个数，然后对于每一个数，我们可以枚举每一对不同的数位，然后交换这两个数位，得到一个新的数，记录到一个哈希表 $\textit{vis}$ 中，表示这个数至多进行一次交换后的所有可能的数，然后继续枚举每一对不同的数位，交换这两个数位，得到一个新的数，记录到哈希表 $\textit{vis}$ 中，表示这个数至多进行两次交换后的所有可能的数。

这样枚举，会少统计一些数对，比如 $[100, 1]$，因为 $100$ 交换后的数是 $1$，而此前枚举过数不包含 $1$，因此会少统计一些数对。我们只需要在枚举之前，将数组排序，即可解决这个问题。

时间复杂度 $O(n \times (\log n + \log^5 M))$，空间复杂度 $O(n + \log^4 M)$。其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $M$ 是数组 $\textit{nums}$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        cnt = defaultdict(int)
        for x in nums:
            vis = {x}
            s = list(str(x))
            m = len(s)
            for j in range(m):
                for i in range(j):
                    s[i], s[j] = s[j], s[i]
                    vis.add(int("".join(s)))
                    for q in range(i + 1, m):
                        for p in range(i + 1, q):
                            s[p], s[q] = s[q], s[p]
                            vis.add(int("".join(s)))
                            s[p], s[q] = s[q], s[p]
                    s[i], s[j] = s[j], s[i]
            ans += sum(cnt[x] for x in vis)
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countPairs(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            Set<Integer> vis = new HashSet<>();
            vis.add(x);
            char[] s = String.valueOf(x).toCharArray();
            for (int j = 0; j < s.length; ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s, i, j);
                    vis.add(Integer.parseInt(String.valueOf(s)));
                    for (int q = i; q < s.length; ++q) {
                        for (int p = i; p < q; ++p) {
                            swap(s, p, q);
                            vis.add(Integer.parseInt(String.valueOf(s)));
                            swap(s, p, q);
                        }
                    }
                    swap(s, i, j);
                }
            }
            for (int y : vis) {
                ans += cnt.getOrDefault(y, 0);
            }
            cnt.merge(x, 1, Integer::sum);
        }
        return ans;
    }

    private void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int x : nums) {
            unordered_set<int> vis = {x};
            string s = to_string(x);

            for (int j = 0; j < s.length(); ++j) {
                for (int i = 0; i < j; ++i) {
                    swap(s[i], s[j]);
                    vis.insert(stoi(s));
                    for (int q = i + 1; q < s.length(); ++q) {
                        for (int p = i + 1; p < q; ++p) {
                            swap(s[p], s[q]);
                            vis.insert(stoi(s));
                            swap(s[p], s[q]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }

            for (int y : vis) {
                ans += cnt[y];
            }
            cnt[x]++;
        }

        return ans;
    }
};
```

#### Go

```go
func countPairs(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := make(map[int]int)

	for _, x := range nums {
		vis := make(map[int]struct{})
		vis[x] = struct{}{}
		s := []rune(strconv.Itoa(x))

		for j := 0; j < len(s); j++ {
			for i := 0; i < j; i++ {
				s[i], s[j] = s[j], s[i]
				y, _ := strconv.Atoi(string(s))
				vis[y] = struct{}{}
				for q := i + 1; q < len(s); q++ {
					for p := i + 1; p < q; p++ {
						s[p], s[q] = s[q], s[p]
						z, _ := strconv.Atoi(string(s))
						vis[z] = struct{}{}
						s[p], s[q] = s[q], s[p]
					}
				}
				s[i], s[j] = s[j], s[i]
			}
		}

		for y := range vis {
			ans += cnt[y]
		}
		cnt[x]++
	}

	return
}
```

#### TypeScript

```ts
function countPairs(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const cnt = new Map<number, number>();

    for (const x of nums) {
        const vis = new Set<number>();
        vis.add(x);
        const s = x.toString().split('');

        for (let j = 0; j < s.length; j++) {
            for (let i = 0; i < j; i++) {
                [s[i], s[j]] = [s[j], s[i]];
                vis.add(+s.join(''));
                for (let q = i + 1; q < s.length; ++q) {
                    for (let p = i + 1; p < q; ++p) {
                        [s[p], s[q]] = [s[q], s[p]];
                        vis.add(+s.join(''));
                        [s[p], s[q]] = [s[q], s[p]];
                    }
                }
                [s[i], s[j]] = [s[j], s[i]];
            }
        }

        for (const y of vis) {
            ans += cnt.get(y) || 0;
        }
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3268. 查找重叠的班次 II 🔒](https://leetcode.cn/problems/find-overlapping-shifts-ii){#3268}

{{< tabs "3268" >}}

{{% tab "sql" %}}
```sql
WITH
    T AS (
        SELECT DISTINCT employee_id, start_time AS st
        FROM EmployeeShifts
        UNION DISTINCT
        SELECT DISTINCT employee_id, end_time AS st
        FROM EmployeeShifts
    ),
    P AS (
        SELECT
            *,
            LEAD(st) OVER (
                PARTITION BY employee_id
                ORDER BY st
            ) AS ed
        FROM T
    ),
    S AS (
        SELECT
            P.*,
            COUNT(1) AS concurrent_count
        FROM
            P
            INNER JOIN EmployeeShifts USING (employee_id)
        WHERE P.st >= EmployeeShifts.start_time AND P.ed <= EmployeeShifts.end_time
        GROUP BY 1, 2, 3
    ),
    U AS (
        SELECT
            t1.employee_id,
            SUM(
                TIMESTAMPDIFF(MINUTE, t2.start_time, LEAST(t1.end_time, t2.end_time))
            ) total_overlap_duration
        FROM
            EmployeeShifts t1
            JOIN EmployeeShifts t2
                ON t1.employee_id = t2.employee_id
                AND t1.start_time < t2.start_time
                AND t1.end_time > t2.start_time
        GROUP BY 1
    )
SELECT
    employee_id,
    MAX(concurrent_count) max_overlapping_shifts,
    IFNULL(AVG(total_overlap_duration), 0) total_overlap_duration
FROM
    S
    LEFT JOIN U USING (employee_id)
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>EmployeeShifts</code></p>

<pre>
+------------------+----------+
| Column Name      | Type     |
+------------------+----------+
| employee_id      | int      |
| start_time       | datetime |
| end_time         | datetime |
+------------------+----------+
(employee_id, start_time) 是此表的唯一主键。
这张表包含员工的排班工作，包括特定日期的开始和结束时间。
</pre>

<p>编写一个解决方案来为每个员工分析重叠排班。如果两个排班在&nbsp;<strong>同一天</strong>&nbsp;且一个排班的&nbsp;<code>end_time</code>&nbsp;比另一个排班的&nbsp;<code>start_time</code>&nbsp;<strong>更晚&nbsp;</strong>则认为两个排班重叠。</p>

<p>对于&nbsp;<strong>每个员工</strong>，计算如下内容：</p>

<ol>
	<li>任何 <strong>给定时间</strong> 的 <strong>最多重叠</strong> 班次数。</li>
	<li>所有重叠班次的 <strong>总持续时间</strong>，以分钟为单位。</li>
</ol>

<p>返回结果表以&nbsp;<code>employee_id</code> <strong>升序&nbsp;</strong>排序。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>EmployeeShifts</code> 表：</p>

<pre class="example-io">
+-------------+---------------------+---------------------+
| employee_id | start_time          | end_time            |
+-------------+---------------------+---------------------+
| 1           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
| 1           | 2023-10-01 15:00:00 | 2023-10-01 23:00:00 |
| 1           | 2023-10-01 16:00:00 | 2023-10-02 00:00:00 |
| 2           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
| 2           | 2023-10-01 11:00:00 | 2023-10-01 19:00:00 |
| 3           | 2023-10-01 09:00:00 | 2023-10-01 17:00:00 |
+-------------+---------------------+---------------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+---------------------------+------------------------+
| employee_id | max_overlapping_shifts    | total_overlap_duration |
+-------------+---------------------------+------------------------+
| 1           | 3                         | 600                    |
| 2           | 2                         | 360                    |
| 3           | 1                         | 0                      |
+-------------+---------------------------+------------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>员工 1 有 3 个排班：
	<ul>
		<li>2023-10-01 09:00:00 到 2023-10-01 17:00:00</li>
		<li>2023-10-01 15:00:00 到 2023-10-01 23:00:00</li>
		<li>2023-10-01 16:00:00 到 2023-10-02 00:00:00</li>
	</ul>
	最大重叠班次数量为 3 (from 16:00 to 17:00)。重叠班次的总持续时间为：第 1 个和第 2 个排班之间的 2 小时 (15:00-17:00) + 第 1 个和第 3 个排班之间的&nbsp;1 小时 (16:00-17:00) +&nbsp;第 2 个和第 3 个排班之间的 7 小时 (16:00-23:00)，总共：10 小时 = 600 分钟</li>
	<li>员工 2 有 2 个排班：
	<ul>
		<li>2023-10-01 09:00:00 到 2023-10-01 17:00:00</li>
		<li>2023-10-01 11:00:00 到 2023-10-01 19:00:00</li>
	</ul>
	最大重叠班次数量为 2。重叠班次的总持续时间为 6 小时&nbsp;(11:00-17:00) = 360 分钟。</li>
	<li>员工 3 只有 1 个排班，所以没有重叠。</li>
</ul>

<p>输出表包含 employee_id，同时重叠排班的最大数量,以及每位员工的重叠班次总持续时间（分钟），以&nbsp;employee_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并 + 连接

我们可以将所有 `employee_id` 的 `start_time` 和 `end_time` 合并到一起，记录在 `T` 表中，然后使用 `LEAD` 函数计算出每个 `employee_id` 的下一个时间段，记录在 `P` 表中。

接着，我们可以通过 `P` 表和 `EmployeeShifts` 表进行连接，计算出每个 `employee_id` 的 `concurrent_count`，即同时存在的时间段数量，记录在 `S` 表中。

最后，我们可以通过 `EmployeeShifts` 表和自身进行连接，计算出每个 `employee_id` 的 `total_overlap_duration`，即总的重叠时间，记录在 `U` 表中。

最终，我们可以通过 `S` 表和 `U` 表进行连接，计算出每个 `employee_id` 的 `max_overlapping_shifts` 和 `total_overlap_duration`。

相似题目：

-   [3156. 员工任务持续时间和并发任务 🔒](https://github.com/doocs/leetcode/blob/main/solution/3100-3199/3156.Employee%20Task%20Duration%20and%20Concurrent%20Tasks/README.md)
-   [3262. 查找重叠的班次 🔒](https://github.com/doocs/leetcode/blob/main/solution/3200-3299/3262.Find%20Overlapping%20Shifts/README.md)

<!-- tabs:start -->

#### MySQL

```sql
WITH
    T AS (
        SELECT DISTINCT employee_id, start_time AS st
        FROM EmployeeShifts
        UNION DISTINCT
        SELECT DISTINCT employee_id, end_time AS st
        FROM EmployeeShifts
    ),
    P AS (
        SELECT
            *,
            LEAD(st) OVER (
                PARTITION BY employee_id
                ORDER BY st
            ) AS ed
        FROM T
    ),
    S AS (
        SELECT
            P.*,
            COUNT(1) AS concurrent_count
        FROM
            P
            INNER JOIN EmployeeShifts USING (employee_id)
        WHERE P.st >= EmployeeShifts.start_time AND P.ed <= EmployeeShifts.end_time
        GROUP BY 1, 2, 3
    ),
    U AS (
        SELECT
            t1.employee_id,
            SUM(
                TIMESTAMPDIFF(MINUTE, t2.start_time, LEAST(t1.end_time, t2.end_time))
            ) total_overlap_duration
        FROM
            EmployeeShifts t1
            JOIN EmployeeShifts t2
                ON t1.employee_id = t2.employee_id
                AND t1.start_time < t2.start_time
                AND t1.end_time > t2.start_time
        GROUP BY 1
    )
SELECT
    employee_id,
    MAX(concurrent_count) max_overlapping_shifts,
    IFNULL(AVG(total_overlap_duration), 0) total_overlap_duration
FROM
    S
    LEFT JOIN U USING (employee_id)
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3269. 构建两个递增数组 🔒](https://leetcode.cn/problems/constructing-two-increasing-arrays){#3269}

{{< tabs "3269" >}}

{{% tab "python" %}}
```python
class Solution:
    def minLargest(self, nums1: List[int], nums2: List[int]) -> int:
        def nxt(x: int, y: int) -> int:
            return x + 1 if (x & 1 ^ y) == 1 else x + 2

        m, n = len(nums1), len(nums2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            f[i][0] = nxt(f[i - 1][0], x)
        for j, y in enumerate(nums2, 1):
            f[0][j] = nxt(f[0][j - 1], y)
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                f[i][j] = min(nxt(f[i - 1][j], x), nxt(f[i][j - 1], y))
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minLargest(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = nxt(f[i - 1][j], nums1[i - 1]);
                int y = nxt(f[i][j - 1], nums2[j - 1]);
                f[i][j] = Math.min(x, y);
            }
        }
        return f[m][n];
    }

    private int nxt(int x, int y) {
        return (x & 1 ^ y) == 1 ? x + 1 : x + 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minLargest(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        auto nxt = [](int x, int y) -> int {
            return (x & 1 ^ y) == 1 ? x + 1 : x + 2;
        };
        for (int i = 1; i <= m; ++i) {
            f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = nxt(f[i - 1][j], nums1[i - 1]);
                int y = nxt(f[i][j - 1], nums2[j - 1]);
                f[i][j] = min(x, y);
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minLargest(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	nxt := func(x, y int) int {
		if (x&1 ^ y) == 1 {
			return x + 1
		}
		return x + 2
	}
	for i := 1; i <= m; i++ {
		f[i][0] = nxt(f[i-1][0], nums1[i-1])
	}
	for j := 1; j <= n; j++ {
		f[0][j] = nxt(f[0][j-1], nums2[j-1])
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			x := nxt(f[i-1][j], nums1[i-1])
			y := nxt(f[i][j-1], nums2[j-1])
			f[i][j] = min(x, y)
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minLargest(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    const nxt = (x: number, y: number): number => {
        return (x & 1) ^ y ? x + 1 : x + 2;
    };
    for (let i = 1; i <= m; ++i) {
        f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
    }
    for (let j = 1; j <= n; ++j) {
        f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            f[i][j] = Math.min(nxt(f[i - 1][j], nums1[i - 1]), nxt(f[i][j - 1], nums2[j - 1]));
        }
    }
    return f[m][n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个只包含 0 和 1 的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>，你的任务是执行下面操作后使数组 <code>nums1</code> 和 <code>nums2</code> 中 <strong>最大</strong> 可达数字 <strong>尽可能小</strong>。</p>

<p>将每个 0 替换为正偶数，将每个 1 替换为正奇数。在替换后，两个数组都应该&nbsp;<strong>递增</strong>&nbsp;并且每个整数&nbsp;<strong>至多</strong>&nbsp;被使用一次。</p>

<p>返回执行操作后最小的最大可达数字。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums1 = [], nums2 = [1,0,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong></p>

<p>在替换之后， <code>nums1 = []</code>&nbsp;与&nbsp;<code>nums2 = [1, 2, 3, 5]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums1 = [0,1,0,1], nums2 = [1,0,0,1]</span></p>

<p><span class="example-io"><b>输出：</b>9</span></p>

<p><strong>解释：</strong></p>

<p>有最大元素 9 的一种替换方式， <code>nums1 = [2, 3, 8, 9]</code>&nbsp;与&nbsp;<code>nums2 = [1, 4, 6, 7]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums1 = [0,1,0,0,1], nums2 = [0,0,0,1]</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p>有最大元素 13 的一种替换方式，<code>nums1 = [2, 3, 4, 6, 7]</code>&nbsp;与&nbsp;<code>nums2 = [8, 10, 12, 13]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;只包含 0 和 1。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示数组 $\textit{nums1}$ 的前 $i$ 个元素和数组 $\textit{nums2}$ 的前 $j$ 个元素中，最小的最大值。初始时 $f[i][j] = 0$，答案为 $f[m][n]$，其中 $m$ 和 $n$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

如果 $j = 0$，那么 $f[i][0]$ 的值只能由 $f[i - 1][0]$ 转移得到，转移方程为 $f[i][0] = \textit{nxt}(f[i - 1][0], \textit{nums1}[i - 1])$，其中 $\textit{nxt}(x, y)$ 表示比 $x$ 大且奇偶性与 $y$ 相同的最小整数。

如果 $i = 0$，那么 $f[0][j]$ 的值只能由 $f[0][j - 1]$ 转移得到，转移方程为 $f[0][j] = \textit{nxt}(f[0][j - 1], \textit{nums2}[j - 1])$。

如果 $i > 0$ 且 $j > 0$，那么 $f[i][j]$ 的值可以由 $f[i - 1][j]$ 和 $f[i][j - 1]$ 转移得到，转移方程为 $f[i][j] = \min(\textit{nxt}(f[i - 1][j], \textit{nums1}[i - 1]), \textit{nxt}(f[i][j - 1], \textit{nums2}[j - 1]))$。

最后返回 $f[m][n]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minLargest(self, nums1: List[int], nums2: List[int]) -> int:
        def nxt(x: int, y: int) -> int:
            return x + 1 if (x & 1 ^ y) == 1 else x + 2

        m, n = len(nums1), len(nums2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            f[i][0] = nxt(f[i - 1][0], x)
        for j, y in enumerate(nums2, 1):
            f[0][j] = nxt(f[0][j - 1], y)
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                f[i][j] = min(nxt(f[i - 1][j], x), nxt(f[i][j - 1], y))
        return f[m][n]
```

#### Java

```java
class Solution {
    public int minLargest(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = nxt(f[i - 1][j], nums1[i - 1]);
                int y = nxt(f[i][j - 1], nums2[j - 1]);
                f[i][j] = Math.min(x, y);
            }
        }
        return f[m][n];
    }

    private int nxt(int x, int y) {
        return (x & 1 ^ y) == 1 ? x + 1 : x + 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minLargest(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        auto nxt = [](int x, int y) -> int {
            return (x & 1 ^ y) == 1 ? x + 1 : x + 2;
        };
        for (int i = 1; i <= m; ++i) {
            f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = nxt(f[i - 1][j], nums1[i - 1]);
                int y = nxt(f[i][j - 1], nums2[j - 1]);
                f[i][j] = min(x, y);
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func minLargest(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	nxt := func(x, y int) int {
		if (x&1 ^ y) == 1 {
			return x + 1
		}
		return x + 2
	}
	for i := 1; i <= m; i++ {
		f[i][0] = nxt(f[i-1][0], nums1[i-1])
	}
	for j := 1; j <= n; j++ {
		f[0][j] = nxt(f[0][j-1], nums2[j-1])
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			x := nxt(f[i-1][j], nums1[i-1])
			y := nxt(f[i][j-1], nums2[j-1])
			f[i][j] = min(x, y)
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function minLargest(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    const nxt = (x: number, y: number): number => {
        return (x & 1) ^ y ? x + 1 : x + 2;
    };
    for (let i = 1; i <= m; ++i) {
        f[i][0] = nxt(f[i - 1][0], nums1[i - 1]);
    }
    for (let j = 1; j <= n; ++j) {
        f[0][j] = nxt(f[0][j - 1], nums2[j - 1]);
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            f[i][j] = Math.min(nxt(f[i - 1][j], nums1[i - 1]), nxt(f[i][j - 1], nums2[j - 1]));
        }
    }
    return f[m][n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

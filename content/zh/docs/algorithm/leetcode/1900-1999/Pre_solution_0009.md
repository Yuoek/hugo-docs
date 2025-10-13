---
title: "1980_找出不同的二进制字符串"
date: 2025-10-08T18:38:49+08:00
weight: 9
tags: [位运算, 分治, 前缀和, 动态规划, 哈希表, 回溯, 堆（优先队列）, 字符串, 快速选择, 排序, 数据库, 数组, 滑动窗口, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [1980_找出不同的二进制字符串](#1980)
#### [数组](#1980)
#### [哈希表](#1980)
#### [字符串](#1980)
#### [回溯](#1980)
### [1981_最小化目标值与所选元素的差](#1981)
#### [数组](#1981)
#### [动态规划](#1981)
#### [矩阵](#1981)
### [1982_从子集的和还原数组](#1982)
#### [数组](#1982)
#### [分治](#1982)
### [1983_范围和相等的最宽索引对 🔒](#1983)
#### [数组](#1983)
#### [哈希表](#1983)
#### [前缀和](#1983)
### [1984_学生分数的最小差值](#1984)
#### [数组](#1984)
#### [排序](#1984)
#### [滑动窗口](#1984)
### [1985_找出数组中的第 K 大整数](#1985)
#### [数组](#1985)
#### [字符串](#1985)
#### [分治](#1985)
#### [快速选择](#1985)
#### [排序](#1985)
#### [堆（优先队列）](#1985)
### [1986_完成任务的最少工作时间段](#1986)
#### [位运算](#1986)
#### [数组](#1986)
#### [动态规划](#1986)
#### [回溯](#1986)
#### [状态压缩](#1986)
### [1987_不同的好子序列数目](#1987)
#### [字符串](#1987)
#### [动态规划](#1987)
### [1988_找出每所学校的最低分数要求 🔒](#1988)
#### [数据库](#1988)
### [1989_捉迷藏中可捕获的最大人数 🔒](#1989)
#### [贪心](#1989)
#### [数组](#1989)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1980_找出不同的二进制字符串
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 1981_最小化目标值与所选元素的差
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1982_从子集的和还原数组
___
#### 数组
___
#### 分治
---
### 1983_范围和相等的最宽索引对 🔒
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1984_学生分数的最小差值
___
#### 数组
___
#### 排序
___
#### 滑动窗口
---
### 1985_找出数组中的第 K 大整数
___
#### 数组
___
#### 字符串
___
#### 分治
___
#### 快速选择
___
#### 排序
___
#### 堆（优先队列）
---
### 1986_完成任务的最少工作时间段
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 1987_不同的好子序列数目
___
#### 字符串
___
#### 动态规划
---
### 1988_找出每所学校的最低分数要求 🔒
___
#### 数据库
---
### 1989_捉迷藏中可捕获的最大人数 🔒
___
#### 贪心
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 分治 | 前缀和 |
| 动态规划 | 哈希表 | 回溯 |
| 堆（优先队列） | 字符串 | 快速选择 |
| 排序 | 数据库 | 数组 |
| 滑动窗口 | 状态压缩 | 矩阵 |
| 贪心 |  |  |

# [1980. 找出不同的二进制字符串](https://leetcode.cn/problems/find-unique-binary-string){#1980}

{{< tabs "1980" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        mask = 0
        for x in nums:
            mask |= 1 << x.count("1")
        n = len(nums)
        for i in range(n + 1):
            if mask >> i & 1 ^ 1:
                return "1" * i + "0" * (n - i)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int mask = 0;
        for (var x : nums) {
            int cnt = 0;
            for (int i = 0; i < x.length(); ++i) {
                if (x.charAt(i) == '1') {
                    ++cnt;
                }
            }
            mask |= 1 << cnt;
        }
        for (int i = 0;; ++i) {
            if ((mask >> i & 1) == 0) {
                return "1".repeat(i) + "0".repeat(nums.length - i);
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
    string findDifferentBinaryString(vector<string>& nums) {
        int mask = 0;
        for (auto& x : nums) {
            int cnt = count(x.begin(), x.end(), '1');
            mask |= 1 << cnt;
        }
        for (int i = 0;; ++i) {
            if (mask >> i & 1 ^ 1) {
                return string(i, '1') + string(nums.size() - i, '0');
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDifferentBinaryString(nums []string) string {
	mask := 0
	for _, x := range nums {
		mask |= 1 << strings.Count(x, "1")
	}
	for i := 0; ; i++ {
		if mask>>i&1 == 0 {
			return strings.Repeat("1", i) + strings.Repeat("0", len(nums)-i)
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDifferentBinaryString(nums: string[]): string {
    const res: string[] = [];

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i][i];
        res.push(x === '0' ? '1' : '0');
    }

    return res.join('');
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string FindDifferentBinaryString(string[] nums) {
        int mask = 0;
        foreach (var x in nums) {
            int cnt = x.Count(c => c == '1');
            mask |= 1 << cnt;
        }
        int i = 0;
        while ((mask >> i & 1) == 1) {
            i++;
        }
        return string.Format("{0}{1}", new string('1', i), new string('0', nums.Length - i));
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function findDifferentBinaryString(nums) {
    const res = [];

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i][i];
        res.push(x === '0' ? '1' : '0');
    }

    return res.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>nums</code> ，该数组由 <code>n</code> 个 <strong>互不相同</strong> 的二进制字符串组成，且每个字符串长度都是 <code>n</code> 。请你找出并返回一个长度为&nbsp;<code>n</code>&nbsp;且&nbsp;<strong>没有出现</strong> 在 <code>nums</code> 中的二进制字符串<em>。</em>如果存在多种答案，只需返回 <strong>任意一个</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = ["01","10"]
<strong>输出：</strong>"11"
<strong>解释：</strong>"11" 没有出现在 nums 中。"00" 也是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = ["00","01"]
<strong>输出：</strong>"11"
<strong>解释：</strong>"11" 没有出现在 nums 中。"10" 也是正确答案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = ["111","011","001"]
<strong>输出：</strong>"101"
<strong>解释：</strong>"101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>nums[i].length == n</code></li>
	<li><code>nums[i] </code>为 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>nums</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

由于 `'1'` 在长度为 $n$ 的二进制字符串中出现的次数可以为 $0, 1, 2, \cdots, n$（共有 $n + 1$ 种可能），因此我们一定可以找出一个新的二进制字符串，满足 `'1'` 在字符串中出现次数与 `nums` 中每个字符串不同。

我们可以用一个整数 $mask$ 记录所有字符串中 `'1'` 出现次数的情况，即 $mask$ 的第 $i$ 位为 $1$ 表示长度为 $n$ 的二进制字符串中 `'1'` 出现次数为 $i$ 的字符串存在，否则不存在。

然后我们从 $0$ 开始枚举长度为 $n$ 的二进制字符串中 `'1'` 出现的次数 $i$，如果 $mask$ 的第 $i$ 位为 $0$，则说明长度为 $n$ 的二进制字符串中 `'1'` 出现次数为 $i$ 的字符串不存在，我们可以将这个字符串作为答案返回。

时间复杂度 $O(L)$，其中 $L$ 为 `nums` 中字符串的总长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        mask = 0
        for x in nums:
            mask |= 1 << x.count("1")
        n = len(nums)
        for i in range(n + 1):
            if mask >> i & 1 ^ 1:
                return "1" * i + "0" * (n - i)
```

#### Java

```java
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int mask = 0;
        for (var x : nums) {
            int cnt = 0;
            for (int i = 0; i < x.length(); ++i) {
                if (x.charAt(i) == '1') {
                    ++cnt;
                }
            }
            mask |= 1 << cnt;
        }
        for (int i = 0;; ++i) {
            if ((mask >> i & 1) == 0) {
                return "1".repeat(i) + "0".repeat(nums.length - i);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int mask = 0;
        for (auto& x : nums) {
            int cnt = count(x.begin(), x.end(), '1');
            mask |= 1 << cnt;
        }
        for (int i = 0;; ++i) {
            if (mask >> i & 1 ^ 1) {
                return string(i, '1') + string(nums.size() - i, '0');
            }
        }
    }
};
```

#### Go

```go
func findDifferentBinaryString(nums []string) string {
	mask := 0
	for _, x := range nums {
		mask |= 1 << strings.Count(x, "1")
	}
	for i := 0; ; i++ {
		if mask>>i&1 == 0 {
			return strings.Repeat("1", i) + strings.Repeat("0", len(nums)-i)
		}
	}
}
```

#### TypeScript

```ts
function findDifferentBinaryString(nums: string[]): string {
    let mask = 0;
    for (let x of nums) {
        const cnt = x.split('').filter(c => c === '1').length;
        mask |= 1 << cnt;
    }
    for (let i = 0; ; ++i) {
        if (((mask >> i) & 1) === 0) {
            return '1'.repeat(i) + '0'.repeat(nums.length - i);
        }
    }
}
```

#### C#

```cs
public class Solution {
    public string FindDifferentBinaryString(string[] nums) {
        int mask = 0;
        foreach (var x in nums) {
            int cnt = x.Count(c => c == '1');
            mask |= 1 << cnt;
        }
        int i = 0;
        while ((mask >> i & 1) == 1) {
            i++;
        }
        return string.Format("{0}{1}", new string('1', i), new string('0', nums.Length - i));
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function findDifferentBinaryString(nums: string[]): string {
    const set = new Set(nums.map(x => Number.parseInt(x, 2)));
    let res = 0;

    while (set.has(res)) {
        res++;
    }

    return res.toString(2).padStart(nums[0].length, '0');
}
```

#### JavaScript

```js
function findDifferentBinaryString(nums) {
    const set = new Set(nums.map(x => Number.parseInt(x, 2)));
    let res = 0;

    while (set.has(res)) {
        res++;
    }

    return res.toString(2).padStart(nums[0].length, '0');
}
```

<!-- solution:end -->

<!-- tabs:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### TypeScript

```ts
function findDifferentBinaryString(nums: string[]): string {
    const res: string[] = [];

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i][i];
        res.push(x === '0' ? '1' : '0');
    }

    return res.join('');
}
```

#### JavaScript

```js
function findDifferentBinaryString(nums) {
    const res = [];

    for (let i = 0; i < nums.length; i++) {
        const x = nums[i][i];
        res.push(x === '0' ? '1' : '0');
    }

    return res.join('');
}
```

<!-- solution:end -->

<!-- tabs:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1981. 最小化目标值与所选元素的差](https://leetcode.cn/problems/minimize-the-difference-between-target-and-chosen-elements){#1981}

{{< tabs "1981" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        f = {0}
        for row in mat:
            f = set(a + b for a in f for b in row)
        return min(abs(v - target) for v in f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        boolean[] f = {true};
        for (var row : mat) {
            int mx = 0;
            for (int x : row) {
                mx = Math.max(mx, x);
            }
            boolean[] g = new boolean[f.length + mx];
            for (int x : row) {
                for (int j = x; j < f.length + x; ++j) {
                    g[j] |= f[j - x];
                }
            }
            f = g;
        }
        int ans = 1 << 30;
        for (int j = 0; j < f.length; ++j) {
            if (f[j]) {
                ans = Math.min(ans, Math.abs(j - target));
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<int> f = {1};
        for (auto& row : mat) {
            int mx = *max_element(row.begin(), row.end());
            vector<int> g(f.size() + mx);
            for (int x : row) {
                for (int j = x; j < f.size() + x; ++j) {
                    g[j] |= f[j - x];
                }
            }
            f = move(g);
        }
        int ans = 1 << 30;
        for (int j = 0; j < f.size(); ++j) {
            if (f[j]) {
                ans = min(ans, abs(j - target));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeTheDifference(mat [][]int, target int) int {
	f := []int{1}
	for _, row := range mat {
		mx := slices.Max(row)
		g := make([]int, len(f)+mx)
		for _, x := range row {
			for j := x; j < len(f)+x; j++ {
				g[j] |= f[j-x]
			}
		}
		f = g
	}
	ans := 1 << 30
	for j, v := range f {
		if v == 1 {
			ans = min(ans, abs(j-target))
		}
	}
	return ans
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

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>mat</code> 和一个整数 <code>target</code> 。</p>

<p>从矩阵的 <strong>每一行</strong> 中选择一个整数，你的目标是&nbsp;<strong>最小化</strong>&nbsp;所有选中元素之&nbsp;<strong>和</strong>&nbsp;与目标值 <code>target</code> 的 <strong>绝对差</strong> 。</p>

<p>返回 <strong>最小的绝对差</strong> 。</p>

<p><code>a</code> 和 <code>b</code> 两数字的 <strong>绝对差</strong> 是 <code>a - b</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1981.Minimize%20the%20Difference%20Between%20Target%20and%20Chosen%20Elements/images/matrix1.png" style="width: 181px; height: 181px;" /></p>

<pre>
<strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
<strong>输出：</strong>0
<strong>解释：</strong>一种可能的最优选择方案是：
- 第一行选出 1
- 第二行选出 5
- 第三行选出 7
所选元素的和是 13 ，等于目标值，所以绝对差是 0 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1981.Minimize%20the%20Difference%20Between%20Target%20and%20Chosen%20Elements/images/matrix1-1.png" style="width: 61px; height: 181px;" /></p>

<pre>
<strong>输入：</strong>mat = [[1],[2],[3]], target = 100
<strong>输出：</strong>94
<strong>解释：</strong>唯一一种选择方案是：
- 第一行选出 1
- 第二行选出 2
- 第三行选出 3
所选元素的和是 6 ，绝对差是 94 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1981.Minimize%20the%20Difference%20Between%20Target%20and%20Chosen%20Elements/images/matrix1-3.png" style="width: 301px; height: 61px;" /></p>

<pre>
<strong>输入：</strong>mat = [[1,2,9,8,7]], target = 6
<strong>输出：</strong>1
<strong>解释：</strong>最优的选择方案是选出第一行的 7 。
绝对差是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 70</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 70</code></li>
	<li><code>1 &lt;= target &lt;= 800</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（分组背包）

设 $f[i][j]$ 表示前 $i$ 行是否能选出元素和为 $j$，则有状态转移方程：

$$
f[i][j] = \begin{cases} 1 & \textit{如果存在 } x \in row[i] \textit{ 使得 } f[i - 1][j - x] = 1 \\ 0 & \textit{否则} \end{cases}
$$

其中 $row[i]$ 表示第 $i$ 行的元素集合。

由于 $f[i][j]$ 只与 $f[i - 1][j]$ 有关，因此我们可以使用滚动数组优化空间复杂度。

最后，遍历 $f$ 数组，找出最小的绝对差即可。

时间复杂度 $O(m^2 \times n \times C)$，空间复杂度 $O(m \times C)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数；而 $C$ 为矩阵元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        f = {0}
        for row in mat:
            f = set(a + b for a in f for b in row)
        return min(abs(v - target) for v in f)
```

#### Java

```java
class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        boolean[] f = {true};
        for (var row : mat) {
            int mx = 0;
            for (int x : row) {
                mx = Math.max(mx, x);
            }
            boolean[] g = new boolean[f.length + mx];
            for (int x : row) {
                for (int j = x; j < f.length + x; ++j) {
                    g[j] |= f[j - x];
                }
            }
            f = g;
        }
        int ans = 1 << 30;
        for (int j = 0; j < f.length; ++j) {
            if (f[j]) {
                ans = Math.min(ans, Math.abs(j - target));
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
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<int> f = {1};
        for (auto& row : mat) {
            int mx = *max_element(row.begin(), row.end());
            vector<int> g(f.size() + mx);
            for (int x : row) {
                for (int j = x; j < f.size() + x; ++j) {
                    g[j] |= f[j - x];
                }
            }
            f = move(g);
        }
        int ans = 1 << 30;
        for (int j = 0; j < f.size(); ++j) {
            if (f[j]) {
                ans = min(ans, abs(j - target));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimizeTheDifference(mat [][]int, target int) int {
	f := []int{1}
	for _, row := range mat {
		mx := slices.Max(row)
		g := make([]int, len(f)+mx)
		for _, x := range row {
			for j := x; j < len(f)+x; j++ {
				g[j] |= f[j-x]
			}
		}
		f = g
	}
	ans := 1 << 30
	for j, v := range f {
		if v == 1 {
			ans = min(ans, abs(j-target))
		}
	}
	return ans
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

# [1982. 从子集的和还原数组](https://leetcode.cn/problems/find-array-given-subset-sums){#1982}

{{< tabs "1982" >}}

{{% tab "python" %}}
```python
class Solution:
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        ans = []
        for i in range(n, 0, -1):
            k = 1 << i
            d = sums[k - 1] - sums[k - 2]
            cnt = Counter(sums[:k])
            sums1, sums2 = [], []
            sign = 1
            for s in sums[:k]:
                if not cnt[s]:
                    continue
                cnt[s] -= 1
                cnt[s + d] -= 1
                sums1.append(s)
                sums2.append(s + d)
                if s + d == 0:
                    sign = -1
            ans.append(sign * d)
            sums = sums1 if sign == 1 else sums2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        Arrays.sort(sums);
        int[] sums1 = new int[1 << n];
        int[] sums2 = new int[1 << n];
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[n];
        for (int i = n; i > 0; --i) {
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            cnt.clear();
            for (int j = 0; j < k; ++j) {
                cnt.merge(sums[j], 1, Integer::sum);
            }
            int sign = 1;
            for (int j = 0, p = 0; j < k; ++j) {
                if (cnt.getOrDefault(sums[j], 0) == 0) {
                    continue;
                }
                cnt.merge(sums[j], -1, Integer::sum);
                cnt.merge(sums[j] + d, -1, Integer::sum);
                sums1[p] = sums[j];
                sums2[p++] = sums[j] + d;
                if (sums[j] + d == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            System.arraycopy(sign == 1 ? sums1 : sums2, 0, sums, 0, k / 2);
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
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans(n);
        unordered_map<int, int> cnt;
        for (int i = n; i; --i) {
            cnt.clear();
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            for (int j = 0; j < k; ++j) {
                cnt[sums[j]]++;
            }
            vector<int> sums1, sums2;
            int sign = 1;
            for (int j = 0; j < k; ++j) {
                if (cnt[sums[j]] == 0) {
                    continue;
                }
                --cnt[sums[j]];
                --cnt[sums[j] + d];
                sums1.push_back(sums[j]);
                sums2.push_back(sums[j] + d);
                if (sums2.back() == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            for (int j = 0; j < k / 2; ++j) {
                sums[j] = sign == 1 ? sums1[j] : sums2[j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func recoverArray(n int, sums []int) (ans []int) {
	sort.Ints(sums)
	for i := n; i > 0; i-- {
		k := 1 << i
		d := sums[k-1] - sums[k-2]
		cnt := map[int]int{}
		for _, s := range sums[:k] {
			cnt[s]++
		}
		sums1, sums2 := []int{}, []int{}
		sign := 1
		for _, s := range sums[:k] {
			if cnt[s] == 0 {
				continue
			}
			cnt[s]--
			cnt[s+d]--
			sums1 = append(sums1, s)
			sums2 = append(sums2, s+d)
			if s+d == 0 {
				sign = -1
			}
		}
		ans = append(ans, sign*d)
		if sign == -1 {
			sums1 = sums2
		}
		sums = sums1
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

<p>存在一个未知数组需要你进行还原，给你一个整数 <code>n</code> 表示该数组的长度。另给你一个数组 <code>sums</code> ，由未知数组中全部 <code>2<sup>n</sup></code> 个 <strong>子集的和</strong> 组成（子集中的元素没有特定的顺序）。</p>

<p>返回一个长度为 <code>n</code> 的数组<em> </em><code>ans</code><em> </em>表示还原得到的未知数组。如果存在 <strong>多种</strong> 答案，只需返回其中 <strong>任意一个</strong> 。</p>

<p>如果可以由数组 <code>arr</code> 删除部分元素（也可能不删除或全删除）得到数组 <code>sub</code> ，那么数组 <code>sub</code> 就是数组 <code>arr</code> 的一个<strong> 子集</strong> 。<code>sub</code> 的元素之和就是 <code>arr</code> 的一个 <strong>子集的和</strong> 。一个空数组的元素之和为 <code>0</code> 。</p>

<p><strong>注意：</strong>生成的测试用例将保证至少存在一个正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, sums = [-3,-2,-1,0,0,1,2,3]
<strong>输出：</strong>[1,2,-3]
<strong>解释：</strong>[1,2,-3] 能够满足给出的子集的和：
- []：和是 0
- [1]：和是 1
- [2]：和是 2
- [1,2]：和是 3
- [-3]：和是 -3
- [1,-3]：和是 -2
- [2,-3]：和是 -1
- [1,2,-3]：和是 0
注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, sums = [0,0,0,0]
<strong>输出：</strong>[0,0]
<strong>解释：</strong>唯一的正确答案是 [0,0] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
<strong>输出：</strong>[0,-1,4,5]
<strong>解释：</strong>[0,-1,4,5] 能够满足给出的子集的和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>sums.length == 2<sup>n</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= sums[i] &lt;= 10<sup>4</sup></code></li>
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
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        m = -min(sums)
        sl = SortedList(x + m for x in sums)
        sl.remove(0)
        ans = [sl[0]]
        for i in range(1, n):
            for j in range(1 << i):
                if j >> (i - 1) & 1:
                    s = sum(ans[k] for k in range(i) if j >> k & 1)
                    sl.remove(s)
            ans.append(sl[0])
        for i in range(1 << n):
            s = sum(ans[j] for j in range(n) if i >> j & 1)
            if s == m:
                for j in range(n):
                    if i >> j & 1:
                        ans[j] *= -1
                break
        return ans
```

#### Java

```java
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        int m = 1 << 30;
        for (int x : sums) {
            m = Math.min(m, x);
        }
        m = -m;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int x : sums) {
            tm.merge(x + m, 1, Integer::sum);
        }
        int[] ans = new int[n];
        if (tm.merge(0, -1, Integer::sum) == 0) {
            tm.remove(0);
        }
        ans[0] = tm.firstKey();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 1 << i; ++j) {
                if ((j >> (i - 1) & 1) == 1) {
                    int s = 0;
                    for (int k = 0; k < i; ++k) {
                        if (((j >> k) & 1) == 1) {
                            s += ans[k];
                        }
                    }
                    if (tm.merge(s, -1, Integer::sum) == 0) {
                        tm.remove(s);
                    }
                }
            }
            ans[i] = tm.firstKey();
        }
        for (int i = 0; i < 1 << n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    s += ans[j];
                }
            }
            if (s == m) {
                for (int j = 0; j < n; ++j) {
                    if (((i >> j) & 1) == 1) {
                        ans[j] *= -1;
                    }
                }
                break;
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
    vector<int> recoverArray(int n, vector<int>& sums) {
        int m = *min_element(sums.begin(), sums.end());
        m = -m;
        multiset<int> st;
        for (int x : sums) {
            st.insert(x + m);
        }
        st.erase(st.begin());
        vector<int> ans;
        ans.push_back(*st.begin());
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 1 << i; ++j) {
                if (j >> (i - 1) & 1) {
                    int s = 0;
                    for (int k = 0; k < i; ++k) {
                        if (j >> k & 1) {
                            s += ans[k];
                        }
                    }
                    st.erase(st.find(s));
                }
            }
            ans.push_back(*st.begin());
        }
        for (int i = 0; i < 1 << n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    s += ans[j];
                }
            }
            if (s == m) {
                for (int j = 0; j < n; ++j) {
                    if (i >> j & 1) {
                        ans[j] = -ans[j];
                    }
                }
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func recoverArray(n int, sums []int) []int {
	m := -slices.Min(sums)
	rbt := redblacktree.NewWithIntComparator()
	merge := func(key int, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}
	for _, x := range sums {
		merge(x+m, 1)
	}
	ans := make([]int, n)
	merge(ans[0], -1)
	ans[0] = rbt.Left().Key.(int)
	for i := 1; i < n; i++ {
		for j := 0; j < 1<<i; j++ {
			if j>>(i-1)&1 == 1 {
				s := 0
				for k := 0; k < i; k++ {
					if j>>k&1 == 1 {
						s += ans[k]
					}
				}
				merge(s, -1)
			}
		}
		ans[i] = rbt.Left().Key.(int)
	}
	for i := 0; i < 1<<n; i++ {
		s := 0
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				s += ans[j]
			}
		}
		if s == m {
			for j := 0; j < n; j++ {
				if i>>j&1 == 1 {
					ans[j] = -ans[j]
				}
			}
			break
		}
	}
	return ans

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
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        ans = []
        for i in range(n, 0, -1):
            k = 1 << i
            d = sums[k - 1] - sums[k - 2]
            cnt = Counter(sums[:k])
            sums1, sums2 = [], []
            sign = 1
            for s in sums[:k]:
                if not cnt[s]:
                    continue
                cnt[s] -= 1
                cnt[s + d] -= 1
                sums1.append(s)
                sums2.append(s + d)
                if s + d == 0:
                    sign = -1
            ans.append(sign * d)
            sums = sums1 if sign == 1 else sums2
        return ans
```

#### Java

```java
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        Arrays.sort(sums);
        int[] sums1 = new int[1 << n];
        int[] sums2 = new int[1 << n];
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[n];
        for (int i = n; i > 0; --i) {
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            cnt.clear();
            for (int j = 0; j < k; ++j) {
                cnt.merge(sums[j], 1, Integer::sum);
            }
            int sign = 1;
            for (int j = 0, p = 0; j < k; ++j) {
                if (cnt.getOrDefault(sums[j], 0) == 0) {
                    continue;
                }
                cnt.merge(sums[j], -1, Integer::sum);
                cnt.merge(sums[j] + d, -1, Integer::sum);
                sums1[p] = sums[j];
                sums2[p++] = sums[j] + d;
                if (sums[j] + d == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            System.arraycopy(sign == 1 ? sums1 : sums2, 0, sums, 0, k / 2);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans(n);
        unordered_map<int, int> cnt;
        for (int i = n; i; --i) {
            cnt.clear();
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            for (int j = 0; j < k; ++j) {
                cnt[sums[j]]++;
            }
            vector<int> sums1, sums2;
            int sign = 1;
            for (int j = 0; j < k; ++j) {
                if (cnt[sums[j]] == 0) {
                    continue;
                }
                --cnt[sums[j]];
                --cnt[sums[j] + d];
                sums1.push_back(sums[j]);
                sums2.push_back(sums[j] + d);
                if (sums2.back() == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            for (int j = 0; j < k / 2; ++j) {
                sums[j] = sign == 1 ? sums1[j] : sums2[j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func recoverArray(n int, sums []int) (ans []int) {
	sort.Ints(sums)
	for i := n; i > 0; i-- {
		k := 1 << i
		d := sums[k-1] - sums[k-2]
		cnt := map[int]int{}
		for _, s := range sums[:k] {
			cnt[s]++
		}
		sums1, sums2 := []int{}, []int{}
		sign := 1
		for _, s := range sums[:k] {
			if cnt[s] == 0 {
				continue
			}
			cnt[s]--
			cnt[s+d]--
			sums1 = append(sums1, s)
			sums2 = append(sums2, s+d)
			if s+d == 0 {
				sign = -1
			}
		}
		ans = append(ans, sign*d)
		if sign == -1 {
			sums1 = sums2
		}
		sums = sums1
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1983. 范围和相等的最宽索引对 🔒](https://leetcode.cn/problems/widest-pair-of-indices-with-equal-range-sum){#1983}

{{< tabs "1983" >}}

{{% tab "python" %}}
```python
class Solution:
    def widestPairOfIndices(self, nums1: List[int], nums2: List[int]) -> int:
        d = {0: -1}
        ans = s = 0
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            s += a - b
            if s in d:
                ans = max(ans, i - d[s])
            else:
                d[s] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int widestPairOfIndices(int[] nums1, int[] nums2) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int n = nums1.length;
        int s = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s += nums1[i] - nums2[i];
            if (d.containsKey(s)) {
                ans = Math.max(ans, i - d.get(s));
            } else {
                d.put(s, i);
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
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> d;
        d[0] = -1;
        int ans = 0, s = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            s += nums1[i] - nums2[i];
            if (d.count(s)) {
                ans = max(ans, i - d[s]);
            } else {
                d[s] = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func widestPairOfIndices(nums1 []int, nums2 []int) (ans int) {
	d := map[int]int{0: -1}
	s := 0
	for i := range nums1 {
		s += nums1[i] - nums2[i]
		if j, ok := d[s]; ok {
			ans = max(ans, i-j)
		} else {
			d[s] = i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function widestPairOfIndices(nums1: number[], nums2: number[]): number {
    const d: Map<number, number> = new Map();
    d.set(0, -1);
    const n: number = nums1.length;
    let s: number = 0;
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        s += nums1[i] - nums2[i];
        if (d.has(s)) {
            ans = Math.max(ans, i - (d.get(s) as number));
        } else {
            d.set(s, i);
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

<p>给定两个 <strong>以0为索引</strong> 的二进制数组 <code>nums1</code> 和 <code>nums2</code> 。找出 <strong>最宽</strong> 的索引对 <code>(i, j)</code> ，使的&nbsp;<code>i &lt;= j</code>&nbsp;并且&nbsp;<code>nums1[i] + nums1[i+1] + ... + nums1[j] == nums2[i] + nums2[i+1] + ... + nums2[j]</code>。</p>

<p><strong>最宽</strong> 的指标对是指在 <code>i </code>和<code> j </code>之间的 <strong>距离最大</strong> 的指标对。一对指标之间的 <strong>距离</strong> 定义为<code> j - i + 1</code> 。</p>

<p>返回 <strong>最宽</strong> 索引对的 <strong>距离</strong> 。如果没有满足条件的索引对，则返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [1,1,0,1], nums2 = [0,1,1,0]
<strong>输出:</strong> 3
<strong>解释:</strong>
如果i = 1, j = 3:
Nums1 [1] + Nums1 [2] + Nums1[3] = 1 + 0 + 1 = 2。
Nums2 [1] + Nums2 [2] + Nums2[3] = 1 + 1 + 0 = 2。
i和j之间的距离是j - i + 1 = 3 - 1 + 1 = 3。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [0,1], nums2 = [1,1]
<strong>输出:</strong> 1
<strong>解释:
</strong>If i = 1 and j = 1:
nums1[1] = 1。
nums2[1] = 1。
i和j之间的距离是j - i + 1 = 1 - 1 + 1 = 1。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [0], nums2 = [1]
<strong>输出:</strong> 0
<strong>解释:
</strong>没有满足要求的索引对。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums1[i]</code>&nbsp;仅为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
	<li><code>nums2[i]</code>&nbsp;仅为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们观察到，对于任意的索引对 $(i, j)$，如果 $nums1[i] + nums1[i+1] + ... + nums1[j] = nums2[i] + nums2[i+1] + ... + nums2[j]$，那么 $nums1[i] - nums2[i] + nums1[i+1] - nums2[i+1] + ... + nums1[j] - nums2[j] = 0$。如果我们将数组 $nums1$ 与数组 $nums2$ 对应位置的元素相减，得到一个新的数组 $nums$，那么问题转换为在数组 $nums$ 中找到一个最长的子数组，使得子数组的和为 $0$。这可以通过前缀和 + 哈希表的方法求解。

我们定义一个变量 $s$ 表示当前 $nums$ 的前缀和，用一个哈希表 $d$ 保存每个前缀和第一次出现的位置。初始时 $s = 0$, $d[0] = -1$。

接下来，我们遍历数组 $nums$ 中的每个元素 $x$，计算 $s$ 的值，然后检查哈希表中是否存在 $s$，如果哈希表存在 $s$，那么说明存在一个子数组 $nums[d[s]+1,..i]$，使得子数组的和为 $0$，我们更新答案为 $\max(ans, i - d[s])$。否则，我们将 $s$ 的值加入哈希表中，表示 $s$ 第一次出现的位置为 $i$。

遍历结束，即可得到最终的答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def widestPairOfIndices(self, nums1: List[int], nums2: List[int]) -> int:
        d = {0: -1}
        ans = s = 0
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            s += a - b
            if s in d:
                ans = max(ans, i - d[s])
            else:
                d[s] = i
        return ans
```

#### Java

```java
class Solution {
    public int widestPairOfIndices(int[] nums1, int[] nums2) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int n = nums1.length;
        int s = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s += nums1[i] - nums2[i];
            if (d.containsKey(s)) {
                ans = Math.max(ans, i - d.get(s));
            } else {
                d.put(s, i);
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
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> d;
        d[0] = -1;
        int ans = 0, s = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            s += nums1[i] - nums2[i];
            if (d.count(s)) {
                ans = max(ans, i - d[s]);
            } else {
                d[s] = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func widestPairOfIndices(nums1 []int, nums2 []int) (ans int) {
	d := map[int]int{0: -1}
	s := 0
	for i := range nums1 {
		s += nums1[i] - nums2[i]
		if j, ok := d[s]; ok {
			ans = max(ans, i-j)
		} else {
			d[s] = i
		}
	}
	return
}
```

#### TypeScript

```ts
function widestPairOfIndices(nums1: number[], nums2: number[]): number {
    const d: Map<number, number> = new Map();
    d.set(0, -1);
    const n: number = nums1.length;
    let s: number = 0;
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        s += nums1[i] - nums2[i];
        if (d.has(s)) {
            ans = Math.max(ans, i - (d.get(s) as number));
        } else {
            d.set(s, i);
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

# [1984. 学生分数的最小差值](https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores){#1984}

{{< tabs "1984" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 100000;
        for (int i = 0; i < nums.length - k + 1; ++i) {
            ans = Math.min(ans, nums[i + k - 1] - nums[i]);
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
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1e5;
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDifference(nums []int, k int) int {
	sort.Ints(nums)
	ans := 100000
	for i := 0; i < len(nums)-k+1; i++ {
		ans = min(ans, nums[i+k-1]-nums[i])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDifference(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let ans = nums[n - 1] - nums[0];
    for (let i = 0; i + k - 1 < n; i++) {
        ans = Math.min(nums[i + k - 1] - nums[i], ans);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let k = k as usize;
        let mut res = i32::MAX;
        for i in 0..=nums.len() - k {
            res = res.min(nums[i + k - 1] - nums[i]);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function minimumDifference($nums, $k) {
        sort($nums);
        $ans = 10 ** 5;
        for ($i = 0; $i < count($nums) - $k + 1; $i++) {
            $ans = min($ans, $nums[$i + $k - 1] - $nums[$i]);
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

<p>给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>nums</code> ，其中 <code>nums[i]</code> 表示第 <code>i</code> 名学生的分数。另给你一个整数 <code>k</code> 。</p>

<p>从数组中选出任意 <code>k</code> 名学生的分数，使这 <code>k</code> 个分数间 <strong>最高分</strong> 和 <strong>最低分</strong> 的 <strong>差值</strong> 达到<strong> 最小化</strong> 。</p>

<p>返回可能的 <strong>最小差值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [90], k = 1
<strong>输出：</strong>0
<strong>解释：</strong>选出 1 名学生的分数，仅有 1 种方法：
- [<em><strong>90</strong></em>] 最高分和最低分之间的差值是 90 - 90 = 0
可能的最小差值是 0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,4,1,7], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>选出 2 名学生的分数，有 6 种方法：
- [<em><strong>9</strong></em>,<em><strong>4</strong></em>,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
- [<em><strong>9</strong></em>,4,<em><strong>1</strong></em>,7] 最高分和最低分之间的差值是 9 - 1 = 8
- [<em><strong>9</strong></em>,4,1,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 9 - 7 = 2
- [9,<em><strong>4</strong></em>,<em><strong>1</strong></em>,7] 最高分和最低分之间的差值是 4 - 1 = 3
- [9,<em><strong>4</strong></em>,1,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 7 - 4 = 3
- [9,4,<em><strong>1</strong></em>,<em><strong>7</strong></em>] 最高分和最低分之间的差值是 7 - 1 = 6
可能的最小差值是 2</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 滑动窗口

我们可以将学生的分数按照升序排序，然后使用滑动窗口的方法，每次取大小为 $k$ 的窗口，计算窗口内的最大值和最小值的差值，最后取所有窗口的差值的最小值。

为什么是取连续的 $k$ 个学生的分数呢？因为如果不连续，那么最大值和最小值的的差值可能不变，或者变大，但一定不会变小。因此，我们只需要考虑排序后的连续的 $k$ 个学生的分数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是学生的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))
```

#### Java

```java
class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 100000;
        for (int i = 0; i < nums.length - k + 1; ++i) {
            ans = Math.min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1e5;
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDifference(nums []int, k int) int {
	sort.Ints(nums)
	ans := 100000
	for i := 0; i < len(nums)-k+1; i++ {
		ans = min(ans, nums[i+k-1]-nums[i])
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDifference(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let ans = nums[n - 1] - nums[0];
    for (let i = 0; i + k - 1 < n; i++) {
        ans = Math.min(nums[i + k - 1] - nums[i], ans);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let k = k as usize;
        let mut res = i32::MAX;
        for i in 0..=nums.len() - k {
            res = res.min(nums[i + k - 1] - nums[i]);
        }
        res
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function minimumDifference($nums, $k) {
        sort($nums);
        $ans = 10 ** 5;
        for ($i = 0; $i < count($nums) - $k + 1; $i++) {
            $ans = min($ans, $nums[$i + $k - 1] - $nums[$i]);
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

# [1985. 找出数组中的第 K 大整数](https://leetcode.cn/problems/find-the-kth-largest-integer-in-the-array){#1985}

{{< tabs "1985" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        return nlargest(k, nums, key=lambda x: int(x))[k - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        Arrays.sort(
            nums, (a, b) -> a.length() == b.length() ? b.compareTo(a) : b.length() - a.length());
        return nums[k - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a > b : a.size() > b.size();
        });
        return nums[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthLargestNumber(nums []string, k int) string {
	sort.Slice(nums, func(i, j int) bool {
		a, b := nums[i], nums[j]
		if len(a) == len(b) {
			return a > b
		}
		return len(a) > len(b)
	})
	return nums[k-1]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>nums</code> 和一个整数 <code>k</code> 。<code>nums</code> 中的每个字符串都表示一个不含前导零的整数。</p>

<p>返回 <code>nums</code> 中表示第 <code>k</code> 大整数的字符串。</p>

<p><strong>注意：</strong>重复的数字在统计时会视为不同元素考虑。例如，如果 <code>nums</code> 是 <code>["1","2","2"]</code>，那么 <code>"2"</code> 是最大的整数，<code>"2"</code> 是第二大的整数，<code>"1"</code> 是第三大的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = ["3","6","7","10"], k = 4
<strong>输出：</strong>"3"
<strong>解释：</strong>
nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
其中第 4 大整数是 "3"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = ["2","21","12","1"], k = 3
<strong>输出：</strong>"2"
<strong>解释：</strong>
nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
其中第 3 大整数是 "2"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = ["0","0"], k = 2
<strong>输出：</strong>"0"
<strong>解释：</strong>
nums 中的数字按非递减顺序排列为 ["0","0"]
其中第 2 大整数是 "0"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>nums[i]</code> 仅由数字组成</li>
	<li><code>nums[i]</code> 不含任何前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序或快速选择

我们可以将 $\textit{nums}$ 数组中的字符串按照整数从大到小排序，然后取第 $k$ 个元素即可。也可以使用快速选择算法，找到第 $k$ 大的整数。

时间复杂度 $O(n \times \log n)$ 或 $O(n)$，其中 $n$ 是 $\textit{nums}$ 数组的长度。空间复杂度 $O(\log n)$ 或 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        return nlargest(k, nums, key=lambda x: int(x))[k - 1]
```

#### Java

```java
class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        Arrays.sort(
            nums, (a, b) -> a.length() == b.length() ? b.compareTo(a) : b.length() - a.length());
        return nums[k - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a > b : a.size() > b.size();
        });
        return nums[k - 1];
    }
};
```

#### Go

```go
func kthLargestNumber(nums []string, k int) string {
	sort.Slice(nums, func(i, j int) bool {
		a, b := nums[i], nums[j]
		if len(a) == len(b) {
			return a > b
		}
		return len(a) > len(b)
	})
	return nums[k-1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1986. 完成任务的最少工作时间段](https://leetcode.cn/problems/minimum-number-of-work-sessions-to-finish-the-tasks){#1986}

{{< tabs "1986" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        n = len(tasks)
        ok = [False] * (1 << n)
        for i in range(1, 1 << n):
            t = sum(tasks[j] for j in range(n) if i >> j & 1)
            ok[i] = t <= sessionTime
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            j = i
            while j:
                if ok[j]:
                    f[i] = min(f[i], f[i ^ j] + 1)
                j = (j - 1) & i
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSessions(int[] tasks, int sessionTime) {
        int n = tasks.length;
        boolean[] ok = new boolean[1 << n];
        for (int i = 1; i < 1 << n; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    t += tasks[j];
                }
            }
            ok[i] = t <= sessionTime;
        }
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = i; j > 0; j = (j - 1) & i) {
                if (ok[j]) {
                    f[i] = Math.min(f[i], f[i ^ j] + 1);
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
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        bool ok[1 << n];
        memset(ok, false, sizeof(ok));
        for (int i = 1; i < 1 << n; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    t += tasks[j];
                }
            }
            ok[i] = t <= sessionTime;
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                if (ok[j]) {
                    f[i] = min(f[i], f[i ^ j] + 1);
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
func minSessions(tasks []int, sessionTime int) int {
	n := len(tasks)
	ok := make([]bool, 1<<n)
	f := make([]int, 1<<n)
	for i := 1; i < 1<<n; i++ {
		t := 0
		f[i] = 1 << 30
		for j, x := range tasks {
			if i>>j&1 == 1 {
				t += x
			}
		}
		ok[i] = t <= sessionTime
	}
	for i := 1; i < 1<<n; i++ {
		for j := i; j > 0; j = (j - 1) & i {
			if ok[j] {
				f[i] = min(f[i], f[i^j]+1)
			}
		}
	}
	return f[1<<n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSessions(tasks: number[], sessionTime: number): number {
    const n = tasks.length;
    const ok: boolean[] = new Array(1 << n).fill(false);
    for (let i = 1; i < 1 << n; ++i) {
        let t = 0;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                t += tasks[j];
            }
        }
        ok[i] = t <= sessionTime;
    }

    const f: number[] = new Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 1; i < 1 << n; ++i) {
        for (let j = i; j > 0; j = (j - 1) & i) {
            if (ok[j]) {
                f[i] = Math.min(f[i], f[i ^ j] + 1);
            }
        }
    }
    return f[(1 << n) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你被安排了 <code>n</code>&nbsp;个任务。任务需要花费的时间用长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>tasks</code>&nbsp;表示，第 <code>i</code>&nbsp;个任务需要花费&nbsp;<code>tasks[i]</code>&nbsp;小时完成。一个 <strong>工作时间段</strong>&nbsp;中，你可以 <strong>至多</strong>&nbsp;连续工作&nbsp;<code>sessionTime</code>&nbsp;个小时，然后休息一会儿。</p>

<p>你需要按照如下条件完成给定任务：</p>

<ul>
	<li>如果你在某一个时间段开始一个任务，你需要在 <strong>同一个</strong>&nbsp;时间段完成它。</li>
	<li>完成一个任务后，你可以 <strong>立马</strong>&nbsp;开始一个新的任务。</li>
	<li>你可以按 <strong>任意顺序</strong>&nbsp;完成任务。</li>
</ul>

<p>给你&nbsp;<code>tasks</code> 和&nbsp;<code>sessionTime</code>&nbsp;，请你按照上述要求，返回完成所有任务所需要的&nbsp;<strong>最少</strong>&nbsp;数目的&nbsp;<strong>工作时间段</strong>&nbsp;。</p>

<p>测试数据保证&nbsp;<code>sessionTime</code> <strong>大于等于</strong>&nbsp;<code>tasks[i]</code>&nbsp;中的&nbsp;<strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [1,2,3], sessionTime = 3
<b>输出：</b>2
<b>解释：</b>你可以在两个工作时间段内完成所有任务。
- 第一个工作时间段：完成第一和第二个任务，花费 1 + 2 = 3 小时。
- 第二个工作时间段：完成第三个任务，花费 3 小时。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [3,1,3,1,1], sessionTime = 8
<b>输出：</b>2
<b>解释：</b>你可以在两个工作时间段内完成所有任务。
- 第一个工作时间段：完成除了最后一个任务以外的所有任务，花费 3 + 1 + 3 + 1 = 8 小时。
- 第二个工作时间段，完成最后一个任务，花费 1 小时。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>tasks = [1,2,3,4,5], sessionTime = 15
<b>输出：</b>1
<b>解释：</b>你可以在一个工作时间段以内完成所有任务。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == tasks.length</code></li>
	<li><code>1 &lt;= n &lt;= 14</code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10</code></li>
	<li><code>max(tasks[i]) &lt;= sessionTime &lt;= 15</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划 + 枚举子集

我们注意到 $n$ 不超过 $14$，因此，我们可以考虑使用状态压缩动态规划的方法求解本题。

我们用一个长度为 $n$ 的二进制数 $i$ 来表示当前的任务状态，其中 $i$ 的第 $j$ 位为 $1$，当且仅当第 $j$ 个任务被完成。我们用 $f[i]$ 表示完成状态为 $i$ 的所有任务所需要的最少工作时间段数。

我们可以枚举 $i$ 的所有子集 $j$，其中 $j$ 的二进制表示中的每一位都是 $i$ 的二进制表示中对应位的子集，即 $j \subseteq i$。如果 $j$ 对应的任务可以在一个工作时间段内完成，那么我们可以用 $f[i \oplus j] + 1$ 来更新 $f[i]$，其中 $i \oplus j$ 表示 $i$ 和 $j$ 的按位异或。

最终的答案即为 $f[2^n - 1]$。

时间复杂度 $O(n \times 3^n)$，空间复杂度 $O(2^n)$。其中 $n$ 为任务的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        n = len(tasks)
        ok = [False] * (1 << n)
        for i in range(1, 1 << n):
            t = sum(tasks[j] for j in range(n) if i >> j & 1)
            ok[i] = t <= sessionTime
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            j = i
            while j:
                if ok[j]:
                    f[i] = min(f[i], f[i ^ j] + 1)
                j = (j - 1) & i
        return f[-1]
```

#### Java

```java
class Solution {
    public int minSessions(int[] tasks, int sessionTime) {
        int n = tasks.length;
        boolean[] ok = new boolean[1 << n];
        for (int i = 1; i < 1 << n; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    t += tasks[j];
                }
            }
            ok[i] = t <= sessionTime;
        }
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = i; j > 0; j = (j - 1) & i) {
                if (ok[j]) {
                    f[i] = Math.min(f[i], f[i ^ j] + 1);
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
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        bool ok[1 << n];
        memset(ok, false, sizeof(ok));
        for (int i = 1; i < 1 << n; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    t += tasks[j];
                }
            }
            ok[i] = t <= sessionTime;
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                if (ok[j]) {
                    f[i] = min(f[i], f[i ^ j] + 1);
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minSessions(tasks []int, sessionTime int) int {
	n := len(tasks)
	ok := make([]bool, 1<<n)
	f := make([]int, 1<<n)
	for i := 1; i < 1<<n; i++ {
		t := 0
		f[i] = 1 << 30
		for j, x := range tasks {
			if i>>j&1 == 1 {
				t += x
			}
		}
		ok[i] = t <= sessionTime
	}
	for i := 1; i < 1<<n; i++ {
		for j := i; j > 0; j = (j - 1) & i {
			if ok[j] {
				f[i] = min(f[i], f[i^j]+1)
			}
		}
	}
	return f[1<<n-1]
}
```

#### TypeScript

```ts
function minSessions(tasks: number[], sessionTime: number): number {
    const n = tasks.length;
    const ok: boolean[] = new Array(1 << n).fill(false);
    for (let i = 1; i < 1 << n; ++i) {
        let t = 0;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 1) {
                t += tasks[j];
            }
        }
        ok[i] = t <= sessionTime;
    }

    const f: number[] = new Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 1; i < 1 << n; ++i) {
        for (let j = i; j > 0; j = (j - 1) & i) {
            if (ok[j]) {
                f[i] = Math.min(f[i], f[i ^ j] + 1);
            }
        }
    }
    return f[(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1987. 不同的好子序列数目](https://leetcode.cn/problems/number-of-unique-good-subsequences){#1987}

{{< tabs "1987" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        f = g = 0
        ans = 0
        mod = 10**9 + 7
        for c in binary:
            if c == "0":
                g = (g + f) % mod
                ans = 1
            else:
                f = (f + g + 1) % mod
        ans = (ans + f + g) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        final int mod = (int) 1e9 + 7;
        int f = 0, g = 0;
        int ans = 0;
        for (int i = 0; i < binary.length(); ++i) {
            if (binary.charAt(i) == '0') {
                g = (g + f) % mod;
                ans = 1;
            } else {
                f = (f + g + 1) % mod;
            }
        }
        ans = (ans + f + g) % mod;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int mod = 1e9 + 7;
        int f = 0, g = 0;
        int ans = 0;
        for (char& c : binary) {
            if (c == '0') {
                g = (g + f) % mod;
                ans = 1;
            } else {
                f = (f + g + 1) % mod;
            }
        }
        ans = (ans + f + g) % mod;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfUniqueGoodSubsequences(binary string) (ans int) {
	const mod int = 1e9 + 7
	f, g := 0, 0
	for _, c := range binary {
		if c == '0' {
			g = (g + f) % mod
			ans = 1
		} else {
			f = (f + g + 1) % mod
		}
	}
	ans = (ans + f + g) % mod
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfUniqueGoodSubsequences(binary: string): number {
    let [f, g] = [0, 0];
    let ans = 0;
    const mod = 1e9 + 7;
    for (const c of binary) {
        if (c === '0') {
            g = (g + f) % mod;
            ans = 1;
        } else {
            f = (f + g + 1) % mod;
        }
    }
    ans = (ans + f + g) % mod;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串&nbsp;<code>binary</code>&nbsp;。&nbsp;<code>binary</code>&nbsp;的一个 <strong>子序列</strong>&nbsp;如果是 <strong>非空</strong>&nbsp;的且没有 <b>前导</b>&nbsp;<strong>0</strong>&nbsp;（除非数字是 <code>"0"</code>&nbsp;本身），那么它就是一个 <strong>好</strong>&nbsp;的子序列。</p>

<p>请你找到&nbsp;<code>binary</code>&nbsp;<strong>不同好子序列</strong>&nbsp;的数目。</p>

<ul>
	<li>比方说，如果&nbsp;<code>binary = "001"</code>&nbsp;，那么所有 <strong>好</strong>&nbsp;子序列为&nbsp;<code>["0", "0", "1"]</code>&nbsp;，所以 <b>不同</b>&nbsp;的好子序列为&nbsp;<code>"0"</code> 和&nbsp;<code>"1"</code>&nbsp;。 注意，子序列&nbsp;<code>"00"</code>&nbsp;，<code>"01"</code>&nbsp;和&nbsp;<code>"001"</code>&nbsp;不是好的，因为它们有前导 0 。</li>
</ul>

<p>请你返回&nbsp;<code>binary</code>&nbsp;中&nbsp;<strong>不同好子序列</strong>&nbsp;的数目。由于答案可能很大，请将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>一个 <strong>子序列</strong>&nbsp;指的是从原数组中删除若干个（可以一个也不删除）元素后，不改变剩余元素顺序得到的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>binary = "001"
<b>输出：</b>2
<b>解释：</b>好的二进制子序列为 ["0", "0", "1"] 。
不同的好子序列为 "0" 和 "1" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>binary = "11"
<b>输出：</b>2
<b>解释：</b>好的二进制子序列为 ["1", "1", "11"] 。
不同的好子序列为 "1" 和 "11" 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>binary = "101"
<b>输出：</b>5
<b>解释：</b>好的二进制子序列为 ["1", "0", "1", "10", "11", "101"] 。
不同的好子序列为 "0" ，"1" ，"10" ，"11" 和 "101" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= binary.length &lt;= 10<sup>5</sup></code></li>
	<li><code>binary</code>&nbsp;只含有&nbsp;<code>'0'</code>&nbsp;和&nbsp;<code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f$ 表示以 $1$ 结尾的不同好子序列的数目，定义 $g$ 表示以 $0$ 结尾的且以 $1$ 开头的不同好子序列的数目。初始时 $f = g = 0$。

对于一个二进制字符串，我们可以从左到右遍历每一位，假设当前位为 $c$，那么：

-   如果 $c = 0$，那么我们可以在 $f$ 和 $g$ 个不同的好子序列拼上 $c$，因此更新 $g = (g + f) \bmod (10^9 + 7)$；
-   如果 $c = 1$，那么我们可以在 $f$ 和 $g$ 个不同的好子序列拼上 $c$，同时还可以单独拼上 $c$，因此更新 $f = (f + g + 1) \bmod (10^9 + 7)$。

如果字符串包含 $0$，那么最终答案为 $f + g + 1$，否则答案为 $f + g$。

时间复杂度 $O(n)$，其中 $n$ 是字符串长度。空间复杂度 $O(1)$。

相似题目：

-   [940. 不同的子序列 II](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0940.Distinct%20Subsequences%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        f = g = 0
        ans = 0
        mod = 10**9 + 7
        for c in binary:
            if c == "0":
                g = (g + f) % mod
                ans = 1
            else:
                f = (f + g + 1) % mod
        ans = (ans + f + g) % mod
        return ans
```

#### Java

```java
class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        final int mod = (int) 1e9 + 7;
        int f = 0, g = 0;
        int ans = 0;
        for (int i = 0; i < binary.length(); ++i) {
            if (binary.charAt(i) == '0') {
                g = (g + f) % mod;
                ans = 1;
            } else {
                f = (f + g + 1) % mod;
            }
        }
        ans = (ans + f + g) % mod;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int mod = 1e9 + 7;
        int f = 0, g = 0;
        int ans = 0;
        for (char& c : binary) {
            if (c == '0') {
                g = (g + f) % mod;
                ans = 1;
            } else {
                f = (f + g + 1) % mod;
            }
        }
        ans = (ans + f + g) % mod;
        return ans;
    }
};
```

#### Go

```go
func numberOfUniqueGoodSubsequences(binary string) (ans int) {
	const mod int = 1e9 + 7
	f, g := 0, 0
	for _, c := range binary {
		if c == '0' {
			g = (g + f) % mod
			ans = 1
		} else {
			f = (f + g + 1) % mod
		}
	}
	ans = (ans + f + g) % mod
	return
}
```

#### TypeScript

```ts
function numberOfUniqueGoodSubsequences(binary: string): number {
    let [f, g] = [0, 0];
    let ans = 0;
    const mod = 1e9 + 7;
    for (const c of binary) {
        if (c === '0') {
            g = (g + f) % mod;
            ans = 1;
        } else {
            f = (f + g + 1) % mod;
        }
    }
    ans = (ans + f + g) % mod;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1988. 找出每所学校的最低分数要求 🔒](https://leetcode.cn/problems/find-cutoff-score-for-each-school){#1988}

{{< tabs "1988" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT school_id, MIN(IFNULL(score, -1)) AS score
FROM
    Schools AS s
    LEFT JOIN Exam AS e ON s.capacity >= e.student_count
GROUP BY school_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Schools</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| school_id   | int  |
| capacity    | int  |
+-------------+------+
school_id 是该表具有唯一值的列。
此表包含了一些学校的容纳能力。容纳能力指的是学校能够接纳学生的最大数量。
</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Exam</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| score         | int  |
| student_count | int  |
+---------------+------+
score 是该表具有唯一值的列。
表中每一行表示有 student_count 名学生在考试中至少获得了 score 分。
表中的数据在逻辑上是正确的，即记录了高 score 的行相比记录了低 score 的行拥有相同或更少的 student_count。也就是说，对于表中的 i 行与 j 行，如果 score<sub>i</sub> &gt; score<sub>j，那么 </sub>student_count<sub>i</sub> &lt;= student_count<sub>j</sub>
</pre>

<p>每年，学校会公布学生申请所需的<strong>最低分数要求</strong>。学校根据所有学生的考试成绩来决定其最低分数要求。</p>

<ol>
	<li>学校希望确保即使 <strong>每</strong> 一个满足分数要求的学生都申请该学校，学校也有足够的能力接纳每一个学生。</li>
	<li>学校也希望&nbsp;<strong>尽可能多&nbsp;</strong>的学生能申请该学校。</li>
	<li>学校&nbsp;<strong>必须&nbsp;</strong>使用在&nbsp;<code>Exam</code> 表中的 score 来作为最低分数要求。</li>
</ol>

<p>编写一个解决方案，报告每所学校的&nbsp;<strong>最低分数要求</strong>。如果同时有多个 score 值满足上述要求，则选择其中&nbsp;<strong>最小的</strong>一个。如果数据不足以决定&nbsp;<strong>最低分数要求</strong>，那么输出&nbsp;<code>-1</code>。</p>

<p>返回的结果表可以按&nbsp;<strong>任意顺序&nbsp;</strong>排序。</p>

<p>结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong>
Schools 表:
+-----------+----------+
| school_id | capacity |
+-----------+----------+
| 11        | 151      |
| 5         | 48       |
| 9         | 9        |
| 10        | 99       |
+-----------+----------+
Exam 表:
+-------+---------------+
| score | student_count |
+-------+---------------+
| 975   | 10            |
| 966   | 60            |
| 844   | 76            |
| 749   | 76            |
| 744   | 100           |
+-------+---------------+
<strong>输出:</strong>
+-----------+-------+
| school_id | score |
+-----------+-------+
| 5         | 975   |
| 9         | -1    |
| 10        | 749   |
| 11        | 744   |
+-----------+-------+
<b>解释：</b> 
- School 5：学校的容纳能力为 48 。选择 975 作为最低分数要求，因为学校最多会收到 10 份申请，这在学校的容纳能力以内。
- School 10：学校的容纳能力为 99 。可以选择 844 或 749 作为最低分数要求，因为学校最多会收到 76 份申请，这在学校的容纳能力以内。又因为 749 是所有可选项中最小的，因此我们选择 749 。
- School 11：学校的容纳能力为 151 。选择 744 作为最低分数要求，因为学校最多会收到 100 份申请，这在学校的容纳能力以内。
- School 9：给出的数据不足以确定最低分数要求。如果选择 975 作为最低分数要求，学校可能会收到 10 份申请，然而学校的容纳能力只有 9 。我们没有关于更高分数的信息，因此我们返回 -1 。
</pre>

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
SELECT school_id, MIN(IFNULL(score, -1)) AS score
FROM
    Schools AS s
    LEFT JOIN Exam AS e ON s.capacity >= e.student_count
GROUP BY school_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1989. 捉迷藏中可捕获的最大人数 🔒](https://leetcode.cn/problems/maximum-number-of-people-that-can-be-caught-in-tag){#1989}

{{< tabs "1989" >}}

{{% tab "python" %}}
```python
class Solution:
    def catchMaximumAmountofPeople(self, team: List[int], dist: int) -> int:
        ans = j = 0
        n = len(team)
        for i, x in enumerate(team):
            if x:
                while j < n and (team[j] or i - j > dist):
                    j += 1
                if j < n and abs(i - j) <= dist:
                    ans += 1
                    j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int catchMaximumAmountofPeople(int[] team, int dist) {
        int ans = 0;
        int n = team.length;
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i] == 1) {
                while (j < n && (team[j] == 1 || i - j > dist)) {
                    ++j;
                }
                if (j < n && Math.abs(i - j) <= dist) {
                    ++ans;
                    ++j;
                }
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
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int ans = 0;
        int n = team.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i]) {
                while (j < n && (team[j] || i - j > dist)) {
                    ++j;
                }
                if (j < n && abs(i - j) <= dist) {
                    ++ans;
                    ++j;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func catchMaximumAmountofPeople(team []int, dist int) (ans int) {
	n := len(team)
	for i, j := 0, 0; i < n; i++ {
		if team[i] == 1 {
			for j < n && (team[j] == 1 || i-j > dist) {
				j++
			}
			if j < n && abs(i-j) <= dist {
				ans++
				j++
			}
		}
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
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在和你的朋友玩捉迷藏游戏。在捉迷藏比赛中，人们被分成两组：是 “鬼” 的人，和不是 “鬼” 的人。是 “鬼” 的人想要抓住尽可能多的不是 “鬼” 的人。</p>

<p>给定一个 <strong>从 0 开始建立索引</strong> 的整数数组 <code>team</code>，其中只包含 0 (表示&nbsp;<strong>不是</strong> “鬼” 的人) 和 1 (表示是 “鬼” 的人)，以及一个整数 <code>dist</code>。索引 <code>i</code> 为 “鬼” 的人可以捕获索引在 <code>[i - dist, i + dist]</code>(<strong>包括</strong>) 范围内且 <strong>不是</strong> “鬼” 的任何<strong>一个</strong>人。</p>

<p>返回 <em>“鬼” 所能捕获的最大人数</em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> team = [0,1,0,1,0], dist = 3
<strong>输出:</strong> 2
<strong>解释:</strong>
在索引 1 的 “鬼” 可以捕获范围 [i-dist, i+dist] = [1-3, 1+3] = [-2, 4] 内的人。
他们可以抓住索引 2 中不是 “鬼” 的人。
在索引 3 的 “鬼” 可以捕获范围 [i-dist, i+dist] = [3-3, 3+3] = [0, 6] 内的人。
他们可以抓住索引 0 中不是 “鬼” 的人。
在索引 4 上不是 “鬼” 的人不会被抓住，因为在索引 1 和 3 上的人已经抓住了一个人。</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> team = [1], dist = 1
<strong>输出:</strong> 0
<strong>解释:</strong>
没有 “鬼" 要抓的人。
</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> team = [0], dist = 1
<strong>输出:</strong> 0
<strong>解释:
</strong>没有 “鬼” 来抓人。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= team.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= team[i] &lt;= 1</code></li>
	<li><code>1 &lt;= dist &lt;= team.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以用两个指针 $i$ 和 $j$ 指向鬼和非鬼的人，初始时 $i=0$, $j=0$。

然后我们从左到右遍历数组，当遇到鬼时，即 $team[i]=1$ 时，如果此时 $j \lt n$ 并且 $\textit{team}[j]=1$ 或者 $i - j \gt \textit{dist}$，则指针 $j$ 循环右移，也即是说，我们要找到第一个不是鬼的人，且 $i$ 和 $j$ 之间的距离不超过 $\textit{dist}$。如果找到了这样的人，则将指针 $j$ 右移一位，表示我们已经抓住了这个人，同时答案加一。继续遍历数组，直到遍历完整个数组。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{team}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def catchMaximumAmountofPeople(self, team: List[int], dist: int) -> int:
        ans = j = 0
        n = len(team)
        for i, x in enumerate(team):
            if x:
                while j < n and (team[j] or i - j > dist):
                    j += 1
                if j < n and abs(i - j) <= dist:
                    ans += 1
                    j += 1
        return ans
```

#### Java

```java
class Solution {
    public int catchMaximumAmountofPeople(int[] team, int dist) {
        int ans = 0;
        int n = team.length;
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i] == 1) {
                while (j < n && (team[j] == 1 || i - j > dist)) {
                    ++j;
                }
                if (j < n && Math.abs(i - j) <= dist) {
                    ++ans;
                    ++j;
                }
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
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int ans = 0;
        int n = team.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (team[i]) {
                while (j < n && (team[j] || i - j > dist)) {
                    ++j;
                }
                if (j < n && abs(i - j) <= dist) {
                    ++ans;
                    ++j;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func catchMaximumAmountofPeople(team []int, dist int) (ans int) {
	n := len(team)
	for i, j := 0, 0; i < n; i++ {
		if team[i] == 1 {
			for j < n && (team[j] == 1 || i-j > dist) {
				j++
			}
			if j < n && abs(i-j) <= dist {
				ans++
				j++
			}
		}
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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

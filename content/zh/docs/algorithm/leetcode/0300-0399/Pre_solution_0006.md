---
title: "0350_两个数组的交集 II"
date: 2025-10-08T18:35:54+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 排序, 数学, 数据流, 数组, 有序集合, 模拟, 状态压缩, 计数, 设计, 贪心, 链表, 队列]
---

{{< markmap >}}
### [0350_两个数组的交集 II](#350)
#### [数组](#350)
#### [哈希表](#350)
#### [双指针](#350)
#### [二分查找](#350)
#### [排序](#350)
### [0351_安卓系统手势解锁 🔒](#351)
#### [位运算](#351)
#### [动态规划](#351)
#### [回溯](#351)
#### [状态压缩](#351)
### [0352_将数据流变为多个不相交区间](#352)
#### [设计](#352)
#### [二分查找](#352)
#### [有序集合](#352)
### [0353_贪吃蛇 🔒](#353)
#### [设计](#353)
#### [队列](#353)
#### [数组](#353)
#### [哈希表](#353)
#### [模拟](#353)
### [0354_俄罗斯套娃信封问题](#354)
#### [数组](#354)
#### [二分查找](#354)
#### [动态规划](#354)
#### [排序](#354)
### [0355_设计推特](#355)
#### [设计](#355)
#### [哈希表](#355)
#### [链表](#355)
#### [堆（优先队列）](#355)
### [0356_直线镜像 🔒](#356)
#### [数组](#356)
#### [哈希表](#356)
#### [数学](#356)
### [0357_统计各位数字都不同的数字个数](#357)
#### [数学](#357)
#### [动态规划](#357)
#### [回溯](#357)
### [0358_K 距离间隔重排字符串 🔒](#358)
#### [贪心](#358)
#### [哈希表](#358)
#### [字符串](#358)
#### [计数](#358)
#### [排序](#358)
#### [堆（优先队列）](#358)
### [0359_日志速率限制器 🔒](#359)
#### [设计](#359)
#### [哈希表](#359)
#### [数据流](#359)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0350_两个数组的交集 II
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0351_安卓系统手势解锁 🔒
___
#### 位运算
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0352_将数据流变为多个不相交区间
___
#### 设计
___
#### 二分查找
___
#### 有序集合
---
### 0353_贪吃蛇 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 0354_俄罗斯套娃信封问题
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 0355_设计推特
___
#### 设计
___
#### 哈希表
___
#### 链表
___
#### 堆（优先队列）
---
### 0356_直线镜像 🔒
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 0357_统计各位数字都不同的数字个数
___
#### 数学
___
#### 动态规划
___
#### 回溯
---
### 0358_K 距离间隔重排字符串 🔒
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 0359_日志速率限制器 🔒
___
#### 设计
___
#### 哈希表
___
#### 数据流
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 回溯 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据流 | 数组 |
| 有序集合 | 模拟 | 状态压缩 |
| 计数 | 设计 | 贪心 |
| 链表 | 队列 |  |

# [350. 两个数组的交集 II](https://leetcode.cn/problems/intersection-of-two-arrays-ii){#350}

{{< tabs "350" >}}

{{% tab "python" %}}
```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums1)
        ans = []
        for x in nums2:
            if cnt[x]:
                ans.append(x)
                cnt[x] -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] cnt = new int[1001];
        for (int x : nums1) {
            ++cnt[x];
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.add(x);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int x : nums1) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intersect(nums1 []int, nums2 []int) (ans []int) {
	cnt := map[int]int{}
	for _, x := range nums1 {
		cnt[x]++
	}
	for _, x := range nums2 {
		if cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function intersect(nums1: number[], nums2: number[]): number[] {
    const cnt: Record<number, number> = {};
    for (const x of nums1) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const ans: number[] = [];
    for (const x of nums2) {
        if (cnt[x]-- > 0) {
            ans.push(x);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut cnt = HashMap::new();
        for &x in &nums1 {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut ans = Vec::new();
        for &x in &nums2 {
            if let Some(count) = cnt.get_mut(&x) {
                if *count > 0 {
                    ans.push(x);
                    *count -= 1;
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
    const cnt = {};
    for (const x of nums1) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const ans = [];
    for (const x of nums2) {
        if (cnt[x]-- > 0) {
            ans.push(x);
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] Intersect(int[] nums1, int[] nums2) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in nums1) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
        }
        List<int> ans = new List<int>();
        foreach (int x in nums2) {
            if (cnt.ContainsKey(x) && cnt[x] > 0) {
                ans.Add(x);
                cnt[x]--;
            }
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $cnt = [];
        foreach ($nums1 as $x) {
            if (isset($cnt[$x])) {
                $cnt[$x]++;
            } else {
                $cnt[$x] = 1;
            }
        }

        $ans = [];
        foreach ($nums2 as $x) {
            if (isset($cnt[$x]) && $cnt[$x] > 0) {
                $ans[] = $x;
                $cnt[$x]--;
            }
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

<p>给你两个整数数组&nbsp;<code>nums1</code> 和 <code>nums2</code> ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[4,9]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong><strong>进阶</strong>：</strong></p>

<ul>
	<li>如果给定的数组已经排好序呢？你将如何优化你的算法？</li>
	<li>如果&nbsp;<code>nums1</code><em>&nbsp;</em>的大小比&nbsp;<code>nums2</code> 小，哪种方法更优？</li>
	<li>如果&nbsp;<code>nums2</code><em>&nbsp;</em>的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{cnt}$ 统计数组 $\textit{nums1}$ 中每个元素出现的次数，然后遍历数组 $\textit{nums2}$，如果元素 $x$ 在 $\textit{cnt}$ 中，并且 $x$ 的出现次数大于 $0$，那么将 $x$ 加入答案，然后将 $x$ 的出现次数减一。

遍历结束后，返回答案数组即可。

时间复杂度 $O(m + n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums1)
        ans = []
        for x in nums2:
            if cnt[x]:
                ans.append(x)
                cnt[x] -= 1
        return ans
```

#### Java

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] cnt = new int[1001];
        for (int x : nums1) {
            ++cnt[x];
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.add(x);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int x : nums1) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func intersect(nums1 []int, nums2 []int) (ans []int) {
	cnt := map[int]int{}
	for _, x := range nums1 {
		cnt[x]++
	}
	for _, x := range nums2 {
		if cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	return
}
```

#### TypeScript

```ts
function intersect(nums1: number[], nums2: number[]): number[] {
    const cnt: Record<number, number> = {};
    for (const x of nums1) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const ans: number[] = [];
    for (const x of nums2) {
        if (cnt[x]-- > 0) {
            ans.push(x);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut cnt = HashMap::new();
        for &x in &nums1 {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut ans = Vec::new();
        for &x in &nums2 {
            if let Some(count) = cnt.get_mut(&x) {
                if *count > 0 {
                    ans.push(x);
                    *count -= 1;
                }
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
    const cnt = {};
    for (const x of nums1) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const ans = [];
    for (const x of nums2) {
        if (cnt[x]-- > 0) {
            ans.push(x);
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] Intersect(int[] nums1, int[] nums2) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in nums1) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
        }
        List<int> ans = new List<int>();
        foreach (int x in nums2) {
            if (cnt.ContainsKey(x) && cnt[x] > 0) {
                ans.Add(x);
                cnt[x]--;
            }
        }
        return ans.ToArray();
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersect($nums1, $nums2) {
        $cnt = [];
        foreach ($nums1 as $x) {
            if (isset($cnt[$x])) {
                $cnt[$x]++;
            } else {
                $cnt[$x] = 1;
            }
        }

        $ans = [];
        foreach ($nums2 as $x) {
            if (isset($cnt[$x]) && $cnt[$x] > 0) {
                $ans[] = $x;
                $cnt[$x]--;
            }
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

# [351. 安卓系统手势解锁 🔒](https://leetcode.cn/problems/android-unlock-patterns){#351}

{{< tabs "351" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        def dfs(i: int, cnt: int = 1) -> int:
            if cnt > n:
                return 0
            vis[i] = True
            ans = int(cnt >= m)
            for j in range(1, 10):
                x = cross[i][j]
                if not vis[j] and (x == 0 or vis[x]):
                    ans += dfs(j, cnt + 1)
            vis[i] = False
            return ans

        cross = [[0] * 10 for _ in range(10)]
        cross[1][3] = cross[3][1] = 2
        cross[1][7] = cross[7][1] = 4
        cross[1][9] = cross[9][1] = 5
        cross[2][8] = cross[8][2] = 5
        cross[3][7] = cross[7][3] = 5
        cross[3][9] = cross[9][3] = 6
        cross[4][6] = cross[6][4] = 5
        cross[7][9] = cross[9][7] = 8
        vis = [False] * 10
        return dfs(1) * 4 + dfs(2) * 4 + dfs(5)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] cross = new int[10][10];
    private boolean[] vis = new boolean[10];

    public int numberOfPatterns(int m, int n) {
        this.m = m;
        this.n = n;
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[1][9] = cross[9][1] = 5;
        cross[2][8] = cross[8][2] = 5;
        cross[3][7] = cross[7][3] = 5;
        cross[3][9] = cross[9][3] = 6;
        cross[4][6] = cross[6][4] = 5;
        cross[7][9] = cross[9][7] = 8;
        return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
    }

    private int dfs(int i, int cnt) {
        if (cnt > n) {
            return 0;
        }
        vis[i] = true;
        int ans = cnt >= m ? 1 : 0;
        for (int j = 1; j < 10; ++j) {
            int x = cross[i][j];
            if (!vis[j] && (x == 0 || vis[x])) {
                ans += dfs(j, cnt + 1);
            }
        }
        vis[i] = false;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int cross[10][10];
        memset(cross, 0, sizeof(cross));
        bool vis[10];
        memset(vis, false, sizeof(vis));
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[1][9] = cross[9][1] = 5;
        cross[2][8] = cross[8][2] = 5;
        cross[3][7] = cross[7][3] = 5;
        cross[3][9] = cross[9][3] = 6;
        cross[4][6] = cross[6][4] = 5;
        cross[7][9] = cross[9][7] = 8;

        function<int(int, int)> dfs = [&](int i, int cnt) {
            if (cnt > n) {
                return 0;
            }
            vis[i] = true;
            int ans = cnt >= m ? 1 : 0;
            for (int j = 1; j < 10; ++j) {
                int x = cross[i][j];
                if (!vis[j] && (x == 0 || vis[x])) {
                    ans += dfs(j, cnt + 1);
                }
            }
            vis[i] = false;
            return ans;
        };

        return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPatterns(m int, n int) int {
	cross := [10][10]int{}
	vis := [10]bool{}
	cross[1][3] = 2
	cross[1][7] = 4
	cross[1][9] = 5
	cross[2][8] = 5
	cross[3][7] = 5
	cross[3][9] = 6
	cross[4][6] = 5
	cross[7][9] = 8
	cross[3][1] = 2
	cross[7][1] = 4
	cross[9][1] = 5
	cross[8][2] = 5
	cross[7][3] = 5
	cross[9][3] = 6
	cross[6][4] = 5
	cross[9][7] = 8
	var dfs func(int, int) int
	dfs = func(i, cnt int) int {
		if cnt > n {
			return 0
		}
		vis[i] = true
		ans := 0
		if cnt >= m {
			ans++
		}
		for j := 1; j < 10; j++ {
			x := cross[i][j]
			if !vis[j] && (x == 0 || vis[x]) {
				ans += dfs(j, cnt+1)
			}
		}
		vis[i] = false
		return ans
	}
	return dfs(1, 1)*4 + dfs(2, 1)*4 + dfs(5, 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPatterns(m: number, n: number): number {
    const cross: number[][] = Array(10)
        .fill(0)
        .map(() => Array(10).fill(0));
    const vis: boolean[] = Array(10).fill(false);
    cross[1][3] = cross[3][1] = 2;
    cross[1][7] = cross[7][1] = 4;
    cross[1][9] = cross[9][1] = 5;
    cross[2][8] = cross[8][2] = 5;
    cross[3][7] = cross[7][3] = 5;
    cross[3][9] = cross[9][3] = 6;
    cross[4][6] = cross[6][4] = 5;
    cross[7][9] = cross[9][7] = 8;
    const dfs = (i: number, cnt: number): number => {
        if (cnt > n) {
            return 0;
        }
        vis[i] = true;
        let ans = 0;
        if (cnt >= m) {
            ++ans;
        }
        for (let j = 1; j < 10; ++j) {
            const x = cross[i][j];
            if (!vis[j] && (x === 0 || vis[x])) {
                ans += dfs(j, cnt + 1);
            }
        }
        vis[i] = false;
        return ans;
    };
    return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们都知道安卓有个手势解锁的界面，是一个&nbsp;<code>3 x 3</code><strong> </strong>的点所绘制出来的网格。用户可以设置一个 “解锁模式” ，通过连接特定序列中的点，形成一系列彼此连接的线段，每个线段的端点都是序列中两个连续的点。如果满足以下两个条件，则 <code>k</code> 点序列是有效的解锁模式：</p>

<ul>
	<li>解锁模式中的所有点 <strong>互不相同</strong> 。</li>
	<li>假如模式中两个连续点的线段需要经过其他点的 <strong>中心</strong> ，那么要经过的点 <strong>必须提前出现</strong> 在序列中（已经经过），不能跨过任何还未被经过的点。
	<ul>
		<li>例如，点 <code>5</code> 或 <code>6</code>&nbsp;没有提前出现的情况下连接点 <code>2</code>&nbsp;和 <code>9</code>&nbsp;是有效的，因为从点 <code>2</code> 到点 <code>9</code> 的线没有穿过点 <code>5</code> 或 <code>6</code> 的中心。</li>
		<li>然而，点 <code>2</code> 没有提前出现的情况下连接点 <code>1</code> 和&nbsp;<code>3</code>&nbsp;是无效的，因为从圆点 <code>1</code> 到圆点 <code>3</code> 的直线穿过圆点 <code>2</code> 的中心。</li>
	</ul>
	</li>
</ul>

<p>以下是一些有效和无效解锁模式的示例：</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0351.Android%20Unlock%20Patterns/images/android-unlock.png" /></p>

<ul>
	<li><strong>无效手势：</strong><code>[4,1,3,6]</code> ，连接点 1 和点&nbsp;3 时经过了未被连接过的&nbsp;2 号点。</li>
	<li><strong>无效手势：</strong><code>[4,1,9,2]</code> ，连接点 1 和点 9 时经过了未被连接过的 5&nbsp;号点。</li>
	<li><strong>有效手势：</strong><code>[2,4,1,3,6]</code> ，连接点 1 和点&nbsp;3 是有效的，因为虽然它经过了点&nbsp;2 ，但是点 2 在该手势中之前已经被连过了。</li>
	<li><strong>有效手势：</strong><code>[6,5,4,1,9,2]</code> ，连接点 1 和点&nbsp;9 是有效的，因为虽然它经过了按键 5 ，但是点&nbsp;5 在该手势中之前已经被连过了。</li>
</ul>

<p>给你两个整数，分别为 ​​<code>m</code> 和 <code>n</code> ，那么请返回有多少种 <strong>不同且有效的解锁模式 </strong>，是 <strong>至少</strong> 需要经过 <code>m</code> 个点，但是 <strong>不超过</strong> <code>n</code> 个点的。</p>

<p>两个解锁模式 <strong>不同</strong> 需满足：经过的点不同或者经过点的顺序不同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>m = 1, n = 1
<strong>输出：</strong>9
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 1, n = 2
<strong>输出：</strong>65
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们定义一个二维数组 $cross$，其中 $cross[i][j]$ 表示数字 $i$ 和数字 $j$ 之间是否有中间数字，如果有则 $cross[i][j]$ 的值为中间数字，否则为 $0$。

我们还需要一个一维数组 $vis$，用来记录数字是否被使用过。

由于数字 $1$, $3$, $7$, $9$ 是对称的，因此我们只需要计算数字 $1$ 的情况，然后乘以 $4$ 即可。

由于数字 $2$, $4$, $6$, $8$ 也是对称的，因此我们只需要计算数字 $2$ 的情况，然后乘以 $4$ 即可。

最后我们再计算数字 $5$ 的情况。

我们设计一个函数 $dfs(i, cnt)$，表示当前位于数字 $i$，且已经选了 $cnt$ 个数字的情况下，有多少种解锁模式。

函数 $dfs(i, cnt)$ 的执行过程如下：

如果 $cnt \gt n$，说明当前选中的数字个数超过了 $n$，直接返回 $0$。

否则，我们将数字 $i$ 标记为已使用，然后初始化答案 $ans$ 为 $0$。如果 $cnt \ge m$，说明当前选中的数字个数不少于 $m$，那么答案 $ans$ 就需要加 $1$。

接下来，我们枚举下一个数字 $j$，如果数字 $j$ 没有被使用过，且数字 $i$ 和数字 $j$ 之间没有中间数字，或者数字 $i$ 和数字 $j$ 之间的中间数字已经被使用过，那么我们就可以从数字 $j$ 出发，继续搜索，此时答案 $ans$ 需要加上 $dfs(j, cnt + 1)$ 的返回值。

最后，我们将数字 $i$ 标记为未使用，然后返回答案 $ans$。

最终的答案即为 $dfs(1, 1) \times 4 + dfs(2, 1) \times 4 + dfs(5, 1)$。

时间复杂度 $O(n!)$，空间复杂度 $O(n)$。其中 $n$ 是手势的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        def dfs(i: int, cnt: int = 1) -> int:
            if cnt > n:
                return 0
            vis[i] = True
            ans = int(cnt >= m)
            for j in range(1, 10):
                x = cross[i][j]
                if not vis[j] and (x == 0 or vis[x]):
                    ans += dfs(j, cnt + 1)
            vis[i] = False
            return ans

        cross = [[0] * 10 for _ in range(10)]
        cross[1][3] = cross[3][1] = 2
        cross[1][7] = cross[7][1] = 4
        cross[1][9] = cross[9][1] = 5
        cross[2][8] = cross[8][2] = 5
        cross[3][7] = cross[7][3] = 5
        cross[3][9] = cross[9][3] = 6
        cross[4][6] = cross[6][4] = 5
        cross[7][9] = cross[9][7] = 8
        vis = [False] * 10
        return dfs(1) * 4 + dfs(2) * 4 + dfs(5)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] cross = new int[10][10];
    private boolean[] vis = new boolean[10];

    public int numberOfPatterns(int m, int n) {
        this.m = m;
        this.n = n;
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[1][9] = cross[9][1] = 5;
        cross[2][8] = cross[8][2] = 5;
        cross[3][7] = cross[7][3] = 5;
        cross[3][9] = cross[9][3] = 6;
        cross[4][6] = cross[6][4] = 5;
        cross[7][9] = cross[9][7] = 8;
        return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
    }

    private int dfs(int i, int cnt) {
        if (cnt > n) {
            return 0;
        }
        vis[i] = true;
        int ans = cnt >= m ? 1 : 0;
        for (int j = 1; j < 10; ++j) {
            int x = cross[i][j];
            if (!vis[j] && (x == 0 || vis[x])) {
                ans += dfs(j, cnt + 1);
            }
        }
        vis[i] = false;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int cross[10][10];
        memset(cross, 0, sizeof(cross));
        bool vis[10];
        memset(vis, false, sizeof(vis));
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[1][9] = cross[9][1] = 5;
        cross[2][8] = cross[8][2] = 5;
        cross[3][7] = cross[7][3] = 5;
        cross[3][9] = cross[9][3] = 6;
        cross[4][6] = cross[6][4] = 5;
        cross[7][9] = cross[9][7] = 8;

        function<int(int, int)> dfs = [&](int i, int cnt) {
            if (cnt > n) {
                return 0;
            }
            vis[i] = true;
            int ans = cnt >= m ? 1 : 0;
            for (int j = 1; j < 10; ++j) {
                int x = cross[i][j];
                if (!vis[j] && (x == 0 || vis[x])) {
                    ans += dfs(j, cnt + 1);
                }
            }
            vis[i] = false;
            return ans;
        };

        return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
    }
};
```

#### Go

```go
func numberOfPatterns(m int, n int) int {
	cross := [10][10]int{}
	vis := [10]bool{}
	cross[1][3] = 2
	cross[1][7] = 4
	cross[1][9] = 5
	cross[2][8] = 5
	cross[3][7] = 5
	cross[3][9] = 6
	cross[4][6] = 5
	cross[7][9] = 8
	cross[3][1] = 2
	cross[7][1] = 4
	cross[9][1] = 5
	cross[8][2] = 5
	cross[7][3] = 5
	cross[9][3] = 6
	cross[6][4] = 5
	cross[9][7] = 8
	var dfs func(int, int) int
	dfs = func(i, cnt int) int {
		if cnt > n {
			return 0
		}
		vis[i] = true
		ans := 0
		if cnt >= m {
			ans++
		}
		for j := 1; j < 10; j++ {
			x := cross[i][j]
			if !vis[j] && (x == 0 || vis[x]) {
				ans += dfs(j, cnt+1)
			}
		}
		vis[i] = false
		return ans
	}
	return dfs(1, 1)*4 + dfs(2, 1)*4 + dfs(5, 1)
}
```

#### TypeScript

```ts
function numberOfPatterns(m: number, n: number): number {
    const cross: number[][] = Array(10)
        .fill(0)
        .map(() => Array(10).fill(0));
    const vis: boolean[] = Array(10).fill(false);
    cross[1][3] = cross[3][1] = 2;
    cross[1][7] = cross[7][1] = 4;
    cross[1][9] = cross[9][1] = 5;
    cross[2][8] = cross[8][2] = 5;
    cross[3][7] = cross[7][3] = 5;
    cross[3][9] = cross[9][3] = 6;
    cross[4][6] = cross[6][4] = 5;
    cross[7][9] = cross[9][7] = 8;
    const dfs = (i: number, cnt: number): number => {
        if (cnt > n) {
            return 0;
        }
        vis[i] = true;
        let ans = 0;
        if (cnt >= m) {
            ++ans;
        }
        for (let j = 1; j < 10; ++j) {
            const x = cross[i][j];
            if (!vis[j] && (x === 0 || vis[x])) {
                ans += dfs(j, cnt + 1);
            }
        }
        vis[i] = false;
        return ans;
    };
    return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [352. 将数据流变为多个不相交区间](https://leetcode.cn/problems/data-stream-as-disjoint-intervals){#352}

{{< tabs "352" >}}

{{% tab "python" %}}
```python
class SummaryRanges:
    def __init__(self):
        self.mp = SortedDict()

    def addNum(self, val: int) -> None:
        n = len(self.mp)
        ridx = self.mp.bisect_right(val)
        lidx = n if ridx == 0 else ridx - 1
        keys = self.mp.keys()
        values = self.mp.values()
        if (
            lidx != n
            and ridx != n
            and values[lidx][1] + 1 == val
            and values[ridx][0] - 1 == val
        ):
            self.mp[keys[lidx]][1] = self.mp[keys[ridx]][1]
            self.mp.pop(keys[ridx])
        elif lidx != n and val <= values[lidx][1] + 1:
            self.mp[keys[lidx]][1] = max(val, self.mp[keys[lidx]][1])
        elif ridx != n and val >= values[ridx][0] - 1:
            self.mp[keys[ridx]][0] = min(val, self.mp[keys[ridx]][0])
        else:
            self.mp[val] = [val, val]

    def getIntervals(self) -> List[List[int]]:
        return list(self.mp.values())


# # Your SummaryRanges object will be instantiated and called as such:
# # obj = SummaryRanges()
# # obj.addNum(val)
# # param_2 = obj.getIntervals()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SummaryRanges {
    private TreeMap<Integer, int[]> mp;

    public SummaryRanges() {
        mp = new TreeMap<>();
    }

    public void addNum(int val) {
        Integer l = mp.floorKey(val);
        Integer r = mp.ceilingKey(val);
        if (l != null && r != null && mp.get(l)[1] + 1 == val && mp.get(r)[0] - 1 == val) {
            mp.get(l)[1] = mp.get(r)[1];
            mp.remove(r);
        } else if (l != null && val <= mp.get(l)[1] + 1) {
            mp.get(l)[1] = Math.max(val, mp.get(l)[1]);
        } else if (r != null && val >= mp.get(r)[0] - 1) {
            mp.get(r)[0] = Math.min(val, mp.get(r)[0]);
        } else {
            mp.put(val, new int[] {val, val});
        }
    }

    public int[][] getIntervals() {
        int[][] res = new int[mp.size()][2];
        int i = 0;
        for (int[] range : mp.values()) {
            res[i++] = range;
        }
        return res;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SummaryRanges {
private:
    map<int, vector<int>> mp;

public:
    SummaryRanges() {
    }

    void addNum(int val) {
        auto r = mp.upper_bound(val);
        auto l = r == mp.begin() ? mp.end() : prev(r);
        if (l != mp.end() && r != mp.end() && l->second[1] + 1 == val && r->second[0] - 1 == val) {
            l->second[1] = r->second[1];
            mp.erase(r);
        } else if (l != mp.end() && val <= l->second[1] + 1)
            l->second[1] = max(val, l->second[1]);
        else if (r != mp.end() && val >= r->second[0] - 1)
            r->second[0] = min(val, r->second[0]);
        else
            mp[val] = {val, val};
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& range : mp) res.push_back(range.second);
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>&nbsp;给你一个由非负整数&nbsp;<code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code> 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。</p>

<p>实现 <code>SummaryRanges</code> 类：</p>

<div class="original__bRMd">
<div>
<ul>
	<li><code>SummaryRanges()</code> 使用一个空数据流初始化对象。</li>
	<li><code>void addNum(int val)</code> 向数据流中加入整数 <code>val</code> 。</li>
	<li><code>int[][] getIntervals()</code> 以不相交区间&nbsp;<code>[start<sub>i</sub>, end<sub>i</sub>]</code> 的列表形式返回对数据流中整数的总结。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
<strong>输出：</strong>
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

<strong>解释：</strong>
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // 返回 [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>4</sup></code></li>
	<li>最多调用&nbsp;<code>addNum</code> 和 <code>getIntervals</code> 方法 <code>3 * 10<sup>4</sup></code> 次</li>
</ul>
</div>
</div>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果存在大量合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?</p>

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
class SummaryRanges:
    def __init__(self):
        self.mp = SortedDict()

    def addNum(self, val: int) -> None:
        n = len(self.mp)
        ridx = self.mp.bisect_right(val)
        lidx = n if ridx == 0 else ridx - 1
        keys = self.mp.keys()
        values = self.mp.values()
        if (
            lidx != n
            and ridx != n
            and values[lidx][1] + 1 == val
            and values[ridx][0] - 1 == val
        ):
            self.mp[keys[lidx]][1] = self.mp[keys[ridx]][1]
            self.mp.pop(keys[ridx])
        elif lidx != n and val <= values[lidx][1] + 1:
            self.mp[keys[lidx]][1] = max(val, self.mp[keys[lidx]][1])
        elif ridx != n and val >= values[ridx][0] - 1:
            self.mp[keys[ridx]][0] = min(val, self.mp[keys[ridx]][0])
        else:
            self.mp[val] = [val, val]

    def getIntervals(self) -> List[List[int]]:
        return list(self.mp.values())


# # Your SummaryRanges object will be instantiated and called as such:
# # obj = SummaryRanges()
# # obj.addNum(val)
# # param_2 = obj.getIntervals()
```

#### Java

```java
class SummaryRanges {
    private TreeMap<Integer, int[]> mp;

    public SummaryRanges() {
        mp = new TreeMap<>();
    }

    public void addNum(int val) {
        Integer l = mp.floorKey(val);
        Integer r = mp.ceilingKey(val);
        if (l != null && r != null && mp.get(l)[1] + 1 == val && mp.get(r)[0] - 1 == val) {
            mp.get(l)[1] = mp.get(r)[1];
            mp.remove(r);
        } else if (l != null && val <= mp.get(l)[1] + 1) {
            mp.get(l)[1] = Math.max(val, mp.get(l)[1]);
        } else if (r != null && val >= mp.get(r)[0] - 1) {
            mp.get(r)[0] = Math.min(val, mp.get(r)[0]);
        } else {
            mp.put(val, new int[] {val, val});
        }
    }

    public int[][] getIntervals() {
        int[][] res = new int[mp.size()][2];
        int i = 0;
        for (int[] range : mp.values()) {
            res[i++] = range;
        }
        return res;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
```

#### C++

```cpp
class SummaryRanges {
private:
    map<int, vector<int>> mp;

public:
    SummaryRanges() {
    }

    void addNum(int val) {
        auto r = mp.upper_bound(val);
        auto l = r == mp.begin() ? mp.end() : prev(r);
        if (l != mp.end() && r != mp.end() && l->second[1] + 1 == val && r->second[0] - 1 == val) {
            l->second[1] = r->second[1];
            mp.erase(r);
        } else if (l != mp.end() && val <= l->second[1] + 1)
            l->second[1] = max(val, l->second[1]);
        else if (r != mp.end() && val >= r->second[0] - 1)
            r->second[0] = min(val, r->second[0]);
        else
            mp[val] = {val, val};
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& range : mp) res.push_back(range.second);
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [353. 贪吃蛇 🔒](https://leetcode.cn/problems/design-snake-game){#353}

{{< tabs "353" >}}

{{% tab "python" %}}
```python
class SnakeGame:
    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.m = height
        self.n = width
        self.food = food
        self.score = 0
        self.idx = 0
        self.q = deque([(0, 0)])
        self.vis = {(0, 0)}

    def move(self, direction: str) -> int:
        i, j = self.q[0]
        x, y = i, j
        match direction:
            case "U":
                x -= 1
            case "D":
                x += 1
            case "L":
                y -= 1
            case "R":
                y += 1
        if x < 0 or x >= self.m or y < 0 or y >= self.n:
            return -1
        if (
            self.idx < len(self.food)
            and x == self.food[self.idx][0]
            and y == self.food[self.idx][1]
        ):
            self.score += 1
            self.idx += 1
        else:
            self.vis.remove(self.q.pop())
        if (x, y) in self.vis:
            return -1
        self.q.appendleft((x, y))
        self.vis.add((x, y))
        return self.score


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SnakeGame {
    private int m;
    private int n;
    private int[][] food;
    private int score;
    private int idx;
    private Deque<Integer> q = new ArrayDeque<>();
    private Set<Integer> vis = new HashSet<>();

    public SnakeGame(int width, int height, int[][] food) {
        m = height;
        n = width;
        this.food = food;
        q.offer(0);
        vis.add(0);
    }

    public int move(String direction) {
        int p = q.peekFirst();
        int i = p / n, j = p % n;
        int x = i, y = j;
        if ("U".equals(direction)) {
            --x;
        } else if ("D".equals(direction)) {
            ++x;
        } else if ("L".equals(direction)) {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return -1;
        }
        if (idx < food.length && x == food[idx][0] && y == food[idx][1]) {
            ++score;
            ++idx;
        } else {
            int t = q.pollLast();
            vis.remove(t);
        }
        int cur = f(x, y);
        if (vis.contains(cur)) {
            return -1;
        }
        q.offerFirst(cur);
        vis.add(cur);
        return score;
    }

    private int f(int i, int j) {
        return i * n + j;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;
        this->food = food;
        score = 0;
        idx = 0;
        q.push_back(0);
        vis.insert(0);
    }

    int move(string direction) {
        int p = q.front();
        int i = p / n, j = p % n;
        int x = i, y = j;
        if (direction == "U") {
            --x;
        } else if (direction == "D") {
            ++x;
        } else if (direction == "L") {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return -1;
        }
        if (idx < food.size() && x == food[idx][0] && y == food[idx][1]) {
            ++score;
            ++idx;
        } else {
            int tail = q.back();
            q.pop_back();
            vis.erase(tail);
        }
        int cur = f(x, y);
        if (vis.count(cur)) {
            return -1;
        }
        q.push_front(cur);
        vis.insert(cur);
        return score;
    }

private:
    int m;
    int n;
    vector<vector<int>> food;
    int score;
    int idx;
    deque<int> q;
    unordered_set<int> vis;

    int f(int i, int j) {
        return i * n + j;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SnakeGame struct {
	m     int
	n     int
	food  [][]int
	score int
	idx   int
	q     []int
	vis   map[int]bool
}

func Constructor(width int, height int, food [][]int) SnakeGame {
	return SnakeGame{height, width, food, 0, 0, []int{0}, map[int]bool{}}
}

func (this *SnakeGame) Move(direction string) int {
	f := func(i, j int) int {
		return i*this.n + j
	}
	p := this.q[0]
	i, j := p/this.n, p%this.n
	x, y := i, j
	if direction == "U" {
		x--
	} else if direction == "D" {
		x++
	} else if direction == "L" {
		y--
	} else {
		y++
	}
	if x < 0 || x >= this.m || y < 0 || y >= this.n {
		return -1
	}
	if this.idx < len(this.food) && x == this.food[this.idx][0] && y == this.food[this.idx][1] {
		this.score++
		this.idx++
	} else {
		t := this.q[len(this.q)-1]
		this.q = this.q[:len(this.q)-1]
		this.vis[t] = false
	}
	cur := f(x, y)
	if this.vis[cur] {
		return -1
	}
	this.q = append([]int{cur}, this.q...)
	this.vis[cur] = true
	return this.score
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * obj := Constructor(width, height, food);
 * param_1 := obj.Move(direction);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SnakeGame {
    private m: number;
    private n: number;
    private food: number[][];
    private score: number;
    private idx: number;
    private q: number[];
    private vis: Set<number>;

    constructor(width: number, height: number, food: number[][]) {
        this.m = height;
        this.n = width;
        this.food = food;
        this.score = 0;
        this.idx = 0;
        this.q = [0];
        this.vis = new Set([0]);
    }

    move(direction: string): number {
        const p = this.q[0];
        const i = Math.floor(p / this.n);
        const j = p % this.n;
        let x = i;
        let y = j;
        if (direction === 'U') {
            --x;
        } else if (direction === 'D') {
            ++x;
        } else if (direction === 'L') {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= this.m || y < 0 || y >= this.n) {
            return -1;
        }
        if (
            this.idx < this.food.length &&
            x === this.food[this.idx][0] &&
            y === this.food[this.idx][1]
        ) {
            ++this.score;
            ++this.idx;
        } else {
            const t = this.q.pop()!;
            this.vis.delete(t);
        }
        const cur = x * this.n + y;
        if (this.vis.has(cur)) {
            return -1;
        }
        this.q.unshift(cur);
        this.vis.add(cur);
        return this.score;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * var obj = new SnakeGame(width, height, food)
 * var param_1 = obj.move(direction)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个 <a href="https://baike.baidu.com/item/%E8%B4%AA%E5%90%83%E8%9B%87/9510203?fr=aladdin" target="_blank">贪吃蛇游戏</a>，该游戏将会在一个 <strong>屏幕尺寸 = 宽度 x 高度 </strong>的屏幕上运行。如果你不熟悉这个游戏，可以 <a href="http://patorjk.com/games/snake/">点击这里</a> 在线试玩。</p>

<p>起初时，蛇在左上角的 <code>(0, 0)</code><strong> </strong>位置，身体长度为 <code>1</code> 个单位。</p>

<p>你将会被给出一个数组形式的食物位置序列 <code>food</code> ，其中 <code>food[i] = (r<sub>i</sub>, c<sub>i</sub>)</code> 。当蛇吃到食物时，身子的长度会增加 <code>1</code> 个单位，得分也会 <code>+1</code> 。</p>

<p>食物不会同时出现，会按列表的顺序逐一显示在屏幕上。比方讲，第一个食物被蛇吃掉后，第二个食物才会出现。</p>

<p>当一个食物在屏幕上出现时，保证 <strong>不会</strong> 出现在被蛇身体占据的格子里。</p>

<p class="MachineTrans-lang-zh-CN">如果蛇越界（与边界相撞）或者头与 <strong>移动后</strong> 的身体相撞（即，身长为 <code>4</code> 的蛇无法与自己相撞），游戏结束。</p>

<p>实现 <code>SnakeGame</code> 类：</p>

<ul>
	<li><code>SnakeGame(int width, int height, int[][] food)</code> 初始化对象，屏幕大小为 <code>height x width</code> ，食物位置序列为 <code>food</code></li>
	<li><code>int move(String direction)</code> 返回蛇在方向 <code>direction</code> 上移动后的得分。如果游戏结束，返回 <code>-1</code> 。</li>
</ul>
 

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0353.Design%20Snake%20Game/images/snake.jpg" style="width: 800px; height: 302px;" />
<pre>
<strong>输入：</strong>
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
<strong>输出：</strong>
[null, 0, 0, 1, 1, 2, -1]

<strong>解释：</strong>
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // 返回 0
snakeGame.move("D"); // 返回 0
snakeGame.move("R"); // 返回 1 ，蛇吃掉了第一个食物，同时第二个食物出现在 (0, 1)
snakeGame.move("U"); // 返回 1
snakeGame.move("L"); // 返回 2 ，蛇吃掉了第二个食物，没有出现更多食物
snakeGame.move("U"); // 返回 -1 ，蛇与边界相撞，游戏结束

</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= width, height <= 10<sup>4</sup></code></li>
	<li><code>1 <= food.length <= 50</code></li>
	<li><code>food[i].length == 2</code></li>
	<li><code>0 <= r<sub>i</sub> < height</code></li>
	<li><code>0 <= c<sub>i</sub> < width</code></li>
	<li><code>direction.length == 1</code></li>
	<li><code>direction</code> is <code>'U'</code>, <code>'D'</code>, <code>'L'</code>, or <code>'R'</code>.</li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>move</code> 方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双端队列模拟

我们可以使用双端队列来模拟蛇的移动。

定义一个双端队列 $q$，其中保存蛇的身体坐标，队头为蛇头，队尾为蛇尾。同时使用一个集合 $vis$ 来保存蛇的身体坐标，用于快速判断蛇头是否与蛇身相撞。

定义一个变量 $score$ 来保存蛇的得分，初始值为 $0$；定义一个变量 $idx$ 来保存当前食物的索引，初始值为 $0$。

每次移动时，首先判断蛇头是否与边界相撞，如果相撞则游戏结束，返回 $-1$；否则，判断蛇头是否与食物重合，如果重合则蛇的得分加 $1$，同时食物索引 $idx$ 加 $1$；否则，蛇的身体长度不变，需要将蛇尾从队尾弹出，并从集合 $vis$ 中删除对应的坐标。

然后，判断蛇头是否与蛇身相撞，如果相撞则游戏结束，返回 $-1$；否则，将蛇头的坐标加入集合 $vis$ 中，并从队头加入蛇头的坐标。

最后，返回蛇的得分 $score$。

时间复杂度 $O(k)$，空间复杂度 $O(k)$，其中 $k$ 为移动的次数。

<!-- tabs:start -->

#### Python3

```python
class SnakeGame:
    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.m = height
        self.n = width
        self.food = food
        self.score = 0
        self.idx = 0
        self.q = deque([(0, 0)])
        self.vis = {(0, 0)}

    def move(self, direction: str) -> int:
        i, j = self.q[0]
        x, y = i, j
        match direction:
            case "U":
                x -= 1
            case "D":
                x += 1
            case "L":
                y -= 1
            case "R":
                y += 1
        if x < 0 or x >= self.m or y < 0 or y >= self.n:
            return -1
        if (
            self.idx < len(self.food)
            and x == self.food[self.idx][0]
            and y == self.food[self.idx][1]
        ):
            self.score += 1
            self.idx += 1
        else:
            self.vis.remove(self.q.pop())
        if (x, y) in self.vis:
            return -1
        self.q.appendleft((x, y))
        self.vis.add((x, y))
        return self.score


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
```

#### Java

```java
class SnakeGame {
    private int m;
    private int n;
    private int[][] food;
    private int score;
    private int idx;
    private Deque<Integer> q = new ArrayDeque<>();
    private Set<Integer> vis = new HashSet<>();

    public SnakeGame(int width, int height, int[][] food) {
        m = height;
        n = width;
        this.food = food;
        q.offer(0);
        vis.add(0);
    }

    public int move(String direction) {
        int p = q.peekFirst();
        int i = p / n, j = p % n;
        int x = i, y = j;
        if ("U".equals(direction)) {
            --x;
        } else if ("D".equals(direction)) {
            ++x;
        } else if ("L".equals(direction)) {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return -1;
        }
        if (idx < food.length && x == food[idx][0] && y == food[idx][1]) {
            ++score;
            ++idx;
        } else {
            int t = q.pollLast();
            vis.remove(t);
        }
        int cur = f(x, y);
        if (vis.contains(cur)) {
            return -1;
        }
        q.offerFirst(cur);
        vis.add(cur);
        return score;
    }

    private int f(int i, int j) {
        return i * n + j;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
```

#### C++

```cpp
class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;
        this->food = food;
        score = 0;
        idx = 0;
        q.push_back(0);
        vis.insert(0);
    }

    int move(string direction) {
        int p = q.front();
        int i = p / n, j = p % n;
        int x = i, y = j;
        if (direction == "U") {
            --x;
        } else if (direction == "D") {
            ++x;
        } else if (direction == "L") {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return -1;
        }
        if (idx < food.size() && x == food[idx][0] && y == food[idx][1]) {
            ++score;
            ++idx;
        } else {
            int tail = q.back();
            q.pop_back();
            vis.erase(tail);
        }
        int cur = f(x, y);
        if (vis.count(cur)) {
            return -1;
        }
        q.push_front(cur);
        vis.insert(cur);
        return score;
    }

private:
    int m;
    int n;
    vector<vector<int>> food;
    int score;
    int idx;
    deque<int> q;
    unordered_set<int> vis;

    int f(int i, int j) {
        return i * n + j;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
```

#### Go

```go
type SnakeGame struct {
	m     int
	n     int
	food  [][]int
	score int
	idx   int
	q     []int
	vis   map[int]bool
}

func Constructor(width int, height int, food [][]int) SnakeGame {
	return SnakeGame{height, width, food, 0, 0, []int{0}, map[int]bool{}}
}

func (this *SnakeGame) Move(direction string) int {
	f := func(i, j int) int {
		return i*this.n + j
	}
	p := this.q[0]
	i, j := p/this.n, p%this.n
	x, y := i, j
	if direction == "U" {
		x--
	} else if direction == "D" {
		x++
	} else if direction == "L" {
		y--
	} else {
		y++
	}
	if x < 0 || x >= this.m || y < 0 || y >= this.n {
		return -1
	}
	if this.idx < len(this.food) && x == this.food[this.idx][0] && y == this.food[this.idx][1] {
		this.score++
		this.idx++
	} else {
		t := this.q[len(this.q)-1]
		this.q = this.q[:len(this.q)-1]
		this.vis[t] = false
	}
	cur := f(x, y)
	if this.vis[cur] {
		return -1
	}
	this.q = append([]int{cur}, this.q...)
	this.vis[cur] = true
	return this.score
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * obj := Constructor(width, height, food);
 * param_1 := obj.Move(direction);
 */
```

#### TypeScript

```ts
class SnakeGame {
    private m: number;
    private n: number;
    private food: number[][];
    private score: number;
    private idx: number;
    private q: number[];
    private vis: Set<number>;

    constructor(width: number, height: number, food: number[][]) {
        this.m = height;
        this.n = width;
        this.food = food;
        this.score = 0;
        this.idx = 0;
        this.q = [0];
        this.vis = new Set([0]);
    }

    move(direction: string): number {
        const p = this.q[0];
        const i = Math.floor(p / this.n);
        const j = p % this.n;
        let x = i;
        let y = j;
        if (direction === 'U') {
            --x;
        } else if (direction === 'D') {
            ++x;
        } else if (direction === 'L') {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= this.m || y < 0 || y >= this.n) {
            return -1;
        }
        if (
            this.idx < this.food.length &&
            x === this.food[this.idx][0] &&
            y === this.food[this.idx][1]
        ) {
            ++this.score;
            ++this.idx;
        } else {
            const t = this.q.pop()!;
            this.vis.delete(t);
        }
        const cur = x * this.n + y;
        if (this.vis.has(cur)) {
            return -1;
        }
        this.q.unshift(cur);
        this.vis.add(cur);
        return this.score;
    }
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * var obj = new SnakeGame(width, height, food)
 * var param_1 = obj.move(direction)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes){#354}

{{< tabs "354" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        d = [envelopes[0][1]]
        for _, h in envelopes[1:]:
            if h > d[-1]:
                d.append(h)
            else:
                idx = bisect_left(d, h)
                d[idx] = h
        return len(d)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> { return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]; });
        int n = envelopes.length;
        int[] d = new int[n + 1];
        d[1] = envelopes[0][1];
        int size = 1;
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[size]) {
                d[++size] = x;
            } else {
                int left = 1, right = size;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (d[mid] >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                int p = d[left] >= x ? left : 1;
                d[p] = x;
            }
        }
        return size;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        vector<int> d{envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[d.size() - 1])
                d.push_back(x);
            else {
                int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = x;
            }
        }
        return d.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxEnvelopes(envelopes [][]int) int {
	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] != envelopes[j][0] {
			return envelopes[i][0] < envelopes[j][0]
		}
		return envelopes[j][1] < envelopes[i][1]
	})
	n := len(envelopes)
	d := make([]int, n+1)
	d[1] = envelopes[0][1]
	size := 1
	for _, e := range envelopes[1:] {
		x := e[1]
		if x > d[size] {
			size++
			d[size] = x
		} else {
			left, right := 1, size
			for left < right {
				mid := (left + right) >> 1
				if d[mid] >= x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			if d[left] < x {
				left = 1
			}
			d[left] = x
		}
	}
	return size
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>envelopes</code> ，其中 <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> ，表示第 <code>i</code> 个信封的宽度和高度。</p>

<p>当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。</p>

<p>请计算 <strong>最多能有多少个</strong> 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。</p>

<p><strong>注意</strong>：不允许旋转信封。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>envelopes = [[5,4],[6,4],[6,7],[2,3]]
<strong>输出：</strong>3
<strong>解释：</strong>最多信封的个数为 <code>3, 组合为: </code>[2,3] =&gt; [5,4] =&gt; [6,7]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>envelopes = [[1,1],[1,1],[1,1]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= envelopes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>envelopes[i].length == 2</code></li>
	<li><code>1 &lt;= w<sub>i</sub>, h<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

时间复杂度 O(nlogn)。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        d = [envelopes[0][1]]
        for _, h in envelopes[1:]:
            if h > d[-1]:
                d.append(h)
            else:
                idx = bisect_left(d, h)
                d[idx] = h
        return len(d)
```

#### Java

```java
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> { return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]; });
        int n = envelopes.length;
        int[] d = new int[n + 1];
        d[1] = envelopes[0][1];
        int size = 1;
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[size]) {
                d[++size] = x;
            } else {
                int left = 1, right = size;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (d[mid] >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                int p = d[left] >= x ? left : 1;
                d[p] = x;
            }
        }
        return size;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        vector<int> d{envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[d.size() - 1])
                d.push_back(x);
            else {
                int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = x;
            }
        }
        return d.size();
    }
};
```

#### Go

```go
func maxEnvelopes(envelopes [][]int) int {
	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] != envelopes[j][0] {
			return envelopes[i][0] < envelopes[j][0]
		}
		return envelopes[j][1] < envelopes[i][1]
	})
	n := len(envelopes)
	d := make([]int, n+1)
	d[1] = envelopes[0][1]
	size := 1
	for _, e := range envelopes[1:] {
		x := e[1]
		if x > d[size] {
			size++
			d[size] = x
		} else {
			left, right := 1, size
			for left < right {
				mid := (left + right) >> 1
				if d[mid] >= x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			if d[left] < x {
				left = 1
			}
			d[left] = x
		}
	}
	return size
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [355. 设计推特](https://leetcode.cn/problems/design-twitter){#355}

{{< tabs "355" >}}

{{% tab "python" %}}
```python
class Twitter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.user_tweets = defaultdict(list)
        self.user_following = defaultdict(set)
        self.tweets = defaultdict()
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.time += 1
        self.user_tweets[userId].append(tweetId)
        self.tweets[tweetId] = self.time

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        following = self.user_following[userId]
        users = set(following)
        users.add(userId)
        tweets = [self.user_tweets[u][::-1][:10] for u in users]
        tweets = sum(tweets, [])
        return nlargest(10, tweets, key=lambda tweet: self.tweets[tweet])

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.user_following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        following = self.user_following[followerId]
        if followeeId in following:
            following.remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Twitter {
    private Map<Integer, List<Integer>> userTweets;
    private Map<Integer, Set<Integer>> userFollowing;
    private Map<Integer, Integer> tweets;
    private int time;

    /** Initialize your data structure here. */
    public Twitter() {
        userTweets = new HashMap<>();
        userFollowing = new HashMap<>();
        tweets = new HashMap<>();
        time = 0;
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        userTweets.computeIfAbsent(userId, k -> new ArrayList<>()).add(tweetId);
        tweets.put(tweetId, ++time);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed
     * must be posted by users who the user followed or by the user herself. Tweets must be ordered
     * from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> following = userFollowing.getOrDefault(userId, new HashSet<>());
        Set<Integer> users = new HashSet<>(following);
        users.add(userId);
        PriorityQueue<Integer> pq
            = new PriorityQueue<>(10, (a, b) -> (tweets.get(b) - tweets.get(a)));
        for (Integer u : users) {
            List<Integer> userTweet = userTweets.get(u);
            if (userTweet != null && !userTweet.isEmpty()) {
                for (int i = userTweet.size() - 1, k = 10; i >= 0 && k > 0; --i, --k) {
                    pq.offer(userTweet.get(i));
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty() && res.size() < 10) {
            res.add(pq.poll());
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        userFollowing.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        userFollowing.computeIfAbsent(followerId, k -> new HashSet<>()).remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 <code>10</code> 条推文。</p>

<p>实现 <code>Twitter</code> 类：</p>

<ul>
	<li><code>Twitter()</code> 初始化简易版推特对象</li>
	<li><code>void postTweet(int userId, int tweetId)</code> 根据给定的 <code>tweetId</code> 和 <code>userId</code> 创建一条新推文。每次调用此函数都会使用一个不同的 <code>tweetId</code> 。</li>
	<li><code>List&lt;Integer&gt; getNewsFeed(int userId)</code> 检索当前用户新闻推送中最近&nbsp; <code>10</code> 条推文的 ID 。新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 <strong>按照时间顺序由最近到最远排序</strong> 。</li>
	<li><code>void follow(int followerId, int followeeId)</code> ID 为 <code>followerId</code> 的用户开始关注 ID 为 <code>followeeId</code> 的用户。</li>
	<li><code>void unfollow(int followerId, int followeeId)</code> ID 为 <code>followerId</code> 的用户不再关注 ID 为 <code>followeeId</code> 的用户。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
<strong>输出</strong>
[null, null, [5], null, null, [6, 5], null, [5]]

<strong>解释</strong>
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
twitter.follow(1, 2);    // 用户 1 关注了用户 2
twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -&gt; [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= userId, followerId, followeeId &lt;= 500</code></li>
	<li><code>0 &lt;= tweetId &lt;= 10<sup>4</sup></code></li>
	<li>所有推特的 ID 都互不相同</li>
	<li><code>postTweet</code>、<code>getNewsFeed</code>、<code>follow</code> 和 <code>unfollow</code> 方法最多调用 <code>3 * 10<sup>4</sup></code> 次</li>
	<li>用户不能关注自己</li>
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
class Twitter:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.user_tweets = defaultdict(list)
        self.user_following = defaultdict(set)
        self.tweets = defaultdict()
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Compose a new tweet.
        """
        self.time += 1
        self.user_tweets[userId].append(tweetId)
        self.tweets[tweetId] = self.time

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        following = self.user_following[userId]
        users = set(following)
        users.add(userId)
        tweets = [self.user_tweets[u][::-1][:10] for u in users]
        tweets = sum(tweets, [])
        return nlargest(10, tweets, key=lambda tweet: self.tweets[tweet])

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.user_following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        following = self.user_following[followerId]
        if followeeId in following:
            following.remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
```

#### Java

```java
class Twitter {
    private Map<Integer, List<Integer>> userTweets;
    private Map<Integer, Set<Integer>> userFollowing;
    private Map<Integer, Integer> tweets;
    private int time;

    /** Initialize your data structure here. */
    public Twitter() {
        userTweets = new HashMap<>();
        userFollowing = new HashMap<>();
        tweets = new HashMap<>();
        time = 0;
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        userTweets.computeIfAbsent(userId, k -> new ArrayList<>()).add(tweetId);
        tweets.put(tweetId, ++time);
    }

    /**
     * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed
     * must be posted by users who the user followed or by the user herself. Tweets must be ordered
     * from most recent to least recent.
     */
    public List<Integer> getNewsFeed(int userId) {
        Set<Integer> following = userFollowing.getOrDefault(userId, new HashSet<>());
        Set<Integer> users = new HashSet<>(following);
        users.add(userId);
        PriorityQueue<Integer> pq
            = new PriorityQueue<>(10, (a, b) -> (tweets.get(b) - tweets.get(a)));
        for (Integer u : users) {
            List<Integer> userTweet = userTweets.get(u);
            if (userTweet != null && !userTweet.isEmpty()) {
                for (int i = userTweet.size() - 1, k = 10; i >= 0 && k > 0; --i, --k) {
                    pq.offer(userTweet.get(i));
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty() && res.size() < 10) {
            res.add(pq.poll());
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        userFollowing.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        userFollowing.computeIfAbsent(followerId, k -> new HashSet<>()).remove(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [356. 直线镜像 🔒](https://leetcode.cn/problems/line-reflection){#356}

{{< tabs "356" >}}

{{% tab "python" %}}
```python
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        min_x, max_x = inf, -inf
        point_set = set()
        for x, y in points:
            min_x = min(min_x, x)
            max_x = max(max_x, x)
            point_set.add((x, y))
        s = min_x + max_x
        return all((s - x, y) in point_set for x, y in points)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isReflected(int[][] points) {
        final int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        Set<List<Integer>> pointSet = new HashSet<>();
        for (int[] p : points) {
            minX = Math.min(minX, p[0]);
            maxX = Math.max(maxX, p[0]);
            pointSet.add(List.of(p[0], p[1]));
        }
        int s = minX + maxX;
        for (int[] p : points) {
            if (!pointSet.contains(List.of(s - p[0], p[1]))) {
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
    bool isReflected(vector<vector<int>>& points) {
        const int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        set<pair<int, int>> pointSet;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pointSet.insert({p[0], p[1]});
        }
        int s = minX + maxX;
        for (auto& p : points) {
            if (!pointSet.count({s - p[0], p[1]})) {
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
func isReflected(points [][]int) bool {
	const inf = 1 << 30
	minX, maxX := inf, -inf
	pointSet := map[[2]int]bool{}
	for _, p := range points {
		minX = min(minX, p[0])
		maxX = max(maxX, p[0])
		pointSet[[2]int{p[0], p[1]}] = true
	}
	s := minX + maxX
	for _, p := range points {
		if !pointSet[[2]int{s - p[0], p[1]}] {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个二维平面空间中，给你 n&nbsp;个点的坐标。问，是否能找出一条平行于 y<strong>&nbsp;</strong>轴的直线，让这些点关于这条直线成镜像排布？</p>

<p><strong>注意</strong>：题目数据中可能有重复的点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0356.Line%20Reflection/images/356_example_1.png" style="width: 389px; height: 340px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[-1,1]]
<strong>输出：</strong>true
<strong>解释：</strong>可以找出 x = 0 这条线。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0356.Line%20Reflection/images/356_example_2.png" style="width: 300px; height: 294px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[-1,-1]]
<strong>输出：</strong>false
<strong>解释：</strong>无法找出这样一条线。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
	<li><code>-10^8&nbsp;&lt;= points[i][j] &lt;=&nbsp;10^8</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能找到比 O(<em>n</em><sup>2</sup>) 更优的解法吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们先找出所有点中的最小、最大的 $x$ 坐标 $minX$ 和 $maxX$。若存在满足条件的直线，则直线 $x = (minX + maxX) / 2$，或者说 $s = minX + maxX$。

接下来，我们遍历每个点 $(x, y)，若 $(s - x, y)$ 不在点集里，说明不满足条件，直接返回 `false`。遍历结束返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        min_x, max_x = inf, -inf
        point_set = set()
        for x, y in points:
            min_x = min(min_x, x)
            max_x = max(max_x, x)
            point_set.add((x, y))
        s = min_x + max_x
        return all((s - x, y) in point_set for x, y in points)
```

#### Java

```java
class Solution {
    public boolean isReflected(int[][] points) {
        final int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        Set<List<Integer>> pointSet = new HashSet<>();
        for (int[] p : points) {
            minX = Math.min(minX, p[0]);
            maxX = Math.max(maxX, p[0]);
            pointSet.add(List.of(p[0], p[1]));
        }
        int s = minX + maxX;
        for (int[] p : points) {
            if (!pointSet.contains(List.of(s - p[0], p[1]))) {
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
    bool isReflected(vector<vector<int>>& points) {
        const int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        set<pair<int, int>> pointSet;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pointSet.insert({p[0], p[1]});
        }
        int s = minX + maxX;
        for (auto& p : points) {
            if (!pointSet.count({s - p[0], p[1]})) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isReflected(points [][]int) bool {
	const inf = 1 << 30
	minX, maxX := inf, -inf
	pointSet := map[[2]int]bool{}
	for _, p := range points {
		minX = min(minX, p[0])
		maxX = max(maxX, p[0])
		pointSet[[2]int{p[0], p[1]}] = true
	}
	s := minX + maxX
	for _, p := range points {
		if !pointSet[[2]int{s - p[0], p[1]}] {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [357. 统计各位数字都不同的数字个数](https://leetcode.cn/problems/count-numbers-with-unique-digits){#357}

{{< tabs "357" >}}

{{% tab "python" %}}
```python
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool) -> int:
            if i < 0:
                return 1
            ans = 0
            for j in range(10):
                if mask >> j & 1:
                    continue
                if lead and j == 0:
                    ans += dfs(i - 1, mask, True)
                else:
                    ans += dfs(i - 1, mask | 1 << j, False)
            return ans

        return dfs(n - 1, 0, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;

    public int countNumbersWithUniqueDigits(int n) {
        f = new Integer[n][1 << 10];
        return dfs(n - 1, 0, true);
    }

    private int dfs(int i, int mask, boolean lead) {
        if (i < 0) {
            return 1;
        }
        if (!lead && f[i][mask] != null) {
            return f[i][mask];
        }
        int ans = 0;
        for (int j = 0; j <= 9; ++j) {
            if ((mask >> j & 1) == 1) {
                continue;
            }
            if (lead && j == 0) {
                ans += dfs(i - 1, mask, true);
            } else {
                ans += dfs(i - 1, mask | 1 << j, false);
            }
        }
        if (!lead) {
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
    int countNumbersWithUniqueDigits(int n) {
        int f[n + 1][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead) -> int {
            if (i < 0) {
                return 1;
            }
            if (!lead && f[i][mask] != -1) {
                return f[i][mask];
            }
            int ans = 0;
            for (int j = 0; j <= 9; ++j) {
                if (mask >> j & 1) {
                    continue;
                }
                if (lead && j == 0) {
                    ans += dfs(i - 1, mask, true);
                } else {
                    ans += dfs(i - 1, mask | 1 << i, false);
                }
            }
            if (!lead) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return dfs(n - 1, 0, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countNumbersWithUniqueDigits(n int) int {
	f := make([][1 << 10]int, n)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, mask int, lead bool) int
	dfs = func(i, mask int, lead bool) int {
		if i < 0 {
			return 1
		}
		if !lead && f[i][mask] != -1 {
			return f[i][mask]
		}
		ans := 0
		for j := 0; j < 10; j++ {
			if mask>>j&1 == 1 {
				continue
			}
			if lead && j == 0 {
				ans += dfs(i-1, mask, true)
			} else {
				ans += dfs(i-1, mask|1<<j, false)
			}
		}
		if !lead {
			f[i][mask] = ans
		}
		return ans
	}
	return dfs(n-1, 0, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countNumbersWithUniqueDigits(n: number): number {
    const f: number[][] = Array.from({ length: n }, () => Array(1 << 10).fill(-1));
    const dfs = (i: number, mask: number, lead: boolean): number => {
        if (i < 0) {
            return 1;
        }
        if (!lead && f[i][mask] !== -1) {
            return f[i][mask];
        }
        let ans = 0;
        for (let j = 0; j < 10; ++j) {
            if ((mask >> j) & 1) {
                continue;
            }
            if (lead && j === 0) {
                ans += dfs(i - 1, mask, true);
            } else {
                ans += dfs(i - 1, mask | (1 << j), false);
            }
        }
        if (!lead) {
            f[i][mask] = ans;
        }
        return ans;
    };
    return dfs(n - 1, 0, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个整数 <code>n</code> ，统计并返回各位数字都不同的数字 <code>x</code> 的个数，其中 <code>0 &lt;= x &lt; 10<sup>n</sup></code><sup>&nbsp;</sup>。

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>91
<strong>解释：</strong>答案应为除去 <code>11、22、33、44、55、66、77、88、99 </code>外，在 0 ≤ x &lt; 100 范围内的所有数字。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>1
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，满足条件的数的个数。条件与数的大小无关，而只与数的组成有关，因此可以使用数位 DP 的思想求解。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[1,..10^n-1]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

我们根据题目信息，设计一个函数 $\textit{dfs}(i, \textit{mask}, \textit{lead})$，其中：

-   数字 $i$ 表示当前搜索到的位置，我们从高位开始搜索，即 $i = 0$ 表示最高位。
-   数字 $\textit{mask}$ 表示当前数字的状态，即 $\textit{mask}$ 的第 $j$ 位为 $1$ 表示数字 $j$ 已经被使用过。
-   布尔值 $\textit{lead}$ 表示当前是否只包含前导 $0$。

函数的执行过程如下：

如果 $i$ 超过了数字 $n$ 的长度，即 $i \lt 0$，说明搜索结束，直接返回 $1$。

否则，我们从 $0$ 到 $9$ 枚举位置 $i$ 的数字 $j$，对于每一个 $j$：

-   如果 $\textit{mask}$ 的第 $j$ 位为 $1$，说明数字 $j$ 已经被使用过，直接跳过。
-   如果 $\textit{lead}$ 为真且 $j = 0$，说明当前数字只包含前导 $0$，递归到下一层时，此时 $\textit{lead}$ 仍为真。
-   否则，我们递归到下一层，更新 $\textit{mask}$ 的第 $j$ 位为 $1$，并将 $\textit{lead}$ 更新为假。

最后，我们将所有递归到下一层的结果累加，即为答案。

答案为 $\textit{dfs}(n - 1, 0, \textit{True})$。

关于函数的实现细节，可以参考下面的代码。

时间复杂度 $O(n \times 2^D \times D)$，空间复杂度 $O(n \times 2^D)$。其中 $n$ 为数字 $n$ 的长度，而 $D = 10$。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        @cache
        def dfs(i: int, mask: int, lead: bool) -> int:
            if i < 0:
                return 1
            ans = 0
            for j in range(10):
                if mask >> j & 1:
                    continue
                if lead and j == 0:
                    ans += dfs(i - 1, mask, True)
                else:
                    ans += dfs(i - 1, mask | 1 << j, False)
            return ans

        return dfs(n - 1, 0, True)
```

#### Java

```java
class Solution {
    private Integer[][] f;

    public int countNumbersWithUniqueDigits(int n) {
        f = new Integer[n][1 << 10];
        return dfs(n - 1, 0, true);
    }

    private int dfs(int i, int mask, boolean lead) {
        if (i < 0) {
            return 1;
        }
        if (!lead && f[i][mask] != null) {
            return f[i][mask];
        }
        int ans = 0;
        for (int j = 0; j <= 9; ++j) {
            if ((mask >> j & 1) == 1) {
                continue;
            }
            if (lead && j == 0) {
                ans += dfs(i - 1, mask, true);
            } else {
                ans += dfs(i - 1, mask | 1 << j, false);
            }
        }
        if (!lead) {
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
    int countNumbersWithUniqueDigits(int n) {
        int f[n + 1][1 << 10];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int mask, bool lead) -> int {
            if (i < 0) {
                return 1;
            }
            if (!lead && f[i][mask] != -1) {
                return f[i][mask];
            }
            int ans = 0;
            for (int j = 0; j <= 9; ++j) {
                if (mask >> j & 1) {
                    continue;
                }
                if (lead && j == 0) {
                    ans += dfs(i - 1, mask, true);
                } else {
                    ans += dfs(i - 1, mask | 1 << i, false);
                }
            }
            if (!lead) {
                f[i][mask] = ans;
            }
            return ans;
        };
        return dfs(n - 1, 0, true);
    }
};
```

#### Go

```go
func countNumbersWithUniqueDigits(n int) int {
	f := make([][1 << 10]int, n)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, mask int, lead bool) int
	dfs = func(i, mask int, lead bool) int {
		if i < 0 {
			return 1
		}
		if !lead && f[i][mask] != -1 {
			return f[i][mask]
		}
		ans := 0
		for j := 0; j < 10; j++ {
			if mask>>j&1 == 1 {
				continue
			}
			if lead && j == 0 {
				ans += dfs(i-1, mask, true)
			} else {
				ans += dfs(i-1, mask|1<<j, false)
			}
		}
		if !lead {
			f[i][mask] = ans
		}
		return ans
	}
	return dfs(n-1, 0, true)
}
```

#### TypeScript

```ts
function countNumbersWithUniqueDigits(n: number): number {
    const f: number[][] = Array.from({ length: n }, () => Array(1 << 10).fill(-1));
    const dfs = (i: number, mask: number, lead: boolean): number => {
        if (i < 0) {
            return 1;
        }
        if (!lead && f[i][mask] !== -1) {
            return f[i][mask];
        }
        let ans = 0;
        for (let j = 0; j < 10; ++j) {
            if ((mask >> j) & 1) {
                continue;
            }
            if (lead && j === 0) {
                ans += dfs(i - 1, mask, true);
            } else {
                ans += dfs(i - 1, mask | (1 << j), false);
            }
        }
        if (!lead) {
            f[i][mask] = ans;
        }
        return ans;
    };
    return dfs(n - 1, 0, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [358. K 距离间隔重排字符串 🔒](https://leetcode.cn/problems/rearrange-string-k-distance-apart){#358}

{{< tabs "358" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        h = [(-v, c) for c, v in Counter(s).items()]
        heapify(h)
        q = deque()
        ans = []
        while h:
            v, c = heappop(h)
            v *= -1
            ans.append(c)
            q.append((v - 1, c))
            if len(q) >= k:
                w, c = q.popleft()
                if w:
                    heappush(h, (-w, c))
        return "" if len(ans) != len(s) else "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String rearrangeString(String s, int k) {
        int n = s.length();
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                pq.offer(new int[] {cnt[i], i});
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int v = p[0], c = p[1];
            ans.append((char) ('a' + c));
            q.offer(new int[] {v - 1, c});
            if (q.size() >= k) {
                p = q.pollFirst();
                if (p[0] > 0) {
                    pq.offer(p);
                }
            }
        }
        return ans.length() == n ? ans.toString() : "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s) ++cnt[c];
        priority_queue<pair<int, char>> pq;
        for (auto& [c, v] : cnt) pq.push({v, c});
        queue<pair<int, char>> q;
        string ans;
        while (!pq.empty()) {
            auto [v, c] = pq.top();
            pq.pop();
            ans += c;
            q.push({v - 1, c});
            if (q.size() >= k) {
                auto p = q.front();
                q.pop();
                if (p.first) {
                    pq.push(p);
                }
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeString(s string, k int) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	pq := hp{}
	for c, v := range cnt {
		heap.Push(&pq, pair{v, c})
	}
	ans := []byte{}
	q := []pair{}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		v, c := p.v, p.c
		ans = append(ans, c)
		q = append(q, pair{v - 1, c})
		if len(q) >= k {
			p = q[0]
			q = q[1:]
			if p.v > 0 {
				heap.Push(&pq, p)
			}
		}
	}
	if len(ans) == len(s) {
		return string(ans)
	}
	return ""
}

type pair struct {
	v int
	c byte
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非空的字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，你要将这个字符串&nbsp;<code>s</code>&nbsp;中的字母进行重新排列，使得重排后的字符串中相同字母的位置间隔距离 <strong>至少</strong> 为&nbsp;<code>k</code>&nbsp;。如果无法做到，请返回一个空字符串&nbsp;<code>""</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>s = "aabbcc", k = 3
<strong>输出: </strong>"abcabc" 
<strong>解释: </strong>相同的字母在新的字符串中间隔至少 3 个单位距离。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "aaabc", k = 3
<strong>输出: </strong>"" 
<strong>解释:</strong> 没有办法找到可能的重排结果。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入: </strong>s = "aaadbbcc", k = 2
<strong>输出: </strong>"abacabcd"
<strong>解释:</strong> 相同的字母在新的字符串中间隔至少 2 个单位距离。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;仅由小写英文字母组成</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 哈希表 + 优先队列（大根堆）

先用哈希表 `cnt` 统计每个字母出现的次数，然后构建一个大根堆 `pq`，其中每个元素是一个 `(v, c)` 的元组，其中 `c` 是字母，`v` 是字母出现的次数。

重排字符串时，我们每次从堆顶弹出一个元素 `(v, c)`，将 `c` 添加到结果字符串中，并将 `(v-1, c)` 放入队列 `q` 中。当队列 `q` 的长度达到 $k$ 及以上时，弹出队首元素，若此时 `v` 大于 0，则将队首元素放入堆中。循环，直至堆为空。

最后判断结果字符串的长度，若与 `s` 长度相等，则返回结果字符串，否则返回空串。

时间复杂度 $O(n\log n)$，其中 $n$ 是字符串 `s` 的长度。

相似题目：

-   [767. 重构字符串](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0767.Reorganize%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        h = [(-v, c) for c, v in Counter(s).items()]
        heapify(h)
        q = deque()
        ans = []
        while h:
            v, c = heappop(h)
            v *= -1
            ans.append(c)
            q.append((v - 1, c))
            if len(q) >= k:
                w, c = q.popleft()
                if w:
                    heappush(h, (-w, c))
        return "" if len(ans) != len(s) else "".join(ans)
```

#### Java

```java
class Solution {
    public String rearrangeString(String s, int k) {
        int n = s.length();
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                pq.offer(new int[] {cnt[i], i});
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int v = p[0], c = p[1];
            ans.append((char) ('a' + c));
            q.offer(new int[] {v - 1, c});
            if (q.size() >= k) {
                p = q.pollFirst();
                if (p[0] > 0) {
                    pq.offer(p);
                }
            }
        }
        return ans.length() == n ? ans.toString() : "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> cnt;
        for (char c : s) ++cnt[c];
        priority_queue<pair<int, char>> pq;
        for (auto& [c, v] : cnt) pq.push({v, c});
        queue<pair<int, char>> q;
        string ans;
        while (!pq.empty()) {
            auto [v, c] = pq.top();
            pq.pop();
            ans += c;
            q.push({v - 1, c});
            if (q.size() >= k) {
                auto p = q.front();
                q.pop();
                if (p.first) {
                    pq.push(p);
                }
            }
        }
        return ans.size() == s.size() ? ans : "";
    }
};
```

#### Go

```go
func rearrangeString(s string, k int) string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	pq := hp{}
	for c, v := range cnt {
		heap.Push(&pq, pair{v, c})
	}
	ans := []byte{}
	q := []pair{}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		v, c := p.v, p.c
		ans = append(ans, c)
		q = append(q, pair{v - 1, c})
		if len(q) >= k {
			p = q[0]
			q = q[1:]
			if p.v > 0 {
				heap.Push(&pq, p)
			}
		}
	}
	if len(ans) == len(s) {
		return string(ans)
	}
	return ""
}

type pair struct {
	v int
	c byte
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [359. 日志速率限制器 🔒](https://leetcode.cn/problems/logger-rate-limiter){#359}

{{< tabs "359" >}}

{{% tab "python" %}}
```python
class Logger:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.limiter = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity.
        """
        t = self.limiter.get(message, 0)
        if t > timestamp:
            return False
        self.limiter[message] = timestamp + 10
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Logger {

    private Map<String, Integer> limiter;

    /** Initialize your data structure here. */
    public Logger() {
        limiter = new HashMap<>();
    }

    /**
       Returns true if the message should be printed in the given timestamp, otherwise returns
       false. If this method returns false, the message will not be printed. The timestamp is in
       seconds granularity.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        int t = limiter.getOrDefault(message, 0);
        if (t > timestamp) {
            return false;
        }
        limiter.put(message, timestamp + 10);
        return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Initialize your data structure here.
 */
var Logger = function () {
    this.limiter = {};
};

/**
 * Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. 
 * @param {number} timestamp 
 * @param {string} message
 * @return {boolean}
 */
Logger.prototype.shouldPrintMessage = function (timestamp, message) {
    const t = this.limiter[message] || 0;
    if (t > timestamp) {
        return false;
    }
    this.limiter[message] = timestamp + 10;
    return true;
};

/**
 * Your Logger object will be instantiated and called as such:
 * var obj = new Logger()
 * var param_1 = obj.shouldPrintMessage(timestamp,message)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个日志系统，可以流式接收消息以及它的时间戳。每条 <strong>不重复</strong> 的消息最多只能每 10 秒打印一次。也就是说，如果在时间戳 <code>t</code> 打印某条消息，那么相同内容的消息直到时间戳变为 <code>t + 10</code> 之前都不会被打印。</p>

<p>所有消息都按时间顺序发送。多条消息可能到达同一时间戳。</p>

<p>实现 <code>Logger</code> 类：</p>

<ul>
	<li><code>Logger()</code> 初始化 <code>logger</code> 对象</li>
	<li><code>bool shouldPrintMessage(int timestamp, string message)</code> 如果这条消息 <code>message</code> 在给定的时间戳 <code>timestamp</code> 应该被打印出来，则返回 <code>true</code> ，否则请返回 <code>false</code> 。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
<strong>输出：</strong>
[null, true, true, false, false, false, true]

<strong>解释：</strong>
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // 返回 true ，下一次 "foo" 可以打印的时间戳是 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // 返回 true ，下一次 "bar" 可以打印的时间戳是 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11 ，返回 false
logger.shouldPrintMessage(8, "bar");  // 8 < 12 ，返回 false
logger.shouldPrintMessage(10, "foo"); // 10 < 11 ，返回 false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11 ，返回 true ，下一次 "foo" 可以打印的时间戳是 11 + 10 = 21
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= timestamp <= 10<sup>9</sup></code></li>
	<li>每个 <code>timestamp</code> 都将按非递减顺序（时间顺序）传递</li>
	<li><code>1 <= message.length <= 30</code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>shouldPrintMessage</code> 方法</li>
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
class Logger:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.limiter = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity.
        """
        t = self.limiter.get(message, 0)
        if t > timestamp:
            return False
        self.limiter[message] = timestamp + 10
        return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)
```

#### Java

```java
class Logger {

    private Map<String, Integer> limiter;

    /** Initialize your data structure here. */
    public Logger() {
        limiter = new HashMap<>();
    }

    /**
       Returns true if the message should be printed in the given timestamp, otherwise returns
       false. If this method returns false, the message will not be printed. The timestamp is in
       seconds granularity.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        int t = limiter.getOrDefault(message, 0);
        if (t > timestamp) {
            return false;
        }
        limiter.put(message, timestamp + 10);
        return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
```

#### JavaScript

```js
/**
 * Initialize your data structure here.
 */
var Logger = function () {
    this.limiter = {};
};

/**
 * Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. 
 * @param {number} timestamp 
 * @param {string} message
 * @return {boolean}
 */
Logger.prototype.shouldPrintMessage = function (timestamp, message) {
    const t = this.limiter[message] || 0;
    if (t > timestamp) {
        return false;
    }
    this.limiter[message] = timestamp + 10;
    return true;
};

/**
 * Your Logger object will be instantiated and called as such:
 * var obj = new Logger()
 * var param_1 = obj.shouldPrintMessage(timestamp,message)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

---
title: "1990_统计实验的数量 🔒"
date: 2025-10-08T18:38:49+08:00
weight: 10
tags: [位运算, 前缀和, 动态规划, 单调栈, 哈希表, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 枚举, 栈, 树, 深度优先搜索, 状态压缩, 矩阵, 计数, 设计, 贪心]
---

{{< markmap >}}
### [1990_统计实验的数量 🔒](#1990)
#### [数据库](#1990)
### [1991_找到数组的中间位置](#1991)
#### [数组](#1991)
#### [前缀和](#1991)
### [1992_找到所有的农场组](#1992)
#### [深度优先搜索](#1992)
#### [广度优先搜索](#1992)
#### [数组](#1992)
#### [矩阵](#1992)
### [1993_树上的操作](#1993)
#### [树](#1993)
#### [深度优先搜索](#1993)
#### [广度优先搜索](#1993)
#### [设计](#1993)
#### [数组](#1993)
#### [哈希表](#1993)
### [1994_好子集的数目](#1994)
#### [位运算](#1994)
#### [数组](#1994)
#### [哈希表](#1994)
#### [数学](#1994)
#### [动态规划](#1994)
#### [状态压缩](#1994)
#### [计数](#1994)
#### [数论](#1994)
### [1995_统计特殊四元组](#1995)
#### [数组](#1995)
#### [哈希表](#1995)
#### [枚举](#1995)
### [1996_游戏中弱角色的数量](#1996)
#### [栈](#1996)
#### [贪心](#1996)
#### [数组](#1996)
#### [排序](#1996)
#### [单调栈](#1996)
### [1997_访问完所有房间的第一天](#1997)
#### [数组](#1997)
#### [动态规划](#1997)
### [1998_数组的最大公因数排序](#1998)
#### [并查集](#1998)
#### [数组](#1998)
#### [数学](#1998)
#### [数论](#1998)
#### [排序](#1998)
### [1999_最小的仅由两个数组成的倍数 🔒](#1999)
#### [数学](#1999)
#### [枚举](#1999)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1990_统计实验的数量 🔒
___
#### 数据库
---
### 1991_找到数组的中间位置
___
#### 数组
___
#### 前缀和
---
### 1992_找到所有的农场组
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1993_树上的操作
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 数组
___
#### 哈希表
---
### 1994_好子集的数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 动态规划
___
#### 状态压缩
___
#### 计数
___
#### 数论
---
### 1995_统计特殊四元组
___
#### 数组
___
#### 哈希表
___
#### 枚举
---
### 1996_游戏中弱角色的数量
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 单调栈
---
### 1997_访问完所有房间的第一天
___
#### 数组
___
#### 动态规划
---
### 1998_数组的最大公因数排序
___
#### 并查集
___
#### 数组
___
#### 数学
___
#### 数论
___
#### 排序
---
### 1999_最小的仅由两个数组成的倍数 🔒
___
#### 数学
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 单调栈 | 哈希表 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 枚举 | 栈 | 树 |
| 深度优先搜索 | 状态压缩 | 矩阵 |
| 计数 | 设计 | 贪心 |

# [1990. 统计实验的数量 🔒](https://leetcode.cn/problems/count-the-number-of-experiments){#1990}

{{< tabs "1990" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT 'Android' AS platform
        UNION
        SELECT 'IOS'
        UNION
        SELECT 'Web'
    ),
    Exp AS (
        SELECT 'Reading' AS experiment_name
        UNION
        SELECT 'Sports'
        UNION
        SELECT 'Programming'
    ),
    T AS (
        SELECT *
        FROM
            P,
            Exp
    )
SELECT platform, experiment_name, COUNT(experiment_id) AS num_experiments
FROM
    T AS t
    LEFT JOIN Experiments USING (platform, experiment_name)
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Experiments</code></p>

<pre>
+-----------------+------+
| Column Name     | Type |
+-----------------+------+
| experiment_id   | int  |
| platform        | enum |
| experiment_name | enum |
+-----------------+------+

experiment_id 是这个表的主键.
platform 是枚举类型的，取值是这三种 ('Android', 'IOS', 'Web') 之一.
experiment_name 也是枚举类型的，取值是这三种 ('Reading', 'Sports', 'Programming') 之一.
这个表包含有关随机实验人员进行的实验的 ID、用于做实验的平台以及实验名称的信息。
</pre>

<p>&nbsp;</p>

<p>写一个 SQL 查询语句，以报告在给定三个实验平台中每种实验完成的次数。请注意，每一对（实验平台、实验名称）都应包含在输出中，包括平台上实验次数是零的。</p>

<p>结果可以以任意顺序给出。</p>

<p>查询的结果如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
Experiments table:
+---------------+----------+-----------------+
| experiment_id | platform | experiment_name |
+---------------+----------+-----------------+
| 4             | IOS      | Programming     |
| 13            | IOS      | Sports          |
| 14            | Android  | Reading         |
| 8             | Web      | Reading         |
| 12            | Web      | Reading         |
| 18            | Web      | Programming     |
+---------------+----------+-----------------+
<strong>输出：</strong>
+----------+-----------------+-----------------+
| platform | experiment_name | num_experiments |
+----------+-----------------+-----------------+
| Android  | Reading         | 1               |
| Android  | Sports          | 0               |
| Android  | Programming     | 0               |
| IOS      | Reading         | 0               |
| IOS      | Sports          | 1               |
| IOS      | Programming     | 1               |
| Web      | Reading         | 2               |
| Web      | Sports          | 0               |
| Web      | Programming     | 1               |
+----------+-----------------+-----------------+
<strong>解释：</strong>
在安卓平台上, 我们只做了一个"Reading" 实验.
在 "IOS" 平台上，我们做了一个"Sports" 实验和一个"Programming" 实验.
在 "Web" 平台上，我们做了两个"Reading" 实验和一个"Programming" 实验.
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
WITH
    P AS (
        SELECT 'Android' AS platform
        UNION
        SELECT 'IOS'
        UNION
        SELECT 'Web'
    ),
    Exp AS (
        SELECT 'Reading' AS experiment_name
        UNION
        SELECT 'Sports'
        UNION
        SELECT 'Programming'
    ),
    T AS (
        SELECT *
        FROM
            P,
            Exp
    )
SELECT platform, experiment_name, COUNT(experiment_id) AS num_experiments
FROM
    T AS t
    LEFT JOIN Experiments USING (platform, experiment_name)
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1991. 找到数组的中间位置](https://leetcode.cn/problems/find-the-middle-index-in-array){#1991}

{{< tabs "1991" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        l, r = 0, sum(nums)
        for i, x in enumerate(nums):
            r -= x
            if l == r:
                return i
            l += x
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMiddleIndex(int[] nums) {
        int l = 0, r = Arrays.stream(nums).sum();
        for (int i = 0; i < nums.length; ++i) {
            r -= nums[i];
            if (l == r) {
                return i;
            }
            l += nums[i];
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
    int findMiddleIndex(vector<int>& nums) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            r -= nums[i];
            if (l == r) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMiddleIndex(nums []int) int {
	l, r := 0, 0
	for _, x := range nums {
		r += x
	}
	for i, x := range nums {
		r -= x
		if l == r {
			return i
		}
		l += x
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMiddleIndex(nums: number[]): number {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    for (let i = 0; i < nums.length; ++i) {
        r -= nums[i];
        if (l === r) {
            return i;
        }
        l += nums[i];
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r: i32 = nums.iter().sum();

        for (i, &x) in nums.iter().enumerate() {
            r -= x;
            if l == r {
                return i as i32;
            }
            l += x;
        }

        -1
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
var findMiddleIndex = function (nums) {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    for (let i = 0; i < nums.length; ++i) {
        r -= nums[i];
        if (l === r) {
            return i;
        }
        l += nums[i];
    }
    return -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，请你找到 <strong>最左边</strong>&nbsp;的中间位置&nbsp;<code>middleIndex</code>&nbsp;（也就是所有可能中间位置下标最小的一个）。</p>

<p>中间位置&nbsp;<code>middleIndex</code>&nbsp;是满足&nbsp;<code>nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1]</code>&nbsp;的数组下标。</p>

<p>如果&nbsp;<code>middleIndex == 0</code>&nbsp;，左边部分的和定义为 <code>0</code>&nbsp;。类似的，如果&nbsp;<code>middleIndex == nums.length - 1</code>&nbsp;，右边部分的和定义为&nbsp;<code>0</code>&nbsp;。</p>

<p>请你返回满足上述条件 <strong>最左边</strong>&nbsp;的<em>&nbsp;</em><code>middleIndex</code>&nbsp;，如果不存在这样的中间位置，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,-1,<em><strong>8</strong></em>,4]
<b>输出：</b>3
<strong>解释：</strong>
下标 3 之前的数字和为：2 + 3 + -1 = 4
下标 3 之后的数字和为：4 = 4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,-1,<em><strong>4</strong></em>]
<b>输出：</b>2
<strong>解释：</strong>
下标 2 之前的数字和为：1 + -1 = 0
下标 2 之后的数字和为：0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [2,5]
<b>输出：</b>-1
<b>解释：</b>
不存在符合要求的 middleIndex 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>nums = [<em><strong>1</strong></em>]
<b>输出：</b>0
<strong>解释：</strong>
下标 0 之前的数字和为：0
下标 0 之后的数字和为：0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 724 题相同：<a href="https://leetcode.cn/problems/find-pivot-index/" target="_blank">https://leetcode.cn/problems/find-pivot-index/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们定义两个变量 $l$ 和 $r$，分别表示数组 $\textit{nums}$ 中下标 $i$ 左侧元素之和和右侧元素之和。初始时 $l = 0$，而 $r = \sum_{i = 0}^{n - 1} nums[i]$。

我们遍历数组 $\textit{nums}$，对于当前遍历到的数字 $x$，我们更新 $r = r - x$，此时如果 $l = r$，说明当前下标 $i$ 就是中间位置，直接返回即可。否则，我们更新 $l = l + x$，继续遍历下一个数字。

遍历结束，如果没有找到中间位置，返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [0724. 寻找数组的中心下标](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0724.Find%20Pivot%20Index/README.md)
-   [2574. 左右元素和的差值](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2574.Left%20and%20Right%20Sum%20Differences/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        l, r = 0, sum(nums)
        for i, x in enumerate(nums):
            r -= x
            if l == r:
                return i
            l += x
        return -1
```

#### Java

```java
class Solution {
    public int findMiddleIndex(int[] nums) {
        int l = 0, r = Arrays.stream(nums).sum();
        for (int i = 0; i < nums.length; ++i) {
            r -= nums[i];
            if (l == r) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            r -= nums[i];
            if (l == r) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
};
```

#### Go

```go
func findMiddleIndex(nums []int) int {
	l, r := 0, 0
	for _, x := range nums {
		r += x
	}
	for i, x := range nums {
		r -= x
		if l == r {
			return i
		}
		l += x
	}
	return -1
}
```

#### TypeScript

```ts
function findMiddleIndex(nums: number[]): number {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    for (let i = 0; i < nums.length; ++i) {
        r -= nums[i];
        if (l === r) {
            return i;
        }
        l += nums[i];
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r: i32 = nums.iter().sum();

        for (i, &x) in nums.iter().enumerate() {
            r -= x;
            if l == r {
                return i as i32;
            }
            l += x;
        }

        -1
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMiddleIndex = function (nums) {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    for (let i = 0; i < nums.length; ++i) {
        r -= nums[i];
        if (l === r) {
            return i;
        }
        l += nums[i];
    }
    return -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1992. 找到所有的农场组](https://leetcode.cn/problems/find-all-groups-of-farmland){#1992}

{{< tabs "1992" >}}

{{% tab "python" %}}
```python
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        ans = []
        for i in range(m):
            for j in range(n):
                if (
                    land[i][j] == 0
                    or (j > 0 and land[i][j - 1] == 1)
                    or (i > 0 and land[i - 1][j] == 1)
                ):
                    continue
                x, y = i, j
                while x + 1 < m and land[x + 1][j] == 1:
                    x += 1
                while y + 1 < n and land[x][y + 1] == 1:
                    y += 1
                ans.append([i, j, x, y])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] findFarmland(int[][] land) {
        List<int[]> ans = new ArrayList<>();
        int m = land.length;
        int n = land[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1)
                    || (i > 0 && land[i - 1][j] == 1)) {
                    continue;
                }
                int x = i;
                int y = j;
                for (; x + 1 < m && land[x + 1][j] == 1; ++x)
                    ;
                for (; y + 1 < n && land[x][y + 1] == 1; ++y)
                    ;
                ans.add(new int[] {i, j, x, y});
            }
        }
        return ans.toArray(new int[ans.size()][4]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)) continue;
                int x = i;
                int y = j;
                for (; x + 1 < m && land[x + 1][j] == 1; ++x)
                    ;
                for (; y + 1 < n && land[x][y + 1] == 1; ++y)
                    ;
                ans.push_back({i, j, x, y});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findFarmland(land [][]int) [][]int {
	m, n := len(land), len(land[0])
	var ans [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if land[i][j] == 0 || (j > 0 && land[i][j-1] == 1) || (i > 0 && land[i-1][j] == 1) {
				continue
			}
			x, y := i, j
			for ; x+1 < m && land[x+1][j] == 1; x++ {
			}
			for ; y+1 < n && land[x][y+1] == 1; y++ {
			}
			ans = append(ans, []int{i, j, x, y})
		}
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始，大小为&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>land</code>&nbsp;，其中 <code>0</code>&nbsp;表示一单位的森林土地，<code>1</code>&nbsp;表示一单位的农场土地。</p>

<p>为了让农场保持有序，农场土地之间以矩形的 <strong>农场组</strong> 的形式存在。每一个农场组都 <strong>仅</strong>&nbsp;包含农场土地。且题目保证不会有两个农场组相邻，也就是说一个农场组中的任何一块土地都 <strong>不会</strong>&nbsp;与另一个农场组的任何一块土地在四个方向上相邻。</p>

<p><code>land</code>&nbsp;可以用坐标系统表示，其中 <code>land</code>&nbsp;左上角坐标为&nbsp;<code>(0, 0)</code>&nbsp;，右下角坐标为&nbsp;<code>(m-1, n-1)</code>&nbsp;。请你找到所有 <b>农场组</b>&nbsp;最左上角和最右下角的坐标。一个左上角坐标为&nbsp;<code>(r<sub>1</sub>, c<sub>1</sub>)</code>&nbsp;且右下角坐标为&nbsp;<code>(r<sub>2</sub>, c<sub>2</sub>)</code>&nbsp;的 <strong>农场组</strong> 用长度为 4 的数组&nbsp;<code>[r<sub>1</sub>, c<sub>1</sub>, r<sub>2</sub>, c<sub>2</sub>]</code>&nbsp;表示。</p>

<p>请你返回一个二维数组，它包含若干个长度为 4 的子数组，每个子数组表示 <code>land</code>&nbsp;中的一个 <strong>农场组</strong>&nbsp;。如果没有任何农场组，请你返回一个空数组。可以以 <strong>任意顺序</strong>&nbsp;返回所有农场组。</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1992.Find%20All%20Groups%20of%20Farmland/images/screenshot-2021-07-27-at-12-23-15-copy-of-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>land = [[1,0,0],[0,1,1],[0,1,1]]
<b>输出：</b>[[0,0,0,0],[1,1,2,2]]
<strong>解释：</strong>
第一个农场组的左上角为 land[0][0] ，右下角为 land[0][0] 。
第二个农场组的左上角为 land[1][1] ，右下角为 land[2][2] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1992.Find%20All%20Groups%20of%20Farmland/images/screenshot-2021-07-27-at-12-30-26-copy-of-diagram-drawio-diagrams-net.png" style="width: 200px; height: 200px;"></p>

<pre><b>输入：</b>land = [[1,1],[1,1]]
<b>输出：</b>[[0,0,1,1]]
<strong>解释：</strong>
第一个农场组左上角为 land[0][0] ，右下角为 land[1][1] 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1992.Find%20All%20Groups%20of%20Farmland/images/screenshot-2021-07-27-at-12-32-24-copy-of-diagram-drawio-diagrams-net.png" style="width: 100px; height: 100px;"></p>

<pre><b>输入：</b>land = [[0]]
<b>输出：</b>[]
<b>解释：</b>
没有任何农场组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == land.length</code></li>
	<li><code>n == land[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>land</code>&nbsp;只包含&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;。</li>
	<li>农场组都是 <strong>矩形</strong>&nbsp;的形状。</li>
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
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        ans = []
        for i in range(m):
            for j in range(n):
                if (
                    land[i][j] == 0
                    or (j > 0 and land[i][j - 1] == 1)
                    or (i > 0 and land[i - 1][j] == 1)
                ):
                    continue
                x, y = i, j
                while x + 1 < m and land[x + 1][j] == 1:
                    x += 1
                while y + 1 < n and land[x][y + 1] == 1:
                    y += 1
                ans.append([i, j, x, y])
        return ans
```

#### Java

```java
class Solution {
    public int[][] findFarmland(int[][] land) {
        List<int[]> ans = new ArrayList<>();
        int m = land.length;
        int n = land[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1)
                    || (i > 0 && land[i - 1][j] == 1)) {
                    continue;
                }
                int x = i;
                int y = j;
                for (; x + 1 < m && land[x + 1][j] == 1; ++x)
                    ;
                for (; y + 1 < n && land[x][y + 1] == 1; ++y)
                    ;
                ans.add(new int[] {i, j, x, y});
            }
        }
        return ans.toArray(new int[ans.size()][4]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)) continue;
                int x = i;
                int y = j;
                for (; x + 1 < m && land[x + 1][j] == 1; ++x)
                    ;
                for (; y + 1 < n && land[x][y + 1] == 1; ++y)
                    ;
                ans.push_back({i, j, x, y});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findFarmland(land [][]int) [][]int {
	m, n := len(land), len(land[0])
	var ans [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if land[i][j] == 0 || (j > 0 && land[i][j-1] == 1) || (i > 0 && land[i-1][j] == 1) {
				continue
			}
			x, y := i, j
			for ; x+1 < m && land[x+1][j] == 1; x++ {
			}
			for ; y+1 < n && land[x][y+1] == 1; y++ {
			}
			ans = append(ans, []int{i, j, x, y})
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1993. 树上的操作](https://leetcode.cn/problems/operations-on-tree){#1993}

{{< tabs "1993" >}}

{{% tab "python" %}}
```python
class LockingTree:
    def __init__(self, parent: List[int]):
        n = len(parent)
        self.locked = [-1] * n
        self.parent = parent
        self.children = [[] for _ in range(n)]
        for son, fa in enumerate(parent[1:], 1):
            self.children[fa].append(son)

    def lock(self, num: int, user: int) -> bool:
        if self.locked[num] == -1:
            self.locked[num] = user
            return True
        return False

    def unlock(self, num: int, user: int) -> bool:
        if self.locked[num] == user:
            self.locked[num] = -1
            return True
        return False

    def upgrade(self, num: int, user: int) -> bool:
        def dfs(x: int):
            nonlocal find
            for y in self.children[x]:
                if self.locked[y] != -1:
                    self.locked[y] = -1
                    find = True
                dfs(y)

        x = num
        while x != -1:
            if self.locked[x] != -1:
                return False
            x = self.parent[x]

        find = False
        dfs(num)
        if not find:
            return False
        self.locked[num] = user
        return True


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class LockingTree {
    private int[] locked;
    private int[] parent;
    private List<Integer>[] children;

    public LockingTree(int[] parent) {
        int n = parent.length;
        locked = new int[n];
        this.parent = parent;
        children = new List[n];
        Arrays.fill(locked, -1);
        Arrays.setAll(children, i -> new ArrayList<>());
        for (int i = 1; i < n; i++) {
            children[parent[i]].add(i);
        }
    }

    public boolean lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    public boolean unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    public boolean upgrade(int num, int user) {
        int x = num;
        while (x != -1) {
            if (locked[x] != -1) {
                return false;
            }
            x = parent[x];
        }
        boolean[] find = new boolean[1];
        dfs(num, find);
        if (!find[0]) {
            return false;
        }
        locked[num] = user;
        return true;
    }

    private void dfs(int x, boolean[] find) {
        for (int y : children[x]) {
            if (locked[y] != -1) {
                locked[y] = -1;
                find[0] = true;
            }
            dfs(y, find);
        }
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree obj = new LockingTree(parent);
 * boolean param_1 = obj.lock(num,user);
 * boolean param_2 = obj.unlock(num,user);
 * boolean param_3 = obj.upgrade(num,user);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        locked = vector<int>(n, -1);
        this->parent = parent;
        children.resize(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        int x = num;
        while (x != -1) {
            if (locked[x] != -1) {
                return false;
            }
            x = parent[x];
        }
        bool find = false;
        function<void(int)> dfs = [&](int x) {
            for (int y : children[x]) {
                if (locked[y] != -1) {
                    find = true;
                    locked[y] = -1;
                }
                dfs(y);
            }
        };
        dfs(num);
        if (!find) {
            return false;
        }
        locked[num] = user;
        return true;
    }

private:
    vector<int> locked;
    vector<int> parent;
    vector<vector<int>> children;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type LockingTree struct {
	locked   []int
	parent   []int
	children [][]int
}

func Constructor(parent []int) LockingTree {
	n := len(parent)
	locked := make([]int, n)
	for i := range locked {
		locked[i] = -1
	}
	children := make([][]int, n)
	for i := 1; i < n; i++ {
		children[parent[i]] = append(children[parent[i]], i)
	}
	return LockingTree{locked, parent, children}
}

func (this *LockingTree) Lock(num int, user int) bool {
	if this.locked[num] == -1 {
		this.locked[num] = user
		return true
	}
	return false
}

func (this *LockingTree) Unlock(num int, user int) bool {
	if this.locked[num] == user {
		this.locked[num] = -1
		return true
	}
	return false
}

func (this *LockingTree) Upgrade(num int, user int) bool {
	x := num
	for ; x != -1; x = this.parent[x] {
		if this.locked[x] != -1 {
			return false
		}
	}
	find := false
	var dfs func(int)
	dfs = func(x int) {
		for _, y := range this.children[x] {
			if this.locked[y] != -1 {
				find = true
				this.locked[y] = -1
			}
			dfs(y)
		}
	}
	dfs(num)
	if !find {
		return false
	}
	this.locked[num] = user
	return true
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class LockingTree {
    private locked: number[];
    private parent: number[];
    private children: number[][];

    constructor(parent: number[]) {
        const n = parent.length;
        this.locked = Array(n).fill(-1);
        this.parent = parent;
        this.children = Array(n)
            .fill(0)
            .map(() => []);
        for (let i = 1; i < n; i++) {
            this.children[parent[i]].push(i);
        }
    }

    lock(num: number, user: number): boolean {
        if (this.locked[num] === -1) {
            this.locked[num] = user;
            return true;
        }
        return false;
    }

    unlock(num: number, user: number): boolean {
        if (this.locked[num] === user) {
            this.locked[num] = -1;
            return true;
        }
        return false;
    }

    upgrade(num: number, user: number): boolean {
        let x = num;
        for (; x !== -1; x = this.parent[x]) {
            if (this.locked[x] !== -1) {
                return false;
            }
        }
        let find = false;
        const dfs = (x: number) => {
            for (const y of this.children[x]) {
                if (this.locked[y] !== -1) {
                    this.locked[y] = -1;
                    find = true;
                }
                dfs(y);
            }
        };
        dfs(num);
        if (!find) {
            return false;
        }
        this.locked[num] = user;
        return true;
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * var obj = new LockingTree(parent)
 * var param_1 = obj.lock(num,user)
 * var param_2 = obj.unlock(num,user)
 * var param_3 = obj.upgrade(num,user)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵&nbsp;<code>n</code>&nbsp;个节点的树，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，以父节点数组&nbsp;<code>parent</code>&nbsp;的形式给出，其中&nbsp;<code>parent[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个节点的父节点。树的根节点为 <code>0</code>&nbsp;号节点，所以&nbsp;<code>parent[0] = -1</code>&nbsp;，因为它没有父节点。你想要设计一个数据结构实现树里面对节点的加锁，解锁和升级操作。</p>

<p>数据结构需要支持如下函数：</p>

<ul>
	<li><strong>Lock：</strong>指定用户给指定节点 <strong>上锁</strong>&nbsp;，上锁后其他用户将无法给同一节点上锁。只有当节点处于未上锁的状态下，才能进行上锁操作。</li>
	<li><strong>Unlock：</strong>指定用户给指定节点 <strong>解锁</strong>&nbsp;，只有当指定节点当前正被指定用户锁住时，才能执行该解锁操作。</li>
	<li><b>Upgrade：</b>指定用户给指定节点&nbsp;<strong>上锁</strong>&nbsp;，并且将该节点的所有子孙节点&nbsp;<strong>解锁</strong>&nbsp;。只有如下 3 个条件 <strong>全部</strong> 满足时才能执行升级操作：
	<ul>
		<li>指定节点当前状态为未上锁。</li>
		<li>指定节点至少有一个上锁状态的子孙节点（可以是 <strong>任意</strong>&nbsp;用户上锁的）。</li>
		<li>指定节点没有任何上锁的祖先节点。</li>
	</ul>
	</li>
</ul>

<p>请你实现&nbsp;<code>LockingTree</code>&nbsp;类：</p>

<ul>
	<li><code>LockingTree(int[] parent)</code>&nbsp;用父节点数组初始化数据结构。</li>
	<li><code>lock(int num, int user)</code> 如果&nbsp;id 为&nbsp;<code>user</code>&nbsp;的用户可以给节点&nbsp;<code>num</code>&nbsp;上锁，那么返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。如果可以执行此操作，节点&nbsp;<code>num</code>&nbsp;会被 id 为 <code>user</code>&nbsp;的用户 <strong>上锁</strong>&nbsp;。</li>
	<li><code>unlock(int num, int user)</code>&nbsp;如果 id 为 <code>user</code>&nbsp;的用户可以给节点 <code>num</code>&nbsp;解锁，那么返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。如果可以执行此操作，节点 <code>num</code>&nbsp;变为 <strong>未上锁</strong>&nbsp;状态。</li>
	<li><code>upgrade(int num, int user)</code>&nbsp;如果 id 为 <code>user</code>&nbsp;的用户可以给节点 <code>num</code>&nbsp;升级，那么返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。如果可以执行此操作，节点 <code>num</code>&nbsp;会被&nbsp;<strong>升级 </strong>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1993.Operations%20on%20Tree/images/untitled.png" style="width: 375px; height: 246px;"></p>

<pre><strong>输入：</strong>
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
<strong>输出：</strong>
[null, true, false, true, true, true, false]

<strong>解释：</strong>
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // 返回 true ，因为节点 2 未上锁。
                           // 节点 2 被用户 2 上锁。
lockingTree.unlock(2, 3);  // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。
lockingTree.unlock(2, 2);  // 返回 true ，因为节点 2 之前被用户 2 上锁。
                           // 节点 2 现在变为未上锁状态。
lockingTree.lock(4, 5);    // 返回 true ，因为节点 4 未上锁。
                           // 节点 4 被用户 5 上锁。
lockingTree.upgrade(0, 1); // 返回 true ，因为节点 0 未上锁且至少有一个被上锁的子孙节点（节点 4）。
                           // 节点 0 被用户 1 上锁，节点 4 变为未上锁。
lockingTree.lock(0, 1);    // 返回 false ，因为节点 0 已经被上锁了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parent.length</code></li>
	<li><code>2 &lt;= n &lt;= 2000</code></li>
	<li>对于&nbsp;<code>i != 0</code>&nbsp;，满足&nbsp;<code>0 &lt;= parent[i] &lt;= n - 1</code></li>
	<li><code>parent[0] == -1</code></li>
	<li><code>0 &lt;= num &lt;= n - 1</code></li>
	<li><code>1 &lt;= user &lt;= 10<sup>4</sup></code></li>
	<li><code>parent</code>&nbsp;表示一棵合法的树。</li>
	<li><code>lock</code>&nbsp;，<code>unlock</code>&nbsp;和&nbsp;<code>upgrade</code>&nbsp;的调用&nbsp;<strong>总共&nbsp;</strong>不超过&nbsp;<code>2000</code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们定义以下几个变量：

-   $locked$：记录每个节点的锁定状态，其中 $locked[i]$ 表示节点 $i$ 的锁定状态，如果节点 $i$ 未被上锁，则 $locked[i] = -1$，否则 $locked[i]$ 为锁定节点 $i$ 的用户编号。
-   $parent$：记录每个节点的父节点。
-   $children$：记录每个节点的子节点。

调用 $lock$ 函数时，如果节点 $num$ 未被上锁，则将节点 $num$ 上锁，返回 `true`，否则返回 `false`。

调用 $unlock$ 函数时，如果节点 $num$ 被上锁且上锁的用户编号为 $user$，则将节点 $num$ 解锁，返回 `true`，否则返回 `false`。

调用 $upgrade$ 函数时，我们首先判断节点 $num$ 及其祖先节点是否被上锁，如果是，则返回 $false$。否则，我们判断节点 $num$ 的子孙节点是否有被上锁的，如果没有，则返回 `false`。否则，我们将节点 $num$ 及其子孙节点解锁，然后将节点 $num$ 上锁，返回 `true`。

时间复杂度方面，初始化和 $upgrade$ 函数的时间复杂度均为 $O(n)$，而 $lock$ 和 $unlock$ 函数的时间复杂度均为 $O(1)$。空间复杂度 $O(n)$。其中 $n$ 是节点的数量。

<!-- tabs:start -->

#### Python3

```python
class LockingTree:
    def __init__(self, parent: List[int]):
        n = len(parent)
        self.locked = [-1] * n
        self.parent = parent
        self.children = [[] for _ in range(n)]
        for son, fa in enumerate(parent[1:], 1):
            self.children[fa].append(son)

    def lock(self, num: int, user: int) -> bool:
        if self.locked[num] == -1:
            self.locked[num] = user
            return True
        return False

    def unlock(self, num: int, user: int) -> bool:
        if self.locked[num] == user:
            self.locked[num] = -1
            return True
        return False

    def upgrade(self, num: int, user: int) -> bool:
        def dfs(x: int):
            nonlocal find
            for y in self.children[x]:
                if self.locked[y] != -1:
                    self.locked[y] = -1
                    find = True
                dfs(y)

        x = num
        while x != -1:
            if self.locked[x] != -1:
                return False
            x = self.parent[x]

        find = False
        dfs(num)
        if not find:
            return False
        self.locked[num] = user
        return True


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
```

#### Java

```java
class LockingTree {
    private int[] locked;
    private int[] parent;
    private List<Integer>[] children;

    public LockingTree(int[] parent) {
        int n = parent.length;
        locked = new int[n];
        this.parent = parent;
        children = new List[n];
        Arrays.fill(locked, -1);
        Arrays.setAll(children, i -> new ArrayList<>());
        for (int i = 1; i < n; i++) {
            children[parent[i]].add(i);
        }
    }

    public boolean lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    public boolean unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    public boolean upgrade(int num, int user) {
        int x = num;
        while (x != -1) {
            if (locked[x] != -1) {
                return false;
            }
            x = parent[x];
        }
        boolean[] find = new boolean[1];
        dfs(num, find);
        if (!find[0]) {
            return false;
        }
        locked[num] = user;
        return true;
    }

    private void dfs(int x, boolean[] find) {
        for (int y : children[x]) {
            if (locked[y] != -1) {
                locked[y] = -1;
                find[0] = true;
            }
            dfs(y, find);
        }
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree obj = new LockingTree(parent);
 * boolean param_1 = obj.lock(num,user);
 * boolean param_2 = obj.unlock(num,user);
 * boolean param_3 = obj.upgrade(num,user);
 */
```

#### C++

```cpp
class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        locked = vector<int>(n, -1);
        this->parent = parent;
        children.resize(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (locked[num] == -1) {
            locked[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        int x = num;
        while (x != -1) {
            if (locked[x] != -1) {
                return false;
            }
            x = parent[x];
        }
        bool find = false;
        function<void(int)> dfs = [&](int x) {
            for (int y : children[x]) {
                if (locked[y] != -1) {
                    find = true;
                    locked[y] = -1;
                }
                dfs(y);
            }
        };
        dfs(num);
        if (!find) {
            return false;
        }
        locked[num] = user;
        return true;
    }

private:
    vector<int> locked;
    vector<int> parent;
    vector<vector<int>> children;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
```

#### Go

```go
type LockingTree struct {
	locked   []int
	parent   []int
	children [][]int
}

func Constructor(parent []int) LockingTree {
	n := len(parent)
	locked := make([]int, n)
	for i := range locked {
		locked[i] = -1
	}
	children := make([][]int, n)
	for i := 1; i < n; i++ {
		children[parent[i]] = append(children[parent[i]], i)
	}
	return LockingTree{locked, parent, children}
}

func (this *LockingTree) Lock(num int, user int) bool {
	if this.locked[num] == -1 {
		this.locked[num] = user
		return true
	}
	return false
}

func (this *LockingTree) Unlock(num int, user int) bool {
	if this.locked[num] == user {
		this.locked[num] = -1
		return true
	}
	return false
}

func (this *LockingTree) Upgrade(num int, user int) bool {
	x := num
	for ; x != -1; x = this.parent[x] {
		if this.locked[x] != -1 {
			return false
		}
	}
	find := false
	var dfs func(int)
	dfs = func(x int) {
		for _, y := range this.children[x] {
			if this.locked[y] != -1 {
				find = true
				this.locked[y] = -1
			}
			dfs(y)
		}
	}
	dfs(num)
	if !find {
		return false
	}
	this.locked[num] = user
	return true
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * obj := Constructor(parent);
 * param_1 := obj.Lock(num,user);
 * param_2 := obj.Unlock(num,user);
 * param_3 := obj.Upgrade(num,user);
 */
```

#### TypeScript

```ts
class LockingTree {
    private locked: number[];
    private parent: number[];
    private children: number[][];

    constructor(parent: number[]) {
        const n = parent.length;
        this.locked = Array(n).fill(-1);
        this.parent = parent;
        this.children = Array(n)
            .fill(0)
            .map(() => []);
        for (let i = 1; i < n; i++) {
            this.children[parent[i]].push(i);
        }
    }

    lock(num: number, user: number): boolean {
        if (this.locked[num] === -1) {
            this.locked[num] = user;
            return true;
        }
        return false;
    }

    unlock(num: number, user: number): boolean {
        if (this.locked[num] === user) {
            this.locked[num] = -1;
            return true;
        }
        return false;
    }

    upgrade(num: number, user: number): boolean {
        let x = num;
        for (; x !== -1; x = this.parent[x]) {
            if (this.locked[x] !== -1) {
                return false;
            }
        }
        let find = false;
        const dfs = (x: number) => {
            for (const y of this.children[x]) {
                if (this.locked[y] !== -1) {
                    this.locked[y] = -1;
                    find = true;
                }
                dfs(y);
            }
        };
        dfs(num);
        if (!find) {
            return false;
        }
        this.locked[num] = user;
        return true;
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * var obj = new LockingTree(parent)
 * var param_1 = obj.lock(num,user)
 * var param_2 = obj.unlock(num,user)
 * var param_3 = obj.upgrade(num,user)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1994. 好子集的数目](https://leetcode.cn/problems/the-number-of-good-subsets){#1994}

{{< tabs "1994" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        cnt = Counter(nums)
        mod = 10**9 + 7
        n = len(primes)
        f = [0] * (1 << n)
        f[0] = pow(2, cnt[1])
        for x in range(2, 31):
            if cnt[x] == 0 or x % 4 == 0 or x % 9 == 0 or x % 25 == 0:
                continue
            mask = 0
            for i, p in enumerate(primes):
                if x % p == 0:
                    mask |= 1 << i
            for state in range((1 << n) - 1, 0, -1):
                if state & mask == mask:
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod
        return sum(f[i] for i in range(1, 1 << n)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfGoodSubsets(int[] nums) {
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int[] cnt = new int[31];
        for (int x : nums) {
            ++cnt[x];
        }
        final int mod = (int) 1e9 + 7;
        int n = primes.length;
        long[] f = new long[1 << n];
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = (f[0] * 2) % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state > 0; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
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
    int numberOfGoodSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt[31]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = 10;
        const int mod = 1e9 + 7;
        vector<long long> f(1 << n);
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = f[0] * 2 % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + 1LL * cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfGoodSubsets(nums []int) (ans int) {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
	cnt := [31]int{}
	for _, x := range nums {
		cnt[x]++
	}
	const mod int = 1e9 + 7
	n := 10
	f := make([]int, 1<<n)
	f[0] = 1
	for i := 0; i < cnt[1]; i++ {
		f[0] = f[0] * 2 % mod
	}
	for x := 2; x < 31; x++ {
		if cnt[x] == 0 || x%4 == 0 || x%9 == 0 || x%25 == 0 {
			continue
		}
		mask := 0
		for i, p := range primes {
			if x%p == 0 {
				mask |= 1 << i
			}
		}
		for state := 1<<n - 1; state > 0; state-- {
			if state&mask == mask {
				f[state] = (f[state] + f[state^mask]*cnt[x]) % mod
			}
		}
	}
	for i := 1; i < 1<<n; i++ {
		ans = (ans + f[i]) % mod
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。如果&nbsp;<code>nums</code>&nbsp;的一个子集中，所有元素的乘积可以表示为一个或多个 <strong>互不相同的质数</strong> 的乘积，那么我们称它为&nbsp;<strong>好子集</strong>&nbsp;。</p>

<ul>
	<li>比方说，如果&nbsp;<code>nums = [1, 2, 3, 4]</code>&nbsp;：

    <ul>
    	<li><code>[2, 3]</code>&nbsp;，<code>[1, 2, 3]</code>&nbsp;和&nbsp;<code>[1, 3]</code>&nbsp;是 <strong>好</strong>&nbsp;子集，乘积分别为&nbsp;<code>6 = 2*3</code>&nbsp;，<code>6 = 2*3</code>&nbsp;和&nbsp;<code>3 = 3</code>&nbsp;。</li>
    	<li><code>[1, 4]</code> 和&nbsp;<code>[4]</code>&nbsp;不是 <strong>好</strong>&nbsp;子集，因为乘积分别为&nbsp;<code>4 = 2*2</code> 和&nbsp;<code>4 = 2*2</code>&nbsp;。</li>
    </ul>
    </li>

</ul>

<p>请你返回 <code>nums</code>&nbsp;中不同的&nbsp;<strong>好</strong>&nbsp;子集的数目对<em>&nbsp;</em><code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。</p>

<p><code>nums</code>&nbsp;中的 <strong>子集</strong>&nbsp;是通过删除 <code>nums</code>&nbsp;中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视为不同的子集。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>6
<b>解释：</b>好子集为：
- [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,2,3,15]
<b>输出：</b>5
<b>解释：</b>好子集为：
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
- [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

注意到题目中 $nums[i]$ 的范围为 $[1, 30]$，因此我们可以预处理出所有小于等于 $30$ 的质数，即 $[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]$。

好子集中，所有元素的乘积可以表示为一个或多个互不相同的质数的乘积，也即是说，每个质因数最多只能出现一次。因此，我们可以使用一个二进制数来表示一个子集中的质因数，其中二进制数的第 $i$ 位表示质数 $primes[i]$ 是否出现在子集中。

我们可以使用状态压缩动态规划的方法来求解本题。设 $f[i]$ 表示二进制数 $i$ 表示的子集中的质因数的乘积为一个或多个互不相同的质数的乘积的方案数。初始时 $f[0]=1$。

我们在 $[2,..30]$ 的范围内枚举一个数 $x$，如果 $x$ 不在 $nums$ 中，或者 $x$ 为 $4, 9, 25$ 的倍数，那么我们可以直接跳过。否则，我们可以将 $x$ 的质因数用一个二进制数 $mask$ 表示，然后我们从大到小枚举当前的状态 $state$，如果 $state$ 与 $mask$ 按位与的结果为 $mask$，那么我们可以从状态 $f[state \oplus mask]$ 转移到状态 $f[state]$，转移方程为 $f[state] = f[state] + cnt[x] \times f[state \oplus mask]$，其中 $cnt[x]$ 表示 $x$ 在 $nums$ 中出现的次数。

注意，我们没有从数字 $1$ 开始枚举，因为我们可以选择任意个数字 $1$，加入到好子集中。那么最终的答案为 $\sum_{i=1}{2^{10}-1} f[i] \times 2^{cnt[1]}$。

时间复杂度 $O(n + C \times M)$，空间复杂度 $O(M)$。其中 $n$ 为 $nums$ 的长度；而 $C$ 和 $M$ 分别为题目中 $nums[i]$ 的范围和状态的个数，本题中 $C=30$, $M=2^{10}$。

相似题目：

-   [2572. 无平方子集计数](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2572.Count%20the%20Number%20of%20Square-Free%20Subsets/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        cnt = Counter(nums)
        mod = 10**9 + 7
        n = len(primes)
        f = [0] * (1 << n)
        f[0] = pow(2, cnt[1])
        for x in range(2, 31):
            if cnt[x] == 0 or x % 4 == 0 or x % 9 == 0 or x % 25 == 0:
                continue
            mask = 0
            for i, p in enumerate(primes):
                if x % p == 0:
                    mask |= 1 << i
            for state in range((1 << n) - 1, 0, -1):
                if state & mask == mask:
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod
        return sum(f[i] for i in range(1, 1 << n)) % mod
```

#### Java

```java
class Solution {
    public int numberOfGoodSubsets(int[] nums) {
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int[] cnt = new int[31];
        for (int x : nums) {
            ++cnt[x];
        }
        final int mod = (int) 1e9 + 7;
        int n = primes.length;
        long[] f = new long[1 << n];
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = (f[0] * 2) % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state > 0; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt[31]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = 10;
        const int mod = 1e9 + 7;
        vector<long long> f(1 << n);
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = f[0] * 2 % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + 1LL * cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfGoodSubsets(nums []int) (ans int) {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
	cnt := [31]int{}
	for _, x := range nums {
		cnt[x]++
	}
	const mod int = 1e9 + 7
	n := 10
	f := make([]int, 1<<n)
	f[0] = 1
	for i := 0; i < cnt[1]; i++ {
		f[0] = f[0] * 2 % mod
	}
	for x := 2; x < 31; x++ {
		if cnt[x] == 0 || x%4 == 0 || x%9 == 0 || x%25 == 0 {
			continue
		}
		mask := 0
		for i, p := range primes {
			if x%p == 0 {
				mask |= 1 << i
			}
		}
		for state := 1<<n - 1; state > 0; state-- {
			if state&mask == mask {
				f[state] = (f[state] + f[state^mask]*cnt[x]) % mod
			}
		}
	}
	for i := 1; i < 1<<n; i++ {
		ans = (ans + f[i]) % mod
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1995. 统计特殊四元组](https://leetcode.cn/problems/count-special-quadruplets){#1995}

{{< tabs "1995" >}}

{{% tab "python" %}}
```python
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        counter = Counter()
        for b in range(n - 3, 0, -1):
            c = b + 1
            for d in range(c + 1, n):
                counter[nums[d] - nums[c]] += 1
            for a in range(b):
                ans += counter[nums[a] + nums[b]]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        int[] counter = new int[310];
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> counter(310);
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countQuadruplets(nums []int) int {
	ans, n := 0, len(nums)
	counter := make([]int, 310)
	for b := n - 3; b > 0; b-- {
		c := b + 1
		for d := c + 1; d < n; d++ {
			if nums[d] >= nums[c] {
				counter[nums[d]-nums[c]]++
			}
		}
		for a := 0; a < b; a++ {
			ans += counter[nums[a]+nums[b]]
		}
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

<p>给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>nums</code> ，返回满足下述条件的 <strong>不同</strong> 四元组 <code>(a, b, c, d)</code> 的 <strong>数目</strong> ：</p>

<ul>
	<li><code>nums[a] + nums[b] + nums[c] == nums[d]</code> ，且</li>
	<li><code>a &lt; b &lt; c &lt; d</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,6]
<strong>输出：</strong>1
<strong>解释：</strong>满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [3,3,6,4,5]
<strong>输出：</strong>0
<strong>解释：</strong>[3,3,6,4,5] 中不存在满足要求的四元组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,3,5]
<strong>输出：</strong>4
<strong>解释：</strong>满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
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
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for a in range(n - 3):
            for b in range(a + 1, n - 2):
                for c in range(b + 1, n - 1):
                    for d in range(c + 1, n):
                        if nums[a] + nums[b] + nums[c] == nums[d]:
                            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        for (int a = 0; a < n - 3; ++a) {
            for (int b = a + 1; b < n - 2; ++b) {
                for (int c = b + 1; c < n - 1; ++c) {
                    for (int d = c + 1; d < n; ++d) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            ++ans;
                        }
                    }
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int a = 0; a < n - 3; ++a)
            for (int b = a + 1; b < n - 2; ++b)
                for (int c = b + 1; c < n - 1; ++c)
                    for (int d = c + 1; d < n; ++d)
                        if (nums[a] + nums[b] + nums[c] == nums[d]) ++ans;
        return ans;
    }
};
```

#### Go

```go
func countQuadruplets(nums []int) int {
	ans, n := 0, len(nums)
	for a := 0; a < n-3; a++ {
		for b := a + 1; b < n-2; b++ {
			for c := b + 1; c < n-1; c++ {
				for d := c + 1; d < n; d++ {
					if nums[a]+nums[b]+nums[c] == nums[d] {
						ans++
					}
				}
			}
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
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        counter = Counter()
        for c in range(n - 2, 1, -1):
            counter[nums[c + 1]] += 1
            for a in range(c - 1):
                for b in range(a + 1, c):
                    ans += counter[nums[a] + nums[b] + nums[c]]
        return ans
```

#### Java

```java
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        int[] counter = new int[310];
        for (int c = n - 2; c > 1; --c) {
            ++counter[nums[c + 1]];
            for (int a = 0; a < c - 1; ++a) {
                for (int b = a + 1; b < c; ++b) {
                    ans += counter[nums[a] + nums[b] + nums[c]];
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> counter(310);
        for (int c = n - 2; c > 1; --c) {
            ++counter[nums[c + 1]];
            for (int a = 0; a < c - 1; ++a) {
                for (int b = a + 1; b < c; ++b) {
                    ans += counter[nums[a] + nums[b] + nums[c]];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countQuadruplets(nums []int) int {
	ans, n := 0, len(nums)
	counter := make([]int, 310)
	for c := n - 2; c > 1; c-- {
		counter[nums[c+1]]++
		for a := 0; a < c-1; a++ {
			for b := a + 1; b < c; b++ {
				ans += counter[nums[a]+nums[b]+nums[c]]
			}
		}
	}
	return ans
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
    def countQuadruplets(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        counter = Counter()
        for b in range(n - 3, 0, -1):
            c = b + 1
            for d in range(c + 1, n):
                counter[nums[d] - nums[c]] += 1
            for a in range(b):
                ans += counter[nums[a] + nums[b]]
        return ans
```

#### Java

```java
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0, n = nums.length;
        int[] counter = new int[310];
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
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
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> counter(310);
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                if (nums[d] - nums[c] >= 0) {
                    ++counter[nums[d] - nums[c]];
                }
            }
            for (int a = 0; a < b; ++a) {
                ans += counter[nums[a] + nums[b]];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countQuadruplets(nums []int) int {
	ans, n := 0, len(nums)
	counter := make([]int, 310)
	for b := n - 3; b > 0; b-- {
		c := b + 1
		for d := c + 1; d < n; d++ {
			if nums[d] >= nums[c] {
				counter[nums[d]-nums[c]]++
			}
		}
		for a := 0; a < b; a++ {
			ans += counter[nums[a]+nums[b]]
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1996. 游戏中弱角色的数量](https://leetcode.cn/problems/the-number-of-weak-characters-in-the-game){#1996}

{{< tabs "1996" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))
        ans = mx = 0
        for _, x in properties:
            ans += x < mx
            mx = max(mx, x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        Arrays.sort(properties, (a, b) -> b[0] - a[0] == 0 ? a[1] - b[1] : b[0] - a[0]);
        int ans = 0, mx = 0;
        for (var x : properties) {
            if (x[1] < mx) {
                ++ans;
            }
            mx = Math.max(mx, x[1]);
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
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
        int ans = 0, mx = 0;
        for (auto& x : properties) {
            ans += x[1] < mx;
            mx = max(mx, x[1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWeakCharacters(properties [][]int) (ans int) {
	sort.Slice(properties, func(i, j int) bool {
		a, b := properties[i], properties[j]
		if a[0] == b[0] {
			return a[1] < b[1]
		}
		return a[0] > b[0]
	})
	mx := 0
	for _, x := range properties {
		if x[1] < mx {
			ans++
		} else {
			mx = x[1]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWeakCharacters(properties: number[][]): number {
    properties.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    let ans = 0;
    let mx = 0;
    for (const [, x] of properties) {
        if (x < mx) {
            ans++;
        } else {
            mx = x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} properties
 * @return {number}
 */
var numberOfWeakCharacters = function (properties) {
    properties.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    let ans = 0;
    let mx = 0;
    for (const [, x] of properties) {
        if (x < mx) {
            ans++;
        } else {
            mx = x;
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

<p>你正在参加一个多角色游戏，每个角色都有两个主要属性：<strong>攻击</strong> 和 <strong>防御</strong> 。给你一个二维整数数组 <code>properties</code> ，其中 <code>properties[i] = [attack<sub>i</sub>, defense<sub>i</sub>]</code> 表示游戏中第 <code>i</code> 个角色的属性。</p>

<p>如果存在一个其他角色的攻击和防御等级 <strong>都严格高于</strong> 该角色的攻击和防御等级，则认为该角色为 <strong>弱角色</strong> 。更正式地，如果认为角色 <code>i</code> <strong>弱于</strong> 存在的另一个角色 <code>j</code> ，那么 <code>attack<sub>j</sub> &gt; attack<sub>i</sub></code> 且 <code>defense<sub>j</sub> &gt; defense<sub>i</sub></code> 。</p>

<p>返回 <strong>弱角色</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>properties = [[5,5],[6,3],[3,6]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在攻击和防御都严格高于其他角色的角色。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>properties = [[2,2],[3,3]]
<strong>输出：</strong>1
<strong>解释：</strong>第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>properties = [[1,5],[10,4],[4,3]]
<strong>输出：</strong>1
<strong>解释：</strong>第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= properties.length &lt;= 10<sup>5</sup></code></li>
	<li><code>properties[i].length == 2</code></li>
	<li><code>1 &lt;= attack<sub>i</sub>, defense<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 遍历

我们可以将所有角色按照攻击力降序排序，防御力升序排序。

然后遍历所有角色，对于当前角色，如果其防御力小于之前的最大防御力，则说明其为弱角色，答案加一，否则更新最大防御力。

遍历结束后，即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为角色数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))
        ans = mx = 0
        for _, x in properties:
            ans += x < mx
            mx = max(mx, x)
        return ans
```

#### Java

```java
class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        Arrays.sort(properties, (a, b) -> b[0] - a[0] == 0 ? a[1] - b[1] : b[0] - a[0]);
        int ans = 0, mx = 0;
        for (var x : properties) {
            if (x[1] < mx) {
                ++ans;
            }
            mx = Math.max(mx, x[1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
        int ans = 0, mx = 0;
        for (auto& x : properties) {
            ans += x[1] < mx;
            mx = max(mx, x[1]);
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfWeakCharacters(properties [][]int) (ans int) {
	sort.Slice(properties, func(i, j int) bool {
		a, b := properties[i], properties[j]
		if a[0] == b[0] {
			return a[1] < b[1]
		}
		return a[0] > b[0]
	})
	mx := 0
	for _, x := range properties {
		if x[1] < mx {
			ans++
		} else {
			mx = x[1]
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfWeakCharacters(properties: number[][]): number {
    properties.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    let ans = 0;
    let mx = 0;
    for (const [, x] of properties) {
        if (x < mx) {
            ans++;
        } else {
            mx = x;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} properties
 * @return {number}
 */
var numberOfWeakCharacters = function (properties) {
    properties.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    let ans = 0;
    let mx = 0;
    for (const [, x] of properties) {
        if (x < mx) {
            ans++;
        } else {
            mx = x;
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

# [1997. 访问完所有房间的第一天](https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms){#1997}

{{< tabs "1997" >}}

{{% tab "python" %}}
```python
class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        n = len(nextVisit)
        f = [0] * n
        mod = 10**9 + 7
        for i in range(1, n):
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1) % mod
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int firstDayBeenInAllRooms(int[] nextVisit) {
        int n = nextVisit.length;
        long[] f = new long[n];
        final int mod = (int) 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return (int) f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> f(n);
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func firstDayBeenInAllRooms(nextVisit []int) int {
	n := len(nextVisit)
	f := make([]int, n)
	const mod = 1e9 + 7
	for i := 1; i < n; i++ {
		f[i] = (f[i-1] + 1 + f[i-1] - f[nextVisit[i-1]] + 1 + mod) % mod
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function firstDayBeenInAllRooms(nextVisit: number[]): number {
    const n = nextVisit.length;
    const mod = 1e9 + 7;
    const f: number[] = new Array<number>(n).fill(0);
    for (let i = 1; i < n; ++i) {
        f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
    }
    return f[n - 1];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FirstDayBeenInAllRooms(int[] nextVisit) {
        int n = nextVisit.Length;
        long[] f = new long[n];
        int mod = (int)1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return (int)f[n - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要访问&nbsp;<code>n</code> 个房间，房间从 <code>0</code> 到 <code>n - 1</code> 编号。同时，每一天都有一个日期编号，从 <code>0</code> 开始，依天数递增。你每天都会访问一个房间。</p>

<p>最开始的第 <code>0</code> 天，你访问&nbsp;<code>0</code> 号房间。给你一个长度为 <code>n</code> 且 <strong>下标从 0 开始</strong> 的数组 <code>nextVisit</code> 。在接下来的几天中，你访问房间的 <strong>次序</strong> 将根据下面的 <strong>规则</strong> 决定：</p>

<ul>
	<li>假设某一天，你访问&nbsp;<code>i</code> 号房间。</li>
	<li>如果算上本次访问，访问&nbsp;<code>i</code> 号房间的次数为 <strong>奇数</strong> ，那么 <strong>第二天</strong> 需要访问&nbsp;<code>nextVisit[i]</code> 所指定的房间，其中 <code>0 &lt;= nextVisit[i] &lt;= i</code> 。</li>
	<li>如果算上本次访问，访问&nbsp;<code>i</code> 号房间的次数为 <strong>偶数</strong> ，那么 <strong>第二天</strong> 需要访问&nbsp;<code>(i + 1) mod n</code> 号房间。</li>
</ul>

<p>请返回你访问完所有房间的第一天的日期编号。题目数据保证总是存在这样的一天。由于答案可能很大，返回对 <code>10<sup>9</sup> + 7</code> 取余后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,0]
<strong>输出：</strong>2
<strong>解释：</strong>
- 第 0 天，你访问房间 0 。访问 0 号房间的总次数为 1 ，次数为奇数。
&nbsp; 下一天你需要访问房间的编号是 nextVisit[0] = 0
- 第 1 天，你访问房间 0 。访问 0 号房间的总次数为 2 ，次数为偶数。
&nbsp; 下一天你需要访问房间的编号是 (0 + 1) mod 2 = 1
- 第 2 天，你访问房间 1 。这是你第一次完成访问所有房间的那天。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,0,2]
<strong>输出：</strong>6
<strong>解释：</strong>
你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
第 6 天是你访问完所有房间的第一天。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,1,2,0]
<strong>输出：</strong>6
<strong>解释：</strong>
你每天访问房间的次序是 [0,0,1,1,2,2,3,...] 。
第 6 天是你访问完所有房间的第一天。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nextVisit.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nextVisit[i] &lt;= i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示第一次访问第 $i$ 号房间的日期编号，那么答案就是 $f[n - 1]$。

我们考虑第一次到达第 $i-1$ 号房间的日期编号，记为 $f[i-1]$，此时需要花一天的时间回退到第 $nextVisit[i-1]$ 号房间，为什么是回退呢？因为题目限制了 $0 \leq nextVisit[i] \leq i$。

回退之后，此时第 $nextVisit[i-1]$ 号房间的访问为奇数次，而第 $[nextVisit[i-1]+1,..i-1]$ 号房间均被访问偶数次，那么这时候我们从第 $nextVisit[i-1]$ 号房间再次走到第 $i-1$ 号房间，就需要花费 $f[i-1] - f[nextVisit[i-1]]$ 天的时间，然后再花费一天的时间到达第 $i$ 号房间，因此 $f[i] = f[i-1] + 1 + f[i-1] - f[nextVisit[i-1]] + 1$。由于 $f[i]$ 可能很大，因此需要对 $10^9 + 7$ 取余，并且为了防止负数，需要加上 $10^9 + 7$。

最后返回 $f[n-1]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为房间数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        n = len(nextVisit)
        f = [0] * n
        mod = 10**9 + 7
        for i in range(1, n):
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1) % mod
        return f[-1]
```

#### Java

```java
class Solution {
    public int firstDayBeenInAllRooms(int[] nextVisit) {
        int n = nextVisit.length;
        long[] f = new long[n];
        final int mod = (int) 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return (int) f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> f(n);
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func firstDayBeenInAllRooms(nextVisit []int) int {
	n := len(nextVisit)
	f := make([]int, n)
	const mod = 1e9 + 7
	for i := 1; i < n; i++ {
		f[i] = (f[i-1] + 1 + f[i-1] - f[nextVisit[i-1]] + 1 + mod) % mod
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function firstDayBeenInAllRooms(nextVisit: number[]): number {
    const n = nextVisit.length;
    const mod = 1e9 + 7;
    const f: number[] = new Array<number>(n).fill(0);
    for (let i = 1; i < n; ++i) {
        f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
    }
    return f[n - 1];
}
```

#### C#

```cs
public class Solution {
    public int FirstDayBeenInAllRooms(int[] nextVisit) {
        int n = nextVisit.Length;
        long[] f = new long[n];
        int mod = (int)1e9 + 7;
        for (int i = 1; i < n; ++i) {
            f[i] = (f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return (int)f[n - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array){#1998}

{{< tabs "1998" >}}

{{% tab "python" %}}
```python
class Solution:
    def gcdSort(self, nums: List[int]) -> bool:
        n = 10**5 + 10
        p = list(range(n))
        f = defaultdict(list)
        mx = max(nums)
        for i in range(2, mx + 1):
            if f[i]:
                continue
            for j in range(i, mx + 1, i):
                f[j].append(i)

        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        for i in nums:
            for j in f[i]:
                p[find(i)] = find(j)

        s = sorted(nums)
        for i, num in enumerate(nums):
            if s[i] != num and find(num) != find(s[i]):
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean gcdSort(int[] nums) {
        int n = 100010;
        p = new int[n];
        Map<Integer, List<Integer>> f = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int mx = 0;
        for (int num : nums) {
            mx = Math.max(mx, num);
        }
        for (int i = 2; i <= mx; ++i) {
            if (f.containsKey(i)) {
                continue;
            }
            for (int j = i; j <= mx; j += i) {
                f.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
            }
        }
        for (int i : nums) {
            for (int j : f.get(i)) {
                p[find(i)] = find(j);
            }
        }
        int[] s = new int[nums.length];
        System.arraycopy(nums, 0, s, 0, nums.length);
        Arrays.sort(s);
        for (int i = 0; i < nums.length; ++i) {
            if (s[i] != nums[i] && find(nums[i]) != find(s[i])) {
                return false;
            }
        }
        return true;
    }

    int find(int x) {
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
    vector<int> p;

    bool gcdSort(vector<int>& nums) {
        int n = 100010;
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int mx = 0;
        for (auto num : nums) mx = max(mx, num);
        unordered_map<int, vector<int>> f;
        for (int i = 2; i <= mx; ++i) {
            if (!f[i].empty()) continue;
            for (int j = i; j <= mx; j += i) f[j].push_back(i);
        }
        for (int i : nums) {
            for (int j : f[i]) p[find(i)] = find(j);
        }
        vector<int> s = nums;
        sort(s.begin(), s.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (s[i] != nums[i] && find(s[i]) != find(nums[i])) return false;
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var p []int

func gcdSort(nums []int) bool {
	n := 100010
	p = make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
	}
	mx := 0
	for _, num := range nums {
		mx = max(mx, num)
	}
	f := make([][]int, mx+1)
	for i := 2; i <= mx; i++ {
		if len(f[i]) > 0 {
			continue
		}
		for j := i; j <= mx; j += i {
			f[j] = append(f[j], i)
		}
	}
	for _, i := range nums {
		for _, j := range f[i] {
			p[find(i)] = find(j)
		}
	}
	s := make([]int, len(nums))
	for i, num := range nums {
		s[i] = num
	}
	sort.Ints(s)
	for i, num := range nums {
		if s[i] != num && find(s[i]) != find(num) {
			return false
		}
	}
	return true
}

func find(x int) int {
	if p[x] != x {
		p[x] = find(p[x])
	}
	return p[x]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，你可以在 <code>nums</code> 上执行下述操作 <strong>任意次</strong> ：</p>

<ul>
	<li>如果 <code>gcd(nums[i], nums[j]) &gt; 1</code> ，交换 <code>nums[i]</code> 和 <code>nums[j]</code> 的位置。其中 <code>gcd(nums[i], nums[j])</code> 是&nbsp;<code>nums[i]</code> 和 <code>nums[j]</code> 的最大公因数。</li>
</ul>

<p>如果能使用上述交换方式将 <code>nums</code> 按 <strong>非递减顺序</strong> 排列，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,21,3]
<strong>输出：</strong>true
<strong>解释：</strong>可以执行下述操作完成对 [7,21,3] 的排序：
- 交换 7 和 21 因为 gcd(7,21) = 7 。nums = [<u><strong>21</strong></u>,<u><strong>7</strong></u>,3]
- 交换 21 和 3 因为 gcd(21,3) = 3 。nums = [<u><strong>3</strong></u>,7,<u><strong>21</strong></u>]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,6,2]
<strong>输出：</strong>false
<strong>解释：</strong>无法完成排序，因为 5 不能与其他元素交换。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,5,9,3,15]
<strong>输出：</strong>true
<strong>解释：</strong>
可以执行下述操作完成对 [10,5,9,3,15] 的排序：
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [<u><strong>15</strong></u>,5,9,3,<u><strong>10</strong></u>]
- 交换 15 和 3 因为 gcd(15,3) = 3 。nums = [<u><strong>3</strong></u>,5,9,<u><strong>15</strong></u>,10]
- 交换 10 和 15 因为 gcd(10,15) = 5 。nums = [3,5,9,<u><strong>10</strong></u>,<u><strong>15</strong></u>]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
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
    def gcdSort(self, nums: List[int]) -> bool:
        n = 10**5 + 10
        p = list(range(n))
        f = defaultdict(list)
        mx = max(nums)
        for i in range(2, mx + 1):
            if f[i]:
                continue
            for j in range(i, mx + 1, i):
                f[j].append(i)

        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        for i in nums:
            for j in f[i]:
                p[find(i)] = find(j)

        s = sorted(nums)
        for i, num in enumerate(nums):
            if s[i] != num and find(num) != find(s[i]):
                return False
        return True
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean gcdSort(int[] nums) {
        int n = 100010;
        p = new int[n];
        Map<Integer, List<Integer>> f = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int mx = 0;
        for (int num : nums) {
            mx = Math.max(mx, num);
        }
        for (int i = 2; i <= mx; ++i) {
            if (f.containsKey(i)) {
                continue;
            }
            for (int j = i; j <= mx; j += i) {
                f.computeIfAbsent(j, k -> new ArrayList<>()).add(i);
            }
        }
        for (int i : nums) {
            for (int j : f.get(i)) {
                p[find(i)] = find(j);
            }
        }
        int[] s = new int[nums.length];
        System.arraycopy(nums, 0, s, 0, nums.length);
        Arrays.sort(s);
        for (int i = 0; i < nums.length; ++i) {
            if (s[i] != nums[i] && find(nums[i]) != find(s[i])) {
                return false;
            }
        }
        return true;
    }

    int find(int x) {
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
    vector<int> p;

    bool gcdSort(vector<int>& nums) {
        int n = 100010;
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int mx = 0;
        for (auto num : nums) mx = max(mx, num);
        unordered_map<int, vector<int>> f;
        for (int i = 2; i <= mx; ++i) {
            if (!f[i].empty()) continue;
            for (int j = i; j <= mx; j += i) f[j].push_back(i);
        }
        for (int i : nums) {
            for (int j : f[i]) p[find(i)] = find(j);
        }
        vector<int> s = nums;
        sort(s.begin(), s.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (s[i] != nums[i] && find(s[i]) != find(nums[i])) return false;
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```

#### Go

```go
var p []int

func gcdSort(nums []int) bool {
	n := 100010
	p = make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
	}
	mx := 0
	for _, num := range nums {
		mx = max(mx, num)
	}
	f := make([][]int, mx+1)
	for i := 2; i <= mx; i++ {
		if len(f[i]) > 0 {
			continue
		}
		for j := i; j <= mx; j += i {
			f[j] = append(f[j], i)
		}
	}
	for _, i := range nums {
		for _, j := range f[i] {
			p[find(i)] = find(j)
		}
	}
	s := make([]int, len(nums))
	for i, num := range nums {
		s[i] = num
	}
	sort.Ints(s)
	for i, num := range nums {
		if s[i] != num && find(s[i]) != find(num) {
			return false
		}
	}
	return true
}

func find(x int) int {
	if p[x] != x {
		p[x] = find(p[x])
	}
	return p[x]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1999. 最小的仅由两个数组成的倍数 🔒](https://leetcode.cn/problems/smallest-greater-multiple-made-of-two-digits){#1999}

{{< tabs "1999" >}}

{{% tab "python" %}}
```python
class Solution:
    def findInteger(self, k: int, digit1: int, digit2: int) -> int:
        if digit1 == 0 and digit2 == 0:
            return -1
        if digit1 > digit2:
            return self.findInteger(k, digit2, digit1)
        q = deque([0])
        while 1:
            x = q.popleft()
            if x > 2**31 - 1:
                return -1
            if x > k and x % k == 0:
                return x
            q.append(x * 10 + digit1)
            if digit1 != digit2:
                q.append(x * 10 + digit2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0) {
            return -1;
        }
        if (digit1 > digit2) {
            return findInteger(k, digit2, digit1);
        }
        Deque<Long> q = new ArrayDeque<>();
        q.offer(0L);
        while (true) {
            long x = q.poll();
            if (x > Integer.MAX_VALUE) {
                return -1;
            }
            if (x > k && x % k == 0) {
                return (int) x;
            }
            q.offer(x * 10 + digit1);
            if (digit1 != digit2) {
                q.offer(x * 10 + digit2);
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
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0) {
            return -1;
        }
        if (digit1 > digit2) {
            swap(digit1, digit2);
        }
        queue<long long> q{{0}};
        while (1) {
            long long x = q.front();
            q.pop();
            if (x > INT_MAX) {
                return -1;
            }
            if (x > k && x % k == 0) {
                return x;
            }
            q.emplace(x * 10 + digit1);
            if (digit1 != digit2) {
                q.emplace(x * 10 + digit2);
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findInteger(k int, digit1 int, digit2 int) int {
	if digit1 == 0 && digit2 == 0 {
		return -1
	}
	if digit1 > digit2 {
		digit1, digit2 = digit2, digit1
	}
	q := []int{0}
	for {
		x := q[0]
		q = q[1:]
		if x > math.MaxInt32 {
			return -1
		}
		if x > k && x%k == 0 {
			return x
		}
		q = append(q, x*10+digit1)
		if digit1 != digit2 {
			q = append(q, x*10+digit2)
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

<p>给你三个整数, <code>k</code>, <code>digit1</code>和&nbsp;<code>digit2</code>, 你想要找到满足以下条件的 <strong>最小 </strong>整数：</p>

<ul>
	<li><span style=""><b>大于</b></span><code>k</code> 且是 <code>k</code> 的<strong>倍数</strong></li>
	<li><strong>仅由</strong><code>digit1</code> <span style="">和 </span><code>digit2</code> 组成，即 <strong>每一位数 </strong>均是 <code>digit1</code> 或 <code>digit2</code></li>
</ul>

<p>请你返回<strong> </strong><strong>最小的满足这两个条件的整数</strong>，如果不存在这样的整数，或者最小的满足这两个条件的整数不在32位整数范围（0~<code>2<sup>31</sup>-1</code>），就返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 2, digit1 = 0, digit2 = 2
<strong>输出：</strong>20
<strong>解释：</strong>
20 是第一个仅有数字0和2组成的，比2大且是2的倍数的整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 3, digit1 = 4, digit2 = 2
<strong>输出：</strong>24
<strong>解释：</strong>
24 是第一个仅有数字 2 和 4 组成的，比 3 大且是 3 的倍数的整数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>k = 2, digit1 = 0, digit2 = 0
<strong>输出：</strong>-1
<strong>解释：
</strong>不存在仅由 0 组成的比 2 大且是 2 的倍数的整数，因此返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>0 &lt;= digit1 &lt;= 9</code></li>
	<li><code>0 &lt;= digit2 &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们观察 $k$ 的范围，发现 $1 \leq k \leq 1000$，因此，如果 $digit1$ 和 $digit2$ 都为 $0$，那么一定不存在满足条件的整数，直接返回 $-1$ 即可。

否则，我们不妨设 $digit1 \leq digit2$，接下来我们可以使用 BFS 的方法，初始时将整数 $0$ 入队，然后不断地从队首取出一个整数 $x$，如果 $x \gt 2^{31} - 1$，那么说明不存在满足条件的整数，直接返回 $-1$ 即可。如果 $x \gt k$ 且 $x \bmod k = 0$，那么说明找到了满足条件的整数，直接返回 $x$ 即可。否则，我们将其乘以 $10$ 后加上 $digit1$ 和 $digit2$，并将这两个整数入队，继续进行搜索。

时间复杂度 $(\log_{10} M)$，空间复杂度 $O(\log_{10} M)$，其中 $M$ 为 $2^{31} - 1$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findInteger(self, k: int, digit1: int, digit2: int) -> int:
        if digit1 == 0 and digit2 == 0:
            return -1
        if digit1 > digit2:
            return self.findInteger(k, digit2, digit1)
        q = deque([0])
        while 1:
            x = q.popleft()
            if x > 2**31 - 1:
                return -1
            if x > k and x % k == 0:
                return x
            q.append(x * 10 + digit1)
            if digit1 != digit2:
                q.append(x * 10 + digit2)
```

#### Java

```java
class Solution {
    public int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0) {
            return -1;
        }
        if (digit1 > digit2) {
            return findInteger(k, digit2, digit1);
        }
        Deque<Long> q = new ArrayDeque<>();
        q.offer(0L);
        while (true) {
            long x = q.poll();
            if (x > Integer.MAX_VALUE) {
                return -1;
            }
            if (x > k && x % k == 0) {
                return (int) x;
            }
            q.offer(x * 10 + digit1);
            if (digit1 != digit2) {
                q.offer(x * 10 + digit2);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0) {
            return -1;
        }
        if (digit1 > digit2) {
            swap(digit1, digit2);
        }
        queue<long long> q{{0}};
        while (1) {
            long long x = q.front();
            q.pop();
            if (x > INT_MAX) {
                return -1;
            }
            if (x > k && x % k == 0) {
                return x;
            }
            q.emplace(x * 10 + digit1);
            if (digit1 != digit2) {
                q.emplace(x * 10 + digit2);
            }
        }
    }
};
```

#### Go

```go
func findInteger(k int, digit1 int, digit2 int) int {
	if digit1 == 0 && digit2 == 0 {
		return -1
	}
	if digit1 > digit2 {
		digit1, digit2 = digit2, digit1
	}
	q := []int{0}
	for {
		x := q[0]
		q = q[1:]
		if x > math.MaxInt32 {
			return -1
		}
		if x > k && x%k == 0 {
			return x
		}
		q = append(q, x*10+digit1)
		if digit1 != digit2 {
			q = append(q, x*10+digit2)
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

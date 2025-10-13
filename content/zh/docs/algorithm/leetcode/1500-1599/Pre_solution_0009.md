---
title: "1580_把箱子放进仓库里 II 🔒"
date: 2025-10-08T18:37:33+08:00
weight: 9
tags: [二叉搜索树, 二叉树, 前缀和, 图, 字符串, 并查集, 排序, 数学, 数据库, 数组, 最小生成树, 栈, 树, 模拟, 矩阵, 设计, 贪心, 迭代器]
---

{{< markmap >}}
### [1580_把箱子放进仓库里 II 🔒](#1580)
#### [贪心](#1580)
#### [数组](#1580)
#### [排序](#1580)
### [1581_进店却未进行过交易的顾客](#1581)
#### [数据库](#1581)
### [1582_二进制矩阵中的特殊位置](#1582)
#### [数组](#1582)
#### [矩阵](#1582)
### [1583_统计不开心的朋友](#1583)
#### [数组](#1583)
#### [模拟](#1583)
### [1584_连接所有点的最小费用](#1584)
#### [并查集](#1584)
#### [图](#1584)
#### [数组](#1584)
#### [最小生成树](#1584)
### [1585_检查字符串是否可以通过排序子字符串得到另一个字符串](#1585)
#### [贪心](#1585)
#### [字符串](#1585)
#### [排序](#1585)
### [1586_二叉搜索树迭代器 II 🔒](#1586)
#### [栈](#1586)
#### [树](#1586)
#### [设计](#1586)
#### [二叉搜索树](#1586)
#### [二叉树](#1586)
#### [迭代器](#1586)
### [1587_银行账户概要 II](#1587)
#### [数据库](#1587)
### [1588_所有奇数长度子数组的和](#1588)
#### [数组](#1588)
#### [数学](#1588)
#### [前缀和](#1588)
### [1589_所有排列中的最大和](#1589)
#### [贪心](#1589)
#### [数组](#1589)
#### [前缀和](#1589)
#### [排序](#1589)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1580_把箱子放进仓库里 II 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1581_进店却未进行过交易的顾客
___
#### 数据库
---
### 1582_二进制矩阵中的特殊位置
___
#### 数组
___
#### 矩阵
---
### 1583_统计不开心的朋友
___
#### 数组
___
#### 模拟
---
### 1584_连接所有点的最小费用
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 最小生成树
---
### 1585_检查字符串是否可以通过排序子字符串得到另一个字符串
___
#### 贪心
___
#### 字符串
___
#### 排序
---
### 1586_二叉搜索树迭代器 II 🔒
___
#### 栈
___
#### 树
___
#### 设计
___
#### 二叉搜索树
___
#### 二叉树
___
#### 迭代器
---
### 1587_银行账户概要 II
___
#### 数据库
---
### 1588_所有奇数长度子数组的和
___
#### 数组
___
#### 数学
___
#### 前缀和
---
### 1589_所有排列中的最大和
___
#### 贪心
___
#### 数组
___
#### 前缀和
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 前缀和 |
| 图 | 字符串 | 并查集 |
| 排序 | 数学 | 数据库 |
| 数组 | 最小生成树 | 栈 |
| 树 | 模拟 | 矩阵 |
| 设计 | 贪心 | 迭代器 |

# [1580. 把箱子放进仓库里 II 🔒](https://leetcode.cn/problems/put-boxes-into-the-warehouse-ii){#1580}

{{< tabs "1580" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        n = len(warehouse)
        left = [0] * n
        right = [0] * n
        left[0] = right[-1] = inf
        for i in range(1, n):
            left[i] = min(left[i - 1], warehouse[i - 1])
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], warehouse[i + 1])
        for i in range(n):
            warehouse[i] = min(warehouse[i], max(left[i], right[i]))
        boxes.sort()
        warehouse.sort()
        ans = i = 0
        for x in boxes:
            while i < n and warehouse[i] < x:
                i += 1
            if i == n:
                break
            ans, i = ans + 1, i + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int[] left = new int[n];
        int[] right = new int[n];
        final int inf = 1 << 30;
        left[0] = inf;
        right[n - 1] = inf;
        for (int i = 1; i < n; ++i) {
            left[i] = Math.min(left[i - 1], warehouse[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], warehouse[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            warehouse[i] = Math.min(warehouse[i], Math.max(left[i], right[i]));
        }
        Arrays.sort(boxes);
        Arrays.sort(warehouse);
        int ans = 0, i = 0;
        for (int x : boxes) {
            while (i < n && warehouse[i] < x) {
                ++i;
            }
            if (i == n) {
                break;
            }
            ++ans;
            ++i;
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
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        const int inf = 1 << 30;
        vector<int> left(n, inf);
        vector<int> right(n, inf);
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], warehouse[i - 1]);
        }
        for (int i = n - 2; ~i; --i) {
            right[i] = min(right[i + 1], warehouse[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            warehouse[i] = min(warehouse[i], max(left[i], right[i]));
        }
        sort(boxes.begin(), boxes.end());
        sort(warehouse.begin(), warehouse.end());
        int ans = 0;
        int i = 0;
        for (int x : boxes) {
            while (i < n && warehouse[i] < x) {
                ++i;
            }
            if (i == n) {
                break;
            }
            ++ans;
            ++i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxBoxesInWarehouse(boxes []int, warehouse []int) (ans int) {
	n := len(warehouse)
	left := make([]int, n)
	right := make([]int, n)
	const inf = 1 << 30
	left[0] = inf
	right[n-1] = inf
	for i := 1; i < n; i++ {
		left[i] = min(left[i-1], warehouse[i-1])
	}
	for i := n - 2; i >= 0; i-- {
		right[i] = min(right[i+1], warehouse[i+1])
	}
	for i := 0; i < n; i++ {
		warehouse[i] = min(warehouse[i], max(left[i], right[i]))
	}
	sort.Ints(boxes)
	sort.Ints(warehouse)
	i := 0
	for _, x := range boxes {
		for i < n && warehouse[i] < x {
			i++
		}
		if i == n {
			break
		}
		ans++
		i++
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

<p>给定两个正整数数组 <code>boxes</code> 和 <code>warehouse</code> ，分别包含单位宽度的箱子的高度，以及仓库中<code>n</code>个房间各自的高度。仓库的房间分别从<code>0</code> 到 <code>n - 1</code>自左向右编号，<code>warehouse[i]</code>（索引从 0 开始）是第 <code>i</code> 个房间的高度。</p>

<p>箱子放进仓库时遵循下列规则：</p>

<ul>
	<li>箱子不可叠放。</li>
	<li>你可以重新调整箱子的顺序。</li>
	<li>箱子可以从任意方向（左边或右边）推入仓库中。</li>
	<li>如果仓库中某房间的高度小于某箱子的高度，则这个箱子和之后的箱子都会停在这个房间的前面。</li>
</ul>

<p>你最多可以在仓库中放进多少个箱子？</p>

<p> </p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1580.Put%20Boxes%20Into%20the%20Warehouse%20II/images/22.png" style="width: 401px; height: 202px;" />
<pre>
<strong>输入:</strong> boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
<strong>输出:</strong> 4
<strong>解释:
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1580.Put%20Boxes%20Into%20the%20Warehouse%20II/images/22-1.png" style="width: 240px; height: 202px;" />
</strong>我们可以按如下顺序推入箱子:
1- 从左边或右边把黄色箱子推入2号房间；
2- 从右边把橙色箱子推入3号房间；
3- 从左边把绿色箱子推入1号房间；
4- 从左边把红色箱子推入0号房间；
还有其他方式推入4个箱子，比如交换红色与绿色箱子，或者交换红色与橙色箱子。
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1580.Put%20Boxes%20Into%20the%20Warehouse%20II/images/22-2.png" style="width: 401px; height: 242px;" />
<pre>
<strong>输入:</strong> boxes = [3,5,5,2], warehouse = [2,1,3,4,5]
<strong>输出:</strong> 3
<strong>解释:
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1580.Put%20Boxes%20Into%20the%20Warehouse%20II/images/22-3.png" style="width: 280px; height: 242px;" />
</strong>因为只有一个高度大于等于5的房间，所以无法将两个高度为5的箱子都推入仓库。
还有其他方式推入箱子，比如将绿色箱子推入2号房间，或者在绿色及红色箱子之前将橙色箱子推入2号房间。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> boxes = [1,2,3], warehouse = [1,2,3,4]
<strong>输出:</strong> 3
</pre>

<p><strong>示例 4:</strong></p>

<pre>
<strong>输入:</strong> boxes = [4,5,6], warehouse = [3,3,3,3,3]
<strong>输出:</strong> 0
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == warehouse.length</code></li>
	<li><code>1 <= boxes.length, warehouse.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= boxes[i], warehouse[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 排序 + 贪心

我们先对仓库进行预处理，得到每个房间的最大高度，然后对箱子和仓库进行排序，从最小的箱子开始，从最小的房间开始，如果当前房间的高度大于等于当前箱子的高度，则可以将当前箱子放入当前房间，否则继续寻找下一个房间。

最后返回可以放入的箱子数量。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为仓库的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        n = len(warehouse)
        left = [0] * n
        right = [0] * n
        left[0] = right[-1] = inf
        for i in range(1, n):
            left[i] = min(left[i - 1], warehouse[i - 1])
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], warehouse[i + 1])
        for i in range(n):
            warehouse[i] = min(warehouse[i], max(left[i], right[i]))
        boxes.sort()
        warehouse.sort()
        ans = i = 0
        for x in boxes:
            while i < n and warehouse[i] < x:
                i += 1
            if i == n:
                break
            ans, i = ans + 1, i + 1
        return ans
```

#### Java

```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int[] left = new int[n];
        int[] right = new int[n];
        final int inf = 1 << 30;
        left[0] = inf;
        right[n - 1] = inf;
        for (int i = 1; i < n; ++i) {
            left[i] = Math.min(left[i - 1], warehouse[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = Math.min(right[i + 1], warehouse[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            warehouse[i] = Math.min(warehouse[i], Math.max(left[i], right[i]));
        }
        Arrays.sort(boxes);
        Arrays.sort(warehouse);
        int ans = 0, i = 0;
        for (int x : boxes) {
            while (i < n && warehouse[i] < x) {
                ++i;
            }
            if (i == n) {
                break;
            }
            ++ans;
            ++i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        const int inf = 1 << 30;
        vector<int> left(n, inf);
        vector<int> right(n, inf);
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], warehouse[i - 1]);
        }
        for (int i = n - 2; ~i; --i) {
            right[i] = min(right[i + 1], warehouse[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            warehouse[i] = min(warehouse[i], max(left[i], right[i]));
        }
        sort(boxes.begin(), boxes.end());
        sort(warehouse.begin(), warehouse.end());
        int ans = 0;
        int i = 0;
        for (int x : boxes) {
            while (i < n && warehouse[i] < x) {
                ++i;
            }
            if (i == n) {
                break;
            }
            ++ans;
            ++i;
        }
        return ans;
    }
};
```

#### Go

```go
func maxBoxesInWarehouse(boxes []int, warehouse []int) (ans int) {
	n := len(warehouse)
	left := make([]int, n)
	right := make([]int, n)
	const inf = 1 << 30
	left[0] = inf
	right[n-1] = inf
	for i := 1; i < n; i++ {
		left[i] = min(left[i-1], warehouse[i-1])
	}
	for i := n - 2; i >= 0; i-- {
		right[i] = min(right[i+1], warehouse[i+1])
	}
	for i := 0; i < n; i++ {
		warehouse[i] = min(warehouse[i], max(left[i], right[i]))
	}
	sort.Ints(boxes)
	sort.Ints(warehouse)
	i := 0
	for _, x := range boxes {
		for i < n && warehouse[i] < x {
			i++
		}
		if i == n {
			break
		}
		ans++
		i++
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1581. 进店却未进行过交易的顾客](https://leetcode.cn/problems/customer-who-visited-but-did-not-make-any-transactions){#1581}

{{< tabs "1581" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT customer_id, COUNT(1) AS count_no_trans
FROM
    Visits
    LEFT JOIN Transactions USING (visit_id)
WHERE amount IS NULL
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Visits</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+
visit_id 是该表中具有唯一值的列。
该表包含有关光临过购物中心的顾客的信息。
</pre>

<p>&nbsp;</p>

<p>表：<code>Transactions</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+
transaction_id 是该表中具有唯一值的列。
此表包含 visit_id 期间进行的交易的信息。
</pre>

<p>&nbsp;</p>

<p>有一些顾客可能光顾了购物中心但没有进行交易。请你编写一个解决方案，来查找这些顾客的 ID ，以及他们只光顾不交易的次数。</p>

<p>返回以 <strong>任何顺序</strong> 排序的结果表。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入:</strong>
Visits</code>
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+
<code>Transactions</code>
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+
<b>输出:</b>
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+
<b>解释:</b>
ID = 23 的顾客曾经逛过一次购物中心，并在 ID = 12 的访问期间进行了一笔交易。
ID = 9 的顾客曾经逛过一次购物中心，并在 ID = 13 的访问期间进行了一笔交易。
ID = 30 的顾客曾经去过购物中心，并且没有进行任何交易。
ID = 54 的顾客三度造访了购物中心。在 2 次访问中，他们没有进行任何交易，在 1 次访问中，他们进行了 3 次交易。
ID = 96 的顾客曾经去过购物中心，并且没有进行任何交易。
如我们所见，ID 为 30 和 96 的顾客一次没有进行任何交易就去了购物中心。顾客 54 也两次访问了购物中心并且没有进行任何交易。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询 + 分组统计

我们可以使用子查询，先找出所有没有进行交易的 `visit_id`，然后按照 `customer_id` 进行分组，统计每个顾客的没有进行交易的次数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT customer_id, COUNT(1) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：左连接 + 分组统计

我们也可以使用左连接，将 `Visits` 表和 `Transactions` 表按照 `visit_id` 进行连接，然后筛选出 `amount` 为 `NULL` 的记录，按照 `customer_id` 进行分组，统计每个顾客的没有进行交易的次数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT customer_id, COUNT(1) AS count_no_trans
FROM
    Visits
    LEFT JOIN Transactions USING (visit_id)
WHERE amount IS NULL
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1582. 二进制矩阵中的特殊位置](https://leetcode.cn/problems/special-positions-in-a-binary-matrix){#1582}

{{< tabs "1582" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows = [0] * len(mat)
        cols = [0] * len(mat[0])
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                rows[i] += x
                cols[j] += x
        ans = 0
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                ans += x == 1 and rows[i] == 1 and cols[j] == 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
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
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
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
func numSpecial(mat [][]int) (ans int) {
	rows := make([]int, len(mat))
	cols := make([]int, len(mat[0]))
	for i, row := range mat {
		for j, x := range row {
			rows[i] += x
			cols[j] += x
		}
	}
	for i, row := range mat {
		for j, x := range row {
			if x == 1 && rows[i] == 1 && cols[j] == 1 {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSpecial(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (mat[i][j] === 1 && rows[i] === 1 && cols[j] === 1) {
                ++ans;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut rows = vec![0; m];
        let mut cols = vec![0; n];
        for i in 0..m {
            for j in 0..n {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        let mut ans = 0;
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize, n = matColSize[0];
    int rows[m];
    int cols[n];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                ans++;
            }
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

<p>给定一个 <code>m x n</code> 的二进制矩阵 <code>mat</code>，返回矩阵 <code>mat</code> 中特殊位置的数量。</p>

<p>如果位置 <code>(i, j)</code> 满足 <code>mat[i][j] == 1</code> 并且行 <code>i</code> 与列 <code>j</code> 中的所有其他元素都是 <code>0</code>（行和列的下标从 <strong>0 </strong>开始计数），那么它被称为<strong> 特殊 </strong>位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1582.Special%20Positions%20in%20a%20Binary%20Matrix/images/special1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>mat = [[1,0,0],[0,0,1],[1,0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>位置 (1, 2) 是一个特殊位置，因为 mat[1][2] == 1 且第 1 行和第 2 列的其他所有元素都是 0。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1582.Special%20Positions%20in%20a%20Binary%20Matrix/images/special-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>mat = [[1,0,0],[0,1,0],[0,0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>位置 (0, 0)，(1, 1) 和 (2, 2) 都是特殊位置。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>mat[i][j]</code> 是 <code>0</code> 或 <code>1</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用两个数组 $\textit{rows}$ 和 $\textit{cols}$ 分别记录每一行和每一列的 $1$ 的个数。

然后遍历矩阵，对于每一个 $1$，检查其所在的行和列是否只有一个 $1$，如果是则答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是矩阵 $\textit{mat}$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows = [0] * len(mat)
        cols = [0] * len(mat[0])
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                rows[i] += x
                cols[j] += x
        ans = 0
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                ans += x == 1 and rows[i] == 1 and cols[j] == 1
        return ans
```

#### Java

```java
class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
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
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
func numSpecial(mat [][]int) (ans int) {
	rows := make([]int, len(mat))
	cols := make([]int, len(mat[0]))
	for i, row := range mat {
		for j, x := range row {
			rows[i] += x
			cols[j] += x
		}
	}
	for i, row := range mat {
		for j, x := range row {
			if x == 1 && rows[i] == 1 && cols[j] == 1 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numSpecial(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;
    const rows: number[] = Array(m).fill(0);
    const cols: number[] = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (mat[i][j] === 1 && rows[i] === 1 && cols[j] === 1) {
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut rows = vec![0; m];
        let mut cols = vec![0; n];
        for i in 0..m {
            for j in 0..n {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }

        let mut ans = 0;
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

#### C

```c
int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize, n = matColSize[0];
    int rows[m];
    int cols[n];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rows[i] += mat[i][j];
            cols[j] += mat[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                ans++;
            }
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

# [1583. 统计不开心的朋友](https://leetcode.cn/problems/count-unhappy-friends){#1583}

{{< tabs "1583" >}}

{{% tab "python" %}}
```python
class Solution:
    def unhappyFriends(
        self, n: int, preferences: List[List[int]], pairs: List[List[int]]
    ) -> int:
        d = [{x: j for j, x in enumerate(p)} for p in preferences]
        p = {}
        for x, y in pairs:
            p[x] = y
            p[y] = x
        ans = 0
        for x in range(n):
            y = p[x]
            for i in range(d[x][y]):
                u = preferences[x][i]
                v = p[u]
                if d[u][x] < d[u][v]:
                    ans += 1
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int[][] d = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                d[i][preferences[i][j]] = j;
            }
        }
        int[] p = new int[n];
        for (var e : pairs) {
            int x = e[0], y = e[1];
            p[x] = y;
            p[y] = x;
        }
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            int y = p[x];
            for (int i = 0; i < d[x][y]; ++i) {
                int u = preferences[x][i];
                int v = p[u];
                if (d[u][x] < d[u][v]) {
                    ++ans;
                    break;
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
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                d[i][preferences[i][j]] = j;
            }
        }
        vector<int> p(n, 0);
        for (auto& e : pairs) {
            int x = e[0], y = e[1];
            p[x] = y;
            p[y] = x;
        }
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            int y = p[x];
            for (int i = 0; i < d[x][y]; ++i) {
                int u = preferences[x][i];
                int v = p[u];
                if (d[u][x] < d[u][v]) {
                    ++ans;
                    break;
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
func unhappyFriends(n int, preferences [][]int, pairs [][]int) (ans int) {
	d := make([][]int, n)
	for i := range d {
		d[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			d[i][preferences[i][j]] = j
		}
	}

	p := make([]int, n)
	for _, e := range pairs {
		x, y := e[0], e[1]
		p[x] = y
		p[y] = x
	}

	for x := 0; x < n; x++ {
		y := p[x]
		for i := 0; i < d[x][y]; i++ {
			u := preferences[x][i]
			v := p[u]
			if d[u][x] < d[u][v] {
				ans++
				break
			}
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function unhappyFriends(n: number, preferences: number[][], pairs: number[][]): number {
    const d: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n - 1; ++j) {
            d[i][preferences[i][j]] = j;
        }
    }
    const p: number[] = Array(n).fill(0);
    for (const [x, y] of pairs) {
        p[x] = y;
        p[y] = x;
    }
    let ans = 0;
    for (let x = 0; x < n; ++x) {
        const y = p[x];
        for (let i = 0; i < d[x][y]; ++i) {
            const u = preferences[x][i];
            const v = p[u];
            if (d[u][x] < d[u][v]) {
                ++ans;
                break;
            }
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

<p>给你一份 <code>n</code> 位朋友的亲近程度列表，其中 <code>n</code> 总是 <strong>偶数</strong> 。</p>

<p>对每位朋友 <code>i</code>，<code>preferences[i]</code> 包含一份 <strong>按亲近程度从高</strong><strong>到低排列</strong> 的朋友列表。换句话说，排在列表前面的朋友与 <code>i</code> 的亲近程度比排在列表后面的朋友更高。每个列表中的朋友均以 <code>0</code> 到 <code>n-1</code> 之间的整数表示。</p>

<p>所有的朋友被分成几对，配对情况以列表 <code>pairs</code> 给出，其中 <code>pairs[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示 <code>x<sub>i</sub></code> 与 <code>y<sub>i</sub></code> 配对，且 <code>y<sub>i</sub></code> 与 <code>x<sub>i</sub></code> 配对。</p>

<p>但是，这样的配对情况可能会使其中部分朋友感到不开心。在 <code>x</code> 与 <code>y</code> 配对且 <code>u</code> 与 <code>v</code> 配对的情况下，如果同时满足下述两个条件，<code>x</code> 就会不开心：</p>

<ul>
	<li><code>x</code> 与 <code>u</code> 的亲近程度胜过 <code>x</code> 与 <code>y</code>，且</li>
	<li><code>u</code> 与 <code>x</code> 的亲近程度胜过 <code>u</code> 与 <code>v</code></li>
</ul>

<p>返回 <strong>不开心的朋友的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
<strong>输出：</strong>2
<strong>解释：</strong>
朋友 1 不开心，因为：
- <strong>1 与 0 </strong>配对，但 <strong>1 与 3</strong> 的亲近程度比 <strong>1 与 0</strong> 高，且
- <strong>3 与 1</strong> 的亲近程度比 <strong>3 与 2</strong> 高。
朋友 3 不开心，因为：
- 3 与 2 配对，但 <strong>3 与 1</strong> 的亲近程度比 <strong>3 与 2</strong> 高，且
- <strong>1 与 3</strong> 的亲近程度比 <strong>1 与 0</strong> 高。
朋友 0 和 2 都是开心的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
<strong>输出：</strong>0
<strong>解释：</strong>朋友 0 和 1 都开心。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], pairs = [[1, 3], [0, 2]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>n</code> 是偶数</li>
	<li><code>preferences.length&nbsp;== n</code></li>
	<li><code>preferences[i].length&nbsp;== n - 1</code></li>
	<li><code>0 &lt;= preferences[i][j] &lt;= n - 1</code></li>
	<li><code>preferences[i]</code> 不包含 <code>i</code></li>
	<li><code>preferences[i]</code> 中的所有值都是独一无二的</li>
	<li><code>pairs.length&nbsp;== n/2</code></li>
	<li><code>pairs[i].length&nbsp;== 2</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li>每位朋友都 <strong>恰好</strong> 被包含在一对中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们用数组 $\textit{d}$ 记录每个朋友与其它朋友的亲近程度，其中 $\textit{d}[i][j]$ 表示朋友 $i$ 对 $j$ 的亲近程度（值越小，越亲近），另外，用数组 $\textit{p}$ 记录每个朋友的配对朋友。

我们枚举每个朋友 $x$，对于 $x$ 的配对朋友 $y$，我们找到 $x$ 对 $y$ 的亲近程度 $\textit{d}[x][y]$，然后枚举比 $\textit{d}[x][y]$ 更亲近的其它朋友 $u$，如果存在 $u$ 对 $x$ 的亲近程度 $\textit{d}[u][x]$ 比 $\textit{d}[u][y]$ 更高，那么 $x$ 就是不开心的朋友，将结果加一即可。

枚举结束后，即可得到不开心的朋友的数目。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为朋友的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def unhappyFriends(
        self, n: int, preferences: List[List[int]], pairs: List[List[int]]
    ) -> int:
        d = [{x: j for j, x in enumerate(p)} for p in preferences]
        p = {}
        for x, y in pairs:
            p[x] = y
            p[y] = x
        ans = 0
        for x in range(n):
            y = p[x]
            for i in range(d[x][y]):
                u = preferences[x][i]
                v = p[u]
                if d[u][x] < d[u][v]:
                    ans += 1
                    break
        return ans
```

#### Java

```java
class Solution {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int[][] d = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                d[i][preferences[i][j]] = j;
            }
        }
        int[] p = new int[n];
        for (var e : pairs) {
            int x = e[0], y = e[1];
            p[x] = y;
            p[y] = x;
        }
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            int y = p[x];
            for (int i = 0; i < d[x][y]; ++i) {
                int u = preferences[x][i];
                int v = p[u];
                if (d[u][x] < d[u][v]) {
                    ++ans;
                    break;
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
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> d(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                d[i][preferences[i][j]] = j;
            }
        }
        vector<int> p(n, 0);
        for (auto& e : pairs) {
            int x = e[0], y = e[1];
            p[x] = y;
            p[y] = x;
        }
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            int y = p[x];
            for (int i = 0; i < d[x][y]; ++i) {
                int u = preferences[x][i];
                int v = p[u];
                if (d[u][x] < d[u][v]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func unhappyFriends(n int, preferences [][]int, pairs [][]int) (ans int) {
	d := make([][]int, n)
	for i := range d {
		d[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			d[i][preferences[i][j]] = j
		}
	}

	p := make([]int, n)
	for _, e := range pairs {
		x, y := e[0], e[1]
		p[x] = y
		p[y] = x
	}

	for x := 0; x < n; x++ {
		y := p[x]
		for i := 0; i < d[x][y]; i++ {
			u := preferences[x][i]
			v := p[u]
			if d[u][x] < d[u][v] {
				ans++
				break
			}
		}
	}

	return
}
```

#### TypeScript

```ts
function unhappyFriends(n: number, preferences: number[][], pairs: number[][]): number {
    const d: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n - 1; ++j) {
            d[i][preferences[i][j]] = j;
        }
    }
    const p: number[] = Array(n).fill(0);
    for (const [x, y] of pairs) {
        p[x] = y;
        p[y] = x;
    }
    let ans = 0;
    for (let x = 0; x < n; ++x) {
        const y = p[x];
        for (let i = 0; i < d[x][y]; ++i) {
            const u = preferences[x][i];
            const v = p[u];
            if (d[u][x] < d[u][v]) {
                ++ans;
                break;
            }
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

# [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points){#1584}

{{< tabs "1584" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(points)
        g = []
        for i, (x1, y1) in enumerate(points):
            for j in range(i + 1, n):
                x2, y2 = points[j]
                t = abs(x1 - x2) + abs(y1 - y2)
                g.append((t, i, j))
        p = list(range(n))
        ans = 0
        for cost, i, j in sorted(g):
            pa, pb = find(i), find(j)
            if pa == pb:
                continue
            p[pa] = pb
            ans += cost
            n -= 1
            if n == 1:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<int[]> g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.add(new int[] {Math.abs(x1 - x2) + Math.abs(y1 - y2), i, j});
            }
        }
        g.sort(Comparator.comparingInt(a -> a[0]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) {
                continue;
            }
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return 0;
    }

    private int find(int x) {
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> g;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        sort(g.begin(), g.end());
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int ans = 0;
        for (auto& e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) continue;
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) return ans;
        }
        return 0;
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
func minCostConnectPoints(points [][]int) int {
	n := len(points)
	var g [][]int
	for i, p := range points {
		x1, y1 := p[0], p[1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			g = append(g, []int{abs(x1-x2) + abs(y1-y2), i, j})
		}
	}
	sort.Slice(g, func(i, j int) bool {
		return g[i][0] < g[j][0]
	})
	ans := 0
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range g {
		cost, i, j := e[0], e[1], e[2]
		if find(i) == find(j) {
			continue
		}
		p[find(i)] = find(j)
		ans += cost
		n--
		if n == 1 {
			return ans
		}
	}
	return 0
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
function minCostConnectPoints(points: number[][]): number {
    const n = points.length;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(0));
    const dist: number[] = Array(n).fill(1 << 30);
    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; ++j) {
            const [x2, y2] = points[j];
            const t = Math.abs(x1 - x2) + Math.abs(y1 - y2);
            g[i][j] = t;
            g[j][i] = t;
        }
    }
    let ans = 0;
    dist[0] = 0;
    for (let i = 0; i < n; ++i) {
        let j = -1;
        for (let k = 0; k < n; ++k) {
            if (!vis[k] && (j === -1 || dist[k] < dist[j])) {
                j = k;
            }
        }
        vis[j] = true;
        ans += dist[j];
        for (let k = 0; k < n; ++k) {
            if (!vis[k]) {
                dist[k] = Math.min(dist[k], g[j][k]);
            }
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

<p>给你一个<code>points</code>&nbsp;数组，表示 2D 平面上的一些点，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;。</p>

<p>连接点&nbsp;<code>[x<sub>i</sub>, y<sub>i</sub>]</code> 和点&nbsp;<code>[x<sub>j</sub>, y<sub>j</sub>]</code>&nbsp;的费用为它们之间的 <strong>曼哈顿距离</strong>&nbsp;：<code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>&nbsp;，其中&nbsp;<code>|val|</code>&nbsp;表示&nbsp;<code>val</code>&nbsp;的绝对值。</p>

<p>请你返回将所有点连接的最小总费用。只有任意两点之间 <strong>有且仅有</strong>&nbsp;一条简单路径时，才认为所有点都已连接。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1584.Min%20Cost%20to%20Connect%20All%20Points/images/d.png" style="height:268px; width:214px; background:#e5e5e5" /></p>

<pre>
<strong>输入：</strong>points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>输出：</strong>20
<strong>解释：
</strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1584.Min%20Cost%20to%20Connect%20All%20Points/images/c.png" style="height:268px; width:214px; background:#e5e5e5" />
我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[3,12],[-2,5],[-4,1]]
<strong>输出：</strong>18
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>points = [[0,0],[1,1],[1,0],[-1,1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>points = [[-1000000,-1000000],[1000000,1000000]]
<strong>输出：</strong>4000000
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>points = [[0,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>所有点&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;两两不同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：朴素 Prim 算法

我们定义一个数组 $dist$，其中 $dist[i]$ 表示点 $i$ 到当前生成树的距离，初始时 $dist[0] = 0$，其余均为 $+\infty$，定义一个数组 $vis$，其中 $vis[i]$ 表示点 $i$ 是否在生成树中，初始时所有点均不在生成树中，定义一个二维数组 $g$，其中 $g[i][j]$ 表示点 $i$ 到点 $j$ 的距离，那么我们的目标是将所有点都加入到生成树中，且总费用最小。

我们每次从不在生成树中的点中选取一个距离最小的点 $i$，将点 $i$ 加入到生成树中，并将 $i$ 到其它点的距离更新到 $dist$ 数组中，直到所有点都在生成树中为止。

该算法适用于稠密图，时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        g = [[0] * n for _ in range(n)]
        dist = [inf] * n
        vis = [False] * n
        for i, (x1, y1) in enumerate(points):
            for j in range(i + 1, n):
                x2, y2 = points[j]
                t = abs(x1 - x2) + abs(y1 - y2)
                g[i][j] = g[j][i] = t
        dist[0] = 0
        ans = 0
        for _ in range(n):
            i = -1
            for j in range(n):
                if not vis[j] and (i == -1 or dist[j] < dist[i]):
                    i = j
            vis[i] = True
            ans += dist[i]
            for j in range(n):
                if not vis[j]:
                    dist[j] = min(dist[j], g[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int minCostConnectPoints(int[][] points) {
        final int inf = 1 << 30;
        int n = points.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int t = Math.abs(x1 - x2) + Math.abs(y1 - y2);
                g[i][j] = t;
                g[j][i] = t;
            }
        }
        int[] dist = new int[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(dist, inf);
        dist[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = -1;
            for (int k = 0; k < n; ++k) {
                if (!vis[k] && (j == -1 || dist[k] < dist[j])) {
                    j = k;
                }
            }
            vis[j] = true;
            ans += dist[j];
            for (int k = 0; k < n; ++k) {
                if (!vis[k]) {
                    dist[k] = Math.min(dist[k], g[j][k]);
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int g[n][n];
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int t = abs(x1 - x2) + abs(y1 - y2);
                g[i][j] = t;
                g[j][i] = t;
            }
        }
        int dist[n];
        bool vis[n];
        memset(dist, 0x3f, sizeof(dist));
        memset(vis, false, sizeof(vis));
        dist[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = -1;
            for (int k = 0; k < n; ++k) {
                if (!vis[k] && (j == -1 || dist[k] < dist[j])) {
                    j = k;
                }
            }
            vis[j] = true;
            ans += dist[j];
            for (int k = 0; k < n; ++k) {
                if (!vis[k]) {
                    dist[k] = min(dist[k], g[j][k]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minCostConnectPoints(points [][]int) (ans int) {
	n := len(points)
	g := make([][]int, n)
	vis := make([]bool, n)
	dist := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
		dist[i] = 1 << 30
	}
	for i := range g {
		x1, y1 := points[i][0], points[i][1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			t := abs(x1-x2) + abs(y1-y2)
			g[i][j] = t
			g[j][i] = t
		}
	}
	dist[0] = 0
	for i := 0; i < n; i++ {
		j := -1
		for k := 0; k < n; k++ {
			if !vis[k] && (j == -1 || dist[k] < dist[j]) {
				j = k
			}
		}
		vis[j] = true
		ans += dist[j]
		for k := 0; k < n; k++ {
			if !vis[k] {
				dist[k] = min(dist[k], g[j][k])
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

#### TypeScript

```ts
function minCostConnectPoints(points: number[][]): number {
    const n = points.length;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(0));
    const dist: number[] = Array(n).fill(1 << 30);
    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; ++j) {
            const [x2, y2] = points[j];
            const t = Math.abs(x1 - x2) + Math.abs(y1 - y2);
            g[i][j] = t;
            g[j][i] = t;
        }
    }
    let ans = 0;
    dist[0] = 0;
    for (let i = 0; i < n; ++i) {
        let j = -1;
        for (let k = 0; k < n; ++k) {
            if (!vis[k] && (j === -1 || dist[k] < dist[j])) {
                j = k;
            }
        }
        vis[j] = true;
        ans += dist[j];
        for (let k = 0; k < n; ++k) {
            if (!vis[k]) {
                dist[k] = Math.min(dist[k], g[j][k]);
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Kruskal 算法

我们先将所有边按照长度由小到大进行排序，循环遍历每条边，逐个加入到图中，当所有点达到一个连通状态时，退出循环，返回此时的总费用即可。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 为边的数量，本题中 $m = n^2$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(points)
        g = []
        for i, (x1, y1) in enumerate(points):
            for j in range(i + 1, n):
                x2, y2 = points[j]
                t = abs(x1 - x2) + abs(y1 - y2)
                g.append((t, i, j))
        p = list(range(n))
        ans = 0
        for cost, i, j in sorted(g):
            pa, pb = find(i), find(j)
            if pa == pb:
                continue
            p[pa] = pb
            ans += cost
            n -= 1
            if n == 1:
                break
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<int[]> g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.add(new int[] {Math.abs(x1 - x2) + Math.abs(y1 - y2), i, j});
            }
        }
        g.sort(Comparator.comparingInt(a -> a[0]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) {
                continue;
            }
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return 0;
    }

    private int find(int x) {
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

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> g;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        sort(g.begin(), g.end());
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int ans = 0;
        for (auto& e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) continue;
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) return ans;
        }
        return 0;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```

#### Go

```go
func minCostConnectPoints(points [][]int) int {
	n := len(points)
	var g [][]int
	for i, p := range points {
		x1, y1 := p[0], p[1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			g = append(g, []int{abs(x1-x2) + abs(y1-y2), i, j})
		}
	}
	sort.Slice(g, func(i, j int) bool {
		return g[i][0] < g[j][0]
	})
	ans := 0
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range g {
		cost, i, j := e[0], e[1], e[2]
		if find(i) == find(j) {
			continue
		}
		p[find(i)] = find(j)
		ans += cost
		n--
		if n == 1 {
			return ans
		}
	}
	return 0
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

# [1585. 检查字符串是否可以通过排序子字符串得到另一个字符串](https://leetcode.cn/problems/check-if-string-is-transformable-with-substring-sort-operations){#1585}

{{< tabs "1585" >}}

{{% tab "python" %}}
```python
class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        pos = defaultdict(deque)
        for i, c in enumerate(s):
            pos[int(c)].append(i)
        for c in t:
            x = int(c)
            if not pos[x] or any(pos[i] and pos[i][0] < pos[x][0] for i in range(x)):
                return False
            pos[x].popleft()
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isTransformable(String s, String t) {
        Deque<Integer>[] pos = new Deque[10];
        Arrays.setAll(pos, k -> new ArrayDeque<>());
        for (int i = 0; i < s.length(); ++i) {
            pos[s.charAt(i) - '0'].offer(i);
        }
        for (int i = 0; i < t.length(); ++i) {
            int x = t.charAt(i) - '0';
            if (pos[x].isEmpty()) {
                return false;
            }
            for (int j = 0; j < x; ++j) {
                if (!pos[j].isEmpty() && pos[j].peek() < pos[x].peek()) {
                    return false;
                }
            }
            pos[x].poll();
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
    bool isTransformable(string s, string t) {
        queue<int> pos[10];
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - '0'].push(i);
        }
        for (char& c : t) {
            int x = c - '0';
            if (pos[x].empty()) {
                return false;
            }
            for (int j = 0; j < x; ++j) {
                if (!pos[j].empty() && pos[j].front() < pos[x].front()) {
                    return false;
                }
            }
            pos[x].pop();
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isTransformable(s string, t string) bool {
	pos := [10][]int{}
	for i, c := range s {
		pos[c-'0'] = append(pos[c-'0'], i)
	}
	for _, c := range t {
		x := int(c - '0')
		if len(pos[x]) == 0 {
			return false
		}
		for j := 0; j < x; j++ {
			if len(pos[j]) > 0 && pos[j][0] < pos[x][0] {
				return false
			}
		}
		pos[x] = pos[x][1:]
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

<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;，请你通过若干次以下操作将字符串&nbsp;<code>s</code>&nbsp;转化成字符串&nbsp;<code>t</code>&nbsp;：</p>

<ul>
	<li>选择 <code>s</code>&nbsp;中一个 <strong>非空</strong>&nbsp;子字符串并将它包含的字符就地 <strong>升序</strong>&nbsp;排序。</li>
</ul>

<p>比方说，对下划线所示的子字符串进行操作可以由&nbsp;<code>&quot;1<strong>4234</strong>&quot;</code>&nbsp;得到&nbsp;<code>&quot;1<strong>2344</strong>&quot;</code>&nbsp;。</p>

<p>如果可以将字符串 <code>s</code>&nbsp;变成 <code>t</code>&nbsp;，返回 <code>true</code>&nbsp;。否则，返回 <code>false</code>&nbsp;。</p>

<p>一个 <strong>子字符串</strong>&nbsp;定义为一个字符串中连续的若干字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;84532&quot;, t = &quot;34852&quot;
<strong>输出：</strong>true
<strong>解释：</strong>你可以按以下操作将 s 转变为 t ：
&quot;84<strong>53</strong>2&quot; （从下标 2 到下标 3）-&gt; &quot;84<strong>35</strong>2&quot;
&quot;<strong>843</strong>52&quot; （从下标 0 到下标 2） -&gt; &quot;<strong>348</strong>52&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;34521&quot;, t = &quot;23415&quot;
<strong>输出：</strong>true
<strong>解释：</strong>你可以按以下操作将 s 转变为 t ：
&quot;<strong>3452</strong>1&quot; -&gt; &quot;<strong>2345</strong>1&quot;
&quot;234<strong>51</strong>&quot; -&gt; &quot;234<strong>15</strong>&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;12345&quot;, t = &quot;12435&quot;
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;1&quot;, t = &quot;2&quot;
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == t.length</code></li>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含数字字符，即&nbsp;<code>&#39;0&#39;</code>&nbsp;到&nbsp;<code>&#39;9&#39;</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：冒泡排序

题目实际上等价于判断：将字符串 $s$ 中任意长度为 $2$ 的子字符串采用冒泡排序交换，是否能得到 $t$。

因此我们用一个长度为 $10$ 的数组 $pos$ 记录字符串 $s$ 中每个字符数字的下标，其中 $pos[i]$ 表示数字 $i$ 出现的下标列表，按从小到大排序。

接下来，我们遍历字符串 $t$，对于 $t$ 中的每个字符 $t[i]$，我们转为数字 $x$，我们判断 $pos[x]$ 是否为空，若是，说明字符串 $s$ 中不存在 $t$ 中的数字，直接返回 `false`。否则，若要将 $pos[x]$ 的第一个位置下标的字符交换到下标 $i$ 的位置，需要满足小于 $x$ 的所有数字的下标均不小于 $pos[x]$ 的第一个位置下标，若不满足，返回 `false`。否则，我们将 $pos[x]$ 的第一个位置下标弹出，然后继续遍历字符串 $t$。

遍历结束，返回 `true`。

时间复杂度 $O(n \times C)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 是数字集的大小，本题中 $C=10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        pos = defaultdict(deque)
        for i, c in enumerate(s):
            pos[int(c)].append(i)
        for c in t:
            x = int(c)
            if not pos[x] or any(pos[i] and pos[i][0] < pos[x][0] for i in range(x)):
                return False
            pos[x].popleft()
        return True
```

#### Java

```java
class Solution {
    public boolean isTransformable(String s, String t) {
        Deque<Integer>[] pos = new Deque[10];
        Arrays.setAll(pos, k -> new ArrayDeque<>());
        for (int i = 0; i < s.length(); ++i) {
            pos[s.charAt(i) - '0'].offer(i);
        }
        for (int i = 0; i < t.length(); ++i) {
            int x = t.charAt(i) - '0';
            if (pos[x].isEmpty()) {
                return false;
            }
            for (int j = 0; j < x; ++j) {
                if (!pos[j].isEmpty() && pos[j].peek() < pos[x].peek()) {
                    return false;
                }
            }
            pos[x].poll();
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int> pos[10];
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - '0'].push(i);
        }
        for (char& c : t) {
            int x = c - '0';
            if (pos[x].empty()) {
                return false;
            }
            for (int j = 0; j < x; ++j) {
                if (!pos[j].empty() && pos[j].front() < pos[x].front()) {
                    return false;
                }
            }
            pos[x].pop();
        }
        return true;
    }
};
```

#### Go

```go
func isTransformable(s string, t string) bool {
	pos := [10][]int{}
	for i, c := range s {
		pos[c-'0'] = append(pos[c-'0'], i)
	}
	for _, c := range t {
		x := int(c - '0')
		if len(pos[x]) == 0 {
			return false
		}
		for j := 0; j < x; j++ {
			if len(pos[j]) > 0 && pos[j][0] < pos[x][0] {
				return false
			}
		}
		pos[x] = pos[x][1:]
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1586. 二叉搜索树迭代器 II 🔒](https://leetcode.cn/problems/binary-search-tree-iterator-ii){#1586}

{{< tabs "1586" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.nums = []

        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            self.nums.append(root.val)
            dfs(root.right)

        dfs(root)
        self.i = -1

    def hasNext(self) -> bool:
        return self.i < len(self.nums) - 1

    def next(self) -> int:
        self.i += 1
        return self.nums[self.i]

    def hasPrev(self) -> bool:
        return self.i > 0

    def prev(self) -> int:
        self.i -= 1
        return self.nums[self.i]


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.hasNext()
# param_2 = obj.next()
# param_3 = obj.hasPrev()
# param_4 = obj.prev()
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private List<Integer> nums = new ArrayList<>();
    private int i = -1;

    public BSTIterator(TreeNode root) {
        dfs(root);
    }

    public boolean hasNext() {
        return i < nums.size() - 1;
    }

    public int next() {
        return nums.get(++i);
    }

    public boolean hasPrev() {
        return i > 0;
    }

    public int prev() {
        return nums.get(--i);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * boolean param_1 = obj.hasNext();
 * int param_2 = obj.next();
 * boolean param_3 = obj.hasPrev();
 * int param_4 = obj.prev();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        n = nums.size();
    }

    bool hasNext() {
        return i < n - 1;
    }

    int next() {
        return nums[++i];
    }

    bool hasPrev() {
        return i > 0;
    }

    int prev() {
        return nums[--i];
    }

private:
    vector<int> nums;
    int i = -1;
    int n;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	nums []int
	i, n int
}

func Constructor(root *TreeNode) BSTIterator {
	nums := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		nums = append(nums, root.Val)
		dfs(root.Right)
	}
	dfs(root)
	return BSTIterator{nums, -1, len(nums)}
}

func (this *BSTIterator) HasNext() bool {
	return this.i < this.n-1
}

func (this *BSTIterator) Next() int {
	this.i++
	return this.nums[this.i]
}

func (this *BSTIterator) HasPrev() bool {
	return this.i > 0
}

func (this *BSTIterator) Prev() int {
	this.i--
	return this.nums[this.i]
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.HasNext();
 * param_2 := obj.Next();
 * param_3 := obj.HasPrev();
 * param_4 := obj.Prev();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
    private nums: number[];
    private n: number;
    private i: number;

    constructor(root: TreeNode | null) {
        this.nums = [];
        const dfs = (root: TreeNode | null) => {
            if (!root) {
                return;
            }
            dfs(root.left);
            this.nums.push(root.val);
            dfs(root.right);
        };
        dfs(root);
        this.n = this.nums.length;
        this.i = -1;
    }

    hasNext(): boolean {
        return this.i < this.n - 1;
    }

    next(): number {
        return this.nums[++this.i];
    }

    hasPrev(): boolean {
        return this.i > 0;
    }

    prev(): number {
        return this.nums[--this.i];
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.hasNext()
 * var param_2 = obj.next()
 * var param_3 = obj.hasPrev()
 * var param_4 = obj.prev()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现二叉搜索树（BST）的<a href="https://baike.baidu.com/item/中序遍历/757281?fr=aladdin">中序遍历</a>迭代器&nbsp;<code>BSTIterator</code>&nbsp;类：</p>

<ul>
	<li><code>BSTIterator(TreeNode root)</code>&nbsp;初始化&nbsp;<code>BSTIterator</code>&nbsp;类的实例。二叉搜索树的根节点&nbsp;<code>root</code>&nbsp;作为构造函数的参数传入。内部指针使用一个不存在于树中且小于树中任意值的数值来初始化。</li>
	<li><code>boolean hasNext()</code>&nbsp;如果当前指针在中序遍历序列中，存在右侧数值，返回&nbsp;<code>true</code> ，否则返回&nbsp;<code>false</code>&nbsp;。</li>
	<li><code>int next()</code>&nbsp;将指针在中序遍历序列中向右移动，然后返回移动后指针所指数值。</li>
	<li><code>boolean hasPrev()</code>&nbsp;如果当前指针在中序遍历序列中，存在左侧数值，返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</li>
	<li><code>int prev()</code>&nbsp;将指针在中序遍历序列中向左移动，然后返回移动后指针所指数值。</li>
</ul>

<p>注意，虽然我们使用树中不存在的最小值来初始化内部指针，第一次调用&nbsp;<code>next()</code>&nbsp;需要返回二叉搜索树中最小的元素。</p>

<p>你可以假设&nbsp;<code>next()</code>&nbsp;和&nbsp;<code>prev()</code>&nbsp;的调用总是有效的。即，当&nbsp;<code>next()</code>/<code>prev()</code>&nbsp;被调用的时候，在中序遍历序列中一定存在下一个/上一个元素。</p>

<p><strong>进阶：</strong>你可以不提前遍历树中的值来解决问题吗？</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1586.Binary%20Search%20Tree%20Iterator%20II/images/untitled-diagram-1.png" style="height: 201px; width: 201px;"></strong></p>

<pre><strong>输入</strong>
[&quot;BSTIterator&quot;, &quot;next&quot;, &quot;next&quot;, &quot;prev&quot;, &quot;next&quot;, &quot;hasNext&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;hasNext&quot;, &quot;hasPrev&quot;, &quot;prev&quot;, &quot;prev&quot;]
[[[7, 3, 15, null, null, 9, 20]], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null]]
<strong>输出</strong>
[null, 3, 7, 3, 7, true, 9, 15, 20, false, true, 15, 9]

<strong>解释</strong>
// 划线的元素表示指针当前的位置。
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]); // 当前状态为 &lt;u&gt; &lt;/u&gt; [3, 7, 9, 15, 20]
bSTIterator.next(); // 状态变为 [&lt;u&gt;3&lt;/u&gt;, 7, 9, 15, 20], 返回 3
bSTIterator.next(); // 状态变为 [3, &lt;u&gt;7&lt;/u&gt;, 9, 15, 20], 返回 7
bSTIterator.prev(); // 状态变为 [&lt;u&gt;3&lt;/u&gt;, 7, 9, 15, 20], 返回 3
bSTIterator.next(); // 状态变为 [3, &lt;u&gt;7&lt;/u&gt;, 9, 15, 20], 返回 7
bSTIterator.hasNext(); // 返回 true
bSTIterator.next(); // 状态变为 [3, 7, &lt;u&gt;9&lt;/u&gt;, 15, 20], 返回 9
bSTIterator.next(); // 状态变为 [3, 7, 9, &lt;u&gt;15&lt;/u&gt;, 20], 返回 15
bSTIterator.next(); // 状态变为 [3, 7, 9, 15, &lt;u&gt;20&lt;/u&gt;], 返回 20
bSTIterator.hasNext(); // 返回 false
bSTIterator.hasPrev(); // 返回 true
bSTIterator.prev(); // 状态变为 [3, 7, 9, &lt;u&gt;15&lt;/u&gt;, 20], 返回 15
bSTIterator.prev(); // 状态变为 [3, 7, &lt;u&gt;9&lt;/u&gt;, 15, 20], 返回 9
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是&nbsp;<code>[1, 10<sup>5</sup>]</code>&nbsp;。</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li>最多调用&nbsp;10<sup>5</sup>&nbsp;次&nbsp;<code>hasNext</code>、&nbsp;<code>next</code>、&nbsp;<code>hasPrev</code>&nbsp;和&nbsp;<code>prev</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历 + 数组

我们可以使用中序遍历将二叉搜索树的所有节点的值存储到数组 $nums$ 中，然后使用数组实现迭代器。我们定义一个指针 $i$，初始时 $i = -1$，表示指向数组 $nums$ 中的一个元素。每次调用 $next()$ 时，我们将 $i$ 的值加 $1$，并返回 $nums[i]$；每次调用 $prev()$ 时，我们将 $i$ 的值减 $1$，并返回 $nums[i]$。

时间复杂度方面，初始化迭代器需要 $O(n)$ 的时间，其中 $n$ 是二叉搜索树的节点数。每次调用 $next()$ 和 $prev()$ 都需要 $O(1)$ 的时间。空间复杂度方面，我们需要 $O(n)$ 的空间存储二叉搜索树的所有节点的值。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.nums = []

        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            self.nums.append(root.val)
            dfs(root.right)

        dfs(root)
        self.i = -1

    def hasNext(self) -> bool:
        return self.i < len(self.nums) - 1

    def next(self) -> int:
        self.i += 1
        return self.nums[self.i]

    def hasPrev(self) -> bool:
        return self.i > 0

    def prev(self) -> int:
        self.i -= 1
        return self.nums[self.i]


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.hasNext()
# param_2 = obj.next()
# param_3 = obj.hasPrev()
# param_4 = obj.prev()
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private List<Integer> nums = new ArrayList<>();
    private int i = -1;

    public BSTIterator(TreeNode root) {
        dfs(root);
    }

    public boolean hasNext() {
        return i < nums.size() - 1;
    }

    public int next() {
        return nums.get(++i);
    }

    public boolean hasPrev() {
        return i > 0;
    }

    public int prev() {
        return nums.get(--i);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * boolean param_1 = obj.hasNext();
 * int param_2 = obj.next();
 * boolean param_3 = obj.hasPrev();
 * int param_4 = obj.prev();
 */
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        n = nums.size();
    }

    bool hasNext() {
        return i < n - 1;
    }

    int next() {
        return nums[++i];
    }

    bool hasPrev() {
        return i > 0;
    }

    int prev() {
        return nums[--i];
    }

private:
    vector<int> nums;
    int i = -1;
    int n;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	nums []int
	i, n int
}

func Constructor(root *TreeNode) BSTIterator {
	nums := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		nums = append(nums, root.Val)
		dfs(root.Right)
	}
	dfs(root)
	return BSTIterator{nums, -1, len(nums)}
}

func (this *BSTIterator) HasNext() bool {
	return this.i < this.n-1
}

func (this *BSTIterator) Next() int {
	this.i++
	return this.nums[this.i]
}

func (this *BSTIterator) HasPrev() bool {
	return this.i > 0
}

func (this *BSTIterator) Prev() int {
	this.i--
	return this.nums[this.i]
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.HasNext();
 * param_2 := obj.Next();
 * param_3 := obj.HasPrev();
 * param_4 := obj.Prev();
 */
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
    private nums: number[];
    private n: number;
    private i: number;

    constructor(root: TreeNode | null) {
        this.nums = [];
        const dfs = (root: TreeNode | null) => {
            if (!root) {
                return;
            }
            dfs(root.left);
            this.nums.push(root.val);
            dfs(root.right);
        };
        dfs(root);
        this.n = this.nums.length;
        this.i = -1;
    }

    hasNext(): boolean {
        return this.i < this.n - 1;
    }

    next(): number {
        return this.nums[++this.i];
    }

    hasPrev(): boolean {
        return this.i > 0;
    }

    prev(): number {
        return this.nums[--this.i];
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.hasNext()
 * var param_2 = obj.next()
 * var param_3 = obj.hasPrev()
 * var param_4 = obj.prev()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1587. 银行账户概要 II](https://leetcode.cn/problems/bank-account-summary-ii){#1587}

{{< tabs "1587" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    name,
    SUM(amount) AS balance
FROM
    Users
    JOIN Transactions USING (account)
GROUP BY account
HAVING balance > 10000;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Users</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| account      | int     |
| name         | varchar |
+--------------+---------+
account 是该表的主键(具有唯一值的列)。
该表的每一行都包含银行中每个用户的帐号。
表中不会有两个用户具有相同的名称。
</pre>

<p>&nbsp;</p>

<p>表: <code>Transactions</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| trans_id      | int     |
| account       | int     |
| amount        | int     |
| transacted_on | date    |
+---------------+---------+
trans_id 是该表主键(具有唯一值的列)。
该表的每一行包含了所有账户的交易改变情况。
如果用户收到了钱, 那么金额是正的; 如果用户转了钱, 那么金额是负的。
所有账户的起始余额为 0。
</pre>

<p>&nbsp;</p>

<p>编写解决方案,&nbsp;&nbsp;报告余额高于 10000 的所有用户的名字和余额.&nbsp;账户的余额等于包含该账户的所有交易的总和。</p>

<p>返回结果表单 <strong>无顺序要求</strong> 。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Users</code> table:
+------------+--------------+
| account    | name         |
+------------+--------------+
| 900001     | Alice        |
| 900002     | Bob          |
| 900003     | Charlie      |
+------------+--------------+

<code>Transactions</code> table:
+------------+------------+------------+---------------+
| trans_id   | account    | amount     | transacted_on |
+------------+------------+------------+---------------+
| 1          | 900001     | 7000       |  2020-08-01   |
| 2          | 900001     | 7000       |  2020-09-01   |
| 3          | 900001     | -3000      |  2020-09-02   |
| 4          | 900002     | 1000       |  2020-09-12   |
| 5          | 900003     | 6000       |  2020-08-07   |
| 6          | 900003     | 6000       |  2020-09-07   |
| 7          | 900003     | -4000      |  2020-09-11   |
+------------+------------+------------+---------------+
<strong>输出：</strong>
+------------+------------+
| <code>name    </code>   | <code>balance  </code>  |
+------------+------------+
| Alice      | 11000      |
+------------+------------+
<strong>解释：</strong>
Alice 的余额为(7000 + 7000 - 3000) = 11000.
Bob 的余额为1000.
Charlie 的余额为(6000 + 6000 - 4000) = 8000.
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组求和

我们可以使用等值连接，将 `Users` 和 `Transactions` 表按照 `account` 列连接起来，然后按照 `account` 列分组求和，最后筛选出余额大于 $10000$ 的用户。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    name,
    SUM(amount) AS balance
FROM
    Users
    JOIN Transactions USING (account)
GROUP BY account
HAVING balance > 10000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1588. 所有奇数长度子数组的和](https://leetcode.cn/problems/sum-of-all-odd-length-subarrays){#1588}

{{< tabs "1588" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans, f, g = arr[0], arr[0], 0
        for i in range(1, len(arr)):
            ff = g + arr[i] * (i // 2 + 1)
            gg = f + arr[i] * ((i + 1) // 2)
            f, g = ff, gg
            ans += f
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int ans = arr[0], f = arr[0], g = 0;
        for (int i = 1; i < arr.length; ++i) {
            int ff = g + arr[i] * (i / 2 + 1);
            int gg = f + arr[i] * ((i + 1) / 2);
            f = ff;
            g = gg;
            ans += f;
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
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = arr[0], f = arr[0], g = 0;
        for (int i = 1; i < arr.size(); ++i) {
            int ff = g + arr[i] * (i / 2 + 1);
            int gg = f + arr[i] * ((i + 1) / 2);
            f = ff;
            g = gg;
            ans += f;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOddLengthSubarrays(arr []int) (ans int) {
	f, g := arr[0], 0
	ans = f
	for i := 1; i < len(arr); i++ {
		ff := g + arr[i]*(i/2+1)
		gg := f + arr[i]*((i+1)/2)
		f, g = ff, gg
		ans += f
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOddLengthSubarrays(arr: number[]): number {
    const n = arr.length;
    let [ans, f, g] = [arr[0], arr[0], 0];
    for (let i = 1; i < n; ++i) {
        const ff = g + arr[i] * (Math.floor(i / 2) + 1);
        const gg = f + arr[i] * Math.floor((i + 1) / 2);
        [f, g] = [ff, gg];
        ans += f;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let mut ans = arr[0];
        let mut f = arr[0];
        let mut g = 0;
        for i in 1..arr.len() {
            let ff = g + arr[i] * ((i as i32) / 2 + 1);
            let gg = f + arr[i] * (((i + 1) as i32) / 2);
            f = ff;
            g = gg;
            ans += f;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int ans = arr[0], f = arr[0], g = 0;
    for (int i = 1; i < arrSize; ++i) {
        int ff = g + arr[i] * (i / 2 + 1);
        int gg = f + arr[i] * ((i + 1) / 2);
        f = ff;
        g = gg;
        ans += f;
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

<p>给你一个正整数数组&nbsp;<code>arr</code>&nbsp;，请你计算所有可能的奇数长度子数组的和。</p>

<p><strong>子数组</strong> 定义为原数组中的一个连续子序列。</p>

<p>请你返回 <code>arr</code>&nbsp;中 <strong>所有奇数长度子数组的和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,4,2,5,3]
<strong>输出：</strong>58
<strong>解释：</strong>所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2]
<strong>输出：</strong>3
<strong>解释：</strong>总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [10,11,12]
<strong>输出：</strong>66
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你可以设计一个 O(n) 时间复杂度的算法解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义两个长度为 $n$ 的数组 $f$ 和 $g$，其中 $f[i]$ 表示以 $\textit{arr}[i]$ 结尾的长度为奇数的子数组的和，而 $g[i]$ 表示以 $\textit{arr}[i]$ 结尾的长度为偶数的子数组的和。初始时 $f[0] = \textit{arr}[0]$，而 $g[0] = 0$。答案即为 $\sum_{i=0}^{n-1} f[i]$。

当 $i > 0$ 时，考虑 $f[i]$ 和 $g[i]$ 如何进行状态转移：

对于状态 $f[i]$，元素 $\textit{arr}[i]$ 可以与前面的 $g[i-1]$ 组成一个长度为奇数的子数组，一共可以组成的子数组个数为 $(i / 2) + 1$ 个，因此 $f[i] = g[i-1] + \textit{arr}[i] \times ((i / 2) + 1)$。

对于状态 $g[i]$，当 $i = 0$ 时，没有长度为偶数的子数组，因此 $g[0] = 0$；当 $i > 0$ 时，元素 $\textit{arr}[i]$ 可以与前面的 $f[i-1]$ 组成一个长度为偶数的子数组，一共可以组成的子数组个数为 $(i + 1) / 2$ 个，因此 $g[i] = f[i-1] + \textit{arr}[i] \times ((i + 1) / 2)$。

最终答案即为 $\sum_{i=0}^{n-1} f[i]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        f = [0] * n
        g = [0] * n
        ans = f[0] = arr[0]
        for i in range(1, n):
            f[i] = g[i - 1] + arr[i] * (i // 2 + 1)
            g[i] = f[i - 1] + arr[i] * ((i + 1) // 2)
            ans += f[i]
        return ans
```

#### Java

```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int n = arr.length;
        int[] f = new int[n];
        int[] g = new int[n];
        int ans = f[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1] + arr[i] * (i / 2 + 1);
            g[i] = f[i - 1] + arr[i] * ((i + 1) / 2);
            ans += f[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n, arr[0]);
        vector<int> g(n);
        int ans = f[0];
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1] + arr[i] * (i / 2 + 1);
            g[i] = f[i - 1] + arr[i] * ((i + 1) / 2);
            ans += f[i];
        }
        return ans;
    }
};
```

#### Go

```go
func sumOddLengthSubarrays(arr []int) (ans int) {
	n := len(arr)
	f := make([]int, n)
	g := make([]int, n)
	f[0] = arr[0]
	ans = f[0]
	for i := 1; i < n; i++ {
		f[i] = g[i-1] + arr[i]*(i/2+1)
		g[i] = f[i-1] + arr[i]*((i+1)/2)
		ans += f[i]
	}
	return
}
```

#### TypeScript

```ts
function sumOddLengthSubarrays(arr: number[]): number {
    const n = arr.length;
    const f: number[] = Array(n).fill(arr[0]);
    const g: number[] = Array(n).fill(0);
    let ans = f[0];
    for (let i = 1; i < n; ++i) {
        f[i] = g[i - 1] + arr[i] * ((i >> 1) + 1);
        g[i] = f[i - 1] + arr[i] * ((i + 1) >> 1);
        ans += f[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut f = vec![0; n];
        let mut g = vec![0; n];
        let mut ans = arr[0];
        f[0] = arr[0];
        for i in 1..n {
            f[i] = g[i - 1] + arr[i] * ((i as i32) / 2 + 1);
            g[i] = f[i - 1] + arr[i] * (((i + 1) as i32) / 2);
            ans += f[i];
        }
        ans
    }
}
```

#### C

```c
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int n = arrSize;
    int f[n];
    int g[n];
    int ans = f[0] = arr[0];
    g[0] = 0;
    for (int i = 1; i < n; ++i) {
        f[i] = g[i - 1] + arr[i] * (i / 2 + 1);
        g[i] = f[i - 1] + arr[i] * ((i + 1) / 2);
        ans += f[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到，状态 $f[i]$ 和 $g[i]$ 的值只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此我们可以使用两个变量 $f$ 和 $g$ 分别记录 $f[i - 1]$ 和 $g[i - 1]$ 的值，从而优化空间复杂度。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans, f, g = arr[0], arr[0], 0
        for i in range(1, len(arr)):
            ff = g + arr[i] * (i // 2 + 1)
            gg = f + arr[i] * ((i + 1) // 2)
            f, g = ff, gg
            ans += f
        return ans
```

#### Java

```java
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int ans = arr[0], f = arr[0], g = 0;
        for (int i = 1; i < arr.length; ++i) {
            int ff = g + arr[i] * (i / 2 + 1);
            int gg = f + arr[i] * ((i + 1) / 2);
            f = ff;
            g = gg;
            ans += f;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = arr[0], f = arr[0], g = 0;
        for (int i = 1; i < arr.size(); ++i) {
            int ff = g + arr[i] * (i / 2 + 1);
            int gg = f + arr[i] * ((i + 1) / 2);
            f = ff;
            g = gg;
            ans += f;
        }
        return ans;
    }
};
```

#### Go

```go
func sumOddLengthSubarrays(arr []int) (ans int) {
	f, g := arr[0], 0
	ans = f
	for i := 1; i < len(arr); i++ {
		ff := g + arr[i]*(i/2+1)
		gg := f + arr[i]*((i+1)/2)
		f, g = ff, gg
		ans += f
	}
	return
}
```

#### TypeScript

```ts
function sumOddLengthSubarrays(arr: number[]): number {
    const n = arr.length;
    let [ans, f, g] = [arr[0], arr[0], 0];
    for (let i = 1; i < n; ++i) {
        const ff = g + arr[i] * (Math.floor(i / 2) + 1);
        const gg = f + arr[i] * Math.floor((i + 1) / 2);
        [f, g] = [ff, gg];
        ans += f;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let mut ans = arr[0];
        let mut f = arr[0];
        let mut g = 0;
        for i in 1..arr.len() {
            let ff = g + arr[i] * ((i as i32) / 2 + 1);
            let gg = f + arr[i] * (((i + 1) as i32) / 2);
            f = ff;
            g = gg;
            ans += f;
        }
        ans
    }
}
```

#### C

```c
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int ans = arr[0], f = arr[0], g = 0;
    for (int i = 1; i < arrSize; ++i) {
        int ff = g + arr[i] * (i / 2 + 1);
        int gg = f + arr[i] * ((i + 1) / 2);
        f = ff;
        g = gg;
        ans += f;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1589. 所有排列中的最大和](https://leetcode.cn/problems/maximum-sum-obtained-of-any-permutation){#1589}

{{< tabs "1589" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        n = len(nums)
        d = [0] * n
        for l, r in requests:
            d[l] += 1
            if r + 1 < n:
                d[r + 1] -= 1
        for i in range(1, n):
            d[i] += d[i - 1]
        nums.sort()
        d.sort()
        mod = 10**9 + 7
        return sum(a * b for a, b in zip(nums, d)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests) {
        int n = nums.length;
        int[] d = new int[n];
        for (var req : requests) {
            int l = req[0], r = req[1];
            d[l]++;
            if (r + 1 < n) {
                d[r + 1]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            d[i] += d[i - 1];
        }
        Arrays.sort(nums);
        Arrays.sort(d);
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1L * nums[i] * d[i]) % mod;
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
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int d[n];
        memset(d, 0, sizeof(d));
        for (auto& req : requests) {
            int l = req[0], r = req[1];
            d[l]++;
            if (r + 1 < n) {
                d[r + 1]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            d[i] += d[i - 1];
        }
        sort(nums.begin(), nums.end());
        sort(d, d + n);
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1LL * nums[i] * d[i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumRangeQuery(nums []int, requests [][]int) (ans int) {
	n := len(nums)
	d := make([]int, n)
	for _, req := range requests {
		l, r := req[0], req[1]
		d[l]++
		if r+1 < n {
			d[r+1]--
		}
	}
	for i := 1; i < n; i++ {
		d[i] += d[i-1]
	}
	sort.Ints(nums)
	sort.Ints(d)
	const mod = 1e9 + 7
	for i, a := range nums {
		b := d[i]
		ans = (ans + a*b) % mod
	}
	return
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumRangeQuery(nums: number[], requests: number[][]): number {
    const n = nums.length;
    const d = new Array(n).fill(0);
    for (const [l, r] of requests) {
        d[l]++;
        if (r + 1 < n) {
            d[r + 1]--;
        }
    }
    for (let i = 1; i < n; ++i) {
        d[i] += d[i - 1];
    }
    nums.sort((a, b) => a - b);
    d.sort((a, b) => a - b);
    let ans = 0;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < n; ++i) {
        ans = (ans + nums[i] * d[i]) % mod;
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

<p>有一个整数数组&nbsp;<code>nums</code>&nbsp;，和一个查询数组&nbsp;<code>requests</code>&nbsp;，其中&nbsp;<code>requests[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个查询求&nbsp;<code>nums[start<sub>i</sub>] + nums[start<sub>i</sub> + 1] + ... + nums[end<sub>i</sub> - 1] + nums[end<sub>i</sub>]</code>&nbsp;的结果&nbsp;，<code>start<sub>i</sub></code> 和&nbsp;<code>end<sub>i</sub></code>&nbsp;数组索引都是 <strong>从 0 开始</strong> 的。</p>

<p>你可以任意排列 <code>nums</code>&nbsp;中的数字，请你返回所有查询结果之和的最大值。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
<strong>输出：</strong>19
<strong>解释：</strong>一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
requests[0] -&gt; nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -&gt; nums[0] + nums[1] = 2 + 1 = 3
总和为：8 + 3 = 11。
一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
requests[0] -&gt; nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -&gt; nums[0] + nums[1] = 3 + 5  = 8
总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5,6], requests = [[0,1]]
<strong>输出：</strong>11
<strong>解释：</strong>一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
<strong>输出：</strong>47
<strong>解释：</strong>一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= requests.length &lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>requests[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub>&nbsp;&lt;= end<sub>i</sub>&nbsp;&lt;&nbsp;n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组 + 排序 + 贪心

我们观察发现，对于一次查询操作，会返回该查询区间 $[l, r]$ 中的所有元素之和。而题目要求的是所有查询操作的结果之和的最大值，也即是说，我们要累计所有查询操作的结果，使得这些结果之和最大。因此，如果一个下标 $i$ 在查询操作中出现的次数越多，那么我们就应该赋给下标 $i$ 一个较大的值，这样才能使得所有查询操作的结果之和最大。

因此，我们可以用差分数组的思想，统计每个下标在查询操作中出现的次数，然后对这些次数从小到大进行排序，然后对数组 $\textit{nums}$ 也从小到大进行排序，这样就能保证每个下标 $i$ 在查询操作中出现的次数越多，该下标对应的值 $\textit{nums}[i]$ 就越大。接下来，我们只需要将这些下标对应的值 $\textit{nums}[i]$ 与其在查询操作中出现的次数相乘，然后累加起来，就是所有查询操作的结果之和的最大值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        n = len(nums)
        d = [0] * n
        for l, r in requests:
            d[l] += 1
            if r + 1 < n:
                d[r + 1] -= 1
        for i in range(1, n):
            d[i] += d[i - 1]
        nums.sort()
        d.sort()
        mod = 10**9 + 7
        return sum(a * b for a, b in zip(nums, d)) % mod
```

#### Java

```java
class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests) {
        int n = nums.length;
        int[] d = new int[n];
        for (var req : requests) {
            int l = req[0], r = req[1];
            d[l]++;
            if (r + 1 < n) {
                d[r + 1]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            d[i] += d[i - 1];
        }
        Arrays.sort(nums);
        Arrays.sort(d);
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1L * nums[i] * d[i]) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int d[n];
        memset(d, 0, sizeof(d));
        for (auto& req : requests) {
            int l = req[0], r = req[1];
            d[l]++;
            if (r + 1 < n) {
                d[r + 1]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            d[i] += d[i - 1];
        }
        sort(nums.begin(), nums.end());
        sort(d, d + n);
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1LL * nums[i] * d[i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func maxSumRangeQuery(nums []int, requests [][]int) (ans int) {
	n := len(nums)
	d := make([]int, n)
	for _, req := range requests {
		l, r := req[0], req[1]
		d[l]++
		if r+1 < n {
			d[r+1]--
		}
	}
	for i := 1; i < n; i++ {
		d[i] += d[i-1]
	}
	sort.Ints(nums)
	sort.Ints(d)
	const mod = 1e9 + 7
	for i, a := range nums {
		b := d[i]
		ans = (ans + a*b) % mod
	}
	return
```

#### TypeScript

```ts
function maxSumRangeQuery(nums: number[], requests: number[][]): number {
    const n = nums.length;
    const d = new Array(n).fill(0);
    for (const [l, r] of requests) {
        d[l]++;
        if (r + 1 < n) {
            d[r + 1]--;
        }
    }
    for (let i = 1; i < n; ++i) {
        d[i] += d[i - 1];
    }
    nums.sort((a, b) => a - b);
    d.sort((a, b) => a - b);
    let ans = 0;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < n; ++i) {
        ans = (ans + nums[i] * d[i]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

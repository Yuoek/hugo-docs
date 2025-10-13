---
title: "3230_客户购买行为分析 🔒"
date: 2025-10-08T18:40:15+08:00
weight: 4
tags: [二分查找, 几何, 双指针, 哈希表, 字符串, 并查集, 广度优先搜索, 数学, 数据库, 数组, 数论, 枚举, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 计数]
---

{{< markmap >}}
### [3230_客户购买行为分析 🔒](#3230)
#### [数据库](#3230)
### [3231_要删除的递增子序列的最小数量 🔒](#3231)
#### [数组](#3231)
#### [二分查找](#3231)
### [3232_判断是否可以赢得数字游戏](#3232)
#### [数组](#3232)
#### [数学](#3232)
### [3233_统计不是特殊数字的数字数量](#3233)
#### [数组](#3233)
#### [数学](#3233)
#### [数论](#3233)
### [3234_统计 1 显著的字符串的数量](#3234)
#### [字符串](#3234)
#### [枚举](#3234)
#### [滑动窗口](#3234)
### [3235_判断矩形的两个角落是否可达](#3235)
#### [深度优先搜索](#3235)
#### [广度优先搜索](#3235)
#### [并查集](#3235)
#### [几何](#3235)
#### [数组](#3235)
#### [数学](#3235)
### [3236_首席执行官下属层级 🔒](#3236)
#### [数据库](#3236)
### [3237_Alt 和 Tab 模拟 🔒](#3237)
#### [数组](#3237)
#### [哈希表](#3237)
#### [模拟](#3237)
### [3238_求出胜利玩家的数目](#3238)
#### [数组](#3238)
#### [哈希表](#3238)
#### [计数](#3238)
### [3239_最少翻转次数使二进制矩阵回文 I](#3239)
#### [数组](#3239)
#### [双指针](#3239)
#### [矩阵](#3239)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3230_客户购买行为分析 🔒
___
#### 数据库
---
### 3231_要删除的递增子序列的最小数量 🔒
___
#### 数组
___
#### 二分查找
---
### 3232_判断是否可以赢得数字游戏
___
#### 数组
___
#### 数学
---
### 3233_统计不是特殊数字的数字数量
___
#### 数组
___
#### 数学
___
#### 数论
---
### 3234_统计 1 显著的字符串的数量
___
#### 字符串
___
#### 枚举
___
#### 滑动窗口
---
### 3235_判断矩形的两个角落是否可达
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 几何
___
#### 数组
___
#### 数学
---
### 3236_首席执行官下属层级 🔒
___
#### 数据库
---
### 3237_Alt 和 Tab 模拟 🔒
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 3238_求出胜利玩家的数目
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 3239_最少翻转次数使二进制矩阵回文 I
___
#### 数组
___
#### 双指针
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 双指针 |
| 哈希表 | 字符串 | 并查集 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 数论 | 枚举 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 矩阵 | 计数 |  |

# [3230. 客户购买行为分析 🔒](https://leetcode.cn/problems/customer-purchasing-behavior-analysis){#3230}

{{< tabs "3230" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT *
        FROM
            Transactions
            JOIN Products USING (product_id)
    ),
    P AS (
        SELECT
            customer_id,
            category,
            COUNT(1) cnt,
            MAX(transaction_date) max_date
        FROM T
        GROUP BY 1, 2
    ),
    R AS (
        SELECT
            customer_id,
            category,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY cnt DESC, max_date DESC
            ) rk
        FROM P
    )
SELECT
    t.customer_id,
    ROUND(SUM(amount), 2) total_amount,
    COUNT(1) transaction_count,
    COUNT(DISTINCT t.category) unique_categories,
    ROUND(AVG(amount), 2) avg_transaction_amount,
    r.category top_category,
    ROUND(COUNT(1) * 10 + SUM(amount) / 100, 2) loyalty_score
FROM
    T t
    JOIN R r ON t.customer_id = r.customer_id AND r.rk = 1
GROUP BY 1
ORDER BY 7 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Transactions</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| transaction_id   | int     |
| customer_id      | int     |
| product_id       | int     |
| transaction_date | date    |
| amount           | decimal |
+------------------+---------+
transaction_id 是这张表的唯一标识符。
这张表的每一行包含一次交易的信息，包括客户 ID，产品 ID，日期和总花费。
</pre>

<p>表：<code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| category    | varchar |
| price       | decimal |
+-------------+---------+
product_id 是这张表的唯一标识符。
这张表的每一行包含一个产品的信息，包括它的分类和价格。
</pre>

<p>编写一个解决方案来分析用户购买行为。对于 <strong>每个消费者</strong>，计算：</p>

<ul>
	<li>总消费额</li>
	<li>交易数量</li>
	<li>购买的 <strong>不同</strong> 产品类别的数量。</li>
	<li>平均消费金额。</li>
	<li><strong>最常购买</strong> 的产品类别（如果相同，选择最近交易的那个）</li>
	<li><strong>忠诚度分数 </strong>定义为：(交易数量 * 10) + (总消费&nbsp;/ 100)。</li>
</ul>

<p>将&nbsp;<code>total_amount</code>，&nbsp;<code>avg_transaction_amount</code>&nbsp;和&nbsp;<code>loyalty_score</code>&nbsp;舍入到&nbsp;<code>2</code> 位小数。</p>

<p>返回结果表以&nbsp;<code>loyalty_score</code>&nbsp;<strong>降序</strong> 排序，然后以<em>&nbsp;</em><code>customer_id</code><em>&nbsp;</em><strong>升序</strong><em> </em>排序。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>Transactions</code> 表：</p>

<pre class="example-io">
+----------------+-------------+------------+------------------+--------+
| transaction_id | customer_id | product_id | transaction_date | amount |
+----------------+-------------+------------+------------------+--------+
| 1              | 101         | 1          | 2023-01-01       | 100.00 |
| 2              | 101         | 2          | 2023-01-15       | 150.00 |
| 3              | 102         | 1          | 2023-01-01       | 100.00 |
| 4              | 102         | 3          | 2023-01-22       | 200.00 |
| 5              | 101         | 3          | 2023-02-10       | 200.00 |
+----------------+-------------+------------+------------------+--------+
</pre>

<p><code>Products</code> 表：</p>

<pre class="example-io">
+------------+----------+--------+
| product_id | category | price  |
+------------+----------+--------+
| 1          | A        | 100.00 |
| 2          | B        | 150.00 |
| 3          | C        | 200.00 |
+------------+----------+--------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+--------------+-------------------+-------------------+------------------------+--------------+---------------+
| customer_id | total_amount | transaction_count | unique_categories | avg_transaction_amount | top_category | loyalty_score |
+-------------+--------------+-------------------+-------------------+------------------------+--------------+---------------+
| 101         | 450.00       | 3                 | 3                 | 150.00                 | C            | 34.50         |
| 102         | 300.00       | 2                 | 2                 | 150.00                 | C            | 23.00         |
+-------------+--------------+-------------------+-------------------+------------------------+--------------+---------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于消费者 101：
	<ul>
		<li>总消费额：100.00 + 150.00 + 200.00 = 450.00</li>
		<li>交易次数：3</li>
		<li>不同分类：A, B, C （3 个分类）</li>
		<li>平均交易金额：450.00 / 3 = 150.00</li>
		<li>最高分类：C （消费者 101 在分类 A，B，C 分别进行了一次交易。因为所有分类的数量都一样，我们选择最近的那次交易，即在 2023-02-10 的分类&nbsp;C）</li>
		<li>忠诚度分数：(3 * 10) + (450.00 / 100) = 34.50</li>
	</ul>
	</li>
	<li>对于消费者 102：
	<ul>
		<li>总消费额：100.00 + 200.00 = 300.00</li>
		<li>交易次数：2</li>
		<li>不同分类：A, C（2 个分类）</li>
		<li>平均交易金额：300.00 / 2 = 150.00</li>
		<li>最高分类：C （消费者 102 在分类 A 和 C 分别进行了一次交易。因为所有分类的数量都一样，我们选择最近的那次交易，即在 2023-01-22 的分类&nbsp;C）</li>
		<li>忠诚度分数：(2 * 10) + (300.00 / 100) = 23.00</li>
	</ul>
	</li>
</ul>

<p><strong>注意：</strong>输出表以&nbsp;loyalty_score 降序排序，然后以&nbsp;customer_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 窗口函数 + 连接

我们首先将 `Transactions` 表和 `Products` 表连接起来，记录在临时表 `T` 中。

然后，我们使用 `T` 表计算每个用户在每个类别下的交易次数以及最近的交易日期，将结果保存在临时表 `P` 中。

接着，我们使用 `P` 表计算每个用户在每个类别下的交易次数的排名，将结果保存在临时表 `R` 中。

最后，我们使用 `T` 表和 `R` 表计算每个用户的总交易金额、交易次数、唯一类别数、平均交易金额、最常购买的类别、忠诚度分数，并按照忠诚度分数降序、用户 ID 升序的顺序返回结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT *
        FROM
            Transactions
            JOIN Products USING (product_id)
    ),
    P AS (
        SELECT
            customer_id,
            category,
            COUNT(1) cnt,
            MAX(transaction_date) max_date
        FROM T
        GROUP BY 1, 2
    ),
    R AS (
        SELECT
            customer_id,
            category,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY cnt DESC, max_date DESC
            ) rk
        FROM P
    )
SELECT
    t.customer_id,
    ROUND(SUM(amount), 2) total_amount,
    COUNT(1) transaction_count,
    COUNT(DISTINCT t.category) unique_categories,
    ROUND(AVG(amount), 2) avg_transaction_amount,
    r.category top_category,
    ROUND(COUNT(1) * 10 + SUM(amount) / 100, 2) loyalty_score
FROM
    T t
    JOIN R r ON t.customer_id = r.customer_id AND r.rk = 1
GROUP BY 1
ORDER BY 7 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3231. 要删除的递增子序列的最小数量 🔒](https://leetcode.cn/problems/minimum-number-of-increasing-subsequence-to-be-removed){#3231}

{{< tabs "3231" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        g = []
        for x in nums:
            l, r = 0, len(g)
            while l < r:
                mid = (l + r) >> 1
                if g[mid] < x:
                    r = mid
                else:
                    l = mid + 1
            if l == len(g):
                g.append(x)
            else:
                g[l] = x
        return len(g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        List<Integer> g = new ArrayList<>();
        for (int x : nums) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g.get(mid) < x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l == g.size()) {
                g.add(x);
            } else {
                g.set(l, x);
            }
        }
        return g.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> g;
        for (int x : nums) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g[mid] < x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l == g.size()) {
                g.push_back(x);
            } else {
                g[l] = x;
            }
        }
        return g.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) int {
	g := []int{}
	for _, x := range nums {
		l, r := 0, len(g)
		for l < r {
			mid := (l + r) >> 1
			if g[mid] < x {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if l == len(g) {
			g = append(g, x)
		} else {
			g[l] = x
		}
	}
	return len(g)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    const g: number[] = [];
    for (const x of nums) {
        let [l, r] = [0, g.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (g[mid] < x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l === g.length) {
            g.push(x);
        } else {
            g[l] = x;
        }
    }
    return g.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut g = Vec::new();
        for &x in nums.iter() {
            let mut l = 0;
            let mut r = g.len();
            while l < r {
                let mid = (l + r) / 2;
                if g[mid] < x {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if l == g.len() {
                g.push(x);
            } else {
                g[l] = x;
            }
        }
        g.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组&nbsp;<code>nums</code>，你可以执行任意次下面的操作：</p>

<ul>
	<li>从数组删除一个 <strong>严格递增</strong> 的 <span data-keyword="subsequence-array">子序列</span>。</li>
</ul>

<p>您的任务是找到使数组为 <strong>空</strong> 所需的 <strong>最小</strong> 操作数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,3,1,4,2]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们删除子序列&nbsp;<code>[1, 2]</code>，<code>[3, 4]</code>，<code>[5]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [1,2,3,4,5]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">1</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [5,4,3,2,1]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">5</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

我们从左到右遍历数组 $\textit{nums}$，对于每个元素 $x$，我们需要贪心地将其追加到前面序列中最后一个元素小于 $x$ 的最大值后面。如果找不到这样的元素，则说明当前元素 $x$ 比前面序列中的所有元素都小，我们需要新开辟一个序列，将 $x$ 放入其中。

这样分析下来，我们可以发现，前面序列中的最后一个元素呈单调递减的状态。因此，我们可以使用二分查找来找到前面序列中最后一个元素小于 $x$ 的第一个元素位置，然后将 $x$ 放入该位置。

最终，我们返回序列的个数即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        g = []
        for x in nums:
            l, r = 0, len(g)
            while l < r:
                mid = (l + r) >> 1
                if g[mid] < x:
                    r = mid
                else:
                    l = mid + 1
            if l == len(g):
                g.append(x)
            else:
                g[l] = x
        return len(g)
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        List<Integer> g = new ArrayList<>();
        for (int x : nums) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g.get(mid) < x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l == g.size()) {
                g.add(x);
            } else {
                g.set(l, x);
            }
        }
        return g.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> g;
        for (int x : nums) {
            int l = 0, r = g.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (g[mid] < x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l == g.size()) {
                g.push_back(x);
            } else {
                g[l] = x;
            }
        }
        return g.size();
    }
};
```

#### Go

```go
func minOperations(nums []int) int {
	g := []int{}
	for _, x := range nums {
		l, r := 0, len(g)
		for l < r {
			mid := (l + r) >> 1
			if g[mid] < x {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if l == len(g) {
			g = append(g, x)
		} else {
			g[l] = x
		}
	}
	return len(g)
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    const g: number[] = [];
    for (const x of nums) {
        let [l, r] = [0, g.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (g[mid] < x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l === g.length) {
            g.push(x);
        } else {
            g[l] = x;
        }
    }
    return g.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut g = Vec::new();
        for &x in nums.iter() {
            let mut l = 0;
            let mut r = g.len();
            while l < r {
                let mid = (l + r) / 2;
                if g[mid] < x {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if l == g.len() {
                g.push(x);
            } else {
                g[l] = x;
            }
        }
        g.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3232. 判断是否可以赢得数字游戏](https://leetcode.cn/problems/find-if-digit-game-can-be-won){#3232}

{{< tabs "3232" >}}

{{% tab "python" %}}
```python
class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        a = sum(x for x in nums if x < 10)
        b = sum(x for x in nums if x > 9)
        return a != b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canAliceWin(int[] nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x < 10) {
                a += x;
            } else {
                b += x;
            }
        }
        return a != b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x < 10) {
                a += x;
            } else {
                b += x;
            }
        }
        return a != b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canAliceWin(nums []int) bool {
	a, b := 0, 0
	for _, x := range nums {
		if x < 10 {
			a += x
		} else {
			b += x
		}
	}
	return a != b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canAliceWin(nums: number[]): boolean {
    let [a, b] = [0, 0];
    for (const x of nums) {
        if (x < 10) {
            a += x;
        } else {
            b += x;
        }
    }
    return a !== b;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>正整数 </strong>数组 <code>nums</code>。</p>

<p>Alice 和 Bob 正在玩游戏。在游戏中，Alice 可以从 <code>nums</code> 中选择所有个位数 <strong>或</strong> 所有两位数，剩余的数字归 Bob 所有。如果 Alice 所选数字之和 <strong>严格大于 </strong>Bob 的数字之和，则 Alice 获胜。</p>

<p>如果 Alice 能赢得这场游戏，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3,4,10]</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>Alice&nbsp;不管选个位数还是两位数都无法赢得比赛。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3,4,5,14]</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>Alice&nbsp;选择个位数可以赢得比赛，所选数字之和为 15。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [5,5,5,25]</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>Alice&nbsp;选择两位数可以赢得比赛，所选数字之和为 25。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 99</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和

根据题目描述，只要个位数之和不等于两位数之和，那么 Alice 一定可以选择一个较大的和来获胜。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        a = sum(x for x in nums if x < 10)
        b = sum(x for x in nums if x > 9)
        return a != b
```

#### Java

```java
class Solution {
    public boolean canAliceWin(int[] nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x < 10) {
                a += x;
            } else {
                b += x;
            }
        }
        return a != b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x < 10) {
                a += x;
            } else {
                b += x;
            }
        }
        return a != b;
    }
};
```

#### Go

```go
func canAliceWin(nums []int) bool {
	a, b := 0, 0
	for _, x := range nums {
		if x < 10 {
			a += x
		} else {
			b += x
		}
	}
	return a != b
}
```

#### TypeScript

```ts
function canAliceWin(nums: number[]): boolean {
    let [a, b] = [0, 0];
    for (const x of nums) {
        if (x < 10) {
            a += x;
        } else {
            b += x;
        }
    }
    return a !== b;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3233. 统计不是特殊数字的数字数量](https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special){#3233}

{{< tabs "3233" >}}

{{% tab "python" %}}
```python
m = 31623
primes = [True] * (m + 1)
primes[0] = primes[1] = False
for i in range(2, m + 1):
    if primes[i]:
        for j in range(i + i, m + 1, i):
            primes[j] = False


class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        lo = ceil(sqrt(l))
        hi = floor(sqrt(r))
        cnt = sum(primes[i] for i in range(lo, hi + 1))
        return r - l + 1 - cnt
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    static int m = 31623;
    static boolean[] primes = new boolean[m + 1];

    static {
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i <= m; i++) {
            if (primes[i]) {
                for (int j = i + i; j <= m; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    public int nonSpecialCount(int l, int r) {
        int lo = (int) Math.ceil(Math.sqrt(l));
        int hi = (int) Math.floor(Math.sqrt(r));
        int cnt = 0;
        for (int i = lo; i <= hi; i++) {
            if (primes[i]) {
                cnt++;
            }
        }
        return r - l + 1 - cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int m = 31623;
bool primes[m + 1];

auto init = [] {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    for (int i = 2; i <= m; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= m; j += i) {
                primes[j] = false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lo = ceil(sqrt(l));
        int hi = floor(sqrt(r));
        int cnt = 0;
        for (int i = lo; i <= hi; ++i) {
            if (primes[i]) {
                ++cnt;
            }
        }
        return r - l + 1 - cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const m = 31623

var primes [m + 1]bool

func init() {
	for i := range primes {
		primes[i] = true
	}
	primes[0] = false
	primes[1] = false
	for i := 2; i <= m; i++ {
		if primes[i] {
			for j := i * 2; j <= m; j += i {
				primes[j] = false
			}
		}
	}
}

func nonSpecialCount(l int, r int) int {
	lo := int(math.Ceil(math.Sqrt(float64(l))))
	hi := int(math.Floor(math.Sqrt(float64(r))))
	cnt := 0
	for i := lo; i <= hi; i++ {
		if primes[i] {
			cnt++
		}
	}
	return r - l + 1 - cnt
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const m = 31623;
const primes: boolean[] = Array(m + 1).fill(true);

(() => {
    primes[0] = primes[1] = false;
    for (let i = 2; i <= m; ++i) {
        if (primes[i]) {
            for (let j = i * 2; j <= m; j += i) {
                primes[j] = false;
            }
        }
    }
})();

function nonSpecialCount(l: number, r: number): number {
    const lo = Math.ceil(Math.sqrt(l));
    const hi = Math.floor(Math.sqrt(r));
    let cnt = 0;
    for (let i = lo; i <= hi; ++i) {
        if (primes[i]) {
            ++cnt;
        }
    }
    return r - l + 1 - cnt;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个<strong> 正整数 </strong><code>l</code> 和 <code>r</code>。对于任何数字 <code>x</code>，<code>x</code> 的所有正因数（除了 <code>x</code> 本身）被称为 <code>x</code> 的 <strong>真因数</strong>。</p>

<p><span class="text-only" data-eleid="13" style="white-space: pre;">如果一个数字恰好仅有两个</span> <strong>真因数</strong>，则称该数字为 <strong>特殊数字</strong>。例如：</p>

<ul>
	<li>数字 4 是<strong> 特殊数字</strong>，因为它的真因数为 1 和 2。</li>
	<li>数字 6 不是 <strong>特殊数字</strong>，因为它的真因数为 1、2 和 3。</li>
</ul>

<p>返回区间 <code>[l, r]</code> 内<strong> 不是 特殊数字 </strong>的数字数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">l = 5, r = 7</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>区间 <code>[5, 7]</code> 内不存在特殊数字。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">l = 4, r = 16</span></p>

<p><strong>输出：</strong> <span class="reset-io">11</span></p>

<p><strong>解释：</strong></p>

<p>区间 <code>[4, 16]</code> 内的特殊数字为 4 和 9。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= l &lt;= r &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

根据题目描述，我们可以发现，只有质数的平方才是特殊数字。因此，我们可以先预处理出小于等于 $\sqrt{10^9}$ 的所有质数，然后遍历区间 $[\lceil\sqrt{l}\rceil, \lfloor\sqrt{r}\rfloor]$，统计出区间内的质数个数 $\textit{cnt}$，最后返回 $r - l + 1 - \textit{cnt}$ 即可。

时间复杂度 $O(\sqrt{m})$，空间复杂度 $O(\sqrt{m})$。其中 $m = 10^9$。

<!-- tabs:start -->

#### Python3

```python
m = 31623
primes = [True] * (m + 1)
primes[0] = primes[1] = False
for i in range(2, m + 1):
    if primes[i]:
        for j in range(i + i, m + 1, i):
            primes[j] = False


class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        lo = ceil(sqrt(l))
        hi = floor(sqrt(r))
        cnt = sum(primes[i] for i in range(lo, hi + 1))
        return r - l + 1 - cnt
```

#### Java

```java
class Solution {
    static int m = 31623;
    static boolean[] primes = new boolean[m + 1];

    static {
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i <= m; i++) {
            if (primes[i]) {
                for (int j = i + i; j <= m; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    public int nonSpecialCount(int l, int r) {
        int lo = (int) Math.ceil(Math.sqrt(l));
        int hi = (int) Math.floor(Math.sqrt(r));
        int cnt = 0;
        for (int i = lo; i <= hi; i++) {
            if (primes[i]) {
                cnt++;
            }
        }
        return r - l + 1 - cnt;
    }
}
```

#### C++

```cpp
const int m = 31623;
bool primes[m + 1];

auto init = [] {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    for (int i = 2; i <= m; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= m; j += i) {
                primes[j] = false;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lo = ceil(sqrt(l));
        int hi = floor(sqrt(r));
        int cnt = 0;
        for (int i = lo; i <= hi; ++i) {
            if (primes[i]) {
                ++cnt;
            }
        }
        return r - l + 1 - cnt;
    }
};
```

#### Go

```go
const m = 31623

var primes [m + 1]bool

func init() {
	for i := range primes {
		primes[i] = true
	}
	primes[0] = false
	primes[1] = false
	for i := 2; i <= m; i++ {
		if primes[i] {
			for j := i * 2; j <= m; j += i {
				primes[j] = false
			}
		}
	}
}

func nonSpecialCount(l int, r int) int {
	lo := int(math.Ceil(math.Sqrt(float64(l))))
	hi := int(math.Floor(math.Sqrt(float64(r))))
	cnt := 0
	for i := lo; i <= hi; i++ {
		if primes[i] {
			cnt++
		}
	}
	return r - l + 1 - cnt
}
```

#### TypeScript

```ts
const m = 31623;
const primes: boolean[] = Array(m + 1).fill(true);

(() => {
    primes[0] = primes[1] = false;
    for (let i = 2; i <= m; ++i) {
        if (primes[i]) {
            for (let j = i * 2; j <= m; j += i) {
                primes[j] = false;
            }
        }
    }
})();

function nonSpecialCount(l: number, r: number): number {
    const lo = Math.ceil(Math.sqrt(l));
    const hi = Math.floor(Math.sqrt(r));
    let cnt = 0;
    for (let i = lo; i <= hi; ++i) {
        if (primes[i]) {
            ++cnt;
        }
    }
    return r - l + 1 - cnt;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3234. 统计 1 显著的字符串的数量](https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones){#3234}

{{< tabs "3234" >}}

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

<p>给你一个二进制字符串 <code>s</code>。</p>

<p>请你统计并返回其中 <strong>1 显著 </strong> 的 <span data-keyword="substring-nonempty">子字符串</span> 的数量。</p>

<p>如果字符串中 1 的数量 <strong>大于或等于</strong> 0 的数量的 <strong>平方</strong>，则认为该字符串是一个 <strong>1 显著</strong> 的字符串 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "00011"</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>1 显著的子字符串如下表所示。</p>
</div>

<table>
	<thead>
		<tr>
			<th>i</th>
			<th>j</th>
			<th>s[i..j]</th>
			<th>0 的数量</th>
			<th>1 的数量</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>3</td>
			<td>3</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td>4</td>
			<td>4</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td>2</td>
			<td>3</td>
			<td>01</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>3</td>
			<td>4</td>
			<td>11</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>4</td>
			<td>011</td>
			<td>1</td>
			<td>2</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "101101"</span></p>

<p><strong>输出：</strong><span class="example-io">16</span></p>

<p><strong>解释：</strong></p>

<p>1 不显著的子字符串如下表所示。</p>

<p>总共有 21 个子字符串，其中 5 个是 1 不显著字符串，因此有 16 个 1 显著子字符串。</p>
</div>

<table>
	<thead>
		<tr>
			<th>i</th>
			<th>j</th>
			<th>s[i..j]</th>
			<th>0 的数量</th>
			<th>1 的数量</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<td>4</td>
			<td>4</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<td>1</td>
			<td>4</td>
			<td>0110</td>
			<td>2</td>
			<td>2</td>
		</tr>
		<tr>
			<td>0</td>
			<td>4</td>
			<td>10110</td>
			<td>2</td>
			<td>3</td>
		</tr>
		<tr>
			<td>1</td>
			<td>5</td>
			<td>01101</td>
			<td>2</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>s</code> 仅包含字符 <code>'0'</code> 和 <code>'1'</code>。</li>
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

# [3235. 判断矩形的两个角落是否可达](https://leetcode.cn/problems/check-if-the-rectangle-corner-is-reachable){#3235}

{{< tabs "3235" >}}

{{% tab "python" %}}
```python
class Solution:
    def canReachCorner(
        self, xCorner: int, yCorner: int, circles: List[List[int]]
    ) -> bool:
        def in_circle(x: int, y: int, cx: int, cy: int, r: int) -> int:
            return (x - cx) ** 2 + (y - cy) ** 2 <= r**2

        def cross_left_top(cx: int, cy: int, r: int) -> bool:
            a = abs(cx) <= r and 0 <= cy <= yCorner
            b = abs(cy - yCorner) <= r and 0 <= cx <= xCorner
            return a or b

        def cross_right_bottom(cx: int, cy: int, r: int) -> bool:
            a = abs(cx - xCorner) <= r and 0 <= cy <= yCorner
            b = abs(cy) <= r and 0 <= cx <= xCorner
            return a or b

        def dfs(i: int) -> bool:
            x1, y1, r1 = circles[i]
            if cross_right_bottom(x1, y1, r1):
                return True
            vis[i] = True
            for j, (x2, y2, r2) in enumerate(circles):
                if vis[j] or not ((x1 - x2) ** 2 + (y1 - y2) ** 2 <= (r1 + r2) ** 2):
                    continue
                if (
                    (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner)
                    and (y1 * r2 + y2 * r1 < (r1 + r2) * yCorner)
                    and dfs(j)
                ):
                    return True
            return False

        vis = [False] * len(circles)
        for i, (x, y, r) in enumerate(circles):
            if in_circle(0, 0, x, y, r) or in_circle(xCorner, yCorner, x, y, r):
                return False
            if (not vis[i]) and cross_left_top(x, y, r) and dfs(i):
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] circles;
    private int xCorner, yCorner;
    private boolean[] vis;

    public boolean canReachCorner(int xCorner, int yCorner, int[][] circles) {
        int n = circles.length;
        this.circles = circles;
        this.xCorner = xCorner;
        this.yCorner = yCorner;
        vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            var c = circles[i];
            int x = c[0], y = c[1], r = c[2];
            if (inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
                return false;
            }
        }
        return true;
    }

    private boolean inCircle(long x, long y, long cx, long cy, long r) {
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    }

    private boolean crossLeftTop(long cx, long cy, long r) {
        boolean a = Math.abs(cx) <= r && (cy >= 0 && cy <= yCorner);
        boolean b = Math.abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    private boolean crossRightBottom(long cx, long cy, long r) {
        boolean a = Math.abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
        boolean b = Math.abs(cy) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    private boolean dfs(int i) {
        var c = circles[i];
        long x1 = c[0], y1 = c[1], r1 = c[2];
        if (crossRightBottom(x1, y1, r1)) {
            return true;
        }
        vis[i] = true;
        for (int j = 0; j < circles.length; ++j) {
            var c2 = circles[j];
            long x2 = c2[0], y2 = c2[1], r2 = c2[2];
            if (vis[j]) {
                continue;
            }
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue;
            }
            if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner && y1 * r2 + y2 * r1 < (r1 + r2) * yCorner
                && dfs(j)) {
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
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        using ll = long long;
        auto inCircle = [&](ll x, ll y, ll cx, ll cy, ll r) {
            return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
        };
        auto crossLeftTop = [&](ll cx, ll cy, ll r) {
            bool a = abs(cx) <= r && (cy >= 0 && cy <= yCorner);
            bool b = abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
            return a || b;
        };
        auto crossRightBottom = [&](ll cx, ll cy, ll r) {
            bool a = abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
            bool b = abs(cy) <= r && (cx >= 0 && cx <= xCorner);
            return a || b;
        };

        int n = circles.size();
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> bool {
            auto c = circles[i];
            ll x1 = c[0], y1 = c[1], r1 = c[2];
            if (crossRightBottom(x1, y1, r1)) {
                return true;
            }
            vis[i] = true;
            for (int j = 0; j < n; ++j) {
                if (vis[j]) {
                    continue;
                }
                auto c2 = circles[j];
                ll x2 = c2[0], y2 = c2[1], r2 = c2[2];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                    continue;
                }
                if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner && y1 * r2 + y2 * r1 < (r1 + r2) * yCorner
                    && dfs(j)) {
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < n; ++i) {
            auto c = circles[i];
            ll x = c[0], y = c[1], r = c[2];
            if (inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
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
func canReachCorner(xCorner int, yCorner int, circles [][]int) bool {
	inCircle := func(x, y, cx, cy, r int) bool {
		dx, dy := x-cx, y-cy
		return dx*dx+dy*dy <= r*r
	}

	crossLeftTop := func(cx, cy, r int) bool {
		a := abs(cx) <= r && cy >= 0 && cy <= yCorner
		b := abs(cy-yCorner) <= r && cx >= 0 && cx <= xCorner
		return a || b
	}

	crossRightBottom := func(cx, cy, r int) bool {
		a := abs(cx-xCorner) <= r && cy >= 0 && cy <= yCorner
		b := abs(cy) <= r && cx >= 0 && cx <= xCorner
		return a || b
	}

	vis := make([]bool, len(circles))

	var dfs func(int) bool
	dfs = func(i int) bool {
		c := circles[i]
		x1, y1, r1 := c[0], c[1], c[2]
		if crossRightBottom(x1, y1, r1) {
			return true
		}
		vis[i] = true
		for j, c2 := range circles {
			if vis[j] {
				continue
			}
			x2, y2, r2 := c2[0], c2[1], c2[2]
			if (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) > (r1+r2)*(r1+r2) {
				continue
			}
			if x1*r2+x2*r1 < (r1+r2)*xCorner && y1*r2+y2*r1 < (r1+r2)*yCorner && dfs(j) {
				return true
			}
		}
		return false
	}

	for i, c := range circles {
		x, y, r := c[0], c[1], c[2]
		if inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r) {
			return false
		}
		if !vis[i] && crossLeftTop(x, y, r) && dfs(i) {
			return false
		}
	}
	return true
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
function canReachCorner(xCorner: number, yCorner: number, circles: number[][]): boolean {
    const inCircle = (x: bigint, y: bigint, cx: bigint, cy: bigint, r: bigint): boolean => {
        const dx = x - cx;
        const dy = y - cy;
        return dx * dx + dy * dy <= r * r;
    };

    const crossLeftTop = (cx: bigint, cy: bigint, r: bigint): boolean => {
        const a = BigInt(Math.abs(Number(cx))) <= r && cy >= 0n && cy <= BigInt(yCorner);
        const b =
            BigInt(Math.abs(Number(cy - BigInt(yCorner)))) <= r &&
            cx >= 0n &&
            cx <= BigInt(xCorner);
        return a || b;
    };

    const crossRightBottom = (cx: bigint, cy: bigint, r: bigint): boolean => {
        const a =
            BigInt(Math.abs(Number(cx - BigInt(xCorner)))) <= r &&
            cy >= 0n &&
            cy <= BigInt(yCorner);
        const b = BigInt(Math.abs(Number(cy))) <= r && cx >= 0n && cx <= BigInt(xCorner);
        return a || b;
    };

    const n = circles.length;
    const vis: boolean[] = new Array(n).fill(false);

    const dfs = (i: number): boolean => {
        const [x1, y1, r1] = circles[i].map(BigInt);
        if (crossRightBottom(x1, y1, r1)) {
            return true;
        }
        vis[i] = true;
        for (let j = 0; j < n; j++) {
            if (vis[j]) continue;
            const [x2, y2, r2] = circles[j].map(BigInt);
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue;
            }
            if (
                x1 * r2 + x2 * r1 < (r1 + r2) * BigInt(xCorner) &&
                y1 * r2 + y2 * r1 < (r1 + r2) * BigInt(yCorner) &&
                dfs(j)
            ) {
                return true;
            }
        }
        return false;
    };

    for (let i = 0; i < n; i++) {
        const [x, y, r] = circles[i].map(BigInt);
        if (inCircle(0n, 0n, x, y, r) || inCircle(BigInt(xCorner), BigInt(yCorner), x, y, r)) {
            return false;
        }
        if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
            return false;
        }
    }

    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_reach_corner(x_corner: i32, y_corner: i32, circles: Vec<Vec<i32>>) -> bool {
        let n = circles.len();
        let mut vis = vec![false; n];

        let in_circle = |x: i64, y: i64, cx: i64, cy: i64, r: i64| -> bool {
            (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r
        };

        let cross_left_top = |cx: i64, cy: i64, r: i64| -> bool {
            let a = cx.abs() <= r && (cy >= 0 && cy <= y_corner as i64);
            let b = (cy - y_corner as i64).abs() <= r && (cx >= 0 && cx <= x_corner as i64);
            a || b
        };

        let cross_right_bottom = |cx: i64, cy: i64, r: i64| -> bool {
            let a = (cx - x_corner as i64).abs() <= r && (cy >= 0 && cy <= y_corner as i64);
            let b = cy.abs() <= r && (cx >= 0 && cx <= x_corner as i64);
            a || b
        };
        fn dfs(
            circles: &Vec<Vec<i32>>,
            vis: &mut Vec<bool>,
            i: usize,
            x_corner: i32,
            y_corner: i32,
            cross_right_bottom: &dyn Fn(i64, i64, i64) -> bool,
        ) -> bool {
            let c = &circles[i];
            let (x1, y1, r1) = (c[0] as i64, c[1] as i64, c[2] as i64);

            if cross_right_bottom(x1, y1, r1) {
                return true;
            }

            vis[i] = true;

            for j in 0..circles.len() {
                if vis[j] {
                    continue;
                }

                let c2 = &circles[j];
                let (x2, y2, r2) = (c2[0] as i64, c2[1] as i64, c2[2] as i64);

                if (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2) {
                    continue;
                }

                if x1 * r2 + x2 * r1 < (r1 + r2) * x_corner as i64
                    && y1 * r2 + y2 * r1 < (r1 + r2) * y_corner as i64
                    && dfs(circles, vis, j, x_corner, y_corner, cross_right_bottom)
                {
                    return true;
                }
            }
            false
        }

        for i in 0..n {
            let c = &circles[i];
            let (x, y, r) = (c[0] as i64, c[1] as i64, c[2] as i64);

            if in_circle(0, 0, x, y, r) || in_circle(x_corner as i64, y_corner as i64, x, y, r) {
                return false;
            }

            if !vis[i]
                && cross_left_top(x, y, r)
                && dfs(
                    &circles,
                    &mut vis,
                    i,
                    x_corner,
                    y_corner,
                    &cross_right_bottom,
                )
            {
                return false;
            }
        }

        true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>xCorner</code> 和&nbsp;<code>yCorner</code>&nbsp;和一个二维整数数组&nbsp;<code>circles</code>&nbsp;，其中&nbsp;<code>circles[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;表示一个圆心在&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;半径为&nbsp;<code>r<sub>i</sub></code>&nbsp;的圆。</p>

<p>坐标平面内有一个左下角在原点，右上角在&nbsp;<code>(xCorner, yCorner)</code>&nbsp;的矩形。你需要判断是否存在一条从左下角到右上角的路径满足：路径&nbsp;<strong>完全</strong>&nbsp;在矩形内部，<strong>不会</strong>&nbsp;触碰或者经过 <strong>任何</strong>&nbsp;圆的内部和边界，同时&nbsp;<strong>只</strong> 在起点和终点接触到矩形。</p>

<p>如果存在这样的路径，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>X = 3, Y = 4, circles = [[2,1,1]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3235.Check%20if%20the%20Rectangle%20Corner%20Is%20Reachable/images/example2circle1.png" style="width: 346px; height: 264px;" /></p>

<p>黑色曲线表示一条从&nbsp;<code>(0, 0)</code>&nbsp;到&nbsp;<code>(3, 4)</code>&nbsp;的路径。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>X = 3, Y = 3, circles = [[1,1,2]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3235.Check%20if%20the%20Rectangle%20Corner%20Is%20Reachable/images/example1circle.png" style="width: 346px; height: 264px;" /></p>

<p>不存在从&nbsp;<code>(0, 0)</code> 到&nbsp;<code>(3, 3)</code>&nbsp;的路径。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>X = 3, Y = 3, circles = [[2,1,1],[1,2,1]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3235.Check%20if%20the%20Rectangle%20Corner%20Is%20Reachable/images/example0circle.png" style="width: 346px; height: 264px;" /></p>

<p>不存在从&nbsp;<code>(0, 0)</code>&nbsp;到&nbsp;<code>(3, 3)</code>&nbsp;的路径。</p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">X = 4, Y = 4, circles = [[5,5,1]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3235.Check%20if%20the%20Rectangle%20Corner%20Is%20Reachable/images/rectangles.png" style="width: 346px; height: 264px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= xCorner, yCorner&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= circles.length &lt;= 1000</code></li>
	<li><code>circles[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 数学

根据题意，我们分情况讨论：

当 `circles` 中只有一个圆时：

1. 如果起点 $(0, 0)$ 在圆内（包括边界），或者终点 $(\textit{xCorner}, \textit{yCorner})$ 在圆内，那么无法满足“不触碰圆”的条件；
1. 如果圆与矩形的左侧或上侧有交点，且与矩形的右侧或下侧有交点，这种情况下，圆会阻断从矩形左下角到右上角的路径，也无法满足“不触碰圆”的条件。

当 `circles` 中有多个圆时：

1. 与上述情况类似，如果起点或终点在圆内时，无法满足“不触碰圆”的条件。
2. 如果有多个圆，多个圆之间可能在矩形内相交，合并形成更大的障碍区域。只要这个障碍区域与矩形的左侧或上侧有交点，且与矩形的右侧或下侧有交点，那么无法满足“不触碰圆”的条件。如果相交区域不在矩形内部，不能进行合并，因为相交的区域无法阻断矩形内部路径。另外，如果相交的区域有一部分在矩形内，有一部分在矩形外，这些圆都可以作为搜索的起点或终点，可以合并，也可以不合并。我们只要任选相交的其中一个点，如果这个点在矩形内，我们就可以将这些圆合并。

根据上述分析，我们遍历所有圆，对于当前遍历到的圆，如果起点或终点在圆内，我们直接返回 `false`。否则，如果这个点没有被访问过，且这个圆与矩形的左侧或上侧有交点，我们就从这个圆开始进行深度优先搜索，搜索过程中，如果找到了一个圆，它与矩形的右侧或下侧有交点，说明圆形成的障碍区域阻断了从矩形左下角到右上角的路径，我们就返回 `false`。

我们定义 $\textit{dfs}(i)$ 表示从第 $i$ 个圆开始进行深度优先搜索，如果找到了一个圆，它与矩形的右侧或下侧有交点，返回 `true`，否则返回 `false`。

函数 $\textit{dfs}(i)$ 的执行过程如下：

1. 如果当前圆与矩形的右侧或下侧有交点，返回 `true`；
1. 否则，我们将当前圆标记为已访问；
1. 接下来，遍历其它所有圆，如果圆 $j$ 没被访问过，且圆 $i$ 和圆 $j$ 相交，且这两个圆的其中一个交点在矩形内，我们就继续从圆 $j$ 开始进行深度优先搜索，如果找到了一个圆，它与矩形的右侧或下侧有交点，返回 `true`；
1. 如果没有找到这样的圆，返回 `false`。

上面的过程中，我们需要在圆 $O_1 = (x_1, y_1, r_1)$ 和 $O_2 = (x_2, y_2, r_2)$ 之间判断是否相交，如果两个圆相交，那么它们的圆心之间的距离不超过两个圆的半径之和，即 $(x_1 - x_2)^2 + (y_1 - y_2)^2 \le (r_1 + r_2)^2$。

我们还需要寻找两个圆的一个交点，我们取一个点 $A = (x, y)$，满足 $\frac{O_1 A}{O_1 O_2} = \frac{r_1}{r_1 + r_2}$，如果两圆相交，那么点 $A$ 一定在交集中，此时 $\frac{x - x_1}{x_2 - x_1} = \frac{r_1}{r_1 + r_2}$，解得 $x = \frac{x_1 r_2 + x_2 r_1}{r_1 + r_2}$，同理，有 $y = \frac{y_1 r_2 + y_2 r_1}{r_1 + r_2}$。只要这个点在矩形内，我们就可以继续进行深度优先搜索，即满足：

$$
\begin{cases}
x_1 r_2 + x_2 r_1 < (r_1 + r_2) \times \textit{xCorner} \\
y_1 r_2 + y_2 r_1 < (r_1 + r_2) \times \textit{yCorner}
\end{cases}
$$

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为圆的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canReachCorner(
        self, xCorner: int, yCorner: int, circles: List[List[int]]
    ) -> bool:
        def in_circle(x: int, y: int, cx: int, cy: int, r: int) -> int:
            return (x - cx) ** 2 + (y - cy) ** 2 <= r**2

        def cross_left_top(cx: int, cy: int, r: int) -> bool:
            a = abs(cx) <= r and 0 <= cy <= yCorner
            b = abs(cy - yCorner) <= r and 0 <= cx <= xCorner
            return a or b

        def cross_right_bottom(cx: int, cy: int, r: int) -> bool:
            a = abs(cx - xCorner) <= r and 0 <= cy <= yCorner
            b = abs(cy) <= r and 0 <= cx <= xCorner
            return a or b

        def dfs(i: int) -> bool:
            x1, y1, r1 = circles[i]
            if cross_right_bottom(x1, y1, r1):
                return True
            vis[i] = True
            for j, (x2, y2, r2) in enumerate(circles):
                if vis[j] or not ((x1 - x2) ** 2 + (y1 - y2) ** 2 <= (r1 + r2) ** 2):
                    continue
                if (
                    (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner)
                    and (y1 * r2 + y2 * r1 < (r1 + r2) * yCorner)
                    and dfs(j)
                ):
                    return True
            return False

        vis = [False] * len(circles)
        for i, (x, y, r) in enumerate(circles):
            if in_circle(0, 0, x, y, r) or in_circle(xCorner, yCorner, x, y, r):
                return False
            if (not vis[i]) and cross_left_top(x, y, r) and dfs(i):
                return False
        return True
```

#### Java

```java
class Solution {
    private int[][] circles;
    private int xCorner, yCorner;
    private boolean[] vis;

    public boolean canReachCorner(int xCorner, int yCorner, int[][] circles) {
        int n = circles.length;
        this.circles = circles;
        this.xCorner = xCorner;
        this.yCorner = yCorner;
        vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            var c = circles[i];
            int x = c[0], y = c[1], r = c[2];
            if (inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
                return false;
            }
        }
        return true;
    }

    private boolean inCircle(long x, long y, long cx, long cy, long r) {
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    }

    private boolean crossLeftTop(long cx, long cy, long r) {
        boolean a = Math.abs(cx) <= r && (cy >= 0 && cy <= yCorner);
        boolean b = Math.abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    private boolean crossRightBottom(long cx, long cy, long r) {
        boolean a = Math.abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
        boolean b = Math.abs(cy) <= r && (cx >= 0 && cx <= xCorner);
        return a || b;
    }

    private boolean dfs(int i) {
        var c = circles[i];
        long x1 = c[0], y1 = c[1], r1 = c[2];
        if (crossRightBottom(x1, y1, r1)) {
            return true;
        }
        vis[i] = true;
        for (int j = 0; j < circles.length; ++j) {
            var c2 = circles[j];
            long x2 = c2[0], y2 = c2[1], r2 = c2[2];
            if (vis[j]) {
                continue;
            }
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue;
            }
            if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner && y1 * r2 + y2 * r1 < (r1 + r2) * yCorner
                && dfs(j)) {
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
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) {
        using ll = long long;
        auto inCircle = [&](ll x, ll y, ll cx, ll cy, ll r) {
            return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
        };
        auto crossLeftTop = [&](ll cx, ll cy, ll r) {
            bool a = abs(cx) <= r && (cy >= 0 && cy <= yCorner);
            bool b = abs(cy - yCorner) <= r && (cx >= 0 && cx <= xCorner);
            return a || b;
        };
        auto crossRightBottom = [&](ll cx, ll cy, ll r) {
            bool a = abs(cx - xCorner) <= r && (cy >= 0 && cy <= yCorner);
            bool b = abs(cy) <= r && (cx >= 0 && cx <= xCorner);
            return a || b;
        };

        int n = circles.size();
        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> bool {
            auto c = circles[i];
            ll x1 = c[0], y1 = c[1], r1 = c[2];
            if (crossRightBottom(x1, y1, r1)) {
                return true;
            }
            vis[i] = true;
            for (int j = 0; j < n; ++j) {
                if (vis[j]) {
                    continue;
                }
                auto c2 = circles[j];
                ll x2 = c2[0], y2 = c2[1], r2 = c2[2];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                    continue;
                }
                if (x1 * r2 + x2 * r1 < (r1 + r2) * xCorner && y1 * r2 + y2 * r1 < (r1 + r2) * yCorner
                    && dfs(j)) {
                    return true;
                }
            }
            return false;
        };

        for (int i = 0; i < n; ++i) {
            auto c = circles[i];
            ll x = c[0], y = c[1], r = c[2];
            if (inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r)) {
                return false;
            }
            if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canReachCorner(xCorner int, yCorner int, circles [][]int) bool {
	inCircle := func(x, y, cx, cy, r int) bool {
		dx, dy := x-cx, y-cy
		return dx*dx+dy*dy <= r*r
	}

	crossLeftTop := func(cx, cy, r int) bool {
		a := abs(cx) <= r && cy >= 0 && cy <= yCorner
		b := abs(cy-yCorner) <= r && cx >= 0 && cx <= xCorner
		return a || b
	}

	crossRightBottom := func(cx, cy, r int) bool {
		a := abs(cx-xCorner) <= r && cy >= 0 && cy <= yCorner
		b := abs(cy) <= r && cx >= 0 && cx <= xCorner
		return a || b
	}

	vis := make([]bool, len(circles))

	var dfs func(int) bool
	dfs = func(i int) bool {
		c := circles[i]
		x1, y1, r1 := c[0], c[1], c[2]
		if crossRightBottom(x1, y1, r1) {
			return true
		}
		vis[i] = true
		for j, c2 := range circles {
			if vis[j] {
				continue
			}
			x2, y2, r2 := c2[0], c2[1], c2[2]
			if (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) > (r1+r2)*(r1+r2) {
				continue
			}
			if x1*r2+x2*r1 < (r1+r2)*xCorner && y1*r2+y2*r1 < (r1+r2)*yCorner && dfs(j) {
				return true
			}
		}
		return false
	}

	for i, c := range circles {
		x, y, r := c[0], c[1], c[2]
		if inCircle(0, 0, x, y, r) || inCircle(xCorner, yCorner, x, y, r) {
			return false
		}
		if !vis[i] && crossLeftTop(x, y, r) && dfs(i) {
			return false
		}
	}
	return true
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
function canReachCorner(xCorner: number, yCorner: number, circles: number[][]): boolean {
    const inCircle = (x: bigint, y: bigint, cx: bigint, cy: bigint, r: bigint): boolean => {
        const dx = x - cx;
        const dy = y - cy;
        return dx * dx + dy * dy <= r * r;
    };

    const crossLeftTop = (cx: bigint, cy: bigint, r: bigint): boolean => {
        const a = BigInt(Math.abs(Number(cx))) <= r && cy >= 0n && cy <= BigInt(yCorner);
        const b =
            BigInt(Math.abs(Number(cy - BigInt(yCorner)))) <= r &&
            cx >= 0n &&
            cx <= BigInt(xCorner);
        return a || b;
    };

    const crossRightBottom = (cx: bigint, cy: bigint, r: bigint): boolean => {
        const a =
            BigInt(Math.abs(Number(cx - BigInt(xCorner)))) <= r &&
            cy >= 0n &&
            cy <= BigInt(yCorner);
        const b = BigInt(Math.abs(Number(cy))) <= r && cx >= 0n && cx <= BigInt(xCorner);
        return a || b;
    };

    const n = circles.length;
    const vis: boolean[] = new Array(n).fill(false);

    const dfs = (i: number): boolean => {
        const [x1, y1, r1] = circles[i].map(BigInt);
        if (crossRightBottom(x1, y1, r1)) {
            return true;
        }
        vis[i] = true;
        for (let j = 0; j < n; j++) {
            if (vis[j]) continue;
            const [x2, y2, r2] = circles[j].map(BigInt);
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2)) {
                continue;
            }
            if (
                x1 * r2 + x2 * r1 < (r1 + r2) * BigInt(xCorner) &&
                y1 * r2 + y2 * r1 < (r1 + r2) * BigInt(yCorner) &&
                dfs(j)
            ) {
                return true;
            }
        }
        return false;
    };

    for (let i = 0; i < n; i++) {
        const [x, y, r] = circles[i].map(BigInt);
        if (inCircle(0n, 0n, x, y, r) || inCircle(BigInt(xCorner), BigInt(yCorner), x, y, r)) {
            return false;
        }
        if (!vis[i] && crossLeftTop(x, y, r) && dfs(i)) {
            return false;
        }
    }

    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_reach_corner(x_corner: i32, y_corner: i32, circles: Vec<Vec<i32>>) -> bool {
        let n = circles.len();
        let mut vis = vec![false; n];

        let in_circle = |x: i64, y: i64, cx: i64, cy: i64, r: i64| -> bool {
            (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r
        };

        let cross_left_top = |cx: i64, cy: i64, r: i64| -> bool {
            let a = cx.abs() <= r && (cy >= 0 && cy <= y_corner as i64);
            let b = (cy - y_corner as i64).abs() <= r && (cx >= 0 && cx <= x_corner as i64);
            a || b
        };

        let cross_right_bottom = |cx: i64, cy: i64, r: i64| -> bool {
            let a = (cx - x_corner as i64).abs() <= r && (cy >= 0 && cy <= y_corner as i64);
            let b = cy.abs() <= r && (cx >= 0 && cx <= x_corner as i64);
            a || b
        };
        fn dfs(
            circles: &Vec<Vec<i32>>,
            vis: &mut Vec<bool>,
            i: usize,
            x_corner: i32,
            y_corner: i32,
            cross_right_bottom: &dyn Fn(i64, i64, i64) -> bool,
        ) -> bool {
            let c = &circles[i];
            let (x1, y1, r1) = (c[0] as i64, c[1] as i64, c[2] as i64);

            if cross_right_bottom(x1, y1, r1) {
                return true;
            }

            vis[i] = true;

            for j in 0..circles.len() {
                if vis[j] {
                    continue;
                }

                let c2 = &circles[j];
                let (x2, y2, r2) = (c2[0] as i64, c2[1] as i64, c2[2] as i64);

                if (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > (r1 + r2) * (r1 + r2) {
                    continue;
                }

                if x1 * r2 + x2 * r1 < (r1 + r2) * x_corner as i64
                    && y1 * r2 + y2 * r1 < (r1 + r2) * y_corner as i64
                    && dfs(circles, vis, j, x_corner, y_corner, cross_right_bottom)
                {
                    return true;
                }
            }
            false
        }

        for i in 0..n {
            let c = &circles[i];
            let (x, y, r) = (c[0] as i64, c[1] as i64, c[2] as i64);

            if in_circle(0, 0, x, y, r) || in_circle(x_corner as i64, y_corner as i64, x, y, r) {
                return false;
            }

            if !vis[i]
                && cross_left_top(x, y, r)
                && dfs(
                    &circles,
                    &mut vis,
                    i,
                    x_corner,
                    y_corner,
                    &cross_right_bottom,
                )
            {
                return false;
            }
        }

        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3236. 首席执行官下属层级 🔒](https://leetcode.cn/problems/ceo-subordinate-hierarchy){#3236}

{{< tabs "3236" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T AS (
        SELECT
            employee_id,
            employee_name,
            0 AS hierarchy_level,
            manager_id,
            salary
        FROM Employees
        WHERE manager_id IS NULL
        UNION ALL
        SELECT
            e.employee_id,
            e.employee_name,
            hierarchy_level + 1 AS hierarchy_level,
            e.manager_id,
            e.salary
        FROM
            T t
            JOIN Employees e ON t.employee_id = e.manager_id
    ),
    P AS (
        SELECT salary
        FROM Employees
        WHERE manager_id IS NULL
    )
SELECT
    employee_id subordinate_id,
    employee_name subordinate_name,
    hierarchy_level,
    t.salary - p.salary salary_difference
FROM
    T t
    JOIN P p
WHERE hierarchy_level != 0
ORDER BY 3, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employees</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| employee_name | varchar |
| manager_id    | int     |
| salary        | int     |
+---------------+---------+
employee_id 是这张表的唯一标识符。
manager_id 是 employee_id 对应员工的经理。首席执行官的 manager_id 为 NULL。
</pre>

<p>编写一个解决方案来找到首席执行官的下属（<strong>直接</strong> 和&nbsp;<strong>非直接</strong>），以及他们在 <strong>等级制度中的级别</strong> 以及与首席执行官的 <strong>薪资差异</strong>。结果应该包含下面的列：</p>

<p>查询结果格式如下所示。</p>

<ul>
	<li><code>subordinate_id</code>：下属的 employee_id。</li>
	<li><code>subordinate_name</code>：下属的名字。</li>
	<li><code>hierarchy_level</code>：下属在等级制度中的级别（<code>1</code>&nbsp;表示直接下属，<code>2</code>&nbsp;表示 <b>他们的直接下属</b>，<strong>以此类推</strong>。）</li>
	<li><code>salary_difference</code>：下属与首席执行官的薪资差异。</li>
</ul>

<p>返回结果表以&nbsp;<code>hierarchy_level</code>&nbsp;<strong>升序排序</strong>，然后按&nbsp;<code>subordinate_id</code>&nbsp;<strong>升序排序</strong>。</p>

<p>查询格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>Employees</code> 表：</p>

<pre class="example-io">
+-------------+----------------+------------+---------+
| employee_id | employee_name  | manager_id | salary  |
+-------------+----------------+------------+---------+
| 1           | Alice          | NULL       | 150000  |
| 2           | Bob            | 1          | 120000  |
| 3           | Charlie        | 1          | 110000  |
| 4           | David          | 2          | 105000  |
| 5           | Eve            | 2          | 100000  |
| 6           | Frank          | 3          | 95000   |
| 7           | Grace          | 3          | 98000   |
| 8           | Helen          | 5          | 90000   |
+-------------+----------------+------------+---------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+----------------+------------------+------------------+-------------------+
| subordinate_id | subordinate_name | hierarchy_level  | salary_difference |
+----------------+------------------+------------------+-------------------+
| 2              | Bob              | 1                | -30000            |
| 3              | Charlie          | 1                | -40000            |
| 4              | David            | 2                | -45000            |
| 5              | Eve              | 2                | -50000            |
| 6              | Frank            | 2                | -55000            |
| 7              | Grace            | 2                | -52000            |
| 8              | Helen            | 3                | -60000            |
+----------------+------------------+------------------+-------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>Bob 和 Charlie 是 Alice 的直接下属（首席执行官）因此，hierarchy_level 为 1。</li>
	<li>David 和 Eve 下属于 Bob，而&nbsp;Frank 和 Grace 下属于 Charlie，因此他们是二级下属（hierarchy_level 为 2）。</li>
	<li>Helen 下属于&nbsp;Eve，因此&nbsp;Helen 为三级下属（hierarchy_level 为 3）。</li>
	<li>薪资差异是相对于 Alice 的薪资 150000 计算的。</li>
	<li>结果先以 hierarchy_level 升序排序，然后以 subordinate_id 升序排序。</li>
</ul>

<p><strong>注意：</strong>输出表先以 hierarchy_level 升序排序，然后以 subordinate_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 CTE + 连接

首先，我们使用递归 CTE 计算出每个员工的层级，其中 CEO 的层级为 0，将 `employee_id`、`employee_name`、`hierarchy_level`、`manager_id` 和 `salary` 保存到临时表 `T` 中。

然后，我们查询出 CEO 的薪资，将其保存到临时表 `P` 中。

最后，我们连接 `T` 和 `P` 表，计算出每个下属的薪资差异，并按照 `hierarchy_level` 和 `subordinate_id` 进行排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T AS (
        SELECT
            employee_id,
            employee_name,
            0 AS hierarchy_level,
            manager_id,
            salary
        FROM Employees
        WHERE manager_id IS NULL
        UNION ALL
        SELECT
            e.employee_id,
            e.employee_name,
            hierarchy_level + 1 AS hierarchy_level,
            e.manager_id,
            e.salary
        FROM
            T t
            JOIN Employees e ON t.employee_id = e.manager_id
    ),
    P AS (
        SELECT salary
        FROM Employees
        WHERE manager_id IS NULL
    )
SELECT
    employee_id subordinate_id,
    employee_name subordinate_name,
    hierarchy_level,
    t.salary - p.salary salary_difference
FROM
    T t
    JOIN P p
WHERE hierarchy_level != 0
ORDER BY 3, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3237. Alt 和 Tab 模拟 🔒](https://leetcode.cn/problems/alt-and-tab-simulation){#3237}

{{< tabs "3237" >}}

{{% tab "python" %}}
```python
class Solution:
    def simulationResult(self, windows: List[int], queries: List[int]) -> List[int]:
        s = set()
        ans = []
        for q in queries[::-1]:
            if q not in s:
                ans.append(q)
                s.add(q)
        for w in windows:
            if w not in s:
                ans.append(w)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] simulationResult(int[] windows, int[] queries) {
        int n = windows.length;
        boolean[] s = new boolean[n + 1];
        int[] ans = new int[n];
        int k = 0;
        for (int i = queries.length - 1; i >= 0; --i) {
            int q = queries[i];
            if (!s[q]) {
                ans[k++] = q;
                s[q] = true;
            }
        }
        for (int w : windows) {
            if (!s[w]) {
                ans[k++] = w;
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
    vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
        int n = windows.size();
        vector<bool> s(n + 1);
        vector<int> ans;
        for (int i = queries.size() - 1; ~i; --i) {
            int q = queries[i];
            if (!s[q]) {
                s[q] = true;
                ans.push_back(q);
            }
        }
        for (int w : windows) {
            if (!s[w]) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func simulationResult(windows []int, queries []int) (ans []int) {
	n := len(windows)
	s := make([]bool, n+1)
	for i := len(queries) - 1; i >= 0; i-- {
		q := queries[i]
		if !s[q] {
			s[q] = true
			ans = append(ans, q)
		}
	}
	for _, w := range windows {
		if !s[w] {
			ans = append(ans, w)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function simulationResult(windows: number[], queries: number[]): number[] {
    const n = windows.length;
    const s: boolean[] = Array(n + 1).fill(false);
    const ans: number[] = [];
    for (let i = queries.length - 1; i >= 0; i--) {
        const q = queries[i];
        if (!s[q]) {
            s[q] = true;
            ans.push(q);
        }
    }
    for (const w of windows) {
        if (!s[w]) {
            ans.push(w);
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

<p>有&nbsp;<code>n</code>&nbsp;个编号从&nbsp; <code>1</code> 到&nbsp;<code>n</code>&nbsp;的打开的窗口，我们想要模拟使用&nbsp;alt + tab 键在窗口之间导航。</p>

<p>给定数组&nbsp;<code>windows</code>&nbsp;包含窗口的初始顺序（第一个元素在最前面，最后一个元素在最后面）。</p>

<p>同时给定数组&nbsp;<code>queries</code>&nbsp;表示每一次查询中，编号为&nbsp;<code>queries[i]</code>&nbsp;的窗口被切换到最前面。</p>

<p>返回&nbsp;<code>windows</code>&nbsp;数组的最后状态。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>windows = [1,2,3], queries = [3,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">[2,3,1]</span></p>

<p><strong>解释：</strong></p>

<p>以下是每次查询后的 windows 数组：</p>

<ul>
	<li>初始顺序：<code>[1,2,3]</code></li>
	<li>第一次查询后：<code>[<u><strong>3</strong></u>,1,2]</code></li>
	<li>第二次查询后：<code>[<u><strong>3</strong></u>,1,2]</code></li>
	<li>最后一次查询后：<code>[<u><strong>2</strong></u>,3,1]</code></li>
</ul>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>windows = [1,4,2,3], queries = [4,1,3]</span></p>

<p><span class="example-io"><b>输出：</b>[3,1,4,2]</span></p>

<p><strong>解释：</strong></p>

<p>以下是每次查询后的 windows 数组：</p>

<ul>
	<li>初始顺序：<code>[1,4,2,3]</code></li>
	<li>第一次查询后：<code>[<u><strong>4</strong></u>,1,2,3]</code></li>
	<li>第二次查询后：<code>[<u><strong>1</strong></u>,4,2,3]</code></li>
	<li>最后一次查询后：<code>[<u><strong>3</strong></u>,1,4,2]</code></li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == windows.length &lt;= 10<sup>5</sup></code></li>
	<li><code>windows</code> 是&nbsp;<code>[1, n]</code>&nbsp;的一个排列。</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 逆序遍历

根据题目描述，越是后面的查询，越是出现在最前面的位置。因此，我们可以逆序遍历 $\textit{queries}$ 数组，用一个哈希表 $\textit{s}$ 记录已经出现过的窗口。对于每一个查询，如果当前窗口不在哈希表中，我们将其加入答案数组，并将其加入哈希表中。最后，我们再次遍历 $\textit{windows}$ 数组，将不在哈希表中的窗口加入答案数组。

时间复杂度 $O(n + m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为 $\textit{windows}$ 和 $\textit{queries}$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def simulationResult(self, windows: List[int], queries: List[int]) -> List[int]:
        s = set()
        ans = []
        for q in queries[::-1]:
            if q not in s:
                ans.append(q)
                s.add(q)
        for w in windows:
            if w not in s:
                ans.append(w)
        return ans
```

#### Java

```java
class Solution {
    public int[] simulationResult(int[] windows, int[] queries) {
        int n = windows.length;
        boolean[] s = new boolean[n + 1];
        int[] ans = new int[n];
        int k = 0;
        for (int i = queries.length - 1; i >= 0; --i) {
            int q = queries[i];
            if (!s[q]) {
                ans[k++] = q;
                s[q] = true;
            }
        }
        for (int w : windows) {
            if (!s[w]) {
                ans[k++] = w;
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
    vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
        int n = windows.size();
        vector<bool> s(n + 1);
        vector<int> ans;
        for (int i = queries.size() - 1; ~i; --i) {
            int q = queries[i];
            if (!s[q]) {
                s[q] = true;
                ans.push_back(q);
            }
        }
        for (int w : windows) {
            if (!s[w]) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func simulationResult(windows []int, queries []int) (ans []int) {
	n := len(windows)
	s := make([]bool, n+1)
	for i := len(queries) - 1; i >= 0; i-- {
		q := queries[i]
		if !s[q] {
			s[q] = true
			ans = append(ans, q)
		}
	}
	for _, w := range windows {
		if !s[w] {
			ans = append(ans, w)
		}
	}
	return
}
```

#### TypeScript

```ts
function simulationResult(windows: number[], queries: number[]): number[] {
    const n = windows.length;
    const s: boolean[] = Array(n + 1).fill(false);
    const ans: number[] = [];
    for (let i = queries.length - 1; i >= 0; i--) {
        const q = queries[i];
        if (!s[q]) {
            s[q] = true;
            ans.push(q);
        }
    }
    for (const w of windows) {
        if (!s[w]) {
            ans.push(w);
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

# [3238. 求出胜利玩家的数目](https://leetcode.cn/problems/find-the-number-of-winning-players){#3238}

{{< tabs "3238" >}}

{{% tab "python" %}}
```python
class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        cnt = [[0] * 11 for _ in range(n)]
        s = set()
        for x, y in pick:
            cnt[x][y] += 1
            if cnt[x][y] > x:
                s.add(x)
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int[][] cnt = new int[n][11];
        Set<Integer> s = new HashSet<>();
        for (var p : pick) {
            int x = p[0], y = p[1];
            if (++cnt[x][y] > x) {
                s.add(x);
            }
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt[10][11]{};
        unordered_set<int> s;
        for (const auto& p : pick) {
            int x = p[0], y = p[1];
            if (++cnt[x][y] > x) {
                s.insert(x);
            }
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func winningPlayerCount(n int, pick [][]int) int {
	cnt := make([][11]int, n)
	s := map[int]struct{}{}
	for _, p := range pick {
		x, y := p[0], p[1]
		cnt[x][y]++
		if cnt[x][y] > x {
			s[x] = struct{}{}
		}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function winningPlayerCount(n: number, pick: number[][]): number {
    const cnt: number[][] = Array.from({ length: n }, () => Array(11).fill(0));
    const s = new Set<number>();
    for (const [x, y] of pick) {
        if (++cnt[x][y] > x) {
            s.add(x);
        }
    }
    return s.size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示在一个游戏中的玩家数目。同时给你一个二维整数数组&nbsp;<code>pick</code>&nbsp;，其中&nbsp;<code>pick[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示玩家&nbsp;<code>x<sub>i</sub></code>&nbsp;获得了一个颜色为&nbsp;<code>y<sub>i</sub></code>&nbsp;的球。</p>

<p>如果玩家 <code>i</code>&nbsp;获得的球中任何一种颜色球的数目 <strong>严格大于</strong>&nbsp;<code>i</code>&nbsp;个，那么我们说玩家 <code>i</code>&nbsp;是胜利玩家。换句话说：</p>

<ul>
	<li>如果玩家 0 获得了任何的球，那么玩家 0 是胜利玩家。</li>
	<li>如果玩家 1 获得了至少 2 个相同颜色的球，那么玩家 1 是胜利玩家。</li>
	<li>...</li>
	<li>如果玩家 <code>i</code>&nbsp;获得了至少&nbsp;<code>i + 1</code>&nbsp;个相同颜色的球，那么玩家 <code>i</code>&nbsp;是胜利玩家。</li>
</ul>

<p>请你返回游戏中 <strong>胜利玩家</strong>&nbsp;的数目。</p>

<p><strong>注意</strong>，可能有多个玩家是胜利玩家。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>玩家 0 和玩家 1 是胜利玩家，玩家 2 和玩家 3 不是胜利玩家。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, pick = [[1,1],[1,2],[1,3],[1,4]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>没有胜利玩家。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, pick = [[1,1],[2,4],[2,4],[2,4]]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>玩家 2 是胜利玩家，因为玩家 2 获得了 3 个颜色为 4 的球。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= pick.length &lt;= 100</code></li>
	<li><code>pick[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub> &lt;= n - 1 </code></li>
	<li><code>0 &lt;= y<sub>i</sub> &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个二维数组 $\textit{cnt}$ 记录每个玩家获得的每种颜色球的数量，用一个哈希表 $\textit{s}$ 记录胜利玩家的编号。

遍历 $\textit{pick}$ 数组，对于每个元素 $[x, y]$，我们将 $\textit{cnt}[x][y]$ 加一，如果 $\textit{cnt}[x][y]$ 大于 $x$，则将 $x$ 加入哈希表 $\textit{s}$。

最后返回哈希表 $\textit{s}$ 的大小即可。

时间复杂度 $O(m + n \times M)$，空间复杂度 $O(n \times M)$。其中 $m$ 为 $\textit{pick}$ 数组的长度，而 $n$ 和 $M$ 分别为玩家数目和颜色数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        cnt = [[0] * 11 for _ in range(n)]
        s = set()
        for x, y in pick:
            cnt[x][y] += 1
            if cnt[x][y] > x:
                s.add(x)
        return len(s)
```

#### Java

```java
class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int[][] cnt = new int[n][11];
        Set<Integer> s = new HashSet<>();
        for (var p : pick) {
            int x = p[0], y = p[1];
            if (++cnt[x][y] > x) {
                s.add(x);
            }
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt[10][11]{};
        unordered_set<int> s;
        for (const auto& p : pick) {
            int x = p[0], y = p[1];
            if (++cnt[x][y] > x) {
                s.insert(x);
            }
        }
        return s.size();
    }
};
```

#### Go

```go
func winningPlayerCount(n int, pick [][]int) int {
	cnt := make([][11]int, n)
	s := map[int]struct{}{}
	for _, p := range pick {
		x, y := p[0], p[1]
		cnt[x][y]++
		if cnt[x][y] > x {
			s[x] = struct{}{}
		}
	}
	return len(s)
}
```

#### TypeScript

```ts
function winningPlayerCount(n: number, pick: number[][]): number {
    const cnt: number[][] = Array.from({ length: n }, () => Array(11).fill(0));
    const s = new Set<number>();
    for (const [x, y] of pick) {
        if (++cnt[x][y] > x) {
            s.add(x);
        }
    }
    return s.size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3239. 最少翻转次数使二进制矩阵回文 I](https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i){#3239}

{{< tabs "3239" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt1 = cnt2 = 0
        for row in grid:
            for j in range(n // 2):
                if row[j] != row[n - j - 1]:
                    cnt1 += 1
        for j in range(n):
            for i in range(m // 2):
                if grid[i][j] != grid[m - i - 1][j]:
                    cnt2 += 1
        return min(cnt1, cnt2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int cnt1 = 0, cnt2 = 0;
        for (var row : grid) {
            for (int j = 0; j < n / 2; ++j) {
                if (row[j] != row[n - j - 1]) {
                    ++cnt1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    ++cnt2;
                }
            }
        }
        return Math.min(cnt1, cnt2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt1 = 0, cnt2 = 0;
        for (const auto& row : grid) {
            for (int j = 0; j < n / 2; ++j) {
                if (row[j] != row[n - j - 1]) {
                    ++cnt1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    ++cnt2;
                }
            }
        }
        return min(cnt1, cnt2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	cnt1, cnt2 := 0, 0
	for _, row := range grid {
		for j := 0; j < n/2; j++ {
			if row[j] != row[n-j-1] {
				cnt1++
			}
		}
	}
	for j := 0; j < n; j++ {
		for i := 0; i < m/2; i++ {
			if grid[i][j] != grid[m-i-1][j] {
				cnt2++
			}
		}
	}
	return min(cnt1, cnt2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFlips(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [cnt1, cnt2] = [0, 0];
    for (const row of grid) {
        for (let j = 0; j < n / 2; ++j) {
            if (row[j] !== row[n - 1 - j]) {
                ++cnt1;
            }
        }
    }
    for (let j = 0; j < n; ++j) {
        for (let i = 0; i < m / 2; ++i) {
            if (grid[i][j] !== grid[m - 1 - i][j]) {
                ++cnt2;
            }
        }
    }
    return Math.min(cnt1, cnt2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 <strong>回文</strong> 的。</p>

<p>你可以将 <code>grid</code>&nbsp;中任意格子的值 <strong>翻转</strong>&nbsp;，也就是将格子里的值从 <code>0</code>&nbsp;变成 <code>1</code>&nbsp;，或者从 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</p>

<p>请你返回 <strong>最少</strong>&nbsp;翻转次数，使得矩阵 <strong>要么</strong>&nbsp;所有行是 <strong>回文的</strong>&nbsp;，要么所有列是 <strong>回文的</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,0],[0,0,0],[0,0,1]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3239.Minimum%20Number%20of%20Flips%20to%20Make%20Binary%20Grid%20Palindromic%20I/images/screenshot-from-2024-07-08-00-20-10.png" style="width: 420px; height: 108px;" /></p>

<p>将高亮的格子翻转，得到所有行都是回文的。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = </span>[[0,1],[0,1],[0,0]]</p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3239.Minimum%20Number%20of%20Flips%20to%20Make%20Binary%20Grid%20Palindromic%20I/images/screenshot-from-2024-07-08-00-31-23.png" style="width: 300px; height: 100px;" /></p>

<p>将高亮的格子翻转，得到所有列都是回文的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[0]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>所有行已经是回文的。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们分别计算行和列的翻转次数，记为 $\textit{cnt1}$ 和 $\textit{cnt2}$，最后取二者的最小值即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵 $\textit{grid}$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt1 = cnt2 = 0
        for row in grid:
            for j in range(n // 2):
                if row[j] != row[n - j - 1]:
                    cnt1 += 1
        for j in range(n):
            for i in range(m // 2):
                if grid[i][j] != grid[m - i - 1][j]:
                    cnt2 += 1
        return min(cnt1, cnt2)
```

#### Java

```java
class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int cnt1 = 0, cnt2 = 0;
        for (var row : grid) {
            for (int j = 0; j < n / 2; ++j) {
                if (row[j] != row[n - j - 1]) {
                    ++cnt1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    ++cnt2;
                }
            }
        }
        return Math.min(cnt1, cnt2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt1 = 0, cnt2 = 0;
        for (const auto& row : grid) {
            for (int j = 0; j < n / 2; ++j) {
                if (row[j] != row[n - j - 1]) {
                    ++cnt1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][j] != grid[m - i - 1][j]) {
                    ++cnt2;
                }
            }
        }
        return min(cnt1, cnt2);
    }
};
```

#### Go

```go
func minFlips(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	cnt1, cnt2 := 0, 0
	for _, row := range grid {
		for j := 0; j < n/2; j++ {
			if row[j] != row[n-j-1] {
				cnt1++
			}
		}
	}
	for j := 0; j < n; j++ {
		for i := 0; i < m/2; i++ {
			if grid[i][j] != grid[m-i-1][j] {
				cnt2++
			}
		}
	}
	return min(cnt1, cnt2)
}
```

#### TypeScript

```ts
function minFlips(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [cnt1, cnt2] = [0, 0];
    for (const row of grid) {
        for (let j = 0; j < n / 2; ++j) {
            if (row[j] !== row[n - 1 - j]) {
                ++cnt1;
            }
        }
    }
    for (let j = 0; j < n; ++j) {
        for (let i = 0; i < m / 2; ++i) {
            if (grid[i][j] !== grid[m - 1 - i][j]) {
                ++cnt2;
            }
        }
    }
    return Math.min(cnt1, cnt2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

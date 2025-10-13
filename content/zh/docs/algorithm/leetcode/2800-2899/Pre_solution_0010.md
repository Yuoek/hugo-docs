---
title: "2890_重塑数据：融合"
date: 2025-10-08T18:39:37+08:00
weight: 10
tags: [Pandas, 位运算, 动态规划, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 模拟, 贪心]
---

{{< markmap >}}
### [2890_重塑数据：融合](#2890)
#### [Pandas](#2890)
### [2891_方法链](#2891)
#### [Pandas](#2891)
### [2892_将相邻元素相乘后得到最小化数组 🔒](#2892)
#### [贪心](#2892)
#### [数组](#2892)
#### [动态规划](#2892)
### [2893_计算每个区间内的订单 🔒](#2893)
#### [数据库](#2893)
### [2894_分类求和并作差](#2894)
#### [数学](#2894)
### [2895_最小处理时间](#2895)
#### [贪心](#2895)
#### [数组](#2895)
#### [排序](#2895)
### [2896_执行操作使两个字符串相等](#2896)
#### [字符串](#2896)
#### [动态规划](#2896)
### [2897_对数组执行操作使平方和最大](#2897)
#### [贪心](#2897)
#### [位运算](#2897)
#### [数组](#2897)
#### [哈希表](#2897)
### [2898_最大线性股票得分 🔒](#2898)
#### [数组](#2898)
#### [哈希表](#2898)
### [2899_上一个遍历的整数](#2899)
#### [数组](#2899)
#### [模拟](#2899)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2890_重塑数据：融合
___
#### Pandas
---
### 2891_方法链
___
#### Pandas
---
### 2892_将相邻元素相乘后得到最小化数组 🔒
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 2893_计算每个区间内的订单 🔒
___
#### 数据库
---
### 2894_分类求和并作差
___
#### 数学
---
### 2895_最小处理时间
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2896_执行操作使两个字符串相等
___
#### 字符串
___
#### 动态规划
---
### 2897_对数组执行操作使平方和最大
___
#### 贪心
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 2898_最大线性股票得分 🔒
___
#### 数组
___
#### 哈希表
---
### 2899_上一个遍历的整数
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| Pandas | 位运算 | 动态规划 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 模拟 | 贪心 |  |

# [2890. 重塑数据：融合](https://leetcode.cn/problems/reshape-data-melt){#2890}

{{< tabs "2890" >}}

{{% tab "python" %}}
```python
import pandas as pd


def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>report</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| product     | object |
| quarter_1   | int    |
| quarter_2   | int    |
| quarter_3   | int    |
| quarter_4   | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案，将数据 <strong>重塑</strong> 成每一行表示特定季度产品销售数据的形式。</p>

<p>结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：
</strong>+-------------+-----------+-----------+-----------+-----------+
| product     | quarter_1 | quarter_2 | quarter_3 | quarter_4 |
+-------------+-----------+-----------+-----------+-----------+
| Umbrella    | 417       | 224       | 379       | 611       |
| SleepingBag | 800       | 936       | 93        | 875       |
+-------------+-----------+-----------+-----------+-----------+
<strong>输出：</strong>
+-------------+-----------+-------+
| product     | quarter   | sales |
+-------------+-----------+-------+
| Umbrella    | quarter_1 | 417   |
| SleepingBag | quarter_1 | 800   |
| Umbrella    | quarter_2 | 224   |
| SleepingBag | quarter_2 | 936   |
| Umbrella    | quarter_3 | 379   |
| SleepingBag | quarter_3 | 93    |
| Umbrella    | quarter_4 | 611   |
| SleepingBag | quarter_4 | 875   |
+-------------+-----------+-------+
<strong>解释：</strong>
DataFrame 已从宽格式重塑为长格式。每一行表示一个季度内产品的销售情况。
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

#### Python3

```python
import pandas as pd


def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2891. 方法链](https://leetcode.cn/problems/method-chaining){#2891}

{{< tabs "2891" >}}

{{% tab "python" %}}
```python
import pandas as pd


def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight'] > 100].sort_values('weight', ascending=False)[
        ['name']
    ]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>animals</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| species     | object |
| age         | int    |
| weight      | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案来列出体重 <strong>严格超过&nbsp;</strong>&nbsp;<code>100</code>&nbsp; 千克的动物的名称。</p>

<p>按体重 <strong>降序</strong> 返回动物。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
DataFrame animals:
+----------+---------+-----+--------+
| name     | species | age | weight |
+----------+---------+-----+--------+
| Tatiana  | Snake   | 98  | 464    |
| Khaled   | Giraffe | 50  | 41     |
| Alex     | Leopard | 6   | 328    |
| Jonathan | Monkey  | 45  | 463    |
| Stefan   | Bear    | 100 | 50     |
| Tommy    | Panda   | 26  | 349    |
+----------+---------+-----+--------+
<b>输出：</b>
+----------+
| name     |
+----------+
| Tatiana  |
| Jonathan |
| Tommy    |
| Alex     |
+----------+
<b>解释：</b>
所有体重超过 100 的动物都应包含在结果表中。
Tatiana 的体重为 464，Jonathan 的体重为 463，Tommy 的体重为 349，Alex 的体重为 328。
结果应按体重降序排序。</pre>

<p>&nbsp;</p>

<p>在 Pandas 中，<strong>方法链</strong> 允许我们在 DataFrame 上执行操作，而无需将每个操作拆分成单独的行或创建多个临时变量。</p>

<p>你能用 <strong>一行</strong> 代码的方法链完成这个任务吗？</p>

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
import pandas as pd


def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight'] > 100].sort_values('weight', ascending=False)[
        ['name']
    ]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2892. 将相邻元素相乘后得到最小化数组 🔒](https://leetcode.cn/problems/minimizing-array-after-replacing-pairs-with-their-product){#2892}

{{< tabs "2892" >}}

{{% tab "python" %}}
```python
class Solution:
    def minArrayLength(self, nums: List[int], k: int) -> int:
        ans, y = 1, nums[0]
        for x in nums[1:]:
            if x == 0:
                return 1
            if x * y <= k:
                y *= x
            else:
                y = x
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minArrayLength(int[] nums, int k) {
        int ans = 1;
        long y = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int x = nums[i];
            if (x == 0) {
                return 1;
            }
            if (x * y <= k) {
                y *= x;
            } else {
                y = x;
                ++ans;
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
    int minArrayLength(vector<int>& nums, int k) {
        int ans = 1;
        long long y = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            if (x == 0) {
                return 1;
            }
            if (x * y <= k) {
                y *= x;
            } else {
                y = x;
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minArrayLength(nums []int, k int) int {
	ans, y := 1, nums[0]
	for _, x := range nums[1:] {
		if x == 0 {
			return 1
		}
		if x*y <= k {
			y *= x
		} else {
			y = x
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minArrayLength(nums: number[], k: number): number {
    let [ans, y] = [1, nums[0]];
    for (const x of nums.slice(1)) {
        if (x === 0) {
            return 1;
        }
        if (x * y <= k) {
            y *= x;
        } else {
            y = x;
            ++ans;
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

<p>给定一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>，你可以对数组执行以下操作任意次数：</p>

<ul>
	<li>选择数组中的两个 <b>相邻</b>&nbsp;元素，例如&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>，使得&nbsp;<code>x * y &lt;= k</code>&nbsp;，并用一个值为&nbsp;<code>x * y</code>&nbsp;的 <b>单个元素</b>&nbsp;替换它们（例如，在一次操作中，数组&nbsp;<code>[1, 2, 2, 3]</code>，其中&nbsp;<code>k = 5</code> 可以变为&nbsp;<code>[1, 4, 3]</code>&nbsp;或&nbsp;<code>[2, 2, 3]</code>，但不能变为&nbsp;<code>[1, 2, 6]</code>）。</li>
</ul>

<p>返回 <em>经过任意次数的操作后，&nbsp;</em><code>nums</code><em>&nbsp;的 <strong>最小</strong> 可能长度。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,3,7,3,5], k = 20
<strong>输出：</strong>3
<strong>解释：</strong>我们执行以下操作：
1. [<u>2,3</u>,3,7,3,5] -&gt; [<u>6</u>,3,7,3,5]
2. [<u>6,3</u>,7,3,5] -&gt; [<u>18</u>,7,3,5]
3. [18,7,<u>3,5</u>] -&gt; [18,7,<u>15</u>]
可以证明，在执行给定操作后，最小可能长度为3.</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3,3,3], k = 6
<strong>输出：</strong>4
<strong>解释：</strong>由于每两个相邻元素的乘积都大于 6，所以无法执行任何操作。因此，答案为 4。</pre>

<p>&nbsp;</p>

<p><strong>约束条件：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用一个变量 $ans$ 记录当前数组的长度，用一个变量 $y$ 记录当前数组的乘积，初始时 $ans = 1$, $y = nums[0]$。

我们从数组的第二个元素开始遍历，设当前元素为 $x$：

-   如果 $x = 0$，那么整个数组的乘积为 $0 \le k$，因此答案数组的最小长度为 $1$，直接返回即可。
-   如果 $x \times y \le k$，那么我们可以将 $x$ 与 $y$ 合并，即 $y = x \times y$。
-   如果 $x \times y \gt k$，那么我们无法将 $x$ 与 $y$ 合并，因此我们需要将 $x$ 单独作为一个元素，即 $ans = ans + 1$，并且 $y = x$。

最终答案即为 $ans$。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minArrayLength(self, nums: List[int], k: int) -> int:
        ans, y = 1, nums[0]
        for x in nums[1:]:
            if x == 0:
                return 1
            if x * y <= k:
                y *= x
            else:
                y = x
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minArrayLength(int[] nums, int k) {
        int ans = 1;
        long y = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int x = nums[i];
            if (x == 0) {
                return 1;
            }
            if (x * y <= k) {
                y *= x;
            } else {
                y = x;
                ++ans;
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
    int minArrayLength(vector<int>& nums, int k) {
        int ans = 1;
        long long y = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            if (x == 0) {
                return 1;
            }
            if (x * y <= k) {
                y *= x;
            } else {
                y = x;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minArrayLength(nums []int, k int) int {
	ans, y := 1, nums[0]
	for _, x := range nums[1:] {
		if x == 0 {
			return 1
		}
		if x*y <= k {
			y *= x
		} else {
			y = x
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minArrayLength(nums: number[], k: number): number {
    let [ans, y] = [1, nums[0]];
    for (const x of nums.slice(1)) {
        if (x === 0) {
            return 1;
        }
        if (x * y <= k) {
            y *= x;
        } else {
            y = x;
            ++ans;
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

# [2893. 计算每个区间内的订单 🔒](https://leetcode.cn/problems/calculate-orders-within-each-interval){#2893}

{{< tabs "2893" >}}

{{% tab "sql" %}}
```sql
SELECT
    FLOOR((minute + 5) / 6) AS interval_no,
    SUM(order_count) AS total_orders
FROM Orders
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code><font face="monospace">Orders</font></code></p>

<pre>
+-------------+------+ 
| Column Name | Type | 
+-------------+------+ 
| minute      | int  | 
| order_count | int  |
+-------------+------+
minute 是该表的主键。
该表的每一行包含分钟数以及在特定分钟数内收到的订单数量。总行数将是 6 的倍数。</pre>

<p>编写一个查询，计算每个&nbsp;<strong>区间</strong><b>&nbsp;</b>内的&nbsp;<b>总订单数量。</b>&nbsp;每个区间被定义为&nbsp;<code>6</code>&nbsp;分钟的组合。</p>

<ul>
	<li>&nbsp;<code>1</code>&nbsp;到&nbsp;<code>6</code>&nbsp;分钟属于第&nbsp;<code>1</code>&nbsp;个区间，而&nbsp;<code>7</code>&nbsp;到&nbsp;<code>12</code>&nbsp;分钟属于第&nbsp;<code>2</code>&nbsp;个区间，以此类推。</li>
</ul>

<p>按 <em><strong>升序顺序</strong></em> <em>返回</em><em>结果表，</em>按<em>&nbsp;<strong>interval_no</strong>&nbsp;排序。</em></p>

<p>结果表的格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Orders table:
+--------+-------------+
| minute | order_count | 
+--------+-------------+
| 1      | 0           |
| 2      | 2           | 
| 3      | 4           | 
| 4      | 6           | 
| 5      | 1           | 
| 6      | 4           | 
| 7      | 1           | 
| 8      | 2           | 
| 9      | 4           | 
| 10     | 1           | 
| 11     | 4           | 
| 12     | 6           | 
+--------+-------------+
<b>输出：</b>
+-------------+--------------+
| interval_no | total_orders | 
+-------------+--------------+
| 1           | 17           | 
| 2           | 18           |    
+-------------+--------------+
<b>解释：</b>
- 区间号 1 包括从 1 到 6 分钟的时间。这 6 分钟内的总订单数量为 (0 + 2 + 4 + 6 + 1 + 4) = 17。
- 区间号 2 包括从 7 到 12 分钟的时间。这 6 分钟内的总订单数量为 (1 + 2 + 4 + 1 + 4 + 6) = 18。
按升序顺序返回结果表，按 interval_no 排序。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

我们可以用窗口函数 `sum() over()` 来计算每 $6$ 分钟的订单总数，然后每条记录中的 `minute` 能被 $6$ 整除的记录。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            minute,
            SUM(order_count) OVER (
                ORDER BY minute
                ROWS 5 PRECEDING
            ) AS total_orders
        FROM Orders
    )
SELECT minute / 6 AS interval_no, total_orders
FROM T
WHERE minute % 6 = 0;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    FLOOR((minute + 5) / 6) AS interval_no,
    SUM(order_count) AS total_orders
FROM Orders
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2894. 分类求和并作差](https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference){#2894}

{{< tabs "2894" >}}

{{% tab "python" %}}
```python
class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return sum(i if i % m else -i for i in range(1, n + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += i % m == 0 ? -i : i;
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
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += i % m ? i : -i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func differenceOfSums(n int, m int) (ans int) {
	for i := 1; i <= n; i++ {
		if i%m == 0 {
			ans -= i
		} else {
			ans += i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function differenceOfSums(n: number, m: number): number {
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        ans += i % m ? i : -i;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut ans = 0;
        for i in 1..=n {
            if i % m != 0 {
                ans += i;
            } else {
                ans -= i;
            }
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

<p>给你两个正整数 <code>n</code> 和 <code>m</code> 。</p>

<p>现定义两个整数 <code>num1</code> 和 <code>num2</code> ，如下所示：</p>

<ul>
	<li><code>num1</code>：范围 <code>[1, n]</code> 内所有 <strong>无法被 </strong><code>m</code><strong> 整除</strong> 的整数之和。</li>
	<li><code>num2</code>：范围 <code>[1, n]</code> 内所有 <strong>能够被 </strong><code>m</code><strong> 整除</strong> 的整数之和。</li>
</ul>

<p>返回整数 <code>num1 - num2</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, m = 3
<strong>输出：</strong>19
<strong>解释：</strong>在这个示例中：
- 范围 [1, 10] 内无法被 3 整除的整数为 [1,2,4,5,7,8,10] ，num1 = 这些整数之和 = 37 。
- 范围 [1, 10] 内能够被 3 整除的整数为 [3,6,9] ，num2 = 这些整数之和 = 18 。
返回 37 - 18 = 19 作为答案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, m = 6
<strong>输出：</strong>15
<strong>解释：</strong>在这个示例中：
- 范围 [1, 5] 内无法被 6 整除的整数为 [1,2,3,4,5] ，num1 = 这些整数之和 =  15 。
- 范围 [1, 5] 内能够被 6 整除的整数为 [] ，num2 = 这些整数之和 = 0 。
返回 15 - 0 = 15 作为答案。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, m = 1
<strong>输出：</strong>-15
<strong>解释：</strong>在这个示例中：
- 范围 [1, 5] 内无法被 1 整除的整数为 [] ，num1 = 这些整数之和 = 0 。 
- 范围 [1, 5] 内能够被 1 整除的整数为 [1,2,3,4,5] ，num2 = 这些整数之和 = 15 。
返回 0 - 15 = -15 作为答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历区间 $[1, n]$ 中的每一个数，如果它能被 $m$ 整除，那么答案就减去这个数，否则答案就加上这个数。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return sum(i if i % m else -i for i in range(1, n + 1))
```

#### Java

```java
class Solution {
    public int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += i % m == 0 ? -i : i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += i % m ? i : -i;
        }
        return ans;
    }
};
```

#### Go

```go
func differenceOfSums(n int, m int) (ans int) {
	for i := 1; i <= n; i++ {
		if i%m == 0 {
			ans -= i
		} else {
			ans += i
		}
	}
	return
}
```

#### TypeScript

```ts
function differenceOfSums(n: number, m: number): number {
    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        ans += i % m ? i : -i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut ans = 0;
        for i in 1..=n {
            if i % m != 0 {
                ans += i;
            } else {
                ans -= i;
            }
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

# [2895. 最小处理时间](https://leetcode.cn/problems/minimum-processing-time){#2895}

{{< tabs "2895" >}}

{{% tab "python" %}}
```python
class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        processorTime.sort()
        tasks.sort()
        ans = 0
        i = len(tasks) - 1
        for t in processorTime:
            ans = max(ans, t + tasks[i])
            i -= 4
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        processorTime.sort((a, b) -> a - b);
        tasks.sort((a, b) -> a - b);
        int ans = 0, i = tasks.size() - 1;
        for (int t : processorTime) {
            ans = Math.max(ans, t + tasks.get(i));
            i -= 4;
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
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int ans = 0, i = tasks.size() - 1;
        for (int t : processorTime) {
            ans = max(ans, t + tasks[i]);
            i -= 4;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minProcessingTime(processorTime []int, tasks []int) (ans int) {
	sort.Ints(processorTime)
	sort.Ints(tasks)
	i := len(tasks) - 1
	for _, t := range processorTime {
		ans = max(ans, t+tasks[i])
		i -= 4
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minProcessingTime(processorTime: number[], tasks: number[]): number {
    processorTime.sort((a, b) => a - b);
    tasks.sort((a, b) => a - b);
    let [ans, i] = [0, tasks.length - 1];
    for (const t of processorTime) {
        ans = Math.max(ans, t + tasks[i]);
        i -= 4;
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

<p>你有 <code>n</code> 颗处理器，每颗处理器都有 <code>4</code> 个核心。现有 <code>n * 4</code> 个待执行任务，每个核心只执行 <strong>一次</strong>&nbsp;任务。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>processorTime</code> ，表示每颗处理器最早空闲时间。另给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tasks</code> ，表示执行每个任务所需的时间。返回所有任务都执行完毕需要的 <strong>最小时间</strong> 。</p>

<p>注意：每个核心独立执行任务。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>
最优的方案是将下标为 4, 5, 6, 7 的任务分配给第一颗处理器（最早空闲时间 time = 8），下标为 0, 1, 2, 3 的任务分配给第二颗处理器（最早空闲时间 time = 10）。 
第一颗处理器执行完所有任务需要花费的时间 = max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16 。
第二颗处理器执行完所有任务需要花费的时间 = max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13 。
因此，可以证明执行完所有任务需要花费的最小时间是 16 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]
<strong>输出：</strong>23
<strong>解释：</strong>
最优的方案是将下标为 1, 4, 5, 6 的任务分配给第一颗处理器（最早空闲时间 time = 10），下标为 0, 2, 3, 7 的任务分配给第二颗处理器（最早空闲时间 time = 20）。 
第一颗处理器执行完所有任务需要花费的时间 = max(10 + 3, 10 + 5, 10 + 8, 10 + 4) = 18 。 
第二颗处理器执行完所有任务需要花费的时间 = max(20 + 2, 20 + 1, 20 + 2, 20 + 3) = 23 。 
因此，可以证明执行完所有任务需要花费的最小时间是 23 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == processorTime.length &lt;= 25000</code></li>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= processorTime[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>tasks.length == 4 * n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

要使得处理完所有任务的时间最小，那么越早处于空闲状态的处理器应该处理耗时最长的 $4$ 个任务。

因此，我们对处理器的空闲时间和任务的耗时分别进行排序，然后依次将耗时最长的 $4$ 个任务分配给空闲时间最早的处理器，计算最大的结束时间即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为任务的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        processorTime.sort()
        tasks.sort()
        ans = 0
        i = len(tasks) - 1
        for t in processorTime:
            ans = max(ans, t + tasks[i])
            i -= 4
        return ans
```

#### Java

```java
class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        processorTime.sort((a, b) -> a - b);
        tasks.sort((a, b) -> a - b);
        int ans = 0, i = tasks.size() - 1;
        for (int t : processorTime) {
            ans = Math.max(ans, t + tasks.get(i));
            i -= 4;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int ans = 0, i = tasks.size() - 1;
        for (int t : processorTime) {
            ans = max(ans, t + tasks[i]);
            i -= 4;
        }
        return ans;
    }
};
```

#### Go

```go
func minProcessingTime(processorTime []int, tasks []int) (ans int) {
	sort.Ints(processorTime)
	sort.Ints(tasks)
	i := len(tasks) - 1
	for _, t := range processorTime {
		ans = max(ans, t+tasks[i])
		i -= 4
	}
	return
}
```

#### TypeScript

```ts
function minProcessingTime(processorTime: number[], tasks: number[]): number {
    processorTime.sort((a, b) => a - b);
    tasks.sort((a, b) => a - b);
    let [ans, i] = [0, tasks.length - 1];
    for (const t of processorTime) {
        ans = Math.max(ans, t + tasks[i]);
        i -= 4;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2896. 执行操作使两个字符串相等](https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal){#2896}

{{< tabs "2896" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            a = dfs(i + 1, j - 1) + x
            b = dfs(i + 2, j) + idx[i + 1] - idx[i]
            c = dfs(i, j - 2) + idx[j] - idx[j - 1]
            return min(a, b, c)

        n = len(s1)
        idx = [i for i in range(n) if s1[i] != s2[i]]
        m = len(idx)
        if m & 1:
            return -1
        return dfs(0, m - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(String s1, String s2, int x) {
        int n = s1.length();
        int inf = 50_000;
        int one = inf, two = inf, last = inf;
        int done = 0;
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                one = Math.min(one, last);
                last = last + 1;
                two = two + 1;
                continue;
            }
            if (done < n) {
                one = Math.min(two + 1, done + x);
                last = Math.min(two + x, done);
                done = two = inf;
                continue;
            }
            done = Math.min(one + x, last + 1);
            two = one;
            one = last = inf;
            continue;
        }
        return done == inf ? -1 : done;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> idx;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                idx.push_back(i);
            }
        }
        int m = idx.size();
        if (m & 1) {
            return -1;
        }
        if (m == 0) {
            return 0;
        }
        int f[m][m];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i > j) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            f[i][j] = min({dfs(i + 1, j - 1) + x, dfs(i + 2, j) + idx[i + 1] - idx[i], dfs(i, j - 2) + idx[j] - idx[j - 1]});
            return f[i][j];
        };
        return dfs(0, m - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(s1 string, s2 string, x int) int {
	idx := []int{}
	for i := range s1 {
		if s1[i] != s2[i] {
			idx = append(idx, i)
		}
	}
	m := len(idx)
	if m&1 == 1 {
		return -1
	}
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = dfs(i+1, j-1) + x
		f[i][j] = min(f[i][j], dfs(i+2, j)+idx[i+1]-idx[i])
		f[i][j] = min(f[i][j], dfs(i, j-2)+idx[j]-idx[j-1])
		return f[i][j]
	}
	return dfs(0, m-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(s1: string, s2: string, x: number): number {
    const idx: number[] = [];
    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] !== s2[i]) {
            idx.push(i);
        }
    }
    const m = idx.length;
    if (m % 2 === 1) {
        return -1;
    }
    if (m === 0) {
        return 0;
    }
    const f: number[][] = Array.from({ length: m }, () => Array.from({ length: m }, () => -1));
    const dfs = (i: number, j: number): number => {
        if (i > j) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] = dfs(i + 1, j - 1) + x;
        f[i][j] = Math.min(f[i][j], dfs(i + 2, j) + idx[i + 1] - idx[i]);
        f[i][j] = Math.min(f[i][j], dfs(i, j - 2) + idx[j] - idx[j - 1]);
        return f[i][j];
    };
    return dfs(0, m - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的二进制字符串&nbsp;<code>s1</code> 和&nbsp;<code>s2</code>&nbsp;，两个字符串的长度都是&nbsp;<code>n</code>&nbsp;，再给你一个正整数&nbsp;<code>x</code>&nbsp;。</p>

<p>你可以对字符串 <code>s1</code>&nbsp;执行以下操作 <strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;，将&nbsp;<code>s1[i]</code> 和&nbsp;<code>s1[j]</code>&nbsp;都反转，操作的代价为&nbsp;<code>x</code>&nbsp;。</li>
	<li>选择满足 <code>i &lt; n - 1</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;，反转&nbsp;<code>s1[i]</code> 和&nbsp;<code>s1[i + 1]</code>&nbsp;，操作的代价为&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>请你返回使字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;相等的&nbsp;<strong>最小</strong>&nbsp;操作代价之和，如果无法让二者相等，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><strong>注意</strong>&nbsp;，反转字符的意思是将&nbsp;<code>0</code>&nbsp;变成&nbsp;<code>1</code>&nbsp;，或者 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "1100011000", s2 = "0101001010", x = 2
<b>输出：</b>4
<b>解释：</b>我们可以执行以下操作：
- 选择 i = 3 执行第二个操作。结果字符串是 s1 = "110<em><strong>11</strong></em>11000" 。
- 选择 i = 4 执行第二个操作。结果字符串是 s1 = "1101<em><strong>00</strong></em>1000" 。
- 选择 i = 0 和 j = 8 ，执行第一个操作。结果字符串是 s1 = "<em><strong>0</strong></em>1010010<em><strong>1</strong></em>0" = s2 。
总代价是 1 + 1 + 2 = 4 。这是最小代价和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "10110", s2 = "00011", x = 4
<b>输出：</b>-1
<b>解释：</b>无法使两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n, x &lt;= 500</code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含字符&nbsp;<code>'0'</code> 和&nbsp;<code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们注意到，由于每次操作都是反转两个字符，因此，如果不同的字符个数为奇数，那么无法使两个字符串相等，直接返回 $-1$。否则，我们将两个字符串中不同的字符的下标存入数组 $idx$ 中，记数组长度为 $m$。

接下来，我们设计一个函数 $dfs(i, j)$，表示将 $idx[i..j]$ 中的字符反转的最小操作代价。答案即为 $dfs(0, m - 1)$。

函数 $dfs(i, j)$ 的计算过程如下：

如果 $i \gt j$，那么不需要进行任何操作，返回 $0$；

否则，我们考虑对区间 $[i, j]$ 的端点进行操作：

-   如果我们对端点 $i$ 进行第一种操作，由于代价 $x$ 已经固定，因此，我们最优的选择是将 $idx[i]$ 和 $idx[j]$ 反转，然后递归计算 $dfs(i + 1, j - 1)$，总代价为 $dfs(i + 1, j - 1) + x$；
-   如果我们对端点 $i$ 进行第二种操作，那么我们需要将 $[idx[i]..idx[i + 1]]$ 中的字符全部反转，然后递归计算 $dfs(i + 2, j)$，总代价为 $dfs(i + 2, j) + idx[i + 1] - idx[i]$；
-   如果我们对端点 $j$ 进行第二种操作，那么我们需要将 $[idx[j - 1]..idx[j]]$ 中的字符全部反转，然后递归计算 $dfs(i, j - 2)$，总代价为 $dfs(i, j - 2) + idx[j] - idx[j - 1]$。

我们取上述三种操作的最小值，即为 $dfs(i, j)$ 的值。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            a = dfs(i + 1, j - 1) + x
            b = dfs(i + 2, j) + idx[i + 1] - idx[i]
            c = dfs(i, j - 2) + idx[j] - idx[j - 1]
            return min(a, b, c)

        n = len(s1)
        idx = [i for i in range(n) if s1[i] != s2[i]]
        m = len(idx)
        if m & 1:
            return -1
        return dfs(0, m - 1)
```

#### Java

```java
class Solution {
    private List<Integer> idx = new ArrayList<>();
    private Integer[][] f;
    private int x;

    public int minOperations(String s1, String s2, int x) {
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            if (s1.charAt(i) != s2.charAt(i)) {
                idx.add(i);
            }
        }
        int m = idx.size();
        if (m % 2 == 1) {
            return -1;
        }
        this.x = x;
        f = new Integer[m][m];
        return dfs(0, m - 1);
    }

    private int dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        f[i][j] = dfs(i + 1, j - 1) + x;
        f[i][j] = Math.min(f[i][j], dfs(i + 2, j) + idx.get(i + 1) - idx.get(i));
        f[i][j] = Math.min(f[i][j], dfs(i, j - 2) + idx.get(j) - idx.get(j - 1));
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> idx;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                idx.push_back(i);
            }
        }
        int m = idx.size();
        if (m & 1) {
            return -1;
        }
        if (m == 0) {
            return 0;
        }
        int f[m][m];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i > j) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            f[i][j] = min({dfs(i + 1, j - 1) + x, dfs(i + 2, j) + idx[i + 1] - idx[i], dfs(i, j - 2) + idx[j] - idx[j - 1]});
            return f[i][j];
        };
        return dfs(0, m - 1);
    }
};
```

#### Go

```go
func minOperations(s1 string, s2 string, x int) int {
	idx := []int{}
	for i := range s1 {
		if s1[i] != s2[i] {
			idx = append(idx, i)
		}
	}
	m := len(idx)
	if m&1 == 1 {
		return -1
	}
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, m)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = dfs(i+1, j-1) + x
		f[i][j] = min(f[i][j], dfs(i+2, j)+idx[i+1]-idx[i])
		f[i][j] = min(f[i][j], dfs(i, j-2)+idx[j]-idx[j-1])
		return f[i][j]
	}
	return dfs(0, m-1)
}
```

#### TypeScript

```ts
function minOperations(s1: string, s2: string, x: number): number {
    const idx: number[] = [];
    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] !== s2[i]) {
            idx.push(i);
        }
    }
    const m = idx.length;
    if (m % 2 === 1) {
        return -1;
    }
    if (m === 0) {
        return 0;
    }
    const f: number[][] = Array.from({ length: m }, () => Array.from({ length: m }, () => -1));
    const dfs = (i: number, j: number): number => {
        if (i > j) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] = dfs(i + 1, j - 1) + x;
        f[i][j] = Math.min(f[i][j], dfs(i + 2, j) + idx[i + 1] - idx[i]);
        f[i][j] = Math.min(f[i][j], dfs(i, j - 2) + idx[j] - idx[j - 1]);
        return f[i][j];
    };
    return dfs(0, m - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int minOperations(String s1, String s2, int x) {
        int n = s1.length();
        int inf = 50_000;
        int one = inf, two = inf, last = inf;
        int done = 0;
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                one = Math.min(one, last);
                last = last + 1;
                two = two + 1;
                continue;
            }
            if (done < n) {
                one = Math.min(two + 1, done + x);
                last = Math.min(two + x, done);
                done = two = inf;
                continue;
            }
            done = Math.min(one + x, last + 1);
            two = one;
            one = last = inf;
            continue;
        }
        return done == inf ? -1 : done;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2897. 对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares){#2897}

{{< tabs "2897" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        cnt = [0] * 31
        for x in nums:
            for i in range(31):
                if x >> i & 1:
                    cnt[i] += 1
        ans = 0
        for _ in range(k):
            x = 0
            for i in range(31):
                if cnt[i]:
                    x |= 1 << i
                    cnt[i] -= 1
            ans = (ans + x * x) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = new int[31];
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((x >> i & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        long ans = 0;
        while (k-- > 0) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if (cnt[i] > 0) {
                    x |= 1 << i;
                    --cnt[i];
                }
            }
            ans = (ans + 1L * x * x) % mod;
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
    int maxSum(vector<int>& nums, int k) {
        int cnt[31]{};
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if (x >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        while (k--) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if (cnt[i]) {
                    x |= 1 << i;
                    --cnt[i];
                }
            }
            ans = (ans + 1LL * x * x) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSum(nums []int, k int) (ans int) {
	cnt := [31]int{}
	for _, x := range nums {
		for i := 0; i < 31; i++ {
			if x>>i&1 == 1 {
				cnt[i]++
			}
		}
	}
	const mod int = 1e9 + 7
	for ; k > 0; k-- {
		x := 0
		for i := 0; i < 31; i++ {
			if cnt[i] > 0 {
				x |= 1 << i
				cnt[i]--
			}
		}
		ans = (ans + x*x) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSum(nums: number[], k: number): number {
    const cnt: number[] = Array(31).fill(0);
    for (const x of nums) {
        for (let i = 0; i < 31; ++i) {
            if ((x >> i) & 1) {
                ++cnt[i];
            }
        }
    }
    let ans = 0n;
    const mod = 1e9 + 7;
    while (k-- > 0) {
        let x = 0;
        for (let i = 0; i < 31; ++i) {
            if (cnt[i] > 0) {
                x |= 1 << i;
                --cnt[i];
            }
        }
        ans = (ans + BigInt(x) * BigInt(x)) % BigInt(mod);
    }
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以对数组执行以下操作 <strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>选择两个互不相同的下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，<strong>同时</strong>&nbsp;将&nbsp;<code>nums[i]</code>&nbsp;更新为&nbsp;<code>(nums[i] AND nums[j])</code> 且将&nbsp;<code>nums[j]</code>&nbsp;更新为&nbsp;<code>(nums[i] OR nums[j])</code>&nbsp;，<code>OR</code>&nbsp;表示按位 <strong>或</strong>&nbsp;运算，<code>AND</code>&nbsp;表示按位 <strong>与</strong>&nbsp;运算。</li>
</ul>

<p>你需要从最终的数组里选择&nbsp;<code>k</code>&nbsp;个元素，并计算它们的 <strong>平方</strong>&nbsp;之和。</p>

<p>请你返回你可以得到的 <strong>最大</strong>&nbsp;平方和。</p>

<p>由于答案可能会很大，将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,6,5,8], k = 2
<b>输出：</b>261
<b>解释：</b>我们可以对数组执行以下操作：
- 选择 i = 0 和 j = 3 ，同时将 nums[0] 变为 (2 AND 8) = 0 且 nums[3] 变为 (2 OR 8) = 10 ，结果数组为 nums = [0,6,5,10] 。
- 选择 i = 2 和 j = 3 ，同时将 nums[2] 变为 (5 AND 10) = 0 且 nums[3] 变为 (5 OR 10) = 15 ，结果数组为 nums = [0,6,0,15] 。
从最终数组里选择元素 15 和 6 ，平方和为 15<sup>2</sup> + 6<sup>2</sup> = 261 。
261 是可以得到的最大结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,5,4,7], k = 3
<b>输出：</b>90
<b>解释：</b>不需要执行任何操作。
选择元素 7 ，5 和 4 ，平方和为 7<sup>2</sup> + 5<sup>2</sup> + 4<sup>2</sup> = 90 。
90 是可以得到的最大结果。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算 + 贪心

根据题目描述，对于一个操作，我们可以将 $nums[i]$ 变为 $nums[i] \textit{ AND } nums[j]$，将 $nums[j]$ 变为 $nums[i] \textit{ OR } nums[j]$。我们不妨按位考虑，两个 $1$ 或两个 $0$ 进行这样的操作，结果都不会改变，如果是 $1$ 和 $0$ 进行这样的操作，结果会变成 $0$ 和 $1$，也即是说，我们可以将 $1$ 转移到 $0$ 上，而 $0$ 不会转移到 $1$ 上。

因此，我们可以用一个数组 $cnt$ 统计每个位置上 $1$ 的个数，然后从中选择 $k$ 个数。由于要使得平方和最大，每次选择的数要尽可能大。这是因为，假设两个数的平方和为 $a^2 + b^2$（其中 $a \gt b$），将两个数平方和变成 $(a + c)^2 + (b - c)^2 = a^2 + b^2 + 2c(a - b) + 2c^2 \gt a^2 + b^2$。因此，为了最大化平方和，我们应该让一个数字尽可能大。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$，其中 $M$ 是数组中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        cnt = [0] * 31
        for x in nums:
            for i in range(31):
                if x >> i & 1:
                    cnt[i] += 1
        ans = 0
        for _ in range(k):
            x = 0
            for i in range(31):
                if cnt[i]:
                    x |= 1 << i
                    cnt[i] -= 1
            ans = (ans + x * x) % mod
        return ans
```

#### Java

```java
class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = new int[31];
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((x >> i & 1) == 1) {
                    ++cnt[i];
                }
            }
        }
        long ans = 0;
        while (k-- > 0) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if (cnt[i] > 0) {
                    x |= 1 << i;
                    --cnt[i];
                }
            }
            ans = (ans + 1L * x * x) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int cnt[31]{};
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if (x >> i & 1) {
                    ++cnt[i];
                }
            }
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        while (k--) {
            int x = 0;
            for (int i = 0; i < 31; ++i) {
                if (cnt[i]) {
                    x |= 1 << i;
                    --cnt[i];
                }
            }
            ans = (ans + 1LL * x * x) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func maxSum(nums []int, k int) (ans int) {
	cnt := [31]int{}
	for _, x := range nums {
		for i := 0; i < 31; i++ {
			if x>>i&1 == 1 {
				cnt[i]++
			}
		}
	}
	const mod int = 1e9 + 7
	for ; k > 0; k-- {
		x := 0
		for i := 0; i < 31; i++ {
			if cnt[i] > 0 {
				x |= 1 << i
				cnt[i]--
			}
		}
		ans = (ans + x*x) % mod
	}
	return
}
```

#### TypeScript

```ts
function maxSum(nums: number[], k: number): number {
    const cnt: number[] = Array(31).fill(0);
    for (const x of nums) {
        for (let i = 0; i < 31; ++i) {
            if ((x >> i) & 1) {
                ++cnt[i];
            }
        }
    }
    let ans = 0n;
    const mod = 1e9 + 7;
    while (k-- > 0) {
        let x = 0;
        for (let i = 0; i < 31; ++i) {
            if (cnt[i] > 0) {
                x |= 1 << i;
                --cnt[i];
            }
        }
        ans = (ans + BigInt(x) * BigInt(x)) % BigInt(mod);
    }
    return Number(ans);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2898. 最大线性股票得分 🔒](https://leetcode.cn/problems/maximum-linear-stock-score){#2898}

{{< tabs "2898" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, prices: List[int]) -> int:
        cnt = Counter()
        for i, x in enumerate(prices):
            cnt[x - i] += x
        return max(cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxScore(int[] prices) {
        Map<Integer, Long> cnt = new HashMap<>();
        for (int i = 0; i < prices.length; ++i) {
            cnt.merge(prices[i] - i, (long) prices[i], Long::sum);
        }
        long ans = 0;
        for (long v : cnt.values()) {
            ans = Math.max(ans, v);
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
    long long maxScore(vector<int>& prices) {
        unordered_map<int, long long> cnt;
        for (int i = 0; i < prices.size(); ++i) {
            cnt[prices[i] - i] += prices[i];
        }
        long long ans = 0;
        for (auto& [_, v] : cnt) {
            ans = max(ans, v);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(prices []int) (ans int64) {
	cnt := map[int]int{}
	for i, x := range prices {
		cnt[x-i] += x
	}
	for _, v := range cnt {
		ans = max(ans, int64(v))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(prices: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (let i = 0; i < prices.length; ++i) {
        const j = prices[i] - i;
        cnt.set(j, (cnt.get(j) || 0) + prices[i]);
    }
    return Math.max(...cnt.values());
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn max_score(prices: Vec<i32>) -> i64 {
        let mut cnt: HashMap<i32, i64> = HashMap::new();

        for (i, x) in prices.iter().enumerate() {
            let key = (*x as i32) - (i as i32);
            let count = cnt.entry(key).or_insert(0);
            *count += *x as i64;
        }

        *cnt.values().max().unwrap_or(&0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <strong>1-indexed</strong> 整数数组 <code>prices</code>，其中 <code>prices[i]</code> 是第 <code>i</code> 天某只股票的价格。你的任务是&nbsp;<strong>线性</strong>&nbsp;地选择 <code>prices</code>&nbsp;中的一些元素。</p>

<p>一个选择 <code>indexes</code>，其中 <code>indexes</code> 是一个 <strong>1-indexed</strong> 整数数组，长度为 <code>k</code>，是数组 <code>[1, 2, ..., n]</code> 的子序列，如果以下条件成立，那么它是 <strong>线性</strong> 的：</p>

<ul>
	<li>对于每个 <code>1 &lt; j &lt;= k，prices[indexes[j]] - prices[indexes[j - 1]] == indexes[j] - indexes[j - 1]</code>。</li>
</ul>

<p>数组的 <strong>子序列</strong> 是经由原数组删除一些元素（可能不删除）而产生的新数组，且删除不改变其余元素相对顺序。</p>

<p>选择 <code>indexes</code> 的 <strong>得分</strong> 等于以下数组的总和：<code>[prices[indexes[1]], prices[indexes[2]], ..., prices[indexes[k]]</code>。</p>

<p>返回 <em>线性选择的&nbsp;<strong>最大得分</strong>。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> prices = [1,5,3,7,8]
<strong>输出：</strong> 20
<strong>解释：</strong> 我们可以选择索引[2,4,5]。我们可以证明我们的选择是线性的：
对于j = 2，我们有：
indexes[2] - indexes[1] = 4 - 2 = 2。
prices[4] - prices[2] = 7 - 5 = 2。
对于j = 3，我们有：
indexes[3] - indexes[2] = 5 - 4 = 1。
prices[5] - prices[4] = 8 - 7 = 1。
元素的总和是：prices[2] + prices[4] + prices[5] = 20。 
可以证明线性选择的最大和是20。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b> prices = [5,6,7,8,9]
<b>输出：</b> 35
<b>解释：</b> 我们可以选择所有索引[1,2,3,4,5]。因为每个元素与前一个元素的差异恰好为1，所以我们的选择是线性的。
所有元素的总和是35，这是每个选择的最大可能总和。</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以将式子进行变换，得到：

$$
prices[i] - i = prices[j] - j
$$

题目实际上求的是相同的 $prices[i] - i$ 下，所有 $prices[i]$ 的和的最大值和。

因此，我们可以用一个哈希表 $cnt$ 来存储 $prices[i] - i$ 下，所有 $prices[i]$ 的和，最后取哈希表中的最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, prices: List[int]) -> int:
        cnt = Counter()
        for i, x in enumerate(prices):
            cnt[x - i] += x
        return max(cnt.values())
```

#### Java

```java
class Solution {
    public long maxScore(int[] prices) {
        Map<Integer, Long> cnt = new HashMap<>();
        for (int i = 0; i < prices.length; ++i) {
            cnt.merge(prices[i] - i, (long) prices[i], Long::sum);
        }
        long ans = 0;
        for (long v : cnt.values()) {
            ans = Math.max(ans, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxScore(vector<int>& prices) {
        unordered_map<int, long long> cnt;
        for (int i = 0; i < prices.size(); ++i) {
            cnt[prices[i] - i] += prices[i];
        }
        long long ans = 0;
        for (auto& [_, v] : cnt) {
            ans = max(ans, v);
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(prices []int) (ans int64) {
	cnt := map[int]int{}
	for i, x := range prices {
		cnt[x-i] += x
	}
	for _, v := range cnt {
		ans = max(ans, int64(v))
	}
	return
}
```

#### TypeScript

```ts
function maxScore(prices: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (let i = 0; i < prices.length; ++i) {
        const j = prices[i] - i;
        cnt.set(j, (cnt.get(j) || 0) + prices[i]);
    }
    return Math.max(...cnt.values());
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn max_score(prices: Vec<i32>) -> i64 {
        let mut cnt: HashMap<i32, i64> = HashMap::new();

        for (i, x) in prices.iter().enumerate() {
            let key = (*x as i32) - (i as i32);
            let count = cnt.entry(key).or_insert(0);
            *count += *x as i64;
        }

        *cnt.values().max().unwrap_or(&0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2899. 上一个遍历的整数](https://leetcode.cn/problems/last-visited-integers){#2899}

{{< tabs "2899" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        nums = []
        ans = []
        k = 0
        for w in words:
            if w == "prev":
                k += 1
                i = len(nums) - k
                ans.append(-1 if i < 0 else nums[i])
            else:
                k = 0
                nums.append(int(w))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> lastVisitedIntegers(List<String> words) {
        List<Integer> nums = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        int k = 0;
        for (var w : words) {
            if ("prev".equals(w)) {
                ++k;
                int i = nums.size() - k;
                ans.add(i < 0 ? -1 : nums.get(i));
            } else {
                k = 0;
                nums.add(Integer.valueOf(w));
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
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> ans;
        int k = 0;
        for (auto& w : words) {
            if (w == "prev") {
                ++k;
                int i = nums.size() - k;
                ans.push_back(i < 0 ? -1 : nums[i]);
            } else {
                k = 0;
                nums.push_back(stoi(w));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastVisitedIntegers(words []string) (ans []int) {
	nums := []int{}
	k := 0
	for _, w := range words {
		if w == "prev" {
			k++
			i := len(nums) - k
			if i < 0 {
				ans = append(ans, -1)
			} else {
				ans = append(ans, nums[i])
			}
		} else {
			k = 0
			x, _ := strconv.Atoi(w)
			nums = append(nums, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lastVisitedIntegers(words: string[]): number[] {
    const nums: number[] = [];
    const ans: number[] = [];
    let k = 0;
    for (const w of words) {
        if (w === 'prev') {
            ++k;
            const i = nums.length - k;
            ans.push(i < 0 ? -1 : nums[i]);
        } else {
            k = 0;
            nums.push(+w);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn last_visited_integers(words: Vec<String>) -> Vec<i32> {
        let mut nums: Vec<i32> = Vec::new();
        let mut ans: Vec<i32> = Vec::new();
        let mut k = 0;

        for w in words {
            if w == "prev" {
                k += 1;
                let i = (nums.len() as i32) - k;
                ans.push(if i < 0 { -1 } else { nums[i as usize] });
            } else {
                k = 0;
                nums.push(w.parse::<i32>().unwrap());
            }
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;要么是一个正整数，要么是&nbsp;<code>-1</code>&nbsp;。我们需要为每个 <code>-1</code> 找到相应的正整数，我们称之为最后访问的整数。</p>

<p>为了达到这个目标，定义两个空数组：<code>seen</code>&nbsp;和&nbsp;<code>ans</code>。</p>

<p>从数组&nbsp;<code>nums</code>&nbsp;的头部开始遍历。</p>

<ul>
	<li>如果遇到正整数，把它添加到&nbsp;<code>seen</code>&nbsp;的&nbsp;<strong>头部</strong>。</li>
	<li>如果遇到 <code>-1</code>，则设 <code>k</code> 是到目前为止看到的 <strong>连续</strong> <code>-1</code> 的数目(包括当前 <code>-1</code>)，
	<ul>
		<li>如果&nbsp;<code>k</code>&nbsp;小于等于&nbsp;<code>seen</code>&nbsp;的长度，把&nbsp;<code>seen</code>&nbsp;的第&nbsp;<code>k</code>&nbsp;个元素添加到&nbsp;<code>ans</code>。</li>
		<li>如果&nbsp;<code>k</code>&nbsp;严格大于&nbsp;<code>seen</code>&nbsp;的长度，把&nbsp;<code>-1</code>&nbsp;添加到&nbsp;<code>ans</code>。</li>
	</ul>
	</li>
</ul>

<p>请你返回数组&nbsp;<code>ans</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,-1,-1,-1]
<b>输出：</b>[2,1,-1]
<b>解释：</b> 开始时 seen = [] 且 ans = []。
1.处理 nums[0]：nums 中的第一个元素是 1。我们将其放在 seen 的前面。现在，seen == [1]。
2.处理 nums[1]：下一个元素是 2。我们将其放在 seen 的前面。现在，seen == [2, 1]。
3.处理 nums[2]：下一个元素是 -1。这是 -1 的第一次出现，所以 k == 1。我们找到 seen 中的第一个元素，把 2 添加到 ans。现在，ans == [2]。
4.处理 nums[3]：又一个 -1。这是 -1 的第二次出现，所以 k == 2。seen 中的第二个元素是 1，所以我们把 1 添加到 ans。现在，ans == [2, 1]。
5.处理 nums[4]：又一个 -1。第三次出现，让 k = 3。然而，seen 中只有两个元素（[2, 1]）。因为 k 比 seen 中的元素数量更大，我们把 -1 添加到 ans。最终，ans == [2, 1, -1]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,-1,2,-1,-1]
<b>输出：</b>[1,2,1]
<strong>解释：</strong> 开始时 seen = [] 且 ans = []。
1.处理 nums[0]：nums 中的第一个元素是 1。我们将其放在 seen 的前面。现在，seen == [1]。
2.处理 nums[1]：下一个元素是 -1。这是 -1 的第一次出现，所以 k == 1。我们找到 seen 中的第一个元素，即 1。把 1 添加到 ans。现在，ans == [1]。
3.处理 nums[2]：下一个元素是 2。我们将其放在 seen 的前面。现在，seen == [2, 1]。
4.处理 nums[3]：下一个元素是 -1。这个 -1 与 第一个 -1 不连续，因为中间有个 2。因此，k 重置为 1。seen 中的第一个元素是 2，所以我们把 2 添加到 ans。现在，ans == [1, 2]。
5.处理 nums[4]：又一个 -1。它与前一个 -1 相邻，所以 k == 2。seen 中的第 2 个元素是 1。把 1 添加到 ans。最终，ans == [1, 2, 1]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums[i] == -1</code>&nbsp;或&nbsp;<code>1 &lt;= nums[i]&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接根据题意模拟即可。在实现上，我们使用一个数组 $nums$ 来存储遍历过的整数，使用一个整数 $k$ 来记录当前连续的 $prev$ 字符串数目。如果当前字符串是 $prev$，那么我们就从 $nums$ 中取出第 $|nums| - k$ 个整数，如果不存在，那么就返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $words$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        nums = []
        ans = []
        k = 0
        for w in words:
            if w == "prev":
                k += 1
                i = len(nums) - k
                ans.append(-1 if i < 0 else nums[i])
            else:
                k = 0
                nums.append(int(w))
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> lastVisitedIntegers(List<String> words) {
        List<Integer> nums = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        int k = 0;
        for (var w : words) {
            if ("prev".equals(w)) {
                ++k;
                int i = nums.size() - k;
                ans.add(i < 0 ? -1 : nums.get(i));
            } else {
                k = 0;
                nums.add(Integer.valueOf(w));
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
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> ans;
        int k = 0;
        for (auto& w : words) {
            if (w == "prev") {
                ++k;
                int i = nums.size() - k;
                ans.push_back(i < 0 ? -1 : nums[i]);
            } else {
                k = 0;
                nums.push_back(stoi(w));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func lastVisitedIntegers(words []string) (ans []int) {
	nums := []int{}
	k := 0
	for _, w := range words {
		if w == "prev" {
			k++
			i := len(nums) - k
			if i < 0 {
				ans = append(ans, -1)
			} else {
				ans = append(ans, nums[i])
			}
		} else {
			k = 0
			x, _ := strconv.Atoi(w)
			nums = append(nums, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function lastVisitedIntegers(words: string[]): number[] {
    const nums: number[] = [];
    const ans: number[] = [];
    let k = 0;
    for (const w of words) {
        if (w === 'prev') {
            ++k;
            const i = nums.length - k;
            ans.push(i < 0 ? -1 : nums[i]);
        } else {
            k = 0;
            nums.push(+w);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn last_visited_integers(words: Vec<String>) -> Vec<i32> {
        let mut nums: Vec<i32> = Vec::new();
        let mut ans: Vec<i32> = Vec::new();
        let mut k = 0;

        for w in words {
            if w == "prev" {
                k += 1;
                let i = (nums.len() as i32) - k;
                ans.push(if i < 0 { -1 } else { nums[i as usize] });
            } else {
                k = 0;
                nums.push(w.parse::<i32>().unwrap());
            }
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

---
title: "1510_石子游戏 IV"
date: 2025-10-08T18:37:33+08:00
weight: 2
tags: [几何, 动态规划, 博弈, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 数学, 数据库, 数组, 最短路, 树, 模拟, 深度优先搜索, 计数, 随机化]
---

{{< markmap >}}
### [1510_石子游戏 IV](#1510)
#### [数学](#1510)
#### [动态规划](#1510)
#### [博弈](#1510)
### [1511_消费者下单频率 🔒](#1511)
#### [数据库](#1511)
### [1512_好数对的数目](#1512)
#### [数组](#1512)
#### [哈希表](#1512)
#### [数学](#1512)
#### [计数](#1512)
### [1513_仅含 1 的子串数](#1513)
#### [数学](#1513)
#### [字符串](#1513)
### [1514_概率最大的路径](#1514)
#### [图](#1514)
#### [数组](#1514)
#### [最短路](#1514)
#### [堆（优先队列）](#1514)
### [1515_服务中心的最佳位置](#1515)
#### [几何](#1515)
#### [数组](#1515)
#### [数学](#1515)
#### [随机化](#1515)
### [1516_移动 N 叉树的子树 🔒](#1516)
#### [树](#1516)
#### [深度优先搜索](#1516)
### [1517_查找拥有有效邮箱的用户](#1517)
#### [数据库](#1517)
### [1518_换水问题](#1518)
#### [数学](#1518)
#### [模拟](#1518)
### [1519_子树中标签相同的节点数](#1519)
#### [树](#1519)
#### [深度优先搜索](#1519)
#### [广度优先搜索](#1519)
#### [哈希表](#1519)
#### [计数](#1519)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1510_石子游戏 IV
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1511_消费者下单频率 🔒
___
#### 数据库
---
### 1512_好数对的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 1513_仅含 1 的子串数
___
#### 数学
___
#### 字符串
---
### 1514_概率最大的路径
___
#### 图
___
#### 数组
___
#### 最短路
___
#### 堆（优先队列）
---
### 1515_服务中心的最佳位置
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 随机化
---
### 1516_移动 N 叉树的子树 🔒
___
#### 树
___
#### 深度优先搜索
---
### 1517_查找拥有有效邮箱的用户
___
#### 数据库
---
### 1518_换水问题
___
#### 数学
___
#### 模拟
---
### 1519_子树中标签相同的节点数
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 几何 | 动态规划 | 博弈 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 数学 |
| 数据库 | 数组 | 最短路 |
| 树 | 模拟 | 深度优先搜索 |
| 计数 | 随机化 |  |

# [1510. 石子游戏 IV](https://leetcode.cn/problems/stone-game-iv){#1510}

{{< tabs "1510" >}}

{{% tab "python" %}}
```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        f = [False] * (n + 1)
        for i in range(1, n + 1):
            j = 1
            while j <= i // j:
                if not f[i - j * j]:
                    f[i] = True
                    break
                j += 1
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] f = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i / j; ++j) {
                if (!f[i - j * j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool winnerSquareGame(int n) {
        bool f[n + 1];
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i / j; ++j) {
                if (!f[i - j * j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func winnerSquareGame(n int) bool {
	f := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= i/j; j++ {
			if !f[i-j*j] {
				f[i] = true
				break
			}
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function winnerSquareGame(n: number): boolean {
    const f: boolean[] = new Array(n + 1).fill(false);
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j * j <= i; ++j) {
            if (!f[i - j * j]) {
                f[i] = true;
                break;
            }
        }
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 两个人轮流玩一个游戏，Alice 先手。</p>

<p>一开始，有 <code>n</code>&nbsp;个石子堆在一起。每个人轮流操作，正在操作的玩家可以从石子堆里拿走 <strong>任意</strong>&nbsp;非零 <strong>平方数</strong>&nbsp;个石子。</p>

<p>如果石子堆里没有石子了，则无法操作的玩家输掉游戏。</p>

<p>给你正整数&nbsp;<code>n</code>&nbsp;，且已知两个人都采取最优策略。如果 Alice 会赢得比赛，那么返回&nbsp;<code>True</code>&nbsp;，否则返回&nbsp;<code>False</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>Alice 拿走 1 个石子并赢得胜利，因为 Bob 无法进行任何操作。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>false
<strong>解释：</strong>Alice 只能拿走 1 个石子，然后 Bob 拿走最后一个石子并赢得胜利（2 -&gt; 1 -&gt; 0）。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>true
<strong>解释：</strong>n 已经是一个平方数，Alice 可以一次全拿掉 4 个石子并赢得胜利（4 -&gt; 0）。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>false
<strong>解释：</strong>当 Bob 采取最优策略时，Alice 无法赢得比赛。
如果 Alice 一开始拿走 4 个石子， Bob 会拿走 1 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -&gt; 3 -&gt; 2 -&gt; 1 -&gt; 0）。
如果 Alice 一开始拿走 1 个石子， Bob 会拿走 4 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -&gt; 6 -&gt; 2 -&gt; 1 -&gt; 0）。</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>n = 17
<strong>输出：</strong>false
<strong>解释：</strong>如果 Bob 采取最优策略，Alice 无法赢得胜利。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示当前石子堆中有 $i$ 个石子时，当前玩家是否能赢得比赛。如果当前玩家能赢得比赛，则返回 $true$，否则返回 $false$。那么答案即为 $dfs(n)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \leq 0$，说明当前玩家无法进行任何操作，因此当前玩家输掉比赛，返回 $false$；
-   否则，枚举当前玩家可以拿走的石子数量 $j$，其中 $j$ 为平方数，如果当前玩家拿走 $j$ 个石子后，另一个玩家无法赢得比赛，则当前玩家赢得比赛，返回 $true$。如果枚举完所有的 $j$，都无法满足上述条件，则当前玩家输掉比赛，返回 $false$。

为了避免重复计算，我们可以使用记忆化搜索，即使用数组 $f$ 记录函数 $dfs(i)$ 的计算结果。

时间复杂度 $O(n \times \sqrt{n})$，空间复杂度 $O(n)$。其中 $n$ 为石子堆中石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @cache
        def dfs(i: int) -> bool:
            if i == 0:
                return False
            j = 1
            while j * j <= i:
                if not dfs(i - j * j):
                    return True
                j += 1
            return False

        return dfs(n)
```

#### Java

```java
class Solution {
    private Boolean[] f;

    public boolean winnerSquareGame(int n) {
        f = new Boolean[n + 1];
        return dfs(n);
    }

    private boolean dfs(int i) {
        if (i <= 0) {
            return false;
        }
        if (f[i] != null) {
            return f[i];
        }
        for (int j = 1; j <= i / j; ++j) {
            if (!dfs(i - j * j)) {
                return f[i] = true;
            }
        }
        return f[i] = false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool winnerSquareGame(int n) {
        int f[n + 1];
        memset(f, 0, sizeof(f));
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i <= 0) {
                return false;
            }
            if (f[i] != 0) {
                return f[i] == 1;
            }
            for (int j = 1; j <= i / j; ++j) {
                if (!dfs(i - j * j)) {
                    f[i] = 1;
                    return true;
                }
            }
            f[i] = -1;
            return false;
        };
        return dfs(n);
    }
};
```

#### Go

```go
func winnerSquareGame(n int) bool {
	f := make([]int, n+1)
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i <= 0 {
			return false
		}
		if f[i] != 0 {
			return f[i] == 1
		}
		for j := 1; j <= i/j; j++ {
			if !dfs(i - j*j) {
				f[i] = 1
				return true
			}
		}
		f[i] = -1
		return false
	}
	return dfs(n)
}
```

#### TypeScript

```ts
function winnerSquareGame(n: number): boolean {
    const f: number[] = new Array(n + 1).fill(0);
    const dfs = (i: number): boolean => {
        if (i <= 0) {
            return false;
        }
        if (f[i] !== 0) {
            return f[i] === 1;
        }
        for (let j = 1; j * j <= i; ++j) {
            if (!dfs(i - j * j)) {
                f[i] = 1;
                return true;
            }
        }
        f[i] = -1;
        return false;
    };
    return dfs(n);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划求解本题。

定义数组 $f$，其中 $f[i]$ 表示当前石子堆中有 $i$ 个石子时，当前玩家是否能赢得比赛。如果当前玩家能赢得比赛，则 $f[i]$ 为 $true$，否则为 $false$。那么答案即为 $f[n]$。

我们在 $[1,..n]$ 的范围内枚举 $i$，并在 $[1,..i]$ 的范围内枚举 $j$，其中 $j$ 为平方数，如果当前玩家拿走 $j$ 个石子后，另一个玩家无法赢得比赛，则当前玩家赢得比赛，即 $f[i] = true$。如果枚举完所有的 $j$，都无法满足上述条件，则当前玩家输掉比赛，即 $f[i] = false$。因此我们可以得到状态转移方程：

$$
f[i]=
\begin{cases}
true, & \textit{if } \exists j \in [1,..i], j^2 \leq i \textit{ and } f[i-j^2] = false\\
false, & \textit{otherwise}
\end{cases}
$$

最后，我们返回 $f[n]$ 即可。

时间复杂度 $O(n \times \sqrt{n})$，空间复杂度 $O(n)$。其中 $n$ 为石子堆中石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        f = [False] * (n + 1)
        for i in range(1, n + 1):
            j = 1
            while j <= i // j:
                if not f[i - j * j]:
                    f[i] = True
                    break
                j += 1
        return f[n]
```

#### Java

```java
class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] f = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i / j; ++j) {
                if (!f[i - j * j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool winnerSquareGame(int n) {
        bool f[n + 1];
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i / j; ++j) {
                if (!f[i - j * j]) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func winnerSquareGame(n int) bool {
	f := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= i/j; j++ {
			if !f[i-j*j] {
				f[i] = true
				break
			}
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function winnerSquareGame(n: number): boolean {
    const f: boolean[] = new Array(n + 1).fill(false);
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j * j <= i; ++j) {
            if (!f[i - j * j]) {
                f[i] = true;
                break;
            }
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1511. 消费者下单频率 🔒](https://leetcode.cn/problems/customer-order-frequency){#1511}

{{< tabs "1511" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT customer_id, name
FROM
    Orders
    JOIN Product USING (product_id)
    JOIN Customers USING (customer_id)
WHERE YEAR(order_date) = 2020
GROUP BY 1
HAVING
    SUM(IF(MONTH(order_date) = 6, quantity * price, 0)) >= 100
    AND SUM(IF(MONTH(order_date) = 7, quantity * price, 0)) >= 100;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
| country       | varchar |
+---------------+---------+
customer_id 是该表具有唯一值的列.
该表包含公司消费者的信息.
</pre>

<p>&nbsp;</p>

<p>表: <code>Product</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| description   | varchar |
| price         | int     |
+---------------+---------+
product_id 是该表具有唯一值的列.
该表包含公司产品的信息.
price 是该产品所需的花销.</pre>

<p>&nbsp;</p>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| product_id    | int     |
| order_date    | date    |
| quantity      | int     |
+---------------+---------+
order_id 是该表具有唯一值的列.
该表包含消费者下单的信息.
customer_id 是买了数量为 "quantity", id 为 "product_id" 产品的消费者的 id.
Order_date 是订单发货的日期, 格式为('YYYY-MM-DD').</pre>

<p>&nbsp;</p>

<p>写一个解决方案，报告在&nbsp;<strong>2020 年 6 月和 7 月&nbsp;</strong>每个月至少花费 <code>$100</code> 的客户的 <code>customer_id</code> 和 <code>customer_name</code> 。</p>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表.</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
<code>Customers table:</code>
+--------------+-----------+-------------+
| customer_id  | name &nbsp;    | country &nbsp; &nbsp; |
+--------------+-----------+-------------+
| 1    &nbsp;       | Winston  &nbsp;| USA        &nbsp;|
| 2          &nbsp; | Jonathan  | Peru       &nbsp;|
| 3          &nbsp; | Moustafa &nbsp;| Egypt      &nbsp;|
+--------------+-----------+-------------+
<code>Product table:</code>
+--------------+-------------+-------------+
| product_id   | description | price   &nbsp; &nbsp; |
+--------------+-------------+-------------+
| 10   &nbsp;       | LC Phone &nbsp;  | 300        &nbsp;|
| 20         &nbsp; | LC T-Shirt  | 10         &nbsp;|
| 30         &nbsp; | LC Book    &nbsp;| 45         &nbsp;|
| 40           | LC Keychain&nbsp;| 2         &nbsp; |
+--------------+-------------+-------------+
<code>Orders table:</code>
+--------------+-------------+-------------+-------------+-----------+
| order_id     | customer_id | product_id  | order_date  | quantity  |
+--------------+-------------+-------------+-------------+-----------+
| 1    &nbsp;       | 1        &nbsp;  | 10         &nbsp;| 2020-06-10  | 1         |
| 2          &nbsp; | 1           | 20         &nbsp;| 2020-07-01  | 1         |
| 3          &nbsp; | 1           | 30         &nbsp;| 2020-07-08  | 2         |
| 4    &nbsp;       | 2        &nbsp;  | 10         &nbsp;| 2020-06-15  | 2         |
| 5          &nbsp; | 2           | 40         &nbsp;| 2020-07-01  | 10        |
| 6          &nbsp; | 3           | 20         &nbsp;| 2020-06-24  | 2         |
| 7    &nbsp;       | 3        &nbsp;  | 30         &nbsp;| 2020-06-25  | 2         |
| 9          &nbsp; | 3           | 30         &nbsp;| 2020-05-08  | 3         |
+--------------+-------------+-------------+-------------+-----------+
<strong>输出：</strong>
+--------------+------------+
| customer_id  | name       |  
+--------------+------------+
| 1            | Winston    |
+--------------+------------+ 
<strong>解释：</strong>
Winston 在 2020 年 6 月花费了 $300(300 * 1), 在 7 月花费了 $100(10 * 1 + 45 * 2).
Jonathan 在 2020 年 6 月花费了 $600(300 * 2), 在 7 月花费了 $20(2 * 10).
Moustafa 在 2020 年 6 月花费了 $110 (10 * 2 + 45 * 2), 在 7 月花费了 $0.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组求和

我们可以使用 `JOIN` 语句，连接 `Orders` 和 `Product` 表，再连接 `Customers` 表，筛选出 `order_date` 在 $2020$ 年的记录，然后使用 `GROUP BY` 语句，按照 `customer_id` 分组，使用 `HAVING` 语句，筛选出 $6$ 月和 $7$ 月花费大于等于 $100$ 的客户。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT customer_id, name
FROM
    Orders
    JOIN Product USING (product_id)
    JOIN Customers USING (customer_id)
WHERE YEAR(order_date) = 2020
GROUP BY 1
HAVING
    SUM(IF(MONTH(order_date) = 6, quantity * price, 0)) >= 100
    AND SUM(IF(MONTH(order_date) = 7, quantity * price, 0)) >= 100;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1512. 好数对的数目](https://leetcode.cn/problems/number-of-good-pairs){#1512}

{{< tabs "1512" >}}

{{% tab "python" %}}
```python
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        cnt = Counter()
        for x in nums:
            ans += cnt[x]
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int ans = 0;
        int[] cnt = new int[101];
        for (int x : nums) {
            ans += cnt[x]++;
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
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int cnt[101]{};
        for (int& x : nums) {
            ans += cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numIdenticalPairs(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numIdenticalPairs(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    let ans = 0;
    for (const x of nums) {
        ans += cnt[x]++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt = [0; 101];
        for &x in nums.iter() {
            ans += cnt[x as usize];
            cnt[x as usize] += 1;
        }
        ans
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
var numIdenticalPairs = function (nums) {
    const cnt = Array(101).fill(0);
    let ans = 0;
    for (const x of nums) {
        ans += cnt[x]++;
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function numIdenticalPairs($nums) {
        $ans = 0;
        $cnt = array_fill(0, 101, 0);
        foreach ($nums as $x) {
            $ans += $cnt[$x]++;
        }
        return $ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int numIdenticalPairs(int* nums, int numsSize) {
    int cnt[101] = {0};
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += cnt[nums[i]]++;
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

<p>给你一个整数数组 <code>nums</code> 。</p>

<p>如果一组数字 <code>(i,j)</code> 满足 <code>nums[i]</code> == <code>nums[j]</code> 且 <code>i</code> &lt; <code>j</code> ，就可以认为这是一组 <strong>好数对</strong> 。</p>

<p>返回好数对的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,1,1,3]
<strong>输出：</strong>4
<strong>解释：</strong>有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,1,1]
<strong>输出：</strong>6
<strong>解释：</strong>数组中的每组数字都是好数对</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>0
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

### 方法一：计数

遍历数组，对于每个元素 $x$，计算 $x$ 之前有多少个元素与其相等，即为 $x$ 与之前元素组成的好数对的数目。遍历完数组后，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为数组长度，而 $C$ 为数组中元素的取值范围。本题中 $C = 101$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        cnt = Counter()
        for x in nums:
            ans += cnt[x]
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int ans = 0;
        int[] cnt = new int[101];
        for (int x : nums) {
            ans += cnt[x]++;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int cnt[101]{};
        for (int& x : nums) {
            ans += cnt[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func numIdenticalPairs(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		ans += cnt[x]
		cnt[x]++
	}
	return
}
```

#### TypeScript

```ts
function numIdenticalPairs(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    let ans = 0;
    for (const x of nums) {
        ans += cnt[x]++;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt = [0; 101];
        for &x in nums.iter() {
            ans += cnt[x as usize];
            cnt[x as usize] += 1;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function (nums) {
    const cnt = Array(101).fill(0);
    let ans = 0;
    for (const x of nums) {
        ans += cnt[x]++;
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function numIdenticalPairs($nums) {
        $ans = 0;
        $cnt = array_fill(0, 101, 0);
        foreach ($nums as $x) {
            $ans += $cnt[$x]++;
        }
        return $ans;
    }
}
```

#### C

```c
int numIdenticalPairs(int* nums, int numsSize) {
    int cnt[101] = {0};
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += cnt[nums[i]]++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1513. 仅含 1 的子串数](https://leetcode.cn/problems/number-of-substrings-with-only-1s){#1513}

{{< tabs "1513" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSub(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == "1":
                cnt += 1
            else:
                cnt = 0
            ans += cnt
        return ans % (10**9 + 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSub(String s) {
        final int mod = (int) 1e9 + 7;
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            cnt = s.charAt(i) == '1' ? cnt + 1 : 0;
            ans = (ans + cnt) % mod;
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
    int numSub(string s) {
        int ans = 0, cnt = 0;
        const int mod = 1e9 + 7;
        for (char& c : s) {
            cnt = c == '1' ? cnt + 1 : 0;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSub(s string) (ans int) {
	const mod = 1e9 + 7
	cnt := 0
	for _, c := range s {
		if c == '1' {
			cnt++
		} else {
			cnt = 0
		}
		ans = (ans + cnt) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSub(s: string): number {
    const mod = 10 ** 9 + 7;
    let ans = 0;
    let cnt = 0;
    for (const c of s) {
        cnt = c == '1' ? cnt + 1 : 0;
        ans = (ans + cnt) % mod;
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

<p>给你一个二进制字符串 <code>s</code>（仅由 &#39;0&#39; 和 &#39;1&#39; 组成的字符串）。</p>

<p>返回所有字符都为 1 的子字符串的数目。</p>

<p>由于答案可能很大，请你将它对 10^9 + 7 取模后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;0110111&quot;
<strong>输出</strong>：9
<strong>解释：</strong>共有 9 个子字符串仅由 &#39;1&#39; 组成
&quot;1&quot; -&gt; 5 次
&quot;11&quot; -&gt; 3 次
&quot;111&quot; -&gt; 1 次</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;101&quot;
<strong>输出：</strong>2
<strong>解释：</strong>子字符串 &quot;1&quot; 在 s 中共出现 2 次
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;111111&quot;
<strong>输出：</strong>21
<strong>解释：</strong>每个子字符串都仅由 &#39;1&#39; 组成
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;000&quot;
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s[i] == &#39;0&#39;</code> 或 <code>s[i] == &#39;1&#39;</code></li>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们遍历字符串 $s$，用变量 $cnt$ 记录当前连续的 1 的个数，用变量 $ans$ 记录答案。当遍历到字符 $s[i]$ 时，如果 $s[i] = 1$，则 $cnt$ 自增 1，否则 $cnt$ 置 0。此时 $ans$ 自增 $cnt$。

遍历结束，返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

相似题目：

-   [413. 等差数列划分](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0413.Arithmetic%20Slices/README.md)
-   [2348. 全 0 子数组的数目](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2348.Number%20of%20Zero-Filled%20Subarrays/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSub(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == "1":
                cnt += 1
            else:
                cnt = 0
            ans += cnt
        return ans % (10**9 + 7)
```

#### Java

```java
class Solution {
    public int numSub(String s) {
        final int mod = (int) 1e9 + 7;
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            cnt = s.charAt(i) == '1' ? cnt + 1 : 0;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSub(string s) {
        int ans = 0, cnt = 0;
        const int mod = 1e9 + 7;
        for (char& c : s) {
            cnt = c == '1' ? cnt + 1 : 0;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numSub(s string) (ans int) {
	const mod = 1e9 + 7
	cnt := 0
	for _, c := range s {
		if c == '1' {
			cnt++
		} else {
			cnt = 0
		}
		ans = (ans + cnt) % mod
	}
	return
}
```

#### TypeScript

```ts
function numSub(s: string): number {
    const mod = 10 ** 9 + 7;
    let ans = 0;
    let cnt = 0;
    for (const c of s) {
        cnt = c == '1' ? cnt + 1 : 0;
        ans = (ans + cnt) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability){#1514}

{{< tabs "1514" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProbability(
        self,
        n: int,
        edges: List[List[int]],
        succProb: List[float],
        start_node: int,
        end_node: int,
    ) -> float:
        g: List[List[Tuple[int, float]]] = [[] for _ in range(n)]
        for (a, b), p in zip(edges, succProb):
            g[a].append((b, p))
            g[b].append((a, p))
        pq = [(-1, start_node)]
        dist = [0] * n
        dist[start_node] = 1
        while pq:
            w, a = heappop(pq)
            w = -w
            if dist[a] > w:
                continue
            for b, p in g[a]:
                if (t := w * p) > dist[b]:
                    dist[b] = t
                    heappush(pq, (-t, b))
        return dist[end_node]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double maxProbability(
        int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        List<Pair<Integer, Double>>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < edges.length; ++i) {
            var e = edges[i];
            int a = e[0], b = e[1];
            double p = succProb[i];
            g[a].add(new Pair<>(b, p));
            g[b].add(new Pair<>(a, p));
        }
        double[] dist = new double[n];
        dist[start_node] = 1;
        PriorityQueue<Pair<Integer, Double>> pq
            = new PriorityQueue<>(Comparator.comparingDouble(p -> - p.getValue()));
        pq.offer(new Pair<>(start_node, 1.0));
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int a = p.getKey();
            double w = p.getValue();
            if (dist[a] > w) {
                continue;
            }
            for (var e : g[a]) {
                int b = e.getKey();
                double pab = e.getValue();
                double wab = w * pab;
                if (wab > dist[b]) {
                    dist[b] = wab;
                    pq.offer(new Pair<>(b, wab));
                }
            }
        }
        return dist[end_node];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using pdi = pair<double, int>;
        vector<pdi> g[n];
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            g[a].emplace_back(p, b);
            g[b].emplace_back(p, a);
        }
        vector<double> dist(n);
        dist[start_node] = 1;
        priority_queue<pdi> pq;
        pq.emplace(1, start_node);
        while (!pq.empty()) {
            auto [w, a] = pq.top();
            pq.pop();
            if (dist[a] > w) {
                continue;
            }
            for (auto [p, b] : g[a]) {
                auto nw = w * p;
                if (nw > dist[b]) {
                    dist[b] = nw;
                    pq.emplace(nw, b);
                }
            }
        }
        return dist[end_node];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProbability(n int, edges [][]int, succProb []float64, start_node int, end_node int) float64 {
	g := make([][]pair, n)
	for i, e := range edges {
		a, b := e[0], e[1]
		p := succProb[i]
		g[a] = append(g[a], pair{p, b})
		g[b] = append(g[b], pair{p, a})
	}
	pq := hp{{1, start_node}}
	dist := make([]float64, n)
	dist[start_node] = 1
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		w, a := p.p, p.a
		if dist[a] > w {
			continue
		}
		for _, e := range g[a] {
			b, p := e.a, e.p
			if nw := w * p; nw > dist[b] {
				dist[b] = nw
				heap.Push(&pq, pair{nw, b})
			}
		}
	}
	return dist[end_node]
}

type pair struct {
	p float64
	a int
}
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].p > h[j].p }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProbability(
    n: number,
    edges: number[][],
    succProb: number[],
    start_node: number,
    end_node: number,
): number {
    const pq = new MaxPriorityQueue({ priority: v => v[0] });
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < edges.length; ++i) {
        const [a, b] = edges[i];
        g[a].push([b, succProb[i]]);
        g[b].push([a, succProb[i]]);
    }
    const dist = Array.from({ length: n }, () => 0);
    dist[start_node] = 1;
    pq.enqueue([1, start_node]);
    while (!pq.isEmpty()) {
        const [w, a] = pq.dequeue().element;
        if (dist[a] > w) {
            continue;
        }
        for (const [b, p] of g[a]) {
            const nw = w * p;
            if (nw > dist[b]) {
                dist[b] = nw;
                pq.enqueue([nw, b]);
            }
        }
    }
    return dist[end_node];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>n</code> 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 <code>edges[i] = [a, b]</code> 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 <code>succProb[i]</code> 。</p>

<p>指定两个节点分别作为起点 <code>start</code> 和终点 <code>end</code> ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。</p>

<p>如果不存在从 <code>start</code> 到 <code>end</code> 的路径，请 <strong>返回 0</strong> 。只要答案与标准答案的误差不超过 <strong>1e-5 </strong>，就会被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1514.Path%20with%20Maximum%20Probability/images/1558_ex1.png" style="height: 186px; width: 187px;"></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
<strong>输出：</strong>0.25000
<strong>解释：</strong>从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5 = 0.25
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1514.Path%20with%20Maximum%20Probability/images/1558_ex2.png" style="height: 186px; width: 189px;"></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
<strong>输出：</strong>0.30000
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1514.Path%20with%20Maximum%20Probability/images/1558_ex3.png" style="height: 191px; width: 215px;"></strong></p>

<pre><strong>输入：</strong>n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
<strong>输出：</strong>0.00000
<strong>解释：</strong>节点 0 和 节点 2 之间不存在路径
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^4</code></li>
	<li><code>0 &lt;= start, end &lt; n</code></li>
	<li><code>start != end</code></li>
	<li><code>0 &lt;= a, b &lt; n</code></li>
	<li><code>a != b</code></li>
	<li><code>0 &lt;= succProb.length == edges.length &lt;= 2*10^4</code></li>
	<li><code>0 &lt;= succProb[i] &lt;= 1</code></li>
	<li>每两个节点之间最多有一条边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：堆优化 Dijkstra 算法

我们可以使用 Dijkstra 算法求解最短路径，这里我们稍微修改一下，求解最大概率路径。

我们可以使用一个优先队列（大根堆） $\textit{pq}$ 来存储从起点到各个节点的概率以及节点编号。初始时我们将起点的概率设为 $1$，其余节点的概率设为 $0$，然后将起点加入到 $\textit{pq}$ 中。

在每一次的迭代中，我们取出 $\textit{pq}$ 中概率最大的节点 $a$，以及 $a$ 的概率 $w$。如果节点 $a$ 的概率已经大于 $w$，那么我们就可以跳过这个节点。否则我们遍历 $a$ 的所有邻接边 $(a, b)$。如果 $b$ 的概率小于 $a$ 的概率乘以 $(a, b)$ 的概率，那么我们就可以更新 $b$ 的概率，并将 $b$ 加入到 $\textit{pq}$ 中。

最终，我们可以得到从起点到终点的最大概率。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 为边的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProbability(
        self,
        n: int,
        edges: List[List[int]],
        succProb: List[float],
        start_node: int,
        end_node: int,
    ) -> float:
        g: List[List[Tuple[int, float]]] = [[] for _ in range(n)]
        for (a, b), p in zip(edges, succProb):
            g[a].append((b, p))
            g[b].append((a, p))
        pq = [(-1, start_node)]
        dist = [0] * n
        dist[start_node] = 1
        while pq:
            w, a = heappop(pq)
            w = -w
            if dist[a] > w:
                continue
            for b, p in g[a]:
                if (t := w * p) > dist[b]:
                    dist[b] = t
                    heappush(pq, (-t, b))
        return dist[end_node]
```

#### Java

```java
class Solution {
    public double maxProbability(
        int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        List<Pair<Integer, Double>>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < edges.length; ++i) {
            var e = edges[i];
            int a = e[0], b = e[1];
            double p = succProb[i];
            g[a].add(new Pair<>(b, p));
            g[b].add(new Pair<>(a, p));
        }
        double[] dist = new double[n];
        dist[start_node] = 1;
        PriorityQueue<Pair<Integer, Double>> pq
            = new PriorityQueue<>(Comparator.comparingDouble(p -> - p.getValue()));
        pq.offer(new Pair<>(start_node, 1.0));
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int a = p.getKey();
            double w = p.getValue();
            if (dist[a] > w) {
                continue;
            }
            for (var e : g[a]) {
                int b = e.getKey();
                double pab = e.getValue();
                double wab = w * pab;
                if (wab > dist[b]) {
                    dist[b] = wab;
                    pq.offer(new Pair<>(b, wab));
                }
            }
        }
        return dist[end_node];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using pdi = pair<double, int>;
        vector<pdi> g[n];
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            g[a].emplace_back(p, b);
            g[b].emplace_back(p, a);
        }
        vector<double> dist(n);
        dist[start_node] = 1;
        priority_queue<pdi> pq;
        pq.emplace(1, start_node);
        while (!pq.empty()) {
            auto [w, a] = pq.top();
            pq.pop();
            if (dist[a] > w) {
                continue;
            }
            for (auto [p, b] : g[a]) {
                auto nw = w * p;
                if (nw > dist[b]) {
                    dist[b] = nw;
                    pq.emplace(nw, b);
                }
            }
        }
        return dist[end_node];
    }
};
```

#### Go

```go
func maxProbability(n int, edges [][]int, succProb []float64, start_node int, end_node int) float64 {
	g := make([][]pair, n)
	for i, e := range edges {
		a, b := e[0], e[1]
		p := succProb[i]
		g[a] = append(g[a], pair{p, b})
		g[b] = append(g[b], pair{p, a})
	}
	pq := hp{{1, start_node}}
	dist := make([]float64, n)
	dist[start_node] = 1
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		w, a := p.p, p.a
		if dist[a] > w {
			continue
		}
		for _, e := range g[a] {
			b, p := e.a, e.p
			if nw := w * p; nw > dist[b] {
				dist[b] = nw
				heap.Push(&pq, pair{nw, b})
			}
		}
	}
	return dist[end_node]
}

type pair struct {
	p float64
	a int
}
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].p > h[j].p }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return }
```

#### TypeScript

```ts
function maxProbability(
    n: number,
    edges: number[][],
    succProb: number[],
    start_node: number,
    end_node: number,
): number {
    const pq = new MaxPriorityQueue({ priority: v => v[0] });
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < edges.length; ++i) {
        const [a, b] = edges[i];
        g[a].push([b, succProb[i]]);
        g[b].push([a, succProb[i]]);
    }
    const dist = Array.from({ length: n }, () => 0);
    dist[start_node] = 1;
    pq.enqueue([1, start_node]);
    while (!pq.isEmpty()) {
        const [w, a] = pq.dequeue().element;
        if (dist[a] > w) {
            continue;
        }
        for (const [b, p] of g[a]) {
            const nw = w * p;
            if (nw > dist[b]) {
                dist[b] = nw;
                pq.enqueue([nw, b]);
            }
        }
    }
    return dist[end_node];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1515. 服务中心的最佳位置](https://leetcode.cn/problems/best-position-for-a-service-centre){#1515}

{{< tabs "1515" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        n = len(positions)
        x = y = 0
        for x1, y1 in positions:
            x += x1
            y += y1
        x, y = x / n, y / n
        decay = 0.999
        eps = 1e-6
        alpha = 0.5
        while 1:
            grad_x = grad_y = 0
            dist = 0
            for x1, y1 in positions:
                a = x - x1
                b = y - y1
                c = sqrt(a * a + b * b)
                grad_x += a / (c + 1e-8)
                grad_y += b / (c + 1e-8)
                dist += c
            dx = grad_x * alpha
            dy = grad_y * alpha
            x -= dx
            y -= dy
            alpha *= decay
            if abs(dx) <= eps and abs(dy) <= eps:
                return dist
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double getMinDistSum(int[][] positions) {
        int n = positions.length;
        double x = 0, y = 0;
        for (int[] p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        double decay = 0.999;
        double eps = 1e-6;
        double alpha = 0.5;
        while (true) {
            double gradX = 0, gradY = 0;
            double dist = 0;
            for (int[] p : positions) {
                double a = x - p[0], b = y - p[1];
                double c = Math.sqrt(a * a + b * b);
                gradX += a / (c + 1e-8);
                gradY += b / (c + 1e-8);
                dist += c;
            }
            double dx = gradX * alpha, dy = gradY * alpha;
            if (Math.abs(dx) <= eps && Math.abs(dy) <= eps) {
                return dist;
            }
            x -= dx;
            y -= dy;
            alpha *= decay;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int n = positions.size();
        double x = 0, y = 0;
        for (auto& p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        double decay = 0.999;
        double eps = 1e-6;
        double alpha = 0.5;
        while (true) {
            double gradX = 0, gradY = 0;
            double dist = 0;
            for (auto& p : positions) {
                double a = x - p[0], b = y - p[1];
                double c = sqrt(a * a + b * b);
                gradX += a / (c + 1e-8);
                gradY += b / (c + 1e-8);
                dist += c;
            }
            double dx = gradX * alpha, dy = gradY * alpha;
            if (abs(dx) <= eps && abs(dy) <= eps) {
                return dist;
            }
            x -= dx;
            y -= dy;
            alpha *= decay;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMinDistSum(positions [][]int) float64 {
	n := len(positions)
	var x, y float64
	for _, p := range positions {
		x += float64(p[0])
		y += float64(p[1])
	}
	x /= float64(n)
	y /= float64(n)
	const decay float64 = 0.999
	const eps float64 = 1e-6
	var alpha float64 = 0.5
	for {
		var gradX, gradY float64
		var dist float64
		for _, p := range positions {
			a := x - float64(p[0])
			b := y - float64(p[1])
			c := math.Sqrt(a*a + b*b)
			gradX += a / (c + 1e-8)
			gradY += b / (c + 1e-8)
			dist += c
		}
		dx := gradX * alpha
		dy := gradY * alpha
		if math.Abs(dx) <= eps && math.Abs(dy) <= eps {
			return dist
		}
		x -= dx
		y -= dy
		alpha *= decay
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMinDistSum(positions: number[][]): number {
    const n = positions.length;
    let [x, y] = [0, 0];
    for (const [px, py] of positions) {
        x += px;
        y += py;
    }
    x /= n;
    y /= n;
    const decay = 0.999;
    const eps = 1e-6;
    let alpha = 0.5;
    while (true) {
        let [gradX, gradY] = [0, 0];
        let dist = 0;
        for (const [px, py] of positions) {
            const a = x - px;
            const b = y - py;
            const c = Math.sqrt(a * a + b * b);
            gradX += a / (c + 1e-8);
            gradY += b / (c + 1e-8);
            dist += c;
        }
        const dx = gradX * alpha;
        const dy = gradY * alpha;
        if (Math.abs(dx) <= eps && Math.abs(dy) <= eps) {
            return dist;
        }
        x -= dx;
        y -= dy;
        alpha *= decay;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一家快递公司希望在新城市建立新的服务中心。公司统计了该城市所有客户在二维地图上的坐标，并希望能够以此为依据为新的服务中心选址：使服务中心 <strong>到所有客户的欧几里得距离的总和最小</strong> 。</p>

<p>给你一个数组 <code>positions</code> ，其中 <code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示第 <code>i</code> 个客户在二维地图上的位置，返回到所有客户的 <strong>欧几里得距离的最小总和 。</strong></p>

<p>换句话说，请你为服务中心选址，该位置的坐标 <code>[x<sub>centre</sub>, y<sub>centre</sub>]</code> 需要使下面的公式取到最小值：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1515.Best%20Position%20for%20a%20Service%20Centre/images/q4_edited.jpg" /></p>

<p>与真实值误差在 <code>10<sup>-5</sup></code>之内的答案将被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1515.Best%20Position%20for%20a%20Service%20Centre/images/q4_e1.jpg" /></p>

<pre>
<strong>输入：</strong>positions = [[0,1],[1,0],[1,2],[2,1]]
<strong>输出：</strong>4.00000
<strong>解释：</strong>如图所示，你可以选 [x<sub>centre</sub>, y<sub>centre</sub>] = [1, 1] 作为新中心的位置，这样一来到每个客户的距离就都是 1，所有距离之和为 4 ，这也是可以找到的最小值。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1515.Best%20Position%20for%20a%20Service%20Centre/images/q4_e3.jpg" /></p>

<pre>
<strong>输入：</strong>positions = [[1,1],[3,3]]
<strong>输出：</strong>2.82843
<strong>解释：</strong>欧几里得距离可能的最小总和为 sqrt(2) + sqrt(2) = 2.82843
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= positions.length &lt;= 50</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：梯度下降法

我们可以先设定一个初始的服务中心位置为所有客户坐标的几何中心 $(x, y)$。接下来，使用梯度下降法不断迭代，设定一个学习率 $\alpha=0.5$，衰减率 $decay=0.999$。每次一次迭代，计算当前位置到所有客户的距离之和，然后计算当前位置的梯度，最后更新当前位置。当梯度的绝对值都小于 $10^{-6}$ 时，停止迭代，返回当前位置到所有客户的距离之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        n = len(positions)
        x = y = 0
        for x1, y1 in positions:
            x += x1
            y += y1
        x, y = x / n, y / n
        decay = 0.999
        eps = 1e-6
        alpha = 0.5
        while 1:
            grad_x = grad_y = 0
            dist = 0
            for x1, y1 in positions:
                a = x - x1
                b = y - y1
                c = sqrt(a * a + b * b)
                grad_x += a / (c + 1e-8)
                grad_y += b / (c + 1e-8)
                dist += c
            dx = grad_x * alpha
            dy = grad_y * alpha
            x -= dx
            y -= dy
            alpha *= decay
            if abs(dx) <= eps and abs(dy) <= eps:
                return dist
```

#### Java

```java
class Solution {
    public double getMinDistSum(int[][] positions) {
        int n = positions.length;
        double x = 0, y = 0;
        for (int[] p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        double decay = 0.999;
        double eps = 1e-6;
        double alpha = 0.5;
        while (true) {
            double gradX = 0, gradY = 0;
            double dist = 0;
            for (int[] p : positions) {
                double a = x - p[0], b = y - p[1];
                double c = Math.sqrt(a * a + b * b);
                gradX += a / (c + 1e-8);
                gradY += b / (c + 1e-8);
                dist += c;
            }
            double dx = gradX * alpha, dy = gradY * alpha;
            if (Math.abs(dx) <= eps && Math.abs(dy) <= eps) {
                return dist;
            }
            x -= dx;
            y -= dy;
            alpha *= decay;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int n = positions.size();
        double x = 0, y = 0;
        for (auto& p : positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        double decay = 0.999;
        double eps = 1e-6;
        double alpha = 0.5;
        while (true) {
            double gradX = 0, gradY = 0;
            double dist = 0;
            for (auto& p : positions) {
                double a = x - p[0], b = y - p[1];
                double c = sqrt(a * a + b * b);
                gradX += a / (c + 1e-8);
                gradY += b / (c + 1e-8);
                dist += c;
            }
            double dx = gradX * alpha, dy = gradY * alpha;
            if (abs(dx) <= eps && abs(dy) <= eps) {
                return dist;
            }
            x -= dx;
            y -= dy;
            alpha *= decay;
        }
    }
};
```

#### Go

```go
func getMinDistSum(positions [][]int) float64 {
	n := len(positions)
	var x, y float64
	for _, p := range positions {
		x += float64(p[0])
		y += float64(p[1])
	}
	x /= float64(n)
	y /= float64(n)
	const decay float64 = 0.999
	const eps float64 = 1e-6
	var alpha float64 = 0.5
	for {
		var gradX, gradY float64
		var dist float64
		for _, p := range positions {
			a := x - float64(p[0])
			b := y - float64(p[1])
			c := math.Sqrt(a*a + b*b)
			gradX += a / (c + 1e-8)
			gradY += b / (c + 1e-8)
			dist += c
		}
		dx := gradX * alpha
		dy := gradY * alpha
		if math.Abs(dx) <= eps && math.Abs(dy) <= eps {
			return dist
		}
		x -= dx
		y -= dy
		alpha *= decay
	}
}
```

#### TypeScript

```ts
function getMinDistSum(positions: number[][]): number {
    const n = positions.length;
    let [x, y] = [0, 0];
    for (const [px, py] of positions) {
        x += px;
        y += py;
    }
    x /= n;
    y /= n;
    const decay = 0.999;
    const eps = 1e-6;
    let alpha = 0.5;
    while (true) {
        let [gradX, gradY] = [0, 0];
        let dist = 0;
        for (const [px, py] of positions) {
            const a = x - px;
            const b = y - py;
            const c = Math.sqrt(a * a + b * b);
            gradX += a / (c + 1e-8);
            gradY += b / (c + 1e-8);
            dist += c;
        }
        const dx = gradX * alpha;
        const dy = gradY * alpha;
        if (Math.abs(dx) <= eps && Math.abs(dy) <= eps) {
            return dist;
        }
        x -= dx;
        y -= dy;
        alpha *= decay;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1516. 移动 N 叉树的子树 🔒](https://leetcode.cn/problems/move-sub-tree-of-n-ary-tree){#1516}

{{< tabs "1516" >}}

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

<p>给定一棵没有重复值的 <span data-keyword="n-ary-tree">N 叉树</span> 的根节点&nbsp;<code>root</code>&nbsp;，以及其中的两个节点&nbsp;<code>p</code> 和&nbsp;<code>q</code>。</p>

<p>移动节点&nbsp;<code>p</code>&nbsp;及其子树，使节点 <code>p</code>&nbsp;成为节点&nbsp;<code>q</code>&nbsp;的直接子节点。如果&nbsp;<code>p</code>&nbsp;已经是&nbsp;<code>q</code>&nbsp;的直接子节点，则请勿改动任何节点。节点&nbsp;<code>p</code> <strong>必须</strong>是节点&nbsp;<code>q</code>&nbsp;的子节点列表的最后一项。</p>

<p>返回改动后的<em>树的根节点</em>。</p>

<p>&nbsp;</p>

<p>节点&nbsp;<code>p</code>&nbsp;和&nbsp;<code>q</code>&nbsp;可能是下列三种情况之一：</p>

<ol>
	<li>节点&nbsp;<code>q</code>&nbsp;在节点&nbsp;<code>p</code>&nbsp;的子树中。</li>
	<li>节点&nbsp;<code>p</code>&nbsp;在节点&nbsp;<code>q</code>&nbsp;的子树中。</li>
	<li>节点&nbsp;<code>p</code>&nbsp;不在节点&nbsp;<code>q</code>&nbsp;的子树中，且节点&nbsp;<code>q</code> 也不在节点&nbsp;<code>p</code>&nbsp;的子树中。</li>
</ol>

<p>在第 2 种和第 3 种情况中，你只需要移动&nbsp;<code>p</code>&nbsp;（及其子树），使 <code>p</code>&nbsp;成为&nbsp;<code>q</code>&nbsp;的子节点。但是在第 1 种情况中，树的节点可能会断连，因此你还需要重新连接这些节点。<strong>请在解题前仔细阅读示例。</strong></p>

<p>&nbsp;</p>

<p><em>N 叉树的输入序列以层序遍历的形式给出，每组子节点用 null 分隔（见示例）。</em></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1516.Move%20Sub-Tree%20of%20N-Ary%20Tree/images/sample_4_964.png" style="height: 269px; width: 296px;" /></p>

<p>例如，上面的树会被序列化为&nbsp;[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1516.Move%20Sub-Tree%20of%20N-Ary%20Tree/images/move_e1.jpg" style="height: 188px; width: 450px;" /></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 4, q = 1
<strong>输出:</strong> [1,null,2,3,4,null,5,null,6,null,7,8]
<strong>解释:</strong> 该示例属于第二种情况，节点 p 在节点 q 的子树中。我们可以移动节点 p 及其子树，使 p 成为节点 q 的直接子节点。
注意，节点 4 是节点 1 的最后一个子节点。</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1516.Move%20Sub-Tree%20of%20N-Ary%20Tree/images/move_e2.jpg" style="height: 281px; width: 281px;" /></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 7, q = 4
<strong>输出:</strong> [1,null,2,3,null,4,5,null,6,null,7,8]
<strong>解释:</strong> 节点 7 已经是节点 4 的直接子节点，因此我们不改动任何节点。
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1516.Move%20Sub-Tree%20of%20N-Ary%20Tree/images/move_e3.jpg" style="height: 331px; width: 450px;" /></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 3, q = 8
<strong>输出:</strong> [1,null,2,null,4,5,null,7,8,null,null,null,3,null,6]
<strong>解释:</strong> 该示例属于第三种情况，节点 p 不在节点 q 的子树中，反之亦然。我们可以移动节点 3 及其子树，使之成为节点 8 的子节点。
</pre>

<p><strong class="example">示例 4：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1516.Move%20Sub-Tree%20of%20N-Ary%20Tree/images/untitled-diagramdrawio.png" style="width: 500px; height: 175px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3,null,4], p = 1, q = 4
<b>输出：</b>[4,null,1,null,2,3]
<strong>解释：</strong>该示例属于第一种情况，因为节点 q 在节点 p 的子树中。断开节点 4 与其父节点，并将节点 1 及其子树移动，使其成为节点 4 的子节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点的总数在&nbsp;<code>[2,&nbsp;1000]</code>&nbsp;间。</li>
	<li>每个节点都有&nbsp;<strong>唯一&nbsp;</strong>的值。</li>
	<li><code>p != null</code></li>
	<li><code>q != null</code></li>
	<li><code>p</code>&nbsp;和&nbsp;<code>q</code>&nbsp;是两个不同的节点（即&nbsp;<code>p != q</code>&nbsp;）。</li>
</ul>

<p>&nbsp;</p>

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

# [1517. 查找拥有有效邮箱的用户](https://leetcode.cn/problems/find-users-with-valid-e-mails){#1517}

{{< tabs "1517" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' AND BINARY mail LIKE '%@leetcode.com';
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    pattern = r"^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$"
    mask = users["mail"].str.match(pattern, flags=0, na=False)
    return users.loc[mask, ["user_id", "name", "mail"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Users</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
| mail          | varchar |
+---------------+---------+
user_id 是该表的主键（具有唯一值的列）。
该表包含了网站已注册用户的信息。有一些电子邮件是无效的。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，以查找具有有效电子邮件的用户。</p>

<p>一个有效的电子邮件具有前缀名称和域，其中：</p>

<ol>
	<li>&nbsp;<strong>前缀</strong> 名称是一个字符串，可以包含字母（大写或小写），数字，下划线 <code>'_'</code> ，点 <code>'.'</code> 和（或）破折号 <code>'-'</code> 。前缀名称 <strong>必须</strong> 以字母开头。</li>
	<li><strong>域</strong> 为 <code>'@leetcode.com'</code> 。</li>
</ol>

<p>以任何顺序返回结果表。</p>

<p>结果的格式如以下示例所示：</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Users 表:
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 2       | Jonathan  | jonathanisgreat         |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 6       | David     | david69@gmail.com       |
| 7       | Shapiro   | .shapo@leetcode.com     |
+---------+-----------+-------------------------+
<b>输出：</b>
+---------+-----------+-------------------------+
| user_id | name      | mail                    |
+---------+-----------+-------------------------+
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
+---------+-----------+-------------------------+
<b>解释：</b>
用户 2 的电子邮件没有域。 
用户 5 的电子邮件带有不允许的 '#' 符号。
用户 6 的电子邮件没有 leetcode 域。 
用户 7 的电子邮件以点开头。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：REGEXP 正则匹配

我们可以使用正则表达式来匹配有效的电子邮件格式。正则表达式可以确保前缀名称符合要求，并且域名是固定的 `@leetcode.com`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' AND BINARY mail LIKE '%@leetcode.com';
```

#### Pandas

```python
import pandas as pd


def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    pattern = r"^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$"
    mask = users["mail"].str.match(pattern, flags=0, na=False)
    return users.loc[mask, ["user_id", "name", "mail"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1518. 换水问题](https://leetcode.cn/problems/water-bottles){#1518}

{{< tabs "1518" >}}

{{% tab "python" %}}
```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange - 1
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        for (; numBottles >= numExchange; ++ans) {
            numBottles -= (numExchange - 1);
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
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        for (; numBottles >= numExchange; ++ans) {
            numBottles -= (numExchange - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numWaterBottles(numBottles int, numExchange int) int {
	ans := numBottles
	for ; numBottles >= numExchange; ans++ {
		numBottles -= (numExchange - 1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numWaterBottles(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    for (; numBottles >= numExchange; ++ans) {
        numBottles -= numExchange - 1;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function (numBottles, numExchange) {
    let ans = numBottles;
    for (; numBottles >= numExchange; ++ans) {
        numBottles -= numExchange - 1;
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $numBottles
     * @param Integer $numExchange
     * @return Integer
     */
    function numWaterBottles($numBottles, $numExchange) {
        $ans = $numBottles;
        while ($numBottles >= $numExchange) {
            $numBottles = $numBottles - $numExchange + 1;
            $ans++;
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

<p>超市正在促销，你可以用 <code>numExchange</code> 个空水瓶从超市兑换一瓶水。最开始，你一共购入了 <code>numBottles</code> 瓶水。</p>

<p>如果喝掉了水瓶中的水，那么水瓶就会变成空的。</p>

<p>给你两个整数 <code>numBottles</code> 和 <code>numExchange</code> ，返回你 <strong>最多</strong> 可以喝到多少瓶水。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1518.Water%20Bottles/images/sample_1_1875.png" style="height: 240px; width: 480px;" /></strong></p>

<pre>
<strong>输入：</strong>numBottles = 9, numExchange = 3
<strong>输出：</strong>13
<strong>解释：</strong>你可以用 <code>3</code> 个空瓶兑换 1 瓶水。
所以最多能喝到 9 + 3 + 1 = 13 瓶水。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1518.Water%20Bottles/images/sample_2_1875.png" style="height: 240px; width: 790px;" /></p>

<pre>
<strong>输入：</strong>numBottles = 15, numExchange = 4
<strong>输出：</strong>19
<strong>解释：</strong>你可以用 <code>4</code> 个空瓶兑换 1 瓶水。
所以最多能喝到 15 + 3 + 1 = 19 瓶水。
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= numBottles &lt;= 100</code></li>
	<li><code>2 &lt;= numExchange &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟整个过程。

初始时，我们有 `numBottles` 瓶水，因此可以喝到 `ans = numBottles` 瓶水，然后得到 `numBottles` 个空瓶子。

接下来，如果我们有 `numExchange` 个空瓶子，那么我们可以用它们兑换一瓶水并喝掉，此时我们剩余的空瓶子数量为 `numBottles - numExchange + 1`，然后我们累加喝到的水的数量，即 $ans = ans + 1$。

最后，返回 `ans` 即可。

时间复杂度 $(\frac{numBottles}{numExchange})$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange - 1
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        for (; numBottles >= numExchange; ++ans) {
            numBottles -= (numExchange - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        for (; numBottles >= numExchange; ++ans) {
            numBottles -= (numExchange - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func numWaterBottles(numBottles int, numExchange int) int {
	ans := numBottles
	for ; numBottles >= numExchange; ans++ {
		numBottles -= (numExchange - 1)
	}
	return ans
}
```

#### TypeScript

```ts
function numWaterBottles(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    for (; numBottles >= numExchange; ++ans) {
        numBottles -= numExchange - 1;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function (numBottles, numExchange) {
    let ans = numBottles;
    for (; numBottles >= numExchange; ++ans) {
        numBottles -= numExchange - 1;
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $numBottles
     * @param Integer $numExchange
     * @return Integer
     */
    function numWaterBottles($numBottles, $numExchange) {
        $ans = $numBottles;
        while ($numBottles >= $numExchange) {
            $numBottles = $numBottles - $numExchange + 1;
            $ans++;
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

# [1519. 子树中标签相同的节点数](https://leetcode.cn/problems/number-of-nodes-in-the-sub-tree-with-the-same-label){#1519}

{{< tabs "1519" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        def dfs(i, fa):
            ans[i] -= cnt[labels[i]]
            cnt[labels[i]] += 1
            for j in g[i]:
                if j != fa:
                    dfs(j, i)
            ans[i] += cnt[labels[i]]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        cnt = Counter()
        ans = [0] * n
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private String labels;
    private int[] ans;
    private int[] cnt;

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.labels = labels;
        ans = new int[n];
        cnt = new int[26];
        dfs(0, -1);
        return ans;
    }

    private void dfs(int i, int fa) {
        int k = labels.charAt(i) - 'a';
        ans[i] -= cnt[k];
        cnt[k]++;
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i);
            }
        }
        ans[i] += cnt[k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n);
        int cnt[26]{};
        function<void(int, int)> dfs = [&](int i, int fa) {
            int k = labels[i] - 'a';
            ans[i] -= cnt[k];
            cnt[k]++;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs(j, i);
                }
            }
            ans[i] += cnt[k];
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubTrees(n int, edges [][]int, labels string) []int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	cnt := [26]int{}
	var dfs func(int, int)
	dfs = func(i, fa int) {
		k := labels[i] - 'a'
		ans[i] -= cnt[k]
		cnt[k]++
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i)
			}
		}
		ans[i] += cnt[k]
	}
	dfs(0, -1)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubTrees(n: number, edges: number[][], labels: string): number[] {
    const dfs = (i: number, fa: number) => {
        const k = labels.charCodeAt(i) - 97;
        ans[i] -= cnt[k];
        cnt[k]++;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i);
            }
        }
        ans[i] += cnt[k];
    };
    const ans = new Array(n).fill(0),
        cnt = new Array(26).fill(0);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵树（即，一个连通的无环无向图），这棵树由编号从 <code>0</code>&nbsp; 到 <code>n - 1</code> 的 n 个节点组成，且恰好有 <code>n - 1</code> 条 <code>edges</code> 。树的根节点为节点 <code>0</code> ，树上的每一个节点都有一个标签，也就是字符串 <code>labels</code> 中的一个小写字符（编号为 <code>i</code> 的 节点的标签就是 <code>labels[i]</code> ）</p>

<p>边数组 <code>edges</code> 以 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 的形式给出，该格式表示节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。</p>

<p>返回一个大小为 <em><code>n</code></em> 的数组，其中 <code>ans[i]</code> 表示第 <code>i</code> 个节点的子树中与节点 <code>i</code> 标签相同的节点数。</p>

<p>树 <code>T</code> 中的子树是由 <code>T</code> 中的某个节点及其所有后代节点组成的树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1519.Number%20of%20Nodes%20in%20the%20Sub-Tree%20With%20the%20Same%20Label/images/q3e1.jpg" style="height: 321px; width: 441px;" /></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
<strong>输出：</strong>[2,1,1,1,1,1,1]
<strong>解释：</strong>节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1519.Number%20of%20Nodes%20in%20the%20Sub-Tree%20With%20the%20Same%20Label/images/q3e2.jpg" style="height: 321px; width: 381px;" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
<strong>输出：</strong>[4,2,1,1]
<strong>解释：</strong>节点 2 的子树中只有节点 2 ，所以答案为 1 。
节点 3 的子树中只有节点 3 ，所以答案为 1 。
节点 1 的子树中包含节点 1 和 2 ，标签都是 'b' ，因此答案为 2 。
节点 0 的子树中包含节点 0、1、2 和 3，标签都是 'b'，因此答案为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1519.Number%20of%20Nodes%20in%20the%20Sub-Tree%20With%20the%20Same%20Label/images/q3e3.jpg" style="height: 321px; width: 381px;" /></p>

<pre>
<strong>输入：</strong>n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
<strong>输出：</strong>[3,2,1,1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>,&nbsp;b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> !=&nbsp;b<sub>i</sub></code></li>
	<li><code>labels.length == n</code></li>
	<li><code>labels</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先将边数组转换为邻接表 $g$。

接下来我们从根节点 $0$ 开始遍历其子树，过程中维护一个计数器 $cnt$，用于统计当前各个字母出现的次数。

在访问某个节点 $i$ 时，我们先将 $ans[i]$ 减去 $cnt[labels[i]]$，然后将 $cnt[labels[i]]$ 加 $1$，表示当前节点 $i$ 的标签出现了一次。接下来递归访问其子节点，最后将 $ans[i]$ 加上 $cnt[labels[i]]$。也即是说，我们将每个点离开时的计数器值减去每个点进来时的计数器值，就得到了以该点为根的子树中各个字母出现的次数。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为节点数；而 $C$ 为字符集大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        def dfs(i, fa):
            ans[i] -= cnt[labels[i]]
            cnt[labels[i]] += 1
            for j in g[i]:
                if j != fa:
                    dfs(j, i)
            ans[i] += cnt[labels[i]]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        cnt = Counter()
        ans = [0] * n
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private String labels;
    private int[] ans;
    private int[] cnt;

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.labels = labels;
        ans = new int[n];
        cnt = new int[26];
        dfs(0, -1);
        return ans;
    }

    private void dfs(int i, int fa) {
        int k = labels.charAt(i) - 'a';
        ans[i] -= cnt[k];
        cnt[k]++;
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i);
            }
        }
        ans[i] += cnt[k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n);
        int cnt[26]{};
        function<void(int, int)> dfs = [&](int i, int fa) {
            int k = labels[i] - 'a';
            ans[i] -= cnt[k];
            cnt[k]++;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs(j, i);
                }
            }
            ans[i] += cnt[k];
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func countSubTrees(n int, edges [][]int, labels string) []int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	cnt := [26]int{}
	var dfs func(int, int)
	dfs = func(i, fa int) {
		k := labels[i] - 'a'
		ans[i] -= cnt[k]
		cnt[k]++
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i)
			}
		}
		ans[i] += cnt[k]
	}
	dfs(0, -1)
	return ans
}
```

#### TypeScript

```ts
function countSubTrees(n: number, edges: number[][], labels: string): number[] {
    const dfs = (i: number, fa: number) => {
        const k = labels.charCodeAt(i) - 97;
        ans[i] -= cnt[k];
        cnt[k]++;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i);
            }
        }
        ans[i] += cnt[k];
    };
    const ans = new Array(n).fill(0),
        cnt = new Array(26).fill(0);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    dfs(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

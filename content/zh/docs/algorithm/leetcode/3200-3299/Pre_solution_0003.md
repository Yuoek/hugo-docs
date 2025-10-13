---
title: "3220_奇数和偶数交易"
date: 2025-10-08T18:40:15+08:00
weight: 3
tags: [位运算, 前缀和, 动态规划, 单调栈, 博弈, 哈希表, 字符串, 数学, 数据库, 数组, 栈, 模拟, 矩阵, 脑筋急转弯, 计数, 贪心]
---

{{< markmap >}}
### [3220_奇数和偶数交易](#3220)
#### [数据库](#3220)
### [3221_最大数组跳跃得分 II 🔒](#3221)
#### [栈](#3221)
#### [贪心](#3221)
#### [数组](#3221)
#### [单调栈](#3221)
### [3222_求出硬币游戏的赢家](#3222)
#### [数学](#3222)
#### [博弈](#3222)
#### [模拟](#3222)
### [3223_操作后字符串的最短长度](#3223)
#### [哈希表](#3223)
#### [字符串](#3223)
#### [计数](#3223)
### [3224_使差值相等的最少数组改动次数](#3224)
#### [数组](#3224)
#### [哈希表](#3224)
#### [前缀和](#3224)
### [3225_网格图操作后的最大分数](#3225)
#### [数组](#3225)
#### [动态规划](#3225)
#### [矩阵](#3225)
#### [前缀和](#3225)
### [3226_使两个整数相等的位更改次数](#3226)
#### [位运算](#3226)
### [3227_字符串元音游戏](#3227)
#### [脑筋急转弯](#3227)
#### [数学](#3227)
#### [字符串](#3227)
#### [博弈](#3227)
### [3228_将 1 移动到末尾的最大操作次数](#3228)
#### [贪心](#3228)
#### [字符串](#3228)
#### [计数](#3228)
### [3229_使数组等于目标数组所需的最少操作次数](#3229)
#### [栈](#3229)
#### [贪心](#3229)
#### [数组](#3229)
#### [动态规划](#3229)
#### [单调栈](#3229)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3220_奇数和偶数交易
___
#### 数据库
---
### 3221_最大数组跳跃得分 II 🔒
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 单调栈
---
### 3222_求出硬币游戏的赢家
___
#### 数学
___
#### 博弈
___
#### 模拟
---
### 3223_操作后字符串的最短长度
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 3224_使差值相等的最少数组改动次数
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 3225_网格图操作后的最大分数
___
#### 数组
___
#### 动态规划
___
#### 矩阵
___
#### 前缀和
---
### 3226_使两个整数相等的位更改次数
___
#### 位运算
---
### 3227_字符串元音游戏
___
#### 脑筋急转弯
___
#### 数学
___
#### 字符串
___
#### 博弈
---
### 3228_将 1 移动到末尾的最大操作次数
___
#### 贪心
___
#### 字符串
___
#### 计数
---
### 3229_使数组等于目标数组所需的最少操作次数
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 单调栈
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 单调栈 | 博弈 | 哈希表 |
| 字符串 | 数学 | 数据库 |
| 数组 | 栈 | 模拟 |
| 矩阵 | 脑筋急转弯 | 计数 |
| 贪心 |  |  |

# [3220. 奇数和偶数交易](https://leetcode.cn/problems/odd-and-even-transactions){#3220}

{{< tabs "3220" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    transaction_date,
    SUM(IF(amount % 2 = 1, amount, 0)) AS odd_sum,
    SUM(IF(amount % 2 = 0, amount, 0)) AS even_sum
FROM transactions
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def sum_daily_odd_even(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions["odd_sum"] = transactions["amount"].where(
        transactions["amount"] % 2 == 1, 0
    )
    transactions["even_sum"] = transactions["amount"].where(
        transactions["amount"] % 2 == 0, 0
    )

    result = (
        transactions.groupby("transaction_date")
        .agg(odd_sum=("odd_sum", "sum"), even_sum=("even_sum", "sum"))
        .reset_index()
    )

    result = result.sort_values("transaction_date")

    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>transactions</code></p>

<pre>
+------------------+------+
| Column Name      | Type | 
+------------------+------+
| transaction_id   | int  |
| amount           | int  |
| transaction_date | date |
+------------------+------+
transactions_id 列唯一标识了表中的每一行。
这张表的每一行包含交易 id，金额总和和交易日期。
</pre>

<p>编写一个解决方案来查找每天 <strong>奇数</strong> 交易金额和 <strong>偶数</strong> 交易金额的 <strong>总和</strong>。如果某天没有奇数或偶数交易，显示为&nbsp;<code>0</code>。</p>

<p>返回结果表以&nbsp;<code>transaction_date</code> <strong>升序</strong>&nbsp;排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><b>输入：</b></p>

<p><code>transactions</code> 表：</p>

<pre class="example-io">
+----------------+--------+------------------+
| transaction_id | amount | transaction_date |
+----------------+--------+------------------+
| 1              | 150    | 2024-07-01       |
| 2              | 200    | 2024-07-01       |
| 3              | 75     | 2024-07-01       |
| 4              | 300    | 2024-07-02       |
| 5              | 50     | 2024-07-02       |
| 6              | 120    | 2024-07-03       |
+----------------+--------+------------------+
  </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+------------------+---------+----------+
| transaction_date | odd_sum | even_sum |
+------------------+---------+----------+
| 2024-07-01       | 75      | 350      |
| 2024-07-02       | 0       | 350      |
| 2024-07-03       | 0       | 120      |
+------------------+---------+----------+
  </pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于交易日期：
	<ul>
		<li>2024-07-01:
		<ul>
			<li>奇数交易金额总和：75</li>
			<li>偶数交易金额总和：150 + 200 = 350</li>
		</ul>
		</li>
		<li>2024-07-02:
		<ul>
			<li>奇数交易金额总和：0</li>
			<li>偶数交易金额总和：300 + 50 = 350</li>
		</ul>
		</li>
		<li>2024-07-03:
		<ul>
			<li>奇数交易金额总和：0</li>
			<li>偶数交易金额总和：120</li>
		</ul>
		</li>
	</ul>
	</li>
</ul>

<p><b>注意：</b>输出表以&nbsp;<code>transaction_date</code>&nbsp;升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和

我们可以将数据按照 `transaction_date` 进行分组，然后分别计算奇数和偶数的交易金额之和。最后按照 `transaction_date` 升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    transaction_date,
    SUM(IF(amount % 2 = 1, amount, 0)) AS odd_sum,
    SUM(IF(amount % 2 = 0, amount, 0)) AS even_sum
FROM transactions
GROUP BY 1
ORDER BY 1;
```

#### Pandas

```python
import pandas as pd


def sum_daily_odd_even(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions["odd_sum"] = transactions["amount"].where(
        transactions["amount"] % 2 == 1, 0
    )
    transactions["even_sum"] = transactions["amount"].where(
        transactions["amount"] % 2 == 0, 0
    )

    result = (
        transactions.groupby("transaction_date")
        .agg(odd_sum=("odd_sum", "sum"), even_sum=("even_sum", "sum"))
        .reset_index()
    )

    result = result.sort_values("transaction_date")

    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3221. 最大数组跳跃得分 II 🔒](https://leetcode.cn/problems/maximum-array-hopping-score-ii){#3221}

{{< tabs "3221" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            stk.append(i)
        ans = i = 0
        for j in stk:
            ans += nums[j] * (j - i)
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxScore(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            stk.push(i);
        }
        long ans = 0, i = 0;
        while (!stk.isEmpty()) {
            int j = stk.pollLast();
            ans += (j - i) * nums[j];
            i = j;
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
    long long maxScore(vector<int>& nums) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (stk.size() && nums[stk.back()] <= nums[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        long long ans = 0, i = 0;
        for (int j : stk) {
            ans += (j - i) * nums[j];
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums []int) (ans int64) {
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	i := 0
	for _, j := range stk {
		ans += int64((j - i) * nums[j])
		i = j
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(nums: number[]): number {
    const stk: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        while (stk.length && nums[stk.at(-1)!] <= nums[i]) {
            stk.pop();
        }
        stk.push(i);
    }
    let ans = 0;
    let i = 0;
    for (const j of stk) {
        ans += (j - i) * nums[j];
        i = j;
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

<p>给定一个数组&nbsp;<code>nums</code>，你必须从索引 0 开始跳跃，直到到达数组的最后一个元素，使得获取 <strong>最大</strong> 分数。</p>

<p>每一次 <strong>跳跃</strong> 中，你可以从下标&nbsp;<code>i</code>&nbsp;跳到一个&nbsp;<code>j &gt; i</code>&nbsp;的下标，并且可以得到&nbsp;<code>(j - i) * nums[j]</code>&nbsp;的分数。</p>

<p>返回你能够取得的最大分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><b>输入：</b>nums = [1,5,8]</p>

<p><b>输出：</b>16</p>

<p><strong>解释：</strong></p>

<p>有两种可能的方法可以到达最后一个元素：</p>

<ul>
	<li><code>0 -&gt; 1 -&gt; 2</code> 得分为&nbsp;<code>(1 - 0) * 5 + (2 - 1) * 8 = 13</code>。</li>
	<li><code>0 -&gt; 2</code> 得分为&nbsp;<code>(2 - 0) * 8 =&nbsp;16</code>。</li>
</ul>

<p><strong>示例 2：</strong></p>

<p><b>输入：</b>nums = [4,5,2,8,9,1,3]</p>

<p><b>输出：</b>42</p>

<p><strong>解释：</strong></p>

<p>我们可以按&nbsp;<code>0 -&gt; 4 -&gt; 6</code>&nbsp;进行跳跃，得分为&nbsp;<code>(4 - 0) * 9 + (6 - 4) * 3 = 42</code>。</p>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们观察发现，对于当前位置 $i$，我们应该跳到下一个值最大的位置 $j$，这样才能获得最大的分数。

因此，我们遍历数组 $\textit{nums}$，维护一个从栈底到栈顶单调递减的栈 $\textit{stk}$。对于当前遍历到的位置 $i$，如果栈顶元素对应的值小于等于 $\textit{nums}[i]$，我们就不断地弹出栈顶元素，直到栈为空或者栈顶元素对应的值大于 $\textit{nums}[i]$，然后将 $i$ 入栈。

然后，我们初始化答案 $\textit{ans}$ 和当前位置 $i = 0$，遍历栈中的元素，每次取出栈顶元素 $j$，更新答案 $\textit{ans} += \textit{nums}[j] \times (j - i)$，然后更新 $i = j$。

最后返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            stk.append(i)
        ans = i = 0
        for j in stk:
            ans += nums[j] * (j - i)
            i = j
        return ans
```

#### Java

```java
class Solution {
    public long maxScore(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            stk.push(i);
        }
        long ans = 0, i = 0;
        while (!stk.isEmpty()) {
            int j = stk.pollLast();
            ans += (j - i) * nums[j];
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (stk.size() && nums[stk.back()] <= nums[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        long long ans = 0, i = 0;
        for (int j : stk) {
            ans += (j - i) * nums[j];
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(nums []int) (ans int64) {
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	i := 0
	for _, j := range stk {
		ans += int64((j - i) * nums[j])
		i = j
	}
	return
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    const stk: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        while (stk.length && nums[stk.at(-1)!] <= nums[i]) {
            stk.pop();
        }
        stk.push(i);
    }
    let ans = 0;
    let i = 0;
    for (const j of stk) {
        ans += (j - i) * nums[j];
        i = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3222. 求出硬币游戏的赢家](https://leetcode.cn/problems/find-the-winning-player-in-coin-game){#3222}

{{< tabs "3222" >}}

{{% tab "python" %}}
```python
class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        k = min(x // 2, y // 8)
        x -= k * 2
        y -= k * 8
        return "Alice" if x and y >= 4 else "Bob"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String losingPlayer(int x, int y) {
        int k = Math.min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x > 0 && y >= 4 ? "Alice" : "Bob";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string losingPlayer(int x, int y) {
        int k = min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x && y >= 4 ? "Alice" : "Bob";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func losingPlayer(x int, y int) string {
	k := min(x/2, y/8)
	x -= 2 * k
	y -= 8 * k
	if x > 0 && y >= 4 {
		return "Alice"
	}
	return "Bob"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function losingPlayer(x: number, y: number): string {
    const k = Math.min((x / 2) | 0, (y / 8) | 0);
    x -= k * 2;
    y -= k * 8;
    return x && y >= 4 ? 'Alice' : 'Bob';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;，分别表示价值为 75 和 10 的硬币的数目。</p>

<p>Alice 和 Bob 正在玩一个游戏。每一轮中，Alice&nbsp;先进行操作，Bob 后操作。每次操作中，玩家需要拿走价值 <b>总和</b>&nbsp;为 115 的硬币。如果一名玩家无法执行此操作，那么这名玩家 <strong>输掉</strong>&nbsp;游戏。</p>

<p>两名玩家都采取 <strong>最优</strong>&nbsp;策略，请你返回游戏的赢家。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>x = 2, y = 7</span></p>

<p><span class="example-io"><b>输出：</b>"Alice"</span></p>

<p><strong>解释：</strong></p>

<p>游戏一次操作后结束：</p>

<ul>
	<li>Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>x = 4, y = 11</span></p>

<p><span class="example-io"><b>输出：</b>"Bob"</span></p>

<p><strong>解释：</strong></p>

<p>游戏 2 次操作后结束：</p>

<ul>
	<li>Alice 拿走&nbsp;1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
	<li>Bob 拿走&nbsp;1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

由于每一轮的操作，会消耗 $2$ 枚价值为 $75$ 的硬币和 $8$ 枚价值为 $10$ 的硬币，因此，我们可以计算得到操作的轮数 $k = \min(x / 2, y / 8)$，然后更新 $x$ 和 $y$ 的值，此时 $x$ 和 $y$ 就是经过 $k$ 轮操作后剩余的硬币数目。

如果 $x > 0$ 且 $y \geq 4$，那么 Alice 还可以继续操作，此时 Bob 就输了，返回 "Alice"；否则，返回 "Bob"。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        k = min(x // 2, y // 8)
        x -= k * 2
        y -= k * 8
        return "Alice" if x and y >= 4 else "Bob"
```

#### Java

```java
class Solution {
    public String losingPlayer(int x, int y) {
        int k = Math.min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x > 0 && y >= 4 ? "Alice" : "Bob";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string losingPlayer(int x, int y) {
        int k = min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x && y >= 4 ? "Alice" : "Bob";
    }
};
```

#### Go

```go
func losingPlayer(x int, y int) string {
	k := min(x/2, y/8)
	x -= 2 * k
	y -= 8 * k
	if x > 0 && y >= 4 {
		return "Alice"
	}
	return "Bob"
}
```

#### TypeScript

```ts
function losingPlayer(x: number, y: number): string {
    const k = Math.min((x / 2) | 0, (y / 8) | 0);
    x -= k * 2;
    y -= k * 8;
    return x && y >= 4 ? 'Alice' : 'Bob';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3223. 操作后字符串的最短长度](https://leetcode.cn/problems/minimum-length-of-string-after-operations){#3223}

{{< tabs "3223" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumLength(self, s: str) -> int:
        cnt = Counter(s)
        return sum(1 if x & 1 else 2 for x in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumLength(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        int ans = 0;
        for (int x : cnt) {
            if (x > 0) {
                ans += x % 2 == 1 ? 1 : 2;
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
    int minimumLength(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (int x : cnt) {
            if (x) {
                ans += x % 2 ? 1 : 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumLength(s string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, x := range cnt {
		if x > 0 {
			if x&1 == 1 {
				ans += 1
			} else {
				ans += 2
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumLength(s: string): number {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    let ans = 0;
    for (const x of cnt.values()) {
        ans += x & 1 ? 1 : 2;
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>你需要对 <code>s</code>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择一个下标 <code>i</code>&nbsp;，满足 <code>s[i]</code>&nbsp;左边和右边都&nbsp;<strong>至少</strong>&nbsp;有一个字符与它相同。</li>
	<li>删除 <code>i</code>&nbsp;<strong>左边</strong>&nbsp;离它 <strong>最近</strong>&nbsp;的&nbsp;<code>s[i]</code> 字符。</li>
	<li>删除 <code>i</code>&nbsp;<strong>右边</strong>&nbsp;离它 <strong>最近</strong>&nbsp;的&nbsp;<code>s[i]</code> 字符。</li>
</ul>

<p>请你返回执行完所有操作后， <code>s</code>&nbsp;的 <strong>最短</strong>&nbsp;长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abaacbcbb"</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong><br />
我们执行以下操作：</p>

<ul>
	<li>选择下标 2 ，然后删除下标 0 和 3 处的字符，得到&nbsp;<code>s = "bacbcbb"</code>&nbsp;。</li>
	<li>选择下标 3 ，然后删除下标 0 和 5 处的字符，得到&nbsp;<code>s = "acbcb"</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "aa"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong><br />
无法对字符串进行任何操作，所以返回初始字符串的长度。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以统计字符串中每个字符出现的次数，然后遍历计数数组，如果字符出现的次数为奇数，则最后该字符剩余 $1$ 个，如果字符出现的次数为偶数，则最后该字符剩余 $2$ 个。我们可以将所有字符的剩余个数相加，即为最终字符串的长度。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $|\Sigma|$ 为字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        cnt = Counter(s)
        return sum(1 if x & 1 else 2 for x in cnt.values())
```

#### Java

```java
class Solution {
    public int minimumLength(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        int ans = 0;
        for (int x : cnt) {
            if (x > 0) {
                ans += x % 2 == 1 ? 1 : 2;
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
    int minimumLength(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (int x : cnt) {
            if (x) {
                ans += x % 2 ? 1 : 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumLength(s string) (ans int) {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, x := range cnt {
		if x > 0 {
			if x&1 == 1 {
				ans += 1
			} else {
				ans += 2
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumLength(s: string): number {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    let ans = 0;
    for (const x of cnt.values()) {
        ans += x & 1 ? 1 : 2;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3224. 使差值相等的最少数组改动次数](https://leetcode.cn/problems/minimum-array-changes-to-make-differences-equal){#3224}

{{< tabs "3224" >}}

{{% tab "python" %}}
```python
class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        d = [0] * (k + 2)
        n = len(nums)
        for i in range(n // 2):
            x, y = nums[i], nums[-i - 1]
            if x > y:
                x, y = y, x
            d[0] += 1
            d[y - x] -= 1
            d[y - x + 1] += 1
            d[max(y, k - x) + 1] -= 1
            d[max(y, k - x) + 1] += 2
        return min(accumulate(d))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minChanges(int[] nums, int k) {
        int[] d = new int[k + 2];
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            int x = Math.min(nums[i], nums[n - i - 1]);
            int y = Math.max(nums[i], nums[n - i - 1]);
            d[0] += 1;
            d[y - x] -= 1;
            d[y - x + 1] += 1;
            d[Math.max(y, k - x) + 1] -= 1;
            d[Math.max(y, k - x) + 1] += 2;
        }
        int ans = n, s = 0;
        for (int x : d) {
            s += x;
            ans = Math.min(ans, s);
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
    int minChanges(vector<int>& nums, int k) {
        int d[k + 2];
        memset(d, 0, sizeof(d));
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int x = min(nums[i], nums[n - i - 1]);
            int y = max(nums[i], nums[n - i - 1]);
            d[0] += 1;
            d[y - x] -= 1;
            d[y - x + 1] += 1;
            d[max(y, k - x) + 1] -= 1;
            d[max(y, k - x) + 1] += 2;
        }
        int ans = n, s = 0;
        for (int x : d) {
            s += x;
            ans = min(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minChanges(nums []int, k int) int {
	d := make([]int, k+2)
	n := len(nums)
	for i := 0; i < n/2; i++ {
		x, y := nums[i], nums[n-1-i]
		if x > y {
			x, y = y, x
		}
		d[0] += 1
		d[y-x] -= 1
		d[y-x+1] += 1
		d[max(y, k-x)+1] -= 1
		d[max(y, k-x)+1] += 2
	}
	ans, s := n, 0
	for _, x := range d {
		s += x
		ans = min(ans, s)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minChanges(nums: number[], k: number): number {
    const d: number[] = Array(k + 2).fill(0);
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        const x = Math.min(nums[i], nums[n - 1 - i]);
        const y = Math.max(nums[i], nums[n - 1 - i]);
        d[0] += 1;
        d[y - x] -= 1;
        d[y - x + 1] += 1;
        d[Math.max(y, k - x) + 1] -= 1;
        d[Math.max(y, k - x) + 1] += 2;
    }
    let [ans, s] = [n, 0];
    for (const x of d) {
        s += x;
        ans = Math.min(ans, s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_changes(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut d = vec![0; (k + 2) as usize];
        for i in 0..n / 2 {
            let x = nums[i].min(nums[n - i - 1]);
            let y = nums[i].max(nums[n - i - 1]);
            d[0] += 1;
            d[(y - x) as usize] -= 1;
            d[(y - x + 1) as usize] += 1;
            let idx = (y.max(k - x) + 1) as usize;
            d[idx] -= 1;
            d[idx] += 2;
        }
        let mut ans = n as i32;
        let mut s = 0;
        for x in d {
            s += x;
            ans = ans.min(s);
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，<code>n</code>&nbsp;是 <strong>偶数</strong>&nbsp;，同时给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以对数组进行一些操作。每次操作中，你可以将数组中 <strong>任一</strong>&nbsp;元素替换为 <code>0</code>&nbsp;到 <code>k</code>&nbsp;之间的<strong>&nbsp;任一</strong>&nbsp;整数。</p>

<p>执行完所有操作以后，你需要确保最后得到的数组满足以下条件：</p>

<ul>
	<li>存在一个整数 <code>X</code>&nbsp;，满足对于所有的&nbsp;<code>(0 &lt;= i &lt; n)</code>&nbsp;都有&nbsp;<code>abs(a[i] - a[n - i - 1]) = X</code>&nbsp;。</li>
</ul>

<p>请你返回满足以上条件 <strong>最少</strong>&nbsp;修改次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,0,1,2,4,3], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>将&nbsp;<code>nums[1]</code>&nbsp;变为 2 ，结果数组为&nbsp;<code>nums = [1,<em><strong>2</strong></em>,1,2,4,3]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[3]</code>&nbsp;变为 3 ，结果数组为&nbsp;<code>nums = [1,2,1,<em><strong>3</strong></em>,4,3]</code>&nbsp;。</li>
</ul>

<p>整数&nbsp;<code>X</code>&nbsp;为 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,2,3,3,6,5,4], k = 6</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>将&nbsp;<code>nums[3]</code>&nbsp;变为 0 ，结果数组为&nbsp;<code>nums = [0,1,2,<em><strong>0</strong></em>,3,6,5,4]</code>&nbsp;。</li>
	<li>将&nbsp;<code>nums[4]</code>&nbsp;变为 4 ，结果数组为&nbsp;<code>nums = [0,1,2,0,<em><strong>4</strong></em>,6,5,4]</code>&nbsp;。</li>
</ul>

<p>整数 <code>X</code>&nbsp;为 4 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code>&nbsp;是偶数。</li>
	<li><code>0 &lt;= nums[i] &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

假设最终的数组中，数对 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的差值为 $s$。

我们不妨设 $x$ 为 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的较小值，设 $y$ 为 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的较大值。

对于每一对数，我们有以下几种情况：

-   如果不需要改动，那么 $y - x = s$。
-   如果改动一次，那么 $s \le \max(y, k - x)$，最大值就是把 $x$ 变为 $0$，或者把 $y$ 变为 $k$。
-   如果改动两次，那么 $s \gt \max(y, k - x)$。

即：

-   在 $[0,y-x-1]$ 范围内，需要改动 $1$ 次。
-   在 $[y-x]$ 时，不需要改动。
-   在 $[y-x+1, \max(y, k-x)]$ 范围内，需要改动 $1$ 次。
-   在 $[\max(y, k-x)+1, k]$ 范围内，需要改动 $2$ 次。

我们枚举每一个数对，利用差分数组，更新每个数对在不同区间范围内的改动次数。

最后，我们求出差分数组的前缀和中的最小值，即为最少的改动次数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

相似题目：

-   [1674. 使数组互补的最少操作次数](https://github.com/doocs/leetcode/tree/main/solution/1600-1699/1674.Minimum%20Moves%20to%20Make%20Array%20Complementary/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        d = [0] * (k + 2)
        n = len(nums)
        for i in range(n // 2):
            x, y = nums[i], nums[-i - 1]
            if x > y:
                x, y = y, x
            d[0] += 1
            d[y - x] -= 1
            d[y - x + 1] += 1
            d[max(y, k - x) + 1] -= 1
            d[max(y, k - x) + 1] += 2
        return min(accumulate(d))
```

#### Java

```java
class Solution {
    public int minChanges(int[] nums, int k) {
        int[] d = new int[k + 2];
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            int x = Math.min(nums[i], nums[n - i - 1]);
            int y = Math.max(nums[i], nums[n - i - 1]);
            d[0] += 1;
            d[y - x] -= 1;
            d[y - x + 1] += 1;
            d[Math.max(y, k - x) + 1] -= 1;
            d[Math.max(y, k - x) + 1] += 2;
        }
        int ans = n, s = 0;
        for (int x : d) {
            s += x;
            ans = Math.min(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int d[k + 2];
        memset(d, 0, sizeof(d));
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int x = min(nums[i], nums[n - i - 1]);
            int y = max(nums[i], nums[n - i - 1]);
            d[0] += 1;
            d[y - x] -= 1;
            d[y - x + 1] += 1;
            d[max(y, k - x) + 1] -= 1;
            d[max(y, k - x) + 1] += 2;
        }
        int ans = n, s = 0;
        for (int x : d) {
            s += x;
            ans = min(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func minChanges(nums []int, k int) int {
	d := make([]int, k+2)
	n := len(nums)
	for i := 0; i < n/2; i++ {
		x, y := nums[i], nums[n-1-i]
		if x > y {
			x, y = y, x
		}
		d[0] += 1
		d[y-x] -= 1
		d[y-x+1] += 1
		d[max(y, k-x)+1] -= 1
		d[max(y, k-x)+1] += 2
	}
	ans, s := n, 0
	for _, x := range d {
		s += x
		ans = min(ans, s)
	}
	return ans
}
```

#### TypeScript

```ts
function minChanges(nums: number[], k: number): number {
    const d: number[] = Array(k + 2).fill(0);
    const n = nums.length;
    for (let i = 0; i < n >> 1; ++i) {
        const x = Math.min(nums[i], nums[n - 1 - i]);
        const y = Math.max(nums[i], nums[n - 1 - i]);
        d[0] += 1;
        d[y - x] -= 1;
        d[y - x + 1] += 1;
        d[Math.max(y, k - x) + 1] -= 1;
        d[Math.max(y, k - x) + 1] += 2;
    }
    let [ans, s] = [n, 0];
    for (const x of d) {
        s += x;
        ans = Math.min(ans, s);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_changes(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut d = vec![0; (k + 2) as usize];
        for i in 0..n / 2 {
            let x = nums[i].min(nums[n - i - 1]);
            let y = nums[i].max(nums[n - i - 1]);
            d[0] += 1;
            d[(y - x) as usize] -= 1;
            d[(y - x + 1) as usize] += 1;
            let idx = (y.max(k - x) + 1) as usize;
            d[idx] -= 1;
            d[idx] += 2;
        }
        let mut ans = n as i32;
        let mut s = 0;
        for x in d {
            s += x;
            ans = ans.min(s);
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

# [3225. 网格图操作后的最大分数](https://leetcode.cn/problems/maximum-score-from-grid-operations){#3225}

{{< tabs "3225" >}}

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

<p>给你一个大小为 <code>n x n</code>&nbsp;的二维矩阵&nbsp;<code>grid</code>&nbsp;，一开始所有格子都是白色的。一次操作中，你可以选择任意下标为&nbsp;<code>(i, j)</code>&nbsp;的格子，并将第&nbsp;<code>j</code>&nbsp;列中从最上面到第&nbsp;<code>i</code>&nbsp;行所有格子改成黑色。</p>

<p>如果格子 <code>(i, j)</code>&nbsp;为白色，且左边或者右边的格子至少一个格子为黑色，那么我们将 <code>grid[i][j]</code>&nbsp;加到最后网格图的总分中去。</p>

<p>请你返回执行任意次操作以后，最终网格图的 <strong>最大</strong>&nbsp;总分数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]</span></p>

<p><span class="example-io"><b>输出：</b>11</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3225.Maximum%20Score%20From%20Grid%20Operations/images/one.png" style="width: 300px; height: 200px;" />
<p>第一次操作中，我们将第 1 列中，最上面的格子到第 3 行的格子染成黑色。第二次操作中，我们将第 4 列中，最上面的格子到最后一行的格子染成黑色。最后网格图总分为&nbsp;<code>grid[3][0] + grid[1][2] + grid[3][3]</code>&nbsp;等于 11 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]</span></p>

<p><span class="example-io"><b>输出：</b>94</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3225.Maximum%20Score%20From%20Grid%20Operations/images/two-1.png" style="width: 300px; height: 200px;" />
<p>我们对第 1 ，2 ，3 列分别从上往下染黑色到第 1 ，4， 0 行。最后网格图总分为&nbsp;<code>grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4]</code>&nbsp;等于 94 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;n == grid.length &lt;= 100</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>9</sup></code></li>
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

# [3226. 使两个整数相等的位更改次数](https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal){#3226}

{{< tabs "3226" >}}

{{% tab "python" %}}
```python
class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return -1 if n & k != k else (n ^ k).bit_count()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minChanges(int n, int k) {
        return (n & k) != k ? -1 : Integer.bitCount(n ^ k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minChanges(n int, k int) int {
	if n&k != k {
		return -1
	}
	return bits.OnesCount(uint(n ^ k))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minChanges(n: number, k: number): number {
    return (n & k) !== k ? -1 : bitCount(n ^ k);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_changes(n: i32, k: i32) -> i32 {
        if (n & k) != k {
            -1
        } else {
            (n ^ k).count_ones() as i32
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinChanges(int n, int k) {
        return (n & k) != k ? -1 : BitOperations.PopCount((uint)(n ^ k));
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>n</code> 和 <code>k</code>。</p>

<p>你可以选择 <code>n</code> 的 <strong>二进制表示</strong> 中任意一个值为 1 的位，并将其改为 0。</p>

<p>返回使得 <code>n</code> 等于 <code>k</code> 所需要的更改次数。如果无法实现，返回 -1。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 13, k = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong><br />
最初，<code>n</code> 和 <code>k</code> 的二进制表示分别为 <code>n = (1101)<sub>2</sub></code> 和 <code>k = (0100)<sub>2</sub></code>，</p>

<p>我们可以改变 <code>n</code> 的第一位和第四位。结果整数为 <code>n = (<u><strong>0</strong></u>10<u><strong>0</strong></u>)<sub>2</sub> = k</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 21, k = 21</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong><br />
<code>n</code> 和 <code>k</code> 已经相等，因此不需要更改。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 14, k = 13</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong><br />
无法使 <code>n</code> 等于 <code>k</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

如果 $n$ 和 $k$ 的按位与结果不等于 $k$，说明 $k$ 存在某一位为 $1$，而 $n$ 对应的位为 $0$，此时无法通过改变 $n$ 的某一位使得 $n$ 等于 $k$，返回 $-1$；否则，我们统计 $n \oplus k$ 的二进制表示中 $1$ 的个数即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return -1 if n & k != k else (n ^ k).bit_count()
```

#### Java

```java
class Solution {
    public int minChanges(int n, int k) {
        return (n & k) != k ? -1 : Integer.bitCount(n ^ k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};
```

#### Go

```go
func minChanges(n int, k int) int {
	if n&k != k {
		return -1
	}
	return bits.OnesCount(uint(n ^ k))
}
```

#### TypeScript

```ts
function minChanges(n: number, k: number): number {
    return (n & k) !== k ? -1 : bitCount(n ^ k);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_changes(n: i32, k: i32) -> i32 {
        if (n & k) != k {
            -1
        } else {
            (n ^ k).count_ones() as i32
        }
    }
}
```

#### C#

```cs
public class Solution {
    public int MinChanges(int n, int k) {
        return (n & k) != k ? -1 : BitOperations.PopCount((uint)(n ^ k));
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3227. 字符串元音游戏](https://leetcode.cn/problems/vowels-game-in-a-string){#3227}

{{< tabs "3227" >}}

{{% tab "python" %}}
```python
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels = set("aeiou")
        return any(c in vowels for c in s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean doesAliceWin(String s) {
        for (int i = 0; i < s.length(); ++i) {
            if ("aeiou".indexOf(s.charAt(i)) != -1) {
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
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func doesAliceWin(s string) bool {
	vowels := "aeiou"
	for _, c := range s {
		if strings.ContainsRune(vowels, c) {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function doesAliceWin(s: string): boolean {
    const vowels = 'aeiou';
    for (const c of s) {
        if (vowels.includes(c)) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        let vowels = "aeiou";
        for c in s.chars() {
            if vowels.contains(c) {
                return true;
            }
        }
        false
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool DoesAliceWin(string s) {
        string vowels = "aeiou";
        foreach (char c in s) {
            if (vowels.Contains(c)) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>小红和小明在玩一个字符串元音游戏。</p>

<p>给你一个字符串 <code>s</code>，小红和小明将轮流参与游戏，小红<strong> 先 </strong>开始：</p>

<ul>
	<li>在小红的回合，她必须移除 <code>s</code> 中包含 <strong>奇数 </strong>个元音的任意 <strong>非空</strong> <span data-keyword="substring">子字符串</span>。</li>
	<li>在小明的回合，他必须移除 <code>s</code> 中包含 <strong>偶数 </strong>个元音的任意 <strong>非空</strong> <span data-keyword="substring">子字符串</span>。</li>
</ul>

<p>第一个无法在其回合内进行移除操作的玩家输掉游戏。假设小红和小明都采取 <strong>最优策略 </strong>。</p>

<p>如果小红赢得游戏，返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>英文元音字母包括：<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, 和 <code>u</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "leetcoder"</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong><br />
小红可以执行如下移除操作来赢得游戏：</p>

<ul>
	<li>小红先手，她可以移除加下划线的子字符串 <code>s = "<u><strong>leetco</strong></u>der"</code>，其中包含 3 个元音。结果字符串为 <code>s = "der"</code>。</li>
	<li>小明接着，他可以移除加下划线的子字符串 <code>s = "<u><strong>d</strong></u>er"</code>，其中包含 0 个元音。结果字符串为 <code>s = "er"</code>。</li>
	<li>小红再次操作，她可以移除整个字符串 <code>s = "<strong><u>er</u></strong>"</code>，其中包含 1 个元音。</li>
	<li>又轮到小明，由于字符串为空，无法执行移除操作，因此小红赢得游戏。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "bbcd"</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong><br />
小红在她的第一回合无法执行移除操作，因此小红输掉了游戏。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们不妨记字符串中元音字母的个数为 $k$。

如果 $k = 0$，即字符串中没有元音字母，那么小红无法移除任何子字符串，小明直接获胜。

如果 $k$ 为奇数，那么小红可以移除整个字符串，小红直接获胜。

如果 $k$ 为偶数，那么小红可以移除 $k - 1$ 个元音字母，此时剩下一个元音字母，小明无法移除任何子字符串，小红直接获胜。

综上所述，如果字符串中包含元音字母，那么小红获胜，否则小明获胜。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels = set("aeiou")
        return any(c in vowels for c in s)
```

#### Java

```java
class Solution {
    public boolean doesAliceWin(String s) {
        for (int i = 0; i < s.length(); ++i) {
            if ("aeiou".indexOf(s.charAt(i)) != -1) {
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
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func doesAliceWin(s string) bool {
	vowels := "aeiou"
	for _, c := range s {
		if strings.ContainsRune(vowels, c) {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function doesAliceWin(s: string): boolean {
    const vowels = 'aeiou';
    for (const c of s) {
        if (vowels.includes(c)) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        let vowels = "aeiou";
        for c in s.chars() {
            if vowels.contains(c) {
                return true;
            }
        }
        false
    }
}
```

#### C#

```cs
public class Solution {
    public bool DoesAliceWin(string s) {
        string vowels = "aeiou";
        foreach (char c in s) {
            if (vowels.Contains(c)) {
                return true;
            }
        }
        return false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3228. 将 1 移动到末尾的最大操作次数](https://leetcode.cn/problems/maximum-number-of-operations-to-move-ones-to-the-end){#3228}

{{< tabs "3228" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxOperations(self, s: str) -> int:
        ans = cnt = 0
        for i, c in enumerate(s):
            if c == "1":
                cnt += 1
            elif i and s[i - 1] == "1":
                ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxOperations(String s) {
        int ans = 0, cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            } else if (i > 0 && s.charAt(i - 1) == '1') {
                ans += cnt;
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
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else if (i && s[i - 1] == '1') {
                ans += cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxOperations(s string) (ans int) {
	cnt := 0
	for i, c := range s {
		if c == '1' {
			cnt++
		} else if i > 0 && s[i-1] == '1' {
			ans += cnt
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxOperations(s: string): number {
    let [ans, cnt] = [0, 0];
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        if (s[i] === '1') {
            ++cnt;
        } else if (i && s[i - 1] === '1') {
            ans += cnt;
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

<p>给你一个 <span data-keyword="binary-string">二进制字符串</span> <code>s</code>。</p>

<p>你可以对这个字符串执行 <strong>任意次</strong> 下述操作：</p>

<ul>
	<li>选择字符串中的任一下标 <code>i</code>（ <code>i + 1 &lt; s.length</code> ），该下标满足 <code>s[i] == '1'</code> 且 <code>s[i + 1] == '0'</code>。</li>
	<li>将字符 <code>s[i]</code> 向 <strong>右移 </strong>直到它到达字符串的末端或另一个 <code>'1'</code>。例如，对于 <code>s = "010010"</code>，如果我们选择 <code>i = 1</code>，结果字符串将会是 <code>s = "0<strong><u>001</u></strong>10"</code>。</li>
</ul>

<p>返回你能执行的<strong> 最大 </strong>操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "1001101"</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>可以执行以下操作：</p>

<ul>
	<li>选择下标 <code>i = 0</code>。结果字符串为 <code>s = "<u><strong>001</strong></u>1101"</code>。</li>
	<li>选择下标 <code>i = 4</code>。结果字符串为 <code>s = "0011<u><strong>01</strong></u>1"</code>。</li>
	<li>选择下标 <code>i = 3</code>。结果字符串为 <code>s = "001<strong><u>01</u></strong>11"</code>。</li>
	<li>选择下标 <code>i = 2</code>。结果字符串为 <code>s = "00<strong><u>01</u></strong>111"</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "00111"</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用一个变量 $\textit{ans}$ 记录答案，用一个变量 $\textit{cnt}$ 记录当前的 $1$ 的个数。

然后我们遍历字符串 $s$，如果当前字符是 $1$，则 $\textit{cnt}$ 加一，否则如果存在前一个字符，且前一个字符是 $1$，那么前面的 $\textit{cnt}$ 个 $1$ 可以往后移动，答案加上 $\textit{cnt}$。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOperations(self, s: str) -> int:
        ans = cnt = 0
        for i, c in enumerate(s):
            if c == "1":
                cnt += 1
            elif i and s[i - 1] == "1":
                ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public int maxOperations(String s) {
        int ans = 0, cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            } else if (i > 0 && s.charAt(i - 1) == '1') {
                ans += cnt;
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
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else if (i && s[i - 1] == '1') {
                ans += cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxOperations(s string) (ans int) {
	cnt := 0
	for i, c := range s {
		if c == '1' {
			cnt++
		} else if i > 0 && s[i-1] == '1' {
			ans += cnt
		}
	}
	return
}
```

#### TypeScript

```ts
function maxOperations(s: string): number {
    let [ans, cnt] = [0, 0];
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        if (s[i] === '1') {
            ++cnt;
        } else if (i && s[i - 1] === '1') {
            ans += cnt;
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

# [3229. 使数组等于目标数组所需的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-array-equal-to-target){#3229}

{{< tabs "3229" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        f = abs(target[0] - nums[0])
        for i in range(1, n):
            x = target[i] - nums[i]
            y = target[i - 1] - nums[i - 1]
            if x * y > 0:
                d = abs(x) - abs(y)
                if d > 0:
                    f += d
            else:
                f += abs(x)
        return f
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        long f = Math.abs(target[0] - nums[0]);
        for (int i = 1; i < nums.length; ++i) {
            long x = target[i] - nums[i];
            long y = target[i - 1] - nums[i - 1];
            if (x * y > 0) {
                long d = Math.abs(x) - Math.abs(y);
                if (d > 0) {
                    f += d;
                }
            } else {
                f += Math.abs(x);
            }
        }
        return f;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        using ll = long long;
        ll f = abs(target[0] - nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            long x = target[i] - nums[i];
            long y = target[i - 1] - nums[i - 1];
            if (x * y > 0) {
                ll d = abs(x) - abs(y);
                if (d > 0) {
                    f += d;
                }
            } else {
                f += abs(x);
            }
        }
        return f;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int, target []int) int64 {
	f := abs(target[0] - nums[0])
	for i := 1; i < len(target); i++ {
		x := target[i] - nums[i]
		y := target[i-1] - nums[i-1]
		if x*y > 0 {
			if d := abs(x) - abs(y); d > 0 {
				f += d
			}
		} else {
			f += abs(x)
		}
	}
	return int64(f)
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
function minimumOperations(nums: number[], target: number[]): number {
    const n = nums.length;
    let f = Math.abs(target[0] - nums[0]);
    for (let i = 1; i < n; ++i) {
        const x = target[i] - nums[i];
        const y = target[i - 1] - nums[i - 1];
        if (x * y > 0) {
            const d = Math.abs(x) - Math.abs(y);
            if (d > 0) {
                f += d;
            }
        } else {
            f += Math.abs(x);
        }
    }
    return f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个长度相同的正整数数组 <code>nums</code> 和 <code>target</code>。</p>

<p>在一次操作中，你可以选择 <code>nums</code> 的任何子数组，并将该子数组内的每个元素的值增加或减少 1。</p>

<p>返回使 <code>nums</code> 数组变为 <code>target</code> 数组所需的 <strong>最少 </strong>操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,5,1,2], target = [4,6,2,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>执行以下操作可以使 <code>nums</code> 等于 <code>target</code>：<br />
- <code>nums[0..3]</code> 增加 1，<code>nums = [4,6,2,3]</code>。<br />
- <code>nums[3..3]</code> 增加 1，<code>nums = [4,6,2,4]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,3,2], target = [2,1,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>执行以下操作可以使 <code>nums</code> 等于 <code>target</code>：<br />
- <code>nums[0..0]</code> 增加 1，<code>nums = [2,3,2]</code>。<br />
- <code>nums[1..1]</code> 减少 1，<code>nums = [2,2,2]</code>。<br />
- <code>nums[1..1]</code> 减少 1，<code>nums = [2,1,2]</code>。<br />
- <code>nums[2..2]</code> 增加 1，<code>nums = [2,1,3]</code>。<br />
- <code>nums[2..2]</code> 增加 1，<code>nums = [2,1,4]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们可以先计算出 $\textit{nums}$ 和 $\textit{target}$ 两个数组的差值，然后对于一个差值数组，我们找出连续的差值符号相同的区间，然后对于每个区间，我们将第一个元素的绝对值加到结果中，然后对于后面的元素，如果差值的绝对值比前一个差值的绝对值大，那么我们将绝对值的差值加到结果中。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [1526. 形成目标数组的子数组最少增加次数](https://github.com/doocs/leetcode/tree/main/solution/1500-1599/1526.Minimum%20Number%20of%20Increments%20on%20Subarrays%20to%20Form%20a%20Target%20Array/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        f = abs(target[0] - nums[0])
        for i in range(1, n):
            x = target[i] - nums[i]
            y = target[i - 1] - nums[i - 1]
            if x * y > 0:
                d = abs(x) - abs(y)
                if d > 0:
                    f += d
            else:
                f += abs(x)
        return f
```

#### Java

```java
class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        long f = Math.abs(target[0] - nums[0]);
        for (int i = 1; i < nums.length; ++i) {
            long x = target[i] - nums[i];
            long y = target[i - 1] - nums[i - 1];
            if (x * y > 0) {
                long d = Math.abs(x) - Math.abs(y);
                if (d > 0) {
                    f += d;
                }
            } else {
                f += Math.abs(x);
            }
        }
        return f;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        using ll = long long;
        ll f = abs(target[0] - nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            long x = target[i] - nums[i];
            long y = target[i - 1] - nums[i - 1];
            if (x * y > 0) {
                ll d = abs(x) - abs(y);
                if (d > 0) {
                    f += d;
                }
            } else {
                f += abs(x);
            }
        }
        return f;
    }
};
```

#### Go

```go
func minimumOperations(nums []int, target []int) int64 {
	f := abs(target[0] - nums[0])
	for i := 1; i < len(target); i++ {
		x := target[i] - nums[i]
		y := target[i-1] - nums[i-1]
		if x*y > 0 {
			if d := abs(x) - abs(y); d > 0 {
				f += d
			}
		} else {
			f += abs(x)
		}
	}
	return int64(f)
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
function minimumOperations(nums: number[], target: number[]): number {
    const n = nums.length;
    let f = Math.abs(target[0] - nums[0]);
    for (let i = 1; i < n; ++i) {
        const x = target[i] - nums[i];
        const y = target[i - 1] - nums[i - 1];
        if (x * y > 0) {
            const d = Math.abs(x) - Math.abs(y);
            if (d > 0) {
                f += d;
            }
        } else {
            f += Math.abs(x);
        }
    }
    return f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

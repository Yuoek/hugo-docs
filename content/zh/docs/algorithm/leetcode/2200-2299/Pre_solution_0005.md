---
title: "2240_买钢笔和铅笔的方案数"
date: 2025-10-08T18:39:07+08:00
weight: 5
tags: [位运算, 几何, 前缀和, 动态规划, 哈希表, 图, 字符串, 拓扑排序, 排序, 数学, 数组, 枚举, 树, 模拟, 深度优先搜索, 状态压缩, 矩阵, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2240_买钢笔和铅笔的方案数](#2240)
#### [数学](#2240)
#### [枚举](#2240)
### [2241_设计一个 ATM 机器](#2241)
#### [贪心](#2241)
#### [设计](#2241)
#### [数组](#2241)
### [2242_节点序列的最大得分](#2242)
#### [图](#2242)
#### [数组](#2242)
#### [枚举](#2242)
#### [排序](#2242)
### [2243_计算字符串的数字和](#2243)
#### [字符串](#2243)
#### [模拟](#2243)
### [2244_完成所有任务需要的最少轮数](#2244)
#### [贪心](#2244)
#### [数组](#2244)
#### [哈希表](#2244)
#### [计数](#2244)
### [2245_转角路径的乘积中最多能有几个尾随零](#2245)
#### [数组](#2245)
#### [矩阵](#2245)
#### [前缀和](#2245)
### [2246_相邻字符不同的最长路径](#2246)
#### [树](#2246)
#### [深度优先搜索](#2246)
#### [图](#2246)
#### [拓扑排序](#2246)
#### [数组](#2246)
#### [字符串](#2246)
### [2247_K 条高速公路的最大旅行费用 🔒](#2247)
#### [位运算](#2247)
#### [图](#2247)
#### [动态规划](#2247)
#### [状态压缩](#2247)
### [2248_多个数组求交集](#2248)
#### [数组](#2248)
#### [哈希表](#2248)
#### [计数](#2248)
#### [排序](#2248)
### [2249_统计圆内格点数目](#2249)
#### [几何](#2249)
#### [数组](#2249)
#### [哈希表](#2249)
#### [数学](#2249)
#### [枚举](#2249)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2240_买钢笔和铅笔的方案数
___
#### 数学
___
#### 枚举
---
### 2241_设计一个 ATM 机器
___
#### 贪心
___
#### 设计
___
#### 数组
---
### 2242_节点序列的最大得分
___
#### 图
___
#### 数组
___
#### 枚举
___
#### 排序
---
### 2243_计算字符串的数字和
___
#### 字符串
___
#### 模拟
---
### 2244_完成所有任务需要的最少轮数
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2245_转角路径的乘积中最多能有几个尾随零
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2246_相邻字符不同的最长路径
___
#### 树
___
#### 深度优先搜索
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 字符串
---
### 2247_K 条高速公路的最大旅行费用 🔒
___
#### 位运算
___
#### 图
___
#### 动态规划
___
#### 状态压缩
---
### 2248_多个数组求交集
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
---
### 2249_统计圆内格点数目
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 前缀和 |
| 动态规划 | 哈希表 | 图 |
| 字符串 | 拓扑排序 | 排序 |
| 数学 | 数组 | 枚举 |
| 树 | 模拟 | 深度优先搜索 |
| 状态压缩 | 矩阵 | 计数 |
| 设计 | 贪心 |  |

# [2240. 买钢笔和铅笔的方案数](https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils){#2240}

{{< tabs "2240" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        ans = 0
        for x in range(total // cost1 + 1):
            y = (total - (x * cost1)) // cost2 + 1
            ans += y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ans = 0;
        for (int x = 0; x <= total / cost1; ++x) {
            int y = (total - x * cost1) / cost2 + 1;
            ans += y;
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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (int x = 0; x <= total / cost1; ++x) {
            int y = (total - x * cost1) / cost2 + 1;
            ans += y;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToBuyPensPencils(total int, cost1 int, cost2 int) (ans int64) {
	for x := 0; x <= total/cost1; x++ {
		y := (total-x*cost1)/cost2 + 1
		ans += int64(y)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function waysToBuyPensPencils(total: number, cost1: number, cost2: number): number {
    let ans = 0;
    for (let x = 0; x <= Math.floor(total / cost1); ++x) {
        const y = Math.floor((total - x * cost1) / cost2) + 1;
        ans += y;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn ways_to_buy_pens_pencils(total: i32, cost1: i32, cost2: i32) -> i64 {
        let mut ans: i64 = 0;
        for pen in 0..=total / cost1 {
            ans += (((total - pen * cost1) / cost2) as i64) + 1;
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

<p>给你一个整数&nbsp;<code>total</code>&nbsp;，表示你拥有的总钱数。同时给你两个整数&nbsp;<code>cost1</code> 和&nbsp;<code>cost2</code>&nbsp;，分别表示一支钢笔和一支铅笔的价格。你可以花费你部分或者全部的钱，去买任意数目的两种笔。</p>

<p>请你返回购买钢笔和铅笔的&nbsp;<strong>不同方案数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>total = 20, cost1 = 10, cost2 = 5
<b>输出：</b>9
<b>解释：</b>一支钢笔的价格为 10 ，一支铅笔的价格为 5 。
- 如果你买 0 支钢笔，那么你可以买 0 ，1 ，2 ，3 或者 4 支铅笔。
- 如果你买 1 支钢笔，那么你可以买 0 ，1 或者 2 支铅笔。
- 如果你买 2 支钢笔，那么你没法买任何铅笔。
所以买钢笔和铅笔的总方案数为 5 + 3 + 1 = 9 种。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>total = 5, cost1 = 10, cost2 = 10
<b>输出：</b>1
<b>解释：</b>钢笔和铅笔的价格都为 10 ，都比拥有的钱数多，所以你没法购买任何文具。所以只有 1 种方案：买 0 支钢笔和 0 支铅笔。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= total, cost1, cost2 &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举购买钢笔的数量 $x$，对于每个 $x$，我们最多可以购买铅笔的数量为 $\frac{\textit{total} - x \times \textit{cost1}}{\textit{cost2}}$，那么数量加 $1$ 即为 $x$ 的方案数。我们累加所有的 $x$ 的方案数，即为答案。

时间复杂度 $O(\frac{total}{cost1})$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        ans = 0
        for x in range(total // cost1 + 1):
            y = (total - (x * cost1)) // cost2 + 1
            ans += y
        return ans
```

#### Java

```java
class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ans = 0;
        for (int x = 0; x <= total / cost1; ++x) {
            int y = (total - x * cost1) / cost2 + 1;
            ans += y;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (int x = 0; x <= total / cost1; ++x) {
            int y = (total - x * cost1) / cost2 + 1;
            ans += y;
        }
        return ans;
    }
};
```

#### Go

```go
func waysToBuyPensPencils(total int, cost1 int, cost2 int) (ans int64) {
	for x := 0; x <= total/cost1; x++ {
		y := (total-x*cost1)/cost2 + 1
		ans += int64(y)
	}
	return
}
```

#### TypeScript

```ts
function waysToBuyPensPencils(total: number, cost1: number, cost2: number): number {
    let ans = 0;
    for (let x = 0; x <= Math.floor(total / cost1); ++x) {
        const y = Math.floor((total - x * cost1) / cost2) + 1;
        ans += y;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn ways_to_buy_pens_pencils(total: i32, cost1: i32, cost2: i32) -> i64 {
        let mut ans: i64 = 0;
        for pen in 0..=total / cost1 {
            ans += (((total - pen * cost1) / cost2) as i64) + 1;
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

# [2241. 设计一个 ATM 机器](https://leetcode.cn/problems/design-an-atm-machine){#2241}

{{< tabs "2241" >}}

{{% tab "python" %}}
```python
class ATM:
    def __init__(self):
        self.d = [20, 50, 100, 200, 500]
        self.m = len(self.d)
        self.cnt = [0] * self.m

    def deposit(self, banknotesCount: List[int]) -> None:
        for i, x in enumerate(banknotesCount):
            self.cnt[i] += x

    def withdraw(self, amount: int) -> List[int]:
        ans = [0] * self.m
        for i in reversed(range(self.m)):
            ans[i] = min(amount // self.d[i], self.cnt[i])
            amount -= ans[i] * self.d[i]
        if amount > 0:
            return [-1]
        for i, x in enumerate(ans):
            self.cnt[i] -= x
        return ans


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ATM {
    private int[] d = {20, 50, 100, 200, 500};
    private int m = d.length;
    private long[] cnt = new long[5];

    public ATM() {
    }

    public void deposit(int[] banknotesCount) {
        for (int i = 0; i < banknotesCount.length; ++i) {
            cnt[i] += banknotesCount[i];
        }
    }

    public int[] withdraw(int amount) {
        int[] ans = new int[m];
        for (int i = m - 1; i >= 0; --i) {
            ans[i] = (int) Math.min(amount / d[i], cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return new int[] {-1};
        }
        for (int i = 0; i < m; ++i) {
            cnt[i] -= ans[i];
        }
        return ans;
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * ATM obj = new ATM();
 * obj.deposit(banknotesCount);
 * int[] param_2 = obj.withdraw(amount);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class ATM {
public:
    ATM() {
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); ++i) {
            cnt[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(m);
        for (int i = m - 1; ~i; --i) {
            ans[i] = min(1ll * amount / d[i], cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return {-1};
        }
        for (int i = 0; i < m; ++i) {
            cnt[i] -= ans[i];
        }
        return ans;
    }

private:
    static constexpr int d[5] = {20, 50, 100, 200, 500};
    static constexpr int m = size(d);
    long long cnt[m] = {0};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
var d = [...]int{20, 50, 100, 200, 500}

const m = len(d)

type ATM [m]int

func Constructor() ATM {
	return ATM{}
}

func (this *ATM) Deposit(banknotesCount []int) {
	for i, x := range banknotesCount {
		this[i] += x
	}
}

func (this *ATM) Withdraw(amount int) []int {
	ans := make([]int, m)
	for i := m - 1; i >= 0; i-- {
		ans[i] = min(amount/d[i], this[i])
		amount -= ans[i] * d[i]
	}
	if amount > 0 {
		return []int{-1}
	}
	for i, x := range ans {
		this[i] -= x
	}
	return ans
}

/**
 * Your ATM object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Deposit(banknotesCount);
 * param_2 := obj.Withdraw(amount);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const d: number[] = [20, 50, 100, 200, 500];
const m = d.length;

class ATM {
    private cnt: number[];

    constructor() {
        this.cnt = Array(m).fill(0);
    }

    deposit(banknotesCount: number[]): void {
        for (let i = 0; i < banknotesCount.length; ++i) {
            this.cnt[i] += banknotesCount[i];
        }
    }

    withdraw(amount: number): number[] {
        const ans: number[] = Array(m).fill(0);
        for (let i = m - 1; i >= 0; --i) {
            ans[i] = Math.min(Math.floor(amount / d[i]), this.cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return [-1];
        }
        for (let i = 0; i < m; ++i) {
            this.cnt[i] -= ans[i];
        }
        return ans;
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * var obj = new ATM()
 * obj.deposit(banknotesCount)
 * var param_2 = obj.withdraw(amount)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 ATM 机器，存有&nbsp;<code>5</code>&nbsp;种面值的钞票：<code>20</code>&nbsp;，<code>50</code>&nbsp;，<code>100</code>&nbsp;，<code>200</code>&nbsp;和&nbsp;<code>500</code>&nbsp;美元。初始时，ATM 机是空的。用户可以用它存或者取任意数目的钱。</p>

<p>取款时，机器会优先取 <b>较大</b>&nbsp;数额的钱。</p>

<ul>
	<li>比方说，你想取&nbsp;<code>$300</code>&nbsp;，并且机器里有&nbsp;<code>2</code>&nbsp;张 <code>$50</code>&nbsp;的钞票，<code>1</code>&nbsp;张&nbsp;<code>$100</code>&nbsp;的钞票和<code>1</code>&nbsp;张&nbsp;<code>$200</code>&nbsp;的钞票，那么机器会取出&nbsp;<code>$100</code> 和&nbsp;<code>$200</code>&nbsp;的钞票。</li>
	<li>但是，如果你想取&nbsp;<code>$600</code>&nbsp;，机器里有&nbsp;<code>3</code>&nbsp;张&nbsp;<code>$200</code>&nbsp;的钞票和<code>1</code>&nbsp;张&nbsp;<code>$500</code>&nbsp;的钞票，那么取款请求会被拒绝，因为机器会先取出&nbsp;<code>$500</code>&nbsp;的钞票，然后无法取出剩余的&nbsp;<code>$100</code>&nbsp;。注意，因为有&nbsp;<code>$500</code>&nbsp;钞票的存在，机器&nbsp;<strong>不能</strong>&nbsp;取&nbsp;<code>$200</code>&nbsp;的钞票。</li>
</ul>

<p>请你实现 ATM 类：</p>

<ul>
	<li><code>ATM()</code>&nbsp;初始化 ATM 对象。</li>
	<li><code>void deposit(int[] banknotesCount)</code>&nbsp;分别存入&nbsp;<code>$20</code>&nbsp;，<code>$50</code>，<code>$100</code>，<code>$200</code>&nbsp;和&nbsp;<code>$500</code>&nbsp;钞票的数目。</li>
	<li><code>int[] withdraw(int amount)</code>&nbsp;返回一个长度为&nbsp;<code>5</code>&nbsp;的数组，分别表示&nbsp;<code>$20</code>&nbsp;，<code>$50</code>，<code>$100</code>&nbsp;，<code>$200</code>&nbsp;和&nbsp;<code>$500</code>&nbsp;钞票的数目，并且更新 ATM 机里取款后钞票的剩余数量。如果无法取出指定数额的钱，请返回&nbsp;<code>[-1]</code>&nbsp;（这种情况下 <strong>不</strong>&nbsp;取出任何钞票）。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
[[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
<strong>输出：</strong>
[null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]

<strong>解释：</strong>
ATM atm = new ATM();
atm.deposit([0,0,1,2,1]); // 存入 1 张 $100 ，2 张 $200 和 1 张 $500 的钞票。
atm.withdraw(600);        // 返回 [0,0,1,0,1] 。机器返回 1 张 $100 和 1 张 $500 的钞票。机器里剩余钞票的数量为 [0,0,0,2,0] 。
atm.deposit([0,1,0,1,1]); // 存入 1 张 $50 ，1 张 $200 和 1 张 $500 的钞票。
                          // 机器中剩余钞票数量为 [0,1,0,3,1] 。
atm.withdraw(600);        // 返回 [-1] 。机器会尝试取出 $500 的钞票，然后无法得到剩余的 $100 ，所以取款请求会被拒绝。
                          // 由于请求被拒绝，机器中钞票的数量不会发生改变。
atm.withdraw(550);        // 返回 [0,1,0,0,1] ，机器会返回 1 张 $50 的钞票和 1 张 $500 的钞票。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>banknotesCount.length == 5</code></li>
	<li><code>0 &lt;= banknotesCount[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= amount &lt;= 10<sup>9</sup></code></li>
	<li><strong>总共</strong>&nbsp;最多有&nbsp;<code>5000</code>&nbsp;次&nbsp;<code>withdraw</code> 和&nbsp;<code>deposit</code>&nbsp;的调用。</li>
	<li><span style="">函数 </span><code>withdraw</code> 和&nbsp;<code>deposit</code>&nbsp;至少各有 <strong>一次&nbsp;</strong>调用。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个数组 $\textit{d}$ 记录钞票面额，用一个数组 $\textit{cnt}$ 记录每种面额的钞票数量。

对于 `deposit` 操作，我们只需要将对应面额的钞票数量加上即可。时间复杂度 $O(1)$。

对于 `withdraw` 操作，我们从大到小枚举每种面额的钞票，取出尽可能多且不超过 $\textit{amount}$ 的钞票，然后将 $\textit{amount}$ 减去取出的钞票面额之和，如果最后 $\textit{amount}$ 仍大于 $0$，说明无法取出 $\textit{amount}$ 的钞票，返回 $-1$ 即可。否则，返回取出的钞票数量即可。时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class ATM:
    def __init__(self):
        self.d = [20, 50, 100, 200, 500]
        self.m = len(self.d)
        self.cnt = [0] * self.m

    def deposit(self, banknotesCount: List[int]) -> None:
        for i, x in enumerate(banknotesCount):
            self.cnt[i] += x

    def withdraw(self, amount: int) -> List[int]:
        ans = [0] * self.m
        for i in reversed(range(self.m)):
            ans[i] = min(amount // self.d[i], self.cnt[i])
            amount -= ans[i] * self.d[i]
        if amount > 0:
            return [-1]
        for i, x in enumerate(ans):
            self.cnt[i] -= x
        return ans


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
```

#### Java

```java
class ATM {
    private int[] d = {20, 50, 100, 200, 500};
    private int m = d.length;
    private long[] cnt = new long[5];

    public ATM() {
    }

    public void deposit(int[] banknotesCount) {
        for (int i = 0; i < banknotesCount.length; ++i) {
            cnt[i] += banknotesCount[i];
        }
    }

    public int[] withdraw(int amount) {
        int[] ans = new int[m];
        for (int i = m - 1; i >= 0; --i) {
            ans[i] = (int) Math.min(amount / d[i], cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return new int[] {-1};
        }
        for (int i = 0; i < m; ++i) {
            cnt[i] -= ans[i];
        }
        return ans;
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * ATM obj = new ATM();
 * obj.deposit(banknotesCount);
 * int[] param_2 = obj.withdraw(amount);
 */
```

#### C++

```cpp
class ATM {
public:
    ATM() {
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); ++i) {
            cnt[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(m);
        for (int i = m - 1; ~i; --i) {
            ans[i] = min(1ll * amount / d[i], cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return {-1};
        }
        for (int i = 0; i < m; ++i) {
            cnt[i] -= ans[i];
        }
        return ans;
    }

private:
    static constexpr int d[5] = {20, 50, 100, 200, 500};
    static constexpr int m = size(d);
    long long cnt[m] = {0};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
```

#### Go

```go
var d = [...]int{20, 50, 100, 200, 500}

const m = len(d)

type ATM [m]int

func Constructor() ATM {
	return ATM{}
}

func (this *ATM) Deposit(banknotesCount []int) {
	for i, x := range banknotesCount {
		this[i] += x
	}
}

func (this *ATM) Withdraw(amount int) []int {
	ans := make([]int, m)
	for i := m - 1; i >= 0; i-- {
		ans[i] = min(amount/d[i], this[i])
		amount -= ans[i] * d[i]
	}
	if amount > 0 {
		return []int{-1}
	}
	for i, x := range ans {
		this[i] -= x
	}
	return ans
}

/**
 * Your ATM object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Deposit(banknotesCount);
 * param_2 := obj.Withdraw(amount);
 */
```

#### TypeScript

```ts
const d: number[] = [20, 50, 100, 200, 500];
const m = d.length;

class ATM {
    private cnt: number[];

    constructor() {
        this.cnt = Array(m).fill(0);
    }

    deposit(banknotesCount: number[]): void {
        for (let i = 0; i < banknotesCount.length; ++i) {
            this.cnt[i] += banknotesCount[i];
        }
    }

    withdraw(amount: number): number[] {
        const ans: number[] = Array(m).fill(0);
        for (let i = m - 1; i >= 0; --i) {
            ans[i] = Math.min(Math.floor(amount / d[i]), this.cnt[i]);
            amount -= ans[i] * d[i];
        }
        if (amount > 0) {
            return [-1];
        }
        for (let i = 0; i < m; ++i) {
            this.cnt[i] -= ans[i];
        }
        return ans;
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * var obj = new ATM()
 * obj.deposit(banknotesCount)
 * var param_2 = obj.withdraw(amount)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2242. 节点序列的最大得分](https://leetcode.cn/problems/maximum-score-of-a-node-sequence){#2242}

{{< tabs "2242" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        for k in g.keys():
            g[k] = nlargest(3, g[k], key=lambda x: scores[x])
        ans = -1
        for a, b in edges:
            for c in g[a]:
                for d in g[b]:
                    if b != c != d != a:
                        t = scores[a] + scores[b] + scores[c] + scores[d]
                        ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumScore(int[] scores, int[][] edges) {
        int n = scores.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            g[i].sort((a, b) -> scores[b] - scores[a]);
            g[i] = g[i].subList(0, Math.min(3, g[i].size()));
        }
        int ans = -1;
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            for (int c : g[a]) {
                for (int d : g[b]) {
                    if (c != b && c != d && a != d) {
                        int t = scores[a] + scores[b] + scores[c] + scores[d];
                        ans = Math.max(ans, t);
                    }
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>n</code>&nbsp;个节点的&nbsp;<strong>无向图</strong>&nbsp;，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>scores</code>&nbsp;，其中&nbsp;<code>scores[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的分数。同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;，表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>无向</strong>&nbsp;边。</p>

<p>一个合法的节点序列如果满足以下条件，我们称它是 <strong>合法的</strong>&nbsp;：</p>

<ul>
	<li>序列中每&nbsp;<b>相邻</b>&nbsp;节点之间有边相连。</li>
	<li>序列中没有节点出现超过一次。</li>
</ul>

<p>节点序列的分数定义为序列中节点分数之 <strong>和</strong> 。</p>

<p>请你返回一个长度为 <code>4</code>&nbsp;的合法节点序列的最大分数。如果不存在这样的序列，请你返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2242.Maximum%20Score%20of%20a%20Node%20Sequence/images/ex1new3.png" style="width: 290px; height: 215px;" /></p>

<pre>
<b>输入：</b>scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
<b>输出：</b>24
<b>解释：</b>上图为输入的图，节点序列为 [0,1,2,3] 。
节点序列的分数为 5 + 2 + 9 + 8 = 24 。
观察可知，没有其他节点序列得分和超过 24 。
注意节点序列 [3,1,2,0] 和 [1,0,2,3] 也是合法的，且分数为 24 。
序列 [0,3,2,4] 不是合法的，因为没有边连接节点 0 和 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2242.Maximum%20Score%20of%20a%20Node%20Sequence/images/ex2.png" style="width: 333px; height: 151px;" /></p>

<pre>
<b>输入：</b>scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
<b>输出：</b>-1
<b>解释：</b>上图为输入的图。
没有长度为 4 的合法序列，所以我们返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == scores.length</code></li>
	<li><code>4 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不会有重边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举中间边

枚举中间边 $(a, b)$，假设与 $a$ 相邻的点为 $c$，与 $b$ 相邻的点为 $d$。对于相邻点，取分数最大的三个点进行枚举。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        for k in g.keys():
            g[k] = nlargest(3, g[k], key=lambda x: scores[x])
        ans = -1
        for a, b in edges:
            for c in g[a]:
                for d in g[b]:
                    if b != c != d != a:
                        t = scores[a] + scores[b] + scores[c] + scores[d]
                        ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int maximumScore(int[] scores, int[][] edges) {
        int n = scores.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            g[i].sort((a, b) -> scores[b] - scores[a]);
            g[i] = g[i].subList(0, Math.min(3, g[i].size()));
        }
        int ans = -1;
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            for (int c : g[a]) {
                for (int d : g[b]) {
                    if (c != b && c != d && a != d) {
                        int t = scores[a] + scores[b] + scores[c] + scores[d];
                        ans = Math.max(ans, t);
                    }
                }
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2243. 计算字符串的数字和](https://leetcode.cn/problems/calculate-digit-sum-of-a-string){#2243}

{{< tabs "2243" >}}

{{% tab "python" %}}
```python
class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            t = []
            n = len(s)
            for i in range(0, n, k):
                x = 0
                for j in range(i, min(i + k, n)):
                    x += int(s[j])
                t.append(str(x))
            s = "".join(t)
        return s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String digitSum(String s, int k) {
        while (s.length() > k) {
            int n = s.length();
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < n; i += k) {
                int x = 0;
                for (int j = i; j < Math.min(i + k, n); ++j) {
                    x += s.charAt(j) - '0';
                }
                t.append(x);
            }
            s = t.toString();
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string t;
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int x = 0;
                for (int j = i; j < min(i + k, n); ++j) {
                    x += s[j] - '0';
                }
                t += to_string(x);
            }
            s = t;
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func digitSum(s string, k int) string {
	for len(s) > k {
		t := &strings.Builder{}
		n := len(s)
		for i := 0; i < n; i += k {
			x := 0
			for j := i; j < i+k && j < n; j++ {
				x += int(s[j] - '0')
			}
			t.WriteString(strconv.Itoa(x))
		}
		s = t.String()
	}
	return s
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function digitSum(s: string, k: number): string {
    while (s.length > k) {
        const t: number[] = [];
        for (let i = 0; i < s.length; i += k) {
            const x = s
                .slice(i, i + k)
                .split('')
                .reduce((a, b) => a + +b, 0);
            t.push(x);
        }
        s = t.join('');
    }
    return s;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        let mut s = s;
        let k = k as usize;
        while s.len() > k {
            let mut t = Vec::new();
            for chunk in s.as_bytes().chunks(k) {
                let sum: i32 = chunk.iter().map(|&c| (c - b'0') as i32).sum();
                t.push(sum.to_string());
            }
            s = t.join("");
        }
        s
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var digitSum = function (s, k) {
    while (s.length > k) {
        const t = [];
        for (let i = 0; i < s.length; i += k) {
            const x = s
                .slice(i, i + k)
                .split('')
                .reduce((a, b) => a + +b, 0);
            t.push(x);
        }
        s = t.join('');
    }
    return s;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由若干数字（<code>0</code> - <code>9</code>）组成的字符串 <code>s</code> ，和一个整数。</p>

<p>如果 <code>s</code> 的长度大于 <code>k</code> ，则可以执行一轮操作。在一轮操作中，需要完成以下工作：</p>

<ol>
	<li>将 <code>s</code> <strong>拆分 </strong>成长度为 <code>k</code> 的若干 <strong>连续数字组</strong> ，使得前 <code>k</code> 个字符都分在第一组，接下来的 <code>k</code> 个字符都分在第二组，依此类推。<strong>注意</strong>，最后一个数字组的长度可以小于 <code>k</code> 。</li>
	<li>用表示每个数字组中所有数字之和的字符串来 <strong>替换</strong> 对应的数字组。例如，<code>"346"</code> 会替换为 <code>"13"</code> ，因为 <code>3 + 4 + 6 = 13</code> 。</li>
	<li><strong>合并</strong> 所有组以形成一个新字符串。如果新字符串的长度大于 <code>k</code> 则重复第一步。</li>
</ol>

<p>返回在完成所有轮操作后的 <code>s</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "11111222223", k = 3
<strong>输出：</strong>"135"
<strong>解释：</strong>
- 第一轮，将 s 分成："111"、"112"、"222" 和 "23" 。
  接着，计算每一组的数字和：1 + 1 + 1 = 3、1 + 1 + 2 = 4、2 + 2 + 2 = 6 和 2 + 3 = 5 。 
&nbsp; 这样，s 在第一轮之后变成 "3" + "4" + "6" + "5" = "3465" 。
- 第二轮，将 s 分成："346" 和 "5" 。
&nbsp; 接着，计算每一组的数字和：3 + 4 + 6 = 13 、5 = 5 。
&nbsp; 这样，s 在第二轮之后变成 "13" + "5" = "135" 。 
现在，s.length &lt;= k ，所以返回 "135" 作为答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "00000000", k = 3
<strong>输出：</strong>"000"
<strong>解释：</strong>
将 "000", "000", and "00".
接着，计算每一组的数字和：0 + 0 + 0 = 0 、0 + 0 + 0 = 0 和 0 + 0 = 0 。 
s 变为 "0" + "0" + "0" = "000" ，其长度等于 k ，所以返回 "000" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>2 &lt;= k &lt;= 100</code></li>
	<li><code>s</code> 仅由数字（<code>0</code> - <code>9</code>）组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意，我们可以模拟题目中的操作过程，直到字符串长度小于等于 $k$ 为止，最后返回字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            t = []
            n = len(s)
            for i in range(0, n, k):
                x = 0
                for j in range(i, min(i + k, n)):
                    x += int(s[j])
                t.append(str(x))
            s = "".join(t)
        return s
```

#### Java

```java
class Solution {
    public String digitSum(String s, int k) {
        while (s.length() > k) {
            int n = s.length();
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < n; i += k) {
                int x = 0;
                for (int j = i; j < Math.min(i + k, n); ++j) {
                    x += s.charAt(j) - '0';
                }
                t.append(x);
            }
            s = t.toString();
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string t;
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int x = 0;
                for (int j = i; j < min(i + k, n); ++j) {
                    x += s[j] - '0';
                }
                t += to_string(x);
            }
            s = t;
        }
        return s;
    }
};
```

#### Go

```go
func digitSum(s string, k int) string {
	for len(s) > k {
		t := &strings.Builder{}
		n := len(s)
		for i := 0; i < n; i += k {
			x := 0
			for j := i; j < i+k && j < n; j++ {
				x += int(s[j] - '0')
			}
			t.WriteString(strconv.Itoa(x))
		}
		s = t.String()
	}
	return s
}
```

#### TypeScript

```ts
function digitSum(s: string, k: number): string {
    while (s.length > k) {
        const t: number[] = [];
        for (let i = 0; i < s.length; i += k) {
            const x = s
                .slice(i, i + k)
                .split('')
                .reduce((a, b) => a + +b, 0);
            t.push(x);
        }
        s = t.join('');
    }
    return s;
}
```

#### Rust

```rust
impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        let mut s = s;
        let k = k as usize;
        while s.len() > k {
            let mut t = Vec::new();
            for chunk in s.as_bytes().chunks(k) {
                let sum: i32 = chunk.iter().map(|&c| (c - b'0') as i32).sum();
                t.push(sum.to_string());
            }
            s = t.join("");
        }
        s
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var digitSum = function (s, k) {
    while (s.length > k) {
        const t = [];
        for (let i = 0; i < s.length; i += k) {
            const x = s
                .slice(i, i + k)
                .split('')
                .reduce((a, b) => a + +b, 0);
            t.push(x);
        }
        s = t.join('');
    }
    return s;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2244. 完成所有任务需要的最少轮数](https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks){#2244}

{{< tabs "2244" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        ans = 0
        for v in cnt.values():
            if v == 1:
                return -1
            ans += v // 3 + (v % 3 != 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : tasks) {
            cnt.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        for (int v : cnt.values()) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 == 0 ? 0 : 1);
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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto& t : tasks) {
            ++cnt[t];
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 != 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRounds(tasks []int) int {
	cnt := map[int]int{}
	for _, t := range tasks {
		cnt[t]++
	}
	ans := 0
	for _, v := range cnt {
		if v == 1 {
			return -1
		}
		ans += v / 3
		if v%3 != 0 {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRounds(tasks: number[]): number {
    const cnt = new Map();
    for (const t of tasks) {
        cnt.set(t, (cnt.get(t) || 0) + 1);
    }
    let ans = 0;
    for (const v of cnt.values()) {
        if (v == 1) {
            return -1;
        }
        ans += Math.floor(v / 3) + (v % 3 === 0 ? 0 : 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn minimum_rounds(tasks: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &t in tasks.iter() {
            let count = cnt.entry(t).or_insert(0);
            *count += 1;
        }
        let mut ans = 0;
        for &v in cnt.values() {
            if v == 1 {
                return -1;
            }
            ans += v / 3 + (if v % 3 == 0 { 0 } else { 1 });
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tasks</code> ，其中 <code>tasks[i]</code> 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 <strong>相同难度级别</strong> 的任务。</p>

<p>返回完成所有任务需要的 <strong>最少</strong> 轮数，如果无法完成所有任务，返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tasks = [2,2,3,3,2,4,4,4,4,4]
<strong>输出：</strong>4
<strong>解释：</strong>要想完成所有任务，一个可能的计划是：
- 第一轮，完成难度级别为 2 的 3 个任务。 
- 第二轮，完成难度级别为 3 的 2 个任务。 
- 第三轮，完成难度级别为 4 的 3 个任务。 
- 第四轮，完成难度级别为 4 的 2 个任务。 
可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tasks = [2,3,3]
<strong>输出：</strong>-1
<strong>解释：</strong>难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表统计每个难度级别的任务数量，然后遍历哈希表，对于每个难度级别的任务数量，如果数量为 $1$，则无法完成所有任务，返回 $-1$；否则，计算完成该难度级别的任务需要的轮数，累加到答案中。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `tasks` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        ans = 0
        for v in cnt.values():
            if v == 1:
                return -1
            ans += v // 3 + (v % 3 != 0)
        return ans
```

#### Java

```java
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : tasks) {
            cnt.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        for (int v : cnt.values()) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 == 0 ? 0 : 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto& t : tasks) {
            ++cnt[t];
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 != 0);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumRounds(tasks []int) int {
	cnt := map[int]int{}
	for _, t := range tasks {
		cnt[t]++
	}
	ans := 0
	for _, v := range cnt {
		if v == 1 {
			return -1
		}
		ans += v / 3
		if v%3 != 0 {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumRounds(tasks: number[]): number {
    const cnt = new Map();
    for (const t of tasks) {
        cnt.set(t, (cnt.get(t) || 0) + 1);
    }
    let ans = 0;
    for (const v of cnt.values()) {
        if (v == 1) {
            return -1;
        }
        ans += Math.floor(v / 3) + (v % 3 === 0 ? 0 : 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn minimum_rounds(tasks: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &t in tasks.iter() {
            let count = cnt.entry(t).or_insert(0);
            *count += 1;
        }
        let mut ans = 0;
        for &v in cnt.values() {
            if v == 1 {
                return -1;
            }
            ans += v / 3 + (if v % 3 == 0 { 0 } else { 1 });
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

# [2245. 转角路径的乘积中最多能有几个尾随零](https://leetcode.cn/problems/maximum-trailing-zeros-in-a-cornered-path){#2245}

{{< tabs "2245" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        r2 = [[0] * (n + 1) for _ in range(m + 1)]
        c2 = [[0] * (n + 1) for _ in range(m + 1)]
        r5 = [[0] * (n + 1) for _ in range(m + 1)]
        c5 = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s2 = s5 = 0
                while x % 2 == 0:
                    x //= 2
                    s2 += 1
                while x % 5 == 0:
                    x //= 5
                    s5 += 1
                r2[i][j] = r2[i][j - 1] + s2
                c2[i][j] = c2[i - 1][j] + s2
                r5[i][j] = r5[i][j - 1] + s5
                c5[i][j] = c5[i - 1][j] + s5
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                a = min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j])
                b = min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j])
                c = min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j])
                d = min(
                    r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                    r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j],
                )
                ans = max(ans, a, b, c, d)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxTrailingZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] r2 = new int[m + 1][n + 1];
        int[][] c2 = new int[m + 1][n + 1];
        int[][] r5 = new int[m + 1][n + 1];
        int[][] c5 = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = grid[i - 1][j - 1];
                int s2 = 0, s5 = 0;
                for (; x % 2 == 0; x /= 2) {
                    ++s2;
                }
                for (; x % 5 == 0; x /= 5) {
                    ++s5;
                }
                r2[i][j] = r2[i][j - 1] + s2;
                c2[i][j] = c2[i - 1][j] + s2;
                r5[i][j] = r5[i][j - 1] + s5;
                c5[i][j] = c5[i - 1][j] + s5;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = Math.min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
                int b = Math.min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
                int c = Math.min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
                int d = Math.min(r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                    r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j]);
                ans = Math.max(ans, Math.max(a, Math.max(b, Math.max(c, d))));
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
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> r2(m + 1, vector<int>(n + 1));
        vector<vector<int>> c2(m + 1, vector<int>(n + 1));
        vector<vector<int>> r5(m + 1, vector<int>(n + 1));
        vector<vector<int>> c5(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = grid[i - 1][j - 1];
                int s2 = 0, s5 = 0;
                for (; x % 2 == 0; x /= 2) {
                    ++s2;
                }
                for (; x % 5 == 0; x /= 5) {
                    ++s5;
                }
                r2[i][j] = r2[i][j - 1] + s2;
                c2[i][j] = c2[i - 1][j] + s2;
                r5[i][j] = r5[i][j - 1] + s5;
                c5[i][j] = c5[i - 1][j] + s5;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
                int b = min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
                int c = min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
                int d = min(r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j], r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j]);
                ans = max({ans, a, b, c, d});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTrailingZeros(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	r2 := get(m+1, n+1)
	c2 := get(m+1, n+1)
	r5 := get(m+1, n+1)
	c5 := get(m+1, n+1)
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			x := grid[i-1][j-1]
			s2, s5 := 0, 0
			for ; x%2 == 0; x /= 2 {
				s2++
			}
			for ; x%5 == 0; x /= 5 {
				s5++
			}
			r2[i][j] = r2[i][j-1] + s2
			c2[i][j] = c2[i-1][j] + s2
			r5[i][j] = r5[i][j-1] + s5
			c5[i][j] = c5[i-1][j] + s5
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			a := min(r2[i][j]+c2[i-1][j], r5[i][j]+c5[i-1][j])
			b := min(r2[i][j]+c2[m][j]-c2[i][j], r5[i][j]+c5[m][j]-c5[i][j])
			c := min(r2[i][n]-r2[i][j]+c2[i][j], r5[i][n]-r5[i][j]+c5[i][j])
			d := min(r2[i][n]-r2[i][j-1]+c2[m][j]-c2[i][j], r5[i][n]-r5[i][j-1]+c5[m][j]-c5[i][j])
			ans = max(ans, max(a, max(b, max(c, d))))
		}
	}
	return
}

func get(m, n int) [][]int {
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	return f
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTrailingZeros(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const r2 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const c2 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const r5 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const c5 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            let x = grid[i - 1][j - 1];
            let s2 = 0;
            let s5 = 0;
            for (; x % 2 == 0; x = Math.floor(x / 2)) {
                ++s2;
            }
            for (; x % 5 == 0; x = Math.floor(x / 5)) {
                ++s5;
            }
            r2[i][j] = r2[i][j - 1] + s2;
            c2[i][j] = c2[i - 1][j] + s2;
            r5[i][j] = r5[i][j - 1] + s5;
            c5[i][j] = c5[i - 1][j] + s5;
        }
    }
    let ans = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const a = Math.min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
            const b = Math.min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
            const c = Math.min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
            const d = Math.min(
                r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j],
            );
            ans = Math.max(ans, a, b, c, d);
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

<p>给你一个二维整数数组 <code>grid</code> ，大小为 <code>m x n</code>，其中每个单元格都含一个正整数。</p>

<p><strong>转角路径</strong> 定义为：包含至多一个弯的一组相邻单元。具体而言，路径应该完全 <strong>向水平方向</strong> 或者 <strong>向竖直方向</strong> 移动过弯（如果存在弯），而不能访问之前访问过的单元格。在过弯之后，路径应当完全朝 <strong>另一个</strong> 方向行进：如果之前是向水平方向，那么就应该变为向竖直方向；反之亦然。当然，同样不能访问之前已经访问过的单元格。</p>

<p>一条路径的 <strong>乘积</strong> 定义为：路径上所有值的乘积。</p>

<p>请你从 <code>grid</code> 中找出一条乘积中尾随零数目最多的转角路径，并返回该路径中尾随零的数目。</p>

<p>注意：</p>

<ul>
	<li><strong>水平</strong> 移动是指向左或右移动。</li>
	<li><strong>竖直 </strong>移动是指向上或下移动。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2245.Maximum%20Trailing%20Zeros%20in%20a%20Cornered%20Path/images/ex1new2.jpg" style="width: 577px; height: 190px;" /></p>

<pre>
<strong>输入：</strong>grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
<strong>输出：</strong>3
<strong>解释：</strong>左侧的图展示了一条有效的转角路径。
其乘积为 15 * 20 * 6 * 1 * 10 = 18000 ，共计 3 个尾随零。
可以证明在这条转角路径的乘积中尾随零数目最多。

中间的图不是一条有效的转角路径，因为它有不止一个弯。
右侧的图也不是一条有效的转角路径，因为它需要重复访问已经访问过的单元格。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2245.Maximum%20Trailing%20Zeros%20in%20a%20Cornered%20Path/images/ex2.jpg" style="width: 150px; height: 157px;" /></p>

<pre>
<strong>输入：</strong>grid = [[4,3,2],[7,6,1],[8,8,8]]
<strong>输出：</strong>0
<strong>解释：</strong>网格如上图所示。
不存在乘积含尾随零的转角路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举拐点

首先我们要明确，对于一个乘积，尾随零的个数取决于因子中 $2$ 和 $5$ 的个数的较小值。另外，每一条转角路径应该覆盖尽可能多的数，因此，它一定是从某个边界出发，到达某个拐点，再到达另一个边界。

因此，我们可以创建四个二维数组 $r2$, $c2$, $r5$, $c5$ 来记录每一行和每一列中 $2$ 和 $5$ 的个数。其中：

-   `r2[i][j]` 表示第 $i$ 行中从第 $1$ 列到第 $j$ 列的 $2$ 的个数；
-   `c2[i][j]` 表示第 $j$ 列中从第 $1$ 行到第 $i$ 行的 $2$ 的个数；
-   `r5[i][j]` 表示第 $i$ 行中从第 $1$ 列到第 $j$ 列的 $5$ 的个数；
-   `c5[i][j]` 表示第 $j$ 列中从第 $1$ 行到第 $i$ 行的 $5$ 的个数。

接下来，我们遍历二维数组 `grid`，对于每个数，我们计算它的 $2$ 和 $5$ 的个数，然后更新四个二维数组。

然后，我们枚举拐点 $(i, j)$，对于每个拐点，我们计算四个值，其中：

-   `a` 表示从 $(i, 1)$ 右移到 $(i, j)$，再从 $(i, j)$ 拐头向上移动到 $(1, j)$ 的路径中 $2$ 的个数和 $5$ 的个数的较小值；
-   `b` 表示从 $(i, 1)$ 右移到 $(i, j)$，再从 $(i, j)$ 拐头向下移动到 $(m, j)$ 的路径中 $2$ 的个数和 $5$ 的个数的较小值；
-   `c` 表示从 $(i, n)$ 左移到 $(i, j)$，再从 $(i, j)$ 拐头向上移动到 $(1, j)$ 的路径中 $2$ 的个数和 $5$ 的个数的较小值；
-   `d` 表示从 $(i, n)$ 左移到 $(i, j)$，再从 $(i, j)$ 拐头向下移动到 $(m, j)$ 的路径中 $2$ 的个数和 $5$ 的个数的较小值。

每一次枚举，我们取这四个值的最大值，然后更新答案。

最后，我们返回答案即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组 `grid` 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        r2 = [[0] * (n + 1) for _ in range(m + 1)]
        c2 = [[0] * (n + 1) for _ in range(m + 1)]
        r5 = [[0] * (n + 1) for _ in range(m + 1)]
        c5 = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s2 = s5 = 0
                while x % 2 == 0:
                    x //= 2
                    s2 += 1
                while x % 5 == 0:
                    x //= 5
                    s5 += 1
                r2[i][j] = r2[i][j - 1] + s2
                c2[i][j] = c2[i - 1][j] + s2
                r5[i][j] = r5[i][j - 1] + s5
                c5[i][j] = c5[i - 1][j] + s5
        ans = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                a = min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j])
                b = min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j])
                c = min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j])
                d = min(
                    r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                    r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j],
                )
                ans = max(ans, a, b, c, d)
        return ans
```

#### Java

```java
class Solution {
    public int maxTrailingZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] r2 = new int[m + 1][n + 1];
        int[][] c2 = new int[m + 1][n + 1];
        int[][] r5 = new int[m + 1][n + 1];
        int[][] c5 = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = grid[i - 1][j - 1];
                int s2 = 0, s5 = 0;
                for (; x % 2 == 0; x /= 2) {
                    ++s2;
                }
                for (; x % 5 == 0; x /= 5) {
                    ++s5;
                }
                r2[i][j] = r2[i][j - 1] + s2;
                c2[i][j] = c2[i - 1][j] + s2;
                r5[i][j] = r5[i][j - 1] + s5;
                c5[i][j] = c5[i - 1][j] + s5;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = Math.min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
                int b = Math.min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
                int c = Math.min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
                int d = Math.min(r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                    r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j]);
                ans = Math.max(ans, Math.max(a, Math.max(b, Math.max(c, d))));
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
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> r2(m + 1, vector<int>(n + 1));
        vector<vector<int>> c2(m + 1, vector<int>(n + 1));
        vector<vector<int>> r5(m + 1, vector<int>(n + 1));
        vector<vector<int>> c5(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = grid[i - 1][j - 1];
                int s2 = 0, s5 = 0;
                for (; x % 2 == 0; x /= 2) {
                    ++s2;
                }
                for (; x % 5 == 0; x /= 5) {
                    ++s5;
                }
                r2[i][j] = r2[i][j - 1] + s2;
                c2[i][j] = c2[i - 1][j] + s2;
                r5[i][j] = r5[i][j - 1] + s5;
                c5[i][j] = c5[i - 1][j] + s5;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
                int b = min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
                int c = min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
                int d = min(r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j], r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j]);
                ans = max({ans, a, b, c, d});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxTrailingZeros(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	r2 := get(m+1, n+1)
	c2 := get(m+1, n+1)
	r5 := get(m+1, n+1)
	c5 := get(m+1, n+1)
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			x := grid[i-1][j-1]
			s2, s5 := 0, 0
			for ; x%2 == 0; x /= 2 {
				s2++
			}
			for ; x%5 == 0; x /= 5 {
				s5++
			}
			r2[i][j] = r2[i][j-1] + s2
			c2[i][j] = c2[i-1][j] + s2
			r5[i][j] = r5[i][j-1] + s5
			c5[i][j] = c5[i-1][j] + s5
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			a := min(r2[i][j]+c2[i-1][j], r5[i][j]+c5[i-1][j])
			b := min(r2[i][j]+c2[m][j]-c2[i][j], r5[i][j]+c5[m][j]-c5[i][j])
			c := min(r2[i][n]-r2[i][j]+c2[i][j], r5[i][n]-r5[i][j]+c5[i][j])
			d := min(r2[i][n]-r2[i][j-1]+c2[m][j]-c2[i][j], r5[i][n]-r5[i][j-1]+c5[m][j]-c5[i][j])
			ans = max(ans, max(a, max(b, max(c, d))))
		}
	}
	return
}

func get(m, n int) [][]int {
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	return f
}
```

#### TypeScript

```ts
function maxTrailingZeros(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const r2 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const c2 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const r5 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    const c5 = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            let x = grid[i - 1][j - 1];
            let s2 = 0;
            let s5 = 0;
            for (; x % 2 == 0; x = Math.floor(x / 2)) {
                ++s2;
            }
            for (; x % 5 == 0; x = Math.floor(x / 5)) {
                ++s5;
            }
            r2[i][j] = r2[i][j - 1] + s2;
            c2[i][j] = c2[i - 1][j] + s2;
            r5[i][j] = r5[i][j - 1] + s5;
            c5[i][j] = c5[i - 1][j] + s5;
        }
    }
    let ans = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const a = Math.min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]);
            const b = Math.min(r2[i][j] + c2[m][j] - c2[i][j], r5[i][j] + c5[m][j] - c5[i][j]);
            const c = Math.min(r2[i][n] - r2[i][j] + c2[i][j], r5[i][n] - r5[i][j] + c5[i][j]);
            const d = Math.min(
                r2[i][n] - r2[i][j - 1] + c2[m][j] - c2[i][j],
                r5[i][n] - r5[i][j - 1] + c5[m][j] - c5[i][j],
            );
            ans = Math.max(ans, a, b, c, d);
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

# [2246. 相邻字符不同的最长路径](https://leetcode.cn/problems/longest-path-with-different-adjacent-characters){#2246}

{{< tabs "2246" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        def dfs(i: int) -> int:
            mx = 0
            nonlocal ans
            for j in g[i]:
                x = dfs(j) + 1
                if s[i] != s[j]:
                    ans = max(ans, mx + x)
                    mx = max(mx, x)
            return mx

        g = defaultdict(list)
        for i in range(1, len(parent)):
            g[parent[i]].append(i)
        ans = 0
        dfs(0)
        return ans + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private String s;
    private int ans;

    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        g = new List[n];
        this.s = s;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            g[parent[i]].add(i);
        }
        dfs(0);
        return ans + 1;
    }

    private int dfs(int i) {
        int mx = 0;
        for (int j : g[i]) {
            int x = dfs(j) + 1;
            if (s.charAt(i) != s.charAt(j)) {
                ans = Math.max(ans, mx + x);
                mx = Math.max(mx, x);
            }
        }
        return mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> g[n];
        for (int i = 1; i < n; ++i) {
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        function<int(int)> dfs = [&](int i) -> int {
            int mx = 0;
            for (int j : g[i]) {
                int x = dfs(j) + 1;
                if (s[i] != s[j]) {
                    ans = max(ans, mx + x);
                    mx = max(mx, x);
                }
            }
            return mx;
        };
        dfs(0);
        return ans + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPath(parent []int, s string) int {
	n := len(parent)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		g[parent[i]] = append(g[parent[i]], i)
	}
	ans := 0
	var dfs func(int) int
	dfs = func(i int) int {
		mx := 0
		for _, j := range g[i] {
			x := dfs(j) + 1
			if s[i] != s[j] {
				ans = max(ans, x+mx)
				mx = max(mx, x)
			}
		}
		return mx
	}
	dfs(0)
	return ans + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPath(parent: number[], s: string): number {
    const n = parent.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; ++i) {
        g[parent[i]].push(i);
    }
    let ans = 0;
    const dfs = (i: number): number => {
        let mx = 0;
        for (const j of g[i]) {
            const x = dfs(j) + 1;
            if (s[i] !== s[j]) {
                ans = Math.max(ans, mx + x);
                mx = Math.max(mx, x);
            }
        }
        return mx;
    };
    dfs(0);
    return ans + 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>树</strong>（即一个连通、无向、无环图），根节点是节点 <code>0</code> ，这棵树由编号从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个节点组成。用下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的数组 <code>parent</code> 来表示这棵树，其中 <code>parent[i]</code> 是节点 <code>i</code> 的父节点，由于节点 <code>0</code> 是根节点，所以 <code>parent[0] == -1</code> 。</p>

<p>另给你一个字符串 <code>s</code> ，长度也是 <code>n</code> ，其中 <code>s[i]</code> 表示分配给节点 <code>i</code> 的字符。</p>

<p>请你找出路径上任意一对相邻节点都没有分配到相同字符的 <strong>最长路径</strong> ，并返回该路径的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2246.Longest%20Path%20With%20Different%20Adjacent%20Characters/images/testingdrawio.png" style="width: 201px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>parent = [-1,0,0,1,1,2], s = "abacbe"
<strong>输出：</strong>3
<strong>解释：</strong>任意一对相邻节点字符都不同的最长路径是：0 -&gt; 1 -&gt; 3 。该路径的长度是 3 ，所以返回 3 。
可以证明不存在满足上述条件且比 3 更长的路径。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2246.Longest%20Path%20With%20Different%20Adjacent%20Characters/images/graph2drawio.png" style="width: 201px; height: 221px;" /></p>

<pre>
<strong>输入：</strong>parent = [-1,0,0,0], s = "aabc"
<strong>输出：</strong>3
<strong>解释：</strong>任意一对相邻节点字符都不同的最长路径是：2 -&gt; 0 -&gt; 3 。该路径的长度为 3 ，所以返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parent.length == s.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li>对所有 <code>i &gt;= 1</code> ，<code>0 &lt;= parent[i] &lt;= n - 1</code> 均成立</li>
	<li><code>parent[0] == -1</code></li>
	<li><code>parent</code> 表示一棵有效的树</li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

我们先根据数组 $parent$ 构建邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有子节点。

然后我们从根节点开始 DFS，对于每个节点 $i$，我们遍历 $g[i]$ 中的每个子节点 $j$，如果 $s[i] \neq s[j]$，那么我们就可以从 $i$ 节点出发，经过 $j$ 节点，到达某个叶子节点，这条路径的长度为 $x = 1 + dfs(j)$，我们用 $mx$ 记录最长的一条从节点 $i$ 出发的路径长度。同时，在遍历的过程中，更新答案 $ans = \max(ans, mx + x)$。

最后，我们返回 $ans + 1$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        def dfs(i: int) -> int:
            mx = 0
            nonlocal ans
            for j in g[i]:
                x = dfs(j) + 1
                if s[i] != s[j]:
                    ans = max(ans, mx + x)
                    mx = max(mx, x)
            return mx

        g = defaultdict(list)
        for i in range(1, len(parent)):
            g[parent[i]].append(i)
        ans = 0
        dfs(0)
        return ans + 1
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private String s;
    private int ans;

    public int longestPath(int[] parent, String s) {
        int n = parent.length;
        g = new List[n];
        this.s = s;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 1; i < n; ++i) {
            g[parent[i]].add(i);
        }
        dfs(0);
        return ans + 1;
    }

    private int dfs(int i) {
        int mx = 0;
        for (int j : g[i]) {
            int x = dfs(j) + 1;
            if (s.charAt(i) != s.charAt(j)) {
                ans = Math.max(ans, mx + x);
                mx = Math.max(mx, x);
            }
        }
        return mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> g[n];
        for (int i = 1; i < n; ++i) {
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        function<int(int)> dfs = [&](int i) -> int {
            int mx = 0;
            for (int j : g[i]) {
                int x = dfs(j) + 1;
                if (s[i] != s[j]) {
                    ans = max(ans, mx + x);
                    mx = max(mx, x);
                }
            }
            return mx;
        };
        dfs(0);
        return ans + 1;
    }
};
```

#### Go

```go
func longestPath(parent []int, s string) int {
	n := len(parent)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		g[parent[i]] = append(g[parent[i]], i)
	}
	ans := 0
	var dfs func(int) int
	dfs = func(i int) int {
		mx := 0
		for _, j := range g[i] {
			x := dfs(j) + 1
			if s[i] != s[j] {
				ans = max(ans, x+mx)
				mx = max(mx, x)
			}
		}
		return mx
	}
	dfs(0)
	return ans + 1
}
```

#### TypeScript

```ts
function longestPath(parent: number[], s: string): number {
    const n = parent.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 1; i < n; ++i) {
        g[parent[i]].push(i);
    }
    let ans = 0;
    const dfs = (i: number): number => {
        let mx = 0;
        for (const j of g[i]) {
            const x = dfs(j) + 1;
            if (s[i] !== s[j]) {
                ans = Math.max(ans, mx + x);
                mx = Math.max(mx, x);
            }
        }
        return mx;
    };
    dfs(0);
    return ans + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2247. K 条高速公路的最大旅行费用 🔒](https://leetcode.cn/problems/maximum-cost-of-trip-with-k-highways){#2247}

{{< tabs "2247" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumCost(self, n: int, highways: List[List[int]], k: int) -> int:
        if k >= n:
            return -1
        g = defaultdict(list)
        for a, b, cost in highways:
            g[a].append((b, cost))
            g[b].append((a, cost))
        f = [[-inf] * n for _ in range(1 << n)]
        for i in range(n):
            f[1 << i][i] = 0
        ans = -1
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for h, cost in g[j]:
                        if i >> h & 1:
                            f[i][j] = max(f[i][j], f[i ^ (1 << j)][h] + cost)
                if i.bit_count() == k + 1:
                    ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumCost(int n, int[][] highways, int k) {
        if (k >= n) {
            return -1;
        }
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, h -> new ArrayList<>());
        for (int[] h : highways) {
            int a = h[0], b = h[1], cost = h[2];
            g[a].add(new int[] {b, cost});
            g[b].add(new int[] {a, cost});
        }
        int[][] f = new int[1 << n][n];
        for (int[] e : f) {
            Arrays.fill(e, -(1 << 30));
        }
        for (int i = 0; i < n; ++i) {
            f[1 << i][i] = 0;
        }
        int ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (var e : g[j]) {
                        int h = e[0], cost = e[1];
                        if ((i >> h & 1) == 1) {
                            f[i][j] = Math.max(f[i][j], f[i ^ (1 << j)][h] + cost);
                        }
                    }
                }
                if (Integer.bitCount(i) == k + 1) {
                    ans = Math.max(ans, f[i][j]);
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
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        if (k >= n) {
            return -1;
        }
        vector<pair<int, int>> g[n];
        for (auto& h : highways) {
            int a = h[0], b = h[1], cost = h[2];
            g[a].emplace_back(b, cost);
            g[b].emplace_back(a, cost);
        }
        int f[1 << n][n];
        memset(f, -0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[1 << i][i] = 0;
        }
        int ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (auto& [h, cost] : g[j]) {
                        if (i >> h & 1) {
                            f[i][j] = max(f[i][j], f[i ^ (1 << j)][h] + cost);
                        }
                    }
                }
                if (__builtin_popcount(i) == k + 1) {
                    ans = max(ans, f[i][j]);
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
func maximumCost(n int, highways [][]int, k int) int {
	if k >= n {
		return -1
	}
	g := make([][][2]int, n)
	for _, h := range highways {
		a, b, cost := h[0], h[1], h[2]
		g[a] = append(g[a], [2]int{b, cost})
		g[b] = append(g[b], [2]int{a, cost})
	}
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	for i := 0; i < n; i++ {
		f[1<<i][i] = 0
	}
	ans := -1
	for i := 0; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for _, e := range g[j] {
					h, cost := e[0], e[1]
					if i>>h&1 == 1 {
						f[i][j] = max(f[i][j], f[i^(1<<j)][h]+cost)
					}
				}
			}
			if bits.OnesCount(uint(i)) == k+1 {
				ans = max(ans, f[i][j])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumCost(n: number, highways: number[][], k: number): number {
    if (k >= n) {
        return -1;
    }
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b, cost] of highways) {
        g[a].push([b, cost]);
        g[b].push([a, cost]);
    }
    const f: number[][] = Array(1 << n)
        .fill(0)
        .map(() => Array(n).fill(-(1 << 30)));
    for (let i = 0; i < n; ++i) {
        f[1 << i][i] = 0;
    }
    let ans = -1;
    for (let i = 0; i < 1 << n; ++i) {
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                for (const [h, cost] of g[j]) {
                    if ((i >> h) & 1) {
                        f[i][j] = Math.max(f[i][j], f[i ^ (1 << j)][h] + cost);
                    }
                }
            }
            if (bitCount(i) === k + 1) {
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一系列高速公路连接从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个城市。给定一个二维整数数组 <code>highways</code>，其中 <code>highways[i] = [city1<sub>i</sub>, city2<sub>i</sub>, toll<sub>i</sub>]</code> 表示有一条高速公路连接 <code>city1<sub>i</sub></code> 和<code>city2<sub>i</sub></code>，允许一辆汽车从 <code>city1<sub>i</sub></code> 前往 <code>city2<sub>i</sub></code>，<strong>反之亦然</strong>，费用为 <code>toll<sub>i</sub></code>。</p>

<p>给你一个整数 <code>k</code>，你要<strong>正好</strong>经过 <code>k</code> 条公路。你可以从任何一个城市出发，但在旅途中每个城市<strong>最多</strong>只能访问一次。</p>

<p>返回<em>您旅行的最大费用。如果没有符合要求的行程，则返回 <code>-1</code>。</em></p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2247.Maximum%20Cost%20of%20Trip%20With%20K%20Highways/images/image-20220418173304-1.png" style="height: 200px; width: 327px;" />
<pre>
<strong>输入:</strong> n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], k = 3
<strong>输出:</strong> 17
<strong>解释:</strong>
一个可能的路径是从 0 -&gt; 1 -&gt; 4 -&gt; 3。这次旅行的费用是 4 + 11 + 2 = 17。
另一种可能的路径是从 4 -&gt; 1 -&gt; 2 -&gt; 3。这次旅行的费用是 11 + 3 + 3 = 17。
可以证明，17 是任何有效行程的最大可能费用。
注意，旅行 4 -&gt; 1 -&gt; 0 -&gt; 1 是不允许的，因为你访问了城市 1 两次。
</pre>

<p>&nbsp;</p>

<p><strong class="example">示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2247.Maximum%20Cost%20of%20Trip%20With%20K%20Highways/images/image-20220418173342-2.png" style="height: 200px; width: 217px;" />
<pre>
<strong>输入:</strong> n = 4, highways = [[0,1,3],[2,3,2]], k = 2
<strong>输出:</strong> -1
<strong>解释:</strong> 没有长度为 2 的有效行程，因此返回-1。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>1 &lt;= highways.length &lt;= 50</code></li>
	<li><code>highways[i].length == 3</code></li>
	<li><code>0 &lt;= city1<sub>i</sub>, city2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>city1<sub>i</sub> != city2<sub>i</sub></code></li>
	<li><code>0 &lt;= toll<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
	<li>
	<p data-group="1-1">没有重复的高速公路。</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

我们注意到，题目要求正好经过 $k$ 条公路，而每个城市最多只能访问一次，城市的数量为 $n$，因此，我们最多只能经过 $n - 1$ 条公路。所以，如果 $k \ge n$，那么我们无法满足题目要求，直接返回 $-1$ 即可。

另外，我们也可以发现，城市数量 $n$ 不超过 $15$，这提示我们可以考虑使用状态压缩动态规划的方法求解本题。我们用一个长度为 $n$ 的二进制数表示当前已经经过的城市，其中第 $i$ 位为 $1$ 表示已经经过了第 $i$ 个城市，为 $0$ 表示还没有经过第 $i$ 个城市。

我们用 $f[i][j]$ 表示当前已经经过的城市为 $i$，最后一个经过的城市为 $j$ 的情况下，最大的旅行费用。初始时 $f[2^i][i]=0$，其余 $f[i][j]=-\infty$。

考虑 $f[i][j]$ 如何进行状态转移。对于 $f[i]$，我们枚举所有城市 $j$，如果 $i$ 的第 $j$ 位为 $1$，那么我们就可以从其它城市 $h$ 经过公路到达城市 $j$，此时 $f[i][j]$ 的值为 $f[i][h]+cost(h, j)$ 的最大值，其中 $cost(h, j)$ 表示从城市 $h$ 到城市 $j$ 的旅行费用。因此，我们可以得到状态转移方程：

$$
f[i][j]=\max_{h \in \textit{city}}\{f[i \backslash j][h]+cost(h, j)\}
$$

其中 $i \backslash j$ 表示将 $i$ 的第 $j$ 位变为 $0$。

求出 $f[i][j]$ 后，我们判断经过的城市数量是否为 $k+1$，即 $i$ 的二进制表示中 $1$ 的个数是否为 $k+1$，如果是，那么我们就更新答案为 $ans = \max(ans, f[i][j])$。

时间复杂度 $O(2^n \times n^2)$，空间复杂度 $O(2^n \times n)$。其中 $n$ 表示城市数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCost(self, n: int, highways: List[List[int]], k: int) -> int:
        if k >= n:
            return -1
        g = defaultdict(list)
        for a, b, cost in highways:
            g[a].append((b, cost))
            g[b].append((a, cost))
        f = [[-inf] * n for _ in range(1 << n)]
        for i in range(n):
            f[1 << i][i] = 0
        ans = -1
        for i in range(1 << n):
            for j in range(n):
                if i >> j & 1:
                    for h, cost in g[j]:
                        if i >> h & 1:
                            f[i][j] = max(f[i][j], f[i ^ (1 << j)][h] + cost)
                if i.bit_count() == k + 1:
                    ans = max(ans, f[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int maximumCost(int n, int[][] highways, int k) {
        if (k >= n) {
            return -1;
        }
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, h -> new ArrayList<>());
        for (int[] h : highways) {
            int a = h[0], b = h[1], cost = h[2];
            g[a].add(new int[] {b, cost});
            g[b].add(new int[] {a, cost});
        }
        int[][] f = new int[1 << n][n];
        for (int[] e : f) {
            Arrays.fill(e, -(1 << 30));
        }
        for (int i = 0; i < n; ++i) {
            f[1 << i][i] = 0;
        }
        int ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    for (var e : g[j]) {
                        int h = e[0], cost = e[1];
                        if ((i >> h & 1) == 1) {
                            f[i][j] = Math.max(f[i][j], f[i ^ (1 << j)][h] + cost);
                        }
                    }
                }
                if (Integer.bitCount(i) == k + 1) {
                    ans = Math.max(ans, f[i][j]);
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
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        if (k >= n) {
            return -1;
        }
        vector<pair<int, int>> g[n];
        for (auto& h : highways) {
            int a = h[0], b = h[1], cost = h[2];
            g[a].emplace_back(b, cost);
            g[b].emplace_back(a, cost);
        }
        int f[1 << n][n];
        memset(f, -0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[1 << i][i] = 0;
        }
        int ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (auto& [h, cost] : g[j]) {
                        if (i >> h & 1) {
                            f[i][j] = max(f[i][j], f[i ^ (1 << j)][h] + cost);
                        }
                    }
                }
                if (__builtin_popcount(i) == k + 1) {
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumCost(n int, highways [][]int, k int) int {
	if k >= n {
		return -1
	}
	g := make([][][2]int, n)
	for _, h := range highways {
		a, b, cost := h[0], h[1], h[2]
		g[a] = append(g[a], [2]int{b, cost})
		g[b] = append(g[b], [2]int{a, cost})
	}
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	for i := 0; i < n; i++ {
		f[1<<i][i] = 0
	}
	ans := -1
	for i := 0; i < 1<<n; i++ {
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for _, e := range g[j] {
					h, cost := e[0], e[1]
					if i>>h&1 == 1 {
						f[i][j] = max(f[i][j], f[i^(1<<j)][h]+cost)
					}
				}
			}
			if bits.OnesCount(uint(i)) == k+1 {
				ans = max(ans, f[i][j])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumCost(n: number, highways: number[][], k: number): number {
    if (k >= n) {
        return -1;
    }
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b, cost] of highways) {
        g[a].push([b, cost]);
        g[b].push([a, cost]);
    }
    const f: number[][] = Array(1 << n)
        .fill(0)
        .map(() => Array(n).fill(-(1 << 30)));
    for (let i = 0; i < n; ++i) {
        f[1 << i][i] = 0;
    }
    let ans = -1;
    for (let i = 0; i < 1 << n; ++i) {
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                for (const [h, cost] of g[j]) {
                    if ((i >> h) & 1) {
                        f[i][j] = Math.max(f[i][j], f[i ^ (1 << j)][h] + cost);
                    }
                }
            }
            if (bitCount(i) === k + 1) {
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2248. 多个数组求交集](https://leetcode.cn/problems/intersection-of-multiple-arrays){#2248}

{{< tabs "2248" >}}

{{% tab "python" %}}
```python
class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        cnt = Counter()
        ans = []
        for arr in nums:
            for x in arr:
                cnt[x] += 1
                if cnt[x] == len(nums):
                    ans.append(x)
        ans.sort()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> intersection(int[][] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for (var arr : nums) {
            for (int x : arr) {
                if (cnt.merge(x, 1, Integer::sum) == nums.length) {
                    ans.add(x);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto& arr : nums) {
            for (int& x : arr) {
                if (++cnt[x] == nums.size()) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intersection(nums [][]int) (ans []int) {
	cnt := map[int]int{}
	for _, arr := range nums {
		for _, x := range arr {
			cnt[x]++
			if cnt[x] == len(nums) {
				ans = append(ans, x)
			}
		}
	}
	sort.Ints(ans)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function intersection(nums: number[][]): number[] {
    const cnt = new Array(1001).fill(0);
    const ans: number[] = [];
    for (const arr of nums) {
        for (const x of arr) {
            if (++cnt[x] == nums.length) {
                ans.push(x);
            }
        }
    }
    ans.sort((a, b) => a - b);
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[][] $nums
     * @return Integer[]
     */
    function intersection($nums) {
        $rs = [];
        for ($i = 0; $i < count($nums); $i++) {
            for ($j = 0; $j < count($nums[$i]); $j++) {
                $hashtable[$nums[$i][$j]] += 1;
                if ($hashtable[$nums[$i][$j]] === count($nums)) {
                    array_push($rs, $nums[$i][$j]);
                }
            }
        }
        sort($rs);
        return $rs;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>nums</code> ，其中 <code>nums[i]</code> 是由 <strong>不同</strong> 正整数组成的一个非空数组，按 <strong>升序排列</strong> 返回一个数组，数组中的每个元素在 <code>nums</code>&nbsp;<strong>所有数组</strong> 中都出现过。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[<em><strong>3</strong></em>,1,2,<em><strong>4</strong></em>,5],[1,2,<em><strong>3</strong></em>,<em><strong>4</strong></em>],[<em><strong>3</strong></em>,<em><strong>4</strong></em>,5,6]]
<strong>输出：</strong>[3,4]
<strong>解释：</strong>
nums[0] = [<em><strong>3</strong></em>,1,2,<em><strong>4</strong></em>,5]，nums[1] = [1,2,<em><strong>3</strong></em>,<em><strong>4</strong></em>]，nums[2] = [<em><strong>3</strong></em>,<em><strong>4</strong></em>,5,6]，在 nums 中每个数组中都出现的数字是 3 和 4 ，所以返回 [3,4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[4,5,6]]
<strong>输出：</strong>[]
<strong>解释：</strong>
不存在同时出现在 nums[0] 和 nums[1] 的整数，所以返回一个空列表 [] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(nums[i].length) &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 1000</code></li>
	<li><code>nums[i]</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

遍历数组 `nums`，对于每个数组 `arr`，统计数组 `arr` 中每个数字出现的次数，然后遍历计数数组，统计出现次数等于数组 `nums` 的长度的数字，即为答案。

时间复杂度 $O(N)$，空间复杂度 $O(1000)$。其中 $N$ 为数组 `nums` 中数字的总数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        cnt = [0] * 1001
        for arr in nums:
            for x in arr:
                cnt[x] += 1
        return [x for x, v in enumerate(cnt) if v == len(nums)]
```

#### Java

```java
class Solution {
    public List<Integer> intersection(int[][] nums) {
        int[] cnt = new int[1001];
        for (var arr : nums) {
            for (int x : arr) {
                ++cnt[x];
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int x = 0; x < 1001; ++x) {
            if (cnt[x] == nums.length) {
                ans.add(x);
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
    vector<int> intersection(vector<vector<int>>& nums) {
        int cnt[1001]{};
        for (auto& arr : nums) {
            for (int& x : arr) {
                ++cnt[x];
            }
        }
        vector<int> ans;
        for (int x = 0; x < 1001; ++x) {
            if (cnt[x] == nums.size()) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func intersection(nums [][]int) (ans []int) {
	cnt := [1001]int{}
	for _, arr := range nums {
		for _, x := range arr {
			cnt[x]++
		}
	}
	for x, v := range cnt {
		if v == len(nums) {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function intersection(nums: number[][]): number[] {
    const cnt = new Array(1001).fill(0);
    for (const arr of nums) {
        for (const x of arr) {
            cnt[x]++;
        }
    }
    const ans: number[] = [];
    for (let x = 0; x < 1001; x++) {
        if (cnt[x] === nums.length) {
            ans.push(x);
        }
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[][] $nums
     * @return Integer[]
     */
    function intersection($nums) {
        $rs = [];
        for ($i = 0; $i < count($nums); $i++) {
            for ($j = 0; $j < count($nums[$i]); $j++) {
                $hashtable[$nums[$i][$j]] += 1;
                if ($hashtable[$nums[$i][$j]] === count($nums)) {
                    array_push($rs, $nums[$i][$j]);
                }
            }
        }
        sort($rs);
        return $rs;
    }
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
    def intersection(self, nums: List[List[int]]) -> List[int]:
        cnt = Counter()
        ans = []
        for arr in nums:
            for x in arr:
                cnt[x] += 1
                if cnt[x] == len(nums):
                    ans.append(x)
        ans.sort()
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> intersection(int[][] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for (var arr : nums) {
            for (int x : arr) {
                if (cnt.merge(x, 1, Integer::sum) == nums.length) {
                    ans.add(x);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (auto& arr : nums) {
            for (int& x : arr) {
                if (++cnt[x] == nums.size()) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func intersection(nums [][]int) (ans []int) {
	cnt := map[int]int{}
	for _, arr := range nums {
		for _, x := range arr {
			cnt[x]++
			if cnt[x] == len(nums) {
				ans = append(ans, x)
			}
		}
	}
	sort.Ints(ans)
	return
}
```

#### TypeScript

```ts
function intersection(nums: number[][]): number[] {
    const cnt = new Array(1001).fill(0);
    const ans: number[] = [];
    for (const arr of nums) {
        for (const x of arr) {
            if (++cnt[x] == nums.length) {
                ans.push(x);
            }
        }
    }
    ans.sort((a, b) => a - b);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2249. 统计圆内格点数目](https://leetcode.cn/problems/count-lattice-points-inside-a-circle){#2249}

{{< tabs "2249" >}}

{{% tab "python" %}}
```python
class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        ans = 0
        mx = max(x + r for x, _, r in circles)
        my = max(y + r for _, y, r in circles)
        for i in range(mx + 1):
            for j in range(my + 1):
                for x, y, r in circles:
                    dx, dy = i - x, j - y
                    if dx * dx + dy * dy <= r * r:
                        ans += 1
                        break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countLatticePoints(int[][] circles) {
        int mx = 0, my = 0;
        for (var c : circles) {
            mx = Math.max(mx, c[0] + c[2]);
            my = Math.max(my, c[1] + c[2]);
        }
        int ans = 0;
        for (int i = 0; i <= mx; ++i) {
            for (int j = 0; j <= my; ++j) {
                for (var c : circles) {
                    int dx = i - c[0], dy = j - c[1];
                    if (dx * dx + dy * dy <= c[2] * c[2]) {
                        ++ans;
                        break;
                    }
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
    int countLatticePoints(vector<vector<int>>& circles) {
        int mx = 0, my = 0;
        for (auto& c : circles) {
            mx = max(mx, c[0] + c[2]);
            my = max(my, c[1] + c[2]);
        }
        int ans = 0;
        for (int i = 0; i <= mx; ++i) {
            for (int j = 0; j <= my; ++j) {
                for (auto& c : circles) {
                    int dx = i - c[0], dy = j - c[1];
                    if (dx * dx + dy * dy <= c[2] * c[2]) {
                        ++ans;
                        break;
                    }
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
func countLatticePoints(circles [][]int) (ans int) {
	mx, my := 0, 0
	for _, c := range circles {
		mx = max(mx, c[0]+c[2])
		my = max(my, c[1]+c[2])
	}
	for i := 0; i <= mx; i++ {
		for j := 0; j <= my; j++ {
			for _, c := range circles {
				dx, dy := i-c[0], j-c[1]
				if dx*dx+dy*dy <= c[2]*c[2] {
					ans++
					break
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countLatticePoints(circles: number[][]): number {
    let mx = 0;
    let my = 0;
    for (const [x, y, r] of circles) {
        mx = Math.max(mx, x + r);
        my = Math.max(my, y + r);
    }
    let ans = 0;
    for (let i = 0; i <= mx; ++i) {
        for (let j = 0; j <= my; ++j) {
            for (const [x, y, r] of circles) {
                const dx = i - x;
                const dy = j - y;
                if (dx * dx + dy * dy <= r * r) {
                    ++ans;
                    break;
                }
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

<p>给你一个二维整数数组 <code>circles</code> ，其中 <code>circles[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code> 表示网格上圆心为 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> 且半径为 <code>r<sub>i</sub></code> 的第 <code>i</code> 个圆，返回出现在<strong> 至少一个 </strong>圆内的 <strong>格点数目</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>格点</strong> 是指整数坐标对应的点。</li>
	<li><strong>圆周上的点</strong> 也被视为出现在圆内的点。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2249.Count%20Lattice%20Points%20Inside%20a%20Circle/images/exa-11.png" style="width: 300px; height: 300px;" /></p>

<pre>
<strong>输入：</strong>circles = [[2,2,1]]
<strong>输出：</strong>5
<strong>解释：</strong>
给定的圆如上图所示。
出现在圆内的格点为 (1, 2)、(2, 1)、(2, 2)、(2, 3) 和 (3, 2)，在图中用绿色标识。
像 (1, 1) 和 (1, 3) 这样用红色标识的点，并未出现在圆内。
因此，出现在至少一个圆内的格点数目是 5 。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2249.Count%20Lattice%20Points%20Inside%20a%20Circle/images/exa-22.png" style="width: 300px; height: 300px;" /></p>

<pre>
<strong>输入：</strong>circles = [[2,2,2],[3,4,1]]
<strong>输出：</strong>16
<strong>解释：</strong>
给定的圆如上图所示。
共有 16 个格点出现在至少一个圆内。
其中部分点的坐标是 (0, 2)、(2, 0)、(2, 4)、(3, 2) 和 (4, 4) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= circles.length &lt;= 200</code></li>
	<li><code>circles[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= min(x<sub>i</sub>, y<sub>i</sub>)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

枚举所有的格点，判断其是否在圆内，如果在圆内，则答案加一。

枚举的时候，可以将所有圆的最大横纵坐标求出来，作为枚举的上界。

时间复杂度 $O(X \times Y \times n)$，空间复杂度 $O(1)$。其中 $X$ 和 $Y$ 分别为所有圆的最大横纵坐标，而 $n$ 为圆的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        ans = 0
        mx = max(x + r for x, _, r in circles)
        my = max(y + r for _, y, r in circles)
        for i in range(mx + 1):
            for j in range(my + 1):
                for x, y, r in circles:
                    dx, dy = i - x, j - y
                    if dx * dx + dy * dy <= r * r:
                        ans += 1
                        break
        return ans
```

#### Java

```java
class Solution {
    public int countLatticePoints(int[][] circles) {
        int mx = 0, my = 0;
        for (var c : circles) {
            mx = Math.max(mx, c[0] + c[2]);
            my = Math.max(my, c[1] + c[2]);
        }
        int ans = 0;
        for (int i = 0; i <= mx; ++i) {
            for (int j = 0; j <= my; ++j) {
                for (var c : circles) {
                    int dx = i - c[0], dy = j - c[1];
                    if (dx * dx + dy * dy <= c[2] * c[2]) {
                        ++ans;
                        break;
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
    int countLatticePoints(vector<vector<int>>& circles) {
        int mx = 0, my = 0;
        for (auto& c : circles) {
            mx = max(mx, c[0] + c[2]);
            my = max(my, c[1] + c[2]);
        }
        int ans = 0;
        for (int i = 0; i <= mx; ++i) {
            for (int j = 0; j <= my; ++j) {
                for (auto& c : circles) {
                    int dx = i - c[0], dy = j - c[1];
                    if (dx * dx + dy * dy <= c[2] * c[2]) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countLatticePoints(circles [][]int) (ans int) {
	mx, my := 0, 0
	for _, c := range circles {
		mx = max(mx, c[0]+c[2])
		my = max(my, c[1]+c[2])
	}
	for i := 0; i <= mx; i++ {
		for j := 0; j <= my; j++ {
			for _, c := range circles {
				dx, dy := i-c[0], j-c[1]
				if dx*dx+dy*dy <= c[2]*c[2] {
					ans++
					break
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countLatticePoints(circles: number[][]): number {
    let mx = 0;
    let my = 0;
    for (const [x, y, r] of circles) {
        mx = Math.max(mx, x + r);
        my = Math.max(my, y + r);
    }
    let ans = 0;
    for (let i = 0; i <= mx; ++i) {
        for (let j = 0; j <= my; ++j) {
            for (const [x, y, r] of circles) {
                const dx = i - x;
                const dy = j - y;
                if (dx * dx + dy * dy <= r * r) {
                    ++ans;
                    break;
                }
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

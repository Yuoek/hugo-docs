---
title: "3021_AliceandBobPlayingFlowerGame"
date: 2025-10-06T00:42:37+08:00
weight: 3021
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3021. Alice 和 Bob 玩鲜花游戏](https://leetcode.cn/problems/alice-and-bob-playing-flower-game)

[English Version](../en/3021-21/3021_AliceandBobPlayingFlowerGame)

## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 在一片田野上玩一个回合制游戏，他们之间有两排花。Alice 和 Bob 之间第一排有 <code>x</code> 朵花，第二排有 <code>y</code> 朵花。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3021.Alice%20and%20Bob%20Playing%20Flower%20Game/images/3021.png" style="width: 300px; height: 150px;" /></p>

<p>游戏过程如下：</p>

<ol>
	<li>Alice 先行动。</li>
	<li>每一次行动中，当前玩家必须选择其中一排，然后在这边摘一朵鲜花。</li>
	<li>一次行动结束后，如果两排上都没有剩下鲜花，那么 <strong>当前</strong>&nbsp;玩家抓住对手并赢得游戏的胜利。</li>
</ol>

<p>给你两个整数&nbsp;<code>n</code>&nbsp;和&nbsp;<code>m</code>&nbsp;，你的任务是求出满足以下条件的所有&nbsp;<code>(x, y)</code>&nbsp;对：</p>

<ul>
	<li>按照上述规则，Alice 必须赢得游戏。</li>
	<li>第一排的鲜花数目&nbsp;<code>x</code>&nbsp;必须在区间&nbsp;<code>[1,n]</code>&nbsp;之间。</li>
	<li>第二排的鲜花数目 <code>y</code>&nbsp;必须在区间&nbsp;<code>[1,m]</code>&nbsp;之间。</li>
</ul>

<p>请你返回满足题目描述的数对&nbsp;<code>(x, y)</code>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 3, m = 2
<b>输出：</b>3
<b>解释：</b>以下数对满足题目要求：(1,2) ，(3,2) ，(2,1) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 1, m = 1
<b>输出：</b>0
<b>解释：</b>没有数对满足题目要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学

根据题目描述，每一次行动，玩家都会选择顺时针或者逆时针方向，然后摘一朵鲜花。由于 Alice 先行动，因此当 $x + y$ 为奇数时，Alice 一定会赢得游戏。

因此，鲜花数目 $x$ 和 $y$ 满足以下条件：

1. $x + y$ 为奇数；
2. $1 \le x \le n$；
3. $1 \le y \le m$。

若 $x$ 为奇数，$y$ 一定为偶数。此时 $x$ 的取值个数为 $\lceil \frac{n}{2} \rceil$，$y$ 的取值个数为 $\lfloor \frac{m}{2} \rfloor$，因此满足条件的数对个数为 $\lceil \frac{n}{2} \rceil \times \lfloor \frac{m}{2} \rfloor$。

若 $x$ 为偶数，$y$ 一定为奇数。此时 $x$ 的取值个数为 $\lfloor \frac{n}{2} \rfloor$，$y$ 的取值个数为 $\lceil \frac{m}{2} \rceil$，因此满足条件的数对个数为 $\lfloor \frac{n}{2} \rfloor \times \lceil \frac{m}{2} \rceil$。

因此，满足条件的数对个数为 $\lceil \frac{n}{2} \rceil \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lceil \frac{m}{2} \rceil$，即 $\lfloor \frac{n + 1}{2} \rfloor \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lfloor \frac{m + 1}{2} \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学（优化）

方法一得出的结果为 $\lfloor \frac{n + 1}{2} \rfloor \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lfloor \frac{m + 1}{2} \rfloor$。

如果 $n$ 和 $m$ 都是奇数，那么结果为 $\frac{n + 1}{2} \times \frac{m - 1}{2} + \frac{n - 1}{2} \times \frac{m + 1}{2}$，即 $\frac{n \times m - 1}{2}$。

如果 $n$ 和 $m$ 都是偶数，那么结果为 $\frac{n}{2} \times \frac{m}{2} + \frac{n}{2} \times \frac{m}{2}$，即 $\frac{n \times m}{2}$。

如果 $n$ 是奇数，且 $m$ 是偶数，那么结果为 $\frac{n + 1}{2} \times \frac{m}{2} + \frac{n - 1}{2} \times \frac{m}{2}$，即 $\frac{n \times m}{2}$。

如果 $n$ 是偶数，且 $m$ 是奇数，那么结果为 $\frac{n}{2} \times \frac{m - 1}{2} + \frac{n}{2} \times \frac{m + 1}{2}$，即 $\frac{n \times m}{2}$。

上面四种情况可以合并为 $\lfloor \frac{n \times m}{2} \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (n * m) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long flowerGame(int n, int m) {
        return ((long) n * m) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long) n * m) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func flowerGame(n int, m int) int64 {
	return int64((n * m) / 2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function flowerGame(n: number, m: number): number {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        (n as i64 * m as i64) / 2
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var flowerGame = function (n, m) {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (n * m) // 2
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public long flowerGame(int n, int m) {
        return ((long) n * m) / 2;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long) n * m) / 2;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
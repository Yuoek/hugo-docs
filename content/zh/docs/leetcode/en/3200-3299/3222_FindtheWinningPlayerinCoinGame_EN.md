---
title: "3222_FindtheWinningPlayerinCoinGame"
date: 2025-10-06T00:42:37+08:00
weight: 3222
tags: [Math, Game Theory, Simulation]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [3222. Find the Winning Player in Coin Game](https://leetcode.com/problems/find-the-winning-player-in-coin-game)

[中文文档](/solution/3200-3299/3222.Find%20the%20Winning%20Player%20in%20Coin%20Game/README.md)

## Description

<!-- description:start -->

<p>You are given two <strong>positive</strong> integers <code>x</code> and <code>y</code>, denoting the number of coins with values 75 and 10 <em>respectively</em>.</p>

<p>Alice and Bob are playing a game. Each turn, starting with <strong>Alice</strong>, the player must pick up coins with a <strong>total</strong> value 115. If the player is unable to do so, they <strong>lose</strong> the game.</p>

<p>Return the <em>name</em> of the player who wins the game if both players play <strong>optimally</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">x = 2, y = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;Alice&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>The game ends in a single turn:</p>

<ul>
	<li>Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">x = 4, y = 11</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;Bob&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>The game ends in 2 turns:</p>

<ul>
	<li>Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.</li>
	<li>Bob picks 1 coin with a value of 75 and 4 coins with a value of 10.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 100</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Mathematics

Since each round of operation consumes $2$ coins valued at $75$ and $8$ coins valued at $10$, we can calculate the number of rounds $k = \min(x / 2, y / 8)$, and then update the values of $x$ and $y$, where $x$ and $y$ are the remaining number of coins after $k$ rounds of operations.

If $x > 0$ and $y \geq 4$, then Alice can continue the operation, and Bob loses, return "Alice"; otherwise, return "Bob".

The time complexity is $O(1)$, and the space complexity is $O(1)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
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
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        k = min(x // 2, y // 8)
        x -= k * 2
        y -= k * 8
        return "Alice" if x and y >= 4 else "Bob"
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String losingPlayer(int x, int y) {
        int k = Math.min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x > 0 && y >= 4 ? "Alice" : "Bob";
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
    string losingPlayer(int x, int y) {
        int k = min(x / 2, y / 8);
        x -= k * 2;
        y -= k * 8;
        return x && y >= 4 ? "Alice" : "Bob";
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
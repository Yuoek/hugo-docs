---
title: "2139_MinimumMovestoReachTargetScore"
date: 2025-10-06T00:42:37+08:00
weight: 2139
tags: [Greedy, Math]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [2139. Minimum Moves to Reach Target Score](https://leetcode.com/problems/minimum-moves-to-reach-target-score)

[中文文档](/solution/2100-2199/2139.Minimum%20Moves%20to%20Reach%20Target%20Score/README.md)

## Description

<!-- description:start -->

<p>You are playing a game with integers. You start with the integer <code>1</code> and you want to reach the integer <code>target</code>.</p>

<p>In one move, you can either:</p>

<ul>
	<li><strong>Increment</strong> the current integer by one (i.e., <code>x = x + 1</code>).</li>
	<li><strong>Double</strong> the current integer (i.e., <code>x = 2 * x</code>).</li>
</ul>

<p>You can use the <strong>increment</strong> operation <strong>any</strong> number of times, however, you can only use the <strong>double</strong> operation <strong>at most</strong> <code>maxDoubles</code> times.</p>

<p>Given the two integers <code>target</code> and <code>maxDoubles</code>, return <em>the minimum number of moves needed to reach </em><code>target</code><em> starting with </em><code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = 5, maxDoubles = 0
<strong>Output:</strong> 4
<strong>Explanation:</strong> Keep incrementing by 1 until you reach target.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = 19, maxDoubles = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Initially, x = 1
Increment 3 times so x = 4
Double once so x = 8
Increment once so x = 9
Double again so x = 18
Increment once so x = 19
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = 10, maxDoubles = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong><b> </b>Initially, x = 1
Increment once so x = 2
Double once so x = 4
Increment once so x = 5
Double again so x = 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= maxDoubles &lt;= 100</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Backtracking + Greedy

Let's start by backtracking from the final state. Assuming the final state is $target$, we can get the previous state of $target$ as $target - 1$ or $target / 2$, depending on the parity of $target$ and the value of $maxDoubles$.

If $target=1$, no operation is needed, and we can return $0$ directly.

If $maxDoubles=0$, we can only use the increment operation, so we need $target-1$ operations.

If $target$ is even and $maxDoubles>0$, we can use the doubling operation, so we need $1$ operation, and then recursively solve $target/2$ and $maxDoubles-1$.

If $target$ is odd, we can only use the increment operation, so we need $1$ operation, and then recursively solve $target-1$ and $maxDoubles$.

The time complexity is $O(\min(\log target, maxDoubles))$, and the space complexity is $O(\min(\log target, maxDoubles))$.

We can also change the above process to an iterative way to avoid the space overhead of recursion.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

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
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        while maxDoubles and target > 1:
            ans += 1
            if target % 2 == 1:
                target -= 1
            else:
                maxDoubles -= 1
                target >>= 1
        ans += target - 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(target int, maxDoubles int) (ans int) {
	for maxDoubles > 0 && target > 1 {
		ans++
		if target&1 == 1 {
			target--
		} else {
			maxDoubles--
			target >>= 1
		}
	}
	ans += target - 1
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMoves(target: number, maxDoubles: number): number {
    let ans = 0;
    while (maxDoubles && target > 1) {
        ++ans;
        if (target & 1) {
            --target;
        } else {
            --maxDoubles;
            target >>= 1;
        }
    }
    ans += target - 1;
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        while maxDoubles and target > 1:
            ans += 1
            if target % 2 == 1:
                target -= 1
            else:
                maxDoubles -= 1
                target >>= 1
        ans += target - 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
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
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
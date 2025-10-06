---
title: "0294_FlipGameII"
date: 2025-10-06T00:42:37+08:00
weight: 0294
tags: [Memoization, Math, Dynamic Programming, Backtracking, Game Theory]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [294. Flip Game II 🔒](https://leetcode.com/problems/flip-game-ii)

[中文文档](/solution/0200-0299/0294.Flip%20Game%20II/README.md)

## Description

<!-- description:start -->

<p>You are playing a Flip Game with your friend.</p>

<p>You are given a string <code>currentState</code> that contains only <code>&#39;+&#39;</code> and <code>&#39;-&#39;</code>. You and your friend take turns to flip <strong>two consecutive</strong> <code>&quot;++&quot;</code> into <code>&quot;--&quot;</code>. The game ends when a person can no longer make a move, and therefore the other person will be the winner.</p>

<p>Return <code>true</code> <em>if the starting player can <strong>guarantee a win</strong></em>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> currentState = &quot;++++&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> The starting player can guarantee a win by flipping the middle &quot;++&quot; to become &quot;+--+&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> currentState = &quot;+&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= currentState.length &lt;= 60</code></li>
	<li><code>currentState[i]</code> is either <code>&#39;+&#39;</code> or <code>&#39;-&#39;</code>.</li>
	<li>There cannot be more than 20 consecutive <code>&#39;+&#39;</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Derive your algorithm&#39;s runtime complexity.

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def canWin(self, currentState: str) -> bool:
        def win(i):
            if sg[i] != -1:
                return sg[i]
            vis = [False] * n
            for j in range(i - 1):
                vis[win(j) ^ win(i - j - 2)] = True
            for j in range(n):
                if not vis[j]:
                    sg[i] = j
                    return j
            return 0

        n = len(currentState)
        sg = [-1] * (n + 1)
        sg[0] = sg[1] = 0
        ans = i = 0
        while i < n:
            j = i
            while j < n and currentState[j] == '+':
                j += 1
            ans ^= win(j - i)
            i = j + 1
        return ans > 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] sg;

    public boolean canWin(String currentState) {
        n = currentState.length();
        sg = new int[n + 1];
        Arrays.fill(sg, -1);
        int i = 0;
        int ans = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState.charAt(j) == '+') {
                ++j;
            }
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }

    private int win(int i) {
        if (sg[i] != -1) {
            return sg[i];
        }
        boolean[] vis = new boolean[n];
        for (int j = 0; j < i - 1; ++j) {
            vis[win(j) ^ win(i - j - 2)] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                return j;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        vector<int> sg(n + 1, -1);
        sg[0] = 0, sg[1] = 0;

        function<int(int)> win = [&](int i) {
            if (sg[i] != -1) return sg[i];
            vector<bool> vis(n);
            for (int j = 0; j < i - 1; ++j) vis[win(j) ^ win(i - j - 2)] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) return sg[i] = j;
            return 0;
        };

        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState[j] == '+') ++j;
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canWin(currentState string) bool {
	n := len(currentState)
	sg := make([]int, n+1)
	for i := range sg {
		sg[i] = -1
	}
	var win func(i int) int
	win = func(i int) int {
		if sg[i] != -1 {
			return sg[i]
		}
		vis := make([]bool, n)
		for j := 0; j < i-1; j++ {
			vis[win(j)^win(i-j-2)] = true
		}
		for j := 0; j < n; j++ {
			if !vis[j] {
				sg[i] = j
				return j
			}
		}
		return 0
	}
	ans, i := 0, 0
	for i < n {
		j := i
		for j < n && currentState[j] == '+' {
			j++
		}
		ans ^= win(j - i)
		i = j + 1
	}
	return ans > 0
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def canWin(self, currentState: str) -> bool:
        def win(i):
            if sg[i] != -1:
                return sg[i]
            vis = [False] * n
            for j in range(i - 1):
                vis[win(j) ^ win(i - j - 2)] = True
            for j in range(n):
                if not vis[j]:
                    sg[i] = j
                    return j
            return 0

        n = len(currentState)
        sg = [-1] * (n + 1)
        sg[0] = sg[1] = 0
        ans = i = 0
        while i < n:
            j = i
            while j < n and currentState[j] == '+':
                j += 1
            ans ^= win(j - i)
            i = j + 1
        return ans > 0
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private int n;
    private int[] sg;

    public boolean canWin(String currentState) {
        n = currentState.length();
        sg = new int[n + 1];
        Arrays.fill(sg, -1);
        int i = 0;
        int ans = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState.charAt(j) == '+') {
                ++j;
            }
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }

    private int win(int i) {
        if (sg[i] != -1) {
            return sg[i];
        }
        boolean[] vis = new boolean[n];
        for (int j = 0; j < i - 1; ++j) {
            vis[win(j) ^ win(i - j - 2)] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                return j;
            }
        }
        return 0;
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
    bool canWin(string currentState) {
        int n = currentState.size();
        vector<int> sg(n + 1, -1);
        sg[0] = 0, sg[1] = 0;

        function<int(int)> win = [&](int i) {
            if (sg[i] != -1) return sg[i];
            vector<bool> vis(n);
            for (int j = 0; j < i - 1; ++j) vis[win(j) ^ win(i - j - 2)] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) return sg[i] = j;
            return 0;
        };

        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState[j] == '+') ++j;
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
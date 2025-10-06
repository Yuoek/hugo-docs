---
title: "0830_PositionsofLargeGroups"
date: 2025-10-06T00:42:37+08:00
weight: 0830
tags: [String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [830. Positions of Large Groups](https://leetcode.com/problems/positions-of-large-groups)

[中文文档](/solution/0800-0899/0830.Positions%20of%20Large%20Groups/README.md)

## Description

<!-- description:start -->

<p>In a string <code><font face="monospace">s</font></code>&nbsp;of lowercase letters, these letters form consecutive groups of the same character.</p>

<p>For example, a string like <code>s = &quot;abbxxxxzyy&quot;</code> has the groups <code>&quot;a&quot;</code>, <code>&quot;bb&quot;</code>, <code>&quot;xxxx&quot;</code>, <code>&quot;z&quot;</code>, and&nbsp;<code>&quot;yy&quot;</code>.</p>

<p>A group is identified by an interval&nbsp;<code>[start, end]</code>, where&nbsp;<code>start</code>&nbsp;and&nbsp;<code>end</code>&nbsp;denote the start and end&nbsp;indices (inclusive) of the group. In the above example,&nbsp;<code>&quot;xxxx&quot;</code>&nbsp;has the interval&nbsp;<code>[3,6]</code>.</p>

<p>A group is considered&nbsp;<strong>large</strong>&nbsp;if it has 3 or more characters.</p>

<p>Return&nbsp;<em>the intervals of every <strong>large</strong> group sorted in&nbsp;<strong>increasing order by start index</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abbxxxxzzy&quot;
<strong>Output:</strong> [[3,6]]
<strong>Explanation:</strong> <code>&quot;xxxx&quot; is the only </code>large group with start index 3 and end index 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abc&quot;
<strong>Output:</strong> []
<strong>Explanation:</strong> We have groups &quot;a&quot;, &quot;b&quot;, and &quot;c&quot;, none of which are large groups.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdddeeeeaabbbcd&quot;
<strong>Output:</strong> [[3,5],[6,9],[12,14]]
<strong>Explanation:</strong> The large groups are &quot;ddd&quot;, &quot;eeee&quot;, and &quot;bbb&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> contains lowercase English letters only.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Two Pointers

We use two pointers $i$ and $j$ to find the start and end positions of each group, then check if the group length is greater than or equal to $3$. If so, we add it to the result array.

The time complexity is $O(n)$, where $n$ is the length of the string $s$.

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
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        i, n = 0, len(s)
        ans = []
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            if j - i >= 3:
                ans.append([i, j - 1])
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        int n = s.length();
        int i = 0;
        List<List<Integer>> ans = new ArrayList<>();
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if (j - i >= 3) {
                ans.add(List.of(i, j - 1));
            }
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
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largeGroupPositions(s string) [][]int {
	i, n := 0, len(s)
	ans := [][]int{}
	for i < n {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		if j-i >= 3 {
			ans = append(ans, []int{i, j - 1})
		}
		i = j
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largeGroupPositions(s: string): number[][] {
    const n = s.length;
    const ans: number[][] = [];

    for (let i = 0; i < n; ) {
        let j = i;
        while (j < n && s[j] === s[i]) {
            ++j;
        }
        if (j - i >= 3) {
            ans.push([i, j - 1]);
        }
        i = j;
    }

    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        i, n = 0, len(s)
        ans = []
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            if j - i >= 3:
                ans.append([i, j - 1])
            i = j
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        int n = s.length();
        int i = 0;
        List<List<Integer>> ans = new ArrayList<>();
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if (j - i >= 3) {
                ans.add(List.of(i, j - 1));
            }
            i = j;
        }
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
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
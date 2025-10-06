---
title: "1584_MinCosttoConnectAllPoints"
date: 2025-10-06T00:42:37+08:00
weight: 1584
tags: [Union Find, Graph, Array, Minimum Spanning Tree]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points)

[中文文档](/solution/1500-1599/1584.Min%20Cost%20to%20Connect%20All%20Points/README.md)

## Description

<!-- description:start -->

<p>You are given an array <code>points</code> representing integer coordinates of some points on a 2D-plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>The cost of connecting two points <code>[x<sub>i</sub>, y<sub>i</sub>]</code> and <code>[x<sub>j</sub>, y<sub>j</sub>]</code> is the <strong>manhattan distance</strong> between them: <code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>, where <code>|val|</code> denotes the absolute value of <code>val</code>.</p>

<p>Return <em>the minimum cost to make all points connected.</em> All points are connected if there is <strong>exactly one</strong> simple path between any two points.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1584.Min%20Cost%20to%20Connect%20All%20Points/images/d.png" style="width: 214px; height: 268px;" />
<pre>
<strong>Input:</strong> points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>Output:</strong> 20
<strong>Explanation:</strong> 
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1584.Min%20Cost%20to%20Connect%20All%20Points/images/c.png" style="width: 214px; height: 268px;" />
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> points = [[3,12],[-2,5],[-4,1]]
<strong>Output:</strong> 18
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are distinct.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

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



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(points)
        g = []
        for i, (x1, y1) in enumerate(points):
            for j in range(i + 1, n):
                x2, y2 = points[j]
                t = abs(x1 - x2) + abs(y1 - y2)
                g.append((t, i, j))
        p = list(range(n))
        ans = 0
        for cost, i, j in sorted(g):
            pa, pb = find(i), find(j)
            if pa == pb:
                continue
            p[pa] = pb
            ans += cost
            n -= 1
            if n == 1:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<int[]> g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.add(new int[] {Math.abs(x1 - x2) + Math.abs(y1 - y2), i, j});
            }
        }
        g.sort(Comparator.comparingInt(a -> a[0]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) {
                continue;
            }
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return 0;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> p;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> g;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        sort(g.begin(), g.end());
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int ans = 0;
        for (auto& e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) continue;
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) return ans;
        }
        return 0;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCostConnectPoints(points [][]int) int {
	n := len(points)
	var g [][]int
	for i, p := range points {
		x1, y1 := p[0], p[1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			g = append(g, []int{abs(x1-x2) + abs(y1-y2), i, j})
		}
	}
	sort.Slice(g, func(i, j int) bool {
		return g[i][0] < g[j][0]
	})
	ans := 0
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range g {
		cost, i, j := e[0], e[1], e[2]
		if find(i) == find(j) {
			continue
		}
		p[find(i)] = find(j)
		ans += cost
		n--
		if n == 1 {
			return ans
		}
	}
	return 0
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
function minCostConnectPoints(points: number[][]): number {
    const n = points.length;
    const g: number[][] = Array(n)
        .fill(0)
        .map(() => Array(n).fill(0));
    const dist: number[] = Array(n).fill(1 << 30);
    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        const [x1, y1] = points[i];
        for (let j = i + 1; j < n; ++j) {
            const [x2, y2] = points[j];
            const t = Math.abs(x1 - x2) + Math.abs(y1 - y2);
            g[i][j] = t;
            g[j][i] = t;
        }
    }
    let ans = 0;
    dist[0] = 0;
    for (let i = 0; i < n; ++i) {
        let j = -1;
        for (let k = 0; k < n; ++k) {
            if (!vis[k] && (j === -1 || dist[k] < dist[j])) {
                j = k;
            }
        }
        vis[j] = true;
        ans += dist[j];
        for (let k = 0; k < n; ++k) {
            if (!vis[k]) {
                dist[k] = Math.min(dist[k], g[j][k]);
            }
        }
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
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(points)
        g = []
        for i, (x1, y1) in enumerate(points):
            for j in range(i + 1, n):
                x2, y2 = points[j]
                t = abs(x1 - x2) + abs(y1 - y2)
                g.append((t, i, j))
        p = list(range(n))
        ans = 0
        for cost, i, j in sorted(g):
            pa, pb = find(i), find(j)
            if pa == pb:
                continue
            p[pa] = pb
            ans += cost
            n -= 1
            if n == 1:
                break
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private int[] p;

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<int[]> g = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.add(new int[] {Math.abs(x1 - x2) + Math.abs(y1 - y2), i, j});
            }
        }
        g.sort(Comparator.comparingInt(a -> a[0]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) {
                continue;
            }
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return 0;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
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
    vector<int> p;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> g;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                g.push_back({abs(x1 - x2) + abs(y1 - y2), i, j});
            }
        }
        sort(g.begin(), g.end());
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        int ans = 0;
        for (auto& e : g) {
            int cost = e[0], i = e[1], j = e[2];
            if (find(i) == find(j)) continue;
            p[find(i)] = find(j);
            ans += cost;
            if (--n == 1) return ans;
        }
        return 0;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
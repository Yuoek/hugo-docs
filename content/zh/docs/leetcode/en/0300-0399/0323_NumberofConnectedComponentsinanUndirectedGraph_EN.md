---
title: "0323_NumberofConnectedComponentsinanUndirectedGraph"
date: 2025-10-06T00:42:37+08:00
weight: 0323
tags: [Depth-First Search, Breadth-First Search, Union Find, Graph]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [323. Number of Connected Components in an Undirected Graph 🔒](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph)

[中文文档](/solution/0300-0399/0323.Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph/README.md)

## Description

<!-- description:start -->

<p>You have a graph of <code>n</code> nodes. You are given an integer <code>n</code> and an array <code>edges</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the graph.</p>

<p>Return <em>the number of connected components in the graph</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0323.Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph/images/conn1-graph.jpg" style="width: 382px; height: 222px;" />
<pre>
<strong>Input:</strong> n = 5, edges = [[0,1],[1,2],[3,4]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0323.Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph/images/conn2-graph.jpg" style="width: 382px; height: 222px;" />
<pre>
<strong>Input:</strong> n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>1 &lt;= edges.length &lt;= 5000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub> &lt;= b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: DFS

First, we construct an adjacency list $g$ based on the given edges, where $g[i]$ represents all neighbor nodes of node $i$.

Then we traverse all nodes. For each node, we use DFS to traverse all its adjacent nodes and mark them as visited until all its adjacent nodes have been visited. In this way, we have found a connected component, and the answer is incremented by one. Then we continue to traverse the next unvisited node until all nodes have been visited.

The time complexity is $O(n + m)$, and the space complexity is $O(n + m)$. Where $n$ and $m$ are the number of nodes and edges, respectively.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Union-Find

We can use a union-find set to maintain the connected components in the graph.

First, we initialize a union-find set, then traverse all the edges. For each edge $(a, b)$, we merge nodes $a$ and $b$ into the same connected component. If the merge is successful, it means that nodes $a$ and $b$ were not in the same connected component before, and the number of connected components decreases by one.

Finally, we return the number of connected components.

The time complexity is $O(n + m \times \alpha(n))$, and the space complexity is $O(n)$. Where $n$ and $m$ are the number of nodes and edges, respectively, and $\alpha(n)$ is the inverse of the Ackermann function, which can be regarded as a very small constant.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: BFS

We can also use BFS (Breadth-First Search) to count the number of connected components in the graph.

Similar to Solution 1, we first construct an adjacency list $g$ based on the given edges. Then we traverse all nodes. For each node, if it has not been visited, we start BFS traversal from this node, marking all its adjacent nodes as visited, until all its adjacent nodes have been visited. In this way, we have found a connected component, and the answer is incremented by one.

After traversing all nodes, we get the number of connected components in the graph.

The time complexity is $O(n + m)$, and the space complexity is $O(n + m)$. Where $n$ and $m$ are the number of nodes and edges, respectively.

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
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        ans = 0
        for i in range(n):
            if i in vis:
                continue
            vis.add(i)
            q = deque([i])
            while q:
                a = q.popleft()
                for b in g[a]:
                    if b not in vis:
                        vis.add(b)
                        q.append(b)
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countComponents(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            while (!q.isEmpty()) {
                int a = q.poll();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.offer(b);
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            queue<int> q{{i}};
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.push(b);
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
func countComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	for i := range g {
		if vis[i] {
			continue
		}
		vis[i] = true
		ans++
		q := []int{i}
		for len(q) > 0 {
			a := q[0]
			q = q[1:]
			for _, b := range g[a] {
				if !vis[b] {
					vis[b] = true
					q = append(q, b)
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
function countComponents(n: number, edges: number[][]): number {
    const g: Map<number, number[]> = new Map(Array.from({ length: n }, (_, i) => [i, []]));
    for (const [a, b] of edges) {
        g.get(a)!.push(b);
        g.get(b)!.push(a);
    }

    const vis = new Set<number>();
    let ans = 0;
    for (const [i] of g) {
        if (vis.has(i)) {
            continue;
        }
        const q = [i];
        for (const j of q) {
            if (vis.has(j)) {
                continue;
            }
            vis.add(j);
            q.push(...g.get(j)!);
        }
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countComponents = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis = Array(n).fill(false);
    const dfs = i => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        for (const j of g[i]) {
            dfs(j);
        }
        return 1;
    };
    return g.reduce((acc, _, i) => acc + dfs(i), 0);
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        ans = 0
        for i in range(n):
            if i in vis:
                continue
            vis.add(i)
            q = deque([i])
            while q:
                a = q.popleft()
                for b in g[a]:
                    if b not in vis:
                        vis.add(b)
                        q.append(b)
            ans += 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countComponents(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            while (!q.isEmpty()) {
                int a = q.poll();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.offer(b);
                    }
                }
            }
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            queue<int> q{{i}};
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.push(b);
                    }
                }
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
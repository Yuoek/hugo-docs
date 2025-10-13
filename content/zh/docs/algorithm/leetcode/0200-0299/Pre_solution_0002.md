---
title: "0210_课程表 II"
date: 2025-10-08T18:35:28+08:00
weight: 2
tags: [分治, 动态规划, 哈希函数, 哈希表, 回溯, 图, 堆（优先队列）, 字典树, 字符串, 字符串匹配, 广度优先搜索, 快速选择, 扫描线, 拓扑排序, 排序, 数组, 有序集合, 树状数组, 深度优先搜索, 滑动窗口, 滚动哈希, 矩阵, 线段树, 设计]
---

{{< markmap >}}
### [0210_课程表 II](#210)
#### [深度优先搜索](#210)
#### [广度优先搜索](#210)
#### [图](#210)
#### [拓扑排序](#210)
### [0211_添加与搜索单词 - 数据结构设计](#211)
#### [深度优先搜索](#211)
#### [设计](#211)
#### [字典树](#211)
#### [字符串](#211)
### [0212_单词搜索 II](#212)
#### [字典树](#212)
#### [数组](#212)
#### [字符串](#212)
#### [回溯](#212)
#### [矩阵](#212)
### [0213_打家劫舍 II](#213)
#### [数组](#213)
#### [动态规划](#213)
### [0214_最短回文串](#214)
#### [字符串](#214)
#### [字符串匹配](#214)
#### [哈希函数](#214)
#### [滚动哈希](#214)
### [0215_数组中的第K个最大元素](#215)
#### [数组](#215)
#### [分治](#215)
#### [快速选择](#215)
#### [排序](#215)
#### [堆（优先队列）](#215)
### [0216_组合总和 III](#216)
#### [数组](#216)
#### [回溯](#216)
### [0217_存在重复元素](#217)
#### [数组](#217)
#### [哈希表](#217)
#### [排序](#217)
### [0218_天际线问题](#218)
#### [树状数组](#218)
#### [线段树](#218)
#### [数组](#218)
#### [分治](#218)
#### [有序集合](#218)
#### [扫描线](#218)
#### [堆（优先队列）](#218)
### [0219_存在重复元素 II](#219)
#### [数组](#219)
#### [哈希表](#219)
#### [滑动窗口](#219)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0210_课程表 II
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 0211_添加与搜索单词 - 数据结构设计
___
#### 深度优先搜索
___
#### 设计
___
#### 字典树
___
#### 字符串
---
### 0212_单词搜索 II
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 回溯
___
#### 矩阵
---
### 0213_打家劫舍 II
___
#### 数组
___
#### 动态规划
---
### 0214_最短回文串
___
#### 字符串
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 0215_数组中的第K个最大元素
___
#### 数组
___
#### 分治
___
#### 快速选择
___
#### 排序
___
#### 堆（优先队列）
---
### 0216_组合总和 III
___
#### 数组
___
#### 回溯
---
### 0217_存在重复元素
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 0218_天际线问题
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 分治
___
#### 有序集合
___
#### 扫描线
___
#### 堆（优先队列）
---
### 0219_存在重复元素 II
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 分治 | 动态规划 | 哈希函数 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字典树 | 字符串 |
| 字符串匹配 | 广度优先搜索 | 快速选择 |
| 扫描线 | 拓扑排序 | 排序 |
| 数组 | 有序集合 | 树状数组 |
| 深度优先搜索 | 滑动窗口 | 滚动哈希 |
| 矩阵 | 线段树 | 设计 |

# [210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii){#210}

{{< tabs "210" >}}

{{% tab "python" %}}
```python
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        indeg = [0] * numCourses
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1
        ans = []
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while q:
            i = q.popleft()
            ans.append(i)
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return ans if len(ans) == numCourses else []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] g = new List[numCourses];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[numCourses];
        for (var p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].add(a);
            ++indeg[a];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int[] ans = new int[numCourses];
        int cnt = 0;
        while (!q.isEmpty()) {
            int i = q.poll();
            ans[cnt++] = i;
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return cnt == numCourses ? ans : new int[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            ++indeg[a];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findOrder(numCourses int, prerequisites [][]int) []int {
	g := make([][]int, numCourses)
	indeg := make([]int, numCourses)
	for _, p := range prerequisites {
		a, b := p[0], p[1]
		g[b] = append(g[b], a)
		indeg[a]++
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	ans := []int{}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		ans = append(ans, i)
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	if len(ans) == numCourses {
		return ans
	}
	return []int{}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    const g: number[][] = Array.from({ length: numCourses }, () => []);
    const indeg: number[] = new Array(numCourses).fill(0);
    for (const [a, b] of prerequisites) {
        g[b].push(a);
        indeg[a]++;
    }
    const q: number[] = [];
    for (let i = 0; i < numCourses; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    const ans: number[] = [];
    while (q.length) {
        const i = q.shift()!;
        ans.push(i);
        for (const j of g[i]) {
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return ans.length === numCourses ? ans : [];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let n = num_courses as usize;
        let mut adjacency = vec![vec![]; n];
        let mut entry = vec![0; n];
        // init
        for iter in prerequisites.iter() {
            let (a, b) = (iter[0], iter[1]);
            adjacency[b as usize].push(a);
            entry[a as usize] += 1;
        }
        // construct deque & reslut
        let mut deque = std::collections::VecDeque::new();
        for index in 0..n {
            if entry[index] == 0 {
                deque.push_back(index);
            }
        }
        let mut result = vec![];
        // bfs
        while !deque.is_empty() {
            let head = deque.pop_front().unwrap();
            result.push(head as i32);
            // update degree of entry
            for &out_entry in adjacency[head].iter() {
                entry[out_entry as usize] -= 1;
                if entry[out_entry as usize] == 0 {
                    deque.push_back(out_entry as usize);
                }
            }
        }
        if result.len() == n {
            result
        } else {
            vec![]
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        var g = new List<int>[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            g[i] = new List<int>();
        }
        var indeg = new int[numCourses];
        foreach (var p in prerequisites) {
            int a = p[0], b = p[1];
            g[b].Add(a);
            ++indeg[a];
        }
        var q = new Queue<int>();
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.Enqueue(i);
            }
        }
        var ans = new int[numCourses];
        var cnt = 0;
        while (q.Count > 0) {
            int i = q.Dequeue();
            ans[cnt++] = i;
            foreach (int j in g[i]) {
                if (--indeg[j] == 0) {
                    q.Enqueue(j);
                }
            }
        }
        return cnt == numCourses ? ans : new int[0];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现在你总共有 <code>numCourses</code> 门课需要选，记为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>numCourses - 1</code>。给你一个数组&nbsp;<code>prerequisites</code> ，其中 <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> ，表示在选修课程 <code>a<sub>i</sub></code> 前 <strong>必须</strong> 先选修&nbsp;<code>b<sub>i</sub></code> 。</p>

<ul>
	<li>例如，想要学习课程 <code>0</code> ，你需要先完成课程&nbsp;<code>1</code> ，我们用一个匹配来表示：<code>[0,1]</code> 。</li>
</ul>

<p>返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 <strong>任意一种</strong> 就可以了。如果不可能完成所有课程，返回 <strong>一个空数组</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 2, prerequisites = [[1,0]]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 <code>[0,1] 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
<strong>输出：</strong>[0,2,1,3]
<strong>解释：</strong>总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是&nbsp;<code>[0,1,2,3]</code> 。另一个正确的排序是&nbsp;<code>[0,2,1,3]</code> 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>numCourses = 1, prerequisites = []
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>所有<code>[a<sub>i</sub>, b<sub>i</sub>]</code> <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们创建一个邻接表 $g$，用于存储每个节点的后继节点，同时还需要一个数组 $indeg$ 存储每个节点的入度。在构建邻接表的同时，我们也统计每个节点的入度。当入度为 $0$ 的节点代表没有任何前置课程，可以直接学习，我们将其加入队列 $q$ 中。

当队列 $q$ 不为空的时候，我们取出队首的节点 $i$：

-   我们将 $i$ 放入答案中；
-   接下来，我们将 $i$ 的所有后继节点的入度减少 $1$。如果发现某个后继节点 $j$ 的入度变为 $0$，则将 $j$ 放入队列 $q$ 中。

在广度优先搜索的结束时，如果答案中包含了这 $n$ 个节点，那么我们就找到了一种拓扑排序，否则说明图中存在环，也就不存在拓扑排序了。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        indeg = [0] * numCourses
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1
        ans = []
        q = deque(i for i, x in enumerate(indeg) if x == 0)
        while q:
            i = q.popleft()
            ans.append(i)
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return ans if len(ans) == numCourses else []
```

#### Java

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] g = new List[numCourses];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[numCourses];
        for (var p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].add(a);
            ++indeg[a];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int[] ans = new int[numCourses];
        int cnt = 0;
        while (!q.isEmpty()) {
            int i = q.poll();
            ans[cnt++] = i;
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        return cnt == numCourses ? ans : new int[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            g[b].push_back(a);
            ++indeg[a];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};
```

#### Go

```go
func findOrder(numCourses int, prerequisites [][]int) []int {
	g := make([][]int, numCourses)
	indeg := make([]int, numCourses)
	for _, p := range prerequisites {
		a, b := p[0], p[1]
		g[b] = append(g[b], a)
		indeg[a]++
	}
	q := []int{}
	for i, x := range indeg {
		if x == 0 {
			q = append(q, i)
		}
	}
	ans := []int{}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		ans = append(ans, i)
		for _, j := range g[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	if len(ans) == numCourses {
		return ans
	}
	return []int{}
}
```

#### TypeScript

```ts
function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    const g: number[][] = Array.from({ length: numCourses }, () => []);
    const indeg: number[] = new Array(numCourses).fill(0);
    for (const [a, b] of prerequisites) {
        g[b].push(a);
        indeg[a]++;
    }
    const q: number[] = [];
    for (let i = 0; i < numCourses; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    const ans: number[] = [];
    while (q.length) {
        const i = q.shift()!;
        ans.push(i);
        for (const j of g[i]) {
            if (--indeg[j] === 0) {
                q.push(j);
            }
        }
    }
    return ans.length === numCourses ? ans : [];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let n = num_courses as usize;
        let mut adjacency = vec![vec![]; n];
        let mut entry = vec![0; n];
        // init
        for iter in prerequisites.iter() {
            let (a, b) = (iter[0], iter[1]);
            adjacency[b as usize].push(a);
            entry[a as usize] += 1;
        }
        // construct deque & reslut
        let mut deque = std::collections::VecDeque::new();
        for index in 0..n {
            if entry[index] == 0 {
                deque.push_back(index);
            }
        }
        let mut result = vec![];
        // bfs
        while !deque.is_empty() {
            let head = deque.pop_front().unwrap();
            result.push(head as i32);
            // update degree of entry
            for &out_entry in adjacency[head].iter() {
                entry[out_entry as usize] -= 1;
                if entry[out_entry as usize] == 0 {
                    deque.push_back(out_entry as usize);
                }
            }
        }
        if result.len() == n {
            result
        } else {
            vec![]
        }
    }
}
```

#### C#

```cs
public class Solution {
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        var g = new List<int>[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            g[i] = new List<int>();
        }
        var indeg = new int[numCourses];
        foreach (var p in prerequisites) {
            int a = p[0], b = p[1];
            g[b].Add(a);
            ++indeg[a];
        }
        var q = new Queue<int>();
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.Enqueue(i);
            }
        }
        var ans = new int[numCourses];
        var cnt = 0;
        while (q.Count > 0) {
            int i = q.Dequeue();
            ans[cnt++] = i;
            foreach (int j in g[i]) {
                if (--indeg[j] == 0) {
                    q.Enqueue(j);
                }
            }
        }
        return cnt == numCourses ? ans : new int[0];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [211. 添加与搜索单词 - 数据结构设计](https://leetcode.cn/problems/design-add-and-search-words-data-structure){#211}

{{< tabs "211" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False


class WordDictionary:
    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        node = self.trie
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word: str) -> bool:
        def search(word, node):
            for i in range(len(word)):
                c = word[i]
                idx = ord(c) - ord('a')
                if c != '.' and node.children[idx] is None:
                    return False
                if c == '.':
                    for child in node.children:
                        if child is not None and search(word[i + 1 :], child):
                            return True
                    return False
                node = node.children[idx]
            return node.is_end

        return search(word, self.trie)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;
}

class WordDictionary {
    private Trie trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new Trie();
    }

    public void addWord(String word) {
        Trie node = trie;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String word) {
        return search(word, trie);
    }

    private boolean search(String word, Trie node) {
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            int idx = c - 'a';
            if (c != '.' && node.children[idx] == null) {
                return false;
            }
            if (c == '.') {
                for (Trie child : node.children) {
                    if (child != null && search(word.substring(i + 1), child)) {
                        return true;
                    }
                }
                return false;
            }
            node = node.children[idx];
        }
        return node.isEnd;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class trie {
public:
    vector<trie*> children;
    bool is_end;

    trie() {
        children = vector<trie*>(26, nullptr);
        is_end = false;
    }

    void insert(const string& word) {
        trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) {
                cur->children[c] = new trie;
            }
            cur = cur->children[c];
        }
        cur->is_end = true;
    }
};

class WordDictionary {
private:
    trie* root;

public:
    WordDictionary()
        : root(new trie) {}

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int i, trie* cur) {
        if (i == word.size()) {
            return cur->is_end;
        }
        char c = word[i];
        if (c != '.') {
            trie* child = cur->children[c - 'a'];
            if (child != nullptr && dfs(word, i + 1, child)) {
                return true;
            }
        } else {
            for (trie* child : cur->children) {
                if (child != nullptr && dfs(word, i + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type WordDictionary struct {
	root *trie
}

func Constructor() WordDictionary {
	return WordDictionary{new(trie)}
}

func (this *WordDictionary) AddWord(word string) {
	this.root.insert(word)
}

func (this *WordDictionary) Search(word string) bool {
	n := len(word)

	var dfs func(int, *trie) bool
	dfs = func(i int, cur *trie) bool {
		if i == n {
			return cur.isEnd
		}
		c := word[i]
		if c != '.' {
			child := cur.children[c-'a']
			if child != nil && dfs(i+1, child) {
				return true
			}
		} else {
			for _, child := range cur.children {
				if child != nil && dfs(i+1, child) {
					return true
				}
			}
		}
		return false
	}

	return dfs(0, this.root)
}

type trie struct {
	children [26]*trie
	isEnd    bool
}

func (t *trie) insert(word string) {
	cur := t
	for _, c := range word {
		c -= 'a'
		if cur.children[c] == nil {
			cur.children[c] = new(trie)
		}
		cur = cur.children[c]
	}
	cur.isEnd = true
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Collections.Generic;
using System.Linq;

class TrieNode {
    public bool IsEnd { get; set; }
    public TrieNode[] Children { get; set; }
    public TrieNode() {
        Children = new TrieNode[26];
    }
}

public class WordDictionary {
    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void AddWord(string word) {
        var node = root;
        for (var i = 0; i < word.Length; ++i)
        {
            TrieNode nextNode;
            var index = word[i] - 'a';
            nextNode = node.Children[index];
            if (nextNode == null)
            {
                nextNode = new TrieNode();
                node.Children[index] = nextNode;
            }
            node = nextNode;
        }
        node.IsEnd = true;
    }

    public bool Search(string word) {
        var queue = new Queue<TrieNode>();
        queue.Enqueue(root);
        for (var i = 0; i < word.Length; ++i)
        {
            var count = queue.Count;
            while (count-- > 0)
            {
                var node = queue.Dequeue();
                if (word[i] == '.')
                {
                    foreach (var nextNode in node.Children)
                    {
                        if (nextNode != null)
                        {
                            queue.Enqueue(nextNode);
                        }
                    }
                }
                else
                {
                    var nextNode = node.Children[word[i] - 'a'];
                    if (nextNode != null)
                    {
                        queue.Enqueue(nextNode);
                    }
                }
            }
        }
        return queue.Any(n => n.IsEnd);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。</p>

<p>实现词典类 <code>WordDictionary</code> ：</p>

<ul>
	<li><code>WordDictionary()</code> 初始化词典对象</li>
	<li><code>void addWord(word)</code> 将 <code>word</code> 添加到数据结构中，之后可以对它进行匹配</li>
	<li><code>bool search(word)</code> 如果数据结构中存在字符串与&nbsp;<code>word</code> 匹配，则返回 <code>true</code> ；否则，返回&nbsp; <code>false</code> 。<code>word</code> 中可能包含一些 <code>'.'</code> ，每个&nbsp;<code>.</code> 都可以表示任何一个字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
<strong>输出：</strong>
[null,null,null,null,false,true,true,true]

<strong>解释：</strong>
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // 返回 False
wordDictionary.search("bad"); // 返回 True
wordDictionary.search(".ad"); // 返回 True
wordDictionary.search("b.."); // 返回 True
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 25</code></li>
	<li><code>addWord</code> 中的 <code>word</code> 由小写英文字母组成</li>
	<li><code>search</code> 中的 <code>word</code> 由 '.' 或小写英文字母组成</li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>addWord</code> 和 <code>search</code></li>
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
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False


class WordDictionary:
    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        node = self.trie
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word: str) -> bool:
        def search(word, node):
            for i in range(len(word)):
                c = word[i]
                idx = ord(c) - ord('a')
                if c != '.' and node.children[idx] is None:
                    return False
                if c == '.':
                    for child in node.children:
                        if child is not None and search(word[i + 1 :], child):
                            return True
                    return False
                node = node.children[idx]
            return node.is_end

        return search(word, self.trie)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;
}

class WordDictionary {
    private Trie trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new Trie();
    }

    public void addWord(String word) {
        Trie node = trie;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String word) {
        return search(word, trie);
    }

    private boolean search(String word, Trie node) {
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            int idx = c - 'a';
            if (c != '.' && node.children[idx] == null) {
                return false;
            }
            if (c == '.') {
                for (Trie child : node.children) {
                    if (child != null && search(word.substring(i + 1), child)) {
                        return true;
                    }
                }
                return false;
            }
            node = node.children[idx];
        }
        return node.isEnd;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
```

#### C++

```cpp
class trie {
public:
    vector<trie*> children;
    bool is_end;

    trie() {
        children = vector<trie*>(26, nullptr);
        is_end = false;
    }

    void insert(const string& word) {
        trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) {
                cur->children[c] = new trie;
            }
            cur = cur->children[c];
        }
        cur->is_end = true;
    }
};

class WordDictionary {
private:
    trie* root;

public:
    WordDictionary()
        : root(new trie) {}

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int i, trie* cur) {
        if (i == word.size()) {
            return cur->is_end;
        }
        char c = word[i];
        if (c != '.') {
            trie* child = cur->children[c - 'a'];
            if (child != nullptr && dfs(word, i + 1, child)) {
                return true;
            }
        } else {
            for (trie* child : cur->children) {
                if (child != nullptr && dfs(word, i + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

#### Go

```go
type WordDictionary struct {
	root *trie
}

func Constructor() WordDictionary {
	return WordDictionary{new(trie)}
}

func (this *WordDictionary) AddWord(word string) {
	this.root.insert(word)
}

func (this *WordDictionary) Search(word string) bool {
	n := len(word)

	var dfs func(int, *trie) bool
	dfs = func(i int, cur *trie) bool {
		if i == n {
			return cur.isEnd
		}
		c := word[i]
		if c != '.' {
			child := cur.children[c-'a']
			if child != nil && dfs(i+1, child) {
				return true
			}
		} else {
			for _, child := range cur.children {
				if child != nil && dfs(i+1, child) {
					return true
				}
			}
		}
		return false
	}

	return dfs(0, this.root)
}

type trie struct {
	children [26]*trie
	isEnd    bool
}

func (t *trie) insert(word string) {
	cur := t
	for _, c := range word {
		c -= 'a'
		if cur.children[c] == nil {
			cur.children[c] = new(trie)
		}
		cur = cur.children[c]
	}
	cur.isEnd = true
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
```

#### C#

```cs
using System.Collections.Generic;
using System.Linq;

class TrieNode {
    public bool IsEnd { get; set; }
    public TrieNode[] Children { get; set; }
    public TrieNode() {
        Children = new TrieNode[26];
    }
}

public class WordDictionary {
    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void AddWord(string word) {
        var node = root;
        for (var i = 0; i < word.Length; ++i)
        {
            TrieNode nextNode;
            var index = word[i] - 'a';
            nextNode = node.Children[index];
            if (nextNode == null)
            {
                nextNode = new TrieNode();
                node.Children[index] = nextNode;
            }
            node = nextNode;
        }
        node.IsEnd = true;
    }

    public bool Search(string word) {
        var queue = new Queue<TrieNode>();
        queue.Enqueue(root);
        for (var i = 0; i < word.Length; ++i)
        {
            var count = queue.Count;
            while (count-- > 0)
            {
                var node = queue.Dequeue();
                if (word[i] == '.')
                {
                    foreach (var nextNode in node.Children)
                    {
                        if (nextNode != null)
                        {
                            queue.Enqueue(nextNode);
                        }
                    }
                }
                else
                {
                    var nextNode = node.Children[word[i] - 'a'];
                    if (nextNode != null)
                    {
                        queue.Enqueue(nextNode);
                    }
                }
            }
        }
        return queue.Any(n => n.IsEnd);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [212. 单词搜索 II](https://leetcode.cn/problems/word-search-ii){#212}

{{< tabs "212" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, ref: int):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = ref


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(node: Trie, i: int, j: int):
            idx = ord(board[i][j]) - ord('a')
            if node.children[idx] is None:
                return
            node = node.children[idx]
            if node.ref >= 0:
                ans.append(words[node.ref])
                node.ref = -1
            c = board[i][j]
            board[i][j] = '#'
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and board[x][y] != '#':
                    dfs(node, x, y)
            board[i][j] = c

        tree = Trie()
        for i, w in enumerate(words):
            tree.insert(w, i)
        m, n = len(board), len(board[0])
        ans = []
        for i in range(m):
            for j in range(n):
                dfs(tree, i, j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    int ref = -1;

    public void insert(String w, int ref) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
        node.ref = ref;
    }
}

class Solution {
    private char[][] board;
    private String[] words;
    private List<String> ans = new ArrayList<>();

    public List<String> findWords(char[][] board, String[] words) {
        this.board = board;
        this.words = words;
        Trie tree = new Trie();
        for (int i = 0; i < words.length; ++i) {
            tree.insert(words[i], i);
        }
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(tree, i, j);
            }
        }
        return ans;
    }

    private void dfs(Trie node, int i, int j) {
        int idx = board[i][j] - 'a';
        if (node.children[idx] == null) {
            return;
        }
        node = node.children[idx];
        if (node.ref != -1) {
            ans.add(words[node.ref]);
            node.ref = -1;
        }
        char c = board[i][j];
        board[i][j] = '#';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < board.length && y >= 0 && y < board[0].length && board[x][y] != '#') {
                dfs(node, x, y);
            }
        }
        board[i][j] = c;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    int ref;

    Trie()
        : children(26, nullptr)
        , ref(-1) {}

    void insert(const string& w, int ref) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->ref = ref;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tree = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            tree->insert(words[i], i);
        }
        vector<string> ans;
        int m = board.size(), n = board[0].size();

        function<void(Trie*, int, int)> dfs = [&](Trie* node, int i, int j) {
            int idx = board[i][j] - 'a';
            if (!node->children[idx]) {
                return;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                ans.emplace_back(words[node->ref]);
                node->ref = -1;
            }
            int dirs[5] = {-1, 0, 1, 0, -1};
            char c = board[i][j];
            board[i][j] = '#';
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                    dfs(node, x, y);
                }
            }
            board[i][j] = c;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(tree, i, j);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	ref      int
}

func newTrie() *Trie {
	return &Trie{ref: -1}
}
func (this *Trie) insert(w string, ref int) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.ref = ref
}

func findWords(board [][]byte, words []string) (ans []string) {
	trie := newTrie()
	for i, w := range words {
		trie.insert(w, i)
	}
	m, n := len(board), len(board[0])
	var dfs func(*Trie, int, int)
	dfs = func(node *Trie, i, j int) {
		idx := board[i][j] - 'a'
		if node.children[idx] == nil {
			return
		}
		node = node.children[idx]
		if node.ref != -1 {
			ans = append(ans, words[node.ref])
			node.ref = -1
		}
		c := board[i][j]
		board[i][j] = '#'
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#' {
				dfs(node, x, y)
			}
		}
		board[i][j] = c
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			dfs(trie, i, j)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: Trie[];
    ref: number;

    constructor() {
        this.children = new Array(26);
        this.ref = -1;
    }

    insert(w: string, ref: number): void {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const c = w.charCodeAt(i) - 97;
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.ref = ref;
    }
}

function findWords(board: string[][], words: string[]): string[] {
    const tree = new Trie();
    for (let i = 0; i < words.length; ++i) {
        tree.insert(words[i], i);
    }
    const m = board.length;
    const n = board[0].length;
    const ans: string[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (node: Trie, i: number, j: number) => {
        const idx = board[i][j].charCodeAt(0) - 97;
        if (node.children[idx] == null) {
            return;
        }
        node = node.children[idx];
        if (node.ref != -1) {
            ans.push(words[node.ref]);
            node.ref = -1;
        }
        const c = board[i][j];
        board[i][j] = '#';
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                dfs(node, x, y);
            }
        }
        board[i][j] = c;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            dfs(tree, i, j);
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

<p>给定一个&nbsp;<code>m x n</code> 二维字符网格&nbsp;<code>board</code><strong>&nbsp;</strong>和一个单词（字符串）列表 <code>words</code>，&nbsp;<em>返回所有二维网格上的单词</em>&nbsp;。</p>

<p>单词必须按照字母顺序，通过 <strong>相邻的单元格</strong> 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0212.Word%20Search%20II/images/search1.jpg" />
<pre>
<strong>输入：</strong>board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
<strong>输出：</strong>["eat","oath"]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0212.Word%20Search%20II/images/search2.jpg" />
<pre>
<strong>输入：</strong>board = [["a","b"],["c","d"]], words = ["abcb"]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 12</code></li>
	<li><code>board[i][j]</code> 是一个小写英文字母</li>
	<li><code>1 &lt;= words.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
	<li><code>words</code> 中的所有字符串互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + DFS

我们首先将 `words` 中的单词构建成前缀树，前缀树的每个节点包含一个长度为 $26$ 的数组 `children`，表示该节点的子节点，数组的下标表示子节点对应的字符，数组的值表示子节点的引用。同时，每个节点还包含一个整数 `ref`，表示该节点对应的单词在 `words` 中的引用，如果该节点不是单词的结尾，则 `ref` 的值为 $-1$。

接下来，我们对于 `board` 中的每个单元格，从该单元格出发，进行深度优先搜索，搜索过程中，如果当前单词不是前缀树中的单词，则剪枝，如果当前单词是前缀树中的单词，则将该单词加入答案，并将该单词在前缀树中的引用置为 $-1$，表示该单词已经被找到，不需要再次搜索。

最后，我们将答案返回即可。

时间复杂度 $(m \times n \times 3^{l-1})$，空间复杂度 $(k \times l)$。其中 $m$ 和 $n$ 分别是 `board` 的行数和列数。而 $l$ 和 $k$ 分别是 `words` 中的单词的平均长度和单词的个数。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, ref: int):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = ref


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(node: Trie, i: int, j: int):
            idx = ord(board[i][j]) - ord('a')
            if node.children[idx] is None:
                return
            node = node.children[idx]
            if node.ref >= 0:
                ans.append(words[node.ref])
                node.ref = -1
            c = board[i][j]
            board[i][j] = '#'
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and board[x][y] != '#':
                    dfs(node, x, y)
            board[i][j] = c

        tree = Trie()
        for i, w in enumerate(words):
            tree.insert(w, i)
        m, n = len(board), len(board[0])
        ans = []
        for i in range(m):
            for j in range(n):
                dfs(tree, i, j)
        return ans
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    int ref = -1;

    public void insert(String w, int ref) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
        node.ref = ref;
    }
}

class Solution {
    private char[][] board;
    private String[] words;
    private List<String> ans = new ArrayList<>();

    public List<String> findWords(char[][] board, String[] words) {
        this.board = board;
        this.words = words;
        Trie tree = new Trie();
        for (int i = 0; i < words.length; ++i) {
            tree.insert(words[i], i);
        }
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(tree, i, j);
            }
        }
        return ans;
    }

    private void dfs(Trie node, int i, int j) {
        int idx = board[i][j] - 'a';
        if (node.children[idx] == null) {
            return;
        }
        node = node.children[idx];
        if (node.ref != -1) {
            ans.add(words[node.ref]);
            node.ref = -1;
        }
        char c = board[i][j];
        board[i][j] = '#';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < board.length && y >= 0 && y < board[0].length && board[x][y] != '#') {
                dfs(node, x, y);
            }
        }
        board[i][j] = c;
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    int ref;

    Trie()
        : children(26, nullptr)
        , ref(-1) {}

    void insert(const string& w, int ref) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->ref = ref;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tree = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            tree->insert(words[i], i);
        }
        vector<string> ans;
        int m = board.size(), n = board[0].size();

        function<void(Trie*, int, int)> dfs = [&](Trie* node, int i, int j) {
            int idx = board[i][j] - 'a';
            if (!node->children[idx]) {
                return;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                ans.emplace_back(words[node->ref]);
                node->ref = -1;
            }
            int dirs[5] = {-1, 0, 1, 0, -1};
            char c = board[i][j];
            board[i][j] = '#';
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                    dfs(node, x, y);
                }
            }
            board[i][j] = c;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(tree, i, j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	ref      int
}

func newTrie() *Trie {
	return &Trie{ref: -1}
}
func (this *Trie) insert(w string, ref int) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.ref = ref
}

func findWords(board [][]byte, words []string) (ans []string) {
	trie := newTrie()
	for i, w := range words {
		trie.insert(w, i)
	}
	m, n := len(board), len(board[0])
	var dfs func(*Trie, int, int)
	dfs = func(node *Trie, i, j int) {
		idx := board[i][j] - 'a'
		if node.children[idx] == nil {
			return
		}
		node = node.children[idx]
		if node.ref != -1 {
			ans = append(ans, words[node.ref])
			node.ref = -1
		}
		c := board[i][j]
		board[i][j] = '#'
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#' {
				dfs(node, x, y)
			}
		}
		board[i][j] = c
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			dfs(trie, i, j)
		}
	}
	return
}
```

#### TypeScript

```ts
class Trie {
    children: Trie[];
    ref: number;

    constructor() {
        this.children = new Array(26);
        this.ref = -1;
    }

    insert(w: string, ref: number): void {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const c = w.charCodeAt(i) - 97;
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.ref = ref;
    }
}

function findWords(board: string[][], words: string[]): string[] {
    const tree = new Trie();
    for (let i = 0; i < words.length; ++i) {
        tree.insert(words[i], i);
    }
    const m = board.length;
    const n = board[0].length;
    const ans: string[] = [];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (node: Trie, i: number, j: number) => {
        const idx = board[i][j].charCodeAt(0) - 97;
        if (node.children[idx] == null) {
            return;
        }
        node = node.children[idx];
        if (node.ref != -1) {
            ans.push(words[node.ref]);
            node.ref = -1;
        }
        const c = board[i][j];
        board[i][j] = '#';
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                dfs(node, x, y);
            }
        }
        board[i][j] = c;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            dfs(tree, i, j);
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

# [213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii){#213}

{{< tabs "213" >}}

{{% tab "python" %}}
```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        def _rob(nums):
            f = g = 0
            for x in nums:
                f, g = max(f, g), f + x
            return max(f, g)

        if len(nums) == 1:
            return nums[0]
        return max(_rob(nums[1:]), _rob(nums[:-1]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

    private int rob(int[] nums, int l, int r) {
        int f = 0, g = 0;
        for (; l <= r; ++l) {
            int ff = Math.max(f, g);
            g = f + nums[l];
            f = ff;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>& nums, int l, int r) {
        int f = 0, g = 0;
        for (; l <= r; ++l) {
            int ff = max(f, g);
            g = f + nums[l];
            f = ff;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1))
}

func robRange(nums []int, l, r int) int {
	f, g := 0, 0
	for _, x := range nums[l : r+1] {
		f, g = max(f, g), f+x
	}
	return max(f, g)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rob(nums: number[]): number {
    const n = nums.length;
    if (n === 1) {
        return nums[0];
    }
    const robRange = (l: number, r: number): number => {
        let [f, g] = [0, 0];
        for (; l <= r; ++l) {
            [f, g] = [Math.max(f, g), f + nums[l]];
        }
        return Math.max(f, g);
    };
    return Math.max(robRange(0, n - 2), robRange(1, n - 1));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        let rob_range = |l, r| {
            let mut f = [0, 0];
            for i in l..r {
                f = [f[0].max(f[1]), f[0] + nums[i]];
            }
            f[0].max(f[1])
        };
        rob_range(0, n - 1).max(rob_range(1, n))
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 <strong>围成一圈</strong> ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong> 。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你 <strong>在不触动警报装置的情况下</strong> ，今晚能够偷窃到的最高金额。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,2]
<strong>输出：</strong>3
<strong>解释：</strong>你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1]
<strong>输出：</strong>4
<strong>解释：</strong>你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
&nbsp;    偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

环状排列意味着第一个房屋和最后一个房屋中最多只能选择一个偷窃，因此可以把此环状排列房间问题约化为两个单排排列房屋子问题。

时间复杂度 $O(n)$，其中 $n$ 是数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        def _rob(nums):
            f = g = 0
            for x in nums:
                f, g = max(f, g), f + x
            return max(f, g)

        if len(nums) == 1:
            return nums[0]
        return max(_rob(nums[1:]), _rob(nums[:-1]))
```

#### Java

```java
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

    private int rob(int[] nums, int l, int r) {
        int f = 0, g = 0;
        for (; l <= r; ++l) {
            int ff = Math.max(f, g);
            g = f + nums[l];
            f = ff;
        }
        return Math.max(f, g);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>& nums, int l, int r) {
        int f = 0, g = 0;
        for (; l <= r; ++l) {
            int ff = max(f, g);
            g = f + nums[l];
            f = ff;
        }
        return max(f, g);
    }
};
```

#### Go

```go
func rob(nums []int) int {
	n := len(nums)
	if n == 1 {
		return nums[0]
	}
	return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1))
}

func robRange(nums []int, l, r int) int {
	f, g := 0, 0
	for _, x := range nums[l : r+1] {
		f, g = max(f, g), f+x
	}
	return max(f, g)
}
```

#### TypeScript

```ts
function rob(nums: number[]): number {
    const n = nums.length;
    if (n === 1) {
        return nums[0];
    }
    const robRange = (l: number, r: number): number => {
        let [f, g] = [0, 0];
        for (; l <= r; ++l) {
            [f, g] = [Math.max(f, g), f + nums[l]];
        }
        return Math.max(f, g);
    };
    return Math.max(robRange(0, n - 2), robRange(1, n - 1));
}
```

#### Rust

```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        let rob_range = |l, r| {
            let mut f = [0, 0];
            for i in l..r {
                f = [f[0].max(f[1]), f[0] + nums[i]];
            }
            f[0].max(f[1])
        };
        rob_range(0, n - 1).max(rob_range(1, n))
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [214. 最短回文串](https://leetcode.cn/problems/shortest-palindrome){#214}

{{< tabs "214" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        t = s + "#" + s[::-1] + "$"
        n = len(t)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if t[i - 1] == t[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[::-1][: -next[-1]] + s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        char[] t = (s + "#" + rev + "$").toCharArray();
        int n = t.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return rev.substring(0, s.length() - next[n - 1]) + s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s + "#" + string(s.rbegin(), s.rend()) + "$";
        int n = t.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - next[n - 1]) + s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPalindrome(s string) string {
	t := s + "#" + reverse(s) + "$"
	n := len(t)
	next := make([]int, n)
	next[0] = -1
	for i, j := 2, 0; i < n; {
		if t[i-1] == t[j] {
			j++
			next[i] = j
			i++
		} else if j > 0 {
			j = next[j]
		} else {
			next[i] = 0
			i++
		}
	}
	return reverse(s)[:len(s)-next[n-1]] + s
}

func reverse(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shortest_palindrome(s: String) -> String {
        let base = 131;
        let (mut idx, mut prefix, mut suffix, mut mul) = (0, 0, 0, 1);
        for (i, c) in s.chars().enumerate() {
            let t = (c as u64) - ('0' as u64) + 1;
            prefix = prefix * base + t;
            suffix = suffix + t * mul;
            mul *= base;
            if prefix == suffix {
                idx = i + 1;
            }
        }
        if idx == s.len() {
            s
        } else {
            let x: String = (&s[idx..]).chars().rev().collect();
            String::from(x + &s)
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string ShortestPalindrome(string s) {
        char[] t = (s + "#" + new string(s.Reverse().ToArray()) + "$").ToCharArray();
        int n = t.Length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return new string(s.Substring(next[n - 1]).Reverse().ToArray()).Substring(0, s.Length - next[n - 1]) + s;
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestPalindrome(s: string): string {
    const rev = s.split('').reverse().join('');
    const t = s + '#' + rev + '$';
    const n = t.length;
    const next: number[] = Array(n).fill(0);
    next[0] = -1;
    for (let i = 2, j = 0; i < n; ) {
        if (t[i - 1] === t[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i++] = 0;
        }
    }
    return rev.slice(0, -next[n - 1]) + s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <em><strong>s</strong></em>，你可以通过在字符串前面添加字符将其转换为<span data-keyword="palindrome-string">回文串</span>。找到并返回可以用这种方式转换的最短回文串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aacecaaa"
<strong>输出：</strong>"aaacecaaa"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>"dcbabcd"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

对于本题，问题等价于**找到字符串 s 的最长回文前缀**。

记 s 的长度为 n，其最长回文前缀的长度为 m，将 s 的后 n-m 个字符反序并添加到 s 的前面即可构成最短回文串。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        base = 131
        mod = 10**9 + 7
        n = len(s)
        prefix = suffix = 0
        mul = 1
        idx = 0
        for i, c in enumerate(s):
            prefix = (prefix * base + (ord(c) - ord('a') + 1)) % mod
            suffix = (suffix + (ord(c) - ord('a') + 1) * mul) % mod
            mul = (mul * base) % mod
            if prefix == suffix:
                idx = i + 1
        return s if idx == n else s[idx:][::-1] + s
```

#### Java

```java
class Solution {
    public String shortestPalindrome(String s) {
        int base = 131;
        int mul = 1;
        int mod = (int) 1e9 + 7;
        int prefix = 0, suffix = 0;
        int idx = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int t = s.charAt(i) - 'a' + 1;
            prefix = (int) (((long) prefix * base + t) % mod);
            suffix = (int) ((suffix + (long) t * mul) % mod);
            mul = (int) (((long) mul * base) % mod);
            if (prefix == suffix) {
                idx = i + 1;
            }
        }
        if (idx == n) {
            return s;
        }
        return new StringBuilder(s.substring(idx)).reverse().toString() + s;
    }
}
```

#### C++

```cpp
typedef unsigned long long ull;

class Solution {
public:
    string shortestPalindrome(string s) {
        int base = 131;
        ull mul = 1;
        ull prefix = 0;
        ull suffix = 0;
        int idx = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int t = s[i] - 'a' + 1;
            prefix = prefix * base + t;
            suffix = suffix + mul * t;
            mul *= base;
            if (prefix == suffix) idx = i + 1;
        }
        if (idx == n) return s;
        string x = s.substr(idx, n - idx);
        reverse(x.begin(), x.end());
        return x + s;
    }
};
```

#### Go

```go
func shortestPalindrome(s string) string {
	n := len(s)
	base, mod := 131, int(1e9)+7
	prefix, suffix, mul := 0, 0, 1
	idx := 0
	for i, c := range s {
		t := int(c-'a') + 1
		prefix = (prefix*base + t) % mod
		suffix = (suffix + t*mul) % mod
		mul = (mul * base) % mod
		if prefix == suffix {
			idx = i + 1
		}
	}
	if idx == n {
		return s
	}
	x := []byte(s[idx:])
	for i, j := 0, len(x)-1; i < j; i, j = i+1, j-1 {
		x[i], x[j] = x[j], x[i]
	}
	return string(x) + s
}
```

#### Rust

```rust
impl Solution {
    pub fn shortest_palindrome(s: String) -> String {
        let base = 131;
        let (mut idx, mut prefix, mut suffix, mut mul) = (0, 0, 0, 1);
        for (i, c) in s.chars().enumerate() {
            let t = (c as u64) - ('0' as u64) + 1;
            prefix = prefix * base + t;
            suffix = suffix + t * mul;
            mul *= base;
            if prefix == suffix {
                idx = i + 1;
            }
        }
        if idx == s.len() {
            s
        } else {
            let x: String = (&s[idx..]).chars().rev().collect();
            String::from(x + &s)
        }
    }
}
```

#### C#

```cs
public class Solution {
    public string ShortestPalindrome(string s) {
        int baseValue = 131;
        int mul = 1;
        int mod = (int)1e9 + 7;
        int prefix = 0, suffix = 0;
        int idx = 0;
        int n = s.Length;

        for (int i = 0; i < n; ++i) {
            int t = s[i] - 'a' + 1;
            prefix = (int)(((long)prefix * baseValue + t) % mod);
            suffix = (int)((suffix + (long)t * mul) % mod);
            mul = (int)(((long)mul * baseValue) % mod);
            if (prefix == suffix) {
                idx = i + 1;
            }
        }

        if (idx == n) {
            return s;
        }

        return new string(s.Substring(idx).Reverse().ToArray()) + s;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：KMP 算法

根据题目描述，我们需要将字符串 $s$ 反转，得到字符串 $\textit{rev}$，然后求出字符串 $rev$ 的后缀与字符串 $s$ 的前缀的最长公共部分。我们可以使用 KMP 算法，将字符串 $s$ 与字符串 $rev$ 连接起来，求出其最长前缀与最长后缀的最长公共部分。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        t = s + "#" + s[::-1] + "$"
        n = len(t)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if t[i - 1] == t[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[::-1][: -next[-1]] + s
```

#### Java

```java
class Solution {
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        char[] t = (s + "#" + rev + "$").toCharArray();
        int n = t.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return rev.substring(0, s.length() - next[n - 1]) + s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s + "#" + string(s.rbegin(), s.rend()) + "$";
        int n = t.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return string(s.rbegin(), s.rbegin() + s.size() - next[n - 1]) + s;
    }
};
```

#### Go

```go
func shortestPalindrome(s string) string {
	t := s + "#" + reverse(s) + "$"
	n := len(t)
	next := make([]int, n)
	next[0] = -1
	for i, j := 2, 0; i < n; {
		if t[i-1] == t[j] {
			j++
			next[i] = j
			i++
		} else if j > 0 {
			j = next[j]
		} else {
			next[i] = 0
			i++
		}
	}
	return reverse(s)[:len(s)-next[n-1]] + s
}

func reverse(s string) string {
	t := []byte(s)
	for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
		t[i], t[j] = t[j], t[i]
	}
	return string(t)
}
```

#### TypeScript

```ts
function shortestPalindrome(s: string): string {
    const rev = s.split('').reverse().join('');
    const t = s + '#' + rev + '$';
    const n = t.length;
    const next: number[] = Array(n).fill(0);
    next[0] = -1;
    for (let i = 2, j = 0; i < n; ) {
        if (t[i - 1] === t[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i++] = 0;
        }
    }
    return rev.slice(0, -next[n - 1]) + s;
}
```

#### C#

```cs
public class Solution {
    public string ShortestPalindrome(string s) {
        char[] t = (s + "#" + new string(s.Reverse().ToArray()) + "$").ToCharArray();
        int n = t.Length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (t[i - 1] == t[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return new string(s.Substring(next[n - 1]).Reverse().ToArray()).Substring(0, s.Length - next[n - 1]) + s;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array){#215}

{{< tabs "215" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for i in count(max(cnt), -1):
            k -= cnt[i]
            if k <= 0:
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>(nums.length);
        int m = Integer.MIN_VALUE;
        for (int x : nums) {
            m = Math.max(m, x);
            cnt.merge(x, 1, Integer::sum);
        }
        for (int i = m;; --i) {
            k -= cnt.getOrDefault(i, 0);
            if (k <= 0) {
                return i;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int m = INT_MIN;
        for (int x : nums) {
            ++cnt[x];
            m = max(m, x);
        }
        for (int i = m;; --i) {
            k -= cnt[i];
            if (k <= 0) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthLargest(nums []int, k int) int {
	cnt := map[int]int{}
	m := -(1 << 30)
	for _, x := range nums {
		cnt[x]++
		m = max(m, x)
	}
	for i := m; ; i-- {
		k -= cnt[i]
		if k <= 0 {
			return i
		}
	}

}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKthLargest(nums: number[], k: number): number {
    const cnt: Record<number, number> = {};
    for (const x of nums) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const m = Math.max(...nums);
    for (let i = m; ; --i) {
        k -= cnt[i] || 0;
        if (k <= 0) {
            return i;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        let mut m = i32::MIN;

        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
            if x > m {
                m = x;
            }
        }

        let mut k = k;
        for i in (i32::MIN..=m).rev() {
            if let Some(&count) = cnt.get(&i) {
                k -= count;
                if k <= 0 {
                    return i;
                }
            }
        }

        unreachable!();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定整数数组 <code>nums</code> 和整数 <code>k</code>，请返回数组中第 <code><strong>k</strong></code> 个最大的元素。</p>

<p>请注意，你需要找的是数组排序后的第 <code>k</code> 个最大的元素，而不是第 <code>k</code> 个不同的元素。</p>

<p>你必须设计并实现时间复杂度为 <code>O(n)</code> 的算法解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>[3,2,1,5,6,4],</code> k = 2
<strong>输出:</strong> 5
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> <code>[3,2,3,1,2,4,5,5,6], </code>k = 4
<strong>输出:</strong> 4</pre>

<p>&nbsp;</p>

<p><strong>提示： </strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快速选择

快速选择算法是一种在未排序的数组中查找第 `k` 个最大元素或最小元素的算法。它的基本思想是每次选择一个基准元素，将数组分为两部分，一部分的元素都比基准元素小，另一部分的元素都比基准元素大，然后根据基准元素的位置，决定继续在左边还是右边查找，直到找到第 `k` 个最大元素。

时间复杂度 $O(n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quick_sort(l: int, r: int) -> int:
            if l == r:
                return nums[l]
            i, j = l - 1, r + 1
            x = nums[(l + r) >> 1]
            while i < j:
                while 1:
                    i += 1
                    if nums[i] >= x:
                        break
                while 1:
                    j -= 1
                    if nums[j] <= x:
                        break
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]
            if j < k:
                return quick_sort(j + 1, r)
            return quick_sort(l, j)

        n = len(nums)
        k = n - k
        return quick_sort(0, n - 1)
```

#### Java

```java
class Solution {
    private int[] nums;
    private int k;

    public int findKthLargest(int[] nums, int k) {
        this.nums = nums;
        this.k = nums.length - k;
        return quickSort(0, nums.length - 1);
    }

    private int quickSort(int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int i = l - 1, j = r + 1;
        int x = nums[(l + r) >>> 1];
        while (i < j) {
            while (nums[++i] < x) {
            }
            while (nums[--j] > x) {
            }
            if (i < j) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        if (j < k) {
            return quickSort(j + 1, r);
        }
        return quickSort(l, j);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        auto quickSort = [&](auto&& quickSort, int l, int r) -> int {
            if (l == r) {
                return nums[l];
            }
            int i = l - 1, j = r + 1;
            int x = nums[(l + r) >> 1];
            while (i < j) {
                while (nums[++i] < x) {
                }
                while (nums[--j] > x) {
                }
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            if (j < k) {
                return quickSort(quickSort, j + 1, r);
            }
            return quickSort(quickSort, l, j);
        };
        return quickSort(quickSort, 0, n - 1);
    }
};
```

#### Go

```go
func findKthLargest(nums []int, k int) int {
	k = len(nums) - k
	var quickSort func(l, r int) int
	quickSort = func(l, r int) int {
		if l == r {
			return nums[l]
		}
		i, j := l-1, r+1
		x := nums[(l+r)>>1]
		for i < j {
			for {
				i++
				if nums[i] >= x {
					break
				}
			}
			for {
				j--
				if nums[j] <= x {
					break
				}
			}
			if i < j {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
		if j < k {
			return quickSort(j+1, r)
		}
		return quickSort(l, j)
	}
	return quickSort(0, len(nums)-1)
}
```

#### TypeScript

```ts
function findKthLargest(nums: number[], k: number): number {
    const n = nums.length;
    k = n - k;
    const quickSort = (l: number, r: number): number => {
        if (l === r) {
            return nums[l];
        }
        let [i, j] = [l - 1, r + 1];
        const x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
            }
        }
        if (j < k) {
            return quickSort(j + 1, r);
        }
        return quickSort(l, j);
    };
    return quickSort(0, n - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn find_kth_largest(mut nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let k = len - k as usize;
        Self::quick_sort(&mut nums, 0, len - 1, k)
    }

    fn quick_sort(nums: &mut Vec<i32>, l: usize, r: usize, k: usize) -> i32 {
        if l == r {
            return nums[l];
        }

        let (mut i, mut j) = (l as isize - 1, r as isize + 1);
        let x = nums[(l + r) / 2];

        while i < j {
            i += 1;
            while nums[i as usize] < x {
                i += 1;
            }

            j -= 1;
            while nums[j as usize] > x {
                j -= 1;
            }

            if i < j {
                nums.swap(i as usize, j as usize);
            }
        }

        let j = j as usize;
        if j < k {
            Self::quick_sort(nums, j + 1, r, k)
        } else {
            Self::quick_sort(nums, l, j, k)
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：优先队列（小根堆）

我们可以维护一个大小为 $k$ 的小根堆 $\textit{minQ}$，然后遍历数组 $\textit{nums}$，将数组中的元素依次加入到小根堆中，当小根堆的大小超过 $k$ 时，我们将堆顶元素弹出，这样最终小根堆中的 $k$ 个元素就是数组中的 $k$ 个最大元素，堆顶元素就是第 $k$ 个最大元素。

时间复杂度 $O(n\log k)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return nlargest(k, nums)[-1]
```

#### Java

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minQ = new PriorityQueue<>();
        for (int x : nums) {
            minQ.offer(x);
            if (minQ.size() > k) {
                minQ.poll();
            }
        }
        return minQ.peek();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int x : nums) {
            minQ.push(x);
            if (minQ.size() > k) {
                minQ.pop();
            }
        }
        return minQ.top();
    }
};
```

#### Go

```go
func findKthLargest(nums []int, k int) int {
	minQ := hp{}
	for _, x := range nums {
		heap.Push(&minQ, x)
		if minQ.Len() > k {
			heap.Pop(&minQ)
		}
	}
	return minQ.IntSlice[0]
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function findKthLargest(nums: number[], k: number): number {
    const minQ = new MinPriorityQueue();
    for (const x of nums) {
        minQ.enqueue(x);
        if (minQ.size() > k) {
            minQ.dequeue();
        }
    }
    return minQ.front().element;
}
```

#### Rust

```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut minQ = BinaryHeap::new();
        for &x in nums.iter() {
            minQ.push(-x);
            if minQ.len() > k as usize {
                minQ.pop();
            }
        }
        -minQ.peek().unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：计数排序

我们可以使用计数排序的思想，统计数组 $\textit{nums}$ 中每个元素出现的次数，记录在哈希表 $\textit{cnt}$ 中，然后从大到小遍历元素 $i$，每次减去出现的次数 $\textit{cnt}[i]$，直到 $k$ 小于等于 $0$，此时的元素 $i$ 就是数组中的第 $k$ 个最大元素。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $m$ 为数组 $\textit{nums}$ 中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for i in count(max(cnt), -1):
            k -= cnt[i]
            if k <= 0:
                return i
```

#### Java

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>(nums.length);
        int m = Integer.MIN_VALUE;
        for (int x : nums) {
            m = Math.max(m, x);
            cnt.merge(x, 1, Integer::sum);
        }
        for (int i = m;; --i) {
            k -= cnt.getOrDefault(i, 0);
            if (k <= 0) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int m = INT_MIN;
        for (int x : nums) {
            ++cnt[x];
            m = max(m, x);
        }
        for (int i = m;; --i) {
            k -= cnt[i];
            if (k <= 0) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func findKthLargest(nums []int, k int) int {
	cnt := map[int]int{}
	m := -(1 << 30)
	for _, x := range nums {
		cnt[x]++
		m = max(m, x)
	}
	for i := m; ; i-- {
		k -= cnt[i]
		if k <= 0 {
			return i
		}
	}

}
```

#### TypeScript

```ts
function findKthLargest(nums: number[], k: number): number {
    const cnt: Record<number, number> = {};
    for (const x of nums) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const m = Math.max(...nums);
    for (let i = m; ; --i) {
        k -= cnt[i] || 0;
        if (k <= 0) {
            return i;
        }
    }
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = HashMap::new();
        let mut m = i32::MIN;

        for &x in &nums {
            *cnt.entry(x).or_insert(0) += 1;
            if x > m {
                m = x;
            }
        }

        let mut k = k;
        for i in (i32::MIN..=m).rev() {
            if let Some(&count) = cnt.get(&i) {
                k -= count;
                if k <= 0 {
                    return i;
                }
            }
        }

        unreachable!();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [216. 组合总和 III](https://leetcode.cn/problems/combination-sum-iii){#216}

{{< tabs "216" >}}

{{% tab "python" %}}
```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        for mask in range(1 << 9):
            if mask.bit_count() == k:
                t = [i + 1 for i in range(9) if mask >> i & 1]
                if sum(t) == n:
                    ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (Integer.bitCount(mask) == k) {
                List<Integer> t = new ArrayList<>();
                int s = 0;
                for (int i = 0; i < 9; ++i) {
                    if ((mask >> i & 1) == 1) {
                        s += (i + 1);
                        t.add(i + 1);
                    }
                }
                if (s == n) {
                    ans.add(t);
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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (__builtin_popcount(mask) == k) {
                int s = 0;
                vector<int> t;
                for (int i = 0; i < 9; ++i) {
                    if (mask >> i & 1) {
                        t.push_back(i + 1);
                        s += i + 1;
                    }
                }
                if (s == n) {
                    ans.emplace_back(t);
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
func combinationSum3(k int, n int) (ans [][]int) {
	for mask := 0; mask < 1<<9; mask++ {
		if bits.OnesCount(uint(mask)) == k {
			t := []int{}
			s := 0
			for i := 0; i < 9; i++ {
				if mask>>i&1 == 1 {
					s += i + 1
					t = append(t, i+1)
				}
			}
			if s == n {
				ans = append(ans, t)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function combinationSum3(k: number, n: number): number[][] {
    const ans: number[][] = [];
    for (let mask = 0; mask < 1 << 9; ++mask) {
        if (bitCount(mask) === k) {
            const t: number[] = [];
            let s = 0;
            for (let i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    t.push(i + 1);
                    s += i + 1;
                }
            }
            if (s === n) {
                ans.push(t);
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
{{% tab "js" %}}
```js
function combinationSum3(k, n) {
    const ans = [];
    for (let mask = 0; mask < 1 << 9; ++mask) {
        if (bitCount(mask) === k) {
            const t = [];
            let s = 0;
            for (let i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    t.push(i + 1);
                    s += i + 1;
                }
            }
            if (s === n) {
                ans.push(t);
            }
        }
    }
    return ans;
}

function bitCount(i) {
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
    #[allow(dead_code)]
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        let mut ret = Vec::new();
        let mut candidates = (1..=9).collect();
        let mut cur_vec = Vec::new();
        Self::dfs(n, k, 0, 0, &mut cur_vec, &mut candidates, &mut ret);
        ret
    }

    #[allow(dead_code)]
    fn dfs(
        target: i32,
        length: i32,
        cur_index: usize,
        cur_sum: i32,
        cur_vec: &mut Vec<i32>,
        candidates: &Vec<i32>,
        ans: &mut Vec<Vec<i32>>,
    ) {
        if cur_sum > target || cur_vec.len() > (length as usize) {
            // No answer for this
            return;
        }
        if cur_sum == target && cur_vec.len() == (length as usize) {
            // We get an answer
            ans.push(cur_vec.clone());
            return;
        }
        for i in cur_index..candidates.len() {
            cur_vec.push(candidates[i]);
            Self::dfs(
                target,
                length,
                i + 1,
                cur_sum + candidates[i],
                cur_vec,
                candidates,
                ans,
            );
            cur_vec.pop().unwrap();
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<IList<int>> CombinationSum3(int k, int n) {
        List<IList<int>> ans = new List<IList<int>>();
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (bitCount(mask) == k) {
                List<int> t = new List<int>();
                int s = 0;
                for (int i = 0; i < 9; ++i) {
                    if ((mask >> i & 1) == 1) {
                        s += i + 1;
                        t.Add(i + 1);
                    }
                }
                if (s == n) {
                    ans.Add(t);
                }
            }
        }
        return ans;
    }

    private int bitCount(int x) {
        int cnt = 0;
        while (x > 0) {
            x -= x & -x;
            ++cnt;
        }
        return cnt;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>找出所有相加之和为&nbsp;<code>n</code><em> </em>的&nbsp;<code>k</code><strong>&nbsp;</strong>个数的组合，且满足下列条件：</p>

<ul>
	<li>只使用数字1到9</li>
	<li>每个数字&nbsp;<strong>最多使用一次</strong>&nbsp;</li>
</ul>

<p>返回 <em>所有可能的有效组合的列表</em> 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 7
<strong>输出:</strong> [[1,2,4]]
<strong>解释:</strong>
1 + 2 + 4 = 7
没有其他符合的组合了。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 9
<strong>输出:</strong> [[1,2,6], [1,3,5], [2,3,4]]
<strong>解释:
</strong>1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> k = 4, n = 1
<strong>输出:</strong> []
<strong>解释:</strong> 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 &gt; 1，没有有效的组合。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：剪枝 + 回溯（两种方式）

我们设计一个函数 $dfs(i, s)$，表示当前枚举到数字 $i$，还剩下和为 $s$ 的数字需要枚举，当前搜索路径为 $t$，答案为 $ans$。

函数 $dfs(i, s)$ 的执行逻辑如下：

方式一：

-   如果 $s = 0$，且当前搜索路径 $t$ 的长度为 $k$，说明找到了一组答案，将 $t$ 加入 $ans$ 中，然后返回。
-   如果 $i \gt 9$ 或者 $i \gt s$ 或者当前搜索路径 $t$ 的长度大于 $k$，说明当前搜索路径不可能是答案，直接返回。
-   否则，我们可以选择将数字 $i$ 加入搜索路径 $t$ 中，然后继续搜索，即执行 $dfs(i + 1, s - i)$，搜索完成后，将 $i$ 从搜索路径 $t$ 中移除；我们也可以选择不将数字 $i$ 加入搜索路径 $t$ 中，直接执行 $dfs(i + 1, s)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                if len(t) == k:
                    ans.append(t[:])
                return
            if i > 9 or i > s or len(t) >= k:
                return
            t.append(i)
            dfs(i + 1, s - i)
            t.pop()
            dfs(i + 1, s)

        ans = []
        t = []
        dfs(1, n)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int k;

    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;
        dfs(1, n);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            if (t.size() == k) {
                ans.add(new ArrayList<>(t));
            }
            return;
        }
        if (i > 9 || i > s || t.size() >= k) {
            return;
        }
        t.add(i);
        dfs(i + 1, s - i);
        t.remove(t.size() - 1);
        dfs(i + 1, s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                if (t.size() == k) {
                    ans.emplace_back(t);
                }
                return;
            }
            if (i > 9 || i > s || t.size() >= k) {
                return;
            }
            t.emplace_back(i);
            dfs(i + 1, s - i);
            t.pop_back();
            dfs(i + 1, s);
        };
        dfs(1, n);
        return ans;
    }
};
```

#### Go

```go
func combinationSum3(k int, n int) (ans [][]int) {
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			if len(t) == k {
				ans = append(ans, slices.Clone(t))
			}
			return
		}
		if i > 9 || i > s || len(t) >= k {
			return
		}
		t = append(t, i)
		dfs(i+1, s-i)
		t = t[:len(t)-1]
		dfs(i+1, s)
	}
	dfs(1, n)
	return
}
```

#### TypeScript

```ts
function combinationSum3(k: number, n: number): number[][] {
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            if (t.length === k) {
                ans.push(t.slice());
            }
            return;
        }
        if (i > 9 || i > s || t.length >= k) {
            return;
        }
        t.push(i);
        dfs(i + 1, s - i);
        t.pop();
        dfs(i + 1, s);
    };
    dfs(1, n);
    return ans;
}
```

#### JavaScript

```js
function combinationSum3(k, n) {
    const ans = [];
    const t = [];
    const dfs = (i, s) => {
        if (s === 0) {
            if (t.length === k) {
                ans.push(t.slice());
            }
            return;
        }
        if (i > 9 || i > s || t.length >= k) {
            return;
        }
        t.push(i);
        dfs(i + 1, s - i);
        t.pop();
        dfs(i + 1, s);
    };
    dfs(1, n);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        let mut ret = Vec::new();
        let mut candidates = (1..=9).collect();
        let mut cur_vec = Vec::new();
        Self::dfs(n, k, 0, 0, &mut cur_vec, &mut candidates, &mut ret);
        ret
    }

    #[allow(dead_code)]
    fn dfs(
        target: i32,
        length: i32,
        cur_index: usize,
        cur_sum: i32,
        cur_vec: &mut Vec<i32>,
        candidates: &Vec<i32>,
        ans: &mut Vec<Vec<i32>>,
    ) {
        if cur_sum > target || cur_vec.len() > (length as usize) {
            // No answer for this
            return;
        }
        if cur_sum == target && cur_vec.len() == (length as usize) {
            // We get an answer
            ans.push(cur_vec.clone());
            return;
        }
        for i in cur_index..candidates.len() {
            cur_vec.push(candidates[i]);
            Self::dfs(
                target,
                length,
                i + 1,
                cur_sum + candidates[i],
                cur_vec,
                candidates,
                ans,
            );
            cur_vec.pop().unwrap();
        }
    }
}
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int k;

    public IList<IList<int>> CombinationSum3(int k, int n) {
        this.k = k;
        dfs(1, n);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            if (t.Count == k) {
                ans.Add(new List<int>(t));
            }
            return;
        }
        if (i > 9 || i > s || t.Count >= k) {
            return;
        }
        t.Add(i);
        dfs(i + 1, s - i);
        t.RemoveAt(t.Count - 1);
        dfs(i + 1, s);
    }
}
```

<!-- tabs:end -->

方式二：

-   如果 $s = 0$，且当前搜索路径 $t$ 的长度为 $k$，说明找到了一组答案，将 $t$ 加入 $ans$ 中，然后返回。
-   如果 $i \gt 9$ 或者 $i \gt s$ 或者当前搜索路径 $t$ 的长度大于 $k$，说明当前搜索路径不可能是答案，直接返回。
-   否则，我们枚举下一个数字 $j$，即 $j \in [i, 9]$，将数字 $j$ 加入搜索路径 $t$ 中，然后继续搜索，即执行 $dfs(j + 1, s - j)$，搜索完成后，将 $j$ 从搜索路径 $t$ 中移除。

在主函数中，我们调用 $dfs(1, n)$，即从数字 $1$ 开始枚举，剩下和为 $n$ 的数字需要枚举。搜索完成后，即可得到所有的答案。

时间复杂度 $(C_{9}^k \times k)$，空间复杂度 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def dfs(i: int, s: int):
            if s == 0:
                if len(t) == k:
                    ans.append(t[:])
                return
            if i > 9 or i > s or len(t) >= k:
                return
            for j in range(i, 10):
                t.append(j)
                dfs(j + 1, s - j)
                t.pop()

        ans = []
        t = []
        dfs(1, n)
        return ans
```

#### Java

```java
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private int k;

    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;
        dfs(1, n);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            if (t.size() == k) {
                ans.add(new ArrayList<>(t));
            }
            return;
        }
        if (i > 9 || i > s || t.size() >= k) {
            return;
        }
        for (int j = i; j <= 9; ++j) {
            t.add(j);
            dfs(j + 1, s - j);
            t.remove(t.size() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        function<void(int, int)> dfs = [&](int i, int s) {
            if (s == 0) {
                if (t.size() == k) {
                    ans.emplace_back(t);
                }
                return;
            }
            if (i > 9 || i > s || t.size() >= k) {
                return;
            }
            for (int j = i; j <= 9; ++j) {
                t.emplace_back(j);
                dfs(j + 1, s - j);
                t.pop_back();
            }
        };
        dfs(1, n);
        return ans;
    }
};
```

#### Go

```go
func combinationSum3(k int, n int) (ans [][]int) {
	t := []int{}
	var dfs func(i, s int)
	dfs = func(i, s int) {
		if s == 0 {
			if len(t) == k {
				ans = append(ans, slices.Clone(t))
			}
			return
		}
		if i > 9 || i > s || len(t) >= k {
			return
		}
		for j := i; j <= 9; j++ {
			t = append(t, j)
			dfs(j+1, s-j)
			t = t[:len(t)-1]
		}
	}
	dfs(1, n)
	return
}
```

#### TypeScript

```ts
function combinationSum3(k: number, n: number): number[][] {
    const ans: number[][] = [];
    const t: number[] = [];
    const dfs = (i: number, s: number) => {
        if (s === 0) {
            if (t.length === k) {
                ans.push(t.slice());
            }
            return;
        }
        if (i > 9 || i > s || t.length >= k) {
            return;
        }
        for (let j = i; j <= 9; ++j) {
            t.push(j);
            dfs(j + 1, s - j);
            t.pop();
        }
    };
    dfs(1, n);
    return ans;
}
```

#### JavaScript

```js
function combinationSum3(k, n) {
    const ans = [];
    const t = [];
    const dfs = (i, s) => {
        if (s === 0) {
            if (t.length === k) {
                ans.push(t.slice());
            }
            return;
        }
        if (i > 9 || i > s || t.length >= k) {
            return;
        }
        for (let j = i; j <= 9; ++j) {
            t.push(j);
            dfs(j + 1, s - j);
            t.pop();
        }
    };
    dfs(1, n);
    return ans;
}
```

#### C#

```cs
public class Solution {
    private List<IList<int>> ans = new List<IList<int>>();
    private List<int> t = new List<int>();
    private int k;

    public IList<IList<int>> CombinationSum3(int k, int n) {
        this.k = k;
        dfs(1, n);
        return ans;
    }

    private void dfs(int i, int s) {
        if (s == 0) {
            if (t.Count == k) {
                ans.Add(new List<int>(t));
            }
            return;
        }
        if (i > 9 || i > s || t.Count >= k) {
            return;
        }
        for (int j = i; j <= 9; ++j) {
            t.Add(j);
            dfs(j + 1, s - j);
            t.RemoveAt(t.Count - 1);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制枚举

我们可以用一个长度为 $9$ 的二进制整数表示数字 $1$ 到 $9$ 的选取情况，其中二进制整数的第 $i$ 位表示数字 $i + 1$ 是否被选取，如果第 $i$ 位为 $1$，则表示数字 $i + 1$ 被选取，否则表示数字 $i + 1$ 没有被选取。

我们在 $[0, 2^9)$ 范围内枚举二进制整数，对于当前枚举到的二进制整数 $mask$，如果 $mask$ 的二进制表示中 $1$ 的个数为 $k$，且 $mask$ 的二进制表示中 $1$ 所对应的数字之和为 $n$，则说明 $mask$ 对应的数字选取方案是一组答案。我们将 $mask$ 对应的数字选取方案加入答案即可。

时间复杂度 $O(2^9 \times 9)$，空间复杂度 $O(k)$。

相似题目：

-   [39. 组合总和](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0039.Combination%20Sum/README.md)
-   [40. 组合总和 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0040.Combination%20Sum%20II/README.md)
-   [77. 组合](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0077.Combinations/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        for mask in range(1 << 9):
            if mask.bit_count() == k:
                t = [i + 1 for i in range(9) if mask >> i & 1]
                if sum(t) == n:
                    ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (Integer.bitCount(mask) == k) {
                List<Integer> t = new ArrayList<>();
                int s = 0;
                for (int i = 0; i < 9; ++i) {
                    if ((mask >> i & 1) == 1) {
                        s += (i + 1);
                        t.add(i + 1);
                    }
                }
                if (s == n) {
                    ans.add(t);
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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (__builtin_popcount(mask) == k) {
                int s = 0;
                vector<int> t;
                for (int i = 0; i < 9; ++i) {
                    if (mask >> i & 1) {
                        t.push_back(i + 1);
                        s += i + 1;
                    }
                }
                if (s == n) {
                    ans.emplace_back(t);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func combinationSum3(k int, n int) (ans [][]int) {
	for mask := 0; mask < 1<<9; mask++ {
		if bits.OnesCount(uint(mask)) == k {
			t := []int{}
			s := 0
			for i := 0; i < 9; i++ {
				if mask>>i&1 == 1 {
					s += i + 1
					t = append(t, i+1)
				}
			}
			if s == n {
				ans = append(ans, t)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function combinationSum3(k: number, n: number): number[][] {
    const ans: number[][] = [];
    for (let mask = 0; mask < 1 << 9; ++mask) {
        if (bitCount(mask) === k) {
            const t: number[] = [];
            let s = 0;
            for (let i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    t.push(i + 1);
                    s += i + 1;
                }
            }
            if (s === n) {
                ans.push(t);
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

#### JavaScript

```js
function combinationSum3(k, n) {
    const ans = [];
    for (let mask = 0; mask < 1 << 9; ++mask) {
        if (bitCount(mask) === k) {
            const t = [];
            let s = 0;
            for (let i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    t.push(i + 1);
                    s += i + 1;
                }
            }
            if (s === n) {
                ans.push(t);
            }
        }
    }
    return ans;
}

function bitCount(i) {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

#### C#

```cs
public class Solution {
    public IList<IList<int>> CombinationSum3(int k, int n) {
        List<IList<int>> ans = new List<IList<int>>();
        for (int mask = 0; mask < 1 << 9; ++mask) {
            if (bitCount(mask) == k) {
                List<int> t = new List<int>();
                int s = 0;
                for (int i = 0; i < 9; ++i) {
                    if ((mask >> i & 1) == 1) {
                        s += i + 1;
                        t.Add(i + 1);
                    }
                }
                if (s == n) {
                    ans.Add(t);
                }
            }
        }
        return ans;
    }

    private int bitCount(int x) {
        int cnt = 0;
        while (x > 0) {
            x -= x & -x;
            ++cnt;
        }
        return cnt;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [217. 存在重复元素](https://leetcode.cn/problems/contains-duplicate){#217}

{{< tabs "217" >}}

{{% tab "python" %}}
```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            if (!s.add(num)) {
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func containsDuplicate(nums []int) bool {
	s := map[int]bool{}
	for _, v := range nums {
		if s[v] {
			return true
		}
		s[v] = true
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function containsDuplicate(nums: number[]): boolean {
    return new Set<number>(nums).size !== nums.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        nums.iter().collect::<HashSet<&i32>>().len() != nums.len()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    return new Set(nums).size !== nums.length;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        return nums.Distinct().Count() < nums.Length;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $numsUnique = array_unique($nums);
        return count($nums) != count($numsUnique);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            return 1;
        }
    }
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个整数数组 <code>nums</code> 。如果任一值在数组中出现 <strong>至少两次</strong> ，返回 <code>true</code> ；如果数组中每个元素互不相同，返回 <code>false</code> 。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,1]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p>元素 1 在下标 0 和 3 出现。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p>所有元素都不同。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,1,3,3,4,3,2,4,2]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先对数组 `nums` 进行排序。

然后遍历数组，如果存在相邻两个元素相同，说明数组中存在重复元素，直接返回 `true`。

否则，遍历结束，返回 `false`。

时间复杂度 $O(n \times \log n)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return any(a == b for a, b in pairwise(sorted(nums)))
```

#### Java

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
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
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	for i, v := range nums[1:] {
		if v == nums[i] {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function containsDuplicate(nums: number[]): boolean {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    for (let i = 1; i < n; i++) {
        if (nums[i - 1] === nums[i]) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort();
        let n = nums.len();
        for i in 1..n {
            if nums[i - 1] == nums[i] {
                return true;
            }
        }
        false
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    return new Set(nums).size !== nums.length;
};
```

#### C#

```cs
public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        return nums.Distinct().Count() < nums.Length;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $numsUnique = array_unique($nums);
        return count($nums) != count($numsUnique);
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            return 1;
        }
    }
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

遍历数组，将出现过的元素记录在哈希表 $s$ 中。若元素第二次出现时，说明数组中存在重复元素，直接返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)
```

#### Java

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            if (!s.add(num)) {
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
};
```

#### Go

```go
func containsDuplicate(nums []int) bool {
	s := map[int]bool{}
	for _, v := range nums {
		if s[v] {
			return true
		}
		s[v] = true
	}
	return false
}
```

#### TypeScript

```ts
function containsDuplicate(nums: number[]): boolean {
    return new Set<number>(nums).size !== nums.length;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        nums.iter().collect::<HashSet<&i32>>().len() != nums.len()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [218. 天际线问题](https://leetcode.cn/problems/the-skyline-problem){#218}

{{< tabs "218" >}}

{{% tab "python" %}}
```python
from queue import PriorityQueue


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        skys, lines, pq = [], [], PriorityQueue()
        for build in buildings:
            lines.extend([build[0], build[1]])
        lines.sort()
        city, n = 0, len(buildings)
        for line in lines:
            while city < n and buildings[city][0] <= line:
                pq.put([-buildings[city][2], buildings[city][0], buildings[city][1]])
                city += 1
            while not pq.empty() and pq.queue[0][2] <= line:
                pq.get()
            high = 0
            if not pq.empty():
                high = -pq.queue[0][0]
            if len(skys) > 0 and skys[-1][1] == high:
                continue
            skys.append([line, high])
        return skys
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> poss;
        map<int, int> m;
        for (auto v : buildings) {
            poss.insert(v[0]);
            poss.insert(v[1]);
        }

        int i = 0;
        for (int pos : poss)
            m.insert(pair<int, int>(pos, i++));

        vector<int> highs(m.size(), 0);
        for (auto v : buildings) {
            const int b = m[v[0]], e = m[v[1]];
            for (int i = b; i < e; ++i)
                highs[i] = max(highs[i], v[2]);
        }

        vector<pair<int, int>> res;
        vector<int> mm(poss.begin(), poss.end());
        for (int i = 0; i < highs.size(); ++i) {
            if (highs[i] != highs[i + 1])
                res.push_back(pair<int, int>(mm[i], highs[i]));
            else {
                const int start = i;
                res.push_back(pair<int, int>(mm[start], highs[i]));
                while (highs[i] == highs[i + 1])
                    ++i;
            }
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Matrix struct{ left, right, height int }
type Queue []Matrix

func (q Queue) Len() int           { return len(q) }
func (q Queue) Top() Matrix        { return q[0] }
func (q Queue) Swap(i, j int)      { q[i], q[j] = q[j], q[i] }
func (q Queue) Less(i, j int) bool { return q[i].height > q[j].height }
func (q *Queue) Push(x any)        { *q = append(*q, x.(Matrix)) }
func (q *Queue) Pop() any {
	old, x := *q, (*q)[len(*q)-1]
	*q = old[:len(old)-1]
	return x
}

func getSkyline(buildings [][]int) [][]int {
	skys, lines, pq := make([][]int, 0), make([]int, 0), &Queue{}
	heap.Init(pq)
	for _, v := range buildings {
		lines = append(lines, v[0], v[1])
	}
	sort.Ints(lines)
	city, n := 0, len(buildings)
	for _, line := range lines {
		// 将所有符合条件的矩形加入队列
		for ; city < n && buildings[city][0] <= line && buildings[city][1] > line; city++ {
			v := Matrix{left: buildings[city][0], right: buildings[city][1], height: buildings[city][2]}
			heap.Push(pq, v)
		}
		// 从队列移除不符合条件的矩形
		for pq.Len() > 0 && pq.Top().right <= line {
			heap.Pop(pq)
		}
		high := 0
		// 队列为空说明是最右侧建筑物的终点，其轮廓点为 (line, 0)
		if pq.Len() != 0 {
			high = pq.Top().height
		}
		// 如果该点高度和前一个轮廓点一样的话，直接忽略
		if len(skys) > 0 && skys[len(skys)-1][1] == high {
			continue
		}
		skys = append(skys, []int{line, high})
	}
	return skys
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_skyline(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut skys: Vec<Vec<i32>> = vec![];
        let mut lines = vec![];
        for building in buildings.iter() {
            lines.push(building[0]);
            lines.push(building[1]);
        }
        lines.sort_unstable();
        let mut pq = std::collections::BinaryHeap::new();
        let (mut city, n) = (0, buildings.len());

        for line in lines {
            while city < n && buildings[city][0] <= line && buildings[city][1] > line {
                pq.push((buildings[city][2], buildings[city][1]));
                city += 1;
            }
            while !pq.is_empty() && pq.peek().unwrap().1 <= line {
                pq.pop();
            }
            let mut high = 0;
            if !pq.is_empty() {
                high = pq.peek().unwrap().0;
            }
            if !skys.is_empty() && skys.last().unwrap()[1] == high {
                continue;
            }
            skys.push(vec![line, high]);
        }
        skys
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>城市的 <strong>天际线</strong> 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 <em>由这些建筑物形成的<strong> 天际线</strong></em> 。</p>

<p>每个建筑物的几何信息由数组 <code>buildings</code> 表示，其中三元组 <code>buildings[i] = [lefti, righti, heighti]</code> 表示：</p>

<ul>
	<li><code>left<sub>i</sub></code> 是第 <code>i</code> 座建筑物左边缘的 <code>x</code> 坐标。</li>
	<li><code>right<sub>i</sub></code> 是第 <code>i</code> 座建筑物右边缘的 <code>x</code> 坐标。</li>
	<li><code>height<sub>i</sub></code> 是第 <code>i</code> 座建筑物的高度。</li>
</ul>

<p>你可以假设所有的建筑都是完美的长方形，在高度为 <code>0</code>&nbsp;的绝对平坦的表面上。</p>

<p><strong>天际线</strong> 应该表示为由 “关键点” 组成的列表，格式 <code>[[x<sub>1</sub>,y<sub>1</sub>],[x<sub>2</sub>,y<sub>2</sub>],...]</code> ，并按 <strong>x 坐标 </strong>进行 <strong>排序</strong> 。<strong>关键点是水平线段的左端点</strong>。列表中最后一个点是最右侧建筑物的终点，<code>y</code> 坐标始终为 <code>0</code> ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。</p>

<p><strong>注意：</strong>输出天际线中不得有连续的相同高度的水平线。例如 <code>[...[2 3], [4 5], [7 5], [11 5], [12 7]...]</code> 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：<code>[...[2 3], [4 5], [12 7], ...]</code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0218.The%20Skyline%20Problem/images/merged.jpg" style="height: 331px; width: 800px;" />
<pre>
<strong>输入：</strong>buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
<strong>输出：</strong>[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
<strong>解释：</strong>
图 A<strong> </strong>显示输入的所有建筑物的位置和高度，
图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>buildings = [[0,2,3],[2,5,3]]
<strong>输出：</strong>[[0,3],[5,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= buildings.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left<sub>i</sub> &lt; right<sub>i</sub> &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= height<sub>i</sub> &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>buildings</code> 按 <code>left<sub>i</sub></code> 非递减排序</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：扫描线+优先队列

记录下所有建筑物的左右边界线，升序排序之后得到序列 lines。对于每一个边界线 lines[i]，找出所有包含 lines[i] 的建筑物，并确保建筑物的左边界小于等于 lines[i]，右边界大于 lines[i]，则这些建筑物中高度最高的建筑物的高度就是该线轮廓点的高度。可以使用建筑物的高度构建优先队列（大根堆），同时需要注意高度相同的轮廓点需要合并为一个。

<!-- tabs:start -->

#### Python3

```python
from queue import PriorityQueue


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        skys, lines, pq = [], [], PriorityQueue()
        for build in buildings:
            lines.extend([build[0], build[1]])
        lines.sort()
        city, n = 0, len(buildings)
        for line in lines:
            while city < n and buildings[city][0] <= line:
                pq.put([-buildings[city][2], buildings[city][0], buildings[city][1]])
                city += 1
            while not pq.empty() and pq.queue[0][2] <= line:
                pq.get()
            high = 0
            if not pq.empty():
                high = -pq.queue[0][0]
            if len(skys) > 0 and skys[-1][1] == high:
                continue
            skys.append([line, high])
        return skys
```

#### C++

```cpp
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> poss;
        map<int, int> m;
        for (auto v : buildings) {
            poss.insert(v[0]);
            poss.insert(v[1]);
        }

        int i = 0;
        for (int pos : poss)
            m.insert(pair<int, int>(pos, i++));

        vector<int> highs(m.size(), 0);
        for (auto v : buildings) {
            const int b = m[v[0]], e = m[v[1]];
            for (int i = b; i < e; ++i)
                highs[i] = max(highs[i], v[2]);
        }

        vector<pair<int, int>> res;
        vector<int> mm(poss.begin(), poss.end());
        for (int i = 0; i < highs.size(); ++i) {
            if (highs[i] != highs[i + 1])
                res.push_back(pair<int, int>(mm[i], highs[i]));
            else {
                const int start = i;
                res.push_back(pair<int, int>(mm[start], highs[i]));
                while (highs[i] == highs[i + 1])
                    ++i;
            }
        }
        return res;
    }
};
```

#### Go

```go
type Matrix struct{ left, right, height int }
type Queue []Matrix

func (q Queue) Len() int           { return len(q) }
func (q Queue) Top() Matrix        { return q[0] }
func (q Queue) Swap(i, j int)      { q[i], q[j] = q[j], q[i] }
func (q Queue) Less(i, j int) bool { return q[i].height > q[j].height }
func (q *Queue) Push(x any)        { *q = append(*q, x.(Matrix)) }
func (q *Queue) Pop() any {
	old, x := *q, (*q)[len(*q)-1]
	*q = old[:len(old)-1]
	return x
}

func getSkyline(buildings [][]int) [][]int {
	skys, lines, pq := make([][]int, 0), make([]int, 0), &Queue{}
	heap.Init(pq)
	for _, v := range buildings {
		lines = append(lines, v[0], v[1])
	}
	sort.Ints(lines)
	city, n := 0, len(buildings)
	for _, line := range lines {
		// 将所有符合条件的矩形加入队列
		for ; city < n && buildings[city][0] <= line && buildings[city][1] > line; city++ {
			v := Matrix{left: buildings[city][0], right: buildings[city][1], height: buildings[city][2]}
			heap.Push(pq, v)
		}
		// 从队列移除不符合条件的矩形
		for pq.Len() > 0 && pq.Top().right <= line {
			heap.Pop(pq)
		}
		high := 0
		// 队列为空说明是最右侧建筑物的终点，其轮廓点为 (line, 0)
		if pq.Len() != 0 {
			high = pq.Top().height
		}
		// 如果该点高度和前一个轮廓点一样的话，直接忽略
		if len(skys) > 0 && skys[len(skys)-1][1] == high {
			continue
		}
		skys = append(skys, []int{line, high})
	}
	return skys
}
```

#### Rust

```rust
impl Solution {
    pub fn get_skyline(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut skys: Vec<Vec<i32>> = vec![];
        let mut lines = vec![];
        for building in buildings.iter() {
            lines.push(building[0]);
            lines.push(building[1]);
        }
        lines.sort_unstable();
        let mut pq = std::collections::BinaryHeap::new();
        let (mut city, n) = (0, buildings.len());

        for line in lines {
            while city < n && buildings[city][0] <= line && buildings[city][1] > line {
                pq.push((buildings[city][2], buildings[city][1]));
                city += 1;
            }
            while !pq.is_empty() && pq.peek().unwrap().1 <= line {
                pq.pop();
            }
            let mut high = 0;
            if !pq.is_empty() {
                high = pq.peek().unwrap().0;
            }
            if !skys.is_empty() && skys.last().unwrap()[1] == high {
                continue;
            }
            skys.push(vec![line, high]);
        }
        skys
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [219. 存在重复元素 II](https://leetcode.cn/problems/contains-duplicate-ii){#219}

{{< tabs "219" >}}

{{% tab "python" %}}
```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i, x in enumerate(nums):
            if x in d and i - d[x] <= k:
                return True
            d[x] = i
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (i - d.getOrDefault(nums[i], -1000000) <= k) {
                return true;
            }
            d.put(nums[i], i);
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            if (d.count(nums[i]) && i - d[nums[i]] <= k) {
                return true;
            }
            d[nums[i]] = i;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func containsNearbyDuplicate(nums []int, k int) bool {
	d := map[int]int{}
	for i, x := range nums {
		if j, ok := d[x]; ok && i-j <= k {
			return true
		}
		d[x] = i
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function containsNearbyDuplicate(nums: number[], k: number): boolean {
    const d: Map<number, number> = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (d.has(nums[i]) && i - d.get(nums[i])! <= k) {
            return true;
        }
        d.set(nums[i], i);
    }
    return false;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
    const d = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (d.has(nums[i]) && i - d.get(nums[i]) <= k) {
            return true;
        }
        d.set(nums[i], i);
    }
    return false;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        var d = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; ++i) {
            if (d.ContainsKey(nums[i]) && i - d[nums[i]] <= k) {
                return true;
            }
            d[nums[i]] = i;
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function containsNearbyDuplicate($nums, $k) {
        $d = [];
        for ($i = 0; $i < count($nums); ++$i) {
            if (array_key_exists($nums[$i], $d) && $i - $d[$nums[$i]] <= $k) {
                return true;
            }
            $d[$nums[$i]] = $i;
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

<p>给你一个整数数组&nbsp;<code>nums</code> 和一个整数&nbsp;<code>k</code> ，判断数组中是否存在两个 <strong>不同的索引</strong><em>&nbsp;</em><code>i</code>&nbsp;和<em>&nbsp;</em><code>j</code> ，满足 <code>nums[i] == nums[j]</code> 且 <code>abs(i - j) &lt;= k</code> 。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1], k<em> </em>= 3
<strong>输出：</strong>true</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,1,1], k<em> </em>=<em> </em>1
<strong>输出：</strong>true</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,1,2,3], k<em> </em>=<em> </em>2
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $\textit{d}$ 存放最近遍历到的数以及对应的下标。

遍历数组 $\textit{nums}$，对于当前遍历到的元素 $\textit{nums}[i]$，如果在哈希表中存在，并且下标与当前元素的下标之差不超过 $k$，则返回 $\text{true}$，否则将当前元素加入哈希表中。

遍历结束后，返回 $\text{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i, x in enumerate(nums):
            if x in d and i - d[x] <= k:
                return True
            d[x] = i
        return False
```

#### Java

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (i - d.getOrDefault(nums[i], -1000000) <= k) {
                return true;
            }
            d.put(nums[i], i);
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            if (d.count(nums[i]) && i - d[nums[i]] <= k) {
                return true;
            }
            d[nums[i]] = i;
        }
        return false;
    }
};
```

#### Go

```go
func containsNearbyDuplicate(nums []int, k int) bool {
	d := map[int]int{}
	for i, x := range nums {
		if j, ok := d[x]; ok && i-j <= k {
			return true
		}
		d[x] = i
	}
	return false
}
```

#### TypeScript

```ts
function containsNearbyDuplicate(nums: number[], k: number): boolean {
    const d: Map<number, number> = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (d.has(nums[i]) && i - d.get(nums[i])! <= k) {
            return true;
        }
        d.set(nums[i], i);
    }
    return false;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
    const d = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (d.has(nums[i]) && i - d.get(nums[i]) <= k) {
            return true;
        }
        d.set(nums[i], i);
    }
    return false;
};
```

#### C#

```cs
public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        var d = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; ++i) {
            if (d.ContainsKey(nums[i]) && i - d[nums[i]] <= k) {
                return true;
            }
            d[nums[i]] = i;
        }
        return false;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function containsNearbyDuplicate($nums, $k) {
        $d = [];
        for ($i = 0; $i < count($nums); ++$i) {
            if (array_key_exists($nums[$i], $d) && $i - $d[$nums[$i]] <= $k) {
                return true;
            }
            $d[$nums[$i]] = $i;
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

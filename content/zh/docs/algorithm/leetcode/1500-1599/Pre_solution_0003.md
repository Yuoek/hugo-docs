---
title: "1520_最多的不重叠子字符串"
date: 2025-10-08T18:37:33+08:00
weight: 3
tags: [二分查找, 位运算, 前缀和, 动态规划, 单调栈, 哈希表, 字符串, 数学, 数据库, 数组, 栈, 树, 深度优先搜索, 线段树, 贪心]
---

{{< markmap >}}
### [1520_最多的不重叠子字符串](#1520)
#### [贪心](#1520)
#### [字符串](#1520)
### [1521_找到最接近目标值的函数值](#1521)
#### [位运算](#1521)
#### [线段树](#1521)
#### [数组](#1521)
#### [二分查找](#1521)
### [1522_N 叉树的直径 🔒](#1522)
#### [树](#1522)
#### [深度优先搜索](#1522)
### [1523_在区间范围内统计奇数数目](#1523)
#### [数学](#1523)
### [1524_和为奇数的子数组数目](#1524)
#### [数组](#1524)
#### [数学](#1524)
#### [动态规划](#1524)
#### [前缀和](#1524)
### [1525_字符串的好分割数目](#1525)
#### [位运算](#1525)
#### [哈希表](#1525)
#### [字符串](#1525)
#### [动态规划](#1525)
### [1526_形成目标数组的子数组最少增加次数](#1526)
#### [栈](#1526)
#### [贪心](#1526)
#### [数组](#1526)
#### [动态规划](#1526)
#### [单调栈](#1526)
### [1527_患某种疾病的患者](#1527)
#### [数据库](#1527)
### [1528_重新排列字符串](#1528)
#### [数组](#1528)
#### [字符串](#1528)
### [1529_最少的后缀翻转次数](#1529)
#### [贪心](#1529)
#### [字符串](#1529)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1520_最多的不重叠子字符串
___
#### 贪心
___
#### 字符串
---
### 1521_找到最接近目标值的函数值
___
#### 位运算
___
#### 线段树
___
#### 数组
___
#### 二分查找
---
### 1522_N 叉树的直径 🔒
___
#### 树
___
#### 深度优先搜索
---
### 1523_在区间范围内统计奇数数目
___
#### 数学
---
### 1524_和为奇数的子数组数目
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 前缀和
---
### 1525_字符串的好分割数目
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 1526_形成目标数组的子数组最少增加次数
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
---
### 1527_患某种疾病的患者
___
#### 数据库
---
### 1528_重新排列字符串
___
#### 数组
___
#### 字符串
---
### 1529_最少的后缀翻转次数
___
#### 贪心
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 单调栈 | 哈希表 |
| 字符串 | 数学 | 数据库 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 线段树 | 贪心 |

# [1520. 最多的不重叠子字符串](https://leetcode.cn/problems/maximum-number-of-non-overlapping-substrings){#1520}

{{< tabs "1520" >}}

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

<p>给你一个只包含小写字母的字符串&nbsp;<code>s</code>&nbsp;，你需要找到 <code>s</code>&nbsp;中最多数目的非空子字符串，满足如下条件：</p>

<ol>
	<li>这些字符串之间互不重叠，也就是说对于任意两个子字符串&nbsp;<code>s[i..j]</code> 和&nbsp;<code>s[x..y]</code>&nbsp;，要么&nbsp;<code>j &lt; x</code>&nbsp;要么&nbsp;<code>i &gt; y</code>&nbsp;。</li>
	<li>如果一个子字符串包含字符&nbsp;<code>char</code> ，那么&nbsp;<code>s</code>&nbsp;中所有&nbsp;<code>char</code> 字符都应该在这个子字符串中。</li>
</ol>

<p>请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。</p>

<p>请注意，你可以以 <strong>任意</strong>&nbsp;顺序返回最优解的子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "adefaddaccc"
<strong>输出：</strong>["e","f","ccc"]
<strong>解释：</strong>下面为所有满足第二个条件的子字符串：
[
&nbsp; "adefaddaccc"
&nbsp; "adefadda",
&nbsp; "ef",
&nbsp; "e",
  "f",
&nbsp; "ccc",
]
如果我们选择第一个字符串，那么我们无法再选择其他任何字符串，所以答案为 1 。如果我们选择 "adefadda" ，剩下子字符串中我们只可以选择 "ccc" ，它是唯一不重叠的子字符串，所以答案为 2 。同时我们可以发现，选择 "ef" 不是最优的，因为它可以被拆分成 2 个子字符串。所以最优解是选择 ["e","f","ccc"] ，答案为 3 。不存在别的相同数目子字符串解。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abbaccd"
<strong>输出：</strong>["d","bb","cc"]
<strong>解释：</strong>注意到解 ["d","abba","cc"] 答案也为 3 ，但它不是最优解，因为它的总长度更长。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
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

# [1521. 找到最接近目标值的函数值](https://leetcode.cn/problems/find-a-value-of-a-mysterious-function-closest-to-target){#1521}

{{< tabs "1521" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        ans = abs(arr[0] - target)
        s = {arr[0]}
        for x in arr:
            s = {x & y for y in s} | {x}
            ans = min(ans, min(abs(y - target) for y in s))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int closestToTarget(int[] arr, int target) {
        int ans = Math.abs(arr[0] - target);
        Set<Integer> pre = new HashSet<>();
        pre.add(arr[0]);
        for (int x : arr) {
            Set<Integer> cur = new HashSet<>();
            for (int y : pre) {
                cur.add(x & y);
            }
            cur.add(x);
            for (int y : cur) {
                ans = Math.min(ans, Math.abs(y - target));
            }
            pre = cur;
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
    int closestToTarget(vector<int>& arr, int target) {
        int ans = abs(arr[0] - target);
        unordered_set<int> pre;
        pre.insert(arr[0]);
        for (int x : arr) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int y : pre) {
                cur.insert(x & y);
            }
            for (int y : cur) {
                ans = min(ans, abs(y - target));
            }
            pre = move(cur);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closestToTarget(arr []int, target int) int {
	ans := abs(arr[0] - target)
	pre := map[int]bool{arr[0]: true}
	for _, x := range arr {
		cur := map[int]bool{x: true}
		for y := range pre {
			cur[x&y] = true
		}
		for y := range cur {
			ans = min(ans, abs(y-target))
		}
		pre = cur
	}
	return ans
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
function closestToTarget(arr: number[], target: number): number {
    let ans = Math.abs(arr[0] - target);
    let pre = new Set<number>();
    pre.add(arr[0]);
    for (const x of arr) {
        const cur = new Set<number>();
        cur.add(x);
        for (const y of pre) {
            cur.add(x & y);
        }
        for (const y of cur) {
            ans = Math.min(ans, Math.abs(y - target));
        }
        pre = cur;
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

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1521.Find%20a%20Value%20of%20a%20Mysterious%20Function%20Closest%20to%20Target/images/change.png" style="height: 312px; width: 635px;"></p>

<p>Winston 构造了一个如上所示的函数&nbsp;<code>func</code>&nbsp;。他有一个整数数组&nbsp;<code>arr</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;，他想找到让&nbsp;<code>|func(arr, l, r) - target|</code>&nbsp;最小的 <code>l</code>&nbsp;和 <code>r</code>&nbsp;。</p>

<p>请你返回&nbsp;<code>|func(arr, l, r) - target|</code>&nbsp;的最小值。</p>

<p>请注意，&nbsp;<code>func</code> 的输入参数&nbsp;<code>l</code> 和&nbsp;<code>r</code>&nbsp;需要满足&nbsp;<code>0 &lt;= l, r &lt; arr.length</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [9,12,3,7,15], target = 5
<strong>输出：</strong>2
<strong>解释：</strong>所有可能的 [l,r] 数对包括 [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]]， Winston 得到的相应结果为 [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0] 。最接近 5 的值是 7 和 3，所以最小差值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1000000,1000000,1000000], target = 1
<strong>输出：</strong>999999
<strong>解释：</strong>Winston 输入函数的所有可能 [l,r] 数对得到的函数值都为 1000000 ，所以最小差值为 999999 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,4,8,16], target = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^6</code></li>
	<li><code>0 &lt;= target &lt;= 10^7</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

根据题目描述，我们知道，函数 $func(arr, l, r)$ 实际上就是数组 $arr$ 下标 $l$ 到 $r$ 的元素的按位与运算的结果，即 $arr[l] \& arr[l + 1] \& \cdots \& arr[r]$。

如果我们每次固定右端点 $r$，那么左端点 $l$ 的范围是 $[0, r]$。由于按位与之和随着 $l$ 的减小而单调递减，并且 $arr[i]$ 的值不超过 $10^6$，因此区间 $[0, r]$ 最多只有 $20$ 种不同的值。因此，我们可以用一个集合来维护所有的 $arr[l] \& arr[l + 1] \& \cdots \& arr[r]$ 的值。当我们从 $r$ 遍历到 $r+1$ 时，以 $r+1$ 为右端点的值，就是集合中每个值与 $arr[r + 1]$ 进行按位与运算得到的值，再加上 $arr[r + 1]$ 本身。因此，我们只需要枚举集合中的每个值，与 $arr[r]$ 进行按位与运算，就可以得到以 $r$ 为右端点的所有值，将每个值与 $target$ 相减后取绝对值，就可以得到以 $r$ 为右端点的所有值与 $target$ 的差的绝对值，其中的最小值就是答案。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 和 $M$ 分别是数组 $arr$ 的长度和数组 $arr$ 中的最大值。

相似题目：

-   [3171. 找到按位与最接近 K 的子数组](https://github.com/doocs/leetcode/blob/main/solution/3100-3199/3171.Find%20Subarray%20With%20Bitwise%20AND%20Closest%20to%20K/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        ans = abs(arr[0] - target)
        s = {arr[0]}
        for x in arr:
            s = {x & y for y in s} | {x}
            ans = min(ans, min(abs(y - target) for y in s))
        return ans
```

#### Java

```java
class Solution {
    public int closestToTarget(int[] arr, int target) {
        int ans = Math.abs(arr[0] - target);
        Set<Integer> pre = new HashSet<>();
        pre.add(arr[0]);
        for (int x : arr) {
            Set<Integer> cur = new HashSet<>();
            for (int y : pre) {
                cur.add(x & y);
            }
            cur.add(x);
            for (int y : cur) {
                ans = Math.min(ans, Math.abs(y - target));
            }
            pre = cur;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans = abs(arr[0] - target);
        unordered_set<int> pre;
        pre.insert(arr[0]);
        for (int x : arr) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int y : pre) {
                cur.insert(x & y);
            }
            for (int y : cur) {
                ans = min(ans, abs(y - target));
            }
            pre = move(cur);
        }
        return ans;
    }
};
```

#### Go

```go
func closestToTarget(arr []int, target int) int {
	ans := abs(arr[0] - target)
	pre := map[int]bool{arr[0]: true}
	for _, x := range arr {
		cur := map[int]bool{x: true}
		for y := range pre {
			cur[x&y] = true
		}
		for y := range cur {
			ans = min(ans, abs(y-target))
		}
		pre = cur
	}
	return ans
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
function closestToTarget(arr: number[], target: number): number {
    let ans = Math.abs(arr[0] - target);
    let pre = new Set<number>();
    pre.add(arr[0]);
    for (const x of arr) {
        const cur = new Set<number>();
        cur.add(x);
        for (const y of pre) {
            cur.add(x & y);
        }
        for (const y of cur) {
            ans = Math.min(ans, Math.abs(y - target));
        }
        pre = cur;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1522. N 叉树的直径 🔒](https://leetcode.cn/problems/diameter-of-n-ary-tree){#1522}

{{< tabs "1522" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """

        def build(root):
            nonlocal d
            if root is None:
                return
            for child in root.children:
                d[root].add(child)
                d[child].add(root)
                build(child)

        def dfs(u, t):
            nonlocal ans, vis, d, next
            if u in vis:
                return
            vis.add(u)
            for v in d[u]:
                dfs(v, t + 1)
            if ans < t:
                ans = t
                next = u

        d = defaultdict(set)
        vis = set()
        build(root)
        ans = 0
        next = None
        dfs(root, 0)
        vis.clear()
        dfs(next, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private Map<Node, Set<Node>> g;
    private Set<Node> vis;
    private Node next;
    private int ans;

    public int diameter(Node root) {
        g = new HashMap<>();
        build(root);
        vis = new HashSet<>();
        next = root;
        ans = 0;
        dfs(next, 0);
        vis.clear();
        dfs(next, 0);
        return ans;
    }

    private void dfs(Node u, int t) {
        if (vis.contains(u)) {
            return;
        }
        vis.add(u);
        if (t > ans) {
            ans = t;
            next = u;
        }
        if (g.containsKey(u)) {
            for (Node v : g.get(u)) {
                dfs(v, t + 1);
            }
        }
    }

    private void build(Node root) {
        if (root == null) {
            return;
        }
        for (Node child : root.children) {
            g.computeIfAbsent(root, k -> new HashSet<>()).add(child);
            g.computeIfAbsent(child, k -> new HashSet<>()).add(root);
            build(child);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, unordered_set<Node*>> g;
    unordered_set<Node*> vis;
    Node* next;
    int ans;

    int diameter(Node* root) {
        build(root);
        next = root;
        ans = 0;
        dfs(next, 0);
        vis.clear();
        dfs(next, 0);
        return ans;
    }

    void dfs(Node* u, int t) {
        if (vis.count(u)) return;
        vis.insert(u);
        if (ans < t) {
            ans = t;
            next = u;
        }
        if (g.count(u))
            for (Node* v : g[u])
                dfs(v, t + 1);
    }

    void build(Node* root) {
        if (!root) return;
        for (Node* child : root->children) {
            g[root].insert(child);
            g[child].insert(root);
            build(child);
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func diameter(root *Node) int {
	g := make(map[*Node][]*Node)
	vis := make(map[*Node]bool)
	next := root
	ans := 0
	var build func(root *Node)
	build = func(root *Node) {
		if root == nil {
			return
		}
		for _, child := range root.Children {
			g[root] = append(g[root], child)
			g[child] = append(g[child], root)
			build(child)
		}
	}
	build(root)
	var dfs func(u *Node, t int)
	dfs = func(u *Node, t int) {
		if vis[u] {
			return
		}
		vis[u] = true
		if t > ans {
			ans = t
			next = u
		}
		if vs, ok := g[u]; ok {
			for _, v := range vs {
				dfs(v, t+1)
			}
		}
	}
	dfs(next, 0)
	vis = make(map[*Node]bool)
	dfs(next, 0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵 <code>N 叉树</code> 的根节点&nbsp;<code>root</code>&nbsp;，计算这棵树的直径长度。</p>

<p>N 叉树的直径指的是树中任意两个节点间路径中<strong> 最长 </strong>路径的长度。这条路径可能经过根节点，也可能不经过根节点。</p>

<p><em>（N 叉树的输入序列以层序遍历的形式给出，每组子节点用 null 分隔）</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1522.Diameter%20of%20N-Ary%20Tree/images/sample_2_1897.png" style="height:173px; width:324px" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>3
<strong>解释：</strong>直径如图中红线所示。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1522.Diameter%20of%20N-Ary%20Tree/images/sample_1_1897.png" style="height:246px; width:253px" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,null,2,null,3,4,null,5,null,6]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1522.Diameter%20of%20N-Ary%20Tree/images/sample_3_1897.png" style="height:326px; width:369px" /></p>

<pre>
<strong>输入:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出:</strong> 7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>N 叉树的深度小于或等于&nbsp;<code>1000</code>&nbsp;。</li>
	<li>节点的总个数在&nbsp;<code>[0,&nbsp;10^4]</code>&nbsp;间。</li>
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
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """

        def dfs(root):
            if root is None:
                return 0
            nonlocal ans
            m1 = m2 = 0
            for child in root.children:
                t = dfs(child)
                if t > m1:
                    m2, m1 = m1, t
                elif t > m2:
                    m2 = t
            ans = max(ans, m1 + m2)
            return 1 + m1

        ans = 0
        dfs(root)
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private int ans;

    public int diameter(Node root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    private int dfs(Node root) {
        if (root == null) {
            return 0;
        }
        int m1 = 0, m2 = 0;
        for (Node child : root.children) {
            int t = dfs(child);
            if (t > m1) {
                m2 = m1;
                m1 = t;
            } else if (t > m2) {
                m2 = t;
            }
        }
        ans = Math.max(ans, m1 + m2);
        return 1 + m1;
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans;

    int diameter(Node* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    int dfs(Node* root) {
        if (!root) return 0;
        int m1 = 0, m2 = 0;
        for (Node* child : root->children) {
            int t = dfs(child);
            if (t > m1) {
                m2 = m1;
                m1 = t;
            } else if (t > m2)
                m2 = t;
        }
        ans = max(ans, m1 + m2);
        return 1 + m1;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func diameter(root *Node) int {
	ans := 0
	var dfs func(root *Node) int
	dfs = func(root *Node) int {
		if root == nil {
			return 0
		}
		m1, m2 := 0, 0
		for _, child := range root.Children {
			t := dfs(child)
			if t > m1 {
				m2, m1 = m1, t
			} else if t > m2 {
				m2 = t
			}
		}
		ans = max(ans, m1+m2)
		return 1 + m1
	}
	dfs(root)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""


class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """

        def build(root):
            nonlocal d
            if root is None:
                return
            for child in root.children:
                d[root].add(child)
                d[child].add(root)
                build(child)

        def dfs(u, t):
            nonlocal ans, vis, d, next
            if u in vis:
                return
            vis.add(u)
            for v in d[u]:
                dfs(v, t + 1)
            if ans < t:
                ans = t
                next = u

        d = defaultdict(set)
        vis = set()
        build(root)
        ans = 0
        next = None
        dfs(root, 0)
        vis.clear()
        dfs(next, 0)
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private Map<Node, Set<Node>> g;
    private Set<Node> vis;
    private Node next;
    private int ans;

    public int diameter(Node root) {
        g = new HashMap<>();
        build(root);
        vis = new HashSet<>();
        next = root;
        ans = 0;
        dfs(next, 0);
        vis.clear();
        dfs(next, 0);
        return ans;
    }

    private void dfs(Node u, int t) {
        if (vis.contains(u)) {
            return;
        }
        vis.add(u);
        if (t > ans) {
            ans = t;
            next = u;
        }
        if (g.containsKey(u)) {
            for (Node v : g.get(u)) {
                dfs(v, t + 1);
            }
        }
    }

    private void build(Node root) {
        if (root == null) {
            return;
        }
        for (Node child : root.children) {
            g.computeIfAbsent(root, k -> new HashSet<>()).add(child);
            g.computeIfAbsent(child, k -> new HashSet<>()).add(root);
            build(child);
        }
    }
}
```

#### C++

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, unordered_set<Node*>> g;
    unordered_set<Node*> vis;
    Node* next;
    int ans;

    int diameter(Node* root) {
        build(root);
        next = root;
        ans = 0;
        dfs(next, 0);
        vis.clear();
        dfs(next, 0);
        return ans;
    }

    void dfs(Node* u, int t) {
        if (vis.count(u)) return;
        vis.insert(u);
        if (ans < t) {
            ans = t;
            next = u;
        }
        if (g.count(u))
            for (Node* v : g[u])
                dfs(v, t + 1);
    }

    void build(Node* root) {
        if (!root) return;
        for (Node* child : root->children) {
            g[root].insert(child);
            g[child].insert(root);
            build(child);
        }
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func diameter(root *Node) int {
	g := make(map[*Node][]*Node)
	vis := make(map[*Node]bool)
	next := root
	ans := 0
	var build func(root *Node)
	build = func(root *Node) {
		if root == nil {
			return
		}
		for _, child := range root.Children {
			g[root] = append(g[root], child)
			g[child] = append(g[child], root)
			build(child)
		}
	}
	build(root)
	var dfs func(u *Node, t int)
	dfs = func(u *Node, t int) {
		if vis[u] {
			return
		}
		vis[u] = true
		if t > ans {
			ans = t
			next = u
		}
		if vs, ok := g[u]; ok {
			for _, v := range vs {
				dfs(v, t+1)
			}
		}
	}
	dfs(next, 0)
	vis = make(map[*Node]bool)
	dfs(next, 0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1523. 在区间范围内统计奇数数目](https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range){#1523}

{{< tabs "1523" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return ((high + 1) >> 1) - (low >> 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOdds(int low, int high) {
        return ((high + 1) >> 1) - (low >> 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1 >> 1) - (low >> 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOdds(low int, high int) int {
	return ((high + 1) >> 1) - (low >> 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOdds(low: number, high: number): number {
    return ((high + 1) >> 1) - (low >> 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        ((high + 1) >> 1) - (low >> 1)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $low
     * @param Integer $high
     * @return Integer
     */
    function countOdds($low, $high) {
        return ($high + 1 >> 1) - ($low >> 1);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countOdds(int low, int high) {
    return ((high + 1) >> 1) - (low >> 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个非负整数&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;。请你返回<em>&nbsp;</em><code>low</code><em> </em>和<em>&nbsp;</em><code>high</code><em>&nbsp;</em>之间（包括二者）奇数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>low = 3, high = 7
<strong>输出：</strong>3
<strong>解释：</strong>3 到 7 之间奇数数字为 [3,5,7] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>low = 8, high = 10
<strong>输出：</strong>1
<strong>解释：</strong>8 到 10 之间奇数数字为 [9] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和思想

`[0, x]` 之间的奇数个数为 `(x + 1) >> 1`，那么 `[low, high]` 之间的奇数个数为 `((high + 1) >> 1) - (low >> 1)`。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return ((high + 1) >> 1) - (low >> 1)
```

#### Java

```java
class Solution {
    public int countOdds(int low, int high) {
        return ((high + 1) >> 1) - (low >> 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1 >> 1) - (low >> 1);
    }
};
```

#### Go

```go
func countOdds(low int, high int) int {
	return ((high + 1) >> 1) - (low >> 1)
}
```

#### TypeScript

```ts
function countOdds(low: number, high: number): number {
    return ((high + 1) >> 1) - (low >> 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        ((high + 1) >> 1) - (low >> 1)
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $low
     * @param Integer $high
     * @return Integer
     */
    function countOdds($low, $high) {
        return ($high + 1 >> 1) - ($low >> 1);
    }
}
```

#### C

```c
int countOdds(int low, int high) {
    return ((high + 1) >> 1) - (low >> 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1524. 和为奇数的子数组数目](https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum){#1524}

{{< tabs "1524" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        cnt = [1, 0]
        ans = s = 0
        for x in arr:
            s += x
            ans = (ans + cnt[s & 1 ^ 1]) % mod
            cnt[s & 1] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numOfSubarrays(int[] arr) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = {1, 0};
        int ans = 0, s = 0;
        for (int x : arr) {
            s += x;
            ans = (ans + cnt[s & 1 ^ 1]) % mod;
            ++cnt[s & 1];
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
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int cnt[2] = {1, 0};
        int ans = 0, s = 0;
        for (int x : arr) {
            s += x;
            ans = (ans + cnt[s & 1 ^ 1]) % mod;
            ++cnt[s & 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfSubarrays(arr []int) (ans int) {
	const mod int = 1e9 + 7
	cnt := [2]int{1, 0}
	s := 0
	for _, x := range arr {
		s += x
		ans = (ans + cnt[s&1^1]) % mod
		cnt[s&1]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfSubarrays(arr: number[]): number {
    let ans = 0;
    let s = 0;
    const cnt: number[] = [1, 0];
    const mod = 1e9 + 7;
    for (const x of arr) {
        s += x;
        ans = (ans + cnt[(s & 1) ^ 1]) % mod;
        cnt[s & 1]++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut cnt = [1, 0];
        let mut ans = 0;
        let mut s = 0;
        for &x in arr.iter() {
            s += x;
            ans = (ans + cnt[((s & 1) ^ 1) as usize]) % MOD;
            cnt[(s & 1) as usize] += 1;
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

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;。请你返回和为 <strong>奇数</strong>&nbsp;的子数组数目。</p>

<p>由于答案可能会很大，请你将结果对&nbsp;<code>10^9 + 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,5]
<strong>输出：</strong>4
<strong>解释：</strong>所有的子数组为 [[1],[1,3],[1,3,5],[3],[3,5],[5]] 。
所有子数组的和为 [1,4,9,3,8,5].
奇数和包括 [1,9,3,5] ，所以答案为 4 。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>arr = [2,4,6]
<strong>输出：</strong>0
<strong>解释：</strong>所有子数组为 [[2],[2,4],[2,4,6],[4],[4,6],[6]] 。
所有子数组和为 [2,6,12,4,10,6] 。
所有子数组和都是偶数，所以答案为 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,4,5,6,7]
<strong>输出：</strong>16
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [100,100,99,99]
<strong>输出：</strong>4
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [7]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 计数器

我们定义一个长度为 $2$ 的数组 $\textit{cnt}$ 作为计数器，其中 $\textit{cnt}[0]$ 和 $\textit{cnt}[1]$ 分别表示前缀和为偶数和奇数的子数组的个数。初始时 $\textit{cnt}[0] = 1$，而 $\textit{cnt}[1] = 0$。

接下来，我们维护当前的前缀和 $s$，初始时 $s = 0$。

遍历数组 $\textit{arr}$，对于遍历到的每个元素 $x$，我们将 $s$ 的值加上 $x$，然后根据 $s$ 的奇偶性，将 $\textit{cnt}[s \mod 2 \oplus 1]$ 的值累加到答案中，然后我们将 $\textit{cnt}[s \mod 2]$ 的值加 $1$。

遍历结束后，我们即可得到答案。注意答案的取模运算。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        cnt = [1, 0]
        ans = s = 0
        for x in arr:
            s += x
            ans = (ans + cnt[s & 1 ^ 1]) % mod
            cnt[s & 1] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numOfSubarrays(int[] arr) {
        final int mod = (int) 1e9 + 7;
        int[] cnt = {1, 0};
        int ans = 0, s = 0;
        for (int x : arr) {
            s += x;
            ans = (ans + cnt[s & 1 ^ 1]) % mod;
            ++cnt[s & 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int cnt[2] = {1, 0};
        int ans = 0, s = 0;
        for (int x : arr) {
            s += x;
            ans = (ans + cnt[s & 1 ^ 1]) % mod;
            ++cnt[s & 1];
        }
        return ans;
    }
};
```

#### Go

```go
func numOfSubarrays(arr []int) (ans int) {
	const mod int = 1e9 + 7
	cnt := [2]int{1, 0}
	s := 0
	for _, x := range arr {
		s += x
		ans = (ans + cnt[s&1^1]) % mod
		cnt[s&1]++
	}
	return
}
```

#### TypeScript

```ts
function numOfSubarrays(arr: number[]): number {
    let ans = 0;
    let s = 0;
    const cnt: number[] = [1, 0];
    const mod = 1e9 + 7;
    for (const x of arr) {
        s += x;
        ans = (ans + cnt[(s & 1) ^ 1]) % mod;
        cnt[s & 1]++;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut cnt = [1, 0];
        let mut ans = 0;
        let mut s = 0;
        for &x in arr.iter() {
            s += x;
            ans = (ans + cnt[((s & 1) ^ 1) as usize]) % MOD;
            cnt[(s & 1) as usize] += 1;
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

# [1525. 字符串的好分割数目](https://leetcode.cn/problems/number-of-good-ways-to-split-a-string){#1525}

{{< tabs "1525" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSplits(self, s: str) -> int:
        cnt = Counter(s)
        vis = set()
        ans = 0
        for c in s:
            vis.add(c)
            cnt[c] -= 1
            if cnt[c] == 0:
                cnt.pop(c)
            ans += len(vis) == len(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSplits(String s) {
        Map<Character, Integer> cnt = new HashMap<>();
        for (char c : s.toCharArray()) {
            cnt.merge(c, 1, Integer::sum);
        }
        Set<Character> vis = new HashSet<>();
        int ans = 0;
        for (char c : s.toCharArray()) {
            vis.add(c);
            if (cnt.merge(c, -1, Integer::sum) == 0) {
                cnt.remove(c);
            }
            if (vis.size() == cnt.size()) {
                ++ans;
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
    int numSplits(string s) {
        unordered_map<char, int> cnt;
        for (char& c : s) {
            ++cnt[c];
        }
        unordered_set<char> vis;
        int ans = 0;
        for (char& c : s) {
            vis.insert(c);
            if (--cnt[c] == 0) {
                cnt.erase(c);
            }
            ans += vis.size() == cnt.size();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSplits(s string) (ans int) {
	cnt := map[rune]int{}
	for _, c := range s {
		cnt[c]++
	}
	vis := map[rune]bool{}
	for _, c := range s {
		vis[c] = true
		cnt[c]--
		if cnt[c] == 0 {
			delete(cnt, c)
		}
		if len(vis) == len(cnt) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，一个分割被称为 「好分割」&nbsp;当它满足：将&nbsp;<code>s</code>&nbsp;分割成 2 个字符串&nbsp;<code>p</code> 和&nbsp;<code>q</code>&nbsp;，它们连接起来等于&nbsp;<code>s</code>&nbsp;且 <code>p</code>&nbsp;和 <code>q</code>&nbsp;中不同字符的数目相同。</p>

<p>请你返回 <code>s</code>&nbsp;中好分割的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;aacaba&quot;
<strong>输出：</strong>2
<strong>解释：</strong>总共有 5 种分割字符串 <code>&quot;aacaba&quot;</code> 的方法，其中 2 种是好分割。
(&quot;a&quot;, &quot;acaba&quot;) 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
(&quot;aa&quot;, &quot;caba&quot;) 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
(&quot;aac&quot;, &quot;aba&quot;) 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
(&quot;aaca&quot;, &quot;ba&quot;) 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
(&quot;aacab&quot;, &quot;a&quot;) 左边字符串和右边字符串分别包含 3 个和 1 个不同的字符。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcd&quot;
<strong>输出：</strong>1
<strong>解释：</strong>好分割为将字符串分割成 (&quot;ab&quot;, &quot;cd&quot;) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaaaa&quot;
<strong>输出：</strong>4
<strong>解释：</strong>所有分割都是好分割。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;acbadbaada&quot;
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们维护两个哈希表，分别记录左侧出现的字符、右侧的字符以及出现的次数。初始时，左侧的哈希表为空，右侧的哈希表为字符串 $s$ 中所有字符出现的次数。

接下来，我们从左到右遍历字符串 $s$，对于遍历到的字符 $c$，我们将其加入左侧的哈希表，同时将其在右侧的哈希表中的出现次数减一。如果减一后，右侧哈希表中的出现次数为 0，则将其从右侧哈希表中移除。然后，我们判断左侧哈希表中的键值对数量是否与右侧哈希表中的键值对数量相等，如果相等，则将答案加一。

最终，我们返回答案即可。

时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSplits(self, s: str) -> int:
        cnt = Counter(s)
        vis = set()
        ans = 0
        for c in s:
            vis.add(c)
            cnt[c] -= 1
            if cnt[c] == 0:
                cnt.pop(c)
            ans += len(vis) == len(cnt)
        return ans
```

#### Java

```java
class Solution {
    public int numSplits(String s) {
        Map<Character, Integer> cnt = new HashMap<>();
        for (char c : s.toCharArray()) {
            cnt.merge(c, 1, Integer::sum);
        }
        Set<Character> vis = new HashSet<>();
        int ans = 0;
        for (char c : s.toCharArray()) {
            vis.add(c);
            if (cnt.merge(c, -1, Integer::sum) == 0) {
                cnt.remove(c);
            }
            if (vis.size() == cnt.size()) {
                ++ans;
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
    int numSplits(string s) {
        unordered_map<char, int> cnt;
        for (char& c : s) {
            ++cnt[c];
        }
        unordered_set<char> vis;
        int ans = 0;
        for (char& c : s) {
            vis.insert(c);
            if (--cnt[c] == 0) {
                cnt.erase(c);
            }
            ans += vis.size() == cnt.size();
        }
        return ans;
    }
};
```

#### Go

```go
func numSplits(s string) (ans int) {
	cnt := map[rune]int{}
	for _, c := range s {
		cnt[c]++
	}
	vis := map[rune]bool{}
	for _, c := range s {
		vis[c] = true
		cnt[c]--
		if cnt[c] == 0 {
			delete(cnt, c)
		}
		if len(vis) == len(cnt) {
			ans++
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1526. 形成目标数组的子数组最少增加次数](https://leetcode.cn/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array){#1526}

{{< tabs "1526" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        return target[0] + sum(max(0, b - a) for a, b in pairwise(target))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumberOperations(int[] target) {
        int f = target[0];
        for (int i = 1; i < target.length; ++i) {
            if (target[i] > target[i - 1]) {
                f += target[i] - target[i - 1];
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
    int minNumberOperations(vector<int>& target) {
        int f = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i - 1]) {
                f += target[i] - target[i - 1];
            }
        }
        return f;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumberOperations(target []int) int {
	f := target[0]
	for i, x := range target[1:] {
		if x > target[i] {
			f += x - target[i]
		}
	}
	return f
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumberOperations(target: number[]): number {
    let f = target[0];
    for (let i = 1; i < target.length; ++i) {
        if (target[i] > target[i - 1]) {
            f += target[i] - target[i - 1];
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

<p>给你一个整数数组&nbsp;<code>target</code>&nbsp;和一个数组&nbsp;<code>initial</code>&nbsp;，<code>initial</code>&nbsp;数组与 <code>target</code>&nbsp; 数组有同样的维度，且一开始全部为 0 。</p>

<p>请你返回从 <code>initial</code>&nbsp;得到&nbsp; <code>target</code>&nbsp;的最少操作次数，每次操作需遵循以下规则：</p>

<ul>
	<li>在 <code>initial</code>&nbsp;中选择 <strong>任意</strong>&nbsp;子数组，并将子数组中每个元素增加 1 。</li>
</ul>

<p>答案保证在 32 位有符号整数以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = [1,2,3,2,1]
<strong>输出：</strong>3
<strong>解释：</strong>我们需要至少 3 次操作从 intial 数组得到 target 数组。
[0,0,0,0,0] 将下标为 0 到 4&nbsp;的元素（包含二者）加 1 。
[1,1,1,1,1] 将下标为 1 到 3 的元素（包含二者）加 1 。
[1,2,2,2,1] 将下表为 2 的元素增加 1 。
[1,2,3,2,1] 得到了目标数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = [3,1,1,2]
<strong>输出：</strong>4
<strong>解释：</strong>(initial)[0,0,0,0] -&gt; [1,1,1,1] -&gt; [1,1,1,2] -&gt; [2,1,1,2] -&gt; [3,1,1,2] (target) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = [3,1,5,4,2]
<strong>输出：</strong>7
<strong>解释：</strong>(initial)[0,0,0,0,0] -&gt; [1,1,1,1,1] -&gt; [2,1,1,1,1] -&gt; [3,1,1,1,1] 
                                  -&gt; [3,1,2,2,2] -&gt; [3,1,3,3,2] -&gt; [3,1,4,4,2] -&gt; [3,1,5,4,2] (target)。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>target = [1,1,1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= target[i] &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示得到 $target[0,..i]$ 的最少操作次数，初始时 $f[0] = target[0]$。

对于 $target[i]$，如果 $target[i] \leq target[i-1]$，则 $f[i] = f[i-1]$；否则 $f[i] = f[i-1] + target[i] - target[i-1]$。

最终答案即为 $f[n-1]$。

我们注意到 $f[i]$ 只与 $f[i-1]$ 有关，因此可以只用一个变量来维护操作次数。

时间复杂度 $O(n)$，其中 $n$ 为数组 $target$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [3229. 使数组等于目标数组所需的最少操作次数](https://github.com/doocs/leetcode/blob/main/solution/3200-3299/3229.Minimum%20Operations%20to%20Make%20Array%20Equal%20to%20Target/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        return target[0] + sum(max(0, b - a) for a, b in pairwise(target))
```

#### Java

```java
class Solution {
    public int minNumberOperations(int[] target) {
        int f = target[0];
        for (int i = 1; i < target.length; ++i) {
            if (target[i] > target[i - 1]) {
                f += target[i] - target[i - 1];
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
    int minNumberOperations(vector<int>& target) {
        int f = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i - 1]) {
                f += target[i] - target[i - 1];
            }
        }
        return f;
    }
};
```

#### Go

```go
func minNumberOperations(target []int) int {
	f := target[0]
	for i, x := range target[1:] {
		if x > target[i] {
			f += x - target[i]
		}
	}
	return f
}
```

#### TypeScript

```ts
function minNumberOperations(target: number[]): number {
    let f = target[0];
    for (let i = 1; i < target.length; ++i) {
        if (target[i] > target[i - 1]) {
            f += target[i] - target[i - 1];
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

# [1527. 患某种疾病的患者](https://leetcode.cn/problems/patients-with-a-condition){#1527}

{{< tabs "1527" >}}

{{% tab "sql" %}}
```sql
SELECT
    patient_id,
    patient_name,
    conditions
FROM patients
WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>患者信息表：&nbsp;<code>Patients</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
在 SQL 中，patient_id （患者 ID）是该表的主键。
'conditions' （疾病）包含 0 个或以上的疾病代码，以空格分隔。
这个表包含医院中患者的信息。</pre>

<p>&nbsp;</p>

<p>查询患有 I 类糖尿病的患者&nbsp;ID （patient_id）、患者姓名（patient_name）以及其患有的所有疾病代码（conditions）。I 类糖尿病的代码总是包含前缀&nbsp;<code>DIAB1</code>&nbsp;。</p>

<p>按 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：
</strong>Patients表：</code>
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel      &nbsp;| YFEV COUGH   |
| 2    &nbsp;     | Alice        |            &nbsp; |
| 3    &nbsp;     | Bob         &nbsp;| DIAB100 MYOP&nbsp;|
| 4 &nbsp;        | George      &nbsp;| ACNE DIAB100&nbsp;|
| 5 &nbsp;        | Alain       &nbsp;| DIAB201     &nbsp;|
+------------+--------------+--------------+
<strong>输出：</strong>
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3    &nbsp;     | Bob         &nbsp;| DIAB100 MYOP&nbsp;|
| 4 &nbsp;        | George   &nbsp;   | ACNE DIAB100&nbsp;| 
+------------+--------------+--------------+
<strong>解释：</strong>Bob 和 George 都患有代码以 DIAB1 开头的疾病。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    patient_id,
    patient_name,
    conditions
FROM patients
WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1528. 重新排列字符串](https://leetcode.cn/problems/shuffle-string){#1528}

{{< tabs "1528" >}}

{{% tab "python" %}}
```python
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans = [0] * len(s)
        for i, c in enumerate(s):
            ans[indices[i]] = c
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] ans = new char[n];
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s.charAt(i);
        }
        return String.valueOf(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func restoreString(s string, indices []int) string {
	ans := make([]rune, len(s))
	for i, c := range s {
		ans[indices[i]] = c
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function (s, indices) {
    let rs = [];
    for (let i = 0; i < s.length; i++) {
        rs[indices[i]] = s[i];
    }
    return rs.join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个 <strong>长度相同</strong> 的整数数组 <code>indices</code> 。</p>

<p>请你重新排列字符串 <code>s</code> ，其中第 <code>i</code> 个字符需要移动到 <code>indices[i]</code> 指示的位置。</p>

<p>返回重新排列后的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1528.Shuffle%20String/images/q1.jpg" /></p>

<pre>
<strong>输入：</strong>s = "codeleet", <code>indices</code> = [4,5,6,7,0,2,1,3]
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>如图所示，"codeleet" 重新排列后变为 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", <code>indices</code> = [0,1,2]
<strong>输出：</strong>"abc"
<strong>解释：</strong>重新排列后，每个字符都还留在原来的位置上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == indices.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>s</code> 仅包含小写英文字母</li>
	<li><code>0 &lt;= indices[i] &lt;&nbsp;n</code></li>
	<li><code>indices</code> 的所有的值都是 <strong>唯一</strong> 的</li>
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
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans = [0] * len(s)
        for i, c in enumerate(s):
            ans[indices[i]] = c
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] ans = new char[n];
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s.charAt(i);
        }
        return String.valueOf(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
```

#### Go

```go
func restoreString(s string, indices []int) string {
	ans := make([]rune, len(s))
	for i, c := range s {
		ans[indices[i]] = c
	}
	return string(ans)
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function (s, indices) {
    let rs = [];
    for (let i = 0; i < s.length; i++) {
        rs[indices[i]] = s[i];
    }
    return rs.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1529. 最少的后缀翻转次数](https://leetcode.cn/problems/minimum-suffix-flips){#1529}

{{< tabs "1529" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, target: str) -> int:
        ans = 0
        for v in target:
            if (ans & 1) ^ int(v):
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(String target) {
        int ans = 0;
        for (int i = 0; i < target.length(); ++i) {
            int v = target.charAt(i) - '0';
            if (((ans & 1) ^ v) != 0) {
                ++ans;
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
    int minFlips(string target) {
        int ans = 0;
        for (char c : target) {
            int v = c - '0';
            if ((ans & 1) ^ v) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(target string) int {
	ans := 0
	for _, c := range target {
		v := int(c - '0')
		if ((ans & 1) ^ v) != 0 {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的二进制字符串 <code>target</code> 。你自己有另一个长度为 <code>n</code> 的二进制字符串 <code>s</code> ，最初每一位上都是 0 。你想要让 <code>s</code> 和 <code>target</code> 相等。</p>

<p>在一步操作，你可以选择下标 <code>i</code>（<code>0 &lt;= i &lt; n</code>）并翻转在 <strong>闭区间</strong> <code>[i, n - 1]</code> 内的所有位。翻转意味着 <code>'0'</code> 变为 <code>'1'</code> ，而 <code>'1'</code> 变为 <code>'0'</code> 。</p>

<div class="original__bRMd">
<div>
<p>返回使<em> </em><code>s</code><em> </em>与<em> </em><code>target</code> 相等需要的最少翻转次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = "10111"
<strong>输出：</strong>3
<strong>解释：</strong>最初，s = "00000" 。
选择下标 i = 2: "00<em><strong>000</strong></em>" -&gt; "00<em><strong>111</strong></em>"
选择下标 i = 0: "<em><strong>00111</strong></em>" -&gt; "<em><strong>11000</strong></em>"
选择下标 i = 1: "1<em><strong>1000</strong></em>" -&gt; "1<em><strong>0111</strong></em>"
要达成目标，需要至少 3 次翻转。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = "101"
<strong>输出：</strong>3
<strong>解释：</strong>最初，s = "000" 。
选择下标 i = 0: "<em><strong>000</strong></em>" -&gt; "<em><strong>111</strong></em>"
选择下标 i = 1: "1<em><strong>11</strong></em>" -&gt; "1<em><strong>00</strong></em>"
选择下标 i = 2: "10<em><strong>0</strong></em>" -&gt; "10<em><strong>1</strong></em>"
要达成目标，需要至少 3 次翻转。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = "00000"
<strong>输出：</strong>0
<strong>解释：</strong>由于 s 已经等于目标，所以不需要任何操作
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>target[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

从前往后遍历 $target$，判断每个位置是否需要翻转，如果需要翻转，则翻转，并记录翻转次数。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, target: str) -> int:
        ans = 0
        for v in target:
            if (ans & 1) ^ int(v):
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minFlips(String target) {
        int ans = 0;
        for (int i = 0; i < target.length(); ++i) {
            int v = target.charAt(i) - '0';
            if (((ans & 1) ^ v) != 0) {
                ++ans;
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
    int minFlips(string target) {
        int ans = 0;
        for (char c : target) {
            int v = c - '0';
            if ((ans & 1) ^ v) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minFlips(target string) int {
	ans := 0
	for _, c := range target {
		v := int(c - '0')
		if ((ans & 1) ^ v) != 0 {
			ans++
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

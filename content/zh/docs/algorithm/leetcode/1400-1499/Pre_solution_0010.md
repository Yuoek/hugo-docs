---
title: "1490_克隆 N 叉树 🔒"
date: 2025-10-08T18:37:18+08:00
weight: 10
tags: [二分查找, 位运算, 动态规划, 单调队列, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 树, 深度优先搜索, 滑动窗口, 状态压缩, 计数, 队列]
---

{{< markmap >}}
### [1490_克隆 N 叉树 🔒](#1490)
#### [树](#1490)
#### [深度优先搜索](#1490)
#### [广度优先搜索](#1490)
#### [哈希表](#1490)
### [1491_去掉最低工资和最高工资后的工资平均值](#1491)
#### [数组](#1491)
#### [排序](#1491)
### [1492_n 的第 k 个因子](#1492)
#### [数学](#1492)
#### [数论](#1492)
### [1493_删掉一个元素以后全为 1 的最长子数组](#1493)
#### [数组](#1493)
#### [动态规划](#1493)
#### [滑动窗口](#1493)
### [1494_并行课程 II](#1494)
#### [位运算](#1494)
#### [图](#1494)
#### [动态规划](#1494)
#### [状态压缩](#1494)
### [1495_上月播放的儿童适宜电影 🔒](#1495)
#### [数据库](#1495)
### [1496_判断路径是否相交](#1496)
#### [哈希表](#1496)
#### [字符串](#1496)
### [1497_检查数组对是否可以被 k 整除](#1497)
#### [数组](#1497)
#### [哈希表](#1497)
#### [计数](#1497)
### [1498_满足条件的子序列数目](#1498)
#### [数组](#1498)
#### [双指针](#1498)
#### [二分查找](#1498)
#### [排序](#1498)
### [1499_满足不等式的最大值](#1499)
#### [队列](#1499)
#### [数组](#1499)
#### [滑动窗口](#1499)
#### [单调队列](#1499)
#### [堆（优先队列）](#1499)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1490_克隆 N 叉树 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
---
### 1491_去掉最低工资和最高工资后的工资平均值
___
#### 数组
___
#### 排序
---
### 1492_n 的第 k 个因子
___
#### 数学
___
#### 数论
---
### 1493_删掉一个元素以后全为 1 的最长子数组
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
---
### 1494_并行课程 II
___
#### 位运算
___
#### 图
___
#### 动态规划
___
#### 状态压缩
---
### 1495_上月播放的儿童适宜电影 🔒
___
#### 数据库
---
### 1496_判断路径是否相交
___
#### 哈希表
___
#### 字符串
---
### 1497_检查数组对是否可以被 k 整除
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1498_满足条件的子序列数目
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 1499_满足不等式的最大值
___
#### 队列
___
#### 数组
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调队列 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 树 | 深度优先搜索 | 滑动窗口 |
| 状态压缩 | 计数 | 队列 |

# [1490. 克隆 N 叉树 🔒](https://leetcode.cn/problems/clone-n-ary-tree){#1490}

{{< tabs "1490" >}}

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
    def cloneTree(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        children = [self.cloneTree(child) for child in root.children]
        return Node(root.val, children)
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
    public Node cloneTree(Node root) {
        if (root == null) {
            return null;
        }
        ArrayList<Node> children = new ArrayList<>();
        for (Node child : root.children) {
            children.add(cloneTree(child));
        }
        return new Node(root.val, children);
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
    Node* cloneTree(Node* root) {
        if (!root) {
            return root;
        }
        vector<Node*> children;
        for (Node* child : root->children) {
            children.emplace_back(cloneTree(child));
        }
        return new Node(root->val, children);
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

func cloneTree(root *Node) *Node {
	if root == nil {
		return nil
	}
	children := []*Node{}
	for _, child := range root.Children {
		children = append(children, cloneTree(child))
	}
	return &Node{root.Val, children}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵 N 叉树的根节点&nbsp;<code>root</code>&nbsp;，返回该树的<a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin"><strong>深拷贝</strong></a>（克隆）。</p>

<p>N 叉树的每个节点都包含一个值（ <code>int</code>&nbsp;）和子节点的列表（ <code>List[Node]</code>&nbsp;）。</p>

<pre>
class Node {
    public int val;
    public List&lt;Node&gt; children;
}
</pre>

<p><em>N 叉树的输入序列用层序遍历表示，每组子节点用 null 分隔（见示例）。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1490.Clone%20N-ary%20Tree/images/narytreeexample.png" style="width:330px" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,null,3,2,4,null,5,6]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1490.Clone%20N-ary%20Tree/images/sample_4_964.png" style="height:241px; width:296px" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定的 N 叉树的深度小于或等于&nbsp;<code>1000</code>。</li>
	<li>节点的总个数在&nbsp;<code>[0,&nbsp;10<sup>4</sup>]</code>&nbsp;之间</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你的解决方案可以适用于<a href="https://leetcode.cn/problems/clone-graph/">克隆图</a>问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以用递归的方法来实现 N 叉树的深拷贝。

对于当前节点，如果为空，则返回空；否则，创建一个新节点，其值为当前节点的值，然后对当前节点的每个子节点递归调用该函数，将返回值作为新节点的子节点。最后返回新节点即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 N 叉树的节点个数。

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
    def cloneTree(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        children = [self.cloneTree(child) for child in root.children]
        return Node(root.val, children)
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
    public Node cloneTree(Node root) {
        if (root == null) {
            return null;
        }
        ArrayList<Node> children = new ArrayList<>();
        for (Node child : root.children) {
            children.add(cloneTree(child));
        }
        return new Node(root.val, children);
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
    Node* cloneTree(Node* root) {
        if (!root) {
            return root;
        }
        vector<Node*> children;
        for (Node* child : root->children) {
            children.emplace_back(cloneTree(child));
        }
        return new Node(root->val, children);
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

func cloneTree(root *Node) *Node {
	if root == nil {
		return nil
	}
	children := []*Node{}
	for _, child := range root.Children {
		children = append(children, cloneTree(child))
	}
	return &Node{root.Val, children}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1491. 去掉最低工资和最高工资后的工资平均值](https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary){#1491}

{{< tabs "1491" >}}

{{% tab "python" %}}
```python
class Solution:
    def average(self, salary: List[int]) -> float:
        s = sum(salary) - min(salary) - max(salary)
        return s / (len(salary) - 2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double average(int[] salary) {
        int s = 0;
        int mi = 10000000, mx = 0;
        for (int v : salary) {
            mi = Math.min(mi, v);
            mx = Math.max(mx, v);
            s += v;
        }
        s -= (mi + mx);
        return s * 1.0 / (salary.length - 2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        int s = 0;
        int mi = 1e7, mx = 0;
        for (int v : salary) {
            s += v;
            mi = min(mi, v);
            mx = max(mx, v);
        }
        s -= (mi + mx);
        return (double) s / (salary.size() - 2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func average(salary []int) float64 {
	s := 0
	mi, mx := 10000000, 0
	for _, v := range salary {
		s += v
		mi = min(mi, v)
		mx = max(mx, v)
	}
	s -= (mi + mx)
	return float64(s) / float64(len(salary)-2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function average(salary: number[]): number {
    let max = -Infinity;
    let min = Infinity;
    let sum = 0;
    for (const v of salary) {
        sum += v;
        max = Math.max(max, v);
        min = Math.min(min, v);
    }
    return (sum - max - min) / (salary.length - 2);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let n = salary.len() as i32;
        let mut min = i32::MAX;
        let mut max = i32::MIN;
        let mut sum = 0;
        for &num in salary.iter() {
            min = min.min(num);
            max = max.max(num);
            sum += num;
        }
        f64::from(sum - min - max) / f64::from(n - 2)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $salary
     * @return Float
     */
    function average($salary) {
        $max = $sum = 0;
        $min = 10 ** 6;
        for ($i = 0; $i < count($salary); $i++) {
            $min = min($min, $salary[$i]);
            $max = max($max, $salary[$i]);
            $sum += $salary[$i];
        }
        return ($sum - $max - $min) / (count($salary) - 2);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double average(int* salary, int salarySize) {
    int ma = INT_MIN;
    int mi = INT_MAX;
    int sum = 0;
    for (int i = 0; i < salarySize; i++) {
        sum += salary[i];
        ma = max(ma, salary[i]);
        mi = min(mi, salary[i]);
    }
    return (sum - mi - ma) * 1.0 / (salarySize - 2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>salary</code>&nbsp;，数组里每个数都是 <strong>唯一</strong>&nbsp;的，其中&nbsp;<code>salary[i]</code> 是第&nbsp;<code>i</code>&nbsp;个员工的工资。</p>

<p>请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>salary = [4000,3000,1000,2000]
<strong>输出：</strong>2500.00000
<strong>解释：</strong>最低工资和最高工资分别是 1000 和 4000 。
去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>salary = [1000,2000,3000]
<strong>输出：</strong>2000.00000
<strong>解释：</strong>最低工资和最高工资分别是 1000 和 3000 。
去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>salary = [6000,5000,4000,3000,2000,1000]
<strong>输出：</strong>3500.00000
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>salary = [8000,9000,2000,3000,6000,1000]
<strong>输出：</strong>4750.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= salary.length &lt;= 100</code></li>
	<li><code>10^3&nbsp;&lt;= salary[i] &lt;= 10^6</code></li>
	<li><code>salary[i]</code>&nbsp;是唯一的。</li>
	<li>与真实值误差在&nbsp;<code>10^-5</code> 以内的结果都将视为正确答案。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

按题意模拟即可。

遍历数组，求出最大值和最小值，并且累加和，然后求出去掉最大值和最小值后的平均值。

时间复杂度 $O(n)$。其中 $n$ 为数组 `salary` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def average(self, salary: List[int]) -> float:
        s = sum(salary) - min(salary) - max(salary)
        return s / (len(salary) - 2)
```

#### Java

```java
class Solution {
    public double average(int[] salary) {
        int s = 0;
        int mi = 10000000, mx = 0;
        for (int v : salary) {
            mi = Math.min(mi, v);
            mx = Math.max(mx, v);
            s += v;
        }
        s -= (mi + mx);
        return s * 1.0 / (salary.length - 2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        int s = 0;
        int mi = 1e7, mx = 0;
        for (int v : salary) {
            s += v;
            mi = min(mi, v);
            mx = max(mx, v);
        }
        s -= (mi + mx);
        return (double) s / (salary.size() - 2);
    }
};
```

#### Go

```go
func average(salary []int) float64 {
	s := 0
	mi, mx := 10000000, 0
	for _, v := range salary {
		s += v
		mi = min(mi, v)
		mx = max(mx, v)
	}
	s -= (mi + mx)
	return float64(s) / float64(len(salary)-2)
}
```

#### TypeScript

```ts
function average(salary: number[]): number {
    let max = -Infinity;
    let min = Infinity;
    let sum = 0;
    for (const v of salary) {
        sum += v;
        max = Math.max(max, v);
        min = Math.min(min, v);
    }
    return (sum - max - min) / (salary.length - 2);
}
```

#### Rust

```rust
impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let n = salary.len() as i32;
        let mut min = i32::MAX;
        let mut max = i32::MIN;
        let mut sum = 0;
        for &num in salary.iter() {
            min = min.min(num);
            max = max.max(num);
            sum += num;
        }
        f64::from(sum - min - max) / f64::from(n - 2)
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $salary
     * @return Float
     */
    function average($salary) {
        $max = $sum = 0;
        $min = 10 ** 6;
        for ($i = 0; $i < count($salary); $i++) {
            $min = min($min, $salary[$i]);
            $max = max($max, $salary[$i]);
            $sum += $salary[$i];
        }
        return ($sum - $max - $min) / (count($salary) - 2);
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double average(int* salary, int salarySize) {
    int ma = INT_MIN;
    int mi = INT_MAX;
    int sum = 0;
    for (int i = 0; i < salarySize; i++) {
        sum += salary[i];
        ma = max(ma, salary[i]);
        mi = min(mi, salary[i]);
    }
    return (sum - mi - ma) * 1.0 / (salarySize - 2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1492. n 的第 k 个因子](https://leetcode.cn/problems/the-kth-factor-of-n){#1492}

{{< tabs "1492" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        i = 1
        while i * i < n:
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i
            i += 1
        if i * i != n:
            i -= 1
        while i:
            if (n % (n // i)) == 0:
                k -= 1
                if k == 0:
                    return n // i
            i -= 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthFactor(int n, int k) {
        int i = 1;
        for (; i < n / i; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        if (i * i != n) {
            --i;
        }
        for (; i > 0; --i) {
            if (n % (n / i) == 0 && (--k == 0)) {
                return n / i;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i < n / i; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        if (i * i != n) {
            --i;
        }
        for (; i > 0; --i) {
            if (n % (n / i) == 0 && (--k == 0)) {
                return n / i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthFactor(n int, k int) int {
	i := 1
	for ; i < n/i; i++ {
		if n%i == 0 {
			k--
			if k == 0 {
				return i
			}
		}
	}
	if i*i != n {
		i--
	}
	for ; i > 0; i-- {
		if n%(n/i) == 0 {
			k--
			if k == 0 {
				return n / i
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthFactor(n: number, k: number): number {
    let i: number = 1;
    for (; i < n / i; ++i) {
        if (n % i === 0 && --k === 0) {
            return i;
        }
    }
    if (i * i !== n) {
        --i;
    }
    for (; i > 0; --i) {
        if (n % Math.floor(n / i) === 0 && --k === 0) {
            return Math.floor(n / i);
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>n</code> 和&nbsp;<code>k</code>&nbsp;。</p>

<p>如果正整数 <code>i</code> 满足 <code>n % i == 0</code> ，那么我们就说正整数 <code>i</code> 是整数 <code>n</code>&nbsp;的因子。</p>

<p>考虑整数 <code>n</code>&nbsp;的所有因子，将它们 <strong>升序排列</strong>&nbsp;。请你返回第 <code>k</code>&nbsp;个因子。如果 <code>n</code>&nbsp;的因子数少于 <code>k</code>&nbsp;，请你返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 12, k = 3
<strong>输出：</strong>3
<strong>解释：</strong>因子列表包括 [1, 2, 3, 4, 6, 12]，第 3 个因子是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 7, k = 2
<strong>输出：</strong>7
<strong>解释：</strong>因子列表包括 [1, 7] ，第 2 个因子是 7 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 4
<strong>输出：</strong>-1
<strong>解释：</strong>因子列表包括 [1, 2, 4] ，只有 3 个因子，所以我们应该返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你可以设计时间复杂度小于 O(n) 的算法来解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

“因子”是指能整除某个数的数。因此，我们只需要从小到大枚举 $[1,2,..n]$，找到所有能整除 $n$ 的数，然后返回第 $k$ 个即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        for i in range(1, n + 1):
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i
        return -1
```

#### Java

```java
class Solution {
    public int kthFactor(int n, int k) {
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func kthFactor(n int, k int) int {
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			k--
			if k == 0 {
				return i
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function kthFactor(n: number, k: number): number {
    for (let i = 1; i <= n; ++i) {
        if (n % i === 0 && --k === 0) {
            return i;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

我们可以发现，如果 $n$ 有一个因子 $x$，那么 $n$ 一定也有一个因子 $n/x$。

因此，我们先需要枚举 $[1,2,...\left \lfloor \sqrt{n}  \right \rfloor]$，找到所有能整除 $n$ 的数，如果找到第 $k$ 个因子，那么直接返回即可。如果没有找到第 $k$ 个因子，那么我们再倒序枚举 $[\left \lfloor \sqrt{n}  \right \rfloor ,..1]$，找到第 $k$ 个因子即可。

时间复杂度 $O(\sqrt{n})$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        i = 1
        while i * i < n:
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i
            i += 1
        if i * i != n:
            i -= 1
        while i:
            if (n % (n // i)) == 0:
                k -= 1
                if k == 0:
                    return n // i
            i -= 1
        return -1
```

#### Java

```java
class Solution {
    public int kthFactor(int n, int k) {
        int i = 1;
        for (; i < n / i; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        if (i * i != n) {
            --i;
        }
        for (; i > 0; --i) {
            if (n % (n / i) == 0 && (--k == 0)) {
                return n / i;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i < n / i; ++i) {
            if (n % i == 0 && (--k == 0)) {
                return i;
            }
        }
        if (i * i != n) {
            --i;
        }
        for (; i > 0; --i) {
            if (n % (n / i) == 0 && (--k == 0)) {
                return n / i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func kthFactor(n int, k int) int {
	i := 1
	for ; i < n/i; i++ {
		if n%i == 0 {
			k--
			if k == 0 {
				return i
			}
		}
	}
	if i*i != n {
		i--
	}
	for ; i > 0; i-- {
		if n%(n/i) == 0 {
			k--
			if k == 0 {
				return n / i
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function kthFactor(n: number, k: number): number {
    let i: number = 1;
    for (; i < n / i; ++i) {
        if (n % i === 0 && --k === 0) {
            return i;
        }
    }
    if (i * i !== n) {
        --i;
    }
    for (; i > 0; --i) {
        if (n % Math.floor(n / i) === 0 && --k === 0) {
            return Math.floor(n / i);
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element){#1493}

{{< tabs "1493" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        cnt = l = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubarray(int[] nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubarray(nums []int) int {
	cnt, l := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > 1 {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubarray(nums: number[]): number {
    let [cnt, l] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l - 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let mut l = 0;

        for &x in &nums {
            cnt += x ^ 1;
            if cnt > 1 {
                cnt -= nums[l] ^ 1;
                l += 1;
            }
        }

        (nums.len() - l - 1) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制数组&nbsp;<code>nums</code>&nbsp;，你需要从中删掉一个元素。</p>

<p>请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。</p>

<p>如果不存在这样的子数组，请返回 0 。</p>

<p>&nbsp;</p>

<p><strong>提示 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,0,1]
<strong>输出：</strong>3
<strong>解释：</strong>删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,1,1,0,1,1,0,1]
<strong>输出：</strong>5
<strong>解释：</strong>删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>2
<strong>解释：</strong>你必须要删除一个元素。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每个删除的位置 $i$，然后计算左侧和右侧的连续 1 的个数，最后取最大值。

具体地，我们使用两个长度为 $n+1$ 的数组 $left$ 和 $right$，其中 $left[i]$ 表示以 $nums[i-1]$ 结尾的连续 $1$ 的个数，而 $right[i]$ 表示以 $nums[i]$ 开头的连续 $1$ 的个数。

最终答案即为 $\max_{0 \leq i < n} \{left[i] + right[i+1]\}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left = [0] * (n + 1)
        right = [0] * (n + 1)
        for i, x in enumerate(nums, 1):
            if x:
                left[i] = left[i - 1] + 1
        for i in range(n - 1, -1, -1):
            if nums[i]:
                right[i] = right[i + 1] + 1
        return max(left[i] + right[i + 1] for i in range(n))
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] == 1) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 1) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, left[i] + right[i + 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 1);
        vector<int> right(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; ~i; --i) {
            if (nums[i]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, left[i] + right[i + 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubarray(nums []int) (ans int) {
	n := len(nums)
	left := make([]int, n+1)
	right := make([]int, n+1)
	for i := 1; i <= n; i++ {
		if nums[i-1] == 1 {
			left[i] = left[i-1] + 1
		}
	}
	for i := n - 1; i >= 0; i-- {
		if nums[i] == 1 {
			right[i] = right[i+1] + 1
		}
	}
	for i := 0; i < n; i++ {
		ans = max(ans, left[i]+right[i+1])
	}
	return
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[]): number {
    const n = nums.length;
    const left: number[] = Array(n + 1).fill(0);
    const right: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        if (nums[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    for (let i = n - 1; ~i; --i) {
        if (nums[i]) {
            right[i] = right[i + 1] + 1;
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, left[i] + right[i + 1]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut left = vec![0; n + 1];
        let mut right = vec![0; n + 1];

        for i in 1..=n {
            if nums[i - 1] == 1 {
                left[i] = left[i - 1] + 1;
            }
        }

        for i in (0..n).rev() {
            if nums[i] == 1 {
                right[i] = right[i + 1] + 1;
            }
        }

        let mut ans = 0;
        for i in 0..n {
            ans = ans.max(left[i] + right[i + 1]);
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

题目实际上是让我们找出一个最长的子数组，该子数组中最多只包含一个 $0$，删掉该子数组中的其中一个元素后，剩余的长度即为答案。

因此，我们可以用两个指针 $j$ 和 $i$ 分别指向子数组的左右边界，初始时 $j = 0$, $i = 0$。另外，我们用一个变量 $cnt$ 记录子数组中 $0$ 的个数。

接下来，我们移动右指针 $i$，如果 $nums[i] = 0$，则 $cnt$ 加 $1$。当 $cnt > 1$ 时，我们需要移动左指针 $j$，直到 $cnt \leq 1$。然后，我们更新答案，即 $ans = \max(ans, i - j)$。继续移动右指针 $i$，直到 $i$ 到达数组的末尾。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = 0
        cnt = j = 0
        for i, x in enumerate(nums):
            cnt += x ^ 1
            while cnt > 1:
                cnt -= nums[j] ^ 1
                j += 1
            ans = max(ans, i - j)
        return ans
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            cnt += nums[i] ^ 1;
            while (cnt > 1) {
                cnt -= nums[j++] ^ 1;
            }
            ans = Math.max(ans, i - j);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            cnt += nums[i] ^ 1;
            while (cnt > 1) {
                cnt -= nums[j++] ^ 1;
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubarray(nums []int) (ans int) {
	cnt, j := 0, 0
	for i, x := range nums {
		cnt += x ^ 1
		for ; cnt > 1; j++ {
			cnt -= nums[j] ^ 1
		}
		ans = max(ans, i-j)
	}
	return
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[]): number {
    let [ans, cnt, j] = [0, 0, 0];
    for (let i = 0; i < nums.length; ++i) {
        cnt += nums[i] ^ 1;
        while (cnt > 1) {
            cnt -= nums[j++] ^ 1;
        }
        ans = Math.max(ans, i - j);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut j = 0;
        let mut cnt = 0;

        for i in 0..n {
            cnt += nums[i] ^ 1;
            while cnt > 1 {
                cnt -= nums[j] ^ 1;
                j += 1;
            }
            ans = ans.max(i - j);
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：双指针（优化）

方法二中，我们每次会循环移动左指针，直到 $cnt \leq 1$。由于题目求的是最长子数组，意味着我们不需要缩小子数组的长度，因此，如果 $\textit{cnt} \gt 1$，我们只移动左指针一次，右指针也继续向右移动。这样可以保证子数组的长度不会减小。

最后，我们返回的答案即为 $n - l - 1$，其中 $l$ 为左指针的位置。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        cnt = l = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l - 1
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, l = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l - 1;
    }
};
```

#### Go

```go
func longestSubarray(nums []int) int {
	cnt, l := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > 1 {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l - 1
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[]): number {
    let [cnt, l] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l - 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let mut l = 0;

        for &x in &nums {
            cnt += x ^ 1;
            if cnt > 1 {
                cnt -= nums[l] ^ 1;
                l += 1;
            }
        }

        (nums.len() - l - 1) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1494. 并行课程 II](https://leetcode.cn/problems/parallel-courses-ii){#1494}

{{< tabs "1494" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        d = [0] * (n + 1)
        for x, y in relations:
            d[y] |= 1 << x
        q = deque([(0, 0)])
        vis = {0}
        while q:
            cur, t = q.popleft()
            if cur == (1 << (n + 1)) - 2:
                return t
            nxt = 0
            for i in range(1, n + 1):
                if (cur & d[i]) == d[i]:
                    nxt |= 1 << i
            nxt ^= cur
            if nxt.bit_count() <= k:
                if (nxt | cur) not in vis:
                    vis.add(nxt | cur)
                    q.append((nxt | cur, t + 1))
            else:
                x = nxt
                while nxt:
                    if nxt.bit_count() == k and (nxt | cur) not in vis:
                        vis.add(nxt | cur)
                        q.append((nxt | cur, t + 1))
                    nxt = (nxt - 1) & x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        int[] d = new int[n + 1];
        for (var e : relations) {
            d[e[1]] |= 1 << e[0];
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        Set<Integer> vis = new HashSet<>();
        vis.add(0);
        while (!q.isEmpty()) {
            var p = q.pollFirst();
            int cur = p[0], t = p[1];
            if (cur == (1 << (n + 1)) - 2) {
                return t;
            }
            int nxt = 0;
            for (int i = 1; i <= n; ++i) {
                if ((cur & d[i]) == d[i]) {
                    nxt |= 1 << i;
                }
            }
            nxt ^= cur;
            if (Integer.bitCount(nxt) <= k) {
                if (vis.add(nxt | cur)) {
                    q.offer(new int[] {nxt | cur, t + 1});
                }
            } else {
                int x = nxt;
                while (nxt > 0) {
                    if (Integer.bitCount(nxt) == k && vis.add(nxt | cur)) {
                        q.offer(new int[] {nxt | cur, t + 1});
                    }
                    nxt = (nxt - 1) & x;
                }
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
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> d(n + 1);
        for (auto& e : relations) {
            d[e[1]] |= 1 << e[0];
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        unordered_set<int> vis{{0}};
        while (!q.empty()) {
            auto [cur, t] = q.front();
            q.pop();
            if (cur == (1 << (n + 1)) - 2) {
                return t;
            }
            int nxt = 0;
            for (int i = 1; i <= n; ++i) {
                if ((cur & d[i]) == d[i]) {
                    nxt |= 1 << i;
                }
            }
            nxt ^= cur;
            if (__builtin_popcount(nxt) <= k) {
                if (!vis.count(nxt | cur)) {
                    vis.insert(nxt | cur);
                    q.push({nxt | cur, t + 1});
                }
            } else {
                int x = nxt;
                while (nxt) {
                    if (__builtin_popcount(nxt) == k && !vis.count(nxt | cur)) {
                        vis.insert(nxt | cur);
                        q.push({nxt | cur, t + 1});
                    }
                    nxt = (nxt - 1) & x;
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumberOfSemesters(n int, relations [][]int, k int) int {
	d := make([]int, n+1)
	for _, e := range relations {
		d[e[1]] |= 1 << e[0]
	}
	type pair struct{ v, t int }
	q := []pair{pair{0, 0}}
	vis := map[int]bool{0: true}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		cur, t := p.v, p.t
		if cur == (1<<(n+1))-2 {
			return t
		}
		nxt := 0
		for i := 1; i <= n; i++ {
			if (cur & d[i]) == d[i] {
				nxt |= 1 << i
			}
		}
		nxt ^= cur
		if bits.OnesCount(uint(nxt)) <= k {
			if !vis[nxt|cur] {
				vis[nxt|cur] = true
				q = append(q, pair{nxt | cur, t + 1})
			}
		} else {
			x := nxt
			for nxt > 0 {
				if bits.OnesCount(uint(nxt)) == k && !vis[nxt|cur] {
					vis[nxt|cur] = true
					q = append(q, pair{nxt | cur, t + 1})
				}
				nxt = (nxt - 1) & x
			}
		}
	}
	return 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;表示某所大学里课程的数目，编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;，数组&nbsp;<code>relations</code>&nbsp;中，&nbsp;<code>relations[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp; 表示一个先修课的关系，也就是课程&nbsp;<code>x<sub>i</sub></code>&nbsp;必须在课程&nbsp;<code>y<sub>i</sub></code><sub>&nbsp;</sub>之前上。同时你还有一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>在一个学期中，你 <strong>最多</strong>&nbsp;可以同时上 <code>k</code>&nbsp;门课，前提是这些课的先修课在之前的学期里已经上过了。</p>

<p>请你返回上完所有课最少需要多少个学期。题目保证一定存在一种上完所有课的方式。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1494.Parallel%20Courses%20II/images/leetcode_parallel_courses_1.png" style="height: 164px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
<strong>输出：</strong>3 
<strong>解释：</strong>上图展示了题目输入的图。在第一个学期中，我们可以上课程 2 和课程 3 。然后第二个学期上课程 1 ，第三个学期上课程 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1494.Parallel%20Courses%20II/images/leetcode_parallel_courses_2.png" style="height: 234px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
<strong>输出：</strong>4 
<strong>解释：</strong>上图展示了题目输入的图。一个最优方案是：第一学期上课程 2 和 3，第二学期上课程 4 ，第三学期上课程 1 ，第四学期上课程 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 11, relations = [], k = 2
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>0 &lt;=&nbsp;relations.length &lt;= n * (n-1) / 2</code></li>
	<li><code>relations[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= n</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li>所有先修关系都是不同的，也就是说&nbsp;<code>relations[i] != relations[j]</code>&nbsp;。</li>
	<li>题目输入的图是个有向无环图。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + BFS + 子集枚举

我们用数组 $d[i]$ 表示课程 $i$ 的先修课程的集合。由于数据规模 $n\lt 15$，我们可以用一个整数的二进制位（状态压缩）来表示集合，其中第 $j$ 位为 $1$ 表示课程 $j$ 是课程 $i$ 的先修课程。

我们用一个状态变量 $cur$ 表示当前已经上过的课程的集合，初始时 $cur=0$。如果 $cur=2^{n+1}-2$，表示所有课程都上过了，返回当前学期即可。

如果课程 $i$ 的先修课程 $d[i]$ 的集合是 $cur$ 的子集，说明课程 $i$ 可以上。这样我们可以找到当前 $cur$ 状态的下一个状态 $nxt$，表示后续学期可以上的课程集合。

如果 $nxt$ 的二进制表示中 $1$ 的个数小于等于 $k$，说明后续学期可以上的课程数不超过 $k$，我们就可以将 $nxt$ 加入队列中。否则，说明后续学期可以上的课程数超过 $k$，那么我们就应该从后续可以上的课程中选择 $k$ 门课程，这样才能保证后续学期可以上的课程数不超过 $k$。我们可以枚举 $nxt$ 的所有子集，将子集加入队列中。

时间复杂度 $O(3^n)$，空间复杂度 $O(2^n)$。其中 $n$ 是题目给定的课程数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        d = [0] * (n + 1)
        for x, y in relations:
            d[y] |= 1 << x
        q = deque([(0, 0)])
        vis = {0}
        while q:
            cur, t = q.popleft()
            if cur == (1 << (n + 1)) - 2:
                return t
            nxt = 0
            for i in range(1, n + 1):
                if (cur & d[i]) == d[i]:
                    nxt |= 1 << i
            nxt ^= cur
            if nxt.bit_count() <= k:
                if (nxt | cur) not in vis:
                    vis.add(nxt | cur)
                    q.append((nxt | cur, t + 1))
            else:
                x = nxt
                while nxt:
                    if nxt.bit_count() == k and (nxt | cur) not in vis:
                        vis.add(nxt | cur)
                        q.append((nxt | cur, t + 1))
                    nxt = (nxt - 1) & x
```

#### Java

```java
class Solution {
    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        int[] d = new int[n + 1];
        for (var e : relations) {
            d[e[1]] |= 1 << e[0];
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        Set<Integer> vis = new HashSet<>();
        vis.add(0);
        while (!q.isEmpty()) {
            var p = q.pollFirst();
            int cur = p[0], t = p[1];
            if (cur == (1 << (n + 1)) - 2) {
                return t;
            }
            int nxt = 0;
            for (int i = 1; i <= n; ++i) {
                if ((cur & d[i]) == d[i]) {
                    nxt |= 1 << i;
                }
            }
            nxt ^= cur;
            if (Integer.bitCount(nxt) <= k) {
                if (vis.add(nxt | cur)) {
                    q.offer(new int[] {nxt | cur, t + 1});
                }
            } else {
                int x = nxt;
                while (nxt > 0) {
                    if (Integer.bitCount(nxt) == k && vis.add(nxt | cur)) {
                        q.offer(new int[] {nxt | cur, t + 1});
                    }
                    nxt = (nxt - 1) & x;
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> d(n + 1);
        for (auto& e : relations) {
            d[e[1]] |= 1 << e[0];
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        unordered_set<int> vis{{0}};
        while (!q.empty()) {
            auto [cur, t] = q.front();
            q.pop();
            if (cur == (1 << (n + 1)) - 2) {
                return t;
            }
            int nxt = 0;
            for (int i = 1; i <= n; ++i) {
                if ((cur & d[i]) == d[i]) {
                    nxt |= 1 << i;
                }
            }
            nxt ^= cur;
            if (__builtin_popcount(nxt) <= k) {
                if (!vis.count(nxt | cur)) {
                    vis.insert(nxt | cur);
                    q.push({nxt | cur, t + 1});
                }
            } else {
                int x = nxt;
                while (nxt) {
                    if (__builtin_popcount(nxt) == k && !vis.count(nxt | cur)) {
                        vis.insert(nxt | cur);
                        q.push({nxt | cur, t + 1});
                    }
                    nxt = (nxt - 1) & x;
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func minNumberOfSemesters(n int, relations [][]int, k int) int {
	d := make([]int, n+1)
	for _, e := range relations {
		d[e[1]] |= 1 << e[0]
	}
	type pair struct{ v, t int }
	q := []pair{pair{0, 0}}
	vis := map[int]bool{0: true}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		cur, t := p.v, p.t
		if cur == (1<<(n+1))-2 {
			return t
		}
		nxt := 0
		for i := 1; i <= n; i++ {
			if (cur & d[i]) == d[i] {
				nxt |= 1 << i
			}
		}
		nxt ^= cur
		if bits.OnesCount(uint(nxt)) <= k {
			if !vis[nxt|cur] {
				vis[nxt|cur] = true
				q = append(q, pair{nxt | cur, t + 1})
			}
		} else {
			x := nxt
			for nxt > 0 {
				if bits.OnesCount(uint(nxt)) == k && !vis[nxt|cur] {
					vis[nxt|cur] = true
					q = append(q, pair{nxt | cur, t + 1})
				}
				nxt = (nxt - 1) & x
			}
		}
	}
	return 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1495. 上月播放的儿童适宜电影 🔒](https://leetcode.cn/problems/friendly-movies-streamed-last-month){#1495}

{{< tabs "1495" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT title
FROM
    TVProgram
    JOIN Content USING (content_id)
WHERE
    DATE_FORMAT(program_date, '%Y%m') = '202006'
    AND kids_content = 'Y'
    AND content_type = 'Movies';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>TVProgram</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| program_date  | date    |
| content_id    | int     |
| channel       | varchar |
+---------------+---------+
(program_date, content_id) 是该表的主键(具有唯一值的列的组合)。
该表包含电视上的节目信息。
content_id 是电视一些频道上的节目的 id。</pre>

<p>&nbsp;</p>

<p>表: <code>Content</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| content_id       | varchar |
| title            | varchar |
| Kids_content     | enum    |
| content_type     | varchar |
+------------------+---------+
content_id 是该表主键(具有唯一值的列)。
Kids_content 是枚举类型, 取值为('Y', 'N'), 其中: 
'Y' 表示儿童适宜内容, 而'N'表示儿童不宜内容。
content_type&nbsp;表示内容的类型, 比如电影, 电视剧等。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，&nbsp;报告在 2020 年 6 月份播放的儿童适宜电影的去重电影名.</p>

<p>返回的结果表单 <strong>没有顺序要求</strong> .</p>

<p>返回结果的格式如下例所示.</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
TVProgram</code> 表:
+--------------------+--------------+-------------+
| program_date       | content_id   | channel     |
+--------------------+--------------+-------------+
| 2020-06-10 08:00   | 1            | LC-Channel  |
| 2020-05-11 12:00   | 2            | LC-Channel  |
| 2020-05-12 12:00   | 3            | LC-Channel  |
| 2020-05-13 14:00   | 4            | Disney Ch   |
| 2020-06-18 14:00   | 4            | Disney Ch   |
| 2020-07-15 16:00   | 5            | Disney Ch   |
+--------------------+--------------+-------------+
<code>Content</code> 表:
+------------+----------------+---------------+---------------+
| content_id | title          | Kids_content  | content_type  |
+------------+----------------+---------------+---------------+
| 1          | Leetcode Movie | N             | Movies        |
| 2          | Alg. for Kids  | Y             | Series        |
| 3          | Database Sols  | N             | Series        |
| 4          | Aladdin        | Y             | Movies        |
| 5          | Cinderella     | Y             | Movies        |
+------------+----------------+---------------+---------------+
<code><strong>输出：</strong></code>
+--------------+
| title        |
+--------------+
| Aladdin      |
+--------------+
<code><strong>解释：</strong></code>
"Leetcode Movie" 是儿童不宜的电影.
"Alg. for Kids" 不是电影.
"Database Sols" 不是电影
"Aladin" 是电影, 儿童适宜, 并且在 2020 年 6 月份播放.
"Cinderella" 不在 2020 年 6 月份播放.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 条件筛选

我们可以先通过等值连接将两张表按照 `content_id` 字段连接起来，然后再通过条件筛选出在 $2020$ 年 $6$ 月份播放的儿童适宜电影。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT title
FROM
    TVProgram
    JOIN Content USING (content_id)
WHERE
    DATE_FORMAT(program_date, '%Y%m') = '202006'
    AND kids_content = 'Y'
    AND content_type = 'Movies';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1496. 判断路径是否相交](https://leetcode.cn/problems/path-crossing){#1496}

{{< tabs "1496" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        i = j = 0
        vis = {(0, 0)}
        for c in path:
            match c:
                case 'N':
                    i -= 1
                case 'S':
                    i += 1
                case 'E':
                    j += 1
                case 'W':
                    j -= 1
            if (i, j) in vis:
                return True
            vis.add((i, j))
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPathCrossing(String path) {
        int i = 0, j = 0;
        Set<Integer> vis = new HashSet<>();
        vis.add(0);
        for (int k = 0, n = path.length(); k < n; ++k) {
            switch (path.charAt(k)) {
                case 'N' -> --i;
                case 'S' -> ++i;
                case 'E' -> ++j;
                case 'W' -> --j;
            }
            int t = i * 20000 + j;
            if (!vis.add(t)) {
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
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        unordered_set<int> s{{0}};
        for (char& c : path) {
            if (c == 'N') {
                --i;
            } else if (c == 'S') {
                ++i;
            } else if (c == 'E') {
                ++j;
            } else {
                --j;
            }
            int t = i * 20000 + j;
            if (s.count(t)) {
                return true;
            }
            s.insert(t);
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPathCrossing(path string) bool {
	i, j := 0, 0
	vis := map[int]bool{0: true}
	for _, c := range path {
		switch c {
		case 'N':
			i--
		case 'S':
			i++
		case 'E':
			j++
		case 'W':
			j--
		}
		if vis[i*20000+j] {
			return true
		}
		vis[i*20000+j] = true
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPathCrossing(path: string): boolean {
    let [i, j] = [0, 0];
    const vis: Set<number> = new Set();
    vis.add(0);
    for (const c of path) {
        if (c === 'N') {
            --i;
        } else if (c === 'S') {
            ++i;
        } else if (c === 'E') {
            ++j;
        } else if (c === 'W') {
            --j;
        }
        const t = i * 20000 + j;
        if (vis.has(t)) {
            return true;
        }
        vis.add(t);
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>path</code>，其中 <code>path[i]</code> 的值可以是 <code>'N'</code>、<code>'S'</code>、<code>'E'</code> 或者 <code>'W'</code>，分别表示向北、向南、向东、向西移动一个单位。</p>

<p>你从二维平面上的原点 <code>(0, 0)</code> 处开始出发，按 <code>path</code> 所指示的路径行走。</p>

<p>如果路径在任何位置上与自身相交，也就是走到之前已经走过的位置，请返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1496.Path%20Crossing/images/screen-shot-2020-06-10-at-123929-pm.png" style="height: 358px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>path = "NES"
<strong>输出：</strong>false 
<strong>解释：</strong>该路径没有在任何位置相交。</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1496.Path%20Crossing/images/screen-shot-2020-06-10-at-123843-pm.png" style="height: 339px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>path = "NESWW"
<strong>输出：</strong>true
<strong>解释：</strong>该路径经过原点两次。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= path.length &lt;= 10<sup>4</sup></code></li>
	<li><code>path[i]</code> 为 <code>'N'</code>、<code>'S'</code>、<code>'E'</code> 或 <code>'W'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $vis$ 记录路径上的点。初始时 $vis$ 中只有原点 $(0, 0)$。

遍历字符串 $path$，对于每个字符 $c$，根据 $c$ 的值更新当前位置 $(i, j)$，然后判断 $(i, j)$ 是否在 $vis$ 中，如果在，则返回 `true`，否则将 $(i, j)$ 加入 $vis$ 中。

遍历结束后，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $path$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        i = j = 0
        vis = {(0, 0)}
        for c in path:
            match c:
                case 'N':
                    i -= 1
                case 'S':
                    i += 1
                case 'E':
                    j += 1
                case 'W':
                    j -= 1
            if (i, j) in vis:
                return True
            vis.add((i, j))
        return False
```

#### Java

```java
class Solution {
    public boolean isPathCrossing(String path) {
        int i = 0, j = 0;
        Set<Integer> vis = new HashSet<>();
        vis.add(0);
        for (int k = 0, n = path.length(); k < n; ++k) {
            switch (path.charAt(k)) {
                case 'N' -> --i;
                case 'S' -> ++i;
                case 'E' -> ++j;
                case 'W' -> --j;
            }
            int t = i * 20000 + j;
            if (!vis.add(t)) {
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
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        unordered_set<int> s{{0}};
        for (char& c : path) {
            if (c == 'N') {
                --i;
            } else if (c == 'S') {
                ++i;
            } else if (c == 'E') {
                ++j;
            } else {
                --j;
            }
            int t = i * 20000 + j;
            if (s.count(t)) {
                return true;
            }
            s.insert(t);
        }
        return false;
    }
};
```

#### Go

```go
func isPathCrossing(path string) bool {
	i, j := 0, 0
	vis := map[int]bool{0: true}
	for _, c := range path {
		switch c {
		case 'N':
			i--
		case 'S':
			i++
		case 'E':
			j++
		case 'W':
			j--
		}
		if vis[i*20000+j] {
			return true
		}
		vis[i*20000+j] = true
	}
	return false
}
```

#### TypeScript

```ts
function isPathCrossing(path: string): boolean {
    let [i, j] = [0, 0];
    const vis: Set<number> = new Set();
    vis.add(0);
    for (const c of path) {
        if (c === 'N') {
            --i;
        } else if (c === 'S') {
            ++i;
        } else if (c === 'E') {
            ++j;
        } else if (c === 'W') {
            --j;
        }
        const t = i * 20000 + j;
        if (vis.has(t)) {
            return true;
        }
        vis.add(t);
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1497. 检查数组对是否可以被 k 整除](https://leetcode.cn/problems/check-if-array-pairs-are-divisible-by-k){#1497}

{{< tabs "1497" >}}

{{% tab "python" %}}
```python
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        cnt = Counter(x % k for x in arr)
        return cnt[0] % 2 == 0 and all(cnt[i] == cnt[k - i] for i in range(1, k))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] cnt = new int[k];
        for (int x : arr) {
            ++cnt[(x % k + k) % k];
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return cnt[0] % 2 == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for (int& x : arr) {
            ++cnt[((x % k) + k) % k];
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return cnt[0] % 2 == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canArrange(arr []int, k int) bool {
	cnt := make([]int, k)
	for _, x := range arr {
		cnt[(x%k+k)%k]++
	}
	for i := 1; i < k; i++ {
		if cnt[i] != cnt[k-i] {
			return false
		}
	}
	return cnt[0]%2 == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canArrange(arr: number[], k: number): boolean {
    const cnt = Array(k).fill(0);

    for (const x of arr) {
        cnt[((x % k) + k) % k]++;
    }

    for (let i = 1; i < k; i++) {
        if (cnt[i] !== cnt[k - i]) return false;
    }

    return cnt[0] % 2 === 0;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function canArrange(arr, k) {
    const cnt = Array(k).fill(0);

    for (const x of arr) {
        cnt[((x % k) + k) % k]++;
    }

    for (let i = 1; i < k; i++) {
        if (cnt[i] !== cnt[k - i]) return false;
    }

    return cnt[0] % 2 === 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> ，其中数组长度是偶数，值为 <code>n</code> 。</p>

<p>现在需要把数组恰好分成 <code>n /&nbsp;2</code> 对，以使每对数字的和都能够被 <code>k</code> 整除。</p>

<p>如果存在这样的分法，请返回&nbsp;<code>true</code> ；否则，返回<i>&nbsp;</i><code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4,5,10,6,7,8,9], k = 5
<strong>输出：</strong>true
<strong>解释：</strong>划分后的数字对为 (1,9),(2,8),(3,7),(4,6) 以及 (5,10) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4,5,6], k = 7
<strong>输出：</strong>true
<strong>解释：</strong>划分后的数字对为 (1,6),(2,5) 以及 (3,4) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4,5,6], k = 10
<strong>输出：</strong>false
<strong>解释：</strong>无法在将数组中的数字分为三对的同时满足每对数字和能够被 10 整除的条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 为偶数<meta charset="UTF-8" /></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计余数

两个数 $a$ 和 $b$ 的和能被 $k$ 整除，当且仅当这两个数分别对 $k$ 取模的结果之和能被 $k$ 整除。

因此，我们可以统计数组中每个数对 $k$ 取模的结果，即余数，记录在数组 `cnt` 中。然后我们遍历数组 `cnt`，对于范围在 $[1,..k-1]$ 的每个数 $i$，如果 $cnt[i]$ 和 $cnt[k-i]$ 的值不相等，说明无法将数组中的数字分为 $n/2$ 对，使得每对数字的和都能被 $k$ 整除。如果 $cnt[0]$ 的值不是偶数，也说明无法将数组中的数字分为 $n/2$ 对，使得每对数字的和都能被 $k$ 整除。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为数组 `arr` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        cnt = Counter(x % k for x in arr)
        return cnt[0] % 2 == 0 and all(cnt[i] == cnt[k - i] for i in range(1, k))
```

#### Java

```java
class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] cnt = new int[k];
        for (int x : arr) {
            ++cnt[(x % k + k) % k];
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return cnt[0] % 2 == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for (int& x : arr) {
            ++cnt[((x % k) + k) % k];
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return cnt[0] % 2 == 0;
    }
};
```

#### Go

```go
func canArrange(arr []int, k int) bool {
	cnt := make([]int, k)
	for _, x := range arr {
		cnt[(x%k+k)%k]++
	}
	for i := 1; i < k; i++ {
		if cnt[i] != cnt[k-i] {
			return false
		}
	}
	return cnt[0]%2 == 0
}
```

#### TypeScript

```ts
function canArrange(arr: number[], k: number): boolean {
    const cnt = Array(k).fill(0);

    for (const x of arr) {
        cnt[((x % k) + k) % k]++;
    }

    for (let i = 1; i < k; i++) {
        if (cnt[i] !== cnt[k - i]) return false;
    }

    return cnt[0] % 2 === 0;
}
```

#### JavaScript

```js
function canArrange(arr, k) {
    const cnt = Array(k).fill(0);

    for (const x of arr) {
        cnt[((x % k) + k) % k]++;
    }

    for (let i = 1; i < k; i++) {
        if (cnt[i] !== cnt[k - i]) return false;
    }

    return cnt[0] % 2 === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1498. 满足条件的子序列数目](https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition){#1498}

{{< tabs "1498" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        mod = 10**9 + 7
        nums.sort()
        n = len(nums)
        f = [1] + [0] * n
        for i in range(1, n + 1):
            f[i] = f[i - 1] * 2 % mod
        ans = 0
        for i, x in enumerate(nums):
            if x * 2 > target:
                break
            j = bisect_right(nums, target - x, i + 1) - 1
            ans = (ans + f[j - i]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * 2) % mod;
        }
        int ans = 0;
        for (int i = 0; i < n && nums[i] * 2 <= target; ++i) {
            int j = search(nums, target - nums[i], i + 1) - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }

    private int search(int[] nums, int x, int left) {
        int right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * 2) % mod;
        }
        int ans = 0;
        for (int i = 0; i < n && nums[i] * 2 <= target; ++i) {
            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSubseq(nums []int, target int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	f := make([]int, n+1)
	f[0] = 1
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] * 2 % mod
	}
	for i, x := range nums {
		if x*2 > target {
			break
		}
		j := sort.SearchInts(nums[i+1:], target-x+1) + i
		ans = (ans + f[j-i]) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSubseq(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    const mod = 1e9 + 7;
    const n = nums.length;
    const f: number[] = Array(n + 1).fill(1);
    for (let i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * 2) % mod;
    }

    let ans = 0;
    for (let i = 0; i < n && nums[i] * 2 <= target; ++i) {
        const j = search(nums, target - nums[i], i + 1) - 1;
        if (j >= i) {
            ans = (ans + f[j - i]) % mod;
        }
    }
    return ans;
}

function search(nums: number[], x: number, left: number): number {
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_subseq(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        const MOD: i32 = 1_000_000_007;
        let n = nums.len();
        let mut f = vec![1; n + 1];
        for i in 1..=n {
            f[i] = (f[i - 1] * 2) % MOD;
        }
        let mut ans = 0;
        for i in 0..n {
            if nums[i] * 2 > target {
                break;
            }
            let mut l = i + 1;
            let mut r = n;
            while l < r {
                let m = (l + r) / 2;
                if nums[m] > target - nums[i] {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            let j = l - 1;
            ans = (ans + f[j - i]) % MOD;
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>target</code> 。</p>

<p>请你统计并返回 <code>nums</code> 中能满足其最小元素与最大元素的 <strong>和</strong> 小于或等于 <code>target</code> 的 <strong>非空</strong> 子序列的数目。</p>

<p>由于答案可能很大，请将结果对<meta charset="UTF-8" />&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,5,6,7], target = 9
<strong>输出：</strong>4
<strong>解释：</strong>有 4 个子序列满足该条件。
[3] -&gt; 最小元素 + 最大元素 &lt;= target (3 + 3 &lt;= 9)
[3,5] -&gt; (3 + 5 &lt;= 9)
[3,5,6] -&gt; (3 + 6 &lt;= 9)
[3,6] -&gt; (3 + 6 &lt;= 9)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3,6,8], target = 10
<strong>输出：</strong>6
<strong>解释：</strong>有 6 个子序列满足该条件。（nums 中可以有重复数字）
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,3,4,6,7], target = 12
<strong>输出：</strong>61
<strong>解释：</strong>共有 63 个非空子序列，其中 2 个不满足条件（[6,7], [7]）
有效序列总数为（63 - 2 = 61）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

由于题目中描述的是子序列，并且涉及到最小元素与最大元素的和，因此我们可以先对数组 $\textit{nums}$ 进行排序。

然后我们枚举最小元素 $\textit{nums}[i]$，对于每个 $\textit{nums}[i]$，我们可以在 $\textit{nums}[i + 1]$ 到 $\textit{nums}[n - 1]$ 中找到最大元素 $\textit{nums}[j]$，使得 $\textit{nums}[i] + \textit{nums}[j] \leq \textit{target}$，此时满足条件的子序列数目为 $2^{j - i}$，其中 $2^{j - i}$ 表示从 $\textit{nums}[i + 1]$ 到 $\textit{nums}[j]$ 的所有子序列的数目。我们将所有的子序列数目累加即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        mod = 10**9 + 7
        nums.sort()
        n = len(nums)
        f = [1] + [0] * n
        for i in range(1, n + 1):
            f[i] = f[i - 1] * 2 % mod
        ans = 0
        for i, x in enumerate(nums):
            if x * 2 > target:
                break
            j = bisect_right(nums, target - x, i + 1) - 1
            ans = (ans + f[j - i]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * 2) % mod;
        }
        int ans = 0;
        for (int i = 0; i < n && nums[i] * 2 <= target; ++i) {
            int j = search(nums, target - nums[i], i + 1) - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }

    private int search(int[] nums, int x, int left) {
        int right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * 2) % mod;
        }
        int ans = 0;
        for (int i = 0; i < n && nums[i] * 2 <= target; ++i) {
            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numSubseq(nums []int, target int) (ans int) {
	sort.Ints(nums)
	n := len(nums)
	f := make([]int, n+1)
	f[0] = 1
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] * 2 % mod
	}
	for i, x := range nums {
		if x*2 > target {
			break
		}
		j := sort.SearchInts(nums[i+1:], target-x+1) + i
		ans = (ans + f[j-i]) % mod
	}
	return
}
```

#### TypeScript

```ts
function numSubseq(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    const mod = 1e9 + 7;
    const n = nums.length;
    const f: number[] = Array(n + 1).fill(1);
    for (let i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * 2) % mod;
    }

    let ans = 0;
    for (let i = 0; i < n && nums[i] * 2 <= target; ++i) {
        const j = search(nums, target - nums[i], i + 1) - 1;
        if (j >= i) {
            ans = (ans + f[j - i]) % mod;
        }
    }
    return ans;
}

function search(nums: number[], x: number, left: number): number {
    let right = nums.length;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (nums[mid] > x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_subseq(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        const MOD: i32 = 1_000_000_007;
        let n = nums.len();
        let mut f = vec![1; n + 1];
        for i in 1..=n {
            f[i] = (f[i - 1] * 2) % MOD;
        }
        let mut ans = 0;
        for i in 0..n {
            if nums[i] * 2 > target {
                break;
            }
            let mut l = i + 1;
            let mut r = n;
            while l < r {
                let m = (l + r) / 2;
                if nums[m] > target - nums[i] {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            let j = l - 1;
            ans = (ans + f[j - i]) % MOD;
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

# [1499. 满足不等式的最大值](https://leetcode.cn/problems/max-value-of-equation){#1499}

{{< tabs "1499" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -inf
        q = deque()
        for x, y in points:
            while q and x - q[0][0] > k:
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][1] - q[0][0])
            while q and y - x >= q[-1][1] - q[-1][0]:
                q.pop()
            q.append((x, y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int ans = -(1 << 30);
        Deque<int[]> q = new ArrayDeque<>();
        for (var p : points) {
            int x = p[0], y = p[1];
            while (!q.isEmpty() && x - q.peekFirst()[0] > k) {
                q.pollFirst();
            }
            if (!q.isEmpty()) {
                ans = Math.max(ans, x + y + q.peekFirst()[1] - q.peekFirst()[0]);
            }
            while (!q.isEmpty() && y - x >= q.peekLast()[1] - q.peekLast()[0]) {
                q.pollLast();
            }
            q.offerLast(p);
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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -(1 << 30);
        deque<pair<int, int>> q;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (!q.empty() && x - q.front().first > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                ans = max(ans, x + y + q.front().second - q.front().first);
            }
            while (!q.empty() && y - x >= q.back().second - q.back().first) {
                q.pop_back();
            }
            q.emplace_back(x, y);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxValueOfEquation(points [][]int, k int) int {
	ans := -(1 << 30)
	q := [][2]int{}
	for _, p := range points {
		x, y := p[0], p[1]
		for len(q) > 0 && x-q[0][0] > k {
			q = q[1:]
		}
		if len(q) > 0 {
			ans = max(ans, x+y+q[0][1]-q[0][0])
		}
		for len(q) > 0 && y-x >= q[len(q)-1][1]-q[len(q)-1][0] {
			q = q[:len(q)-1]
		}
		q = append(q, [2]int{x, y})
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxValueOfEquation(points: number[][], k: number): number {
    let ans = -(1 << 30);
    const q: number[][] = [];
    for (const [x, y] of points) {
        while (q.length > 0 && x - q[0][0] > k) {
            q.shift();
        }
        if (q.length > 0) {
            ans = Math.max(ans, x + y + q[0][1] - q[0][0]);
        }
        while (q.length > 0 && y - x > q[q.length - 1][1] - q[q.length - 1][0]) {
            q.pop();
        }
        q.push([x, y]);
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

<p>给你一个数组 <code>points</code> 和一个整数 <code>k</code> 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，并且在 <code>1 &lt;= i &lt; j &lt;= points.length</code> 的前提下， <code>x<sub>i</sub> &lt; x<sub>j</sub></code> 总成立。</p>

<p>请你找出<em> </em><code>y<sub>i</sub>&nbsp;+ y<sub>j</sub>&nbsp;+ |x<sub>i</sub>&nbsp;- x<sub>j</sub>|</code> 的 <strong>最大值</strong>，其中 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code> 且 <code>1 &lt;= i &lt; j &lt;= points.length</code>。</p>

<p>题目测试数据保证至少存在一对能够满足 <code>|x<sub>i</sub>&nbsp;- x<sub>j</sub>|&nbsp;&lt;= k</code> 的点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
<strong>输出：</strong>4
<strong>解释：</strong>前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| &lt;= 1 ，代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>points = [[0,0],[3,0],[9,2]], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>只有前两个点满足 |x<sub>i</sub>&nbsp;- x<sub>j</sub>| &lt;= 3 ，代入方程后得到值 0 + 0 + |0 - 3| = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= points.length &lt;= 10^5</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10^8&nbsp;&lt;= points[i][0], points[i][1] &lt;= 10^8</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10^8</code></li>
	<li>对于所有的<code>1 &lt;= i &lt; j &lt;= points.length</code> ，<code>points[i][0] &lt; points[j][0]</code> 都成立。也就是说，<code>x<sub>i</sub></code> 是严格递增的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

题目要求 $y_i + y_j + |x_i - x_j|$ 的最大值，其中 $i \lt j$，并且 $|x_i - x_j| \leq k$。由于 $x_i$ 是严格单调递增的，那么：

$$
\begin{aligned}
y_i + y_j + |x_i - x_j| & = y_i + y_j + x_j - x_i \\
& = (y_i - x_i) + (x_j + y_j)
\end{aligned}
$$

因此，对于当前遍历到的点 $(x_j, y_j)$，我们只需要找到前面所有满足 $x_j - x_i \leq k$ 的点 $(x_i, y_i)$ 中 $y_i - x_i$ 的最大值，再加上当前的 $x_j + y_j$ 即可。而 $y_i - x_i$ 的最大值，我们可以使用优先队列（大根堆）来维护。

具体地，我们定义一个优先队列（大根堆） $pq$，堆中每个元素是一个二元组 $(y_i - x_i, x_i)$。

当我们遍历到点 $(x, y)$ 时，如果堆 $pq$ 不为空，并且 $x - pq[0][1] \gt k$，那么循环将堆顶元素弹出，直到堆为空或者满足 $x - pq[0][1] \leq k$。此时，堆顶元素 $(y_i - x_i, x_i)$ 即为所有满足 $x_j - x_i \leq k$ 的点中 $y_i - x_i$ 的最大值，此时更新答案 $ans = \max(ans, x + y + pq[0][0])$。

然后，我们将点 $(x, y)$ 加入堆中，继续遍历下一个点，直到遍历完整个数组 $points$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -inf
        pq = []
        for x, y in points:
            while pq and x - pq[0][1] > k:
                heappop(pq)
            if pq:
                ans = max(ans, x + y - pq[0][0])
            heappush(pq, (x - y, x))
        return ans
```

#### Java

```java
class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int ans = -(1 << 30);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (var p : points) {
            int x = p[0], y = p[1];
            while (!pq.isEmpty() && x - pq.peek()[1] > k) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                ans = Math.max(ans, x + y + pq.peek()[0]);
            }
            pq.offer(new int[] {y - x, x});
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -(1 << 30);
        priority_queue<pair<int, int>> pq;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (pq.size() && x - pq.top().second > k) {
                pq.pop();
            }
            if (pq.size()) {
                ans = max(ans, x + y + pq.top().first);
            }
            pq.emplace(y - x, x);
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxValueOfEquation(points [][]int, k int) int {
	ans := -(1 << 30)
	hp := hp{}
	for _, p := range points {
		x, y := p[0], p[1]
		for hp.Len() > 0 && x-hp[0].x > k {
			heap.Pop(&hp)
		}
		if hp.Len() > 0 {
			ans = max(ans, x+y+hp[0].v)
		}
		heap.Push(&hp, pair{y - x, x})
	}
	return ans
}

type pair struct{ v, x int }

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.v > b.v
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function findMaxValueOfEquation(points: number[][], k: number): number {
    let ans = -(1 << 30);
    const pq = new Heap<[number, number]>((a, b) => b[0] - a[0]);
    for (const [x, y] of points) {
        while (pq.size() && x - pq.top()[1] > k) {
            pq.pop();
        }
        if (pq.size()) {
            ans = Math.max(ans, x + y + pq.top()[0]);
        }
        pq.push([y - x, x]);
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class Heap<T = number> {
    data: Array<T | null>;
    lt: (i: number, j: number) => boolean;
    constructor();
    constructor(data: T[]);
    constructor(compare: Compare<T>);
    constructor(data: T[], compare: Compare<T>);
    constructor(data: T[] | Compare<T>, compare?: (lhs: T, rhs: T) => number);
    constructor(
        data: T[] | Compare<T> = [],
        compare: Compare<T> = (lhs: T, rhs: T) => (lhs < rhs ? -1 : lhs > rhs ? 1 : 0),
    ) {
        if (typeof data === 'function') {
            compare = data;
            data = [];
        }
        this.data = [null, ...data];
        this.lt = (i, j) => compare(this.data[i]!, this.data[j]!) < 0;
        for (let i = this.size(); i > 0; i--) this.heapify(i);
    }

    size(): number {
        return this.data.length - 1;
    }

    push(v: T): void {
        this.data.push(v);
        let i = this.size();
        while (i >> 1 !== 0 && this.lt(i, i >> 1)) this.swap(i, (i >>= 1));
    }

    pop(): T {
        this.swap(1, this.size());
        const top = this.data.pop();
        this.heapify(1);
        return top!;
    }

    top(): T {
        return this.data[1]!;
    }
    heapify(i: number): void {
        while (true) {
            let min = i;
            const [l, r, n] = [i * 2, i * 2 + 1, this.data.length];
            if (l < n && this.lt(l, min)) min = l;
            if (r < n && this.lt(r, min)) min = r;
            if (min !== i) {
                this.swap(i, min);
                i = min;
            } else break;
        }
    }

    clear(): void {
        this.data = [null];
    }

    private swap(i: number, j: number): void {
        const d = this.data;
        [d[i], d[j]] = [d[j], d[i]];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调队列

这道题实际上需要我们维护的是一个长度为 $k$ 的窗口中 $y-x$ 的最大值，单调队列可以很好地解决这个问题。

具体地，我们定义一个单调队列 $q$，队列中每个元素是一个二元组 $(x_i, y_i)$。

当我们遍历到点 $(x, y)$ 时，如果队列 $q$ 不为空，并且 $x - q[0][0] \gt k$，那么不断弹出队首元素，直到队列为空或者满足 $x - q[0][0] \leq k$。此时，队首元素 $(x_i, y_i)$ 即为所有满足 $x_j - x_i \leq k$ 的点中 $y_i - x_i$ 的最大值，此时更新答案 $ans = \max(ans, x + y + y_i - x_i)$。

接下来，在将点 $(x, y)$ 加入队尾之前，我们将队列中所有 $y_i - x_i \leq y - x$ 的元素 $(x_i, y_i)$ 弹出队列，然后将点 $(x, y)$ 加入队尾。继续遍历下一个点，直到遍历完整个数组 $points$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -inf
        q = deque()
        for x, y in points:
            while q and x - q[0][0] > k:
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][1] - q[0][0])
            while q and y - x >= q[-1][1] - q[-1][0]:
                q.pop()
            q.append((x, y))
        return ans
```

#### Java

```java
class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int ans = -(1 << 30);
        Deque<int[]> q = new ArrayDeque<>();
        for (var p : points) {
            int x = p[0], y = p[1];
            while (!q.isEmpty() && x - q.peekFirst()[0] > k) {
                q.pollFirst();
            }
            if (!q.isEmpty()) {
                ans = Math.max(ans, x + y + q.peekFirst()[1] - q.peekFirst()[0]);
            }
            while (!q.isEmpty() && y - x >= q.peekLast()[1] - q.peekLast()[0]) {
                q.pollLast();
            }
            q.offerLast(p);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -(1 << 30);
        deque<pair<int, int>> q;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (!q.empty() && x - q.front().first > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                ans = max(ans, x + y + q.front().second - q.front().first);
            }
            while (!q.empty() && y - x >= q.back().second - q.back().first) {
                q.pop_back();
            }
            q.emplace_back(x, y);
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxValueOfEquation(points [][]int, k int) int {
	ans := -(1 << 30)
	q := [][2]int{}
	for _, p := range points {
		x, y := p[0], p[1]
		for len(q) > 0 && x-q[0][0] > k {
			q = q[1:]
		}
		if len(q) > 0 {
			ans = max(ans, x+y+q[0][1]-q[0][0])
		}
		for len(q) > 0 && y-x >= q[len(q)-1][1]-q[len(q)-1][0] {
			q = q[:len(q)-1]
		}
		q = append(q, [2]int{x, y})
	}
	return ans
}
```

#### TypeScript

```ts
function findMaxValueOfEquation(points: number[][], k: number): number {
    let ans = -(1 << 30);
    const q: number[][] = [];
    for (const [x, y] of points) {
        while (q.length > 0 && x - q[0][0] > k) {
            q.shift();
        }
        if (q.length > 0) {
            ans = Math.max(ans, x + y + q[0][1] - q[0][0]);
        }
        while (q.length > 0 && y - x > q[q.length - 1][1] - q[q.length - 1][0]) {
            q.pop();
        }
        q.push([x, y]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

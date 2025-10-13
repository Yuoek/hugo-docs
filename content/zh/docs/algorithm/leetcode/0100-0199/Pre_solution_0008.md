---
title: "0170_两数之和 III - 数据结构设计 🔒"
date: 2025-10-08T18:45:43+08:00
weight: 8
tags: [二叉搜索树, 二叉树, 动态规划, 双指针, 哈希表, 字符串, 排序, 数学, 数据库, 数据流, 数组, 栈, 树, 矩阵, 设计, 贪心, 迭代器]
---

{{< markmap >}}
### [0170_两数之和 III - 数据结构设计 🔒](#170)
#### [设计](#170)
#### [数组](#170)
#### [哈希表](#170)
#### [双指针](#170)
#### [数据流](#170)
### [0171_Excel 表列序号](#171)
#### [数学](#171)
#### [字符串](#171)
### [0172_阶乘后的零](#172)
#### [数学](#172)
### [0173_二叉搜索树迭代器](#173)
#### [栈](#173)
#### [树](#173)
#### [设计](#173)
#### [二叉搜索树](#173)
#### [二叉树](#173)
#### [迭代器](#173)
### [0174_地下城游戏](#174)
#### [数组](#174)
#### [动态规划](#174)
#### [矩阵](#174)
### [0175_组合两个表](#175)
#### [数据库](#175)
### [0176_第二高的薪水](#176)
#### [数据库](#176)
### [0177_第N高的薪水](#177)
#### [数据库](#177)
### [0178_分数排名](#178)
#### [数据库](#178)
### [0179_最大数](#179)
#### [贪心](#179)
#### [数组](#179)
#### [字符串](#179)
#### [排序](#179)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0170_两数之和 III - 数据结构设计 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 数据流
---
### 0171_Excel 表列序号
___
#### 数学
___
#### 字符串
---
### 0172_阶乘后的零
___
#### 数学
---
### 0173_二叉搜索树迭代器
___
#### 栈
___
#### 树
___
#### 设计
___
#### 二叉搜索树
___
#### 二叉树
___
#### 迭代器
---
### 0174_地下城游戏
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0175_组合两个表
___
#### 数据库
---
### 0176_第二高的薪水
___
#### 数据库
---
### 0177_第N高的薪水
___
#### 数据库
---
### 0178_分数排名
___
#### 数据库
---
### 0179_最大数
___
#### 贪心
___
#### 数组
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 排序 | 数学 | 数据库 |
| 数据流 | 数组 | 栈 |
| 树 | 矩阵 | 设计 |
| 贪心 | 迭代器 |  |

# [170. 两数之和 III - 数据结构设计 🔒](https://leetcode.cn/problems/two-sum-iii-data-structure-design){#170}

{{< tabs "170" >}}

{{% tab "python" %}}
```python
class TwoSum:

    def __init__(self):
        self.cnt = defaultdict(int)

    def add(self, number: int) -> None:
        self.cnt[number] += 1

    def find(self, value: int) -> bool:
        for x, v in self.cnt.items():
            y = value - x
            if y in self.cnt and (x != y or v > 1):
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TwoSum {
    private Map<Integer, Integer> cnt = new HashMap<>();

    public TwoSum() {
    }

    public void add(int number) {
        cnt.merge(number, 1, Integer::sum);
    }

    public boolean find(int value) {
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int y = value - x;
            if (cnt.containsKey(y) && (x != y || v > 1)) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TwoSum {
public:
    TwoSum() {
    }

    void add(int number) {
        ++cnt[number];
    }

    bool find(int value) {
        for (auto& [x, v] : cnt) {
            long y = (long) value - x;
            if (cnt.contains(y) && (x != y || v > 1)) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> cnt;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TwoSum struct {
	cnt map[int]int
}

func Constructor() TwoSum {
	return TwoSum{map[int]int{}}
}

func (this *TwoSum) Add(number int) {
	this.cnt[number] += 1
}

func (this *TwoSum) Find(value int) bool {
	for x, v := range this.cnt {
		y := value - x
		if _, ok := this.cnt[y]; ok && (x != y || v > 1) {
			return true
		}
	}
	return false
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * param_2 := obj.Find(value);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class TwoSum {
    private cnt: Map<number, number> = new Map();
    constructor() {}

    add(number: number): void {
        this.cnt.set(number, (this.cnt.get(number) || 0) + 1);
    }

    find(value: number): boolean {
        for (const [x, v] of this.cnt) {
            const y = value - x;
            if (this.cnt.has(y) && (x !== y || v > 1)) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * var obj = new TwoSum()
 * obj.add(number)
 * var param_2 = obj.find(value)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个接收整数流的数据结构，该数据结构支持检查是否存在两数之和等于特定值。</p>

<p>实现 <code>TwoSum</code> 类：</p>

<ul>
	<li><code>TwoSum()</code> 使用空数组初始化 <code>TwoSum</code> 对象</li>
	<li><code>void add(int number)</code> 向数据结构添加一个数 <code>number</code></li>
	<li><code>boolean find(int value)</code> 寻找数据结构中是否存在一对整数，使得两数之和与给定的值相等。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
<strong>输出：</strong>
[null, null, null, null, true, false]

<strong>解释：</strong>
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --&gt; [1]
twoSum.add(3);   // [1] --&gt; [1,3]
twoSum.add(5);   // [1,3] --&gt; [1,3,5]
twoSum.find(4);  // 1 + 3 = 4，返回 true
twoSum.find(7);  // 没有两个整数加起来等于 7 ，返回 false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-10<sup>5</sup> &lt;= number &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= value &lt;= 2<sup>31</sup> - 1</code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>add</code> 和 <code>find</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 `cnt` 存储数字出现的次数。

调用 `add` 方法时，将数字 `number` 的出现次数加一。

调用 `find` 方法时，遍历哈希表 `cnt`，对于每个键 `x`，判断 `value - x` 是否也是哈希表 `cnt` 的键，如果是，判断 `x` 是否等于 `value - x`，如果不等，说明找到了一对和为 `value` 的数字，返回 `true`；如果等，判断 `x` 的出现次数是否大于 `1`，如果大于 `1`，说明找到了一对和为 `value` 的数字，返回 `true`；如果小于等于 `1`，说明没有找到一对和为 `value` 的数字，继续遍历哈希表 `cnt`，如果遍历结束都没有找到，返回 `false`。

时间复杂度：

-   `add` 方法的时间复杂度为 $O(1)$；
-   `find` 方法的时间复杂度为 $O(n)$。

空间复杂度 $O(n)$，其中 $n$ 为哈希表 `cnt` 的大小。

<!-- tabs:start -->

#### Python3

```python
class TwoSum:

    def __init__(self):
        self.cnt = defaultdict(int)

    def add(self, number: int) -> None:
        self.cnt[number] += 1

    def find(self, value: int) -> bool:
        for x, v in self.cnt.items():
            y = value - x
            if y in self.cnt and (x != y or v > 1):
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
```

#### Java

```java
class TwoSum {
    private Map<Integer, Integer> cnt = new HashMap<>();

    public TwoSum() {
    }

    public void add(int number) {
        cnt.merge(number, 1, Integer::sum);
    }

    public boolean find(int value) {
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            int y = value - x;
            if (cnt.containsKey(y) && (x != y || v > 1)) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
```

#### C++

```cpp
class TwoSum {
public:
    TwoSum() {
    }

    void add(int number) {
        ++cnt[number];
    }

    bool find(int value) {
        for (auto& [x, v] : cnt) {
            long y = (long) value - x;
            if (cnt.contains(y) && (x != y || v > 1)) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> cnt;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
```

#### Go

```go
type TwoSum struct {
	cnt map[int]int
}

func Constructor() TwoSum {
	return TwoSum{map[int]int{}}
}

func (this *TwoSum) Add(number int) {
	this.cnt[number] += 1
}

func (this *TwoSum) Find(value int) bool {
	for x, v := range this.cnt {
		y := value - x
		if _, ok := this.cnt[y]; ok && (x != y || v > 1) {
			return true
		}
	}
	return false
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * param_2 := obj.Find(value);
 */
```

#### TypeScript

```ts
class TwoSum {
    private cnt: Map<number, number> = new Map();
    constructor() {}

    add(number: number): void {
        this.cnt.set(number, (this.cnt.get(number) || 0) + 1);
    }

    find(value: number): boolean {
        for (const [x, v] of this.cnt) {
            const y = value - x;
            if (this.cnt.has(y) && (x !== y || v > 1)) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * var obj = new TwoSum()
 * obj.add(number)
 * var param_2 = obj.find(value)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [171. Excel 表列序号](https://leetcode.cn/problems/excel-sheet-column-number){#171}

{{< tabs "171" >}}

{{% tab "python" %}}
```python
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for c in map(ord, columnTitle):
            ans = ans * 26 + c - ord("A") + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int titleToNumber(String columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.length(); ++i) {
            ans = ans * 26 + (columnTitle.charAt(i) - 'A' + 1);
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
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char& c : columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func titleToNumber(columnTitle string) (ans int) {
	for _, c := range columnTitle {
		ans = ans*26 + int(c-'A'+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function titleToNumber(columnTitle: string): number {
    let ans: number = 0;
    for (const c of columnTitle) {
        ans = ans * 26 + (c.charCodeAt(0) - 'A'.charCodeAt(0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int TitleToNumber(string columnTitle) {
        int ans = 0;
        foreach (char c in columnTitle) {
            ans = ans * 26 + c - 'A' + 1;
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>columnTitle</code> ，表示 Excel 表格中的列名称。返回 <em>该列名称对应的列序号</em>&nbsp;。</p>

<p>例如：</p>

<pre>
A -&gt; 1
B -&gt; 2
C -&gt; 3
...
Z -&gt; 26
AA -&gt; 27
AB -&gt; 28 
...</pre>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> columnTitle = "A"
<strong>输出:</strong> 1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>columnTitle = "AB"
<strong>输出:</strong> 28
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入: </strong>columnTitle = "ZY"
<strong>输出:</strong> 701</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= columnTitle.length &lt;= 7</code></li>
	<li><code>columnTitle</code> 仅由大写英文组成</li>
	<li><code>columnTitle</code> 在范围 <code>["A", "FXSHRXW"]</code> 内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：进制转换

Excel 表格中的列名称是一种 26 进制的表示方法。例如，"AB" 表示的列序号是 $1 \times 26 + 2 = 28$。

因此，我们可以遍历字符串 `columnTitle`，将每个字符转换为对应的数值，然后计算结果即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 `columnTitle` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for c in map(ord, columnTitle):
            ans = ans * 26 + c - ord("A") + 1
        return ans
```

#### Java

```java
class Solution {
    public int titleToNumber(String columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.length(); ++i) {
            ans = ans * 26 + (columnTitle.charAt(i) - 'A' + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (char& c : columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func titleToNumber(columnTitle string) (ans int) {
	for _, c := range columnTitle {
		ans = ans*26 + int(c-'A'+1)
	}
	return
}
```

#### TypeScript

```ts
function titleToNumber(columnTitle: string): number {
    let ans: number = 0;
    for (const c of columnTitle) {
        ans = ans * 26 + (c.charCodeAt(0) - 'A'.charCodeAt(0) + 1);
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int TitleToNumber(string columnTitle) {
        int ans = 0;
        foreach (char c in columnTitle) {
            ans = ans * 26 + c - 'A' + 1;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [172. 阶乘后的零](https://leetcode.cn/problems/factorial-trailing-zeroes){#172}

{{< tabs "172" >}}

{{% tab "python" %}}
```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n:
            n //= 5
            ans += n
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
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
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func trailingZeroes(n int) int {
	ans := 0
	for n > 0 {
		n /= 5
		ans += n
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function trailingZeroes(n: number): number {
    let ans = 0;
    while (n > 0) {
        n = Math.floor(n / 5);
        ans += n;
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

<p>给定一个整数 <code>n</code> ，返回 <code>n!</code> 结果中尾随零的数量。</p>

<p>提示&nbsp;<code>n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1</code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>0
<strong>解释：</strong>3! = 6 ，不含尾随 0
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>1
<strong>解释：</strong>5! = 120 ，有一个尾随 0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你可以设计并实现对数时间复杂度的算法来解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

题目实际上是求 $[1,n]$ 中有多少个 $5$ 的因数。

我们以 $130$ 为例来分析：

1. 第 $1$ 次除以 $5$，得到 $26$，表示存在 $26$ 个包含因数 $5$ 的数；
1. 第 $2$ 次除以 $5$，得到 $5$，表示存在 $5$ 个包含因数 $5^2$ 的数；
1. 第 $3$ 次除以 $5$，得到 $1$，表示存在 $1$ 个包含因数 $5^3$ 的数；
1. 累加得到从 $[1,n]$ 中所有 $5$ 的因数的个数。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n:
            n //= 5
            ans += n
        return ans
```

#### Java

```java
class Solution {
    public int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
```

#### Go

```go
func trailingZeroes(n int) int {
	ans := 0
	for n > 0 {
		n /= 5
		ans += n
	}
	return ans
}
```

#### TypeScript

```ts
function trailingZeroes(n: number): number {
    let ans = 0;
    while (n > 0) {
        n = Math.floor(n / 5);
        ans += n;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [173. 二叉搜索树迭代器](https://leetcode.cn/problems/binary-search-tree-iterator){#173}

{{< tabs "173" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        cur = self.stack.pop()
        node = cur.right
        while node:
            self.stack.append(node)
            node = node.left
        return cur.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private Deque<TreeNode> stack = new LinkedList<>();

    public BSTIterator(TreeNode root) {
        for (; root != null; root = root.left) {
            stack.offerLast(root);
        }
    }

    public int next() {
        TreeNode cur = stack.pollLast();
        for (TreeNode node = cur.right; node != null; node = node.left) {
            stack.offerLast(node);
        }
        return cur.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stack;
    BSTIterator(TreeNode* root) {
        for (; root != nullptr; root = root->left) {
            stack.push(root);
        }
    }

    int next() {
        TreeNode* cur = stack.top();
        stack.pop();
        TreeNode* node = cur->right;
        for (; node != nullptr; node = node->left) {
            stack.push(node);
        }
        return cur->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	var stack []*TreeNode
	for ; root != nil; root = root.Left {
		stack = append(stack, root)
	}
	return BSTIterator{
		stack: stack,
	}
}

func (this *BSTIterator) Next() int {
	cur := this.stack[len(this.stack)-1]
	this.stack = this.stack[:len(this.stack)-1]
	for node := cur.Right; node != nil; node = node.Left {
		this.stack = append(this.stack, node)
	}
	return cur.Val
}

func (this *BSTIterator) HasNext() bool {
	return len(this.stack) > 0
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
    private stack: TreeNode[];

    constructor(root: TreeNode | null) {
        this.stack = [];
        const dfs = (root: TreeNode | null) => {
            if (root == null) {
                return;
            }
            this.stack.push(root);
            dfs(root.left);
        };
        dfs(root);
    }

    next(): number {
        const { val, right } = this.stack.pop();
        if (right) {
            let cur = right;
            while (cur != null) {
                this.stack.push(cur);
                cur = cur.left;
            }
        }
        return val;
    }

    hasNext(): boolean {
        return this.stack.length !== 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    stack: Vec<Option<Rc<RefCell<TreeNode>>>>,
}

use std::cell::RefCell;
use std::rc::Rc;
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn dfs(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        stack: &mut Vec<Option<Rc<RefCell<TreeNode>>>>,
    ) {
        if root.is_some() {
            let left = root.as_mut().unwrap().borrow_mut().left.take();
            stack.push(root);
            Self::dfs(left, stack);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut stack = vec![];
        Self::dfs(root, &mut stack);
        BSTIterator { stack }
    }

    fn next(&mut self) -> i32 {
        let node = self.stack.pop().unwrap().unwrap();
        let mut node = node.borrow_mut();
        if node.right.is_some() {
            Self::dfs(node.right.take(), &mut self.stack);
        }
        node.val
    }

    fn has_next(&self) -> bool {
        self.stack.len() != 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var BSTIterator = function (root) {
    this.stack = [];
    for (; root != null; root = root.left) {
        this.stack.push(root);
    }
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function () {
    let cur = this.stack.pop();
    let node = cur.right;
    for (; node != null; node = node.left) {
        this.stack.push(node);
    }
    return cur.val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function () {
    return this.stack.length > 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

实现一个二叉搜索树迭代器类<code>BSTIterator</code> ，表示一个按中序遍历二叉搜索树（BST）的迭代器：

<div class="original__bRMd">
<div>
<ul>
	<li><code>BSTIterator(TreeNode root)</code> 初始化 <code>BSTIterator</code> 类的一个对象。BST 的根节点 <code>root</code> 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。</li>
	<li><code>boolean hasNext()</code> 如果向指针右侧遍历存在数字，则返回 <code>true</code> ；否则返回 <code>false</code> 。</li>
	<li><code>int next()</code>将指针向右移动，然后返回指针处的数字。</li>
</ul>

<p>注意，指针初始化为一个不存在于 BST 中的数字，所以对 <code>next()</code> 的首次调用将返回 BST 中的最小元素。</p>
</div>
</div>

<p>你可以假设 <code>next()</code> 调用总是有效的，也就是说，当调用 <code>next()</code> 时，BST 的中序遍历中至少存在一个下一个数字。</p>

<p> </p>

<p><strong>示例：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0173.Binary%20Search%20Tree%20Iterator/images/bst-tree.png" style="width: 189px; height: 178px;" />
<pre>
<strong>输入</strong>
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
<strong>输出</strong>
[null, 3, 7, true, 9, true, 15, true, 20, false]

<strong>解释</strong>
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next(); // 返回 3
bSTIterator.next(); // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next(); // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next(); // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next(); // 返回 20
bSTIterator.hasNext(); // 返回 False

</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 <= Node.val <= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>5</sup></code> 次 <code>hasNext</code> 和 <code>next</code> 操作</li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以设计一个满足下述条件的解决方案吗？<code>next()</code> 和 <code>hasNext()</code> 操作均摊时间复杂度为 <code>O(1)</code> ，并使用 <code>O(h)</code> 内存。其中 <code>h</code> 是树的高度。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

初始化数据时，递归中序遍历，将二叉搜索树每个结点的值保存在列表 `vals` 中。用 `cur` 指针记录外部即将遍历的位置，初始化为 0。

调用 `next()` 时，返回 `vals[cur]`，同时 `cur` 指针自增。调用 `hasNext()` 时，判断 `cur` 指针是否已经达到 `len(vals)` 个数，若是，说明已经遍历结束，返回 false，否则返回 true。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        def inorder(root):
            if root:
                inorder(root.left)
                self.vals.append(root.val)
                inorder(root.right)

        self.cur = 0
        self.vals = []
        inorder(root)

    def next(self) -> int:
        res = self.vals[self.cur]
        self.cur += 1
        return res

    def hasNext(self) -> bool:
        return self.cur < len(self.vals)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private int cur = 0;
    private List<Integer> vals = new ArrayList<>();

    public BSTIterator(TreeNode root) {
        inorder(root);
    }

    public int next() {
        return vals.get(cur++);
    }

    public boolean hasNext() {
        return cur < vals.size();
    }

    private void inorder(TreeNode root) {
        if (root != null) {
            inorder(root.left);
            vals.add(root.val);
            inorder(root.right);
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> vals;
    int cur;
    BSTIterator(TreeNode* root) {
        cur = 0;
        inorder(root);
    }

    int next() {
        return vals[cur++];
    }

    bool hasNext() {
        return cur < vals.size();
    }

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            vals.push_back(root->val);
            inorder(root->right);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
	stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	var stack []*TreeNode
	for ; root != nil; root = root.Left {
		stack = append(stack, root)
	}
	return BSTIterator{
		stack: stack,
	}
}

func (this *BSTIterator) Next() int {
	cur := this.stack[len(this.stack)-1]
	this.stack = this.stack[:len(this.stack)-1]
	for node := cur.Right; node != nil; node = node.Left {
		this.stack = append(this.stack, node)
	}
	return cur.Val
}

func (this *BSTIterator) HasNext() bool {
	return len(this.stack) > 0
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
    private data: number[];
    private index: number;

    constructor(root: TreeNode | null) {
        this.index = 0;
        this.data = [];
        const dfs = (root: TreeNode | null) => {
            if (root == null) {
                return;
            }
            const { val, left, right } = root;
            dfs(left);
            this.data.push(val);
            dfs(right);
        };
        dfs(root);
    }

    next(): number {
        return this.data[this.index++];
    }

    hasNext(): boolean {
        return this.index < this.data.length;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    vals: Vec<i32>,
    index: usize,
}

use std::cell::RefCell;
use std::rc::Rc;
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn inorder(root: &Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<i32>) {
        if let Some(node) = root {
            let node = node.as_ref().borrow();
            Self::inorder(&node.left, res);
            res.push(node.val);
            Self::inorder(&node.right, res);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut vals = vec![];
        Self::inorder(&root, &mut vals);
        BSTIterator { vals, index: 0 }
    }

    fn next(&mut self) -> i32 {
        self.index += 1;
        self.vals[self.index - 1]
    }

    fn has_next(&self) -> bool {
        self.index != self.vals.len()
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var BSTIterator = function (root) {
    this.stack = [];
    for (; root != null; root = root.left) {
        this.stack.push(root);
    }
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function () {
    let cur = this.stack.pop();
    let node = cur.right;
    for (; node != null; node = node.left) {
        this.stack.push(node);
    }
    return cur.val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function () {
    return this.stack.length > 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈迭代

初始化时，从根节点一路遍历所有左子节点，压入栈 `stack` 中。

调用 `next()`时，弹出栈顶元素 `cur`，获取 `cur` 的右子节点 `node`，若 `node` 不为空，一直循环压入左节点。最后返回 `cur.val` 即可。调用 `hasNext()` 时，判断 `stack` 是否为空，空则表示迭代结束。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root: TreeNode):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        cur = self.stack.pop()
        node = cur.right
        while node:
            self.stack.append(node)
            node = node.left
        return cur.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private Deque<TreeNode> stack = new LinkedList<>();

    public BSTIterator(TreeNode root) {
        for (; root != null; root = root.left) {
            stack.offerLast(root);
        }
    }

    public int next() {
        TreeNode cur = stack.pollLast();
        for (TreeNode node = cur.right; node != null; node = node.left) {
            stack.offerLast(node);
        }
        return cur.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stack;
    BSTIterator(TreeNode* root) {
        for (; root != nullptr; root = root->left) {
            stack.push(root);
        }
    }

    int next() {
        TreeNode* cur = stack.top();
        stack.pop();
        TreeNode* node = cur->right;
        for (; node != nullptr; node = node->left) {
            stack.push(node);
        }
        return cur->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

class BSTIterator {
    private stack: TreeNode[];

    constructor(root: TreeNode | null) {
        this.stack = [];
        const dfs = (root: TreeNode | null) => {
            if (root == null) {
                return;
            }
            this.stack.push(root);
            dfs(root.left);
        };
        dfs(root);
    }

    next(): number {
        const { val, right } = this.stack.pop();
        if (right) {
            let cur = right;
            while (cur != null) {
                this.stack.push(cur);
                cur = cur.left;
            }
        }
        return val;
    }

    hasNext(): boolean {
        return this.stack.length !== 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
struct BSTIterator {
    stack: Vec<Option<Rc<RefCell<TreeNode>>>>,
}

use std::cell::RefCell;
use std::rc::Rc;
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn dfs(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        stack: &mut Vec<Option<Rc<RefCell<TreeNode>>>>,
    ) {
        if root.is_some() {
            let left = root.as_mut().unwrap().borrow_mut().left.take();
            stack.push(root);
            Self::dfs(left, stack);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut stack = vec![];
        Self::dfs(root, &mut stack);
        BSTIterator { stack }
    }

    fn next(&mut self) -> i32 {
        let node = self.stack.pop().unwrap().unwrap();
        let mut node = node.borrow_mut();
        if node.right.is_some() {
            Self::dfs(node.right.take(), &mut self.stack);
        }
        node.val
    }

    fn has_next(&self) -> bool {
        self.stack.len() != 0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [174. 地下城游戏](https://leetcode.cn/problems/dungeon-game){#174}

{{< tabs "174" >}}

{{% tab "python" %}}
```python
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[inf] * (n + 1) for _ in range(m + 1)]
        dp[m][n - 1] = dp[m - 1][n] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])
        return dp[0][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m + 1][n + 1];
        for (var e : dp) {
            Arrays.fill(e, 1 << 30);
        }
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = Math.max(1, Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func calculateMinimumHP(dungeon [][]int) int {
	m, n := len(dungeon), len(dungeon[0])
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = 1 << 30
		}
	}
	dp[m][n-1], dp[m-1][n] = 1, 1
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j])
		}
	}
	return dp[0][0]
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CalculateMinimumHP(int[][] dungeon) {
        int m = dungeon.Length, n = dungeon[0].Length;
        int[][] dp = new int[m + 1][];
        for (int i = 0; i < m + 1; ++i) {
            dp[i] = new int[n + 1];
            Array.Fill(dp[i], 1 << 30);
        }
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = Math.Max(1, Math.Min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<style type="text/css">table.dungeon, .dungeon th, .dungeon td {
  border:3px solid black;
}

 .dungeon th, .dungeon td {
    text-align: center;
    height: 70px;
    width: 70px;
}
</style>
<p>恶魔们抓住了公主并将她关在了地下城&nbsp;<code>dungeon</code> 的 <strong>右下角</strong> 。地下城是由 <code>m x n</code> 个房间组成的二维网格。我们英勇的骑士最初被安置在 <strong>左上角</strong> 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。</p>

<p>骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。</p>

<p>有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为<em>负整数</em>，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 <em>0</em>），要么包含增加骑士健康点数的魔法球（若房间里的值为<em>正整数</em>，则表示骑士将增加健康点数）。</p>

<p>为了尽快解救公主，骑士决定每次只 <strong>向右</strong> 或 <strong>向下</strong> 移动一步。</p>

<p>返回确保骑士能够拯救到公主所需的最低初始健康点数。</p>

<p><strong>注意：</strong>任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0174.Dungeon%20Game/images/dungeon-grid-1.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
<strong>输出：</strong>7
<strong>解释：</strong>如果骑士遵循最佳路径：右 -&gt; 右 -&gt; 下 -&gt; 下 ，则骑士的初始健康点数至少为 7 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>dungeon = [[0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == dungeon.length</code></li>
	<li><code>n == dungeon[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-1000 &lt;= dungeon[i][j] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $dp[i][j]$ 表示从 $(i, j)$ 到终点所需的最小初始值，那么 $dp[i][j]$ 的值可以由 $dp[i+1][j]$ 和 $dp[i][j+1]$ 得到，即：

$$
dp[i][j] = \max(\min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1)
$$

初始时 $dp[m][n-1]$ 和 $dp[m-1][n]$ 都为 $1$，其他位置的值为最大值。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为地牢的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[inf] * (n + 1) for _ in range(m + 1)]
        dp[m][n - 1] = dp[m - 1][n] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j])
        return dp[0][0]
```

#### Java

```java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m + 1][n + 1];
        for (var e : dp) {
            Arrays.fill(e, 1 << 30);
        }
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = Math.max(1, Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
```

#### Go

```go
func calculateMinimumHP(dungeon [][]int) int {
	m, n := len(dungeon), len(dungeon[0])
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = 1 << 30
		}
	}
	dp[m][n-1], dp[m-1][n] = 1, 1
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j])
		}
	}
	return dp[0][0]
}
```

#### C#

```cs
public class Solution {
    public int CalculateMinimumHP(int[][] dungeon) {
        int m = dungeon.Length, n = dungeon[0].Length;
        int[][] dp = new int[m + 1][];
        for (int i = 0; i < m + 1; ++i) {
            dp[i] = new int[n + 1];
            Array.Fill(dp[i], 1 << 30);
        }
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = Math.Max(1, Math.Min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [175. 组合两个表](https://leetcode.cn/problems/combine-two-tables){#175}

{{< tabs "175" >}}

{{% tab "python" %}}
```python
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]
    ]
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT firstName, lastName, city, state
FROM
    Person
    LEFT JOIN Address USING (personId);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Person</code></p>

<pre>
+-------------+---------+
| 列名         | 类型     |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
personId 是该表的主键（具有唯一值的列）。
该表包含一些人的 ID 和他们的姓和名的信息。
</pre>

<p>&nbsp;</p>

<p>表: <code>Address</code></p>

<pre>
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
addressId 是该表的主键（具有唯一值的列）。
该表的每一行都包含一个 ID = PersonId 的人的城市和州的信息。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告 <code>Person</code> 表中每个人的姓、名、城市和州。如果 <code>personId</code> 的地址不在&nbsp;<code>Address</code>&nbsp;表中，则报告为&nbsp;<code>null</code>&nbsp;。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Person表:
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |
+----------+----------+-----------+
Address表:
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |
+-----------+----------+---------------+------------+
<strong>输出:</strong> 
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |
+-----------+----------+---------------+----------+
<strong>解释:</strong> 
地址表中没有 personId = 1 的地址，所以它们的城市和州返回 null。
addressId = 1 包含了 personId = 2 的地址信息。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接

我们可以使用左连接，将 `Person` 表左连接 `Address` 表，连接条件为 `Person.personId = Address.personId`，这样就可以得到每个人的姓、名、城市和州。如果 `personId` 的地址不在 `Address` 表中，则报告为空 `null`。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=person, right=address, how="left", on="personId")[
        ["firstName", "lastName", "city", "state"]
    ]
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT firstName, lastName, city, state
FROM
    Person
    LEFT JOIN Address USING (personId);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [176. 第二高的薪水](https://leetcode.cn/problems/second-highest-salary){#176}

{{< tabs "176" >}}

{{% tab "python" %}}
```python
import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # Drop any duplicate salary values to avoid counting duplicates as separate salary ranks
    unique_salaries = employee["salary"].drop_duplicates()

    # Sort the unique salaries in descending order and get the second highest salary
    second_highest = (
        unique_salaries.nlargest(2).iloc[-1] if len(unique_salaries) >= 2 else None
    )

    # If the second highest salary doesn't exist (e.g., there are fewer than two unique salaries), return None
    if second_highest is None:
        return pd.DataFrame({"SecondHighestSalary": [None]})

    # Create a DataFrame with the second highest salary
    result_df = pd.DataFrame({"SecondHighestSalary": [second_highest]})

    return result_df
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH T AS (SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rk FROM Employee)
SELECT (SELECT DISTINCT salary FROM T WHERE rk = 2) AS SecondHighestSalary;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<code>Employee</code> 表：

<div class="original__bRMd">
<div>
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id 是这个表的主键。
表的每一行包含员工的工资信息。
</pre>

<p>&nbsp;</p>

<p>查询并返回 <code>Employee</code>&nbsp;表中第二高的 <b>不同</b>&nbsp;薪水 。如果不存在第二高的薪水，查询应该返回 <code>null(Pandas 则返回 None)</code> 。</p>

<p>查询结果如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
<strong>输出：</strong>
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
Employee 表：
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
<strong>输出：</strong>
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
</pre>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 LIMIT 语句和子查询

我们可以按照薪水降序排列，然后使用 `LIMIT` 语句来获取第二高的薪水，如果不存在第二高的薪水，那么就返回 `null`。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # Drop any duplicate salary values to avoid counting duplicates as separate salary ranks
    unique_salaries = employee["salary"].drop_duplicates()

    # Sort the unique salaries in descending order and get the second highest salary
    second_highest = (
        unique_salaries.nlargest(2).iloc[-1] if len(unique_salaries) >= 2 else None
    )

    # If the second highest salary doesn't exist (e.g., there are fewer than two unique salaries), return None
    if second_highest is None:
        return pd.DataFrame({"SecondHighestSalary": [None]})

    # Create a DataFrame with the second highest salary
    result_df = pd.DataFrame({"SecondHighestSalary": [second_highest]})

    return result_df
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1, 1
    ) AS SecondHighestSalary;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：使用 MAX() 函数和子查询

我们也可以使用 `MAX()` 函数，从小于 `MAX()` 的薪水中挑选一个最大的薪水即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：使用 DISTINCT 和窗口函数

我们还可以先通过 `DENSE_RANK()` 函数计算出每个员工的薪水排名，然后再筛选出排名为 $2$ 的员工薪水即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH T AS (SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rk FROM Employee)
SELECT (SELECT DISTINCT salary FROM T WHERE rk = 2) AS SecondHighestSalary;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [177. 第N高的薪水](https://leetcode.cn/problems/nth-highest-salary){#177}

{{< tabs "177" >}}

{{% tab "python" %}}
```python
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee.salary.unique()
    if len(unique_salaries) < N:
        return pd.DataFrame([np.NaN], columns=[f"getNthHighestSalary({N})"])
    else:
        salary = sorted(unique_salaries, reverse=True)[N - 1]
        return pd.DataFrame([salary], columns=[f"getNthHighestSalary({N})"])
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
          SELECT DISTINCT salary
          FROM Employee
          ORDER BY salary DESC
          LIMIT 1 OFFSET N
      )
  );
END
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Employee</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id 是该表的主键（列中的值互不相同）。
该表的每一行都包含有关员工工资的信息。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案查询&nbsp;<code>Employee</code> 表中第 <code>n</code> 高的&nbsp;<strong>不同</strong> 工资。如果少于&nbsp;<code>n</code> 个不同工资，查询结果应该为&nbsp;<code>null</code> 。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
n = 2
<strong>输出:</strong> 
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
n = 2
<strong>输出:</strong> 
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| null                   |
+------------------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + LIMIT

我们可以先对 `salary` 进行降序排序，然后使用 `LIMIT` 语句获取第 $n$ 高的工资。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee.salary.unique()
    if len(unique_salaries) < N:
        return pd.DataFrame([np.NaN], columns=[f"getNthHighestSalary({N})"])
    else:
        salary = sorted(unique_salaries, reverse=True)[N - 1]
        return pd.DataFrame([salary], columns=[f"getNthHighestSalary({N})"])
```

#### MySQL

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
          SELECT DISTINCT salary
          FROM Employee
          ORDER BY salary DESC
          LIMIT 1 OFFSET N
      )
  );
END
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [178. 分数排名](https://leetcode.cn/problems/rank-scores){#178}

{{< tabs "178" >}}

{{% tab "sql" %}}
```sql
SELECT
    Score,
    CONVERT(rk, SIGNED) `Rank`
FROM
    (
        SELECT
            Score,
            IF(@latest = Score, @rank, @rank := @rank + 1) rk,
            @latest := Score
        FROM
            Scores,
            (
                SELECT
                    @rank := 0,
                    @latest := NULL
            ) tmp
        ORDER BY
            Score DESC
    ) s;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # Use the rank method to assign ranks to the scores in descending order with no gaps
    scores["rank"] = scores["score"].rank(method="dense", ascending=False)

    # Drop id column & Sort the DataFrame by score in descending order
    result_df = scores.drop("id", axis=1).sort_values(by="score", ascending=False)

    return result_df
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Scores</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id 是该表的主键（有不同值的列）。
该表的每一行都包含了一场比赛的分数。Score 是一个有两位小数点的浮点值。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案来查询分数的排名。排名按以下规则计算:</p>

<ul>
	<li>分数应按从高到低排列。</li>
	<li>如果两个分数相等，那么两个分数的排名应该相同。</li>
	<li>在排名相同的分数后，排名数应该是下一个连续的整数。换句话说，排名之间不应该有空缺的数字。</li>
</ul>

<p>按&nbsp;<code>score</code>&nbsp;降序返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Scores 表:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
<strong>输出:</strong> 
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用窗口函数 `DENSE_RANK()`

使用 `DENSE_RANK()` 函数，语法如下：

```sql
DENSE_RANK() OVER (
    PARTITION BY <expression>[{,<expression>...}]
    ORDER BY <expression> [ASC|DESC], [{,<expression>...}]
)
```

在这个语法中：

-   首先，`PARTITION BY` 子句将 `FROM` 子句生成的结果集划分为分区。`DENSE_RANK()`函数应用于每个分区。
-   其次，`ORDER BY` 子句指定 `DENSE_RANK()` 函数操作的每个分区中的行顺序。

与 `RANK()` 函数不同，`DENSE_RANK()` 函数始终返回连续的排名值。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # Use the rank method to assign ranks to the scores in descending order with no gaps
    scores["rank"] = scores["score"].rank(method="dense", ascending=False)

    # Drop id column & Sort the DataFrame by score in descending order
    result_df = scores.drop("id", axis=1).sort_values(by="score", ascending=False)

    return result_df
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM Scores;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：变量

MySQL 8 开始才提供了 `ROW_NUMBER()`，`RANK()`，`DENSE_RANK()` 等[窗口函数](https://dev.mysql.com/doc/refman/8.0/en/window-function-descriptions.html)，在之前的版本，可以使用变量实现类似的功能。

<!-- tabs:start -->

#### MySQL

```sql
SELECT
    Score,
    CONVERT(rk, SIGNED) `Rank`
FROM
    (
        SELECT
            Score,
            IF(@latest = Score, @rank, @rank := @rank + 1) rk,
            @latest := Score
        FROM
            Scores,
            (
                SELECT
                    @rank := 0,
                    @latest := NULL
            ) tmp
        ORDER BY
            Score DESC
    ) s;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [179. 最大数](https://leetcode.cn/problems/largest-number){#179}

{{< tabs "179" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(v) for v in nums]
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        return "0" if nums[0] == "0" else "".join(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestNumber(int[] nums) {
        List<String> vs = new ArrayList<>();
        for (int v : nums) {
            vs.add(v + "");
        }
        vs.sort((a, b) -> (b + a).compareTo(a + b));
        if ("0".equals(vs.get(0))) {
            return "0";
        }
        return String.join("", vs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for (int v : nums) vs.push_back(to_string(v));
        sort(vs.begin(), vs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        if (vs[0] == "0") return "0";
        string ans;
        for (string v : vs) ans += v;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestNumber(nums []int) string {
	vs := make([]string, len(nums))
	for i, v := range nums {
		vs[i] = strconv.Itoa(v)
	}
	sort.Slice(vs, func(i, j int) bool {
		return vs[i]+vs[j] > vs[j]+vs[i]
	})
	if vs[0] == "0" {
		return "0"
	}
	return strings.Join(vs, "")
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Comparer: IComparer<string>
{
    public int Compare(string left, string right)
    {
        return Compare(left, right, 0, 0);
    }

    private int Compare(string left, string right, int lBegin, int rBegin)
    {
        var len = Math.Min(left.Length - lBegin, right.Length - rBegin);
        for (var i = 0; i < len; ++i)
        {
            if (left[lBegin + i] != right[rBegin + i])
            {
                return left[lBegin + i] < right[rBegin + i] ? -1 : 1;
            }
        }

        if (left.Length - lBegin == right.Length - rBegin)
        {
            return 0;
        }
        if (left.Length - lBegin > right.Length - rBegin)
        {
            return Compare(left, right, lBegin + len, rBegin);
        }
        else
        {
            return Compare(left, right, lBegin, rBegin + len);
        }
    }
}

public class Solution {
    public string LargestNumber(int[] nums) {
        var sb = new StringBuilder();
        var strs = nums.Select(n => n.ToString(CultureInfo.InvariantCulture)).OrderByDescending(s => s, new Comparer());

        var nonZeroOccurred = false;
        foreach (var str in strs)
        {
            if (!nonZeroOccurred && str == "0") continue;
            sb.Append(str);
            nonZeroOccurred = true;
        }
        return sb.Length == 0 ? "0" : sb.ToString();
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestNumber(nums: number[]): string {
    nums.sort((a, b) => {
        const [ab, ba] = [String(a) + String(b), String(b) + String(a)];
        return +ba - +ab;
    });

    return nums[0] ? nums.join('') : '0';
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function largestNumber(nums) {
    nums.sort((a, b) => {
        const [ab, ba] = [String(a) + String(b), String(b) + String(a)];
        return +ba - +ab;
    });

    return nums[0] ? nums.join('') : '0';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一组非负整数 <code>nums</code>，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。</p>

<p><strong>注意：</strong>输出结果可能非常大，所以你需要返回一个字符串而不是整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [10,2]</code>
<strong>输出：</strong><code>"210"</code></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [3,30,34,5,9]</code>
<strong>输出：</strong><code>"9534330"</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

先转成字符串列表，再对字符串列表进行字典序降序排列。最后将列表所有字符串拼接即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(v) for v in nums]
        nums.sort(key=cmp_to_key(lambda a, b: 1 if a + b < b + a else -1))
        return "0" if nums[0] == "0" else "".join(nums)
```

#### Java

```java
class Solution {
    public String largestNumber(int[] nums) {
        List<String> vs = new ArrayList<>();
        for (int v : nums) {
            vs.add(v + "");
        }
        vs.sort((a, b) -> (b + a).compareTo(a + b));
        if ("0".equals(vs.get(0))) {
            return "0";
        }
        return String.join("", vs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for (int v : nums) vs.push_back(to_string(v));
        sort(vs.begin(), vs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        if (vs[0] == "0") return "0";
        string ans;
        for (string v : vs) ans += v;
        return ans;
    }
};
```

#### Go

```go
func largestNumber(nums []int) string {
	vs := make([]string, len(nums))
	for i, v := range nums {
		vs[i] = strconv.Itoa(v)
	}
	sort.Slice(vs, func(i, j int) bool {
		return vs[i]+vs[j] > vs[j]+vs[i]
	})
	if vs[0] == "0" {
		return "0"
	}
	return strings.Join(vs, "")
}
```

#### C#

```cs
using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Comparer: IComparer<string>
{
    public int Compare(string left, string right)
    {
        return Compare(left, right, 0, 0);
    }

    private int Compare(string left, string right, int lBegin, int rBegin)
    {
        var len = Math.Min(left.Length - lBegin, right.Length - rBegin);
        for (var i = 0; i < len; ++i)
        {
            if (left[lBegin + i] != right[rBegin + i])
            {
                return left[lBegin + i] < right[rBegin + i] ? -1 : 1;
            }
        }

        if (left.Length - lBegin == right.Length - rBegin)
        {
            return 0;
        }
        if (left.Length - lBegin > right.Length - rBegin)
        {
            return Compare(left, right, lBegin + len, rBegin);
        }
        else
        {
            return Compare(left, right, lBegin, rBegin + len);
        }
    }
}

public class Solution {
    public string LargestNumber(int[] nums) {
        var sb = new StringBuilder();
        var strs = nums.Select(n => n.ToString(CultureInfo.InvariantCulture)).OrderByDescending(s => s, new Comparer());

        var nonZeroOccurred = false;
        foreach (var str in strs)
        {
            if (!nonZeroOccurred && str == "0") continue;
            sb.Append(str);
            nonZeroOccurred = true;
        }
        return sb.Length == 0 ? "0" : sb.ToString();
    }
}
```

#### TypeScript

```ts
function largestNumber(nums: number[]): string {
    nums.sort((a, b) => {
        const [ab, ba] = [String(a) + String(b), String(b) + String(a)];
        return +ba - +ab;
    });

    return nums[0] ? nums.join('') : '0';
}
```

#### JavaScript

```js
function largestNumber(nums) {
    nums.sort((a, b) => {
        const [ab, ba] = [String(a) + String(b), String(b) + String(a)];
        return +ba - +ab;
    });

    return nums[0] ? nums.join('') : '0';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

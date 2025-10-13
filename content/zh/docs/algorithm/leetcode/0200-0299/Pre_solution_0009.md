---
title: "0280_摆动排序 🔒"
date: 2025-10-08T18:35:28+08:00
weight: 9
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 双指针, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数组, 树, 模拟, 深度优先搜索, 矩阵, 设计, 贪心, 迭代器, 队列]
---

{{< markmap >}}
### [0280_摆动排序 🔒](#280)
#### [贪心](#280)
#### [数组](#280)
#### [排序](#280)
### [0281_锯齿迭代器 🔒](#281)
#### [设计](#281)
#### [队列](#281)
#### [数组](#281)
#### [迭代器](#281)
### [0282_给表达式添加运算符](#282)
#### [数学](#282)
#### [字符串](#282)
#### [回溯](#282)
### [0283_移动零](#283)
#### [数组](#283)
#### [双指针](#283)
### [0284_窥视迭代器](#284)
#### [设计](#284)
#### [数组](#284)
#### [迭代器](#284)
### [0285_二叉搜索树中的中序后继 🔒](#285)
#### [树](#285)
#### [深度优先搜索](#285)
#### [二叉搜索树](#285)
#### [二叉树](#285)
### [0286_墙与门 🔒](#286)
#### [广度优先搜索](#286)
#### [数组](#286)
#### [矩阵](#286)
### [0287_寻找重复数](#287)
#### [位运算](#287)
#### [数组](#287)
#### [双指针](#287)
#### [二分查找](#287)
### [0288_单词的唯一缩写 🔒](#288)
#### [设计](#288)
#### [数组](#288)
#### [哈希表](#288)
#### [字符串](#288)
### [0289_生命游戏](#289)
#### [数组](#289)
#### [矩阵](#289)
#### [模拟](#289)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0280_摆动排序 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 0281_锯齿迭代器 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 迭代器
---
### 0282_给表达式添加运算符
___
#### 数学
___
#### 字符串
___
#### 回溯
---
### 0283_移动零
___
#### 数组
___
#### 双指针
---
### 0284_窥视迭代器
___
#### 设计
___
#### 数组
___
#### 迭代器
---
### 0285_二叉搜索树中的中序后继 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0286_墙与门 🔒
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0287_寻找重复数
___
#### 位运算
___
#### 数组
___
#### 双指针
___
#### 二分查找
---
### 0288_单词的唯一缩写 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0289_生命游戏
___
#### 数组
___
#### 矩阵
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 双指针 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 树 | 模拟 | 深度优先搜索 |
| 矩阵 | 设计 | 贪心 |
| 迭代器 | 队列 |  |

# [280. 摆动排序 🔒](https://leetcode.cn/problems/wiggle-sort){#280}

{{< tabs "280" >}}

{{% tab "python" %}}
```python
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(1, len(nums)):
            if (i % 2 == 1 and nums[i] < nums[i - 1]) or (
                i % 2 == 0 and nums[i] > nums[i - 1]
            ):
                nums[i], nums[i - 1] = nums[i - 1], nums[i]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void wiggleSort(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums, i, i - 1);
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wiggleSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		if (i%2 == 1 && nums[i] < nums[i-1]) || (i%2 == 0 && nums[i] > nums[i-1]) {
			nums[i], nums[i-1] = nums[i-1], nums[i]
		}
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个的整数数组&nbsp;<code>nums</code>, 将该数组重新排序后使&nbsp;<code>nums[0] &lt;= nums[1] &gt;= nums[2] &lt;= nums[3]...</code>&nbsp;</p>

<p>输入数组总是有一个有效的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong><code>nums = [3,5,2,1,6,4]</code>
<strong>输出：</strong>[3,5,1,6,2,4]
<strong>解释：</strong>[1,6,2,5,3,4]也是有效的答案</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>nums = [6,6,5,6,3,8]
<b>输出：</b>[6,6,5,6,3,8]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>
	<p>输入的&nbsp;<code>nums</code> 保证至少有一个答案。</p>
	</li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你能在&nbsp;<code>O(n)</code>&nbsp;时间复杂度下解决这个问题吗？</p>

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
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(1, len(nums)):
            if (i % 2 == 1 and nums[i] < nums[i - 1]) or (
                i % 2 == 0 and nums[i] > nums[i - 1]
            ):
                nums[i], nums[i - 1] = nums[i - 1], nums[i]
```

#### Java

```java
class Solution {
    public void wiggleSort(int[] nums) {
        for (int i = 1; i < nums.length; ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums, i, i - 1);
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
```

#### Go

```go
func wiggleSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		if (i%2 == 1 && nums[i] < nums[i-1]) || (i%2 == 0 && nums[i] > nums[i-1]) {
			nums[i], nums[i-1] = nums[i-1], nums[i]
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [281. 锯齿迭代器 🔒](https://leetcode.cn/problems/zigzag-iterator){#281}

{{< tabs "281" >}}

{{% tab "python" %}}
```python
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.cur = 0
        self.size = 2
        self.indexes = [0] * self.size
        self.vectors = [v1, v2]

    def next(self) -> int:
        vector = self.vectors[self.cur]
        index = self.indexes[self.cur]
        res = vector[index]
        self.indexes[self.cur] = index + 1
        self.cur = (self.cur + 1) % self.size
        return res

    def hasNext(self) -> bool:
        start = self.cur
        while self.indexes[self.cur] == len(self.vectors[self.cur]):
            self.cur = (self.cur + 1) % self.size
            if self.cur == start:
                return False
        return True


# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class ZigzagIterator {
    private int cur;
    private int size;
    private List<Integer> indexes = new ArrayList<>();
    private List<List<Integer>> vectors = new ArrayList<>();

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        cur = 0;
        size = 2;
        indexes.add(0);
        indexes.add(0);
        vectors.add(v1);
        vectors.add(v2);
    }

    public int next() {
        List<Integer> vector = vectors.get(cur);
        int index = indexes.get(cur);
        int res = vector.get(index);
        indexes.set(cur, index + 1);
        cur = (cur + 1) % size;
        return res;
    }

    public boolean hasNext() {
        int start = cur;
        while (indexes.get(cur) == vectors.get(cur).size()) {
            cur = (cur + 1) % size;
            if (start == cur) {
                return false;
            }
        }
        return true;
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type ZigzagIterator struct {
	cur     int
	size    int
	indexes []int
	vectors [][]int
}

func Constructor(v1, v2 []int) *ZigzagIterator {
	return &ZigzagIterator{
		cur:     0,
		size:    2,
		indexes: []int{0, 0},
		vectors: [][]int{v1, v2},
	}
}

func (this *ZigzagIterator) next() int {
	vector := this.vectors[this.cur]
	index := this.indexes[this.cur]
	res := vector[index]
	this.indexes[this.cur]++
	this.cur = (this.cur + 1) % this.size
	return res
}

func (this *ZigzagIterator) hasNext() bool {
	start := this.cur
	for this.indexes[this.cur] == len(this.vectors[this.cur]) {
		this.cur = (this.cur + 1) % this.size
		if start == this.cur {
			return false
		}
	}
	return true
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * obj := Constructor(param_1, param_2);
 * for obj.hasNext() {
 *	 ans = append(ans, obj.next())
 * }
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct ZigzagIterator {
    v1: Vec<i32>,
    v2: Vec<i32>,
    /// `false` represents `v1`, `true` represents `v2`
    flag: bool,
}

impl ZigzagIterator {
    fn new(v1: Vec<i32>, v2: Vec<i32>) -> Self {
        Self {
            v1,
            v2,
            // Initially beginning with `v1`
            flag: false,
        }
    }

    fn next(&mut self) -> i32 {
        if !self.flag {
            // v1
            if self.v1.is_empty() && !self.v2.is_empty() {
                self.flag = true;
                let ret = self.v2.remove(0);
                return ret;
            }
            if self.v2.is_empty() {
                let ret = self.v1.remove(0);
                return ret;
            }
            let ret = self.v1.remove(0);
            self.flag = true;
            return ret;
        } else {
            // v2
            if self.v2.is_empty() && !self.v1.is_empty() {
                self.flag = false;
                let ret = self.v1.remove(0);
                return ret;
            }
            if self.v1.is_empty() {
                let ret = self.v2.remove(0);
                return ret;
            }
            let ret = self.v2.remove(0);
            self.flag = false;
            return ret;
        }
    }

    fn has_next(&self) -> bool {
        !self.v1.is_empty() || !self.v2.is_empty()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出两个整数向量&nbsp;<code>v1</code>&nbsp;和&nbsp;<code>v2</code>，请你实现一个迭代器，交替返回它们的元素。</p>

<p>实现&nbsp;<code>ZigzagIterator</code>&nbsp;类：</p>

<ul>
	<li><code>ZigzagIterator(List&lt;int&gt; v1, List&lt;int&gt; v2)</code>&nbsp;用两个向量&nbsp;<code>v1</code>&nbsp;和&nbsp;<code>v2</code>&nbsp;初始化对象。</li>
	<li><code>boolean hasNext()</code>&nbsp;如果迭代器还有元素返回&nbsp;<code>true</code>，否则返回 <code>false</code>。</li>
	<li><code>int next()</code>&nbsp;返回迭代器的当前元素并将迭代器移动到下一个元素。</li>
</ul>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入：</strong>v1 = [1,2], v2 = [3,4,5,6]
<strong>输出：</strong>[1,3,2,4,5,6]
<strong>解释：</strong>通过重复调用 next 直到 hasNext 返回 false，那么 next 返回的元素的顺序应该是：[1,3,2,4,5,6]。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入：</strong>v1 = [1], v2 = []
<strong>输出：</strong>[1]
</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入：</strong>v1 = [], v2 = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>拓展：</strong>假如给你&nbsp;<code>k</code>&nbsp;个向量呢？你的代码在这种情况下的扩展性又会如何呢?</p>

<p><strong>拓展声明：</strong><br />
&nbsp;“锯齿” 顺序对于&nbsp;<code>k &gt; 2</code>&nbsp;的情况定义可能会有些歧义。所以，假如你觉得 “锯齿” 这个表述不妥，也可以认为这是一种&nbsp;“循环”。例如：</p>

<pre>
<strong>输入：</strong>v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
<strong>输出：</strong>[1,4,8,2,5,9,3,6,7]
</pre>

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
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.cur = 0
        self.size = 2
        self.indexes = [0] * self.size
        self.vectors = [v1, v2]

    def next(self) -> int:
        vector = self.vectors[self.cur]
        index = self.indexes[self.cur]
        res = vector[index]
        self.indexes[self.cur] = index + 1
        self.cur = (self.cur + 1) % self.size
        return res

    def hasNext(self) -> bool:
        start = self.cur
        while self.indexes[self.cur] == len(self.vectors[self.cur]):
            self.cur = (self.cur + 1) % self.size
            if self.cur == start:
                return False
        return True


# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
```

#### Java

```java
public class ZigzagIterator {
    private int cur;
    private int size;
    private List<Integer> indexes = new ArrayList<>();
    private List<List<Integer>> vectors = new ArrayList<>();

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        cur = 0;
        size = 2;
        indexes.add(0);
        indexes.add(0);
        vectors.add(v1);
        vectors.add(v2);
    }

    public int next() {
        List<Integer> vector = vectors.get(cur);
        int index = indexes.get(cur);
        int res = vector.get(index);
        indexes.set(cur, index + 1);
        cur = (cur + 1) % size;
        return res;
    }

    public boolean hasNext() {
        int start = cur;
        while (indexes.get(cur) == vectors.get(cur).size()) {
            cur = (cur + 1) % size;
            if (start == cur) {
                return false;
            }
        }
        return true;
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
```

#### Go

```go
type ZigzagIterator struct {
	cur     int
	size    int
	indexes []int
	vectors [][]int
}

func Constructor(v1, v2 []int) *ZigzagIterator {
	return &ZigzagIterator{
		cur:     0,
		size:    2,
		indexes: []int{0, 0},
		vectors: [][]int{v1, v2},
	}
}

func (this *ZigzagIterator) next() int {
	vector := this.vectors[this.cur]
	index := this.indexes[this.cur]
	res := vector[index]
	this.indexes[this.cur]++
	this.cur = (this.cur + 1) % this.size
	return res
}

func (this *ZigzagIterator) hasNext() bool {
	start := this.cur
	for this.indexes[this.cur] == len(this.vectors[this.cur]) {
		this.cur = (this.cur + 1) % this.size
		if start == this.cur {
			return false
		}
	}
	return true
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * obj := Constructor(param_1, param_2);
 * for obj.hasNext() {
 *	 ans = append(ans, obj.next())
 * }
 */
```

#### Rust

```rust
struct ZigzagIterator {
    v1: Vec<i32>,
    v2: Vec<i32>,
    /// `false` represents `v1`, `true` represents `v2`
    flag: bool,
}

impl ZigzagIterator {
    fn new(v1: Vec<i32>, v2: Vec<i32>) -> Self {
        Self {
            v1,
            v2,
            // Initially beginning with `v1`
            flag: false,
        }
    }

    fn next(&mut self) -> i32 {
        if !self.flag {
            // v1
            if self.v1.is_empty() && !self.v2.is_empty() {
                self.flag = true;
                let ret = self.v2.remove(0);
                return ret;
            }
            if self.v2.is_empty() {
                let ret = self.v1.remove(0);
                return ret;
            }
            let ret = self.v1.remove(0);
            self.flag = true;
            return ret;
        } else {
            // v2
            if self.v2.is_empty() && !self.v1.is_empty() {
                self.flag = false;
                let ret = self.v1.remove(0);
                return ret;
            }
            if self.v1.is_empty() {
                let ret = self.v2.remove(0);
                return ret;
            }
            let ret = self.v2.remove(0);
            self.flag = false;
            return ret;
        }
    }

    fn has_next(&self) -> bool {
        !self.v1.is_empty() || !self.v2.is_empty()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [282. 给表达式添加运算符](https://leetcode.cn/problems/expression-add-operators){#282}

{{< tabs "282" >}}

{{% tab "python" %}}
```python
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        ans = []

        def dfs(u, prev, curr, path):
            if u == len(num):
                if curr == target:
                    ans.append(path)
                return
            for i in range(u, len(num)):
                if i != u and num[u] == '0':
                    break
                next = int(num[u : i + 1])
                if u == 0:
                    dfs(i + 1, next, next, path + str(next))
                else:
                    dfs(i + 1, next, curr + next, path + "+" + str(next))
                    dfs(i + 1, -next, curr - next, path + "-" + str(next))
                    dfs(
                        i + 1,
                        prev * next,
                        curr - prev + prev * next,
                        path + "*" + str(next),
                    )

        dfs(0, 0, 0, "")
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> ans;
    private String num;
    private int target;

    public List<String> addOperators(String num, int target) {
        ans = new ArrayList<>();
        this.num = num;
        this.target = target;
        dfs(0, 0, 0, "");
        return ans;
    }

    private void dfs(int u, long prev, long curr, String path) {
        if (u == num.length()) {
            if (curr == target) ans.add(path);
            return;
        }
        for (int i = u; i < num.length(); i++) {
            if (i != u && num.charAt(u) == '0') {
                break;
            }
            long next = Long.parseLong(num.substring(u, i + 1));
            if (u == 0) {
                dfs(i + 1, next, next, path + next);
            } else {
                dfs(i + 1, next, curr + next, path + "+" + next);
                dfs(i + 1, -next, curr - next, path + "-" + next);
                dfs(i + 1, prev * next, curr - prev + prev * next, path + "*" + next);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System;
using System.Collections.Generic;

public class Expression
{
    public long Value;

    public override string ToString()
    {
        return Value.ToString();
    }
}

public class BinaryExpression : Expression
{
    public char Operator;

    public Expression LeftChild;
    public Expression RightChild;

    public override string ToString()
    {
        return string.Format("{0}{1}{2}", LeftChild, Operator, RightChild);
    }
}

public class Solution {
    public IList<string> AddOperators(string num, int target) {
        var results = new List<string>();
        if (string.IsNullOrEmpty(num)) return results;
        this.num = num;
        this.results = new List<Expression>[num.Length, num.Length, 3];
        foreach (var ex in Search(0, num.Length - 1, 0))
        {
            if (ex.Value == target)
            {
                results.Add(ex.ToString());
            }
        }
        return results;
    }

    private string num;
    private List<Expression>[,,] results;

    private List<Expression> Search(int left, int right, int level)
    {
        if (results[left, right, level] != null)
        {
            return results[left, right, level];
        }
        var result = new List<Expression>();
        if (level < 2)
        {
            for (var i = left + 1; i <= right; ++i)
            {
                List<Expression> leftResult, rightResult;
                leftResult = Search(left, i - 1, level);
                rightResult = Search(i, right, level + 1);
                foreach (var l in leftResult)
                {
                    foreach (var r in rightResult)
                    {
                        var newObjects = new List<Tuple<char, long>>();
                        if (level == 0)
                        {
                            newObjects.Add(Tuple.Create('+', l.Value + r.Value));
                            newObjects.Add(Tuple.Create('-', l.Value - r.Value));
                        }
                        else
                        {
                            newObjects.Add(Tuple.Create('*', l.Value * r.Value));
                        }
                        foreach (var newObject in newObjects)
                        {
                            result.Add(new BinaryExpression
                            {
                                Value = newObject.Item2,
                                Operator = newObject.Item1,
                                LeftChild = l,
                                RightChild = r
                            });
                        }
                    }
                }
            }
        }
        else
        {
            if (left == right || num[left] != '0')
            {
                long x = 0;
                for (var i = left; i <= right; ++i)
                {
                    x = x * 10 + num[i] - '0';
                }
                result.Add(new Expression
                {
                    Value = x
                });
            }
        }
        if (level < 2)
        {
            result.AddRange(Search(left, right, level + 1));
        }
        return results[left, right, level] = result;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个仅包含数字&nbsp;<code>0-9</code>&nbsp;的字符串 <code>num</code> 和一个目标值整数 <code>target</code> ，在 <code>num</code> 的数字之间添加 <strong>二元 </strong>运算符（不是一元）<code>+</code>、<code>-</code>&nbsp;或&nbsp;<code>*</code>&nbsp;，返回 <strong>所有</strong> 能够得到 <code>target</code>&nbsp;的表达式。</p>

<p>注意，返回表达式中的操作数 <strong>不应该</strong> 包含前导零。</p>

<p><strong>注意</strong>，一个数字可以包含多个数位。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>num = </code>"123", target = 6
<strong>输出: </strong>["1+2+3", "1*2*3"] 
<strong>解释: </strong>“1*2*3” 和 “1+2+3” 的值都是6。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> <code>num = </code>"232", target = 8
<strong>输出: </strong>["2*3+2", "2+3*2"]
<strong>解释:</strong> “2*3+2” 和 “2+3*2” 的值都是8。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> <code>num = </code>"3456237490", target = 9191
<strong>输出: </strong>[]
<strong>解释: </strong>表达式 “3456237490” 无法得到 9191 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10</code></li>
	<li><code>num</code> 仅含数字</li>
	<li><code>-2<sup>31</sup> &lt;= target &lt;= 2<sup>31</sup> - 1</code></li>
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
    def addOperators(self, num: str, target: int) -> List[str]:
        ans = []

        def dfs(u, prev, curr, path):
            if u == len(num):
                if curr == target:
                    ans.append(path)
                return
            for i in range(u, len(num)):
                if i != u and num[u] == '0':
                    break
                next = int(num[u : i + 1])
                if u == 0:
                    dfs(i + 1, next, next, path + str(next))
                else:
                    dfs(i + 1, next, curr + next, path + "+" + str(next))
                    dfs(i + 1, -next, curr - next, path + "-" + str(next))
                    dfs(
                        i + 1,
                        prev * next,
                        curr - prev + prev * next,
                        path + "*" + str(next),
                    )

        dfs(0, 0, 0, "")
        return ans
```

#### Java

```java
class Solution {
    private List<String> ans;
    private String num;
    private int target;

    public List<String> addOperators(String num, int target) {
        ans = new ArrayList<>();
        this.num = num;
        this.target = target;
        dfs(0, 0, 0, "");
        return ans;
    }

    private void dfs(int u, long prev, long curr, String path) {
        if (u == num.length()) {
            if (curr == target) ans.add(path);
            return;
        }
        for (int i = u; i < num.length(); i++) {
            if (i != u && num.charAt(u) == '0') {
                break;
            }
            long next = Long.parseLong(num.substring(u, i + 1));
            if (u == 0) {
                dfs(i + 1, next, next, path + next);
            } else {
                dfs(i + 1, next, curr + next, path + "+" + next);
                dfs(i + 1, -next, curr - next, path + "-" + next);
                dfs(i + 1, prev * next, curr - prev + prev * next, path + "*" + next);
            }
        }
    }
}
```

#### C#

```cs
using System;
using System.Collections.Generic;

public class Expression
{
    public long Value;

    public override string ToString()
    {
        return Value.ToString();
    }
}

public class BinaryExpression : Expression
{
    public char Operator;

    public Expression LeftChild;
    public Expression RightChild;

    public override string ToString()
    {
        return string.Format("{0}{1}{2}", LeftChild, Operator, RightChild);
    }
}

public class Solution {
    public IList<string> AddOperators(string num, int target) {
        var results = new List<string>();
        if (string.IsNullOrEmpty(num)) return results;
        this.num = num;
        this.results = new List<Expression>[num.Length, num.Length, 3];
        foreach (var ex in Search(0, num.Length - 1, 0))
        {
            if (ex.Value == target)
            {
                results.Add(ex.ToString());
            }
        }
        return results;
    }

    private string num;
    private List<Expression>[,,] results;

    private List<Expression> Search(int left, int right, int level)
    {
        if (results[left, right, level] != null)
        {
            return results[left, right, level];
        }
        var result = new List<Expression>();
        if (level < 2)
        {
            for (var i = left + 1; i <= right; ++i)
            {
                List<Expression> leftResult, rightResult;
                leftResult = Search(left, i - 1, level);
                rightResult = Search(i, right, level + 1);
                foreach (var l in leftResult)
                {
                    foreach (var r in rightResult)
                    {
                        var newObjects = new List<Tuple<char, long>>();
                        if (level == 0)
                        {
                            newObjects.Add(Tuple.Create('+', l.Value + r.Value));
                            newObjects.Add(Tuple.Create('-', l.Value - r.Value));
                        }
                        else
                        {
                            newObjects.Add(Tuple.Create('*', l.Value * r.Value));
                        }
                        foreach (var newObject in newObjects)
                        {
                            result.Add(new BinaryExpression
                            {
                                Value = newObject.Item2,
                                Operator = newObject.Item1,
                                LeftChild = l,
                                RightChild = r
                            });
                        }
                    }
                }
            }
        }
        else
        {
            if (left == right || num[left] != '0')
            {
                long x = 0;
                for (var i = left; i <= right; ++i)
                {
                    x = x * 10 + num[i] - '0';
                }
                result.Add(new Expression
                {
                    Value = x
                });
            }
        }
        if (level < 2)
        {
            result.AddRange(Search(left, right, level + 1));
        }
        return results[left, right, level] = result;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [283. 移动零](https://leetcode.cn/problems/move-zeroes){#283}

{{< tabs "283" >}}

{{% tab "python" %}}
```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        k = 0
        for i, x in enumerate(nums):
            if x:
                nums[k], nums[i] = nums[i], nums[k]
                k += 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int k = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                int t = nums[i];
                nums[i] = nums[k];
                nums[k++] = t;
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
    void moveZeroes(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func moveZeroes(nums []int) {
	k := 0
	for i, x := range nums {
		if x != 0 {
			nums[i], nums[k] = nums[k], nums[i]
			k++
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i]) {
            [nums[i], nums[k]] = [nums[k], nums[i]];
            ++k;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut k = 0;
        let n = nums.len();
        for i in 0..n {
            if nums[i] != 0 {
                nums.swap(i, k);
                k += 1;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i]) {
            [nums[i], nums[k]] = [nums[k], nums[i]];
            ++k;
        }
    }
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            int t = nums[i];
            nums[i] = nums[k];
            nums[k++] = t;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组 <code>nums</code>，编写一个函数将所有 <code>0</code> 移动到数组的末尾，同时保持非零元素的相对顺序。</p>

<p><strong>请注意</strong>&nbsp;，必须在不复制数组的情况下原地对数组进行操作。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0,1,0,3,12]</code>
<strong>输出:</strong> <code>[1,3,12,0,0]</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0]</code>
<strong>输出:</strong> <code>[0]</code></pre>

<p>&nbsp;</p>

<p><strong>提示</strong>:</p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= nums[i] &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你能尽量减少完成的操作次数吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用一个指针 $k$ 记录当前待插入的位置，初始时 $k = 0$。

然后我们遍历数组 $\textit{nums}$，每次遇到一个非零数，就将其与 $\textit{nums}[k]$ 交换，同时将 $k$ 的值加 $1$。

这样我们就可以保证 $\textit{nums}$ 的前 $k$ 个元素都是非零的，且它们的相对顺序与原数组一致。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        k = 0
        for i, x in enumerate(nums):
            if x:
                nums[k], nums[i] = nums[i], nums[k]
                k += 1
```

#### Java

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int k = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                int t = nums[i];
                nums[i] = nums[k];
                nums[k++] = t;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};
```

#### Go

```go
func moveZeroes(nums []int) {
	k := 0
	for i, x := range nums {
		if x != 0 {
			nums[i], nums[k] = nums[k], nums[i]
			k++
		}
	}
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i]) {
            [nums[i], nums[k]] = [nums[k], nums[i]];
            ++k;
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut k = 0;
        let n = nums.len();
        for i in 0..n {
            if nums[i] != 0 {
                nums.swap(i, k);
                k += 1;
            }
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i]) {
            [nums[i], nums[k]] = [nums[k], nums[i]];
            ++k;
        }
    }
};
```

#### C

```c
void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            int t = nums[i];
            nums[i] = nums[k];
            nums[k++] = t;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [284. 窥视迭代器](https://leetcode.cn/problems/peeking-iterator){#284}

{{< tabs "284" >}}

{{% tab "python" %}}
```python
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.has_peeked = False
        self.peeked_element = None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.has_peeked:
            self.peeked_element = self.iterator.next()
            self.has_peeked = True
        return self.peeked_element

    def next(self):
        """
        :rtype: int
        """
        if not self.has_peeked:
            return self.iterator.next()
        result = self.peeked_element
        self.has_peeked = False
        self.peeked_element = None
        return result

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.has_peeked or self.iterator.hasNext()


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
```
{{% /tab %}}
{{% tab "java" %}}
```java
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iterator;
    private boolean hasPeeked;
    private Integer peekedElement;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        this.iterator = iterator;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        if (!hasPeeked) {
            peekedElement = iterator.next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        if (!hasPeeked) {
            return iterator.next();
        }
        Integer result = peekedElement;
        hasPeeked = false;
        peekedElement = null;
        return result;
    }

    @Override
    public boolean hasNext() {
        return hasPeeked || iterator.hasNext();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums)
        : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasPeeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!hasPeeked) return Iterator::next();
        hasPeeked = false;
        return peekedElement;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }

private:
    bool hasPeeked;
    int peekedElement;
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
	iter          *Iterator
	hasPeeked     bool
	peekedElement int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{iter, iter.hasNext(), iter.next()}
}

func (this *PeekingIterator) hasNext() bool {
	return this.hasPeeked || this.iter.hasNext()
}

func (this *PeekingIterator) next() int {
	if !this.hasPeeked {
		return this.iter.next()
	}
	this.hasPeeked = false
	return this.peekedElement
}

func (this *PeekingIterator) peek() int {
	if !this.hasPeeked {
		this.peekedElement = this.iter.next()
		this.hasPeeked = true
	}
	return this.peekedElement
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你在设计一个迭代器，在集成现有迭代器拥有的&nbsp;<code>hasNext</code> 和 <code>next</code> 操作的基础上，还额外支持 <code>peek</code> 操作。</p>

<p>实现 <code>PeekingIterator</code> 类：</p>

<ul>
	<li><code>PeekingIterator(Iterator&lt;int&gt; nums)</code> 使用指定整数迭代器&nbsp;<code>nums</code> 初始化迭代器。</li>
	<li><code>int next()</code> 返回数组中的下一个元素，并将指针移动到下个元素处。</li>
	<li><code>bool hasNext()</code> 如果数组中存在下一个元素，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>int peek()</code> 返回数组中的下一个元素，但 <strong>不</strong> 移动指针。</li>
</ul>

<p><strong>注意：</strong>每种语言可能有不同的构造函数和迭代器&nbsp;<code>Iterator</code>，但均支持 <code>int next()</code> 和 <code>boolean hasNext()</code> 函数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
<strong>输出：</strong>
[null, 1, 2, 2, 3, false]

<strong>解释：</strong>
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [<u><strong>1</strong></u>,2,3]
peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,<u><strong>2</strong></u>,3]
peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,<u><strong>2</strong></u>,3]
peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,<u><strong>3</strong></u>]
peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
peekingIterator.hasNext(); // 返回 False
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>对 <code>next</code> 和 <code>peek</code> 的调用均有效</li>
	<li><code>next</code>、<code>hasNext</code> 和 <code>peek </code>最多调用&nbsp; <code>1000</code> 次</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？</p>

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
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.has_peeked = False
        self.peeked_element = None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.has_peeked:
            self.peeked_element = self.iterator.next()
            self.has_peeked = True
        return self.peeked_element

    def next(self):
        """
        :rtype: int
        """
        if not self.has_peeked:
            return self.iterator.next()
        result = self.peeked_element
        self.has_peeked = False
        self.peeked_element = None
        return result

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.has_peeked or self.iterator.hasNext()


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
```

#### Java

```java
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iterator;
    private boolean hasPeeked;
    private Integer peekedElement;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        this.iterator = iterator;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        if (!hasPeeked) {
            peekedElement = iterator.next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        if (!hasPeeked) {
            return iterator.next();
        }
        Integer result = peekedElement;
        hasPeeked = false;
        peekedElement = null;
        return result;
    }

    @Override
    public boolean hasNext() {
        return hasPeeked || iterator.hasNext();
    }
}
```

#### C++

```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums)
        : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasPeeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!hasPeeked) return Iterator::next();
        hasPeeked = false;
        return peekedElement;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }

private:
    bool hasPeeked;
    int peekedElement;
};
```

#### Go

```go
/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
	iter          *Iterator
	hasPeeked     bool
	peekedElement int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{iter, iter.hasNext(), iter.next()}
}

func (this *PeekingIterator) hasNext() bool {
	return this.hasPeeked || this.iter.hasNext()
}

func (this *PeekingIterator) next() int {
	if !this.hasPeeked {
		return this.iter.next()
	}
	this.hasPeeked = false
	return this.peekedElement
}

func (this *PeekingIterator) peek() int {
	if !this.hasPeeked {
		this.peekedElement = this.iter.next()
		this.hasPeeked = true
	}
	return this.peekedElement
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [285. 二叉搜索树中的中序后继 🔒](https://leetcode.cn/problems/inorder-successor-in-bst){#285}

{{< tabs "285" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        ans = None
        while root:
            if root.val > p.val:
                ans = root
                root = root.left
            else:
                root = root.right
        return ans
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode ans = null;
        while (root != null) {
            if (root.val > p.val) {
                ans = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return ans;
    }
}
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root) {
            if (root->val > p->val) {
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
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
func inorderSuccessor(root *TreeNode, p *TreeNode) (ans *TreeNode) {
	for root != nil {
		if root.Val > p.Val {
			ans = root
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return
}
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

function inorderSuccessor(root: TreeNode | null, p: TreeNode | null): TreeNode | null {
    let ans: TreeNode | null = null;
    while (root) {
        if (root.val > p.val) {
            ans = root;
            root = root.left;
        } else {
            root = root.right;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @return {TreeNode}
 */
var inorderSuccessor = function (root, p) {
    let ans = null;
    while (root) {
        if (root.val > p.val) {
            ans = root;
            root = root.left;
        } else {
            root = root.right;
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉搜索树和其中的一个节点 <code>p</code> ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 <code>null</code> 。</p>

<p>节点 <code>p</code> 的后继是值比 <code>p.val</code> 大的节点中键值最小的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0285.Inorder%20Successor%20in%20BST/images/285_example_1.png" style="height: 117px; width: 122px;" /></p>

<pre>
<strong>输入：</strong>root = [2,1,3], p = 1
<strong>输出：</strong>2
<strong>解释：</strong>这里 1 的中序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0285.Inorder%20Successor%20in%20BST/images/285_example_2.png" style="height: 229px; width: 246px;" /></p>

<pre>
<strong>输入：</strong>root = [5,3,6,2,4,null,null,1], p = 6
<strong>输出：</strong>null
<strong>解释：</strong>因为给出的节点没有中序后继，所以答案就返回 <code>null 了。</code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>4</sup>]</code> 内。</li>
	<li><code>-10<sup>5</sup> <= Node.val <= 10<sup>5</sup></code></li>
	<li>树中各节点的值均保证唯一。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分搜索

二叉搜索树的中序遍历是一个升序序列，因此可以使用二分搜索的方法。

二叉搜索树节点 $p$ 的中序后继节点满足：

1. 中序后继的节点值大于 $p$ 的节点值
2. 中序后继是所有大于 $p$ 的节点中值最小的节点

因此，对于当前节点 $root$，如果 $root.val \gt p.val$，则 $root$ 可能是 $p$ 的中序后继节点，将 $root$ 记为 $ans$，然后搜索左子树，即 $root = root.left$；如果 $root.val \leq p.val$，则 $root$ 不能是 $p$ 的中序后继节点，搜索右子树，即 $root = root.right$。

时间复杂度 $O(h)$，其中 $h$ 为二叉搜索树的高度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        ans = None
        while root:
            if root.val > p.val:
                ans = root
                root = root.left
            else:
                root = root.right
        return ans
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode ans = null;
        while (root != null) {
            if (root.val > p.val) {
                ans = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root) {
            if (root->val > p->val) {
                ans = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
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
func inorderSuccessor(root *TreeNode, p *TreeNode) (ans *TreeNode) {
	for root != nil {
		if root.Val > p.Val {
			ans = root
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return
}
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

function inorderSuccessor(root: TreeNode | null, p: TreeNode | null): TreeNode | null {
    let ans: TreeNode | null = null;
    while (root) {
        if (root.val > p.val) {
            ans = root;
            root = root.left;
        } else {
            root = root.right;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @return {TreeNode}
 */
var inorderSuccessor = function (root, p) {
    let ans = null;
    while (root) {
        if (root.val > p.val) {
            ans = root;
            root = root.left;
        } else {
            root = root.right;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [286. 墙与门 🔒](https://leetcode.cn/problems/walls-and-gates){#286}

{{< tabs "286" >}}

{{% tab "python" %}}
```python
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        inf = 2**31 - 1
        q = deque([(i, j) for i in range(m) for j in range(n) if rooms[i][j] == 0])
        d = 0
        while q:
            d += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and rooms[x][y] == inf:
                        rooms[x][y] = d
                        q.append((x, y))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;
        int n = rooms[0].length;
        Deque<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int d = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            ++d;
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j];
                    int y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == Integer.MAX_VALUE) {
                        rooms[x][y] = d;
                        q.offer(new int[] {x, y});
                    }
                }
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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0)
                    q.emplace(i, j);
        int d = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            ++d;
            for (int i = q.size(); i > 0; --i) {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dirs[j];
                    int y = p.second + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == INT_MAX) {
                        rooms[x][y] = d;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wallsAndGates(rooms [][]int) {
	m, n := len(rooms), len(rooms[0])
	var q [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if rooms[i][j] == 0 {
				q = append(q, []int{i, j})
			}
		}
	}
	d := 0
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		d++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for j := 0; j < 4; j++ {
				x, y := p[0]+dirs[j], p[1]+dirs[j+1]
				if x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == math.MaxInt32 {
					rooms[x][y] = d
					q = append(q, []int{x, y})
				}
			}
		}
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你被给定一个 <code>m × n</code> 的二维网格 <code>rooms</code> ，网格中有以下三种可能的初始化值：</p>

<ol>
	<li><code>-1</code> 表示墙或是障碍物</li>
	<li><code>0</code> 表示一扇门</li>
	<li><code>INF</code> 无限表示一个空的房间。然后，我们用 <code>2<sup>31</sup> - 1 = 2147483647</code> 代表 <code>INF</code>。你可以认为通往门的距离总是小于 <code>2147483647</code> 的。</li>
</ol>

<p>你要给每个空房间位上填上该房间到 <strong>最近门的距离</strong> ，如果无法到达门，则填 <code>INF</code> 即可。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0286.Walls%20and%20Gates/images/grid.jpg" style="width: 500px; height: 223px;" />
<pre>
<strong>输入：</strong>rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
<strong>输出：</strong>[[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rooms = [[-1]]
<strong>输出：</strong>[[-1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rooms = [[2147483647]]
<strong>输出：</strong>[[2147483647]]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rooms = [[0]]
<strong>输出：</strong>[[0]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == rooms.length</code></li>
	<li><code>n == rooms[i].length</code></li>
	<li><code>1 <= m, n <= 250</code></li>
	<li><code>rooms[i][j]</code> 是 <code>-1</code>、<code>0</code> 或 <code>2<sup>31</sup> - 1</code></li>
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
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        inf = 2**31 - 1
        q = deque([(i, j) for i in range(m) for j in range(n) if rooms[i][j] == 0])
        d = 0
        while q:
            d += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and rooms[x][y] == inf:
                        rooms[x][y] = d
                        q.append((x, y))
```

#### Java

```java
class Solution {
    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;
        int n = rooms[0].length;
        Deque<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int d = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            ++d;
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j];
                    int y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == Integer.MAX_VALUE) {
                        rooms[x][y] = d;
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0)
                    q.emplace(i, j);
        int d = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            ++d;
            for (int i = q.size(); i > 0; --i) {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p.first + dirs[j];
                    int y = p.second + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == INT_MAX) {
                        rooms[x][y] = d;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func wallsAndGates(rooms [][]int) {
	m, n := len(rooms), len(rooms[0])
	var q [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if rooms[i][j] == 0 {
				q = append(q, []int{i, j})
			}
		}
	}
	d := 0
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		d++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for j := 0; j < 4; j++ {
				x, y := p[0]+dirs[j], p[1]+dirs[j+1]
				if x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] == math.MaxInt32 {
					rooms[x][y] = d
					q = append(q, []int{x, y})
				}
			}
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number){#287}

{{< tabs "287" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        def f(x: int) -> bool:
            return sum(v <= x for v in nums) > x

        return bisect_left(range(len(nums)), True, key=f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int v : nums) {
                if (v <= mid) {
                    ++cnt;
                }
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& v : nums) {
                cnt += v <= mid;
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDuplicate(nums []int) int {
	return sort.Search(len(nums), func(x int) bool {
		cnt := 0
		for _, v := range nums {
			if v <= x {
				cnt++
			}
		}
		return cnt > x
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDuplicate(nums: number[]): number {
    let l = 0;
    let r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const v of nums) {
            if (v <= mid) {
                ++cnt;
            }
        }
        if (cnt > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left < right {
            let mid = (left + right) >> 1;
            let cnt = nums.iter().filter(|x| **x <= (mid as i32)).count();
            if cnt > mid {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function (nums) {
    let l = 0;
    let r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const v of nums) {
            if (v <= mid) {
                ++cnt;
            }
        }
        if (cnt > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含&nbsp;<code>n + 1</code> 个整数的数组&nbsp;<code>nums</code> ，其数字都在&nbsp;<code>[1, n]</code>&nbsp;范围内（包括 <code>1</code> 和 <code>n</code>），可知至少存在一个重复的整数。</p>

<p>假设 <code>nums</code> 只有 <strong>一个重复的整数</strong> ，返回&nbsp;<strong>这个重复的数</strong> 。</p>

<p>你设计的解决方案必须 <strong>不修改</strong> 数组 <code>nums</code> 且只用常量级 <code>O(1)</code> 的额外空间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,4,2,2]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,3,4,2]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3 :</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3,3,3,3]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n + 1</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 中 <strong>只有一个整数</strong> 出现 <strong>两次或多次</strong> ，其余整数均只出现 <strong>一次</strong></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b></p>

<ul>
	<li>如何证明 <code>nums</code> 中至少存在一个重复的数字?</li>
	<li>你可以设计一个线性级时间复杂度 <code>O(n)</code> 的解决方案吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以发现，如果 $[1,..x]$ 中的数字个数大于 $x$，那么重复的数字一定在 $[1,..x]$ 中，否则重复的数字一定在 $[x+1,..n]$ 中。

因此，我们可以二分枚举 $x$，每次判断 $[1,..x]$ 中的数字个数是否大于 $x$，从而确定重复的数字在哪个区间中，进而缩小区间范围，直到找到重复的数字。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        def f(x: int) -> bool:
            return sum(v <= x for v in nums) > x

        return bisect_left(range(len(nums)), True, key=f)
```

#### Java

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int v : nums) {
                if (v <= mid) {
                    ++cnt;
                }
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& v : nums) {
                cnt += v <= mid;
            }
            if (cnt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func findDuplicate(nums []int) int {
	return sort.Search(len(nums), func(x int) bool {
		cnt := 0
		for _, v := range nums {
			if v <= x {
				cnt++
			}
		}
		return cnt > x
	})
}
```

#### TypeScript

```ts
function findDuplicate(nums: number[]): number {
    let l = 0;
    let r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const v of nums) {
            if (v <= mid) {
                ++cnt;
            }
        }
        if (cnt > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;

        while left < right {
            let mid = (left + right) >> 1;
            let cnt = nums.iter().filter(|x| **x <= (mid as i32)).count();
            if cnt > mid {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function (nums) {
    let l = 0;
    let r = nums.length - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        let cnt = 0;
        for (const v of nums) {
            if (v <= mid) {
                ++cnt;
            }
        }
        if (cnt > mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [288. 单词的唯一缩写 🔒](https://leetcode.cn/problems/unique-word-abbreviation){#288}

{{< tabs "288" >}}

{{% tab "python" %}}
```python
class ValidWordAbbr:
    def __init__(self, dictionary: List[str]):
        self.d = defaultdict(set)
        for s in dictionary:
            self.d[self.abbr(s)].add(s)

    def isUnique(self, word: str) -> bool:
        s = self.abbr(word)
        return s not in self.d or all(word == t for t in self.d[s])

    def abbr(self, s: str) -> str:
        return s if len(s) < 3 else s[0] + str(len(s) - 2) + s[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ValidWordAbbr {
    private Map<String, Set<String>> d = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        for (var s : dictionary) {
            d.computeIfAbsent(abbr(s), k -> new HashSet<>()).add(s);
        }
    }

    public boolean isUnique(String word) {
        var ws = d.get(abbr(word));
        return ws == null || (ws.size() == 1 && ws.contains(word));
    }

    private String abbr(String s) {
        int n = s.length();
        return n < 3 ? s : s.substring(0, 1) + (n - 2) + s.substring(n - 1);
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * boolean param_1 = obj.isUnique(word);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto& s : dictionary) {
            d[abbr(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        string s = abbr(word);
        return !d.count(s) || (d[s].size() == 1 && d[s].count(word));
    }

private:
    unordered_map<string, unordered_set<string>> d;

    string abbr(string& s) {
        int n = s.size();
        return n < 3 ? s : s.substr(0, 1) + to_string(n - 2) + s.substr(n - 1, 1);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type ValidWordAbbr struct {
	d map[string]map[string]bool
}

func Constructor(dictionary []string) ValidWordAbbr {
	d := make(map[string]map[string]bool)
	for _, s := range dictionary {
		abbr := abbr(s)
		if _, ok := d[abbr]; !ok {
			d[abbr] = make(map[string]bool)
		}
		d[abbr][s] = true
	}
	return ValidWordAbbr{d}
}

func (this *ValidWordAbbr) IsUnique(word string) bool {
	ws := this.d[abbr(word)]
	return ws == nil || (len(ws) == 1 && ws[word])
}

func abbr(s string) string {
	n := len(s)
	if n < 3 {
		return s
	}
	return fmt.Sprintf("%c%d%c", s[0], n-2, s[n-1])
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * obj := Constructor(dictionary);
 * param_1 := obj.IsUnique(word);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class ValidWordAbbr {
    private d: Map<string, Set<string>> = new Map();

    constructor(dictionary: string[]) {
        for (const s of dictionary) {
            const abbr = this.abbr(s);
            if (!this.d.has(abbr)) {
                this.d.set(abbr, new Set());
            }
            this.d.get(abbr)!.add(s);
        }
    }

    isUnique(word: string): boolean {
        const ws = this.d.get(this.abbr(word));
        return ws === undefined || (ws.size === 1 && ws.has(word));
    }

    abbr(s: string): string {
        const n = s.length;
        return n < 3 ? s : s[0] + (n - 2) + s[n - 1];
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * var obj = new ValidWordAbbr(dictionary)
 * var param_1 = obj.isUnique(word)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>单词的 <strong>缩写</strong> 需要遵循 <起始字母><中间字母数><结尾字母> 这样的格式。如果单词只有两个字符，那么它就是它自身的 <strong>缩写</strong> 。</p>

<p>以下是一些单词缩写的范例：</p>

<ul>
	<li><code>dog --> d1g</code> 因为第一个字母 <code>'d'</code> 和最后一个字母 <code>'g'</code> 之间有 <code>1</code> 个字母</li>
	<li><code>internationalization --> i18n</code> 因为第一个字母 <code>'i'</code> 和最后一个字母 <code>'n'</code> 之间有 <code>18</code> 个字母</li>
	<li><code>it --> it</code> 单词只有两个字符，它就是它自身的 <strong>缩写</strong></li>
</ul>

<p> </p>

<p>实现 <code>ValidWordAbbr</code> 类：</p>

<ul>
	<li><code>ValidWordAbbr(String[] dictionary)</code> 使用单词字典 <code>dictionary</code> 初始化对象</li>
	<li><code>boolean isUnique(string word)</code> 如果满足下述任意一个条件，返回 <code>true</code> ；否则，返回 <code>false</code> ：
	<ul>
		<li>字典 <code>dictionary</code> 中没有任何其他单词的 <strong>缩写</strong> 与该单词 <code>word</code> 的 <strong>缩写</strong> 相同。</li>
		<li>字典 <code>dictionary</code> 中的所有 <strong>缩写</strong> 与该单词 <code>word</code> 的 <strong>缩写</strong> 相同的单词都与 <code>word</code> <strong>相同</strong> 。</li>
	</ul>
	</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique", "isUnique"]
[[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"], ["cake"]]
<strong>输出
</strong>[null, false, true, false, true, true]

<strong>解释</strong>
ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
validWordAbbr.isUnique("dear"); // 返回 false，字典中的 "deer" 与输入 "dear" 的缩写都是 "d2r"，但这两个单词不相同
validWordAbbr.isUnique("cart"); // 返回 true，字典中不存在缩写为 "c2t" 的单词
validWordAbbr.isUnique("cane"); // 返回 false，字典中的 "cake" 与输入 "cane" 的缩写都是 "c2e"，但这两个单词不相同
validWordAbbr.isUnique("make"); // 返回 true，字典中不存在缩写为 "m2e" 的单词
validWordAbbr.isUnique("cake"); // 返回 true，因为 "cake" 已经存在于字典中，并且字典中没有其他缩写为 "c2e" 的单词
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= dictionary.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>1 <= dictionary[i].length <= 20</code></li>
	<li><code>dictionary[i]</code> 由小写英文字母组成</li>
	<li><code>1 <= word <= 20</code></li>
	<li><code>word</code> 由小写英文字母组成</li>
	<li>最多调用 <code>5000</code> 次 <code>isUnique</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

根据题目描述，我们定义一个函数 $abbr(s)$，它的功能是计算单词 $s$ 的缩写。如果单词 $s$ 的长度小于 $3$，那么它的缩写就是它本身；否则，它的缩写是它的首字母 + (它的长度 - 2) + 它的尾字母。

接下来，我们定义一个哈希表 $d$，它的键是单词的缩写，值是一个集合，集合中的元素是所有缩写为该键的单词。我们遍历给定的单词字典，对于字典中的每个单词 $s$，我们求出它的缩写 $abbr(s)$，并将 $s$ 添加到 $d[abbr(s)]$ 中。

在判断单词 $word$ 是否满足题目要求时，我们求出它的缩写 $abbr(word)$，如果 $abbr(word)$ 不在哈希表 $d$ 中，那么 $word$ 满足题目要求；否则，我们判断 $d[abbr(word)]$ 中是否只有一个元素，如果 $d[abbr(word)]$ 中只有一个元素且该元素就是 $word$，那么 $word$ 满足题目要求。

时间复杂度方面，初始化哈希表的时间复杂度是 $O(n)$，其中 $n$ 是单词字典的长度；判断单词是否满足题目要求的时间复杂度是 $O(1)$。空间复杂度方面，哈希表的空间复杂度是 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class ValidWordAbbr:
    def __init__(self, dictionary: List[str]):
        self.d = defaultdict(set)
        for s in dictionary:
            self.d[self.abbr(s)].add(s)

    def isUnique(self, word: str) -> bool:
        s = self.abbr(word)
        return s not in self.d or all(word == t for t in self.d[s])

    def abbr(self, s: str) -> str:
        return s if len(s) < 3 else s[0] + str(len(s) - 2) + s[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
```

#### Java

```java
class ValidWordAbbr {
    private Map<String, Set<String>> d = new HashMap<>();

    public ValidWordAbbr(String[] dictionary) {
        for (var s : dictionary) {
            d.computeIfAbsent(abbr(s), k -> new HashSet<>()).add(s);
        }
    }

    public boolean isUnique(String word) {
        var ws = d.get(abbr(word));
        return ws == null || (ws.size() == 1 && ws.contains(word));
    }

    private String abbr(String s) {
        int n = s.length();
        return n < 3 ? s : s.substring(0, 1) + (n - 2) + s.substring(n - 1);
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * boolean param_1 = obj.isUnique(word);
 */
```

#### C++

```cpp
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto& s : dictionary) {
            d[abbr(s)].insert(s);
        }
    }

    bool isUnique(string word) {
        string s = abbr(word);
        return !d.count(s) || (d[s].size() == 1 && d[s].count(word));
    }

private:
    unordered_map<string, unordered_set<string>> d;

    string abbr(string& s) {
        int n = s.size();
        return n < 3 ? s : s.substr(0, 1) + to_string(n - 2) + s.substr(n - 1, 1);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
```

#### Go

```go
type ValidWordAbbr struct {
	d map[string]map[string]bool
}

func Constructor(dictionary []string) ValidWordAbbr {
	d := make(map[string]map[string]bool)
	for _, s := range dictionary {
		abbr := abbr(s)
		if _, ok := d[abbr]; !ok {
			d[abbr] = make(map[string]bool)
		}
		d[abbr][s] = true
	}
	return ValidWordAbbr{d}
}

func (this *ValidWordAbbr) IsUnique(word string) bool {
	ws := this.d[abbr(word)]
	return ws == nil || (len(ws) == 1 && ws[word])
}

func abbr(s string) string {
	n := len(s)
	if n < 3 {
		return s
	}
	return fmt.Sprintf("%c%d%c", s[0], n-2, s[n-1])
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * obj := Constructor(dictionary);
 * param_1 := obj.IsUnique(word);
 */
```

#### TypeScript

```ts
class ValidWordAbbr {
    private d: Map<string, Set<string>> = new Map();

    constructor(dictionary: string[]) {
        for (const s of dictionary) {
            const abbr = this.abbr(s);
            if (!this.d.has(abbr)) {
                this.d.set(abbr, new Set());
            }
            this.d.get(abbr)!.add(s);
        }
    }

    isUnique(word: string): boolean {
        const ws = this.d.get(this.abbr(word));
        return ws === undefined || (ws.size === 1 && ws.has(word));
    }

    abbr(s: string): string {
        const n = s.length;
        return n < 3 ? s : s[0] + (n - 2) + s[n - 1];
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * var obj = new ValidWordAbbr(dictionary)
 * var param_1 = obj.isUnique(word)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [289. 生命游戏](https://leetcode.cn/problems/game-of-life){#289}

{{< tabs "289" >}}

{{% tab "python" %}}
```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                live = -board[i][j]
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n and board[x][y] > 0:
                            live += 1
                if board[i][j] and (live < 2 or live > 3):
                    board[i][j] = 2
                if board[i][j] == 0 and live == 3:
                    board[i][j] = -1
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 0
                elif board[i][j] == -1:
                    board[i][j] = 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
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
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func gameOfLife(board [][]int) {
	m, n := len(board), len(board[0])
	for i := 0; i < m; i++ {
		for j, v := range board[i] {
			live := -v
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0 {
						live++
					}
				}
			}
			if v == 1 && (live < 2 || live > 3) {
				board[i][j] = 2
			}
			if v == 0 && live == 3 {
				board[i][j] = -1
			}
		}
	}
	for i := 0; i < m; i++ {
		for j, v := range board[i] {
			if v == 2 {
				board[i][j] = 0
			}
			if v == -1 {
				board[i][j] = 1
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify board in-place instead.
 */
function gameOfLife(board: number[][]): void {
    const m = board.length;
    const n = board[0].length;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let live = -board[i][j];
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                        ++live;
                    }
                }
            }
            if (board[i][j] === 1 && (live < 2 || live > 3)) {
                board[i][j] = 2;
            }
            if (board[i][j] === 0 && live === 3) {
                board[i][j] = -1;
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 2) {
                board[i][j] = 0;
            }
            if (board[i][j] === -1) {
                board[i][j] = 1;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
const DIR: [(i32, i32); 8] = [
    (-1, 0),
    (1, 0),
    (0, -1),
    (0, 1),
    (-1, -1),
    (-1, 1),
    (1, -1),
    (1, 1),
];

impl Solution {
    #[allow(dead_code)]
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let n = board.len();
        let m = board[0].len();
        let mut weight_vec: Vec<Vec<i32>> = vec![vec![0; m]; n];

        // Initialize the weight vector
        for i in 0..n {
            for j in 0..m {
                if board[i][j] == 0 {
                    continue;
                }
                for (dx, dy) in DIR {
                    let x = (i as i32) + dx;
                    let y = (j as i32) + dy;
                    if Self::check_bounds(x, y, n as i32, m as i32) {
                        weight_vec[x as usize][y as usize] += 1;
                    }
                }
            }
        }

        // Update the board
        for i in 0..n {
            for j in 0..m {
                if weight_vec[i][j] < 2 {
                    board[i][j] = 0;
                } else if weight_vec[i][j] <= 3 {
                    if board[i][j] == 0 && weight_vec[i][j] == 3 {
                        board[i][j] = 1;
                    }
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public void GameOfLife(int[][] board) {
        int m = board.Length;
        int n = board[0].Length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>根据&nbsp;<a href="https://baike.baidu.com/item/%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F/2926434?fr=aladdin" target="_blank">百度百科</a>&nbsp;，&nbsp;<strong>生命游戏</strong>&nbsp;，简称为 <strong>生命</strong> ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。</p>

<p>给定一个包含 <code>m × n</code>&nbsp;个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： <code>1</code> 即为 <strong>活细胞</strong> （live），或 <code>0</code> 即为 <strong>死细胞</strong> （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：</p>

<ol>
	<li>如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；</li>
	<li>如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；</li>
	<li>如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；</li>
	<li>如果死细胞周围正好有三个活细胞，则该位置死细胞复活；</li>
</ol>

<p>下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是 <strong>同时</strong> 发生的。给你 <code>m x n</code> 网格面板 <code>board</code> 的当前状态，返回下一个状态。</p>

<p>给定当前&nbsp;<code>board</code>&nbsp;的状态，<strong>更新</strong>&nbsp;<code>board</code>&nbsp;到下一个状态。</p>

<p><strong>注意</strong> 你不需要返回任何东西。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0289.Game%20of%20Life/images/grid1.jpg" />
<pre>
<strong>输入：</strong>board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
<strong>输出：</strong>[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0289.Game%20of%20Life/images/grid2.jpg" />
<pre>
<strong>输入：</strong>board = [[1,1],[1,0]]
<strong>输出：</strong>[[1,1],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 25</code></li>
	<li><code>board[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。</li>
	<li>本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：原地标记

我们不妨定义两个新的状态，其中状态 $2$ 表示活细胞在下一个状态转为死细胞，状态 $-1$ 表示死细胞在下一个状态转为活细胞。那么，对于当前遍历到的格子，如果格子大于 $0$，就表示当前格子是活细胞，否则就是死细胞。

因此，我们可以遍历整个面板，对于每个格子，统计其周围的活细胞数目，用变量 $live$ 表示。如果当前格子是活细胞，那么当 $live \lt 2$ 或者 $live \gt 3$ 时，当前格子的下一个状态是死细胞，即状态 $2$；如果当前格子是死细胞，那么当 $live = 3$ 时，当前格子的下一个状态是活细胞，即状态 $-1$。

最后，我们再遍历一遍面板，将状态 $2$ 的格子更新为死细胞，将状态 $-1$ 的格子更新为活细胞。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是面板的行数和列数。我们需要遍历整个面板。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                live = -board[i][j]
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n and board[x][y] > 0:
                            live += 1
                if board[i][j] and (live < 2 or live > 3):
                    board[i][j] = 2
                if board[i][j] == 0 and live == 3:
                    board[i][j] = -1
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 0
                elif board[i][j] == -1:
                    board[i][j] = 1
```

#### Java

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
```

#### Go

```go
func gameOfLife(board [][]int) {
	m, n := len(board), len(board[0])
	for i := 0; i < m; i++ {
		for j, v := range board[i] {
			live := -v
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0 {
						live++
					}
				}
			}
			if v == 1 && (live < 2 || live > 3) {
				board[i][j] = 2
			}
			if v == 0 && live == 3 {
				board[i][j] = -1
			}
		}
	}
	for i := 0; i < m; i++ {
		for j, v := range board[i] {
			if v == 2 {
				board[i][j] = 0
			}
			if v == -1 {
				board[i][j] = 1
			}
		}
	}
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify board in-place instead.
 */
function gameOfLife(board: number[][]): void {
    const m = board.length;
    const n = board[0].length;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let live = -board[i][j];
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                        ++live;
                    }
                }
            }
            if (board[i][j] === 1 && (live < 2 || live > 3)) {
                board[i][j] = 2;
            }
            if (board[i][j] === 0 && live === 3) {
                board[i][j] = -1;
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === 2) {
                board[i][j] = 0;
            }
            if (board[i][j] === -1) {
                board[i][j] = 1;
            }
        }
    }
}
```

#### Rust

```rust
const DIR: [(i32, i32); 8] = [
    (-1, 0),
    (1, 0),
    (0, -1),
    (0, 1),
    (-1, -1),
    (-1, 1),
    (1, -1),
    (1, 1),
];

impl Solution {
    #[allow(dead_code)]
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let n = board.len();
        let m = board[0].len();
        let mut weight_vec: Vec<Vec<i32>> = vec![vec![0; m]; n];

        // Initialize the weight vector
        for i in 0..n {
            for j in 0..m {
                if board[i][j] == 0 {
                    continue;
                }
                for (dx, dy) in DIR {
                    let x = (i as i32) + dx;
                    let y = (j as i32) + dy;
                    if Self::check_bounds(x, y, n as i32, m as i32) {
                        weight_vec[x as usize][y as usize] += 1;
                    }
                }
            }
        }

        // Update the board
        for i in 0..n {
            for j in 0..m {
                if weight_vec[i][j] < 2 {
                    board[i][j] = 0;
                } else if weight_vec[i][j] <= 3 {
                    if board[i][j] == 0 && weight_vec[i][j] == 3 {
                        board[i][j] = 1;
                    }
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```

#### C#

```cs
public class Solution {
    public void GameOfLife(int[][] board) {
        int m = board.Length;
        int n = board[0].Length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = -board[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                            ++live;
                        }
                    }
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = 2;
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

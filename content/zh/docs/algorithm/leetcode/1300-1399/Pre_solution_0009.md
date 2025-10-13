---
title: "1380_矩阵中的幸运数"
date: 2025-10-08T18:37:12+08:00
weight: 9
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 分治, 动态规划, 双指针, 哈希表, 堆（优先队列）, 排序, 数据库, 数组, 栈, 树, 模拟, 深度优先搜索, 矩阵, 记忆化搜索, 设计, 贪心]
---

{{< markmap >}}
### [1380_矩阵中的幸运数](#1380)
#### [数组](#1380)
#### [矩阵](#1380)
### [1381_设计一个支持增量操作的栈](#1381)
#### [栈](#1381)
#### [设计](#1381)
#### [数组](#1381)
### [1382_将二叉搜索树变平衡](#1382)
#### [贪心](#1382)
#### [树](#1382)
#### [深度优先搜索](#1382)
#### [二叉搜索树](#1382)
#### [分治](#1382)
#### [二叉树](#1382)
### [1383_最大的团队表现值](#1383)
#### [贪心](#1383)
#### [数组](#1383)
#### [排序](#1383)
#### [堆（优先队列）](#1383)
### [1384_按年度列出销售总额 🔒](#1384)
#### [数据库](#1384)
### [1385_两个数组间的距离值](#1385)
#### [数组](#1385)
#### [双指针](#1385)
#### [二分查找](#1385)
#### [排序](#1385)
### [1386_安排电影院座位](#1386)
#### [贪心](#1386)
#### [位运算](#1386)
#### [数组](#1386)
#### [哈希表](#1386)
### [1387_将整数按权重排序](#1387)
#### [记忆化搜索](#1387)
#### [动态规划](#1387)
#### [排序](#1387)
### [1388_3n 块披萨](#1388)
#### [贪心](#1388)
#### [数组](#1388)
#### [动态规划](#1388)
#### [堆（优先队列）](#1388)
### [1389_按既定顺序创建目标数组](#1389)
#### [数组](#1389)
#### [模拟](#1389)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1380_矩阵中的幸运数
___
#### 数组
___
#### 矩阵
---
### 1381_设计一个支持增量操作的栈
___
#### 栈
___
#### 设计
___
#### 数组
---
### 1382_将二叉搜索树变平衡
___
#### 贪心
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 分治
___
#### 二叉树
---
### 1383_最大的团队表现值
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1384_按年度列出销售总额 🔒
___
#### 数据库
---
### 1385_两个数组间的距离值
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 1386_安排电影院座位
___
#### 贪心
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 1387_将整数按权重排序
___
#### 记忆化搜索
___
#### 动态规划
___
#### 排序
---
### 1388_3n 块披萨
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 堆（优先队列）
---
### 1389_按既定顺序创建目标数组
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 分治 | 动态规划 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 排序 | 数据库 | 数组 |
| 栈 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 记忆化搜索 |
| 设计 | 贪心 |  |

# [1380. 矩阵中的幸运数](https://leetcode.cn/problems/lucky-numbers-in-a-matrix){#1380}

{{< tabs "1380" >}}

{{% tab "python" %}}
```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        rows = {min(row) for row in matrix}
        cols = {max(col) for col in zip(*matrix)}
        return list(rows & cols)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        Arrays.fill(rows, 1 << 30);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = Math.min(rows[i], matrix[i][j]);
                cols[j] = Math.max(cols[j], matrix[i][j]);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] == cols[j]) {
                    ans.add(rows[i]);
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
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rows[m];
        int cols[n];
        memset(rows, 0x3f, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] == cols[j]) {
                    ans.push_back(rows[i]);
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
func luckyNumbers(matrix [][]int) (ans []int) {
	m, n := len(matrix), len(matrix[0])
	rows, cols := make([]int, m), make([]int, n)
	for i := range rows {
		rows[i] = 1 << 30
	}
	for i, row := range matrix {
		for j, x := range row {
			rows[i] = min(rows[i], x)
			cols[j] = max(cols[j], x)
		}
	}
	for i, row := range matrix {
		for j, x := range row {
			if rows[i] == cols[j] {
				ans = append(ans, x)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function luckyNumbers(matrix: number[][]): number[] {
    const m = matrix.length;
    const n = matrix[0].length;
    const rows: number[] = new Array(m).fill(1 << 30);
    const cols: number[] = new Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            rows[i] = Math.min(rows[i], matrix[i][j]);
            cols[j] = Math.max(cols[j], matrix[i][j]);
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (rows[i] === cols[j]) {
                ans.push(rows[i]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const rows = new Array(m).fill(1 << 30);
    const cols = new Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            rows[i] = Math.min(rows[i], matrix[i][j]);
            cols[j] = Math.max(cols[j], matrix[i][j]);
        }
    }
    const ans = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (rows[i] === cols[j]) {
                ans.push(rows[i]);
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut res = vec![];
        let mut col = vec![0; n];
        for j in 0..n {
            for i in 0..m {
                col[j] = col[j].max(matrix[i][j]);
            }
        }
        for x in 0..m {
            let mut i = 0;
            for y in 1..n {
                if matrix[x][y] < matrix[x][i] {
                    i = y;
                }
            }
            if matrix[x][i] == col[i] {
                res.push(col[i]);
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x&nbsp;n</code> 的矩阵，矩阵中的数字 <strong>各不相同</strong> 。请你按 <strong>任意</strong> 顺序返回矩阵中的所有幸运数。</p>

<p><strong>幸运数</strong> 是指矩阵中满足同时下列两个条件的元素：</p>

<ul>
	<li>在同一行的所有元素中最小</li>
	<li>在同一列的所有元素中最大</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[3,7,8],[9,11,13],[15,16,17]]
<strong>输出：</strong>[15]
<strong>解释：</strong>15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
<strong>输出：</strong>[12]
<strong>解释：</strong>12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[7,8],[1,2]]
<strong>输出：</strong>[7]
<strong>解释：</strong>7 是唯一的幸运数字，因为它是行中的最小值，列中的最大值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 50</code></li>
	<li><code>1 &lt;=&nbsp;matrix[i][j]&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li>矩阵中的所有元素都是不同的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护行最小值和列最大值

我们可以使用两个数组 $rows$ 和 $cols$ 记录矩阵中每一行的最小值和每一列的最大值，然后遍历矩阵中的每一个元素，检查该元素是否为所在行的最小值且为所在列的最大值，如果是则该元素为幸运数，我们将其加入答案数组。

遍历结束后，我们返回答案数组即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        rows = {min(row) for row in matrix}
        cols = {max(col) for col in zip(*matrix)}
        return list(rows & cols)
```

#### Java

```java
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        Arrays.fill(rows, 1 << 30);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = Math.min(rows[i], matrix[i][j]);
                cols[j] = Math.max(cols[j], matrix[i][j]);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] == cols[j]) {
                    ans.add(rows[i]);
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
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rows[m];
        int cols[n];
        memset(rows, 0x3f, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] == cols[j]) {
                    ans.push_back(rows[i]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func luckyNumbers(matrix [][]int) (ans []int) {
	m, n := len(matrix), len(matrix[0])
	rows, cols := make([]int, m), make([]int, n)
	for i := range rows {
		rows[i] = 1 << 30
	}
	for i, row := range matrix {
		for j, x := range row {
			rows[i] = min(rows[i], x)
			cols[j] = max(cols[j], x)
		}
	}
	for i, row := range matrix {
		for j, x := range row {
			if rows[i] == cols[j] {
				ans = append(ans, x)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function luckyNumbers(matrix: number[][]): number[] {
    const m = matrix.length;
    const n = matrix[0].length;
    const rows: number[] = new Array(m).fill(1 << 30);
    const cols: number[] = new Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            rows[i] = Math.min(rows[i], matrix[i][j]);
            cols[j] = Math.max(cols[j], matrix[i][j]);
        }
    }
    const ans: number[] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (rows[i] === cols[j]) {
                ans.push(rows[i]);
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function (matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const rows = new Array(m).fill(1 << 30);
    const cols = new Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            rows[i] = Math.min(rows[i], matrix[i][j]);
            cols[j] = Math.max(cols[j], matrix[i][j]);
        }
    }
    const ans = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (rows[i] === cols[j]) {
                ans.push(rows[i]);
            }
        }
    }
    return ans;
};
```

#### Rust

```rust
impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut res = vec![];
        let mut col = vec![0; n];
        for j in 0..n {
            for i in 0..m {
                col[j] = col[j].max(matrix[i][j]);
            }
        }
        for x in 0..m {
            let mut i = 0;
            for y in 1..n {
                if matrix[x][y] < matrix[x][i] {
                    i = y;
                }
            }
            if matrix[x][i] == col[i] {
                res.push(col[i]);
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1381. 设计一个支持增量操作的栈](https://leetcode.cn/problems/design-a-stack-with-increment-operation){#1381}

{{< tabs "1381" >}}

{{% tab "python" %}}
```python
class CustomStack:
    def __init__(self, maxSize: int):
        self.stk = [0] * maxSize
        self.add = [0] * maxSize
        self.i = 0

    def push(self, x: int) -> None:
        if self.i < len(self.stk):
            self.stk[self.i] = x
            self.i += 1

    def pop(self) -> int:
        if self.i <= 0:
            return -1
        self.i -= 1
        ans = self.stk[self.i] + self.add[self.i]
        if self.i > 0:
            self.add[self.i - 1] += self.add[self.i]
        self.add[self.i] = 0
        return ans

    def increment(self, k: int, val: int) -> None:
        i = min(k, self.i) - 1
        if i >= 0:
            self.add[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class CustomStack {
    private int[] stk;
    private int[] add;
    private int i;

    public CustomStack(int maxSize) {
        stk = new int[maxSize];
        add = new int[maxSize];
    }

    public void push(int x) {
        if (i < stk.length) {
            stk[i++] = x;
        }
    }

    public int pop() {
        if (i <= 0) {
            return -1;
        }
        int ans = stk[--i] + add[i];
        if (i > 0) {
            add[i - 1] += add[i];
        }
        add[i] = 0;
        return ans;
    }

    public void increment(int k, int val) {
        if (i > 0) {
            add[Math.min(i, k) - 1] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class CustomStack {
public:
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        add.resize(maxSize);
        i = 0;
    }

    void push(int x) {
        if (i < stk.size()) {
            stk[i++] = x;
        }
    }

    int pop() {
        if (i <= 0) {
            return -1;
        }
        int ans = stk[--i] + add[i];
        if (i > 0) {
            add[i - 1] += add[i];
        }
        add[i] = 0;
        return ans;
    }

    void increment(int k, int val) {
        if (i > 0) {
            add[min(k, i) - 1] += val;
        }
    }

private:
    vector<int> stk;
    vector<int> add;
    int i;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type CustomStack struct {
	stk []int
	add []int
	i   int
}

func Constructor(maxSize int) CustomStack {
	return CustomStack{make([]int, maxSize), make([]int, maxSize), 0}
}

func (this *CustomStack) Push(x int) {
	if this.i < len(this.stk) {
		this.stk[this.i] = x
		this.i++
	}
}

func (this *CustomStack) Pop() int {
	if this.i <= 0 {
		return -1
	}
	this.i--
	ans := this.stk[this.i] + this.add[this.i]
	if this.i > 0 {
		this.add[this.i-1] += this.add[this.i]
	}
	this.add[this.i] = 0
	return ans
}

func (this *CustomStack) Increment(k int, val int) {
	if this.i > 0 {
		this.add[min(k, this.i)-1] += val
	}
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class CustomStack {
    private stk: number[];
    private add: number[];
    private i: number;

    constructor(maxSize: number) {
        this.stk = Array(maxSize).fill(0);
        this.add = Array(maxSize).fill(0);
        this.i = 0;
    }

    push(x: number): void {
        if (this.i < this.stk.length) {
            this.stk[this.i++] = x;
        }
    }

    pop(): number {
        if (this.i <= 0) {
            return -1;
        }
        const ans = this.stk[--this.i] + this.add[this.i];
        if (this.i > 0) {
            this.add[this.i - 1] += this.add[this.i];
        }
        this.add[this.i] = 0;
        return ans;
    }

    increment(k: number, val: number): void {
        if (this.i > 0) {
            this.add[Math.min(this.i, k) - 1] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个支持对其元素进行增量操作的栈。</p>

<p>实现自定义栈类 <code>CustomStack</code> ：</p>

<ul>
	<li><code>CustomStack(int maxSize)</code>：用 <code>maxSize</code> 初始化对象，<code>maxSize</code> 是栈中最多能容纳的元素数量。</li>
	<li><code>void push(int x)</code>：如果栈还未增长到 <code>maxSize</code> ，就将 <code>x</code> 添加到栈顶。</li>
	<li><code>int pop()</code>：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 <strong>-1</strong> 。</li>
	<li><code>void inc(int k, int val)</code>：栈底的 <code>k</code> 个元素的值都增加 <code>val</code> 。如果栈中元素总数小于 <code>k</code> ，则栈中的所有元素都增加 <code>val</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
<strong>输出：</strong>
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
<strong>解释：</strong>
CustomStack stk = new CustomStack(3); // 栈是空的 []
stk.push(1);                          // 栈变为 [1]
stk.push(2);                          // 栈变为 [1, 2]
stk.pop();                            // 返回 2 --&gt; 返回栈顶值 2，栈变为 [1]
stk.push(2);                          // 栈变为 [1, 2]
stk.push(3);                          // 栈变为 [1, 2, 3]
stk.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
stk.increment(5, 100);                // 栈变为 [101, 102, 103]
stk.increment(2, 100);                // 栈变为 [201, 202, 103]
stk.pop();                            // 返回 103 --&gt; 返回栈顶值 103，栈变为 [201, 202]
stk.pop();                            // 返回 202 --&gt; 返回栈顶值 202，栈变为 [201]
stk.pop();                            // 返回 201 --&gt; 返回栈顶值 201，栈变为 []
stk.pop();                            // 返回 -1 --&gt; 栈为空，返回 -1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= maxSize, x, k &lt;= 1000</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
	<li>每种方法 <code>increment</code>，<code>push</code> 以及 <code>pop</code> 分别最多调用 <code>1000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组模拟

我们可以用一个数组 $stk$ 来模拟栈，用一个整数 $i$ 表示下一个入栈的元素位置。另外，我们还需要一个数组 $add$ 来记录每个位置上的增量累加值。

调用 $push(x)$ 时，如果 $i \lt maxSize$，我们将 $x$ 放入 $stk[i]$ 中，并将 $i$ 加一。

调用 $pop()$ 时，如果 $i \leq 0$，说明栈为空，返回 $-1$。否则我们将 $i$ 减一，答案为 $stk[i] + add[i]$，然后我们将 $add[i - 1]$ 加上 $add[i]$，并将 $add[i]$ 清零。最后返回答案。

调用 $increment(k, val)$ 时，如果 $i \gt 0$，我们将 $add[\min(i, k) - 1]$ 加上 $val$。

时间复杂度 $O(1)$，空间复杂度 $O(n)$。其中 $n$ 是栈的最大容量。

<!-- tabs:start -->

#### Python3

```python
class CustomStack:
    def __init__(self, maxSize: int):
        self.stk = [0] * maxSize
        self.add = [0] * maxSize
        self.i = 0

    def push(self, x: int) -> None:
        if self.i < len(self.stk):
            self.stk[self.i] = x
            self.i += 1

    def pop(self) -> int:
        if self.i <= 0:
            return -1
        self.i -= 1
        ans = self.stk[self.i] + self.add[self.i]
        if self.i > 0:
            self.add[self.i - 1] += self.add[self.i]
        self.add[self.i] = 0
        return ans

    def increment(self, k: int, val: int) -> None:
        i = min(k, self.i) - 1
        if i >= 0:
            self.add[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
```

#### Java

```java
class CustomStack {
    private int[] stk;
    private int[] add;
    private int i;

    public CustomStack(int maxSize) {
        stk = new int[maxSize];
        add = new int[maxSize];
    }

    public void push(int x) {
        if (i < stk.length) {
            stk[i++] = x;
        }
    }

    public int pop() {
        if (i <= 0) {
            return -1;
        }
        int ans = stk[--i] + add[i];
        if (i > 0) {
            add[i - 1] += add[i];
        }
        add[i] = 0;
        return ans;
    }

    public void increment(int k, int val) {
        if (i > 0) {
            add[Math.min(i, k) - 1] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```

#### C++

```cpp
class CustomStack {
public:
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        add.resize(maxSize);
        i = 0;
    }

    void push(int x) {
        if (i < stk.size()) {
            stk[i++] = x;
        }
    }

    int pop() {
        if (i <= 0) {
            return -1;
        }
        int ans = stk[--i] + add[i];
        if (i > 0) {
            add[i - 1] += add[i];
        }
        add[i] = 0;
        return ans;
    }

    void increment(int k, int val) {
        if (i > 0) {
            add[min(k, i) - 1] += val;
        }
    }

private:
    vector<int> stk;
    vector<int> add;
    int i;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```

#### Go

```go
type CustomStack struct {
	stk []int
	add []int
	i   int
}

func Constructor(maxSize int) CustomStack {
	return CustomStack{make([]int, maxSize), make([]int, maxSize), 0}
}

func (this *CustomStack) Push(x int) {
	if this.i < len(this.stk) {
		this.stk[this.i] = x
		this.i++
	}
}

func (this *CustomStack) Pop() int {
	if this.i <= 0 {
		return -1
	}
	this.i--
	ans := this.stk[this.i] + this.add[this.i]
	if this.i > 0 {
		this.add[this.i-1] += this.add[this.i]
	}
	this.add[this.i] = 0
	return ans
}

func (this *CustomStack) Increment(k int, val int) {
	if this.i > 0 {
		this.add[min(k, this.i)-1] += val
	}
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */
```

#### TypeScript

```ts
class CustomStack {
    private stk: number[];
    private add: number[];
    private i: number;

    constructor(maxSize: number) {
        this.stk = Array(maxSize).fill(0);
        this.add = Array(maxSize).fill(0);
        this.i = 0;
    }

    push(x: number): void {
        if (this.i < this.stk.length) {
            this.stk[this.i++] = x;
        }
    }

    pop(): number {
        if (this.i <= 0) {
            return -1;
        }
        const ans = this.stk[--this.i] + this.add[this.i];
        if (this.i > 0) {
            this.add[this.i - 1] += this.add[this.i];
        }
        this.add[this.i] = 0;
        return ans;
    }

    increment(k: number, val: number): void {
        if (this.i > 0) {
            this.add[Math.min(this.i, k) - 1] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * var obj = new CustomStack(maxSize)
 * obj.push(x)
 * var param_2 = obj.pop()
 * obj.increment(k,val)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1382. 将二叉搜索树变平衡](https://leetcode.cn/problems/balance-a-binary-search-tree){#1382}

{{< tabs "1382" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def dfs(root: TreeNode):
            if root is None:
                return
            dfs(root.left)
            nums.append(root.val)
            dfs(root.right)

        def build(i: int, j: int) -> TreeNode:
            if i > j:
                return None
            mid = (i + j) >> 1
            left = build(i, mid - 1)
            right = build(mid + 1, j)
            return TreeNode(nums[mid], left, right)

        nums = []
        dfs(root)
        return build(0, len(nums) - 1)
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
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public TreeNode balanceBST(TreeNode root) {
        dfs(root);
        return build(0, nums.size() - 1);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
    }

    private TreeNode build(int i, int j) {
        if (i > j) {
            return null;
        }
        int mid = (i + j) >> 1;
        TreeNode left = build(i, mid - 1);
        TreeNode right = build(mid + 1, j);
        return new TreeNode(nums.get(mid), left, right);
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, nums.size() - 1);
    }

private:
    vector<int> nums;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* build(int i, int j) {
        if (i > j) {
            return nullptr;
        }
        int mid = (i + j) >> 1;
        TreeNode* left = build(i, mid - 1);
        TreeNode* right = build(mid + 1, j);
        return new TreeNode(nums[mid], left, right);
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
func balanceBST(root *TreeNode) *TreeNode {
	ans := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = append(ans, root.Val)
		dfs(root.Right)
	}
	var build func(i, j int) *TreeNode
	build = func(i, j int) *TreeNode {
		if i > j {
			return nil
		}
		mid := (i + j) >> 1
		left := build(i, mid-1)
		right := build(mid+1, j)
		return &TreeNode{Val: ans[mid], Left: left, Right: right}
	}
	dfs(root)
	return build(0, len(ans)-1)
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

function balanceBST(root: TreeNode | null): TreeNode | null {
    const nums: number[] = [];
    const dfs = (root: TreeNode | null): void => {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.push(root.val);
        dfs(root.right);
    };
    const build = (i: number, j: number): TreeNode | null => {
        if (i > j) {
            return null;
        }
        const mid: number = (i + j) >> 1;
        const left: TreeNode | null = build(i, mid - 1);
        const right: TreeNode | null = build(mid + 1, j);
        return new TreeNode(nums[mid], left, right);
    };
    dfs(root);
    return build(0, nums.length - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉搜索树，请你返回一棵&nbsp;<strong>平衡后</strong>&nbsp;的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。</p>

<p>如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 <code>1</code> ，我们就称这棵二叉搜索树是&nbsp;<strong>平衡的</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1382.Balance%20a%20Binary%20Search%20Tree/images/balance1-tree.jpg" style="height: 319px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,null,3,null,4,null,null]
<strong>输出：</strong>[2,1,3,null,null,null,4]
<strong>解释：</strong>这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1382.Balance%20a%20Binary%20Search%20Tree/images/balanced2-tree.jpg" style="height: 145px; width: 224px;" /></p>

<pre>
<strong>输入:</strong> root = [2,1,3]
<strong>输出:</strong> [2,1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树节点的数目在&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;范围内。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历 + 构造平衡二叉树

由于原树是一棵二叉搜索树，因此我们可以将其中序遍历的结果保存在一个数组 $nums$ 中，然后我们设计一个函数 $build(i, j)$，它用来构造 $nums$ 中下标范围 $[i, j]$ 内的平衡二叉搜索树，那么答案就是 $build(0, |nums| - 1)$。

函数 $build(i, j)$ 的执行逻辑如下：

-   如果 $i > j$，那么平衡二叉搜索树为空，返回空节点；
-   否则，我们取 $mid = (i + j) / 2$ 作为根节点，然后递归构建左子树和右子树，返回根节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def dfs(root: TreeNode):
            if root is None:
                return
            dfs(root.left)
            nums.append(root.val)
            dfs(root.right)

        def build(i: int, j: int) -> TreeNode:
            if i > j:
                return None
            mid = (i + j) >> 1
            left = build(i, mid - 1)
            right = build(mid + 1, j)
            return TreeNode(nums[mid], left, right)

        nums = []
        dfs(root)
        return build(0, len(nums) - 1)
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
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public TreeNode balanceBST(TreeNode root) {
        dfs(root);
        return build(0, nums.size() - 1);
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.add(root.val);
        dfs(root.right);
    }

    private TreeNode build(int i, int j) {
        if (i > j) {
            return null;
        }
        int mid = (i + j) >> 1;
        TreeNode left = build(i, mid - 1);
        TreeNode right = build(mid + 1, j);
        return new TreeNode(nums.get(mid), left, right);
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, nums.size() - 1);
    }

private:
    vector<int> nums;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* build(int i, int j) {
        if (i > j) {
            return nullptr;
        }
        int mid = (i + j) >> 1;
        TreeNode* left = build(i, mid - 1);
        TreeNode* right = build(mid + 1, j);
        return new TreeNode(nums[mid], left, right);
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
func balanceBST(root *TreeNode) *TreeNode {
	ans := []int{}
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = append(ans, root.Val)
		dfs(root.Right)
	}
	var build func(i, j int) *TreeNode
	build = func(i, j int) *TreeNode {
		if i > j {
			return nil
		}
		mid := (i + j) >> 1
		left := build(i, mid-1)
		right := build(mid+1, j)
		return &TreeNode{Val: ans[mid], Left: left, Right: right}
	}
	dfs(root)
	return build(0, len(ans)-1)
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

function balanceBST(root: TreeNode | null): TreeNode | null {
    const nums: number[] = [];
    const dfs = (root: TreeNode | null): void => {
        if (root == null) {
            return;
        }
        dfs(root.left);
        nums.push(root.val);
        dfs(root.right);
    };
    const build = (i: number, j: number): TreeNode | null => {
        if (i > j) {
            return null;
        }
        const mid: number = (i + j) >> 1;
        const left: TreeNode | null = build(i, mid - 1);
        const right: TreeNode | null = build(mid + 1, j);
        return new TreeNode(nums[mid], left, right);
    };
    dfs(root);
    return build(0, nums.length - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1383. 最大的团队表现值](https://leetcode.cn/problems/maximum-performance-of-a-team){#1383}

{{< tabs "1383" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPerformance(
        self, n: int, speed: List[int], efficiency: List[int], k: int
    ) -> int:
        t = sorted(zip(speed, efficiency), key=lambda x: -x[1])
        ans = tot = 0
        mod = 10**9 + 7
        h = []
        for s, e in t:
            tot += s
            ans = max(ans, tot * e)
            heappush(h, s)
            if len(h) == k:
                tot -= heappop(h)
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] t = new int[n][2];
        for (int i = 0; i < n; ++i) {
            t[i] = new int[] {speed[i], efficiency[i]};
        }
        Arrays.sort(t, (a, b) -> b[1] - a[1]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        long tot = 0;
        long ans = 0;
        for (var x : t) {
            int s = x[0], e = x[1];
            tot += s;
            ans = Math.max(ans, tot * e);
            q.offer(s);
            if (q.size() == k) {
                tot -= q.poll();
            }
        }
        return (int) (ans % MOD);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> t(n);
        for (int i = 0; i < n; ++i) t[i] = {-efficiency[i], speed[i]};
        sort(t.begin(), t.end());
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = 0, tot = 0;
        int mod = 1e9 + 7;
        for (auto& x : t) {
            int s = x.second, e = -x.first;
            tot += s;
            ans = max(ans, tot * e);
            q.push(s);
            if (q.size() == k) {
                tot -= q.top();
                q.pop();
            }
        }
        return (int) (ans % mod);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPerformance(n int, speed []int, efficiency []int, k int) int {
	t := make([][]int, n)
	for i, s := range speed {
		t[i] = []int{s, efficiency[i]}
	}
	sort.Slice(t, func(i, j int) bool { return t[i][1] > t[j][1] })
	var mod int = 1e9 + 7
	ans, tot := 0, 0
	pq := hp{}
	for _, x := range t {
		s, e := x[0], x[1]
		tot += s
		ans = max(ans, tot*e)
		heap.Push(&pq, s)
		if pq.Len() == k {
			tot -= heap.Pop(&pq).(int)
		}
	}
	return ans % mod
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个整数 <code>n</code> 和 <code>k</code>，以及两个长度为 <code>n</code> 的整数数组 <code>speed</code> 和<code> efficiency</code>。现有 <code>n</code> 名工程师，编号从 <code>1</code> 到 <code>n</code>。其中 <code>speed[i]</code>&nbsp;和 <code>efficiency[i]</code>&nbsp;分别代表第 <code>i</code>&nbsp;位工程师的速度和效率。</p>

<p>从这 <code>n</code> 名工程师中最多选择 <code>k</code> 名不同的工程师，使其组成的团队具有最大的团队表现值。</p>

<p><strong>团队表现值</strong>&nbsp;的定义为：一个团队中「所有工程师速度的和」乘以他们「效率值中的最小值」。</p>

<p>请你返回该团队的​​​​​​最大团队表现值，由于答案可能很大，请你返回结果对 <code>10^9 + 7</code> 取余后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
<strong>输出：</strong>60
<strong>解释：</strong>
我们选择工程师 2（speed=10 且 efficiency=4）和工程师 5（speed=5 且 efficiency=7）。他们的团队表现值为 performance = (10 + 5) * min(4, 7) = 60 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
<strong>输出：</strong>68
<strong>解释：
</strong>此示例与第一个示例相同，除了 k = 3 。我们可以选择工程师 1 ，工程师 2 和工程师 5 得到最大的团队表现值。表现值为 performance = (2 + 10 + 5) * min(5, 4, 7) = 68 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
<strong>输出：</strong>72
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 10^5</code></li>
	<li><code>speed.length == n</code></li>
	<li><code>efficiency.length == n</code></li>
	<li><code>1 &lt;= speed[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= efficiency[i] &lt;= 10^8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

本题是求“速度和”与“效率最小值”乘积的最大值。变量有两个，我们可以从大到小枚举 `efficiency[i]` 作为效率最小值，在所有效率大于等于 `efficiency[i]` 的工程师中选取不超过 $k-1$ 个，让他们速度和最大。

时间复杂度 $O(n\log n)$。

相似题目：

-   [857. 雇佣 K 名工人的最低成本](https://github.com/doocs/leetcode/blob/main/solution/0800-0899/0857.Minimum%20Cost%20to%20Hire%20K%20Workers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPerformance(
        self, n: int, speed: List[int], efficiency: List[int], k: int
    ) -> int:
        t = sorted(zip(speed, efficiency), key=lambda x: -x[1])
        ans = tot = 0
        mod = 10**9 + 7
        h = []
        for s, e in t:
            tot += s
            ans = max(ans, tot * e)
            heappush(h, s)
            if len(h) == k:
                tot -= heappop(h)
        return ans % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] t = new int[n][2];
        for (int i = 0; i < n; ++i) {
            t[i] = new int[] {speed[i], efficiency[i]};
        }
        Arrays.sort(t, (a, b) -> b[1] - a[1]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        long tot = 0;
        long ans = 0;
        for (var x : t) {
            int s = x[0], e = x[1];
            tot += s;
            ans = Math.max(ans, tot * e);
            q.offer(s);
            if (q.size() == k) {
                tot -= q.poll();
            }
        }
        return (int) (ans % MOD);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> t(n);
        for (int i = 0; i < n; ++i) t[i] = {-efficiency[i], speed[i]};
        sort(t.begin(), t.end());
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = 0, tot = 0;
        int mod = 1e9 + 7;
        for (auto& x : t) {
            int s = x.second, e = -x.first;
            tot += s;
            ans = max(ans, tot * e);
            q.push(s);
            if (q.size() == k) {
                tot -= q.top();
                q.pop();
            }
        }
        return (int) (ans % mod);
    }
};
```

#### Go

```go
func maxPerformance(n int, speed []int, efficiency []int, k int) int {
	t := make([][]int, n)
	for i, s := range speed {
		t[i] = []int{s, efficiency[i]}
	}
	sort.Slice(t, func(i, j int) bool { return t[i][1] > t[j][1] })
	var mod int = 1e9 + 7
	ans, tot := 0, 0
	pq := hp{}
	for _, x := range t {
		s, e := x[0], x[1]
		tot += s
		ans = max(ans, tot*e)
		heap.Push(&pq, s)
		if pq.Len() == k {
			tot -= heap.Pop(&pq).(int)
		}
	}
	return ans % mod
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1384. 按年度列出销售总额 🔒](https://leetcode.cn/problems/total-sales-amount-by-year){#1384}

{{< tabs "1384" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    s.product_id,
    p.product_name,
    y.YEAR report_year,
    s.average_daily_sales * (
        IF(
            YEAR(s.period_end) > y.YEAR,
            y.days_of_year,
            DAYOFYEAR(s.period_end)
        ) - IF(
            YEAR(s.period_start) < y.YEAR,
            1,
            DAYOFYEAR(s.period_start)
        ) + 1
    ) total_amount
FROM
    Sales s
    INNER JOIN (
        SELECT
            '2018' YEAR,
            365 days_of_year
        UNION
        ALL
        SELECT
            '2019' YEAR,
            365 days_of_year
        UNION
        ALL
        SELECT
            '2020' YEAR,
            366 days_of_year
    ) y ON YEAR(s.period_start) <= y.YEAR
    AND YEAR(s.period_end) >= y.YEAR
    INNER JOIN Product p ON p.product_id = s.product_id
ORDER BY
    s.product_id,
    y.YEAR
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>&nbsp;<code>Product</code>&nbsp;表：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
+---------------+---------+
product_id 是这张表的主键(具有唯一值的列)。
product_name 是产品的名称。
</pre>

<p>&nbsp;</p>

<p><code>Sales</code>&nbsp;表：</p>

<pre>
+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| product_id          | int     |
| period_start        | date    |
| period_end          | date    |
| average_daily_sales | int     |
+---------------------+---------+
product_id 是这张表的主键(具有唯一值的列)。
period_start&nbsp;和 period_end&nbsp;是该产品销售期的起始日期和结束日期，且这两个日期包含在销售期内。
average_daily_sales 列存储销售期内该产品的日平均销售额。
销售日期范围为2018年到2020年。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出每个产品每年的总销售额，并包含 <code>product_id</code> , <code>product_name</code> ,&nbsp;<code>report_year</code> 以及 <code>total_amount</code>&nbsp;。</p>

<p>返回结果并按&nbsp;<code>product_id</code> 和 <code>report_year</code><strong> 排序</strong>。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Product</code> table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 1          | LC Phone     |
| 2          | LC T-Shirt   |
| 3          | LC Keychain  |
+------------+--------------+
<code>Sales</code> table:
+------------+--------------+-------------+---------------------+
| product_id | period_start | period_end  | average_daily_sales |
+------------+--------------+-------------+---------------------+
| 1          | 2019-01-25   | 2019-02-28  | 100                 |
| 2          | 2018-12-01   | 2020-01-01  | 10                  |
| 3          | 2019-12-01   | 2020-01-31  | 1                   |
+------------+--------------+-------------+---------------------+
<strong>输出：</strong>
+------------+--------------+-------------+--------------+
| product_id | product_name | report_year | total_amount |
+------------+--------------+-------------+--------------+
| 1          | LC Phone     |    2019     | 3500         |
| 2          | LC T-Shirt   |    2018     | 310          |
| 2          | LC T-Shirt   |    2019     | 3650         |
| 2          | LC T-Shirt   |    2020     | 10           |
| 3          | LC Keychain  |    2019     | 31           |
| 3          | LC Keychain  |    2020     | 31           |
+------------+--------------+-------------+--------------+
<strong>解释：</strong>
LC Phone 在 2019-01-25 至 2019-02-28 期间销售，该产品销售时间总计35天。销售总额 35*100 = 3500。
LC T-shirt 在 2018-12-01&nbsp;至 2020-01-01 期间销售，该产品在2018年、2019年、2020年的销售时间分别是31天、365天、1天，2018年、2019年、2020年的销售总额分别是31*10=310、365*10=3650、1*10=10。
LC Keychain 在 2019-12-01&nbsp;至 2020-01-31 期间销售，该产品在2019年、2020年的销售时间分别是：31天、31天，2019年、2020年的销售总额分别是31*1=31、31*1=31。</pre>

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
# Write your MySQL query statement below
SELECT
    s.product_id,
    p.product_name,
    y.YEAR report_year,
    s.average_daily_sales * (
        IF(
            YEAR(s.period_end) > y.YEAR,
            y.days_of_year,
            DAYOFYEAR(s.period_end)
        ) - IF(
            YEAR(s.period_start) < y.YEAR,
            1,
            DAYOFYEAR(s.period_start)
        ) + 1
    ) total_amount
FROM
    Sales s
    INNER JOIN (
        SELECT
            '2018' YEAR,
            365 days_of_year
        UNION
        ALL
        SELECT
            '2019' YEAR,
            365 days_of_year
        UNION
        ALL
        SELECT
            '2020' YEAR,
            366 days_of_year
    ) y ON YEAR(s.period_start) <= y.YEAR
    AND YEAR(s.period_end) >= y.YEAR
    INNER JOIN Product p ON p.product_id = s.product_id
ORDER BY
    s.product_id,
    y.YEAR
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1385. 两个数组间的距离值](https://leetcode.cn/problems/find-the-distance-value-between-two-arrays){#1385}

{{< tabs "1385" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        ans = 0
        for x in arr1:
            i = bisect_left(arr2, x - d)
            ans += i == len(arr2) or arr2[i] > x + d
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int ans = 0;
        for (int x : arr1) {
            int i = Arrays.binarySearch(arr2, x - d);
            i = i < 0 ? -i - 1 : i;
            if (i == arr2.length || arr2[i] > x + d) {
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);
        int ans = 0;
        for (int x : arr1) {
            auto it = ranges::lower_bound(arr2, x - d);
            if (it == arr2.end() || *it > x + d) {
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
func findTheDistanceValue(arr1 []int, arr2 []int, d int) (ans int) {
	sort.Ints(arr2)
	for _, x := range arr1 {
		i := sort.SearchInts(arr2, x-d)
		if i == len(arr2) || arr2[i] > x+d {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheDistanceValue(arr1: number[], arr2: number[], d: number): number {
    arr2.sort((a, b) => a - b);
    let ans: number = 0;
    for (const x of arr1) {
        const i = _.sortedIndex(arr2, x - d);
        if (i === arr2.length || arr2[i] > x + d) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr2.sort();
        let mut ans = 0;
        for &x in &arr1 {
            let i = match arr2.binary_search(&(x - d)) {
                Ok(j) => j,
                Err(j) => j,
            };
            if i == arr2.len() || arr2[i] > x + d {
                ans += 1;
            }
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

<p>给你两个整数数组&nbsp;<code>arr1</code>&nbsp;，&nbsp;<code>arr2</code>&nbsp;和一个整数&nbsp;<code>d</code>&nbsp;，请你返回两个数组之间的&nbsp;<strong>距离值</strong>&nbsp;。</p>

<p>「<strong>距离值</strong>」<strong>&nbsp;</strong>定义为符合此距离要求的元素数目：对于元素&nbsp;<code>arr1[i]</code>&nbsp;，不存在任何元素&nbsp;<code>arr2[j]</code>&nbsp;满足 <code>|arr1[i]-arr2[j]| &lt;= d</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
<strong>输出：</strong>2
<strong>解释：</strong>
对于 arr1[0]=4 我们有：
|4-10|=6 &gt; d=2 
|4-9|=5 &gt; d=2 
|4-1|=3 &gt; d=2 
|4-8|=4 &gt; d=2 
所以 arr1[0]=4 符合距离要求

对于 arr1[1]=5 我们有：
|5-10|=5 &gt; d=2 
|5-9|=4 &gt; d=2 
|5-1|=4 &gt; d=2 
|5-8|=3 &gt; d=2
所以 arr1[1]=5 也符合距离要求

对于 arr1[2]=8 我们有：
<strong>|8-10|=2 &lt;= d=2</strong>
<strong>|8-9|=1 &lt;= d=2</strong>
|8-1|=7 &gt; d=2
<strong>|8-8|=0 &lt;= d=2</strong>
存在距离小于等于 2 的情况，不符合距离要求 

故而只有 arr1[0]=4 和 arr1[1]=5 两个符合距离要求，距离值为 2</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 500</code></li>
	<li><code>-10^3 &lt;= arr1[i], arr2[j] &lt;= 10^3</code></li>
	<li><code>0 &lt;= d &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以先对数组 $\textit{arr2}$ 排序，然后对于数组 $\textit{arr1}$ 中的每个元素 $x$，使用二分查找，找到数组 $\textit{arr2}$ 中第一个大于等于 $x - d$ 的元素，如果元素存在，且小于等于 $x + d$，则说明不符合距离要求，否则说明符合距离要求。我们将符合距离要求的元素个数累加，即为答案。

时间复杂度 $O((m + n) \times \log n)$，空间复杂度 $O(\log n)$。其中 $m$ 和 $n$ 分别是数组 $\textit{arr1}$ 和 $\textit{arr2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        arr2.sort()
        ans = 0
        for x in arr1:
            i = bisect_left(arr2, x - d)
            ans += i == len(arr2) or arr2[i] > x + d
        return ans
```

#### Java

```java
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int ans = 0;
        for (int x : arr1) {
            int i = Arrays.binarySearch(arr2, x - d);
            i = i < 0 ? -i - 1 : i;
            if (i == arr2.length || arr2[i] > x + d) {
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);
        int ans = 0;
        for (int x : arr1) {
            auto it = ranges::lower_bound(arr2, x - d);
            if (it == arr2.end() || *it > x + d) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findTheDistanceValue(arr1 []int, arr2 []int, d int) (ans int) {
	sort.Ints(arr2)
	for _, x := range arr1 {
		i := sort.SearchInts(arr2, x-d)
		if i == len(arr2) || arr2[i] > x+d {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function findTheDistanceValue(arr1: number[], arr2: number[], d: number): number {
    arr2.sort((a, b) => a - b);
    let ans: number = 0;
    for (const x of arr1) {
        const i = _.sortedIndex(arr2, x - d);
        if (i === arr2.length || arr2[i] > x + d) {
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr2.sort();
        let mut ans = 0;
        for &x in &arr1 {
            let i = match arr2.binary_search(&(x - d)) {
                Ok(j) => j,
                Err(j) => j,
            };
            if i == arr2.len() || arr2[i] > x + d {
                ans += 1;
            }
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

# [1386. 安排电影院座位](https://leetcode.cn/problems/cinema-seat-allocation){#1386}

{{< tabs "1386" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        d = defaultdict(int)
        for i, j in reservedSeats:
            d[i] |= 1 << (10 - j)
        masks = (0b0111100000, 0b0000011110, 0b0001111000)
        ans = (n - len(d)) * 2
        for x in d.values():
            for mask in masks:
                if (x & mask) == 0:
                    x |= mask
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> d = new HashMap<>();
        for (var e : reservedSeats) {
            int i = e[0], j = e[1];
            d.merge(i, 1 << (10 - j), (x, y) -> x | y);
        }
        int[] masks = {0b0111100000, 0b0000011110, 0b0001111000};
        int ans = (n - d.size()) * 2;
        for (int x : d.values()) {
            for (int mask : masks) {
                if ((x & mask) == 0) {
                    x |= mask;
                    ++ans;
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
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> d;
        for (auto& e : reservedSeats) {
            int i = e[0], j = e[1];
            d[i] |= 1 << (10 - j);
        }
        int masks[3] = {0b0111100000, 0b0000011110, 0b0001111000};
        int ans = (n - d.size()) * 2;
        for (auto& [_, x] : d) {
            for (int& mask : masks) {
                if ((x & mask) == 0) {
                    x |= mask;
                    ++ans;
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
func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	d := map[int]int{}
	for _, e := range reservedSeats {
		i, j := e[0], e[1]
		d[i] |= 1 << (10 - j)
	}
	ans := (n - len(d)) * 2
	masks := [3]int{0b0111100000, 0b0000011110, 0b0001111000}
	for _, x := range d {
		for _, mask := range masks {
			if x&mask == 0 {
				x |= mask
				ans++
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumberOfFamilies(n: number, reservedSeats: number[][]): number {
    const d: Map<number, number> = new Map();
    for (const [i, j] of reservedSeats) {
        d.set(i, (d.get(i) ?? 0) | (1 << (10 - j)));
    }
    let ans = (n - d.size) << 1;
    const masks = [0b0111100000, 0b0000011110, 0b0001111000];
    for (let [_, x] of d) {
        for (const mask of masks) {
            if ((x & mask) === 0) {
                x |= mask;
                ++ans;
            }
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

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1386.Cinema%20Seat%20Allocation/images/cinema_seats_1.png" style="height: 149px; width: 400px;" /></p>

<p>如上图所示，电影院的观影厅中有 <code>n</code>&nbsp;行座位，行编号从 1&nbsp;到 <code>n</code>&nbsp;，且每一行内总共有 10 个座位，列编号从 1 到 10 。</p>

<p>给你数组&nbsp;<code>reservedSeats</code>&nbsp;，包含所有已经被预约了的座位。比如说，<code>reservedSeats[i]=[3,8]</code>&nbsp;，它表示第&nbsp;<strong>3</strong>&nbsp;行第&nbsp;<strong>8</strong>&nbsp;个座位被预约了。</p>

<p>请你返回&nbsp;<strong>最多能安排多少个 4 人家庭</strong>&nbsp;。4 人家庭要占据&nbsp;<strong>同一行内连续&nbsp;</strong>的 4 个座位。隔着过道的座位（比方说 [3,3] 和 [3,4]）不是连续的座位，但是如果你可以将 4 人家庭拆成过道两边各坐 2 人，这样子是允许的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1386.Cinema%20Seat%20Allocation/images/cinema_seats_3.png" style="height: 96px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
<strong>输出：</strong>4
<strong>解释：</strong>上图所示是最优的安排方案，总共可以安排 4 个家庭。蓝色的叉表示被预约的座位，橙色的连续座位表示一个 4 人家庭。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats.length &lt;= min(10*n, 10^4)</code></li>
	<li><code>reservedSeats[i].length == 2</code></li>
	<li><code>1&nbsp;&lt;=&nbsp;reservedSeats[i][0] &lt;= n</code></li>
	<li><code>1 &lt;=&nbsp;reservedSeats[i][1] &lt;= 10</code></li>
	<li>所有&nbsp;<code>reservedSeats[i]</code> 都是互不相同的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 状态压缩

我们用哈希表 $d$ 来存储所有已经被预约的座位，其中键为行号，值为该行上已经被预约的座位的状态，即一个二进制数，第 $j$ 位为 $1$ 表示第 $j$ 个座位已经被预约，为 $0$ 表示第 $j$ 个座位尚未被预约。

我们遍历 $reservedSeats$，对于每个座位 $(i, j)$，将第 $j$ 个座位（对应低位的第 $10-j$ 位）的状态加入到 $d[i]$ 中即可。

对于没有出现在哈希表 $d$ 中的行，我们可以任意安排 $2$ 个家庭，因此，初始答案为 $(n - len(d)) \times 2$。

接下来，我们遍历哈希表中每一行的状态，对于每一行，我们依次尝试安排 $1234, 5678, 3456$ 这几种情况，如果某种情况可以安排，我们就将答案加 $1$。

遍历结束后，我们就得到了最终的答案。

时间复杂度 $O(m)$，空间复杂度 $O(m)$，其中 $m$ 是 $reservedSeats$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        d = defaultdict(int)
        for i, j in reservedSeats:
            d[i] |= 1 << (10 - j)
        masks = (0b0111100000, 0b0000011110, 0b0001111000)
        ans = (n - len(d)) * 2
        for x in d.values():
            for mask in masks:
                if (x & mask) == 0:
                    x |= mask
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> d = new HashMap<>();
        for (var e : reservedSeats) {
            int i = e[0], j = e[1];
            d.merge(i, 1 << (10 - j), (x, y) -> x | y);
        }
        int[] masks = {0b0111100000, 0b0000011110, 0b0001111000};
        int ans = (n - d.size()) * 2;
        for (int x : d.values()) {
            for (int mask : masks) {
                if ((x & mask) == 0) {
                    x |= mask;
                    ++ans;
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
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> d;
        for (auto& e : reservedSeats) {
            int i = e[0], j = e[1];
            d[i] |= 1 << (10 - j);
        }
        int masks[3] = {0b0111100000, 0b0000011110, 0b0001111000};
        int ans = (n - d.size()) * 2;
        for (auto& [_, x] : d) {
            for (int& mask : masks) {
                if ((x & mask) == 0) {
                    x |= mask;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	d := map[int]int{}
	for _, e := range reservedSeats {
		i, j := e[0], e[1]
		d[i] |= 1 << (10 - j)
	}
	ans := (n - len(d)) * 2
	masks := [3]int{0b0111100000, 0b0000011110, 0b0001111000}
	for _, x := range d {
		for _, mask := range masks {
			if x&mask == 0 {
				x |= mask
				ans++
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxNumberOfFamilies(n: number, reservedSeats: number[][]): number {
    const d: Map<number, number> = new Map();
    for (const [i, j] of reservedSeats) {
        d.set(i, (d.get(i) ?? 0) | (1 << (10 - j)));
    }
    let ans = (n - d.size) << 1;
    const masks = [0b0111100000, 0b0000011110, 0b0001111000];
    for (let [_, x] of d) {
        for (const mask of masks) {
            if ((x & mask) === 0) {
                x |= mask;
                ++ans;
            }
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

# [1387. 将整数按权重排序](https://leetcode.cn/problems/sort-integers-by-the-power-value){#1387}

{{< tabs "1387" >}}

{{% tab "python" %}}
```python
@cache
def f(x: int) -> int:
    ans = 0
    while x != 1:
        if x % 2 == 0:
            x //= 2
        else:
            x = 3 * x + 1
        ans += 1
    return ans


class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        return sorted(range(lo, hi + 1), key=f)[k - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getKth(int lo, int hi, int k) {
        Integer[] nums = new Integer[hi - lo + 1];
        for (int i = lo; i <= hi; ++i) {
            nums[i - lo] = i;
        }
        Arrays.sort(nums, (a, b) -> {
            int fa = f(a), fb = f(b);
            return fa == fb ? a - b : fa - fb;
        });
        return nums[k - 1];
    }

    private int f(int x) {
        int ans = 0;
        for (; x != 1; ++ans) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x = x * 3 + 1;
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
    int getKth(int lo, int hi, int k) {
        auto f = [](int x) {
            int ans = 0;
            for (; x != 1; ++ans) {
                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
            }
            return ans;
        };
        vector<int> nums;
        for (int i = lo; i <= hi; ++i) {
            nums.push_back(i);
        }
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            int fx = f(x), fy = f(y);
            if (fx != fy) {
                return fx < fy;
            } else {
                return x < y;
            }
        });
        return nums[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getKth(lo int, hi int, k int) int {
	f := func(x int) (ans int) {
		for ; x != 1; ans++ {
			if x%2 == 0 {
				x /= 2
			} else {
				x = 3*x + 1
			}
		}
		return
	}
	nums := make([]int, hi-lo+1)
	for i := range nums {
		nums[i] = lo + i
	}
	sort.Slice(nums, func(i, j int) bool {
		fx, fy := f(nums[i]), f(nums[j])
		if fx != fy {
			return fx < fy
		}
		return nums[i] < nums[j]
	})
	return nums[k-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getKth(lo: number, hi: number, k: number): number {
    const f = (x: number): number => {
        let ans = 0;
        for (; x !== 1; ++ans) {
            if (x % 2 === 0) {
                x >>= 1;
            } else {
                x = x * 3 + 1;
            }
        }
        return ans;
    };
    const nums = new Array(hi - lo + 1).fill(0).map((_, i) => i + lo);
    nums.sort((a, b) => {
        const fa = f(a),
            fb = f(b);
        return fa === fb ? a - b : fa - fb;
    });
    return nums[k - 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_kth(lo: i32, hi: i32, k: i32) -> i32 {
        let f = |mut x: i32| -> i32 {
            let mut ans = 0;
            while x != 1 {
                if x % 2 == 0 {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
                ans += 1;
            }
            ans
        };

        let mut nums: Vec<i32> = (lo..=hi).collect();
        nums.sort_by(|&x, &y| f(x).cmp(&f(y)));
        nums[(k - 1) as usize]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们将整数 <code>x</code>&nbsp;的 <strong>权重</strong> 定义为按照下述规则将 <code>x</code>&nbsp;变成 <code>1</code>&nbsp;所需要的步数：</p>

<ul>
	<li>如果&nbsp;<code>x</code>&nbsp;是偶数，那么&nbsp;<code>x = x / 2</code></li>
	<li>如果&nbsp;<code>x</code>&nbsp;是奇数，那么&nbsp;<code>x = 3 * x + 1</code></li>
</ul>

<p>比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --&gt; 10 --&gt; 5 --&gt; 16 --&gt; 8 --&gt; 4 --&gt; 2 --&gt; 1）。</p>

<p>给你三个整数&nbsp;<code>lo</code>，&nbsp;<code>hi</code> 和&nbsp;<code>k</code>&nbsp;。你的任务是将区间&nbsp;<code>[lo, hi]</code>&nbsp;之间的整数按照它们的权重&nbsp;<strong>升序排序&nbsp;</strong>，如果大于等于 2 个整数有&nbsp;<strong>相同</strong>&nbsp;的权重，那么按照数字自身的数值&nbsp;<strong>升序排序</strong>&nbsp;。</p>

<p>请你返回区间&nbsp;<code>[lo, hi]</code>&nbsp;之间的整数按权重排序后的第&nbsp;<code>k</code>&nbsp;个数。</p>

<p>注意，题目保证对于任意整数&nbsp;<code>x</code>&nbsp;<code>（lo &lt;= x &lt;= hi）</code>&nbsp;，它变成&nbsp;<code>1</code> 所需要的步数是一个 32 位有符号整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>lo = 12, hi = 15, k = 2
<strong>输出：</strong>13
<strong>解释：</strong>12 的权重为 9（12 --&gt; 6 --&gt; 3 --&gt; 10 --&gt; 5 --&gt; 16 --&gt; 8 --&gt; 4 --&gt; 2 --&gt; 1）
13 的权重为 9
14 的权重为 17
15 的权重为 17
区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>lo = 7, hi = 11, k = 4
<strong>输出：</strong>7
<strong>解释：</strong>区间内整数 [7, 8, 9, 10, 11] 对应的权重为 [16, 3, 19, 6, 14] 。
按权重排序后得到的结果为 [8, 10, 11, 7, 9] 。
排序后数组中第 4 个数字为 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= lo &lt;= hi &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= hi - lo + 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们先定义一个函数 $\textit{f}(x)$，表示将数字 $x$ 变成 $1$ 所需要的步数，也即是数字 $x$ 的权重。

然后我们将区间 $[\textit{lo}, \textit{hi}]$ 内的所有数字按照权重升序排序，如果权重相同，按照数字自身的数值升序排序。

最后返回排序后的第 $k$ 个数字。

时间复杂度 $O(n \times \log n \times M)$，空间复杂度 $O(n)$。其中 $n$ 是区间 $[\textit{lo}, \textit{hi}]$ 内的数字个数，而 $M$ 是 $f(x)$ 的最大值，本题中 $M$ 最大为 $178$。

<!-- tabs:start -->

#### Python3

```python
@cache
def f(x: int) -> int:
    ans = 0
    while x != 1:
        if x % 2 == 0:
            x //= 2
        else:
            x = 3 * x + 1
        ans += 1
    return ans


class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        return sorted(range(lo, hi + 1), key=f)[k - 1]
```

#### Java

```java
class Solution {
    public int getKth(int lo, int hi, int k) {
        Integer[] nums = new Integer[hi - lo + 1];
        for (int i = lo; i <= hi; ++i) {
            nums[i - lo] = i;
        }
        Arrays.sort(nums, (a, b) -> {
            int fa = f(a), fb = f(b);
            return fa == fb ? a - b : fa - fb;
        });
        return nums[k - 1];
    }

    private int f(int x) {
        int ans = 0;
        for (; x != 1; ++ans) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x = x * 3 + 1;
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
    int getKth(int lo, int hi, int k) {
        auto f = [](int x) {
            int ans = 0;
            for (; x != 1; ++ans) {
                if (x % 2 == 0) {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
            }
            return ans;
        };
        vector<int> nums;
        for (int i = lo; i <= hi; ++i) {
            nums.push_back(i);
        }
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            int fx = f(x), fy = f(y);
            if (fx != fy) {
                return fx < fy;
            } else {
                return x < y;
            }
        });
        return nums[k - 1];
    }
};
```

#### Go

```go
func getKth(lo int, hi int, k int) int {
	f := func(x int) (ans int) {
		for ; x != 1; ans++ {
			if x%2 == 0 {
				x /= 2
			} else {
				x = 3*x + 1
			}
		}
		return
	}
	nums := make([]int, hi-lo+1)
	for i := range nums {
		nums[i] = lo + i
	}
	sort.Slice(nums, func(i, j int) bool {
		fx, fy := f(nums[i]), f(nums[j])
		if fx != fy {
			return fx < fy
		}
		return nums[i] < nums[j]
	})
	return nums[k-1]
}
```

#### TypeScript

```ts
function getKth(lo: number, hi: number, k: number): number {
    const f = (x: number): number => {
        let ans = 0;
        for (; x !== 1; ++ans) {
            if (x % 2 === 0) {
                x >>= 1;
            } else {
                x = x * 3 + 1;
            }
        }
        return ans;
    };
    const nums = new Array(hi - lo + 1).fill(0).map((_, i) => i + lo);
    nums.sort((a, b) => {
        const fa = f(a),
            fb = f(b);
        return fa === fb ? a - b : fa - fb;
    });
    return nums[k - 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn get_kth(lo: i32, hi: i32, k: i32) -> i32 {
        let f = |mut x: i32| -> i32 {
            let mut ans = 0;
            while x != 1 {
                if x % 2 == 0 {
                    x /= 2;
                } else {
                    x = 3 * x + 1;
                }
                ans += 1;
            }
            ans
        };

        let mut nums: Vec<i32> = (lo..=hi).collect();
        nums.sort_by(|&x, &y| f(x).cmp(&f(y)));
        nums[(k - 1) as usize]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1388. 3n 块披萨](https://leetcode.cn/problems/pizza-with-3n-slices){#1388}

{{< tabs "1388" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        def g(nums: List[int]) -> int:
            m = len(nums)
            f = [[0] * (n + 1) for _ in range(m + 1)]
            for i in range(1, m + 1):
                for j in range(1, n + 1):
                    f[i][j] = max(
                        f[i - 1][j], (f[i - 2][j - 1] if i >= 2 else 0) + nums[i - 1]
                    )
            return f[m][n]

        n = len(slices) // 3
        a, b = g(slices[:-1]), g(slices[1:])
        return max(a, b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int maxSizeSlices(int[] slices) {
        n = slices.length / 3;
        int[] nums = new int[slices.length - 1];
        System.arraycopy(slices, 1, nums, 0, nums.length);
        int a = g(nums);
        System.arraycopy(slices, 0, nums, 0, nums.length);
        int b = g(nums);
        return Math.max(a, b);
    }

    private int g(int[] nums) {
        int m = nums.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = Math.max(f[i - 1][j], (i >= 2 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        auto g = [&](vector<int>& nums) -> int {
            int m = nums.size();
            int f[m + 1][n + 1];
            memset(f, 0, sizeof f);
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    f[i][j] = max(f[i - 1][j], (i >= 2 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
                }
            }
            return f[m][n];
        };
        vector<int> nums(slices.begin(), slices.end() - 1);
        int a = g(nums);
        nums = vector<int>(slices.begin() + 1, slices.end());
        int b = g(nums);
        return max(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSizeSlices(slices []int) int {
	n := len(slices) / 3
	g := func(nums []int) int {
		m := len(nums)
		f := make([][]int, m+1)
		for i := range f {
			f[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				f[i][j] = max(f[i-1][j], nums[i-1])
				if i >= 2 {
					f[i][j] = max(f[i][j], f[i-2][j-1]+nums[i-1])
				}
			}
		}
		return f[m][n]
	}
	a, b := g(slices[:len(slices)-1]), g(slices[1:])
	return max(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSizeSlices(slices: number[]): number {
    const n = Math.floor(slices.length / 3);
    const g = (nums: number[]): number => {
        const m = nums.length;
        const f: number[][] = Array(m + 1)
            .fill(0)
            .map(() => Array(n + 1).fill(0));
        for (let i = 1; i <= m; ++i) {
            for (let j = 1; j <= n; ++j) {
                f[i][j] = Math.max(f[i - 1][j], (i > 1 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
            }
        }
        return f[m][n];
    };
    const a = g(slices.slice(0, -1));
    const b = g(slices.slice(1));
    return Math.max(a, b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：</p>

<ul>
	<li>你挑选 <strong>任意</strong>&nbsp;一块披萨。</li>
	<li>Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。</li>
	<li>Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。</li>
	<li>重复上述过程直到没有披萨剩下。</li>
</ul>

<p>每一块披萨的大小按顺时针方向由循环数组 <code>slices</code>&nbsp;表示。</p>

<p>请你返回你可以获得的披萨大小总和的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1388.Pizza%20With%203n%20Slices/images/sample_3_1723.png" style="height: 240px; width: 475px;" /></p>

<pre>
<strong>输入：</strong>slices = [1,2,3,4,5,6]
<strong>输出：</strong>10
<strong>解释：</strong>选择大小为 4 的披萨，Alice 和 Bob 分别挑选大小为 3 和 5 的披萨。然后你选择大小为 6 的披萨，Alice 和 Bob 分别挑选大小为 2 和 1 的披萨。你获得的披萨总大小为 4 + 6 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1388.Pizza%20With%203n%20Slices/images/sample_4_1723.png" style="height: 250px; width: 475px;" /></strong></p>

<pre>
<strong>输入：</strong>slices = [8,9,8,6,1,1]
<strong>输出：</strong>16
<strong>解释：</strong>两轮都选大小为 8 的披萨。如果你选择大小为 9 的披萨，你的朋友们就会选择大小为 8 的披萨，这种情况下你的总和不是最大的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= slices.length &lt;= 500</code></li>
	<li><code>slices.length % 3 == 0</code></li>
	<li><code>1 &lt;= slices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们可以将这个问题转化为：在一个长度为 $3n$ 的环形数组中，选择其中 $n$ 个不相邻的数，使得这 $n$ 个数的和最大。

证明如下：

-   当 $n = 1$ 时，我们可以选择数组中的任意一个数。
-   当 $n \gt 1$ 时，那么一定存在一个数，使得它的某一侧有两个连续的数没有被选择，而另一侧至少有一个数没有被选择。因此，我们可以将这个数和它两侧的数一起从数组中删除，然后剩下的 $3(n - 1)$ 个数构成一个新的环形数组。问题规模缩小成了在长度为 $3(n - 1)$ 的环形数组中选择 $n - 1$ 个不相邻的数，使得这 $n - 1$ 个数的和最大。

因此，我们需要求解的问题可以转化为：在一个长度为 $3n$ 的环形数组中，选择其中 $n$ 个不相邻的数，使得这 $n$ 个数的和最大。

环形数组中，如果选择了第一个数，那么最后一个数就不能选择，如果选择了最后一个数，那么第一个数就不能选择，因此我们可以将环形数组拆成两个数组，一个是去掉第一个数的，一个是去掉最后一个数的，然后分别求解这两个数组的最大值，最后取两个最大值中的较大值即可。

我们用一个函数 $g(nums)$，表示在数组 $nums$ 中选择 $n$ 个不相邻的数，使得这 $n$ 个数的和最大，那么我们的目标就是求 $g(slices)$ 和 $g(slices[1:])$ 中的较大值。

函数 $g(nums)$ 的求解方法如下：

我们记数组 $nums$ 的长度为 $m$，定义 $f[i][j]$ 表示在数组 $nums$ 的前 $i$ 个数中选择 $j$ 个不相邻的数的最大和。

考虑 $f[i][j]$，如果我们不选择第 $i$ 个数，那么 $f[i][j] = f[i - 1][j]$，如果我们选择第 $i$ 个数，那么 $f[i][j] = f[i - 2][j - 1] + nums[i - 1]$，因此我们可以得到状态转移方程：

$$
f[i][j] = \max(f[i - 1][j], f[i - 2][j - 1] + nums[i - 1])
$$

最后返回 $f[m][n]$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $slices$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        def g(nums: List[int]) -> int:
            m = len(nums)
            f = [[0] * (n + 1) for _ in range(m + 1)]
            for i in range(1, m + 1):
                for j in range(1, n + 1):
                    f[i][j] = max(
                        f[i - 1][j], (f[i - 2][j - 1] if i >= 2 else 0) + nums[i - 1]
                    )
            return f[m][n]

        n = len(slices) // 3
        a, b = g(slices[:-1]), g(slices[1:])
        return max(a, b)
```

#### Java

```java
class Solution {
    private int n;

    public int maxSizeSlices(int[] slices) {
        n = slices.length / 3;
        int[] nums = new int[slices.length - 1];
        System.arraycopy(slices, 1, nums, 0, nums.length);
        int a = g(nums);
        System.arraycopy(slices, 0, nums, 0, nums.length);
        int b = g(nums);
        return Math.max(a, b);
    }

    private int g(int[] nums) {
        int m = nums.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = Math.max(f[i - 1][j], (i >= 2 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        auto g = [&](vector<int>& nums) -> int {
            int m = nums.size();
            int f[m + 1][n + 1];
            memset(f, 0, sizeof f);
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    f[i][j] = max(f[i - 1][j], (i >= 2 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
                }
            }
            return f[m][n];
        };
        vector<int> nums(slices.begin(), slices.end() - 1);
        int a = g(nums);
        nums = vector<int>(slices.begin() + 1, slices.end());
        int b = g(nums);
        return max(a, b);
    }
};
```

#### Go

```go
func maxSizeSlices(slices []int) int {
	n := len(slices) / 3
	g := func(nums []int) int {
		m := len(nums)
		f := make([][]int, m+1)
		for i := range f {
			f[i] = make([]int, n+1)
		}
		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				f[i][j] = max(f[i-1][j], nums[i-1])
				if i >= 2 {
					f[i][j] = max(f[i][j], f[i-2][j-1]+nums[i-1])
				}
			}
		}
		return f[m][n]
	}
	a, b := g(slices[:len(slices)-1]), g(slices[1:])
	return max(a, b)
}
```

#### TypeScript

```ts
function maxSizeSlices(slices: number[]): number {
    const n = Math.floor(slices.length / 3);
    const g = (nums: number[]): number => {
        const m = nums.length;
        const f: number[][] = Array(m + 1)
            .fill(0)
            .map(() => Array(n + 1).fill(0));
        for (let i = 1; i <= m; ++i) {
            for (let j = 1; j <= n; ++j) {
                f[i][j] = Math.max(f[i - 1][j], (i > 1 ? f[i - 2][j - 1] : 0) + nums[i - 1]);
            }
        }
        return f[m][n];
    };
    const a = g(slices.slice(0, -1));
    const b = g(slices.slice(1));
    return Math.max(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1389. 按既定顺序创建目标数组](https://leetcode.cn/problems/create-target-array-in-the-given-order){#1389}

{{< tabs "1389" >}}

{{% tab "python" %}}
```python
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for x, i in zip(nums, index):
            target.insert(i, x)
        return target
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        List<Integer> target = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            target.add(index[i], nums[i]);
        }
        // return target.stream().mapToInt(i -> i).toArray();
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = target.get(i);
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
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for (int i = 0; i < nums.size(); ++i) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func createTargetArray(nums []int, index []int) []int {
	target := make([]int, len(nums))
	for i, x := range nums {
		copy(target[index[i]+1:], target[index[i]:])
		target[index[i]] = x
	}
	return target
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function createTargetArray(nums: number[], index: number[]): number[] {
    const ans: number[] = [];
    for (let i = 0; i < nums.length; i++) {
        ans.splice(index[i], 0, nums[i]);
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

<p>给你两个整数数组 <code>nums</code> 和 <code>index</code>。你需要按照以下规则创建目标数组：</p>

<ul>
	<li>目标数组 <code>target</code> 最初为空。</li>
	<li>按从左到右的顺序依次读取 <code>nums[i]</code> 和 <code>index[i]</code>，在 <code>target</code> 数组中的下标 <code>index[i]</code> 处插入值 <code>nums[i]</code> 。</li>
	<li>重复上一步，直到在 <code>nums</code> 和 <code>index</code> 中都没有要读取的元素。</li>
</ul>

<p>请你返回目标数组。</p>

<p>题目保证数字插入位置总是存在。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2,3,4], index = [0,1,2,2,1]
<strong>输出：</strong>[0,4,1,3,2]
<strong>解释：</strong>
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,0], index = [0,1,2,3,0]
<strong>输出：</strong>[0,1,2,3,4]
<strong>解释：</strong>
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1], index = [0]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, index.length &lt;= 100</code></li>
	<li><code>nums.length == index.length</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>0 &lt;= index[i] &lt;= i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们创建一个列表 $target$，用于存储目标数组。由于题目保证数字插入位置总是存在，因此我们可以直接按照给定的顺序插入到对应的位置。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for x, i in zip(nums, index):
            target.insert(i, x)
        return target
```

#### Java

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        List<Integer> target = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            target.add(index[i], nums[i]);
        }
        // return target.stream().mapToInt(i -> i).toArray();
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = target.get(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for (int i = 0; i < nums.size(); ++i) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};
```

#### Go

```go
func createTargetArray(nums []int, index []int) []int {
	target := make([]int, len(nums))
	for i, x := range nums {
		copy(target[index[i]+1:], target[index[i]:])
		target[index[i]] = x
	}
	return target
}
```

#### TypeScript

```ts
function createTargetArray(nums: number[], index: number[]): number[] {
    const ans: number[] = [];
    for (let i = 0; i < nums.length; i++) {
        ans.splice(index[i], 0, nums[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

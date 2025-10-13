---
title: "0620_有趣的电影"
date: 2025-10-08T18:36:23+08:00
weight: 3
tags: [二叉树, 动态规划, 哈希表, 堆（优先队列）, 广度优先搜索, 排序, 数学, 数据库, 数组, 树, 深度优先搜索, 计数, 设计, 贪心, 链表, 队列]
---

{{< markmap >}}
### [0620_有趣的电影](#620)
#### [数据库](#620)
### [0621_任务调度器](#621)
#### [贪心](#621)
#### [数组](#621)
#### [哈希表](#621)
#### [计数](#621)
#### [排序](#621)
#### [堆（优先队列）](#621)
### [0622_设计循环队列](#622)
#### [设计](#622)
#### [队列](#622)
#### [数组](#622)
#### [链表](#622)
### [0623_在二叉树中增加一行](#623)
#### [树](#623)
#### [深度优先搜索](#623)
#### [广度优先搜索](#623)
#### [二叉树](#623)
### [0624_数组列表中的最大距离](#624)
#### [贪心](#624)
#### [数组](#624)
### [0625_最小因式分解 🔒](#625)
#### [贪心](#625)
#### [数学](#625)
### [0626_换座位](#626)
#### [数据库](#626)
### [0627_变更性别](#627)
#### [数据库](#627)
### [0628_三个数的最大乘积](#628)
#### [数组](#628)
#### [数学](#628)
#### [排序](#628)
### [0629_K 个逆序对数组](#629)
#### [动态规划](#629)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0620_有趣的电影
___
#### 数据库
---
### 0621_任务调度器
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
___
#### 堆（优先队列）
---
### 0622_设计循环队列
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 链表
---
### 0623_在二叉树中增加一行
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0624_数组列表中的最大距离
___
#### 贪心
___
#### 数组
---
### 0625_最小因式分解 🔒
___
#### 贪心
___
#### 数学
---
### 0626_换座位
___
#### 数据库
---
### 0627_变更性别
___
#### 数据库
---
### 0628_三个数的最大乘积
___
#### 数组
___
#### 数学
___
#### 排序
---
### 0629_K 个逆序对数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 哈希表 |
| 堆（优先队列） | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 树 | 深度优先搜索 | 计数 |
| 设计 | 贪心 | 链表 |
| 队列 |  |  |

# [620. 有趣的电影](https://leetcode.cn/problems/not-boring-movies){#620}

{{< tabs "620" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE description != 'boring' AND id & 1 = 1
ORDER BY 4 DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>cinema</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| id             | int      |
| movie          | varchar  |
| description    | varchar  |
| rating         | float    |
+----------------+----------+
id 是该表的主键(具有唯一值的列)。
每行包含有关电影名称、类型和评级的信息。
评级为 [0,10] 范围内的小数点后 2 位浮点数。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出所有影片描述为&nbsp;<strong>非</strong>&nbsp;<code>boring</code>&nbsp;(不无聊)&nbsp;的并且<strong> id 为奇数&nbsp;</strong>的影片。</p>

<p>返回结果按&nbsp;<code>rating</code>&nbsp;<strong>降序排列</strong>。</p>

<p>结果格式如下示例。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   1     | War       |   great 3D   |   8.9     |
|   2     | Science   |   fiction    |   8.5     |
|   3     | irish     |   boring     |   6.2     |
|   4     | Ice song  |   Fantacy    |   8.6     |
|   5     | House card|   Interesting|   9.1     |
<strong>+---------+-----------+--------------+-----------+
输出：</strong>
+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   5     | House card|   Interesting|   9.1     |
|   1     | War       |   great 3D   |   8.9     |
+---------+-----------+--------------+-----------+
<strong>解释：</strong>
我们有三部电影，它们的 id 是奇数:1、3 和 5。id = 3 的电影是 boring 的，所以我们不把它包括在答案中。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件筛选 + 排序

我们可以使用 `WHERE` 子句筛选出 `description` 不为 `boring`，并且 `id` 为奇数的记录，然后使用 `ORDER BY` 子句对结果按照 `rating` 降序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE description != 'boring' AND id & 1 = 1
ORDER BY 4 DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [621. 任务调度器](https://leetcode.cn/problems/task-scheduler){#621}

{{< tabs "621" >}}

{{% tab "python" %}}
```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = Counter(tasks)
        x = max(cnt.values())
        s = sum(v == x for v in cnt.values())
        return max(len(tasks), (x - 1) * (n + 1) + s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        int x = 0;
        for (char c : tasks) {
            c -= 'A';
            ++cnt[c];
            x = Math.max(x, cnt[c]);
        }
        int s = 0;
        for (int v : cnt) {
            if (v == x) {
                ++s;
            }
        }
        return Math.max(tasks.length, (x - 1) * (n + 1) + s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int x = 0;
        for (char c : tasks) {
            c -= 'A';
            ++cnt[c];
            x = max(x, cnt[c]);
        }
        int s = 0;
        for (int v : cnt) {
            s += v == x;
        }
        return max((int) tasks.size(), (x - 1) * (n + 1) + s);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func leastInterval(tasks []byte, n int) int {
	cnt := make([]int, 26)
	x := 0
	for _, c := range tasks {
		c -= 'A'
		cnt[c]++
		x = max(x, cnt[c])
	}
	s := 0
	for _, v := range cnt {
		if v == x {
			s++
		}
	}
	return max(len(tasks), (x-1)*(n+1)+s)
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        int x = 0;
        foreach (char c in tasks) {
            cnt[c - 'A']++;
            x = Math.Max(x, cnt[c - 'A']);
        }
        int s = 0;
        foreach (int v in cnt) {
            s = v == x ? s + 1 : s;
        }
        return Math.Max(tasks.Length, (x - 1) * (n + 1) + s);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个用字符数组&nbsp;<code>tasks</code> 表示的 CPU 需要执行的任务列表，用字母 A 到 Z 表示，以及一个冷却时间 <code>n</code>。每个周期或时间间隔允许完成一项任务。任务可以按任何顺序完成，但有一个限制：两个<strong> 相同种类</strong> 的任务之间必须有长度为<strong>&nbsp;</strong><code>n</code><strong> </strong>的冷却时间。</p>

<p>返回完成所有任务所需要的<strong> 最短时间间隔</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block"><strong>输入：</strong>tasks = ["A","A","A","B","B","B"], n = 2</div>

<div class="example-block"><strong>输出：</strong>8</div>

<div class="example-block"><strong>解释：</strong></div>

<div class="example-block">在完成任务 A 之后，你必须等待两个间隔。对任务 B 来说也是一样。在第 3 个间隔，A 和 B 都不能完成，所以你需要待命。在第 4 个间隔，由于已经经过了 2 个间隔，你可以再次执行 A 任务。</div>

<div class="example-block">&nbsp;</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><b>输入：</b>tasks = ["A","C","A","B","D","B"], n = 1</p>

<p><b>输出：</b>6</p>

<p><b>解释：</b>一种可能的序列是：A -&gt; B -&gt; C -&gt; D -&gt; A -&gt; B。</p>

<p>由于冷却间隔为 1，你可以在完成另一个任务后重复执行这个任务。</p>
</div>

<p><strong>示例 3：</strong></p>

<div class="example-block"><strong>输入：</strong>tasks = ["A","A","A","B","B","B"], n = 3</div>

<div class="example-block"><strong>输出：</strong>10</div>

<div class="example-block"><strong>解释：</strong>一种可能的序列为：A -&gt; B -&gt; idle -&gt; idle -&gt; A -&gt; B -&gt; idle -&gt; idle -&gt; A -&gt; B。</div>

<div class="example-block">只有两种任务类型，A 和 B，需要被 3 个间隔分割。这导致重复执行这些任务的间隔当中有两次待命状态。</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>4</sup></code></li>
	<li><code>tasks[i]</code> 是大写英文字母</li>
	<li><code>0 &lt;= n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

不妨设 $m$ 是任务的个数，统计每种任务出现的次数，记录在数组 `cnt` 中。

假设出现次数最多的任务为 `A`，出现次数为 $x$，则至少需要 $(x-1)\times(n+1) + 1$ 个时间单位才能安排完所有任务。如果出现次数最多的任务有 $s$ 个，则需要再加上出现次数最多的任务的个数。

答案是 $\max ((x-1) \times(n+1)+s, m)$。

时间复杂度 $O(m+|\Sigma|)$。其中 $|\Sigma|$ 是任务的种类数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt = Counter(tasks)
        x = max(cnt.values())
        s = sum(v == x for v in cnt.values())
        return max(len(tasks), (x - 1) * (n + 1) + s)
```

#### Java

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        int x = 0;
        for (char c : tasks) {
            c -= 'A';
            ++cnt[c];
            x = Math.max(x, cnt[c]);
        }
        int s = 0;
        for (int v : cnt) {
            if (v == x) {
                ++s;
            }
        }
        return Math.max(tasks.length, (x - 1) * (n + 1) + s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int x = 0;
        for (char c : tasks) {
            c -= 'A';
            ++cnt[c];
            x = max(x, cnt[c]);
        }
        int s = 0;
        for (int v : cnt) {
            s += v == x;
        }
        return max((int) tasks.size(), (x - 1) * (n + 1) + s);
    }
};
```

#### Go

```go
func leastInterval(tasks []byte, n int) int {
	cnt := make([]int, 26)
	x := 0
	for _, c := range tasks {
		c -= 'A'
		cnt[c]++
		x = max(x, cnt[c])
	}
	s := 0
	for _, v := range cnt {
		if v == x {
			s++
		}
	}
	return max(len(tasks), (x-1)*(n+1)+s)
}
```

#### C#

```cs
public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        int[] cnt = new int[26];
        int x = 0;
        foreach (char c in tasks) {
            cnt[c - 'A']++;
            x = Math.Max(x, cnt[c - 'A']);
        }
        int s = 0;
        foreach (int v in cnt) {
            s = v == x ? s + 1 : s;
        }
        return Math.Max(tasks.Length, (x - 1) * (n + 1) + s);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [622. 设计循环队列](https://leetcode.cn/problems/design-circular-queue){#622}

{{< tabs "622" >}}

{{% tab "python" %}}
```python
class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [0] * k
        self.size = 0
        self.capacity = k
        self.front = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.q[(self.front + self.size) % self.capacity] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def Front(self) -> int:
        return -1 if self.isEmpty() else self.q[self.front]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[(self.front + self.size - 1) % self.capacity]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyCircularQueue {
    private int[] q;
    private int front;
    private int size;
    private int capacity;

    public MyCircularQueue(int k) {
        q = new int[k];
        capacity = k;
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyCircularQueue {
private:
    int front;
    int size;
    int capacity;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q = vector<int>(k);
        front = size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyCircularQueue struct {
	front    int
	size     int
	capacity int
	q        []int
}

func Constructor(k int) MyCircularQueue {
	q := make([]int, k)
	return MyCircularQueue{0, 0, k, q}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	idx := (this.front + this.size) % this.capacity
	this.q[idx] = value
	this.size++
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1) % this.capacity
	this.size--
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[this.front]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	idx := (this.front + this.size - 1) % this.capacity
	return this.q[idx]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularQueue) IsFull() bool {
	return this.size == this.capacity
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyCircularQueue {
    private queue: number[];
    private left: number;
    private right: number;
    private capacity: number;

    constructor(k: number) {
        this.queue = new Array(k);
        this.left = 0;
        this.right = 0;
        this.capacity = k;
    }

    enQueue(value: number): boolean {
        if (this.isFull()) {
            return false;
        }
        this.queue[this.right % this.capacity] = value;
        this.right++;
        return true;
    }

    deQueue(): boolean {
        if (this.isEmpty()) {
            return false;
        }
        this.left++;
        return true;
    }

    Front(): number {
        if (this.isEmpty()) {
            return -1;
        }
        return this.queue[this.left % this.capacity];
    }

    Rear(): number {
        if (this.isEmpty()) {
            return -1;
        }
        return this.queue[(this.right - 1) % this.capacity];
    }

    isEmpty(): boolean {
        return this.right - this.left === 0;
    }

    isFull(): boolean {
        return this.right - this.left === this.capacity;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct MyCircularQueue {
    q: Vec<i32>,
    size: usize,
    capacity: usize,
    front: usize,
}

impl MyCircularQueue {
    fn new(k: i32) -> Self {
        MyCircularQueue {
            q: vec![0; k as usize],
            size: 0,
            capacity: k as usize,
            front: 0,
        }
    }

    fn en_queue(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }
        let rear = (self.front + self.size) % self.capacity;
        self.q[rear] = value;
        self.size += 1;
        true
    }

    fn de_queue(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        self.front = (self.front + 1) % self.capacity;
        self.size -= 1;
        true
    }

    fn front(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            self.q[self.front]
        }
    }

    fn rear(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            let rear = (self.front + self.size - 1) % self.capacity;
            self.q[rear]
        }
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn is_full(&self) -> bool {
        self.size == self.capacity
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为&ldquo;环形缓冲器&rdquo;。</p>

<p>循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。</p>

<p>你的实现应该支持如下操作：</p>

<ul>
	<li><code>MyCircularQueue(k)</code>: 构造器，设置队列长度为 k 。</li>
	<li><code>Front</code>: 从队首获取元素。如果队列为空，返回 -1 。</li>
	<li><code>Rear</code>: 获取队尾元素。如果队列为空，返回 -1 。</li>
	<li><code>enQueue(value)</code>: 向循环队列插入一个元素。如果成功插入则返回真。</li>
	<li><code>deQueue()</code>: 从循环队列中删除一个元素。如果成功删除则返回真。</li>
	<li><code>isEmpty()</code>: 检查循环队列是否为空。</li>
	<li><code>isFull()</code>: 检查循环队列是否已满。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1); &nbsp;// 返回 true
circularQueue.enQueue(2); &nbsp;// 返回 true
circularQueue.enQueue(3); &nbsp;// 返回 true
circularQueue.enQueue(4); &nbsp;// 返回 false，队列已满
circularQueue.Rear(); &nbsp;// 返回 3
circularQueue.isFull(); &nbsp;// 返回 true
circularQueue.deQueue(); &nbsp;// 返回 true
circularQueue.enQueue(4); &nbsp;// 返回 true
circularQueue.Rear(); &nbsp;// 返回 4</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有的值都在 0&nbsp;至 1000 的范围内；</li>
	<li>操作数将在 1 至 1000 的范围内；</li>
	<li>请不要使用内置的队列库。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组模拟

我们可以使用一个长度为 $k$ 的数组 $q$ 来模拟循环队列，用一个指针 $\textit{front}$ 记录队首元素的位置，初始时队列为空，而 $\textit{front}$ 为 $0$。另外，我们用一个变量 $\textit{size}$ 记录队列中元素的个数，初始时 $\textit{size}$ 为 $0$。

调用 `enQueue` 方法时，我们首先检查队列是否已满，即 $\textit{size} = k$，如果满了则直接返回 $\textit{false}$。否则，我们将元素插入到 $(\textit{front} + \textit{size}) \bmod k$ 的位置，然后 $\textit{size} = \textit{size} + 1$，表示队列中元素的个数增加了 $1$。最后返回 $\textit{true}$。

调用 `deQueue` 方法时，我们首先检查队列是否为空，即 $\textit{size} = 0$，如果为空则直接返回 $\textit{false}$。否则，我们将 $\textit{front} = (\textit{front} + 1) \bmod k$，表示队首元素出队，然后 $\textit{size} = \textit{size} - 1$，

调用 `Front` 方法时，我们首先检查队列是否为空，即 $\textit{size} = 0$，如果为空则返回 $-1$。否则，返回 $q[\textit{front}]$。

调用 `Rear` 方法时，我们首先检查队列是否为空，即 $\textit{size} = 0$，如果为空则返回 $-1$。否则，返回 $q[(\textit{front} + \textit{size} - 1) \bmod k]$。

调用 `isEmpty` 方法时，我们只需判断 $\textit{size} = 0$ 即可。

调用 `isFull` 方法时，我们只需判断 $\textit{size} = k$ 即可。

时间复杂度方面，以上操作的时间复杂度均为 $O(1)$。空间复杂度为 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [0] * k
        self.size = 0
        self.capacity = k
        self.front = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.q[(self.front + self.size) % self.capacity] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def Front(self) -> int:
        return -1 if self.isEmpty() else self.q[self.front]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[(self.front + self.size - 1) % self.capacity]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.capacity


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```

#### Java

```java
class MyCircularQueue {
    private int[] q;
    private int front;
    private int size;
    private int capacity;

    public MyCircularQueue(int k) {
        q = new int[k];
        capacity = k;
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
```

#### C++

```cpp
class MyCircularQueue {
private:
    int front;
    int size;
    int capacity;
    vector<int> q;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q = vector<int>(k);
        front = size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

#### Go

```go
type MyCircularQueue struct {
	front    int
	size     int
	capacity int
	q        []int
}

func Constructor(k int) MyCircularQueue {
	q := make([]int, k)
	return MyCircularQueue{0, 0, k, q}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}
	idx := (this.front + this.size) % this.capacity
	this.q[idx] = value
	this.size++
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1) % this.capacity
	this.size--
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[this.front]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}
	idx := (this.front + this.size - 1) % this.capacity
	return this.q[idx]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularQueue) IsFull() bool {
	return this.size == this.capacity
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */
```

#### TypeScript

```ts
class MyCircularQueue {
    private queue: number[];
    private left: number;
    private right: number;
    private capacity: number;

    constructor(k: number) {
        this.queue = new Array(k);
        this.left = 0;
        this.right = 0;
        this.capacity = k;
    }

    enQueue(value: number): boolean {
        if (this.isFull()) {
            return false;
        }
        this.queue[this.right % this.capacity] = value;
        this.right++;
        return true;
    }

    deQueue(): boolean {
        if (this.isEmpty()) {
            return false;
        }
        this.left++;
        return true;
    }

    Front(): number {
        if (this.isEmpty()) {
            return -1;
        }
        return this.queue[this.left % this.capacity];
    }

    Rear(): number {
        if (this.isEmpty()) {
            return -1;
        }
        return this.queue[(this.right - 1) % this.capacity];
    }

    isEmpty(): boolean {
        return this.right - this.left === 0;
    }

    isFull(): boolean {
        return this.right - this.left === this.capacity;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */
```

#### Rust

```rust
struct MyCircularQueue {
    q: Vec<i32>,
    size: usize,
    capacity: usize,
    front: usize,
}

impl MyCircularQueue {
    fn new(k: i32) -> Self {
        MyCircularQueue {
            q: vec![0; k as usize],
            size: 0,
            capacity: k as usize,
            front: 0,
        }
    }

    fn en_queue(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }
        let rear = (self.front + self.size) % self.capacity;
        self.q[rear] = value;
        self.size += 1;
        true
    }

    fn de_queue(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        self.front = (self.front + 1) % self.capacity;
        self.size -= 1;
        true
    }

    fn front(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            self.q[self.front]
        }
    }

    fn rear(&self) -> i32 {
        if self.is_empty() {
            -1
        } else {
            let rear = (self.front + self.size - 1) % self.capacity;
            self.q[rear]
        }
    }

    fn is_empty(&self) -> bool {
        self.size == 0
    }

    fn is_full(&self) -> bool {
        self.size == self.capacity
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [623. 在二叉树中增加一行](https://leetcode.cn/problems/add-one-row-to-tree){#623}

{{< tabs "623" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(
        self, root: Optional[TreeNode], val: int, depth: int
    ) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val, root)
        q = deque([root])
        i = 0
        while q:
            i += 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                if i == depth - 1:
                    node.left = TreeNode(val, node.left, None)
                    node.right = TreeNode(val, None, node.right)
        return root
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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int i = 0;
        while (!q.isEmpty()) {
            ++i;
            for (int k = q.size(); k > 0; --k) {
                TreeNode node = q.pollFirst();
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
                if (i == depth - 1) {
                    node.left = new TreeNode(val, node.left, null);
                    node.right = new TreeNode(val, null, node.right);
                }
            }
        }
        return root;
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q{{root}};
        int i = 0;
        while (!q.empty()) {
            ++i;
            for (int k = q.size(); k; --k) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == depth - 1) {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }
            }
        }
        return root;
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
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{val, root, nil}
	}
	q := []*TreeNode{root}
	i := 0
	for len(q) > 0 {
		i++
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
			if i == depth-1 {
				node.Left = &TreeNode{val, node.Left, nil}
				node.Right = &TreeNode{val, nil, node.Right}
			}
		}
	}
	return root
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

function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
    if (depth === 1) {
        return new TreeNode(val, root);
    }

    const queue = [root];
    for (let i = 1; i < depth - 1; i++) {
        const n = queue.length;
        for (let j = 0; j < n; j++) {
            const { left, right } = queue.shift();
            left && queue.push(left);
            right && queue.push(right);
        }
    }
    for (const node of queue) {
        node.left = new TreeNode(val, node.left);
        node.right = new TreeNode(val, null, node.right);
    }
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的根&nbsp;<code>root</code>&nbsp;和两个整数 <code>val</code> 和&nbsp;<code>depth</code>&nbsp;，在给定的深度&nbsp;<code>depth</code>&nbsp;处添加一个值为 <code>val</code> 的节点行。</p>

<p>注意，根节点&nbsp;<code>root</code>&nbsp;位于深度&nbsp;<code>1</code>&nbsp;。</p>

<p>加法规则如下:</p>

<ul>
	<li>给定整数&nbsp;<code>depth</code>，对于深度为&nbsp;<code>depth - 1</code> 的每个非空树节点 <code>cur</code> ，创建两个值为 <code>val</code> 的树节点作为 <code>cur</code> 的左子树根和右子树根。</li>
	<li><code>cur</code> 原来的左子树应该是新的左子树根的左子树。</li>
	<li><code>cur</code> 原来的右子树应该是新的右子树根的右子树。</li>
	<li>如果 <code>depth == 1 </code>意味着&nbsp;<code>depth - 1</code>&nbsp;根本没有深度，那么创建一个树节点，值 <code>val </code>作为整个原始树的新根，而原始树就是新根的左子树。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0623.Add%20One%20Row%20to%20Tree/images/addrow-tree.jpg" style="height: 231px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> root = [4,2,6,3,1,5], val = 1, depth = 2
<strong>输出:</strong> [4,1,1,2,null,null,6,3,1,5]</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0623.Add%20One%20Row%20to%20Tree/images/add2-tree.jpg" style="height: 277px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> root = [4,2,null,3,1], val = 1, depth = 3
<strong>输出:</strong>  [4,2,null,1,1,3,null,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数在&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;范围内</li>
	<li>树的深度在&nbsp;<code>[1, 10<sup>4</sup>]</code>范围内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= val &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= depth &lt;= the depth of tree + 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

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
    def addOneRow(
        self, root: Optional[TreeNode], val: int, depth: int
    ) -> Optional[TreeNode]:
        def dfs(root, d):
            if root is None:
                return
            if d == depth - 1:
                root.left = TreeNode(val, root.left, None)
                root.right = TreeNode(val, None, root.right)
                return
            dfs(root.left, d + 1)
            dfs(root.right, d + 1)

        if depth == 1:
            return TreeNode(val, root)
        dfs(root, 1)
        return root
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
    private int val;
    private int depth;

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        this.val = val;
        this.depth = depth;
        dfs(root, 1);
        return root;
    }

    private void dfs(TreeNode root, int d) {
        if (root == null) {
            return;
        }
        if (d == depth - 1) {
            TreeNode l = new TreeNode(val, root.left, null);
            TreeNode r = new TreeNode(val, null, root.right);
            root.left = l;
            root.right = r;
            return;
        }
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
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
    int val;
    int depth;

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        this->val = val;
        this->depth = depth;
        dfs(root, 1);
        return root;
    }

    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (d == depth - 1) {
            auto l = new TreeNode(val, root->left, nullptr);
            auto r = new TreeNode(val, nullptr, root->right);
            root->left = l;
            root->right = r;
            return;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
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
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{Val: val, Left: root}
	}
	var dfs func(root *TreeNode, d int)
	dfs = func(root *TreeNode, d int) {
		if root == nil {
			return
		}
		if d == depth-1 {
			l, r := &TreeNode{Val: val, Left: root.Left}, &TreeNode{Val: val, Right: root.Right}
			root.Left, root.Right = l, r
			return
		}
		dfs(root.Left, d+1)
		dfs(root.Right, d+1)
	}
	dfs(root, 1)
	return root
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

function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
    function dfs(root, d) {
        if (!root) {
            return;
        }
        if (d == depth - 1) {
            root.left = new TreeNode(val, root.left, null);
            root.right = new TreeNode(val, null, root.right);
            return;
        }
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    }
    if (depth == 1) {
        return new TreeNode(val, root);
    }
    dfs(root, 1);
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

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
    def addOneRow(
        self, root: Optional[TreeNode], val: int, depth: int
    ) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val, root)
        q = deque([root])
        i = 0
        while q:
            i += 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                if i == depth - 1:
                    node.left = TreeNode(val, node.left, None)
                    node.right = TreeNode(val, None, node.right)
        return root
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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, null);
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int i = 0;
        while (!q.isEmpty()) {
            ++i;
            for (int k = q.size(); k > 0; --k) {
                TreeNode node = q.pollFirst();
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
                if (i == depth - 1) {
                    node.left = new TreeNode(val, node.left, null);
                    node.right = new TreeNode(val, null, node.right);
                }
            }
        }
        return root;
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode*> q{{root}};
        int i = 0;
        while (!q.empty()) {
            ++i;
            for (int k = q.size(); k; --k) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == depth - 1) {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }
            }
        }
        return root;
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
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{val, root, nil}
	}
	q := []*TreeNode{root}
	i := 0
	for len(q) > 0 {
		i++
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
			if i == depth-1 {
				node.Left = &TreeNode{val, node.Left, nil}
				node.Right = &TreeNode{val, nil, node.Right}
			}
		}
	}
	return root
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

function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
    if (depth === 1) {
        return new TreeNode(val, root);
    }

    const queue = [root];
    for (let i = 1; i < depth - 1; i++) {
        const n = queue.length;
        for (let j = 0; j < n; j++) {
            const { left, right } = queue.shift();
            left && queue.push(left);
            right && queue.push(right);
        }
    }
    for (const node of queue) {
        node.left = new TreeNode(val, node.left);
        node.right = new TreeNode(val, null, node.right);
    }
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [624. 数组列表中的最大距离](https://leetcode.cn/problems/maximum-distance-in-arrays){#624}

{{< tabs "624" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        mi, mx = arrays[0][0], arrays[0][-1]
        for arr in arrays[1:]:
            a, b = abs(arr[0] - mx), abs(arr[-1] - mi)
            ans = max(ans, a, b)
            mi = min(mi, arr[0])
            mx = max(mx, arr[-1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int ans = 0;
        int mi = arrays.get(0).get(0);
        int mx = arrays.get(0).get(arrays.get(0).size() - 1);
        for (int i = 1; i < arrays.size(); ++i) {
            var arr = arrays.get(i);
            int a = Math.abs(arr.get(0) - mx);
            int b = Math.abs(arr.get(arr.size() - 1) - mi);
            ans = Math.max(ans, Math.max(a, b));
            mi = Math.min(mi, arr.get(0));
            mx = Math.max(mx, arr.get(arr.size() - 1));
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
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mi = arrays[0][0], mx = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < arrays.size(); ++i) {
            auto& arr = arrays[i];
            int a = abs(arr[0] - mx), b = abs(arr[arr.size() - 1] - mi);
            ans = max({ans, a, b});
            mi = min(mi, arr[0]);
            mx = max(mx, arr[arr.size() - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistance(arrays [][]int) (ans int) {
	mi, mx := arrays[0][0], arrays[0][len(arrays[0])-1]
	for _, arr := range arrays[1:] {
		a, b := abs(arr[0]-mx), abs(arr[len(arr)-1]-mi)
		ans = max(ans, max(a, b))
		mi = min(mi, arr[0])
		mx = max(mx, arr[len(arr)-1])
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
function maxDistance(arrays: number[][]): number {
    let ans = 0;
    let [mi, mx] = [arrays[0][0], arrays[0].at(-1)!];
    for (let i = 1; i < arrays.length; ++i) {
        const arr = arrays[i];
        const a = Math.abs(arr[0] - mx);
        const b = Math.abs(arr.at(-1)! - mi);
        ans = Math.max(ans, a, b);
        mi = Math.min(mi, arr[0]);
        mx = Math.max(mx, arr.at(-1)!);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mi = arrays[0][0];
        let mut mx = arrays[0][arrays[0].len() - 1];

        for i in 1..arrays.len() {
            let arr = &arrays[i];
            let a = (arr[0] - mx).abs();
            let b = (arr[arr.len() - 1] - mi).abs();
            ans = ans.max(a).max(b);

            mi = mi.min(arr[0]);
            mx = mx.max(arr[arr.len() - 1]);
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function (arrays) {
    let ans = 0;
    let [mi, mx] = [arrays[0][0], arrays[0].at(-1)];
    for (let i = 1; i < arrays.length; ++i) {
        const arr = arrays[i];
        const a = Math.abs(arr[0] - mx);
        const b = Math.abs(arr.at(-1) - mi);
        ans = Math.max(ans, a, b);
        mi = Math.min(mi, arr[0]);
        mx = Math.max(mx, arr.at(-1));
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

<p>给定&nbsp;<code>m</code>&nbsp;个数组，每个数组都已经按照升序排好序了。</p>

<p>现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;之间的距离定义为它们差的绝对值&nbsp;<code>|a-b|</code>&nbsp;。</p>

<p>返回最大距离。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[[1,2,3],[4,5],[1,2,3]]
<strong>输出：</strong>4
<strong>解释：</strong>
一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arrays = [[1],[1]]
<b>输出：</b>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == arrays.length</code></li>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrays[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= arrays[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>arrays[i]</code>&nbsp;以&nbsp;<strong>升序</strong>&nbsp;排序。</li>
	<li>所有数组中最多有&nbsp;<code>10<sup>5</sup></code> 个整数。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护最大值和最小值

我们注意到，最大距离一定是两个数组中的一个最大值和另一个最小值之间的距离。因此，我们可以维护两个变量 $\textit{mi}$ 和 $\textit{mx}$，分别表示已经遍历过的数组中的最小值和最大值。初始时 $\textit{mi}$ 和 $\textit{mx}$ 分别为第一个数组的第一个元素和最后一个元素。

接下来，我们从第二个数组开始遍历，对于每个数组，我们首先计算当前数组的第一个元素和 $\textit{mx}$ 之间的距离，以及当前数组的最后一个元素和 $\textit{mi}$ 之间的距离，然后更新最大距离。同时，我们更新 $\textit{mi} = \min(\textit{mi}, \textit{arr}[0])$ 和 $\textit{mx} = \max(\textit{mx}, \textit{arr}[\textit{size} - 1])$。

遍历结束后，即可得到最大距离。

时间复杂度 $O(m)$，其中 $m$ 为数组的个数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        mi, mx = arrays[0][0], arrays[0][-1]
        for arr in arrays[1:]:
            a, b = abs(arr[0] - mx), abs(arr[-1] - mi)
            ans = max(ans, a, b)
            mi = min(mi, arr[0])
            mx = max(mx, arr[-1])
        return ans
```

#### Java

```java
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int ans = 0;
        int mi = arrays.get(0).get(0);
        int mx = arrays.get(0).get(arrays.get(0).size() - 1);
        for (int i = 1; i < arrays.size(); ++i) {
            var arr = arrays.get(i);
            int a = Math.abs(arr.get(0) - mx);
            int b = Math.abs(arr.get(arr.size() - 1) - mi);
            ans = Math.max(ans, Math.max(a, b));
            mi = Math.min(mi, arr.get(0));
            mx = Math.max(mx, arr.get(arr.size() - 1));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mi = arrays[0][0], mx = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < arrays.size(); ++i) {
            auto& arr = arrays[i];
            int a = abs(arr[0] - mx), b = abs(arr[arr.size() - 1] - mi);
            ans = max({ans, a, b});
            mi = min(mi, arr[0]);
            mx = max(mx, arr[arr.size() - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxDistance(arrays [][]int) (ans int) {
	mi, mx := arrays[0][0], arrays[0][len(arrays[0])-1]
	for _, arr := range arrays[1:] {
		a, b := abs(arr[0]-mx), abs(arr[len(arr)-1]-mi)
		ans = max(ans, max(a, b))
		mi = min(mi, arr[0])
		mx = max(mx, arr[len(arr)-1])
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
function maxDistance(arrays: number[][]): number {
    let ans = 0;
    let [mi, mx] = [arrays[0][0], arrays[0].at(-1)!];
    for (let i = 1; i < arrays.length; ++i) {
        const arr = arrays[i];
        const a = Math.abs(arr[0] - mx);
        const b = Math.abs(arr.at(-1)! - mi);
        ans = Math.max(ans, a, b);
        mi = Math.min(mi, arr[0]);
        mx = Math.max(mx, arr.at(-1)!);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mi = arrays[0][0];
        let mut mx = arrays[0][arrays[0].len() - 1];

        for i in 1..arrays.len() {
            let arr = &arrays[i];
            let a = (arr[0] - mx).abs();
            let b = (arr[arr.len() - 1] - mi).abs();
            ans = ans.max(a).max(b);

            mi = mi.min(arr[0]);
            mx = mx.max(arr[arr.len() - 1]);
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function (arrays) {
    let ans = 0;
    let [mi, mx] = [arrays[0][0], arrays[0].at(-1)];
    for (let i = 1; i < arrays.length; ++i) {
        const arr = arrays[i];
        const a = Math.abs(arr[0] - mx);
        const b = Math.abs(arr.at(-1) - mi);
        ans = Math.max(ans, a, b);
        mi = Math.min(mi, arr[0]);
        mx = Math.max(mx, arr.at(-1));
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [625. 最小因式分解 🔒](https://leetcode.cn/problems/minimum-factorization){#625}

{{< tabs "625" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestFactorization(self, num: int) -> int:
        if num < 2:
            return num
        ans, mul = 0, 1
        for i in range(9, 1, -1):
            while num % i == 0:
                num //= i
                ans = mul * i + ans
                mul *= 10
        return ans if num < 2 and ans <= 2**31 - 1 else 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        long ans = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                    ans = mul * i + ans;
                    mul *= 10;
                }
            }
        }
        return num < 2 && ans <= Integer.MAX_VALUE ? (int) ans : 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        long long ans = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                    ans = mul * i + ans;
                    mul *= 10;
                }
            }
        }
        return num < 2 && ans <= INT_MAX ? ans : 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestFactorization(num int) int {
	if num < 2 {
		return num
	}
	ans, mul := 0, 1
	for i := 9; i >= 2; i-- {
		if num%i == 0 {
			for num%i == 0 {
				num /= i
				ans = mul*i + ans
				mul *= 10
			}
		}
	}
	if num < 2 && ans <= math.MaxInt32 {
		return ans
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

<p>给定一个正整数 <code>num</code>，找出最小的正整数 <code>x</code> 使得 <code>x</code> 的所有数位相乘恰好等于 <code>num</code>。</p>

<p>如果不存在这样的结果或者结果不是 32 位有符号整数，返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 48
<strong>输出：</strong>68
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 15
<strong>输出：</strong>35
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 因式分解

我们先判断 $num$ 是否小于 $2$，如果是，直接返回 $num$。然后从 $9$ 开始，尽可能多地将数字分解为 $9$，然后分解为 $8$，以此类推，直到分解为 $2$。如果最后剩下的数字不是 $1$，或者结果超过了 $2^{31} - 1$，则返回 $0$。否则，我们返回结果。

> 注意，分解后的数字，应该依次填充到结果的个位、十位、百位、千位……上，因此我们需要维护一个变量 $mul$，表示当前的位数。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为 $num$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestFactorization(self, num: int) -> int:
        if num < 2:
            return num
        ans, mul = 0, 1
        for i in range(9, 1, -1):
            while num % i == 0:
                num //= i
                ans = mul * i + ans
                mul *= 10
        return ans if num < 2 and ans <= 2**31 - 1 else 0
```

#### Java

```java
class Solution {
    public int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        long ans = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                    ans = mul * i + ans;
                    mul *= 10;
                }
            }
        }
        return num < 2 && ans <= Integer.MAX_VALUE ? (int) ans : 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        long long ans = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                    ans = mul * i + ans;
                    mul *= 10;
                }
            }
        }
        return num < 2 && ans <= INT_MAX ? ans : 0;
    }
};
```

#### Go

```go
func smallestFactorization(num int) int {
	if num < 2 {
		return num
	}
	ans, mul := 0, 1
	for i := 9; i >= 2; i-- {
		if num%i == 0 {
			for num%i == 0 {
				num /= i
				ans = mul*i + ans
				mul *= 10
			}
		}
	}
	if num < 2 && ans <= math.MaxInt32 {
		return ans
	}
	return 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [626. 换座位](https://leetcode.cn/problems/exchange-seats){#626}

{{< tabs "626" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN id & 1 = 0 THEN id - 1
        WHEN ROW_NUMBER() OVER (ORDER BY id) != COUNT(id) OVER () THEN id + 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Seat</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
<code>id</code> 是该表的主键（唯一值）列。
该表的每一行都表示学生的姓名和 ID。
ID 序列始终从 1 开始并连续增加。
</pre>

<p>&nbsp;</p>

<p>编写解决方案来交换每两个连续的学生的座位号。如果学生的数量是奇数，则最后一个学生的id不交换。</p>

<p>按 <code>id</code> <strong>升序</strong> 返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Seat 表:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
<strong>输出:</strong> 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
<strong>解释:
</strong>请注意，如果学生人数为奇数，则不需要更换最后一名学生的座位。</pre>

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
SELECT s1.id, COALESCE(s2.student, s1.student) AS student
FROM
    Seat AS s1
    LEFT JOIN Seat AS s2 ON (s1.id + 1) ^ 1 - 1 = s2.id
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    id + (
        CASE
            WHEN id % 2 = 1
            AND id != (SELECT MAX(id) FROM Seat) THEN 1
            WHEN id % 2 = 0 THEN -1
            ELSE 0
        END
    ) AS id,
    student
FROM Seat
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    RANK() OVER (ORDER BY (id - 1) ^ 1) AS id,
    student
FROM Seat;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法四

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN id & 1 = 0 THEN id - 1
        WHEN ROW_NUMBER() OVER (ORDER BY id) != COUNT(id) OVER () THEN id + 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [627. 变更性别](https://leetcode.cn/problems/swap-salary){#627}

{{< tabs "627" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
UPDATE Salary
SET sex = IF(sex = 'f', 'm', 'f');
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="original__bRMd">
<div>
<p><code>Salary</code> 表：</p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id 是这个表的主键（具有唯一值的列）。
sex 这一列的值是 ENUM 类型，只能从 ('m', 'f') 中取。
本表包含公司雇员的信息。
</pre>

<p>&nbsp;</p>

<p>请你编写一个解决方案来交换所有的 <code>'f'</code> 和 <code>'m'</code> （即，将所有 <code>'f'</code> 变为 <code>'m'</code> ，反之亦然），仅使用 <strong>单个 update 语句</strong> ，且不产生中间临时表。</p>

<p>注意，你必须仅使用一条 update 语句，且 <strong>不能</strong> 使用 select 语句。</p>

<p>结果如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Salary 表：
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
+----+------+-----+--------+
<strong>输出：</strong>
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
+----+------+-----+--------+
<strong>解释：</strong>
(1, A) 和 (3, C) 从 'm' 变为 'f' 。
(2, B) 和 (4, D) 从 'f' 变为 'm' 。</pre>
</div>
</div>

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
UPDATE salary
SET sex = CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
UPDATE Salary
SET sex = IF(sex = 'f', 'm', 'f');
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [628. 三个数的最大乘积](https://leetcode.cn/problems/maximum-product-of-three-numbers){#628}

{{< tabs "628" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        top3 = nlargest(3, nums)
        bottom2 = nlargest(2, nums, key=lambda x: -x)
        return max(top3[0] * top3[1] * top3[2], top3[0] * bottom2[0] * bottom2[1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumProduct(int[] nums) {
        final int inf = 1 << 30;
        int mi1 = inf, mi2 = inf;
        int mx1 = -inf, mx2 = -inf, mx3 = -inf;
        for (int x : nums) {
            if (x < mi1) {
                mi2 = mi1;
                mi1 = x;
            } else if (x < mi2) {
                mi2 = x;
            }
            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }
        return Math.max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int inf = 1 << 30;
        int mi1 = inf, mi2 = inf;
        int mx1 = -inf, mx2 = -inf, mx3 = -inf;
        for (int x : nums) {
            if (x < mi1) {
                mi2 = mi1;
                mi1 = x;
            } else if (x < mi2) {
                mi2 = x;
            }
            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }
        return max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumProduct(nums []int) int {
	const inf = 1 << 30
	mi1, mi2 := inf, inf
	mx1, mx2, mx3 := -inf, -inf, -inf
	for _, x := range nums {
		if x < mi1 {
			mi1, mi2 = x, mi1
		} else if x < mi2 {
			mi2 = x
		}
		if x > mx1 {
			mx1, mx2, mx3 = x, mx1, mx2
		} else if x > mx2 {
			mx2, mx3 = x, mx2
		} else if x > mx3 {
			mx3 = x
		}
	}
	return max(mi1*mi2*mx1, mx1*mx2*mx3)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumProduct(nums: number[]): number {
    const inf = 1 << 30;
    let mi1 = inf,
        mi2 = inf;
    let mx1 = -inf,
        mx2 = -inf,
        mx3 = -inf;
    for (const x of nums) {
        if (x < mi1) {
            mi2 = mi1;
            mi1 = x;
        } else if (x < mi2) {
            mi2 = x;
        }
        if (x > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx3 = mx2;
            mx2 = x;
        } else if (x > mx3) {
            mx3 = x;
        }
    }
    return Math.max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整型数组 <code>nums</code> ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>24
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3]
<strong>输出：</strong>-6
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-1000 <= nums[i] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 分类讨论

我们先对数组 $\textit{nums}$ 进行排序，接下来分两种情况讨论：

-   如果 $\textit{nums}$ 中全是非负数或者全是非正数，那么答案即为最后三个数的乘积，即 $\textit{nums}[n-1] \times \textit{nums}[n-2] \times \textit{nums}[n-3]$；
-   如果 $\textit{nums}$ 中既有正数也有负数，那么答案可能是两个最小负数和一个最大整数的乘积，即 $\textit{nums}[n-1] \times \textit{nums}[0] \times \textit{nums}[1]$；也可能是最后三个数的乘积，即 $\textit{nums}[n-1] \times \textit{nums}[n-2] \times \textit{nums}[n-3]$。

最后返回两种情况的最大值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        a = nums[-1] * nums[-2] * nums[-3]
        b = nums[-1] * nums[0] * nums[1]
        return max(a, b)
```

#### Java

```java
class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int b = nums[n - 1] * nums[0] * nums[1];
        return Math.max(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int b = nums[n - 1] * nums[0] * nums[1];
        return max(a, b);
    }
};
```

#### Go

```go
func maximumProduct(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	a := nums[n-1] * nums[n-2] * nums[n-3]
	b := nums[n-1] * nums[0] * nums[1]
	if a > b {
		return a
	}
	return b
}
```

#### TypeScript

```ts
function maximumProduct(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const a = nums[n - 1] * nums[n - 2] * nums[n - 3];
    const b = nums[n - 1] * nums[0] * nums[1];
    return Math.max(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一次遍历

我们可以不用对数组进行排序，而是维护五个变量，其中 $\textit{mi1}$ 和 $\textit{mi2}$ 表示数组中最小的两个数，而 $\textit{mx1}$, $\textit{mx2}$ 和 $\textit{mx3}$ 表示数组中最大的三个数。

最后返回 $\max(\textit{mi1} \times \textit{mi2} \times \textit{mx1}, \textit{mx1} \times \textit{mx2} \times \textit{mx3})$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        top3 = nlargest(3, nums)
        bottom2 = nlargest(2, nums, key=lambda x: -x)
        return max(top3[0] * top3[1] * top3[2], top3[0] * bottom2[0] * bottom2[1])
```

#### Java

```java
class Solution {
    public int maximumProduct(int[] nums) {
        final int inf = 1 << 30;
        int mi1 = inf, mi2 = inf;
        int mx1 = -inf, mx2 = -inf, mx3 = -inf;
        for (int x : nums) {
            if (x < mi1) {
                mi2 = mi1;
                mi1 = x;
            } else if (x < mi2) {
                mi2 = x;
            }
            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }
        return Math.max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int inf = 1 << 30;
        int mi1 = inf, mi2 = inf;
        int mx1 = -inf, mx2 = -inf, mx3 = -inf;
        for (int x : nums) {
            if (x < mi1) {
                mi2 = mi1;
                mi1 = x;
            } else if (x < mi2) {
                mi2 = x;
            }
            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }
        }
        return max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
    }
};
```

#### Go

```go
func maximumProduct(nums []int) int {
	const inf = 1 << 30
	mi1, mi2 := inf, inf
	mx1, mx2, mx3 := -inf, -inf, -inf
	for _, x := range nums {
		if x < mi1 {
			mi1, mi2 = x, mi1
		} else if x < mi2 {
			mi2 = x
		}
		if x > mx1 {
			mx1, mx2, mx3 = x, mx1, mx2
		} else if x > mx2 {
			mx2, mx3 = x, mx2
		} else if x > mx3 {
			mx3 = x
		}
	}
	return max(mi1*mi2*mx1, mx1*mx2*mx3)
}
```

#### TypeScript

```ts
function maximumProduct(nums: number[]): number {
    const inf = 1 << 30;
    let mi1 = inf,
        mi2 = inf;
    let mx1 = -inf,
        mx2 = -inf,
        mx3 = -inf;
    for (const x of nums) {
        if (x < mi1) {
            mi2 = mi1;
            mi1 = x;
        } else if (x < mi2) {
            mi2 = x;
        }
        if (x > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx3 = mx2;
            mx2 = x;
        } else if (x > mx3) {
            mx3 = x;
        }
    }
    return Math.max(mi1 * mi2 * mx1, mx1 * mx2 * mx3);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [629. K 个逆序对数组](https://leetcode.cn/problems/k-inverse-pairs-array){#629}

{{< tabs "629" >}}

{{% tab "python" %}}
```python
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        s = [0] * (k + 2)
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                f[j] = (s[j + 1] - s[max(0, j - (i - 1))]) % mod
            for j in range(1, k + 2):
                s[j] = (s[j - 1] + f[j - 1]) % mod
        return f[k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kInversePairs(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        int[] s = new int[k + 2];
        f[0] = 1;
        Arrays.fill(s, 1);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[j] = (s[j + 1] - s[Math.max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                s[j] = (s[j - 1] + f[j - 1]) % mod;
            }
        }
        return f[k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kInversePairs(int n, int k) {
        int f[k + 1];
        int s[k + 2];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        fill(s, s + k + 2, 1);
        s[0] = 0;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[j] = (s[j + 1] - s[max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                s[j] = (s[j - 1] + f[j - 1]) % mod;
            }
        }
        return f[k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kInversePairs(n int, k int) int {
	f := make([]int, k+1)
	s := make([]int, k+2)
	f[0] = 1
	for i, x := range f {
		s[i+1] = s[i] + x
	}
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			f[j] = (s[j+1] - s[max(0, j-(i-1))] + mod) % mod
		}
		for j := 1; j <= k+1; j++ {
			s[j] = (s[j-1] + f[j-1]) % mod
		}
	}
	return f[k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kInversePairs(n: number, k: number): number {
    const f: number[] = Array(k + 1).fill(0);
    f[0] = 1;
    const s: number[] = Array(k + 2).fill(1);
    s[0] = 0;
    const mod: number = 1e9 + 7;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[j] = (s[j + 1] - s[Math.max(0, j - (i - 1))] + mod) % mod;
        }
        for (let j = 1; j <= k + 1; ++j) {
            s[j] = (s[j - 1] + f[j - 1]) % mod;
        }
    }
    return f[k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对于一个整数数组&nbsp;<code>nums</code>，<strong>逆序对</strong>是一对满足 <code>0 &lt;= i &lt; j &lt; nums.length</code> 且&nbsp;<code>nums[i] &gt; nums[j]</code>的整数对&nbsp;<code>[i, j]</code>&nbsp;。</p>

<p>给你两个整数&nbsp;<code>n</code>&nbsp;和&nbsp;<code>k</code>，找出所有包含从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;的数字，且恰好拥有&nbsp;<code>k</code>&nbsp;个 <strong>逆序对</strong> 的不同的数组的个数。由于答案可能很大，只需要返回对 <code>10<sup>9</sup>&nbsp;+ 7</code> 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 0
<strong>输出：</strong>1
<strong>解释：</strong>
只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>2
<strong>解释：</strong>
数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 前缀和

我们定义 $f[i][j]$ 表示数组长度为 $i$，逆序对数为 $j$ 的数组个数。初始时 $f[0][0] = 1$，其余 $f[i][j] = 0$。

接下来我们考虑如何得到 $f[i][j]$。

假设前 $i-1$ 个数已经确定，现在要插入数字 $i$，我们讨论 $i$ 插入到每个位置的情况：

-   如果 $i$ 插入到第 $1$ 个位置，那么逆序对增加了 $i-1$ 个，所以 $f[i][j]+=f[i-1][j-(i-1)]$。
-   如果 $i$ 插入到第 $2$ 个位置，那么逆序对增加了 $i-2$ 个，所以 $f[i][j]+=f[i-1][j-(i-2)]$。
-   ...
-   如果 $i$ 插入到第 $i-1$ 个位置，那么逆序对增加了 $1$ 个，所以 $f[i][j]+=f[i-1][j-1]$。
-   如果 $i$ 插入到第 $i$ 个位置，那么逆序对不变，所以 $f[i][j]+=f[i-1][j]$。

所以 $f[i][j]=\sum_{k=1}^{i}f[i-1][j-(i-k)]$。

我们注意到 $f[i][j]$ 的计算实际上涉及到前缀和，因此，我们可以使用前缀和优化计算过程。并且，由于 $f[i][j]$ 只与 $f[i-1][j]$ 有关，因此我们可以用一个一维数组来优化空间复杂度。

时间复杂度 $O(n \times k)$，空间复杂度 $O(k)$。其中 $n$ 和 $k$ 分别为数组长度和逆序对数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        s = [0] * (k + 2)
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                f[j] = (s[j + 1] - s[max(0, j - (i - 1))]) % mod
            for j in range(1, k + 2):
                s[j] = (s[j - 1] + f[j - 1]) % mod
        return f[k]
```

#### Java

```java
class Solution {
    public int kInversePairs(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        int[] s = new int[k + 2];
        f[0] = 1;
        Arrays.fill(s, 1);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[j] = (s[j + 1] - s[Math.max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                s[j] = (s[j - 1] + f[j - 1]) % mod;
            }
        }
        return f[k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kInversePairs(int n, int k) {
        int f[k + 1];
        int s[k + 2];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        fill(s, s + k + 2, 1);
        s[0] = 0;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[j] = (s[j + 1] - s[max(0, j - (i - 1))] + mod) % mod;
            }
            for (int j = 1; j <= k + 1; ++j) {
                s[j] = (s[j - 1] + f[j - 1]) % mod;
            }
        }
        return f[k];
    }
};
```

#### Go

```go
func kInversePairs(n int, k int) int {
	f := make([]int, k+1)
	s := make([]int, k+2)
	f[0] = 1
	for i, x := range f {
		s[i+1] = s[i] + x
	}
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			f[j] = (s[j+1] - s[max(0, j-(i-1))] + mod) % mod
		}
		for j := 1; j <= k+1; j++ {
			s[j] = (s[j-1] + f[j-1]) % mod
		}
	}
	return f[k]
}
```

#### TypeScript

```ts
function kInversePairs(n: number, k: number): number {
    const f: number[] = Array(k + 1).fill(0);
    f[0] = 1;
    const s: number[] = Array(k + 2).fill(1);
    s[0] = 0;
    const mod: number = 1e9 + 7;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[j] = (s[j + 1] - s[Math.max(0, j - (i - 1))] + mod) % mod;
        }
        for (let j = 1; j <= k + 1; ++j) {
            s[j] = (s[j - 1] + f[j - 1]) % mod;
        }
    }
    return f[k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

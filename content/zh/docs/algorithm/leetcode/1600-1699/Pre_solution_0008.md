---
title: "1670_设计前中后队列"
date: 2025-10-08T18:38:12+08:00
weight: 8
tags: [二分查找, 二叉树, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数据库, 数据流, 数组, 有序集合, 栈, 树, 深度优先搜索, 矩阵, 设计, 贪心, 链表, 队列]
---

{{< markmap >}}
### [1670_设计前中后队列](#1670)
#### [设计](#1670)
#### [队列](#1670)
#### [数组](#1670)
#### [链表](#1670)
#### [数据流](#1670)
### [1671_得到山形数组的最少删除次数](#1671)
#### [贪心](#1671)
#### [数组](#1671)
#### [二分查找](#1671)
#### [动态规划](#1671)
### [1672_最富有客户的资产总量](#1672)
#### [数组](#1672)
#### [矩阵](#1672)
### [1673_找出最具竞争力的子序列](#1673)
#### [栈](#1673)
#### [贪心](#1673)
#### [数组](#1673)
#### [单调栈](#1673)
### [1674_使数组互补的最少操作次数](#1674)
#### [数组](#1674)
#### [哈希表](#1674)
#### [前缀和](#1674)
### [1675_数组的最小偏移量](#1675)
#### [贪心](#1675)
#### [数组](#1675)
#### [有序集合](#1675)
#### [堆（优先队列）](#1675)
### [1676_二叉树的最近公共祖先 IV 🔒](#1676)
#### [树](#1676)
#### [深度优先搜索](#1676)
#### [哈希表](#1676)
#### [二叉树](#1676)
### [1677_发票中的产品金额 🔒](#1677)
#### [数据库](#1677)
### [1678_设计 Goal 解析器](#1678)
#### [字符串](#1678)
### [1679_K 和数对的最大数目](#1679)
#### [数组](#1679)
#### [哈希表](#1679)
#### [双指针](#1679)
#### [排序](#1679)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1670_设计前中后队列
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 链表
___
#### 数据流
---
### 1671_得到山形数组的最少删除次数
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 1672_最富有客户的资产总量
___
#### 数组
___
#### 矩阵
---
### 1673_找出最具竞争力的子序列
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 单调栈
---
### 1674_使数组互补的最少操作次数
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1675_数组的最小偏移量
___
#### 贪心
___
#### 数组
___
#### 有序集合
___
#### 堆（优先队列）
---
### 1676_二叉树的最近公共祖先 IV 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 1677_发票中的产品金额 🔒
___
#### 数据库
---
### 1678_设计 Goal 解析器
___
#### 字符串
---
### 1679_K 和数对的最大数目
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 单调栈 | 双指针 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 排序 | 数据库 | 数据流 |
| 数组 | 有序集合 | 栈 |
| 树 | 深度优先搜索 | 矩阵 |
| 设计 | 贪心 | 链表 |
| 队列 |  |  |

# [1670. 设计前中后队列](https://leetcode.cn/problems/design-front-middle-back-queue){#1670}

{{< tabs "1670" >}}

{{% tab "python" %}}
```python
class FrontMiddleBackQueue:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def pushFront(self, val: int) -> None:
        self.q1.appendleft(val)
        self.rebalance()

    def pushMiddle(self, val: int) -> None:
        self.q1.append(val)
        self.rebalance()

    def pushBack(self, val: int) -> None:
        self.q2.append(val)
        self.rebalance()

    def popFront(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if self.q1:
            val = self.q1.popleft()
        else:
            val = self.q2.popleft()
        self.rebalance()
        return val

    def popMiddle(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if len(self.q1) == len(self.q2):
            val = self.q1.pop()
        else:
            val = self.q2.popleft()
        self.rebalance()
        return val

    def popBack(self) -> int:
        if not self.q2:
            return -1
        val = self.q2.pop()
        self.rebalance()
        return val

    def rebalance(self):
        if len(self.q1) > len(self.q2):
            self.q2.appendleft(self.q1.pop())
        if len(self.q2) > len(self.q1) + 1:
            self.q1.append(self.q2.popleft())


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FrontMiddleBackQueue {
    private Deque<Integer> q1 = new ArrayDeque<>();
    private Deque<Integer> q2 = new ArrayDeque<>();

    public FrontMiddleBackQueue() {
    }

    public void pushFront(int val) {
        q1.offerFirst(val);
        rebalance();
    }

    public void pushMiddle(int val) {
        q1.offerLast(val);
        rebalance();
    }

    public void pushBack(int val) {
        q2.offerLast(val);
        rebalance();
    }

    public int popFront() {
        if (q1.isEmpty() && q2.isEmpty()) {
            return -1;
        }
        int val = q1.isEmpty() ? q2.pollFirst() : q1.pollFirst();
        rebalance();
        return val;
    }

    public int popMiddle() {
        if (q1.isEmpty() && q2.isEmpty()) {
            return -1;
        }
        int val = q1.size() == q2.size() ? q1.pollLast() : q2.pollFirst();
        rebalance();
        return val;
    }

    public int popBack() {
        if (q2.isEmpty()) {
            return -1;
        }
        int val = q2.pollLast();
        rebalance();
        return val;
    }

    private void rebalance() {
        if (q1.size() > q2.size()) {
            q2.offerFirst(q1.pollLast());
        }
        if (q2.size() > q1.size() + 1) {
            q1.offerLast(q2.pollFirst());
        }
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        q1.push_front(val);
        rebalance();
    }

    void pushMiddle(int val) {
        q1.push_back(val);
        rebalance();
    }

    void pushBack(int val) {
        q2.push_back(val);
        rebalance();
    }

    int popFront() {
        if (q1.empty() && q2.empty()) return -1;
        int val = 0;
        if (q1.size()) {
            val = q1.front();
            q1.pop_front();
        } else {
            val = q2.front();
            q2.pop_front();
        }
        rebalance();
        return val;
    }

    int popMiddle() {
        if (q1.empty() && q2.empty()) return -1;
        int val = 0;
        if (q1.size() == q2.size()) {
            val = q1.back();
            q1.pop_back();
        } else {
            val = q2.front();
            q2.pop_front();
        }
        rebalance();
        return val;
    }

    int popBack() {
        if (q2.empty()) return -1;
        int val = q2.back();
        q2.pop_back();
        rebalance();
        return val;
    }

private:
    deque<int> q1;
    deque<int> q2;

    void rebalance() {
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        if (q2.size() > q1.size() + 1) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type FrontMiddleBackQueue struct {
	q1, q2 Deque
}

func Constructor() FrontMiddleBackQueue {
	return FrontMiddleBackQueue{}
}

func (this *FrontMiddleBackQueue) PushFront(val int) {
	this.q1.PushFront(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PushMiddle(val int) {
	this.q1.PushBack(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PushBack(val int) {
	this.q2.PushBack(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PopFront() int {
	if this.q1.Empty() && this.q2.Empty() {
		return -1
	}
	var val int
	if !this.q1.Empty() {
		val = this.q1.PopFront()
	} else {
		val = this.q2.PopFront()
	}
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) PopMiddle() int {
	if this.q1.Empty() && this.q2.Empty() {
		return -1
	}
	var val int
	if this.q1.Size() == this.q2.Size() {
		val = this.q1.PopBack()
	} else {
		val = this.q2.PopFront()
	}
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) PopBack() int {
	if this.q2.Empty() {
		return -1
	}
	val := this.q2.PopBack()
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) rebalance() {
	if this.q1.Size() > this.q2.Size() {
		this.q2.PushFront(this.q1.PopBack())
	}
	if this.q2.Size() > this.q1.Size()+1 {
		this.q1.PushBack(this.q2.PopFront())
	}
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PushFront(val);
 * obj.PushMiddle(val);
 * obj.PushBack(val);
 * param_4 := obj.PopFront();
 * param_5 := obj.PopMiddle();
 * param_6 := obj.PopBack();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class FrontMiddleBackQueue {
    private q1: Deque<number>;
    private q2: Deque<number>;

    constructor() {
        this.q1 = new Deque<number>();
        this.q2 = new Deque<number>();
    }

    pushFront(val: number): void {
        this.q1.pushFront(val);
        this.rebalance();
    }

    pushMiddle(val: number): void {
        this.q1.pushBack(val);
        this.rebalance();
    }

    pushBack(val: number): void {
        this.q2.pushBack(val);
        this.rebalance();
    }

    popFront(): number {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q1.isEmpty() ? this.q2.popFront() : this.q1.popFront();
        this.rebalance();
        return val!;
    }

    popMiddle(): number {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val =
            this.q1.getSize() === this.q2.getSize() ? this.q1.popBack() : this.q2.popFront();
        this.rebalance();
        return val!;
    }

    popBack(): number {
        if (this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q2.popBack();
        this.rebalance();
        return val!;
    }

    private rebalance(): void {
        if (this.q1.getSize() > this.q2.getSize()) {
            this.q2.pushFront(this.q1.popBack()!);
        }
        if (this.q2.getSize() > this.q1.getSize() + 1) {
            this.q1.pushBack(this.q2.popFront()!);
        }
    }
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
class FrontMiddleBackQueue {
    constructor() {
        this.q1 = new Deque();
        this.q2 = new Deque();
    }

    pushFront(val) {
        this.q1.pushFront(val);
        this.rebalance();
    }

    pushMiddle(val) {
        this.q1.pushBack(val);
        this.rebalance();
    }

    pushBack(val) {
        this.q2.pushBack(val);
        this.rebalance();
    }

    popFront() {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q1.isEmpty() ? this.q2.popFront() : this.q1.popFront();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    popMiddle() {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val =
            this.q1.getSize() === this.q2.getSize() ? this.q1.popBack() : this.q2.popFront();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    popBack() {
        if (this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q2.popBack();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    rebalance() {
        if (this.q1.getSize() > this.q2.getSize()) {
            this.q2.pushFront(this.q1.popBack());
        }
        if (this.q2.getSize() > this.q1.getSize() + 1) {
            this.q1.pushBack(this.q2.popFront());
        }
    }
}

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque {
    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val) {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val) {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront() {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front.value;
        this.front = this.front.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack() {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back.value;
        this.back = this.back.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue() {
        return this.front?.value;
    }

    backValue() {
        return this.back?.value;
    }

    getSize() {
        return this.size;
    }

    isEmpty() {
        return this.size === 0;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个队列，支持在前，中，后三个位置的 <code>push</code> 和 <code>pop</code> 操作。</p>

<p>请你完成 <code>FrontMiddleBack</code> 类：</p>

<ul>
	<li><code>FrontMiddleBack()</code> 初始化队列。</li>
	<li><code>void pushFront(int val)</code> 将 <code>val</code> 添加到队列的 <strong>最前面</strong> 。</li>
	<li><code>void pushMiddle(int val)</code> 将 <code>val</code> 添加到队列的 <strong>正中间</strong> 。</li>
	<li><code>void pushBack(int val)</code> 将 <code>val</code> 添加到队里的 <strong>最后面</strong> 。</li>
	<li><code>int popFront()</code> 将 <strong>最前面</strong> 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code> 。</li>
	<li><code>int popMiddle()</code> 将 <b>正中间</b> 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code> 。</li>
	<li><code>int popBack()</code> 将 <strong>最后面</strong> 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 <code>-1</code> 。</li>
</ul>

<p>请注意当有 <strong>两个</strong> 中间位置的时候，选择靠前面的位置进行操作。比方说：</p>

<ul>
	<li>将 <code>6</code> 添加到 <code>[1, 2, 3, 4, 5]</code> 的中间位置，结果数组为 <code>[1, 2, <strong>6</strong>, 3, 4, 5]</code> 。</li>
	<li>从 <code>[1, 2, <strong>3</strong>, 4, 5, 6]</code> 的中间位置弹出元素，返回 <code>3</code> ，数组变为 <code>[1, 2, 4, 5, 6]</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
<strong>输出：</strong>
[null, null, null, null, null, 1, 3, 4, 2, -1]

<strong>解释：</strong>
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [<strong>1</strong>]
q.pushBack(2);    // [1, <strong>2</strong>]
q.pushMiddle(3);  // [1, <strong>3</strong>, 2]
q.pushMiddle(4);  // [1, <strong>4</strong>, 3, 2]
q.popFront();     // 返回 1 -> [4, 3, 2]
q.popMiddle();    // 返回 3 -> [4, 2]
q.popMiddle();    // 返回 4 -> [2]
q.popBack();      // 返回 2 -> []
q.popFront();     // 返回 -1 -> [] （队列为空）
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= val <= 10<sup>9</sup></code></li>
	<li>最多调用 <code>1000</code> 次 <code>pushFront</code>， <code>pushMiddle</code>， <code>pushBack</code>， <code>popFront</code>， <code>popMiddle</code> 和 <code>popBack</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两个双端队列

我们用两个双端队列，其中 $q_1$ 存储前半部分，而 $q_2$ 存储后半部分。每次由 `rebalance` 函数来维护两个队列的平衡性，即保持 $q_2$ 的长度大于等于 $q_1$ 的长度，且长度之差不超过 $1$。

在 `pushFront`、`pushMiddle` 和 `pushBack` 函数中，我们只需要将元素添加到 $q_1$ 或 $q_2$ 中，并调用 `rebalance` 函数即可。

对于 `popFront` 函数，我们需要判断 $q_1$ 和 $q_2$ 是否为空，如果都为空，则返回 $-1$，否则我们需要判断 $q_1$ 是否为空，如果不为空，则弹出 $q_1$ 的队首元素，否则弹出 $q_2$ 的队首元素，并调用 `rebalance` 函数。

对于 `popMiddle` 函数，我们需要判断 $q_1$ 和 $q_2$ 是否为空，如果都为空，则返回 $-1$，否则我们需要判断 $q_1$ 和 $q_2$ 的长度是否相等，如果相等，则弹出 $q_1$ 的队尾元素，否则弹出 $q_2$ 的队首元素，并调用 `rebalance` 函数。

对于 `popBack` 函数，我们只需要判断 $q_2$ 是否为空，如果为空，则返回 $-1$，否则弹出 $q_2$ 的队尾元素，并调用 `rebalance` 函数。

以上操作的时间复杂度均为 $O(1)$，空间复杂度为 $O(n)$，其中 $n$ 是队列中的元素数量。

<!-- tabs:start -->

#### Python3

```python
class FrontMiddleBackQueue:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def pushFront(self, val: int) -> None:
        self.q1.appendleft(val)
        self.rebalance()

    def pushMiddle(self, val: int) -> None:
        self.q1.append(val)
        self.rebalance()

    def pushBack(self, val: int) -> None:
        self.q2.append(val)
        self.rebalance()

    def popFront(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if self.q1:
            val = self.q1.popleft()
        else:
            val = self.q2.popleft()
        self.rebalance()
        return val

    def popMiddle(self) -> int:
        if not self.q1 and not self.q2:
            return -1
        if len(self.q1) == len(self.q2):
            val = self.q1.pop()
        else:
            val = self.q2.popleft()
        self.rebalance()
        return val

    def popBack(self) -> int:
        if not self.q2:
            return -1
        val = self.q2.pop()
        self.rebalance()
        return val

    def rebalance(self):
        if len(self.q1) > len(self.q2):
            self.q2.appendleft(self.q1.pop())
        if len(self.q2) > len(self.q1) + 1:
            self.q1.append(self.q2.popleft())


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
```

#### Java

```java
class FrontMiddleBackQueue {
    private Deque<Integer> q1 = new ArrayDeque<>();
    private Deque<Integer> q2 = new ArrayDeque<>();

    public FrontMiddleBackQueue() {
    }

    public void pushFront(int val) {
        q1.offerFirst(val);
        rebalance();
    }

    public void pushMiddle(int val) {
        q1.offerLast(val);
        rebalance();
    }

    public void pushBack(int val) {
        q2.offerLast(val);
        rebalance();
    }

    public int popFront() {
        if (q1.isEmpty() && q2.isEmpty()) {
            return -1;
        }
        int val = q1.isEmpty() ? q2.pollFirst() : q1.pollFirst();
        rebalance();
        return val;
    }

    public int popMiddle() {
        if (q1.isEmpty() && q2.isEmpty()) {
            return -1;
        }
        int val = q1.size() == q2.size() ? q1.pollLast() : q2.pollFirst();
        rebalance();
        return val;
    }

    public int popBack() {
        if (q2.isEmpty()) {
            return -1;
        }
        int val = q2.pollLast();
        rebalance();
        return val;
    }

    private void rebalance() {
        if (q1.size() > q2.size()) {
            q2.offerFirst(q1.pollLast());
        }
        if (q2.size() > q1.size() + 1) {
            q1.offerLast(q2.pollFirst());
        }
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */
```

#### C++

```cpp
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        q1.push_front(val);
        rebalance();
    }

    void pushMiddle(int val) {
        q1.push_back(val);
        rebalance();
    }

    void pushBack(int val) {
        q2.push_back(val);
        rebalance();
    }

    int popFront() {
        if (q1.empty() && q2.empty()) return -1;
        int val = 0;
        if (q1.size()) {
            val = q1.front();
            q1.pop_front();
        } else {
            val = q2.front();
            q2.pop_front();
        }
        rebalance();
        return val;
    }

    int popMiddle() {
        if (q1.empty() && q2.empty()) return -1;
        int val = 0;
        if (q1.size() == q2.size()) {
            val = q1.back();
            q1.pop_back();
        } else {
            val = q2.front();
            q2.pop_front();
        }
        rebalance();
        return val;
    }

    int popBack() {
        if (q2.empty()) return -1;
        int val = q2.back();
        q2.pop_back();
        rebalance();
        return val;
    }

private:
    deque<int> q1;
    deque<int> q2;

    void rebalance() {
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        if (q2.size() > q1.size() + 1) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
```

#### Go

```go
type FrontMiddleBackQueue struct {
	q1, q2 Deque
}

func Constructor() FrontMiddleBackQueue {
	return FrontMiddleBackQueue{}
}

func (this *FrontMiddleBackQueue) PushFront(val int) {
	this.q1.PushFront(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PushMiddle(val int) {
	this.q1.PushBack(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PushBack(val int) {
	this.q2.PushBack(val)
	this.rebalance()
}

func (this *FrontMiddleBackQueue) PopFront() int {
	if this.q1.Empty() && this.q2.Empty() {
		return -1
	}
	var val int
	if !this.q1.Empty() {
		val = this.q1.PopFront()
	} else {
		val = this.q2.PopFront()
	}
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) PopMiddle() int {
	if this.q1.Empty() && this.q2.Empty() {
		return -1
	}
	var val int
	if this.q1.Size() == this.q2.Size() {
		val = this.q1.PopBack()
	} else {
		val = this.q2.PopFront()
	}
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) PopBack() int {
	if this.q2.Empty() {
		return -1
	}
	val := this.q2.PopBack()
	this.rebalance()
	return val
}

func (this *FrontMiddleBackQueue) rebalance() {
	if this.q1.Size() > this.q2.Size() {
		this.q2.PushFront(this.q1.PopBack())
	}
	if this.q2.Size() > this.q1.Size()+1 {
		this.q1.PushBack(this.q2.PopFront())
	}
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PushFront(val);
 * obj.PushMiddle(val);
 * obj.PushBack(val);
 * param_4 := obj.PopFront();
 * param_5 := obj.PopMiddle();
 * param_6 := obj.PopBack();
 */
```

#### TypeScript

```ts
class FrontMiddleBackQueue {
    private q1: Deque<number>;
    private q2: Deque<number>;

    constructor() {
        this.q1 = new Deque<number>();
        this.q2 = new Deque<number>();
    }

    pushFront(val: number): void {
        this.q1.pushFront(val);
        this.rebalance();
    }

    pushMiddle(val: number): void {
        this.q1.pushBack(val);
        this.rebalance();
    }

    pushBack(val: number): void {
        this.q2.pushBack(val);
        this.rebalance();
    }

    popFront(): number {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q1.isEmpty() ? this.q2.popFront() : this.q1.popFront();
        this.rebalance();
        return val!;
    }

    popMiddle(): number {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val =
            this.q1.getSize() === this.q2.getSize() ? this.q1.popBack() : this.q2.popFront();
        this.rebalance();
        return val!;
    }

    popBack(): number {
        if (this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q2.popBack();
        this.rebalance();
        return val!;
    }

    private rebalance(): void {
        if (this.q1.getSize() > this.q2.getSize()) {
            this.q2.pushFront(this.q1.popBack()!);
        }
        if (this.q2.getSize() > this.q1.getSize() + 1) {
            this.q1.pushBack(this.q2.popFront()!);
        }
    }
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */
```

#### JavaScript

```js
class FrontMiddleBackQueue {
    constructor() {
        this.q1 = new Deque();
        this.q2 = new Deque();
    }

    pushFront(val) {
        this.q1.pushFront(val);
        this.rebalance();
    }

    pushMiddle(val) {
        this.q1.pushBack(val);
        this.rebalance();
    }

    pushBack(val) {
        this.q2.pushBack(val);
        this.rebalance();
    }

    popFront() {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q1.isEmpty() ? this.q2.popFront() : this.q1.popFront();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    popMiddle() {
        if (this.q1.isEmpty() && this.q2.isEmpty()) {
            return -1;
        }
        const val =
            this.q1.getSize() === this.q2.getSize() ? this.q1.popBack() : this.q2.popFront();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    popBack() {
        if (this.q2.isEmpty()) {
            return -1;
        }
        const val = this.q2.popBack();
        this.rebalance();
        return val !== undefined ? val : -1;
    }

    rebalance() {
        if (this.q1.getSize() > this.q2.getSize()) {
            this.q2.pushFront(this.q1.popBack());
        }
        if (this.q2.getSize() > this.q1.getSize() + 1) {
            this.q1.pushBack(this.q2.popFront());
        }
    }
}

class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque {
    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val) {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val) {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront() {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front.value;
        this.front = this.front.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack() {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back.value;
        this.back = this.back.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue() {
        return this.front?.value;
    }

    backValue() {
        return this.back?.value;
    }

    getSize() {
        return this.size;
    }

    isEmpty() {
        return this.size === 0;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * var obj = new FrontMiddleBackQueue()
 * obj.pushFront(val)
 * obj.pushMiddle(val)
 * obj.pushBack(val)
 * var param_4 = obj.popFront()
 * var param_5 = obj.popMiddle()
 * var param_6 = obj.popBack()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1671. 得到山形数组的最少删除次数](https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array){#1671}

{{< tabs "1671" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    left[i] = max(left[i], left[j] + 1)
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    right[i] = max(right[i], right[j] + 1)
        return n - max(a + b - 1 for a, b in zip(left, right) if a > 1 and b > 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = Math.max(left[i], left[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    right[i] = Math.max(right[i], right[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 1 && right[i] > 1) {
                ans = Math.max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 1 && right[i] > 1) {
                ans = max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMountainRemovals(nums []int) int {
	n := len(nums)
	left, right := make([]int, n), make([]int, n)
	for i := range left {
		left[i], right[i] = 1, 1
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				left[i] = max(left[i], left[j]+1)
			}
		}
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if nums[i] > nums[j] {
				right[i] = max(right[i], right[j]+1)
			}
		}
	}
	ans := 0
	for i := range left {
		if left[i] > 1 && right[i] > 1 {
			ans = max(ans, left[i]+right[i]-1)
		}
	}
	return n - ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMountainRemovals(nums: number[]): number {
    const n = nums.length;
    const left = Array(n).fill(1);
    const right = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                left[i] = Math.max(left[i], left[j] + 1);
            }
        }
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (nums[i] > nums[j]) {
                right[i] = Math.max(right[i], right[j] + 1);
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (left[i] > 1 && right[i] > 1) {
            ans = Math.max(ans, left[i] + right[i] - 1);
        }
    }
    return n - ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut left = vec![1; n];
        let mut right = vec![1; n];
        for i in 1..n {
            for j in 0..i {
                if nums[i] > nums[j] {
                    left[i] = left[i].max(left[j] + 1);
                }
            }
        }
        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                if nums[i] > nums[j] {
                    right[i] = right[i].max(right[j] + 1);
                }
            }
        }

        let mut ans = 0;
        for i in 0..n {
            if left[i] > 1 && right[i] > 1 {
                ans = ans.max(left[i] + right[i] - 1);
            }
        }

        (n as i32) - ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们定义&nbsp;<code>arr</code>&nbsp;是 <b>山形数组</b>&nbsp;当且仅当它满足：</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>存在某个下标&nbsp;<code>i</code>&nbsp;（<strong>从 0 开始</strong>）&nbsp;满足&nbsp;<code>0 &lt; i &lt; arr.length - 1</code>&nbsp;且：
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>给你整数数组&nbsp;<code>nums</code>​ ，请你返回将 <code>nums</code>&nbsp;变成 <strong>山形状数组</strong>&nbsp;的​ <strong>最少</strong>&nbsp;删除次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,1]
<b>输出：</b>0
<b>解释：</b>数组本身就是山形数组，所以我们不需要删除任何元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,1,5,6,2,3,1]
<b>输出：</b>3
<b>解释：</b>一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>题目保证&nbsp;<code>nums</code> 删除一些元素后一定能得到山形数组。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

本题可以转化为求最长上升子序列和最长下降子序列。

我们定义 $left[i]$ 表示以 $nums[i]$ 结尾的最长上升子序列的长度，定义 $right[i]$ 表示以 $nums[i]$ 开头的最长下降子序列的长度。

那么最终答案就是 $n - \max(left[i] + right[i] - 1)$，其中 $1 \leq i \leq n$，并且 $left[i] \gt 1$ 且 $right[i] \gt 1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        left = [1] * n
        right = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    left[i] = max(left[i], left[j] + 1)
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    right[i] = max(right[i], right[j] + 1)
        return n - max(a + b - 1 for a, b in zip(left, right) if a > 1 and b > 1)
```

#### Java

```java
class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = Math.max(left[i], left[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    right[i] = Math.max(right[i], right[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 1 && right[i] > 1) {
                ans = Math.max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 1 && right[i] > 1) {
                ans = max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
};
```

#### Go

```go
func minimumMountainRemovals(nums []int) int {
	n := len(nums)
	left, right := make([]int, n), make([]int, n)
	for i := range left {
		left[i], right[i] = 1, 1
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				left[i] = max(left[i], left[j]+1)
			}
		}
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if nums[i] > nums[j] {
				right[i] = max(right[i], right[j]+1)
			}
		}
	}
	ans := 0
	for i := range left {
		if left[i] > 1 && right[i] > 1 {
			ans = max(ans, left[i]+right[i]-1)
		}
	}
	return n - ans
}
```

#### TypeScript

```ts
function minimumMountainRemovals(nums: number[]): number {
    const n = nums.length;
    const left = Array(n).fill(1);
    const right = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                left[i] = Math.max(left[i], left[j] + 1);
            }
        }
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (nums[i] > nums[j]) {
                right[i] = Math.max(right[i], right[j] + 1);
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (left[i] > 1 && right[i] > 1) {
            ans = Math.max(ans, left[i] + right[i] - 1);
        }
    }
    return n - ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_mountain_removals(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut left = vec![1; n];
        let mut right = vec![1; n];
        for i in 1..n {
            for j in 0..i {
                if nums[i] > nums[j] {
                    left[i] = left[i].max(left[j] + 1);
                }
            }
        }
        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                if nums[i] > nums[j] {
                    right[i] = right[i].max(right[j] + 1);
                }
            }
        }

        let mut ans = 0;
        for i in 0..n {
            if left[i] > 1 && right[i] > 1 {
                ans = ans.max(left[i] + right[i] - 1);
            }
        }

        (n as i32) - ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1672. 最富有客户的资产总量](https://leetcode.cn/problems/richest-customer-wealth){#1672}

{{< tabs "1672" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(v) for v in accounts)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = 0;
        for (var e : accounts) {
            // int s = Arrays.stream(e).sum();
            int s = 0;
            for (int v : e) {
                s += v;
            }
            ans = Math.max(ans, s);
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
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& v : accounts) {
            ans = max(ans, accumulate(v.begin(), v.end(), 0));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumWealth(accounts [][]int) int {
	ans := 0
	for _, e := range accounts {
		s := 0
		for _, v := range e {
			s += v
		}
		if ans < s {
			ans = s
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumWealth(accounts: number[][]): number {
    return accounts.reduce(
        (r, v) =>
            Math.max(
                r,
                v.reduce((r, v) => r + v),
            ),
        0,
    );
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map(|v| v.iter().sum()).max().unwrap()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[][] $accounts
     * @return Integer
     */
    function maximumWealth($accounts) {
        $rs = 0;
        for ($i = 0; $i < count($accounts); $i++) {
            $sum = 0;
            for ($j = 0; $j < count($accounts[$i]); $j++) {
                $sum += $accounts[$i][$j];
            }
            if ($sum > $rs) {
                $rs = $sum;
            }
        }
        return $rs;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int ans = INT_MIN;
    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            sum += accounts[i][j];
        }
        ans = max(ans, sum);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun maximumWealth(accounts: Array<IntArray>): Int {
        var max = 0
        for (account in accounts) {
            val sum = account.sum()
            if (sum > max) {
                max = sum
            }
        }
        return max
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的整数网格 <code>accounts</code> ，其中 <code>accounts[i][j]</code> 是第 <code>i​​​​​<sup>​​​​​​</sup>​</code> 位客户在第 <code>j</code> 家银行托管的资产数量。返回最富有客户所拥有的 <strong>资产总量</strong> 。</p>

<p>客户的 <strong>资产总量</strong> 就是他们在各家银行托管的资产数量之和。最富有客户就是 <strong>资产总量</strong> 最大的客户。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>accounts = [[1,2,3],[3,2,1]]
<strong>输出：</strong>6
<strong>解释：</strong>
<code>第 1 位客户的资产总量 = 1 + 2 + 3 = 6
第 2 位客户的资产总量 = 3 + 2 + 1 = 6
</code>两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>accounts = [[1,5],[7,3],[3,5]]
<strong>输出：</strong>10
<strong>解释：</strong>
<code>第 1 位客户的资产总量</code> = 6
<code>第 2 位客户的资产总量</code> = 10 
<code>第 3 位客户的资产总量</code> = 8
第 2 位客户是最富有的，资产总量是 10</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>accounts = [[2,8,7],[7,1,3],[1,9,5]]
<strong>输出：</strong>17
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == accounts.length</code></li>
	<li><code>n == accounts[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= accounts[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和

我们遍历 `accounts`，求出每一行的和的最大值即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为网格的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(v) for v in accounts)
```

#### Java

```java
class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = 0;
        for (var e : accounts) {
            // int s = Arrays.stream(e).sum();
            int s = 0;
            for (int v : e) {
                s += v;
            }
            ans = Math.max(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& v : accounts) {
            ans = max(ans, accumulate(v.begin(), v.end(), 0));
        }
        return ans;
    }
};
```

#### Go

```go
func maximumWealth(accounts [][]int) int {
	ans := 0
	for _, e := range accounts {
		s := 0
		for _, v := range e {
			s += v
		}
		if ans < s {
			ans = s
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumWealth(accounts: number[][]): number {
    return accounts.reduce(
        (r, v) =>
            Math.max(
                r,
                v.reduce((r, v) => r + v),
            ),
        0,
    );
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map(|v| v.iter().sum()).max().unwrap()
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[][] $accounts
     * @return Integer
     */
    function maximumWealth($accounts) {
        $rs = 0;
        for ($i = 0; $i < count($accounts); $i++) {
            $sum = 0;
            for ($j = 0; $j < count($accounts[$i]); $j++) {
                $sum += $accounts[$i][$j];
            }
            if ($sum > $rs) {
                $rs = $sum;
            }
        }
        return $rs;
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int ans = INT_MIN;
    for (int i = 0; i < accountsSize; i++) {
        int sum = 0;
        for (int j = 0; j < accountsColSize[i]; j++) {
            sum += accounts[i][j];
        }
        ans = max(ans, sum);
    }
    return ans;
}
```

#### Kotlin

```kotlin
class Solution {
    fun maximumWealth(accounts: Array<IntArray>): Int {
        var max = 0
        for (account in accounts) {
            val sum = account.sum()
            if (sum > max) {
                max = sum
            }
        }
        return max
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1673. 找出最具竞争力的子序列](https://leetcode.cn/problems/find-the-most-competitive-subsequence){#1673}

{{< tabs "1673" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stk = []
        n = len(nums)
        for i, v in enumerate(nums):
            while stk and stk[-1] > v and len(stk) + n - i > k:
                stk.pop()
            if len(stk) < k:
                stk.append(v)
        return stk
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && stk.peek() > nums[i] && stk.size() + n - i > k) {
                stk.pop();
            }
            if (stk.size() < k) {
                stk.push(nums[i]);
            }
        }
        int[] ans = new int[stk.size()];
        for (int i = ans.length - 1; i >= 0; --i) {
            ans[i] = stk.pop();
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (stk.size() && stk.back() > nums[i] && stk.size() + n - i > k) {
                stk.pop_back();
            }
            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }
        return stk;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostCompetitive(nums []int, k int) []int {
	stk := []int{}
	n := len(nums)
	for i, v := range nums {
		for len(stk) > 0 && stk[len(stk)-1] > v && len(stk)+n-i > k {
			stk = stk[:len(stk)-1]
		}
		if len(stk) < k {
			stk = append(stk, v)
		}
	}
	return stk
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostCompetitive(nums: number[], k: number): number[] {
    const stk: number[] = [];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        while (stk.length && stk.at(-1)! > nums[i] && stk.length + n - i > k) {
            stk.pop();
        }
        if (stk.length < k) {
            stk.push(nums[i]);
        }
    }
    return stk;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个正整数 <code>k</code> ，返回长度为 <code>k</code> 且最具 <strong>竞争力</strong> 的<em> </em><code>nums</code> 子序列。</p>

<p>数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。</p>

<p>在子序列 <code>a</code> 和子序列 <code>b</code> 第一个不相同的位置上，如果 <code>a</code> 中的数字小于 <code>b</code> 中对应的数字，那么我们称子序列 <code>a</code> 比子序列 <code>b</code>（相同长度下）更具 <strong>竞争力</strong> 。 例如，<code>[1,3,4]</code> 比 <code>[1,3,5]</code> 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， <code>4</code> 小于 <code>5</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,5,2,6], k = 2
<strong>输出：</strong>[2,6]
<strong>解释：</strong>在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,3,3,5,4,9,6], k = 4
<strong>输出：</strong>[2,3,3,4]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= k <= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们从左到右遍历数组 `nums`，维护一个栈 `stk`，遍历过程中，如果当前元素 `nums[i]` 小于栈顶元素，且栈中元素个数加上 $n-i$ 大于 $k$，则将栈顶元素出栈，直到不满足上述条件为止。此时如果栈中元素个数小于 $k$，则将当前元素入栈。

遍历结束后，栈中元素即为所求。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stk = []
        n = len(nums)
        for i, v in enumerate(nums):
            while stk and stk[-1] > v and len(stk) + n - i > k:
                stk.pop()
            if len(stk) < k:
                stk.append(v)
        return stk
```

#### Java

```java
class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> stk = new ArrayDeque<>();
        int n = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && stk.peek() > nums[i] && stk.size() + n - i > k) {
                stk.pop();
            }
            if (stk.size() < k) {
                stk.push(nums[i]);
            }
        }
        int[] ans = new int[stk.size()];
        for (int i = ans.length - 1; i >= 0; --i) {
            ans[i] = stk.pop();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (stk.size() && stk.back() > nums[i] && stk.size() + n - i > k) {
                stk.pop_back();
            }
            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }
        return stk;
    }
};
```

#### Go

```go
func mostCompetitive(nums []int, k int) []int {
	stk := []int{}
	n := len(nums)
	for i, v := range nums {
		for len(stk) > 0 && stk[len(stk)-1] > v && len(stk)+n-i > k {
			stk = stk[:len(stk)-1]
		}
		if len(stk) < k {
			stk = append(stk, v)
		}
	}
	return stk
}
```

#### TypeScript

```ts
function mostCompetitive(nums: number[], k: number): number[] {
    const stk: number[] = [];
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        while (stk.length && stk.at(-1)! > nums[i] && stk.length + n - i > k) {
            stk.pop();
        }
        if (stk.length < k) {
            stk.push(nums[i]);
        }
    }
    return stk;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1674. 使数组互补的最少操作次数](https://leetcode.cn/problems/minimum-moves-to-make-array-complementary){#1674}

{{< tabs "1674" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        d = [0] * (2 * limit + 2)
        n = len(nums)
        for i in range(n // 2):
            x, y = nums[i], nums[-i - 1]
            if x > y:
                x, y = y, x
            d[2] += 2
            d[x + 1] -= 2
            d[x + 1] += 1
            d[x + y] -= 1
            d[x + y + 1] += 1
            d[y + limit + 1] -= 1
            d[y + limit + 1] += 2
        return min(accumulate(d[2:]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int[] nums, int limit) {
        int[] d = new int[2 * limit + 2];
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            int x = Math.min(nums[i], nums[n - i - 1]);
            int y = Math.max(nums[i], nums[n - i - 1]);
            d[2] += 2;
            d[x + 1] -= 2;
            d[x + 1] += 1;
            d[x + y] -= 1;
            d[x + y + 1] += 1;
            d[y + limit + 1] -= 1;
            d[y + limit + 1] += 2;
        }
        int ans = n;
        for (int i = 2, s = 0; i < d.length; ++i) {
            s += d[i];
            ans = Math.min(ans, s);
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
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int d[limit * 2 + 2];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n / 2; ++i) {
            int x = nums[i], y = nums[n - i - 1];
            if (x > y) {
                swap(x, y);
            }
            d[2] += 2;
            d[x + 1] -= 2;
            d[x + 1] += 1;
            d[x + y] -= 1;
            d[x + y + 1] += 1;
            d[y + limit + 1] -= 1;
            d[y + limit + 1] += 2;
        }
        int ans = n;
        for (int i = 2, s = 0; i <= limit * 2; ++i) {
            s += d[i];
            ans = min(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(nums []int, limit int) int {
	n := len(nums)
	d := make([]int, 2*limit+2)
	for i := 0; i < n/2; i++ {
		x, y := nums[i], nums[n-1-i]
		if x > y {
			x, y = y, x
		}
		d[2] += 2
		d[x+1] -= 2
		d[x+1] += 1
		d[x+y] -= 1
		d[x+y+1] += 1
		d[y+limit+1] -= 1
		d[y+limit+1] += 2
	}
	ans, s := n, 0
	for _, x := range d[2:] {
		s += x
		ans = min(ans, s)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMoves(nums: number[], limit: number): number {
    const n = nums.length;
    const d: number[] = Array(limit * 2 + 2).fill(0);
    for (let i = 0; i < n >> 1; ++i) {
        const x = Math.min(nums[i], nums[n - 1 - i]);
        const y = Math.max(nums[i], nums[n - 1 - i]);
        d[2] += 2;
        d[x + 1] -= 2;
        d[x + 1] += 1;
        d[x + y] -= 1;
        d[x + y + 1] += 1;
        d[y + limit + 1] -= 1;
        d[y + limit + 1] += 2;
    }
    let ans = n;
    let s = 0;
    for (let i = 2; i < d.length; ++i) {
        s += d[i];
        ans = Math.min(ans, s);
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

<p>给你一个长度为<strong> 偶数</strong> <code>n</code> 的整数数组 <code>nums</code> 和一个整数 <code>limit</code> 。每一次操作，你可以将 <code>nums</code> 中的任何整数替换为 <code>1</code> 到 <code>limit</code> 之间的另一个整数。</p>

<p>如果对于所有下标 <code>i</code>（<strong>下标从 </strong><code>0</code><strong> 开始</strong>），<code>nums[i] + nums[n - 1 - i]</code> 都等于同一个数，则数组 <code>nums</code> 是 <strong>互补的</strong> 。例如，数组 <code>[1,2,3,4]</code> 是互补的，因为对于所有下标 <code>i</code> ，<code>nums[i] + nums[n - 1 - i] = 5</code> 。</p>

<p>返回使数组 <strong>互补</strong> 的 <strong>最少</strong> 操作次数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,3], limit = 4
<strong>输出：</strong>1
<strong>解释：</strong>经过 1 次操作，你可以将数组 nums 变成 [1,2,<strong>2</strong>,3]（加粗元素是变更的数字）：
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
对于每个 i ，nums[i] + nums[n-1-i] = 4 ，所以 nums 是互补的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,1], limit = 2
<strong>输出：</strong>2
<strong>解释：</strong>经过 2 次操作，你可以将数组 nums 变成 [<strong>2</strong>,2,2,<strong>2</strong>] 。你不能将任何数字变更为 3 ，因为 3 > limit 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,2], limit = 2
<strong>输出：</strong>0
<strong>解释：</strong>nums 已经是互补的。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= limit <= 10<sup>5</sup></code></li>
	<li><code>n</code> 是偶数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

假设最终的数组中，数对 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的和为 $s$。

我们不妨设 $x$ 为 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的较小值，设 $y$ 为 $\textit{nums}[i]$ 和 $\textit{nums}[n-i-1]$ 的较大值。

对于每一对数，我们有以下几种情况：

-   如果不需要替换，那么 $x + y = s$。
-   如果替换一次，那么 $x + 1 \le s \le y + \textit{limit}$。
-   如果替换两次，那么 $2 \le s \le x$ 或 $y + \textit{limit} + 1 \le s \le 2 \times \textit{limit}$。

即：

-   在 $[2,..x]$ 范围内，需要替换 $2$ 次。
-   在 $[x+1,..x+y-1]$ 范围内，需要替换 $1$ 次。
-   在 $[x+y]$ 时，不需要替换。
-   在 $[x+y+1,..y + \textit{limit}]$ 范围内，需要替换 $1$ 次。
-   在 $[y + \textit{limit} + 1,..2 \times \textit{limit}]$ 范围内，需要替换 $2$ 次。

我们枚举每一个数对，利用差分数组，更新每个数对在不同区间范围内的替换次数。

最后，我们求出下标 $2$ 到 $2 \times \textit{limit}$ 的前缀和中的最小值，即为最少的替换次数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

相似题目：

-   [3224. 使差值相等的最少数组改动次数](https://github.com/doocs/leetcode/blob/main/solution/3200-3299/3224.Minimum%20Array%20Changes%20to%20Make%20Differences%20Equal/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        d = [0] * (2 * limit + 2)
        n = len(nums)
        for i in range(n // 2):
            x, y = nums[i], nums[-i - 1]
            if x > y:
                x, y = y, x
            d[2] += 2
            d[x + 1] -= 2
            d[x + 1] += 1
            d[x + y] -= 1
            d[x + y + 1] += 1
            d[y + limit + 1] -= 1
            d[y + limit + 1] += 2
        return min(accumulate(d[2:]))
```

#### Java

```java
class Solution {
    public int minMoves(int[] nums, int limit) {
        int[] d = new int[2 * limit + 2];
        int n = nums.length;
        for (int i = 0; i < n / 2; ++i) {
            int x = Math.min(nums[i], nums[n - i - 1]);
            int y = Math.max(nums[i], nums[n - i - 1]);
            d[2] += 2;
            d[x + 1] -= 2;
            d[x + 1] += 1;
            d[x + y] -= 1;
            d[x + y + 1] += 1;
            d[y + limit + 1] -= 1;
            d[y + limit + 1] += 2;
        }
        int ans = n;
        for (int i = 2, s = 0; i < d.length; ++i) {
            s += d[i];
            ans = Math.min(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int d[limit * 2 + 2];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n / 2; ++i) {
            int x = nums[i], y = nums[n - i - 1];
            if (x > y) {
                swap(x, y);
            }
            d[2] += 2;
            d[x + 1] -= 2;
            d[x + 1] += 1;
            d[x + y] -= 1;
            d[x + y + 1] += 1;
            d[y + limit + 1] -= 1;
            d[y + limit + 1] += 2;
        }
        int ans = n;
        for (int i = 2, s = 0; i <= limit * 2; ++i) {
            s += d[i];
            ans = min(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func minMoves(nums []int, limit int) int {
	n := len(nums)
	d := make([]int, 2*limit+2)
	for i := 0; i < n/2; i++ {
		x, y := nums[i], nums[n-1-i]
		if x > y {
			x, y = y, x
		}
		d[2] += 2
		d[x+1] -= 2
		d[x+1] += 1
		d[x+y] -= 1
		d[x+y+1] += 1
		d[y+limit+1] -= 1
		d[y+limit+1] += 2
	}
	ans, s := n, 0
	for _, x := range d[2:] {
		s += x
		ans = min(ans, s)
	}
	return ans
}
```

#### TypeScript

```ts
function minMoves(nums: number[], limit: number): number {
    const n = nums.length;
    const d: number[] = Array(limit * 2 + 2).fill(0);
    for (let i = 0; i < n >> 1; ++i) {
        const x = Math.min(nums[i], nums[n - 1 - i]);
        const y = Math.max(nums[i], nums[n - 1 - i]);
        d[2] += 2;
        d[x + 1] -= 2;
        d[x + 1] += 1;
        d[x + y] -= 1;
        d[x + y + 1] += 1;
        d[y + limit + 1] -= 1;
        d[y + limit + 1] += 2;
    }
    let ans = n;
    let s = 0;
    for (let i = 2; i < d.length; ++i) {
        s += d[i];
        ans = Math.min(ans, s);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1675. 数组的最小偏移量](https://leetcode.cn/problems/minimize-deviation-in-array){#1675}

{{< tabs "1675" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        h = []
        mi = inf
        for v in nums:
            if v & 1:
                v <<= 1
            h.append(-v)
            mi = min(mi, v)
        heapify(h)
        ans = -h[0] - mi
        while h[0] % 2 == 0:
            x = heappop(h) // 2
            heappush(h, x)
            mi = min(mi, -x)
            ans = min(ans, -h[0] - mi)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> b - a);
        int mi = Integer.MAX_VALUE;
        for (int v : nums) {
            if (v % 2 == 1) {
                v <<= 1;
            }
            q.offer(v);
            mi = Math.min(mi, v);
        }
        int ans = q.peek() - mi;
        while (q.peek() % 2 == 0) {
            int x = q.poll() / 2;
            q.offer(x);
            mi = Math.min(mi, x);
            ans = Math.min(ans, q.peek() - mi);
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
    int minimumDeviation(vector<int>& nums) {
        int mi = INT_MAX;
        priority_queue<int> pq;
        for (int v : nums) {
            if (v & 1) v <<= 1;
            pq.push(v);
            mi = min(mi, v);
        }
        int ans = pq.top() - mi;
        while (pq.top() % 2 == 0) {
            int x = pq.top() >> 1;
            pq.pop();
            pq.push(x);
            mi = min(mi, x);
            ans = min(ans, pq.top() - mi);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDeviation(nums []int) int {
	q := hp{}
	mi := math.MaxInt32
	for _, v := range nums {
		if v%2 == 1 {
			v <<= 1
		}
		heap.Push(&q, v)
		mi = min(mi, v)
	}
	ans := q.IntSlice[0] - mi
	for q.IntSlice[0]%2 == 0 {
		x := heap.Pop(&q).(int) >> 1
		heap.Push(&q, x)
		mi = min(mi, x)
		ans = min(ans, q.IntSlice[0]-mi)
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>n</code> 个正整数组成的数组 <code>nums</code> 。</p>

<p>你可以对数组的任意元素执行任意次数的两类操作：</p>

<ul>
	<li>如果元素是<strong> 偶数</strong> ，<strong>除以</strong> <code>2</code>

    <ul>
    	<li>例如，如果数组是 <code>[1,2,3,4]</code> ，那么你可以对最后一个元素执行此操作，使其变成 <code>[1,2,3,<strong>2</strong>]</code></li>
    </ul>
    </li>
    <li>如果元素是 <strong>奇数</strong> ，<strong>乘上</strong> <code>2</code>
    <ul>
    	<li>例如，如果数组是 <code>[1,2,3,4]</code> ，那么你可以对第一个元素执行此操作，使其变成 <code>[<strong>2</strong>,2,3,4]</code></li>
    </ul>
    </li>

</ul>

<p>数组的 <strong>偏移量</strong> 是数组中任意两个元素之间的 <strong>最大差值</strong> 。</p>

<p>返回数组在执行某些操作之后可以拥有的 <strong>最小偏移量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>1
<strong>解释：</strong>你可以将数组转换为 [1,2,3,<strong>2</strong>]，然后转换成 [<strong>2</strong>,2,3,2]，偏移量是 3 - 2 = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,1,5,20,3]
<strong>输出：</strong>3
<strong>解释：</strong>两次操作后，你可以将数组转换为 [4,<strong>2</strong>,5,<strong>5</strong>,3]，偏移量是 5 - 2 = 3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,10,8]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup><span style="font-size: 10.8333px;">4</span></sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列

直观上，为了得到数组的最小偏移量，我们需要将减小数组的最大值，增大数组的最小值。

由于每次可以执行乘、除两种操作：将奇数乘以 $2$；将偶数除以 $2$，情况较为复杂，我们可以将奇数统一乘以 $2$，转成偶数，这样就等价于只有一种除法操作。除法操作只能减少某个数，而只有减少最大值，结果才可能更优。

因此，我们用优先队列（大根堆）维护数组的最大值，每次取出堆顶元素做除法操作，将新值放入堆中，并且更新最小值以及堆顶元素与最小值的差值的最小值。

当堆顶元素为奇数时，操作停止。

时间复杂度 $O(n\log n \times \log m)$。其中 $n$, $m$ 分别是数组 `nums` 的长度以及数组的最大元素。由于数组中的最大元素除以 $2$ 的操作最多有 $O(\log m)$ 次，因此全部元素除以 $2$ 的操作最多有 $O(n\log m)$ 次。每次弹出、放入堆的操作，时间复杂度为 $O(\log n)$。因此，总的时间复杂度为 $O(n\log n \times \log m)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        h = []
        mi = inf
        for v in nums:
            if v & 1:
                v <<= 1
            h.append(-v)
            mi = min(mi, v)
        heapify(h)
        ans = -h[0] - mi
        while h[0] % 2 == 0:
            x = heappop(h) // 2
            heappush(h, x)
            mi = min(mi, -x)
            ans = min(ans, -h[0] - mi)
        return ans
```

#### Java

```java
class Solution {
    public int minimumDeviation(int[] nums) {
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> b - a);
        int mi = Integer.MAX_VALUE;
        for (int v : nums) {
            if (v % 2 == 1) {
                v <<= 1;
            }
            q.offer(v);
            mi = Math.min(mi, v);
        }
        int ans = q.peek() - mi;
        while (q.peek() % 2 == 0) {
            int x = q.poll() / 2;
            q.offer(x);
            mi = Math.min(mi, x);
            ans = Math.min(ans, q.peek() - mi);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mi = INT_MAX;
        priority_queue<int> pq;
        for (int v : nums) {
            if (v & 1) v <<= 1;
            pq.push(v);
            mi = min(mi, v);
        }
        int ans = pq.top() - mi;
        while (pq.top() % 2 == 0) {
            int x = pq.top() >> 1;
            pq.pop();
            pq.push(x);
            mi = min(mi, x);
            ans = min(ans, pq.top() - mi);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDeviation(nums []int) int {
	q := hp{}
	mi := math.MaxInt32
	for _, v := range nums {
		if v%2 == 1 {
			v <<= 1
		}
		heap.Push(&q, v)
		mi = min(mi, v)
	}
	ans := q.IntSlice[0] - mi
	for q.IntSlice[0]%2 == 0 {
		x := heap.Pop(&q).(int) >> 1
		heap.Push(&q, x)
		mi = min(mi, x)
		ans = min(ans, q.IntSlice[0]-mi)
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1676. 二叉树的最近公共祖先 IV 🔒](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-iv){#1676}

{{< tabs "1676" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: 'TreeNode', nodes: 'List[TreeNode]'
    ) -> 'TreeNode':
        def dfs(root):
            if root is None or root.val in s:
                return root
            left, right = dfs(root.left), dfs(root.right)
            if left and right:
                return root
            return left or right

        s = {node.val for node in nodes}
        return dfs(root)
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
    private Set<Integer> s = new HashSet<>();

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
        for (TreeNode node : nodes) {
            s.add(node.val);
        }
        return dfs(root);
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null || s.contains(root.val)) {
            return root;
        }
        TreeNode left = dfs(root.left);
        TreeNode right = dfs(root.right);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        unordered_set<int> s;
        for (auto node : nodes) {
            s.insert(node->val);
        }
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> TreeNode* {
            if (!root || s.contains(root->val)) {
                return root;
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            if (!left) {
                return right;
            }
            if (!right) {
                return left;
            }
            return root;
        };
        return dfs(root);
    }
};
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
 * @param {TreeNode[]} nodes
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, nodes) {
    const s = new Set();
    for (const node of nodes) {
        s.add(node.val);
    }
    function dfs(root) {
        if (!root || s.has(root.val)) {
            return root;
        }
        const [left, right] = [dfs(root.left), dfs(root.right)];
        if (left && right) {
            return root;
        }
        return left || right;
    }
    return dfs(root);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点 <code>root</code> 和 <code>TreeNode</code> 类对象的数组（列表） <code>nodes</code>，返回<em> </em><code>nodes</code> 中所有节点的最近公共祖先（LCA）。数组（列表）中所有节点都存在于该二叉树中，且二叉树中所有节点的值都是互不相同的。</p>

<p>我们扩展<a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">二叉树的最近公共祖先节点在维基百科上的定义</a>：“对于任意合理的 <code>i</code> 值， <code>n</code> 个节点 <code>p<sub>1</sub></code> 、 <code>p<sub>2</sub></code>、...、 <code>p<sub>n</sub></code> 在二叉树 <code>T</code> 中的最近公共祖先节点是<strong>后代</strong>中包含所有节点 <code>p<sub>i</sub></code> 的最深节点（我们允许一个节点是其自身的后代）”。一个节点 <code>x</code> 的后代节点是节点 <code>x</code> 到某一叶节点间的路径中的节点 <code>y</code>。</p>

<p> </p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1676.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20IV/images/binarytree.png">
<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
<strong>输出:</strong> 2
<strong>解释:</strong> 节点 4 和 7 的最近公共祖先是 2。
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1676.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20IV/images/binarytree.png">
<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
<strong>输出:</strong> 1
<strong>解释:</strong> 单个节点的最近公共祖先是该节点本身。

</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1676.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20IV/images/binarytree.png">
<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
<strong>输出:</strong> 5
<strong>解释:</strong> 节点 7、6、2 和 4 的最近公共祖先节点是 5。
</pre>

<p><strong>示例 4:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1676.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20IV/images/binarytree.png">
<pre><strong>输入:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [0,1,2,3,4,5,6,7,8]
<strong>输出:</strong> 3
<strong>解释:</strong> 树中所有节点的最近公共祖先是根节点。
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是 <code>[1, 10<sup>4</sup>]</code> 。</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>所有的 <code>Node.val</code> 都是<strong>互不相同</strong>的。</li>
	<li>所有的 <code>nodes[i]</code> 都存在于该树中。</li>
	<li>所有的 <code>nodes[i]</code> 都是互不相同的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + DFS

我们用一个哈希表 $\textit{s}$ 记录数组 $\textit{nodes}$ 中所有节点的值，然后使用深度优先搜索，当遍历到的节点为空或者节点的值在哈希表 $\textit{s}$ 中时，返回当前节点。否则，递归遍历左右子树，如果左右子树的返回值都不为空，说明当前节点就是最近公共祖先，否则返回不为空的那个子树的返回值。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是二叉树的节点数和数组 $\textit{nodes}$ 的长度。

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
    def lowestCommonAncestor(
        self, root: 'TreeNode', nodes: 'List[TreeNode]'
    ) -> 'TreeNode':
        def dfs(root):
            if root is None or root.val in s:
                return root
            left, right = dfs(root.left), dfs(root.right)
            if left and right:
                return root
            return left or right

        s = {node.val for node in nodes}
        return dfs(root)
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
    private Set<Integer> s = new HashSet<>();

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
        for (TreeNode node : nodes) {
            s.add(node.val);
        }
        return dfs(root);
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null || s.contains(root.val)) {
            return root;
        }
        TreeNode left = dfs(root.left);
        TreeNode right = dfs(root.right);
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        unordered_set<int> s;
        for (auto node : nodes) {
            s.insert(node->val);
        }
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> TreeNode* {
            if (!root || s.contains(root->val)) {
                return root;
            }
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            if (!left) {
                return right;
            }
            if (!right) {
                return left;
            }
            return root;
        };
        return dfs(root);
    }
};
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
 * @param {TreeNode[]} nodes
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, nodes) {
    const s = new Set();
    for (const node of nodes) {
        s.add(node.val);
    }
    function dfs(root) {
        if (!root || s.has(root.val)) {
            return root;
        }
        const [left, right] = [dfs(root.left), dfs(root.right)];
        if (left && right) {
            return root;
        }
        return left || right;
    }
    return dfs(root);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1677. 发票中的产品金额 🔒](https://leetcode.cn/problems/products-worth-over-invoices){#1677}

{{< tabs "1677" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    name,
    IFNULL(SUM(rest), 0) AS rest,
    IFNULL(SUM(paid), 0) AS paid,
    IFNULL(SUM(canceled), 0) AS canceled,
    IFNULL(SUM(refunded), 0) AS refunded
FROM
    Product
    LEFT JOIN Invoice USING (product_id)
GROUP BY product_id
ORDER BY name;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Product</code> 表：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| name        | varchar |
+-------------+---------+
product_id 是这张表的主键
表中含有产品 id 、产品名称。产品名称都是小写的英文字母，产品名称都是唯一的
</pre>

<p><code>Invoice </code>表：</p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| invoice_id  | int  |
| product_id  | int  |
| rest        | int  |
| paid        | int  |
| canceled    | int  |
| refunded    | int  |
+-------------+------+
invoice_id 发票 id ，是这张表的主键
product_id 产品 id
rest 应缴款项
paid 已支付金额
canceled 已取消金额
refunded 已退款金额
</pre>

<p> </p>

<p>要求写一个SQL查询，对于所有产品，返回每个产品的产品名称，以及全部发票累计的总应缴款项、总已支付金额、总已取消金额、总已退款金额。</p>

<p>查询结果按 <code>product_name</code> 排序</p>

<p>示例：</p>

<pre>
Product 表：
+------------+-------+
| product_id | name  |
+------------+-------+
| 0          | ham   |
| 1          | bacon |
+------------+-------+
Invoice table:
+------------+------------+------+------+----------+----------+
| invoice_id | product_id | rest | paid | canceled | refunded |
+------------+------------+------+------+----------+----------+
| 23         | 0          | 2    | 0    | 5        | 0        |
| 12         | 0          | 0    | 4    | 0        | 3        |
| 1          | 1          | 1    | 1    | 0        | 1        |
| 2          | 1          | 1    | 0    | 1        | 1        |
| 3          | 1          | 0    | 1    | 1        | 1        |
| 4          | 1          | 1    | 1    | 1        | 0        |
+------------+------------+------+------+----------+----------+
Result 表：
+-------+------+------+----------+----------+
| name  | rest | paid | canceled | refunded |
+-------+------+------+----------+----------+
| bacon | 3    | 3    | 3        | 3        |
| ham   | 2    | 4    | 5        | 3        |
+-------+------+------+----------+----------+
- bacon 的总应缴款项为 1 + 1 + 0 + 1 = 3
- bacon 的总已支付金额为 1 + 0 + 1 + 1 = 3
- bacon 的总已取消金额为 0 + 1 + 1 + 1 = 3
- bacon 的总已退款金额为 1 + 1 + 1 + 0 = 3
- ham 的总应缴款项为 2 + 0 = 2
- ham 的总已支付金额为 0 + 4 = 4
- ham 的总已取消金额为 5 + 0 = 5
- ham 的总已退款金额为 0 + 3 = 3
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

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    name,
    IFNULL(SUM(rest), 0) AS rest,
    IFNULL(SUM(paid), 0) AS paid,
    IFNULL(SUM(canceled), 0) AS canceled,
    IFNULL(SUM(refunded), 0) AS refunded
FROM
    Product
    LEFT JOIN Invoice USING (product_id)
GROUP BY product_id
ORDER BY name;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1678. 设计 Goal 解析器](https://leetcode.cn/problems/goal-parser-interpretation){#1678}

{{< tabs "1678" >}}

{{% tab "python" %}}
```python
class Solution:
    def interpret(self, command: str) -> str:
        ans = []
        for i, c in enumerate(command):
            if c == 'G':
                ans.append(c)
            elif c == '(':
                ans.append('o' if command[i + 1] == ')' else 'al')
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String interpret(String command) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < command.length(); ++i) {
            char c = command.charAt(i);
            if (c == 'G') {
                ans.append(c);
            } else if (c == '(') {
                ans.append(command.charAt(i + 1) == ')' ? "o" : "al");
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); ++i) {
            char c = command[i];
            if (c == 'G')
                ans += c;
            else if (c == '(')
                ans += command[i + 1] == ')' ? "o" : "al";
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func interpret(command string) string {
	ans := &strings.Builder{}
	for i, c := range command {
		if c == 'G' {
			ans.WriteRune(c)
		} else if c == '(' {
			if command[i+1] == ')' {
				ans.WriteByte('o')
			} else {
				ans.WriteString("al")
			}
		}
	}
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function interpret(command: string): string {
    const n = command.length;
    const ans: string[] = [];
    for (let i = 0; i < n; i++) {
        const c = command[i];
        if (c === 'G') {
            ans.push(c);
        } else if (c === '(') {
            ans.push(command[i + 1] === ')' ? 'o' : 'al');
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn interpret(command: String) -> String {
        let mut ans = String::new();
        let bs = command.as_bytes();
        for i in 0..bs.len() {
            if bs[i] == b'G' {
                ans.push_str("G");
            }
            if bs[i] == b'(' {
                ans.push_str({
                    if bs[i + 1] == b')' {
                        "o"
                    } else {
                        "al"
                    }
                });
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* interpret(char* command) {
    int n = strlen(command);
    char* ans = malloc(sizeof(char) * n + 1);
    int i = 0;
    for (int j = 0; j < n; j++) {
        char c = command[j];
        if (c == 'G') {
            ans[i++] = 'G';
        } else if (c == '(') {
            if (command[j + 1] == ')') {
                ans[i++] = 'o';
            } else {
                ans[i++] = 'a';
                ans[i++] = 'l';
            }
        }
    }
    ans[i] = '\0';
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个可以解释字符串 <code>command</code> 的 <strong>Goal 解析器</strong> 。<code>command</code> 由 <code>"G"</code>、<code>"()"</code> 和/或 <code>"(al)"</code> 按某种顺序组成。Goal 解析器会将 <code>"G"</code> 解释为字符串 <code>"G"</code>、<code>"()"</code> 解释为字符串 <code>"o"</code> ，<code>"(al)"</code> 解释为字符串 <code>"al"</code> 。然后，按原顺序将经解释得到的字符串连接成一个字符串。</p>

<p>给你字符串 <code>command</code> ，返回<em> </em><strong>Goal<em><strong> </strong></em>解析器 </strong>对<em> </em><code>command</code> 的解释结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>command = "G()(al)"
<strong>输出：</strong>"Goal"
<strong>解释：</strong>Goal 解析器解释命令的步骤如下所示：
G -&gt; G
() -&gt; o
(al) -&gt; al
最后连接得到的结果是 "Goal"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>command = "G()()()()(al)"
<strong>输出：</strong>"Gooooal"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>command = "(al)G(al)()()G"
<strong>输出：</strong>"alGalooG"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= command.length &lt;= 100</code></li>
	<li><code>command</code> 由 <code>"G"</code>、<code>"()"</code> 和/或 <code>"(al)"</code> 按某种顺序组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串替换

根据题意，只需要将字符串 `command` 中的 `"()"` 替换为 `'o'`，`"(al)"` 替换为 `"al"` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $command$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def interpret(self, command: str) -> str:
        return command.replace('()', 'o').replace('(al)', 'al')
```

#### Java

```java
class Solution {
    public String interpret(String command) {
        return command.replace("()", "o").replace("(al)", "al");
    }
}
```

#### C++

```cpp
class Solution {
public:
    string interpret(string command) {
        while (command.find("()") != -1) command.replace(command.find("()"), 2, "o");
        while (command.find("(al)") != -1) command.replace(command.find("(al)"), 4, "al");
        return command;
    }
};
```

#### Go

```go
func interpret(command string) string {
	command = strings.ReplaceAll(command, "()", "o")
	command = strings.ReplaceAll(command, "(al)", "al")
	return command
}
```

#### TypeScript

```ts
function interpret(command: string): string {
    return command.replace(/\(\)/g, 'o').replace(/\(al\)/g, 'al');
}
```

#### Rust

```rust
impl Solution {
    pub fn interpret(command: String) -> String {
        command.replace("()", "o").replace("(al)", "al")
    }
}
```

#### C

```c
char* interpret(char* command) {
    int n = strlen(command);
    char* ans = malloc(sizeof(char) * n + 1);
    int i = 0;
    for (int j = 0; j < n; j++) {
        char c = command[j];
        if (c == 'G') {
            ans[i++] = 'G';
        } else if (c == '(') {
            if (command[j + 1] == ')') {
                ans[i++] = 'o';
            } else {
                ans[i++] = 'a';
                ans[i++] = 'l';
            }
        }
    }
    ans[i] = '\0';
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字符串遍历

我们也可以遍历字符串 `command`，对于每个字符 $c$：

-   如果是 `'G'`，直接将 $c$ 添加到结果串中；
-   如果是 `'('`，判断下一个字符是否是 `')'`，若是，将 `'o'` 添加到结果串中，否则，将 `"al"` 添加到结果串中。

遍历结束，返回结果串即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $command$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def interpret(self, command: str) -> str:
        ans = []
        for i, c in enumerate(command):
            if c == 'G':
                ans.append(c)
            elif c == '(':
                ans.append('o' if command[i + 1] == ')' else 'al')
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String interpret(String command) {
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < command.length(); ++i) {
            char c = command.charAt(i);
            if (c == 'G') {
                ans.append(c);
            } else if (c == '(') {
                ans.append(command.charAt(i + 1) == ')' ? "o" : "al");
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); ++i) {
            char c = command[i];
            if (c == 'G')
                ans += c;
            else if (c == '(')
                ans += command[i + 1] == ')' ? "o" : "al";
        }
        return ans;
    }
};
```

#### Go

```go
func interpret(command string) string {
	ans := &strings.Builder{}
	for i, c := range command {
		if c == 'G' {
			ans.WriteRune(c)
		} else if c == '(' {
			if command[i+1] == ')' {
				ans.WriteByte('o')
			} else {
				ans.WriteString("al")
			}
		}
	}
	return ans.String()
}
```

#### TypeScript

```ts
function interpret(command: string): string {
    const n = command.length;
    const ans: string[] = [];
    for (let i = 0; i < n; i++) {
        const c = command[i];
        if (c === 'G') {
            ans.push(c);
        } else if (c === '(') {
            ans.push(command[i + 1] === ')' ? 'o' : 'al');
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn interpret(command: String) -> String {
        let mut ans = String::new();
        let bs = command.as_bytes();
        for i in 0..bs.len() {
            if bs[i] == b'G' {
                ans.push_str("G");
            }
            if bs[i] == b'(' {
                ans.push_str({
                    if bs[i + 1] == b')' {
                        "o"
                    } else {
                        "al"
                    }
                });
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

# [1679. K 和数对的最大数目](https://leetcode.cn/problems/max-number-of-k-sum-pairs){#1679}

{{< tabs "1679" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        ans = 0
        for x in nums:
            if cnt[k - x]:
                ans += 1
                cnt[k - x] -= 1
            else:
                cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int x : nums) {
            if (cnt.containsKey(k - x)) {
                ++ans;
                if (cnt.merge(k - x, -1, Integer::sum) == 0) {
                    cnt.remove(k - x);
                }
            } else {
                cnt.merge(x, 1, Integer::sum);
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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int& x : nums) {
            if (cnt[k - x]) {
                --cnt[k - x];
                ++ans;
            } else {
                ++cnt[x];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxOperations(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		if cnt[k-x] > 0 {
			cnt[k-x]--
			ans++
		} else {
			cnt[x]++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxOperations(nums: number[], k: number): number {
    const cnt = new Map();
    let ans = 0;
    for (const x of nums) {
        if (cnt.get(k - x)) {
            cnt.set(k - x, cnt.get(k - x) - 1);
            ++ans;
        } else {
            cnt.set(x, (cnt.get(x) | 0) + 1);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = std::collections::HashMap::new();
        let mut ans = 0;
        for x in nums {
            let m = k - x;
            if let Some(v) = cnt.get_mut(&m) {
                ans += 1;
                *v -= 1;
                if *v == 0 {
                    cnt.remove(&m);
                }
            } else if let Some(v) = cnt.get_mut(&x) {
                *v += 1;
            } else {
                cnt.insert(x, 1);
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>每一步操作中，你需要从数组中选出和为 <code>k</code> 的两个整数，并将它们移出数组。</p>

<p>返回你可以对数组执行的最大操作数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], k = 5
<strong>输出：</strong>2
<strong>解释：</strong>开始时 nums = [1,2,3,4]：
- 移出 1 和 4 ，之后 nums = [2,3]
- 移出 2 和 3 ，之后 nums = []
不再有和为 5 的数对，因此最多执行 2 次操作。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,3,4,3], k = 6
<strong>输出：</strong>1
<strong>解释：</strong>开始时 nums = [3,1,3,4,3]：
- 移出前两个 3 ，之后nums = [1,4,3]
不再有和为 6 的数对，因此最多执行 1 次操作。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= k <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们对 $nums$ 进行排序。然后 $l$, $r$ 分别指向 $nums$ 首尾元素，判断两整数之和 $s$ 与 $k$ 的大小关系。

-   若 $s = k$，说明找到了两个整数，满足和为 $k$，答案加一，然后 $l$, $r$ 向中间移动；
-   若 $s \gt k$，则 $r$ 指针向左移动；
-   若 $s \lt k$，则 $l$ 指针向右移动；
-   继续循环判断，直至 $l \geq r$。

循环结束，返回答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        l, r, ans = 0, len(nums) - 1, 0
        while l < r:
            s = nums[l] + nums[r]
            if s == k:
                ans += 1
                l, r = l + 1, r - 1
            elif s > k:
                r -= 1
            else:
                l += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = nums.length - 1;
        int ans = 0;
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s == k) {
                ++ans;
                ++l;
                --r;
            } else if (s > k) {
                --r;
            } else {
                ++l;
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
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                i++;
                j--;
                cnt++;
            } else if (nums[i] + nums[j] > k) {
                j--;
            } else {
                i++;
            }
        }
        return cnt;
    }
};
```

#### Go

```go
func maxOperations(nums []int, k int) int {
	sort.Ints(nums)
	l, r, ans := 0, len(nums)-1, 0
	for l < r {
		s := nums[l] + nums[r]
		if s == k {
			ans++
			l++
			r--
		} else if s > k {
			r--
		} else {
			l++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxOperations(nums: number[], k: number): number {
    const cnt = new Map();
    let ans = 0;
    for (const x of nums) {
        if (cnt.get(k - x)) {
            cnt.set(k - x, cnt.get(k - x) - 1);
            ++ans;
        } else {
            cnt.set(x, (cnt.get(x) | 0) + 1);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums.clone();
        nums.sort();
        let (mut l, mut r, mut ans) = (0, nums.len() - 1, 0);
        while l < r {
            match nums[l] + nums[r] {
                sum if sum == k => {
                    ans += 1;
                    l += 1;
                    r -= 1;
                }
                sum if sum > k => {
                    r -= 1;
                }
                _ => {
                    l += 1;
                }
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

我们使用哈希表 $cnt$ 记录当前剩余整数及其出现的次数。

遍历 $nums$，对于当前整数 $x$，判断 $k - x$ 是否在 $cnt$ 中，若存在，则说明找到了两个整数，满足和为 $k$，答案加一，然后将 $k - x$ 的出现次数减一；否则，将 $x$ 的出现次数加一。

遍历结束，返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        ans = 0
        for x in nums:
            if cnt[k - x]:
                ans += 1
                cnt[k - x] -= 1
            else:
                cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int x : nums) {
            if (cnt.containsKey(k - x)) {
                ++ans;
                if (cnt.merge(k - x, -1, Integer::sum) == 0) {
                    cnt.remove(k - x);
                }
            } else {
                cnt.merge(x, 1, Integer::sum);
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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int& x : nums) {
            if (cnt[k - x]) {
                --cnt[k - x];
                ++ans;
            } else {
                ++cnt[x];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxOperations(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		if cnt[k-x] > 0 {
			cnt[k-x]--
			ans++
		} else {
			cnt[x]++
		}
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = std::collections::HashMap::new();
        let mut ans = 0;
        for x in nums {
            let m = k - x;
            if let Some(v) = cnt.get_mut(&m) {
                ans += 1;
                *v -= 1;
                if *v == 0 {
                    cnt.remove(&m);
                }
            } else if let Some(v) = cnt.get_mut(&x) {
                *v += 1;
            } else {
                cnt.insert(x, 1);
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

---
title: "0707_DesignLinkedList"
date: 2025-10-06T00:42:37+08:00
weight: 0707
tags: [设计, 链表]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [707. 设计链表](https://leetcode.cn/problems/design-linked-list)

[English Version](../en/0707-07/0707_DesignLinkedList)

## 题目描述

<!-- description:start -->

<p>你可以选择使用单链表或者双链表，设计并实现自己的链表。</p>

<p>单链表中的节点应该具备两个属性：<code>val</code> 和 <code>next</code> 。<code>val</code> 是当前节点的值，<code>next</code> 是指向下一个节点的指针/引用。</p>

<p>如果是双向链表，则还需要属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点下标从 <strong>0</strong> 开始。</p>

<p>实现 <code>MyLinkedList</code> 类：</p>

<ul>
	<li><code>MyLinkedList()</code> 初始化 <code>MyLinkedList</code> 对象。</li>
	<li><code>int get(int index)</code> 获取链表中下标为 <code>index</code> 的节点的值。如果下标无效，则返回 <code>-1</code> 。</li>
	<li><code>void addAtHead(int val)</code> 将一个值为 <code>val</code> 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。</li>
	<li><code>void addAtTail(int val)</code> 将一个值为 <code>val</code> 的节点追加到链表中作为链表的最后一个元素。</li>
	<li><code>void addAtIndex(int index, int val)</code> 将一个值为 <code>val</code> 的节点插入到链表中下标为 <code>index</code> 的节点之前。如果 <code>index</code> 等于链表的长度，那么该节点会被追加到链表的末尾。如果 <code>index</code> 比长度更大，该节点将 <strong>不会插入</strong> 到链表中。</li>
	<li><code>void deleteAtIndex(int index)</code> 如果下标有效，则删除链表中下标为 <code>index</code> 的节点。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入</strong>
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
<strong>输出</strong>
[null, null, null, null, 2, null, 3]

<strong>解释</strong>
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1-&gt;2-&gt;3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1-&gt;3
myLinkedList.get(1);              // 返回 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= index, val &lt;= 1000</code></li>
	<li>请不要使用内置的 LinkedList 库。</li>
	<li>调用 <code>get</code>、<code>addAtHead</code>、<code>addAtTail</code>、<code>addAtIndex</code> 和 <code>deleteAtIndex</code> 的次数不超过 <code>2000</code> 。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：指针引用实现单链表

我们创建链表虚拟头节点 `dummy`，用变量 `cnt` 记录当前链表节点个数。

具体的方法如下：

-   `get(index)`：遍历链表，找到第 `index` 个节点，返回其值，如果不存在，返回 $-1$。时间复杂度 $O(n)$。
-   `addAtHead(val)`：创建新节点，将其插入到虚拟头节点后面。时间复杂度 $O(1)$。
-   `addAtTail(val)`：创建新节点，将其插入到链表尾部。时间复杂度 $O(n)$。
-   `addAtIndex(index, val)`：如果 `index` 等于链表长度，则该节点将附加到链表的末尾。如果 `index` 大于链表长度，则不会插入节点。如果 `index` 小于 $0$，则在头部插入节点。否则，遍历链表，找到第 `index` 个节点的前一个节点，将新节点插入到该节点后面。时间复杂度 $O(n)$。
-   `deleteAtIndex(index)`：如果索引 `index` 有效，则删除链表中的第 `index` 个节点。否则，不做任何操作。时间复杂度 $O(n)$。

时间复杂度见具体的方法说明。其中 $n$ 为链表长度。

注意：LeetCode 平台已经内置 ListNode 单链表节点类，可以直接使用。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：静态数组实现单链表

在方法一中，我们使用了指针引用的方式，每次动态创建一个链表节点。在链表节点数量达到 $10^5$ 甚至更大时，频繁执行 new 操作，会大大增加程序的执行耗时。

因此，我们可以使用静态数组来实现单链表，预先申请一块大小略大于数据范围的内存空间，每次插入节点时，从数组中取出一个空闲的位置，将新节点插入到该位置，同时更新该位置的前驱和后继节点的指针引用。

我们定义以下几个变量，其中：

-   `head` 存放链表头节点的索引，初始时指向 $-1$。
-   `e` 存放链表所有节点的值（预先申请）。
-   `ne` 存放链表所有节点的 `next` 指针（预先申请）。
-   `idx` 指向当前可分配的节点索引，初始时指向索引 $0$。
-   `cnt` 记录当前链表节点个数，初始时为 $0$。

具体操作可参考以下代码。时间复杂度与方法一相同。

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
class MyLinkedList:
    def __init__(self):
        self.e = [0] * 1010
        self.ne = [0] * 1010
        self.idx = 0
        self.head = -1
        self.cnt = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.cnt:
            return -1
        i = self.head
        for _ in range(index):
            i = self.ne[i]
        return self.e[i]

    def addAtHead(self, val: int) -> None:
        self.e[self.idx] = val
        self.ne[self.idx] = self.head
        self.head = self.idx
        self.idx += 1
        self.cnt += 1

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.cnt, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.cnt:
            return
        if index <= 0:
            self.addAtHead(val)
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.e[self.idx] = val
        self.ne[self.idx] = self.ne[i]
        self.ne[i] = self.idx
        self.idx += 1
        self.cnt += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.cnt:
            return -1
        self.cnt -= 1
        if index == 0:
            self.head = self.ne[self.head]
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.ne[i] = self.ne[self.ne[i]]


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyLinkedList {
    private int[] e = new int[1010];
    private int[] ne = new int[1010];
    private int head = -1;
    private int idx;
    private int cnt;

    public MyLinkedList() {
    }

    public int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index-- > 0) {
            i = ne[i];
        }
        return e[i];
    }

    public void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    public void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyLinkedList {
private:
    int e[1010], ne[1010];
    int head = -1, idx = 0, cnt = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index--) {
            i = ne[i];
        }
        return e[i];
    }

    void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyLinkedList struct {
	e    []int
	ne   []int
	idx  int
	head int
	cnt  int
}

func Constructor() MyLinkedList {
	e := make([]int, 1010)
	ne := make([]int, 1010)
	return MyLinkedList{e, ne, 0, -1, 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.cnt {
		return -1
	}
	i := this.head
	for ; index > 0; index-- {
		i = this.ne[i]
	}
	return this.e[i]
}

func (this *MyLinkedList) AddAtHead(val int) {
	this.e[this.idx] = val
	this.ne[this.idx] = this.head
	this.head = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) AddAtTail(val int) {
	this.AddAtIndex(this.cnt, val)
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.cnt {
		return
	}
	if index <= 0 {
		this.AddAtHead(val)
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.e[this.idx] = val
	this.ne[this.idx] = this.ne[i]
	this.ne[i] = this.idx
	this.idx++
	this.cnt++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.cnt {
		return
	}
	this.cnt--
	if index == 0 {
		this.head = this.ne[this.head]
		return
	}
	i := this.head
	for ; index > 1; index-- {
		i = this.ne[i]
	}
	this.ne[i] = this.ne[this.ne[i]]
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyLinkedList {
    e: Array<number>;
    ne: Array<number>;
    idx: number;
    head: number;
    cnt: number;

    constructor() {
        this.e = new Array(1010).fill(0);
        this.ne = new Array(1010).fill(0);
        this.head = -1;
        this.idx = 0;
        this.cnt = 0;
    }

    get(index: number): number {
        if (index < 0 || index >= this.cnt) {
            return -1;
        }
        let i = this.head;
        while (index--) {
            i = this.ne[i];
        }
        return this.e[i];
    }

    addAtHead(val: number): void {
        this.e[this.idx] = val;
        this.ne[this.idx] = this.head;
        this.head = this.idx++;
        this.cnt++;
    }

    addAtTail(val: number): void {
        this.addAtIndex(this.cnt, val);
    }

    addAtIndex(index: number, val: number): void {
        if (index > this.cnt) {
            return;
        }
        if (index <= 0) {
            this.addAtHead(val);
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.e[this.idx] = val;
        this.ne[this.idx] = this.ne[i];
        this.ne[i] = this.idx++;
        this.cnt++;
    }

    deleteAtIndex(index: number): void {
        if (index < 0 || index >= this.cnt) {
            return;
        }
        this.cnt--;
        if (index == 0) {
            this.head = this.ne[this.head];
            return;
        }
        let i = this.head;
        while (--index) {
            i = this.ne[i];
        }
        this.ne[i] = this.ne[this.ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
#[derive(Default)]
struct MyLinkedList {
    head: Option<Box<ListNode>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyLinkedList {
    fn new() -> Self {
        Default::default()
    }

    fn get(&self, mut index: i32) -> i32 {
        if self.head.is_none() {
            return -1;
        }
        let mut cur = self.head.as_ref().unwrap();
        while index > 0 {
            match cur.next {
                None => {
                    return -1;
                }
                Some(ref next) => {
                    cur = next;
                    index -= 1;
                }
            }
        }
        cur.val
    }

    fn add_at_head(&mut self, val: i32) {
        self.head = Some(Box::new(ListNode {
            val,
            next: self.head.take(),
        }));
    }

    fn add_at_tail(&mut self, val: i32) {
        let new_node = Some(Box::new(ListNode { val, next: None }));
        if self.head.is_none() {
            self.head = new_node;
            return;
        }
        let mut cur = self.head.as_mut().unwrap();
        while let Some(ref mut next) = cur.next {
            cur = next;
        }
        cur.next = new_node;
    }

    fn add_at_index(&mut self, mut index: i32, val: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if cur.next.is_none() {
                return;
            }
            cur = cur.next.as_mut().unwrap();
            index -= 1;
        }
        cur.next = Some(Box::new(ListNode {
            val,
            next: cur.next.take(),
        }));
        self.head = dummy.next;
    }

    fn delete_at_index(&mut self, mut index: i32) {
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: self.head.take(),
        });
        let mut cur = &mut dummy;
        while index > 0 {
            if let Some(ref mut next) = cur.next {
                cur = next;
            }
            index -= 1;
        }
        cur.next = cur.next.take().and_then(|n| n.next);
        self.head = dummy.next;
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class MyLinkedList:
    def __init__(self):
        self.e = [0] * 1010
        self.ne = [0] * 1010
        self.idx = 0
        self.head = -1
        self.cnt = 0

    def get(self, index: int) -> int:
        if index < 0 or index >= self.cnt:
            return -1
        i = self.head
        for _ in range(index):
            i = self.ne[i]
        return self.e[i]

    def addAtHead(self, val: int) -> None:
        self.e[self.idx] = val
        self.ne[self.idx] = self.head
        self.head = self.idx
        self.idx += 1
        self.cnt += 1

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.cnt, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.cnt:
            return
        if index <= 0:
            self.addAtHead(val)
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.e[self.idx] = val
        self.ne[self.idx] = self.ne[i]
        self.ne[i] = self.idx
        self.idx += 1
        self.cnt += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.cnt:
            return -1
        self.cnt -= 1
        if index == 0:
            self.head = self.ne[self.head]
            return
        i = self.head
        for _ in range(index - 1):
            i = self.ne[i]
        self.ne[i] = self.ne[self.ne[i]]


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class MyLinkedList {
    private int[] e = new int[1010];
    private int[] ne = new int[1010];
    private int head = -1;
    private int idx;
    private int cnt;

    public MyLinkedList() {
    }

    public int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index-- > 0) {
            i = ne[i];
        }
        return e[i];
    }

    public void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    public void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index > 0) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class MyLinkedList {
private:
    int e[1010], ne[1010];
    int head = -1, idx = 0, cnt = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || index >= cnt) {
            return -1;
        }
        int i = head;
        while (index--) {
            i = ne[i];
        }
        return e[i];
    }

    void addAtHead(int val) {
        e[idx] = val;
        ne[idx] = head;
        head = idx++;
        ++cnt;
    }

    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }

    void addAtIndex(int index, int val) {
        if (index > cnt) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        e[idx] = val;
        ne[idx] = ne[i];
        ne[i] = idx++;
        ++cnt;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= cnt) {
            return;
        }
        --cnt;
        if (index == 0) {
            head = ne[head];
            return;
        }
        int i = head;
        while (--index) {
            i = ne[i];
        }
        ne[i] = ne[ne[i]];
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}
---
title: "0460_LFU 缓存"
date: 2025-10-08T18:36:10+08:00
weight: 7
tags: [位运算, 几何, 动态规划, 博弈, 双向链表, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数组, 深度优先搜索, 状态压缩, 矩阵, 记忆化搜索, 设计, 链表]
---

{{< markmap >}}
### [0460_LFU 缓存](#460)
#### [设计](#460)
#### [哈希表](#460)
#### [链表](#460)
#### [双向链表](#460)
### [0461_汉明距离](#461)
#### [位运算](#461)
### [0462_最小操作次数使数组元素相等 II](#462)
#### [数组](#462)
#### [数学](#462)
#### [排序](#462)
### [0463_岛屿的周长](#463)
#### [深度优先搜索](#463)
#### [广度优先搜索](#463)
#### [数组](#463)
#### [矩阵](#463)
### [0464_我能赢吗](#464)
#### [位运算](#464)
#### [记忆化搜索](#464)
#### [数学](#464)
#### [动态规划](#464)
#### [状态压缩](#464)
#### [博弈](#464)
### [0465_最优账单平衡 🔒](#465)
#### [位运算](#465)
#### [数组](#465)
#### [动态规划](#465)
#### [回溯](#465)
#### [状态压缩](#465)
### [0466_统计重复个数](#466)
#### [字符串](#466)
#### [动态规划](#466)
### [0467_环绕字符串中唯一的子字符串](#467)
#### [字符串](#467)
#### [动态规划](#467)
### [0468_验证IP地址](#468)
#### [字符串](#468)
### [0469_凸多边形 🔒](#469)
#### [几何](#469)
#### [数组](#469)
#### [数学](#469)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0460_LFU 缓存
___
#### 设计
___
#### 哈希表
___
#### 链表
___
#### 双向链表
---
### 0461_汉明距离
___
#### 位运算
---
### 0462_最小操作次数使数组元素相等 II
___
#### 数组
___
#### 数学
___
#### 排序
---
### 0463_岛屿的周长
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0464_我能赢吗
___
#### 位运算
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
___
#### 状态压缩
___
#### 博弈
---
### 0465_最优账单平衡 🔒
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0466_统计重复个数
___
#### 字符串
___
#### 动态规划
---
### 0467_环绕字符串中唯一的子字符串
___
#### 字符串
___
#### 动态规划
---
### 0468_验证IP地址
___
#### 字符串
---
### 0469_凸多边形 🔒
___
#### 几何
___
#### 数组
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 动态规划 |
| 博弈 | 双向链表 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 深度优先搜索 | 状态压缩 | 矩阵 |
| 记忆化搜索 | 设计 | 链表 |

# [460. LFU 缓存](https://leetcode.cn/problems/lfu-cache){#460}

{{< tabs "460" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self, key: int, value: int) -> None:
        self.key = key
        self.value = value
        self.freq = 1
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def add_first(self, node: Node) -> None:
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def remove(self, node: Node) -> Node:
        node.next.prev = node.prev
        node.prev.next = node.next
        node.next, node.prev = None, None
        return node

    def remove_last(self) -> Node:
        return self.remove(self.tail.prev)

    def is_empty(self) -> bool:
        return self.head.next == self.tail


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.min_freq = 0
        self.map = defaultdict(Node)
        self.freq_map = defaultdict(DoublyLinkedList)

    def get(self, key: int) -> int:
        if self.capacity == 0 or key not in self.map:
            return -1
        node = self.map[key]
        self.incr_freq(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.map:
            node = self.map[key]
            node.value = value
            self.incr_freq(node)
            return
        if len(self.map) == self.capacity:
            ls = self.freq_map[self.min_freq]
            node = ls.remove_last()
            self.map.pop(node.key)
        node = Node(key, value)
        self.add_node(node)
        self.map[key] = node
        self.min_freq = 1

    def incr_freq(self, node: Node) -> None:
        freq = node.freq
        ls = self.freq_map[freq]
        ls.remove(node)
        if ls.is_empty():
            self.freq_map.pop(freq)
            if freq == self.min_freq:
                self.min_freq += 1
        node.freq += 1
        self.add_node(node)

    def add_node(self, node: Node) -> None:
        freq = node.freq
        ls = self.freq_map[freq]
        ls.add_first(node)
        self.freq_map[freq] = ls


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class LFUCache {

    private final Map<Integer, Node> map;
    private final Map<Integer, DoublyLinkedList> freqMap;
    private final int capacity;
    private int minFreq;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>(capacity, 1);
        freqMap = new HashMap<>();
    }

    public int get(int key) {
        if (capacity == 0) {
            return -1;
        }
        if (!map.containsKey(key)) {
            return -1;
        }
        Node node = map.get(key);
        incrFreq(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;
            incrFreq(node);
            return;
        }
        if (map.size() == capacity) {
            DoublyLinkedList list = freqMap.get(minFreq);
            map.remove(list.removeLast().key);
        }
        Node node = new Node(key, value);
        addNode(node);
        map.put(key, node);
        minFreq = 1;
    }

    private void incrFreq(Node node) {
        int freq = node.freq;
        DoublyLinkedList list = freqMap.get(freq);
        list.remove(node);
        if (list.isEmpty()) {
            freqMap.remove(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        node.freq++;
        addNode(node);
    }

    private void addNode(Node node) {
        int freq = node.freq;
        DoublyLinkedList list = freqMap.getOrDefault(freq, new DoublyLinkedList());
        list.addFirst(node);
        freqMap.put(freq, list);
    }

    private static class Node {
        int key;
        int value;
        int freq;
        Node prev;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.freq = 1;
        }
    }

    private static class DoublyLinkedList {

        private final Node head;
        private final Node tail;

        public DoublyLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
        }

        public void addFirst(Node node) {
            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
        }

        public Node remove(Node node) {
            node.next.prev = node.prev;
            node.prev.next = node.next;
            node.next = null;
            node.prev = null;
            return node;
        }

        public Node removeLast() {
            return remove(tail.prev);
        }

        public boolean isEmpty() {
            return head.next == tail;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    void addFirst(Node* node) {
        node->prev = this->head;
        node->next = this->head->next;
        this->head->next->prev = node;
        this->head->next = node;
    }
    Node* remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }
    Node* removeLast() {
        return remove(this->tail->prev);
    }
    bool isEmpty() {
        return this->head->next == this->tail;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        incrFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            incrFreq(node);
            return;
        }
        if (map.size() == capacity) {
            DoublyLinkedList* list = freqMap[minFreq];
            Node* node = list->removeLast();
            map.erase(node->key);
        }
        Node* node = new Node(key, value);
        addNode(node);
        map[key] = node;
        minFreq = 1;
    }

private:
    int capacity;
    int minFreq;
    unordered_map<int, Node*> map;
    unordered_map<int, DoublyLinkedList*> freqMap;

    void incrFreq(Node* node) {
        int freq = node->freq;
        DoublyLinkedList* list = freqMap[freq];
        list->remove(node);
        if (list->isEmpty()) {
            freqMap.erase(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        node->freq++;
        addNode(node);
    }

    void addNode(Node* node) {
        int freq = node->freq;
        if (freqMap.find(freq) == freqMap.end()) {
            freqMap[freq] = new DoublyLinkedList();
        }
        DoublyLinkedList* list = freqMap[freq];
        list->addFirst(node);
        freqMap[freq] = list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type LFUCache struct {
	cache    map[int]*node
	freqMap  map[int]*list
	minFreq  int
	capacity int
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		cache:    make(map[int]*node),
		freqMap:  make(map[int]*list),
		capacity: capacity,
	}
}

func (this *LFUCache) Get(key int) int {
	if this.capacity == 0 {
		return -1
	}

	n, ok := this.cache[key]
	if !ok {
		return -1
	}

	this.incrFreq(n)
	return n.val
}

func (this *LFUCache) Put(key int, value int) {
	if this.capacity == 0 {
		return
	}

	n, ok := this.cache[key]
	if ok {
		n.val = value
		this.incrFreq(n)
		return
	}

	if len(this.cache) == this.capacity {
		l := this.freqMap[this.minFreq]
		delete(this.cache, l.removeBack().key)
	}
	n = &node{key: key, val: value, freq: 1}
	this.addNode(n)
	this.cache[key] = n
	this.minFreq = 1
}

func (this *LFUCache) incrFreq(n *node) {
	l := this.freqMap[n.freq]
	l.remove(n)
	if l.empty() {
		delete(this.freqMap, n.freq)
		if n.freq == this.minFreq {
			this.minFreq++
		}
	}
	n.freq++
	this.addNode(n)
}

func (this *LFUCache) addNode(n *node) {
	l, ok := this.freqMap[n.freq]
	if !ok {
		l = newList()
		this.freqMap[n.freq] = l
	}
	l.pushFront(n)
}

type node struct {
	key  int
	val  int
	freq int
	prev *node
	next *node
}

type list struct {
	head *node
	tail *node
}

func newList() *list {
	head := new(node)
	tail := new(node)
	head.next = tail
	tail.prev = head
	return &list{
		head: head,
		tail: tail,
	}
}

func (l *list) pushFront(n *node) {
	n.prev = l.head
	n.next = l.head.next
	l.head.next.prev = n
	l.head.next = n
}

func (l *list) remove(n *node) {
	n.prev.next = n.next
	n.next.prev = n.prev
	n.next = nil
	n.prev = nil
}

func (l *list) removeBack() *node {
	n := l.tail.prev
	l.remove(n)
	return n
}

func (l *list) empty() bool {
	return l.head.next == l.tail
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

struct Node {
    key: i32,
    value: i32,
    freq: i32,
    prev: Option<Rc<RefCell<Node>>>,
    next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    fn new(key: i32, value: i32) -> Self {
        Self {
            key,
            value,
            freq: 1,
            prev: None,
            next: None,
        }
    }
}

struct LinkedList {
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

impl LinkedList {
    fn new() -> Self {
        Self {
            head: None,
            tail: None,
        }
    }

    fn push_front(&mut self, node: &Rc<RefCell<Node>>) {
        match self.head.take() {
            Some(head) => {
                head.borrow_mut().prev = Some(Rc::clone(node));
                node.borrow_mut().prev = None;
                node.borrow_mut().next = Some(head);
                self.head = Some(Rc::clone(node));
            }
            None => {
                node.borrow_mut().prev = None;
                node.borrow_mut().next = None;
                self.head = Some(Rc::clone(node));
                self.tail = Some(Rc::clone(node));
            }
        };
    }

    fn remove(&mut self, node: &Rc<RefCell<Node>>) {
        match (node.borrow().prev.as_ref(), node.borrow().next.as_ref()) {
            (None, None) => {
                self.head = None;
                self.tail = None;
            }
            (None, Some(next)) => {
                self.head = Some(Rc::clone(next));
                next.borrow_mut().prev = None;
            }
            (Some(prev), None) => {
                self.tail = Some(Rc::clone(prev));
                prev.borrow_mut().next = None;
            }
            (Some(prev), Some(next)) => {
                next.borrow_mut().prev = Some(Rc::clone(prev));
                prev.borrow_mut().next = Some(Rc::clone(next));
            }
        };
    }

    fn pop_back(&mut self) -> Option<Rc<RefCell<Node>>> {
        match self.tail.take() {
            Some(tail) => {
                self.remove(&tail);
                Some(tail)
            }
            None => None,
        }
    }

    fn is_empty(&self) -> bool {
        self.head.is_none()
    }
}

struct LFUCache {
    cache: HashMap<i32, Rc<RefCell<Node>>>,
    freq_map: HashMap<i32, LinkedList>,
    min_freq: i32,
    capacity: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LFUCache {
    fn new(capacity: i32) -> Self {
        Self {
            cache: HashMap::new(),
            freq_map: HashMap::new(),
            min_freq: 0,
            capacity: capacity as usize,
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if self.capacity == 0 {
            return -1;
        }

        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                self.incr_freq(&node);
                let value = node.borrow().value;
                value
            }
            None => -1,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.capacity == 0 {
            return;
        }

        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                node.borrow_mut().value = value;
                self.incr_freq(&node);
            }
            None => {
                if self.cache.len() == self.capacity {
                    let list = self.freq_map.get_mut(&self.min_freq).unwrap();
                    self.cache.remove(&list.pop_back().unwrap().borrow().key);
                }
                let node = Rc::new(RefCell::new(Node::new(key, value)));
                self.add_node(&node);
                self.cache.insert(key, node);
                self.min_freq = 1;
            }
        };
    }

    fn incr_freq(&mut self, node: &Rc<RefCell<Node>>) {
        let freq = node.borrow().freq;
        let list = self.freq_map.get_mut(&freq).unwrap();
        list.remove(node);
        if list.is_empty() {
            self.freq_map.remove(&freq);
            if freq == self.min_freq {
                self.min_freq += 1;
            }
        }
        node.borrow_mut().freq += 1;
        self.add_node(node);
    }

    fn add_node(&mut self, node: &Rc<RefCell<Node>>) {
        let freq = node.borrow().freq;
        match self.freq_map.get_mut(&freq) {
            Some(list) => {
                list.push_front(node);
            }
            None => {
                let mut list = LinkedList::new();
                list.push_front(node);
                self.freq_map.insert(node.borrow().freq, list);
            }
        };
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你为 <a href="https://baike.baidu.com/item/%E7%BC%93%E5%AD%98%E7%AE%97%E6%B3%95">最不经常使用（LFU）</a>缓存算法设计并实现数据结构。</p>

<p>实现 <code>LFUCache</code> 类：</p>

<ul>
	<li><code>LFUCache(int capacity)</code> - 用数据结构的容量&nbsp;<code>capacity</code> 初始化对象</li>
	<li><code>int get(int key)</code>&nbsp;- 如果键&nbsp;<code>key</code> 存在于缓存中，则获取键的值，否则返回 <code>-1</code> 。</li>
	<li><code>void put(int key, int value)</code>&nbsp;- 如果键&nbsp;<code>key</code> 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量&nbsp;<code>capacity</code> 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 <strong>最久未使用</strong> 的键。</li>
</ul>

<p>为了确定最不常使用的键，可以为缓存中的每个键维护一个 <strong>使用计数器</strong> 。使用计数最小的键是最久未使用的键。</p>

<p>当一个键首次插入到缓存中时，它的使用计数器被设置为 <code>1</code> (由于 put 操作)。对缓存中的键执行 <code>get</code> 或 <code>put</code> 操作，使用计数器的值将会递增。</p>

<p>函数 <code>get</code> 和 <code>put</code> 必须以 <code>O(1)</code> 的平均时间复杂度运行。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
<strong>输出：</strong>
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

<strong>解释：</strong>
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // 返回 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // 返回 -1（未找到）
lfu.get(3);      // 返回 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // 返回 -1（未找到）
lfu.get(3);      // 返回 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // 返回 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= capacity&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= key &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>9</sup></code></li>
	<li>最多调用 <code>2 * 10<sup>5</sup></code> 次 <code>get</code> 和 <code>put</code> 方法</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双哈希表 + 双向链表

我们定义两个哈希表，其中：

-   哈希表 $map$：用于存储缓存的键值对，哈希表的键 $key$ 对应到缓存节点 $node$，方便 $O(1)$ 时间内获取缓存节点。
-   哈希表 $freqMap$：用于存储使用频率相同的缓存节点的双向链表，哈希表的键 $freq$ 对应到双向链表 $list$，方便 $O(1)$ 时间内获取使用频率相同的缓存节点的双向链表。

另外，我们还需要维护一个变量 $minFreq$，用于记录当前最小的使用频率，方便 $O(1)$ 时间内获取最小使用频率的缓存节点。

对于 $get(key)$ 操作：

我们首先判断 $capacity$ 是否为 $0$ 或者 $map$ 中是否存在键 $key$，如果不存在则返回 $-1$；否则从 $map$ 中获取缓存节点 $node$，并将 $node$ 的使用频率加 $1$，最后返回 $node$ 的值。

对于 $put(key, value)$ 操作：

我们首先判断 $capacity$ 是否为 $0$，如果为 $0$ 则直接返回；

否则判断 $map$ 中是否存在键 $key$，如果存在则从 $map$ 中获取缓存节点 $node$，更新 $node$ 的值为 $value$，并将 $node$ 的使用频率加 $1$，最后返回 $node$ 的值；

如果不存在则判断 $map$ 的长度是否等于 $capacity$，如果等于 $capacity$ 则从 $freqMap$ 中获取使用频率最小的双向链表 $list$，从 $list$ 中删除最后一个节点，并且移除该节点对应的键值对。然后创建新的缓存节点 $node$，将 $node$ 的使用频率设置为 $1$，将 $node$ 添加到 $map$ 和 $freqMap$ 中，最后将 $minFreq$ 设置为 $1$。

时间复杂度方面，操作 $get$ 和 $put$ 的时间复杂度都是 $O(1)$。空间复杂度 $O(n)$，其中 $n$ 为缓存的容量。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self, key: int, value: int) -> None:
        self.key = key
        self.value = value
        self.freq = 1
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def add_first(self, node: Node) -> None:
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def remove(self, node: Node) -> Node:
        node.next.prev = node.prev
        node.prev.next = node.next
        node.next, node.prev = None, None
        return node

    def remove_last(self) -> Node:
        return self.remove(self.tail.prev)

    def is_empty(self) -> bool:
        return self.head.next == self.tail


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.min_freq = 0
        self.map = defaultdict(Node)
        self.freq_map = defaultdict(DoublyLinkedList)

    def get(self, key: int) -> int:
        if self.capacity == 0 or key not in self.map:
            return -1
        node = self.map[key]
        self.incr_freq(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if key in self.map:
            node = self.map[key]
            node.value = value
            self.incr_freq(node)
            return
        if len(self.map) == self.capacity:
            ls = self.freq_map[self.min_freq]
            node = ls.remove_last()
            self.map.pop(node.key)
        node = Node(key, value)
        self.add_node(node)
        self.map[key] = node
        self.min_freq = 1

    def incr_freq(self, node: Node) -> None:
        freq = node.freq
        ls = self.freq_map[freq]
        ls.remove(node)
        if ls.is_empty():
            self.freq_map.pop(freq)
            if freq == self.min_freq:
                self.min_freq += 1
        node.freq += 1
        self.add_node(node)

    def add_node(self, node: Node) -> None:
        freq = node.freq
        ls = self.freq_map[freq]
        ls.add_first(node)
        self.freq_map[freq] = ls


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```

#### Java

```java
class LFUCache {

    private final Map<Integer, Node> map;
    private final Map<Integer, DoublyLinkedList> freqMap;
    private final int capacity;
    private int minFreq;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>(capacity, 1);
        freqMap = new HashMap<>();
    }

    public int get(int key) {
        if (capacity == 0) {
            return -1;
        }
        if (!map.containsKey(key)) {
            return -1;
        }
        Node node = map.get(key);
        incrFreq(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;
            incrFreq(node);
            return;
        }
        if (map.size() == capacity) {
            DoublyLinkedList list = freqMap.get(minFreq);
            map.remove(list.removeLast().key);
        }
        Node node = new Node(key, value);
        addNode(node);
        map.put(key, node);
        minFreq = 1;
    }

    private void incrFreq(Node node) {
        int freq = node.freq;
        DoublyLinkedList list = freqMap.get(freq);
        list.remove(node);
        if (list.isEmpty()) {
            freqMap.remove(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        node.freq++;
        addNode(node);
    }

    private void addNode(Node node) {
        int freq = node.freq;
        DoublyLinkedList list = freqMap.getOrDefault(freq, new DoublyLinkedList());
        list.addFirst(node);
        freqMap.put(freq, list);
    }

    private static class Node {
        int key;
        int value;
        int freq;
        Node prev;
        Node next;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.freq = 1;
        }
    }

    private static class DoublyLinkedList {

        private final Node head;
        private final Node tail;

        public DoublyLinkedList() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
        }

        public void addFirst(Node node) {
            node.prev = head;
            node.next = head.next;
            head.next.prev = node;
            head.next = node;
        }

        public Node remove(Node node) {
            node.next.prev = node.prev;
            node.prev.next = node.next;
            node.next = null;
            node.prev = null;
            return node;
        }

        public Node removeLast() {
            return remove(tail.prev);
        }

        public boolean isEmpty() {
            return head.next == tail;
        }
    }
}
```

#### C++

```cpp
class Node {
public:
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    void addFirst(Node* node) {
        node->prev = this->head;
        node->next = this->head->next;
        this->head->next->prev = node;
        this->head->next = node;
    }
    Node* remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }
    Node* removeLast() {
        return remove(this->tail->prev);
    }
    bool isEmpty() {
        return this->head->next == this->tail;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        incrFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            incrFreq(node);
            return;
        }
        if (map.size() == capacity) {
            DoublyLinkedList* list = freqMap[minFreq];
            Node* node = list->removeLast();
            map.erase(node->key);
        }
        Node* node = new Node(key, value);
        addNode(node);
        map[key] = node;
        minFreq = 1;
    }

private:
    int capacity;
    int minFreq;
    unordered_map<int, Node*> map;
    unordered_map<int, DoublyLinkedList*> freqMap;

    void incrFreq(Node* node) {
        int freq = node->freq;
        DoublyLinkedList* list = freqMap[freq];
        list->remove(node);
        if (list->isEmpty()) {
            freqMap.erase(freq);
            if (freq == minFreq) {
                minFreq++;
            }
        }
        node->freq++;
        addNode(node);
    }

    void addNode(Node* node) {
        int freq = node->freq;
        if (freqMap.find(freq) == freqMap.end()) {
            freqMap[freq] = new DoublyLinkedList();
        }
        DoublyLinkedList* list = freqMap[freq];
        list->addFirst(node);
        freqMap[freq] = list;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

#### Go

```go
type LFUCache struct {
	cache    map[int]*node
	freqMap  map[int]*list
	minFreq  int
	capacity int
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		cache:    make(map[int]*node),
		freqMap:  make(map[int]*list),
		capacity: capacity,
	}
}

func (this *LFUCache) Get(key int) int {
	if this.capacity == 0 {
		return -1
	}

	n, ok := this.cache[key]
	if !ok {
		return -1
	}

	this.incrFreq(n)
	return n.val
}

func (this *LFUCache) Put(key int, value int) {
	if this.capacity == 0 {
		return
	}

	n, ok := this.cache[key]
	if ok {
		n.val = value
		this.incrFreq(n)
		return
	}

	if len(this.cache) == this.capacity {
		l := this.freqMap[this.minFreq]
		delete(this.cache, l.removeBack().key)
	}
	n = &node{key: key, val: value, freq: 1}
	this.addNode(n)
	this.cache[key] = n
	this.minFreq = 1
}

func (this *LFUCache) incrFreq(n *node) {
	l := this.freqMap[n.freq]
	l.remove(n)
	if l.empty() {
		delete(this.freqMap, n.freq)
		if n.freq == this.minFreq {
			this.minFreq++
		}
	}
	n.freq++
	this.addNode(n)
}

func (this *LFUCache) addNode(n *node) {
	l, ok := this.freqMap[n.freq]
	if !ok {
		l = newList()
		this.freqMap[n.freq] = l
	}
	l.pushFront(n)
}

type node struct {
	key  int
	val  int
	freq int
	prev *node
	next *node
}

type list struct {
	head *node
	tail *node
}

func newList() *list {
	head := new(node)
	tail := new(node)
	head.next = tail
	tail.prev = head
	return &list{
		head: head,
		tail: tail,
	}
}

func (l *list) pushFront(n *node) {
	n.prev = l.head
	n.next = l.head.next
	l.head.next.prev = n
	l.head.next = n
}

func (l *list) remove(n *node) {
	n.prev.next = n.next
	n.next.prev = n.prev
	n.next = nil
	n.prev = nil
}

func (l *list) removeBack() *node {
	n := l.tail.prev
	l.remove(n)
	return n
}

func (l *list) empty() bool {
	return l.head.next == l.tail
}
```

#### Rust

```rust
use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

struct Node {
    key: i32,
    value: i32,
    freq: i32,
    prev: Option<Rc<RefCell<Node>>>,
    next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    fn new(key: i32, value: i32) -> Self {
        Self {
            key,
            value,
            freq: 1,
            prev: None,
            next: None,
        }
    }
}

struct LinkedList {
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

impl LinkedList {
    fn new() -> Self {
        Self {
            head: None,
            tail: None,
        }
    }

    fn push_front(&mut self, node: &Rc<RefCell<Node>>) {
        match self.head.take() {
            Some(head) => {
                head.borrow_mut().prev = Some(Rc::clone(node));
                node.borrow_mut().prev = None;
                node.borrow_mut().next = Some(head);
                self.head = Some(Rc::clone(node));
            }
            None => {
                node.borrow_mut().prev = None;
                node.borrow_mut().next = None;
                self.head = Some(Rc::clone(node));
                self.tail = Some(Rc::clone(node));
            }
        };
    }

    fn remove(&mut self, node: &Rc<RefCell<Node>>) {
        match (node.borrow().prev.as_ref(), node.borrow().next.as_ref()) {
            (None, None) => {
                self.head = None;
                self.tail = None;
            }
            (None, Some(next)) => {
                self.head = Some(Rc::clone(next));
                next.borrow_mut().prev = None;
            }
            (Some(prev), None) => {
                self.tail = Some(Rc::clone(prev));
                prev.borrow_mut().next = None;
            }
            (Some(prev), Some(next)) => {
                next.borrow_mut().prev = Some(Rc::clone(prev));
                prev.borrow_mut().next = Some(Rc::clone(next));
            }
        };
    }

    fn pop_back(&mut self) -> Option<Rc<RefCell<Node>>> {
        match self.tail.take() {
            Some(tail) => {
                self.remove(&tail);
                Some(tail)
            }
            None => None,
        }
    }

    fn is_empty(&self) -> bool {
        self.head.is_none()
    }
}

struct LFUCache {
    cache: HashMap<i32, Rc<RefCell<Node>>>,
    freq_map: HashMap<i32, LinkedList>,
    min_freq: i32,
    capacity: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LFUCache {
    fn new(capacity: i32) -> Self {
        Self {
            cache: HashMap::new(),
            freq_map: HashMap::new(),
            min_freq: 0,
            capacity: capacity as usize,
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        if self.capacity == 0 {
            return -1;
        }

        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                self.incr_freq(&node);
                let value = node.borrow().value;
                value
            }
            None => -1,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.capacity == 0 {
            return;
        }

        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                node.borrow_mut().value = value;
                self.incr_freq(&node);
            }
            None => {
                if self.cache.len() == self.capacity {
                    let list = self.freq_map.get_mut(&self.min_freq).unwrap();
                    self.cache.remove(&list.pop_back().unwrap().borrow().key);
                }
                let node = Rc::new(RefCell::new(Node::new(key, value)));
                self.add_node(&node);
                self.cache.insert(key, node);
                self.min_freq = 1;
            }
        };
    }

    fn incr_freq(&mut self, node: &Rc<RefCell<Node>>) {
        let freq = node.borrow().freq;
        let list = self.freq_map.get_mut(&freq).unwrap();
        list.remove(node);
        if list.is_empty() {
            self.freq_map.remove(&freq);
            if freq == self.min_freq {
                self.min_freq += 1;
            }
        }
        node.borrow_mut().freq += 1;
        self.add_node(node);
    }

    fn add_node(&mut self, node: &Rc<RefCell<Node>>) {
        let freq = node.borrow().freq;
        match self.freq_map.get_mut(&freq) {
            Some(list) => {
                list.push_front(node);
            }
            None => {
                let mut list = LinkedList::new();
                list.push_front(node);
                self.freq_map.insert(node.borrow().freq, list);
            }
        };
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [461. 汉明距离](https://leetcode.cn/problems/hamming-distance){#461}

{{< tabs "461" >}}

{{% tab "python" %}}
```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return (x ^ y).bit_count()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hammingDistance(x int, y int) int {
	return bits.OnesCount(uint(x ^ y))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hammingDistance(x: number, y: number): number {
    x ^= y;
    let ans = 0;
    while (x) {
        x -= x & -x;
        ++ans;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
    x ^= y;
    let ans = 0;
    while (x) {
        x -= x & -x;
        ++ans;
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

<p>两个整数之间的 <a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB">汉明距离</a> 指的是这两个数字对应二进制位不同的位置的数目。</p>

<p>给你两个整数 <code>x</code> 和 <code>y</code>，计算并返回它们之间的汉明距离。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 1, y = 4
<strong>输出：</strong>2
<strong>解释：</strong>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 3, y = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;=&nbsp;x, y &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/minimum-bit-flips-to-convert-number/">2220. 转换数字的最少位翻转次数</a>&nbsp;相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们将 $x$ 和 $y$ 按位异或，得到的结果中的 $1$ 的个数就是汉明距离。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return (x ^ y).bit_count()
```

#### Java

```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
```

#### Go

```go
func hammingDistance(x int, y int) int {
	return bits.OnesCount(uint(x ^ y))
}
```

#### TypeScript

```ts
function hammingDistance(x: number, y: number): number {
    x ^= y;
    let ans = 0;
    while (x) {
        x -= x & -x;
        ++ans;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
    x ^= y;
    let ans = 0;
    while (x) {
        x -= x & -x;
        ++ans;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [462. 最小操作次数使数组元素相等 II](https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii){#462}

{{< tabs "462" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        k = nums[len(nums) >> 1]
        return sum(abs(v - k) for v in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int k = nums[nums.length >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - k);
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
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[nums.size() >> 1];
        int ans = 0;
        for (int& v : nums) {
            ans += abs(v - k);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves2(nums []int) int {
	sort.Ints(nums)
	k := nums[len(nums)>>1]
	ans := 0
	for _, v := range nums {
		ans += abs(v - k)
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
function minMoves2(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const k = nums[nums.length >> 1];
    return nums.reduce((r, v) => r + Math.abs(v - k), 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_moves2(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let k = nums[nums.len() / 2];
        let mut ans = 0;
        for num in nums.iter() {
            ans += (num - k).abs();
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，返回使所有数组元素相等需要的最小操作数。</p>

<p>在一次操作中，你可以使数组中的一个元素加 <code>1</code> 或者减 <code>1</code> 。</p>

<p>测试用例经过设计以使答案在&nbsp;<strong>32 位</strong>&nbsp;整数范围内。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>
只需要两次操作（每次操作指南使一个元素加 1 或减 1）：
[<u>1</u>,2,3]  =&gt;  [2,2,<u>3</u>]  =&gt;  [2,2,2]
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,10,2,9]
<strong>输出：</strong>16
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
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

### 方法一：排序 + 中位数

这个问题可以抽象为，在数轴上有 $n$ 个点，找到一个点使得所有点到该点的距离之和最小。答案为 $n$ 个点的中位数。

中位数有这样的性质：所有数与中位数的距离之和最小。

证明：

首先，给定一个从小到大的数列 $a_1, a_2, \cdots, a_n$，我们假设 $x$ 是从 $a_1$ 到 $a_n$ 与其距离之和最小的点，显然 $x$ 必须位于 $a_1$ 和 $a_n$ 之间。而由于 $a_1$ 与 $a_n$ 与 $x$ 的距离之和都相等，都等于 $a_n-a_1$，因此，接下来不考虑 $a_1$ 和 $a_n$，我们只考虑 $a_2, a_3, \cdots, a_{n-1}$，这样的话，我们就可以把问题转化为在 $a_2, a_3, \cdots, a_{n-1}$ 中找到一个点与其距离之和最小，依此类推，我们最后可以得出结论：在一个数列中，中位数与其余数的距离之和最小。

在这个问题中，我们可以先对数组进行排序，然后找到中位数，最后计算所有数与中位数的距离之和即可。

时间复杂度 $O(n\log n)$，空间复杂度 $O(\log n)$。

相似题目：

-   [296. 最佳的碰头地点](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0296.Best%20Meeting%20Point/README.md)
-   [2448. 使数组相等的最小开销](https://github.com/doocs/leetcode/blob/main/solution/2400-2499/2448.Minimum%20Cost%20to%20Make%20Array%20Equal/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        k = nums[len(nums) >> 1]
        return sum(abs(v - k) for v in nums)
```

#### Java

```java
class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int k = nums[nums.length >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - k);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = nums[nums.size() >> 1];
        int ans = 0;
        for (int& v : nums) {
            ans += abs(v - k);
        }
        return ans;
    }
};
```

#### Go

```go
func minMoves2(nums []int) int {
	sort.Ints(nums)
	k := nums[len(nums)>>1]
	ans := 0
	for _, v := range nums {
		ans += abs(v - k)
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
function minMoves2(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const k = nums[nums.length >> 1];
    return nums.reduce((r, v) => r + Math.abs(v - k), 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_moves2(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let k = nums[nums.len() / 2];
        let mut ans = 0;
        for num in nums.iter() {
            ans += (num - k).abs();
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

# [463. 岛屿的周长](https://leetcode.cn/problems/island-perimeter){#463}

{{< tabs "463" >}}

{{% tab "python" %}}
```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans += 4
                    if i < m - 1 and grid[i + 1][j] == 1:
                        ans -= 2
                    if j < n - 1 and grid[i][j + 1] == 1:
                        ans -= 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        ans -= 2;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        ans -= 2;
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
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) ans -= 2;
                    if (j < n - 1 && grid[i][j + 1] == 1) ans -= 2;
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
func islandPerimeter(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	ans := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				ans += 4
				if i < m-1 && grid[i+1][j] == 1 {
					ans -= 2
				}
				if j < n-1 && grid[i][j+1] == 1 {
					ans -= 2
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function islandPerimeter(grid: number[][]): number {
    let m = grid.length,
        n = grid[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let top = 0,
                left = 0;
            if (i > 0) {
                top = grid[i - 1][j];
            }
            if (j > 0) {
                left = grid[i][j - 1];
            }
            let cur = grid[i][j];
            if (cur != top) ++ans;
            if (cur != left) ++ans;
        }
    }
    // 最后一行， 最后一列
    for (let i = 0; i < m; ++i) {
        if (grid[i][n - 1] == 1) ++ans;
    }
    for (let j = 0; j < n; ++j) {
        if (grid[m - 1][j] == 1) ++ans;
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

<p>给定一个 <code>row x col</code> 的二维网格地图 <code>grid</code> ，其中：<code>grid[i][j] = 1</code> 表示陆地， <code>grid[i][j] = 0</code> 表示水域。</p>

<p>网格中的格子 <strong>水平和垂直</strong> 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。</p>

<p>岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0463.Island%20Perimeter/images/island.png" /></p>

<pre>
<strong>输入：</strong>grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>输出：</strong>16
<strong>解释：</strong>它的周长是上面图片中的 16 个黄色的边</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0]]
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 <= row, col <= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
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
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans += 4
                    if i < m - 1 and grid[i + 1][j] == 1:
                        ans -= 2
                    if j < n - 1 and grid[i][j + 1] == 1:
                        ans -= 2
        return ans
```

#### Java

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) {
                        ans -= 2;
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1) {
                        ans -= 2;
                    }
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
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (i < m - 1 && grid[i + 1][j] == 1) ans -= 2;
                    if (j < n - 1 && grid[i][j + 1] == 1) ans -= 2;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func islandPerimeter(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	ans := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				ans += 4
				if i < m-1 && grid[i+1][j] == 1 {
					ans -= 2
				}
				if j < n-1 && grid[i][j+1] == 1 {
					ans -= 2
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function islandPerimeter(grid: number[][]): number {
    let m = grid.length,
        n = grid[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let top = 0,
                left = 0;
            if (i > 0) {
                top = grid[i - 1][j];
            }
            if (j > 0) {
                left = grid[i][j - 1];
            }
            let cur = grid[i][j];
            if (cur != top) ++ans;
            if (cur != left) ++ans;
        }
    }
    // 最后一行， 最后一列
    for (let i = 0; i < m; ++i) {
        if (grid[i][n - 1] == 1) ++ans;
    }
    for (let j = 0; j < n; ++j) {
        if (grid[m - 1][j] == 1) ++ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [464. 我能赢吗](https://leetcode.cn/problems/can-i-win){#464}

{{< tabs "464" >}}

{{% tab "python" %}}
```python
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        @cache
        def dfs(mask: int, s: int) -> bool:
            for i in range(1, maxChoosableInteger + 1):
                if mask >> i & 1 ^ 1:
                    if s + i >= desiredTotal or not dfs(mask | 1 << i, s + i):
                        return True
            return False

        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, Boolean> f = new HashMap<>();
    private int maxChoosableInteger;
    private int desiredTotal;

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        this.maxChoosableInteger = maxChoosableInteger;
        this.desiredTotal = desiredTotal;
        return dfs(0, 0);
    }

    private boolean dfs(int mask, int s) {
        if (f.containsKey(mask)) {
            return f.get(mask);
        }
        for (int i = 0; i < maxChoosableInteger; ++i) {
            if ((mask >> i & 1) == 0) {
                if (s + i + 1 >= desiredTotal || !dfs(mask | 1 << i, s + i + 1)) {
                    f.put(mask, true);
                    return true;
                }
            }
        }
        f.put(mask, false);
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        unordered_map<int, int> f;
        function<bool(int, int)> dfs = [&](int mask, int s) {
            if (f.contains(mask)) {
                return f[mask];
            }
            for (int i = 0; i < maxChoosableInteger; ++i) {
                if (mask >> i & 1 ^ 1) {
                    if (s + i + 1 >= desiredTotal || !dfs(mask | 1 << i, s + i + 1)) {
                        return f[mask] = true;
                    }
                }
            }
            return f[mask] = false;
        };
        return dfs(0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if (1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal {
		return false
	}
	f := map[int]bool{}
	var dfs func(int, int) bool
	dfs = func(mask, s int) bool {
		if v, ok := f[mask]; ok {
			return v
		}
		for i := 1; i <= maxChoosableInteger; i++ {
			if mask>>i&1 == 0 {
				if s+i >= desiredTotal || !dfs(mask|1<<i, s+i) {
					f[mask] = true
					return true
				}
			}
		}
		f[mask] = false
		return false
	}
	return dfs(0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canIWin(maxChoosableInteger: number, desiredTotal: number): boolean {
    if (((1 + maxChoosableInteger) * maxChoosableInteger) / 2 < desiredTotal) {
        return false;
    }
    const f: Record<string, boolean> = {};
    const dfs = (mask: number, s: number): boolean => {
        if (f.hasOwnProperty(mask)) {
            return f[mask];
        }
        for (let i = 1; i <= maxChoosableInteger; ++i) {
            if (((mask >> i) & 1) ^ 1) {
                if (s + i >= desiredTotal || !dfs(mask ^ (1 << i), s + i)) {
                    return (f[mask] = true);
                }
            }
        }
        return (f[mask] = false);
    };
    return dfs(0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在 "100 game" 这个游戏中，两名玩家轮流选择从 <code>1</code> 到 <code>10</code> 的任意整数，累计整数和，先使得累计整数和 <strong>达到或超过</strong>&nbsp; 100 的玩家，即为胜者。</p>

<p>如果我们将游戏规则改为 “玩家 <strong>不能</strong> 重复使用整数” 呢？</p>

<p>例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 &gt;= 100。</p>

<p>给定两个整数&nbsp;<code>maxChoosableInteger</code>&nbsp;（整数池中可选择的最大数）和&nbsp;<code>desiredTotal</code>（累计和），若先出手的玩家能稳赢则返回 <code>true</code>&nbsp;，否则返回 <code>false</code> 。假设两位玩家游戏时都表现 <strong>最佳</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>maxChoosableInteger = 10, desiredTotal = 11
<strong>输出：</strong>false
<strong>解释：
</strong>无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 &gt;= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>maxChoosableInteger = 10, desiredTotal = 0
<b>输出：</b>true
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>maxChoosableInteger = 10, desiredTotal = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= maxChoosableInteger &lt;= 20</code></li>
	<li><code>0 &lt;= desiredTotal &lt;= 300</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们首先判断可以选择的所有整数的和是否小于目标值，如果是，说明无论如何都无法赢，直接返回 `false`。

然后，我们设计一个函数 $\textit{dfs}(mask, s)$，其中 `mask` 表示当前已选择的整数的状态，`s` 表示当前的累计和。函数返回值为当前玩家是否能赢。

函数 $\textit{dfs}(mask, s)$ 的执行过程如下：

我们遍历 $1$ 到 $maxChoosableInteger$ 中的每个整数 $i$，如果 $i$ 还没有被选择，我们可以选择 $i$，如果选择 $i$ 后的累计和 $s + i$ 大于等于目标值 `desiredTotal`，或者对手选择 $i$ 后的结果是输的，那么当前玩家就是赢的，返回 `true`。

如果没有任何一个选择能让当前玩家赢，那么当前玩家就是输的，返回 `false`。

为了避免重复计算，我们使用一个哈希表 `f` 记录已经计算过的状态，键为 `mask`，值为当前玩家是否能赢。

时间复杂度 $O(2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 是 `maxChoosableInteger`。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        @cache
        def dfs(mask: int, s: int) -> bool:
            for i in range(1, maxChoosableInteger + 1):
                if mask >> i & 1 ^ 1:
                    if s + i >= desiredTotal or not dfs(mask | 1 << i, s + i):
                        return True
            return False

        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Map<Integer, Boolean> f = new HashMap<>();
    private int maxChoosableInteger;
    private int desiredTotal;

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        this.maxChoosableInteger = maxChoosableInteger;
        this.desiredTotal = desiredTotal;
        return dfs(0, 0);
    }

    private boolean dfs(int mask, int s) {
        if (f.containsKey(mask)) {
            return f.get(mask);
        }
        for (int i = 0; i < maxChoosableInteger; ++i) {
            if ((mask >> i & 1) == 0) {
                if (s + i + 1 >= desiredTotal || !dfs(mask | 1 << i, s + i + 1)) {
                    f.put(mask, true);
                    return true;
                }
            }
        }
        f.put(mask, false);
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        unordered_map<int, int> f;
        function<bool(int, int)> dfs = [&](int mask, int s) {
            if (f.contains(mask)) {
                return f[mask];
            }
            for (int i = 0; i < maxChoosableInteger; ++i) {
                if (mask >> i & 1 ^ 1) {
                    if (s + i + 1 >= desiredTotal || !dfs(mask | 1 << i, s + i + 1)) {
                        return f[mask] = true;
                    }
                }
            }
            return f[mask] = false;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if (1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal {
		return false
	}
	f := map[int]bool{}
	var dfs func(int, int) bool
	dfs = func(mask, s int) bool {
		if v, ok := f[mask]; ok {
			return v
		}
		for i := 1; i <= maxChoosableInteger; i++ {
			if mask>>i&1 == 0 {
				if s+i >= desiredTotal || !dfs(mask|1<<i, s+i) {
					f[mask] = true
					return true
				}
			}
		}
		f[mask] = false
		return false
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function canIWin(maxChoosableInteger: number, desiredTotal: number): boolean {
    if (((1 + maxChoosableInteger) * maxChoosableInteger) / 2 < desiredTotal) {
        return false;
    }
    const f: Record<string, boolean> = {};
    const dfs = (mask: number, s: number): boolean => {
        if (f.hasOwnProperty(mask)) {
            return f[mask];
        }
        for (let i = 1; i <= maxChoosableInteger; ++i) {
            if (((mask >> i) & 1) ^ 1) {
                if (s + i >= desiredTotal || !dfs(mask ^ (1 << i), s + i)) {
                    return (f[mask] = true);
                }
            }
        }
        return (f[mask] = false);
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [465. 最优账单平衡 🔒](https://leetcode.cn/problems/optimal-account-balancing){#465}

{{< tabs "465" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        g = defaultdict(int)
        for f, t, x in transactions:
            g[f] -= x
            g[t] += x
        nums = [x for x in g.values() if x]
        m = len(nums)
        f = [inf] * (1 << m)
        f[0] = 0
        for i in range(1, 1 << m):
            s = 0
            for j, x in enumerate(nums):
                if i >> j & 1:
                    s += x
            if s == 0:
                f[i] = i.bit_count() - 1
                j = (i - 1) & i
                while j > 0:
                    f[i] = min(f[i], f[j] + f[i ^ j])
                    j = (j - 1) & i
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTransfers(int[][] transactions) {
        int[] g = new int[12];
        for (var t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        List<Integer> nums = new ArrayList<>();
        for (int x : g) {
            if (x != 0) {
                nums.add(x);
            }
        }
        int m = nums.size();
        int[] f = new int[1 << m];
        Arrays.fill(f, 1 << 29);
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) == 1) {
                    s += nums.get(j);
                }
            }
            if (s == 0) {
                f[i] = Integer.bitCount(i) - 1;
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    f[i] = Math.min(f[i], f[j] + f[i ^ j]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int g[12]{};
        for (auto& t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        vector<int> nums;
        for (int x : g) {
            if (x) {
                nums.push_back(x);
            }
        }
        int m = nums.size();
        int f[1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    s += nums[j];
                }
            }
            if (s == 0) {
                f[i] = __builtin_popcount(i) - 1;
                for (int j = (i - 1) & i; j; j = (j - 1) & i) {
                    f[i] = min(f[i], f[j] + f[i ^ j]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTransfers(transactions [][]int) int {
	g := [12]int{}
	for _, t := range transactions {
		g[t[0]] -= t[2]
		g[t[1]] += t[2]
	}
	nums := []int{}
	for _, x := range g {
		if x != 0 {
			nums = append(nums, x)
		}
	}
	m := len(nums)
	f := make([]int, 1<<m)
	for i := 1; i < 1<<m; i++ {
		f[i] = 1 << 29
		s := 0
		for j, x := range nums {
			if i>>j&1 == 1 {
				s += x
			}
		}
		if s == 0 {
			f[i] = bits.OnesCount(uint(i)) - 1
			for j := (i - 1) & i; j > 0; j = (j - 1) & i {
				f[i] = min(f[i], f[j]+f[i^j])
			}
		}
	}
	return f[1<<m-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minTransfers(transactions: number[][]): number {
    const g: number[] = new Array(12).fill(0);
    for (const [f, t, x] of transactions) {
        g[f] -= x;
        g[t] += x;
    }
    const nums = g.filter(x => x !== 0);
    const m = nums.length;
    const f: number[] = new Array(1 << m).fill(1 << 29);
    f[0] = 0;
    for (let i = 1; i < 1 << m; ++i) {
        let s = 0;
        for (let j = 0; j < m; ++j) {
            if (((i >> j) & 1) === 1) {
                s += nums[j];
            }
        }
        if (s === 0) {
            f[i] = bitCount(i) - 1;
            for (let j = (i - 1) & i; j; j = (j - 1) & i) {
                f[i] = Math.min(f[i], f[j] + f[i ^ j]);
            }
        }
    }
    return f[(1 << m) - 1];
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个表示交易的数组 <code>transactions</code> ，其中 <code>transactions[i] = [from<sub>i</sub>, to<sub>i</sub>, amount<sub>i</sub>]</code> 表示 <code>ID = from<sub>i</sub></code> 的人给&nbsp;<code>ID = to<sub>i</sub></code> 的人共计 <code>amount<sub>i</sub> $</code> 。</p>

<p>请你计算并返回还清所有债务的最小交易笔数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>transactions = [[0,1,10],[2,0,5]]
<strong>输出：</strong>2
<strong>解释：</strong>
#0 给 #1 $10 。
#2 给 #0 $5 。
需要进行两笔交易。一种结清债务的方式是 #1 给 #0 和 #2 各 $5 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
<strong>输出：</strong>1
<strong>解释：</strong>
#0 给 #1 $10 。
#1 给 #0 $1 。
#1 给 #2 $5 。
#2 给 #0 $5 。
因此，#1 只需要给 #0 $4 ，所有的债务即可还清。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= transactions.length &lt;= 8</code></li>
	<li><code>transactions[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt; 12</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li><code>1 &lt;= amount<sub>i</sub> &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划 + 子集枚举

我们先遍历数组 `transactions`，统计每个人的收支情况，然后将所有收支不为零的人的收支情况存入数组 $nums$ 中。如果我们可以找到一个子集，子集中共有 $k$ 个人，且这 $k$ 个人的收支情况之和为零，那么我们最多通过 $k-1$ 次交易，就能够使得这 $k$ 个人的收支情况全部清零。这样，我们就能将原问题转化成一个子集枚举的问题。

我们定义 $f[i]$ 表示将集合 $i$ 的所有元素的收支情况全部清零，所需的最少交易次数，初始时 $f[0]=0$，其余 $f[i]=+\infty$。

考虑 $f[i]$，其中 $i \in [1,2^m)$, $m$ 是数组 $nums$ 的长度。我们可以统计集合 $i$ 中所有元素的收支情况之和 $s$，如果 $s=0$，那么 $f[i]$ 的取值不超过 $|i|-1$，其中 $|i|$ 表示集合 $i$ 中的元素个数。然后我们可以枚举 $i$ 的所有非空子集 $j$，计算 $f[j]+f[i-j]$，其中 $f[j]$ 和 $f[i-j]$ 分别表示将集合 $j$ 和 $i-j$ 的所有元素的收支情况全部清零，所需的最少交易次数。我们可以得到状态转移方程：

$$
f[i]=
\begin{cases}
0, & i=0 \\
+\infty, & i \neq 0, s \neq 0 \\
\min(|i|-1, \min_{j \subset i, j \neq \emptyset} \{f[j]+f[i-j]\}), & i \neq 0, s = 0
\end{cases}
$$

其中 $j \subset i$ 表示 $j$ 是 $i$ 的子集，且 $j \neq \emptyset$。

最终答案即为 $f[2^m-1]$。

时间复杂度 $O(3^n)$，空间复杂度 $O(2^n)$。其中 $n$ 是人的数量，本题中 $n \leq 12$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        g = defaultdict(int)
        for f, t, x in transactions:
            g[f] -= x
            g[t] += x
        nums = [x for x in g.values() if x]
        m = len(nums)
        f = [inf] * (1 << m)
        f[0] = 0
        for i in range(1, 1 << m):
            s = 0
            for j, x in enumerate(nums):
                if i >> j & 1:
                    s += x
            if s == 0:
                f[i] = i.bit_count() - 1
                j = (i - 1) & i
                while j > 0:
                    f[i] = min(f[i], f[j] + f[i ^ j])
                    j = (j - 1) & i
        return f[-1]
```

#### Java

```java
class Solution {
    public int minTransfers(int[][] transactions) {
        int[] g = new int[12];
        for (var t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        List<Integer> nums = new ArrayList<>();
        for (int x : g) {
            if (x != 0) {
                nums.add(x);
            }
        }
        int m = nums.size();
        int[] f = new int[1 << m];
        Arrays.fill(f, 1 << 29);
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) == 1) {
                    s += nums.get(j);
                }
            }
            if (s == 0) {
                f[i] = Integer.bitCount(i) - 1;
                for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                    f[i] = Math.min(f[i], f[j] + f[i ^ j]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int g[12]{};
        for (auto& t : transactions) {
            g[t[0]] -= t[2];
            g[t[1]] += t[2];
        }
        vector<int> nums;
        for (int x : g) {
            if (x) {
                nums.push_back(x);
            }
        }
        int m = nums.size();
        int f[1 << m];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << m; ++i) {
            int s = 0;
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    s += nums[j];
                }
            }
            if (s == 0) {
                f[i] = __builtin_popcount(i) - 1;
                for (int j = (i - 1) & i; j; j = (j - 1) & i) {
                    f[i] = min(f[i], f[j] + f[i ^ j]);
                }
            }
        }
        return f[(1 << m) - 1];
    }
};
```

#### Go

```go
func minTransfers(transactions [][]int) int {
	g := [12]int{}
	for _, t := range transactions {
		g[t[0]] -= t[2]
		g[t[1]] += t[2]
	}
	nums := []int{}
	for _, x := range g {
		if x != 0 {
			nums = append(nums, x)
		}
	}
	m := len(nums)
	f := make([]int, 1<<m)
	for i := 1; i < 1<<m; i++ {
		f[i] = 1 << 29
		s := 0
		for j, x := range nums {
			if i>>j&1 == 1 {
				s += x
			}
		}
		if s == 0 {
			f[i] = bits.OnesCount(uint(i)) - 1
			for j := (i - 1) & i; j > 0; j = (j - 1) & i {
				f[i] = min(f[i], f[j]+f[i^j])
			}
		}
	}
	return f[1<<m-1]
}
```

#### TypeScript

```ts
function minTransfers(transactions: number[][]): number {
    const g: number[] = new Array(12).fill(0);
    for (const [f, t, x] of transactions) {
        g[f] -= x;
        g[t] += x;
    }
    const nums = g.filter(x => x !== 0);
    const m = nums.length;
    const f: number[] = new Array(1 << m).fill(1 << 29);
    f[0] = 0;
    for (let i = 1; i < 1 << m; ++i) {
        let s = 0;
        for (let j = 0; j < m; ++j) {
            if (((i >> j) & 1) === 1) {
                s += nums[j];
            }
        }
        if (s === 0) {
            f[i] = bitCount(i) - 1;
            for (let j = (i - 1) & i; j; j = (j - 1) & i) {
                f[i] = Math.min(f[i], f[j] + f[i ^ j]);
            }
        }
    }
    return f[(1 << m) - 1];
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

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [466. 统计重复个数](https://leetcode.cn/problems/count-the-repetitions){#466}

{{< tabs "466" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        n = len(s2)
        d = {}
        for i in range(n):
            cnt = 0
            j = i
            for c in s1:
                if c == s2[j]:
                    j += 1
                if j == n:
                    cnt += 1
                    j = 0
            d[i] = (cnt, j)

        ans = 0
        j = 0
        for _ in range(n1):
            cnt, j = d[j]
            ans += cnt
        return ans // n2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int m = s1.length(), n = s2.length();
        int[][] d = new int[n][0];
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1.charAt(k) == s2.charAt(j)) {
                    if (++j == n) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            d[i] = new int[] {cnt, j};
        }
        int ans = 0;
        for (int j = 0; n1 > 0; --n1) {
            ans += d[j][0];
            j = d[j][1];
        }
        return ans / n2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(), n = s2.size();
        vector<pair<int, int>> d;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == n) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt, j);
        }
        int ans = 0;
        for (int j = 0; n1; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }
        return ans / n2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaxRepetitions(s1 string, n1 int, s2 string, n2 int) (ans int) {
	n := len(s2)
	d := make([][2]int, n)
	for i := 0; i < n; i++ {
		j := i
		cnt := 0
		for k := range s1 {
			if s1[k] == s2[j] {
				j++
				if j == n {
					cnt++
					j = 0
				}
			}
		}
		d[i] = [2]int{cnt, j}
	}
	for j := 0; n1 > 0; n1-- {
		ans += d[j][0]
		j = d[j][1]
	}
	ans /= n2
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaxRepetitions(s1: string, n1: number, s2: string, n2: number): number {
    const n = s2.length;
    const d: number[][] = new Array(n).fill(0).map(() => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        let j = i;
        let cnt = 0;
        for (const c of s1) {
            if (c === s2[j]) {
                if (++j === n) {
                    j = 0;
                    ++cnt;
                }
            }
        }
        d[i] = [cnt, j];
    }
    let ans = 0;
    for (let j = 0; n1 > 0; --n1) {
        ans += d[j][0];
        j = d[j][1];
    }
    return Math.floor(ans / n2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>定义 <code>str = [s, n]</code> 表示 <code>str</code> 由 <code>n</code> 个字符串 <code>s</code> 连接构成。</p>

<ul>
	<li>例如，<code>str == ["abc", 3] =="abcabcabc"</code> 。</li>
</ul>

<p>如果可以从 <code>s2</code><sub> </sub>中删除某些字符使其变为 <code>s1</code>，则称字符串 <code>s1</code><sub> </sub>可以从字符串 <code>s2</code> 获得。</p>

<ul>
	<li>例如，根据定义，<code>s1 = "abc"</code> 可以从 <code>s2 = "ab<em><strong>dbe</strong></em>c"</code> 获得，仅需要删除加粗且用斜体标识的字符。</li>
</ul>

<p>现在给你两个字符串 <code>s1</code> 和 <code>s2</code> 和两个整数 <code>n1</code> 和 <code>n2</code> 。由此构造得到两个字符串，其中 <code>str1 = [s1, n1]</code>、<code>str2 = [s2, n2]</code> 。</p>

<p>请你找出一个最大整数 <code>m</code> ，以满足 <code>str = [str2, m]</code> 可以从 <code>str1</code> 获得。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s1.length, s2.length <= 100</code></li>
	<li><code>s1</code> 和 <code>s2</code> 由小写英文字母组成</li>
	<li><code>1 <= n1, n2 <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 递推

我们预处理出以字符串 $s_2$ 的每个位置 $i$ 开始匹配一个完整的 $s_1$ 后，下一个位置 $j$ 以及经过了多少个 $s_2$，即 $d[i] = (cnt, j)$，其中 $cnt$ 表示匹配了多少个 $s_2$，而 $j$ 表示字符串 $s_2$ 的下一个位置。

接下来，我们初始化 $j=0$，然后循环 $n1$ 次，每一次将 $d[j][0]$ 加到答案中，然后更新 $j=d[j][1]$。

最后得到的答案就是 $n1$ 个 $s_1$ 所能匹配的 $s_2$ 的个数，除以 $n2$ 即可得到答案。

时间复杂度 $O(m \times n + n_1)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是 $s_1$ 和 $s_2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        n = len(s2)
        d = {}
        for i in range(n):
            cnt = 0
            j = i
            for c in s1:
                if c == s2[j]:
                    j += 1
                if j == n:
                    cnt += 1
                    j = 0
            d[i] = (cnt, j)

        ans = 0
        j = 0
        for _ in range(n1):
            cnt, j = d[j]
            ans += cnt
        return ans // n2
```

#### Java

```java
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int m = s1.length(), n = s2.length();
        int[][] d = new int[n][0];
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1.charAt(k) == s2.charAt(j)) {
                    if (++j == n) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            d[i] = new int[] {cnt, j};
        }
        int ans = 0;
        for (int j = 0; n1 > 0; --n1) {
            ans += d[j][0];
            j = d[j][1];
        }
        return ans / n2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(), n = s2.size();
        vector<pair<int, int>> d;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (s1[k] == s2[j]) {
                    if (++j == n) {
                        ++cnt;
                        j = 0;
                    }
                }
            }
            d.emplace_back(cnt, j);
        }
        int ans = 0;
        for (int j = 0; n1; --n1) {
            ans += d[j].first;
            j = d[j].second;
        }
        return ans / n2;
    }
};
```

#### Go

```go
func getMaxRepetitions(s1 string, n1 int, s2 string, n2 int) (ans int) {
	n := len(s2)
	d := make([][2]int, n)
	for i := 0; i < n; i++ {
		j := i
		cnt := 0
		for k := range s1 {
			if s1[k] == s2[j] {
				j++
				if j == n {
					cnt++
					j = 0
				}
			}
		}
		d[i] = [2]int{cnt, j}
	}
	for j := 0; n1 > 0; n1-- {
		ans += d[j][0]
		j = d[j][1]
	}
	ans /= n2
	return
}
```

#### TypeScript

```ts
function getMaxRepetitions(s1: string, n1: number, s2: string, n2: number): number {
    const n = s2.length;
    const d: number[][] = new Array(n).fill(0).map(() => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        let j = i;
        let cnt = 0;
        for (const c of s1) {
            if (c === s2[j]) {
                if (++j === n) {
                    j = 0;
                    ++cnt;
                }
            }
        }
        d[i] = [cnt, j];
    }
    let ans = 0;
    for (let j = 0; n1 > 0; --n1) {
        ans += d[j][0];
        j = d[j][1];
    }
    return Math.floor(ans / n2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [467. 环绕字符串中唯一的子字符串](https://leetcode.cn/problems/unique-substrings-in-wraparound-string){#467}

{{< tabs "467" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        f = defaultdict(int)
        k = 0
        for i, c in enumerate(s):
            if i and (ord(c) - ord(s[i - 1])) % 26 == 1:
                k += 1
            else:
                k = 1
            f[c] = max(f[c], k)
        return sum(f.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findSubstringInWraproundString(String s) {
        int[] f = new int[26];
        int n = s.length();
        for (int i = 0, k = 0; i < n; ++i) {
            if (i > 0 && (s.charAt(i) - s.charAt(i - 1) + 26) % 26 == 1) {
                ++k;
            } else {
                k = 1;
            }
            f[s.charAt(i) - 'a'] = Math.max(f[s.charAt(i) - 'a'], k);
        }
        return Arrays.stream(f).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int f[26]{};
        int n = s.length();
        for (int i = 0, k = 0; i < n; ++i) {
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1) {
                ++k;
            } else {
                k = 1;
            }
            f[s[i] - 'a'] = max(f[s[i] - 'a'], k);
        }
        return accumulate(begin(f), end(f), 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSubstringInWraproundString(s string) (ans int) {
	f := [26]int{}
	k := 0
	for i := range s {
		if i > 0 && (s[i]-s[i-1]+26)%26 == 1 {
			k++
		} else {
			k = 1
		}
		f[s[i]-'a'] = max(f[s[i]-'a'], k)
	}
	for _, x := range f {
		ans += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSubstringInWraproundString(s: string): number {
    const idx = (c: string): number => c.charCodeAt(0) - 97;
    const f: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0, k = 0; i < n; ++i) {
        const j = idx(s[i]);
        if (i && (j - idx(s[i - 1]) + 26) % 26 === 1) {
            ++k;
        } else {
            k = 1;
        }
        f[j] = Math.max(f[j], k);
    }
    return f.reduce((acc, cur) => acc + cur, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_substring_in_wrapround_string(s: String) -> i32 {
        let idx = |c: u8| -> usize { (c - b'a') as usize };
        let mut f = vec![0; 26];
        let n = s.len();
        let s = s.as_bytes();
        let mut k = 0;
        for i in 0..n {
            let j = idx(s[i]);
            if i > 0 && ((j as i32) - (idx(s[i - 1]) as i32) + 26) % 26 == 1 {
                k += 1;
            } else {
                k = 1;
            }
            f[j] = f[j].max(k);
        }

        f.iter().sum()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>定义字符串&nbsp;<code>base</code>&nbsp;为一个&nbsp;<code>"abcdefghijklmnopqrstuvwxyz"</code>&nbsp;无限环绕的字符串，所以&nbsp;<code>base</code>&nbsp;看起来是这样的：</p>

<ul>
	<li><code>"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...."</code>.</li>
</ul>

<p>给你一个字符串&nbsp;<code>s</code> ，请你统计并返回&nbsp;<code>s</code>&nbsp;中有多少&nbsp;<strong>不同</strong><strong>非空子串</strong>&nbsp;也在&nbsp;<code>base</code>&nbsp;中出现。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>1
<strong>解释：</strong>字符串 s 的子字符串 "a" 在 base 中出现。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "cac"
<strong>输出：</strong>2
<strong>解释：</strong>字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "zab"
<strong>输出：</strong>6
<strong>解释：</strong>字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">s</span></font> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们不妨定义一个长度为 $26$ 的数组 $f$，其中 $f[i]$ 表示以第 $i$ 个字符结尾的最长连续子串的长度。那么答案就是 $f$ 中所有元素的和。

我们定义一个变量 $k$，表示以当前字符结尾的最长连续子串的长度。遍历字符串 $s$，对于每个字符 $c$，如果 $c$ 和前一个字符 $s[i - 1]$ 之间的差值为 $1$，那么 $k$ 就加 $1$，否则 $k$ 重置为 $1$。然后更新 $f[c]$ 为 $f[c]$ 和 $k$ 的较大值。

最后返回 $f$ 中所有元素的和即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这里是小写字母集合。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        f = defaultdict(int)
        k = 0
        for i, c in enumerate(s):
            if i and (ord(c) - ord(s[i - 1])) % 26 == 1:
                k += 1
            else:
                k = 1
            f[c] = max(f[c], k)
        return sum(f.values())
```

#### Java

```java
class Solution {
    public int findSubstringInWraproundString(String s) {
        int[] f = new int[26];
        int n = s.length();
        for (int i = 0, k = 0; i < n; ++i) {
            if (i > 0 && (s.charAt(i) - s.charAt(i - 1) + 26) % 26 == 1) {
                ++k;
            } else {
                k = 1;
            }
            f[s.charAt(i) - 'a'] = Math.max(f[s.charAt(i) - 'a'], k);
        }
        return Arrays.stream(f).sum();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int f[26]{};
        int n = s.length();
        for (int i = 0, k = 0; i < n; ++i) {
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1) {
                ++k;
            } else {
                k = 1;
            }
            f[s[i] - 'a'] = max(f[s[i] - 'a'], k);
        }
        return accumulate(begin(f), end(f), 0);
    }
};
```

#### Go

```go
func findSubstringInWraproundString(s string) (ans int) {
	f := [26]int{}
	k := 0
	for i := range s {
		if i > 0 && (s[i]-s[i-1]+26)%26 == 1 {
			k++
		} else {
			k = 1
		}
		f[s[i]-'a'] = max(f[s[i]-'a'], k)
	}
	for _, x := range f {
		ans += x
	}
	return
}
```

#### TypeScript

```ts
function findSubstringInWraproundString(s: string): number {
    const idx = (c: string): number => c.charCodeAt(0) - 97;
    const f: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0, k = 0; i < n; ++i) {
        const j = idx(s[i]);
        if (i && (j - idx(s[i - 1]) + 26) % 26 === 1) {
            ++k;
        } else {
            k = 1;
        }
        f[j] = Math.max(f[j], k);
    }
    return f.reduce((acc, cur) => acc + cur, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn find_substring_in_wrapround_string(s: String) -> i32 {
        let idx = |c: u8| -> usize { (c - b'a') as usize };
        let mut f = vec![0; 26];
        let n = s.len();
        let s = s.as_bytes();
        let mut k = 0;
        for i in 0..n {
            let j = idx(s[i]);
            if i > 0 && ((j as i32) - (idx(s[i - 1]) as i32) + 26) % 26 == 1 {
                k += 1;
            } else {
                k = 1;
            }
            f[j] = f[j].max(k);
        }

        f.iter().sum()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [468. 验证IP地址](https://leetcode.cn/problems/validate-ip-address){#468}

{{< tabs "468" >}}

{{% tab "python" %}}
```python
class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def is_ipv4(s: str) -> bool:
            ss = s.split(".")
            if len(ss) != 4:
                return False
            for t in ss:
                if len(t) > 1 and t[0] == "0":
                    return False
                if not t.isdigit() or not 0 <= int(t) <= 255:
                    return False
            return True

        def is_ipv6(s: str) -> bool:
            ss = s.split(":")
            if len(ss) != 8:
                return False
            for t in ss:
                if not 1 <= len(t) <= 4:
                    return False
                if not all(c in "0123456789abcdefABCDEF" for c in t):
                    return False
            return True

        if is_ipv4(queryIP):
            return "IPv4"
        if is_ipv6(queryIP):
            return "IPv6"
        return "Neither"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String validIPAddress(String queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

    private boolean isIPv4(String s) {
        if (s.endsWith(".")) {
            return false;
        }
        String[] ss = s.split("\\.");
        if (ss.length != 4) {
            return false;
        }
        for (String t : ss) {
            if (t.length() == 0 || t.length() > 1 && t.charAt(0) == '0') {
                return false;
            }
            int x = convert(t);
            if (x < 0 || x > 255) {
                return false;
            }
        }
        return true;
    }

    private boolean isIPv6(String s) {
        if (s.endsWith(":")) {
            return false;
        }
        String[] ss = s.split(":");
        if (ss.length != 8) {
            return false;
        }
        for (String t : ss) {
            if (t.length() < 1 || t.length() > 4) {
                return false;
            }
            for (char c : t.toCharArray()) {
                if (!Character.isDigit(c)
                    && !"0123456789abcdefABCDEF".contains(String.valueOf(c))) {
                    return false;
                }
            }
        }
        return true;
    }

    private int convert(String s) {
        int x = 0;
        for (char c : s.toCharArray()) {
            if (!Character.isDigit(c)) {
                return -1;
            }
            x = x * 10 + (c - '0');
            if (x > 255) {
                return x;
            }
        }
        return x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    bool isIPv4(const string& s) {
        if (s.empty() || s.back() == '.') {
            return false;
        }
        vector<string> ss = split(s, '.');
        if (ss.size() != 4) {
            return false;
        }
        for (const string& t : ss) {
            if (t.empty() || (t.size() > 1 && t[0] == '0')) {
                return false;
            }
            int x = convert(t);
            if (x < 0 || x > 255) {
                return false;
            }
        }
        return true;
    }

    bool isIPv6(const string& s) {
        if (s.empty() || s.back() == ':') {
            return false;
        }
        vector<string> ss = split(s, ':');
        if (ss.size() != 8) {
            return false;
        }
        for (const string& t : ss) {
            if (t.size() < 1 || t.size() > 4) {
                return false;
            }
            for (char c : t) {
                if (!isxdigit(c)) {
                    return false;
                }
            }
        }
        return true;
    }

    int convert(const string& s) {
        int x = 0;
        for (char c : s) {
            if (!isdigit(c)) {
                return -1;
            }
            x = x * 10 + (c - '0');
            if (x > 255) {
                return x;
            }
        }
        return x;
    }

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream iss(s);
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validIPAddress(queryIP string) string {
	if isIPv4(queryIP) {
		return "IPv4"
	}
	if isIPv6(queryIP) {
		return "IPv6"
	}
	return "Neither"
}

func isIPv4(s string) bool {
	if strings.HasSuffix(s, ".") {
		return false
	}
	ss := strings.Split(s, ".")
	if len(ss) != 4 {
		return false
	}
	for _, t := range ss {
		if len(t) == 0 || (len(t) > 1 && t[0] == '0') {
			return false
		}
		x := convert(t)
		if x < 0 || x > 255 {
			return false
		}
	}
	return true
}

func isIPv6(s string) bool {
	if strings.HasSuffix(s, ":") {
		return false
	}
	ss := strings.Split(s, ":")
	if len(ss) != 8 {
		return false
	}
	for _, t := range ss {
		if len(t) < 1 || len(t) > 4 {
			return false
		}
		for _, c := range t {
			if !unicode.IsDigit(c) && !strings.ContainsRune("0123456789abcdefABCDEF", c) {
				return false
			}
		}
	}
	return true
}

func convert(s string) int {
	x := 0
	for _, c := range s {
		if !unicode.IsDigit(c) {
			return -1
		}
		x = x*10 + int(c-'0')
		if x > 255 {
			return x
		}
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validIPAddress(queryIP: string): string {
    if (isIPv4(queryIP)) {
        return 'IPv4';
    }
    if (isIPv6(queryIP)) {
        return 'IPv6';
    }
    return 'Neither';
}

function isIPv4(s: string): boolean {
    if (s.endsWith('.')) {
        return false;
    }
    const ss = s.split('.');
    if (ss.length !== 4) {
        return false;
    }
    for (const t of ss) {
        if (t.length === 0 || (t.length > 1 && t[0] === '0')) {
            return false;
        }
        const x = convert(t);
        if (x < 0 || x > 255) {
            return false;
        }
    }
    return true;
}

function isIPv6(s: string): boolean {
    if (s.endsWith(':')) {
        return false;
    }
    const ss = s.split(':');
    if (ss.length !== 8) {
        return false;
    }
    for (const t of ss) {
        if (t.length < 1 || t.length > 4) {
            return false;
        }
        for (const c of t) {
            if (!isHexDigit(c)) {
                return false;
            }
        }
    }
    return true;
}

function convert(s: string): number {
    let x = 0;
    for (const c of s) {
        if (!isDigit(c)) {
            return -1;
        }
        x = x * 10 + (c.charCodeAt(0) - '0'.charCodeAt(0));
        if (x > 255) {
            return x;
        }
    }
    return x;
}

function isDigit(c: string): boolean {
    return c >= '0' && c <= '9';
}

function isHexDigit(c: string): boolean {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn valid_ip_address(query_ip: String) -> String {
        if Self::is_ipv4(&query_ip) {
            return "IPv4".to_string();
        }
        if Self::is_ipv6(&query_ip) {
            return "IPv6".to_string();
        }
        "Neither".to_string()
    }

    fn is_ipv4(s: &str) -> bool {
        if s.ends_with('.') {
            return false;
        }
        let ss: Vec<&str> = s.split('.').collect();
        if ss.len() != 4 {
            return false;
        }
        for t in ss {
            if t.is_empty() || (t.len() > 1 && t.starts_with('0')) {
                return false;
            }
            match Self::convert(t) {
                Some(x) if x <= 255 => {
                    continue;
                }
                _ => {
                    return false;
                }
            }
        }
        true
    }

    fn is_ipv6(s: &str) -> bool {
        if s.ends_with(':') {
            return false;
        }
        let ss: Vec<&str> = s.split(':').collect();
        if ss.len() != 8 {
            return false;
        }
        for t in ss {
            if t.len() < 1 || t.len() > 4 {
                return false;
            }
            if !t.chars().all(|c| c.is_digit(16)) {
                return false;
            }
        }
        true
    }

    fn convert(s: &str) -> Option<i32> {
        let mut x = 0;
        for c in s.chars() {
            if !c.is_digit(10) {
                return None;
            }
            x = x * 10 + (c.to_digit(10).unwrap() as i32);
            if x > 255 {
                return Some(x);
            }
        }
        Some(x)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>queryIP</code>。如果是有效的 IPv4 地址，返回 <code>"IPv4"</code> ；如果是有效的 IPv6 地址，返回 <code>"IPv6"</code> ；如果不是上述类型的 IP 地址，返回 <code>"Neither"</code> 。</p>

<p><strong>有效的IPv4地址</strong> 是 <code>“x1.x2.x3.x4”</code> 形式的IP地址。 其中&nbsp;<code>0 &lt;= x<sub>i</sub>&nbsp;&lt;= 255</code>&nbsp;且&nbsp;<code>x<sub>i</sub></code>&nbsp;<strong>不能包含</strong> 前导零。例如:&nbsp;<code>“192.168.1.1”</code>&nbsp;、 <code>“192.168.1.0”</code> 为有效IPv4地址， <code>“192.168.01.1”</code> 为无效IPv4地址; <code>“192.168.1.00”</code> 、 <code>“192.168@1.1”</code> 为无效IPv4地址。</p>

<p><strong>一个有效的IPv6地址&nbsp;</strong>是一个格式为<code>“x1:x2:x3:x4:x5:x6:x7:x8”</code> 的IP地址，其中:</p>

<ul>
	<li><code>1 &lt;= x<sub>i</sub>.length &lt;= 4</code></li>
	<li><code>x<sub>i</sub></code>&nbsp;是一个 <strong>十六进制字符串</strong> ，可以包含数字、小写英文字母( <code>'a'</code> 到 <code>'f'</code> )和大写英文字母( <code>'A'</code> 到 <code>'F'</code> )。</li>
	<li>在&nbsp;<code>x<sub>i</sub></code>&nbsp;中允许前导零。</li>
</ul>

<p>例如 <code>"2001:0db8:85a3:0000:0000:8a2e:0370:7334"</code> 和 <code>"2001:db8:85a3:0:0:8A2E:0370:7334"</code> 是有效的 IPv6 地址，而 <code>"2001:0db8:85a3::8A2E:037j:7334"</code> 和 <code>"02001:0db8:85a3:0000:0000:8a2e:0370:7334"</code> 是无效的 IPv6 地址。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>queryIP = "172.16.254.1"
<strong>输出：</strong>"IPv4"
<strong>解释：</strong>有效的 IPv4 地址，返回 "IPv4"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
<strong>输出：</strong>"IPv6"
<strong>解释：</strong>有效的 IPv6 地址，返回 "IPv6"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>queryIP = "256.256.256.256"
<strong>输出：</strong>"Neither"
<strong>解释：</strong>既不是 IPv4 地址，又不是 IPv6 地址
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>queryIP</code> 仅由英文字母，数字，字符 <code>'.'</code> 和 <code>':'</code> 组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以定义两个函数 `isIPv4` 和 `isIPv6` 来判断一个字符串是否是有效的 IPv4 地址和 IPv6 地址。

函数 `isIPv4` 的实现如下：

1. 我们首先判断字符串 `s` 是否以 `.` 结尾，如果是的话，说明 `s` 不是一个有效的 IPv4 地址，直接返回 `false`。
1. 然后我们将字符串 `s` 以 `.` 分割成一个字符串数组 `ss`，如果 `ss` 的长度不等于 `4`，说明 `s` 不是一个有效的 IPv4 地址，直接返回 `false`。
1. 对于数组 `ss` 中的每个字符串 `t`，我们判断：
    - 如果 `t` 的长度大于 `1` 且 `t` 的第一个字符是 `0`，说明 `t` 不是一个有效的 IPv4 地址，直接返回 `false`。
    - 如果 `t` 不是一个数字或者 `t` 不在 `0` 到 `255` 的范围内，说明 `t` 不是一个有效的 IPv4 地址，直接返回 `false`。
1. 如果上述条件都不满足，说明 `s` 是一个有效的 IPv4 地址，返回 `true`。

函数 `isIPv6` 的实现如下：

1. 我们首先判断字符串 `s` 是否以 `:` 结尾，如果是的话，说明 `s` 不是一个有效的 IPv6 地址，直接返回 `false`。
1. 然后我们将字符串 `s` 以 `:` 分割成一个字符串数组 `ss`，如果 `ss` 的长度不等于 `8`，说明 `s` 不是一个有效的 IPv6 地址，直接返回 `false`。
1. 对于数组 `ss` 中的每个字符串 `t`，我们判断：
    - 如果 `t` 的长度小于 `1` 或大于 `4`，说明 `t` 不是一个有效的 IPv6 地址，直接返回 `false`。
    - 如果 `t` 中的字符不全是 `0` 到 `9` 和 `a` 到 `f`（不区分大小写），说明 `t` 不是一个有效的 IPv6 地址，直接返回 `false`。
1. 如果上述条件都不满足，说明 `s` 是一个有效的 IPv6 地址，返回 `true`。

最后，我们调用 `isIPv4` 和 `isIPv6` 函数判断 `queryIP` 是不是一个有效的 IPv4 地址或 IPv6 地址，如果都不是，返回 `Neither`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `queryIP` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def is_ipv4(s: str) -> bool:
            ss = s.split(".")
            if len(ss) != 4:
                return False
            for t in ss:
                if len(t) > 1 and t[0] == "0":
                    return False
                if not t.isdigit() or not 0 <= int(t) <= 255:
                    return False
            return True

        def is_ipv6(s: str) -> bool:
            ss = s.split(":")
            if len(ss) != 8:
                return False
            for t in ss:
                if not 1 <= len(t) <= 4:
                    return False
                if not all(c in "0123456789abcdefABCDEF" for c in t):
                    return False
            return True

        if is_ipv4(queryIP):
            return "IPv4"
        if is_ipv6(queryIP):
            return "IPv6"
        return "Neither"
```

#### Java

```java
class Solution {
    public String validIPAddress(String queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

    private boolean isIPv4(String s) {
        if (s.endsWith(".")) {
            return false;
        }
        String[] ss = s.split("\\.");
        if (ss.length != 4) {
            return false;
        }
        for (String t : ss) {
            if (t.length() == 0 || t.length() > 1 && t.charAt(0) == '0') {
                return false;
            }
            int x = convert(t);
            if (x < 0 || x > 255) {
                return false;
            }
        }
        return true;
    }

    private boolean isIPv6(String s) {
        if (s.endsWith(":")) {
            return false;
        }
        String[] ss = s.split(":");
        if (ss.length != 8) {
            return false;
        }
        for (String t : ss) {
            if (t.length() < 1 || t.length() > 4) {
                return false;
            }
            for (char c : t.toCharArray()) {
                if (!Character.isDigit(c)
                    && !"0123456789abcdefABCDEF".contains(String.valueOf(c))) {
                    return false;
                }
            }
        }
        return true;
    }

    private int convert(String s) {
        int x = 0;
        for (char c : s.toCharArray()) {
            if (!Character.isDigit(c)) {
                return -1;
            }
            x = x * 10 + (c - '0');
            if (x > 255) {
                return x;
            }
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    bool isIPv4(const string& s) {
        if (s.empty() || s.back() == '.') {
            return false;
        }
        vector<string> ss = split(s, '.');
        if (ss.size() != 4) {
            return false;
        }
        for (const string& t : ss) {
            if (t.empty() || (t.size() > 1 && t[0] == '0')) {
                return false;
            }
            int x = convert(t);
            if (x < 0 || x > 255) {
                return false;
            }
        }
        return true;
    }

    bool isIPv6(const string& s) {
        if (s.empty() || s.back() == ':') {
            return false;
        }
        vector<string> ss = split(s, ':');
        if (ss.size() != 8) {
            return false;
        }
        for (const string& t : ss) {
            if (t.size() < 1 || t.size() > 4) {
                return false;
            }
            for (char c : t) {
                if (!isxdigit(c)) {
                    return false;
                }
            }
        }
        return true;
    }

    int convert(const string& s) {
        int x = 0;
        for (char c : s) {
            if (!isdigit(c)) {
                return -1;
            }
            x = x * 10 + (c - '0');
            if (x > 255) {
                return x;
            }
        }
        return x;
    }

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream iss(s);
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
```

#### Go

```go
func validIPAddress(queryIP string) string {
	if isIPv4(queryIP) {
		return "IPv4"
	}
	if isIPv6(queryIP) {
		return "IPv6"
	}
	return "Neither"
}

func isIPv4(s string) bool {
	if strings.HasSuffix(s, ".") {
		return false
	}
	ss := strings.Split(s, ".")
	if len(ss) != 4 {
		return false
	}
	for _, t := range ss {
		if len(t) == 0 || (len(t) > 1 && t[0] == '0') {
			return false
		}
		x := convert(t)
		if x < 0 || x > 255 {
			return false
		}
	}
	return true
}

func isIPv6(s string) bool {
	if strings.HasSuffix(s, ":") {
		return false
	}
	ss := strings.Split(s, ":")
	if len(ss) != 8 {
		return false
	}
	for _, t := range ss {
		if len(t) < 1 || len(t) > 4 {
			return false
		}
		for _, c := range t {
			if !unicode.IsDigit(c) && !strings.ContainsRune("0123456789abcdefABCDEF", c) {
				return false
			}
		}
	}
	return true
}

func convert(s string) int {
	x := 0
	for _, c := range s {
		if !unicode.IsDigit(c) {
			return -1
		}
		x = x*10 + int(c-'0')
		if x > 255 {
			return x
		}
	}
	return x
}
```

#### TypeScript

```ts
function validIPAddress(queryIP: string): string {
    if (isIPv4(queryIP)) {
        return 'IPv4';
    }
    if (isIPv6(queryIP)) {
        return 'IPv6';
    }
    return 'Neither';
}

function isIPv4(s: string): boolean {
    if (s.endsWith('.')) {
        return false;
    }
    const ss = s.split('.');
    if (ss.length !== 4) {
        return false;
    }
    for (const t of ss) {
        if (t.length === 0 || (t.length > 1 && t[0] === '0')) {
            return false;
        }
        const x = convert(t);
        if (x < 0 || x > 255) {
            return false;
        }
    }
    return true;
}

function isIPv6(s: string): boolean {
    if (s.endsWith(':')) {
        return false;
    }
    const ss = s.split(':');
    if (ss.length !== 8) {
        return false;
    }
    for (const t of ss) {
        if (t.length < 1 || t.length > 4) {
            return false;
        }
        for (const c of t) {
            if (!isHexDigit(c)) {
                return false;
            }
        }
    }
    return true;
}

function convert(s: string): number {
    let x = 0;
    for (const c of s) {
        if (!isDigit(c)) {
            return -1;
        }
        x = x * 10 + (c.charCodeAt(0) - '0'.charCodeAt(0));
        if (x > 255) {
            return x;
        }
    }
    return x;
}

function isDigit(c: string): boolean {
    return c >= '0' && c <= '9';
}

function isHexDigit(c: string): boolean {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
```

#### Rust

```rust
impl Solution {
    pub fn valid_ip_address(query_ip: String) -> String {
        if Self::is_ipv4(&query_ip) {
            return "IPv4".to_string();
        }
        if Self::is_ipv6(&query_ip) {
            return "IPv6".to_string();
        }
        "Neither".to_string()
    }

    fn is_ipv4(s: &str) -> bool {
        if s.ends_with('.') {
            return false;
        }
        let ss: Vec<&str> = s.split('.').collect();
        if ss.len() != 4 {
            return false;
        }
        for t in ss {
            if t.is_empty() || (t.len() > 1 && t.starts_with('0')) {
                return false;
            }
            match Self::convert(t) {
                Some(x) if x <= 255 => {
                    continue;
                }
                _ => {
                    return false;
                }
            }
        }
        true
    }

    fn is_ipv6(s: &str) -> bool {
        if s.ends_with(':') {
            return false;
        }
        let ss: Vec<&str> = s.split(':').collect();
        if ss.len() != 8 {
            return false;
        }
        for t in ss {
            if t.len() < 1 || t.len() > 4 {
                return false;
            }
            if !t.chars().all(|c| c.is_digit(16)) {
                return false;
            }
        }
        true
    }

    fn convert(s: &str) -> Option<i32> {
        let mut x = 0;
        for c in s.chars() {
            if !c.is_digit(10) {
                return None;
            }
            x = x * 10 + (c.to_digit(10).unwrap() as i32);
            if x > 255 {
                return Some(x);
            }
        }
        Some(x)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [469. 凸多边形 🔒](https://leetcode.cn/problems/convex-polygon){#469}

{{< tabs "469" >}}

{{% tab "python" %}}
```python
class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        n = len(points)
        pre = cur = 0
        for i in range(n):
            x1 = points[(i + 1) % n][0] - points[i][0]
            y1 = points[(i + 1) % n][1] - points[i][1]
            x2 = points[(i + 2) % n][0] - points[i][0]
            y2 = points[(i + 2) % n][1] - points[i][1]
            cur = x1 * y2 - x2 * y1
            if cur != 0:
                if cur * pre < 0:
                    return False
                pre = cur
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isConvex(List<List<Integer>> points) {
        int n = points.size();
        long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            var p1 = points.get(i);
            var p2 = points.get((i + 1) % n);
            var p3 = points.get((i + 2) % n);
            int x1 = p2.get(0) - p1.get(0);
            int y1 = p2.get(1) - p1.get(1);
            int x2 = p3.get(0) - p1.get(0);
            int y2 = p3.get(1) - p1.get(1);
            cur = x1 * y2 - x2 * y1;
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[(i + 1) % n][0] - points[i][0];
            int y1 = points[(i + 1) % n][1] - points[i][1];
            int x2 = points[(i + 2) % n][0] - points[i][0];
            int y2 = points[(i + 2) % n][1] - points[i][1];
            cur = 1L * x1 * y2 - x2 * y1;
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isConvex(points [][]int) bool {
	n := len(points)
	pre, cur := 0, 0
	for i := range points {
		x1 := points[(i+1)%n][0] - points[i][0]
		y1 := points[(i+1)%n][1] - points[i][1]
		x2 := points[(i+2)%n][0] - points[i][0]
		y2 := points[(i+2)%n][1] - points[i][1]
		cur = x1*y2 - x2*y1
		if cur != 0 {
			if cur*pre < 0 {
				return false
			}
			pre = cur
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定 <strong>X-Y</strong> 平面上的一组点&nbsp;<code>points</code>&nbsp;，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。这些点按顺序连成一个多边形。</p>

<p>如果该多边形为&nbsp;<strong>凸</strong>&nbsp;多边形<a href="https://baike.baidu.com/item/凸多边形/">（凸多边形的定义）</a>则返回 <code>true</code> ，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>你可以假设由给定点构成的多边形总是一个 简单的多边形<a href="https://baike.baidu.com/item/%E7%AE%80%E5%8D%95%E5%A4%9A%E8%BE%B9%E5%BD%A2">（简单多边形的定义）</a>。换句话说，我们要保证每个顶点处恰好是两条边的汇合点，并且这些边&nbsp;<strong>互不相交&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0469.Convex%20Polygon/images/covpoly1-plane.jpg" style="height: 294px; width: 300px;" /></p>

<pre>
<strong>输入:</strong> points = [[0,0],[0,5],[5,5],[5,0]]
<strong>输出:</strong> true</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0469.Convex%20Polygon/images/covpoly2-plane.jpg" style="height: 303px; width: 300px;" /></p>

<pre>
<strong>输入:</strong> points = [[0,0],[0,10],[10,10],[10,0],[5,5]]
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li>所有点都 <strong>不同</strong></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学（向量叉积）

假设当前连续的三个顶点分别为 $p_1, p_2, p_3$，我们可以计算向量 $\overrightarrow{p_1p_2}$ 和 $\overrightarrow{p_1p_3}$ 的叉积，记为 $cur$。如果 $cur$ 的方向与之前的 $pre$ 方向不一致，说明多边形不是凸多边形 🔒。否则，我们更新 $pre = cur$，继续遍历下一个顶点。

遍历结束，如果没有发现不一致的情况，说明多边形是凸多边形 🔒。

时间复杂度 $O(n)$，其中 $n$ 是顶点的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        n = len(points)
        pre = cur = 0
        for i in range(n):
            x1 = points[(i + 1) % n][0] - points[i][0]
            y1 = points[(i + 1) % n][1] - points[i][1]
            x2 = points[(i + 2) % n][0] - points[i][0]
            y2 = points[(i + 2) % n][1] - points[i][1]
            cur = x1 * y2 - x2 * y1
            if cur != 0:
                if cur * pre < 0:
                    return False
                pre = cur
        return True
```

#### Java

```java
class Solution {
    public boolean isConvex(List<List<Integer>> points) {
        int n = points.size();
        long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            var p1 = points.get(i);
            var p2 = points.get((i + 1) % n);
            var p3 = points.get((i + 2) % n);
            int x1 = p2.get(0) - p1.get(0);
            int y1 = p2.get(1) - p1.get(1);
            int x2 = p3.get(0) - p1.get(0);
            int y2 = p3.get(1) - p1.get(1);
            cur = x1 * y2 - x2 * y1;
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[(i + 1) % n][0] - points[i][0];
            int y1 = points[(i + 1) % n][1] - points[i][1];
            int x2 = points[(i + 2) % n][0] - points[i][0];
            int y2 = points[(i + 2) % n][1] - points[i][1];
            cur = 1L * x1 * y2 - x2 * y1;
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isConvex(points [][]int) bool {
	n := len(points)
	pre, cur := 0, 0
	for i := range points {
		x1 := points[(i+1)%n][0] - points[i][0]
		y1 := points[(i+1)%n][1] - points[i][1]
		x2 := points[(i+2)%n][0] - points[i][0]
		y2 := points[(i+2)%n][1] - points[i][1]
		cur = x1*y2 - x2*y1
		if cur != 0 {
			if cur*pre < 0 {
				return false
			}
			pre = cur
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

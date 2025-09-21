---
title: "day_0146 "
date: 2025-09-21T09:33:40+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0146 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.size = 0
        self.capacity = capacity
        self.cache = {}
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self.remove_node(node)
        self.add_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.remove_node(node)
            node.val = value
            self.add_to_head(node)
        else:
            node = Node(key, value)
            self.cache[key] = node
            self.add_to_head(node)
            self.size += 1
            if self.size > self.capacity:
                node = self.tail.prev
                self.cache.pop(node.key)
                self.remove_node(node)
                self.size -= 1

    def remove_node(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def add_to_head(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        node.next.prev = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0146  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key  # 节点的键
        self.val = val  # 节点的值
        self.prev = None  # 前驱指针
        self.next = None  # 后继指针


class LRUCache:
    def __init__(self, capacity: int):
        self.size = 0  # 当前缓存大小
        self.capacity = capacity  # 缓存容量
        self.cache = {}  # 哈希表，存储键到节点的映射
        self.head = Node()  # 虚拟头节点
        self.tail = Node()  # 虚拟尾节点
        self.head.next = self.tail  # 初始化双向链表
        self.tail.prev = self.head  # 初始化双向链表

    def get(self, key: int) -> int:
        if key not in self.cache:  # 如果键不存在
            return -1  # 返回-1
        node = self.cache[key]  # 获取节点
        self.remove_node(node)  # 从当前位置移除节点
        self.add_to_head(node)  # 将节点添加到头部（最近使用）
        return node.val  # 返回节点值

    def put(self, key: int, value: int) -> None:
        if key in self.cache:  # 如果键已存在
            node = self.cache[key]  # 获取节点
            self.remove_node(node)  # 移除旧节点
            node.val = value  # 更新节点值
            self.add_to_head(node)  # 添加到头部（最近使用）
        else:  # 如果键不存在
            node = Node(key, value)  # 创建新节点
            self.cache[key] = node  # 添加到哈希表
            self.add_to_head(node)  # 添加到头部
            self.size += 1  # 增加缓存大小
            if self.size > self.capacity:  # 如果超过容量
                node = self.tail.prev  # 获取最久未使用的节点（尾部前一个）
                self.cache.pop(node.key)  # 从哈希表中移除
                self.remove_node(node)  # 从链表中移除
                self.size -= 1  # 减少缓存大小

    def remove_node(self, node):  # 从链表中移除节点
        node.prev.next = node.next  # 前驱节点的next指向后继节点
        node.next.prev = node.prev  # 后继节点的prev指向前驱节点

    def add_to_head(self, node):  # 将节点添加到链表头部
        node.next = self.head.next  # 新节点的next指向原头节点的下一个
        node.prev = self.head  # 新节点的prev指向虚拟头节点
        self.head.next = node  # 头节点的next指向新节点
        node.next.prev = node  # 原头节点的前一个指向新节点


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0146  数学解释

```python 
class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.size = 0
        self.capacity = capacity
        self.cache = {}
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self.remove_node(node)
        self.add_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            self.remove_node(node)
            node.val = value
            self.add_to_head(node)
        else:
            node = Node(key, value)
            self.cache[key] = node
            self.add_to_head(node)
            self.size += 1
            if self.size > self.capacity:
                node = self.tail.prev
                self.cache.pop(node.key)
                self.remove_node(node)
                self.size -= 1

    def remove_node(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def add_to_head(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next = node
        node.next.prev = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value) 
```


这段代码实现了一个**最近最少使用（LRU）缓存**，它体现了以下几个重要的数学和计算机科学思想：

## 1. 哈希表与双向链表的结合（时空权衡）
- **哈希表**（`self.cache`）提供O(1)时间复杂度的查找
- **双向链表**维护访问顺序，最近访问的节点在头部，最少使用的在尾部
- 这是典型的**空间换时间**策略，用额外空间换取操作效率

## 2. 队列理论的应用
- 实现了一个**优先队列**，但不是基于优先级，而是基于**访问时间**
- 遵循"先进先出"的变体：**最近最少使用先出**
- 体现了**缓存替换策略**的数学建模

## 3. 双指针技术的运用
- 头指针(`head`)和尾指针(`tail`)作为哨兵节点
- 简化了边界条件的处理，避免空指针异常
- 这是**数据结构设计**中的常见技巧

## 4. 操作的时间复杂度分析
- `get()`: O(1) - 哈希查找 + 链表调整
- `put()`: O(1) - 哈希操作 + 链表操作
- `remove_node()`: O(1) - 指针重定向
- `add_to_head()`: O(1) - 指针操作

## 5. 状态维护的数学思想
- `size`变量维护当前缓存大小
- 当`size > capacity`时触发淘汰机制
- 体现了**有限状态机**的思想，系统状态由缓存内容和访问顺序共同决定

这种设计完美体现了**算法与数据结构的结合**，通过合适的抽象和数学建模，实现了高效的缓存管理策略。



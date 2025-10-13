---
title: "0380_O(1) 时间插入、删除和获取随机元素"
date: 2025-10-08T18:35:54+08:00
weight: 9
tags: [位运算, 哈希表, 字典树, 字符串, 排序, 数学, 数组, 栈, 水塘抽样, 深度优先搜索, 计数, 设计, 链表, 队列, 随机化]
---

{{< markmap >}}
### [0380_O(1) 时间插入、删除和获取随机元素](#380)
#### [设计](#380)
#### [数组](#380)
#### [哈希表](#380)
#### [数学](#380)
#### [随机化](#380)
### [0381_O(1) 时间插入、删除和获取随机元素 - 允许重复](#381)
#### [设计](#381)
#### [数组](#381)
#### [哈希表](#381)
#### [数学](#381)
#### [随机化](#381)
### [0382_链表随机节点](#382)
#### [水塘抽样](#382)
#### [链表](#382)
#### [数学](#382)
#### [随机化](#382)
### [0383_赎金信](#383)
#### [哈希表](#383)
#### [字符串](#383)
#### [计数](#383)
### [0384_打乱数组](#384)
#### [设计](#384)
#### [数组](#384)
#### [数学](#384)
#### [随机化](#384)
### [0385_迷你语法分析器](#385)
#### [栈](#385)
#### [深度优先搜索](#385)
#### [字符串](#385)
### [0386_字典序排数](#386)
#### [深度优先搜索](#386)
#### [字典树](#386)
### [0387_字符串中的第一个唯一字符](#387)
#### [队列](#387)
#### [哈希表](#387)
#### [字符串](#387)
#### [计数](#387)
### [0388_文件的最长绝对路径](#388)
#### [栈](#388)
#### [深度优先搜索](#388)
#### [字符串](#388)
### [0389_找不同](#389)
#### [位运算](#389)
#### [哈希表](#389)
#### [字符串](#389)
#### [排序](#389)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0380_O(1) 时间插入、删除和获取随机元素
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 随机化
---
### 0381_O(1) 时间插入、删除和获取随机元素 - 允许重复
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 随机化
---
### 0382_链表随机节点
___
#### 水塘抽样
___
#### 链表
___
#### 数学
___
#### 随机化
---
### 0383_赎金信
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 0384_打乱数组
___
#### 设计
___
#### 数组
___
#### 数学
___
#### 随机化
---
### 0385_迷你语法分析器
___
#### 栈
___
#### 深度优先搜索
___
#### 字符串
---
### 0386_字典序排数
___
#### 深度优先搜索
___
#### 字典树
---
### 0387_字符串中的第一个唯一字符
___
#### 队列
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 0388_文件的最长绝对路径
___
#### 栈
___
#### 深度优先搜索
___
#### 字符串
---
### 0389_找不同
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 哈希表 | 字典树 |
| 字符串 | 排序 | 数学 |
| 数组 | 栈 | 水塘抽样 |
| 深度优先搜索 | 计数 | 设计 |
| 链表 | 队列 | 随机化 |

# [380. O(1) 时间插入、删除和获取随机元素](https://leetcode.cn/problems/insert-delete-getrandom-o1){#380}

{{< tabs "380" >}}

{{% tab "python" %}}
```python
class RandomizedSet:
    def __init__(self):
        self.d = {}
        self.q = []

    def insert(self, val: int) -> bool:
        if val in self.d:
            return False
        self.d[val] = len(self.q)
        self.q.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.d:
            return False
        i = self.d[val]
        self.d[self.q[-1]] = i
        self.q[i] = self.q[-1]
        self.q.pop()
        self.d.pop(val)
        return True

    def getRandom(self) -> int:
        return choice(self.q)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class RandomizedSet {
    private Map<Integer, Integer> d = new HashMap<>();
    private List<Integer> q = new ArrayList<>();
    private Random rnd = new Random();

    public RandomizedSet() {
    }

    public boolean insert(int val) {
        if (d.containsKey(val)) {
            return false;
        }
        d.put(val, q.size());
        q.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (!d.containsKey(val)) {
            return false;
        }
        int i = d.get(val);
        d.put(q.get(q.size() - 1), i);
        q.set(i, q.get(q.size() - 1));
        q.remove(q.size() - 1);
        d.remove(val);
        return true;
    }

    public int getRandom() {
        return q.get(rnd.nextInt(q.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (d.count(val)) {
            return false;
        }
        d[val] = q.size();
        q.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!d.count(val)) {
            return false;
        }
        int i = d[val];
        d[q.back()] = i;
        q[i] = q.back();
        q.pop_back();
        d.erase(val);
        return true;
    }

    int getRandom() {
        return q[rand() % q.size()];
    }

private:
    unordered_map<int, int> d;
    vector<int> q;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type RandomizedSet struct {
	d map[int]int
	q []int
}

func Constructor() RandomizedSet {
	return RandomizedSet{map[int]int{}, []int{}}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.d[val]; ok {
		return false
	}
	this.d[val] = len(this.q)
	this.q = append(this.q, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.d[val]; !ok {
		return false
	}
	i := this.d[val]
	this.d[this.q[len(this.q)-1]] = i
	this.q[i] = this.q[len(this.q)-1]
	this.q = this.q[:len(this.q)-1]
	delete(this.d, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.q[rand.Intn(len(this.q))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class RandomizedSet {
    private d: Map<number, number> = new Map();
    private q: number[] = [];

    constructor() {}

    insert(val: number): boolean {
        if (this.d.has(val)) {
            return false;
        }
        this.d.set(val, this.q.length);
        this.q.push(val);
        return true;
    }

    remove(val: number): boolean {
        if (!this.d.has(val)) {
            return false;
        }
        const i = this.d.get(val)!;
        this.d.set(this.q[this.q.length - 1], i);
        this.q[i] = this.q[this.q.length - 1];
        this.q.pop();
        this.d.delete(val);
        return true;
    }

    getRandom(): number {
        return this.q[Math.floor(Math.random() * this.q.length)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use rand::Rng;
use std::collections::HashSet;

struct RandomizedSet {
    list: HashSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Self {
            list: HashSet::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        self.list.insert(val)
    }

    fn remove(&mut self, val: i32) -> bool {
        self.list.remove(&val)
    }

    fn get_random(&self) -> i32 {
        let i = rand::thread_rng().gen_range(0, self.list.len());
        *self.list.iter().collect::<Vec<&i32>>()[i]
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class RandomizedSet {
    private Dictionary<int, int> d = new Dictionary<int, int>();
    private List<int> q = new List<int>();

    public RandomizedSet() {

    }

    public bool Insert(int val) {
        if (d.ContainsKey(val)) {
            return false;
        }
        d.Add(val, q.Count);
        q.Add(val);
        return true;
    }

    public bool Remove(int val) {
        if (!d.ContainsKey(val)) {
            return false;
        }
        int i = d[val];
        d[q[q.Count - 1]] = i;
        q[i] = q[q.Count - 1];
        q.RemoveAt(q.Count - 1);
        d.Remove(val);
        return true;
    }

    public int GetRandom() {
        return q[new Random().Next(0, q.Count)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现<code>RandomizedSet</code> 类：</p>

<div class="original__bRMd">
<div>
<ul>
	<li><code>RandomizedSet()</code> 初始化 <code>RandomizedSet</code> 对象</li>
	<li><code>bool insert(int val)</code> 当元素 <code>val</code> 不存在时，向集合中插入该项，并返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>bool remove(int val)</code> 当元素 <code>val</code> 存在时，从集合中移除该项，并返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
	<li><code>int getRandom()</code> 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 <strong>相同的概率</strong> 被返回。</li>
</ul>

<p>你必须实现类的所有函数，并满足每个函数的 <strong>平均</strong> 时间复杂度为 <code>O(1)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
<strong>输出</strong>
[null, true, false, true, 2, true, false, 2]

<strong>解释</strong>
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>最多调用 <code>insert</code>、<code>remove</code> 和 <code>getRandom</code> 函数 <code>2 *&nbsp;</code><code>10<sup>5</sup></code> 次</li>
	<li>在调用 <code>getRandom</code> 方法时，数据结构中 <strong>至少存在一个</strong> 元素。</li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 动态列表

我们定义一个动态列表 $q$，用于存储集合中的元素，定义一个哈希表 $d$，用于存储每个元素在 $q$ 中的下标。

插入元素时，如果元素已经存在于哈希表 $d$ 中，直接返回 `false`；否则，我们将元素插入到动态列表 $q$ 的末尾，同时将元素和其在 $q$ 中的下标插入到哈希表 $d$ 中，最后返回 `true`。

删除元素时，如果元素不存在于哈希表 $d$ 中，直接返回 `false`；否则，我们从哈希表中获取元素在列表 $q$ 中的下标 $i$，然后将列表 $q$ 的最后一个元素 $q[-1]$ 与 $q[i]$ 交换，然后将哈希表中 $q[-1]$ 的下标更新为 $i$，最后将 $q$ 的最后一个元素删除，同时将元素从哈希表中删除，最后返回 `true`。

获取随机元素时，我们从动态列表 $q$ 中随机选择一个元素返回即可。

时间复杂度 $O(1)$，空间复杂度 $O(n)$。其中 $n$ 为集合中元素的个数。

<!-- tabs:start -->

#### Python3

```python
class RandomizedSet:
    def __init__(self):
        self.d = {}
        self.q = []

    def insert(self, val: int) -> bool:
        if val in self.d:
            return False
        self.d[val] = len(self.q)
        self.q.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.d:
            return False
        i = self.d[val]
        self.d[self.q[-1]] = i
        self.q[i] = self.q[-1]
        self.q.pop()
        self.d.pop(val)
        return True

    def getRandom(self) -> int:
        return choice(self.q)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```

#### Java

```java
class RandomizedSet {
    private Map<Integer, Integer> d = new HashMap<>();
    private List<Integer> q = new ArrayList<>();
    private Random rnd = new Random();

    public RandomizedSet() {
    }

    public boolean insert(int val) {
        if (d.containsKey(val)) {
            return false;
        }
        d.put(val, q.size());
        q.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (!d.containsKey(val)) {
            return false;
        }
        int i = d.get(val);
        d.put(q.get(q.size() - 1), i);
        q.set(i, q.get(q.size() - 1));
        q.remove(q.size() - 1);
        d.remove(val);
        return true;
    }

    public int getRandom() {
        return q.get(rnd.nextInt(q.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```

#### C++

```cpp
class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (d.count(val)) {
            return false;
        }
        d[val] = q.size();
        q.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!d.count(val)) {
            return false;
        }
        int i = d[val];
        d[q.back()] = i;
        q[i] = q.back();
        q.pop_back();
        d.erase(val);
        return true;
    }

    int getRandom() {
        return q[rand() % q.size()];
    }

private:
    unordered_map<int, int> d;
    vector<int> q;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```

#### Go

```go
type RandomizedSet struct {
	d map[int]int
	q []int
}

func Constructor() RandomizedSet {
	return RandomizedSet{map[int]int{}, []int{}}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.d[val]; ok {
		return false
	}
	this.d[val] = len(this.q)
	this.q = append(this.q, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if _, ok := this.d[val]; !ok {
		return false
	}
	i := this.d[val]
	this.d[this.q[len(this.q)-1]] = i
	this.q[i] = this.q[len(this.q)-1]
	this.q = this.q[:len(this.q)-1]
	delete(this.d, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.q[rand.Intn(len(this.q))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
```

#### TypeScript

```ts
class RandomizedSet {
    private d: Map<number, number> = new Map();
    private q: number[] = [];

    constructor() {}

    insert(val: number): boolean {
        if (this.d.has(val)) {
            return false;
        }
        this.d.set(val, this.q.length);
        this.q.push(val);
        return true;
    }

    remove(val: number): boolean {
        if (!this.d.has(val)) {
            return false;
        }
        const i = this.d.get(val)!;
        this.d.set(this.q[this.q.length - 1], i);
        this.q[i] = this.q[this.q.length - 1];
        this.q.pop();
        this.d.delete(val);
        return true;
    }

    getRandom(): number {
        return this.q[Math.floor(Math.random() * this.q.length)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
```

#### Rust

```rust
use rand::Rng;
use std::collections::HashSet;

struct RandomizedSet {
    list: HashSet<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Self {
            list: HashSet::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        self.list.insert(val)
    }

    fn remove(&mut self, val: i32) -> bool {
        self.list.remove(&val)
    }

    fn get_random(&self) -> i32 {
        let i = rand::thread_rng().gen_range(0, self.list.len());
        *self.list.iter().collect::<Vec<&i32>>()[i]
    }
}
```

#### C#

```cs
public class RandomizedSet {
    private Dictionary<int, int> d = new Dictionary<int, int>();
    private List<int> q = new List<int>();

    public RandomizedSet() {

    }

    public bool Insert(int val) {
        if (d.ContainsKey(val)) {
            return false;
        }
        d.Add(val, q.Count);
        q.Add(val);
        return true;
    }

    public bool Remove(int val) {
        if (!d.ContainsKey(val)) {
            return false;
        }
        int i = d[val];
        d[q[q.Count - 1]] = i;
        q[i] = q[q.Count - 1];
        q.RemoveAt(q.Count - 1);
        d.Remove(val);
        return true;
    }

    public int GetRandom() {
        return q[new Random().Next(0, q.Count)];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [381. O(1) 时间插入、删除和获取随机元素 - 允许重复](https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed){#381}

{{< tabs "381" >}}

{{% tab "python" %}}
```python
class RandomizedCollection:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = {}
        self.l = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        idx_set = self.m.get(val, set())
        idx_set.add(len(self.l))
        self.m[val] = idx_set
        self.l.append(val)
        return len(idx_set) == 1

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.m:
            return False
        idx_set = self.m[val]
        idx = list(idx_set)[0]
        last_idx = len(self.l) - 1
        self.l[idx] = self.l[last_idx]
        idx_set.remove(idx)

        last_idx_set = self.m[self.l[last_idx]]
        if last_idx in last_idx_set:
            last_idx_set.remove(last_idx)
        if idx < last_idx:
            last_idx_set.add(idx)
        if not idx_set:
            self.m.pop(val)
        self.l.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return -1 if len(self.l) == 0 else random.choice(self.l)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class RandomizedCollection {
    private Map<Integer, Set<Integer>> m;
    private List<Integer> l;
    private Random rnd;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        m = new HashMap<>();
        l = new ArrayList<>();
        rnd = new Random();
    }

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain
     * the specified element.
     */
    public boolean insert(int val) {
        m.computeIfAbsent(val, k -> new HashSet<>()).add(l.size());
        l.add(val);
        return m.get(val).size() == 1;
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified
     * element.
     */
    public boolean remove(int val) {
        if (!m.containsKey(val)) {
            return false;
        }
        Set<Integer> idxSet = m.get(val);
        int idx = idxSet.iterator().next();
        int lastIdx = l.size() - 1;
        l.set(idx, l.get(lastIdx));
        idxSet.remove(idx);

        Set<Integer> lastIdxSet = m.get(l.get(lastIdx));
        lastIdxSet.remove(lastIdx);
        if (idx < lastIdx) {
            lastIdxSet.add(idx);
        }
        if (idxSet.isEmpty()) {
            m.remove(val);
        }
        l.remove(lastIdx);
        return true;
    }

    /** Get a random element from the collection. */
    public int getRandom() {
        int size = l.size();
        return size == 0 ? -1 : l.get(rnd.nextInt(size));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>RandomizedCollection</code> 是一种包含数字集合(可能是重复的)的数据结构。它应该支持插入和删除特定元素，以及删除随机元素。</p>

<p>实现 <code>RandomizedCollection</code> 类:</p>

<ul>
	<li><code>RandomizedCollection()</code>初始化空的 <code>RandomizedCollection</code> 对象。</li>
	<li><code>bool insert(int val)</code>&nbsp;将一个 <code>val</code> 项插入到集合中，即使该项已经存在。如果该项不存在，则返回 <code>true</code> ，否则返回 <code>false</code> 。</li>
	<li><code>bool remove(int val)</code>&nbsp;如果存在，从集合中移除一个 <code>val</code> 项。如果该项存在，则返回 <code>true</code> ，否则返回 <code>false</code> 。注意，如果 <code>val</code> 在集合中出现多次，我们只删除其中一个。</li>
	<li><code>int getRandom()</code> 从当前的多个元素集合中返回一个随机元素。每个元素被返回的概率与集合中包含的相同值的数量 <strong>线性相关</strong> 。</li>
</ul>

<p>您必须实现类的函数，使每个函数的 <strong>平均</strong> 时间复杂度为 <code>O(1)</code> 。</p>

<p><strong>注意：</strong>生成测试用例时，只有在 <code>RandomizedCollection</code> 中 <strong>至少有一项</strong> 时，才会调用 <code>getRandom</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入</strong>
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
<strong>输出</strong>
[null, true, false, true, 2, true, 1]

<strong>解释</strong>
RandomizedCollection collection = new RandomizedCollection();// 初始化一个空的集合。
collection.insert(1);   // 返回 true，因为集合不包含 1。
                        // 将 1 插入到集合中。
collection.insert(1);   // 返回 false，因为集合包含 1。
&nbsp;                       // 将另一个 1 插入到集合中。集合现在包含 [1,1]。
collection.insert(2);   // 返回 true，因为集合不包含 2。
&nbsp;                       // 将 2 插入到集合中。集合现在包含 [1,1,2]。
collection.getRandom(); // getRandom 应当:
&nbsp;                       // 有 2/3 的概率返回 1,
&nbsp;                       // 1/3 的概率返回 2。
collection.remove(1);   // 返回 true，因为集合包含 1。
&nbsp;                       // 从集合中移除 1。集合现在包含 [1,2]。
collection.getRandom(); // getRandom 应该返回 1 或 2，两者的可能性相同。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
	<li><code>insert</code>,&nbsp;<code>remove</code>&nbsp;和&nbsp;<code>getRandom</code>&nbsp;最多 <strong>总共</strong> 被调用&nbsp;<code>2 * 10<sup>5</sup></code>&nbsp;次</li>
	<li>当调用 <code>getRandom</code> 时，数据结构中 <strong>至少有一个</strong> 元素</li>
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
class RandomizedCollection:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = {}
        self.l = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        idx_set = self.m.get(val, set())
        idx_set.add(len(self.l))
        self.m[val] = idx_set
        self.l.append(val)
        return len(idx_set) == 1

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.m:
            return False
        idx_set = self.m[val]
        idx = list(idx_set)[0]
        last_idx = len(self.l) - 1
        self.l[idx] = self.l[last_idx]
        idx_set.remove(idx)

        last_idx_set = self.m[self.l[last_idx]]
        if last_idx in last_idx_set:
            last_idx_set.remove(last_idx)
        if idx < last_idx:
            last_idx_set.add(idx)
        if not idx_set:
            self.m.pop(val)
        self.l.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return -1 if len(self.l) == 0 else random.choice(self.l)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```

#### Java

```java
class RandomizedCollection {
    private Map<Integer, Set<Integer>> m;
    private List<Integer> l;
    private Random rnd;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        m = new HashMap<>();
        l = new ArrayList<>();
        rnd = new Random();
    }

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain
     * the specified element.
     */
    public boolean insert(int val) {
        m.computeIfAbsent(val, k -> new HashSet<>()).add(l.size());
        l.add(val);
        return m.get(val).size() == 1;
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified
     * element.
     */
    public boolean remove(int val) {
        if (!m.containsKey(val)) {
            return false;
        }
        Set<Integer> idxSet = m.get(val);
        int idx = idxSet.iterator().next();
        int lastIdx = l.size() - 1;
        l.set(idx, l.get(lastIdx));
        idxSet.remove(idx);

        Set<Integer> lastIdxSet = m.get(l.get(lastIdx));
        lastIdxSet.remove(lastIdx);
        if (idx < lastIdx) {
            lastIdxSet.add(idx);
        }
        if (idxSet.isEmpty()) {
            m.remove(val);
        }
        l.remove(lastIdx);
        return true;
    }

    /** Get a random element from the collection. */
    public int getRandom() {
        int size = l.size();
        return size == 0 ? -1 : l.get(rnd.nextInt(size));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node){#382}

{{< tabs "382" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.head = head

    def getRandom(self) -> int:
        n = ans = 0
        head = self.head
        while head:
            n += 1
            x = random.randint(1, n)
            if n == x:
                ans = head.val
            head = head.next
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode head;
    private Random random = new Random();

    public Solution(ListNode head) {
        this.head = head;
    }

    public int getRandom() {
        int ans = 0, n = 0;
        for (ListNode node = head; node != null; node = node.next) {
            ++n;
            int x = 1 + random.nextInt(n);
            if (n == x) {
                ans = node.val;
            }
        }
        return ans;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int n = 0, ans = 0;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            n += 1;
            int x = 1 + rand() % n;
            if (n == x) ans = node->val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
	head *ListNode
}

func Constructor(head *ListNode) Solution {
	return Solution{head}
}

func (this *Solution) GetRandom() int {
	n, ans := 0, 0
	for node := this.head; node != nil; node = node.Next {
		n++
		x := 1 + rand.Intn(n)
		if n == x {
			ans = node.Val
		}
	}
	return ans
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点<strong> 被选中的概率一样</strong> 。</p>

<p>实现 <code>Solution</code> 类：</p>

<ul>
	<li><code>Solution(ListNode head)</code> 使用整数数组初始化对象。</li>
	<li><code>int getRandom()</code> 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0382.Linked%20List%20Random%20Node/images/getrand-linked-list.jpg" style="width: 302px; height: 62px;" />
<pre>
<strong>输入</strong>
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
<strong>输出</strong>
[null, 1, 3, 2, 2, 3]

<strong>解释</strong>
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // 返回 1
solution.getRandom(); // 返回 3
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 2
solution.getRandom(); // 返回 3
// getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中的节点数在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>至多调用&nbsp;<code>getRandom</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>如果链表非常大且长度未知，该怎么处理？</li>
	<li>你能否在不使用额外空间的情况下解决此问题？</li>
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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.head = head

    def getRandom(self) -> int:
        n = ans = 0
        head = self.head
        while head:
            n += 1
            x = random.randint(1, n)
            if n == x:
                ans = head.val
            head = head.next
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode head;
    private Random random = new Random();

    public Solution(ListNode head) {
        this.head = head;
    }

    public int getRandom() {
        int ans = 0, n = 0;
        for (ListNode node = head; node != null; node = node.next) {
            ++n;
            int x = 1 + random.nextInt(n);
            if (n == x) {
                ans = node.val;
            }
        }
        return ans;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int n = 0, ans = 0;
        for (ListNode* node = head; node != nullptr; node = node->next) {
            n += 1;
            int x = 1 + rand() % n;
            if (n == x) ans = node->val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
	head *ListNode
}

func Constructor(head *ListNode) Solution {
	return Solution{head}
}

func (this *Solution) GetRandom() int {
	n, ans := 0, 0
	for node := this.head; node != nil; node = node.Next {
		n++
		x := 1 + rand.Intn(n)
		if n == x {
			ans = node.Val
		}
	}
	return ans
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [383. 赎金信](https://leetcode.cn/problems/ransom-note){#383}

{{< tabs "383" >}}

{{% tab "python" %}}
```python
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnt = Counter(magazine)
        for c in ransomNote:
            cnt[c] -= 1
            if cnt[c] < 0:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] cnt = new int[26];
        for (int i = 0; i < magazine.length(); ++i) {
            ++cnt[magazine.charAt(i) - 'a'];
        }
        for (int i = 0; i < ransomNote.length(); ++i) {
            if (--cnt[ransomNote.charAt(i) - 'a'] < 0) {
                return false;
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
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]{};
        for (char& c : magazine) {
            ++cnt[c - 'a'];
        }
        for (char& c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canConstruct(ransomNote string, magazine string) bool {
	cnt := [26]int{}
	for _, c := range magazine {
		cnt[c-'a']++
	}
	for _, c := range ransomNote {
		cnt[c-'a']--
		if cnt[c-'a'] < 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canConstruct(ransomNote: string, magazine: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of magazine) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    for (const c of ransomNote) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        int[] cnt = new int[26];
        foreach (var c in magazine) {
            ++cnt[c - 'a'];
        }
        foreach (var c in ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $ransomNote
     * @param String $magazine
     * @return Boolean
     */
    function canConstruct($ransomNote, $magazine) {
        $arrM = str_split($magazine);
        for ($i = 0; $i < strlen($magazine); $i++) {
            $hashtable[$arrM[$i]] += 1;
        }
        for ($j = 0; $j < strlen($ransomNote); $j++) {
            if (!isset($hashtable[$ransomNote[$j]]) || $hashtable[$ransomNote[$j]] == 0) {
                return false;
            } else {
                $hashtable[$ransomNote[$j]] -= 1;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串：<code>ransomNote</code> 和 <code>magazine</code> ，判断 <code>ransomNote</code> 能不能由 <code>magazine</code> 里面的字符构成。</p>

<p>如果可以，返回 <code>true</code> ；否则返回 <code>false</code> 。</p>

<p><code>magazine</code> 中的每个字符只能在 <code>ransomNote</code> 中使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "a", magazine = "b"
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "ab"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ransomNote = "aa", magazine = "aab"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ransomNote.length, magazine.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ransomNote</code> 和 <code>magazine</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以用一个哈希表或长度为 $26$ 的数组 $cnt$ 记录字符串 `magazine` 中所有字符出现的次数。然后遍历字符串 `ransomNote`，对于其中的每个字符 $c$，我们将其从 $cnt$ 的次数减 $1$，如果减 $1$ 之后的次数小于 $0$，说明 $c$ 在 `magazine` 中出现的次数不够，因此无法构成 `ransomNote`，返回 $false$ 即可。

否则，遍历结束后，说明 `ransomNote` 中的每个字符都可以在 `magazine` 中找到对应的字符，因此返回 $true$。

时间复杂度 $O(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别为字符串 `ransomNote` 和 `magazine` 的长度；而 $C$ 为字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnt = Counter(magazine)
        for c in ransomNote:
            cnt[c] -= 1
            if cnt[c] < 0:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] cnt = new int[26];
        for (int i = 0; i < magazine.length(); ++i) {
            ++cnt[magazine.charAt(i) - 'a'];
        }
        for (int i = 0; i < ransomNote.length(); ++i) {
            if (--cnt[ransomNote.charAt(i) - 'a'] < 0) {
                return false;
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
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]{};
        for (char& c : magazine) {
            ++cnt[c - 'a'];
        }
        for (char& c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canConstruct(ransomNote string, magazine string) bool {
	cnt := [26]int{}
	for _, c := range magazine {
		cnt[c-'a']++
	}
	for _, c := range ransomNote {
		cnt[c-'a']--
		if cnt[c-'a'] < 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canConstruct(ransomNote: string, magazine: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of magazine) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    for (const c of ransomNote) {
        if (--cnt[c.charCodeAt(0) - 97] < 0) {
            return false;
        }
    }
    return true;
}
```

#### C#

```cs
public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        int[] cnt = new int[26];
        foreach (var c in magazine) {
            ++cnt[c - 'a'];
        }
        foreach (var c in ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $ransomNote
     * @param String $magazine
     * @return Boolean
     */
    function canConstruct($ransomNote, $magazine) {
        $arrM = str_split($magazine);
        for ($i = 0; $i < strlen($magazine); $i++) {
            $hashtable[$arrM[$i]] += 1;
        }
        for ($j = 0; $j < strlen($ransomNote); $j++) {
            if (!isset($hashtable[$ransomNote[$j]]) || $hashtable[$ransomNote[$j]] == 0) {
                return false;
            } else {
                $hashtable[$ransomNote[$j]] -= 1;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [384. 打乱数组](https://leetcode.cn/problems/shuffle-an-array){#384}

{{< tabs "384" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.original = nums.copy()

    def reset(self) -> List[int]:
        self.nums = self.original.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        for i in range(len(self.nums)):
            j = random.randrange(i, len(self.nums))
            self.nums[i], self.nums[j] = self.nums[j], self.nums[i]
        return self.nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private int[] original;
    private Random rand;

    public Solution(int[] nums) {
        this.nums = nums;
        this.original = Arrays.copyOf(nums, nums.length);
        this.rand = new Random();
    }

    public int[] reset() {
        nums = Arrays.copyOf(original, original.length);
        return nums;
    }

    public int[] shuffle() {
        for (int i = 0; i < nums.length; ++i) {
            swap(i, i + rand.nextInt(nums.length - i));
        }
        return nums;
    }

    private void swap(int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> nums;
    vector<int> original;

    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Solution struct {
	nums, original []int
}

func Constructor(nums []int) Solution {
	return Solution{nums, append([]int(nil), nums...)}
}

func (this *Solution) Reset() []int {
	copy(this.nums, this.original)
	return this.nums
}

func (this *Solution) Shuffle() []int {
	n := len(this.nums)
	for i := range this.nums {
		j := i + rand.Intn(n-i)
		this.nums[i], this.nums[j] = this.nums[j], this.nums[i]
	}
	return this.nums
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Solution {
    private nums: number[];

    constructor(nums: number[]) {
        this.nums = nums;
    }

    reset(): number[] {
        return this.nums;
    }

    shuffle(): number[] {
        const n = this.nums.length;
        const res = [...this.nums];
        for (let i = 0; i < n; i++) {
            const j = Math.floor(Math.random() * n);
            [res[i], res[j]] = [res[j], res[i]];
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use rand::Rng;
struct Solution {
    nums: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        Self { nums }
    }

    fn reset(&self) -> Vec<i32> {
        self.nums.clone()
    }

    fn shuffle(&mut self) -> Vec<i32> {
        let n = self.nums.len();
        let mut res = self.nums.clone();
        for i in 0..n {
            let j = rand::thread_rng().gen_range(0, n);
            res.swap(i, j);
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 */
const Solution = function (nums) {
    this.nums = nums || [];
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function () {
    return this.nums;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function () {
    let a = this.nums.slice();
    for (let i = 0; i < a.length; i++) {
        let rand = Math.floor(Math.random() * (a.length - i)) + i;
        let tmp = a[i];
        a[i] = a[rand];
        a[rand] = tmp;
    }
    return a;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = Object.create(Solution).createNew(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是&nbsp;<strong>等可能</strong>&nbsp;的。</p>

<p>实现 <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(int[] nums)</code> 使用整数数组 <code>nums</code> 初始化对象</li>
	<li><code>int[] reset()</code> 重设数组到它的初始状态并返回</li>
	<li><code>int[] shuffle()</code> 返回数组随机打乱后的结果</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
<strong>输出</strong>
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

<strong>解释</strong>
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>nums</code> 中的所有元素都是 <strong>唯一的</strong></li>
	<li>最多可以调用 <code>10<sup>4</sup></code> 次 <code>reset</code> 和 <code>shuffle</code></li>
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
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.original = nums.copy()

    def reset(self) -> List[int]:
        self.nums = self.original.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        for i in range(len(self.nums)):
            j = random.randrange(i, len(self.nums))
            self.nums[i], self.nums[j] = self.nums[j], self.nums[i]
        return self.nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] original;
    private Random rand;

    public Solution(int[] nums) {
        this.nums = nums;
        this.original = Arrays.copyOf(nums, nums.length);
        this.rand = new Random();
    }

    public int[] reset() {
        nums = Arrays.copyOf(original, original.length);
        return nums;
    }

    public int[] shuffle() {
        for (int i = 0; i < nums.length; ++i) {
            swap(i, i + rand.nextInt(nums.length - i));
        }
        return nums;
    }

    private void swap(int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
```

#### C++

```cpp
class Solution {
public:
    vector<int> nums;
    vector<int> original;

    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```

#### Go

```go
type Solution struct {
	nums, original []int
}

func Constructor(nums []int) Solution {
	return Solution{nums, append([]int(nil), nums...)}
}

func (this *Solution) Reset() []int {
	copy(this.nums, this.original)
	return this.nums
}

func (this *Solution) Shuffle() []int {
	n := len(this.nums)
	for i := range this.nums {
		j := i + rand.Intn(n-i)
		this.nums[i], this.nums[j] = this.nums[j], this.nums[i]
	}
	return this.nums
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */
```

#### TypeScript

```ts
class Solution {
    private nums: number[];

    constructor(nums: number[]) {
        this.nums = nums;
    }

    reset(): number[] {
        return this.nums;
    }

    shuffle(): number[] {
        const n = this.nums.length;
        const res = [...this.nums];
        for (let i = 0; i < n; i++) {
            const j = Math.floor(Math.random() * n);
            [res[i], res[j]] = [res[j], res[i]];
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
```

#### Rust

```rust
use rand::Rng;
struct Solution {
    nums: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        Self { nums }
    }

    fn reset(&self) -> Vec<i32> {
        self.nums.clone()
    }

    fn shuffle(&mut self) -> Vec<i32> {
        let n = self.nums.len();
        let mut res = self.nums.clone();
        for i in 0..n {
            let j = rand::thread_rng().gen_range(0, n);
            res.swap(i, j);
        }
        res
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 */
const Solution = function (nums) {
    this.nums = nums || [];
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function () {
    return this.nums;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function () {
    let a = this.nums.slice();
    for (let i = 0; i < a.length; i++) {
        let rand = Math.floor(Math.random() * (a.length - i)) + i;
        let tmp = a[i];
        a[i] = a[rand];
        a[rand] = tmp;
    }
    return a;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = Object.create(Solution).createNew(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [385. 迷你语法分析器](https://leetcode.cn/problems/mini-parser){#385}

{{< tabs "385" >}}

{{% tab "python" %}}
```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        if s[0] != '[':
            return NestedInteger(int(s))
        stk, x, neg = [], 0, False
        for i, c in enumerate(s):
            if c == '-':
                neg = True
            elif c.isdigit():
                x = x * 10 + int(c)
            elif c == '[':
                stk.append(NestedInteger())
            elif c in ',]':
                if s[i - 1].isdigit():
                    if neg:
                        x = -x
                    stk[-1].add(NestedInteger(x))
                x, neg = 0, False
                if c == ']' and len(stk) > 1:
                    t = stk.pop()
                    stk[-1].add(t)
        return stk.pop()
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String s) {
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }
        Deque<NestedInteger> stk = new ArrayDeque<>();
        int x = 0;
        boolean neg = false;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '-') {
                neg = true;
            } else if (Character.isDigit(c)) {
                x = x * 10 + c - '0';
            } else if (c == '[') {
                stk.push(new NestedInteger());
            } else if (c == ',' || c == ']') {
                if (Character.isDigit(s.charAt(i - 1))) {
                    if (neg) {
                        x = -x;
                    }
                    stk.peek().add(new NestedInteger(x));
                }
                x = 0;
                neg = false;
                if (c == ']' && stk.size() > 1) {
                    NestedInteger t = stk.pop();
                    stk.peek().add(t);
                }
            }
        }
        return stk.peek();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> stk;
        int x = 0;
        bool neg = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                neg = true;
            } else if (isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                stk.push(NestedInteger());
            } else if (s[i] == ',' || s[i] == ']') {
                if (isdigit(s[i - 1])) {
                    if (neg) {
                        x = -x;
                    }
                    stk.top().add(NestedInteger(x));
                }
                x = 0;
                neg = false;
                if (s[i] == ']' && stk.size() > 1) {
                    auto t = stk.top();
                    stk.pop();
                    stk.top().add(t);
                }
            }
        }
        return stk.top();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */
func deserialize(s string) *NestedInteger {
	if s[0] != '[' {
		v, _ := strconv.Atoi(s)
		ans := NestedInteger{}
		ans.SetInteger(v)
		return &ans
	}
	stk := []*NestedInteger{}
	x := 0
	neg := false
	for i, c := range s {
		if c == '-' {
			neg = true
		} else if c >= '0' && c <= '9' {
			x = x*10 + int(c-'0')
		} else if c == '[' {
			stk = append(stk, &NestedInteger{})
		} else if c == ',' || c == ']' {
			if s[i-1] >= '0' && s[i-1] <= '9' {
				if neg {
					x = -x
				}
				t := NestedInteger{}
				t.SetInteger(x)
				stk[len(stk)-1].Add(t)
			}
			x = 0
			neg = false
			if c == ']' && len(stk) > 1 {
				t := stk[len(stk)-1]
				stk = stk[:len(stk)-1]
				stk[len(stk)-1].Add(*t)
			}
		}
	}
	return stk[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

function deserialize(s: string): NestedInteger {
    if (s[0] !== '[') {
        return new NestedInteger(+s);
    }
    const stk: NestedInteger[] = [];
    let x = 0;
    let neg = false;
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '-') {
            neg = true;
        } else if (s[i] === '[') {
            stk.push(new NestedInteger());
        } else if (s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + s[i].charCodeAt(0) - '0'.charCodeAt(0);
        } else if (s[i] === ',' || s[i] === ']') {
            if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                stk[stk.length - 1].add(new NestedInteger(neg ? -x : x));
            }
            x = 0;
            neg = false;
            if (s[i] === ']' && stk.length > 1) {
                const t = stk.pop()!;
                stk[stk.length - 1].add(t);
            }
        }
    }
    return stk[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果&nbsp;<code>NestedInteger</code> 。</p>

<p>列表中的每个元素只可能是整数或整数嵌套列表</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "324",
<strong>输出：</strong>324
<strong>解释：</strong>你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "[123,[456,[789]]]",
<strong>输出：</strong>[123,[456,[789]]]
<strong>解释：</strong>返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
1. 一个 integer 包含值 123
2. 一个包含两个元素的嵌套列表：
    i.  一个 integer 包含值 456
    ii. 一个包含一个元素的嵌套列表
         a. 一个 integer 包含值 789
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 由数字、方括号&nbsp;<code>"[]"</code>、负号&nbsp;<code>'-'</code>&nbsp;、逗号&nbsp;<code>','</code>组成</li>
	<li>用例保证&nbsp;<code>s</code> 是可解析的&nbsp;<code>NestedInteger</code></li>
	<li>输入中的所有值的范围是&nbsp;<code>[-10<sup>6</sup>, 10<sup>6</sup>]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们首先判断字符串 $s$ 是否为空或是一个空列表，如果是的话，直接返回一个空的 `NestedInteger` 即可。如果 $s$ 是一个整数，我们直接返回一个包含这个整数的 `NestedInteger`。否则，我们从左到右遍历字符串 $s$，如果当前深度为 $0$，并且遇到了逗号或者字符串 $s$ 的末尾，则我们截取出一个子串并递归调用函数解析该子串，将返回值加入到列表中。否则，如果当前遇到了左括号，我们将深度加 $1$，并继续遍历。如果遇到了右括号，我们将深度减 $1$，继续遍历。

遍历结束后，返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        if not s or s == '[]':
            return NestedInteger()
        if s[0] != '[':
            return NestedInteger(int(s))
        ans = NestedInteger()
        depth, j = 0, 1
        for i in range(1, len(s)):
            if depth == 0 and (s[i] == ',' or i == len(s) - 1):
                ans.add(self.deserialize(s[j:i]))
                j = i + 1
            elif s[i] == '[':
                depth += 1
            elif s[i] == ']':
                depth -= 1
        return ans
```

#### Java

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String s) {
        if ("".equals(s) || "[]".equals(s)) {
            return new NestedInteger();
        }
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }
        NestedInteger ans = new NestedInteger();
        int depth = 0;
        for (int i = 1, j = 1; i < s.length(); ++i) {
            if (depth == 0 && (s.charAt(i) == ',' || i == s.length() - 1)) {
                ans.add(deserialize(s.substring(j, i)));
                j = i + 1;
            } else if (s.charAt(i) == '[') {
                ++depth;
            } else if (s.charAt(i) == ']') {
                --depth;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s == "" || s == "[]") {
            return NestedInteger();
        }
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        NestedInteger ans;
        int depth = 0;
        for (int i = 1, j = 1; i < s.size(); ++i) {
            if (depth == 0 && (s[i] == ',' || i == s.size() - 1)) {
                ans.add(deserialize(s.substr(j, i - j)));
                j = i + 1;
            } else if (s[i] == '[') {
                ++depth;
            } else if (s[i] == ']') {
                --depth;
            }
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */
func deserialize(s string) *NestedInteger {
	ans := &NestedInteger{}
	if s == "" || s == "[]" {
		return ans
	}
	if s[0] != '[' {
		v, _ := strconv.Atoi(s)
		ans.SetInteger(v)
		return ans
	}
	depth := 0
	for i, j := 1, 1; i < len(s); i++ {
		if depth == 0 && (s[i] == ',' || i == len(s)-1) {
			(*ans).Add(*deserialize(s[j:i]))
			j = i + 1
		} else if s[i] == '[' {
			depth++
		} else if s[i] == ']' {
			depth--
		}
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

function deserialize(s: string): NestedInteger {
    if (s === '' || s === '[]') {
        return new NestedInteger();
    }
    if (s[0] !== '[') {
        return new NestedInteger(+s);
    }
    const ans: NestedInteger = new NestedInteger();
    let depth = 0;
    for (let i = 1, j = 1; i < s.length; ++i) {
        if (depth === 0 && (s[i] === ',' || i === s.length - 1)) {
            ans.add(deserialize(s.slice(j, i)));
            j = i + 1;
        } else if (s[i] === '[') {
            ++depth;
        } else if (s[i] === ']') {
            --depth;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈

我们可以使用栈来模拟递归的过程。

我们首先判断字符串 $s$ 是否是一个整数，如果是，直接返回一个包含这个整数的 `NestedInteger`。否则，我们从左到右遍历字符串 $s$，对于当前遍历到的字符 $c$：

-   如果 $c$ 是负号，我们将负号标识置为 `true`；
-   如果 $c$ 是数字，我们将数字加入到当前数字 $x$ 中，其中 $x$ 的初始值为 $0$；
-   如果 $c$ 是左括号，我们将一个新的 `NestedInteger` 压入栈中；
-   如果 $c$ 是右括号或者逗号，我们判断当前字符的前一个字符是否是数字，如果是，我们根据负号标识将当前数字 $x$ 加入到栈顶的 `NestedInteger` 中，然后将负号标识置为 `false`，当前数字 $x$ 重置为 $0$。如果 $c$ 是右括号，并且当前栈的大小大于 $1$，我们将栈顶的 `NestedInteger` 出栈，将其加入到栈顶的 `NestedInteger` 中。

遍历结束后，返回栈顶的 `NestedInteger` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        if s[0] != '[':
            return NestedInteger(int(s))
        stk, x, neg = [], 0, False
        for i, c in enumerate(s):
            if c == '-':
                neg = True
            elif c.isdigit():
                x = x * 10 + int(c)
            elif c == '[':
                stk.append(NestedInteger())
            elif c in ',]':
                if s[i - 1].isdigit():
                    if neg:
                        x = -x
                    stk[-1].add(NestedInteger(x))
                x, neg = 0, False
                if c == ']' and len(stk) > 1:
                    t = stk.pop()
                    stk[-1].add(t)
        return stk.pop()
```

#### Java

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String s) {
        if (s.charAt(0) != '[') {
            return new NestedInteger(Integer.parseInt(s));
        }
        Deque<NestedInteger> stk = new ArrayDeque<>();
        int x = 0;
        boolean neg = false;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '-') {
                neg = true;
            } else if (Character.isDigit(c)) {
                x = x * 10 + c - '0';
            } else if (c == '[') {
                stk.push(new NestedInteger());
            } else if (c == ',' || c == ']') {
                if (Character.isDigit(s.charAt(i - 1))) {
                    if (neg) {
                        x = -x;
                    }
                    stk.peek().add(new NestedInteger(x));
                }
                x = 0;
                neg = false;
                if (c == ']' && stk.size() > 1) {
                    NestedInteger t = stk.pop();
                    stk.peek().add(t);
                }
            }
        }
        return stk.peek();
    }
}
```

#### C++

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> stk;
        int x = 0;
        bool neg = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                neg = true;
            } else if (isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                stk.push(NestedInteger());
            } else if (s[i] == ',' || s[i] == ']') {
                if (isdigit(s[i - 1])) {
                    if (neg) {
                        x = -x;
                    }
                    stk.top().add(NestedInteger(x));
                }
                x = 0;
                neg = false;
                if (s[i] == ']' && stk.size() > 1) {
                    auto t = stk.top();
                    stk.pop();
                    stk.top().add(t);
                }
            }
        }
        return stk.top();
    }
};
```

#### Go

```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */
func deserialize(s string) *NestedInteger {
	if s[0] != '[' {
		v, _ := strconv.Atoi(s)
		ans := NestedInteger{}
		ans.SetInteger(v)
		return &ans
	}
	stk := []*NestedInteger{}
	x := 0
	neg := false
	for i, c := range s {
		if c == '-' {
			neg = true
		} else if c >= '0' && c <= '9' {
			x = x*10 + int(c-'0')
		} else if c == '[' {
			stk = append(stk, &NestedInteger{})
		} else if c == ',' || c == ']' {
			if s[i-1] >= '0' && s[i-1] <= '9' {
				if neg {
					x = -x
				}
				t := NestedInteger{}
				t.SetInteger(x)
				stk[len(stk)-1].Add(t)
			}
			x = 0
			neg = false
			if c == ']' && len(stk) > 1 {
				t := stk[len(stk)-1]
				stk = stk[:len(stk)-1]
				stk[len(stk)-1].Add(*t)
			}
		}
	}
	return stk[0]
}
```

#### TypeScript

```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

function deserialize(s: string): NestedInteger {
    if (s[0] !== '[') {
        return new NestedInteger(+s);
    }
    const stk: NestedInteger[] = [];
    let x = 0;
    let neg = false;
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '-') {
            neg = true;
        } else if (s[i] === '[') {
            stk.push(new NestedInteger());
        } else if (s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + s[i].charCodeAt(0) - '0'.charCodeAt(0);
        } else if (s[i] === ',' || s[i] === ']') {
            if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                stk[stk.length - 1].add(new NestedInteger(neg ? -x : x));
            }
            x = 0;
            neg = false;
            if (s[i] === ']' && stk.length > 1) {
                const t = stk.pop()!;
                stk[stk.length - 1].add(t);
            }
        }
    }
    return stk[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers){#386}

{{< tabs "386" >}}

{{% tab "python" %}}
```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        v = 1
        for _ in range(n):
            ans.append(v)
            if v * 10 <= n:
                v *= 10
            else:
                while v % 10 == 9 or v + 1 > n:
                    v //= 10
                v += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>(n);
        int v = 1;
        for (int i = 0; i < n; ++i) {
            ans.add(v);
            if (v * 10 <= n) {
                v *= 10;
            } else {
                while (v % 10 == 9 || v + 1 > n) {
                    v /= 10;
                }
                ++v;
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
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int v = 1;
        for (int i = 0; i < n; ++i) {
            ans.push_back(v);
            if (v * 10 <= n) {
                v *= 10;
            } else {
                while (v % 10 == 9 || v + 1 > n) {
                    v /= 10;
                }
                ++v;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lexicalOrder(n int) (ans []int) {
	v := 1
	for i := 0; i < n; i++ {
		ans = append(ans, v)
		if v*10 <= n {
			v *= 10
		} else {
			for v%10 == 9 || v+1 > n {
				v /= 10
			}
			v++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lexicalOrder(n: number): number[] {
    const ans: number[] = [];
    let v = 1;
    for (let i = 0; i < n; ++i) {
        ans.push(v);
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 === 9 || v === n) {
                v = Math.floor(v / 10);
            }
            ++v;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut ans = Vec::with_capacity(n as usize);
        let mut v = 1;
        for _ in 0..n {
            ans.push(v);
            if v * 10 <= n {
                v *= 10;
            } else {
                while v % 10 == 9 || v + 1 > n {
                    v /= 10;
                }
                v += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function (n) {
    const ans = [];
    let v = 1;
    for (let i = 0; i < n; ++i) {
        ans.push(v);
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 === 9 || v === n) {
                v = Math.floor(v / 10);
            }
            ++v;
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

<p>给你一个整数 <code>n</code> ，按字典序返回范围 <code>[1, n]</code> 内所有整数。</p>

<p>你必须设计一个时间复杂度为 <code>O(n)</code> 且使用 <code>O(1)</code> 额外空间的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 13
<strong>输出：</strong>[1,10,11,12,13,2,3,4,5,6,7,8,9]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：迭代

我们首先定义一个变量 $v$，初始时 $v = 1$。然后我们从 $1$ 开始迭代，每次迭代都将 $v$ 添加到答案数组中。然后，如果 $v \times 10 \leq n$，我们将 $v$ 更新为 $v \times 10$；否则，如果 $v \bmod 10 = 9$ 或者 $v + 1 > n$，我们就循环将 $v$ 除以 $10$。循环结束后，我们将 $v$ 加一。继续迭代，直到我们添加了 $n$ 个数到答案数组中。

时间复杂度 $O(n)$，其中 $n$ 是给定的整数 $n$。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        v = 1
        for _ in range(n):
            ans.append(v)
            if v * 10 <= n:
                v *= 10
            else:
                while v % 10 == 9 or v + 1 > n:
                    v //= 10
                v += 1
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>(n);
        int v = 1;
        for (int i = 0; i < n; ++i) {
            ans.add(v);
            if (v * 10 <= n) {
                v *= 10;
            } else {
                while (v % 10 == 9 || v + 1 > n) {
                    v /= 10;
                }
                ++v;
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
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int v = 1;
        for (int i = 0; i < n; ++i) {
            ans.push_back(v);
            if (v * 10 <= n) {
                v *= 10;
            } else {
                while (v % 10 == 9 || v + 1 > n) {
                    v /= 10;
                }
                ++v;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func lexicalOrder(n int) (ans []int) {
	v := 1
	for i := 0; i < n; i++ {
		ans = append(ans, v)
		if v*10 <= n {
			v *= 10
		} else {
			for v%10 == 9 || v+1 > n {
				v /= 10
			}
			v++
		}
	}
	return
}
```

#### TypeScript

```ts
function lexicalOrder(n: number): number[] {
    const ans: number[] = [];
    let v = 1;
    for (let i = 0; i < n; ++i) {
        ans.push(v);
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 === 9 || v === n) {
                v = Math.floor(v / 10);
            }
            ++v;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut ans = Vec::with_capacity(n as usize);
        let mut v = 1;
        for _ in 0..n {
            ans.push(v);
            if v * 10 <= n {
                v *= 10;
            } else {
                while v % 10 == 9 || v + 1 > n {
                    v /= 10;
                }
                v += 1;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function (n) {
    const ans = [];
    let v = 1;
    for (let i = 0; i < n; ++i) {
        ans.push(v);
        if (v * 10 <= n) {
            v *= 10;
        } else {
            while (v % 10 === 9 || v === n) {
                v = Math.floor(v / 10);
            }
            ++v;
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

# [387. 字符串中的第一个唯一字符](https://leetcode.cn/problems/first-unique-character-in-a-string){#387}

{{< tabs "387" >}}

{{% tab "python" %}}
```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = Counter(s)
        for i, c in enumerate(s):
            if cnt[c] == 1:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int firstUniqChar(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[s.charAt(i) - 'a'] == 1) {
                return i;
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
    int firstUniqChar(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func firstUniqChar(s string) int {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for i, c := range s {
		if cnt[c-'a'] == 1 {
			return i
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function firstUniqChar(s: string): number {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    for (let i = 0; i < s.length; ++i) {
        if (cnt.get(s[i]) === 1) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
    const cnt = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    for (let i = 0; i < s.length; ++i) {
        if (cnt.get(s[i]) === 1) {
            return i;
        }
    }
    return -1;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        for ($i = 0; $i < strlen($s); $i++) {
            $hashtable[$s[$i]]++;
        }
        for ($i = 0; $i < strlen($s); $i++) {
            if ($hashtable[$s[$i]] == 1) {
                return $i;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，找到 <em>它的第一个不重复的字符，并返回它的索引</em> 。如果不存在，则返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> s = "leetcode"
<strong>输出:</strong> 0
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "loveleetcode"
<strong>输出:</strong> 2
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "aabb"
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用一个哈希表或者一个长度为 $26$ 的数组 $\text{cnt}$ 来存储每个字符出现的次数，然后从头开始遍历每个字符 $\text{s[i]}$，如果 $\text{cnt[s[i]]}$ 为 $1$，则返回 $i$。

遍历结束后，如果没有找到符合条件的字符，返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，本题中字符集为小写字母，所以 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = Counter(s)
        for i, c in enumerate(s):
            if cnt[c] == 1:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int firstUniqChar(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[s.charAt(i) - 'a'] == 1) {
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
    int firstUniqChar(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func firstUniqChar(s string) int {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for i, c := range s {
		if cnt[c-'a'] == 1 {
			return i
		}
	}
	return -1
}
```

#### TypeScript

```ts
function firstUniqChar(s: string): number {
    const cnt = new Map<string, number>();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    for (let i = 0; i < s.length; ++i) {
        if (cnt.get(s[i]) === 1) {
            return i;
        }
    }
    return -1;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
    const cnt = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    for (let i = 0; i < s.length; ++i) {
        if (cnt.get(s[i]) === 1) {
            return i;
        }
    }
    return -1;
};
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        for ($i = 0; $i < strlen($s); $i++) {
            $hashtable[$s[$i]]++;
        }
        for ($i = 0; $i < strlen($s); $i++) {
            if ($hashtable[$s[$i]] == 1) {
                return $i;
            }
        }
        return -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [388. 文件的最长绝对路径](https://leetcode.cn/problems/longest-absolute-file-path){#388}

{{< tabs "388" >}}

{{% tab "python" %}}
```python
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        i, n = 0, len(input)
        ans = 0
        stk = []
        while i < n:
            ident = 0
            while input[i] == '\t':
                ident += 1
                i += 1

            cur, isFile = 0, False
            while i < n and input[i] != '\n':
                cur += 1
                if input[i] == '.':
                    isFile = True
                i += 1
            i += 1

            # popd
            while len(stk) > 0 and len(stk) > ident:
                stk.pop()

            if len(stk) > 0:
                cur += stk[-1] + 1

            # pushd
            if not isFile:
                stk.append(cur)
                continue

            ans = max(ans, cur)

        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthLongestPath(String input) {
        int i = 0;
        int n = input.length();
        int ans = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        while (i < n) {
            int ident = 0;
            for (; input.charAt(i) == '\t'; i++) {
                ident++;
            }

            int cur = 0;
            boolean isFile = false;
            for (; i < n && input.charAt(i) != '\n'; i++) {
                cur++;
                if (input.charAt(i) == '.') {
                    isFile = true;
                }
            }
            i++;

            // popd
            while (!stack.isEmpty() && stack.size() > ident) {
                stack.pop();
            }

            if (stack.size() > 0) {
                cur += stack.peek() + 1;
            }

            // pushd
            if (!isFile) {
                stack.push(cur);
                continue;
            }

            ans = Math.max(ans, cur);
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
    int lengthLongestPath(string input) {
        int i = 0, n = input.size();
        int ans = 0;
        stack<int> stk;
        while (i < n) {
            int ident = 0;
            for (; input[i] == '\t'; ++i) {
                ++ident;
            }

            int cur = 0;
            bool isFile = false;
            for (; i < n && input[i] != '\n'; ++i) {
                ++cur;
                if (input[i] == '.') {
                    isFile = true;
                }
            }
            ++i;

            // popd
            while (!stk.empty() && stk.size() > ident) {
                stk.pop();
            }

            if (stk.size() > 0) {
                cur += stk.top() + 1;
            }

            // pushd
            if (!isFile) {
                stk.push(cur);
                continue;
            }

            ans = max(ans, cur);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthLongestPath(input string) int {
	i, n := 0, len(input)
	ans := 0
	var stk []int
	for i < n {
		ident := 0
		for ; input[i] == '\t'; i++ {
			ident++
		}

		cur, isFile := 0, false
		for ; i < n && input[i] != '\n'; i++ {
			cur++
			if input[i] == '.' {
				isFile = true
			}
		}
		i++

		// popd
		for len(stk) > 0 && len(stk) > ident {
			stk = stk[:len(stk)-1]
		}

		if len(stk) > 0 {
			cur += stk[len(stk)-1] + 1
		}

		// pushd
		if !isFile {
			stk = append(stk, cur)
			continue
		}

		ans = max(ans, cur)
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

<p>假设有一个同时存储文件和目录的文件系统。下图展示了文件系统的一个示例：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0388.Longest%20Absolute%20File%20Path/images/mdir.jpg" style="height: 142px; width: 300px;" /></p>

<p>这里将 <code>dir</code> 作为根目录中的唯一目录。<code>dir</code> 包含两个子目录 <code>subdir1</code> 和 <code>subdir2</code> 。<code>subdir1</code> 包含文件 <code>file1.ext</code> 和子目录 <code>subsubdir1</code>；<code>subdir2</code> 包含子目录 <code>subsubdir2</code>，该子目录下包含文件 <code>file2.ext</code> 。</p>

<p>在文本格式中，如下所示(⟶表示制表符)：</p>

<pre>
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
</pre>

<p>如果是代码表示，上面的文件系统可以写为 <code>"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"</code> 。<code>'\n'</code> 和 <code>'\t'</code> 分别是换行符和制表符。</p>

<p>文件系统中的每个文件和文件夹都有一个唯一的 <strong>绝对路径</strong> ，即必须打开才能到达文件/目录所在位置的目录顺序，所有路径用 <code>'/'</code> 连接。上面例子中，指向 <code>file2.ext</code> 的 <strong>绝对路径</strong> 是 <code>"dir/subdir2/subsubdir2/file2.ext"</code> 。每个目录名由字母、数字和/或空格组成，每个文件名遵循 <code>name.extension</code> 的格式，其中<meta charset="UTF-8" />&nbsp;<code>name</code>&nbsp;和<meta charset="UTF-8" />&nbsp;<code>extension</code>由字母、数字和/或空格组成。</p>

<p>给定一个以上述格式表示文件系统的字符串 <code>input</code> ，返回文件系统中&nbsp;<em>指向&nbsp;<strong>文件</strong>&nbsp;的 <strong>最长绝对路径</strong> 的长度</em>&nbsp;。 如果系统中没有文件，返回&nbsp;<code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0388.Longest%20Absolute%20File%20Path/images/dir1.jpg" style="height: 101px; width: 200px;" />
<pre>
<strong>输入：</strong>input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
<strong>输出：</strong>20
<strong>解释：</strong>只有一个文件，绝对路径为 "dir/subdir2/file.ext" ，路径长度 20
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0388.Longest%20Absolute%20File%20Path/images/dir2.jpg" style="height: 151px; width: 300px;" />
<pre>
<strong>输入：</strong>input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
<strong>输出：</strong>32
<strong>解释：</strong>存在两个文件：
"dir/subdir1/file1.ext" ，路径长度 21
"dir/subdir2/subsubdir2/file2.ext" ，路径长度 32
返回 32 ，因为这是最长的路径</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>input = "a"
<strong>输出：</strong>0
<strong>解释：</strong>不存在任何文件</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>input = "file1.txt\nfile2.txt\nlongfile.txt"
<strong>输出：</strong>12
<strong>解释：</strong>根目录下有 3 个文件。
因为根目录中任何东西的绝对路径只是名称本身，所以答案是 "longfile.txt" ，路径长度为 12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= input.length &lt;= 10<sup>4</sup></code></li>
	<li><code>input</code> 可能包含小写或大写的英文字母，一个换行符 <code>'\n'</code>，一个制表符 <code>'\t'</code>，一个点 <code>'.'</code>，一个空格 <code>' '</code>，和数字。</li>
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
    def lengthLongestPath(self, input: str) -> int:
        i, n = 0, len(input)
        ans = 0
        stk = []
        while i < n:
            ident = 0
            while input[i] == '\t':
                ident += 1
                i += 1

            cur, isFile = 0, False
            while i < n and input[i] != '\n':
                cur += 1
                if input[i] == '.':
                    isFile = True
                i += 1
            i += 1

            # popd
            while len(stk) > 0 and len(stk) > ident:
                stk.pop()

            if len(stk) > 0:
                cur += stk[-1] + 1

            # pushd
            if not isFile:
                stk.append(cur)
                continue

            ans = max(ans, cur)

        return ans
```

#### Java

```java
class Solution {
    public int lengthLongestPath(String input) {
        int i = 0;
        int n = input.length();
        int ans = 0;
        Deque<Integer> stack = new ArrayDeque<>();
        while (i < n) {
            int ident = 0;
            for (; input.charAt(i) == '\t'; i++) {
                ident++;
            }

            int cur = 0;
            boolean isFile = false;
            for (; i < n && input.charAt(i) != '\n'; i++) {
                cur++;
                if (input.charAt(i) == '.') {
                    isFile = true;
                }
            }
            i++;

            // popd
            while (!stack.isEmpty() && stack.size() > ident) {
                stack.pop();
            }

            if (stack.size() > 0) {
                cur += stack.peek() + 1;
            }

            // pushd
            if (!isFile) {
                stack.push(cur);
                continue;
            }

            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0, n = input.size();
        int ans = 0;
        stack<int> stk;
        while (i < n) {
            int ident = 0;
            for (; input[i] == '\t'; ++i) {
                ++ident;
            }

            int cur = 0;
            bool isFile = false;
            for (; i < n && input[i] != '\n'; ++i) {
                ++cur;
                if (input[i] == '.') {
                    isFile = true;
                }
            }
            ++i;

            // popd
            while (!stk.empty() && stk.size() > ident) {
                stk.pop();
            }

            if (stk.size() > 0) {
                cur += stk.top() + 1;
            }

            // pushd
            if (!isFile) {
                stk.push(cur);
                continue;
            }

            ans = max(ans, cur);
        }
        return ans;
    }
};
```

#### Go

```go
func lengthLongestPath(input string) int {
	i, n := 0, len(input)
	ans := 0
	var stk []int
	for i < n {
		ident := 0
		for ; input[i] == '\t'; i++ {
			ident++
		}

		cur, isFile := 0, false
		for ; i < n && input[i] != '\n'; i++ {
			cur++
			if input[i] == '.' {
				isFile = true
			}
		}
		i++

		// popd
		for len(stk) > 0 && len(stk) > ident {
			stk = stk[:len(stk)-1]
		}

		if len(stk) > 0 {
			cur += stk[len(stk)-1] + 1
		}

		// pushd
		if !isFile {
			stk = append(stk, cur)
			continue
		}

		ans = max(ans, cur)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [389. 找不同](https://leetcode.cn/problems/find-the-difference){#389}

{{< tabs "389" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a = sum(ord(c) for c in s)
        b = sum(ord(c) for c in t)
        return chr(b - a)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char findTheDifference(String s, String t) {
        int ss = 0;
        for (int i = 0; i < t.length(); ++i) {
            ss += t.charAt(i);
        }
        for (int i = 0; i < s.length(); ++i) {
            ss -= s.charAt(i);
        }
        return (char) ss;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int a = 0, b = 0;
        for (char& c : s) {
            a += c;
        }
        for (char& c : t) {
            b += c;
        }
        return b - a;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheDifference(s string, t string) byte {
	ss := 0
	for _, c := range s {
		ss -= int(c)
	}
	for _, c := range t {
		ss += int(c)
	}
	return byte(ss)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheDifference(s: string, t: string): string {
    return String.fromCharCode(
        [...t].reduce((r, v) => r + v.charCodeAt(0), 0) -
            [...s].reduce((r, v) => r + v.charCodeAt(0), 0),
    );
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut ans = 0;
        for c in s.as_bytes() {
            ans ^= c;
        }
        for c in t.as_bytes() {
            ans ^= c;
        }
        char::from(ans)
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char findTheDifference(char* s, char* t) {
    int n = strlen(s);
    char ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= s[i];
        ans ^= t[i];
    }
    ans ^= t[n];
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串 <code>s</code> 和 <code>t</code>&nbsp;，它们只包含小写字母。</p>

<p>字符串 <code>t</code>&nbsp;由字符串 <code>s</code> 随机重排，然后在随机位置添加一个字母。</p>

<p>请找出在 <code>t</code>&nbsp;中被添加的字母。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", t = "abcde"
<strong>输出：</strong>"e"
<strong>解释：</strong>'e' 是那个被添加的字母。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "", t = "y"
<strong>输出：</strong>"y"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 1000</code></li>
	<li><code>t.length == s.length + 1</code></li>
	<li><code>s</code> 和 <code>t</code> 只包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或数组 $cnt$ 统计字符串 $s$ 中每个字符出现的次数，再遍历字符串 $t$，对于每个字符，我们在 $cnt$ 中减去一次出现的次数，如果对应次数为负数，则说明该字符在 $t$ 中出现的次数大于在 $s$ 中出现的次数，因此该字符为被添加的字符。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 为字符串的长度，而 $\Sigma$ 表示字符集，这里字符集为所有小写字母，所以 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        cnt = Counter(s)
        for c in t:
            cnt[c] -= 1
            if cnt[c] < 0:
                return c
```

#### Java

```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int i = 0;; ++i) {
            if (--cnt[t.charAt(i) - 'a'] < 0) {
                return t.charAt(i);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        for (char& c : t) {
            if (--cnt[c - 'a'] < 0) {
                return c;
            }
        }
        return ' ';
    }
};
```

#### Go

```go
func findTheDifference(s, t string) byte {
	cnt := [26]int{}
	for _, ch := range s {
		cnt[ch-'a']++
	}
	for i := 0; ; i++ {
		ch := t[i]
		cnt[ch-'a']--
		if cnt[ch-'a'] < 0 {
			return ch
		}
	}
}
```

#### TypeScript

```ts
function findTheDifference(s: string, t: string): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (const c of t) {
        --cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    for (let i = 0; ; ++i) {
        if (cnt[i] < 0) {
            return String.fromCharCode(i + 'a'.charCodeAt(0));
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let s = s.as_bytes();
        let t = t.as_bytes();
        let n = s.len();
        let mut count = [0; 26];
        for i in 0..n {
            count[(s[i] - b'a') as usize] += 1;
            count[(t[i] - b'a') as usize] -= 1;
        }
        count[(t[n] - b'a') as usize] -= 1;
        char::from(b'a' + (count.iter().position(|&v| v != 0).unwrap() as u8))
    }
}
```

#### C

```c
char findTheDifference(char* s, char* t) {
    int n = strlen(s);
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
    }
    cnt[t[n] - 'a']--;
    for (int i = 0;; i++) {
        if (cnt[i]) {
            return 'a' + i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：求和

我们可以将字符串 $t$ 中每个字符的 ASCII 码的值求和，再减去字符串 $s$ 中每个字符的 ASCII 码的值求和，最后的结果即为被添加的字符的 ASCII 码对应的值。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a = sum(ord(c) for c in s)
        b = sum(ord(c) for c in t)
        return chr(b - a)
```

#### Java

```java
class Solution {
    public char findTheDifference(String s, String t) {
        int ss = 0;
        for (int i = 0; i < t.length(); ++i) {
            ss += t.charAt(i);
        }
        for (int i = 0; i < s.length(); ++i) {
            ss -= s.charAt(i);
        }
        return (char) ss;
    }
}
```

#### C++

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int a = 0, b = 0;
        for (char& c : s) {
            a += c;
        }
        for (char& c : t) {
            b += c;
        }
        return b - a;
    }
};
```

#### Go

```go
func findTheDifference(s string, t string) byte {
	ss := 0
	for _, c := range s {
		ss -= int(c)
	}
	for _, c := range t {
		ss += int(c)
	}
	return byte(ss)
}
```

#### TypeScript

```ts
function findTheDifference(s: string, t: string): string {
    return String.fromCharCode(
        [...t].reduce((r, v) => r + v.charCodeAt(0), 0) -
            [...s].reduce((r, v) => r + v.charCodeAt(0), 0),
    );
}
```

#### Rust

```rust
impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut ans = 0;
        for c in s.as_bytes() {
            ans ^= c;
        }
        for c in t.as_bytes() {
            ans ^= c;
        }
        char::from(ans)
    }
}
```

#### C

```c
char findTheDifference(char* s, char* t) {
    int n = strlen(s);
    char ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= s[i];
        ans ^= t[i];
    }
    ans ^= t[n];
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

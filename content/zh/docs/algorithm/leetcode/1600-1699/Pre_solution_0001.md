---
title: "1600_王位继承顺序"
date: 2025-10-08T18:38:12+08:00
weight: 1
tags: [二分查找, 二叉树, 位运算, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数据库, 数组, 有序集合, 枚举, 树, 模拟, 深度优先搜索, 矩阵, 计数, 设计, 贪心]
---

{{< markmap >}}
### [1600_王位继承顺序](#1600)
#### [树](#1600)
#### [深度优先搜索](#1600)
#### [设计](#1600)
#### [哈希表](#1600)
### [1601_最多可达成的换楼请求数目](#1601)
#### [位运算](#1601)
#### [数组](#1601)
#### [回溯](#1601)
#### [枚举](#1601)
### [1602_找到二叉树中最近的右侧节点 🔒](#1602)
#### [树](#1602)
#### [广度优先搜索](#1602)
#### [二叉树](#1602)
### [1603_设计停车系统](#1603)
#### [设计](#1603)
#### [计数](#1603)
#### [模拟](#1603)
### [1604_警告一小时内使用相同员工卡大于等于三次的人](#1604)
#### [数组](#1604)
#### [哈希表](#1604)
#### [字符串](#1604)
#### [排序](#1604)
### [1605_给定行和列的和求可行矩阵](#1605)
#### [贪心](#1605)
#### [数组](#1605)
#### [矩阵](#1605)
### [1606_找到处理最多请求的服务器](#1606)
#### [贪心](#1606)
#### [数组](#1606)
#### [有序集合](#1606)
#### [堆（优先队列）](#1606)
### [1607_没有卖出的卖家 🔒](#1607)
#### [数据库](#1607)
### [1608_特殊数组的特征值](#1608)
#### [数组](#1608)
#### [二分查找](#1608)
#### [排序](#1608)
### [1609_奇偶树](#1609)
#### [树](#1609)
#### [广度优先搜索](#1609)
#### [二叉树](#1609)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1600_王位继承顺序
___
#### 树
___
#### 深度优先搜索
___
#### 设计
___
#### 哈希表
---
### 1601_最多可达成的换楼请求数目
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 枚举
---
### 1602_找到二叉树中最近的右侧节点 🔒
___
#### 树
___
#### 广度优先搜索
___
#### 二叉树
---
### 1603_设计停车系统
___
#### 设计
___
#### 计数
___
#### 模拟
---
### 1604_警告一小时内使用相同员工卡大于等于三次的人
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1605_给定行和列的和求可行矩阵
___
#### 贪心
___
#### 数组
___
#### 矩阵
---
### 1606_找到处理最多请求的服务器
___
#### 贪心
___
#### 数组
___
#### 有序集合
___
#### 堆（优先队列）
---
### 1607_没有卖出的卖家 🔒
___
#### 数据库
---
### 1608_特殊数组的特征值
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 1609_奇偶树
___
#### 树
___
#### 广度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数据库 | 数组 | 有序集合 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 计数 |
| 设计 | 贪心 |  |

# [1600. 王位继承顺序](https://leetcode.cn/problems/throne-inheritance){#1600}

{{< tabs "1600" >}}

{{% tab "python" %}}
```python
class ThroneInheritance:

    def __init__(self, kingName: str):
        self.king = kingName
        self.dead = set()
        self.g = defaultdict(list)

    def birth(self, parentName: str, childName: str) -> None:
        self.g[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        def dfs(x: str):
            x not in self.dead and ans.append(x)
            for y in self.g[x]:
                dfs(y)

        ans = []
        dfs(self.king)
        return ans


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ThroneInheritance {
    private String king;
    private Set<String> dead = new HashSet<>();
    private Map<String, List<String>> g = new HashMap<>();
    private List<String> ans = new ArrayList<>();

    public ThroneInheritance(String kingName) {
        king = kingName;
    }

    public void birth(String parentName, String childName) {
        g.computeIfAbsent(parentName, k -> new ArrayList<>()).add(childName);
    }

    public void death(String name) {
        dead.add(name);
    }

    public List<String> getInheritanceOrder() {
        ans.clear();
        dfs(king);
        return ans;
    }

    private void dfs(String x) {
        if (!dead.contains(x)) {
            ans.add(x);
        }
        for (String y : g.getOrDefault(x, List.of())) {
            dfs(y);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        g[parentName].emplace_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        ans.resize(0);
        dfs(king);
        return ans;
    }

private:
    string king;
    unordered_set<string> dead;
    unordered_map<string, vector<string>> g;
    vector<string> ans;

    void dfs(string& x) {
        if (!dead.contains(x)) {
            ans.emplace_back(x);
        }
        for (auto& y : g[x]) {
            dfs(y);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type ThroneInheritance struct {
	king string
	dead map[string]bool
	g map[string][]string
}


func Constructor(kingName string) ThroneInheritance {
	return ThroneInheritance{kingName, map[string]bool{}, map[string][]string{}}
}


func (this *ThroneInheritance) Birth(parentName string, childName string)  {
	this.g[parentName] = append(this.g[parentName], childName)
}


func (this *ThroneInheritance) Death(name string)  {
	this.dead[name] = true
}


func (this *ThroneInheritance) GetInheritanceOrder() (ans []string) {
	var dfs func(string)
	dfs = func(x string) {
		if !this.dead[x] {
			ans = append(ans, x)
		}
		for _, y := range this.g[x] {
			dfs(y)
		}
	}
	dfs(this.king)
	return
}


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * obj := Constructor(kingName);
 * obj.Birth(parentName,childName);
 * obj.Death(name);
 * param_3 := obj.GetInheritanceOrder();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class ThroneInheritance {
    private king: string;
    private dead: Set<string> = new Set();
    private g: Map<string, string[]> = new Map();

    constructor(kingName: string) {
        this.king = kingName;
    }

    birth(parentName: string, childName: string): void {
        this.g.set(parentName, this.g.get(parentName) || []);
        this.g.get(parentName)!.push(childName);
    }

    death(name: string): void {
        this.dead.add(name);
    }

    getInheritanceOrder(): string[] {
        const ans: string[] = [];
        const dfs = (x: string) => {
            if (!this.dead.has(x)) {
                ans.push(x);
            }
            for (const y of this.g.get(x) || []) {
                dfs(y);
            }
        };
        dfs(this.king);
        return ans;
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * var obj = new ThroneInheritance(kingName)
 * obj.birth(parentName,childName)
 * obj.death(name)
 * var param_3 = obj.getInheritanceOrder()
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class ThroneInheritance {
    private string king;
    private HashSet<string> dead = new HashSet<string>();
    private Dictionary<string, List<string>> g = new Dictionary<string, List<string>>();
    private List<string> ans = new List<string>();

    public ThroneInheritance(string kingName) {
        king = kingName;
    }

    public void Birth(string parentName, string childName) {
        if (!g.ContainsKey(parentName)) {
            g[parentName] = new List<string>();
        }
        g[parentName].Add(childName);
    }

    public void Death(string name) {
        dead.Add(name);
    }

    public IList<string> GetInheritanceOrder() {
        ans.Clear();
        DFS(king);
        return ans;
    }

    private void DFS(string x) {
        if (!dead.Contains(x)) {
            ans.Add(x);
        }
        if (g.ContainsKey(x)) {
            foreach (string y in g[x]) {
                DFS(y);
            }
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.Birth(parentName,childName);
 * obj.Death(name);
 * IList<string> param_3 = obj.GetInheritanceOrder();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个王国里住着国王、他的孩子们、他的孙子们等等。每一个时间点，这个家庭里有人出生也有人死亡。</p>

<p>这个王国有一个明确规定的王位继承顺序，第一继承人总是国王自己。我们定义递归函数&nbsp;<code>Successor(x, curOrder)</code>&nbsp;，给定一个人&nbsp;<code>x</code>&nbsp;和当前的继承顺序，该函数返回 <code>x</code>&nbsp;的下一继承人。</p>

<pre>
Successor(x, curOrder):
    如果 x 没有孩子或者所有 x 的孩子都在 curOrder 中：
        如果 x 是国王，那么返回 null
        否则，返回 Successor(x 的父亲, curOrder)
    否则，返回 x 不在 curOrder 中最年长的孩子
</pre>

<p>比方说，假设王国由国王，他的孩子&nbsp;Alice 和 Bob （Alice 比 Bob&nbsp;年长）和 Alice 的孩子&nbsp;Jack 组成。</p>

<ol>
	<li>一开始，&nbsp;<code>curOrder</code>&nbsp;为&nbsp;<code>["king"]</code>.</li>
	<li>调用&nbsp;<code>Successor(king, curOrder)</code>&nbsp;，返回 Alice ，所以我们将 Alice 放入 <code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Alice, curOrder)</code>&nbsp;，返回 Jack ，所以我们将 Jack 放入&nbsp;<code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice", "Jack"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Jack, curOrder)</code>&nbsp;，返回 Bob ，所以我们将 Bob 放入&nbsp;<code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice", "Jack", "Bob"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Bob, curOrder)</code>&nbsp;，返回&nbsp;<code>null</code>&nbsp;。最终得到继承顺序为&nbsp;<code>["king", "Alice", "Jack", "Bob"]</code>&nbsp;。</li>
</ol>

<p>通过以上的函数，我们总是能得到一个唯一的继承顺序。</p>

<p>请你实现&nbsp;<code>ThroneInheritance</code>&nbsp;类：</p>

<ul>
	<li><code>ThroneInheritance(string kingName)</code> 初始化一个&nbsp;<code>ThroneInheritance</code>&nbsp;类的对象。国王的名字作为构造函数的参数传入。</li>
	<li><code>void birth(string parentName, string childName)</code>&nbsp;表示&nbsp;<code>parentName</code>&nbsp;新拥有了一个名为&nbsp;<code>childName</code>&nbsp;的孩子。</li>
	<li><code>void death(string name)</code>&nbsp;表示名为&nbsp;<code>name</code>&nbsp;的人死亡。一个人的死亡不会影响&nbsp;<code>Successor</code>&nbsp;函数，也不会影响当前的继承顺序。你可以只将这个人标记为死亡状态。</li>
	<li><code>string[] getInheritanceOrder()</code>&nbsp;返回 <strong>除去</strong>&nbsp;死亡人员的当前继承顺序列表。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
<strong>输出：</strong>
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

<strong>解释：</strong>
ThroneInheritance t= new ThroneInheritance("king"); // 继承顺序：<strong>king</strong>
t.birth("king", "andy"); // 继承顺序：king &gt; <strong>andy</strong>
t.birth("king", "bob"); // 继承顺序：king &gt; andy &gt; <strong>bob</strong>
t.birth("king", "catherine"); // 继承顺序：king &gt; andy &gt; bob &gt; <strong>catherine</strong>
t.birth("andy", "matthew"); // 继承顺序：king &gt; andy &gt; <strong>matthew</strong> &gt; bob &gt; catherine
t.birth("bob", "alex"); // 继承顺序：king &gt; andy &gt; matthew &gt; bob &gt; <strong>alex</strong> &gt; catherine
t.birth("bob", "asha"); // 继承顺序：king &gt; andy &gt; matthew &gt; bob &gt; alex &gt; <strong>asha</strong> &gt; catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // 继承顺序：king &gt; andy &gt; matthew &gt; <strong>bob（已经去世）</strong>&gt; alex &gt; asha &gt; catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= kingName.length, parentName.length, childName.length, name.length &lt;= 15</code></li>
	<li><code>kingName</code>，<code>parentName</code>，&nbsp;<code>childName</code>&nbsp;和&nbsp;<code>name</code>&nbsp;仅包含小写英文字母。</li>
	<li>所有的参数&nbsp;<code>childName</code> 和&nbsp;<code>kingName</code>&nbsp;<strong>互不相同</strong>。</li>
	<li>所有&nbsp;<code>death</code>&nbsp;函数中的死亡名字 <code>name</code>&nbsp;要么是国王，要么是已经出生了的人员名字。</li>
	<li>每次调用 <code>birth(parentName, childName)</code> 时，测试用例都保证 <code>parentName</code> 对应的人员是活着的。</li>
	<li>最多调用&nbsp;<code>10<sup>5</sup></code>&nbsp;次<code>birth</code> 和&nbsp;<code>death</code>&nbsp;。</li>
	<li>最多调用&nbsp;<code>10</code>&nbsp;次&nbsp;<code>getInheritanceOrder</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多叉树的前序遍历

根据题目描述，我们可以发现，王位继承顺序实际上是一个多叉树的前序遍历。我们可以使用一个哈希表 $g$ 存储每个人的孩子，使用一个集合 $dead$ 存储已经去世的人。

-   调用 `birth(parentName, childName)` 时，我们将 `childName` 添加到 `parentName` 的孩子列表中。
-   调用 `death(name)` 时，我们将 `name` 添加到 `dead` 集合中。
-   调用 `getInheritanceOrder()` 时，我们从国王开始进行深度优先搜索，如果当前节点 `x` 没有去世，我们将 `x` 添加到答案列表中，然后递归地遍历 `x` 的所有孩子。

时间复杂度方面，`birth` 和 `death` 的时间复杂度均为 $O(1)$，`getInheritanceOrder` 的时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。其中 $n$ 是节点数量。

<!-- tabs:start -->

#### Python3

```python
class ThroneInheritance:

    def __init__(self, kingName: str):
        self.king = kingName
        self.dead = set()
        self.g = defaultdict(list)

    def birth(self, parentName: str, childName: str) -> None:
        self.g[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        def dfs(x: str):
            x not in self.dead and ans.append(x)
            for y in self.g[x]:
                dfs(y)

        ans = []
        dfs(self.king)
        return ans


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
```

#### Java

```java
class ThroneInheritance {
    private String king;
    private Set<String> dead = new HashSet<>();
    private Map<String, List<String>> g = new HashMap<>();
    private List<String> ans = new ArrayList<>();

    public ThroneInheritance(String kingName) {
        king = kingName;
    }

    public void birth(String parentName, String childName) {
        g.computeIfAbsent(parentName, k -> new ArrayList<>()).add(childName);
    }

    public void death(String name) {
        dead.add(name);
    }

    public List<String> getInheritanceOrder() {
        ans.clear();
        dfs(king);
        return ans;
    }

    private void dfs(String x) {
        if (!dead.contains(x)) {
            ans.add(x);
        }
        for (String y : g.getOrDefault(x, List.of())) {
            dfs(y);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */
```

#### C++

```cpp
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        g[parentName].emplace_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        ans.resize(0);
        dfs(king);
        return ans;
    }

private:
    string king;
    unordered_set<string> dead;
    unordered_map<string, vector<string>> g;
    vector<string> ans;

    void dfs(string& x) {
        if (!dead.contains(x)) {
            ans.emplace_back(x);
        }
        for (auto& y : g[x]) {
            dfs(y);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
```

#### Go

```go
type ThroneInheritance struct {
	king string
	dead map[string]bool
	g map[string][]string
}


func Constructor(kingName string) ThroneInheritance {
	return ThroneInheritance{kingName, map[string]bool{}, map[string][]string{}}
}


func (this *ThroneInheritance) Birth(parentName string, childName string)  {
	this.g[parentName] = append(this.g[parentName], childName)
}


func (this *ThroneInheritance) Death(name string)  {
	this.dead[name] = true
}


func (this *ThroneInheritance) GetInheritanceOrder() (ans []string) {
	var dfs func(string)
	dfs = func(x string) {
		if !this.dead[x] {
			ans = append(ans, x)
		}
		for _, y := range this.g[x] {
			dfs(y)
		}
	}
	dfs(this.king)
	return
}


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * obj := Constructor(kingName);
 * obj.Birth(parentName,childName);
 * obj.Death(name);
 * param_3 := obj.GetInheritanceOrder();
 */
```

#### TypeScript

```ts
class ThroneInheritance {
    private king: string;
    private dead: Set<string> = new Set();
    private g: Map<string, string[]> = new Map();

    constructor(kingName: string) {
        this.king = kingName;
    }

    birth(parentName: string, childName: string): void {
        this.g.set(parentName, this.g.get(parentName) || []);
        this.g.get(parentName)!.push(childName);
    }

    death(name: string): void {
        this.dead.add(name);
    }

    getInheritanceOrder(): string[] {
        const ans: string[] = [];
        const dfs = (x: string) => {
            if (!this.dead.has(x)) {
                ans.push(x);
            }
            for (const y of this.g.get(x) || []) {
                dfs(y);
            }
        };
        dfs(this.king);
        return ans;
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * var obj = new ThroneInheritance(kingName)
 * obj.birth(parentName,childName)
 * obj.death(name)
 * var param_3 = obj.getInheritanceOrder()
 */
```

#### C#

```cs
public class ThroneInheritance {
    private string king;
    private HashSet<string> dead = new HashSet<string>();
    private Dictionary<string, List<string>> g = new Dictionary<string, List<string>>();
    private List<string> ans = new List<string>();

    public ThroneInheritance(string kingName) {
        king = kingName;
    }

    public void Birth(string parentName, string childName) {
        if (!g.ContainsKey(parentName)) {
            g[parentName] = new List<string>();
        }
        g[parentName].Add(childName);
    }

    public void Death(string name) {
        dead.Add(name);
    }

    public IList<string> GetInheritanceOrder() {
        ans.Clear();
        DFS(king);
        return ans;
    }

    private void DFS(string x) {
        if (!dead.Contains(x)) {
            ans.Add(x);
        }
        if (g.ContainsKey(x)) {
            foreach (string y in g[x]) {
                DFS(y);
            }
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.Birth(parentName,childName);
 * obj.Death(name);
 * IList<string> param_3 = obj.GetInheritanceOrder();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1601. 最多可达成的换楼请求数目](https://leetcode.cn/problems/maximum-number-of-achievable-transfer-requests){#1601}

{{< tabs "1601" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        def check(mask: int) -> bool:
            cnt = [0] * n
            for i, (f, t) in enumerate(requests):
                if mask >> i & 1:
                    cnt[f] -= 1
                    cnt[t] += 1
            return all(v == 0 for v in cnt)

        ans = 0
        for mask in range(1 << len(requests)):
            cnt = mask.bit_count()
            if ans < cnt and check(mask):
                ans = cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] requests;

    public int maximumRequests(int n, int[][] requests) {
        m = requests.length;
        this.n = n;
        this.requests = requests;
        int ans = 0;
        for (int mask = 0; mask < 1 << m; ++mask) {
            int cnt = Integer.bitCount(mask);
            if (ans < cnt && check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }

    private boolean check(int mask) {
        int[] cnt = new int[n];
        for (int i = 0; i < m; ++i) {
            if ((mask >> i & 1) == 1) {
                int f = requests[i][0], t = requests[i][1];
                --cnt[f];
                ++cnt[t];
            }
        }
        for (int v : cnt) {
            if (v != 0) {
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
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        auto check = [&](int mask) -> bool {
            int cnt[n];
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < m; ++i) {
                if (mask >> i & 1) {
                    int f = requests[i][0], t = requests[i][1];
                    --cnt[f];
                    ++cnt[t];
                }
            }
            for (int v : cnt) {
                if (v) {
                    return false;
                }
            }
            return true;
        };
        for (int mask = 0; mask < 1 << m; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (ans < cnt && check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumRequests(n int, requests [][]int) (ans int) {
	m := len(requests)
	check := func(mask int) bool {
		cnt := make([]int, n)
		for i, r := range requests {
			if mask>>i&1 == 1 {
				f, t := r[0], r[1]
				cnt[f]--
				cnt[t]++
			}
		}
		for _, v := range cnt {
			if v != 0 {
				return false
			}
		}
		return true
	}
	for mask := 0; mask < 1<<m; mask++ {
		cnt := bits.OnesCount(uint(mask))
		if ans < cnt && check(mask) {
			ans = cnt
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumRequests(n: number, requests: number[][]): number {
    const m = requests.length;
    let ans = 0;
    const check = (mask: number): boolean => {
        const cnt = Array(n).fill(0);
        for (let i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                const [f, t] = requests[i];
                --cnt[f];
                ++cnt[t];
            }
        }
        return cnt.every(v => v === 0);
    };
    for (let mask = 0; mask < 1 << m; ++mask) {
        const cnt = bitCount(mask);
        if (ans < cnt && check(mask)) {
            ans = cnt;
        }
    }
    return ans;
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
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number[][]} requests
 * @return {number}
 */
var maximumRequests = function (n, requests) {
    const m = requests.length;
    let ans = 0;
    const check = mask => {
        const cnt = new Array(n).fill(0);
        for (let i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                const [f, t] = requests[i];
                --cnt[f];
                ++cnt[t];
            }
        }
        return cnt.every(v => v === 0);
    };
    for (let mask = 0; mask < 1 << m; ++mask) {
        const cnt = bitCount(mask);
        if (ans < cnt && check(mask)) {
            ans = cnt;
        }
    }
    return ans;
};

function bitCount(i) {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int m;
    private int n;
    private int[][] requests;

    public int MaximumRequests(int n, int[][] requests) {
        m = requests.Length;
        this.n = n;
        this.requests = requests;
        int ans = 0;
        for (int mask = 0; mask < (1 << m); ++mask) {
            int cnt = CountBits(mask);
            if (ans < cnt && Check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }

    private bool Check(int mask) {
        int[] cnt = new int[n];
        for (int i = 0; i < m; ++i) {
            if (((mask >> i) & 1) == 1) {
                int f = requests[i][0], t = requests[i][1];
                --cnt[f];
                ++cnt[t];
            }
        }
        foreach (int v in cnt) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }

    private int CountBits(int n) {
        int count = 0;
        while (n > 0) {
            n -= n & -n;
            ++count;
        }
        return count;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们有&nbsp;<code>n</code>&nbsp;栋楼，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。每栋楼有若干员工。由于现在是换楼的季节，部分员工想要换一栋楼居住。</p>

<p>给你一个数组 <code>requests</code>&nbsp;，其中&nbsp;<code>requests[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;，表示一个员工请求从编号为&nbsp;<code>from<sub>i</sub></code>&nbsp;的楼搬到编号为&nbsp;<code>to<sub>i</sub></code><sub>&nbsp;</sub>的楼。</p>

<p>一开始&nbsp;<strong>所有楼都是满的</strong>，所以从请求列表中选出的若干个请求是可行的需要满足 <strong>每栋楼员工净变化为 0&nbsp;</strong>。意思是每栋楼 <strong>离开</strong>&nbsp;的员工数目 <strong>等于</strong>&nbsp;该楼 <strong>搬入</strong>&nbsp;的员工数数目。比方说&nbsp;<code>n = 3</code>&nbsp;且两个员工要离开楼&nbsp;<code>0</code>&nbsp;，一个员工要离开楼&nbsp;<code>1</code>&nbsp;，一个员工要离开楼 <code>2</code>&nbsp;，如果该请求列表可行，应该要有两个员工搬入楼&nbsp;<code>0</code>&nbsp;，一个员工搬入楼&nbsp;<code>1</code>&nbsp;，一个员工搬入楼&nbsp;<code>2</code>&nbsp;。</p>

<p>请你从原请求列表中选出若干个请求，使得它们是一个可行的请求列表，并返回所有可行列表中最大请求数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1601.Maximum%20Number%20of%20Achievable%20Transfer%20Requests/images/move1.jpg" style="height: 406px; width: 600px;"></p>

<pre><strong>输入：</strong>n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
<strong>输出：</strong>5
<strong>解释：</strong>请求列表如下：
从楼 0 离开的员工为 x 和 y ，且他们都想要搬到楼 1 。
从楼 1 离开的员工为 a 和 b ，且他们分别想要搬到楼 2 和 0 。
从楼 2 离开的员工为 z ，且他想要搬到楼 0 。
从楼 3 离开的员工为 c ，且他想要搬到楼 4 。
没有员工从楼 4 离开。
我们可以让 x 和 b 交换他们的楼，以满足他们的请求。
我们可以让 y，a 和 z 三人在三栋楼间交换位置，满足他们的要求。
所以最多可以满足 5 个请求。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1601.Maximum%20Number%20of%20Achievable%20Transfer%20Requests/images/move2.jpg" style="height: 327px; width: 450px;"></p>

<pre><strong>输入：</strong>n = 3, requests = [[0,0],[1,2],[2,1]]
<strong>输出：</strong>3
<strong>解释：</strong>请求列表如下：
从楼 0 离开的员工为 x ，且他想要回到原来的楼 0 。
从楼 1 离开的员工为 y ，且他想要搬到楼 2 。
从楼 2 离开的员工为 z ，且他想要搬到楼 1 。
我们可以满足所有的请求。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= requests.length &lt;= 16</code></li>
	<li><code>requests[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

我们注意到，换楼请求列表长度不超过 $16$，因此我们可以使用二进制枚举的方法枚举所有的换楼请求列表。具体地，我们可以使用一个长度为 $16$ 的二进制数来表示一种换楼请求列表，其中第 $i$ 位为 $1$ 表示第 $i$ 个换楼请求被选中，为 $0$ 表示第 $i$ 个换楼请求不被选中。

我们在 $[1, 2^{m})$ 的范围内枚举所有的二进制数，对于每个二进制数 $mask$，我们先算出它的二进制表示中有多少个 $1$，记为 $cnt$，如果 $cnt$ 比当前答案 $ans$ 大，那么我们再判断 $mask$ 是否是一个可行的换楼请求列表。如果是，那么我们就用 $cnt$ 更新答案 $ans$。判断 $mask$ 是否是一个可行的换楼请求列表，只需要判断对于每个楼，它的净流入量是否为 $0$ 即可。

时间复杂度 $O(2^m \times (m + n))$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是换楼请求列表的长度和楼的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        def check(mask: int) -> bool:
            cnt = [0] * n
            for i, (f, t) in enumerate(requests):
                if mask >> i & 1:
                    cnt[f] -= 1
                    cnt[t] += 1
            return all(v == 0 for v in cnt)

        ans = 0
        for mask in range(1 << len(requests)):
            cnt = mask.bit_count()
            if ans < cnt and check(mask):
                ans = cnt
        return ans
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] requests;

    public int maximumRequests(int n, int[][] requests) {
        m = requests.length;
        this.n = n;
        this.requests = requests;
        int ans = 0;
        for (int mask = 0; mask < 1 << m; ++mask) {
            int cnt = Integer.bitCount(mask);
            if (ans < cnt && check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }

    private boolean check(int mask) {
        int[] cnt = new int[n];
        for (int i = 0; i < m; ++i) {
            if ((mask >> i & 1) == 1) {
                int f = requests[i][0], t = requests[i][1];
                --cnt[f];
                ++cnt[t];
            }
        }
        for (int v : cnt) {
            if (v != 0) {
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
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        auto check = [&](int mask) -> bool {
            int cnt[n];
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < m; ++i) {
                if (mask >> i & 1) {
                    int f = requests[i][0], t = requests[i][1];
                    --cnt[f];
                    ++cnt[t];
                }
            }
            for (int v : cnt) {
                if (v) {
                    return false;
                }
            }
            return true;
        };
        for (int mask = 0; mask < 1 << m; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (ans < cnt && check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumRequests(n int, requests [][]int) (ans int) {
	m := len(requests)
	check := func(mask int) bool {
		cnt := make([]int, n)
		for i, r := range requests {
			if mask>>i&1 == 1 {
				f, t := r[0], r[1]
				cnt[f]--
				cnt[t]++
			}
		}
		for _, v := range cnt {
			if v != 0 {
				return false
			}
		}
		return true
	}
	for mask := 0; mask < 1<<m; mask++ {
		cnt := bits.OnesCount(uint(mask))
		if ans < cnt && check(mask) {
			ans = cnt
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumRequests(n: number, requests: number[][]): number {
    const m = requests.length;
    let ans = 0;
    const check = (mask: number): boolean => {
        const cnt = Array(n).fill(0);
        for (let i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                const [f, t] = requests[i];
                --cnt[f];
                ++cnt[t];
            }
        }
        return cnt.every(v => v === 0);
    };
    for (let mask = 0; mask < 1 << m; ++mask) {
        const cnt = bitCount(mask);
        if (ans < cnt && check(mask)) {
            ans = cnt;
        }
    }
    return ans;
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

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number[][]} requests
 * @return {number}
 */
var maximumRequests = function (n, requests) {
    const m = requests.length;
    let ans = 0;
    const check = mask => {
        const cnt = new Array(n).fill(0);
        for (let i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                const [f, t] = requests[i];
                --cnt[f];
                ++cnt[t];
            }
        }
        return cnt.every(v => v === 0);
    };
    for (let mask = 0; mask < 1 << m; ++mask) {
        const cnt = bitCount(mask);
        if (ans < cnt && check(mask)) {
            ans = cnt;
        }
    }
    return ans;
};

function bitCount(i) {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

#### C#

```cs
public class Solution {
    private int m;
    private int n;
    private int[][] requests;

    public int MaximumRequests(int n, int[][] requests) {
        m = requests.Length;
        this.n = n;
        this.requests = requests;
        int ans = 0;
        for (int mask = 0; mask < (1 << m); ++mask) {
            int cnt = CountBits(mask);
            if (ans < cnt && Check(mask)) {
                ans = cnt;
            }
        }
        return ans;
    }

    private bool Check(int mask) {
        int[] cnt = new int[n];
        for (int i = 0; i < m; ++i) {
            if (((mask >> i) & 1) == 1) {
                int f = requests[i][0], t = requests[i][1];
                --cnt[f];
                ++cnt[t];
            }
        }
        foreach (int v in cnt) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }

    private int CountBits(int n) {
        int count = 0;
        while (n > 0) {
            n -= n & -n;
            ++count;
        }
        return count;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1602. 找到二叉树中最近的右侧节点 🔒](https://leetcode.cn/problems/find-nearest-right-node-in-binary-tree){#1602}

{{< tabs "1602" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
        def dfs(root, i):
            nonlocal d, ans
            if root is None or ans:
                return
            if d == i:
                ans = root
                return
            if root == u:
                d = i
                return
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        d = 0
        ans = None
        dfs(root, 1)
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
    private TreeNode u;
    private TreeNode ans;
    private int d;

    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        this.u = u;
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null || ans != null) {
            return;
        }
        if (d == i) {
            ans = root;
            return;
        }
        if (root == u) {
            d = i;
            return;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* ans;
        int d = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int i) {
            if (!root || ans) {
                return;
            }
            if (d == i) {
                ans = root;
                return;
            }
            if (root == u) {
                d = i;
                return;
            }
            dfs(root->left, i + 1);
            dfs(root->right, i + 1);
        };
        dfs(root, 1);
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
func findNearestRightNode(root *TreeNode, u *TreeNode) *TreeNode {
	d := 0
	var ans *TreeNode
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil || ans != nil {
			return
		}
		if d == i {
			ans = root
			return
		}
		if root == u {
			d = i
			return
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 1)
	return ans
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
 * @param {TreeNode} u
 * @return {TreeNode}
 */
var findNearestRightNode = function (root, u) {
    let d = 0;
    let ans = null;
    function dfs(root, i) {
        if (!root || ans) {
            return;
        }
        if (d == i) {
            ans = root;
            return;
        }
        if (root == u) {
            d = i;
            return;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    }
    dfs(root, 1);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一棵二叉树的根节点 <code>root</code> 和树中的一个节点 <code>u</code> ，返回与 <code>u</code> <strong>所在层</strong>中<strong>距离最近</strong>的<strong>右侧</strong>节点，当 <code>u</code> 是所在层中最右侧的节点，返回 <code>null</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1602.Find%20Nearest%20Right%20Node%20in%20Binary%20Tree/images/p3.png" style="width: 241px; height: 161px;" /></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4,5,6], u = 4
<strong>输出：</strong>5
<strong>解释：</strong>节点 4 所在层中，最近的右侧节点是节点 5。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1602.Find%20Nearest%20Right%20Node%20in%20Binary%20Tree/images/p2.png" style="width: 101px; height: 161px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [3,null,4,2], u = 2
<strong>输出：</strong>null
<strong>解释：</strong>2 的右侧没有节点。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1], u = 1
<strong>输出：</strong>null
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>root = [3,4,2,null,null,null,1], u = 4
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中节点个数的范围是 <code>[1, 10<sup>5</sup>]</code> 。</li>
	<li><code>1 <= Node.val <= 10<sup>5</sup></code></li>
	<li>树中所有节点的值是<strong>唯一</strong>的。</li>
	<li><code>u</code> 是以 <code>root</code> 为根的二叉树的一个节点。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索，从根节点开始搜索，当搜索到节点 $u$ 时，返回队列中的下一个节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

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
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
        q = deque([root])
        while q:
            for i in range(len(q) - 1, -1, -1):
                root = q.popleft()
                if root == u:
                    return q[0] if i else None
                if root.left:
                    q.append(root.left)
                if root.right:
                    q.append(root.right)
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
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                root = q.pollFirst();
                if (root == u) {
                    return i > 1 ? q.peekFirst() : null;
                }
                if (root.left != null) {
                    q.offer(root.left);
                }
                if (root.right != null) {
                    q.offer(root.right);
                }
            }
        }
        return null;
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            for (int i = q.size(); i; --i) {
                root = q.front();
                q.pop();
                if (root == u) {
                    return i > 1 ? q.front() : nullptr;
                }
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
        }
        return nullptr;
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
func findNearestRightNode(root *TreeNode, u *TreeNode) *TreeNode {
	q := []*TreeNode{root}
	for len(q) > 0 {
		for i := len(q); i > 0; i-- {
			root = q[0]
			q = q[1:]
			if root == u {
				if i > 1 {
					return q[0]
				}
				return nil
			}
			if root.Left != nil {
				q = append(q, root.Left)
			}
			if root.Right != nil {
				q = append(q, root.Right)
			}
		}
	}
	return nil
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
 * @param {TreeNode} u
 * @return {TreeNode}
 */
var findNearestRightNode = function (root, u) {
    const q = [root];
    while (q.length) {
        for (let i = q.length; i; --i) {
            root = q.shift();
            if (root == u) {
                return i > 1 ? q[0] : null;
            }
            if (root.left) {
                q.push(root.left);
            }
            if (root.right) {
                q.push(root.right);
            }
        }
    }
    return null;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

DFS 先序遍历二叉树，首次搜索到 $u$ 时，标记目前层数 $d$，下次遇到同一层的节点时，即为目标节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

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
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> Optional[TreeNode]:
        def dfs(root, i):
            nonlocal d, ans
            if root is None or ans:
                return
            if d == i:
                ans = root
                return
            if root == u:
                d = i
                return
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        d = 0
        ans = None
        dfs(root, 1)
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
    private TreeNode u;
    private TreeNode ans;
    private int d;

    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        this.u = u;
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null || ans != null) {
            return;
        }
        if (d == i) {
            ans = root;
            return;
        }
        if (root == u) {
            d = i;
            return;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* ans;
        int d = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int i) {
            if (!root || ans) {
                return;
            }
            if (d == i) {
                ans = root;
                return;
            }
            if (root == u) {
                d = i;
                return;
            }
            dfs(root->left, i + 1);
            dfs(root->right, i + 1);
        };
        dfs(root, 1);
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
func findNearestRightNode(root *TreeNode, u *TreeNode) *TreeNode {
	d := 0
	var ans *TreeNode
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil || ans != nil {
			return
		}
		if d == i {
			ans = root
			return
		}
		if root == u {
			d = i
			return
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 1)
	return ans
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
 * @param {TreeNode} u
 * @return {TreeNode}
 */
var findNearestRightNode = function (root, u) {
    let d = 0;
    let ans = null;
    function dfs(root, i) {
        if (!root || ans) {
            return;
        }
        if (d == i) {
            ans = root;
            return;
        }
        if (root == u) {
            d = i;
            return;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    }
    dfs(root, 1);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1603. 设计停车系统](https://leetcode.cn/problems/design-parking-system){#1603}

{{< tabs "1603" >}}

{{% tab "python" %}}
```python
class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.cnt = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.cnt[carType] == 0:
            return False
        self.cnt[carType] -= 1
        return True


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ParkingSystem {
    private int[] cnt;

    public ParkingSystem(int big, int medium, int small) {
        cnt = new int[] {0, big, medium, small};
    }

    public boolean addCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        cnt = {0, big, medium, small};
    }

    bool addCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }

private:
    vector<int> cnt;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type ParkingSystem struct {
	cnt []int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{[]int{0, big, medium, small}}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if this.cnt[carType] == 0 {
		return false
	}
	this.cnt[carType]--
	return true
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class ParkingSystem {
    private cnt: [number, number, number, number];

    constructor(big: number, medium: number, small: number) {
        this.cnt = [0, big, medium, small];
    }

    addCar(carType: number): boolean {
        if (this.cnt[carType] === 0) {
            return false;
        }
        this.cnt[carType]--;
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct ParkingSystem {
    cnt: [i32; 4]
}

impl ParkingSystem {

    fn new(big: i32, medium: i32, small: i32) -> Self {
        ParkingSystem {
            cnt: [0, big, medium, small],
        }
    }

    fn add_car(&mut self, car_type: i32) -> bool {
        if self.cnt[car_type as usize] == 0 {
            return false;
        }
        self.cnt[car_type as usize] -= 1;
        true
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class ParkingSystem {

    private List<int> cnt;

    public ParkingSystem(int big, int medium, int small) {
        cnt = new List<int>() {0 , big, medium, small};
    }

    public bool AddCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj.AddCar(carType);
 */
```
{{% /tab %}}
{{% tab "c" %}}
```c
typedef struct {
    int* count;
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* res = malloc(sizeof(ParkingSystem));
    res->count = malloc(sizeof(int) * 3);
    res->count[0] = big;
    res->count[1] = medium;
    res->count[2] = small;
    return res;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    int i = carType - 1;
    if (!obj->count[i]) {
        return 0;
    }
    obj->count[i]--;
    return 1;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);

 * parkingSystemFree(obj);
*/
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。</p>

<p>请你实现 <code>ParkingSystem</code> 类：</p>

<ul>
	<li><code>ParkingSystem(int big, int medium, int small)</code> 初始化 <code>ParkingSystem</code> 类，三个参数分别对应每种停车位的数目。</li>
	<li><code>bool addCar(int carType)</code> 检查是否有 <code>carType</code> 对应的停车位。 <code>carType</code> 有三种类型：大，中，小，分别用数字 <code>1</code>， <code>2</code> 和 <code>3</code> 表示。<strong>一辆车只能停在</strong> <strong> </strong><code>carType</code> 对应尺寸的停车位中。如果没有空车位，请返回 <code>false</code> ，否则将该车停入车位并返回 <code>true</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
<strong>输出：</strong>
[null, true, true, false, false]

<strong>解释：</strong>
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // 返回 true ，因为有 1 个空的大车位
parkingSystem.addCar(2); // 返回 true ，因为有 1 个空的中车位
parkingSystem.addCar(3); // 返回 false ，因为没有空的小车位
parkingSystem.addCar(1); // 返回 false ，因为没有空的大车位，唯一一个大车位已经被占据了
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= big, medium, small <= 1000</code></li>
	<li><code>carType</code> 取值为 <code>1</code>， <code>2</code> 或 <code>3</code></li>
	<li>最多会调用 <code>addCar</code> 函数 <code>1000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个长度为 $4$ 的数组 $\textit{cnt}$ 来表示停车场中每种车位的数量，其中 $\textit{cnt}[1]$, $\textit{cnt}[2]$, $\textit{cnt}[3]$ 分别表示大车位、中车位、小车位的数量。

在初始化时，我们将 $\textit{cnt}[1]$, $\textit{cnt}[2]$, $\textit{cnt}[3]$ 分别初始化为大车位、中车位、小车位的数量。

每次停车时，我们检查停车场中是否有对应车位，如果没有则返回 $\textit{false}$，否则将对应车位的数量减一，并返回 $\textit{true}$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.cnt = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.cnt[carType] == 0:
            return False
        self.cnt[carType] -= 1
        return True


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
```

#### Java

```java
class ParkingSystem {
    private int[] cnt;

    public ParkingSystem(int big, int medium, int small) {
        cnt = new int[] {0, big, medium, small};
    }

    public boolean addCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
```

#### C++

```cpp
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        cnt = {0, big, medium, small};
    }

    bool addCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }

private:
    vector<int> cnt;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
```

#### Go

```go
type ParkingSystem struct {
	cnt []int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{[]int{0, big, medium, small}}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	if this.cnt[carType] == 0 {
		return false
	}
	this.cnt[carType]--
	return true
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
```

#### TypeScript

```ts
class ParkingSystem {
    private cnt: [number, number, number, number];

    constructor(big: number, medium: number, small: number) {
        this.cnt = [0, big, medium, small];
    }

    addCar(carType: number): boolean {
        if (this.cnt[carType] === 0) {
            return false;
        }
        this.cnt[carType]--;
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */
```

#### Rust

```rust
struct ParkingSystem {
    cnt: [i32; 4]
}

impl ParkingSystem {

    fn new(big: i32, medium: i32, small: i32) -> Self {
        ParkingSystem {
            cnt: [0, big, medium, small],
        }
    }

    fn add_car(&mut self, car_type: i32) -> bool {
        if self.cnt[car_type as usize] == 0 {
            return false;
        }
        self.cnt[car_type as usize] -= 1;
        true
    }
}
```

#### C#

```cs
public class ParkingSystem {

    private List<int> cnt;

    public ParkingSystem(int big, int medium, int small) {
        cnt = new List<int>() {0 , big, medium, small};
    }

    public bool AddCar(int carType) {
        if (cnt[carType] == 0) {
            return false;
        }
        --cnt[carType];
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj.AddCar(carType);
 */
```

#### C

```c
typedef struct {
    int* count;
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* res = malloc(sizeof(ParkingSystem));
    res->count = malloc(sizeof(int) * 3);
    res->count[0] = big;
    res->count[1] = medium;
    res->count[2] = small;
    return res;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    int i = carType - 1;
    if (!obj->count[i]) {
        return 0;
    }
    obj->count[i]--;
    return 1;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);

 * parkingSystemFree(obj);
*/
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1604. 警告一小时内使用相同员工卡大于等于三次的人](https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period){#1604}

{{< tabs "1604" >}}

{{% tab "python" %}}
```python
class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        d = defaultdict(list)
        for name, t in zip(keyName, keyTime):
            t = int(t[:2]) * 60 + int(t[3:])
            d[name].append(t)
        ans = []
        for name, ts in d.items():
            if (n := len(ts)) > 2:
                ts.sort()
                for i in range(n - 2):
                    if ts[i + 2] - ts[i] <= 60:
                        ans.append(name)
                        break
        ans.sort()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, List<Integer>> d = new HashMap<>();
        for (int i = 0; i < keyName.length; ++i) {
            String name = keyName[i];
            String time = keyTime[i];
            int t
                = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3));
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(t);
        }
        List<String> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            var ts = e.getValue();
            int n = ts.size();
            if (n > 2) {
                Collections.sort(ts);
                for (int i = 0; i < n - 2; ++i) {
                    if (ts.get(i + 2) - ts.get(i) <= 60) {
                        ans.add(e.getKey());
                        break;
                    }
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> d;
        for (int i = 0; i < keyName.size(); ++i) {
            auto name = keyName[i];
            auto time = keyTime[i];
            int a, b;
            sscanf(time.c_str(), "%d:%d", &a, &b);
            int t = a * 60 + b;
            d[name].emplace_back(t);
        }
        vector<string> ans;
        for (auto& [name, ts] : d) {
            int n = ts.size();
            if (n > 2) {
                sort(ts.begin(), ts.end());
                for (int i = 0; i < n - 2; ++i) {
                    if (ts[i + 2] - ts[i] <= 60) {
                        ans.emplace_back(name);
                        break;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alertNames(keyName []string, keyTime []string) (ans []string) {
	d := map[string][]int{}
	for i, name := range keyName {
		var a, b int
		fmt.Sscanf(keyTime[i], "%d:%d", &a, &b)
		t := a*60 + b
		d[name] = append(d[name], t)
	}
	for name, ts := range d {
		n := len(ts)
		if n > 2 {
			sort.Ints(ts)
			for i := 0; i < n-2; i++ {
				if ts[i+2]-ts[i] <= 60 {
					ans = append(ans, name)
					break
				}
			}
		}
	}
	sort.Strings(ans)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function alertNames(keyName: string[], keyTime: string[]): string[] {
    const d: { [name: string]: number[] } = {};
    for (let i = 0; i < keyName.length; ++i) {
        const name = keyName[i];
        const t = keyTime[i];
        const minutes = +t.slice(0, 2) * 60 + +t.slice(3);
        if (d[name] === undefined) {
            d[name] = [];
        }
        d[name].push(minutes);
    }
    const ans: string[] = [];
    for (const name in d) {
        if (d.hasOwnProperty(name)) {
            const ts = d[name];
            if (ts.length > 2) {
                ts.sort((a, b) => a - b);
                for (let i = 0; i < ts.length - 2; ++i) {
                    if (ts[i + 2] - ts[i] <= 60) {
                        ans.push(name);
                        break;
                    }
                }
            }
        }
    }
    ans.sort();
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个 <strong>警告</strong>&nbsp;。</p>

<p>给你字符串数组&nbsp;<code>keyName</code>&nbsp;和&nbsp;<code>keyTime</code> ，其中&nbsp;<code>[keyName[i], keyTime[i]]</code>&nbsp;对应一个人的名字和他在&nbsp;<strong>某一天</strong> 内使用员工卡的时间。</p>

<p>使用时间的格式是 <strong>24小时制</strong>&nbsp;，形如<strong>&nbsp;"HH:MM"</strong>&nbsp;，比方说&nbsp;<code>"23:51"</code> 和&nbsp;<code>"09:49"</code>&nbsp;。</p>

<p>请你返回去重后的收到系统警告的员工名字，将它们按 <strong>字典序</strong><strong>升序&nbsp;</strong>排序后返回。</p>

<p>请注意&nbsp;<code>"10:00"</code> - <code>"11:00"</code>&nbsp;视为一个小时时间范围内，而&nbsp;<code>"22:51"</code> - <code>"23:52"</code>&nbsp;不被视为一小时时间范围内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
<strong>输出：</strong>["daniel"]
<strong>解释：</strong>"daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
<strong>输出：</strong>["bob"]
<strong>解释：</strong>"bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= keyName.length, keyTime.length &lt;= 10<sup>5</sup></code></li>
	<li><code>keyName.length == keyTime.length</code></li>
	<li><code>keyTime</code> 格式为&nbsp;<strong>"HH:MM"&nbsp;</strong>。</li>
	<li>保证&nbsp;<code>[keyName[i], keyTime[i]]</code>&nbsp;形成的二元对&nbsp;<strong>互不相同&nbsp;</strong>。</li>
	<li><code>1 &lt;= keyName[i].length &lt;= 10</code></li>
	<li><code>keyName[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们先用哈希表 $d$ 记录每个员工的所有打卡时间。

然后遍历哈希表，对于每个员工，我们先判断员工的打卡次数是否大于等于 3，如果不是，则跳过该员工。否则，我们将该员工的所有打卡时间按照时间先后排序，然后遍历排序后的打卡时间，判断下标距离为 $2$ 的两个时间是否在同一小时内，如果是，则将该员工加入答案数组。

最后，将答案数组按照字典序排序，即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是打卡记录的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        d = defaultdict(list)
        for name, t in zip(keyName, keyTime):
            t = int(t[:2]) * 60 + int(t[3:])
            d[name].append(t)
        ans = []
        for name, ts in d.items():
            if (n := len(ts)) > 2:
                ts.sort()
                for i in range(n - 2):
                    if ts[i + 2] - ts[i] <= 60:
                        ans.append(name)
                        break
        ans.sort()
        return ans
```

#### Java

```java
class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, List<Integer>> d = new HashMap<>();
        for (int i = 0; i < keyName.length; ++i) {
            String name = keyName[i];
            String time = keyTime[i];
            int t
                = Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3));
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(t);
        }
        List<String> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            var ts = e.getValue();
            int n = ts.size();
            if (n > 2) {
                Collections.sort(ts);
                for (int i = 0; i < n - 2; ++i) {
                    if (ts.get(i + 2) - ts.get(i) <= 60) {
                        ans.add(e.getKey());
                        break;
                    }
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> d;
        for (int i = 0; i < keyName.size(); ++i) {
            auto name = keyName[i];
            auto time = keyTime[i];
            int a, b;
            sscanf(time.c_str(), "%d:%d", &a, &b);
            int t = a * 60 + b;
            d[name].emplace_back(t);
        }
        vector<string> ans;
        for (auto& [name, ts] : d) {
            int n = ts.size();
            if (n > 2) {
                sort(ts.begin(), ts.end());
                for (int i = 0; i < n - 2; ++i) {
                    if (ts[i + 2] - ts[i] <= 60) {
                        ans.emplace_back(name);
                        break;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func alertNames(keyName []string, keyTime []string) (ans []string) {
	d := map[string][]int{}
	for i, name := range keyName {
		var a, b int
		fmt.Sscanf(keyTime[i], "%d:%d", &a, &b)
		t := a*60 + b
		d[name] = append(d[name], t)
	}
	for name, ts := range d {
		n := len(ts)
		if n > 2 {
			sort.Ints(ts)
			for i := 0; i < n-2; i++ {
				if ts[i+2]-ts[i] <= 60 {
					ans = append(ans, name)
					break
				}
			}
		}
	}
	sort.Strings(ans)
	return
}
```

#### TypeScript

```ts
function alertNames(keyName: string[], keyTime: string[]): string[] {
    const d: { [name: string]: number[] } = {};
    for (let i = 0; i < keyName.length; ++i) {
        const name = keyName[i];
        const t = keyTime[i];
        const minutes = +t.slice(0, 2) * 60 + +t.slice(3);
        if (d[name] === undefined) {
            d[name] = [];
        }
        d[name].push(minutes);
    }
    const ans: string[] = [];
    for (const name in d) {
        if (d.hasOwnProperty(name)) {
            const ts = d[name];
            if (ts.length > 2) {
                ts.sort((a, b) => a - b);
                for (let i = 0; i < ts.length - 2; ++i) {
                    if (ts[i + 2] - ts[i] <= 60) {
                        ans.push(name);
                        break;
                    }
                }
            }
        }
    }
    ans.sort();
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1605. 给定行和列的和求可行矩阵](https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums){#1605}

{{< tabs "1605" >}}

{{% tab "python" %}}
```python
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x = min(rowSum[i], colSum[j])
                ans[i][j] = x
                rowSum[i] -= x
                colSum[j] -= x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.length;
        int n = colSum.length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = Math.min(rowSum[i], colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = min(rowSum[i], colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func restoreMatrix(rowSum []int, colSum []int) [][]int {
	m, n := len(rowSum), len(colSum)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for i := range rowSum {
		for j := range colSum {
			x := min(rowSum[i], colSum[j])
			ans[i][j] = x
			rowSum[i] -= x
			colSum[j] -= x
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function restoreMatrix(rowSum: number[], colSum: number[]): number[][] {
    const m = rowSum.length;
    const n = colSum.length;
    const ans = Array.from(new Array(m), () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = Math.min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} rowSum
 * @param {number[]} colSum
 * @return {number[][]}
 */
var restoreMatrix = function (rowSum, colSum) {
    const m = rowSum.length;
    const n = colSum.length;
    const ans = Array.from(new Array(m), () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = Math.min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
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

<p>给你两个非负整数数组&nbsp;<code>rowSum</code> 和&nbsp;<code>colSum</code>&nbsp;，其中&nbsp;<code>rowSum[i]</code>&nbsp;是二维矩阵中第 <code>i</code>&nbsp;行元素的和， <code>colSum[j]</code>&nbsp;是第 <code>j</code>&nbsp;列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。</p>

<p>请找到大小为&nbsp;<code>rowSum.length x colSum.length</code>&nbsp;的任意 <strong>非负整数</strong>&nbsp;矩阵，且该矩阵满足&nbsp;<code>rowSum</code> 和&nbsp;<code>colSum</code>&nbsp;的要求。</p>

<p>请你返回任意一个满足题目要求的二维矩阵，题目保证存在 <strong>至少一个</strong>&nbsp;可行矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [3,8], colSum = [4,7]
<strong>输出：</strong>[[3,0],
      [1,7]]
<strong>解释：</strong>
第 0 行：3 + 0 = 3 == rowSum[0]
第 1 行：1 + 7 = 8 == rowSum[1]
第 0 列：3 + 1 = 4 == colSum[0]
第 1 列：0 + 7 = 7 == colSum[1]
行和列的和都满足题目要求，且所有矩阵元素都是非负的。
另一个可行的矩阵为：[[1,2],
                  [3,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [5,7,10], colSum = [8,6,8]
<strong>输出：</strong>[[0,5,0],
      [6,1,0],
      [2,0,8]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [14,9], colSum = [6,9,8]
<strong>输出：</strong>[[0,9,5],
      [6,0,3]]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [1,0], colSum = [1]
<strong>输出：</strong>[[1],
      [0]]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [0], colSum = [0]
<strong>输出：</strong>[[0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rowSum.length, colSum.length &lt;= 500</code></li>
	<li><code>0 &lt;= rowSum[i], colSum[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>sum(rowSum) == sum(colSum)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

我们可以先初始化一个 $m$ 行 $n$ 列的答案矩阵 $ans$。

接下来，遍历矩阵的每一个位置 $(i, j)$，将该位置的元素设为 $x = min(rowSum[i], colSum[j])$，并将 $rowSum[i]$ 和 $colSum[j]$ 分别减去 $x$。遍历完所有的位置后，我们就可以得到一个满足题目要求的矩阵 $ans$。

以上策略的正确性说明如下：

根据题目的要求，我们知道 $rowSum$ 和 $colSum$ 的和是相等的，那么 $rowSum[0]$ 一定小于等于 $\sum_{j = 0}^{n - 1} colSum[j]$。所以，在经过 $n$ 次操作后，一定能够使得 $rowSum[0]$ 为 $0$，并且保证对任意 $j \in [0, n - 1]$，都有 $colSum[j] \geq 0$。

因此，我们把原问题缩小为一个 $m-1$ 行和 $n$ 列的子问题，继续进行上述的操作，直到 $rowSum$ 和 $colSum$ 中的所有元素都为 $0$，就可以得到一个满足题目要求的矩阵 $ans$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为 $rowSum$ 和 $colSum$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                x = min(rowSum[i], colSum[j])
                ans[i][j] = x
                rowSum[i] -= x
                colSum[j] -= x
        return ans
```

#### Java

```java
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.length;
        int n = colSum.length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = Math.min(rowSum[i], colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = min(rowSum[i], colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func restoreMatrix(rowSum []int, colSum []int) [][]int {
	m, n := len(rowSum), len(colSum)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for i := range rowSum {
		for j := range colSum {
			x := min(rowSum[i], colSum[j])
			ans[i][j] = x
			rowSum[i] -= x
			colSum[j] -= x
		}
	}
	return ans
}
```

#### TypeScript

```ts
function restoreMatrix(rowSum: number[], colSum: number[]): number[][] {
    const m = rowSum.length;
    const n = colSum.length;
    const ans = Array.from(new Array(m), () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = Math.min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} rowSum
 * @param {number[]} colSum
 * @return {number[][]}
 */
var restoreMatrix = function (rowSum, colSum) {
    const m = rowSum.length;
    const n = colSum.length;
    const ans = Array.from(new Array(m), () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const x = Math.min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
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

# [1606. 找到处理最多请求的服务器](https://leetcode.cn/problems/find-servers-that-handled-most-number-of-requests){#1606}

{{< tabs "1606" >}}

{{% tab "python" %}}
```python
class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        free = SortedList(range(k))
        busy = []
        cnt = [0] * k
        for i, (start, t) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= start:
                free.add(busy[0][1])
                heappop(busy)
            if not free:
                continue
            j = free.bisect_left(i % k)
            if j == len(free):
                j = 0
            server = free[j]
            cnt[server] += 1
            heappush(busy, (start + t, server))
            free.remove(server)

        mx = max(cnt)
        return [i for i, v in enumerate(cnt) if v == mx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] cnt = new int[k];
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        TreeSet<Integer> free = new TreeSet<>();
        for (int i = 0; i < k; ++i) {
            free.add(i);
        }
        for (int i = 0; i < arrival.length; ++i) {
            int start = arrival[i];
            int end = start + load[i];
            while (!busy.isEmpty() && busy.peek()[0] <= start) {
                free.add(busy.poll()[1]);
            }
            if (free.isEmpty()) {
                continue;
            }
            Integer server = free.ceiling(i % k);
            if (server == null) {
                server = free.first();
            }
            ++cnt[server];
            busy.offer(new int[] {end, server});
            free.remove(server);
        }
        int mx = 0;
        for (int v : cnt) {
            mx = Math.max(mx, v);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == mx) {
                ans.add(i);
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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; ++i) free.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> cnt(k);
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i], end = start + load[i];
            while (!busy.empty() && busy.top().first <= start) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.empty()) continue;
            auto p = free.lower_bound(i % k);
            if (p == free.end()) p = free.begin();
            int server = *p;
            ++cnt[server];
            busy.emplace(end, server);
            free.erase(server);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            if (cnt[i] == mx)
                ans.push_back(i);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func busiestServers(k int, arrival, load []int) (ans []int) {
	free := redblacktree.NewWithIntComparator()
	for i := 0; i < k; i++ {
		free.Put(i, nil)
	}
	busy := hp{}
	cnt := make([]int, k)
	for i, t := range arrival {
		for len(busy) > 0 && busy[0].end <= t {
			free.Put(busy[0].server, nil)
			heap.Pop(&busy)
		}
		if free.Size() == 0 {
			continue
		}
		p, _ := free.Ceiling(i % k)
		if p == nil {
			p = free.Left()
		}
		server := p.Key.(int)
		cnt[server]++
		heap.Push(&busy, pair{t + load[i], server})
		free.Remove(server)
	}
	mx := slices.Max(cnt)
	for i, v := range cnt {
		if v == mx {
			ans = append(ans, i)
		}
	}
	return
}

type pair struct{ end, server int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].end < h[j].end }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有 <code>k</code>&nbsp;个服务器，编号为 <code>0</code>&nbsp;到 <code>k-1</code>&nbsp;，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是 <strong>不能同时处理超过一个请求</strong>&nbsp;。请求分配到服务器的规则如下：</p>

<ul>
	<li>第&nbsp;<code>i</code>&nbsp;（序号从 0 开始）个请求到达。</li>
	<li>如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。</li>
	<li>如果第&nbsp;<code>(i % k)</code>&nbsp;个服务器空闲，那么对应服务器会处理该请求。</li>
	<li>否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 <code>i</code>&nbsp;个服务器在忙，那么会查看第 <code>(i+1)</code>&nbsp;个服务器，第 <code>(i+2)</code>&nbsp;个服务器等等。</li>
</ul>

<p>给你一个 <strong>严格递增</strong>&nbsp;的正整数数组&nbsp;<code>arrival</code>&nbsp;，表示第&nbsp;<code>i</code>&nbsp;个任务的到达时间，和另一个数组&nbsp;<code>load</code>&nbsp;，其中&nbsp;<code>load[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到 <strong>最繁忙的服务器</strong>&nbsp;。最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。</p>

<p>请你返回包含所有&nbsp;<strong>最繁忙服务器</strong>&nbsp;序号的列表，你可以以任意顺序返回这个列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1606.Find%20Servers%20That%20Handled%20Most%20Number%20of%20Requests/images/load-1.png" style="height: 221px; width: 389px;" /></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
<strong>输出：</strong>[1] 
<strong>解释：</strong>
所有服务器一开始都是空闲的。
前 3 个请求分别由前 3 台服务器依次处理。
请求 3 进来的时候，服务器 0 被占据，所以它被安排到下一台空闲的服务器，也就是服务器 1 。
请求 4 进来的时候，由于所有服务器都被占据，该请求被舍弃。
服务器 0 和 2 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
<strong>输出：</strong>[0]
<strong>解释：</strong>
前 3 个请求分别被前 3 个服务器处理。
请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0 是最忙的服务器。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3], load = [10,12,11]
<strong>输出：</strong>[0,1,2]
<strong>解释：</strong>每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>k = 1, arrival = [1], load = [1]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrival.length, load.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arrival.length == load.length</code></li>
	<li><code>1 &lt;= arrival[i], load[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>arrival</code>&nbsp;保证 <strong>严格递增</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + 优先队列

题目求的是最繁忙的服务器列表，因此可以想到用**哈希表**记录每个服务器处理的任务数，然后获取所有处理了最大任务数 mx 的服务器列表即可。关键的问题就在于，求出每个任务分配给了哪台服务器处理。

我们用 有序集合 free 存放所有的空闲服务器，优先队列 busy 存放正在处理请求的服务器的处理结束时间和对应的服务器编号，即二元组 `(end, server)`，优先队列满足队首元素的处理结束时间最小，用一个哈希表 cnt 记录每台服务器处理的任务数。

当第 i 个请求到达时，如果 busy 不为空，我们循环判断 busy 队首的任务结束时间是否小于等于当前请求的到达时间 `arrival[i]`，即 start。如果是，说明队首任务在此时刻已经处理结束，可以从 busy 队列中移出，循环判断。

接下来，如果 free 为空，说明当前没有空闲服务器能够处理第 i 个请求，直接 continue 丢弃；否则，查找 free 中大于等于 `i % k` 的第一个服务器，如果查找成功，那么由该服务器来处理该请求，否则，由 free 的第一个服务器（编号最小）来处理。假设该服务器是 server, 那么 `cnt[server]` 加 1，同时将二元组 `(end, server)` 放入优先队列 busy 中，并且将该 server 中有序集合 free 中移出。

最后，只需要获取 cnt 中的最大值 mx，找出处理了 mx 个任务数的服务器列表，即为答案。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        free = SortedList(range(k))
        busy = []
        cnt = [0] * k
        for i, (start, t) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= start:
                free.add(busy[0][1])
                heappop(busy)
            if not free:
                continue
            j = free.bisect_left(i % k)
            if j == len(free):
                j = 0
            server = free[j]
            cnt[server] += 1
            heappush(busy, (start + t, server))
            free.remove(server)

        mx = max(cnt)
        return [i for i, v in enumerate(cnt) if v == mx]
```

#### Java

```java
class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] cnt = new int[k];
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        TreeSet<Integer> free = new TreeSet<>();
        for (int i = 0; i < k; ++i) {
            free.add(i);
        }
        for (int i = 0; i < arrival.length; ++i) {
            int start = arrival[i];
            int end = start + load[i];
            while (!busy.isEmpty() && busy.peek()[0] <= start) {
                free.add(busy.poll()[1]);
            }
            if (free.isEmpty()) {
                continue;
            }
            Integer server = free.ceiling(i % k);
            if (server == null) {
                server = free.first();
            }
            ++cnt[server];
            busy.offer(new int[] {end, server});
            free.remove(server);
        }
        int mx = 0;
        for (int v : cnt) {
            mx = Math.max(mx, v);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == mx) {
                ans.add(i);
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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; ++i) free.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> cnt(k);
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i], end = start + load[i];
            while (!busy.empty() && busy.top().first <= start) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.empty()) continue;
            auto p = free.lower_bound(i % k);
            if (p == free.end()) p = free.begin();
            int server = *p;
            ++cnt[server];
            busy.emplace(end, server);
            free.erase(server);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            if (cnt[i] == mx)
                ans.push_back(i);
        return ans;
    }
};
```

#### Go

```go
func busiestServers(k int, arrival, load []int) (ans []int) {
	free := redblacktree.NewWithIntComparator()
	for i := 0; i < k; i++ {
		free.Put(i, nil)
	}
	busy := hp{}
	cnt := make([]int, k)
	for i, t := range arrival {
		for len(busy) > 0 && busy[0].end <= t {
			free.Put(busy[0].server, nil)
			heap.Pop(&busy)
		}
		if free.Size() == 0 {
			continue
		}
		p, _ := free.Ceiling(i % k)
		if p == nil {
			p = free.Left()
		}
		server := p.Key.(int)
		cnt[server]++
		heap.Push(&busy, pair{t + load[i], server})
		free.Remove(server)
	}
	mx := slices.Max(cnt)
	for i, v := range cnt {
		if v == mx {
			ans = append(ans, i)
		}
	}
	return
}

type pair struct{ end, server int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].end < h[j].end }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1607. 没有卖出的卖家 🔒](https://leetcode.cn/problems/sellers-with-no-sales){#1607}

{{< tabs "1607" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT seller_name
FROM
    Seller
    LEFT JOIN Orders USING (seller_id)
GROUP BY seller_id
HAVING IFNULL(SUM(YEAR(sale_date) = 2020), 0) = 0
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Customer</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id 是该表具有唯一值的列。
该表的每行包含网上商城的每一位顾客的信息。
</pre>

<p>&nbsp;</p>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| sale_date     | date    |
| order_cost    | int     |
| customer_id   | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是该表具有唯一值的列。
该表的每行包含网上商城的所有订单的信息.
sale_date 是顾客 customer_id 和卖家 seller_id 之间交易的日期.
</pre>

<p>&nbsp;</p>

<p>表: <code>Seller</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| seller_id     | int     |
| seller_name   | varchar |
+---------------+---------+
seller_id 是该表主具有唯一值的列。
该表的每行包含每一位卖家的信息.
</pre>

<p>&nbsp;</p>

<p>写一个解决方案,&nbsp;报告所有在&nbsp;<code>2020</code>&nbsp;年度没有任何卖出的卖家的名字。</p>

<p>返回结果按照&nbsp;<code>seller_name</code>&nbsp;<strong>升序排列。</strong></p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Customer</code> 表:
+--------------+---------------+
| customer_id  | customer_name |
+--------------+---------------+
| 101          | Alice         |
| 102          | Bob           |
| 103          | Charlie       |
+--------------+---------------+
<code>Orders</code> 表:
+-------------+------------+--------------+-------------+-------------+
| order_id    | sale_date  | order_cost   | customer_id | seller_id   |
+-------------+------------+--------------+-------------+-------------+
| 1           | 2020-03-01 | 1500         | 101         | 1           |
| 2           | 2020-05-25 | 2400         | 102         | 2           |
| 3           | 2019-05-25 | 800          | 101         | 3           |
| 4           | 2020-09-13 | 1000         | 103         | 2           |
| 5           | 2019-02-11 | 700          | 101         | 2           |
+-------------+------------+--------------+-------------+-------------+
<code>Seller</code> 表:
+-------------+-------------+
| seller_id   | seller_name |
+-------------+-------------+
| 1           | Daniel      |
| 2           | Elizabeth   |
| 3           | Frank       |
+-------------+-------------+
<code><strong>输出：</strong></code>
+-------------+
| <code>seller_name </code>|
+-------------+
| Frank       |
+-------------+
<code><strong>解释：</strong></code>
Daniel 在 2020 年 3 月卖出 1 次。
Elizabeth 在 2020 年卖出 2 次, 在 2019 年卖出 1 次。
Frank 在 2019 年卖出 1 次, 在 2020 年没有卖出。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组 + 筛选

我们可以使用左连接，将 `Seller` 表与 `Orders` 表按照字段 `seller_id` 连接，然后按照 `seller_id` 分组，统计每个卖家在 $2020$ 年的卖出次数，最后筛选出卖出次数为 $0$ 的卖家。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT seller_name
FROM
    Seller
    LEFT JOIN Orders USING (seller_id)
GROUP BY seller_id
HAVING IFNULL(SUM(YEAR(sale_date) = 2020), 0) = 0
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1608. 特殊数组的特征值](https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x){#1608}

{{< tabs "1608" >}}

{{% tab "python" %}}
```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        for x in range(1, n + 1):
            cnt = n - bisect_left(nums, x)
            if cnt == x:
                return x
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int x = 1; x <= n; ++x) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (nums[mid] >= x) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int cnt = n - left;
            if (cnt == x) {
                return x;
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
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int x = 1; x <= n; ++x) {
            int cnt = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (cnt == x) return x;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func specialArray(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	for x := 1; x <= n; x++ {
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if nums[mid] >= x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		cnt := n - left
		if cnt == x {
			return x
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function specialArray(nums: number[]): number {
    const n = nums.length;
    let left = 0;
    let right = n + 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        const count = nums.reduce((r, v) => r + (v >= mid ? 1 : 0), 0);

        if (count === mid) {
            return mid;
        }

        if (count > mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;
impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut left = 0;
        let mut right = n + 1;
        while left < right {
            let mid = left + (right - left) / 2;
            let mut count = 0;
            for &num in nums.iter() {
                if num >= mid {
                    count += 1;
                }
            }
            match count.cmp(&mid) {
                Ordering::Equal => {
                    return mid;
                }
                Ordering::Less => {
                    right = mid;
                }
                Ordering::Greater => {
                    left = mid + 1;
                }
            }
        }
        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非负整数数组 <code>nums</code> 。如果存在一个数 <code>x</code> ，使得 <code>nums</code> 中恰好有 <code>x</code> 个元素 <strong>大于或者等于</strong> <code>x</code> ，那么就称 <code>nums</code> 是一个 <strong>特殊数组</strong> ，而 <code>x</code> 是该数组的 <strong>特征值</strong> 。</p>

<p>注意： <code>x</code> <strong>不必</strong> 是 <code>nums</code> 的中的元素。</p>

<p>如果数组 <code>nums</code> 是一个 <strong>特殊数组</strong> ，请返回它的特征值 <code>x</code> 。否则，返回<em> </em><code>-1</code> 。可以证明的是，如果 <code>nums</code> 是特殊数组，那么其特征值 <code>x</code> 是 <strong>唯一的</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,5]
<strong>输出：</strong>2
<strong>解释：</strong>有 2 个元素（3 和 5）大于或等于 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,0]
<strong>输出：</strong>-1
<strong>解释：</strong>没有满足题目要求的特殊数组，故而也不存在特征值 x 。
如果 x = 0，应该有 0 个元素 &gt;= x，但实际有 2 个。
如果 x = 1，应该有 1 个元素 &gt;= x，但实际有 0 个。
如果 x = 2，应该有 2 个元素 &gt;= x，但实际有 0 个。
x 不能取更大的值，因为 nums 中只有两个元素。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [0,4,3,0,4]
<strong>输出：</strong>3
<strong>解释：</strong>有 3 个元素大于或等于 3 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [3,6,7,7,0]
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们在 $[1..n]$ 范围内枚举 $x$，然后统计数组中大于等于 $x$ 的元素个数，记为 $cnt$。若存在 $cnt$ 与 $x$ 相等，直接返回 $x$。

时间复杂度 $O(n^2)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for x in range(1, len(nums) + 1):
            cnt = sum(v >= x for v in nums)
            if cnt == x:
                return x
        return -1
```

#### Java

```java
class Solution {
    public int specialArray(int[] nums) {
        for (int x = 1; x <= nums.length; ++x) {
            int cnt = 0;
            for (int v : nums) {
                if (v >= x) {
                    ++cnt;
                }
            }
            if (cnt == x) {
                return x;
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
    int specialArray(vector<int>& nums) {
        for (int x = 1; x <= nums.size(); ++x) {
            int cnt = 0;
            for (int v : nums) cnt += v >= x;
            if (cnt == x) return x;
        }
        return -1;
    }
};
```

#### Go

```go
func specialArray(nums []int) int {
	for x := 1; x <= len(nums); x++ {
		cnt := 0
		for _, v := range nums {
			if v >= x {
				cnt++
			}
		}
		if cnt == x {
			return x
		}
	}
	return -1
}
```

#### TypeScript

```ts
function specialArray(nums: number[]): number {
    const n = nums.length;
    for (let i = 0; i <= n; i++) {
        if (i === nums.reduce((r, v) => r + (v >= i ? 1 : 0), 0)) {
            return i;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        for i in 0..=n {
            let mut count = 0;
            for &num in nums.iter() {
                if num >= i {
                    count += 1;
                }
            }
            if count == i {
                return i;
            }
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 二分查找

我们也可以先对 `nums` 进行排序。

接下来同样枚举 $x$，利用二分查找，找到 `nums` 中第一个大于等于 $x$ 的元素，快速统计出 `nums` 中大于等于 $x$ 的元素个数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        for x in range(1, n + 1):
            cnt = n - bisect_left(nums, x)
            if cnt == x:
                return x
        return -1
```

#### Java

```java
class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int x = 1; x <= n; ++x) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (nums[mid] >= x) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int cnt = n - left;
            if (cnt == x) {
                return x;
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
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int x = 1; x <= n; ++x) {
            int cnt = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (cnt == x) return x;
        }
        return -1;
    }
};
```

#### Go

```go
func specialArray(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	for x := 1; x <= n; x++ {
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if nums[mid] >= x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		cnt := n - left
		if cnt == x {
			return x
		}
	}
	return -1
}
```

#### TypeScript

```ts
function specialArray(nums: number[]): number {
    const n = nums.length;
    let left = 0;
    let right = n + 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        const count = nums.reduce((r, v) => r + (v >= mid ? 1 : 0), 0);

        if (count === mid) {
            return mid;
        }

        if (count > mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return -1;
}
```

#### Rust

```rust
use std::cmp::Ordering;
impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut left = 0;
        let mut right = n + 1;
        while left < right {
            let mid = left + (right - left) / 2;
            let mut count = 0;
            for &num in nums.iter() {
                if num >= mid {
                    count += 1;
                }
            }
            match count.cmp(&mid) {
                Ordering::Equal => {
                    return mid;
                }
                Ordering::Less => {
                    right = mid;
                }
                Ordering::Greater => {
                    left = mid + 1;
                }
            }
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1609. 奇偶树](https://leetcode.cn/problems/even-odd-tree){#1609}

{{< tabs "1609" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, i):
            if root is None:
                return True
            even = i % 2 == 0
            prev = d.get(i, 0 if even else inf)
            if even and (root.val % 2 == 0 or prev >= root.val):
                return False
            if not even and (root.val % 2 == 1 or prev <= root.val):
                return False
            d[i] = root.val
            return dfs(root.left, i + 1) and dfs(root.right, i + 1)

        d = {}
        return dfs(root, 0)
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
    private Map<Integer, Integer> d = new HashMap<>();

    public boolean isEvenOddTree(TreeNode root) {
        return dfs(root, 0);
    }

    private boolean dfs(TreeNode root, int i) {
        if (root == null) {
            return true;
        }
        boolean even = i % 2 == 0;
        int prev = d.getOrDefault(i, even ? 0 : 1000001);
        if (even && (root.val % 2 == 0 || prev >= root.val)) {
            return false;
        }
        if (!even && (root.val % 2 == 1 || prev <= root.val)) {
            return false;
        }
        d.put(i, root.val);
        return dfs(root.left, i + 1) && dfs(root.right, i + 1);
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
    unordered_map<int, int> d;

    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }

    bool dfs(TreeNode* root, int i) {
        if (!root) {
            return true;
        }
        int even = i % 2 == 0;
        int prev = d.count(i) ? d[i] : (even ? 0 : 1e7);
        if (even && (root->val % 2 == 0 || prev >= root->val)) {
            return false;
        }
        if (!even && (root->val % 2 == 1 || prev <= root->val)) {
            return false;
        }
        d[i] = root->val;
        return dfs(root->left, i + 1) && dfs(root->right, i + 1);
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
func isEvenOddTree(root *TreeNode) bool {
	d := map[int]int{}
	var dfs func(*TreeNode, int) bool
	dfs = func(root *TreeNode, i int) bool {
		if root == nil {
			return true
		}
		even := i%2 == 0
		prev, ok := d[i]
		if !ok {
			if even {
				prev = 0
			} else {
				prev = 10000000
			}
		}
		if even && (root.Val%2 == 0 || prev >= root.Val) {
			return false
		}
		if !even && (root.Val%2 == 1 || prev <= root.Val) {
			return false
		}
		d[i] = root.Val
		return dfs(root.Left, i+1) && dfs(root.Right, i+1)
	}
	return dfs(root, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一棵二叉树满足下述几个条件，则可以称为 <strong>奇偶树</strong> ：</p>

<ul>
	<li>二叉树根节点所在层下标为 <code>0</code> ，根的子节点所在层下标为 <code>1</code> ，根的孙节点所在层下标为 <code>2</code> ，依此类推。</li>
	<li><strong>偶数下标</strong> 层上的所有节点的值都是 <strong>奇</strong> 整数，从左到右按顺序 <strong>严格递增</strong></li>
	<li><strong>奇数下标</strong> 层上的所有节点的值都是 <strong>偶</strong> 整数，从左到右按顺序 <strong>严格递减</strong></li>
</ul>

<p>给你二叉树的根节点，如果二叉树为 <strong>奇偶树 </strong>，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1609.Even%20Odd%20Tree/images/sample_1_1966.png" style="height: 229px; width: 362px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
<strong>输出：</strong>true
<strong>解释：</strong>每一层的节点值分别是：
0 层：[1]
1 层：[10,4]
2 层：[3,7,9]
3 层：[12,8,6,2]
由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1609.Even%20Odd%20Tree/images/sample_2_1966.png" style="height: 167px; width: 363px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [5,4,2,3,3,7]
<strong>输出：</strong>false
<strong>解释：</strong>每一层的节点值分别是：
0 层：[5]
1 层：[4,2]
2 层：[3,3,7]
2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1609.Even%20Odd%20Tree/images/sample_1_333_1966.png" style="height: 167px; width: 363px;" /></p>

<pre>
<strong>输入：</strong>root = [5,9,1,3,5,7]
<strong>输出：</strong>false
<strong>解释：</strong>1 层上的节点值应为偶数。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
<strong>输出：</strong>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

BFS 逐层遍历，每层按照奇偶性判断，每层的节点值都是偶数或奇数，且严格递增或递减。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        even = 1
        q = deque([root])
        while q:
            prev = 0 if even else inf
            for _ in range(len(q)):
                root = q.popleft()
                if even and (root.val % 2 == 0 or prev >= root.val):
                    return False
                if not even and (root.val % 2 == 1 or prev <= root.val):
                    return False
                prev = root.val
                if root.left:
                    q.append(root.left)
                if root.right:
                    q.append(root.right)
            even ^= 1
        return True
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
    public boolean isEvenOddTree(TreeNode root) {
        boolean even = true;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int prev = even ? 0 : 1000001;
            for (int n = q.size(); n > 0; --n) {
                root = q.pollFirst();
                if (even && (root.val % 2 == 0 || prev >= root.val)) {
                    return false;
                }
                if (!even && (root.val % 2 == 1 || prev <= root.val)) {
                    return false;
                }
                prev = root.val;
                if (root.left != null) {
                    q.offer(root.left);
                }
                if (root.right != null) {
                    q.offer(root.right);
                }
            }
            even = !even;
        }
        return true;
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
    bool isEvenOddTree(TreeNode* root) {
        int even = 1;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int prev = even ? 0 : 1e7;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                if (even && (root->val % 2 == 0 || prev >= root->val)) {
                    return false;
                }
                if (!even && (root->val % 2 == 1 || prev <= root->val)) {
                    return false;
                }
                prev = root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            even ^= 1;
        }
        return true;
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
func isEvenOddTree(root *TreeNode) bool {
	even := true
	q := []*TreeNode{root}
	for len(q) > 0 {
		var prev int = 1e7
		if even {
			prev = 0
		}
		for n := len(q); n > 0; n-- {
			root = q[0]
			q = q[1:]
			if even && (root.Val%2 == 0 || prev >= root.Val) {
				return false
			}
			if !even && (root.Val%2 == 1 || prev <= root.Val) {
				return false
			}
			prev = root.Val
			if root.Left != nil {
				q = append(q, root.Left)
			}
			if root.Right != nil {
				q = append(q, root.Right)
			}
		}
		even = !even
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

DFS 先序遍历二叉树，同样根据节点所在层的奇偶性判断是否满足条件，遍历过程中用哈希表记录每一层最近访问到的节点值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, i):
            if root is None:
                return True
            even = i % 2 == 0
            prev = d.get(i, 0 if even else inf)
            if even and (root.val % 2 == 0 or prev >= root.val):
                return False
            if not even and (root.val % 2 == 1 or prev <= root.val):
                return False
            d[i] = root.val
            return dfs(root.left, i + 1) and dfs(root.right, i + 1)

        d = {}
        return dfs(root, 0)
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
    private Map<Integer, Integer> d = new HashMap<>();

    public boolean isEvenOddTree(TreeNode root) {
        return dfs(root, 0);
    }

    private boolean dfs(TreeNode root, int i) {
        if (root == null) {
            return true;
        }
        boolean even = i % 2 == 0;
        int prev = d.getOrDefault(i, even ? 0 : 1000001);
        if (even && (root.val % 2 == 0 || prev >= root.val)) {
            return false;
        }
        if (!even && (root.val % 2 == 1 || prev <= root.val)) {
            return false;
        }
        d.put(i, root.val);
        return dfs(root.left, i + 1) && dfs(root.right, i + 1);
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
    unordered_map<int, int> d;

    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }

    bool dfs(TreeNode* root, int i) {
        if (!root) {
            return true;
        }
        int even = i % 2 == 0;
        int prev = d.count(i) ? d[i] : (even ? 0 : 1e7);
        if (even && (root->val % 2 == 0 || prev >= root->val)) {
            return false;
        }
        if (!even && (root->val % 2 == 1 || prev <= root->val)) {
            return false;
        }
        d[i] = root->val;
        return dfs(root->left, i + 1) && dfs(root->right, i + 1);
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
func isEvenOddTree(root *TreeNode) bool {
	d := map[int]int{}
	var dfs func(*TreeNode, int) bool
	dfs = func(root *TreeNode, i int) bool {
		if root == nil {
			return true
		}
		even := i%2 == 0
		prev, ok := d[i]
		if !ok {
			if even {
				prev = 0
			} else {
				prev = 10000000
			}
		}
		if even && (root.Val%2 == 0 || prev >= root.Val) {
			return false
		}
		if !even && (root.Val%2 == 1 || prev <= root.Val) {
			return false
		}
		d[i] = root.Val
		return dfs(root.Left, i+1) && dfs(root.Right, i+1)
	}
	return dfs(root, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

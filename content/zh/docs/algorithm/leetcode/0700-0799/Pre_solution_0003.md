---
title: "0720_词典中最长的单词"
date: 2025-10-08T18:36:29+08:00
weight: 3
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 有序集合, 栈, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 线段树, 设计, 链表]
---

{{< markmap >}}
### [0720_词典中最长的单词](#720)
#### [字典树](#720)
#### [数组](#720)
#### [哈希表](#720)
#### [字符串](#720)
#### [排序](#720)
### [0721_账户合并](#721)
#### [深度优先搜索](#721)
#### [广度优先搜索](#721)
#### [并查集](#721)
#### [数组](#721)
#### [哈希表](#721)
#### [字符串](#721)
#### [排序](#721)
### [0722_删除注释](#722)
#### [数组](#722)
#### [字符串](#722)
### [0723_粉碎糖果 🔒](#723)
#### [数组](#723)
#### [双指针](#723)
#### [矩阵](#723)
#### [模拟](#723)
### [0724_寻找数组的中心下标](#724)
#### [数组](#724)
#### [前缀和](#724)
### [0725_分隔链表](#725)
#### [链表](#725)
### [0726_原子的数量](#726)
#### [栈](#726)
#### [哈希表](#726)
#### [字符串](#726)
#### [排序](#726)
### [0727_最小窗口子序列 🔒](#727)
#### [字符串](#727)
#### [动态规划](#727)
#### [滑动窗口](#727)
### [0728_自除数](#728)
#### [数学](#728)
### [0729_我的日程安排表 I](#729)
#### [设计](#729)
#### [线段树](#729)
#### [数组](#729)
#### [二分查找](#729)
#### [有序集合](#729)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0720_词典中最长的单词
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0721_账户合并
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0722_删除注释
___
#### 数组
___
#### 字符串
---
### 0723_粉碎糖果 🔒
___
#### 数组
___
#### 双指针
___
#### 矩阵
___
#### 模拟
---
### 0724_寻找数组的中心下标
___
#### 数组
___
#### 前缀和
---
### 0725_分隔链表
___
#### 链表
---
### 0726_原子的数量
___
#### 栈
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0727_最小窗口子序列 🔒
___
#### 字符串
___
#### 动态规划
___
#### 滑动窗口
---
### 0728_自除数
___
#### 数学
---
### 0729_我的日程安排表 I
___
#### 设计
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 有序集合
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 字典树 |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 有序集合 | 栈 | 模拟 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 线段树 | 设计 | 链表 |

# [720. 词典中最长的单词](https://leetcode.cn/problems/longest-word-in-dictionary){#720}

{{< tabs "720" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.is_end = False

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return False
            node = node.children[idx]
            if not node.is_end:
                return False
        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        ans = ""
        for w in words:
            if trie.search(w) and (
                len(ans) < len(w) or (len(ans) == len(w) and ans > w)
            ):
                ans = w
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null || !node.children[idx].isEnd) {
                return false;
            }
            node = node.children[idx];
        }
        return true;
    }
}

class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        String ans = "";
        for (String w : words) {
            if (trie.search(w)
                && (ans.length() < w.length()
                    || (ans.length() == w.length() && w.compareTo(ans) < 0))) {
                ans = w;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie* children[26] = {nullptr};
    bool isEnd = false;

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr || !node->children[idx]->isEnd) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const string& w : words) {
            trie.insert(w);
        }

        string ans = "";
        for (const string& w : words) {
            if (trie.search(w) && (ans.length() < w.length() || (ans.length() == w.length() && w < ans))) {
                ans = w;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func (t *Trie) insert(w string) {
	node := t
	for i := 0; i < len(w); i++ {
		idx := w[i] - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (t *Trie) search(w string) bool {
	node := t
	for i := 0; i < len(w); i++ {
		idx := w[i] - 'a'
		if node.children[idx] == nil || !node.children[idx].isEnd {
			return false
		}
		node = node.children[idx]
	}
	return true
}

func longestWord(words []string) string {
	trie := &Trie{}
	for _, w := range words {
		trie.insert(w)
	}

	ans := ""
	for _, w := range words {
		if trie.search(w) && (len(ans) < len(w) || (len(ans) == len(w) && w < ans)) {
			ans = w
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: (Trie | null)[] = new Array(26).fill(null);
    isEnd: boolean = false;

    insert(w: string): void {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const idx: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx]!;
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const idx: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null || !node.children[idx]!.isEnd) {
                return false;
            }
            node = node.children[idx]!;
        }
        return true;
    }
}

function longestWord(words: string[]): string {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }

    let ans = '';
    for (const w of words) {
        if (trie.search(w) && (ans.length < w.length || (ans.length === w.length && w < ans))) {
            ans = w;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                node.children[idx] = Some(Box::new(Trie::new()));
            }
            node = node.children[idx].as_mut().unwrap();
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() || !node.children[idx].as_ref().unwrap().is_end {
                return false;
            }
            node = node.children[idx].as_ref().unwrap();
        }
        true
    }
}

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut trie = Trie::new();
        for w in &words {
            trie.insert(w);
        }

        let mut ans = String::new();
        for w in words {
            if trie.search(&w) && (ans.len() < w.len() || (ans.len() == w.len() && w < ans)) {
                ans = w;
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
 * @param {string[]} words
 * @return {string}
 */
var longestWord = function (words) {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }

    let ans = '';
    for (const w of words) {
        if (trie.search(w) && (ans.length < w.length || (ans.length === w.length && w < ans))) {
            ans = w;
        }
    }
    return ans;
};

class Trie {
    constructor() {
        this.children = Array(26).fill(null);
        this.isEnd = false;
    }

    insert(w) {
        let node = this;
        for (let i = 0; i < w.length; i++) {
            const idx = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    search(w) {
        let node = this;
        for (let i = 0; i < w.length; i++) {
            const idx = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null || !node.children[idx].isEnd) {
                return false;
            }
            node = node.children[idx];
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

<p>给出一个字符串数组&nbsp;<code>words</code> 组成的一本英语词典。返回能够通过&nbsp;<code>words</code>&nbsp;中其它单词逐步添加一个字母来构造得到的&nbsp;<code>words</code> 中最长的单词。</p>

<p>若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。</p>

<p>请注意，单词应该从左到右构建，每个额外的字符都添加到前一个单词的结尾。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["w","wo","wor","worl", "world"]
<strong>输出：</strong>"world"
<strong>解释：</strong> 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
<strong>输出：</strong>"apple"
<strong>解释：</strong>"apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li>所有输入的字符串&nbsp;<code>words[i]</code>&nbsp;都只包含小写字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树

我们可以使用字典树来存储所有的单词，然后遍历所有的单词，判断当前单词是否可以由字典树中的其他单词逐步添加一个字母组成，找出满足条件的最长的，且字典序最小的单词。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 是所有单词的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26
        self.is_end = False

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: str) -> bool:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return False
            node = node.children[idx]
            if not node.is_end:
                return False
        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        ans = ""
        for w in words:
            if trie.search(w) and (
                len(ans) < len(w) or (len(ans) == len(w) and ans > w)
            ):
                ans = w
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean search(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null || !node.children[idx].isEnd) {
                return false;
            }
            node = node.children[idx];
        }
        return true;
    }
}

class Solution {
    public String longestWord(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        String ans = "";
        for (String w : words) {
            if (trie.search(w)
                && (ans.length() < w.length()
                    || (ans.length() == w.length() && w.compareTo(ans) < 0))) {
                ans = w;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie* children[26] = {nullptr};
    bool isEnd = false;

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr || !node->children[idx]->isEnd) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const string& w : words) {
            trie.insert(w);
        }

        string ans = "";
        for (const string& w : words) {
            if (trie.search(w) && (ans.length() < w.length() || (ans.length() == w.length() && w < ans))) {
                ans = w;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func (t *Trie) insert(w string) {
	node := t
	for i := 0; i < len(w); i++ {
		idx := w[i] - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (t *Trie) search(w string) bool {
	node := t
	for i := 0; i < len(w); i++ {
		idx := w[i] - 'a'
		if node.children[idx] == nil || !node.children[idx].isEnd {
			return false
		}
		node = node.children[idx]
	}
	return true
}

func longestWord(words []string) string {
	trie := &Trie{}
	for _, w := range words {
		trie.insert(w)
	}

	ans := ""
	for _, w := range words {
		if trie.search(w) && (len(ans) < len(w) || (len(ans) == len(w) && w < ans)) {
			ans = w
		}
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    children: (Trie | null)[] = new Array(26).fill(null);
    isEnd: boolean = false;

    insert(w: string): void {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const idx: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx]!;
        }
        node.isEnd = true;
    }

    search(w: string): boolean {
        let node: Trie = this;
        for (let i = 0; i < w.length; i++) {
            const idx: number = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null || !node.children[idx]!.isEnd) {
                return false;
            }
            node = node.children[idx]!;
        }
        return true;
    }
}

function longestWord(words: string[]): string {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }

    let ans = '';
    for (const w of words) {
        if (trie.search(w) && (ans.length < w.length || (ans.length === w.length && w < ans))) {
            ans = w;
        }
    }
    return ans;
}
```

#### Rust

```rust
struct Trie {
    children: [Option<Box<Trie>>; 26],
    is_end: bool,
}

impl Trie {
    fn new() -> Self {
        Trie {
            children: Default::default(),
            is_end: false,
        }
    }

    fn insert(&mut self, w: &str) {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() {
                node.children[idx] = Some(Box::new(Trie::new()));
            }
            node = node.children[idx].as_mut().unwrap();
        }
        node.is_end = true;
    }

    fn search(&self, w: &str) -> bool {
        let mut node = self;
        for c in w.chars() {
            let idx = (c as usize) - ('a' as usize);
            if node.children[idx].is_none() || !node.children[idx].as_ref().unwrap().is_end {
                return false;
            }
            node = node.children[idx].as_ref().unwrap();
        }
        true
    }
}

impl Solution {
    pub fn longest_word(words: Vec<String>) -> String {
        let mut trie = Trie::new();
        for w in &words {
            trie.insert(w);
        }

        let mut ans = String::new();
        for w in words {
            if trie.search(&w) && (ans.len() < w.len() || (ans.len() == w.len() && w < ans)) {
                ans = w;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string[]} words
 * @return {string}
 */
var longestWord = function (words) {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }

    let ans = '';
    for (const w of words) {
        if (trie.search(w) && (ans.length < w.length || (ans.length === w.length && w < ans))) {
            ans = w;
        }
    }
    return ans;
};

class Trie {
    constructor() {
        this.children = Array(26).fill(null);
        this.isEnd = false;
    }

    insert(w) {
        let node = this;
        for (let i = 0; i < w.length; i++) {
            const idx = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    search(w) {
        let node = this;
        for (let i = 0; i < w.length; i++) {
            const idx = w.charCodeAt(i) - 'a'.charCodeAt(0);
            if (node.children[idx] === null || !node.children[idx].isEnd) {
                return false;
            }
            node = node.children[idx];
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

# [721. 账户合并](https://leetcode.cn/problems/accounts-merge){#721}

{{< tabs "721" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UnionFind(len(accounts))
        d = {}
        for i, (_, *emails) in enumerate(accounts):
            for email in emails:
                if email in d:
                    uf.union(i, d[email])
                else:
                    d[email] = i
        g = defaultdict(set)
        for i, (_, *emails) in enumerate(accounts):
            root = uf.find(i)
            g[root].update(emails)
        return [[accounts[root][0]] + sorted(emails) for root, emails in g.items()]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        UnionFind uf = new UnionFind(n);
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts.get(i).size(); ++j) {
                String email = accounts.get(i).get(j);
                if (d.containsKey(email)) {
                    uf.union(i, d.get(email));
                } else {
                    d.put(email, i);
                }
            }
        }
        Map<Integer, Set<String>> g = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            g.computeIfAbsent(root, k -> new HashSet<>())
                .addAll(accounts.get(i).subList(1, accounts.get(i).size()));
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : g.entrySet()) {
            List<String> emails = new ArrayList<>(e.getValue());
            Collections.sort(emails);
            ans.add(new ArrayList<>());
            ans.get(ans.size() - 1).add(accounts.get(e.getKey()).get(0));
            ans.get(ans.size() - 1).addAll(emails);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> d;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                const string& email = accounts[i][j];
                if (d.find(email) != d.end()) {
                    uf.unite(i, d[email]);
                } else {
                    d[email] = i;
                }
            }
        }
        unordered_map<int, set<string>> g;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            g[root].insert(accounts[i].begin() + 1, accounts[i].end());
        }
        vector<vector<string>> ans;
        for (const auto& [root, s] : g) {
            vector<string> emails(s.begin(), s.end());
            emails.insert(emails.begin(), accounts[root][0]);
            ans.push_back(emails);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func accountsMerge(accounts [][]string) (ans [][]string) {
	n := len(accounts)
	uf := newUnionFind(n)
	d := make(map[string]int)
	for i := 0; i < n; i++ {
		for _, email := range accounts[i][1:] {
			if j, ok := d[email]; ok {
				uf.union(i, j)
			} else {
				d[email] = i
			}
		}
	}
	g := make(map[int]map[string]struct{})
	for i := 0; i < n; i++ {
		root := uf.find(i)
		if _, ok := g[root]; !ok {
			g[root] = make(map[string]struct{})
		}
		for _, email := range accounts[i][1:] {
			g[root][email] = struct{}{}
		}
	}
	for root, s := range g {
		emails := []string{}
		for email := range s {
			emails = append(emails, email)
		}
		sort.Strings(emails)
		account := append([]string{accounts[root][0]}, emails...)
		ans = append(ans, account)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = new Array(n);
        this.size = new Array(n);
        for (let i = 0; i < n; ++i) {
            this.p[i] = i;
            this.size[i] = 1;
        }
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        let pa = this.find(a),
            pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function accountsMerge(accounts: string[][]): string[][] {
    const n = accounts.length;
    const uf = new UnionFind(n);
    const d = new Map<string, number>();

    for (let i = 0; i < n; ++i) {
        for (let j = 1; j < accounts[i].length; ++j) {
            const email = accounts[i][j];
            if (d.has(email)) {
                uf.union(i, d.get(email)!);
            } else {
                d.set(email, i);
            }
        }
    }

    const g = new Map<number, Set<string>>();
    for (let i = 0; i < n; ++i) {
        const root = uf.find(i);
        if (!g.has(root)) {
            g.set(root, new Set<string>());
        }
        const emailSet = g.get(root)!;
        for (let j = 1; j < accounts[i].length; ++j) {
            emailSet.add(accounts[i][j]);
        }
    }

    const ans: string[][] = [];
    for (const [root, emails] of g.entries()) {
        const emailList = Array.from(emails).sort();
        const mergedAccount = [accounts[root][0], ...emailList];
        ans.push(mergedAccount);
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

<p>给定一个列表 <code>accounts</code>，每个元素 <code>accounts[i]</code>&nbsp;是一个字符串列表，其中第一个元素 <code>accounts[i][0]</code>&nbsp;是&nbsp;<em>名称 (name)</em>，其余元素是 <em><strong>emails</strong> </em>表示该账户的邮箱地址。</p>

<p>现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。</p>

<p>合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 <strong>按字符 ASCII 顺序排列</strong> 的邮箱地址。账户本身可以以 <strong>任意顺序</strong> 返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
<b>输出：</b>[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
<b>解释：</b>
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
<strong>输出：</strong>[["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= accounts.length &lt;= 1000</code></li>
	<li><code>2 &lt;= accounts[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= accounts[i][j].length &lt;= 30</code></li>
	<li><code>accounts[i][0]</code> 由英文字母组成</li>
	<li><code>accounts[i][j] (for j &gt; 0)</code> 是有效的邮箱地址</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集 + 哈希表

根据题目描述，我们可以使用并查集，将具有相同邮箱地址的账户合并在一起。

我们首先遍历所有的账户，对于第 $i$ 个账户，我们遍历其所有的邮箱地址，如果该邮箱地址在哈希表 $\textit{d}$ 中出现过，则使用并查集，将该账户的编号 $i$ 与之前出现过的邮箱地址所属的账户编号进行合并；否则，将该邮箱地址与账户的编号 $i$ 进行映射。

接下来，我们遍历所有的账户，对于第 $i$ 个账户，我们使用并查集找到其根节点，然后将该账户的所有邮箱地址添加到哈希表 $\textit{g}$ 中，其中键为根节点，值为该账户的所有邮箱地址。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为账户的数量。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UnionFind(len(accounts))
        d = {}
        for i, (_, *emails) in enumerate(accounts):
            for email in emails:
                if email in d:
                    uf.union(i, d[email])
                else:
                    d[email] = i
        g = defaultdict(set)
        for i, (_, *emails) in enumerate(accounts):
            root = uf.find(i)
            g[root].update(emails)
        return [[accounts[root][0]] + sorted(emails) for root, emails in g.items()]
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        UnionFind uf = new UnionFind(n);
        Map<String, Integer> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts.get(i).size(); ++j) {
                String email = accounts.get(i).get(j);
                if (d.containsKey(email)) {
                    uf.union(i, d.get(email));
                } else {
                    d.put(email, i);
                }
            }
        }
        Map<Integer, Set<String>> g = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            g.computeIfAbsent(root, k -> new HashSet<>())
                .addAll(accounts.get(i).subList(1, accounts.get(i).size()));
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : g.entrySet()) {
            List<String> emails = new ArrayList<>(e.getValue());
            Collections.sort(emails);
            ans.add(new ArrayList<>());
            ans.get(ans.size() - 1).add(accounts.get(e.getKey()).get(0));
            ans.get(ans.size() - 1).addAll(emails);
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> d;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                const string& email = accounts[i][j];
                if (d.find(email) != d.end()) {
                    uf.unite(i, d[email]);
                } else {
                    d[email] = i;
                }
            }
        }
        unordered_map<int, set<string>> g;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            g[root].insert(accounts[i].begin() + 1, accounts[i].end());
        }
        vector<vector<string>> ans;
        for (const auto& [root, s] : g) {
            vector<string> emails(s.begin(), s.end());
            emails.insert(emails.begin(), accounts[root][0]);
            ans.push_back(emails);
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func accountsMerge(accounts [][]string) (ans [][]string) {
	n := len(accounts)
	uf := newUnionFind(n)
	d := make(map[string]int)
	for i := 0; i < n; i++ {
		for _, email := range accounts[i][1:] {
			if j, ok := d[email]; ok {
				uf.union(i, j)
			} else {
				d[email] = i
			}
		}
	}
	g := make(map[int]map[string]struct{})
	for i := 0; i < n; i++ {
		root := uf.find(i)
		if _, ok := g[root]; !ok {
			g[root] = make(map[string]struct{})
		}
		for _, email := range accounts[i][1:] {
			g[root][email] = struct{}{}
		}
	}
	for root, s := range g {
		emails := []string{}
		for email := range s {
			emails = append(emails, email)
		}
		sort.Strings(emails)
		account := append([]string{accounts[root][0]}, emails...)
		ans = append(ans, account)
	}
	return
}
```

#### TypeScript

```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = new Array(n);
        this.size = new Array(n);
        for (let i = 0; i < n; ++i) {
            this.p[i] = i;
            this.size[i] = 1;
        }
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        let pa = this.find(a),
            pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function accountsMerge(accounts: string[][]): string[][] {
    const n = accounts.length;
    const uf = new UnionFind(n);
    const d = new Map<string, number>();

    for (let i = 0; i < n; ++i) {
        for (let j = 1; j < accounts[i].length; ++j) {
            const email = accounts[i][j];
            if (d.has(email)) {
                uf.union(i, d.get(email)!);
            } else {
                d.set(email, i);
            }
        }
    }

    const g = new Map<number, Set<string>>();
    for (let i = 0; i < n; ++i) {
        const root = uf.find(i);
        if (!g.has(root)) {
            g.set(root, new Set<string>());
        }
        const emailSet = g.get(root)!;
        for (let j = 1; j < accounts[i].length; ++j) {
            emailSet.add(accounts[i][j]);
        }
    }

    const ans: string[][] = [];
    for (const [root, emails] of g.entries()) {
        const emailList = Array.from(emails).sort();
        const mergedAccount = [accounts[root][0], ...emailList];
        ans.push(mergedAccount);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [722. 删除注释](https://leetcode.cn/problems/remove-comments){#722}

{{< tabs "722" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans = []
        t = []
        block_comment = False
        for s in source:
            i, m = 0, len(s)
            while i < m:
                if block_comment:
                    if i + 1 < m and s[i : i + 2] == "*/":
                        block_comment = False
                        i += 1
                else:
                    if i + 1 < m and s[i : i + 2] == "/*":
                        block_comment = True
                        i += 1
                    elif i + 1 < m and s[i : i + 2] == "//":
                        break
                    else:
                        t.append(s[i])
                i += 1
            if not block_comment and t:
                ans.append("".join(t))
                t.clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> removeComments(String[] source) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        boolean blockComment = false;
        for (String s : source) {
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                if (blockComment) {
                    if (i + 1 < m && s.charAt(i) == '*' && s.charAt(i + 1) == '/') {
                        blockComment = false;
                        ++i;
                    }
                } else {
                    if (i + 1 < m && s.charAt(i) == '/' && s.charAt(i + 1) == '*') {
                        blockComment = true;
                        ++i;
                    } else if (i + 1 < m && s.charAt(i) == '/' && s.charAt(i + 1) == '/') {
                        break;
                    } else {
                        sb.append(s.charAt(i));
                    }
                }
            }
            if (!blockComment && sb.length() > 0) {
                ans.add(sb.toString());
                sb.setLength(0);
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
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string t;
        bool blockComment = false;
        for (auto& s : source) {
            int m = s.size();
            for (int i = 0; i < m; ++i) {
                if (blockComment) {
                    if (i + 1 < m && s[i] == '*' && s[i + 1] == '/') {
                        blockComment = false;
                        ++i;
                    }
                } else {
                    if (i + 1 < m && s[i] == '/' && s[i + 1] == '*') {
                        blockComment = true;
                        ++i;
                    } else if (i + 1 < m && s[i] == '/' && s[i + 1] == '/') {
                        break;
                    } else {
                        t.push_back(s[i]);
                    }
                }
            }
            if (!blockComment && !t.empty()) {
                ans.emplace_back(t);
                t.clear();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeComments(source []string) (ans []string) {
	t := []byte{}
	blockComment := false
	for _, s := range source {
		m := len(s)
		for i := 0; i < m; i++ {
			if blockComment {
				if i+1 < m && s[i] == '*' && s[i+1] == '/' {
					blockComment = false
					i++
				}
			} else {
				if i+1 < m && s[i] == '/' && s[i+1] == '*' {
					blockComment = true
					i++
				} else if i+1 < m && s[i] == '/' && s[i+1] == '/' {
					break
				} else {
					t = append(t, s[i])
				}
			}
		}
		if !blockComment && len(t) > 0 {
			ans = append(ans, string(t))
			t = []byte{}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeComments(source: string[]): string[] {
    const ans: string[] = [];
    const t: string[] = [];
    let blockComment = false;
    for (const s of source) {
        const m = s.length;
        for (let i = 0; i < m; ++i) {
            if (blockComment) {
                if (i + 1 < m && s.slice(i, i + 2) === '*/') {
                    blockComment = false;
                    ++i;
                }
            } else {
                if (i + 1 < m && s.slice(i, i + 2) === '/*') {
                    blockComment = true;
                    ++i;
                } else if (i + 1 < m && s.slice(i, i + 2) === '//') {
                    break;
                } else {
                    t.push(s[i]);
                }
            }
        }
        if (!blockComment && t.length) {
            ans.push(t.join(''));
            t.length = 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_comments(source: Vec<String>) -> Vec<String> {
        let mut ans: Vec<String> = Vec::new();
        let mut t: Vec<String> = Vec::new();
        let mut blockComment = false;

        for s in &source {
            let m = s.len();
            let mut i = 0;
            while i < m {
                if blockComment {
                    if i + 1 < m && &s[i..i + 2] == "*/" {
                        blockComment = false;
                        i += 2;
                    } else {
                        i += 1;
                    }
                } else {
                    if i + 1 < m && &s[i..i + 2] == "/*" {
                        blockComment = true;
                        i += 2;
                    } else if i + 1 < m && &s[i..i + 2] == "//" {
                        break;
                    } else {
                        t.push(s.chars().nth(i).unwrap().to_string());
                        i += 1;
                    }
                }
            }
            if !blockComment && !t.is_empty() {
                ans.push(t.join(""));
                t.clear();
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

<p>给一个 C++ 程序，删除程序中的注释。这个程序<code>source</code>是一个数组，其中<code>source[i]</code>表示第&nbsp;<code>i</code>&nbsp;行源码。&nbsp;这表示每行源码由 <code>'\n'</code>&nbsp;分隔。</p>

<p>在 C++ 中有两种注释风格，行内注释和块注释。</p>

<ul>
	<li>字符串<code>//</code> 表示行注释，表示<code>//</code>和其右侧的其余字符应该被忽略。</li>
	<li>字符串<code>/*</code> 表示一个块注释，它表示直到下一个（非重叠）出现的<code>*/</code>之间的所有字符都应该被忽略。（阅读顺序为从左到右）非重叠是指，字符串<code>/*/</code>并没有结束块注释，因为注释的结尾与开头相重叠。</li>
</ul>

<p>第一个有效注释优先于其他注释。</p>

<ul>
	<li>如果字符串<code>//</code>出现在块注释中会被忽略。</li>
	<li>同样，如果字符串<code>/*</code>出现在行或块注释中也会被忽略。</li>
</ul>

<p>如果一行在删除注释之后变为空字符串，那么<strong>不要</strong>输出该行。即，答案列表中的每个字符串都是非空的。</p>

<p>样例中<strong>没有</strong>控制字符，单引号或双引号字符。</p>

<ul>
	<li>比如，<code>source = "string s = "/* Not a comment. */";"</code> 不会出现在测试样例里。</li>
</ul>

<p>此外，没有其他内容（如定义或宏）会干扰注释。</p>

<p>我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的<code>/*</code>总是开始新的注释。</p>

<p>最后，隐式换行符<strong>可以</strong>通过块注释删除。 有关详细信息，请参阅下面的示例。</p>

<p>从源代码中删除注释后，需要以相同的格式返回源代码。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
<strong>输出:</strong> ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
<strong>解释:</strong> 示例代码可以编排成这样:
/*Test program */
int main()
{ 
  // variable declaration 
int a, b, c;
/* This is a test
   multiline  
   comment for 
   testing */
a = b + c;
}
第 1 行和第 6-9 行的字符串 /* 表示块注释。第 4 行的字符串 // 表示行注释。
编排后: 
int main()
{ 
  
int a, b, c;
a = b + c;
}</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> source = ["a/*comment", "line", "more_comment*/b"]
<strong>输出:</strong> ["ab"]
<strong>解释:</strong> 原始的 source 字符串是 "a/*comment<strong>\n</strong>line<strong>\n</strong>more_comment*/b", 其中我们用粗体显示了换行符。删除注释后，隐含的换行符被删除，留下字符串 "ab" 用换行符分隔成数组时就是 ["ab"].
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= source.length &lt;= 100</code></li>
	<li><code>0 &lt;= source[i].length &lt;= 80</code></li>
	<li><code>source[i]</code>&nbsp;由可打印的 <strong>ASCII</strong> 字符组成。</li>
	<li>每个块注释都会被闭合。</li>
	<li>给定的源码中不会有单引号、双引号或其他控制字符。</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute"><span style="top:0px"><span style="left:-9999px"><span style="opacity:0"><span style="overflow:hidden">&nbsp;</span></span></span></span></span></span>​​​​​​</span>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

我们用一个变量 来表示当前是否处于块注释中，初始时 $\textit{blockComment}$ 为 `false`；用一个变量 $t$ 来存储当前行的有效字符。

接下来，遍历每一行，分情况讨论：

如果当前处于块注释中，那么如果当前字符和下一个字符是 `'*/'`，说明块注释结束，我们将 $\textit{blockComment}$ 置为 `false`，并且跳过这两个字符；否则，我们继续保持块注释状态，不做任何操作；

如果当前不处于块注释中，那么如果当前字符和下一个字符是 `'/*'`，说明块注释开始，我们将 $\textit{blockComment}$ 置为 `true`，并且跳过这两个字符；如果当前字符和下一个字符是 `'//'`，那么说明行注释开始，我们直接退出当前行的遍历；否则，说明当前字符是有效字符，我们将其加入 $t$ 中；

遍历完当前行后，如果 $\textit{blockComment}$ 为 `false`，并且 $t$ 不为空，说明当前行是有效行，我们将其加入答案数组中，并且清空 $t$。继续遍历下一行。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 是源代码的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans = []
        t = []
        block_comment = False
        for s in source:
            i, m = 0, len(s)
            while i < m:
                if block_comment:
                    if i + 1 < m and s[i : i + 2] == "*/":
                        block_comment = False
                        i += 1
                else:
                    if i + 1 < m and s[i : i + 2] == "/*":
                        block_comment = True
                        i += 1
                    elif i + 1 < m and s[i : i + 2] == "//":
                        break
                    else:
                        t.append(s[i])
                i += 1
            if not block_comment and t:
                ans.append("".join(t))
                t.clear()
        return ans
```

#### Java

```java
class Solution {
    public List<String> removeComments(String[] source) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        boolean blockComment = false;
        for (String s : source) {
            int m = s.length();
            for (int i = 0; i < m; ++i) {
                if (blockComment) {
                    if (i + 1 < m && s.charAt(i) == '*' && s.charAt(i + 1) == '/') {
                        blockComment = false;
                        ++i;
                    }
                } else {
                    if (i + 1 < m && s.charAt(i) == '/' && s.charAt(i + 1) == '*') {
                        blockComment = true;
                        ++i;
                    } else if (i + 1 < m && s.charAt(i) == '/' && s.charAt(i + 1) == '/') {
                        break;
                    } else {
                        sb.append(s.charAt(i));
                    }
                }
            }
            if (!blockComment && sb.length() > 0) {
                ans.add(sb.toString());
                sb.setLength(0);
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
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string t;
        bool blockComment = false;
        for (auto& s : source) {
            int m = s.size();
            for (int i = 0; i < m; ++i) {
                if (blockComment) {
                    if (i + 1 < m && s[i] == '*' && s[i + 1] == '/') {
                        blockComment = false;
                        ++i;
                    }
                } else {
                    if (i + 1 < m && s[i] == '/' && s[i + 1] == '*') {
                        blockComment = true;
                        ++i;
                    } else if (i + 1 < m && s[i] == '/' && s[i + 1] == '/') {
                        break;
                    } else {
                        t.push_back(s[i]);
                    }
                }
            }
            if (!blockComment && !t.empty()) {
                ans.emplace_back(t);
                t.clear();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeComments(source []string) (ans []string) {
	t := []byte{}
	blockComment := false
	for _, s := range source {
		m := len(s)
		for i := 0; i < m; i++ {
			if blockComment {
				if i+1 < m && s[i] == '*' && s[i+1] == '/' {
					blockComment = false
					i++
				}
			} else {
				if i+1 < m && s[i] == '/' && s[i+1] == '*' {
					blockComment = true
					i++
				} else if i+1 < m && s[i] == '/' && s[i+1] == '/' {
					break
				} else {
					t = append(t, s[i])
				}
			}
		}
		if !blockComment && len(t) > 0 {
			ans = append(ans, string(t))
			t = []byte{}
		}
	}
	return
}
```

#### TypeScript

```ts
function removeComments(source: string[]): string[] {
    const ans: string[] = [];
    const t: string[] = [];
    let blockComment = false;
    for (const s of source) {
        const m = s.length;
        for (let i = 0; i < m; ++i) {
            if (blockComment) {
                if (i + 1 < m && s.slice(i, i + 2) === '*/') {
                    blockComment = false;
                    ++i;
                }
            } else {
                if (i + 1 < m && s.slice(i, i + 2) === '/*') {
                    blockComment = true;
                    ++i;
                } else if (i + 1 < m && s.slice(i, i + 2) === '//') {
                    break;
                } else {
                    t.push(s[i]);
                }
            }
        }
        if (!blockComment && t.length) {
            ans.push(t.join(''));
            t.length = 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_comments(source: Vec<String>) -> Vec<String> {
        let mut ans: Vec<String> = Vec::new();
        let mut t: Vec<String> = Vec::new();
        let mut blockComment = false;

        for s in &source {
            let m = s.len();
            let mut i = 0;
            while i < m {
                if blockComment {
                    if i + 1 < m && &s[i..i + 2] == "*/" {
                        blockComment = false;
                        i += 2;
                    } else {
                        i += 1;
                    }
                } else {
                    if i + 1 < m && &s[i..i + 2] == "/*" {
                        blockComment = true;
                        i += 2;
                    } else if i + 1 < m && &s[i..i + 2] == "//" {
                        break;
                    } else {
                        t.push(s.chars().nth(i).unwrap().to_string());
                        i += 1;
                    }
                }
            }
            if !blockComment && !t.is_empty() {
                ans.push(t.join(""));
                t.clear();
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

# [723. 粉碎糖果 🔒](https://leetcode.cn/problems/candy-crush){#723}

{{< tabs "723" >}}

{{% tab "python" %}}
```python
class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m, n = len(board), len(board[0])
        run = True
        while run:
            run = False
            for i in range(m):
                for j in range(2, n):
                    if board[i][j] and abs(board[i][j]) == abs(board[i][j - 1]) == abs(
                        board[i][j - 2]
                    ):
                        run = True
                        board[i][j] = board[i][j - 1] = board[i][j - 2] = -abs(
                            board[i][j]
                        )
            for j in range(n):
                for i in range(2, m):
                    if board[i][j] and abs(board[i][j]) == abs(board[i - 1][j]) == abs(
                        board[i - 2][j]
                    ):
                        run = True
                        board[i][j] = board[i - 1][j] = board[i - 2][j] = -abs(
                            board[i][j]
                        )
            if run:
                for j in range(n):
                    k = m - 1
                    for i in range(m - 1, -1, -1):
                        if board[i][j] > 0:
                            board[k][j] = board[i][j]
                            k -= 1
                    while k >= 0:
                        board[k][j] = 0
                        k -= 1
        return board
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] candyCrush(int[][] board) {
        int m = board.length, n = board[0].length;
        boolean run = true;

        while (run) {
            run = false;
            for (int i = 0; i < m; i++) {
                for (int j = 2; j < n; j++) {
                    if (board[i][j] != 0 && Math.abs(board[i][j]) == Math.abs(board[i][j - 1])
                        && Math.abs(board[i][j]) == Math.abs(board[i][j - 2])) {
                        run = true;
                        int val = Math.abs(board[i][j]);
                        board[i][j] = board[i][j - 1] = board[i][j - 2] = -val;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 2; i < m; i++) {
                    if (board[i][j] != 0 && Math.abs(board[i][j]) == Math.abs(board[i - 1][j])
                        && Math.abs(board[i][j]) == Math.abs(board[i - 2][j])) {
                        run = true;
                        int val = Math.abs(board[i][j]);
                        board[i][j] = board[i - 1][j] = board[i - 2][j] = -val;
                    }
                }
            }
            if (run) {
                for (int j = 0; j < n; j++) {
                    int k = m - 1;
                    for (int i = m - 1; i >= 0; i--) {
                        if (board[i][j] > 0) {
                            board[k][j] = board[i][j];
                            k--;
                        }
                    }
                    while (k >= 0) {
                        board[k][j] = 0;
                        k--;
                    }
                }
            }
        }

        return board;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        bool run = true;
        while (run) {
            run = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n - 2; ++j) {
                    if (board[i][j] != 0 && abs(board[i][j]) == abs(board[i][j + 1]) && abs(board[i][j]) == abs(board[i][j + 2])) {
                        run = true;
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = -abs(board[i][j]);
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m - 2; ++i) {
                    if (board[i][j] != 0 && abs(board[i][j]) == abs(board[i + 1][j]) && abs(board[i][j]) == abs(board[i + 2][j])) {
                        run = true;
                        board[i][j] = board[i + 1][j] = board[i + 2][j] = -abs(board[i][j]);
                    }
                }
            }
            if (run) {
                for (int j = 0; j < n; ++j) {
                    int curr = m - 1;
                    for (int i = m - 1; i >= 0; --i) {
                        if (board[i][j] > 0) {
                            board[curr][j] = board[i][j];
                            --curr;
                        }
                    }
                    while (curr > -1) {
                        board[curr][j] = 0;
                        --curr;
                    }
                }
            }
        }
        return board;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func candyCrush(board [][]int) [][]int {
	m := len(board)
	n := len(board[0])
	run := true

	for run {
		run = false
		for i := 0; i < m; i++ {
			for j := 2; j < n; j++ {
				if board[i][j] != 0 && abs(board[i][j]) == abs(board[i][j-1]) && abs(board[i][j]) == abs(board[i][j-2]) {
					run = true
					val := abs(board[i][j])
					board[i][j] = -val
					board[i][j-1] = -val
					board[i][j-2] = -val
				}
			}
		}
		for j := 0; j < n; j++ {
			for i := 2; i < m; i++ {
				if board[i][j] != 0 && abs(board[i][j]) == abs(board[i-1][j]) && abs(board[i][j]) == abs(board[i-2][j]) {
					run = true
					val := abs(board[i][j])
					board[i][j] = -val
					board[i-1][j] = -val
					board[i-2][j] = -val
				}
			}
		}
		if run {
			for j := 0; j < n; j++ {
				k := m - 1
				for i := m - 1; i >= 0; i-- {
					if board[i][j] > 0 {
						board[k][j] = board[i][j]
						k--
					}
				}
				for k >= 0 {
					board[k][j] = 0
					k--
				}
			}
		}
	}

	return board
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
function candyCrush(board: number[][]): number[][] {
    const m = board.length;
    const n = board[0].length;
    let run = true;
    while (run) {
        run = false;
        for (let i = 0; i < m; i++) {
            for (let j = 2; j < n; j++) {
                if (
                    board[i][j] !== 0 &&
                    Math.abs(board[i][j]) === Math.abs(board[i][j - 1]) &&
                    Math.abs(board[i][j]) === Math.abs(board[i][j - 2])
                ) {
                    run = true;
                    const val = Math.abs(board[i][j]);
                    board[i][j] = board[i][j - 1] = board[i][j - 2] = -val;
                }
            }
        }
        for (let j = 0; j < n; j++) {
            for (let i = 2; i < m; i++) {
                if (
                    board[i][j] !== 0 &&
                    Math.abs(board[i][j]) === Math.abs(board[i - 1][j]) &&
                    Math.abs(board[i][j]) === Math.abs(board[i - 2][j])
                ) {
                    run = true;
                    const val = Math.abs(board[i][j]);
                    board[i][j] = board[i - 1][j] = board[i - 2][j] = -val;
                }
            }
        }
        if (run) {
            for (let j = 0; j < n; j++) {
                let k = m - 1;
                for (let i = m - 1; i >= 0; i--) {
                    if (board[i][j] > 0) {
                        board[k][j] = board[i][j];
                        k--;
                    }
                }
                while (k >= 0) {
                    board[k][j] = 0;
                    k--;
                }
            }
        }
    }
    return board;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这个问题是实现一个简单的消除算法。</p>

<p>给定一个&nbsp;<code>m x n</code>&nbsp;的二维整数数组 <code>board</code> 代表糖果所在的方格，不同的正整数 <code>board[i][j]</code> 代表不同种类的糖果，如果 <code>board[i][j] == 0</code> 代表&nbsp;<code>(i, j)</code> 这个位置是空的。</p>

<p>给定的方格是玩家移动后的游戏状态，现在需要你根据以下规则粉碎糖果，使得整个方格处于稳定状态并最终输出：</p>

<ul>
	<li>如果有三个及以上水平或者垂直相连的同种糖果，同一时间将它们粉碎，即将这些位置变成空的。</li>
	<li>在同时粉碎掉这些糖果之后，如果有一个空的位置上方还有糖果，那么上方的糖果就会下落直到碰到下方的糖果或者底部，这些糖果都是同时下落，也不会有新的糖果从顶部出现并落下来。</li>
	<li>通过前两步的操作，可能又会出现可以粉碎的糖果，请继续重复前面的操作。</li>
	<li>当不存在可以粉碎的糖果，也就是状态稳定之后，请输出最终的状态。</li>
</ul>

<p>你需要模拟上述规则并使整个方格达到稳定状态，并输出。</p>

<p>&nbsp;</p>

<p><strong>示例 1 :</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0723.Candy%20Crush/images/candy_crush_example_2.png" style="height: 411px; width: 600px;" /></p>

<pre>
<strong>输入: </strong>board = [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
<strong>输出: </strong>[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> board = [[1,3,5,5,2],[3,4,3,3,1],[3,2,4,5,2],[2,4,4,5,5],[1,4,4,1,1]]
<strong>输出:</strong> [[1,3,0,0,0],[3,4,0,5,2],[3,2,0,3,1],[2,4,0,5,2],[1,4,3,1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>3 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= board[i][j] &lt;= 2000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以逐行和逐列遍历矩阵，找到连续三个相同的元素，将它们标记为负数。如果成功标记，我们需要将矩阵中的元素下移，直到没有元素可以下移为止。

时间复杂度 $O(m^2 \times n^2)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m, n = len(board), len(board[0])
        run = True
        while run:
            run = False
            for i in range(m):
                for j in range(2, n):
                    if board[i][j] and abs(board[i][j]) == abs(board[i][j - 1]) == abs(
                        board[i][j - 2]
                    ):
                        run = True
                        board[i][j] = board[i][j - 1] = board[i][j - 2] = -abs(
                            board[i][j]
                        )
            for j in range(n):
                for i in range(2, m):
                    if board[i][j] and abs(board[i][j]) == abs(board[i - 1][j]) == abs(
                        board[i - 2][j]
                    ):
                        run = True
                        board[i][j] = board[i - 1][j] = board[i - 2][j] = -abs(
                            board[i][j]
                        )
            if run:
                for j in range(n):
                    k = m - 1
                    for i in range(m - 1, -1, -1):
                        if board[i][j] > 0:
                            board[k][j] = board[i][j]
                            k -= 1
                    while k >= 0:
                        board[k][j] = 0
                        k -= 1
        return board
```

#### Java

```java
class Solution {
    public int[][] candyCrush(int[][] board) {
        int m = board.length, n = board[0].length;
        boolean run = true;

        while (run) {
            run = false;
            for (int i = 0; i < m; i++) {
                for (int j = 2; j < n; j++) {
                    if (board[i][j] != 0 && Math.abs(board[i][j]) == Math.abs(board[i][j - 1])
                        && Math.abs(board[i][j]) == Math.abs(board[i][j - 2])) {
                        run = true;
                        int val = Math.abs(board[i][j]);
                        board[i][j] = board[i][j - 1] = board[i][j - 2] = -val;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 2; i < m; i++) {
                    if (board[i][j] != 0 && Math.abs(board[i][j]) == Math.abs(board[i - 1][j])
                        && Math.abs(board[i][j]) == Math.abs(board[i - 2][j])) {
                        run = true;
                        int val = Math.abs(board[i][j]);
                        board[i][j] = board[i - 1][j] = board[i - 2][j] = -val;
                    }
                }
            }
            if (run) {
                for (int j = 0; j < n; j++) {
                    int k = m - 1;
                    for (int i = m - 1; i >= 0; i--) {
                        if (board[i][j] > 0) {
                            board[k][j] = board[i][j];
                            k--;
                        }
                    }
                    while (k >= 0) {
                        board[k][j] = 0;
                        k--;
                    }
                }
            }
        }

        return board;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        bool run = true;
        while (run) {
            run = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n - 2; ++j) {
                    if (board[i][j] != 0 && abs(board[i][j]) == abs(board[i][j + 1]) && abs(board[i][j]) == abs(board[i][j + 2])) {
                        run = true;
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = -abs(board[i][j]);
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m - 2; ++i) {
                    if (board[i][j] != 0 && abs(board[i][j]) == abs(board[i + 1][j]) && abs(board[i][j]) == abs(board[i + 2][j])) {
                        run = true;
                        board[i][j] = board[i + 1][j] = board[i + 2][j] = -abs(board[i][j]);
                    }
                }
            }
            if (run) {
                for (int j = 0; j < n; ++j) {
                    int curr = m - 1;
                    for (int i = m - 1; i >= 0; --i) {
                        if (board[i][j] > 0) {
                            board[curr][j] = board[i][j];
                            --curr;
                        }
                    }
                    while (curr > -1) {
                        board[curr][j] = 0;
                        --curr;
                    }
                }
            }
        }
        return board;
    }
};
```

#### Go

```go
func candyCrush(board [][]int) [][]int {
	m := len(board)
	n := len(board[0])
	run := true

	for run {
		run = false
		for i := 0; i < m; i++ {
			for j := 2; j < n; j++ {
				if board[i][j] != 0 && abs(board[i][j]) == abs(board[i][j-1]) && abs(board[i][j]) == abs(board[i][j-2]) {
					run = true
					val := abs(board[i][j])
					board[i][j] = -val
					board[i][j-1] = -val
					board[i][j-2] = -val
				}
			}
		}
		for j := 0; j < n; j++ {
			for i := 2; i < m; i++ {
				if board[i][j] != 0 && abs(board[i][j]) == abs(board[i-1][j]) && abs(board[i][j]) == abs(board[i-2][j]) {
					run = true
					val := abs(board[i][j])
					board[i][j] = -val
					board[i-1][j] = -val
					board[i-2][j] = -val
				}
			}
		}
		if run {
			for j := 0; j < n; j++ {
				k := m - 1
				for i := m - 1; i >= 0; i-- {
					if board[i][j] > 0 {
						board[k][j] = board[i][j]
						k--
					}
				}
				for k >= 0 {
					board[k][j] = 0
					k--
				}
			}
		}
	}

	return board
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
function candyCrush(board: number[][]): number[][] {
    const m = board.length;
    const n = board[0].length;
    let run = true;
    while (run) {
        run = false;
        for (let i = 0; i < m; i++) {
            for (let j = 2; j < n; j++) {
                if (
                    board[i][j] !== 0 &&
                    Math.abs(board[i][j]) === Math.abs(board[i][j - 1]) &&
                    Math.abs(board[i][j]) === Math.abs(board[i][j - 2])
                ) {
                    run = true;
                    const val = Math.abs(board[i][j]);
                    board[i][j] = board[i][j - 1] = board[i][j - 2] = -val;
                }
            }
        }
        for (let j = 0; j < n; j++) {
            for (let i = 2; i < m; i++) {
                if (
                    board[i][j] !== 0 &&
                    Math.abs(board[i][j]) === Math.abs(board[i - 1][j]) &&
                    Math.abs(board[i][j]) === Math.abs(board[i - 2][j])
                ) {
                    run = true;
                    const val = Math.abs(board[i][j]);
                    board[i][j] = board[i - 1][j] = board[i - 2][j] = -val;
                }
            }
        }
        if (run) {
            for (let j = 0; j < n; j++) {
                let k = m - 1;
                for (let i = m - 1; i >= 0; i--) {
                    if (board[i][j] > 0) {
                        board[k][j] = board[i][j];
                        k--;
                    }
                }
                while (k >= 0) {
                    board[k][j] = 0;
                    k--;
                }
            }
        }
    }
    return board;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [724. 寻找数组的中心下标](https://leetcode.cn/problems/find-pivot-index){#724}

{{< tabs "724" >}}

{{% tab "python" %}}
```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left, right = 0, sum(nums)
        for i, x in enumerate(nums):
            right -= x
            if left == right:
                return i
            left += x
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int pivotIndex(int[] nums) {
        int left = 0, right = Arrays.stream(nums).sum();
        for (int i = 0; i < nums.length; ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
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
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pivotIndex(nums []int) int {
	var left, right int
	for _, x := range nums {
		right += x
	}
	for i, x := range nums {
		right -= x
		if left == right {
			return i
		}
		left += x
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pivotIndex(nums: number[]): number {
    let left = 0,
        right = nums.reduce((a, b) => a + b);
    for (let i = 0; i < nums.length; ++i) {
        right -= nums[i];
        if (left == right) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let (mut left, mut right): (i32, i32) = (0, nums.iter().sum());
        for i in 0..nums.len() {
            right -= nums[i];
            if left == right {
                return i as i32;
            }
            left += nums[i];
        }
        -1
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
var pivotIndex = function (nums) {
    let left = 0,
        right = nums.reduce((a, b) => a + b);
    for (let i = 0; i < nums.length; ++i) {
        right -= nums[i];
        if (left == right) {
            return i;
        }
        left += nums[i];
    }
    return -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code> ，请计算数组的 <strong>中心下标 </strong>。</p>

<p>数组<strong> 中心下标</strong><strong> </strong>是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。</p>

<p>如果中心下标位于数组最左端，那么左侧数之和视为 <code>0</code> ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。</p>

<p>如果数组有多个中心下标，应该返回 <strong>最靠近左边</strong> 的那一个。如果数组不存在中心下标，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 7, 3, 6, 5, 6]
<strong>输出：</strong>3
<strong>解释：</strong>
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1, 2, 3]
<strong>输出：</strong>-1
<strong>解释：</strong>
数组中不存在满足此条件的中心下标。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2, 1, -1]
<strong>输出：</strong>0
<strong>解释：</strong>
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与主站 1991 题相同：<a href="https://leetcode.cn/problems/find-the-middle-index-in-array/" target="_blank">https://leetcode.cn/problems/find-the-middle-index-in-array/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们定义变量 $left$ 表示数组 $\textit{nums}$ 中下标 $i$ 左侧元素之和，变量 $right$ 表示数组 $\textit{nums}$ 中下标 $i$ 右侧元素之和。初始时 $left = 0$, $right = \sum_{i = 0}^{n - 1} nums[i]$。

遍历数组 $\textit{nums}$，对于当前遍历到的数字 $x$，我们更新 $right = right - x$，此时如果 $left=right$，说明当前下标 $i$ 就是中间位置，直接返回即可。否则，我们更新 $left = left + x$，继续遍历下一个数字。

遍历结束，如果没有找到中间位置，返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

相似题目：

-   [1991. 找到数组的中间位置](https://github.com/doocs/leetcode/blob/main/solution/1900-1999/1991.Find%20the%20Middle%20Index%20in%20Array/README.md)
-   [2574. 左右元素和的差值](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2574.Left%20and%20Right%20Sum%20Differences/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left, right = 0, sum(nums)
        for i, x in enumerate(nums):
            right -= x
            if left == right:
                return i
            left += x
        return -1
```

#### Java

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int left = 0, right = Arrays.stream(nums).sum();
        for (int i = 0; i < nums.length; ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
```

#### Go

```go
func pivotIndex(nums []int) int {
	var left, right int
	for _, x := range nums {
		right += x
	}
	for i, x := range nums {
		right -= x
		if left == right {
			return i
		}
		left += x
	}
	return -1
}
```

#### TypeScript

```ts
function pivotIndex(nums: number[]): number {
    let left = 0,
        right = nums.reduce((a, b) => a + b);
    for (let i = 0; i < nums.length; ++i) {
        right -= nums[i];
        if (left == right) {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let (mut left, mut right): (i32, i32) = (0, nums.iter().sum());
        for i in 0..nums.len() {
            right -= nums[i];
            if left == right {
                return i as i32;
            }
            left += nums[i];
        }
        -1
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function (nums) {
    let left = 0,
        right = nums.reduce((a, b) => a + b);
    for (let i = 0; i < nums.length; ++i) {
        right -= nums[i];
        if (left == right) {
            return i;
        }
        left += nums[i];
    }
    return -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [725. 分隔链表](https://leetcode.cn/problems/split-linked-list-in-parts){#725}

{{< tabs "725" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(
        self, head: Optional[ListNode], k: int
    ) -> List[Optional[ListNode]]:
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        cnt, mod = divmod(n, k)
        ans = [None] * k
        cur = head
        for i in range(k):
            if cur is None:
                break
            ans[i] = cur
            m = cnt + int(i < mod)
            for _ in range(1, m):
                cur = cur.next
            nxt = cur.next
            cur.next = None
            cur = nxt
        return ans
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
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            ++n;
        }
        int cnt = n / k, mod = n % k;
        ListNode[] ans = new ListNode[k];
        ListNode cur = head;
        for (int i = 0; i < k && cur != null; ++i) {
            ans[i] = cur;
            int m = cnt + (i < mod ? 1 : 0);
            for (int j = 1; j < m; ++j) {
                cur = cur.next;
            }
            ListNode nxt = cur.next;
            cur.next = null;
            cur = nxt;
        }
        return ans;
    }
}
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            ++n;
        }
        int cnt = n / k, mod = n % k;
        vector<ListNode*> ans(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            ans[i] = cur;
            int m = cnt + (i < mod ? 1 : 0);
            for (int j = 1; j < m; ++j) {
                cur = cur->next;
            }
            ListNode* nxt = cur->next;
            cur->next = nullptr;
            cur = nxt;
        }
        return ans;
    }
};
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
func splitListToParts(head *ListNode, k int) []*ListNode {
	n := 0
	for cur := head; cur != nil; cur = cur.Next {
		n++
	}

	cnt := n / k
	mod := n % k
	ans := make([]*ListNode, k)
	cur := head

	for i := 0; i < k && cur != nil; i++ {
		ans[i] = cur
		m := cnt
		if i < mod {
			m++
		}
		for j := 1; j < m; j++ {
			cur = cur.Next
		}
		next := cur.Next
		cur.Next = nil
		cur = next
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function splitListToParts(head: ListNode | null, k: number): Array<ListNode | null> {
    let n = 0;
    for (let cur = head; cur !== null; cur = cur.next) {
        n++;
    }
    const cnt = (n / k) | 0;
    const mod = n % k;
    const ans: Array<ListNode | null> = Array(k).fill(null);
    let cur = head;
    for (let i = 0; i < k && cur !== null; i++) {
        ans[i] = cur;
        let m = cnt + (i < mod ? 1 : 0);
        for (let j = 1; j < m; j++) {
            cur = cur.next!;
        }
        let next = cur.next;
        cur.next = null;
        cur = next;
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

<p>给你一个头结点为 <code>head</code> 的单链表和一个整数 <code>k</code> ，请你设计一个算法将链表分隔为 <code>k</code> 个连续的部分。</p>

<p>每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。</p>

<p>这 <code>k</code> 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。</p>

<p>返回一个由上述 <code>k</code> 部分组成的数组。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0725.Split%20Linked%20List%20in%20Parts/images/split1-lc.jpg" style="width: 400px; height: 134px;" />
<pre>
<strong>输入：</strong>head = [1,2,3], k = 5
<strong>输出：</strong>[[1],[2],[3],[],[]]
<strong>解释：</strong>
第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0725.Split%20Linked%20List%20in%20Parts/images/split2-lc.jpg" style="width: 600px; height: 60px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5,6,7,8,9,10], k = 3
<strong>输出：</strong>[[1,2,3,4],[5,6,7],[8,9,10]]
<strong>解释：</strong>
输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 1000]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先遍历链表，得到链表的长度 $n$，然后我们计算出平均长度 $\textit{cnt} = \lfloor \frac{n}{k} \rfloor$ 和余数 $\textit{mod} = n \bmod k$。那么对于前 $\textit{mod}$ 个部分，每个部分的长度为 $\textit{cnt} + 1$，其余部分的长度为 $\textit{cnt}$。

接下来，我们只需要遍历链表，将链表分割成 $k$ 个部分即可。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(
        self, head: Optional[ListNode], k: int
    ) -> List[Optional[ListNode]]:
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        cnt, mod = divmod(n, k)
        ans = [None] * k
        cur = head
        for i in range(k):
            if cur is None:
                break
            ans[i] = cur
            m = cnt + int(i < mod)
            for _ in range(1, m):
                cur = cur.next
            nxt = cur.next
            cur.next = None
            cur = nxt
        return ans
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
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        for (ListNode cur = head; cur != null; cur = cur.next) {
            ++n;
        }
        int cnt = n / k, mod = n % k;
        ListNode[] ans = new ListNode[k];
        ListNode cur = head;
        for (int i = 0; i < k && cur != null; ++i) {
            ans[i] = cur;
            int m = cnt + (i < mod ? 1 : 0);
            for (int j = 1; j < m; ++j) {
                cur = cur.next;
            }
            ListNode nxt = cur.next;
            cur.next = null;
            cur = nxt;
        }
        return ans;
    }
}
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            ++n;
        }
        int cnt = n / k, mod = n % k;
        vector<ListNode*> ans(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            ans[i] = cur;
            int m = cnt + (i < mod ? 1 : 0);
            for (int j = 1; j < m; ++j) {
                cur = cur->next;
            }
            ListNode* nxt = cur->next;
            cur->next = nullptr;
            cur = nxt;
        }
        return ans;
    }
};
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
func splitListToParts(head *ListNode, k int) []*ListNode {
	n := 0
	for cur := head; cur != nil; cur = cur.Next {
		n++
	}

	cnt := n / k
	mod := n % k
	ans := make([]*ListNode, k)
	cur := head

	for i := 0; i < k && cur != nil; i++ {
		ans[i] = cur
		m := cnt
		if i < mod {
			m++
		}
		for j := 1; j < m; j++ {
			cur = cur.Next
		}
		next := cur.Next
		cur.Next = nil
		cur = next
	}

	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function splitListToParts(head: ListNode | null, k: number): Array<ListNode | null> {
    let n = 0;
    for (let cur = head; cur !== null; cur = cur.next) {
        n++;
    }
    const cnt = (n / k) | 0;
    const mod = n % k;
    const ans: Array<ListNode | null> = Array(k).fill(null);
    let cur = head;
    for (let i = 0; i < k && cur !== null; i++) {
        ans[i] = cur;
        let m = cnt + (i < mod ? 1 : 0);
        for (let j = 1; j < m; j++) {
            cur = cur.next!;
        }
        let next = cur.next;
        cur.next = null;
        cur = next;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [726. 原子的数量](https://leetcode.cn/problems/number-of-atoms){#726}

{{< tabs "726" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = new HashMap<>();
        int[] stack = new int[1000];
        int top = 0, multiplier = 1, freq = 0;
        char[] c = formula.toCharArray();
        for (int i = c.length - 1; i >= 0; i--) {
            if (c[i] >= 'a' && c[i] <= 'z') {
                int end = i--;
                while (i >= 0 && c[i] >= 'a' && c[i] <= 'z') i--;
                String key = new String(c, i, end - i + 1);
                map.put(key, map.getOrDefault(key, 0) + Math.max(freq, 1) * multiplier);
                freq = 0;
            } else if (c[i] >= 'A' && c[i] <= 'Z') {
                String key = new String(c, i, 1);
                map.put(key, map.getOrDefault(key, 0) + Math.max(freq, 1) * multiplier);
                freq = 0;
            } else if (c[i] >= '0' && c[i] <= '9') {
                freq = c[i] - '0';
                int p = 10;
                while (i - 1 >= 0 && c[i - 1] >= '0' && c[i - 1] <= '9') {
                    freq += p * (c[--i] - '0');
                    p *= 10;
                }
            } else if (c[i] == ')') {
                stack[top++] = multiplier;
                multiplier *= Math.max(freq, 1);
                freq = 0;
            } else {
                multiplier = stack[--top];
            }
        }
        List<String> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);
        StringBuilder sb = new StringBuilder();
        for (String key : keys) {
            sb.append(key);
            int f = map.get(key);
            if (f > 1) sb.append(f);
        }
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOfAtoms(formula: string): string {
    const getCount = (formula: string, factor = 1) => {
        const n = formula.length;
        const cnt: Record<string, number> = {};
        const s: string[] = [];
        let [atom, c] = ['', 0];

        for (let i = 0; i <= n; i++) {
            if (formula[i] === '(') {
                const stk: string[] = ['('];
                let j = i;
                while (stk.length) {
                    j++;
                    if (formula[j] === '(') stk.push('(');
                    else if (formula[j] === ')') stk.pop();
                }

                const molecule = formula.slice(i + 1, j);
                const nextFactor: string[] = [];

                while (isDigit(formula[++j])) {
                    nextFactor.push(formula[j]);
                }

                const nextC = getCount(molecule, +nextFactor.join('') || 1);
                for (const [atom, c] of Object.entries(nextC)) {
                    cnt[atom] = (cnt[atom] ?? 0) + c * factor;
                }

                i = j - 1;
                continue;
            }

            if (s.length && (!formula[i] || isUpper(formula[i]))) {
                [atom, c] = getAtom(s);

                c *= factor;
                cnt[atom] = (cnt[atom] ?? 0) + c;
                s.length = 0;
            }

            s.push(formula[i]);
        }

        return cnt;
    };

    return Object.entries(getCount(formula))
        .sort(([a], [b]) => a.localeCompare(b))
        .map(([a, b]) => (b > 1 ? a + b : a))
        .join('');
}

const regex = {
    atom: /(\D+)(\d+)?/,
    isUpper: /[A-Z]+/,
};
const getAtom = (s: string[]): [string, number] => {
    const [_, atom, c] = regex.atom.exec(s.join(''))!;
    return [atom, c ? +c : 1];
};
const isDigit = (ch: string) => !Number.isNaN(Number.parseInt(ch));
const isUpper = (ch: string) => regex.isUpper.test(ch);
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} formula
 * @return {string}
 */
var countOfAtoms = function (formula) {
    const getCount = (formula, factor = 1) => {
        const n = formula.length;
        const cnt = {};
        const s = [];
        let [atom, c] = ['', 0];

        for (let i = 0; i <= n; i++) {
            if (formula[i] === '(') {
                const stk = ['('];
                let j = i;
                while (stk.length) {
                    j++;
                    if (formula[j] === '(') stk.push('(');
                    else if (formula[j] === ')') stk.pop();
                }

                const molecule = formula.slice(i + 1, j);
                const nextFactor = [];

                while (isDigit(formula[++j])) {
                    nextFactor.push(formula[j]);
                }

                const nextC = getCount(molecule, +nextFactor.join('') || 1);
                for (const [atom, c] of Object.entries(nextC)) {
                    cnt[atom] = (cnt[atom] ?? 0) + c * factor;
                }

                i = j - 1;
                continue;
            }

            if (s.length && (!formula[i] || isUpper(formula[i]))) {
                [atom, c] = getAtom(s);

                c *= factor;
                cnt[atom] = (cnt[atom] ?? 0) + c;
                s.length = 0;
            }

            s.push(formula[i]);
        }

        return cnt;
    };

    return Object.entries(getCount(formula))
        .sort(([a], [b]) => a.localeCompare(b))
        .map(([a, b]) => (b > 1 ? a + b : a))
        .join('');
};

const regex = {
    atom: /(\D+)(\d+)?/,
    isUpper: /[A-Z]+/,
};
const getAtom = s => {
    const [_, atom, c] = regex.atom.exec(s.join(''));
    return [atom, c ? +c : 1];
};
const isDigit = ch => !Number.isNaN(Number.parseInt(ch));
const isUpper = ch => regex.isUpper.test(ch);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串化学式 <code>formula</code> ，返回 <strong>每种原子的数量</strong> 。</p>

<p>原子总是以一个大写字母开始，接着跟随 0 个或任意个小写字母，表示原子的名字。</p>

<p>如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。</p>

<ul>
	<li>例如，<code>"H2O"</code> 和 <code>"H2O2"</code> 是可行的，但 <code>"H1O2"</code> 这个表达是不可行的。</li>
</ul>

<p>两个化学式连在一起可以构成新的化学式。</p>

<ul>
	<li>例如 <code>"H2O2He3Mg4"</code> 也是化学式。</li>
</ul>

<p>由括号括起的化学式并佐以数字（可选择性添加）也是化学式。</p>

<ul>
	<li>例如 <code>"(H2O2)"</code> 和 <code>"(H2O2)3"</code> 是化学式。</li>
</ul>

<p>返回所有原子的数量，格式为：第一个（按字典序）原子的名字，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>formula = "H2O"
<strong>输出：</strong>"H2O"
<strong>解释：</strong>原子的数量是 {'H': 2, 'O': 1}。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>formula = "Mg(OH)2"
<strong>输出：</strong>"H2MgO2"
<strong>解释：</strong>原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>formula = "K4(ON(SO3)2)2"
<strong>输出：</strong>"K4N2O14S4"
<strong>解释：</strong>原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= formula.length&nbsp;&lt;= 1000</code></li>
	<li><code>formula</code> 由英文字母、数字、<code>'('</code> 和 <code>')'</code> 组成</li>
	<li><code>formula</code> 总是有效的化学式</li>
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

```

#### Java

```java
class Solution {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = new HashMap<>();
        int[] stack = new int[1000];
        int top = 0, multiplier = 1, freq = 0;
        char[] c = formula.toCharArray();
        for (int i = c.length - 1; i >= 0; i--) {
            if (c[i] >= 'a' && c[i] <= 'z') {
                int end = i--;
                while (i >= 0 && c[i] >= 'a' && c[i] <= 'z') i--;
                String key = new String(c, i, end - i + 1);
                map.put(key, map.getOrDefault(key, 0) + Math.max(freq, 1) * multiplier);
                freq = 0;
            } else if (c[i] >= 'A' && c[i] <= 'Z') {
                String key = new String(c, i, 1);
                map.put(key, map.getOrDefault(key, 0) + Math.max(freq, 1) * multiplier);
                freq = 0;
            } else if (c[i] >= '0' && c[i] <= '9') {
                freq = c[i] - '0';
                int p = 10;
                while (i - 1 >= 0 && c[i - 1] >= '0' && c[i - 1] <= '9') {
                    freq += p * (c[--i] - '0');
                    p *= 10;
                }
            } else if (c[i] == ')') {
                stack[top++] = multiplier;
                multiplier *= Math.max(freq, 1);
                freq = 0;
            } else {
                multiplier = stack[--top];
            }
        }
        List<String> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);
        StringBuilder sb = new StringBuilder();
        for (String key : keys) {
            sb.append(key);
            int f = map.get(key);
            if (f > 1) sb.append(f);
        }
        return sb.toString();
    }
}
```

#### C++

```cpp

```

#### Go

```go

```

#### TypeScript

```ts
function countOfAtoms(formula: string): string {
    const getCount = (formula: string, factor = 1) => {
        const n = formula.length;
        const cnt: Record<string, number> = {};
        const s: string[] = [];
        let [atom, c] = ['', 0];

        for (let i = 0; i <= n; i++) {
            if (formula[i] === '(') {
                const stk: string[] = ['('];
                let j = i;
                while (stk.length) {
                    j++;
                    if (formula[j] === '(') stk.push('(');
                    else if (formula[j] === ')') stk.pop();
                }

                const molecule = formula.slice(i + 1, j);
                const nextFactor: string[] = [];

                while (isDigit(formula[++j])) {
                    nextFactor.push(formula[j]);
                }

                const nextC = getCount(molecule, +nextFactor.join('') || 1);
                for (const [atom, c] of Object.entries(nextC)) {
                    cnt[atom] = (cnt[atom] ?? 0) + c * factor;
                }

                i = j - 1;
                continue;
            }

            if (s.length && (!formula[i] || isUpper(formula[i]))) {
                [atom, c] = getAtom(s);

                c *= factor;
                cnt[atom] = (cnt[atom] ?? 0) + c;
                s.length = 0;
            }

            s.push(formula[i]);
        }

        return cnt;
    };

    return Object.entries(getCount(formula))
        .sort(([a], [b]) => a.localeCompare(b))
        .map(([a, b]) => (b > 1 ? a + b : a))
        .join('');
}

const regex = {
    atom: /(\D+)(\d+)?/,
    isUpper: /[A-Z]+/,
};
const getAtom = (s: string[]): [string, number] => {
    const [_, atom, c] = regex.atom.exec(s.join(''))!;
    return [atom, c ? +c : 1];
};
const isDigit = (ch: string) => !Number.isNaN(Number.parseInt(ch));
const isUpper = (ch: string) => regex.isUpper.test(ch);
```

#### JavaScript

```js
/**
 * @param {string} formula
 * @return {string}
 */
var countOfAtoms = function (formula) {
    const getCount = (formula, factor = 1) => {
        const n = formula.length;
        const cnt = {};
        const s = [];
        let [atom, c] = ['', 0];

        for (let i = 0; i <= n; i++) {
            if (formula[i] === '(') {
                const stk = ['('];
                let j = i;
                while (stk.length) {
                    j++;
                    if (formula[j] === '(') stk.push('(');
                    else if (formula[j] === ')') stk.pop();
                }

                const molecule = formula.slice(i + 1, j);
                const nextFactor = [];

                while (isDigit(formula[++j])) {
                    nextFactor.push(formula[j]);
                }

                const nextC = getCount(molecule, +nextFactor.join('') || 1);
                for (const [atom, c] of Object.entries(nextC)) {
                    cnt[atom] = (cnt[atom] ?? 0) + c * factor;
                }

                i = j - 1;
                continue;
            }

            if (s.length && (!formula[i] || isUpper(formula[i]))) {
                [atom, c] = getAtom(s);

                c *= factor;
                cnt[atom] = (cnt[atom] ?? 0) + c;
                s.length = 0;
            }

            s.push(formula[i]);
        }

        return cnt;
    };

    return Object.entries(getCount(formula))
        .sort(([a], [b]) => a.localeCompare(b))
        .map(([a, b]) => (b > 1 ? a + b : a))
        .join('');
};

const regex = {
    atom: /(\D+)(\d+)?/,
    isUpper: /[A-Z]+/,
};
const getAtom = s => {
    const [_, atom, c] = regex.atom.exec(s.join(''));
    return [atom, c ? +c : 1];
};
const isDigit = ch => !Number.isNaN(Number.parseInt(ch));
const isUpper = ch => regex.isUpper.test(ch);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [727. 最小窗口子序列 🔒](https://leetcode.cn/problems/minimum-window-subsequence){#727}

{{< tabs "727" >}}

{{% tab "python" %}}
```python
class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        m, n = len(s1), len(s2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s1, 1):
            for j, b in enumerate(s2, 1):
                if a == b:
                    f[i][j] = i if j == 1 else f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j]
        p, k = 0, m + 1
        for i, a in enumerate(s1, 1):
            if a == s2[n - 1] and f[i][n]:
                j = f[i][n] - 1
                if i - j < k:
                    k = i - j
                    p = j
        return "" if k > m else s1[p : p + k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minWindow(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        int p = 0, k = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1.charAt(i - 1) == s2.charAt(n - 1) && f[i][n] > 0) {
                int j = f[i][n] - 1;
                if (i - j < k) {
                    k = i - j;
                    p = j;
                }
            }
        }
        return k > m ? "" : s1.substring(p, p + k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        int p = 0, k = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s2[n - 1] && f[i][n]) {
                int j = f[i][n] - 1;
                if (i - j < k) {
                    k = i - j;
                    p = j;
                }
            }
        }
        return k > m ? "" : s1.substr(p, k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minWindow(s1 string, s2 string) string {
	m, n := len(s1), len(s2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if s1[i-1] == s2[j-1] {
				if j == 1 {
					f[i][j] = i
				} else {
					f[i][j] = f[i-1][j-1]
				}
			} else {
				f[i][j] = f[i-1][j]
			}
		}
	}
	p, k := 0, m+1
	for i := 1; i <= m; i++ {
		if s1[i-1] == s2[n-1] && f[i][n] > 0 {
			j := f[i][n] - 1
			if i-j < k {
				k = i - j
				p = j
			}
		}
	}
	if k > m {
		return ""
	}
	return s1[p : p+k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minWindow(s1: string, s2: string): string {
    const m = s1.length;
    const n = s2.length;
    const f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (s1[i - 1] === s2[j - 1]) {
                f[i][j] = j === 1 ? i : f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    let p = 0;
    let k = m + 1;
    for (let i = 1; i <= m; ++i) {
        if (s1[i - 1] === s2[n - 1] && f[i][n]) {
            const j = f[i][n] - 1;
            if (i - j < k) {
                k = i - j;
                p = j;
            }
        }
    }
    return k > m ? '' : s1.slice(p, p + k);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定字符串 <code>s1</code> 和&nbsp;<code>s2</code>，找出 <code>s1</code> 中最短的连续&nbsp;<strong>子串</strong>，使得 <code>s2</code> 是该子串的 <strong>子序列</strong> 。</p>

<p>如果 <code>s1</code> 中没有窗口可以包含 <code>s2</code> 中的所有字符，返回空字符串 <code>""</code>。如果有不止一个最短长度的窗口，返回 <strong>开始位置最靠左</strong> 的那个。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
s1 = "abcdebdde", s2 = "bde"
<strong>输出：</strong>"bcde"
<strong>解释：</strong>
"bcde" 是答案，因为它在相同长度的字符串 "bdde" 出现之前。
"deb" 不是一个更短的答案，因为在窗口中必须按顺序出现 T 中的元素。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s1 = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", s2 = "u"
<b>输出：</b>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= s2.length &lt;= 100</code></li>
	<li><code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示字符串 $\textit{s1}$ 的前 $i$ 个字符包含字符串 $\textit{s2}$ 的前 $j$ 个字符时的最短子串的起始位置，如果不存在则为 $0$。

我们可以得到状态转移方程：

$$
f[i][j] = \begin{cases}
i, & j = 1 \textit{ and } s1[i-1] = s2[j] \\
f[i - 1][j - 1], & j > 1 \textit{ and } s1[i-1] = s2[j-1] \\
f[i - 1][j], & s1[i-1] \ne s2[j-1]
\end{cases}
$$

接下来我们只需要遍历 $\textit{s1}$，如果 $f[i][n] \gt 0$，则更新最短子串的起始位置和长度。最后返回最短子串即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为字符串 $\textit{s1}$ 和 $\textit{s2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        m, n = len(s1), len(s2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s1, 1):
            for j, b in enumerate(s2, 1):
                if a == b:
                    f[i][j] = i if j == 1 else f[i - 1][j - 1]
                else:
                    f[i][j] = f[i - 1][j]
        p, k = 0, m + 1
        for i, a in enumerate(s1, 1):
            if a == s2[n - 1] and f[i][n]:
                j = f[i][n] - 1
                if i - j < k:
                    k = i - j
                    p = j
        return "" if k > m else s1[p : p + k]
```

#### Java

```java
class Solution {
    public String minWindow(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        int p = 0, k = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1.charAt(i - 1) == s2.charAt(n - 1) && f[i][n] > 0) {
                int j = f[i][n] - 1;
                if (i - j < k) {
                    k = i - j;
                    p = j;
                }
            }
        }
        return k > m ? "" : s1.substring(p, p + k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    f[i][j] = j == 1 ? i : f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        int p = 0, k = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s2[n - 1] && f[i][n]) {
                int j = f[i][n] - 1;
                if (i - j < k) {
                    k = i - j;
                    p = j;
                }
            }
        }
        return k > m ? "" : s1.substr(p, k);
    }
};
```

#### Go

```go
func minWindow(s1 string, s2 string) string {
	m, n := len(s1), len(s2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if s1[i-1] == s2[j-1] {
				if j == 1 {
					f[i][j] = i
				} else {
					f[i][j] = f[i-1][j-1]
				}
			} else {
				f[i][j] = f[i-1][j]
			}
		}
	}
	p, k := 0, m+1
	for i := 1; i <= m; i++ {
		if s1[i-1] == s2[n-1] && f[i][n] > 0 {
			j := f[i][n] - 1
			if i-j < k {
				k = i - j
				p = j
			}
		}
	}
	if k > m {
		return ""
	}
	return s1[p : p+k]
}
```

#### TypeScript

```ts
function minWindow(s1: string, s2: string): string {
    const m = s1.length;
    const n = s2.length;
    const f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (s1[i - 1] === s2[j - 1]) {
                f[i][j] = j === 1 ? i : f[i - 1][j - 1];
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    let p = 0;
    let k = m + 1;
    for (let i = 1; i <= m; ++i) {
        if (s1[i - 1] === s2[n - 1] && f[i][n]) {
            const j = f[i][n] - 1;
            if (i - j < k) {
                k = i - j;
                p = j;
            }
        }
    }
    return k > m ? '' : s1.slice(p, p + k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [728. 自除数](https://leetcode.cn/problems/self-dividing-numbers){#728}

{{< tabs "728" >}}

{{% tab "python" %}}
```python
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def check(x: int) -> bool:
            y = x
            while y:
                if y % 10 == 0 or x % (y % 10):
                    return False
                y //= 10
            return True

        return [x for x in range(left, right + 1) if check(x)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>();
        for (int x = left; x <= right; ++x) {
            if (check(x)) {
                ans.add(x);
            }
        }
        return ans;
    }

    private boolean check(int x) {
        for (int y = x; y > 0; y /= 10) {
            if (y % 10 == 0 || x % (y % 10) != 0) {
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
    vector<int> selfDividingNumbers(int left, int right) {
        auto check = [&](int x) -> bool {
            for (int y = x; y; y /= 10) {
                if (y % 10 == 0 || x % (y % 10)) {
                    return false;
                }
            }
            return true;
        };
        vector<int> ans;
        for (int x = left; x <= right; ++x) {
            if (check(x)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func selfDividingNumbers(left int, right int) (ans []int) {
	check := func(x int) bool {
		for y := x; y > 0; y /= 10 {
			if y%10 == 0 || x%(y%10) != 0 {
				return false
			}
		}
		return true
	}
	for x := left; x <= right; x++ {
		if check(x) {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function selfDividingNumbers(left: number, right: number): number[] {
    const check = (x: number): boolean => {
        for (let y = x; y; y = Math.floor(y / 10)) {
            if (y % 10 === 0 || x % (y % 10) !== 0) {
                return false;
            }
        }
        return true;
    };
    return Array.from({ length: right - left + 1 }, (_, i) => i + left).filter(check);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        fn check(x: i32) -> bool {
            let mut y = x;
            while y > 0 {
                if y % 10 == 0 || x % (y % 10) != 0 {
                    return false;
                }
                y /= 10;
            }
            true
        }

        (left..=right).filter(|&x| check(x)).collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>自除数</strong><em>&nbsp;</em>是指可以被它包含的每一位数整除的数。</p>

<ul>
	<li>例如，<code>128</code> 是一个 <strong>自除数</strong> ，因为&nbsp;<code>128 % 1 == 0</code>，<code>128 % 2 == 0</code>，<code>128 % 8 == 0</code>。</li>
</ul>

<p><strong>自除数</strong> 不允许包含 0 。</p>

<p>给定两个整数&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code> ，返回一个列表，<em>列表的元素是范围&nbsp;<code>[left, right]</code>（包括两个端点）内所有的 <strong>自除数</strong></em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>left = 1, right = 22
<strong>输出：</strong>[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>left = 47, right = 85
<b>输出：</b>[48,55,66,77]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个函数 $\textit{check}(x)$，用来判断 $x$ 是否是自除数。函数的实现思路如下：

我们用 $y$ 来记录 $x$ 的值，然后不断地对 $y$ 除以 $10$，直到 $y$ 为 $0$。在这个过程中，我们判断 $y$ 的末位是否为 $0$，或者 $x$ 是否不能被 $y$ 的末位整除，如果满足这两个条件中的任意一个，那么 $x$ 就不是自除数，返回 $\text{false}$。否则遍历完所有的位数后，返回 $\text{true}$。

最后，我们遍历区间 $[\textit{left}, \textit{right}]$ 中的所有数，对每个数调用 $\textit{check}(x)$，如果返回 $\text{true}$，那么我们就将这个数加入答案数组中。

时间复杂度 $O(n \times \log_{10} M)$，其中 $n$ 是区间 $[\textit{left}, \textit{right}]$ 中的元素个数，而 $M = \textit{right}$，表示区间中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def check(x: int) -> bool:
            y = x
            while y:
                if y % 10 == 0 or x % (y % 10):
                    return False
                y //= 10
            return True

        return [x for x in range(left, right + 1) if check(x)]
```

#### Java

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>();
        for (int x = left; x <= right; ++x) {
            if (check(x)) {
                ans.add(x);
            }
        }
        return ans;
    }

    private boolean check(int x) {
        for (int y = x; y > 0; y /= 10) {
            if (y % 10 == 0 || x % (y % 10) != 0) {
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
    vector<int> selfDividingNumbers(int left, int right) {
        auto check = [&](int x) -> bool {
            for (int y = x; y; y /= 10) {
                if (y % 10 == 0 || x % (y % 10)) {
                    return false;
                }
            }
            return true;
        };
        vector<int> ans;
        for (int x = left; x <= right; ++x) {
            if (check(x)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func selfDividingNumbers(left int, right int) (ans []int) {
	check := func(x int) bool {
		for y := x; y > 0; y /= 10 {
			if y%10 == 0 || x%(y%10) != 0 {
				return false
			}
		}
		return true
	}
	for x := left; x <= right; x++ {
		if check(x) {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function selfDividingNumbers(left: number, right: number): number[] {
    const check = (x: number): boolean => {
        for (let y = x; y; y = Math.floor(y / 10)) {
            if (y % 10 === 0 || x % (y % 10) !== 0) {
                return false;
            }
        }
        return true;
    };
    return Array.from({ length: right - left + 1 }, (_, i) => i + left).filter(check);
}
```

#### Rust

```rust
impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        fn check(x: i32) -> bool {
            let mut y = x;
            while y > 0 {
                if y % 10 == 0 || x % (y % 10) != 0 {
                    return false;
                }
                y /= 10;
            }
            true
        }

        (left..=right).filter(|&x| check(x)).collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i){#729}

{{< tabs "729" >}}

{{% tab "python" %}}
```python
class MyCalendar:

    def __init__(self):
        self.sd = SortedDict()

    def book(self, start: int, end: int) -> bool:
        idx = self.sd.bisect_right(start)
        if idx < len(self.sd) and self.sd.values()[idx] < end:
            return False
        self.sd[end] = start
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyCalendar {
    private final TreeMap<Integer, Integer> tm = new TreeMap<>();

    public MyCalendar() {
    }

    public boolean book(int startTime, int endTime) {
        var e = tm.ceilingEntry(startTime + 1);
        if (e != null && e.getValue() < endTime) {
            return false;
        }
        tm.put(endTime, startTime);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        auto e = m.lower_bound(startTime + 1);
        if (e != m.end() && e->second < endTime) {
            return false;
        }
        m[endTime] = startTime;
        return true;
    }

private:
    map<int, int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyCalendar struct {
	rbt *redblacktree.Tree
}

func Constructor() MyCalendar {
	return MyCalendar{
		rbt: redblacktree.NewWithIntComparator(),
	}
}

func (this *MyCalendar) Book(startTime int, endTime int) bool {
	if p, ok := this.rbt.Ceiling(startTime + 1); ok && p.Value.(int) < endTime {
		return false
	}
	this.rbt.Put(endTime, startTime)
	return true
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyCalendar {
    tm: TreeMap<number, number>;
    constructor() {
        this.tm = new TreeMap<number, number>();
    }

    book(startTime: number, endTime: number): boolean {
        const e = this.tm.higher(startTime);
        if (e && e[1] < endTime) {
            return false;
        }
        this.tm.set(endTime, startTime);
        return true;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(startTime,endTime)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BTreeMap;

struct MyCalendar {
    tm: BTreeMap<i32, i32>,
}

impl MyCalendar {
    fn new() -> Self {
        MyCalendar {
            tm: BTreeMap::new(),
        }
    }

    fn book(&mut self, start_time: i32, end_time: i32) -> bool {
        if let Some((&key, &value)) = self.tm.range(start_time + 1..).next() {
            if value < end_time {
                return false;
            }
        }
        self.tm.insert(end_time, start_time);
        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var MyCalendar = function () {
    this.tm = new TreeMap();
};

/**
 * @param {number} startTime
 * @param {number} endTime
 * @return {boolean}
 */
MyCalendar.prototype.book = function (startTime, endTime) {
    const e = this.tm.higher(startTime);
    if (e && e[1] < endTime) {
        return false;
    }
    this.tm.set(endTime, startTime);
    return true;
};

var RBTreeNode = class {
    constructor(data) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }
    sibling() {
        if (!this.parent) return null;
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }
    isOnLeft() {
        return this === this.parent.left;
    }
    hasRedChild() {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
};
var RBTree = class {
    constructor(compare = (l, r) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l, r) => compare(l, r) < 0;
    }
    rotateLeft(pt) {
        const right = pt.right;
        pt.right = right.left;
        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;
        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;
        right.left = pt;
        pt.parent = right;
    }
    rotateRight(pt) {
        const left = pt.left;
        pt.left = left.right;
        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;
        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;
        left.right = pt;
        pt.parent = left;
    }
    swapColor(p1, p2) {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }
    swapData(p1, p2) {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }
    fixAfterInsert(pt) {
        var _a;
        let parent = null;
        let grandParent = null;
        while (
            pt !== this.root &&
            pt.color !== 1 &&
            ((_a = pt.parent) == null ? void 0 : _a.color) === 0
        ) {
            parent = pt.parent;
            grandParent = pt.parent.parent;
            if (parent === (grandParent == null ? void 0 : grandParent.left)) {
                const uncle = grandParent.right;
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }
                    this.rotateRight(grandParent);
                    this.swapColor(parent, grandParent);
                    pt = parent;
                }
            } else {
                const uncle = grandParent.left;
                if (uncle != null && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }
                    this.rotateLeft(grandParent);
                    this.swapColor(parent, grandParent);
                    pt = parent;
                }
            }
        }
        this.root.color = 1;
    }
    delete(val) {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }
    deleteAll(val) {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }
    deleteNode(v) {
        const u = BSTreplace(v);
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent;
        if (!u) {
            if (v === this.root) this.root = null;
            else {
                if (uvBlack) {
                    this.fixDoubleBlack(v);
                } else {
                    if (v.sibling()) {
                        v.sibling().color = 0;
                    }
                }
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }
        if (!v.left || !v.right) {
            if (v === this.root) {
                v.data = u.data;
                v.left = v.right = null;
            } else {
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                else u.color = 1;
            }
            return;
        }
        this.swapData(u, v);
        this.deleteNode(u);
        function BSTreplace(x) {
            var _a;
            if (x.left && x.right) return successor(x.right);
            if (!x.left && !x.right) return null;
            return (_a = x.left) != null ? _a : x.right;
        }
        function successor(x) {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }
    fixDoubleBlack(x) {
        if (x === this.root) return;
        const sibling = x.sibling();
        const parent = x.parent;
        if (!sibling) {
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                else this.rotateLeft(parent);
                this.fixDoubleBlack(x);
            } else {
                if (sibling.hasRedChild()) {
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            sibling.right.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            sibling.right.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }
    insert(data) {
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }
    search(predicate, direction) {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result == null ? void 0 : result.data;
    }
    find(data) {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p != null ? p : null;
    }
    count(data) {
        const node = this.find(data);
        return node ? node.count : 0;
    }
    *inOrder(root = this.root) {
        if (!root) return;
        for (const v of this.inOrder(root.left)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right)) yield v;
    }
    *reverseInOrder(root = this.root) {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left)) yield v;
    }
};

// src/treemap.ts
var TreeMap = class {
    constructor(collection = [], compare = (l, r) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.map = new Map();
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }
    size() {
        return this._size;
    }
    has(key) {
        return !!this.tree.find(key);
    }
    get(key) {
        return this.map.get(key);
    }
    set(key, val) {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }
    delete(key) {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }
    ceil(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }
    floor(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }
    higher(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }
    lower(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }
    first() {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }
    last() {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }
    shift() {
        const first = this.first();
        if (first === void 0) return void 0;
        this.delete(first[0]);
        return first;
    }
    pop() {
        const last = this.last();
        if (last === void 0) return void 0;
        this.delete(last[0]);
        return last;
    }
    toKeyValue(key) {
        return key != null ? [key, this.map.get(key)] : void 0;
    }
    *[Symbol.iterator]() {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }
    *keys() {
        for (const key of this.tree.inOrder()) yield key;
    }
    *values() {
        for (const key of this.keys()) yield this.map.get(key);
        return void 0;
    }
    *rkeys() {
        for (const key of this.tree.reverseInOrder()) yield key;
        return void 0;
    }
    *rvalues() {
        for (const key of this.rkeys()) yield this.map.get(key);
        return void 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(startTime,endTime)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>实现一个 <code>MyCalendar</code> 类来存放你的日程安排。如果要添加的日程安排不会造成 <strong>重复预订</strong> ，则可以存储这个新的日程安排。</p>

<p>当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 <strong>重复预订</strong> 。</p>

<p>日程可以用一对整数 <code>startTime</code> 和 <code>endTime</code> 表示，这里的时间是半开区间，即 <code>[startTime, endTime)</code>, 实数&nbsp;<code>x</code> 的范围为， &nbsp;<code>startTime &lt;= x &lt; endTime</code> 。</p>

<p>实现 <code>MyCalendar</code> 类：</p>

<ul>
	<li><code>MyCalendar()</code> 初始化日历对象。</li>
	<li><code>boolean book(int startTime, int endTime)</code> 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 <code>true</code> 。否则，返回 <code>false</code>&nbsp;并且不要将该日程安排添加到日历中。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
<strong>输出：</strong>
[null, true, false, true]

<strong>解释：</strong>
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= start &lt; end &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例，调用 <code>book</code> 方法的次数最多不超过 <code>1000</code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合

我们可以使用有序集合来存储日程安排，有序集合可以在 $O(\log n)$ 的时间内完成插入、删除、查找操作。有序集合中的元素，按照日程安排的 $\textit{endTime}$ 从小到大排序。

调用 $\text{book}(start, end)$ 方法时，我们在有序集合中查找第一个结束时间大于 $\textit{start}$ 的日程安排，如果存在并且其开始时间小于 $\textit{end}$，则说明存在重复预订，返回 $\text{false}$；否则，将 $\textit{end}$ 作为键，将 $\textit{start}$ 作为值插入有序集合中，返回 $\text{true}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为日程安排的数量。

<!-- tabs:start -->

#### Python3

```python
class MyCalendar:

    def __init__(self):
        self.sd = SortedDict()

    def book(self, start: int, end: int) -> bool:
        idx = self.sd.bisect_right(start)
        if idx < len(self.sd) and self.sd.values()[idx] < end:
            return False
        self.sd[end] = start
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
```

#### Java

```java
class MyCalendar {
    private final TreeMap<Integer, Integer> tm = new TreeMap<>();

    public MyCalendar() {
    }

    public boolean book(int startTime, int endTime) {
        var e = tm.ceilingEntry(startTime + 1);
        if (e != null && e.getValue() < endTime) {
            return false;
        }
        tm.put(endTime, startTime);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */
```

#### C++

```cpp
class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        auto e = m.lower_bound(startTime + 1);
        if (e != m.end() && e->second < endTime) {
            return false;
        }
        m[endTime] = startTime;
        return true;
    }

private:
    map<int, int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
```

#### Go

```go
type MyCalendar struct {
	rbt *redblacktree.Tree
}

func Constructor() MyCalendar {
	return MyCalendar{
		rbt: redblacktree.NewWithIntComparator(),
	}
}

func (this *MyCalendar) Book(startTime int, endTime int) bool {
	if p, ok := this.rbt.Ceiling(startTime + 1); ok && p.Value.(int) < endTime {
		return false
	}
	this.rbt.Put(endTime, startTime)
	return true
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */
```

#### TypeScript

```ts
class MyCalendar {
    tm: TreeMap<number, number>;
    constructor() {
        this.tm = new TreeMap<number, number>();
    }

    book(startTime: number, endTime: number): boolean {
        const e = this.tm.higher(startTime);
        if (e && e[1] < endTime) {
            return false;
        }
        this.tm.set(endTime, startTime);
        return true;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(startTime,endTime)
 */
```

#### Rust

```rust
use std::collections::BTreeMap;

struct MyCalendar {
    tm: BTreeMap<i32, i32>,
}

impl MyCalendar {
    fn new() -> Self {
        MyCalendar {
            tm: BTreeMap::new(),
        }
    }

    fn book(&mut self, start_time: i32, end_time: i32) -> bool {
        if let Some((&key, &value)) = self.tm.range(start_time + 1..).next() {
            if value < end_time {
                return false;
            }
        }
        self.tm.insert(end_time, start_time);
        true
    }
}
```

#### JavaScript

```js
var MyCalendar = function () {
    this.tm = new TreeMap();
};

/**
 * @param {number} startTime
 * @param {number} endTime
 * @return {boolean}
 */
MyCalendar.prototype.book = function (startTime, endTime) {
    const e = this.tm.higher(startTime);
    if (e && e[1] < endTime) {
        return false;
    }
    this.tm.set(endTime, startTime);
    return true;
};

var RBTreeNode = class {
    constructor(data) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }
    sibling() {
        if (!this.parent) return null;
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }
    isOnLeft() {
        return this === this.parent.left;
    }
    hasRedChild() {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
};
var RBTree = class {
    constructor(compare = (l, r) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l, r) => compare(l, r) < 0;
    }
    rotateLeft(pt) {
        const right = pt.right;
        pt.right = right.left;
        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;
        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;
        right.left = pt;
        pt.parent = right;
    }
    rotateRight(pt) {
        const left = pt.left;
        pt.left = left.right;
        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;
        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;
        left.right = pt;
        pt.parent = left;
    }
    swapColor(p1, p2) {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }
    swapData(p1, p2) {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }
    fixAfterInsert(pt) {
        var _a;
        let parent = null;
        let grandParent = null;
        while (
            pt !== this.root &&
            pt.color !== 1 &&
            ((_a = pt.parent) == null ? void 0 : _a.color) === 0
        ) {
            parent = pt.parent;
            grandParent = pt.parent.parent;
            if (parent === (grandParent == null ? void 0 : grandParent.left)) {
                const uncle = grandParent.right;
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }
                    this.rotateRight(grandParent);
                    this.swapColor(parent, grandParent);
                    pt = parent;
                }
            } else {
                const uncle = grandParent.left;
                if (uncle != null && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }
                    this.rotateLeft(grandParent);
                    this.swapColor(parent, grandParent);
                    pt = parent;
                }
            }
        }
        this.root.color = 1;
    }
    delete(val) {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }
    deleteAll(val) {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }
    deleteNode(v) {
        const u = BSTreplace(v);
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent;
        if (!u) {
            if (v === this.root) this.root = null;
            else {
                if (uvBlack) {
                    this.fixDoubleBlack(v);
                } else {
                    if (v.sibling()) {
                        v.sibling().color = 0;
                    }
                }
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }
        if (!v.left || !v.right) {
            if (v === this.root) {
                v.data = u.data;
                v.left = v.right = null;
            } else {
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                else u.color = 1;
            }
            return;
        }
        this.swapData(u, v);
        this.deleteNode(u);
        function BSTreplace(x) {
            var _a;
            if (x.left && x.right) return successor(x.right);
            if (!x.left && !x.right) return null;
            return (_a = x.left) != null ? _a : x.right;
        }
        function successor(x) {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }
    fixDoubleBlack(x) {
        if (x === this.root) return;
        const sibling = x.sibling();
        const parent = x.parent;
        if (!sibling) {
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                else this.rotateLeft(parent);
                this.fixDoubleBlack(x);
            } else {
                if (sibling.hasRedChild()) {
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            sibling.right.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            sibling.right.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }
    insert(data) {
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }
    search(predicate, direction) {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result == null ? void 0 : result.data;
    }
    find(data) {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p != null ? p : null;
    }
    count(data) {
        const node = this.find(data);
        return node ? node.count : 0;
    }
    *inOrder(root = this.root) {
        if (!root) return;
        for (const v of this.inOrder(root.left)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right)) yield v;
    }
    *reverseInOrder(root = this.root) {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left)) yield v;
    }
};

// src/treemap.ts
var TreeMap = class {
    constructor(collection = [], compare = (l, r) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.map = new Map();
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }
    size() {
        return this._size;
    }
    has(key) {
        return !!this.tree.find(key);
    }
    get(key) {
        return this.map.get(key);
    }
    set(key, val) {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }
    delete(key) {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }
    ceil(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }
    floor(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }
    higher(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }
    lower(target) {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }
    first() {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }
    last() {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }
    shift() {
        const first = this.first();
        if (first === void 0) return void 0;
        this.delete(first[0]);
        return first;
    }
    pop() {
        const last = this.last();
        if (last === void 0) return void 0;
        this.delete(last[0]);
        return last;
    }
    toKeyValue(key) {
        return key != null ? [key, this.map.get(key)] : void 0;
    }
    *[Symbol.iterator]() {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }
    *keys() {
        for (const key of this.tree.inOrder()) yield key;
    }
    *values() {
        for (const key of this.keys()) yield this.map.get(key);
        return void 0;
    }
    *rkeys() {
        for (const key of this.tree.reverseInOrder()) yield key;
        return void 0;
    }
    *rvalues() {
        for (const key of this.rkeys()) yield this.map.get(key);
        return void 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(startTime,endTime)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

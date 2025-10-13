---
title: "0820_单词的压缩编码"
date: 2025-10-08T18:36:34+08:00
weight: 3
tags: [二分查找, 动态规划, 双指针, 哈希表, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 枚举, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [0820_单词的压缩编码](#820)
#### [字典树](#820)
#### [数组](#820)
#### [哈希表](#820)
#### [字符串](#820)
### [0821_字符的最短距离](#821)
#### [数组](#821)
#### [双指针](#821)
#### [字符串](#821)
### [0822_翻转卡片游戏](#822)
#### [数组](#822)
#### [哈希表](#822)
### [0823_带因子的二叉树](#823)
#### [数组](#823)
#### [哈希表](#823)
#### [动态规划](#823)
#### [排序](#823)
### [0824_山羊拉丁文](#824)
#### [字符串](#824)
### [0825_适龄的朋友](#825)
#### [数组](#825)
#### [双指针](#825)
#### [二分查找](#825)
#### [排序](#825)
### [0826_安排工作以达到最大收益](#826)
#### [贪心](#826)
#### [数组](#826)
#### [双指针](#826)
#### [二分查找](#826)
#### [排序](#826)
### [0827_最大人工岛](#827)
#### [深度优先搜索](#827)
#### [广度优先搜索](#827)
#### [并查集](#827)
#### [数组](#827)
#### [矩阵](#827)
### [0828_统计子串中的唯一字符](#828)
#### [哈希表](#828)
#### [字符串](#828)
#### [动态规划](#828)
### [0829_连续整数求和](#829)
#### [数学](#829)
#### [枚举](#829)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0820_单词的压缩编码
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0821_字符的最短距离
___
#### 数组
___
#### 双指针
___
#### 字符串
---
### 0822_翻转卡片游戏
___
#### 数组
___
#### 哈希表
---
### 0823_带因子的二叉树
___
#### 数组
___
#### 哈希表
___
#### 动态规划
___
#### 排序
---
### 0824_山羊拉丁文
___
#### 字符串
---
### 0825_适龄的朋友
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0826_安排工作以达到最大收益
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0827_最大人工岛
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 0828_统计子串中的唯一字符
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 0829_连续整数求和
___
#### 数学
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 哈希表 | 字典树 | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 枚举 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [820. 单词的压缩编码](https://leetcode.cn/problems/short-encoding-of-words){#820}

{{< tabs "820" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26

    def insert(self, w):
        node = self
        pref = True
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
                pref = False
            node = node.children[idx]
        return 0 if pref else len(w) + 1


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda x: -len(x))
        trie = Trie()
        return sum(trie.insert(w[::-1]) for w in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];

    int insert(String w) {
        Trie node = this;
        boolean pref = true;
        for (int i = w.length() - 1; i >= 0; --i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                pref = false;
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        return pref ? 0 : w.length() + 1;
    }
}

class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (a, b) -> b.length() - a.length());
        int ans = 0;
        Trie trie = new Trie();
        for (String w : words) {
            ans += trie.insert(w);
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
    vector<Trie*> children;
    Trie()
        : children(26) {}

    int insert(string w) {
        Trie* node = this;
        bool pref = true;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                pref = false;
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        return pref ? 0 : w.size() + 1;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) { return a.size() > b.size(); });
        Trie* trie = new Trie();
        int ans = 0;
        for (auto& w : words) {
            reverse(w.begin(), w.end());
            ans += trie->insert(w);
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
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(w string) int {
	node := this
	pref := true
	for i := len(w) - 1; i >= 0; i-- {
		idx := w[i] - 'a'
		if node.children[idx] == nil {
			pref = false
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	if pref {
		return 0
	}
	return len(w) + 1
}

func minimumLengthEncoding(words []string) int {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) > len(words[j]) })
	trie := newTrie()
	ans := 0
	for _, w := range words {
		ans += trie.insert(w)
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

<p>单词数组 <code>words</code> 的 <strong>有效编码</strong> 由任意助记字符串 <code>s</code> 和下标数组 <code>indices</code> 组成，且满足：</p>

<ul>
	<li><code>words.length == indices.length</code></li>
	<li>助记字符串 <code>s</code> 以 <code>'#'</code> 字符结尾</li>
	<li>对于每个下标 <code>indices[i]</code> ，<code>s</code> 的一个从 <code>indices[i]</code> 开始、到下一个 <code>'#'</code> 字符结束（但不包括 <code>'#'</code>）的 <strong>子字符串</strong> 恰好与 <code>words[i]</code> 相等</li>
</ul>

<p>给你一个单词数组 <code>words</code> ，返回成功对 <code>words</code> 进行编码的最小助记字符串 <code>s</code> 的长度 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["time", "me", "bell"]
<strong>输出：</strong>10
<strong>解释：</strong>一组有效编码为 s = <code>"time#bell#" 和 indices = [0, 2, 5</code>] 。
words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "<strong>time</strong>#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "ti<strong>me</strong>#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#<strong>bell</strong>#"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["t"]
<strong>输出：</strong>2
<strong>解释：</strong>一组有效编码为 s = "t#" 和 indices = [0] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 2000</code></li>
	<li><code>1 <= words[i].length <= 7</code></li>
	<li><code>words[i]</code> 仅由小写字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

题目大意：充分利用重叠的后缀，使有效编码尽可能短。

判断当前单词是否是其他单词的后缀，若是，就不用写入助记字符串中，否则需要写入并且加上一个 # 后缀。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self) -> None:
        self.children = [None] * 26


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        root = Trie()
        for w in words:
            cur = root
            for c in w[::-1]:
                idx = ord(c) - ord("a")
                if cur.children[idx] == None:
                    cur.children[idx] = Trie()
                cur = cur.children[idx]
        return self.dfs(root, 1)

    def dfs(self, cur: Trie, l: int) -> int:
        isLeaf, ans = True, 0
        for i in range(26):
            if cur.children[i] != None:
                isLeaf = False
                ans += self.dfs(cur.children[i], l + 1)
        if isLeaf:
            ans += l
        return ans
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
}

class Solution {
    public int minimumLengthEncoding(String[] words) {
        Trie root = new Trie();
        for (String w : words) {
            Trie cur = root;
            for (int i = w.length() - 1; i >= 0; i--) {
                int idx = w.charAt(i) - 'a';
                if (cur.children[idx] == null) {
                    cur.children[idx] = new Trie();
                }
                cur = cur.children[idx];
            }
        }
        return dfs(root, 1);
    }

    private int dfs(Trie cur, int l) {
        boolean isLeaf = true;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cur.children[i] != null) {
                isLeaf = false;
                ans += dfs(cur.children[i], l + 1);
            }
        }
        if (isLeaf) {
            ans += l;
        }
        return ans;
    }
}
```

#### C++

```cpp
struct Trie {
    Trie* children[26] = {nullptr};
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        auto root = new Trie();
        for (auto& w : words) {
            auto cur = root;
            for (int i = w.size() - 1; i >= 0; --i) {
                if (cur->children[w[i] - 'a'] == nullptr) {
                    cur->children[w[i] - 'a'] = new Trie();
                }
                cur = cur->children[w[i] - 'a'];
            }
        }
        return dfs(root, 1);
    }

private:
    int dfs(Trie* cur, int l) {
        bool isLeaf = true;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (cur->children[i] != nullptr) {
                isLeaf = false;
                ans += dfs(cur->children[i], l + 1);
            }
        }
        if (isLeaf) {
            ans += l;
        }
        return ans;
    }
};
```

#### Go

```go
type trie struct {
	children [26]*trie
}

func minimumLengthEncoding(words []string) int {
	root := new(trie)
	for _, w := range words {
		cur := root
		for i := len(w) - 1; i >= 0; i-- {
			if cur.children[w[i]-'a'] == nil {
				cur.children[w[i]-'a'] = new(trie)
			}
			cur = cur.children[w[i]-'a']
		}
	}
	return dfs(root, 1)
}

func dfs(cur *trie, l int) int {
	isLeaf, ans := true, 0
	for i := 0; i < 26; i++ {
		if cur.children[i] != nil {
			isLeaf = false
			ans += dfs(cur.children[i], l+1)
		}
	}
	if isLeaf {
		ans += l
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26

    def insert(self, w):
        node = self
        pref = True
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
                pref = False
            node = node.children[idx]
        return 0 if pref else len(w) + 1


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda x: -len(x))
        trie = Trie()
        return sum(trie.insert(w[::-1]) for w in words)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];

    int insert(String w) {
        Trie node = this;
        boolean pref = true;
        for (int i = w.length() - 1; i >= 0; --i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                pref = false;
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        return pref ? 0 : w.length() + 1;
    }
}

class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (a, b) -> b.length() - a.length());
        int ans = 0;
        Trie trie = new Trie();
        for (String w : words) {
            ans += trie.insert(w);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    Trie()
        : children(26) {}

    int insert(string w) {
        Trie* node = this;
        bool pref = true;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) {
                pref = false;
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        return pref ? 0 : w.size() + 1;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) { return a.size() > b.size(); });
        Trie* trie = new Trie();
        int ans = 0;
        for (auto& w : words) {
            reverse(w.begin(), w.end());
            ans += trie->insert(w);
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(w string) int {
	node := this
	pref := true
	for i := len(w) - 1; i >= 0; i-- {
		idx := w[i] - 'a'
		if node.children[idx] == nil {
			pref = false
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	if pref {
		return 0
	}
	return len(w) + 1
}

func minimumLengthEncoding(words []string) int {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) > len(words[j]) })
	trie := newTrie()
	ans := 0
	for _, w := range words {
		ans += trie.insert(w)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [821. 字符的最短距离](https://leetcode.cn/problems/shortest-distance-to-a-character){#821}

{{< tabs "821" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        ans = [n] * n
        pre = -inf
        for i, ch in enumerate(s):
            if ch == c:
                pre = i
            ans[i] = min(ans[i], i - pre)
        suf = inf
        for i in range(n - 1, -1, -1):
            if s[i] == c:
                suf = i
            ans[i] = min(ans[i], suf - i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] shortestToChar(String s, char c) {
        int n = s.length();
        int[] ans = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(ans, inf);
        for (int i = 0, pre = -inf; i < n; ++i) {
            if (s.charAt(i) == c) {
                pre = i;
            }
            ans[i] = Math.min(ans[i], i - pre);
        }
        for (int i = n - 1, suf = inf; i >= 0; --i) {
            if (s.charAt(i) == c) {
                suf = i;
            }
            ans[i] = Math.min(ans[i], suf - i);
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
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        const int inf = 1 << 30;
        vector<int> ans(n, inf);
        for (int i = 0, pre = -inf; i < n; ++i) {
            if (s[i] == c) {
                pre = i;
            }
            ans[i] = min(ans[i], i - pre);
        }
        for (int i = n - 1, suf = inf; ~i; --i) {
            if (s[i] == c) {
                suf = i;
            }
            ans[i] = min(ans[i], suf - i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestToChar(s string, c byte) []int {
	n := len(s)
	ans := make([]int, n)
	const inf int = 1 << 30
	pre := -inf
	for i := range s {
		if s[i] == c {
			pre = i
		}
		ans[i] = i - pre
	}
	suf := inf
	for i := n - 1; i >= 0; i-- {
		if s[i] == c {
			suf = i
		}
		ans[i] = min(ans[i], suf-i)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestToChar(s: string, c: string): number[] {
    const n = s.length;
    const inf = 1 << 30;
    const ans: number[] = new Array(n).fill(inf);
    for (let i = 0, pre = -inf; i < n; ++i) {
        if (s[i] === c) {
            pre = i;
        }
        ans[i] = i - pre;
    }
    for (let i = n - 1, suf = inf; i >= 0; --i) {
        if (s[i] === c) {
            suf = i;
        }
        ans[i] = Math.min(ans[i], suf - i);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let c = c as u8;
        let s = s.as_bytes();
        let n = s.len();
        let mut res = vec![i32::MAX; n];
        let mut pre = i32::MAX;
        for i in 0..n {
            if s[i] == c {
                pre = i as i32;
            }
            res[i] = i32::abs((i as i32) - pre);
        }
        pre = i32::MAX;
        for i in (0..n).rev() {
            if s[i] == c {
                pre = i as i32;
            }
            res[i] = res[i].min(i32::abs((i as i32) - pre));
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

<p>给你一个字符串 <code>s</code> 和一个字符 <code>c</code> ，且 <code>c</code> 是 <code>s</code> 中出现过的字符。</p>

<p>返回一个整数数组 <code>answer</code> ，其中 <code>answer.length == s.length</code> 且 <code>answer[i]</code> 是 <code>s</code> 中从下标 <code>i</code> 到离它 <strong>最近</strong> 的字符 <code>c</code> 的 <strong>距离</strong> 。</p>

<p>两个下标&nbsp;<code>i</code> 和 <code>j</code> 之间的 <strong>距离</strong> 为 <code>abs(i - j)</code> ，其中 <code>abs</code> 是绝对值函数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "loveleetcode", c = "e"
<strong>输出：</strong>[3,2,1,0,1,0,0,1,2,2,1,0]
<strong>解释：</strong>字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaab", c = "b"
<strong>输出：</strong>[3,2,1,0]
</pre>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> 和 <code>c</code> 均为小写英文字母</li>
	<li>题目数据保证 <code>c</code> 在 <code>s</code> 中至少出现一次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们先创建一个长度为 $n$ 的答案数组 $ans$。

接下来，我们从左到右遍历字符串 $s$，记录最近出现的字符 $c$ 的位置 $pre$，那么对于位置 $i$，答案就是 $i - pre$，即 $ans[i] = i - pre$。

然后，我们从右到左遍历字符串 $s$，记录最近出现的字符 $c$ 的位置 $suf$，那么对于位置 $i$，答案就是 $suf - i$，即 $ans[i] = \min(ans[i], suf - i)$。

最后返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        ans = [n] * n
        pre = -inf
        for i, ch in enumerate(s):
            if ch == c:
                pre = i
            ans[i] = min(ans[i], i - pre)
        suf = inf
        for i in range(n - 1, -1, -1):
            if s[i] == c:
                suf = i
            ans[i] = min(ans[i], suf - i)
        return ans
```

#### Java

```java
class Solution {
    public int[] shortestToChar(String s, char c) {
        int n = s.length();
        int[] ans = new int[n];
        final int inf = 1 << 30;
        Arrays.fill(ans, inf);
        for (int i = 0, pre = -inf; i < n; ++i) {
            if (s.charAt(i) == c) {
                pre = i;
            }
            ans[i] = Math.min(ans[i], i - pre);
        }
        for (int i = n - 1, suf = inf; i >= 0; --i) {
            if (s.charAt(i) == c) {
                suf = i;
            }
            ans[i] = Math.min(ans[i], suf - i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        const int inf = 1 << 30;
        vector<int> ans(n, inf);
        for (int i = 0, pre = -inf; i < n; ++i) {
            if (s[i] == c) {
                pre = i;
            }
            ans[i] = min(ans[i], i - pre);
        }
        for (int i = n - 1, suf = inf; ~i; --i) {
            if (s[i] == c) {
                suf = i;
            }
            ans[i] = min(ans[i], suf - i);
        }
        return ans;
    }
};
```

#### Go

```go
func shortestToChar(s string, c byte) []int {
	n := len(s)
	ans := make([]int, n)
	const inf int = 1 << 30
	pre := -inf
	for i := range s {
		if s[i] == c {
			pre = i
		}
		ans[i] = i - pre
	}
	suf := inf
	for i := n - 1; i >= 0; i-- {
		if s[i] == c {
			suf = i
		}
		ans[i] = min(ans[i], suf-i)
	}
	return ans
}
```

#### TypeScript

```ts
function shortestToChar(s: string, c: string): number[] {
    const n = s.length;
    const inf = 1 << 30;
    const ans: number[] = new Array(n).fill(inf);
    for (let i = 0, pre = -inf; i < n; ++i) {
        if (s[i] === c) {
            pre = i;
        }
        ans[i] = i - pre;
    }
    for (let i = n - 1, suf = inf; i >= 0; --i) {
        if (s[i] === c) {
            suf = i;
        }
        ans[i] = Math.min(ans[i], suf - i);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let c = c as u8;
        let s = s.as_bytes();
        let n = s.len();
        let mut res = vec![i32::MAX; n];
        let mut pre = i32::MAX;
        for i in 0..n {
            if s[i] == c {
                pre = i as i32;
            }
            res[i] = i32::abs((i as i32) - pre);
        }
        pre = i32::MAX;
        for i in (0..n).rev() {
            if s[i] == c {
                pre = i as i32;
            }
            res[i] = res[i].min(i32::abs((i as i32) - pre));
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

# [822. 翻转卡片游戏](https://leetcode.cn/problems/card-flipping-game){#822}

{{< tabs "822" >}}

{{% tab "python" %}}
```python
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        s = {a for a, b in zip(fronts, backs) if a == b}
        return min((x for x in chain(fronts, backs) if x not in s), default=0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> s = new HashSet<>();
        int n = fronts.length;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.add(fronts[i]);
            }
        }
        int ans = 9999;
        for (int v : fronts) {
            if (!s.contains(v)) {
                ans = Math.min(ans, v);
            }
        }
        for (int v : backs) {
            if (!s.contains(v)) {
                ans = Math.min(ans, v);
            }
        }
        return ans % 9999;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        int n = fronts.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.insert(fronts[i]);
            }
        }
        int ans = 9999;
        for (int& v : fronts) {
            if (!s.count(v)) {
                ans = min(ans, v);
            }
        }
        for (int& v : backs) {
            if (!s.count(v)) {
                ans = min(ans, v);
            }
        }
        return ans % 9999;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func flipgame(fronts []int, backs []int) int {
	s := map[int]struct{}{}
	for i, a := range fronts {
		if a == backs[i] {
			s[a] = struct{}{}
		}
	}
	ans := 9999
	for _, v := range fronts {
		if _, ok := s[v]; !ok {
			ans = min(ans, v)
		}
	}
	for _, v := range backs {
		if _, ok := s[v]; !ok {
			ans = min(ans, v)
		}
	}
	return ans % 9999
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function flipgame(fronts: number[], backs: number[]): number {
    const s: Set<number> = new Set();
    const n = fronts.length;
    for (let i = 0; i < n; ++i) {
        if (fronts[i] === backs[i]) {
            s.add(fronts[i]);
        }
    }
    let ans = 9999;
    for (const v of fronts) {
        if (!s.has(v)) {
            ans = Math.min(ans, v);
        }
    }
    for (const v of backs) {
        if (!s.has(v)) {
            ans = Math.min(ans, v);
        }
    }
    return ans % 9999;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
        let n = fronts.len();
        let mut s: HashSet<i32> = HashSet::new();

        for i in 0..n {
            if fronts[i] == backs[i] {
                s.insert(fronts[i]);
            }
        }

        let mut ans = 9999;
        for &v in fronts.iter() {
            if !s.contains(&v) {
                ans = ans.min(v);
            }
        }
        for &v in backs.iter() {
            if !s.contains(&v) {
                ans = ans.min(v);
            }
        }

        if ans == 9999 {
            0
        } else {
            ans
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Flipgame(int[] fronts, int[] backs) {
        var s = new HashSet<int>();
        int n = fronts.Length;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.Add(fronts[i]);
            }
        }
        int ans = 9999;
        for (int i = 0; i < n; ++i) {
            if (!s.Contains(fronts[i])) {
                ans = Math.Min(ans, fronts[i]);
            }
            if (!s.Contains(backs[i])) {
                ans = Math.Min(ans, backs[i]);
            }
        }
        return ans % 9999;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在桌子上有 <code>n</code> 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。</p>

<p>我们可以先翻转任意张卡片，然后选择其中一张卡片。</p>

<p>如果选中的那张卡片背面的数字 <code>x</code> 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。</p>

<p>哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 <code>0</code> 。</p>

<p>其中, <code>fronts[i]</code>&nbsp;和&nbsp;<code>backs[i]</code>&nbsp;分别代表第&nbsp;<code>i</code>&nbsp;张卡片的正面和背面的数字。</p>

<p>如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
<strong>输出：</strong><code>2</code>
<strong>解释：</strong>假设我们翻转第二张卡片，那么在正面的数变成了 <code>[1,3,4,4,7]</code> ， 背面的数变成了 <code>[1,2,4,1,3]。</code>
接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>fronts = [1], backs = [1]
<strong>输出：</strong>0
<strong>解释：</strong>
无论如何翻转都无法得到想要的数字，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == fronts.length == backs.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= fronts[i], backs[i] &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们注意到，对于位置 $i$，若 $\textit{fronts}[i]$ 与 $\textit{backs}[i]$ 元素相同，则一定不满足条件。

因此，我们先找出正面与背面相同的元素，记录在哈希表 $s$ 中。

接下来，遍历正面与背面的元素，若元素 $x$ 不在哈希表 $s$ 中，则更新答案的最小值。

最后，若找到一个满足条件的元素，返回答案，否则返回 $0$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        s = {a for a, b in zip(fronts, backs) if a == b}
        return min((x for x in chain(fronts, backs) if x not in s), default=0)
```

#### Java

```java
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> s = new HashSet<>();
        int n = fronts.length;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.add(fronts[i]);
            }
        }
        int ans = 9999;
        for (int v : fronts) {
            if (!s.contains(v)) {
                ans = Math.min(ans, v);
            }
        }
        for (int v : backs) {
            if (!s.contains(v)) {
                ans = Math.min(ans, v);
            }
        }
        return ans % 9999;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s;
        int n = fronts.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.insert(fronts[i]);
            }
        }
        int ans = 9999;
        for (int& v : fronts) {
            if (!s.count(v)) {
                ans = min(ans, v);
            }
        }
        for (int& v : backs) {
            if (!s.count(v)) {
                ans = min(ans, v);
            }
        }
        return ans % 9999;
    }
};
```

#### Go

```go
func flipgame(fronts []int, backs []int) int {
	s := map[int]struct{}{}
	for i, a := range fronts {
		if a == backs[i] {
			s[a] = struct{}{}
		}
	}
	ans := 9999
	for _, v := range fronts {
		if _, ok := s[v]; !ok {
			ans = min(ans, v)
		}
	}
	for _, v := range backs {
		if _, ok := s[v]; !ok {
			ans = min(ans, v)
		}
	}
	return ans % 9999
}
```

#### TypeScript

```ts
function flipgame(fronts: number[], backs: number[]): number {
    const s: Set<number> = new Set();
    const n = fronts.length;
    for (let i = 0; i < n; ++i) {
        if (fronts[i] === backs[i]) {
            s.add(fronts[i]);
        }
    }
    let ans = 9999;
    for (const v of fronts) {
        if (!s.has(v)) {
            ans = Math.min(ans, v);
        }
    }
    for (const v of backs) {
        if (!s.has(v)) {
            ans = Math.min(ans, v);
        }
    }
    return ans % 9999;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
        let n = fronts.len();
        let mut s: HashSet<i32> = HashSet::new();

        for i in 0..n {
            if fronts[i] == backs[i] {
                s.insert(fronts[i]);
            }
        }

        let mut ans = 9999;
        for &v in fronts.iter() {
            if !s.contains(&v) {
                ans = ans.min(v);
            }
        }
        for &v in backs.iter() {
            if !s.contains(&v) {
                ans = ans.min(v);
            }
        }

        if ans == 9999 {
            0
        } else {
            ans
        }
    }
}
```

#### C#

```cs
public class Solution {
    public int Flipgame(int[] fronts, int[] backs) {
        var s = new HashSet<int>();
        int n = fronts.Length;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                s.Add(fronts[i]);
            }
        }
        int ans = 9999;
        for (int i = 0; i < n; ++i) {
            if (!s.Contains(fronts[i])) {
                ans = Math.Min(ans, fronts[i]);
            }
            if (!s.Contains(backs[i])) {
                ans = Math.Min(ans, backs[i]);
            }
        }
        return ans % 9999;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [823. 带因子的二叉树](https://leetcode.cn/problems/binary-trees-with-factors){#823}

{{< tabs "823" >}}

{{% tab "python" %}}
```python
class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        n = len(arr)
        arr.sort()
        idx = {v: i for i, v in enumerate(arr)}
        f = [1] * n
        for i, a in enumerate(arr):
            for j in range(i):
                b = arr[j]
                if a % b == 0 and (c := (a // b)) in idx:
                    f[i] = (f[i] + f[j] * f[idx[c]]) % mod
        return sum(f) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(arr);
        int n = arr.length;
        long[] f = new long[n];
        Arrays.fill(f, 1);
        Map<Integer, Integer> idx = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            idx.put(arr[i], i);
        }
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            for (int j = 0; j < i; ++j) {
                int b = arr[j];
                if (a % b == 0) {
                    int c = a / b;
                    if (idx.containsKey(c)) {
                        int k = idx.get(c);
                        f[i] = (f[i] + f[j] * f[k]) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (long v : f) {
            ans = (ans + v) % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> idx;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            idx[arr[i]] = i;
        }
        vector<long> f(n, 1);
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            for (int j = 0; j < i; ++j) {
                int b = arr[j];
                if (a % b == 0) {
                    int c = a / b;
                    if (idx.count(c)) {
                        int k = idx[c];
                        f[i] = (f[i] + 1l * f[j] * f[k]) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (long v : f) {
            ans = (ans + v) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numFactoredBinaryTrees(arr []int) int {
	const mod int = 1e9 + 7
	sort.Ints(arr)
	f := make([]int, len(arr))
	idx := map[int]int{}
	for i, v := range arr {
		f[i] = 1
		idx[v] = i
	}
	for i, a := range arr {
		for j := 0; j < i; j++ {
			b := arr[j]
			if c := a / b; a%b == 0 {
				if k, ok := idx[c]; ok {
					f[i] = (f[i] + f[j]*f[k]) % mod
				}
			}
		}
	}
	ans := 0
	for _, v := range f {
		ans = (ans + v) % mod
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numFactoredBinaryTrees(arr: number[]): number {
    const mod = 10 ** 9 + 7;
    arr.sort((a, b) => a - b);
    const idx: Map<number, number> = new Map();
    const n = arr.length;
    for (let i = 0; i < n; ++i) {
        idx.set(arr[i], i);
    }
    const f: number[] = new Array(n).fill(1);
    for (let i = 0; i < n; ++i) {
        const a = arr[i];
        for (let j = 0; j < i; ++j) {
            const b = arr[j];
            if (a % b === 0) {
                const c = a / b;
                if (idx.has(c)) {
                    const k = idx.get(c)!;
                    f[i] = (f[i] + f[j] * f[k]) % mod;
                }
            }
        }
    }
    return f.reduce((a, b) => a + b) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个含有不重复整数元素的数组 <code>arr</code> ，每个整数 <code>arr[i]</code> 均大于 1。</p>

<p>用这些整数来构建二叉树，每个整数可以使用任意次数。其中：每个非叶结点的值应等于它的两个子结点的值的乘积。</p>

<p>满足条件的二叉树一共有多少个？答案可能很大，返回<strong> 对 </strong><code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <code>arr = [2, 4]</code>
<strong>输出:</strong> 3
<strong>解释:</strong> 可以得到这些二叉树: <code>[2], [4], [4, 2, 2]</code></pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> <code>arr = [2, 4, 5, 10]</code>
<strong>输出:</strong> <code>7</code>
<strong>解释:</strong> 可以得到这些二叉树: <code>[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]</code>.</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>2 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>arr</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们可以枚举 $arr$ 中的每一个数 $a$ 作为二叉树的根节点（根节点一定最大），然后枚举枚举左子树的值 $b$，若 $a$ 能被 $b$ 整除，则右子树的值为 $a / b$，若 $a / b$ 也在 $arr$ 中，则可以构成一棵二叉树。此时，以 $a$ 为根节点的二叉树的个数为 $f(a) = f(b) \times f(a / b)$，其中 $f(b)$ 和 $f(a / b)$ 分别为左子树和右子树的二叉树个数。

因此，我们先将 $arr$ 排序，然后用 $f[i]$ 表示以 $arr[i]$ 为根节点的二叉树的个数，最终答案即为 $f[0] + f[1] + \cdots + f[n - 1]$。注意答案可能很大，需要对 $10^9 + 7$ 取模。

时间复杂度为 $O(n^2)$，空间复杂度为 $O(n)$。其中 $n$ 为 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        n = len(arr)
        arr.sort()
        idx = {v: i for i, v in enumerate(arr)}
        f = [1] * n
        for i, a in enumerate(arr):
            for j in range(i):
                b = arr[j]
                if a % b == 0 and (c := (a // b)) in idx:
                    f[i] = (f[i] + f[j] * f[idx[c]]) % mod
        return sum(f) % mod
```

#### Java

```java
class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(arr);
        int n = arr.length;
        long[] f = new long[n];
        Arrays.fill(f, 1);
        Map<Integer, Integer> idx = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            idx.put(arr[i], i);
        }
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            for (int j = 0; j < i; ++j) {
                int b = arr[j];
                if (a % b == 0) {
                    int c = a / b;
                    if (idx.containsKey(c)) {
                        int k = idx.get(c);
                        f[i] = (f[i] + f[j] * f[k]) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (long v : f) {
            ans = (ans + v) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> idx;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            idx[arr[i]] = i;
        }
        vector<long> f(n, 1);
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            for (int j = 0; j < i; ++j) {
                int b = arr[j];
                if (a % b == 0) {
                    int c = a / b;
                    if (idx.count(c)) {
                        int k = idx[c];
                        f[i] = (f[i] + 1l * f[j] * f[k]) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (long v : f) {
            ans = (ans + v) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numFactoredBinaryTrees(arr []int) int {
	const mod int = 1e9 + 7
	sort.Ints(arr)
	f := make([]int, len(arr))
	idx := map[int]int{}
	for i, v := range arr {
		f[i] = 1
		idx[v] = i
	}
	for i, a := range arr {
		for j := 0; j < i; j++ {
			b := arr[j]
			if c := a / b; a%b == 0 {
				if k, ok := idx[c]; ok {
					f[i] = (f[i] + f[j]*f[k]) % mod
				}
			}
		}
	}
	ans := 0
	for _, v := range f {
		ans = (ans + v) % mod
	}
	return ans
}
```

#### TypeScript

```ts
function numFactoredBinaryTrees(arr: number[]): number {
    const mod = 10 ** 9 + 7;
    arr.sort((a, b) => a - b);
    const idx: Map<number, number> = new Map();
    const n = arr.length;
    for (let i = 0; i < n; ++i) {
        idx.set(arr[i], i);
    }
    const f: number[] = new Array(n).fill(1);
    for (let i = 0; i < n; ++i) {
        const a = arr[i];
        for (let j = 0; j < i; ++j) {
            const b = arr[j];
            if (a % b === 0) {
                const c = a / b;
                if (idx.has(c)) {
                    const k = idx.get(c)!;
                    f[i] = (f[i] + f[j] * f[k]) % mod;
                }
            }
        }
    }
    return f.reduce((a, b) => a + b) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [824. 山羊拉丁文](https://leetcode.cn/problems/goat-latin){#824}

{{< tabs "824" >}}

{{% tab "python" %}}
```python
class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        ans = []
        for i, word in enumerate(sentence.split()):
            if word.lower()[0] not in ['a', 'e', 'i', 'o', 'u']:
                word = word[1:] + word[0]
            word += 'ma'
            word += 'a' * (i + 1)
            ans.append(word)
        return ' '.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String toGoatLatin(String sentence) {
        List<String> ans = new ArrayList<>();
        Set<Character> vowels
            = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int i = 1;
        for (String word : sentence.split(" ")) {
            StringBuilder t = new StringBuilder();
            if (!vowels.contains(word.charAt(0))) {
                t.append(word.substring(1));
                t.append(word.charAt(0));
            } else {
                t.append(word);
            }
            t.append("ma");
            for (int j = 0; j < i; ++j) {
                t.append("a");
            }
            ++i;
            ans.add(t.toString());
        }
        return String.join(" ", ans);
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function toGoatLatin(sentence: string): string {
    return sentence
        .split(' ')
        .map((s, i) => {
            let startStr: string;
            if (/[aeiou]/i.test(s[0])) {
                startStr = s;
            } else {
                startStr = s.slice(1) + s[0];
            }
            return `${startStr}ma${'a'.repeat(i + 1)}`;
        })
        .join(' ');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        let set: HashSet<&char> = ['a', 'e', 'i', 'o', 'u'].into_iter().collect();
        sentence
            .split_whitespace()
            .enumerate()
            .map(|(i, s)| {
                let first = char::from(s.as_bytes()[0]);
                let mut res = if set.contains(&first.to_ascii_lowercase()) {
                    s.to_string()
                } else {
                    s[1..].to_string() + &first.to_string()
                };
                res.push_str("ma");
                res.push_str(&"a".repeat(i + 1));
                res
            })
            .into_iter()
            .collect::<Vec<String>>()
            .join(" ")
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由若干单词组成的句子&nbsp;<code>sentence</code> ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。</p>

<p>请你将句子转换为 <em>“</em>山羊拉丁文（<em>Goat Latin</em>）<em>”</em>（一种类似于 猪拉丁文&nbsp;- Pig Latin 的虚构语言）。山羊拉丁文的规则如下：</p>

<ul>
	<li>如果单词以元音开头（<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>），在单词后添加<code>"ma"</code>。

    <ul>
    	<li>例如，单词 <code>"apple"</code> 变为 <code>"applema"</code> 。</li>
    </ul>
    </li>
    <li>如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加<code>"ma"</code>。
    <ul>
    	<li>例如，单词 <code>"goat"</code> 变为 <code>"oatgma"</code> 。</li>
    </ul>
    </li>
    <li>根据单词在句子中的索引，在单词最后添加与索引相同数量的字母<code>'a'</code>，索引从 <code>1</code> 开始。
    <ul>
    	<li>例如，在第一个单词后添加 <code>"a"</code> ，在第二个单词后添加 <code>"aa"</code> ，以此类推。</li>
    </ul>
    </li>

</ul>

<p>返回将 <code>sentence</code> 转换为山羊拉丁文后的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "I speak Goat Latin"
<strong>输出：</strong>"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "The quick brown fox jumped over the lazy dog"
<strong>输出：</strong>"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 150</code></li>
	<li><code>sentence</code> 由英文字母和空格组成</li>
	<li><code>sentence</code> 不含前导或尾随空格</li>
	<li><code>sentence</code> 中的所有单词由单个空格分隔</li>
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
    def toGoatLatin(self, sentence: str) -> str:
        ans = []
        for i, word in enumerate(sentence.split()):
            if word.lower()[0] not in ['a', 'e', 'i', 'o', 'u']:
                word = word[1:] + word[0]
            word += 'ma'
            word += 'a' * (i + 1)
            ans.append(word)
        return ' '.join(ans)
```

#### Java

```java
class Solution {
    public String toGoatLatin(String sentence) {
        List<String> ans = new ArrayList<>();
        Set<Character> vowels
            = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int i = 1;
        for (String word : sentence.split(" ")) {
            StringBuilder t = new StringBuilder();
            if (!vowels.contains(word.charAt(0))) {
                t.append(word.substring(1));
                t.append(word.charAt(0));
            } else {
                t.append(word);
            }
            t.append("ma");
            for (int j = 0; j < i; ++j) {
                t.append("a");
            }
            ++i;
            ans.add(t.toString());
        }
        return String.join(" ", ans);
    }
}
```

#### TypeScript

```ts
function toGoatLatin(sentence: string): string {
    return sentence
        .split(' ')
        .map((s, i) => {
            let startStr: string;
            if (/[aeiou]/i.test(s[0])) {
                startStr = s;
            } else {
                startStr = s.slice(1) + s[0];
            }
            return `${startStr}ma${'a'.repeat(i + 1)}`;
        })
        .join(' ');
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn to_goat_latin(sentence: String) -> String {
        let set: HashSet<&char> = ['a', 'e', 'i', 'o', 'u'].into_iter().collect();
        sentence
            .split_whitespace()
            .enumerate()
            .map(|(i, s)| {
                let first = char::from(s.as_bytes()[0]);
                let mut res = if set.contains(&first.to_ascii_lowercase()) {
                    s.to_string()
                } else {
                    s[1..].to_string() + &first.to_string()
                };
                res.push_str("ma");
                res.push_str(&"a".repeat(i + 1));
                res
            })
            .into_iter()
            .collect::<Vec<String>>()
            .join(" ")
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [825. 适龄的朋友](https://leetcode.cn/problems/friends-of-appropriate-ages){#825}

{{< tabs "825" >}}

{{% tab "python" %}}
```python
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cnt = [0] * 121
        for x in ages:
            cnt[x] += 1
        ans = 0
        for ax, x in enumerate(cnt):
            for ay, y in enumerate(cnt):
                if not (ay <= 0.5 * ax + 7 or ay > ax or (ay > 100 and ax < 100)):
                    ans += x * (y - int(ax == ay))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numFriendRequests(int[] ages) {
        final int m = 121;
        int[] cnt = new int[m];
        for (int x : ages) {
            ++cnt[x];
        }
        int ans = 0;
        for (int ax = 1; ax < m; ++ax) {
            for (int ay = 1; ay < m; ++ay) {
                if (!(ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100))) {
                    ans += cnt[ax] * (cnt[ay] - (ax == ay ? 1 : 0));
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
    int numFriendRequests(vector<int>& ages) {
        const int m = 121;
        vector<int> cnt(m);
        for (int x : ages) {
            ++cnt[x];
        }
        int ans = 0;
        for (int ax = 1; ax < m; ++ax) {
            for (int ay = 1; ay < m; ++ay) {
                if (!(ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100))) {
                    ans += cnt[ax] * (cnt[ay] - (ax == ay ? 1 : 0));
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
func numFriendRequests(ages []int) (ans int) {
	cnt := [121]int{}
	for _, x := range ages {
		cnt[x]++
	}
	for ax, x := range cnt {
		for ay, y := range cnt {
			if ay <= ax/2+7 || ay > ax || (ay > 100 && ax < 100) {
				continue
			}
			if ax == ay {
				ans += x * (x - 1)
			} else {
				ans += x * y
			}
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numFriendRequests(ages: number[]): number {
    const m = 121;
    const cnt = Array(m).fill(0);
    for (const x of ages) {
        cnt[x]++;
    }

    let ans = 0;
    for (let ax = 0; ax < m; ax++) {
        for (let ay = 0; ay < m; ay++) {
            if (ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100)) {
                continue;
            }
            ans += cnt[ax] * (cnt[ay] - (ax === ay ? 1 : 0));
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

<p>在社交媒体网站上有 <code>n</code> 个用户。给你一个整数数组 <code>ages</code> ，其中 <code>ages[i]</code> 是第 <code>i</code> 个用户的年龄。</p>

<p>如果下述任意一个条件为真，那么用户 <code>x</code> 将不会向用户 <code>y</code>（<code>x != y</code>）发送好友请求：</p>

<ul>
	<li><code>ages[y] &lt;= 0.5 * ages[x] + 7</code></li>
	<li><code>ages[y] &gt; ages[x]</code></li>
	<li><code>ages[y] &gt; 100 &amp;&amp; ages[x] &lt; 100</code></li>
</ul>

<p>否则，<code>x</code> 将会向 <code>y</code> 发送一条好友请求。</p>

<p>注意，如果 <code>x</code> 向 <code>y</code> 发送一条好友请求，<code>y</code> 不必也向 <code>x</code> 发送一条好友请求。另外，用户不会向自己发送好友请求。</p>

<p>返回在该社交媒体网站上产生的好友请求总数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ages = [16,16]
<strong>输出：</strong>2
<strong>解释：</strong>2 人互发好友请求。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ages = [16,17,18]
<strong>输出：</strong>2
<strong>解释：</strong>产生的好友请求为 17 -&gt; 16 ，18 -&gt; 17 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ages = [20,30,100,110,120]
<strong>输出：</strong>3
<strong>解释：</strong>产生的好友请求为 110 -&gt; 100 ，120 -&gt; 110 ，120 -&gt; 100 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == ages.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 120</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以用一个长度为 $121$ 的数组 $\textit{cnt}$ 记录每个年龄的人数。

接下来，枚举所有可能的年龄对 $(\textit{ax}, \textit{ay})$，如果 $\textit{ax}$ 和 $\textit{ay}$ 不满足题目中的任意一个条件，这些年龄对 $(\textit{ax}, \textit{ay})$ 就可以互发好友请求。

此时，如果 $\textit{ax} = \textit{ay}$，年龄相同，那么 $\textit{ax}$ 和 $\textit{ay}$ 之间的好友请求数为 $\textit{cnt}[\textit{ax}] \times (\textit{cnt}[\textit{ax}] - 1)$；否则，年龄不同，那么 $\textit{ax}$ 和 $\textit{ay}$ 之间的好友请求数为 $\textit{cnt}[\textit{ax}] \times \textit{cnt}[\textit{ay}]$。我们将这些好友请求数累加到答案中即可。

时间复杂度 $O(n + m^2)$，其中 $n$ 是数组 $\textit{ages}$ 的长度，而 $m$ 是年龄的最大值，本题中 $m = 121$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cnt = [0] * 121
        for x in ages:
            cnt[x] += 1
        ans = 0
        for ax, x in enumerate(cnt):
            for ay, y in enumerate(cnt):
                if not (ay <= 0.5 * ax + 7 or ay > ax or (ay > 100 and ax < 100)):
                    ans += x * (y - int(ax == ay))
        return ans
```

#### Java

```java
class Solution {
    public int numFriendRequests(int[] ages) {
        final int m = 121;
        int[] cnt = new int[m];
        for (int x : ages) {
            ++cnt[x];
        }
        int ans = 0;
        for (int ax = 1; ax < m; ++ax) {
            for (int ay = 1; ay < m; ++ay) {
                if (!(ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100))) {
                    ans += cnt[ax] * (cnt[ay] - (ax == ay ? 1 : 0));
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
    int numFriendRequests(vector<int>& ages) {
        const int m = 121;
        vector<int> cnt(m);
        for (int x : ages) {
            ++cnt[x];
        }
        int ans = 0;
        for (int ax = 1; ax < m; ++ax) {
            for (int ay = 1; ay < m; ++ay) {
                if (!(ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100))) {
                    ans += cnt[ax] * (cnt[ay] - (ax == ay ? 1 : 0));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numFriendRequests(ages []int) (ans int) {
	cnt := [121]int{}
	for _, x := range ages {
		cnt[x]++
	}
	for ax, x := range cnt {
		for ay, y := range cnt {
			if ay <= ax/2+7 || ay > ax || (ay > 100 && ax < 100) {
				continue
			}
			if ax == ay {
				ans += x * (x - 1)
			} else {
				ans += x * y
			}
		}
	}

	return
}
```

#### TypeScript

```ts
function numFriendRequests(ages: number[]): number {
    const m = 121;
    const cnt = Array(m).fill(0);
    for (const x of ages) {
        cnt[x]++;
    }

    let ans = 0;
    for (let ax = 0; ax < m; ax++) {
        for (let ay = 0; ay < m; ay++) {
            if (ay <= 0.5 * ax + 7 || ay > ax || (ay > 100 && ax < 100)) {
                continue;
            }
            ans += cnt[ax] * (cnt[ay] - (ax === ay ? 1 : 0));
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

# [826. 安排工作以达到最大收益](https://leetcode.cn/problems/most-profit-assigning-work){#826}

{{< tabs "826" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        m = max(difficulty)
        f = [0] * (m + 1)
        for d, p in zip(difficulty, profit):
            f[d] = max(f[d], p)
        for i in range(1, m + 1):
            f[i] = max(f[i], f[i - 1])
        return sum(f[min(w, m)] for w in worker)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int m = Arrays.stream(difficulty).max().getAsInt();
        int[] f = new int[m + 1];
        int n = profit.length;
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = Math.max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = Math.max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[Math.min(w, m)];
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = *max_element(begin(difficulty), end(difficulty));
        int f[m + 1];
        memset(f, 0, sizeof(f));
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[min(w, m)];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfitAssignment(difficulty []int, profit []int, worker []int) (ans int) {
	m := slices.Max(difficulty)
	f := make([]int, m+1)
	for i, d := range difficulty {
		f[d] = max(f[d], profit[i])
	}
	for i := 1; i <= m; i++ {
		f[i] = max(f[i], f[i-1])
	}
	for _, w := range worker {
		ans += f[min(w, m)]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfitAssignment(difficulty: number[], profit: number[], worker: number[]): number {
    const m = Math.max(...difficulty);
    const f = Array(m + 1).fill(0);
    const n = profit.length;
    for (let i = 0; i < n; ++i) {
        const d = difficulty[i];
        f[d] = Math.max(f[d], profit[i]);
    }
    for (let i = 1; i <= m; ++i) {
        f[i] = Math.max(f[i], f[i - 1]);
    }
    return worker.reduce((acc, w) => acc + f[Math.min(w, m)], 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有 <code>n</code>&nbsp;个工作和 <code>m</code> 个工人。给定三个数组：&nbsp;<code>difficulty</code>,&nbsp;<code>profit</code>&nbsp;和&nbsp;<code>worker</code>&nbsp;，其中:</p>

<ul>
	<li><code>difficulty[i]</code>&nbsp;表示第 <code>i</code> 个工作的难度，<code>profit[i]</code> 表示第 <code>i</code> 个工作的收益。</li>
	<li><code>worker[i]</code> 是第 <code>i</code> 个工人的能力，即该工人只能完成难度小于等于 <code>worker[i]</code> 的工作。</li>
</ul>

<p>每个工人&nbsp;<strong>最多</strong> 只能安排 <strong>一个</strong> 工作，但是一个工作可以 <strong>完成多次</strong> 。</p>

<ul>
	<li>举个例子，如果 3 个工人都尝试完成一份报酬为 <code>$1</code> 的同样工作，那么总收益为 <code>$3</code>&nbsp;。如果一个工人不能完成任何工作，他的收益为 <code>$0</code> 。</li>
</ul>

<p>返回 <em>在把工人分配到工作岗位后，我们所能获得的最大利润&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
<strong>输出: </strong>100 
<strong>解释: </strong>工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
<strong>输出:</strong> 0</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == difficulty.length</code></li>
	<li><code>n == profit.length</code></li>
	<li><code>m == worker.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= difficulty[i], profit[i], worker[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们可以将工作按照能力升序排列，然后将工作按照难度升序排列。

然后我们遍历工人，对于每个工人，我们找出他能完成的工作中收益最大的那个，然后将这个收益加到答案中。

时间复杂度 $O(n \times \log n + m \times \log m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 `profit` 和 `worker` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        worker.sort()
        jobs = sorted(zip(difficulty, profit))
        ans = mx = i = 0
        for w in worker:
            while i < len(jobs) and jobs[i][0] <= w:
                mx = max(mx, jobs[i][1])
                i += 1
            ans += mx
        return ans
```

#### Java

```java
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        Arrays.sort(worker);
        int n = profit.length;
        int[][] jobs = new int[n][0];
        for (int i = 0; i < n; ++i) {
            jobs[i] = new int[] {difficulty[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        int ans = 0, mx = 0, i = 0;
        for (int w : worker) {
            while (i < n && jobs[i][0] <= w) {
                mx = Math.max(mx, jobs[i++][1]);
            }
            ans += mx;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        int n = profit.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        int ans = 0, mx = 0, i = 0;
        for (int w : worker) {
            while (i < n && jobs[i].first <= w) {
                mx = max(mx, jobs[i++].second);
            }
            ans += mx;
        }
        return ans;
    }
};
```

#### Go

```go
func maxProfitAssignment(difficulty []int, profit []int, worker []int) (ans int) {
	sort.Ints(worker)
	n := len(profit)
	jobs := make([][2]int, n)
	for i, p := range profit {
		jobs[i] = [2]int{difficulty[i], p}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i][0] < jobs[j][0] })
	mx, i := 0, 0
	for _, w := range worker {
		for ; i < n && jobs[i][0] <= w; i++ {
			mx = max(mx, jobs[i][1])
		}
		ans += mx
	}
	return
}
```

#### TypeScript

```ts
function maxProfitAssignment(difficulty: number[], profit: number[], worker: number[]): number {
    const n = profit.length;
    worker.sort((a, b) => a - b);
    const jobs = Array.from({ length: n }, (_, i) => [difficulty[i], profit[i]]);
    jobs.sort((a, b) => a[0] - b[0]);
    let [ans, mx, i] = [0, 0, 0];
    for (const w of worker) {
        while (i < n && jobs[i][0] <= w) {
            mx = Math.max(mx, jobs[i++][1]);
        }
        ans += mx;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们不妨记 $m = \max(\textit{difficulty})$，定义一个长度为 $m + 1$ 的数组 $f$，其中 $f[i]$ 表示难度小于等于 $i$ 的工作中收益的最大值，初始时 $f[i] = 0$。

然后我们遍历工作，对于每个工作 $(d, p)$，我们更新 $f[d] = \max(f[d], p)$。

接下来，我们从 $1$ 到 $m$ 遍历，对于每个 $i$，我们更新 $f[i] = \max(f[i], f[i - 1])$。

最后，我们遍历工人，对于每个工人 $w$，我们将 $f[\min(w, m)]$ 加到答案中。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 `profit` 的长度，而 $M$ 是数组 `difficulty` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        m = max(difficulty)
        f = [0] * (m + 1)
        for d, p in zip(difficulty, profit):
            f[d] = max(f[d], p)
        for i in range(1, m + 1):
            f[i] = max(f[i], f[i - 1])
        return sum(f[min(w, m)] for w in worker)
```

#### Java

```java
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int m = Arrays.stream(difficulty).max().getAsInt();
        int[] f = new int[m + 1];
        int n = profit.length;
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = Math.max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = Math.max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[Math.min(w, m)];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = *max_element(begin(difficulty), end(difficulty));
        int f[m + 1];
        memset(f, 0, sizeof(f));
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[min(w, m)];
        }
        return ans;
    }
};
```

#### Go

```go
func maxProfitAssignment(difficulty []int, profit []int, worker []int) (ans int) {
	m := slices.Max(difficulty)
	f := make([]int, m+1)
	for i, d := range difficulty {
		f[d] = max(f[d], profit[i])
	}
	for i := 1; i <= m; i++ {
		f[i] = max(f[i], f[i-1])
	}
	for _, w := range worker {
		ans += f[min(w, m)]
	}
	return
}
```

#### TypeScript

```ts
function maxProfitAssignment(difficulty: number[], profit: number[], worker: number[]): number {
    const m = Math.max(...difficulty);
    const f = Array(m + 1).fill(0);
    const n = profit.length;
    for (let i = 0; i < n; ++i) {
        const d = difficulty[i];
        f[d] = Math.max(f[d], profit[i]);
    }
    for (let i = 1; i <= m; ++i) {
        f[i] = Math.max(f[i], f[i - 1]);
    }
    return worker.reduce((acc, w) => acc + f[Math.min(w, m)], 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [827. 最大人工岛](https://leetcode.cn/problems/making-a-large-island){#827}

{{< tabs "827" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int):
            p[i][j] = root
            cnt[root] += 1
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] and p[x][y] == 0:
                    dfs(x, y)

        n = len(grid)
        cnt = Counter()
        p = [[0] * n for _ in range(n)]
        dirs = (-1, 0, 1, 0, -1)
        root = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x and p[i][j] == 0:
                    root += 1
                    dfs(i, j)
        ans = max(cnt.values() or [0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 0:
                    s = set()
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        if 0 <= x < n and 0 <= y < n:
                            s.add(p[x][y])
                    ans = max(ans, sum(cnt[root] for root in s) + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int root;
    private int[] cnt;
    private int[][] p;
    private int[][] grid;
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public int largestIsland(int[][] grid) {
        n = grid.length;
        p = new int[n][n];
        this.grid = grid;
        cnt = new int[n * n + 1];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && p[i][j] == 0) {
                    ++root;
                    ans = Math.max(ans, dfs(i, j));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    Set<Integer> s = new HashSet<>();
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            s.add(p[x][y]);
                        }
                    }
                    int t = 1;
                    for (int x : s) {
                        t += cnt[x];
                    }
                    ans = Math.max(ans, t);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        p[i][j] = root;
        ++cnt[root];
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && p[x][y] == 0) {
                dfs(x, y);
            }
        }
        return cnt[root];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int p[n][n];
        memset(p, 0, sizeof(p));
        int cnt[n * n + 1];
        memset(cnt, 0, sizeof(cnt));
        const int dirs[5] = {-1, 0, 1, 0, -1};
        int root = 0;
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            p[i][j] = root;
            ++cnt[root];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && !p[x][y]) {
                    dfs(x, y);
                }
            }
            return cnt[root];
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !p[i][j]) {
                    ++root;
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    unordered_set<int> s;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            s.insert(p[x][y]);
                        }
                    }
                    int t = 1;
                    for (int x : s) {
                        t += cnt[x];
                    }
                    ans = max(ans, t);
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
func largestIsland(grid [][]int) int {
	n := len(grid)
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}
	cnt := make([]int, n*n+1)
	dirs := []int{-1, 0, 1, 0, -1}
	root := 0
	ans := 0

	var dfs func(int, int) int
	dfs = func(i, j int) int {
		p[i][j] = root
		cnt[root]++
		for k := 0; k < 4; k++ {
			x := i + dirs[k]
			y := j + dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && p[x][y] == 0 {
				dfs(x, y)
			}
		}
		return cnt[root]
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 && p[i][j] == 0 {
				root++
				ans = max(ans, dfs(i, j))
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				s := make(map[int]struct{})
				for k := 0; k < 4; k++ {
					x := i + dirs[k]
					y := j + dirs[k+1]
					if x >= 0 && x < n && y >= 0 && y < n {
						s[p[x][y]] = struct{}{}
					}
				}
				t := 1
				for x := range s {
					t += cnt[x]
				}
				ans = max(ans, t)
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestIsland(grid: number[][]): number {
    const n = grid.length;
    const p = Array.from({ length: n }, () => Array(n).fill(0));
    const cnt = Array(n * n + 1).fill(0);
    const dirs = [-1, 0, 1, 0, -1];
    let root = 0;
    let ans = 0;

    const dfs = (i: number, j: number): number => {
        p[i][j] = root;
        cnt[root]++;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] === 1 && p[x][y] === 0) {
                dfs(x, y);
            }
        }
        return cnt[root];
    };

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1 && p[i][j] === 0) {
                root++;
                ans = Math.max(ans, dfs(i, j));
            }
        }
    }

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                const s = new Set<number>();
                for (let k = 0; k < 4; ++k) {
                    const x = i + dirs[k];
                    const y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        s.add(p[x][y]);
                    }
                }
                let t = 1;
                for (const x of s) {
                    t += cnt[x];
                }
                ans = Math.max(ans, t);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut p = vec![vec![0; n]; n];
        let mut cnt = vec![0; n * n + 1];
        let dirs = [-1, 0, 1, 0, -1];
        let mut root = 0;
        let mut ans = 0;

        fn dfs(
            grid: &Vec<Vec<i32>>,
            p: &mut Vec<Vec<i32>>,
            cnt: &mut Vec<i32>,
            root: i32,
            i: usize,
            j: usize,
            dirs: &[i32; 5],
        ) -> i32 {
            p[i][j] = root;
            cnt[root as usize] += 1;
            for k in 0..4 {
                let x = (i as i32) + dirs[k];
                let y = (j as i32) + dirs[k + 1];
                if x >= 0
                    && (x as usize) < grid.len()
                    && y >= 0
                    && (y as usize) < grid.len()
                    && grid[x as usize][y as usize] == 1
                    && p[x as usize][y as usize] == 0
                {
                    dfs(grid, p, cnt, root, x as usize, y as usize, dirs);
                }
            }
            cnt[root as usize]
        }

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 && p[i][j] == 0 {
                    root += 1;
                    ans = ans.max(dfs(&grid, &mut p, &mut cnt, root, i, j, &dirs));
                }
            }
        }

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 0 {
                    let mut s = HashSet::new();
                    for k in 0..4 {
                        let x = (i as i32) + dirs[k];
                        let y = (j as i32) + dirs[k + 1];
                        if x >= 0 && (x as usize) < n && y >= 0 && (y as usize) < n {
                            s.insert(p[x as usize][y as usize]);
                        }
                    }
                    let mut t = 1;
                    for &x in &s {
                        t += cnt[x as usize];
                    }
                    ans = ans.max(t);
                }
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

<p>给你一个大小为 <code>n x n</code> 二进制矩阵 <code>grid</code> 。<strong>最多</strong> 只能将一格&nbsp;<code>0</code> 变成&nbsp;<code>1</code> 。</p>

<p>返回执行此操作后，<code>grid</code> 中最大的岛屿面积是多少？</p>

<p><strong>岛屿</strong> 由一组上、下、左、右四个方向相连的&nbsp;<code>1</code> 形成。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入: </strong>grid = [[1, 0], [0, 1]]
<strong>输出:</strong> 3
<strong>解释:</strong> 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入: </strong>grid =<strong> </strong>[[1, 1], [1, 0]]
<strong>输出:</strong> 4
<strong>解释:</strong> 将一格0变成1，岛屿的面积扩大为 4。</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入: </strong>grid = [[1, 1], [1, 1]]
<strong>输出:</strong> 4
<strong>解释:</strong> 没有0可以让我们变成1，面积依然为 4。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以给每个连通块一个唯一的标识，用数组 $p$ 记录每个位置所属的连通块，即 $p[i][j]$ 表示 $(i, j)$ 所属的连通块编号。用数组 $cnt$ 记录每个连通块的大小，即 $cnt[root]$ 表示连通块 $root$ 的大小。

首先，我们遍历整个矩阵，对于每个 $grid[i][j] = 1$ 且 $p[i][j] = 0$ 的位置，我们对其进行深度优先搜索，将其所属的连通块标记为 $root$，并统计连通块的大小。

接着，我们遍历整个矩阵，对于每个 $grid[i][j] = 0$ 的位置，我们找到其上、下、左、右四个位置所属的连通块，将这些连通块的大小相加，再加上当前位置的 $1$，即可得到将当前位置变为 $1$ 后的最大岛屿面积。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为矩阵的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int):
            p[i][j] = root
            cnt[root] += 1
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] and p[x][y] == 0:
                    dfs(x, y)

        n = len(grid)
        cnt = Counter()
        p = [[0] * n for _ in range(n)]
        dirs = (-1, 0, 1, 0, -1)
        root = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x and p[i][j] == 0:
                    root += 1
                    dfs(i, j)
        ans = max(cnt.values() or [0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 0:
                    s = set()
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        if 0 <= x < n and 0 <= y < n:
                            s.add(p[x][y])
                    ans = max(ans, sum(cnt[root] for root in s) + 1)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int root;
    private int[] cnt;
    private int[][] p;
    private int[][] grid;
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public int largestIsland(int[][] grid) {
        n = grid.length;
        p = new int[n][n];
        this.grid = grid;
        cnt = new int[n * n + 1];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && p[i][j] == 0) {
                    ++root;
                    ans = Math.max(ans, dfs(i, j));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    Set<Integer> s = new HashSet<>();
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            s.add(p[x][y]);
                        }
                    }
                    int t = 1;
                    for (int x : s) {
                        t += cnt[x];
                    }
                    ans = Math.max(ans, t);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        p[i][j] = root;
        ++cnt[root];
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && p[x][y] == 0) {
                dfs(x, y);
            }
        }
        return cnt[root];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int p[n][n];
        memset(p, 0, sizeof(p));
        int cnt[n * n + 1];
        memset(cnt, 0, sizeof(cnt));
        const int dirs[5] = {-1, 0, 1, 0, -1};
        int root = 0;
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) {
            p[i][j] = root;
            ++cnt[root];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && !p[x][y]) {
                    dfs(x, y);
                }
            }
            return cnt[root];
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && !p[i][j]) {
                    ++root;
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    unordered_set<int> s;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            s.insert(p[x][y]);
                        }
                    }
                    int t = 1;
                    for (int x : s) {
                        t += cnt[x];
                    }
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestIsland(grid [][]int) int {
	n := len(grid)
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}
	cnt := make([]int, n*n+1)
	dirs := []int{-1, 0, 1, 0, -1}
	root := 0
	ans := 0

	var dfs func(int, int) int
	dfs = func(i, j int) int {
		p[i][j] = root
		cnt[root]++
		for k := 0; k < 4; k++ {
			x := i + dirs[k]
			y := j + dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && p[x][y] == 0 {
				dfs(x, y)
			}
		}
		return cnt[root]
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 && p[i][j] == 0 {
				root++
				ans = max(ans, dfs(i, j))
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				s := make(map[int]struct{})
				for k := 0; k < 4; k++ {
					x := i + dirs[k]
					y := j + dirs[k+1]
					if x >= 0 && x < n && y >= 0 && y < n {
						s[p[x][y]] = struct{}{}
					}
				}
				t := 1
				for x := range s {
					t += cnt[x]
				}
				ans = max(ans, t)
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function largestIsland(grid: number[][]): number {
    const n = grid.length;
    const p = Array.from({ length: n }, () => Array(n).fill(0));
    const cnt = Array(n * n + 1).fill(0);
    const dirs = [-1, 0, 1, 0, -1];
    let root = 0;
    let ans = 0;

    const dfs = (i: number, j: number): number => {
        p[i][j] = root;
        cnt[root]++;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] === 1 && p[x][y] === 0) {
                dfs(x, y);
            }
        }
        return cnt[root];
    };

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1 && p[i][j] === 0) {
                root++;
                ans = Math.max(ans, dfs(i, j));
            }
        }
    }

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                const s = new Set<number>();
                for (let k = 0; k < 4; ++k) {
                    const x = i + dirs[k];
                    const y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        s.add(p[x][y]);
                    }
                }
                let t = 1;
                for (const x of s) {
                    t += cnt[x];
                }
                ans = Math.max(ans, t);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut p = vec![vec![0; n]; n];
        let mut cnt = vec![0; n * n + 1];
        let dirs = [-1, 0, 1, 0, -1];
        let mut root = 0;
        let mut ans = 0;

        fn dfs(
            grid: &Vec<Vec<i32>>,
            p: &mut Vec<Vec<i32>>,
            cnt: &mut Vec<i32>,
            root: i32,
            i: usize,
            j: usize,
            dirs: &[i32; 5],
        ) -> i32 {
            p[i][j] = root;
            cnt[root as usize] += 1;
            for k in 0..4 {
                let x = (i as i32) + dirs[k];
                let y = (j as i32) + dirs[k + 1];
                if x >= 0
                    && (x as usize) < grid.len()
                    && y >= 0
                    && (y as usize) < grid.len()
                    && grid[x as usize][y as usize] == 1
                    && p[x as usize][y as usize] == 0
                {
                    dfs(grid, p, cnt, root, x as usize, y as usize, dirs);
                }
            }
            cnt[root as usize]
        }

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 && p[i][j] == 0 {
                    root += 1;
                    ans = ans.max(dfs(&grid, &mut p, &mut cnt, root, i, j, &dirs));
                }
            }
        }

        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 0 {
                    let mut s = HashSet::new();
                    for k in 0..4 {
                        let x = (i as i32) + dirs[k];
                        let y = (j as i32) + dirs[k + 1];
                        if x >= 0 && (x as usize) < n && y >= 0 && (y as usize) < n {
                            s.insert(p[x as usize][y as usize]);
                        }
                    }
                    let mut t = 1;
                    for &x in &s {
                        t += cnt[x as usize];
                    }
                    ans = ans.max(t);
                }
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

# [828. 统计子串中的唯一字符](https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string){#828}

{{< tabs "828" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
        ans = 0
        for v in d.values():
            v = [-1] + v + [len(s)]
            for i in range(1, len(v) - 1):
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int uniqueLetterString(String s) {
        List<Integer>[] d = new List[26];
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int i = 0; i < 26; ++i) {
            d[i].add(-1);
        }
        for (int i = 0; i < s.length(); ++i) {
            d[s.charAt(i) - 'A'].add(i);
        }
        int ans = 0;
        for (var v : d) {
            v.add(s.length());
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += (v.get(i) - v.get(i - 1)) * (v.get(i + 1) - v.get(i));
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
    int uniqueLetterString(string s) {
        vector<vector<int>> d(26, {-1});
        for (int i = 0; i < s.size(); ++i) {
            d[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (auto& v : d) {
            v.push_back(s.size());
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uniqueLetterString(s string) (ans int) {
	d := make([][]int, 26)
	for i := range d {
		d[i] = []int{-1}
	}
	for i, c := range s {
		d[c-'A'] = append(d[c-'A'], i)
	}
	for _, v := range d {
		v = append(v, len(s))
		for i := 1; i < len(v)-1; i++ {
			ans += (v[i] - v[i-1]) * (v[i+1] - v[i])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uniqueLetterString(s: string): number {
    const d: number[][] = Array.from({ length: 26 }, () => [-1]);
    for (let i = 0; i < s.length; ++i) {
        d[s.charCodeAt(i) - 'A'.charCodeAt(0)].push(i);
    }
    let ans = 0;
    for (const v of d) {
        v.push(s.length);

        for (let i = 1; i < v.length - 1; ++i) {
            ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let mut d: Vec<Vec<i32>> = vec![vec![-1; 1]; 26];
        for (i, c) in s.chars().enumerate() {
            d[(c as usize) - ('A' as usize)].push(i as i32);
        }
        let mut ans = 0;
        for v in d.iter_mut() {
            v.push(s.len() as i32);
            for i in 1..v.len() - 1 {
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们定义了一个函数 <code>countUniqueChars(s)</code> 来统计字符串 <code>s</code> 中的唯一字符，并返回唯一字符的个数。</p>

<p>例如：<code>s = "LEETCODE"</code> ，则其中 <code>"L"</code>, <code>"T"</code>,<code>"C"</code>,<code>"O"</code>,<code>"D"</code> 都是唯一字符，因为它们只出现一次，所以 <code>countUniqueChars(s) = 5</code> 。</p>

<p>本题将会给你一个字符串 <code>s</code> ，我们需要返回 <code>countUniqueChars(t)</code> 的总和，其中 <code>t</code> 是 <code>s</code> 的子字符串。输入用例保证返回值为&nbsp;32 位整数。</p>

<p>注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 <code>s</code> 的所有子字符串中的唯一字符）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入: </strong>s = "ABC"
<strong>输出: </strong>10
<strong>解释:</strong> 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
     其中，每一个子串都由独特字符构成。
     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入: </strong>s = "ABA"
<strong>输出: </strong>8
<strong>解释: </strong>除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "LEETCODE"
<strong>输出：</strong>92
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 只包含大写英文字符</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计算每个字符的贡献

对于字符串 $s$ 的每个字符 $c_i$，当它在某个子字符串中仅出现一次时，它会对这个子字符串统计唯一字符时有贡献。

因此，我们只需要对每个字符 $c_i$，计算有多少子字符串仅包含该字符一次即可。

我们用一个哈希表或者长度为 $26$ 的数组 $d$，按照下标顺序存储每个字符在 $s$ 中所有出现的位置。

对于每个字符 $c_i$，我们遍历 $d[c_i]$ 中的每个位置 $p$，找出左侧相邻的位置 $l$ 和右侧相邻的位置 $r$，那么从位置 $p$ 向左右两边扩散，满足要求的子字符串的数量就是 $(p - l) \times (r - p)$。我们对每个字符都进行这样的操作，累加所有字符的贡献，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
        ans = 0
        for v in d.values():
            v = [-1] + v + [len(s)]
            for i in range(1, len(v) - 1):
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i])
        return ans
```

#### Java

```java
class Solution {
    public int uniqueLetterString(String s) {
        List<Integer>[] d = new List[26];
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int i = 0; i < 26; ++i) {
            d[i].add(-1);
        }
        for (int i = 0; i < s.length(); ++i) {
            d[s.charAt(i) - 'A'].add(i);
        }
        int ans = 0;
        for (var v : d) {
            v.add(s.length());
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += (v.get(i) - v.get(i - 1)) * (v.get(i + 1) - v.get(i));
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
    int uniqueLetterString(string s) {
        vector<vector<int>> d(26, {-1});
        for (int i = 0; i < s.size(); ++i) {
            d[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (auto& v : d) {
            v.push_back(s.size());
            for (int i = 1; i < v.size() - 1; ++i) {
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func uniqueLetterString(s string) (ans int) {
	d := make([][]int, 26)
	for i := range d {
		d[i] = []int{-1}
	}
	for i, c := range s {
		d[c-'A'] = append(d[c-'A'], i)
	}
	for _, v := range d {
		v = append(v, len(s))
		for i := 1; i < len(v)-1; i++ {
			ans += (v[i] - v[i-1]) * (v[i+1] - v[i])
		}
	}
	return
}
```

#### TypeScript

```ts
function uniqueLetterString(s: string): number {
    const d: number[][] = Array.from({ length: 26 }, () => [-1]);
    for (let i = 0; i < s.length; ++i) {
        d[s.charCodeAt(i) - 'A'.charCodeAt(0)].push(i);
    }
    let ans = 0;
    for (const v of d) {
        v.push(s.length);

        for (let i = 1; i < v.length - 1; ++i) {
            ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let mut d: Vec<Vec<i32>> = vec![vec![-1; 1]; 26];
        for (i, c) in s.chars().enumerate() {
            d[(c as usize) - ('A' as usize)].push(i as i32);
        }
        let mut ans = 0;
        for v in d.iter_mut() {
            v.push(s.len() as i32);
            for i in 1..v.len() - 1 {
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [829. 连续整数求和](https://leetcode.cn/problems/consecutive-numbers-sum){#829}

{{< tabs "829" >}}

{{% tab "python" %}}
```python
class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        n <<= 1
        ans, k = 0, 1
        while k * (k + 1) <= n:
            if n % k == 0 and (n // k + 1 - k) % 2 == 0:
                ans += 1
            k += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public int consecutiveNumbersSum(int n) {
        n <<= 1;
        int ans = 0;
        for (int k = 1; k * (k + 1) <= n; ++k) {
            if (n % k == 0 && (n / k + 1 - k) % 2 == 0) {
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
    int consecutiveNumbersSum(int n) {
        n <<= 1;
        int ans = 0;
        for (int k = 1; k * (k + 1) <= n; ++k) {
            if (n % k == 0 && (n / k + 1 - k) % 2 == 0) {
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
func consecutiveNumbersSum(n int) int {
	n <<= 1
	ans := 0
	for k := 1; k*(k+1) <= n; k++ {
		if n%k == 0 && (n/k+1-k)%2 == 0 {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function consecutiveNumbersSum(n: number): number {
    let ans = 0;
    n <<= 1;
    for (let k = 1; k * (k + 1) <= n; ++k) {
        if (n % k === 0 && (Math.floor(n / k) + 1 - k) % 2 === 0) {
            ++ans;
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

<p>给定一个正整数 <code>n</code>，返回 <em>连续正整数满足所有数字之和为 <code>n</code>&nbsp;的组数</em> 。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示</strong><strong>例 1:</strong></p>

<pre>
<strong>输入: </strong>n = 5
<strong>输出: </strong>2
<strong>解释: </strong>5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>n = 9
<strong>输出: </strong>3
<strong>解释: </strong>9 = 4 + 5 = 2 + 3 + 4</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>n = 15
<strong>输出: </strong>4
<strong>解释: </strong>15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code>​​​​​​​</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学推导

连续正整数构成一个公差 $d = 1$ 的等差数列。我们假设等差数列的第一项为 $a$，项数为 $k$，那么 $n = (a + a + k - 1) \times k / 2$，即 $n \times 2 = (a \times 2 + k - 1) \times k$。这里我们可以得出 $k$ 一定能整除 $n \times 2$，并且 $(n \times 2) / k - k + 1$ 一定是偶数。

由于 $a \geq 1$，所以 $n \times 2 = (a \times 2 + k - 1) \times k \geq k \times (k + 1)$。

综上，我们可以得出：

1. $k$ 一定能整除 $n \times 2$；
2. $k \times (k + 1) \leq n \times 2$；
3. $(n \times 2) / k - k + 1$ 一定是偶数。

我们从 $k = 1$ 开始枚举，当 $k \times (k + 1) > n \times 2$ 时，我们可以结束枚举。在枚举的过程中，我们判断 $k$ 是否能整除 $n \times 2$，并且 $(n \times 2) / k - k + 1$ 是否是偶数，如果是则满足条件，答案加一。

枚举结束后，返回答案即可。

时间复杂度 $O(\sqrt{n})$，其中 $n$ 为给定的正整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        n <<= 1
        ans, k = 0, 1
        while k * (k + 1) <= n:
            if n % k == 0 and (n // k + 1 - k) % 2 == 0:
                ans += 1
            k += 1
        return ans
```

#### Java

```java
class Solution {

    public int consecutiveNumbersSum(int n) {
        n <<= 1;
        int ans = 0;
        for (int k = 1; k * (k + 1) <= n; ++k) {
            if (n % k == 0 && (n / k + 1 - k) % 2 == 0) {
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
    int consecutiveNumbersSum(int n) {
        n <<= 1;
        int ans = 0;
        for (int k = 1; k * (k + 1) <= n; ++k) {
            if (n % k == 0 && (n / k + 1 - k) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func consecutiveNumbersSum(n int) int {
	n <<= 1
	ans := 0
	for k := 1; k*(k+1) <= n; k++ {
		if n%k == 0 && (n/k+1-k)%2 == 0 {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function consecutiveNumbersSum(n: number): number {
    let ans = 0;
    n <<= 1;
    for (let k = 1; k * (k + 1) <= n; ++k) {
        if (n % k === 0 && (Math.floor(n / k) + 1 - k) % 2 === 0) {
            ++ans;
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

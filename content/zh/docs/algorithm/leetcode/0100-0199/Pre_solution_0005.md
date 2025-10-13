---
title: "0140_单词拆分 II"
date: 2025-10-08T18:45:43+08:00
weight: 5
tags: [二叉树, 几何, 分治, 动态规划, 双向链表, 双指针, 哈希表, 回溯, 字典树, 字符串, 归并排序, 排序, 数学, 数组, 栈, 树, 深度优先搜索, 记忆化搜索, 设计, 递归, 链表]
---

{{< markmap >}}
### [0140_单词拆分 II](#140)
#### [字典树](#140)
#### [记忆化搜索](#140)
#### [数组](#140)
#### [哈希表](#140)
#### [字符串](#140)
#### [动态规划](#140)
#### [回溯](#140)
### [0141_环形链表](#141)
#### [哈希表](#141)
#### [链表](#141)
#### [双指针](#141)
### [0142_环形链表 II](#142)
#### [哈希表](#142)
#### [链表](#142)
#### [双指针](#142)
### [0143_重排链表](#143)
#### [栈](#143)
#### [递归](#143)
#### [链表](#143)
#### [双指针](#143)
### [0144_二叉树的前序遍历](#144)
#### [栈](#144)
#### [树](#144)
#### [深度优先搜索](#144)
#### [二叉树](#144)
### [0145_二叉树的后序遍历](#145)
#### [栈](#145)
#### [树](#145)
#### [深度优先搜索](#145)
#### [二叉树](#145)
### [0146_LRU 缓存](#146)
#### [设计](#146)
#### [哈希表](#146)
#### [链表](#146)
#### [双向链表](#146)
### [0147_对链表进行插入排序](#147)
#### [链表](#147)
#### [排序](#147)
### [0148_排序链表](#148)
#### [链表](#148)
#### [双指针](#148)
#### [分治](#148)
#### [排序](#148)
#### [归并排序](#148)
### [0149_直线上最多的点数](#149)
#### [几何](#149)
#### [数组](#149)
#### [哈希表](#149)
#### [数学](#149)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0140_单词拆分 II
___
#### 字典树
___
#### 记忆化搜索
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
___
#### 回溯
---
### 0141_环形链表
___
#### 哈希表
___
#### 链表
___
#### 双指针
---
### 0142_环形链表 II
___
#### 哈希表
___
#### 链表
___
#### 双指针
---
### 0143_重排链表
___
#### 栈
___
#### 递归
___
#### 链表
___
#### 双指针
---
### 0144_二叉树的前序遍历
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0145_二叉树的后序遍历
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0146_LRU 缓存
___
#### 设计
___
#### 哈希表
___
#### 链表
___
#### 双向链表
---
### 0147_对链表进行插入排序
___
#### 链表
___
#### 排序
---
### 0148_排序链表
___
#### 链表
___
#### 双指针
___
#### 分治
___
#### 排序
___
#### 归并排序
---
### 0149_直线上最多的点数
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 几何 | 分治 |
| 动态规划 | 双向链表 | 双指针 |
| 哈希表 | 回溯 | 字典树 |
| 字符串 | 归并排序 | 排序 |
| 数学 | 数组 | 栈 |
| 树 | 深度优先搜索 | 记忆化搜索 |
| 设计 | 递归 | 链表 |

# [140. 单词拆分 II](https://leetcode.cn/problems/word-break-ii){#140}

{{< tabs "140" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
        return node.is_end


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def dfs(s):
            if not s:
                return [[]]
            res = []
            for i in range(1, len(s) + 1):
                if trie.search(s[:i]):
                    for v in dfs(s[i:]):
                        res.append([s[:i]] + v)
            return res

        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        ans = dfs(s)
        return [' '.join(v) for v in ans]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;

    void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }

    boolean search(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return false;
            }
            node = node.children[c];
        }
        return node.isEnd;
    }
}

class Solution {
    private Trie trie = new Trie();

    public List<String> wordBreak(String s, List<String> wordDict) {
        for (String w : wordDict) {
            trie.insert(w);
        }
        List<List<String>> res = dfs(s);
        return res.stream().map(e -> String.join(" ", e)).collect(Collectors.toList());
    }

    private List<List<String>> dfs(String s) {
        List<List<String>> res = new ArrayList<>();
        if ("".equals(s)) {
            res.add(new ArrayList<>());
            return res;
        }
        for (int i = 1; i <= s.length(); ++i) {
            if (trie.search(s.substring(0, i))) {
                for (List<String> v : dfs(s.substring(i))) {
                    v.add(0, s.substring(0, i));
                    res.add(v);
                }
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}
func (this *Trie) search(word string) bool {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return false
		}
		node = node.children[c]
	}
	return node.isEnd
}

func wordBreak(s string, wordDict []string) []string {
	trie := newTrie()
	for _, w := range wordDict {
		trie.insert(w)
	}
	var dfs func(string) [][]string
	dfs = func(s string) [][]string {
		res := [][]string{}
		if len(s) == 0 {
			res = append(res, []string{})
			return res
		}
		for i := 1; i <= len(s); i++ {
			if trie.search(s[:i]) {
				for _, v := range dfs(s[i:]) {
					v = append([]string{s[:i]}, v...)
					res = append(res, v)
				}
			}
		}
		return res
	}
	res := dfs(s)
	ans := []string{}
	for _, v := range res {
		ans = append(ans, strings.Join(v, " "))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Node
{
    public int Index1 { get; set; }
    public int Index2 { get; set; }
}

public class Solution {
    public IList<string> WordBreak(string s, IList<string> wordDict) {
        var paths = new List<Tuple<int, string>>[s.Length + 1];
        paths[s.Length] = new List<Tuple<int, string>> { Tuple.Create(-1, (string)null) };
        var wordDictGroup = wordDict.GroupBy(word => word.Length);
        for (var i = s.Length - 1; i >= 0; --i)
        {
            paths[i] = new List<Tuple<int, string>>();
            foreach (var wordGroup in wordDictGroup)
            {
                var wordLength = wordGroup.Key;
                if (i + wordLength <= s.Length && paths[i + wordLength].Count > 0)
                {
                    foreach (var word in wordGroup)
                    {
                        if (s.Substring(i, wordLength) == word)
                        {
                            paths[i].Add(Tuple.Create(i + wordLength, word));
                        }
                    }
                }
            }
        }

        return GenerateResults(paths);
    }

    private IList<string> GenerateResults(List<Tuple<int, string>>[] paths)
    {
        var results = new List<string>();
        var sb = new StringBuilder();
        var stack = new Stack<Node>();
        stack.Push(new Node());
        while (stack.Count > 0)
        {
            var node = stack.Peek();
            if (node.Index1 == paths.Length - 1 || node.Index2 == paths[node.Index1].Count)
            {
                if (node.Index1 == paths.Length - 1)
                {
                    results.Add(sb.ToString());
                }
                stack.Pop();
                if (stack.Count > 0)
                {
                    var parent = stack.Peek();
                    var length = paths[parent.Index1][parent.Index2 - 1].Item2.Length;
                    if (length < sb.Length) ++length;
                    sb.Remove(sb.Length - length, length);
                }
            }
            else
            {
                var newNode = new Node { Index1 = paths[node.Index1][node.Index2].Item1, Index2 = 0 };
                if (sb.Length != 0)
                {
                    sb.Append(' ');
                }
                sb.Append(paths[node.Index1][node.Index2].Item2);
                stack.Push(newNode);
                ++node.Index2;
            }
        }
        return results;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code> 和一个字符串字典<meta charset="UTF-8" />&nbsp;<code>wordDict</code>&nbsp;，在字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;中增加空格来构建一个句子，使得句子中所有的单词都在词典中。<strong>以任意顺序</strong> 返回所有这些可能的句子。</p>

<p><strong>注意：</strong>词典中的同一个单词可能在分段中被重复使用多次。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入:</strong>s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
<strong>输出:</strong>["cats and dog","cat sand dog"]
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入:</strong>s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
<strong>输出:</strong>["pine apple pen apple","pineapple pen apple","pine applepen apple"]
<strong>解释:</strong> 注意你可以重复使用字典中的单词。
</pre>

<p><strong class="example">示例&nbsp;3：</strong></p>

<pre>
<strong>输入:</strong>s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
<strong>输出:</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>wordDict[i]</code>&nbsp;仅有小写英文字母组成</li>
	<li><code>wordDict</code>&nbsp;中所有字符串都 <strong>不同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + DFS

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
        return node.is_end


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def dfs(s):
            if not s:
                return [[]]
            res = []
            for i in range(1, len(s) + 1):
                if trie.search(s[:i]):
                    for v in dfs(s[i:]):
                        res.append([s[:i]] + v)
            return res

        trie = Trie()
        for w in wordDict:
            trie.insert(w)
        ans = dfs(s)
        return [' '.join(v) for v in ans]
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;

    void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }

    boolean search(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return false;
            }
            node = node.children[c];
        }
        return node.isEnd;
    }
}

class Solution {
    private Trie trie = new Trie();

    public List<String> wordBreak(String s, List<String> wordDict) {
        for (String w : wordDict) {
            trie.insert(w);
        }
        List<List<String>> res = dfs(s);
        return res.stream().map(e -> String.join(" ", e)).collect(Collectors.toList());
    }

    private List<List<String>> dfs(String s) {
        List<List<String>> res = new ArrayList<>();
        if ("".equals(s)) {
            res.add(new ArrayList<>());
            return res;
        }
        for (int i = 1; i <= s.length(); ++i) {
            if (trie.search(s.substring(0, i))) {
                for (List<String> v : dfs(s.substring(i))) {
                    v.add(0, s.substring(0, i));
                    res.add(v);
                }
            }
        }
        return res;
    }
}
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}
func (this *Trie) search(word string) bool {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return false
		}
		node = node.children[c]
	}
	return node.isEnd
}

func wordBreak(s string, wordDict []string) []string {
	trie := newTrie()
	for _, w := range wordDict {
		trie.insert(w)
	}
	var dfs func(string) [][]string
	dfs = func(s string) [][]string {
		res := [][]string{}
		if len(s) == 0 {
			res = append(res, []string{})
			return res
		}
		for i := 1; i <= len(s); i++ {
			if trie.search(s[:i]) {
				for _, v := range dfs(s[i:]) {
					v = append([]string{s[:i]}, v...)
					res = append(res, v)
				}
			}
		}
		return res
	}
	res := dfs(s)
	ans := []string{}
	for _, v := range res {
		ans = append(ans, strings.Join(v, " "))
	}
	return ans
}
```

#### C#

```cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Node
{
    public int Index1 { get; set; }
    public int Index2 { get; set; }
}

public class Solution {
    public IList<string> WordBreak(string s, IList<string> wordDict) {
        var paths = new List<Tuple<int, string>>[s.Length + 1];
        paths[s.Length] = new List<Tuple<int, string>> { Tuple.Create(-1, (string)null) };
        var wordDictGroup = wordDict.GroupBy(word => word.Length);
        for (var i = s.Length - 1; i >= 0; --i)
        {
            paths[i] = new List<Tuple<int, string>>();
            foreach (var wordGroup in wordDictGroup)
            {
                var wordLength = wordGroup.Key;
                if (i + wordLength <= s.Length && paths[i + wordLength].Count > 0)
                {
                    foreach (var word in wordGroup)
                    {
                        if (s.Substring(i, wordLength) == word)
                        {
                            paths[i].Add(Tuple.Create(i + wordLength, word));
                        }
                    }
                }
            }
        }

        return GenerateResults(paths);
    }

    private IList<string> GenerateResults(List<Tuple<int, string>>[] paths)
    {
        var results = new List<string>();
        var sb = new StringBuilder();
        var stack = new Stack<Node>();
        stack.Push(new Node());
        while (stack.Count > 0)
        {
            var node = stack.Peek();
            if (node.Index1 == paths.Length - 1 || node.Index2 == paths[node.Index1].Count)
            {
                if (node.Index1 == paths.Length - 1)
                {
                    results.Add(sb.ToString());
                }
                stack.Pop();
                if (stack.Count > 0)
                {
                    var parent = stack.Peek();
                    var length = paths[parent.Index1][parent.Index2 - 1].Item2.Length;
                    if (length < sb.Length) ++length;
                    sb.Remove(sb.Length - length, length);
                }
            }
            else
            {
                var newNode = new Node { Index1 = paths[node.Index1][node.Index2].Item1, Index2 = 0 };
                if (sb.Length != 0)
                {
                    sb.Append(' ');
                }
                sb.Append(paths[node.Index1][node.Index2].Item2);
                stack.Push(newNode);
                ++node.Index2;
            }
        }
        return results;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle){#141}

{{< tabs "141" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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
func hasCycle(head *ListNode) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
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

function hasCycle(head: ListNode | null): boolean {
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
    let slow = head;
    let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        var fast = head;
        var slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点 <code>head</code> ，判断链表中是否有环。</p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。<strong>注意：<code>pos</code> 不作为参数进行传递&nbsp;</strong>。仅仅是为了标识链表的实际情况。</p>

<p><em>如果链表中存在环</em>&nbsp;，则返回 <code>true</code> 。 否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0141.Linked%20List%20Cycle/images/circularlinkedlist.png" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0141.Linked%20List%20Cycle/images/circularlinkedlist_test2.png" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0141.Linked%20List%20Cycle/images/circularlinkedlist_test3.png" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>false
<strong>解释：</strong>链表中没有环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[0, 10<sup>4</sup>]</code></li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> 为 <code>-1</code> 或者链表中的一个 <strong>有效索引</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能用 <code>O(1)</code>（即，常量）内存解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以遍历链表，用一个哈希表 $s$ 记录每个节点。当某个节点二次出现时，则表示存在环，直接返回 `true`。否则链表遍历结束，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是链表中的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = set()
        while head:
            if head in s:
                return True
            s.add(head)
            head = head.next
        return False
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> s = new HashSet<>();
        for (; head != null; head = head.next) {
            if (!s.add(head)) {
                return true;
            }
        }
        return false;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        for (; head; head = head->next) {
            if (s.contains(head)) {
                return true;
            }
            s.insert(head);
        }
        return false;
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
func hasCycle(head *ListNode) bool {
	s := map[*ListNode]bool{}
	for ; head != nil; head = head.Next {
		if s[head] {
			return true
		}
		s[head] = true
	}
	return false
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

function hasCycle(head: ListNode | null): boolean {
    const s: Set<ListNode> = new Set();
    for (; head; head = head.next) {
        if (s.has(head)) {
            return true;
        }
        s.add(head);
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：快慢指针

我们定义快慢指针 $fast$ 和 $slow$，初始时均指向 $head$。

快指针每次走两步，慢指针每次走一步，不断循环。当快慢指针相遇时，说明链表存在环。如果循环结束依然没有相遇，说明链表不存在环。

时间复杂度 $O(n)$，其中 $n$ 是链表中的节点数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                return True
        return False
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
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
func hasCycle(head *ListNode) bool {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
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

function hasCycle(head: ListNode | null): boolean {
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
    let slow = head;
    let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            return true;
        }
    }
    return false;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        var fast = head;
        var slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii){#142}

{{< tabs "142" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                ans = head
                while ans != slow:
                    ans = ans.next
                    slow = slow.next
                return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                ListNode ans = head;
                while (ans != slow) {
                    ans = ans.next;
                    slow = slow.next;
                }
                return ans;
            }
        }
        return null;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* ans = head;
                while (ans != slow) {
                    ans = ans->next;
                    slow = slow->next;
                }
                return ans;
            }
        }
        return nullptr;
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
func detectCycle(head *ListNode) *ListNode {
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			ans := head
			for ans != slow {
				ans = ans.Next
				slow = slow.Next
			}
			return ans
		}
	}
	return nil
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

function detectCycle(head: ListNode | null): ListNode | null {
    let [slow, fast] = [head, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            let ans = head;
            while (ans !== slow) {
                ans = ans.next;
                slow = slow.next;
            }
            return ans;
        }
    }
    return null;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function (head) {
    let [slow, fast] = [head, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            let ans = head;
            while (ans !== slow) {
                ans = ans.next;
                slow = slow.next;
            }
            return ans;
        }
    }
    return null;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个链表的头节点 &nbsp;<code>head</code>&nbsp;，返回链表开始入环的第一个节点。&nbsp;<em>如果链表无环，则返回&nbsp;<code>null</code>。</em></p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（<strong>索引从 0 开始</strong>）。如果 <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。<strong>注意：<code>pos</code> 不作为参数进行传递</strong>，仅仅是为了标识链表的实际情况。</p>

<p><strong>不允许修改 </strong>链表。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0142.Linked%20List%20Cycle%20II/images/circularlinkedlist.png" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>返回索引为 1 的链表节点
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0142.Linked%20List%20Cycle%20II/images/circularlinkedlist_test2.png" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>返回索引为 0 的链表节点
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0142.Linked%20List%20Cycle%20II/images/circularlinkedlist_test3.png" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>返回 null
<strong>解释：</strong>链表中没有环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> 的值为 <code>-1</code> 或者链表中的一个有效索引</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你是否可以使用 <code>O(1)</code> 空间解决此题？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

我们先利用快慢指针判断链表是否有环，如果有环的话，快慢指针一定会相遇，且相遇的节点一定在环中。

如果没有环，快指针会先到达链表尾部，直接返回 `null` 即可。

如果有环，我们再定义一个答案指针 $ans$ 指向链表头部，然后让 $ans$ 和慢指针一起向前走，每次走一步，直到 $ans$ 和慢指针相遇，相遇的节点即为环的入口节点。

为什么这样能找到环的入口节点呢？

我们不妨假设链表头节点到环入口的距离为 $x$，环入口到相遇节点的距离为 $y$，相遇节点到环入口的距离为 $z$，那么慢指针走过的距离为 $x + y$，快指针走过的距离为 $x + y + k \times (y + z)$，其中 $k$ 是快指针在环中绕了 $k$ 圈。

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0142.Linked%20List%20Cycle%20II/images/linked-list-cycle-ii.png" /></p>

由于快指针速度是慢指针的 $2$ 倍，因此有 $2 \times (x + y) = x + y + k \times (y + z)$，可以推出 $x + y = k \times (y + z)$，即 $x = (k - 1) \times (y + z) + z$。

也即是说，如果我们定义一个答案指针 $ans$ 指向链表头部，然后 $ans$ 和慢指针一起向前走，那么它们一定会在环入口相遇。

时间复杂度 $O(n)$，其中 $n$ 是链表中节点的数目。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                ans = head
                while ans != slow:
                    ans = ans.next
                    slow = slow.next
                return ans
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                ListNode ans = head;
                while (ans != slow) {
                    ans = ans.next;
                    slow = slow.next;
                }
                return ans;
            }
        }
        return null;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* ans = head;
                while (ans != slow) {
                    ans = ans->next;
                    slow = slow->next;
                }
                return ans;
            }
        }
        return nullptr;
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
func detectCycle(head *ListNode) *ListNode {
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			ans := head
			for ans != slow {
				ans = ans.Next
				slow = slow.Next
			}
			return ans
		}
	}
	return nil
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

function detectCycle(head: ListNode | null): ListNode | null {
    let [slow, fast] = [head, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            let ans = head;
            while (ans !== slow) {
                ans = ans.next;
                slow = slow.next;
            }
            return ans;
        }
    }
    return null;
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function (head) {
    let [slow, fast] = [head, head];
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            let ans = head;
            while (ans !== slow) {
                ans = ans.next;
                slow = slow.next;
            }
            return ans;
        }
    }
    return null;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [143. 重排链表](https://leetcode.cn/problems/reorder-list){#143}

{{< tabs "143" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # 快慢指针找到链表中点
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # cur 指向右半部分链表
        cur = slow.next
        slow.next = None

        # 反转右半部分链表
        pre = None
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        cur = head

        # 此时 cur, pre 分别指向链表左右两半的第一个节点
        # 合并
        while pre:
            t = pre.next
            pre.next = cur.next
            cur.next = pre
            cur, pre = pre.next, t
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
    public void reorderList(ListNode head) {
        // 快慢指针找到链表中点
        ListNode fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // cur 指向右半部分链表
        ListNode cur = slow.next;
        slow.next = null;

        // 反转右半部分链表
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre != null) {
            ListNode t = pre.next;
            pre.next = cur.next;
            cur.next = pre;
            cur = pre.next;
            pre = t;
        }
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
    void reorderList(ListNode* head) {
        // 快慢指针找到链表中点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // cur 指向右半部分链表
        ListNode* cur = slow->next;
        slow->next = nullptr;

        // 反转右半部分链表
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre) {
            ListNode* t = pre->next;
            pre->next = cur->next;
            cur->next = pre;
            cur = pre->next;
            pre = t;
        }
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
func reorderList(head *ListNode) {
	// 快慢指针找到链表中点
	fast, slow := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}

	// cur 指向右半部分链表
	cur := slow.Next
	slow.Next = nil

	// 反转右半部分链表
	var pre *ListNode
	for cur != nil {
		t := cur.Next
		cur.Next = pre
		pre, cur = cur, t
	}
	cur = head

	// 此时 cur, pre 分别指向链表左右两半的第一个节点
	// 合并
	for pre != nil {
		t := pre.Next
		pre.Next = cur.Next
		cur.Next = pre
		cur, pre = pre.Next, t
	}
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

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
    let slow = head;
    let fast = head;
    // 找到中心节点
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // 反转节点
    let next = slow.next;
    slow.next = null;
    while (next) {
        [next.next, slow, next] = [slow, next, next.next];
    }
    // 合并
    let left = head;
    let right = slow;
    while (right.next) {
        const next = left.next;
        left.next = right;
        right = right.next;
        left.next.next = next;
        left = left.next.next;
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::VecDeque;
impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        let mut tail = &mut head.as_mut().unwrap().next;
        let mut head = tail.take();
        let mut deque = VecDeque::new();
        while head.is_some() {
            let next = head.as_mut().unwrap().next.take();
            deque.push_back(head);
            head = next;
        }
        let mut flag = false;
        while !deque.is_empty() {
            *tail = if flag {
                deque.pop_front().unwrap()
            } else {
                deque.pop_back().unwrap()
            };
            tail = &mut tail.as_mut().unwrap().next;
            flag = !flag;
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    // 快慢指针找到链表中点
    let slow = head;
    let fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // cur 指向右半部分链表
    let cur = slow.next;
    slow.next = null;

    // 反转右半部分链表
    let pre = null;
    while (cur) {
        const t = cur.next;
        cur.next = pre;
        pre = cur;
        cur = t;
    }
    cur = head;

    // 此时 cur, pre 分别指向链表左右两半的第一个节点
    // 合并
    while (pre) {
        const t = pre.next;
        pre.next = cur.next;
        cur.next = pre;
        cur = pre.next;
        pre = t;
    }
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public void ReorderList(ListNode head) {
        // 快慢指针找到链表中点
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // cur 指向右半部分链表
        ListNode cur = slow.next;
        slow.next = null;

        // 反转右半部分链表
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre != null) {
            ListNode t = pre.next;
            pre.next = cur.next;
            cur.next = pre;
            cur = pre.next;
            pre = t;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个单链表 <code>L</code><em> </em>的头节点 <code>head</code> ，单链表 <code>L</code> 表示为：</p>

<pre>
L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p>请将其重新排列后变为：</p>

<pre>
L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …</pre>

<p>不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0143.Reorder%20List/images/1626420311-PkUiGI-image.png" style="width: 240px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,4,2,3]</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0143.Reorder%20List/images/1626420320-YUiulT-image.png" style="width: 320px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5]
<strong>输出：</strong>[1,5,2,4,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为 <code>[1, 5 * 10<sup>4</sup>]</code></li>
	<li><code>1 &lt;= node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针 + 反转链表 + 合并链表

我们先用快慢指针找到链表的中点，然后将链表的后半部分反转，最后将左右两个链表合并。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # 快慢指针找到链表中点
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # cur 指向右半部分链表
        cur = slow.next
        slow.next = None

        # 反转右半部分链表
        pre = None
        while cur:
            t = cur.next
            cur.next = pre
            pre, cur = cur, t
        cur = head

        # 此时 cur, pre 分别指向链表左右两半的第一个节点
        # 合并
        while pre:
            t = pre.next
            pre.next = cur.next
            cur.next = pre
            cur, pre = pre.next, t
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
    public void reorderList(ListNode head) {
        // 快慢指针找到链表中点
        ListNode fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // cur 指向右半部分链表
        ListNode cur = slow.next;
        slow.next = null;

        // 反转右半部分链表
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre != null) {
            ListNode t = pre.next;
            pre.next = cur.next;
            cur.next = pre;
            cur = pre.next;
            pre = t;
        }
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
    void reorderList(ListNode* head) {
        // 快慢指针找到链表中点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // cur 指向右半部分链表
        ListNode* cur = slow->next;
        slow->next = nullptr;

        // 反转右半部分链表
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre) {
            ListNode* t = pre->next;
            pre->next = cur->next;
            cur->next = pre;
            cur = pre->next;
            pre = t;
        }
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
func reorderList(head *ListNode) {
	// 快慢指针找到链表中点
	fast, slow := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}

	// cur 指向右半部分链表
	cur := slow.Next
	slow.Next = nil

	// 反转右半部分链表
	var pre *ListNode
	for cur != nil {
		t := cur.Next
		cur.Next = pre
		pre, cur = cur, t
	}
	cur = head

	// 此时 cur, pre 分别指向链表左右两半的第一个节点
	// 合并
	for pre != nil {
		t := pre.Next
		pre.Next = cur.Next
		cur.Next = pre
		cur, pre = pre.Next, t
	}
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

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
    let slow = head;
    let fast = head;
    // 找到中心节点
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // 反转节点
    let next = slow.next;
    slow.next = null;
    while (next) {
        [next.next, slow, next] = [slow, next, next.next];
    }
    // 合并
    let left = head;
    let right = slow;
    while (right.next) {
        const next = left.next;
        left.next = right;
        right = right.next;
        left.next.next = next;
        left = left.next.next;
    }
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::VecDeque;
impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        let mut tail = &mut head.as_mut().unwrap().next;
        let mut head = tail.take();
        let mut deque = VecDeque::new();
        while head.is_some() {
            let next = head.as_mut().unwrap().next.take();
            deque.push_back(head);
            head = next;
        }
        let mut flag = false;
        while !deque.is_empty() {
            *tail = if flag {
                deque.pop_front().unwrap()
            } else {
                deque.pop_back().unwrap()
            };
            tail = &mut tail.as_mut().unwrap().next;
            flag = !flag;
        }
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    // 快慢指针找到链表中点
    let slow = head;
    let fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // cur 指向右半部分链表
    let cur = slow.next;
    slow.next = null;

    // 反转右半部分链表
    let pre = null;
    while (cur) {
        const t = cur.next;
        cur.next = pre;
        pre = cur;
        cur = t;
    }
    cur = head;

    // 此时 cur, pre 分别指向链表左右两半的第一个节点
    // 合并
    while (pre) {
        const t = pre.next;
        pre.next = cur.next;
        cur.next = pre;
        cur = pre.next;
        pre = t;
    }
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public void ReorderList(ListNode head) {
        // 快慢指针找到链表中点
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // cur 指向右半部分链表
        ListNode cur = slow.next;
        slow.next = null;

        // 反转右半部分链表
        ListNode pre = null;
        while (cur != null) {
            ListNode t = cur.next;
            cur.next = pre;
            pre = cur;
            cur = t;
        }
        cur = head;

        // 此时 cur, pre 分别指向链表左右两半的第一个节点
        // 合并
        while (pre != null) {
            ListNode t = pre.next;
            pre.next = cur.next;
            cur.next = pre;
            cur = pre.next;
            pre = t;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal){#144}

{{< tabs "144" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.left is None:
                ans.append(root.val)
                root = root.right
            else:
                prev = root.left
                while prev.right and prev.right != root:
                    prev = prev.right
                if prev.right is None:
                    ans.append(root.val)
                    prev.right = root
                    root = root.left
                else:
                    prev.right = None
                    root = root.right
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        while (root != null) {
            if (root.left == null) {
                ans.add(root.val);
                root = root.right;
            } else {
                TreeNode prev = root.left;
                while (prev.right != null && prev.right != root) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    ans.add(root.val);
                    prev.right = root;
                    root = root.left;
                } else {
                    prev.right = null;
                    root = root.right;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    ans.push_back(root->val);
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    root = root->right;
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
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) (ans []int) {
	for root != nil {
		if root.Left == nil {
			ans = append(ans, root.Val)
			root = root.Right
		} else {
			prev := root.Left
			for prev.Right != nil && prev.Right != root {
				prev = prev.Right
			}
			if prev.Right == nil {
				ans = append(ans, root.Val)
				prev.Right = root
				root = root.Left
			} else {
				prev.Right = nil
				root = root.Right
			}
		}
	}
	return
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

function preorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    while (root) {
        const { left, right, val } = root;
        if (!left) {
            ans.push(val);
            root = right;
        } else {
            let prev = left;
            while (prev.right && prev.right != root) {
                prev = prev.right;
            }
            if (!prev.right) {
                ans.push(val);
                prev.right = root;
                root = root.left;
            } else {
                prev.right = null;
                root = root.right;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        ans.push(node.val);
        Self::dfs(&node.left, ans);
        Self::dfs(&node.right, ans);
    }

    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        Self::dfs(&root, &mut ans);
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

<p>给你二叉树的根节点 <code>root</code> ，返回它节点值的&nbsp;<strong>前序</strong><em>&nbsp;</em>遍历。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [1,null,2,3]</span></p>

<p><strong>输出：</strong><span class="example-io">[1,2,3]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0144.Binary%20Tree%20Preorder%20Traversal/images/screenshot-2024-08-29-202743.png" style="width: 200px; height: 264px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1,2,3,4,5,null,8,null,null,6,7,9]</span></p>

<p><span class="example-io"><b>输出：</b>[1,2,4,5,6,7,3,8,9]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0144.Binary%20Tree%20Preorder%20Traversal/images/tree_2.png" style="width: 350px; height: 286px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = []</span></p>

<p><span class="example-io"><b>输出：</b>[]</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">root = [1]</span></p>

<p><span class="example-io"><b>输出：</b>[1]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归遍历

我们先访问根节点，然后递归左子树和右子树。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数，空间复杂度主要取决于递归调用的栈空间。

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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            ans.append(root.val)
            dfs(root.left)
            dfs(root.right)

        ans = []
        dfs(root)
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> preorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        ans.add(root.val);
        dfs(root.left);
        dfs(root.right);
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            ans.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
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
func preorderTraversal(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		ans = append(ans, root.Val)
		dfs(root.Left)
		dfs(root.Right)
	}
	dfs(root)
	return
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

function preorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        ans.push(root.val);
        dfs(root.left);
        dfs(root.right);
    };
    dfs(root);
    return ans;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        ans.push(node.val);
        Self::dfs(&node.left, ans);
        Self::dfs(&node.right, ans);
    }

    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        Self::dfs(&root, &mut ans);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈实现非递归遍历

栈实现非递归遍历的思路如下：

1. 定义一个栈 $stk$，先将根节点压入栈
1. 若栈不为空，每次从栈中弹出一个节点
1. 处理该节点
1. 先把节点右孩子压入栈，接着把节点左孩子压入栈（如果有孩子节点）
1. 重复 2-4
1. 返回结果

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数，空间复杂度主要取决于栈空间。

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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            if node.right:
                stk.append(node.right)
            if node.left:
                stk.append(node.left)
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<TreeNode> stk = new ArrayDeque<>();
        stk.push(root);
        while (!stk.isEmpty()) {
            TreeNode node = stk.pop();
            ans.add(node.val);
            if (node.right != null) {
                stk.push(node.right);
            }
            if (node.left != null) {
                stk.push(node.left);
            }
        }
        return ans;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (stk.size()) {
            auto node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
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
func preorderTraversal(root *TreeNode) (ans []int) {
	if root == nil {
		return
	}
	stk := []*TreeNode{root}
	for len(stk) > 0 {
		node := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		ans = append(ans, node.Val)
		if node.Right != nil {
			stk = append(stk, node.Right)
		}
		if node.Left != nil {
			stk = append(stk, node.Left)
		}
	}
	return
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

function preorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: TreeNode[] = [root];
    while (stk.length) {
        const { left, right, val } = stk.pop();
        ans.push(val);
        right && stk.push(right);
        left && stk.push(left);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：Morris 实现前序遍历

Morris 遍历无需使用栈，空间复杂度为 $O(1)$。核心思想是：

遍历二叉树节点，

1. 若当前节点 `root` 的左子树为空，将当前节点值添加至结果列表 $ans$ 中，并将当前节点更新为 `root.right`
1. 若当前节点 `root` 的左子树不为空，找到左子树的最右节点 `pre`（也即是 `root` 节点在中序遍历下的前驱节点）：
    - 若前驱节点 `pre` 的右子树为空，将当前节点值添加至结果列表 $ans$ 中，然后将前驱节点的右子树指向当前节点 `root`，并将当前节点更新为 `root.left`。
    - 若前驱节点 `pre` 的右子树不为空，将前驱节点右子树指向空（即解除 `pre` 与 `root` 的指向关系），并将当前节点更新为 `root.right`。
1. 循环以上步骤，直至二叉树节点为空，遍历结束。

时间复杂度 $O(n)$，其中 $n$ 是二叉树的节点数。空间复杂度 $O(1)$。

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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.left is None:
                ans.append(root.val)
                root = root.right
            else:
                prev = root.left
                while prev.right and prev.right != root:
                    prev = prev.right
                if prev.right is None:
                    ans.append(root.val)
                    prev.right = root
                    root = root.left
                else:
                    prev.right = None
                    root = root.right
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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        while (root != null) {
            if (root.left == null) {
                ans.add(root.val);
                root = root.right;
            } else {
                TreeNode prev = root.left;
                while (prev.right != null && prev.right != root) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    ans.add(root.val);
                    prev.right = root;
                    root = root.left;
                } else {
                    prev.right = null;
                    root = root.right;
                }
            }
        }
        return ans;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    ans.push_back(root->val);
                    prev->right = root;
                    root = root->left;
                } else {
                    prev->right = nullptr;
                    root = root->right;
                }
            }
        }
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
func preorderTraversal(root *TreeNode) (ans []int) {
	for root != nil {
		if root.Left == nil {
			ans = append(ans, root.Val)
			root = root.Right
		} else {
			prev := root.Left
			for prev.Right != nil && prev.Right != root {
				prev = prev.Right
			}
			if prev.Right == nil {
				ans = append(ans, root.Val)
				prev.Right = root
				root = root.Left
			} else {
				prev.Right = nil
				root = root.Right
			}
		}
	}
	return
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

function preorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    while (root) {
        const { left, right, val } = root;
        if (!left) {
            ans.push(val);
            root = right;
        } else {
            let prev = left;
            while (prev.right && prev.right != root) {
                prev = prev.right;
            }
            if (!prev.right) {
                ans.push(val);
                prev.right = root;
                root = root.left;
            } else {
                prev.right = null;
                root = root.right;
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

# [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal){#145}

{{< tabs "145" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.right is None:
                ans.append(root.val)
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left != root:
                    ans.append(root.val)
                    next.left = root
                    root = root.right
                else:
                    next.left = None
                    root = root.left
        return ans[::-1]
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
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        while (root != null) {
            if (root.right == null) {
                ans.addFirst(root.val);
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    ans.addFirst(root.val);
                    next.left = root;
                    root = root.right;
                } else {
                    next.left = null;
                    root = root.left;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root) {
            if (!root->right) {
                ans.push_back(root->val);
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left != root) {
                    ans.push_back(root->val);
                    next->left = root;
                    root = root->right;
                } else {
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
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
func postorderTraversal(root *TreeNode) (ans []int) {
	for root != nil {
		if root.Right == nil {
			ans = append([]int{root.Val}, ans...)
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				ans = append([]int{root.Val}, ans...)
				next.Left = root
				root = root.Right
			} else {
				next.Left = nil
				root = root.Left
			}
		}
	}
	return
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

function postorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    while (root !== null) {
        const { val, left, right } = root;
        if (right === null) {
            ans.push(val);
            root = left;
        } else {
            let next = right;
            while (next.left !== null && next.left !== root) {
                next = next.left;
            }
            if (next.left === null) {
                ans.push(val);
                next.left = root;
                root = right;
            } else {
                next.left = null;
                root = left;
            }
        }
    }
    return ans.reverse();
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        Self::dfs(&node.left, ans);
        Self::dfs(&node.right, ans);
        ans.push(node.val);
    }

    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        Self::dfs(&root, &mut ans);
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

<p>给你一棵二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>后序遍历 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1,null,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>[3,2,1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0145.Binary%20Tree%20Postorder%20Traversal/images/screenshot-2024-08-29-202743.png" style="width: 200px; height: 264px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1,2,3,4,5,null,8,null,null,6,7,9]</span></p>

<p><span class="example-io"><b>输出：</b>[4,6,7,5,2,9,8,3,1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0145.Binary%20Tree%20Postorder%20Traversal/images/tree_2.png" style="width: 350px; height: 286px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = []</span></p>

<p><span class="example-io"><b>输出：</b>[]</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>root = [1]</span></p>

<p><span class="example-io"><b>输出：</b>[1]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先递归左右子树，然后再访问根节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数，空间复杂度主要取决于递归调用的栈空间。

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            if root is None:
                return
            dfs(root.left)
            dfs(root.right)
            ans.append(root.val)

        ans = []
        dfs(root)
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
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> postorderTraversal(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        dfs(root.right);
        ans.add(root.val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            dfs(root->right);
            ans.push_back(root->val);
        };
        dfs(root);
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
func postorderTraversal(root *TreeNode) (ans []int) {
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		dfs(root.Right)
		ans = append(ans, root.Val)
	}
	dfs(root)
	return
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

function postorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        dfs(root.right);
        ans.push(root.val);
    };
    dfs(root);
    return ans;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, ans: &mut Vec<i32>) {
        if root.is_none() {
            return;
        }
        let node = root.as_ref().unwrap().borrow();
        Self::dfs(&node.left, ans);
        Self::dfs(&node.right, ans);
        ans.push(node.val);
    }

    pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        Self::dfs(&root, &mut ans);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：栈实现后序遍历

先序遍历的顺序是：根、左、右，如果我们改变左右孩子的顺序，就能将顺序变成：根、右、左。最后再将结果反转一下，就得到了后序遍历的结果。

因此，栈实现非递归遍历的思路如下：

1. 定义一个栈 $stk$，先将根节点压入栈
1. 若栈不为空，每次从栈中弹出一个节点
1. 处理该节点
1. 先把节点左孩子压入栈，接着把节点右孩子压入栈（如果有孩子节点）
1. 重复 2-4
1. 将结果反转，得到后序遍历的结果

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数，空间复杂度主要取决于栈空间。

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        if root is None:
            return ans
        stk = [root]
        while stk:
            node = stk.pop()
            ans.append(node.val)
            if node.left:
                stk.append(node.left)
            if node.right:
                stk.append(node.right)
        return ans[::-1]
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
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        Deque<TreeNode> stk = new ArrayDeque<>();
        stk.push(root);
        while (!stk.isEmpty()) {
            TreeNode node = stk.pop();
            ans.addFirst(node.val);
            if (node.left != null) {
                stk.push(node.left);
            }
            if (node.right != null) {
                stk.push(node.right);
            }
        }
        return ans;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (stk.size()) {
            auto node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
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
func postorderTraversal(root *TreeNode) (ans []int) {
	if root == nil {
		return
	}
	stk := []*TreeNode{root}
	for len(stk) > 0 {
		node := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		ans = append(ans, node.Val)
		if node.Left != nil {
			stk = append(stk, node.Left)
		}
		if node.Right != nil {
			stk = append(stk, node.Right)
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
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

function postorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    if (!root) {
        return ans;
    }
    const stk: TreeNode[] = [root];
    while (stk.length) {
        const { left, right, val } = stk.pop();
        ans.push(val);
        left && stk.push(left);
        right && stk.push(right);
    }
    ans.reverse();
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：Morris 实现后序遍历

Morris 遍历无需使用栈，空间复杂度为 $O(1)$。核心思想是：

遍历二叉树节点，

1. 若当前节点 `root` 的右子树为空，将当前节点值添加至结果列表 $ans$ 中，并将当前节点更新为 `root.left`
1. 若当前节点 `root` 的右子树不为空，找到右子树的最左节点 `next`（也即是 `root` 节点在中序遍历下的后继节点）：
    - 若后继节点 `next` 的左子树为空，将当前节点值添加至结果列表 $ans$ 中，然后将后继节点的左子树指向当前节点 `root`，并将当前节点更新为 `root.right`。
    - 若后继节点 `next` 的左子树不为空，将后继节点左子树指向空（即解除 `next` 与 `root` 的指向关系），并将当前节点更新为 `root.left`。
1. 循环以上步骤，直至二叉树节点为空，遍历结束。
1. 最后返回结果列表的逆序即可。

> Morris 后序遍历跟 Morris 前序遍历思路一致，只是将前序的“根左右”变为“根右左”，最后逆序结果即可变成“左右根”。

时间复杂度 $O(n)$，其中 $n$ 是二叉树的节点数。空间复杂度 $O(1)$。

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        while root:
            if root.right is None:
                ans.append(root.val)
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left != root:
                    ans.append(root.val)
                    next.left = root
                    root = root.right
                else:
                    next.left = None
                    root = root.left
        return ans[::-1]
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
    public List<Integer> postorderTraversal(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();
        while (root != null) {
            if (root.right == null) {
                ans.addFirst(root.val);
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    ans.addFirst(root.val);
                    next.left = root;
                    root = root.right;
                } else {
                    next.left = null;
                    root = root.left;
                }
            }
        }
        return ans;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while (root) {
            if (!root->right) {
                ans.push_back(root->val);
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left != root) {
                    ans.push_back(root->val);
                    next->left = root;
                    root = root->right;
                } else {
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
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
func postorderTraversal(root *TreeNode) (ans []int) {
	for root != nil {
		if root.Right == nil {
			ans = append([]int{root.Val}, ans...)
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				ans = append([]int{root.Val}, ans...)
				next.Left = root
				root = root.Right
			} else {
				next.Left = nil
				root = root.Left
			}
		}
	}
	return
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

function postorderTraversal(root: TreeNode | null): number[] {
    const ans: number[] = [];
    while (root !== null) {
        const { val, left, right } = root;
        if (right === null) {
            ans.push(val);
            root = left;
        } else {
            let next = right;
            while (next.left !== null && next.left !== root) {
                next = next.left;
            }
            if (next.left === null) {
                ans.push(val);
                next.left = root;
                root = right;
            } else {
                next.left = null;
                root = left;
            }
        }
    }
    return ans.reverse();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [146. LRU 缓存](https://leetcode.cn/problems/lru-cache){#146}

{{< tabs "146" >}}

{{% tab "python" %}}
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
{{% tab "java" %}}
```java
class Node {
    int key, val;
    Node prev, next;

    Node() {
    }

    Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    private int size;
    private int capacity;
    private Node head = new Node();
    private Node tail = new Node();
    private Map<Integer, Node> cache = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        Node node = cache.get(key);
        removeNode(node);
        addToHead(node);
        return node.val;
    }

    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            removeNode(node);
            node.val = value;
            addToHead(node);
        } else {
            Node node = new Node(key, value);
            cache.put(key, node);
            addToHead(node);
            if (++size > capacity) {
                node = tail.prev;
                cache.remove(node.key);
                removeNode(node);
                --size;
            }
        }
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void addToHead(Node node) {
        node.next = head.next;
        node.prev = head;
        head.next = node;
        node.next.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val)
            : key(key)
            , val(val)
            , prev(nullptr)
            , next(nullptr) {}
    };

    int size;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
        : size(0)
        , capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            if (++size > capacity) {
                node = tail->prev;
                cache.erase(node->key);
                removeNode(node);
                --size;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	key, val   int
	prev, next *Node
}

type LRUCache struct {
	size, capacity int
	head, tail     *Node
	cache          map[int]*Node
}

func Constructor(capacity int) LRUCache {
	head := &Node{}
	tail := &Node{}
	head.next = tail
	tail.prev = head
	return LRUCache{
		capacity: capacity,
		head:     head,
		tail:     tail,
		cache:    make(map[int]*Node),
	}
}

func (this *LRUCache) Get(key int) int {
	if node, exists := this.cache[key]; exists {
		this.removeNode(node)
		this.addToHead(node)
		return node.val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if node, exists := this.cache[key]; exists {
		this.removeNode(node)
		node.val = value
		this.addToHead(node)
	} else {
		node := &Node{key: key, val: value}
		this.cache[key] = node
		this.addToHead(node)
		if this.size++; this.size > this.capacity {
			node = this.tail.prev
			delete(this.cache, node.key)
			this.removeNode(node)
			this.size--
		}
	}
}

func (this *LRUCache) removeNode(node *Node) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LRUCache) addToHead(node *Node) {
	node.next = this.head.next
	node.prev = this.head
	this.head.next = node
	node.next.prev = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    key: number;
    val: number;
    prev: Node | null;
    next: Node | null;

    constructor(key: number, val: number) {
        this.key = key;
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    private size: number;
    private capacity: number;
    private head: Node;
    private tail: Node;
    private cache: Map<number, Node>;

    constructor(capacity: number) {
        this.size = 0;
        this.capacity = capacity;
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.cache = new Map();
    }

    get(key: number): number {
        if (!this.cache.has(key)) {
            return -1;
        }
        const node = this.cache.get(key)!;
        this.removeNode(node);
        this.addToHead(node);
        return node.val;
    }

    put(key: number, value: number): void {
        if (this.cache.has(key)) {
            const node = this.cache.get(key)!;
            this.removeNode(node);
            node.val = value;
            this.addToHead(node);
        } else {
            const node = new Node(key, value);
            this.cache.set(key, node);
            this.addToHead(node);
            if (++this.size > this.capacity) {
                const nodeToRemove = this.tail.prev!;
                this.cache.delete(nodeToRemove.key);
                this.removeNode(nodeToRemove);
                --this.size;
            }
        }
    }

    private removeNode(node: Node): void {
        if (!node) return;
        node.prev!.next = node.next;
        node.next!.prev = node.prev;
    }

    private addToHead(node: Node): void {
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next!.prev = node;
        this.head.next = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
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
    prev: Option<Rc<RefCell<Node>>>,
    next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    #[inline]
    fn new(key: i32, value: i32) -> Self {
        Self {
            key,
            value,
            prev: None,
            next: None,
        }
    }
}

struct LRUCache {
    capacity: usize,
    cache: HashMap<i32, Rc<RefCell<Node>>>,
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            cache: HashMap::new(),
            head: None,
            tail: None,
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                self.remove(&node);
                self.push_front(&node);
                let value = node.borrow().value;
                value
            }
            None => -1,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                node.borrow_mut().value = value;
                self.remove(&node);
                self.push_front(&node);
            }
            None => {
                let node = Rc::new(RefCell::new(Node::new(key, value)));
                self.cache.insert(key, Rc::clone(&node));
                self.push_front(&node);
                if self.cache.len() > self.capacity {
                    let back_key = self.pop_back().unwrap().borrow().key;
                    self.cache.remove(&back_key);
                }
            }
        };
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
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    this.size = 0;
    this.capacity = capacity;
    this.cache = new Map();
    this.head = new Node(0, 0);
    this.tail = new Node(0, 0);
    this.head.next = this.tail;
    this.tail.prev = this.head;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
    if (!this.cache.has(key)) {
        return -1;
    }
    const node = this.cache.get(key);
    this.removeNode(node);
    this.addToHead(node);
    return node.val;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
    if (this.cache.has(key)) {
        const node = this.cache.get(key);
        this.removeNode(node);
        node.val = value;
        this.addToHead(node);
    } else {
        const node = new Node(key, value);
        this.cache.set(key, node);
        this.addToHead(node);
        if (++this.size > this.capacity) {
            const nodeToRemove = this.tail.prev;
            this.cache.delete(nodeToRemove.key);
            this.removeNode(nodeToRemove);
            --this.size;
        }
    }
};

LRUCache.prototype.removeNode = function (node) {
    if (!node) return;
    node.prev.next = node.next;
    node.next.prev = node.prev;
};

LRUCache.prototype.addToHead = function (node) {
    node.next = this.head.next;
    node.prev = this.head;
    this.head.next.prev = node;
    this.head.next = node;
};

/**
 * @constructor
 * @param {number} key
 * @param {number} val
 */
function Node(key, val) {
    this.key = key;
    this.val = val;
    this.prev = null;
    this.next = null;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class LRUCache {
    private int size;
    private int capacity;
    private Dictionary<int, Node> cache = new Dictionary<int, Node>();
    private Node head = new Node();
    private Node tail = new Node();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.Next = tail;
        tail.Prev = head;
    }

    public int Get(int key) {
        if (!cache.ContainsKey(key)) {
            return -1;
        }
        Node node = cache[key];
        RemoveNode(node);
        AddToHead(node);
        return node.Val;
    }

    public void Put(int key, int value) {
        if (cache.ContainsKey(key)) {
            Node node = cache[key];
            RemoveNode(node);
            node.Val = value;
            AddToHead(node);
        } else {
            Node node = new Node(key, value);
            cache[key] = node;
            AddToHead(node);
            if (++size > capacity) {
                node = tail.Prev;
                cache.Remove(node.Key);
                RemoveNode(node);
                --size;
            }
        }
    }

    private void RemoveNode(Node node) {
        node.Prev.Next = node.Next;
        node.Next.Prev = node.Prev;
    }

    private void AddToHead(Node node) {
        node.Next = head.Next;
        node.Prev = head;
        head.Next = node;
        node.Next.Prev = node;
    }

    // Node class to represent each entry in the cache.
    private class Node {
        public int Key;
        public int Val;
        public Node Prev;
        public Node Next;

        public Node() {}

        public Node(int key, int val) {
            Key = key;
            Val = val;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<div class="title__3Vvk">请你设计并实现一个满足&nbsp; <a href="https://baike.baidu.com/item/LRU" target="_blank">LRU (最近最少使用) 缓存</a> 约束的数据结构。</div>

<div class="title__3Vvk">实现 <code>LRUCache</code> 类：</div>

<div class="original__bRMd">
<div>
<ul>
	<li><code>LRUCache(int capacity)</code> 以 <strong>正整数</strong> 作为容量&nbsp;<code>capacity</code> 初始化 LRU 缓存</li>
	<li><code>int get(int key)</code> 如果关键字 <code>key</code> 存在于缓存中，则返回关键字的值，否则返回 <code>-1</code> 。</li>
	<li><code>void put(int key, int value)</code>&nbsp;如果关键字&nbsp;<code>key</code> 已经存在，则变更其数据值&nbsp;<code>value</code> ；如果不存在，则向缓存中插入该组&nbsp;<code>key-value</code> 。如果插入操作导致关键字数量超过&nbsp;<code>capacity</code> ，则应该 <strong>逐出</strong> 最久未使用的关键字。</li>
</ul>

<p>函数 <code>get</code> 和 <code>put</code> 必须以 <code>O(1)</code> 的平均时间复杂度运行。</p>
</div>
</div>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>输出</strong>
[null, null, null, 1, null, -1, null, -1, 3, 4]

<strong>解释</strong>
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
	<li><code>0 &lt;= key &lt;= 10000</code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>2 * 10<sup>5</sup></code> 次 <code>get</code> 和 <code>put</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双向链表

我们可以用“哈希表”和“双向链表”实现一个 LRU 缓存。

-   哈希表：用于存储 key 和对应的节点位置。
-   双向链表：用于存储节点数据，按照访问时间排序。

当访问一个节点时，如果节点存在，我们将其从原来的位置删除，并重新插入到链表头部。这样就能保证链表尾部存储的就是最近最久未使用的节点，当节点数量大于缓存最大空间时就淘汰链表尾部的节点。

当插入一个节点时，如果节点存在，我们将其从原来的位置删除，并重新插入到链表头部。如果不存在，我们首先检查缓存是否已满，如果已满，则删除链表尾部的节点，将新的节点插入链表头部。

时间复杂度 $O(1)$，空间复杂度 $O(\textit{capacity})$。

<!-- tabs:start -->

#### Python3

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

#### Java

```java
class Node {
    int key, val;
    Node prev, next;

    Node() {
    }

    Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    private int size;
    private int capacity;
    private Node head = new Node();
    private Node tail = new Node();
    private Map<Integer, Node> cache = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        Node node = cache.get(key);
        removeNode(node);
        addToHead(node);
        return node.val;
    }

    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            removeNode(node);
            node.val = value;
            addToHead(node);
        } else {
            Node node = new Node(key, value);
            cache.put(key, node);
            addToHead(node);
            if (++size > capacity) {
                node = tail.prev;
                cache.remove(node.key);
                removeNode(node);
                --size;
            }
        }
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void addToHead(Node node) {
        node.next = head.next;
        node.prev = head;
        head.next = node;
        node.next.prev = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```

#### C++

```cpp
class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val)
            : key(key)
            , val(val)
            , prev(nullptr)
            , next(nullptr) {}
    };

    int size;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
        : size(0)
        , capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }
        Node* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            if (++size > capacity) {
                node = tail->prev;
                cache.erase(node->key);
                removeNode(node);
                --size;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

#### Go

```go
type Node struct {
	key, val   int
	prev, next *Node
}

type LRUCache struct {
	size, capacity int
	head, tail     *Node
	cache          map[int]*Node
}

func Constructor(capacity int) LRUCache {
	head := &Node{}
	tail := &Node{}
	head.next = tail
	tail.prev = head
	return LRUCache{
		capacity: capacity,
		head:     head,
		tail:     tail,
		cache:    make(map[int]*Node),
	}
}

func (this *LRUCache) Get(key int) int {
	if node, exists := this.cache[key]; exists {
		this.removeNode(node)
		this.addToHead(node)
		return node.val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if node, exists := this.cache[key]; exists {
		this.removeNode(node)
		node.val = value
		this.addToHead(node)
	} else {
		node := &Node{key: key, val: value}
		this.cache[key] = node
		this.addToHead(node)
		if this.size++; this.size > this.capacity {
			node = this.tail.prev
			delete(this.cache, node.key)
			this.removeNode(node)
			this.size--
		}
	}
}

func (this *LRUCache) removeNode(node *Node) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LRUCache) addToHead(node *Node) {
	node.next = this.head.next
	node.prev = this.head
	this.head.next = node
	node.next.prev = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
```

#### TypeScript

```ts
class Node {
    key: number;
    val: number;
    prev: Node | null;
    next: Node | null;

    constructor(key: number, val: number) {
        this.key = key;
        this.val = val;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    private size: number;
    private capacity: number;
    private head: Node;
    private tail: Node;
    private cache: Map<number, Node>;

    constructor(capacity: number) {
        this.size = 0;
        this.capacity = capacity;
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.cache = new Map();
    }

    get(key: number): number {
        if (!this.cache.has(key)) {
            return -1;
        }
        const node = this.cache.get(key)!;
        this.removeNode(node);
        this.addToHead(node);
        return node.val;
    }

    put(key: number, value: number): void {
        if (this.cache.has(key)) {
            const node = this.cache.get(key)!;
            this.removeNode(node);
            node.val = value;
            this.addToHead(node);
        } else {
            const node = new Node(key, value);
            this.cache.set(key, node);
            this.addToHead(node);
            if (++this.size > this.capacity) {
                const nodeToRemove = this.tail.prev!;
                this.cache.delete(nodeToRemove.key);
                this.removeNode(nodeToRemove);
                --this.size;
            }
        }
    }

    private removeNode(node: Node): void {
        if (!node) return;
        node.prev!.next = node.next;
        node.next!.prev = node.prev;
    }

    private addToHead(node: Node): void {
        node.next = this.head.next;
        node.prev = this.head;
        this.head.next!.prev = node;
        this.head.next = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```

#### Rust

```rust
use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

struct Node {
    key: i32,
    value: i32,
    prev: Option<Rc<RefCell<Node>>>,
    next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    #[inline]
    fn new(key: i32, value: i32) -> Self {
        Self {
            key,
            value,
            prev: None,
            next: None,
        }
    }
}

struct LRUCache {
    capacity: usize,
    cache: HashMap<i32, Rc<RefCell<Node>>>,
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity as usize,
            cache: HashMap::new(),
            head: None,
            tail: None,
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                self.remove(&node);
                self.push_front(&node);
                let value = node.borrow().value;
                value
            }
            None => -1,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        match self.cache.get(&key) {
            Some(node) => {
                let node = Rc::clone(node);
                node.borrow_mut().value = value;
                self.remove(&node);
                self.push_front(&node);
            }
            None => {
                let node = Rc::new(RefCell::new(Node::new(key, value)));
                self.cache.insert(key, Rc::clone(&node));
                self.push_front(&node);
                if self.cache.len() > self.capacity {
                    let back_key = self.pop_back().unwrap().borrow().key;
                    self.cache.remove(&back_key);
                }
            }
        };
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
}
```

#### JavaScript

```js
/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    this.size = 0;
    this.capacity = capacity;
    this.cache = new Map();
    this.head = new Node(0, 0);
    this.tail = new Node(0, 0);
    this.head.next = this.tail;
    this.tail.prev = this.head;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
    if (!this.cache.has(key)) {
        return -1;
    }
    const node = this.cache.get(key);
    this.removeNode(node);
    this.addToHead(node);
    return node.val;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
    if (this.cache.has(key)) {
        const node = this.cache.get(key);
        this.removeNode(node);
        node.val = value;
        this.addToHead(node);
    } else {
        const node = new Node(key, value);
        this.cache.set(key, node);
        this.addToHead(node);
        if (++this.size > this.capacity) {
            const nodeToRemove = this.tail.prev;
            this.cache.delete(nodeToRemove.key);
            this.removeNode(nodeToRemove);
            --this.size;
        }
    }
};

LRUCache.prototype.removeNode = function (node) {
    if (!node) return;
    node.prev.next = node.next;
    node.next.prev = node.prev;
};

LRUCache.prototype.addToHead = function (node) {
    node.next = this.head.next;
    node.prev = this.head;
    this.head.next.prev = node;
    this.head.next = node;
};

/**
 * @constructor
 * @param {number} key
 * @param {number} val
 */
function Node(key, val) {
    this.key = key;
    this.val = val;
    this.prev = null;
    this.next = null;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```

#### C#

```cs
public class LRUCache {
    private int size;
    private int capacity;
    private Dictionary<int, Node> cache = new Dictionary<int, Node>();
    private Node head = new Node();
    private Node tail = new Node();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.Next = tail;
        tail.Prev = head;
    }

    public int Get(int key) {
        if (!cache.ContainsKey(key)) {
            return -1;
        }
        Node node = cache[key];
        RemoveNode(node);
        AddToHead(node);
        return node.Val;
    }

    public void Put(int key, int value) {
        if (cache.ContainsKey(key)) {
            Node node = cache[key];
            RemoveNode(node);
            node.Val = value;
            AddToHead(node);
        } else {
            Node node = new Node(key, value);
            cache[key] = node;
            AddToHead(node);
            if (++size > capacity) {
                node = tail.Prev;
                cache.Remove(node.Key);
                RemoveNode(node);
                --size;
            }
        }
    }

    private void RemoveNode(Node node) {
        node.Prev.Next = node.Next;
        node.Next.Prev = node.Prev;
    }

    private void AddToHead(Node node) {
        node.Next = head.Next;
        node.Prev = head;
        head.Next = node;
        node.Next.Prev = node;
    }

    // Node class to represent each entry in the cache.
    private class Node {
        public int Key;
        public int Val;
        public Node Prev;
        public Node Next;

        public Node() {}

        public Node(int key, int val) {
            Key = key;
            Val = val;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list){#147}

{{< tabs "147" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        dummy = ListNode(head.val, head)
        pre, cur = dummy, head
        while cur:
            if pre.val <= cur.val:
                pre, cur = cur, cur.next
                continue
            p = dummy
            while p.next.val <= cur.val:
                p = p.next
            t = cur.next
            cur.next = p.next
            p.next = cur
            pre.next = t
            cur = t
        return dummy.next
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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(head.val, head);
        ListNode pre = dummy, cur = head;
        while (cur != null) {
            if (pre.val <= cur.val) {
                pre = cur;
                cur = cur.next;
                continue;
            }
            ListNode p = dummy;
            while (p.next.val <= cur.val) {
                p = p.next;
            }
            ListNode t = cur.next;
            cur.next = p.next;
            p.next = cur;
            pre.next = t;
            cur = t;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertionSortList = function (head) {
    if (head == null || head.next == null) return head;
    let dummy = new ListNode(head.val, head);
    let prev = dummy,
        cur = head;
    while (cur != null) {
        if (prev.val <= cur.val) {
            prev = cur;
            cur = cur.next;
            continue;
        }
        let p = dummy;
        while (p.next.val <= cur.val) {
            p = p.next;
        }
        let t = cur.next;
        cur.next = p.next;
        p.next = cur;
        prev.next = t;
        cur = t;
    }
    return dummy.next;
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
func insertionSortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	dummy := &ListNode{head.Val, head}
	pre, cur := dummy, head
	for cur != nil {
		if pre.Val <= cur.Val {
			pre = cur
			cur = cur.Next
			continue
		}
		p := dummy
		for p.Next.Val <= cur.Val {
			p = p.Next
		}
		t := cur.Next
		cur.Next = p.Next
		p.Next = cur
		pre.Next = t
		cur = t
	}
	return dummy.Next
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定单个链表的头<meta charset="UTF-8" />&nbsp;<code>head</code>&nbsp;，使用 <strong>插入排序</strong> 对链表进行排序，并返回&nbsp;<em>排序后链表的头</em>&nbsp;。</p>

<p><strong>插入排序</strong>&nbsp;算法的步骤:</p>

<ol>
	<li>插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。</li>
	<li>每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。</li>
	<li>重复直到所有输入数据插入完为止。</li>
</ol>

<p>下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。</p>

<p>对链表进行插入排序。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0147.Insertion%20Sort%20List/images/1724130387-qxfMwx-Insertion-sort-example-300px.gif" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0147.Insertion%20Sort%20List/images/1724130414-QbPAjl-image.png" /></p>

<pre>
<strong>输入:</strong> head = [4,2,1,3]
<strong>输出:</strong> [1,2,3,4]</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0147.Insertion%20Sort%20List/images/1724130432-zoOvdI-image.png" /></p>

<pre>
<strong>输入:</strong> head = [-1,5,3,4,0]
<strong>输出:</strong> [-1,0,3,4,5]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li>列表中的节点数在&nbsp;<code>[1, 5000]</code>范围内</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
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
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        dummy = ListNode(head.val, head)
        pre, cur = dummy, head
        while cur:
            if pre.val <= cur.val:
                pre, cur = cur, cur.next
                continue
            p = dummy
            while p.next.val <= cur.val:
                p = p.next
            t = cur.next
            cur.next = p.next
            p.next = cur
            pre.next = t
            cur = t
        return dummy.next
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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(head.val, head);
        ListNode pre = dummy, cur = head;
        while (cur != null) {
            if (pre.val <= cur.val) {
                pre = cur;
                cur = cur.next;
                continue;
            }
            ListNode p = dummy;
            while (p.next.val <= cur.val) {
                p = p.next;
            }
            ListNode t = cur.next;
            cur.next = p.next;
            p.next = cur;
            pre.next = t;
            cur = t;
        }
        return dummy.next;
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertionSortList = function (head) {
    if (head == null || head.next == null) return head;
    let dummy = new ListNode(head.val, head);
    let prev = dummy,
        cur = head;
    while (cur != null) {
        if (prev.val <= cur.val) {
            prev = cur;
            cur = cur.next;
            continue;
        }
        let p = dummy;
        while (p.next.val <= cur.val) {
            p = p.next;
        }
        let t = cur.next;
        cur.next = p.next;
        p.next = cur;
        prev.next = t;
        cur = t;
    }
    return dummy.next;
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
func insertionSortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	dummy := &ListNode{head.Val, head}
	pre, cur := dummy, head
	for cur != nil {
		if pre.Val <= cur.Val {
			pre = cur
			cur = cur.Next
			continue
		}
		p := dummy
		for p.Next.Val <= cur.Val {
			p = p.Next
		}
		t := cur.Next
		cur.Next = p.Next
		p.Next = cur
		pre.Next = t
		cur = t
	}
	return dummy.Next
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [148. 排序链表](https://leetcode.cn/problems/sort-list){#148}

{{< tabs "148" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        l1, l2 = head, slow.next
        slow.next = None
        l1, l2 = self.sortList(l1), self.sortList(l2)
        dummy = ListNode()
        tail = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        tail.next = l1 or l2
        return dummy.next
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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l1 = head, l2 = slow.next;
        slow.next = null;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        tail.next = l1 != null ? l1 : l2;
        return dummy.next;
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
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
func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	l1 := head
	l2 := slow.Next
	slow.Next = nil
	l1 = sortList(l1)
	l2 = sortList(l2)
	dummy := &ListNode{}
	tail := dummy
	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
	}
	if l1 != nil {
		tail.Next = l1
	} else {
		tail.Next = l2
	}
	return dummy.Next
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

function sortList(head: ListNode | null): ListNode | null {
    if (head === null || head.next === null) {
        return head;
    }
    let [slow, fast] = [head, head.next];
    while (fast !== null && fast.next !== null) {
        slow = slow.next!;
        fast = fast.next.next;
    }
    let [l1, l2] = [head, slow.next];
    slow.next = null;
    l1 = sortList(l1);
    l2 = sortList(l2);
    const dummy = new ListNode();
    let tail = dummy;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    tail.next = l1 ?? l2;
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        fn merge(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            match (l1, l2) {
                (None, Some(node)) | (Some(node), None) => Some(node),
                (Some(mut node1), Some(mut node2)) => {
                    if node1.val < node2.val {
                        node1.next = merge(node1.next.take(), Some(node2));
                        Some(node1)
                    } else {
                        node2.next = merge(Some(node1), node2.next.take());
                        Some(node2)
                    }
                }
                _ => None,
            }
        }

        fn sort(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            if head.is_none() || head.as_ref().unwrap().next.is_none() {
                return head;
            }
            let mut head = head;
            let mut length = 0;
            let mut cur = &head;
            while cur.is_some() {
                length += 1;
                cur = &cur.as_ref().unwrap().next;
            }
            let mut cur = &mut head;
            for _ in 0..length / 2 - 1 {
                cur = &mut cur.as_mut().unwrap().next;
            }
            let right = cur.as_mut().unwrap().next.take();

            merge(sort(head), sort(right))
        }
        sort(head)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function (head) {
    if (head === null || head.next === null) {
        return head;
    }
    let [slow, fast] = [head, head.next];
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let [l1, l2] = [head, slow.next];
    slow.next = null;
    l1 = sortList(l1);
    l2 = sortList(l2);
    const dummy = new ListNode();
    let tail = dummy;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    tail.next = l1 ?? l2;
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l1 = head, l2 = slow.next;
        slow.next = null;
        l1 = SortList(l1);
        l2 = SortList(l2);
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        tail.next = l1 != null ? l1 : l2;
        return dummy.next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你链表的头结点&nbsp;<code>head</code>&nbsp;，请将其按 <strong>升序</strong> 排列并返回 <strong>排序后的链表</strong> 。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0148.Sort%20List/images/sort_list_1.jpg" style="width: 450px;" />
<pre>
<b>输入：</b>head = [4,2,1,3]
<b>输出：</b>[1,2,3,4]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0148.Sort%20List/images/sort_list_2.jpg" style="width: 550px;" />
<pre>
<b>输入：</b>head = [-1,5,3,4,0]
<b>输出：</b>[-1,0,3,4,5]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>head = []
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li>链表中节点的数目在范围&nbsp;<code>[0, 5 * 10<sup>4</sup>]</code>&nbsp;内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你可以在&nbsp;<code>O(n&nbsp;log&nbsp;n)</code> 时间复杂度和常数级空间复杂度下，对链表进行排序吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：归并排序

我们可以用归并排序的思想来解决。

首先，我们利用快慢指针找到链表的中点，将链表从中点处断开，形成两个独立的子链表 $\textit{l1}$ 和 $\textit{l2}$。

然后，我们递归地对 $\textit{l1}$ 和 $\textit{l2}$ 进行排序，最后将 $\textit{l1}$ 和 $\textit{l2}$ 合并为一个有序链表。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        l1, l2 = head, slow.next
        slow.next = None
        l1, l2 = self.sortList(l1), self.sortList(l2)
        dummy = ListNode()
        tail = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        tail.next = l1 or l2
        return dummy.next
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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l1 = head, l2 = slow.next;
        slow.next = null;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        tail.next = l1 != null ? l1 : l2;
        return dummy.next;
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
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
func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	l1 := head
	l2 := slow.Next
	slow.Next = nil
	l1 = sortList(l1)
	l2 = sortList(l2)
	dummy := &ListNode{}
	tail := dummy
	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
	}
	if l1 != nil {
		tail.Next = l1
	} else {
		tail.Next = l2
	}
	return dummy.Next
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

function sortList(head: ListNode | null): ListNode | null {
    if (head === null || head.next === null) {
        return head;
    }
    let [slow, fast] = [head, head.next];
    while (fast !== null && fast.next !== null) {
        slow = slow.next!;
        fast = fast.next.next;
    }
    let [l1, l2] = [head, slow.next];
    slow.next = null;
    l1 = sortList(l1);
    l2 = sortList(l2);
    const dummy = new ListNode();
    let tail = dummy;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    tail.next = l1 ?? l2;
    return dummy.next;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        fn merge(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            match (l1, l2) {
                (None, Some(node)) | (Some(node), None) => Some(node),
                (Some(mut node1), Some(mut node2)) => {
                    if node1.val < node2.val {
                        node1.next = merge(node1.next.take(), Some(node2));
                        Some(node1)
                    } else {
                        node2.next = merge(Some(node1), node2.next.take());
                        Some(node2)
                    }
                }
                _ => None,
            }
        }

        fn sort(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            if head.is_none() || head.as_ref().unwrap().next.is_none() {
                return head;
            }
            let mut head = head;
            let mut length = 0;
            let mut cur = &head;
            while cur.is_some() {
                length += 1;
                cur = &cur.as_ref().unwrap().next;
            }
            let mut cur = &mut head;
            for _ in 0..length / 2 - 1 {
                cur = &mut cur.as_mut().unwrap().next;
            }
            let right = cur.as_mut().unwrap().next.take();

            merge(sort(head), sort(right))
        }
        sort(head)
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var sortList = function (head) {
    if (head === null || head.next === null) {
        return head;
    }
    let [slow, fast] = [head, head.next];
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let [l1, l2] = [head, slow.next];
    slow.next = null;
    l1 = sortList(l1);
    l2 = sortList(l2);
    const dummy = new ListNode();
    let tail = dummy;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            tail.next = l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    tail.next = l1 ?? l2;
    return dummy.next;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l1 = head, l2 = slow.next;
        slow.next = null;
        l1 = SortList(l1);
        l2 = SortList(l2);
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        tail.next = l1 != null ? l1 : l2;
        return dummy.next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [149. 直线上最多的点数](https://leetcode.cn/problems/max-points-on-a-line){#149}

{{< tabs "149" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)

        n = len(points)
        ans = 1
        for i in range(n):
            x1, y1 = points[i]
            cnt = Counter()
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx, dy = x2 - x1, y2 - y1
                g = gcd(dx, dy)
                k = (dx // g, dy // g)
                cnt[k] += 1
                ans = max(ans, cnt[k] + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            Map<String, Integer> cnt = new HashMap<>();
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                String k = (dx / g) + "." + (dy / g);
                cnt.put(k, cnt.getOrDefault(k, 0) + 1);
                ans = Math.max(ans, cnt.get(k) + 1);
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<string, int> cnt;
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                string k = to_string(dx / g) + "." + to_string(dy / g);
                cnt[k]++;
                ans = max(ans, cnt[k] + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPoints(points [][]int) int {
	n := len(points)
	ans := 1
	type pair struct{ x, y int }
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		cnt := map[pair]int{}
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			dx, dy := x2-x1, y2-y1
			g := gcd(dx, dy)
			k := pair{dx / g, dy / g}
			cnt[k]++
			if ans < cnt[k]+1 {
				ans = cnt[k] + 1
			}
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxPoints(int[][] points) {
        int n = points.Length;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int a = (y2 - y1) * (x3 - x1);
                    int b = (y3 - y1) * (x2 - x1);
                    if (a == b) {
                        ++cnt;
                    }
                }
                if (ans < cnt) {
                    ans = cnt;
                }
            }
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>points</code> ，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示 <strong>X-Y</strong> 平面上的一个点。求最多有多少个点在同一条直线上。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0149.Max%20Points%20on%20a%20Line/images/plane1.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0100-0199/0149.Max%20Points%20on%20a%20Line/images/plane2.jpg" style="width: 300px; height: 294px;" />
<pre>
<strong>输入：</strong>points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= points.length <= 300</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>4</sup></code></li>
	<li><code>points</code> 中的所有点 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们可以枚举任意两个点 $(x_1, y_1), (x_2, y_2)$，把这两个点连成一条直线，那么此时这条直线上的点的个数就是 2，接下来我们再枚举其他点 $(x_3, y_3)$，判断它们是否在同一条直线上，如果在，那么直线上的点的个数就加 1，如果不在，那么直线上的点的个数不变。找出所有直线上的点的个数的最大值，即为答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(1)$。其中 $n$ 是数组 `points` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                cnt = 2
                for k in range(j + 1, n):
                    x3, y3 = points[k]
                    a = (y2 - y1) * (x3 - x1)
                    b = (y3 - y1) * (x2 - x1)
                    cnt += a == b
                ans = max(ans, cnt)
        return ans
```

#### Java

```java
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int a = (y2 - y1) * (x3 - x1);
                    int b = (y3 - y1) * (x2 - x1);
                    if (a == b) {
                        ++cnt;
                    }
                }
                ans = Math.max(ans, cnt);
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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int a = (y2 - y1) * (x3 - x1);
                    int b = (y3 - y1) * (x2 - x1);
                    cnt += a == b;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxPoints(points [][]int) int {
	n := len(points)
	ans := 1
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			cnt := 2
			for k := j + 1; k < n; k++ {
				x3, y3 := points[k][0], points[k][1]
				a := (y2 - y1) * (x3 - x1)
				b := (y3 - y1) * (x2 - x1)
				if a == b {
					cnt++
				}
			}
			if ans < cnt {
				ans = cnt
			}
		}
	}
	return ans
}
```

#### C#

```cs
public class Solution {
    public int MaxPoints(int[][] points) {
        int n = points.Length;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int a = (y2 - y1) * (x3 - x1);
                    int b = (y3 - y1) * (x2 - x1);
                    if (a == b) {
                        ++cnt;
                    }
                }
                if (ans < cnt) {
                    ans = cnt;
                }
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举 + 哈希表

我们可以枚举一个点 $(x_1, y_1)$，把其他所有点 $(x_2, y_2)$ 与 $(x_1, y_1)$ 连成的直线的斜率存入哈希表中，斜率相同的点在同一条直线上，哈希表的键为斜率，值为直线上的点的个数。找出哈希表中的最大值，即为答案。为了避免精度问题，我们可以将斜率 $\frac{y_2 - y_1}{x_2 - x_1}$ 进行约分，约分的方法是求最大公约数，然后分子分母同时除以最大公约数，将求得的分子分母作为哈希表的键。

时间复杂度 $O(n^2 \times \log m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 `points` 的长度和数组 `points` 所有横纵坐标差的最大值。

相似题目：

-   [面试题 16.14. 最佳直线](https://github.com/doocs/leetcode/blob/main/lcci/16.14.Best%20Line/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)

        n = len(points)
        ans = 1
        for i in range(n):
            x1, y1 = points[i]
            cnt = Counter()
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx, dy = x2 - x1, y2 - y1
                g = gcd(dx, dy)
                k = (dx // g, dy // g)
                cnt[k] += 1
                ans = max(ans, cnt[k] + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            Map<String, Integer> cnt = new HashMap<>();
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                String k = (dx / g) + "." + (dy / g);
                cnt.put(k, cnt.getOrDefault(k, 0) + 1);
                ans = Math.max(ans, cnt.get(k) + 1);
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<string, int> cnt;
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                int g = gcd(dx, dy);
                string k = to_string(dx / g) + "." + to_string(dy / g);
                cnt[k]++;
                ans = max(ans, cnt[k] + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxPoints(points [][]int) int {
	n := len(points)
	ans := 1
	type pair struct{ x, y int }
	for i := 0; i < n; i++ {
		x1, y1 := points[i][0], points[i][1]
		cnt := map[pair]int{}
		for j := i + 1; j < n; j++ {
			x2, y2 := points[j][0], points[j][1]
			dx, dy := x2-x1, y2-y1
			g := gcd(dx, dy)
			k := pair{dx / g, dy / g}
			cnt[k]++
			if ans < cnt[k]+1 {
				ans = cnt[k] + 1
			}
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

---
title: "1160_拼写单词"
date: 2025-10-08T18:36:57+08:00
weight: 7
tags: [二叉树, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 并查集, 广度优先搜索, 排序, 数据库, 数组, 最小生成树, 树, 深度优先搜索, 矩阵, 计数, 设计, 贪心]
---

{{< markmap >}}
### [1160_拼写单词](#1160)
#### [数组](#1160)
#### [哈希表](#1160)
#### [字符串](#1160)
#### [计数](#1160)
### [1161_最大层内元素和](#1161)
#### [树](#1161)
#### [深度优先搜索](#1161)
#### [广度优先搜索](#1161)
#### [二叉树](#1161)
### [1162_地图分析](#1162)
#### [广度优先搜索](#1162)
#### [数组](#1162)
#### [动态规划](#1162)
#### [矩阵](#1162)
### [1163_按字典序排在最后的子串](#1163)
#### [双指针](#1163)
#### [字符串](#1163)
### [1164_指定日期的产品价格](#1164)
#### [数据库](#1164)
### [1165_单行键盘 🔒](#1165)
#### [哈希表](#1165)
#### [字符串](#1165)
### [1166_设计文件系统 🔒](#1166)
#### [设计](#1166)
#### [字典树](#1166)
#### [哈希表](#1166)
#### [字符串](#1166)
### [1167_连接木棍的最低费用 🔒](#1167)
#### [贪心](#1167)
#### [数组](#1167)
#### [堆（优先队列）](#1167)
### [1168_水资源分配优化 🔒](#1168)
#### [并查集](#1168)
#### [图](#1168)
#### [最小生成树](#1168)
#### [堆（优先队列）](#1168)
### [1169_查询无效交易](#1169)
#### [数组](#1169)
#### [哈希表](#1169)
#### [字符串](#1169)
#### [排序](#1169)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1160_拼写单词
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1161_最大层内元素和
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1162_地图分析
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1163_按字典序排在最后的子串
___
#### 双指针
___
#### 字符串
---
### 1164_指定日期的产品价格
___
#### 数据库
---
### 1165_单行键盘 🔒
___
#### 哈希表
___
#### 字符串
---
### 1166_设计文件系统 🔒
___
#### 设计
___
#### 字典树
___
#### 哈希表
___
#### 字符串
---
### 1167_连接木棍的最低费用 🔒
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 1168_水资源分配优化 🔒
___
#### 并查集
___
#### 图
___
#### 最小生成树
___
#### 堆（优先队列）
---
### 1169_查询无效交易
___
#### 数组
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
| 二叉树 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字典树 | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数据库 |
| 数组 | 最小生成树 | 树 |
| 深度优先搜索 | 矩阵 | 计数 |
| 设计 | 贪心 |  |

# [1160. 拼写单词](https://leetcode.cn/problems/find-words-that-can-be-formed-by-characters){#1160}

{{< tabs "1160" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        cnt = Counter(chars)
        ans = 0
        for w in words:
            wc = Counter(w)
            if all(cnt[c] >= v for c, v in wc.items()):
                ans += len(w)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] cnt = new int[26];
        for (int i = 0; i < chars.length(); ++i) {
            ++cnt[chars.charAt(i) - 'a'];
        }
        int ans = 0;
        for (String w : words) {
            int[] wc = new int[26];
            boolean ok = true;
            for (int i = 0; i < w.length(); ++i) {
                int j = w.charAt(i) - 'a';
                if (++wc[j] > cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += w.length();
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
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26]{};
        for (char& c : chars) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (auto& w : words) {
            int wc[26]{};
            bool ok = true;
            for (auto& c : w) {
                int i = c - 'a';
                if (++wc[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += w.size();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCharacters(words []string, chars string) (ans int) {
	cnt := [26]int{}
	for _, c := range chars {
		cnt[c-'a']++
	}
	for _, w := range words {
		wc := [26]int{}
		ok := true
		for _, c := range w {
			c -= 'a'
			wc[c]++
			if wc[c] > cnt[c] {
				ok = false
				break
			}
		}
		if ok {
			ans += len(w)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCharacters(words: string[], chars: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const cnt = new Array(26).fill(0);
    for (const c of chars) {
        cnt[idx(c)]++;
    }
    let ans = 0;
    for (const w of words) {
        const wc = new Array(26).fill(0);
        let ok = true;
        for (const c of w) {
            if (++wc[idx(c)] > cnt[idx(c)]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans += w.length;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $sum = 0;
        for ($i = 0; $i < strlen($chars); $i++) {
            $hashtable[$chars[$i]] += 1;
        }
        for ($j = 0; $j < count($words); $j++) {
            $tmp = $hashtable;
            $sum += strlen($words[$j]);
            for ($k = 0; $k < strlen($words[$j]); $k++) {
                if (!isset($tmp[$words[$j][$k]]) || $tmp[$words[$j][$k]] === 0) {
                    $sum -= strlen($words[$j]);
                    break;
                }
                $tmp[$words[$j][$k]] -= 1;
            }
        }
        return $sum;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串数组&nbsp;<code>words</code>&nbsp;和一个字符串 <code>chars</code>。</p>

<p>如果字符串可以由 <code>chars</code> 中的字符组成（每个字符在 <strong>每个</strong>&nbsp;<code>words</code> 中只能使用一次），则认为它是好的。</p>

<p>返回&nbsp;<code>words</code>&nbsp;中所有好的字符串的长度之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["cat","bt","hat","tree"], chars = "atach"
<strong>输出：</strong>6
<strong>解释： </strong>
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["hello","world","leetcode"], chars = "welldonehoneyr"
<strong>输出：</strong>10
<strong>解释：</strong>
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, chars.length&nbsp;&lt;= 100</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>chars</code> 中都仅包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个长度为 $26$ 的数组 $cnt$ 统计字符串 $chars$ 中每个字母出现的次数。

然后遍历字符串数组 $words$，对于每个字符串 $w$，我们用一个长度为 $26$ 的数组 $wc$ 统计字符串 $w$ 中每个字母出现的次数，如果对于每个字母 $c$，$wc[c] \leq cnt[c]$，那么我们就可以用 $chars$ 中的字母拼写出字符串 $w$，否则我们无法拼写出字符串 $w$。如果可以拼写出字符串 $w$，那么我们就将字符串 $w$ 的长度加到答案中。

遍历结束后，即可得到答案。

时间复杂度 $(L)$，空间复杂度 $O(C)$。其中 $L$ 为题目中所有字符串的长度之和；而 $C$ 为字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        cnt = Counter(chars)
        ans = 0
        for w in words:
            wc = Counter(w)
            if all(cnt[c] >= v for c, v in wc.items()):
                ans += len(w)
        return ans
```

#### Java

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] cnt = new int[26];
        for (int i = 0; i < chars.length(); ++i) {
            ++cnt[chars.charAt(i) - 'a'];
        }
        int ans = 0;
        for (String w : words) {
            int[] wc = new int[26];
            boolean ok = true;
            for (int i = 0; i < w.length(); ++i) {
                int j = w.charAt(i) - 'a';
                if (++wc[j] > cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += w.length();
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
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26]{};
        for (char& c : chars) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (auto& w : words) {
            int wc[26]{};
            bool ok = true;
            for (auto& c : w) {
                int i = c - 'a';
                if (++wc[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += w.size();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countCharacters(words []string, chars string) (ans int) {
	cnt := [26]int{}
	for _, c := range chars {
		cnt[c-'a']++
	}
	for _, w := range words {
		wc := [26]int{}
		ok := true
		for _, c := range w {
			c -= 'a'
			wc[c]++
			if wc[c] > cnt[c] {
				ok = false
				break
			}
		}
		if ok {
			ans += len(w)
		}
	}
	return
}
```

#### TypeScript

```ts
function countCharacters(words: string[], chars: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const cnt = new Array(26).fill(0);
    for (const c of chars) {
        cnt[idx(c)]++;
    }
    let ans = 0;
    for (const w of words) {
        const wc = new Array(26).fill(0);
        let ok = true;
        for (const c of w) {
            if (++wc[idx(c)] > cnt[idx(c)]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans += w.length;
        }
    }
    return ans;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $sum = 0;
        for ($i = 0; $i < strlen($chars); $i++) {
            $hashtable[$chars[$i]] += 1;
        }
        for ($j = 0; $j < count($words); $j++) {
            $tmp = $hashtable;
            $sum += strlen($words[$j]);
            for ($k = 0; $k < strlen($words[$j]); $k++) {
                if (!isset($tmp[$words[$j][$k]]) || $tmp[$words[$j][$k]] === 0) {
                    $sum -= strlen($words[$j]);
                    break;
                }
                $tmp[$words[$j][$k]] -= 1;
            }
        }
        return $sum;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1161. 最大层内元素和](https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree){#1161}

{{< tabs "1161" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        def dfs(node, i):
            if node is None:
                return
            if i == len(s):
                s.append(node.val)
            else:
                s[i] += node.val
            dfs(node.left, i + 1)
            dfs(node.right, i + 1)

        s = []
        dfs(root, 0)
        return s.index(max(s)) + 1
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
    private List<Integer> s = new ArrayList<>();

    public int maxLevelSum(TreeNode root) {
        dfs(root, 0);
        int mx = Integer.MIN_VALUE;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mx < s.get(i)) {
                mx = s.get(i);
                ans = i + 1;
            }
        }
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i == s.size()) {
            s.add(root.val);
        } else {
            s.set(i, s.get(i) + root.val);
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
    int maxLevelSum(TreeNode* root) {
        vector<int> s;
        dfs(root, 0, s);
        int mx = INT_MIN;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
            if (mx < s[i]) mx = s[i], ans = i + 1;
        return ans;
    }

    void dfs(TreeNode* root, int i, vector<int>& s) {
        if (!root) return;
        if (s.size() == i)
            s.push_back(root->val);
        else
            s[i] += root->val;
        dfs(root->left, i + 1, s);
        dfs(root->right, i + 1, s);
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
func maxLevelSum(root *TreeNode) int {
	s := []int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if len(s) == i {
			s = append(s, root.Val)
		} else {
			s[i] += root.Val
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 0)
	ans, mx := 0, -0x3f3f3f3f
	for i, v := range s {
		if mx < v {
			mx = v
			ans = i + 1
		}
	}
	return ans
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

function maxLevelSum(root: TreeNode | null): number {
    const queue = [root];
    let res = 1;
    let max = -Infinity;
    let h = 1;
    while (queue.length !== 0) {
        const n = queue.length;
        let sum = 0;
        for (let i = 0; i < n; i++) {
            const { val, left, right } = queue.shift();
            sum += val;
            left && queue.push(left);
            right && queue.push(right);
        }
        if (sum > max) {
            max = sum;
            res = h;
        }
        h++;
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉树的根节点&nbsp;<code>root</code>。设根节点位于二叉树的第 <code>1</code> 层，而根节点的子节点位于第 <code>2</code> 层，依此类推。</p>

<p>请返回层内元素之和 <strong>最大</strong> 的那几层（可能只有一层）的层号，并返回其中&nbsp;<strong>最小</strong> 的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1161.Maximum%20Level%20Sum%20of%20a%20Binary%20Tree/images/capture.jpeg" style="height: 175px; width: 200px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,7,0,7,-8,null,null]
<strong>输出：</strong>2
<strong>解释：</strong>
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [989,null,10250,98693,-89388,null,null,null,-32127]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 10<sup>4</sup>]</code>范围内<meta charset="UTF-8" /></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

BFS 层次遍历，求每一层的节点和，找出节点和最大的层，若有多个层的节点和最大，则返回最小的层。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

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
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        mx = -inf
        i = 0
        while q:
            i += 1
            s = 0
            for _ in range(len(q)):
                node = q.popleft()
                s += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if mx < s:
                mx = s
                ans = i
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
    public int maxLevelSum(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int mx = Integer.MIN_VALUE;
        int i = 0;
        int ans = 0;
        while (!q.isEmpty()) {
            ++i;
            int s = 0;
            for (int n = q.size(); n > 0; --n) {
                TreeNode node = q.pollFirst();
                s += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            if (mx < s) {
                mx = s;
                ans = i;
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int mx = INT_MIN;
        int ans = 0;
        int i = 0;
        while (!q.empty()) {
            ++i;
            int s = 0;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                s += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (mx < s) mx = s, ans = i;
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
func maxLevelSum(root *TreeNode) int {
	q := []*TreeNode{root}
	mx := -0x3f3f3f3f
	i := 0
	ans := 0
	for len(q) > 0 {
		i++
		s := 0
		for n := len(q); n > 0; n-- {
			root = q[0]
			q = q[1:]
			s += root.Val
			if root.Left != nil {
				q = append(q, root.Left)
			}
			if root.Right != nil {
				q = append(q, root.Right)
			}
		}
		if mx < s {
			mx = s
			ans = i
		}
	}
	return ans
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

function maxLevelSum(root: TreeNode | null): number {
    const queue = [root];
    let res = 1;
    let max = -Infinity;
    let h = 1;
    while (queue.length !== 0) {
        const n = queue.length;
        let sum = 0;
        for (let i = 0; i < n; i++) {
            const { val, left, right } = queue.shift();
            sum += val;
            left && queue.push(left);
            right && queue.push(right);
        }
        if (sum > max) {
            max = sum;
            res = h;
        }
        h++;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们也可以使用 DFS 求解。我们用一个数组 $s$ 来存储每一层的节点和，数组的下标表示层数，数组的值表示节点和。我们使用 DFS 遍历二叉树，将每个节点的值加到对应层数的节点和上。最后，我们返回 $s$ 中的最大值对应的下标即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

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
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        def dfs(node, i):
            if node is None:
                return
            if i == len(s):
                s.append(node.val)
            else:
                s[i] += node.val
            dfs(node.left, i + 1)
            dfs(node.right, i + 1)

        s = []
        dfs(root, 0)
        return s.index(max(s)) + 1
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
    private List<Integer> s = new ArrayList<>();

    public int maxLevelSum(TreeNode root) {
        dfs(root, 0);
        int mx = Integer.MIN_VALUE;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mx < s.get(i)) {
                mx = s.get(i);
                ans = i + 1;
            }
        }
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i == s.size()) {
            s.add(root.val);
        } else {
            s.set(i, s.get(i) + root.val);
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
    int maxLevelSum(TreeNode* root) {
        vector<int> s;
        dfs(root, 0, s);
        int mx = INT_MIN;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
            if (mx < s[i]) mx = s[i], ans = i + 1;
        return ans;
    }

    void dfs(TreeNode* root, int i, vector<int>& s) {
        if (!root) return;
        if (s.size() == i)
            s.push_back(root->val);
        else
            s[i] += root->val;
        dfs(root->left, i + 1, s);
        dfs(root->right, i + 1, s);
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
func maxLevelSum(root *TreeNode) int {
	s := []int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if len(s) == i {
			s = append(s, root.Val)
		} else {
			s[i] += root.Val
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 0)
	ans, mx := 0, -0x3f3f3f3f
	for i, v := range s {
		if mx < v {
			mx = v
			ans = i + 1
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1162. 地图分析](https://leetcode.cn/problems/as-far-from-land-as-possible){#1162}

{{< tabs "1162" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque((i, j) for i in range(n) for j in range(n) if grid[i][j])
        ans = -1
        if len(q) in (0, n * n):
            return ans
        dirs = (-1, 0, 1, 0, -1)
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                        grid[x][y] = 1
                        q.append((x, y))
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int ans = -1;
        if (q.isEmpty() || q.size() == n * n) {
            return ans;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.offer(new int[] {x, y});
                    }
                }
            }
            ++ans;
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
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                }
            }
        }
        int ans = -1;
        if (q.empty() || q.size() == n * n) {
            return ans;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int m = q.size(); m; --m) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                        grid[x][y] = 1;
                        q.emplace(x, y);
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistance(grid [][]int) int {
	n := len(grid)
	q := [][2]int{}
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				q = append(q, [2]int{i, j})
			}
		}
	}
	ans := -1
	if len(q) == 0 || len(q) == n*n {
		return ans
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 {
					grid[x][y] = 1
					q = append(q, [2]int{x, y})
				}
			}
		}
		ans++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDistance(grid: number[][]): number {
    const n = grid.length;
    const q: [number, number][] = [];
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
            }
        }
    }
    let ans = -1;
    if (q.length === 0 || q.length === n * n) {
        return ans;
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    while (q.length > 0) {
        for (let m = q.length; m; --m) {
            const [i, j] = q.shift()!;
            for (let k = 0; k < 4; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] === 0) {
                    grid[x][y] = 1;
                    q.push([x, y]);
                }
            }
        }
        ++ans;
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

<p>你现在手里有一份大小为<meta charset="UTF-8" />&nbsp;<code>n x n</code>&nbsp;的 网格 <code>grid</code>，上面的每个 单元格 都用&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;标记好了。其中&nbsp;<code>0</code>&nbsp;代表海洋，<code>1</code>&nbsp;代表陆地。</p>

<p>请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回&nbsp;<code>-1</code>。</p>

<p>我们这里说的距离是「曼哈顿距离」（&nbsp;Manhattan Distance）：<code>(x0, y0)</code> 和&nbsp;<code>(x1, y1)</code>&nbsp;这两个单元格之间的距离是&nbsp;<code>|x0 - x1| + |y0 - y1|</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1162.As%20Far%20from%20Land%20as%20Possible/images/1336_ex1.jpeg" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0,1],[0,0,0],[1,0,1]]
<strong>输出：</strong>2
<strong>解释： </strong>
海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1162.As%20Far%20from%20Land%20as%20Possible/images/1336_ex2.jpeg" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0,0],[0,0,0],[0,0,0]]
<strong>输出：</strong>4
<strong>解释： </strong>
海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以将所有陆地单元格加入队列 $q$ 中，如果队列为空，或者队列中元素个数等于网格中的单元格个数，则说明网格中只有陆地或者海洋，返回 $-1$。

否则，我们从陆地单元格开始进行广度优先搜索。定义初始步数 $ans=-1$。

在每一轮搜索中，我们将队列中的所有单元格向四个方向扩散，若单元格是海洋单元格，则将其标记为陆地单元格，并加入队列。在一轮扩散完成后，我们将步数加 $1$。重复这一过程，直到队列为空。

最后，我们返回步数 $ans$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是网格的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = deque((i, j) for i in range(n) for j in range(n) if grid[i][j])
        ans = -1
        if len(q) in (0, n * n):
            return ans
        dirs = (-1, 0, 1, 0, -1)
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                        grid[x][y] = 1
                        q.append((x, y))
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int ans = -1;
        if (q.isEmpty() || q.size() == n * n) {
            return ans;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.offer(new int[] {x, y});
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.emplace(i, j);
                }
            }
        }
        int ans = -1;
        if (q.empty() || q.size() == n * n) {
            return ans;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int m = q.size(); m; --m) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                        grid[x][y] = 1;
                        q.emplace(x, y);
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func maxDistance(grid [][]int) int {
	n := len(grid)
	q := [][2]int{}
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				q = append(q, [2]int{i, j})
			}
		}
	}
	ans := -1
	if len(q) == 0 || len(q) == n*n {
		return ans
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 {
					grid[x][y] = 1
					q = append(q, [2]int{x, y})
				}
			}
		}
		ans++
	}
	return ans
}
```

#### TypeScript

```ts
function maxDistance(grid: number[][]): number {
    const n = grid.length;
    const q: [number, number][] = [];
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
            }
        }
    }
    let ans = -1;
    if (q.length === 0 || q.length === n * n) {
        return ans;
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    while (q.length > 0) {
        for (let m = q.length; m; --m) {
            const [i, j] = q.shift()!;
            for (let k = 0; k < 4; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] === 0) {
                    grid[x][y] = 1;
                    q.push([x, y]);
                }
            }
        }
        ++ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1163. 按字典序排在最后的子串](https://leetcode.cn/problems/last-substring-in-lexicographical-order){#1163}

{{< tabs "1163" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastSubstring(self, s: str) -> str:
        i, j, k = 0, 1, 0
        while j + k < len(s):
            if s[i + k] == s[j + k]:
                k += 1
            elif s[i + k] < s[j + k]:
                i += k + 1
                k = 0
                if i >= j:
                    j = i + 1
            else:
                j += k + 1
                k = 0
        return s[i:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String lastSubstring(String s) {
        int n = s.length();
        int i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            int d = s.charAt(i + k) - s.charAt(j + k);
            if (d == 0) {
                ++k;
            } else if (d < 0) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substring(i);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] < s[j + k]) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastSubstring(s string) string {
	i, n := 0, len(s)
	for j, k := 1, 0; j+k < n; {
		if s[i+k] == s[j+k] {
			k++
		} else if s[i+k] < s[j+k] {
			i += k + 1
			k = 0
			if i >= j {
				j = i + 1
			}
		} else {
			j += k + 1
			k = 0
		}
	}
	return s[i:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lastSubstring(s: string): string {
    const n = s.length;
    let i = 0;
    for (let j = 1, k = 0; j + k < n; ) {
        if (s[i + k] === s[j + k]) {
            ++k;
        } else if (s[i + k] < s[j + k]) {
            i += k + 1;
            k = 0;
            if (i >= j) {
                j = i + 1;
            }
        } else {
            j += k + 1;
            k = 0;
        }
    }
    return s.slice(i);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，找出它的所有子串并按字典序排列，返回排在最后的那个子串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abab"
<strong>输出：</strong>"bab"
<strong>解释：</strong>我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是 "bab"。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>"tcode"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 4 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅含有小写英文字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们注意到，如果一个子串从位置 $i$ 开始，那么字典序最大的子串一定是 $s[i,..n-1]$，即从位置 $i$ 开始的最长后缀。因此，我们只需要找出字典序最大的后缀子串即可。

我们使用双指针 $i$ 和 $j$，其中指针 $i$ 指向当前字典序最大的子串的起始位置，指针 $j$ 指向当前考虑的子串的起始位置。另外，用一个变量 $k$ 记录当前比较到的位置。初始时 $i = 0$, $j=1$, $k=0$。

每一次，我们比较 $s[i+k]$ 和 $s[j+k]$：

如果 $s[i + k] = s[j + k]$，说明 $s[i,..i+k]$ 和 $s[j,..j+k]$ 相同，我们将 $k$ 加 $1$，继续比较 $s[i+k]$ 和 $s[j+k]$；

如果 $s[i + k] \lt s[j + k]$，说明 $s[j,..j+k]$ 的字典序更大。此时，我们更新 $i = i + k + 1$，并将 $k$ 重置为 $0$。如果此时 $i \geq j$，那么我们将指针 $j$ 更新为 $i + 1$，即 $j = i + 1$。这里我们跳过了以 $s[i,..,i+k]$ 为起始位置的所有后缀子串，因为它们的字典序一定小于对应的 $s[j,..,j+k]$ 为起始位置的后缀子串。

同理，如果 $s[i + k] \gt s[j + k]$，说明 $s[i,..,i+k]$ 的字典序更大。此时，我们更新 $j = j + k + 1$，并将 $k$ 重置为 $0$。这里我们跳过了以 $s[j,..,j+k]$ 为起始位置的所有后缀子串，因为它们的字典序一定小于对应的 $s[i,..,i+k]$ 为起始位置的后缀子串。

最后，我们返回以 $i$ 为起始位置的后缀子串即可，即 $s[i,..,n-1]$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastSubstring(self, s: str) -> str:
        i, j, k = 0, 1, 0
        while j + k < len(s):
            if s[i + k] == s[j + k]:
                k += 1
            elif s[i + k] < s[j + k]:
                i += k + 1
                k = 0
                if i >= j:
                    j = i + 1
            else:
                j += k + 1
                k = 0
        return s[i:]
```

#### Java

```java
class Solution {
    public String lastSubstring(String s) {
        int n = s.length();
        int i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            int d = s.charAt(i + k) - s.charAt(j + k);
            if (d == 0) {
                ++k;
            } else if (d < 0) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substring(i);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] < s[j + k]) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
```

#### Go

```go
func lastSubstring(s string) string {
	i, n := 0, len(s)
	for j, k := 1, 0; j+k < n; {
		if s[i+k] == s[j+k] {
			k++
		} else if s[i+k] < s[j+k] {
			i += k + 1
			k = 0
			if i >= j {
				j = i + 1
			}
		} else {
			j += k + 1
			k = 0
		}
	}
	return s[i:]
}
```

#### TypeScript

```ts
function lastSubstring(s: string): string {
    const n = s.length;
    let i = 0;
    for (let j = 1, k = 0; j + k < n; ) {
        if (s[i + k] === s[j + k]) {
            ++k;
        } else if (s[i + k] < s[j + k]) {
            i += k + 1;
            k = 0;
            if (i >= j) {
                j = i + 1;
            }
        } else {
            j += k + 1;
            k = 0;
        }
    }
    return s.slice(i);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1164. 指定日期的产品价格](https://leetcode.cn/problems/product-price-at-a-given-date){#1164}

{{< tabs "1164" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT p1.product_id, new_price, change_date
        FROM
            (
                SELECT DISTINCT product_id
                FROM Products
            ) AS p1
            LEFT JOIN Products AS p2
                ON p1.product_id = p2.product_id AND p2.change_date <= '2019-08-16'
    ),
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY change_date DESC
            ) AS rk
        FROM P
    )
SELECT product_id, IFNULL(new_price, 10) AS price
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>产品数据表: <code>Products</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) 是此表的主键（具有唯一值的列组合）。
这张表的每一行分别记录了 某产品 在某个日期 更改后 的新价格。</pre>

<p>一开始，所有产品价格都为 10。</p>

<p>编写一个解决方案，找出在&nbsp;<code>2019-08-16</code><strong>&nbsp;</strong>所有产品的价格。</p>

<p>以 <strong>任意顺序 </strong>返回结果表。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Products 表:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
<strong>输出：</strong>
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询 + 连接

我们可以使用子查询，找出每个产品在给定日期之前最后一次价格变更的价格，记录在 `P` 表中。然后，我们再找出所有产品的 `product_id`，记录在 `T` 表中。最后，我们将 `T` 表和 `P` 表按照 `product_id` 进行左连接，即可得到最终结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (SELECT DISTINCT product_id FROM Products),
    P AS (
        SELECT product_id, new_price AS price
        FROM Products
        WHERE
            (product_id, change_date) IN (
                SELECT product_id, MAX(change_date) AS change_date
                FROM Products
                WHERE change_date <= '2019-08-16'
                GROUP BY 1
            )
    )
SELECT product_id, IFNULL(price, 10) AS price
FROM
    T
    LEFT JOIN P USING (product_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT p1.product_id, new_price, change_date
        FROM
            (
                SELECT DISTINCT product_id
                FROM Products
            ) AS p1
            LEFT JOIN Products AS p2
                ON p1.product_id = p2.product_id AND p2.change_date <= '2019-08-16'
    ),
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY change_date DESC
            ) AS rk
        FROM P
    )
SELECT product_id, IFNULL(new_price, 10) AS price
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1165. 单行键盘 🔒](https://leetcode.cn/problems/single-row-keyboard){#1165}

{{< tabs "1165" >}}

{{% tab "python" %}}
```python
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        pos = {c: i for i, c in enumerate(keyboard)}
        ans = i = 0
        for c in word:
            ans += abs(pos[c] - i)
            i = pos[c]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int calculateTime(String keyboard, String word) {
        int[] pos = new int[26];
        for (int i = 0; i < 26; ++i) {
            pos[keyboard.charAt(i) - 'a'] = i;
        }
        int ans = 0, i = 0;
        for (int k = 0; k < word.length(); ++k) {
            int j = pos[word.charAt(k) - 'a'];
            ans += Math.abs(i - j);
            i = j;
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
    int calculateTime(string keyboard, string word) {
        int pos[26];
        for (int i = 0; i < 26; ++i) {
            pos[keyboard[i] - 'a'] = i;
        }
        int ans = 0, i = 0;
        for (char& c : word) {
            int j = pos[c - 'a'];
            ans += abs(i - j);
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func calculateTime(keyboard string, word string) (ans int) {
	pos := [26]int{}
	for i, c := range keyboard {
		pos[c-'a'] = i
	}
	i := 0
	for _, c := range word {
		j := pos[c-'a']
		ans += abs(i - j)
		i = j
	}
	return
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
function calculateTime(keyboard: string, word: string): number {
    const pos: number[] = Array(26).fill(0);
    for (let i = 0; i < 26; ++i) {
        pos[keyboard.charCodeAt(i) - 97] = i;
    }
    let ans = 0;
    let i = 0;
    for (const c of word) {
        const j = pos[c.charCodeAt(0) - 97];
        ans += Math.abs(i - j);
        i = j;
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

<p>我们定制了一款特殊的键盘，所有的键都 <strong>排列在一行上</strong>&nbsp;。</p>

<p>给定一个长度为 <code>26</code> 的字符串&nbsp;<code>keyboard</code>&nbsp;，来表示键盘的布局(索引从 <code>0</code> 到 <code>25</code> )。一开始，你的手指在索引 <code>0</code> 处。要输入一个字符，你必须把你的手指移动到所需字符的索引处。手指从索引&nbsp;<code>i</code>&nbsp;移动到索引&nbsp;<code>j</code>&nbsp;所需要的时间是&nbsp;<code>|i - j|</code>。</p>

<p>您需要输入一个字符串&nbsp;<code>word</code>&nbsp;。写一个函数来计算用一个手指输入需要多少时间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
<strong>输出：</strong>4
<strong>解释：</strong>从 0 号键移动到 2 号键来输出 'c'，又移动到 1 号键来输出 'b'，接着移动到 0 号键来输出 'a'。
总用时 = 2 + 1 + 1 = 4. 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
<strong>输出：</strong>73
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>keyboard.length == 26</code></li>
	<li><code>keyboard</code>&nbsp;按某种特定顺序排列，并包含每个小写英文字母一次。</li>
	<li><code>1 &lt;= word.length &lt;= 10<sup>4</sup></code></li>
	<li><code>word[i]</code>&nbsp;为小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以用哈希表或者一个长度为 $26$ 的数组 $pos$ 来存储每个字符在键盘上的位置，其中 $pos[c]$ 表示字符 $c$ 在键盘上的位置。

然后我们遍历字符串 $word$，用一个变量 $i$ 记录当前手指所在的位置，初始时 $i = 0$。每次计算当前字符 $c$ 在键盘上的位置 $j$，并将答案增加 $|i - j|$，然后将 $i$ 更新为 $j$。继续遍历下一个字符，直到遍历完整个字符串 $word$。

遍历完字符串 $word$ 之后，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $word$ 的长度；而 $C$ 为字符集大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        pos = {c: i for i, c in enumerate(keyboard)}
        ans = i = 0
        for c in word:
            ans += abs(pos[c] - i)
            i = pos[c]
        return ans
```

#### Java

```java
class Solution {
    public int calculateTime(String keyboard, String word) {
        int[] pos = new int[26];
        for (int i = 0; i < 26; ++i) {
            pos[keyboard.charAt(i) - 'a'] = i;
        }
        int ans = 0, i = 0;
        for (int k = 0; k < word.length(); ++k) {
            int j = pos[word.charAt(k) - 'a'];
            ans += Math.abs(i - j);
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int pos[26];
        for (int i = 0; i < 26; ++i) {
            pos[keyboard[i] - 'a'] = i;
        }
        int ans = 0, i = 0;
        for (char& c : word) {
            int j = pos[c - 'a'];
            ans += abs(i - j);
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func calculateTime(keyboard string, word string) (ans int) {
	pos := [26]int{}
	for i, c := range keyboard {
		pos[c-'a'] = i
	}
	i := 0
	for _, c := range word {
		j := pos[c-'a']
		ans += abs(i - j)
		i = j
	}
	return
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
function calculateTime(keyboard: string, word: string): number {
    const pos: number[] = Array(26).fill(0);
    for (let i = 0; i < 26; ++i) {
        pos[keyboard.charCodeAt(i) - 97] = i;
    }
    let ans = 0;
    let i = 0;
    for (const c of word) {
        const j = pos[c.charCodeAt(0) - 97];
        ans += Math.abs(i - j);
        i = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1166. 设计文件系统 🔒](https://leetcode.cn/problems/design-file-system){#1166}

{{< tabs "1166" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self, v: int = -1):
        self.children = {}
        self.v = v

    def insert(self, w: str, v: int) -> bool:
        node = self
        ps = w.split("/")
        for p in ps[1:-1]:
            if p not in node.children:
                return False
            node = node.children[p]
        if ps[-1] in node.children:
            return False
        node.children[ps[-1]] = Trie(v)
        return True

    def search(self, w: str) -> int:
        node = self
        for p in w.split("/")[1:]:
            if p not in node.children:
                return -1
            node = node.children[p]
        return node.v


class FileSystem:
    def __init__(self):
        self.trie = Trie()

    def createPath(self, path: str, value: int) -> bool:
        return self.trie.insert(path, value)

    def get(self, path: str) -> int:
        return self.trie.search(path)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Map<String, Trie> children = new HashMap<>();
    int v;

    Trie(int v) {
        this.v = v;
    }

    boolean insert(String w, int v) {
        Trie node = this;
        var ps = w.split("/");
        for (int i = 1; i < ps.length - 1; ++i) {
            var p = ps[i];
            if (!node.children.containsKey(p)) {
                return false;
            }
            node = node.children.get(p);
        }
        if (node.children.containsKey(ps[ps.length - 1])) {
            return false;
        }
        node.children.put(ps[ps.length - 1], new Trie(v));
        return true;
    }

    int search(String w) {
        Trie node = this;
        var ps = w.split("/");
        for (int i = 1; i < ps.length; ++i) {
            var p = ps[i];
            if (!node.children.containsKey(p)) {
                return -1;
            }
            node = node.children.get(p);
        }
        return node.v;
    }
}

class FileSystem {
    private Trie trie = new Trie(-1);

    public FileSystem() {
    }

    public boolean createPath(String path, int value) {
        return trie.insert(path, value);
    }

    public int get(String path) {
        return trie.search(path);
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * boolean param_1 = obj.createPath(path,value);
 * int param_2 = obj.get(path);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    unordered_map<string, Trie*> children;
    int v;

    Trie(int v) {
        this->v = v;
    }

    bool insert(string& w, int v) {
        Trie* node = this;
        auto ps = split(w, '/');
        for (int i = 1; i < ps.size() - 1; ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return false;
            }
            node = node->children[p];
        }
        if (node->children.count(ps.back())) {
            return false;
        }
        node->children[ps.back()] = new Trie(v);
        return true;
    }

    int search(string& w) {
        Trie* node = this;
        auto ps = split(w, '/');
        for (int i = 1; i < ps.size(); ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return -1;
            }
            node = node->children[p];
        }
        return node->v;
    }

private:
    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};

class FileSystem {
public:
    FileSystem() {
        trie = new Trie(-1);
    }

    bool createPath(string path, int value) {
        return trie->insert(path, value);
    }

    int get(string path) {
        return trie->search(path);
    }

private:
    Trie* trie;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type trie struct {
	children map[string]*trie
	v        int
}

func newTrie(v int) *trie {
	return &trie{map[string]*trie{}, v}
}

func (t *trie) insert(w string, v int) bool {
	node := t
	ps := strings.Split(w, "/")
	for _, p := range ps[1 : len(ps)-1] {
		if _, ok := node.children[p]; !ok {
			return false
		}
		node = node.children[p]
	}
	if _, ok := node.children[ps[len(ps)-1]]; ok {
		return false
	}
	node.children[ps[len(ps)-1]] = newTrie(v)
	return true
}

func (t *trie) search(w string) int {
	node := t
	ps := strings.Split(w, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			return -1
		}
		node = node.children[p]
	}
	return node.v
}

type FileSystem struct {
	trie *trie
}

func Constructor() FileSystem {
	return FileSystem{trie: newTrie(-1)}
}

func (this *FileSystem) CreatePath(path string, value int) bool {
	return this.trie.insert(path, value)
}

func (this *FileSystem) Get(path string) int {
	return this.trie.search(path)
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.CreatePath(path,value);
 * param_2 := obj.Get(path);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: Map<string, Trie>;
    v: number;

    constructor(v: number) {
        this.children = new Map<string, Trie>();
        this.v = v;
    }

    insert(w: string, v: number): boolean {
        let node: Trie = this;
        const ps = w.split('/').slice(1);
        for (let i = 0; i < ps.length - 1; ++i) {
            const p = ps[i];
            if (!node.children.has(p)) {
                return false;
            }
            node = node.children.get(p)!;
        }
        if (node.children.has(ps[ps.length - 1])) {
            return false;
        }
        node.children.set(ps[ps.length - 1], new Trie(v));
        return true;
    }

    search(w: string): number {
        let node: Trie = this;
        const ps = w.split('/').slice(1);
        for (const p of ps) {
            if (!node.children.has(p)) {
                return -1;
            }
            node = node.children.get(p)!;
        }
        return node.v;
    }
}

class FileSystem {
    trie: Trie;

    constructor() {
        this.trie = new Trie(-1);
    }

    createPath(path: string, value: number): boolean {
        return this.trie.insert(path, value);
    }

    get(path: string): number {
        return this.trie.search(path);
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * var obj = new FileSystem()
 * var param_1 = obj.createPath(path,value)
 * var param_2 = obj.get(path)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要设计一个文件系统，你可以创建新的路径并将它们与不同的值关联。</p>

<p>路径的格式是一个或多个连接在一起的字符串，形式为：&nbsp;<code>/</code> ，后面跟着一个或多个小写英文字母。例如， <code>" /leetcode"</code> 和 <code>"/leetcode/problems"</code> 是有效路径，而空字符串 <code>""</code> 和 <code>"/"</code> 不是。</p>

<p>实现 <code>FileSystem</code> 类:</p>

<ul>
	<li><meta charset="UTF-8" /><code>bool createPath(string path, int value)</code>&nbsp;创建一个新的&nbsp;<code>path</code> ，并在可能的情况下关联一个 <code>value</code> ，然后返回 <code>true</code> 。如果路径<strong>已经存在</strong>或其父路径<strong>不存在</strong>，则返回&nbsp;<code>false</code>&nbsp;。</li>
	<li>&nbsp;<code>int get(string path)</code> 返回与 <code>path</code> 关联的值，如果路径不存在则返回 <code>-1</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
["FileSystem","create","get"]
[[],["/a",1],["/a"]]
<strong>输出：</strong> 
[null,true,1]
<strong>解释：</strong> 
FileSystem fileSystem = new FileSystem();

fileSystem.create("/a", 1); // 返回 true
fileSystem.get("/a"); // 返回 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong> 
["FileSystem","createPath","createPath","get","createPath","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
<strong>输出：</strong> 
[null,true,true,2,false,-1]
<strong>解释：</strong>
FileSystem fileSystem = new FileSystem();

fileSystem.createPath("/leet", 1); // 返回 true
fileSystem.createPath("/leet/code", 2); // 返回 true
fileSystem.get("/leet/code"); // 返回 2
fileSystem.createPath("/c/d", 1); // 返回 false 因为父路径 "/c" 不存在。
fileSystem.get("/c"); // 返回 -1 因为该路径不存在。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>对两个函数的调用次数加起来小于等于&nbsp;<meta charset="UTF-8" /><code>10<sup>4</sup></code>&nbsp;</li>
	<li><code>2 &lt;= path.length &lt;= 100</code></li>
	<li><code>1 &lt;= value &lt;= 10<sup>9</sup></code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

我们可以使用前缀树来存储路径，每个节点存储一个值，表示该节点对应的路径的值。

定义前缀树的节点结构如下：

-   `children`：子节点，使用哈希表存储，键为子节点的路径，值为子节点的引用；
-   `v`：当前节点对应的路径的值。

定义前缀树的方法如下：

-   `insert(w, v)`：插入路径 $w$，并将其对应的值设为 $v$。如果路径 $w$ 已经存在或其父路径不存在，则返回 `false`，否则返回 `true`。时间复杂度为 $O(|w|)$，其中 $|w|$ 为路径 $w$ 的长度；
-   `search(w)`：返回路径 $w$ 对应的值。如果路径 $w$ 不存在，则返回 $-1$。时间复杂度为 $O(|w|)$。

总时间复杂度 $O(\sum_{w \in W}|w|)$，总空间复杂度 $O(\sum_{w \in W}|w|)$，其中 $W$ 为所有插入的路径的集合。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self, v: int = -1):
        self.children = {}
        self.v = v

    def insert(self, w: str, v: int) -> bool:
        node = self
        ps = w.split("/")
        for p in ps[1:-1]:
            if p not in node.children:
                return False
            node = node.children[p]
        if ps[-1] in node.children:
            return False
        node.children[ps[-1]] = Trie(v)
        return True

    def search(self, w: str) -> int:
        node = self
        for p in w.split("/")[1:]:
            if p not in node.children:
                return -1
            node = node.children[p]
        return node.v


class FileSystem:
    def __init__(self):
        self.trie = Trie()

    def createPath(self, path: str, value: int) -> bool:
        return self.trie.insert(path, value)

    def get(self, path: str) -> int:
        return self.trie.search(path)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
```

#### Java

```java
class Trie {
    Map<String, Trie> children = new HashMap<>();
    int v;

    Trie(int v) {
        this.v = v;
    }

    boolean insert(String w, int v) {
        Trie node = this;
        var ps = w.split("/");
        for (int i = 1; i < ps.length - 1; ++i) {
            var p = ps[i];
            if (!node.children.containsKey(p)) {
                return false;
            }
            node = node.children.get(p);
        }
        if (node.children.containsKey(ps[ps.length - 1])) {
            return false;
        }
        node.children.put(ps[ps.length - 1], new Trie(v));
        return true;
    }

    int search(String w) {
        Trie node = this;
        var ps = w.split("/");
        for (int i = 1; i < ps.length; ++i) {
            var p = ps[i];
            if (!node.children.containsKey(p)) {
                return -1;
            }
            node = node.children.get(p);
        }
        return node.v;
    }
}

class FileSystem {
    private Trie trie = new Trie(-1);

    public FileSystem() {
    }

    public boolean createPath(String path, int value) {
        return trie.insert(path, value);
    }

    public int get(String path) {
        return trie.search(path);
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * boolean param_1 = obj.createPath(path,value);
 * int param_2 = obj.get(path);
 */
```

#### C++

```cpp
class Trie {
public:
    unordered_map<string, Trie*> children;
    int v;

    Trie(int v) {
        this->v = v;
    }

    bool insert(string& w, int v) {
        Trie* node = this;
        auto ps = split(w, '/');
        for (int i = 1; i < ps.size() - 1; ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return false;
            }
            node = node->children[p];
        }
        if (node->children.count(ps.back())) {
            return false;
        }
        node->children[ps.back()] = new Trie(v);
        return true;
    }

    int search(string& w) {
        Trie* node = this;
        auto ps = split(w, '/');
        for (int i = 1; i < ps.size(); ++i) {
            auto p = ps[i];
            if (!node->children.count(p)) {
                return -1;
            }
            node = node->children[p];
        }
        return node->v;
    }

private:
    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};

class FileSystem {
public:
    FileSystem() {
        trie = new Trie(-1);
    }

    bool createPath(string path, int value) {
        return trie->insert(path, value);
    }

    int get(string path) {
        return trie->search(path);
    }

private:
    Trie* trie;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
```

#### Go

```go
type trie struct {
	children map[string]*trie
	v        int
}

func newTrie(v int) *trie {
	return &trie{map[string]*trie{}, v}
}

func (t *trie) insert(w string, v int) bool {
	node := t
	ps := strings.Split(w, "/")
	for _, p := range ps[1 : len(ps)-1] {
		if _, ok := node.children[p]; !ok {
			return false
		}
		node = node.children[p]
	}
	if _, ok := node.children[ps[len(ps)-1]]; ok {
		return false
	}
	node.children[ps[len(ps)-1]] = newTrie(v)
	return true
}

func (t *trie) search(w string) int {
	node := t
	ps := strings.Split(w, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			return -1
		}
		node = node.children[p]
	}
	return node.v
}

type FileSystem struct {
	trie *trie
}

func Constructor() FileSystem {
	return FileSystem{trie: newTrie(-1)}
}

func (this *FileSystem) CreatePath(path string, value int) bool {
	return this.trie.insert(path, value)
}

func (this *FileSystem) Get(path string) int {
	return this.trie.search(path)
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.CreatePath(path,value);
 * param_2 := obj.Get(path);
 */
```

#### TypeScript

```ts
class Trie {
    children: Map<string, Trie>;
    v: number;

    constructor(v: number) {
        this.children = new Map<string, Trie>();
        this.v = v;
    }

    insert(w: string, v: number): boolean {
        let node: Trie = this;
        const ps = w.split('/').slice(1);
        for (let i = 0; i < ps.length - 1; ++i) {
            const p = ps[i];
            if (!node.children.has(p)) {
                return false;
            }
            node = node.children.get(p)!;
        }
        if (node.children.has(ps[ps.length - 1])) {
            return false;
        }
        node.children.set(ps[ps.length - 1], new Trie(v));
        return true;
    }

    search(w: string): number {
        let node: Trie = this;
        const ps = w.split('/').slice(1);
        for (const p of ps) {
            if (!node.children.has(p)) {
                return -1;
            }
            node = node.children.get(p)!;
        }
        return node.v;
    }
}

class FileSystem {
    trie: Trie;

    constructor() {
        this.trie = new Trie(-1);
    }

    createPath(path: string, value: number): boolean {
        return this.trie.insert(path, value);
    }

    get(path: string): number {
        return this.trie.search(path);
    }
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * var obj = new FileSystem()
 * var param_1 = obj.createPath(path,value)
 * var param_2 = obj.get(path)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1167. 连接木棍的最低费用 🔒](https://leetcode.cn/problems/minimum-cost-to-connect-sticks){#1167}

{{< tabs "1167" >}}

{{% tab "python" %}}
```python
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapify(sticks)
        ans = 0
        while len(sticks) > 1:
            z = heappop(sticks) + heappop(sticks)
            ans += z
            heappush(sticks, z)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : sticks) {
            pq.offer(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int z = pq.poll() + pq.poll();
            ans += z;
            pq.offer(z);
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
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& x : sticks) {
            pq.push(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int z = x + y;
            ans += z;
            pq.push(z);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func connectSticks(sticks []int) (ans int) {
	hp := &hp{sticks}
	heap.Init(hp)
	for hp.Len() > 1 {
		x, y := heap.Pop(hp).(int), heap.Pop(hp).(int)
		ans += x + y
		heap.Push(hp, x+y)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function connectSticks(sticks: number[]): number {
    const pq = new Heap(sticks);
    let ans = 0;
    while (pq.size() > 1) {
        const x = pq.pop();
        const y = pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class Heap<T = number> {
    data: Array<T | null>;
    lt: (i: number, j: number) => boolean;
    constructor();
    constructor(data: T[]);
    constructor(compare: Compare<T>);
    constructor(data: T[], compare: Compare<T>);
    constructor(data: T[] | Compare<T>, compare?: (lhs: T, rhs: T) => number);
    constructor(
        data: T[] | Compare<T> = [],
        compare: Compare<T> = (lhs: T, rhs: T) => (lhs < rhs ? -1 : lhs > rhs ? 1 : 0),
    ) {
        if (typeof data === 'function') {
            compare = data;
            data = [];
        }
        this.data = [null, ...data];
        this.lt = (i, j) => compare(this.data[i]!, this.data[j]!) < 0;
        for (let i = this.size(); i > 0; i--) this.heapify(i);
    }

    size(): number {
        return this.data.length - 1;
    }

    push(v: T): void {
        this.data.push(v);
        let i = this.size();
        while (i >> 1 !== 0 && this.lt(i, i >> 1)) this.swap(i, (i >>= 1));
    }

    pop(): T {
        this.swap(1, this.size());
        const top = this.data.pop();
        this.heapify(1);
        return top!;
    }

    top(): T {
        return this.data[1]!;
    }
    heapify(i: number): void {
        while (true) {
            let min = i;
            const [l, r, n] = [i * 2, i * 2 + 1, this.data.length];
            if (l < n && this.lt(l, min)) min = l;
            if (r < n && this.lt(r, min)) min = r;
            if (min !== i) {
                this.swap(i, min);
                i = min;
            } else break;
        }
    }

    clear(): void {
        this.data = [null];
    }

    private swap(i: number, j: number): void {
        const d = this.data;
        [d[i], d[j]] = [d[j], d[i]];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一些长度为正整数的木棍。这些长度以数组<meta charset="UTF-8" />&nbsp;<code>sticks</code>&nbsp;的形式给出，<meta charset="UTF-8" />&nbsp;<code>sticks[i]</code>&nbsp;是第 <code>i</code> 个木棍的长度。</p>

<p>你可以通过支付 <code>x + y</code> 的成本将任意两个长度为 <code>x</code> 和 <code>y</code> 的木棍连接成一个木棍。你必须连接所有的木棍，直到剩下一个木棍。</p>

<p>返回以这种方式将所有给定的木棍连接成一个木棍的<em> 最小成本 </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sticks = [2,4,3]
<strong>输出：</strong>14
<strong>解释：</strong>从 sticks = [2,4,3] 开始。
1. 连接 2 和 3 ，费用为 2 + 3 = 5 。现在 sticks = [5,4]
2. 连接 5 和 4 ，费用为 5 + 4 = 9 。现在 sticks = [9]
所有木棍已经连成一根，总费用 5 + 9 = 14
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sticks = [1,8,3,5]
<strong>输出：</strong>30
<strong>解释：</strong>从 sticks = [1,8,3,5] 开始。
1. 连接 1 和 3 ，费用为 1 + 3 = 4 。现在 sticks = [4,8,5]
2. 连接 4 和 5 ，费用为 4 + 5 = 9 。现在 sticks = [9,8]
3. 连接 9 和 8 ，费用为 9 + 8 = 17 。现在 sticks = [17]
所有木棍已经连成一根，总费用 4 + 9 + 17 = 30
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sticks = [5]
<strong>输出：</strong>0
<strong>解释：</strong>只有一根木棍，不必再连接。总费用 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sticks.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sticks[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

我们可以使用贪心的思路，每次选择最短的两根棍子进行拼接，这样可以保证拼接的代价最小。

因此，我们可以使用优先队列（小根堆）来维护当前棍子的长度，每次从优先队列中取出两根棍子进行拼接，再将拼接后的棍子放回优先队列中，直到优先队列中只剩下一根棍子为止。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `sticks` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapify(sticks)
        ans = 0
        while len(sticks) > 1:
            z = heappop(sticks) + heappop(sticks)
            ans += z
            heappush(sticks, z)
        return ans
```

#### Java

```java
class Solution {
    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : sticks) {
            pq.offer(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int z = pq.poll() + pq.poll();
            ans += z;
            pq.offer(z);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& x : sticks) {
            pq.push(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int z = x + y;
            ans += z;
            pq.push(z);
        }
        return ans;
    }
};
```

#### Go

```go
func connectSticks(sticks []int) (ans int) {
	hp := &hp{sticks}
	heap.Init(hp)
	for hp.Len() > 1 {
		x, y := heap.Pop(hp).(int), heap.Pop(hp).(int)
		ans += x + y
		heap.Push(hp, x+y)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function connectSticks(sticks: number[]): number {
    const pq = new Heap(sticks);
    let ans = 0;
    while (pq.size() > 1) {
        const x = pq.pop();
        const y = pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class Heap<T = number> {
    data: Array<T | null>;
    lt: (i: number, j: number) => boolean;
    constructor();
    constructor(data: T[]);
    constructor(compare: Compare<T>);
    constructor(data: T[], compare: Compare<T>);
    constructor(data: T[] | Compare<T>, compare?: (lhs: T, rhs: T) => number);
    constructor(
        data: T[] | Compare<T> = [],
        compare: Compare<T> = (lhs: T, rhs: T) => (lhs < rhs ? -1 : lhs > rhs ? 1 : 0),
    ) {
        if (typeof data === 'function') {
            compare = data;
            data = [];
        }
        this.data = [null, ...data];
        this.lt = (i, j) => compare(this.data[i]!, this.data[j]!) < 0;
        for (let i = this.size(); i > 0; i--) this.heapify(i);
    }

    size(): number {
        return this.data.length - 1;
    }

    push(v: T): void {
        this.data.push(v);
        let i = this.size();
        while (i >> 1 !== 0 && this.lt(i, i >> 1)) this.swap(i, (i >>= 1));
    }

    pop(): T {
        this.swap(1, this.size());
        const top = this.data.pop();
        this.heapify(1);
        return top!;
    }

    top(): T {
        return this.data[1]!;
    }
    heapify(i: number): void {
        while (true) {
            let min = i;
            const [l, r, n] = [i * 2, i * 2 + 1, this.data.length];
            if (l < n && this.lt(l, min)) min = l;
            if (r < n && this.lt(r, min)) min = r;
            if (min !== i) {
                this.swap(i, min);
                i = min;
            } else break;
        }
    }

    clear(): void {
        this.data = [null];
    }

    private swap(i: number, j: number): void {
        const d = this.data;
        [d[i], d[j]] = [d[j], d[i]];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1168. 水资源分配优化 🔒](https://leetcode.cn/problems/optimize-water-distribution-in-a-village){#1168}

{{< tabs "1168" >}}

{{% tab "python" %}}
```python
class UnionFind:
    __slots__ = ("p", "size")

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
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
    def minCostToSupplyWater(
        self, n: int, wells: List[int], pipes: List[List[int]]
    ) -> int:
        for i, w in enumerate(wells, 1):
            pipes.append([0, i, w])
        pipes.sort(key=lambda x: x[2])
        uf = UnionFind(n + 1)
        ans = 0
        for a, b, c in pipes:
            if uf.union(a, b):
                ans += c
                n -= 1
                if n == 0:
                    return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

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
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        int[][] nums = Arrays.copyOf(pipes, pipes.length + n);
        for (int i = 0; i < n; i++) {
            nums[pipes.length + i] = new int[] {0, i + 1, wells[i]};
        }
        Arrays.sort(nums, (a, b) -> a[2] - b[2]);
        UnionFind uf = new UnionFind(n + 1);
        int ans = 0;
        for (var x : nums) {
            int a = x[0], b = x[1], c = x[2];
            if (uf.union(a, b)) {
                ans += c;
                if (--n == 0) {
                    break;
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i < n; ++i) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        UnionFind uf(n + 1);
        int ans = 0;
        for (const auto& x : pipes) {
            if (uf.unite(x[0], x[1])) {
                ans += x[2];
                if (--n == 0) {
                    break;
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

func minCostToSupplyWater(n int, wells []int, pipes [][]int) (ans int) {
	for i, w := range wells {
		pipes = append(pipes, []int{0, i + 1, w})
	}
	sort.Slice(pipes, func(i, j int) bool { return pipes[i][2] < pipes[j][2] })
	uf := newUnionFind(n + 1)
	for _, x := range pipes {
		if uf.union(x[0], x[1]) {
			ans += x[2]
			n--
			if n == 0 {
				break
			}
		}
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
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
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

function minCostToSupplyWater(n: number, wells: number[], pipes: number[][]): number {
    for (let i = 0; i < n; ++i) {
        pipes.push([0, i + 1, wells[i]]);
    }
    pipes.sort((a, b) => a[2] - b[2]);
    const uf = new UnionFind(n + 1);
    let ans = 0;
    for (const [a, b, c] of pipes) {
        if (uf.union(a, b)) {
            ans += c;
            if (--n === 0) {
                break;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) -> bool {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            false
        } else if self.size[pa] > self.size[pb] {
            self.p[pb] = pa;
            self.size[pa] += self.size[pb];
            true
        } else {
            self.p[pa] = pb;
            self.size[pb] += self.size[pa];
            true
        }
    }
}

impl Solution {
    pub fn min_cost_to_supply_water(n: i32, wells: Vec<i32>, pipes: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut pipes = pipes;
        for i in 0..n {
            pipes.push(vec![0, (i + 1) as i32, wells[i]]);
        }
        pipes.sort_by(|a, b| a[2].cmp(&b[2]));
        let mut uf = UnionFind::new(n + 1);
        let mut ans = 0;
        for pipe in pipes {
            let a = pipe[0] as usize;
            let b = pipe[1] as usize;
            let c = pipe[2];
            if uf.union(a, b) {
                ans += c;
                if n == 0 {
                    break;
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

<p>村里面一共有 <code>n</code> 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。</p>

<p>对于每个房子&nbsp;<code>i</code>，我们有两种可选的供水方案：一种是直接在房子内建造水井，成本为&nbsp;<code>wells[i - 1]</code>&nbsp;（注意 <code>-1</code> ，因为 <strong>索引从0开始</strong> ）；另一种是从另一口井铺设管道引水，数组&nbsp;<code>pipes</code>&nbsp;给出了在房子间铺设管道的成本，其中每个&nbsp;<code>pipes[j] = [house1<sub>j</sub>, house2<sub>j</sub>, cost<sub>j</sub>]</code>&nbsp;代表用管道将&nbsp;<code>house1<sub>j</sub></code>&nbsp;和&nbsp;<code>house2<sub>j</sub></code>连接在一起的成本。连接是双向的。</p>

<p>请返回 <em>为所有房子都供水的最低总成本</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1168.Optimize%20Water%20Distribution%20in%20a%20Village/images/1359_ex1.png" /></strong></p>

<pre>
<strong>输入：</strong>n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
<strong>输出：</strong>3
<strong>解释： </strong>
上图展示了铺设管道连接房屋的成本。
最好的策略是在第一个房子里建造水井（成本为 1），然后将其他房子铺设管道连起来（成本为 2），所以总成本为 3。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, wells = [1,1], pipes = [[1,2,1]]
<strong>输出：</strong>2
<strong>解释：</strong>我们可以用以下三种方法中的一种来提供低成本的水:
选项1:
在1号房子里面建一口井，成本为1
在房子2内建造井，成本为1
总成本是2。
选项2:
在1号房子里面建一口井，成本为1
-花费1连接房子2和房子1。
总成本是2。
选项3:
在房子2内建造井，成本为1
-花费1连接房子1和房子2。
总成本是2。
注意，我们可以用cost 1或cost 2连接房子1和房子2，但我们总是选择最便宜的选项。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>wells.length == n</code></li>
	<li><code>0 &lt;= wells[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= pipes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>pipes[j].length == 3</code></li>
	<li><code>1 &lt;= house1<sub>j</sub>, house2<sub>j</sub>&nbsp;&lt;= n</code></li>
	<li><code>0 &lt;= cost<sub>j</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>house1<sub>j</sub>&nbsp;!= house2<sub>j</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Kruskal 算法（最小生成树）

我们假设有一个水井编号为 $0$，那么我们可以将每个房子与水井 $0$ 之间的连通性看作是一条边，每条边的权值为该房子建造水井的成本。同时，我们将每个房子之间的连通性也看作是一条边，每条边的权值为铺设管道的成本。这样一来，我们就可以将本题转化成求一张无向图的最小生成树的问题。

我们可以使用 Kruskal 算法求出无向图的最小生成树。我们先把水井 $0$ 与房子之间的一条边加入 $pipes$ 数组中，然后将 $pipes$ 数组按照边权值从小到大排序。随后，我们遍历每一条边，如果这条边连接了不同的连通分量，我们就选用这条边，并将对应连通分量合并。如果当前的连通分量恰好为 $1$，那么我们就找到了最小生成树，此时的答案即为当前边权值，我们将其返回即可。

时间复杂度 $O((m + n) \times \log (m + n))$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是 $pipes$ 数组和 $wells$ 数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostToSupplyWater(
        self, n: int, wells: List[int], pipes: List[List[int]]
    ) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        for i, w in enumerate(wells, 1):
            pipes.append([0, i, w])
        pipes.sort(key=lambda x: x[2])
        p = list(range(n + 1))
        ans = 0
        for a, b, c in pipes:
            pa, pb = find(a), find(b)
            if pa != pb:
                p[pa] = pb
                n -= 1
                ans += c
                if n == 0:
                    return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        int[][] nums = Arrays.copyOf(pipes, pipes.length + n);
        for (int i = 0; i < n; i++) {
            nums[pipes.length + i] = new int[] {0, i + 1, wells[i]};
        }
        Arrays.sort(nums, (a, b) -> a[2] - b[2]);
        p = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            p[i] = i;
        }
        int ans = 0;
        for (var x : nums) {
            int a = x[0], b = x[1], c = x[2];
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                p[pa] = pb;
                ans += c;
                if (--n == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i < n; ++i) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int p[n + 1];
        iota(p, p + n + 1, 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        int ans = 0;
        for (const auto& x : pipes) {
            int pa = find(x[0]), pb = find(x[1]);
            if (pa == pb) {
                continue;
            }
            p[pa] = pb;
            ans += x[2];
            if (--n == 0) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minCostToSupplyWater(n int, wells []int, pipes [][]int) (ans int) {
	for i, w := range wells {
		pipes = append(pipes, []int{0, i + 1, w})
	}
	sort.Slice(pipes, func(i, j int) bool { return pipes[i][2] < pipes[j][2] })
	p := make([]int, n+1)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	for _, x := range pipes {
		pa, pb := find(x[0]), find(x[1])
		if pa == pb {
			continue
		}
		p[pa] = pb
		ans += x[2]
		n--
		if n == 0 {
			break
		}
	}
	return
}
```

#### TypeScript

```ts
function minCostToSupplyWater(n: number, wells: number[], pipes: number[][]): number {
    for (let i = 0; i < n; ++i) {
        pipes.push([0, i + 1, wells[i]]);
    }
    pipes.sort((a, b) => a[2] - b[2]);
    const p = Array(n + 1)
        .fill(0)
        .map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    let ans = 0;
    for (const [a, b, c] of pipes) {
        const pa = find(a);
        const pb = find(b);
        if (pa === pb) {
            continue;
        }
        p[pa] = pb;
        ans += c;
        if (--n === 0) {
            break;
        }
    }
    return ans;
}
```

#### Rust

```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p: Vec<usize> = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) -> bool {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            false
        } else if self.size[pa] > self.size[pb] {
            self.p[pb] = pa;
            self.size[pa] += self.size[pb];
            true
        } else {
            self.p[pa] = pb;
            self.size[pb] += self.size[pa];
            true
        }
    }
}

impl Solution {
    pub fn min_cost_to_supply_water(n: i32, wells: Vec<i32>, pipes: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut pipes = pipes;
        for i in 0..n {
            pipes.push(vec![0, (i + 1) as i32, wells[i]]);
        }
        pipes.sort_by(|a, b| a[2].cmp(&b[2]));
        let mut uf = UnionFind::new(n + 1);
        let mut ans = 0;
        for pipe in pipes {
            let a = pipe[0] as usize;
            let b = pipe[1] as usize;
            let c = pipe[2];
            if uf.union(a, b) {
                ans += c;
                if n == 0 {
                    break;
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

### 方法二

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    __slots__ = ("p", "size")

    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int) -> bool:
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
    def minCostToSupplyWater(
        self, n: int, wells: List[int], pipes: List[List[int]]
    ) -> int:
        for i, w in enumerate(wells, 1):
            pipes.append([0, i, w])
        pipes.sort(key=lambda x: x[2])
        uf = UnionFind(n + 1)
        ans = 0
        for a, b, c in pipes:
            if uf.union(a, b):
                ans += c
                n -= 1
                if n == 0:
                    return ans
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

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
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        int[][] nums = Arrays.copyOf(pipes, pipes.length + n);
        for (int i = 0; i < n; i++) {
            nums[pipes.length + i] = new int[] {0, i + 1, wells[i]};
        }
        Arrays.sort(nums, (a, b) -> a[2] - b[2]);
        UnionFind uf = new UnionFind(n + 1);
        int ans = 0;
        for (var x : nums) {
            int a = x[0], b = x[1], c = x[2];
            if (uf.union(a, b)) {
                ans += c;
                if (--n == 0) {
                    break;
                }
            }
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i < n; ++i) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        UnionFind uf(n + 1);
        int ans = 0;
        for (const auto& x : pipes) {
            if (uf.unite(x[0], x[1])) {
                ans += x[2];
                if (--n == 0) {
                    break;
                }
            }
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

func minCostToSupplyWater(n int, wells []int, pipes [][]int) (ans int) {
	for i, w := range wells {
		pipes = append(pipes, []int{0, i + 1, w})
	}
	sort.Slice(pipes, func(i, j int) bool { return pipes[i][2] < pipes[j][2] })
	uf := newUnionFind(n + 1)
	for _, x := range pipes {
		if uf.union(x[0], x[1]) {
			ans += x[2]
			n--
			if n == 0 {
				break
			}
		}
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
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
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

function minCostToSupplyWater(n: number, wells: number[], pipes: number[][]): number {
    for (let i = 0; i < n; ++i) {
        pipes.push([0, i + 1, wells[i]]);
    }
    pipes.sort((a, b) => a[2] - b[2]);
    const uf = new UnionFind(n + 1);
    let ans = 0;
    for (const [a, b, c] of pipes) {
        if (uf.union(a, b)) {
            ans += c;
            if (--n === 0) {
                break;
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

# [1169. 查询无效交易](https://leetcode.cn/problems/invalid-transactions){#1169}

{{< tabs "1169" >}}

{{% tab "python" %}}
```python
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        d = defaultdict(list)
        idx = set()
        for i, x in enumerate(transactions):
            name, time, amount, city = x.split(",")
            time, amount = int(time), int(amount)
            d[name].append((time, city, i))
            if amount > 1000:
                idx.add(i)
            for t, c, j in d[name]:
                if c != city and abs(time - t) <= 60:
                    idx.add(i)
                    idx.add(j)
        return [transactions[i] for i in idx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        Map<String, List<Item>> d = new HashMap<>();
        Set<Integer> idx = new HashSet<>();
        for (int i = 0; i < transactions.length; ++i) {
            var e = transactions[i].split(",");
            String name = e[0];
            int time = Integer.parseInt(e[1]);
            int amount = Integer.parseInt(e[2]);
            String city = e[3];
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(new Item(time, city, i));
            if (amount > 1000) {
                idx.add(i);
            }
            for (Item item : d.get(name)) {
                if (!city.equals(item.city) && Math.abs(time - item.t) <= 60) {
                    idx.add(i);
                    idx.add(item.i);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i : idx) {
            ans.add(transactions[i]);
        }
        return ans;
    }
}

class Item {
    int t;
    String city;
    int i;

    Item(int t, String city, int i) {
        this.t = t;
        this.city = city;
        this.i = i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> d;
        unordered_set<int> idx;
        for (int i = 0; i < transactions.size(); ++i) {
            vector<string> e = split(transactions[i], ',');
            string name = e[0];
            int time = stoi(e[1]);
            int amount = stoi(e[2]);
            string city = e[3];
            d[name].push_back({time, city, i});
            if (amount > 1000) {
                idx.insert(i);
            }
            for (auto& [t, c, j] : d[name]) {
                if (c != city && abs(time - t) <= 60) {
                    idx.insert(i);
                    idx.insert(j);
                }
            }
        }
        vector<string> ans;
        for (int i : idx) {
            ans.emplace_back(transactions[i]);
        }
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func invalidTransactions(transactions []string) (ans []string) {
	d := map[string][]tuple{}
	idx := map[int]bool{}
	for i, x := range transactions {
		e := strings.Split(x, ",")
		name := e[0]
		time, _ := strconv.Atoi(e[1])
		amount, _ := strconv.Atoi(e[2])
		city := e[3]
		d[name] = append(d[name], tuple{time, city, i})
		if amount > 1000 {
			idx[i] = true
		}
		for _, item := range d[name] {
			if city != item.city && abs(time-item.t) <= 60 {
				idx[i], idx[item.i] = true, true
			}
		}
	}
	for i := range idx {
		ans = append(ans, transactions[i])
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct {
	t    int
	city string
	i    int
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果出现下述两种情况，交易 <strong>可能无效</strong>：</p>

<ul>
	<li>交易金额超过<meta charset="UTF-8" />&nbsp;<code>$1000</code></li>
	<li>或者，它和&nbsp;<strong>另一个城市</strong>&nbsp;中 <strong>同名</strong> 的另一笔交易相隔不超过 <code>60</code> 分钟（包含 60 分钟整）</li>
</ul>

<p>给定字符串数组交易清单<meta charset="UTF-8" />&nbsp;<code>transaction</code>&nbsp;。每个交易字符串&nbsp;<code>transactions[i]</code>&nbsp;由一些用逗号分隔的值组成，这些值分别表示交易的名称，时间（以分钟计），金额以及城市。</p>

<p>返回&nbsp;<code>transactions</code>，返回可能无效的交易列表。你可以按 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
<strong>输出：</strong>["alice,20,800,mtv","alice,50,100,beijing"]
<strong>解释：</strong>第一笔交易是无效的，因为第二笔交易和它间隔不超过 60 分钟、名称相同且发生在不同的城市。同样，第二笔交易也是无效的。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
<strong>输出：</strong>["alice,50,1200,mtv"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
<strong>输出：</strong>["bob,50,1200,mtv"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>transactions.length &lt;= 1000</code></li>
	<li>每笔交易&nbsp;<code>transactions[i]</code>&nbsp;按&nbsp;<code>"{name},{time},{amount},{city}"</code>&nbsp;的格式进行记录</li>
	<li>每个交易名称&nbsp;<code>{name}</code>&nbsp;和城市&nbsp;<code>{city}</code>&nbsp;都由小写英文字母组成，长度在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>10</code>&nbsp;之间</li>
	<li>每个交易时间&nbsp;<code>{time}</code>&nbsp;由一些数字组成，表示一个&nbsp;<code>0</code>&nbsp;到&nbsp;<code>1000</code>&nbsp;之间的整数</li>
	<li>每笔交易金额&nbsp;<code>{amount}</code>&nbsp;由一些数字组成，表示一个&nbsp;<code>0</code> 到&nbsp;<code>2000</code>&nbsp;之间的整数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

遍历交易列表，对于每笔交易，如果金额大于 1000，或者同名且城市不同且时间间隔不超过 60 分钟，则将其加入答案。

具体地，我们使用哈希表 `d` 记录每个交易，其中键为交易名称，值为一个列表，列表中的每个元素为一个三元组 `(time, city, index)`，表示在 `time` 时刻在 `city` 城市进行了编号为 `index` 的交易。同时，我们使用哈希表 `idx` 记录答案中的交易编号。

遍历交易列表，对于每笔交易，我们首先将其加入哈希表 `d` 中，然后判断其金额是否大于 1000，如果是，则将其编号加入答案中。然后我们遍历哈希表 `d` 中的交易，如果交易名称相同且城市不同且时间间隔不超过 60 分钟，则将其编号加入答案中。

最后，我们遍历答案中的交易编号，将其对应的交易加入答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为交易列表的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        d = defaultdict(list)
        idx = set()
        for i, x in enumerate(transactions):
            name, time, amount, city = x.split(",")
            time, amount = int(time), int(amount)
            d[name].append((time, city, i))
            if amount > 1000:
                idx.add(i)
            for t, c, j in d[name]:
                if c != city and abs(time - t) <= 60:
                    idx.add(i)
                    idx.add(j)
        return [transactions[i] for i in idx]
```

#### Java

```java
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        Map<String, List<Item>> d = new HashMap<>();
        Set<Integer> idx = new HashSet<>();
        for (int i = 0; i < transactions.length; ++i) {
            var e = transactions[i].split(",");
            String name = e[0];
            int time = Integer.parseInt(e[1]);
            int amount = Integer.parseInt(e[2]);
            String city = e[3];
            d.computeIfAbsent(name, k -> new ArrayList<>()).add(new Item(time, city, i));
            if (amount > 1000) {
                idx.add(i);
            }
            for (Item item : d.get(name)) {
                if (!city.equals(item.city) && Math.abs(time - item.t) <= 60) {
                    idx.add(i);
                    idx.add(item.i);
                }
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i : idx) {
            ans.add(transactions[i]);
        }
        return ans;
    }
}

class Item {
    int t;
    String city;
    int i;

    Item(int t, String city, int i) {
        this.t = t;
        this.city = city;
        this.i = i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> d;
        unordered_set<int> idx;
        for (int i = 0; i < transactions.size(); ++i) {
            vector<string> e = split(transactions[i], ',');
            string name = e[0];
            int time = stoi(e[1]);
            int amount = stoi(e[2]);
            string city = e[3];
            d[name].push_back({time, city, i});
            if (amount > 1000) {
                idx.insert(i);
            }
            for (auto& [t, c, j] : d[name]) {
                if (c != city && abs(time - t) <= 60) {
                    idx.insert(i);
                    idx.insert(j);
                }
            }
        }
        vector<string> ans;
        for (int i : idx) {
            ans.emplace_back(transactions[i]);
        }
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```

#### Go

```go
func invalidTransactions(transactions []string) (ans []string) {
	d := map[string][]tuple{}
	idx := map[int]bool{}
	for i, x := range transactions {
		e := strings.Split(x, ",")
		name := e[0]
		time, _ := strconv.Atoi(e[1])
		amount, _ := strconv.Atoi(e[2])
		city := e[3]
		d[name] = append(d[name], tuple{time, city, i})
		if amount > 1000 {
			idx[i] = true
		}
		for _, item := range d[name] {
			if city != item.city && abs(time-item.t) <= 60 {
				idx[i], idx[item.i] = true, true
			}
		}
	}
	for i := range idx {
		ans = append(ans, transactions[i])
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct {
	t    int
	city string
	i    int
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
